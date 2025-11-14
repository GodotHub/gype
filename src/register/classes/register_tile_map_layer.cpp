#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/tile_data.hpp>
#include <godot_cpp/classes/tile_map_pattern.hpp>
#include <godot_cpp/classes/tile_set.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tile_map_layer.hpp>
using namespace godot;

static void tile_map_layer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileMapLayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_map_layer_class_def = {
    "TileMapLayer",
    tile_map_layer_class_finalizer
};

static JSValue tile_map_layer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileMapLayer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileMapLayer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileMapLayer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileMapLayer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_map_layer_class_set_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_erase_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::erase_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_fix_invalid_tiles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::fix_invalid_tiles, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::clear, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_cell_source_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_cell_source_id, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_cell_atlas_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_cell_atlas_coords, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_cell_alternative_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_cell_alternative_tile, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_cell_tile_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_cell_tile_data, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_cell_flipped_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_cell_flipped_h, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_cell_flipped_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_cell_flipped_v, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_cell_transposed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_cell_transposed, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_used_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_used_cells, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_used_cells_by_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_used_cells_by_id, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_used_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_used_rect, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMapLayer::get_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_set_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_set_cells_terrain_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_cells_terrain_connect, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_set_cells_terrain_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_cells_terrain_path, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_has_body_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::has_body_rid, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_coords_for_body_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_coords_for_body_rid, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_update_internals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::update_internals, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_notify_runtime_tile_data_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::notify_runtime_tile_data_update, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_map_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMapLayer::map_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_surrounding_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMapLayer::get_surrounding_cells, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_neighbor_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_neighbor_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_map_to_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::map_to_local, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_local_to_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::local_to_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_set_tile_map_data_from_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_tile_map_data_from_array, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_tile_map_data_as_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedByteArray> *proxy = memnew(ObjectProxy<PackedByteArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedByteArray {
		TileMapLayer *obj = static_cast<TileMapLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tile_map_data_as_array();
	};
	proxy->setter = [this_val](const PackedByteArray &value) -> void {
		TileMapLayer *js_proxy = static_cast<TileMapLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tile_map_data_from_array(PackedByteArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedByteArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedByteArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue tile_map_layer_class_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_enabled, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_tile_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_tile_set, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_tile_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_tile_set, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_y_sort_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_y_sort_origin, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_y_sort_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_y_sort_origin, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_x_draw_order_reversed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_x_draw_order_reversed, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_x_draw_order_reversed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_x_draw_order_reversed, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_rendering_quadrant_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_rendering_quadrant_size, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_rendering_quadrant_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_rendering_quadrant_size, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_collision_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_collision_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_collision_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_collision_enabled, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_use_kinematic_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_use_kinematic_bodies, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_using_kinematic_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_using_kinematic_bodies, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_collision_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_collision_visibility_mode, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_collision_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_collision_visibility_mode, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_physics_quadrant_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_physics_quadrant_size, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_physics_quadrant_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_physics_quadrant_size, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_occlusion_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_occlusion_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_occlusion_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_occlusion_enabled, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_navigation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_navigation_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_is_navigation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::is_navigation_enabled, ctx, this_val, argc, argv);
}
static JSValue tile_map_layer_class_set_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_navigation_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_navigation_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_set_navigation_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapLayer::set_navigation_visibility_mode, ctx, this_val, argc, argv);
};
static JSValue tile_map_layer_class_get_navigation_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapLayer::get_navigation_visibility_mode, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry tile_map_layer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_cell", 4, &tile_map_layer_class_set_cell),
	JS_CFUNC_DEF("erase_cell", 1, &tile_map_layer_class_erase_cell),
	JS_CFUNC_DEF("fix_invalid_tiles", 0, &tile_map_layer_class_fix_invalid_tiles),
	JS_CFUNC_DEF("clear", 0, &tile_map_layer_class_clear),
	JS_CFUNC_DEF("get_cell_source_id", 1, &tile_map_layer_class_get_cell_source_id),
	JS_CFUNC_DEF("get_cell_atlas_coords", 1, &tile_map_layer_class_get_cell_atlas_coords),
	JS_CFUNC_DEF("get_cell_alternative_tile", 1, &tile_map_layer_class_get_cell_alternative_tile),
	JS_CFUNC_DEF("get_cell_tile_data", 1, &tile_map_layer_class_get_cell_tile_data),
	JS_CFUNC_DEF("is_cell_flipped_h", 1, &tile_map_layer_class_is_cell_flipped_h),
	JS_CFUNC_DEF("is_cell_flipped_v", 1, &tile_map_layer_class_is_cell_flipped_v),
	JS_CFUNC_DEF("is_cell_transposed", 1, &tile_map_layer_class_is_cell_transposed),
	JS_CFUNC_DEF("get_used_cells", 0, &tile_map_layer_class_get_used_cells),
	JS_CFUNC_DEF("get_used_cells_by_id", 3, &tile_map_layer_class_get_used_cells_by_id),
	JS_CFUNC_DEF("get_used_rect", 0, &tile_map_layer_class_get_used_rect),
	JS_CFUNC_DEF("get_pattern", 1, &tile_map_layer_class_get_pattern),
	JS_CFUNC_DEF("set_pattern", 2, &tile_map_layer_class_set_pattern),
	JS_CFUNC_DEF("set_cells_terrain_connect", 4, &tile_map_layer_class_set_cells_terrain_connect),
	JS_CFUNC_DEF("set_cells_terrain_path", 4, &tile_map_layer_class_set_cells_terrain_path),
	JS_CFUNC_DEF("has_body_rid", 1, &tile_map_layer_class_has_body_rid),
	JS_CFUNC_DEF("get_coords_for_body_rid", 1, &tile_map_layer_class_get_coords_for_body_rid),
	JS_CFUNC_DEF("update_internals", 0, &tile_map_layer_class_update_internals),
	JS_CFUNC_DEF("notify_runtime_tile_data_update", 0, &tile_map_layer_class_notify_runtime_tile_data_update),
	JS_CFUNC_DEF("map_pattern", 3, &tile_map_layer_class_map_pattern),
	JS_CFUNC_DEF("get_surrounding_cells", 1, &tile_map_layer_class_get_surrounding_cells),
	JS_CFUNC_DEF("get_neighbor_cell", 2, &tile_map_layer_class_get_neighbor_cell),
	JS_CFUNC_DEF("map_to_local", 1, &tile_map_layer_class_map_to_local),
	JS_CFUNC_DEF("local_to_map", 1, &tile_map_layer_class_local_to_map),
	JS_CFUNC_DEF("set_tile_map_data_from_array", 1, &tile_map_layer_class_set_tile_map_data_from_array),
	JS_CFUNC_DEF("get_tile_map_data_as_array", 0, &tile_map_layer_class_get_tile_map_data_as_array),
	JS_CFUNC_DEF("set_enabled", 1, &tile_map_layer_class_set_enabled),
	JS_CFUNC_DEF("is_enabled", 0, &tile_map_layer_class_is_enabled),
	JS_CFUNC_DEF("set_tile_set", 1, &tile_map_layer_class_set_tile_set),
	JS_CFUNC_DEF("get_tile_set", 0, &tile_map_layer_class_get_tile_set),
	JS_CFUNC_DEF("set_y_sort_origin", 1, &tile_map_layer_class_set_y_sort_origin),
	JS_CFUNC_DEF("get_y_sort_origin", 0, &tile_map_layer_class_get_y_sort_origin),
	JS_CFUNC_DEF("set_x_draw_order_reversed", 1, &tile_map_layer_class_set_x_draw_order_reversed),
	JS_CFUNC_DEF("is_x_draw_order_reversed", 0, &tile_map_layer_class_is_x_draw_order_reversed),
	JS_CFUNC_DEF("set_rendering_quadrant_size", 1, &tile_map_layer_class_set_rendering_quadrant_size),
	JS_CFUNC_DEF("get_rendering_quadrant_size", 0, &tile_map_layer_class_get_rendering_quadrant_size),
	JS_CFUNC_DEF("set_collision_enabled", 1, &tile_map_layer_class_set_collision_enabled),
	JS_CFUNC_DEF("is_collision_enabled", 0, &tile_map_layer_class_is_collision_enabled),
	JS_CFUNC_DEF("set_use_kinematic_bodies", 1, &tile_map_layer_class_set_use_kinematic_bodies),
	JS_CFUNC_DEF("is_using_kinematic_bodies", 0, &tile_map_layer_class_is_using_kinematic_bodies),
	JS_CFUNC_DEF("set_collision_visibility_mode", 1, &tile_map_layer_class_set_collision_visibility_mode),
	JS_CFUNC_DEF("get_collision_visibility_mode", 0, &tile_map_layer_class_get_collision_visibility_mode),
	JS_CFUNC_DEF("set_physics_quadrant_size", 1, &tile_map_layer_class_set_physics_quadrant_size),
	JS_CFUNC_DEF("get_physics_quadrant_size", 0, &tile_map_layer_class_get_physics_quadrant_size),
	JS_CFUNC_DEF("set_occlusion_enabled", 1, &tile_map_layer_class_set_occlusion_enabled),
	JS_CFUNC_DEF("is_occlusion_enabled", 0, &tile_map_layer_class_is_occlusion_enabled),
	JS_CFUNC_DEF("set_navigation_enabled", 1, &tile_map_layer_class_set_navigation_enabled),
	JS_CFUNC_DEF("is_navigation_enabled", 0, &tile_map_layer_class_is_navigation_enabled),
	JS_CFUNC_DEF("set_navigation_map", 1, &tile_map_layer_class_set_navigation_map),
	JS_CFUNC_DEF("get_navigation_map", 0, &tile_map_layer_class_get_navigation_map),
	JS_CFUNC_DEF("set_navigation_visibility_mode", 1, &tile_map_layer_class_set_navigation_visibility_mode),
	JS_CFUNC_DEF("get_navigation_visibility_mode", 0, &tile_map_layer_class_get_navigation_visibility_mode),
};


