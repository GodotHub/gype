#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/procedural_sky_material.hpp>
using namespace godot;

static void procedural_sky_material_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ProceduralSkyMaterial"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef procedural_sky_material_class_def = {
    "ProceduralSkyMaterial",
    procedural_sky_material_class_finalizer
};

static JSValue procedural_sky_material_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ProceduralSkyMaterial"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ProceduralSkyMaterial *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ProceduralSkyMaterial *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ProceduralSkyMaterial);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue procedural_sky_material_class_set_sky_top_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sky_top_color, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sky_top_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ProceduralSkyMaterial *obj = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_sky_top_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ProceduralSkyMaterial *js_proxy = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_sky_top_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue procedural_sky_material_class_set_sky_horizon_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sky_horizon_color, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sky_horizon_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ProceduralSkyMaterial *obj = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_sky_horizon_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ProceduralSkyMaterial *js_proxy = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_sky_horizon_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue procedural_sky_material_class_set_sky_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sky_curve, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sky_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_sky_curve, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_sky_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sky_energy_multiplier, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sky_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_sky_energy_multiplier, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_sky_cover(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sky_cover, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sky_cover(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_sky_cover, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_sky_cover_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sky_cover_modulate, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sky_cover_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ProceduralSkyMaterial *obj = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_sky_cover_modulate();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ProceduralSkyMaterial *js_proxy = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_sky_cover_modulate(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue procedural_sky_material_class_set_ground_bottom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_ground_bottom_color, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_ground_bottom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ProceduralSkyMaterial *obj = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_ground_bottom_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ProceduralSkyMaterial *js_proxy = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_ground_bottom_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue procedural_sky_material_class_set_ground_horizon_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_ground_horizon_color, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_ground_horizon_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ProceduralSkyMaterial *obj = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_ground_horizon_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ProceduralSkyMaterial *js_proxy = static_cast<ProceduralSkyMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_ground_horizon_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue procedural_sky_material_class_set_ground_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_ground_curve, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_ground_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_ground_curve, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_ground_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_ground_energy_multiplier, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_ground_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_ground_energy_multiplier, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_sun_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sun_angle_max, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sun_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_sun_angle_max, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_sun_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_sun_curve, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_sun_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_sun_curve, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_use_debanding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_use_debanding, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_use_debanding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_use_debanding, ctx, this_val, argc, argv);
}
static JSValue procedural_sky_material_class_set_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProceduralSkyMaterial::set_energy_multiplier, ctx, this_val, argc, argv);
};
static JSValue procedural_sky_material_class_get_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProceduralSkyMaterial::get_energy_multiplier, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry procedural_sky_material_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_sky_top_color", 1, &procedural_sky_material_class_set_sky_top_color),
	JS_CFUNC_DEF("get_sky_top_color", 0, &procedural_sky_material_class_get_sky_top_color),
	JS_CFUNC_DEF("set_sky_horizon_color", 1, &procedural_sky_material_class_set_sky_horizon_color),
	JS_CFUNC_DEF("get_sky_horizon_color", 0, &procedural_sky_material_class_get_sky_horizon_color),
	JS_CFUNC_DEF("set_sky_curve", 1, &procedural_sky_material_class_set_sky_curve),
	JS_CFUNC_DEF("get_sky_curve", 0, &procedural_sky_material_class_get_sky_curve),
	JS_CFUNC_DEF("set_sky_energy_multiplier", 1, &procedural_sky_material_class_set_sky_energy_multiplier),
	JS_CFUNC_DEF("get_sky_energy_multiplier", 0, &procedural_sky_material_class_get_sky_energy_multiplier),
	JS_CFUNC_DEF("set_sky_cover", 1, &procedural_sky_material_class_set_sky_cover),
	JS_CFUNC_DEF("get_sky_cover", 0, &procedural_sky_material_class_get_sky_cover),
	JS_CFUNC_DEF("set_sky_cover_modulate", 1, &procedural_sky_material_class_set_sky_cover_modulate),
	JS_CFUNC_DEF("get_sky_cover_modulate", 0, &procedural_sky_material_class_get_sky_cover_modulate),
	JS_CFUNC_DEF("set_ground_bottom_color", 1, &procedural_sky_material_class_set_ground_bottom_color),
	JS_CFUNC_DEF("get_ground_bottom_color", 0, &procedural_sky_material_class_get_ground_bottom_color),
	JS_CFUNC_DEF("set_ground_horizon_color", 1, &procedural_sky_material_class_set_ground_horizon_color),
	JS_CFUNC_DEF("get_ground_horizon_color", 0, &procedural_sky_material_class_get_ground_horizon_color),
	JS_CFUNC_DEF("set_ground_curve", 1, &procedural_sky_material_class_set_ground_curve),
	JS_CFUNC_DEF("get_ground_curve", 0, &procedural_sky_material_class_get_ground_curve),
	JS_CFUNC_DEF("set_ground_energy_multiplier", 1, &procedural_sky_material_class_set_ground_energy_multiplier),
	JS_CFUNC_DEF("get_ground_energy_multiplier", 0, &procedural_sky_material_class_get_ground_energy_multiplier),
	JS_CFUNC_DEF("set_sun_angle_max", 1, &procedural_sky_material_class_set_sun_angle_max),
	JS_CFUNC_DEF("get_sun_angle_max", 0, &procedural_sky_material_class_get_sun_angle_max),
	JS_CFUNC_DEF("set_sun_curve", 1, &procedural_sky_material_class_set_sun_curve),
	JS_CFUNC_DEF("get_sun_curve", 0, &procedural_sky_material_class_get_sun_curve),
	JS_CFUNC_DEF("set_use_debanding", 1, &procedural_sky_material_class_set_use_debanding),
	JS_CFUNC_DEF("get_use_debanding", 0, &procedural_sky_material_class_get_use_debanding),
	JS_CFUNC_DEF("set_energy_multiplier", 1, &procedural_sky_material_class_set_energy_multiplier),
	JS_CFUNC_DEF("get_energy_multiplier", 0, &procedural_sky_material_class_get_energy_multiplier),
};




