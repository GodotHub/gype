#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/light3d.hpp>
using namespace godot;

static void light3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Light3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef light3d_class_def = {
    "Light3D",
    light3d_class_finalizer
};

static JSValue light3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Light3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Light3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Light3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Light3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue light3d_class_set_editor_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_editor_only, ctx, this_val, argc, argv);
};
static JSValue light3d_class_is_editor_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::is_editor_only, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_param, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_param, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_shadow, ctx, this_val, argc, argv);
};
static JSValue light3d_class_has_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::has_shadow, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_negative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_negative, ctx, this_val, argc, argv);
};
static JSValue light3d_class_is_negative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::is_negative, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_cull_mask, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_cull_mask, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_enable_distance_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_enable_distance_fade, ctx, this_val, argc, argv);
};
static JSValue light3d_class_is_distance_fade_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::is_distance_fade_enabled, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_distance_fade_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_distance_fade_begin, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_distance_fade_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_distance_fade_begin, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_distance_fade_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_distance_fade_shadow, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_distance_fade_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_distance_fade_shadow, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_distance_fade_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_distance_fade_length, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_distance_fade_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_distance_fade_length, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_color, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Light3D *obj = static_cast<Light3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Light3D *js_proxy = static_cast<Light3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue light3d_class_set_shadow_reverse_cull_face(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_shadow_reverse_cull_face, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_shadow_reverse_cull_face(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_shadow_reverse_cull_face, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_shadow_caster_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_shadow_caster_mask, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_shadow_caster_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_shadow_caster_mask, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_bake_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_bake_mode, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_bake_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_bake_mode, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_projector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_projector, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_projector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_projector, ctx, this_val, argc, argv);
}
static JSValue light3d_class_set_temperature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light3D::set_temperature, ctx, this_val, argc, argv);
};
static JSValue light3d_class_get_temperature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_temperature, ctx, this_val, argc, argv);
}
static JSValue light3d_class_get_correlated_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light3D::get_correlated_color, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry light3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_editor_only", 1, &light3d_class_set_editor_only),
	JS_CFUNC_DEF("is_editor_only", 0, &light3d_class_is_editor_only),
	JS_CFUNC_DEF("set_param", 2, &light3d_class_set_param),
	JS_CFUNC_DEF("get_param", 1, &light3d_class_get_param),
	JS_CFUNC_DEF("set_shadow", 1, &light3d_class_set_shadow),
	JS_CFUNC_DEF("has_shadow", 0, &light3d_class_has_shadow),
	JS_CFUNC_DEF("set_negative", 1, &light3d_class_set_negative),
	JS_CFUNC_DEF("is_negative", 0, &light3d_class_is_negative),
	JS_CFUNC_DEF("set_cull_mask", 1, &light3d_class_set_cull_mask),
	JS_CFUNC_DEF("get_cull_mask", 0, &light3d_class_get_cull_mask),
	JS_CFUNC_DEF("set_enable_distance_fade", 1, &light3d_class_set_enable_distance_fade),
	JS_CFUNC_DEF("is_distance_fade_enabled", 0, &light3d_class_is_distance_fade_enabled),
	JS_CFUNC_DEF("set_distance_fade_begin", 1, &light3d_class_set_distance_fade_begin),
	JS_CFUNC_DEF("get_distance_fade_begin", 0, &light3d_class_get_distance_fade_begin),
	JS_CFUNC_DEF("set_distance_fade_shadow", 1, &light3d_class_set_distance_fade_shadow),
	JS_CFUNC_DEF("get_distance_fade_shadow", 0, &light3d_class_get_distance_fade_shadow),
	JS_CFUNC_DEF("set_distance_fade_length", 1, &light3d_class_set_distance_fade_length),
	JS_CFUNC_DEF("get_distance_fade_length", 0, &light3d_class_get_distance_fade_length),
	JS_CFUNC_DEF("set_color", 1, &light3d_class_set_color),
	JS_CFUNC_DEF("get_color", 0, &light3d_class_get_color),
	JS_CFUNC_DEF("set_shadow_reverse_cull_face", 1, &light3d_class_set_shadow_reverse_cull_face),
	JS_CFUNC_DEF("get_shadow_reverse_cull_face", 0, &light3d_class_get_shadow_reverse_cull_face),
	JS_CFUNC_DEF("set_shadow_caster_mask", 1, &light3d_class_set_shadow_caster_mask),
	JS_CFUNC_DEF("get_shadow_caster_mask", 0, &light3d_class_get_shadow_caster_mask),
	JS_CFUNC_DEF("set_bake_mode", 1, &light3d_class_set_bake_mode),
	JS_CFUNC_DEF("get_bake_mode", 0, &light3d_class_get_bake_mode),
	JS_CFUNC_DEF("set_projector", 1, &light3d_class_set_projector),
	JS_CFUNC_DEF("get_projector", 0, &light3d_class_get_projector),
	JS_CFUNC_DEF("set_temperature", 1, &light3d_class_set_temperature),
	JS_CFUNC_DEF("get_temperature", 0, &light3d_class_get_temperature),
	JS_CFUNC_DEF("get_correlated_color", 0, &light3d_class_get_correlated_color),
};




