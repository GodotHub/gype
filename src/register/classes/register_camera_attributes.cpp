#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/camera_attributes.hpp>
using namespace godot;

static void camera_attributes_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CameraAttributes"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef camera_attributes_class_def = {
    "CameraAttributes",
    camera_attributes_class_finalizer
};

static JSValue camera_attributes_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CameraAttributes"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CameraAttributes *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CameraAttributes *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CameraAttributes);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue camera_attributes_class_set_exposure_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributes::set_exposure_multiplier, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_class_get_exposure_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributes::get_exposure_multiplier, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_class_set_exposure_sensitivity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributes::set_exposure_sensitivity, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_class_get_exposure_sensitivity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributes::get_exposure_sensitivity, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_class_set_auto_exposure_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributes::set_auto_exposure_enabled, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_class_is_auto_exposure_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributes::is_auto_exposure_enabled, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_class_set_auto_exposure_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributes::set_auto_exposure_speed, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_class_get_auto_exposure_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributes::get_auto_exposure_speed, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_class_set_auto_exposure_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributes::set_auto_exposure_scale, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_class_get_auto_exposure_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributes::get_auto_exposure_scale, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry camera_attributes_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_exposure_multiplier", 1, &camera_attributes_class_set_exposure_multiplier),
	JS_CFUNC_DEF("get_exposure_multiplier", 0, &camera_attributes_class_get_exposure_multiplier),
	JS_CFUNC_DEF("set_exposure_sensitivity", 1, &camera_attributes_class_set_exposure_sensitivity),
	JS_CFUNC_DEF("get_exposure_sensitivity", 0, &camera_attributes_class_get_exposure_sensitivity),
	JS_CFUNC_DEF("set_auto_exposure_enabled", 1, &camera_attributes_class_set_auto_exposure_enabled),
	JS_CFUNC_DEF("is_auto_exposure_enabled", 0, &camera_attributes_class_is_auto_exposure_enabled),
	JS_CFUNC_DEF("set_auto_exposure_speed", 1, &camera_attributes_class_set_auto_exposure_speed),
	JS_CFUNC_DEF("get_auto_exposure_speed", 0, &camera_attributes_class_get_auto_exposure_speed),
	JS_CFUNC_DEF("set_auto_exposure_scale", 1, &camera_attributes_class_set_auto_exposure_scale),
	JS_CFUNC_DEF("get_auto_exposure_scale", 0, &camera_attributes_class_get_auto_exposure_scale),
};




static void define_camera_attributes_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exposure_sensitivity"),
        JS_NewCFunction(ctx, camera_attributes_class_get_exposure_sensitivity, "get_exposure_sensitivity", 0),
        JS_NewCFunction(ctx, camera_attributes_class_set_exposure_sensitivity, "set_exposure_sensitivity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exposure_multiplier"),
        JS_NewCFunction(ctx, camera_attributes_class_get_exposure_multiplier, "get_exposure_multiplier", 0),
        JS_NewCFunction(ctx, camera_attributes_class_set_exposure_multiplier, "set_exposure_multiplier", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_exposure_enabled"),
        JS_NewCFunction(ctx, camera_attributes_class_is_auto_exposure_enabled, "is_auto_exposure_enabled", 0),
        JS_NewCFunction(ctx, camera_attributes_class_set_auto_exposure_enabled, "set_auto_exposure_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_exposure_scale"),
        JS_NewCFunction(ctx, camera_attributes_class_get_auto_exposure_scale, "get_auto_exposure_scale", 0),
        JS_NewCFunction(ctx, camera_attributes_class_set_auto_exposure_scale, "set_auto_exposure_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_exposure_speed"),
        JS_NewCFunction(ctx, camera_attributes_class_get_auto_exposure_speed, "get_auto_exposure_speed", 0),
        JS_NewCFunction(ctx, camera_attributes_class_set_auto_exposure_speed, "set_auto_exposure_speed", 1),
        JS_PROP_GETSET
    );
}

static void define_camera_attributes_enum(JSContext *ctx, JSValue proto) {
}

static int js_camera_attributes_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CameraAttributes"] = class_id;
	classes_by_id[class_id] = "CameraAttributes";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &camera_attributes_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_camera_attributes_property(ctx, proto);
	define_camera_attributes_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, camera_attributes_class_proto_funcs, _countof(camera_attributes_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, camera_attributes_class_constructor, "CameraAttributes", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CameraAttributes", ctor);

	return 0;
}

JSModuleDef *_js_init_camera_attributes_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_camera_attributes_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CameraAttributes");
	return m;
}

JSModuleDef *js_init_camera_attributes_module(JSContext *ctx) {
	return _js_init_camera_attributes_module(ctx, "@godot/classes/camera_attributes");
}

void __register_camera_attributes() {
	js_init_camera_attributes_module(js_context());
}

void register_camera_attributes() {
	__register_camera_attributes();
}