#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/tweener.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/property_tweener.hpp>
using namespace godot;

static void property_tweener_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PropertyTweener"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef property_tweener_class_def = {
    "PropertyTweener",
    property_tweener_class_finalizer
};

static JSValue property_tweener_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PropertyTweener"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PropertyTweener *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PropertyTweener *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PropertyTweener);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue property_tweener_class_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::from, ctx, this_val, argc, argv);
};
static JSValue property_tweener_class_from_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::from_current, ctx, this_val, argc, argv);
};
static JSValue property_tweener_class_as_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::as_relative, ctx, this_val, argc, argv);
};
static JSValue property_tweener_class_set_trans(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::set_trans, ctx, this_val, argc, argv);
};
static JSValue property_tweener_class_set_ease(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::set_ease, ctx, this_val, argc, argv);
};
static JSValue property_tweener_class_set_custom_interpolator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::set_custom_interpolator, ctx, this_val, argc, argv);
};
static JSValue property_tweener_class_set_delay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PropertyTweener::set_delay, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry property_tweener_class_proto_funcs[] = {
	JS_CFUNC_DEF("from", 1, &property_tweener_class_from),
	JS_CFUNC_DEF("from_current", 0, &property_tweener_class_from_current),
	JS_CFUNC_DEF("as_relative", 0, &property_tweener_class_as_relative),
	JS_CFUNC_DEF("set_trans", 1, &property_tweener_class_set_trans),
	JS_CFUNC_DEF("set_ease", 1, &property_tweener_class_set_ease),
	JS_CFUNC_DEF("set_custom_interpolator", 1, &property_tweener_class_set_custom_interpolator),
	JS_CFUNC_DEF("set_delay", 1, &property_tweener_class_set_delay),
};




static void define_property_tweener_property(JSContext *ctx, JSValue proto) {
}

static void define_property_tweener_enum(JSContext *ctx, JSValue ctor) {
}

static int js_property_tweener_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PropertyTweener"] = class_id;
	classes_by_id[class_id] = "PropertyTweener";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &property_tweener_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Tweener"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_property_tweener_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, property_tweener_class_proto_funcs, _countof(property_tweener_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, property_tweener_class_constructor, "PropertyTweener", 0, JS_CFUNC_constructor, 0);
	define_property_tweener_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PropertyTweener", ctor);

	return 0;
}

JSModuleDef *_js_init_property_tweener_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/tweener';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_property_tweener_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PropertyTweener");
	return m;
}

JSModuleDef *js_init_property_tweener_module(JSContext *ctx) {
	return _js_init_property_tweener_module(ctx, "@godot/classes/property_tweener");
}

void __register_property_tweener() {
	js_init_property_tweener_module(js_context());
}

void register_property_tweener() {
	__register_property_tweener();
}