static JSValue tile_map_layer_class_get_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TileMapLayer *opaque = static_cast<TileMapLayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_tile_map_layer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_map_data"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_tile_map_data_as_array, "get_tile_map_data_as_array", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_tile_map_data_from_array, "set_tile_map_data_from_array", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled"),
        JS_NewCFunction(ctx, tile_map_layer_class_is_enabled, "is_enabled", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_enabled, "set_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_set"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_tile_set, "get_tile_set", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_tile_set, "set_tile_set", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "occlusion_enabled"),
        JS_NewCFunction(ctx, tile_map_layer_class_is_occlusion_enabled, "is_occlusion_enabled", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_occlusion_enabled, "set_occlusion_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "y_sort_origin"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_y_sort_origin, "get_y_sort_origin", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_y_sort_origin, "set_y_sort_origin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "x_draw_order_reversed"),
        JS_NewCFunction(ctx, tile_map_layer_class_is_x_draw_order_reversed, "is_x_draw_order_reversed", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_x_draw_order_reversed, "set_x_draw_order_reversed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rendering_quadrant_size"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_rendering_quadrant_size, "get_rendering_quadrant_size", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_rendering_quadrant_size, "set_rendering_quadrant_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_enabled"),
        JS_NewCFunction(ctx, tile_map_layer_class_is_collision_enabled, "is_collision_enabled", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_collision_enabled, "set_collision_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_kinematic_bodies"),
        JS_NewCFunction(ctx, tile_map_layer_class_is_using_kinematic_bodies, "is_using_kinematic_bodies", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_use_kinematic_bodies, "set_use_kinematic_bodies", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_visibility_mode"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_collision_visibility_mode, "get_collision_visibility_mode", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_collision_visibility_mode, "set_collision_visibility_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "physics_quadrant_size"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_physics_quadrant_size, "get_physics_quadrant_size", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_physics_quadrant_size, "set_physics_quadrant_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_enabled"),
        JS_NewCFunction(ctx, tile_map_layer_class_is_navigation_enabled, "is_navigation_enabled", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_navigation_enabled, "set_navigation_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_visibility_mode"),
        JS_NewCFunction(ctx, tile_map_layer_class_get_navigation_visibility_mode, "get_navigation_visibility_mode", 0),
        JS_NewCFunction(ctx, tile_map_layer_class_set_navigation_visibility_mode, "set_navigation_visibility_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "changed"),
		JS_NewCFunction(ctx, tile_map_layer_class_get_changed_signal, "get_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_tile_map_layer_enum(JSContext *ctx, JSValue proto) {
	JSValue DebugVisibilityMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DebugVisibilityMode_obj, "DEBUG_VISIBILITY_MODE_DEFAULT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DebugVisibilityMode_obj, "DEBUG_VISIBILITY_MODE_FORCE_HIDE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DebugVisibilityMode_obj, "DEBUG_VISIBILITY_MODE_FORCE_SHOW", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "DebugVisibilityMode", DebugVisibilityMode_obj);
}

static int js_tile_map_layer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileMapLayer"] = class_id;
	classes_by_id[class_id] = "TileMapLayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_map_layer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_map_layer_property(ctx, proto);
	define_tile_map_layer_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_map_layer_class_proto_funcs, _countof(tile_map_layer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_map_layer_class_constructor, "TileMapLayer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileMapLayer", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_map_layer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_map_layer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileMapLayer");
	return m;
}

JSModuleDef *js_init_tile_map_layer_module(JSContext *ctx) {
	return _js_init_tile_map_layer_module(ctx, "@godot/classes/tile_map_layer");
}

void __register_tile_map_layer() {
	js_init_tile_map_layer_module(js_context());
}

void register_tile_map_layer() {
	__register_tile_map_layer();
}