static void define_light3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_intensity_lumens"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_intensity_lux"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_temperature"),
        JS_NewCFunction(ctx, light3d_class_get_temperature, "get_temperature", 0),
        JS_NewCFunction(ctx, light3d_class_set_temperature, "set_temperature", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_color"),
        JS_NewCFunction(ctx, light3d_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, light3d_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_energy"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_indirect_energy"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_volumetric_fog_energy"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_projector"),
        JS_NewCFunction(ctx, light3d_class_get_projector, "get_projector", 0),
        JS_NewCFunction(ctx, light3d_class_set_projector, "set_projector", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_size"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_angular_distance"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_negative"),
        JS_NewCFunction(ctx, light3d_class_is_negative, "is_negative", 0),
        JS_NewCFunction(ctx, light3d_class_set_negative, "set_negative", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_specular"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_bake_mode"),
        JS_NewCFunction(ctx, light3d_class_get_bake_mode, "get_bake_mode", 0),
        JS_NewCFunction(ctx, light3d_class_set_bake_mode, "set_bake_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_cull_mask"),
        JS_NewCFunction(ctx, light3d_class_get_cull_mask, "get_cull_mask", 0),
        JS_NewCFunction(ctx, light3d_class_set_cull_mask, "set_cull_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_enabled"),
        JS_NewCFunction(ctx, light3d_class_has_shadow, "has_shadow", 0),
        JS_NewCFunction(ctx, light3d_class_set_shadow, "set_shadow", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_bias"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_normal_bias"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_reverse_cull_face"),
        JS_NewCFunction(ctx, light3d_class_get_shadow_reverse_cull_face, "get_shadow_reverse_cull_face", 0),
        JS_NewCFunction(ctx, light3d_class_set_shadow_reverse_cull_face, "set_shadow_reverse_cull_face", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_transmittance_bias"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_opacity"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_blur"),
        JS_NewCFunction(ctx, light3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, light3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_caster_mask"),
        JS_NewCFunction(ctx, light3d_class_get_shadow_caster_mask, "get_shadow_caster_mask", 0),
        JS_NewCFunction(ctx, light3d_class_set_shadow_caster_mask, "set_shadow_caster_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_enabled"),
        JS_NewCFunction(ctx, light3d_class_is_distance_fade_enabled, "is_distance_fade_enabled", 0),
        JS_NewCFunction(ctx, light3d_class_set_enable_distance_fade, "set_enable_distance_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_begin"),
        JS_NewCFunction(ctx, light3d_class_get_distance_fade_begin, "get_distance_fade_begin", 0),
        JS_NewCFunction(ctx, light3d_class_set_distance_fade_begin, "set_distance_fade_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_shadow"),
        JS_NewCFunction(ctx, light3d_class_get_distance_fade_shadow, "get_distance_fade_shadow", 0),
        JS_NewCFunction(ctx, light3d_class_set_distance_fade_shadow, "set_distance_fade_shadow", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_length"),
        JS_NewCFunction(ctx, light3d_class_get_distance_fade_length, "get_distance_fade_length", 0),
        JS_NewCFunction(ctx, light3d_class_set_distance_fade_length, "set_distance_fade_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editor_only"),
        JS_NewCFunction(ctx, light3d_class_is_editor_only, "is_editor_only", 0),
        JS_NewCFunction(ctx, light3d_class_set_editor_only, "set_editor_only", 1),
        JS_PROP_GETSET
    );
}

static void define_light3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Param_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ENERGY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_INDIRECT_ENERGY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_VOLUMETRIC_FOG_ENERGY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SPECULAR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_RANGE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SIZE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ATTENUATION", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SPOT_ANGLE", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SPOT_ATTENUATION", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_MAX_DISTANCE", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_SPLIT_1_OFFSET", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_SPLIT_2_OFFSET", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_SPLIT_3_OFFSET", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_FADE_START", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_NORMAL_BIAS", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_BIAS", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_PANCAKE_SIZE", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_OPACITY", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SHADOW_BLUR", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_TRANSMITTANCE_BIAS", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_INTENSITY", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_MAX", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, ctor, "Param", Param_obj);
	JSValue BakeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BakeMode_obj, "BAKE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BakeMode_obj, "BAKE_STATIC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BakeMode_obj, "BAKE_DYNAMIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "BakeMode", BakeMode_obj);
}

static int js_light3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Light3D"] = class_id;
	classes_by_id[class_id] = "Light3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &light3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_light3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, light3d_class_proto_funcs, _countof(light3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, light3d_class_constructor, "Light3D", 0, JS_CFUNC_constructor, 0);
	define_light3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Light3D", ctor);

	return 0;
}

JSModuleDef *_js_init_light3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_light3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Light3D");
	return m;
}

JSModuleDef *js_init_light3d_module(JSContext *ctx) {
	return _js_init_light3d_module(ctx, "@godot/classes/light3d");
}

void __register_light3d() {
	js_init_light3d_module(js_context());
}

void register_light3d() {
	__register_light3d();
}