#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/light2d.hpp>
using namespace godot;

static void light2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Light2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef light2d_class_def = {
    "Light2D",
    light2d_class_finalizer
};

static JSValue light2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Light2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Light2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Light2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Light2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue light2d_class_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_enabled, ctx, this_val, argc, argv);
};
static JSValue light2d_class_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::is_enabled, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_editor_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_editor_only, ctx, this_val, argc, argv);
};
static JSValue light2d_class_is_editor_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::is_editor_only, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_color, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Light2D *obj = static_cast<Light2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Light2D *js_proxy = static_cast<Light2D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue light2d_class_set_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_energy, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_energy, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_z_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_z_range_min, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_z_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_z_range_min, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_z_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_z_range_max, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_z_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_z_range_max, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_layer_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_layer_range_min, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_layer_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_layer_range_min, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_layer_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_layer_range_max, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_layer_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_layer_range_max, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_item_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_item_cull_mask, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_item_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_item_cull_mask, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_item_shadow_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_item_shadow_cull_mask, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_item_shadow_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_item_shadow_cull_mask, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_shadow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_shadow_enabled, ctx, this_val, argc, argv);
};
static JSValue light2d_class_is_shadow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::is_shadow_enabled, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_shadow_smooth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_shadow_smooth, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_shadow_smooth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_shadow_smooth, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_shadow_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_shadow_filter, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_shadow_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_shadow_filter, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_shadow_color, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Light2D *obj = static_cast<Light2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shadow_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Light2D *js_proxy = static_cast<Light2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shadow_color(value);
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
static JSValue light2d_class_set_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_blend_mode, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_blend_mode, ctx, this_val, argc, argv);
}
static JSValue light2d_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Light2D::set_height, ctx, this_val, argc, argv);
};
static JSValue light2d_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Light2D::get_height, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry light2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_enabled", 1, &light2d_class_set_enabled),
	JS_CFUNC_DEF("is_enabled", 0, &light2d_class_is_enabled),
	JS_CFUNC_DEF("set_editor_only", 1, &light2d_class_set_editor_only),
	JS_CFUNC_DEF("is_editor_only", 0, &light2d_class_is_editor_only),
	JS_CFUNC_DEF("set_color", 1, &light2d_class_set_color),
	JS_CFUNC_DEF("get_color", 0, &light2d_class_get_color),
	JS_CFUNC_DEF("set_energy", 1, &light2d_class_set_energy),
	JS_CFUNC_DEF("get_energy", 0, &light2d_class_get_energy),
	JS_CFUNC_DEF("set_z_range_min", 1, &light2d_class_set_z_range_min),
	JS_CFUNC_DEF("get_z_range_min", 0, &light2d_class_get_z_range_min),
	JS_CFUNC_DEF("set_z_range_max", 1, &light2d_class_set_z_range_max),
	JS_CFUNC_DEF("get_z_range_max", 0, &light2d_class_get_z_range_max),
	JS_CFUNC_DEF("set_layer_range_min", 1, &light2d_class_set_layer_range_min),
	JS_CFUNC_DEF("get_layer_range_min", 0, &light2d_class_get_layer_range_min),
	JS_CFUNC_DEF("set_layer_range_max", 1, &light2d_class_set_layer_range_max),
	JS_CFUNC_DEF("get_layer_range_max", 0, &light2d_class_get_layer_range_max),
	JS_CFUNC_DEF("set_item_cull_mask", 1, &light2d_class_set_item_cull_mask),
	JS_CFUNC_DEF("get_item_cull_mask", 0, &light2d_class_get_item_cull_mask),
	JS_CFUNC_DEF("set_item_shadow_cull_mask", 1, &light2d_class_set_item_shadow_cull_mask),
	JS_CFUNC_DEF("get_item_shadow_cull_mask", 0, &light2d_class_get_item_shadow_cull_mask),
	JS_CFUNC_DEF("set_shadow_enabled", 1, &light2d_class_set_shadow_enabled),
	JS_CFUNC_DEF("is_shadow_enabled", 0, &light2d_class_is_shadow_enabled),
	JS_CFUNC_DEF("set_shadow_smooth", 1, &light2d_class_set_shadow_smooth),
	JS_CFUNC_DEF("get_shadow_smooth", 0, &light2d_class_get_shadow_smooth),
	JS_CFUNC_DEF("set_shadow_filter", 1, &light2d_class_set_shadow_filter),
	JS_CFUNC_DEF("get_shadow_filter", 0, &light2d_class_get_shadow_filter),
	JS_CFUNC_DEF("set_shadow_color", 1, &light2d_class_set_shadow_color),
	JS_CFUNC_DEF("get_shadow_color", 0, &light2d_class_get_shadow_color),
	JS_CFUNC_DEF("set_blend_mode", 1, &light2d_class_set_blend_mode),
	JS_CFUNC_DEF("get_blend_mode", 0, &light2d_class_get_blend_mode),
	JS_CFUNC_DEF("set_height", 1, &light2d_class_set_height),
	JS_CFUNC_DEF("get_height", 0, &light2d_class_get_height),
};




