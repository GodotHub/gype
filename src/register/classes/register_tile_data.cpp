#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/navigation_polygon.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/occluder_polygon2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tile_data.hpp>
using namespace godot;

static void tile_data_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileData"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_data_class_def = {
    "TileData",
    tile_data_class_finalizer
};

static JSValue tile_data_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileData"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileData *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileData *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileData);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_data_class_set_flip_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_flip_h, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_flip_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_flip_h, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_flip_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_flip_v, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_flip_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_flip_v, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_transpose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_transpose, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_transpose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_transpose, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_material, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_material, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_texture_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_texture_origin, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_texture_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		TileData *obj = static_cast<TileData *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_texture_origin();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		TileData *js_proxy = static_cast<TileData *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_texture_origin(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue tile_data_class_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_modulate, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		TileData *obj = static_cast<TileData *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_modulate();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		TileData *js_proxy = static_cast<TileData *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_modulate(value);
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
static JSValue tile_data_class_set_z_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_z_index, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_z_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_z_index, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_y_sort_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_y_sort_origin, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_y_sort_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_y_sort_origin, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_occluder_polygons_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_occluder_polygons_count, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_occluder_polygons_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_occluder_polygons_count, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_add_occluder_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::add_occluder_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_remove_occluder_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::remove_occluder_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_occluder_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_occluder_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_occluder_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_occluder_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_occluder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_occluder, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_occluder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_occluder, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_constant_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_constant_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_constant_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_constant_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_constant_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_constant_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_constant_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_constant_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_collision_polygons_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_collision_polygons_count, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_collision_polygons_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_collision_polygons_count, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_add_collision_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::add_collision_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_remove_collision_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::remove_collision_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_collision_polygon_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_collision_polygon_points, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_collision_polygon_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_collision_polygon_points, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_collision_polygon_one_way(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_collision_polygon_one_way, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_is_collision_polygon_one_way(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::is_collision_polygon_one_way, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_collision_polygon_one_way_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_collision_polygon_one_way_margin, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_collision_polygon_one_way_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_collision_polygon_one_way_margin, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_terrain_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_terrain_set, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_terrain_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_terrain_set, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_terrain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_terrain, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_terrain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_terrain, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_terrain_peering_bit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_terrain_peering_bit, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_terrain_peering_bit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_terrain_peering_bit, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_is_valid_terrain_peering_bit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::is_valid_terrain_peering_bit, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_navigation_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_navigation_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_navigation_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_navigation_polygon, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_probability(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_probability, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_probability(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_probability, ctx, this_val, argc, argv);
}
static JSValue tile_data_class_set_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_custom_data, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_custom_data, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_has_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::has_custom_data, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_set_custom_data_by_layer_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileData::set_custom_data_by_layer_id, ctx, this_val, argc, argv);
};
static JSValue tile_data_class_get_custom_data_by_layer_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileData::get_custom_data_by_layer_id, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry tile_data_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_flip_h", 1, &tile_data_class_set_flip_h),
	JS_CFUNC_DEF("get_flip_h", 0, &tile_data_class_get_flip_h),
	JS_CFUNC_DEF("set_flip_v", 1, &tile_data_class_set_flip_v),
	JS_CFUNC_DEF("get_flip_v", 0, &tile_data_class_get_flip_v),
	JS_CFUNC_DEF("set_transpose", 1, &tile_data_class_set_transpose),
	JS_CFUNC_DEF("get_transpose", 0, &tile_data_class_get_transpose),
	JS_CFUNC_DEF("set_material", 1, &tile_data_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &tile_data_class_get_material),
	JS_CFUNC_DEF("set_texture_origin", 1, &tile_data_class_set_texture_origin),
	JS_CFUNC_DEF("get_texture_origin", 0, &tile_data_class_get_texture_origin),
	JS_CFUNC_DEF("set_modulate", 1, &tile_data_class_set_modulate),
	JS_CFUNC_DEF("get_modulate", 0, &tile_data_class_get_modulate),
	JS_CFUNC_DEF("set_z_index", 1, &tile_data_class_set_z_index),
	JS_CFUNC_DEF("get_z_index", 0, &tile_data_class_get_z_index),
	JS_CFUNC_DEF("set_y_sort_origin", 1, &tile_data_class_set_y_sort_origin),
	JS_CFUNC_DEF("get_y_sort_origin", 0, &tile_data_class_get_y_sort_origin),
	JS_CFUNC_DEF("set_occluder_polygons_count", 2, &tile_data_class_set_occluder_polygons_count),
	JS_CFUNC_DEF("get_occluder_polygons_count", 1, &tile_data_class_get_occluder_polygons_count),
	JS_CFUNC_DEF("add_occluder_polygon", 1, &tile_data_class_add_occluder_polygon),
	JS_CFUNC_DEF("remove_occluder_polygon", 2, &tile_data_class_remove_occluder_polygon),
	JS_CFUNC_DEF("set_occluder_polygon", 3, &tile_data_class_set_occluder_polygon),
	JS_CFUNC_DEF("get_occluder_polygon", 5, &tile_data_class_get_occluder_polygon),
	JS_CFUNC_DEF("set_occluder", 2, &tile_data_class_set_occluder),
	JS_CFUNC_DEF("get_occluder", 4, &tile_data_class_get_occluder),
	JS_CFUNC_DEF("set_constant_linear_velocity", 2, &tile_data_class_set_constant_linear_velocity),
	JS_CFUNC_DEF("get_constant_linear_velocity", 1, &tile_data_class_get_constant_linear_velocity),
	JS_CFUNC_DEF("set_constant_angular_velocity", 2, &tile_data_class_set_constant_angular_velocity),
	JS_CFUNC_DEF("get_constant_angular_velocity", 1, &tile_data_class_get_constant_angular_velocity),
	JS_CFUNC_DEF("set_collision_polygons_count", 2, &tile_data_class_set_collision_polygons_count),
	JS_CFUNC_DEF("get_collision_polygons_count", 1, &tile_data_class_get_collision_polygons_count),
	JS_CFUNC_DEF("add_collision_polygon", 1, &tile_data_class_add_collision_polygon),
	JS_CFUNC_DEF("remove_collision_polygon", 2, &tile_data_class_remove_collision_polygon),
	JS_CFUNC_DEF("set_collision_polygon_points", 3, &tile_data_class_set_collision_polygon_points),
	JS_CFUNC_DEF("get_collision_polygon_points", 2, &tile_data_class_get_collision_polygon_points),
	JS_CFUNC_DEF("set_collision_polygon_one_way", 3, &tile_data_class_set_collision_polygon_one_way),
	JS_CFUNC_DEF("is_collision_polygon_one_way", 2, &tile_data_class_is_collision_polygon_one_way),
	JS_CFUNC_DEF("set_collision_polygon_one_way_margin", 3, &tile_data_class_set_collision_polygon_one_way_margin),
	JS_CFUNC_DEF("get_collision_polygon_one_way_margin", 2, &tile_data_class_get_collision_polygon_one_way_margin),
	JS_CFUNC_DEF("set_terrain_set", 1, &tile_data_class_set_terrain_set),
	JS_CFUNC_DEF("get_terrain_set", 0, &tile_data_class_get_terrain_set),
	JS_CFUNC_DEF("set_terrain", 1, &tile_data_class_set_terrain),
	JS_CFUNC_DEF("get_terrain", 0, &tile_data_class_get_terrain),
	JS_CFUNC_DEF("set_terrain_peering_bit", 2, &tile_data_class_set_terrain_peering_bit),
	JS_CFUNC_DEF("get_terrain_peering_bit", 1, &tile_data_class_get_terrain_peering_bit),
	JS_CFUNC_DEF("is_valid_terrain_peering_bit", 1, &tile_data_class_is_valid_terrain_peering_bit),
	JS_CFUNC_DEF("set_navigation_polygon", 2, &tile_data_class_set_navigation_polygon),
	JS_CFUNC_DEF("get_navigation_polygon", 4, &tile_data_class_get_navigation_polygon),
	JS_CFUNC_DEF("set_probability", 1, &tile_data_class_set_probability),
	JS_CFUNC_DEF("get_probability", 0, &tile_data_class_get_probability),
	JS_CFUNC_DEF("set_custom_data", 2, &tile_data_class_set_custom_data),
	JS_CFUNC_DEF("get_custom_data", 1, &tile_data_class_get_custom_data),
	JS_CFUNC_DEF("has_custom_data", 1, &tile_data_class_has_custom_data),
	JS_CFUNC_DEF("set_custom_data_by_layer_id", 2, &tile_data_class_set_custom_data_by_layer_id),
	JS_CFUNC_DEF("get_custom_data_by_layer_id", 1, &tile_data_class_get_custom_data_by_layer_id),
};


