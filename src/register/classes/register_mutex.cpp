#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/mutex.hpp>
using namespace godot;

static void mutex_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Mutex"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef mutex_class_def = {
    "Mutex",
    mutex_class_finalizer
};

static JSValue mutex_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Mutex"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Mutex *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Mutex *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Mutex);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue mutex_class_lock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Mutex::lock, ctx, this_val, argc, argv);
};
static JSValue mutex_class_try_lock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Mutex::try_lock, ctx, this_val, argc, argv);
};
static JSValue mutex_class_unlock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Mutex::unlock, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry mutex_class_proto_funcs[] = {
	JS_CFUNC_DEF("lock", 0, &mutex_class_lock),
	JS_CFUNC_DEF("try_lock", 0, &mutex_class_try_lock),
	JS_CFUNC_DEF("unlock", 0, &mutex_class_unlock),
};




static void define_mutex_property(JSContext *ctx, JSValue proto) {
}

static void define_mutex_enum(JSContext *ctx, JSValue ctor) {
}

static int js_mutex_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Mutex"] = class_id;
	classes_by_id[class_id] = "Mutex";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &mutex_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_mutex_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, mutex_class_proto_funcs, _countof(mutex_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, mutex_class_constructor, "Mutex", 0, JS_CFUNC_constructor, 0);
	define_mutex_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Mutex", ctor);

	return 0;
}

JSModuleDef *_js_init_mutex_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_mutex_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Mutex");
	return m;
}

JSModuleDef *js_init_mutex_module(JSContext *ctx) {
	return _js_init_mutex_module(ctx, "@godot/classes/mutex");
}

void __register_mutex() {
	js_init_mutex_module(js_context());
}

void register_mutex() {
	__register_mutex();
}