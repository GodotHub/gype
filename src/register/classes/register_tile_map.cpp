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
#include <godot_cpp/classes/tile_map.hpp>
using namespace godot;

static void tile_map_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileMap"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_map_class_def = {
    "TileMap",
    tile_map_class_finalizer
};

static JSValue tile_map_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileMap"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileMap *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileMap *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileMap);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_map_class_set_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_navigation_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_navigation_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_force_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::force_update, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_tileset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_tileset, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_tileset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_tileset, ctx, this_val, argc, argv);
}
static JSValue tile_map_class_set_rendering_quadrant_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_rendering_quadrant_size, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_rendering_quadrant_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_rendering_quadrant_size, ctx, this_val, argc, argv);
}
static JSValue tile_map_class_get_layers_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_layers_count, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_add_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::add_layer, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_move_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::move_layer, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_remove_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::remove_layer, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_name, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_layer_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_layer_name, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_layer_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_layer_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_modulate, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_layer_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_layer_modulate, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_y_sort_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_y_sort_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_layer_y_sort_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_layer_y_sort_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_y_sort_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_y_sort_origin, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_layer_y_sort_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_layer_y_sort_origin, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_z_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_z_index, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_layer_z_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_layer_z_index, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_navigation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_navigation_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_layer_navigation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_layer_navigation_enabled, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_layer_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_layer_navigation_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_layer_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_layer_navigation_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_collision_animatable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_collision_animatable, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_collision_animatable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_collision_animatable, ctx, this_val, argc, argv);
}
static JSValue tile_map_class_set_collision_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_collision_visibility_mode, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_collision_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_collision_visibility_mode, ctx, this_val, argc, argv);
}
static JSValue tile_map_class_set_navigation_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_navigation_visibility_mode, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_navigation_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_navigation_visibility_mode, ctx, this_val, argc, argv);
}
static JSValue tile_map_class_set_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_erase_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::erase_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_cell_source_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_cell_source_id, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_cell_atlas_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_cell_atlas_coords, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_cell_alternative_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_cell_alternative_tile, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_cell_tile_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_cell_tile_data, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_cell_flipped_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_cell_flipped_h, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_cell_flipped_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_cell_flipped_v, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_is_cell_transposed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::is_cell_transposed, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_coords_for_body_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMap::get_coords_for_body_rid, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_layer_for_body_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMap::get_layer_for_body_rid, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMap::get_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_map_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMap::map_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_cells_terrain_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_cells_terrain_connect, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_set_cells_terrain_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::set_cells_terrain_path, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_fix_invalid_tiles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::fix_invalid_tiles, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_clear_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::clear_layer, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::clear, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_update_internals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::update_internals, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_notify_runtime_tile_data_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMap::notify_runtime_tile_data_update, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_surrounding_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileMap::get_surrounding_cells, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_used_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_used_cells, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_used_cells_by_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_used_cells_by_id, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_used_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_used_rect, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_map_to_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::map_to_local, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_local_to_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::local_to_map, ctx, this_val, argc, argv);
};
static JSValue tile_map_class_get_neighbor_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMap::get_neighbor_cell, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry tile_map_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_navigation_map", 2, &tile_map_class_set_navigation_map),
	JS_CFUNC_DEF("get_navigation_map", 1, &tile_map_class_get_navigation_map),
	JS_CFUNC_DEF("force_update", 1, &tile_map_class_force_update),
	JS_CFUNC_DEF("set_tileset", 1, &tile_map_class_set_tileset),
	JS_CFUNC_DEF("get_tileset", 0, &tile_map_class_get_tileset),
	JS_CFUNC_DEF("set_rendering_quadrant_size", 1, &tile_map_class_set_rendering_quadrant_size),
	JS_CFUNC_DEF("get_rendering_quadrant_size", 0, &tile_map_class_get_rendering_quadrant_size),
	JS_CFUNC_DEF("get_layers_count", 0, &tile_map_class_get_layers_count),
	JS_CFUNC_DEF("add_layer", 1, &tile_map_class_add_layer),
	JS_CFUNC_DEF("move_layer", 2, &tile_map_class_move_layer),
	JS_CFUNC_DEF("remove_layer", 1, &tile_map_class_remove_layer),
	JS_CFUNC_DEF("set_layer_name", 2, &tile_map_class_set_layer_name),
	JS_CFUNC_DEF("get_layer_name", 1, &tile_map_class_get_layer_name),
	JS_CFUNC_DEF("set_layer_enabled", 2, &tile_map_class_set_layer_enabled),
	JS_CFUNC_DEF("is_layer_enabled", 1, &tile_map_class_is_layer_enabled),
	JS_CFUNC_DEF("set_layer_modulate", 2, &tile_map_class_set_layer_modulate),
	JS_CFUNC_DEF("get_layer_modulate", 1, &tile_map_class_get_layer_modulate),
	JS_CFUNC_DEF("set_layer_y_sort_enabled", 2, &tile_map_class_set_layer_y_sort_enabled),
	JS_CFUNC_DEF("is_layer_y_sort_enabled", 1, &tile_map_class_is_layer_y_sort_enabled),
	JS_CFUNC_DEF("set_layer_y_sort_origin", 2, &tile_map_class_set_layer_y_sort_origin),
	JS_CFUNC_DEF("get_layer_y_sort_origin", 1, &tile_map_class_get_layer_y_sort_origin),
	JS_CFUNC_DEF("set_layer_z_index", 2, &tile_map_class_set_layer_z_index),
	JS_CFUNC_DEF("get_layer_z_index", 1, &tile_map_class_get_layer_z_index),
	JS_CFUNC_DEF("set_layer_navigation_enabled", 2, &tile_map_class_set_layer_navigation_enabled),
	JS_CFUNC_DEF("is_layer_navigation_enabled", 1, &tile_map_class_is_layer_navigation_enabled),
	JS_CFUNC_DEF("set_layer_navigation_map", 2, &tile_map_class_set_layer_navigation_map),
	JS_CFUNC_DEF("get_layer_navigation_map", 1, &tile_map_class_get_layer_navigation_map),
	JS_CFUNC_DEF("set_collision_animatable", 1, &tile_map_class_set_collision_animatable),
	JS_CFUNC_DEF("is_collision_animatable", 0, &tile_map_class_is_collision_animatable),
	JS_CFUNC_DEF("set_collision_visibility_mode", 1, &tile_map_class_set_collision_visibility_mode),
	JS_CFUNC_DEF("get_collision_visibility_mode", 0, &tile_map_class_get_collision_visibility_mode),
	JS_CFUNC_DEF("set_navigation_visibility_mode", 1, &tile_map_class_set_navigation_visibility_mode),
	JS_CFUNC_DEF("get_navigation_visibility_mode", 0, &tile_map_class_get_navigation_visibility_mode),
	JS_CFUNC_DEF("set_cell", 5, &tile_map_class_set_cell),
	JS_CFUNC_DEF("erase_cell", 2, &tile_map_class_erase_cell),
	JS_CFUNC_DEF("get_cell_source_id", 3, &tile_map_class_get_cell_source_id),
	JS_CFUNC_DEF("get_cell_atlas_coords", 3, &tile_map_class_get_cell_atlas_coords),
	JS_CFUNC_DEF("get_cell_alternative_tile", 3, &tile_map_class_get_cell_alternative_tile),
	JS_CFUNC_DEF("get_cell_tile_data", 3, &tile_map_class_get_cell_tile_data),
	JS_CFUNC_DEF("is_cell_flipped_h", 3, &tile_map_class_is_cell_flipped_h),
	JS_CFUNC_DEF("is_cell_flipped_v", 3, &tile_map_class_is_cell_flipped_v),
	JS_CFUNC_DEF("is_cell_transposed", 3, &tile_map_class_is_cell_transposed),
	JS_CFUNC_DEF("get_coords_for_body_rid", 1, &tile_map_class_get_coords_for_body_rid),
	JS_CFUNC_DEF("get_layer_for_body_rid", 1, &tile_map_class_get_layer_for_body_rid),
	JS_CFUNC_DEF("get_pattern", 2, &tile_map_class_get_pattern),
	JS_CFUNC_DEF("map_pattern", 3, &tile_map_class_map_pattern),
	JS_CFUNC_DEF("set_pattern", 3, &tile_map_class_set_pattern),
	JS_CFUNC_DEF("set_cells_terrain_connect", 5, &tile_map_class_set_cells_terrain_connect),
	JS_CFUNC_DEF("set_cells_terrain_path", 5, &tile_map_class_set_cells_terrain_path),
	JS_CFUNC_DEF("fix_invalid_tiles", 0, &tile_map_class_fix_invalid_tiles),
	JS_CFUNC_DEF("clear_layer", 1, &tile_map_class_clear_layer),
	JS_CFUNC_DEF("clear", 0, &tile_map_class_clear),
	JS_CFUNC_DEF("update_internals", 0, &tile_map_class_update_internals),
	JS_CFUNC_DEF("notify_runtime_tile_data_update", 1, &tile_map_class_notify_runtime_tile_data_update),
	JS_CFUNC_DEF("get_surrounding_cells", 1, &tile_map_class_get_surrounding_cells),
	JS_CFUNC_DEF("get_used_cells", 1, &tile_map_class_get_used_cells),
	JS_CFUNC_DEF("get_used_cells_by_id", 4, &tile_map_class_get_used_cells_by_id),
	JS_CFUNC_DEF("get_used_rect", 0, &tile_map_class_get_used_rect),
	JS_CFUNC_DEF("map_to_local", 1, &tile_map_class_map_to_local),
	JS_CFUNC_DEF("local_to_map", 1, &tile_map_class_local_to_map),
	JS_CFUNC_DEF("get_neighbor_cell", 2, &tile_map_class_get_neighbor_cell),
};