static void define_procedural_sky_material_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_top_color"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sky_top_color, "get_sky_top_color", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sky_top_color, "set_sky_top_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_horizon_color"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sky_horizon_color, "get_sky_horizon_color", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sky_horizon_color, "set_sky_horizon_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_curve"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sky_curve, "get_sky_curve", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sky_curve, "set_sky_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_energy_multiplier"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sky_energy_multiplier, "get_sky_energy_multiplier", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sky_energy_multiplier, "set_sky_energy_multiplier", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_cover"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sky_cover, "get_sky_cover", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sky_cover, "set_sky_cover", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_cover_modulate"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sky_cover_modulate, "get_sky_cover_modulate", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sky_cover_modulate, "set_sky_cover_modulate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ground_bottom_color"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_ground_bottom_color, "get_ground_bottom_color", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_ground_bottom_color, "set_ground_bottom_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ground_horizon_color"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_ground_horizon_color, "get_ground_horizon_color", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_ground_horizon_color, "set_ground_horizon_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ground_curve"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_ground_curve, "get_ground_curve", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_ground_curve, "set_ground_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ground_energy_multiplier"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_ground_energy_multiplier, "get_ground_energy_multiplier", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_ground_energy_multiplier, "set_ground_energy_multiplier", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sun_angle_max"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sun_angle_max, "get_sun_angle_max", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sun_angle_max, "set_sun_angle_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sun_curve"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_sun_curve, "get_sun_curve", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_sun_curve, "set_sun_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_debanding"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_use_debanding, "get_use_debanding", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_use_debanding, "set_use_debanding", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "energy_multiplier"),
        JS_NewCFunction(ctx, procedural_sky_material_class_get_energy_multiplier, "get_energy_multiplier", 0),
        JS_NewCFunction(ctx, procedural_sky_material_class_set_energy_multiplier, "set_energy_multiplier", 1),
        JS_PROP_GETSET
    );
}

static void define_procedural_sky_material_enum(JSContext *ctx, JSValue ctor) {
}

static int js_procedural_sky_material_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ProceduralSkyMaterial"] = class_id;
	classes_by_id[class_id] = "ProceduralSkyMaterial";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &procedural_sky_material_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Material"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_procedural_sky_material_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, procedural_sky_material_class_proto_funcs, _countof(procedural_sky_material_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, procedural_sky_material_class_constructor, "ProceduralSkyMaterial", 0, JS_CFUNC_constructor, 0);
	define_procedural_sky_material_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ProceduralSkyMaterial", ctor);

	return 0;
}

JSModuleDef *_js_init_procedural_sky_material_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/material';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_procedural_sky_material_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ProceduralSkyMaterial");
	return m;
}

JSModuleDef *js_init_procedural_sky_material_module(JSContext *ctx) {
	return _js_init_procedural_sky_material_module(ctx, "@godot/classes/procedural_sky_material");
}

void __register_procedural_sky_material() {
	js_init_procedural_sky_material_module(js_context());
}

void register_procedural_sky_material() {
	__register_procedural_sky_material();
}