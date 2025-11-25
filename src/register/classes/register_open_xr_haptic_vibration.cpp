#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_haptic_base.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_haptic_vibration.hpp>
using namespace godot;

static void open_xr_haptic_vibration_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRHapticVibration"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_haptic_vibration_class_def = {
    "OpenXRHapticVibration",
    open_xr_haptic_vibration_class_finalizer
};

static JSValue open_xr_haptic_vibration_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRHapticVibration"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(OpenXRHapticVibration);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_haptic_vibration_class_set_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHapticVibration::set_duration, ctx, this_val, argc, argv);
};
static JSValue open_xr_haptic_vibration_class_get_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHapticVibration::get_duration, ctx, this_val, argc, argv);
}
static JSValue open_xr_haptic_vibration_class_set_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHapticVibration::set_frequency, ctx, this_val, argc, argv);
};
static JSValue open_xr_haptic_vibration_class_get_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHapticVibration::get_frequency, ctx, this_val, argc, argv);
}
static JSValue open_xr_haptic_vibration_class_set_amplitude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHapticVibration::set_amplitude, ctx, this_val, argc, argv);
};
static JSValue open_xr_haptic_vibration_class_get_amplitude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHapticVibration::get_amplitude, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry open_xr_haptic_vibration_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_duration", 1, &open_xr_haptic_vibration_class_set_duration),
	JS_CFUNC_DEF("get_duration", 0, &open_xr_haptic_vibration_class_get_duration),
	JS_CFUNC_DEF("set_frequency", 1, &open_xr_haptic_vibration_class_set_frequency),
	JS_CFUNC_DEF("get_frequency", 0, &open_xr_haptic_vibration_class_get_frequency),
	JS_CFUNC_DEF("set_amplitude", 1, &open_xr_haptic_vibration_class_set_amplitude),
	JS_CFUNC_DEF("get_amplitude", 0, &open_xr_haptic_vibration_class_get_amplitude),
};




static void define_open_xr_haptic_vibration_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "duration"),
        JS_NewCFunction(ctx, open_xr_haptic_vibration_class_get_duration, "get_duration", 0),
        JS_NewCFunction(ctx, open_xr_haptic_vibration_class_set_duration, "set_duration", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frequency"),
        JS_NewCFunction(ctx, open_xr_haptic_vibration_class_get_frequency, "get_frequency", 0),
        JS_NewCFunction(ctx, open_xr_haptic_vibration_class_set_frequency, "set_frequency", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "amplitude"),
        JS_NewCFunction(ctx, open_xr_haptic_vibration_class_get_amplitude, "get_amplitude", 0),
        JS_NewCFunction(ctx, open_xr_haptic_vibration_class_set_amplitude, "set_amplitude", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_haptic_vibration_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_haptic_vibration_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRHapticVibration"] = class_id;
	classes_by_id[class_id] = "OpenXRHapticVibration";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_haptic_vibration_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["OpenXRHapticBase"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_haptic_vibration_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_haptic_vibration_class_proto_funcs, _countof(open_xr_haptic_vibration_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_haptic_vibration_class_constructor, "OpenXRHapticVibration", 0, JS_CFUNC_constructor, 0);
	define_open_xr_haptic_vibration_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRHapticVibration", ctor);
	ctor_list["OpenXRHapticVibration"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_haptic_vibration_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/open_xr_haptic_base';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_haptic_vibration_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRHapticVibration");
	return m;
}

JSModuleDef *js_init_open_xr_haptic_vibration_module(JSContext *ctx) {
	return _js_init_open_xr_haptic_vibration_module(ctx, "@godot/classes/open_xr_haptic_vibration");
}

void __register_open_xr_haptic_vibration() {
	js_init_open_xr_haptic_vibration_module(js_context());
}

void register_open_xr_haptic_vibration() {
	__register_open_xr_haptic_vibration();
}