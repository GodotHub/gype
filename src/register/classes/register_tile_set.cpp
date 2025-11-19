#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/physics_material.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/tile_map_pattern.hpp>
#include <godot_cpp/classes/tile_set_source.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tile_set.hpp>
using namespace godot;

static void tile_set_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileSet"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_set_class_def = {
    "TileSet",
    tile_set_class_finalizer
};

static JSValue tile_set_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileSet"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileSet *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileSet *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileSet);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_set_class_get_next_source_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_next_source_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::add_source, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_source, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_source_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_source_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_source_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_source_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_source_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_source_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_has_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::has_source, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_source, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_tile_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_tile_shape, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_tile_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_tile_shape, ctx, this_val, argc, argv);
}
static JSValue tile_set_class_set_tile_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_tile_layout, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_tile_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_tile_layout, ctx, this_val, argc, argv);
}
static JSValue tile_set_class_set_tile_offset_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_tile_offset_axis, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_tile_offset_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_tile_offset_axis, ctx, this_val, argc, argv);
}
static JSValue tile_set_class_set_tile_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_tile_size, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_tile_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		TileSet *obj = static_cast<TileSet *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tile_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		TileSet *js_proxy = static_cast<TileSet *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tile_size(value);
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
static JSValue tile_set_class_set_uv_clipping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_uv_clipping, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_is_uv_clipping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::is_uv_clipping, ctx, this_val, argc, argv);
}
static JSValue tile_set_class_get_occlusion_layers_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_occlusion_layers_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_occlusion_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::add_occlusion_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_move_occlusion_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::move_occlusion_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_occlusion_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_occlusion_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_occlusion_layer_light_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_occlusion_layer_light_mask, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_occlusion_layer_light_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_occlusion_layer_light_mask, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_occlusion_layer_sdf_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_occlusion_layer_sdf_collision, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_occlusion_layer_sdf_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_occlusion_layer_sdf_collision, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_physics_layers_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_physics_layers_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_physics_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::add_physics_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_move_physics_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::move_physics_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_physics_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_physics_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_physics_layer_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_physics_layer_collision_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_physics_layer_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_physics_layer_collision_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_physics_layer_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_physics_layer_collision_mask, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_physics_layer_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_physics_layer_collision_mask, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_physics_layer_collision_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_physics_layer_collision_priority, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_physics_layer_collision_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_physics_layer_collision_priority, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_physics_layer_physics_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_physics_layer_physics_material, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_physics_layer_physics_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_physics_layer_physics_material, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_terrain_sets_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_terrain_sets_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_terrain_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::add_terrain_set, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_move_terrain_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::move_terrain_set, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_terrain_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_terrain_set, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_terrain_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_terrain_set_mode, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_terrain_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_terrain_set_mode, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_terrains_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_terrains_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_terrain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::add_terrain, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_move_terrain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::move_terrain, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_terrain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_terrain, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_terrain_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_terrain_name, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_terrain_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_terrain_name, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_terrain_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_terrain_color, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_terrain_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_terrain_color, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_navigation_layers_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_navigation_layers_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_navigation_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::add_navigation_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_move_navigation_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::move_navigation_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_navigation_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_navigation_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_navigation_layer_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_navigation_layer_layers, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_navigation_layer_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_navigation_layer_layers, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_navigation_layer_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_navigation_layer_layer_value, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_navigation_layer_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_navigation_layer_layer_value, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_custom_data_layers_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_custom_data_layers_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_custom_data_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::add_custom_data_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_move_custom_data_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::move_custom_data_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_custom_data_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_custom_data_layer, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_custom_data_layer_by_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_custom_data_layer_by_name, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_custom_data_layer_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_custom_data_layer_name, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_has_custom_data_layer_by_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::has_custom_data_layer_by_name, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_custom_data_layer_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_custom_data_layer_name, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_custom_data_layer_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_custom_data_layer_type, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_custom_data_layer_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::get_custom_data_layer_type, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_source_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_source_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_source_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::get_source_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_has_source_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::has_source_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_source_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_source_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_coords_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_coords_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_coords_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::get_coords_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_has_coords_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::has_coords_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_coords_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_coords_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_set_alternative_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::set_alternative_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_alternative_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::get_alternative_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_has_alternative_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::has_alternative_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_alternative_level_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_alternative_level_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_map_tile_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSet::map_tile_proxy, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_cleanup_invalid_tile_proxies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::cleanup_invalid_tile_proxies, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_clear_tile_proxies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::clear_tile_proxies, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_add_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::add_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::get_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_remove_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSet::remove_pattern, ctx, this_val, argc, argv);
};
static JSValue tile_set_class_get_patterns_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSet::get_patterns_count, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry tile_set_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_next_source_id", 0, &tile_set_class_get_next_source_id),
	JS_CFUNC_DEF("add_source", 2, &tile_set_class_add_source),
	JS_CFUNC_DEF("remove_source", 1, &tile_set_class_remove_source),
	JS_CFUNC_DEF("set_source_id", 2, &tile_set_class_set_source_id),
	JS_CFUNC_DEF("get_source_count", 0, &tile_set_class_get_source_count),
	JS_CFUNC_DEF("get_source_id", 1, &tile_set_class_get_source_id),
	JS_CFUNC_DEF("has_source", 1, &tile_set_class_has_source),
	JS_CFUNC_DEF("get_source", 1, &tile_set_class_get_source),
	JS_CFUNC_DEF("set_tile_shape", 1, &tile_set_class_set_tile_shape),
	JS_CFUNC_DEF("get_tile_shape", 0, &tile_set_class_get_tile_shape),
	JS_CFUNC_DEF("set_tile_layout", 1, &tile_set_class_set_tile_layout),
	JS_CFUNC_DEF("get_tile_layout", 0, &tile_set_class_get_tile_layout),
	JS_CFUNC_DEF("set_tile_offset_axis", 1, &tile_set_class_set_tile_offset_axis),
	JS_CFUNC_DEF("get_tile_offset_axis", 0, &tile_set_class_get_tile_offset_axis),
	JS_CFUNC_DEF("set_tile_size", 1, &tile_set_class_set_tile_size),
	JS_CFUNC_DEF("get_tile_size", 0, &tile_set_class_get_tile_size),
	JS_CFUNC_DEF("set_uv_clipping", 1, &tile_set_class_set_uv_clipping),
	JS_CFUNC_DEF("is_uv_clipping", 0, &tile_set_class_is_uv_clipping),
	JS_CFUNC_DEF("get_occlusion_layers_count", 0, &tile_set_class_get_occlusion_layers_count),
	JS_CFUNC_DEF("add_occlusion_layer", 1, &tile_set_class_add_occlusion_layer),
	JS_CFUNC_DEF("move_occlusion_layer", 2, &tile_set_class_move_occlusion_layer),
	JS_CFUNC_DEF("remove_occlusion_layer", 1, &tile_set_class_remove_occlusion_layer),
	JS_CFUNC_DEF("set_occlusion_layer_light_mask", 2, &tile_set_class_set_occlusion_layer_light_mask),
	JS_CFUNC_DEF("get_occlusion_layer_light_mask", 1, &tile_set_class_get_occlusion_layer_light_mask),
	JS_CFUNC_DEF("set_occlusion_layer_sdf_collision", 2, &tile_set_class_set_occlusion_layer_sdf_collision),
	JS_CFUNC_DEF("get_occlusion_layer_sdf_collision", 1, &tile_set_class_get_occlusion_layer_sdf_collision),
	JS_CFUNC_DEF("get_physics_layers_count", 0, &tile_set_class_get_physics_layers_count),
	JS_CFUNC_DEF("add_physics_layer", 1, &tile_set_class_add_physics_layer),
	JS_CFUNC_DEF("move_physics_layer", 2, &tile_set_class_move_physics_layer),
	JS_CFUNC_DEF("remove_physics_layer", 1, &tile_set_class_remove_physics_layer),
	JS_CFUNC_DEF("set_physics_layer_collision_layer", 2, &tile_set_class_set_physics_layer_collision_layer),
	JS_CFUNC_DEF("get_physics_layer_collision_layer", 1, &tile_set_class_get_physics_layer_collision_layer),
	JS_CFUNC_DEF("set_physics_layer_collision_mask", 2, &tile_set_class_set_physics_layer_collision_mask),
	JS_CFUNC_DEF("get_physics_layer_collision_mask", 1, &tile_set_class_get_physics_layer_collision_mask),
	JS_CFUNC_DEF("set_physics_layer_collision_priority", 2, &tile_set_class_set_physics_layer_collision_priority),
	JS_CFUNC_DEF("get_physics_layer_collision_priority", 1, &tile_set_class_get_physics_layer_collision_priority),
	JS_CFUNC_DEF("set_physics_layer_physics_material", 2, &tile_set_class_set_physics_layer_physics_material),
	JS_CFUNC_DEF("get_physics_layer_physics_material", 1, &tile_set_class_get_physics_layer_physics_material),
	JS_CFUNC_DEF("get_terrain_sets_count", 0, &tile_set_class_get_terrain_sets_count),
	JS_CFUNC_DEF("add_terrain_set", 1, &tile_set_class_add_terrain_set),
	JS_CFUNC_DEF("move_terrain_set", 2, &tile_set_class_move_terrain_set),
	JS_CFUNC_DEF("remove_terrain_set", 1, &tile_set_class_remove_terrain_set),
	JS_CFUNC_DEF("set_terrain_set_mode", 2, &tile_set_class_set_terrain_set_mode),
	JS_CFUNC_DEF("get_terrain_set_mode", 1, &tile_set_class_get_terrain_set_mode),
	JS_CFUNC_DEF("get_terrains_count", 1, &tile_set_class_get_terrains_count),
	JS_CFUNC_DEF("add_terrain", 2, &tile_set_class_add_terrain),
	JS_CFUNC_DEF("move_terrain", 3, &tile_set_class_move_terrain),
	JS_CFUNC_DEF("remove_terrain", 2, &tile_set_class_remove_terrain),
	JS_CFUNC_DEF("set_terrain_name", 3, &tile_set_class_set_terrain_name),
	JS_CFUNC_DEF("get_terrain_name", 2, &tile_set_class_get_terrain_name),
	JS_CFUNC_DEF("set_terrain_color", 3, &tile_set_class_set_terrain_color),
	JS_CFUNC_DEF("get_terrain_color", 2, &tile_set_class_get_terrain_color),
	JS_CFUNC_DEF("get_navigation_layers_count", 0, &tile_set_class_get_navigation_layers_count),
	JS_CFUNC_DEF("add_navigation_layer", 1, &tile_set_class_add_navigation_layer),
	JS_CFUNC_DEF("move_navigation_layer", 2, &tile_set_class_move_navigation_layer),
	JS_CFUNC_DEF("remove_navigation_layer", 1, &tile_set_class_remove_navigation_layer),
	JS_CFUNC_DEF("set_navigation_layer_layers", 2, &tile_set_class_set_navigation_layer_layers),
	JS_CFUNC_DEF("get_navigation_layer_layers", 1, &tile_set_class_get_navigation_layer_layers),
	JS_CFUNC_DEF("set_navigation_layer_layer_value", 3, &tile_set_class_set_navigation_layer_layer_value),
	JS_CFUNC_DEF("get_navigation_layer_layer_value", 2, &tile_set_class_get_navigation_layer_layer_value),
	JS_CFUNC_DEF("get_custom_data_layers_count", 0, &tile_set_class_get_custom_data_layers_count),
	JS_CFUNC_DEF("add_custom_data_layer", 1, &tile_set_class_add_custom_data_layer),
	JS_CFUNC_DEF("move_custom_data_layer", 2, &tile_set_class_move_custom_data_layer),
	JS_CFUNC_DEF("remove_custom_data_layer", 1, &tile_set_class_remove_custom_data_layer),
	JS_CFUNC_DEF("get_custom_data_layer_by_name", 1, &tile_set_class_get_custom_data_layer_by_name),
	JS_CFUNC_DEF("set_custom_data_layer_name", 2, &tile_set_class_set_custom_data_layer_name),
	JS_CFUNC_DEF("has_custom_data_layer_by_name", 1, &tile_set_class_has_custom_data_layer_by_name),
	JS_CFUNC_DEF("get_custom_data_layer_name", 1, &tile_set_class_get_custom_data_layer_name),
	JS_CFUNC_DEF("set_custom_data_layer_type", 2, &tile_set_class_set_custom_data_layer_type),
	JS_CFUNC_DEF("get_custom_data_layer_type", 1, &tile_set_class_get_custom_data_layer_type),
	JS_CFUNC_DEF("set_source_level_tile_proxy", 2, &tile_set_class_set_source_level_tile_proxy),
	JS_CFUNC_DEF("get_source_level_tile_proxy", 1, &tile_set_class_get_source_level_tile_proxy),
	JS_CFUNC_DEF("has_source_level_tile_proxy", 1, &tile_set_class_has_source_level_tile_proxy),
	JS_CFUNC_DEF("remove_source_level_tile_proxy", 1, &tile_set_class_remove_source_level_tile_proxy),
	JS_CFUNC_DEF("set_coords_level_tile_proxy", 4, &tile_set_class_set_coords_level_tile_proxy),
	JS_CFUNC_DEF("get_coords_level_tile_proxy", 2, &tile_set_class_get_coords_level_tile_proxy),
	JS_CFUNC_DEF("has_coords_level_tile_proxy", 2, &tile_set_class_has_coords_level_tile_proxy),
	JS_CFUNC_DEF("remove_coords_level_tile_proxy", 2, &tile_set_class_remove_coords_level_tile_proxy),
	JS_CFUNC_DEF("set_alternative_level_tile_proxy", 6, &tile_set_class_set_alternative_level_tile_proxy),
	JS_CFUNC_DEF("get_alternative_level_tile_proxy", 3, &tile_set_class_get_alternative_level_tile_proxy),
	JS_CFUNC_DEF("has_alternative_level_tile_proxy", 3, &tile_set_class_has_alternative_level_tile_proxy),
	JS_CFUNC_DEF("remove_alternative_level_tile_proxy", 3, &tile_set_class_remove_alternative_level_tile_proxy),
	JS_CFUNC_DEF("map_tile_proxy", 3, &tile_set_class_map_tile_proxy),
	JS_CFUNC_DEF("cleanup_invalid_tile_proxies", 0, &tile_set_class_cleanup_invalid_tile_proxies),
	JS_CFUNC_DEF("clear_tile_proxies", 0, &tile_set_class_clear_tile_proxies),
	JS_CFUNC_DEF("add_pattern", 2, &tile_set_class_add_pattern),
	JS_CFUNC_DEF("get_pattern", 1, &tile_set_class_get_pattern),
	JS_CFUNC_DEF("remove_pattern", 1, &tile_set_class_remove_pattern),
	JS_CFUNC_DEF("get_patterns_count", 0, &tile_set_class_get_patterns_count),
};




