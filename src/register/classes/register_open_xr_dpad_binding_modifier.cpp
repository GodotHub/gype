#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_action_set.hpp>
#include <godot_cpp/classes/open_xr_haptic_base.hpp>
#include <godot_cpp/classes/open_xrip_binding_modifier.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_dpad_binding_modifier.hpp>
using namespace godot;

static void open_xr_dpad_binding_modifier_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRDpadBindingModifier"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_dpad_binding_modifier_class_def = {
    "OpenXRDpadBindingModifier",
    open_xr_dpad_binding_modifier_class_finalizer
};

static JSValue open_xr_dpad_binding_modifier_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRDpadBindingModifier"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRDpadBindingModifier *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRDpadBindingModifier *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRDpadBindingModifier);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_dpad_binding_modifier_class_set_action_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_action_set, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_action_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_action_set, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_input_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_input_path, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_input_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		OpenXRDpadBindingModifier *obj = static_cast<OpenXRDpadBindingModifier *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_input_path();
	};
	proxy->setter = [this_val](const String &value) -> void {
		OpenXRDpadBindingModifier *js_proxy = static_cast<OpenXRDpadBindingModifier *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_input_path(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue open_xr_dpad_binding_modifier_class_set_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_threshold, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_threshold, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_threshold_released(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_threshold_released, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_threshold_released(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_threshold_released, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_center_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_center_region, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_center_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_center_region, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_wedge_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_wedge_angle, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_wedge_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_wedge_angle, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_is_sticky(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_is_sticky, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_is_sticky(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_is_sticky, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_on_haptic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_on_haptic, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_on_haptic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_on_haptic, ctx, this_val, argc, argv);
}
static JSValue open_xr_dpad_binding_modifier_class_set_off_haptic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRDpadBindingModifier::set_off_haptic, ctx, this_val, argc, argv);
};
static JSValue open_xr_dpad_binding_modifier_class_get_off_haptic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRDpadBindingModifier::get_off_haptic, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry open_xr_dpad_binding_modifier_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_action_set", 1, &open_xr_dpad_binding_modifier_class_set_action_set),
	JS_CFUNC_DEF("get_action_set", 0, &open_xr_dpad_binding_modifier_class_get_action_set),
	JS_CFUNC_DEF("set_input_path", 1, &open_xr_dpad_binding_modifier_class_set_input_path),
	JS_CFUNC_DEF("get_input_path", 0, &open_xr_dpad_binding_modifier_class_get_input_path),
	JS_CFUNC_DEF("set_threshold", 1, &open_xr_dpad_binding_modifier_class_set_threshold),
	JS_CFUNC_DEF("get_threshold", 0, &open_xr_dpad_binding_modifier_class_get_threshold),
	JS_CFUNC_DEF("set_threshold_released", 1, &open_xr_dpad_binding_modifier_class_set_threshold_released),
	JS_CFUNC_DEF("get_threshold_released", 0, &open_xr_dpad_binding_modifier_class_get_threshold_released),
	JS_CFUNC_DEF("set_center_region", 1, &open_xr_dpad_binding_modifier_class_set_center_region),
	JS_CFUNC_DEF("get_center_region", 0, &open_xr_dpad_binding_modifier_class_get_center_region),
	JS_CFUNC_DEF("set_wedge_angle", 1, &open_xr_dpad_binding_modifier_class_set_wedge_angle),
	JS_CFUNC_DEF("get_wedge_angle", 0, &open_xr_dpad_binding_modifier_class_get_wedge_angle),
	JS_CFUNC_DEF("set_is_sticky", 1, &open_xr_dpad_binding_modifier_class_set_is_sticky),
	JS_CFUNC_DEF("get_is_sticky", 0, &open_xr_dpad_binding_modifier_class_get_is_sticky),
	JS_CFUNC_DEF("set_on_haptic", 1, &open_xr_dpad_binding_modifier_class_set_on_haptic),
	JS_CFUNC_DEF("get_on_haptic", 0, &open_xr_dpad_binding_modifier_class_get_on_haptic),
	JS_CFUNC_DEF("set_off_haptic", 1, &open_xr_dpad_binding_modifier_class_set_off_haptic),
	JS_CFUNC_DEF("get_off_haptic", 0, &open_xr_dpad_binding_modifier_class_get_off_haptic),
};




static void define_open_xr_dpad_binding_modifier_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action_set"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_action_set, "get_action_set", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_action_set, "set_action_set", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_path"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_input_path, "get_input_path", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_input_path, "set_input_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "threshold"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_threshold, "get_threshold", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_threshold, "set_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "threshold_released"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_threshold_released, "get_threshold_released", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_threshold_released, "set_threshold_released", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_region"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_center_region, "get_center_region", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_center_region, "set_center_region", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wedge_angle"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_wedge_angle, "get_wedge_angle", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_wedge_angle, "set_wedge_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "is_sticky"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_is_sticky, "get_is_sticky", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_is_sticky, "set_is_sticky", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "on_haptic"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_on_haptic, "get_on_haptic", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_on_haptic, "set_on_haptic", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "off_haptic"),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_get_off_haptic, "get_off_haptic", 0),
        JS_NewCFunction(ctx, open_xr_dpad_binding_modifier_class_set_off_haptic, "set_off_haptic", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_dpad_binding_modifier_enum(JSContext *ctx, JSValue proto) {
}

static int js_open_xr_dpad_binding_modifier_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRDpadBindingModifier"] = class_id;
	classes_by_id[class_id] = "OpenXRDpadBindingModifier";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_dpad_binding_modifier_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["OpenXRIPBindingModifier"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_dpad_binding_modifier_property(ctx, proto);
	define_open_xr_dpad_binding_modifier_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_dpad_binding_modifier_class_proto_funcs, _countof(open_xr_dpad_binding_modifier_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_dpad_binding_modifier_class_constructor, "OpenXRDpadBindingModifier", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRDpadBindingModifier", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_dpad_binding_modifier_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/open_xrip_binding_modifier';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_dpad_binding_modifier_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRDpadBindingModifier");
	return m;
}

JSModuleDef *js_init_open_xr_dpad_binding_modifier_module(JSContext *ctx) {
	return _js_init_open_xr_dpad_binding_modifier_module(ctx, "@godot/classes/open_xr_dpad_binding_modifier");
}

void __register_open_xr_dpad_binding_modifier() {
	js_init_open_xr_dpad_binding_modifier_module(js_context());
}

void register_open_xr_dpad_binding_modifier() {
	__register_open_xr_dpad_binding_modifier();
}