static void define_light2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled"),
        JS_NewCFunction(ctx, light2d_class_is_enabled, "is_enabled", 0),
        JS_NewCFunction(ctx, light2d_class_set_enabled, "set_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editor_only"),
        JS_NewCFunction(ctx, light2d_class_is_editor_only, "is_editor_only", 0),
        JS_NewCFunction(ctx, light2d_class_set_editor_only, "set_editor_only", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, light2d_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, light2d_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "energy"),
        JS_NewCFunction(ctx, light2d_class_get_energy, "get_energy", 0),
        JS_NewCFunction(ctx, light2d_class_set_energy, "set_energy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_mode"),
        JS_NewCFunction(ctx, light2d_class_get_blend_mode, "get_blend_mode", 0),
        JS_NewCFunction(ctx, light2d_class_set_blend_mode, "set_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_z_min"),
        JS_NewCFunction(ctx, light2d_class_get_z_range_min, "get_z_range_min", 0),
        JS_NewCFunction(ctx, light2d_class_set_z_range_min, "set_z_range_min", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_z_max"),
        JS_NewCFunction(ctx, light2d_class_get_z_range_max, "get_z_range_max", 0),
        JS_NewCFunction(ctx, light2d_class_set_z_range_max, "set_z_range_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_layer_min"),
        JS_NewCFunction(ctx, light2d_class_get_layer_range_min, "get_layer_range_min", 0),
        JS_NewCFunction(ctx, light2d_class_set_layer_range_min, "set_layer_range_min", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_layer_max"),
        JS_NewCFunction(ctx, light2d_class_get_layer_range_max, "get_layer_range_max", 0),
        JS_NewCFunction(ctx, light2d_class_set_layer_range_max, "set_layer_range_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_item_cull_mask"),
        JS_NewCFunction(ctx, light2d_class_get_item_cull_mask, "get_item_cull_mask", 0),
        JS_NewCFunction(ctx, light2d_class_set_item_cull_mask, "set_item_cull_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_enabled"),
        JS_NewCFunction(ctx, light2d_class_is_shadow_enabled, "is_shadow_enabled", 0),
        JS_NewCFunction(ctx, light2d_class_set_shadow_enabled, "set_shadow_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_color"),
        JS_NewCFunction(ctx, light2d_class_get_shadow_color, "get_shadow_color", 0),
        JS_NewCFunction(ctx, light2d_class_set_shadow_color, "set_shadow_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_filter"),
        JS_NewCFunction(ctx, light2d_class_get_shadow_filter, "get_shadow_filter", 0),
        JS_NewCFunction(ctx, light2d_class_set_shadow_filter, "set_shadow_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_filter_smooth"),
        JS_NewCFunction(ctx, light2d_class_get_shadow_smooth, "get_shadow_smooth", 0),
        JS_NewCFunction(ctx, light2d_class_set_shadow_smooth, "set_shadow_smooth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_item_cull_mask"),
        JS_NewCFunction(ctx, light2d_class_get_item_shadow_cull_mask, "get_item_shadow_cull_mask", 0),
        JS_NewCFunction(ctx, light2d_class_set_item_shadow_cull_mask, "set_item_shadow_cull_mask", 1),
        JS_PROP_GETSET
    );
}

static void define_light2d_enum(JSContext *ctx, JSValue ctor) {
	JSValue ShadowFilter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShadowFilter_obj, "SHADOW_FILTER_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShadowFilter_obj, "SHADOW_FILTER_PCF5", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShadowFilter_obj, "SHADOW_FILTER_PCF13", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ShadowFilter", ShadowFilter_obj);
	JSValue BlendMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_ADD", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_SUB", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_MIX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "BlendMode", BlendMode_obj);
}

static int js_light2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Light2D"] = class_id;
	classes_by_id[class_id] = "Light2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &light2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_light2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, light2d_class_proto_funcs, _countof(light2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, light2d_class_constructor, "Light2D", 0, JS_CFUNC_constructor, 0);
	define_light2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Light2D", ctor);

	return 0;
}

JSModuleDef *_js_init_light2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_light2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Light2D");
	return m;
}

JSModuleDef *js_init_light2d_module(JSContext *ctx) {
	return _js_init_light2d_module(ctx, "@godot/classes/light2d");
}

void __register_light2d() {
	js_init_light2d_module(js_context());
}

void register_light2d() {
	__register_light2d();
}