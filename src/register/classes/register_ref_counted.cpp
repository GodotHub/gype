#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
using namespace godot;

static void ref_counted_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RefCounted"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef ref_counted_class_def = {
    "RefCounted",
    ref_counted_class_finalizer
};

static JSValue ref_counted_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RefCounted"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RefCounted *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RefCounted *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RefCounted);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue ref_counted_class_init_ref(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RefCounted::init_ref, ctx, this_val, argc, argv);
};
static JSValue ref_counted_class_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RefCounted::reference, ctx, this_val, argc, argv);
};
static JSValue ref_counted_class_unreference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RefCounted::unreference, ctx, this_val, argc, argv);
};
static JSValue ref_counted_class_get_reference_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RefCounted::get_reference_count, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry ref_counted_class_proto_funcs[] = {
	JS_CFUNC_DEF("init_ref", 0, &ref_counted_class_init_ref),
	JS_CFUNC_DEF("reference", 0, &ref_counted_class_reference),
	JS_CFUNC_DEF("unreference", 0, &ref_counted_class_unreference),
	JS_CFUNC_DEF("get_reference_count", 0, &ref_counted_class_get_reference_count),
};




static void define_ref_counted_property(JSContext *ctx, JSValue proto) {
}

static void define_ref_counted_enum(JSContext *ctx, JSValue ctor) {
}

static int js_ref_counted_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RefCounted"] = class_id;
	classes_by_id[class_id] = "RefCounted";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &ref_counted_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_ref_counted_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, ref_counted_class_proto_funcs, _countof(ref_counted_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, ref_counted_class_constructor, "RefCounted", 0, JS_CFUNC_constructor, 0);
	define_ref_counted_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RefCounted", ctor);

	return 0;
}

JSModuleDef *_js_init_ref_counted_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_ref_counted_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RefCounted");
	return m;
}

JSModuleDef *js_init_ref_counted_module(JSContext *ctx) {
	return _js_init_ref_counted_module(ctx, "@godot/classes/ref_counted");
}

void __register_ref_counted() {
	js_init_ref_counted_module(js_context());
}

void register_ref_counted() {
	__register_ref_counted();
}