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
#include <godot_cpp/classes/hashing_context.hpp>
using namespace godot;

static void hashing_context_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["HashingContext"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef hashing_context_class_def = {
    "HashingContext",
    hashing_context_class_finalizer
};

static JSValue hashing_context_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["HashingContext"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    HashingContext *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<HashingContext *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(HashingContext);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue hashing_context_class_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HashingContext::start, ctx, this_val, argc, argv);
};
static JSValue hashing_context_class_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HashingContext::update, ctx, this_val, argc, argv);
};
static JSValue hashing_context_class_finish(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HashingContext::finish, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry hashing_context_class_proto_funcs[] = {
	JS_CFUNC_DEF("start", 1, &hashing_context_class_start),
	JS_CFUNC_DEF("update", 1, &hashing_context_class_update),
	JS_CFUNC_DEF("finish", 0, &hashing_context_class_finish),
};




static void define_hashing_context_property(JSContext *ctx, JSValue proto) {
}

static void define_hashing_context_enum(JSContext *ctx, JSValue ctor) {
	JSValue HashType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HashType_obj, "HASH_MD5", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HashType_obj, "HASH_SHA1", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HashType_obj, "HASH_SHA256", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "HashType", HashType_obj);
}

static int js_hashing_context_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["HashingContext"] = class_id;
	classes_by_id[class_id] = "HashingContext";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &hashing_context_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_hashing_context_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, hashing_context_class_proto_funcs, _countof(hashing_context_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, hashing_context_class_constructor, "HashingContext", 0, JS_CFUNC_constructor, 0);
	define_hashing_context_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "HashingContext", ctor);

	return 0;
}

JSModuleDef *_js_init_hashing_context_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_hashing_context_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "HashingContext");
	return m;
}

JSModuleDef *js_init_hashing_context_module(JSContext *ctx) {
	return _js_init_hashing_context_module(ctx, "@godot/classes/hashing_context");
}

void __register_hashing_context() {
	js_init_hashing_context_module(js_context());
}

void register_hashing_context() {
	__register_hashing_context();
}