static JSValue tile_data_class_get_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TileData *opaque = static_cast<TileData *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_tile_data_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flip_h"),
        JS_NewCFunction(ctx, tile_data_class_get_flip_h, "get_flip_h", 0),
        JS_NewCFunction(ctx, tile_data_class_set_flip_h, "set_flip_h", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flip_v"),
        JS_NewCFunction(ctx, tile_data_class_get_flip_v, "get_flip_v", 0),
        JS_NewCFunction(ctx, tile_data_class_set_flip_v, "set_flip_v", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transpose"),
        JS_NewCFunction(ctx, tile_data_class_get_transpose, "get_transpose", 0),
        JS_NewCFunction(ctx, tile_data_class_set_transpose, "set_transpose", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_origin"),
        JS_NewCFunction(ctx, tile_data_class_get_texture_origin, "get_texture_origin", 0),
        JS_NewCFunction(ctx, tile_data_class_set_texture_origin, "set_texture_origin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modulate"),
        JS_NewCFunction(ctx, tile_data_class_get_modulate, "get_modulate", 0),
        JS_NewCFunction(ctx, tile_data_class_set_modulate, "set_modulate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, tile_data_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, tile_data_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "z_index"),
        JS_NewCFunction(ctx, tile_data_class_get_z_index, "get_z_index", 0),
        JS_NewCFunction(ctx, tile_data_class_set_z_index, "set_z_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "y_sort_origin"),
        JS_NewCFunction(ctx, tile_data_class_get_y_sort_origin, "get_y_sort_origin", 0),
        JS_NewCFunction(ctx, tile_data_class_set_y_sort_origin, "set_y_sort_origin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "terrain_set"),
        JS_NewCFunction(ctx, tile_data_class_get_terrain_set, "get_terrain_set", 0),
        JS_NewCFunction(ctx, tile_data_class_set_terrain_set, "set_terrain_set", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "terrain"),
        JS_NewCFunction(ctx, tile_data_class_get_terrain, "get_terrain", 0),
        JS_NewCFunction(ctx, tile_data_class_set_terrain, "set_terrain", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "probability"),
        JS_NewCFunction(ctx, tile_data_class_get_probability, "get_probability", 0),
        JS_NewCFunction(ctx, tile_data_class_set_probability, "set_probability", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "changed"),
		JS_NewCFunction(ctx, tile_data_class_get_changed_signal, "get_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_tile_data_enum(JSContext *ctx, JSValue ctor) {
}

static int js_tile_data_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileData"] = class_id;
	classes_by_id[class_id] = "TileData";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_data_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_data_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_data_class_proto_funcs, _countof(tile_data_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_data_class_constructor, "TileData", 0, JS_CFUNC_constructor, 0);
	define_tile_data_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileData", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_data_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_data_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileData");
	return m;
}

JSModuleDef *js_init_tile_data_module(JSContext *ctx) {
	return _js_init_tile_data_module(ctx, "@godot/classes/tile_data");
}

void __register_tile_data() {
	js_init_tile_data_module(js_context());
}

void register_tile_data() {
	__register_tile_data();
}