static JSValue tile_map_class_get_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TileMap *opaque = static_cast<TileMap *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_tile_map_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_set"),
        JS_NewCFunction(ctx, tile_map_class_get_tileset, "get_tileset", 0),
        JS_NewCFunction(ctx, tile_map_class_set_tileset, "set_tileset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rendering_quadrant_size"),
        JS_NewCFunction(ctx, tile_map_class_get_rendering_quadrant_size, "get_rendering_quadrant_size", 0),
        JS_NewCFunction(ctx, tile_map_class_set_rendering_quadrant_size, "set_rendering_quadrant_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_animatable"),
        JS_NewCFunction(ctx, tile_map_class_is_collision_animatable, "is_collision_animatable", 0),
        JS_NewCFunction(ctx, tile_map_class_set_collision_animatable, "set_collision_animatable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_visibility_mode"),
        JS_NewCFunction(ctx, tile_map_class_get_collision_visibility_mode, "get_collision_visibility_mode", 0),
        JS_NewCFunction(ctx, tile_map_class_set_collision_visibility_mode, "set_collision_visibility_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_visibility_mode"),
        JS_NewCFunction(ctx, tile_map_class_get_navigation_visibility_mode, "get_navigation_visibility_mode", 0),
        JS_NewCFunction(ctx, tile_map_class_set_navigation_visibility_mode, "set_navigation_visibility_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "changed"),
		JS_NewCFunction(ctx, tile_map_class_get_changed_signal, "get_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_tile_map_enum(JSContext *ctx, JSValue ctor) {
	JSValue VisibilityMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_MODE_DEFAULT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_MODE_FORCE_HIDE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_MODE_FORCE_SHOW", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "VisibilityMode", VisibilityMode_obj);
}

static int js_tile_map_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileMap"] = class_id;
	classes_by_id[class_id] = "TileMap";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_map_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_map_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_map_class_proto_funcs, _countof(tile_map_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_map_class_constructor, "TileMap", 0, JS_CFUNC_constructor, 0);
	define_tile_map_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileMap", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_map_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_map_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileMap");
	return m;
}

JSModuleDef *js_init_tile_map_module(JSContext *ctx) {
	return _js_init_tile_map_module(ctx, "@godot/classes/tile_map");
}

void __register_tile_map() {
	js_init_tile_map_module(js_context());
}

void register_tile_map() {
	__register_tile_map();
}