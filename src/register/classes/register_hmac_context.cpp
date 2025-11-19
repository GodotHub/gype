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
#include <godot_cpp/classes/hmac_context.hpp>
using namespace godot;

static void hmac_context_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["HMACContext"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef hmac_context_class_def = {
    "HMACContext",
    hmac_context_class_finalizer
};

static JSValue hmac_context_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["HMACContext"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    HMACContext *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<HMACContext *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(HMACContext);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue hmac_context_class_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HMACContext::start, ctx, this_val, argc, argv);
};
static JSValue hmac_context_class_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HMACContext::update, ctx, this_val, argc, argv);
};
static JSValue hmac_context_class_finish(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HMACContext::finish, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry hmac_context_class_proto_funcs[] = {
	JS_CFUNC_DEF("start", 2, &hmac_context_class_start),
	JS_CFUNC_DEF("update", 1, &hmac_context_class_update),
	JS_CFUNC_DEF("finish", 0, &hmac_context_class_finish),
};




static void define_hmac_context_property(JSContext *ctx, JSValue proto) {
}

static void define_hmac_context_enum(JSContext *ctx, JSValue ctor) {
}

static int js_hmac_context_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["HMACContext"] = class_id;
	classes_by_id[class_id] = "HMACContext";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &hmac_context_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_hmac_context_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, hmac_context_class_proto_funcs, _countof(hmac_context_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, hmac_context_class_constructor, "HMACContext", 0, JS_CFUNC_constructor, 0);
	define_hmac_context_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "HMACContext", ctor);

	return 0;
}

JSModuleDef *_js_init_hmac_context_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_hmac_context_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "HMACContext");
	return m;
}

JSModuleDef *js_init_hmac_context_module(JSContext *ctx) {
	return _js_init_hmac_context_module(ctx, "@godot/classes/hmac_context");
}

void __register_hmac_context() {
	js_init_hmac_context_module(js_context());
}

void register_hmac_context() {
	__register_hmac_context();
}