static void define_tile_set_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_shape"),
        JS_NewCFunction(ctx, tile_set_class_get_tile_shape, "get_tile_shape", 0),
        JS_NewCFunction(ctx, tile_set_class_set_tile_shape, "set_tile_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_layout"),
        JS_NewCFunction(ctx, tile_set_class_get_tile_layout, "get_tile_layout", 0),
        JS_NewCFunction(ctx, tile_set_class_set_tile_layout, "set_tile_layout", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_offset_axis"),
        JS_NewCFunction(ctx, tile_set_class_get_tile_offset_axis, "get_tile_offset_axis", 0),
        JS_NewCFunction(ctx, tile_set_class_set_tile_offset_axis, "set_tile_offset_axis", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tile_size"),
        JS_NewCFunction(ctx, tile_set_class_get_tile_size, "get_tile_size", 0),
        JS_NewCFunction(ctx, tile_set_class_set_tile_size, "set_tile_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv_clipping"),
        JS_NewCFunction(ctx, tile_set_class_is_uv_clipping, "is_uv_clipping", 0),
        JS_NewCFunction(ctx, tile_set_class_set_uv_clipping, "set_uv_clipping", 1),
        JS_PROP_GETSET
    );
}

static void define_tile_set_enum(JSContext *ctx, JSValue ctor) {
	JSValue TileShape_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TileShape_obj, "TILE_SHAPE_SQUARE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TileShape_obj, "TILE_SHAPE_ISOMETRIC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TileShape_obj, "TILE_SHAPE_HALF_OFFSET_SQUARE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TileShape_obj, "TILE_SHAPE_HEXAGON", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TileShape", TileShape_obj);
	JSValue TileLayout_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TileLayout_obj, "TILE_LAYOUT_STACKED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TileLayout_obj, "TILE_LAYOUT_STACKED_OFFSET", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TileLayout_obj, "TILE_LAYOUT_STAIRS_RIGHT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TileLayout_obj, "TILE_LAYOUT_STAIRS_DOWN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TileLayout_obj, "TILE_LAYOUT_DIAMOND_RIGHT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TileLayout_obj, "TILE_LAYOUT_DIAMOND_DOWN", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "TileLayout", TileLayout_obj);
	JSValue TileOffsetAxis_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TileOffsetAxis_obj, "TILE_OFFSET_AXIS_HORIZONTAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TileOffsetAxis_obj, "TILE_OFFSET_AXIS_VERTICAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "TileOffsetAxis", TileOffsetAxis_obj);
	JSValue CellNeighbor_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_RIGHT_SIDE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_RIGHT_CORNER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_BOTTOM_RIGHT_SIDE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_BOTTOM_RIGHT_CORNER", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_BOTTOM_SIDE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_BOTTOM_CORNER", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_BOTTOM_LEFT_SIDE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_BOTTOM_LEFT_CORNER", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_LEFT_SIDE", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_LEFT_CORNER", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_TOP_LEFT_SIDE", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_TOP_LEFT_CORNER", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_TOP_SIDE", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_TOP_CORNER", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_TOP_RIGHT_SIDE", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, CellNeighbor_obj, "CELL_NEIGHBOR_TOP_RIGHT_CORNER", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, ctor, "CellNeighbor", CellNeighbor_obj);
	JSValue TerrainMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TerrainMode_obj, "TERRAIN_MODE_MATCH_CORNERS_AND_SIDES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TerrainMode_obj, "TERRAIN_MODE_MATCH_CORNERS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TerrainMode_obj, "TERRAIN_MODE_MATCH_SIDES", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TerrainMode", TerrainMode_obj);
}

static int js_tile_set_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileSet"] = class_id;
	classes_by_id[class_id] = "TileSet";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_set_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_set_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_set_class_proto_funcs, _countof(tile_set_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_set_class_constructor, "TileSet", 0, JS_CFUNC_constructor, 0);
	define_tile_set_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileSet", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_set_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_set_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileSet");
	return m;
}

JSModuleDef *js_init_tile_set_module(JSContext *ctx) {
	return _js_init_tile_set_module(ctx, "@godot/classes/tile_set");
}

void __register_tile_set() {
	js_init_tile_set_module(js_context());
}

void register_tile_set() {
	__register_tile_set();
}