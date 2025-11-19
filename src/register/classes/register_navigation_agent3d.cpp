#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/navigation_path_query_result3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_agent3d.hpp>
using namespace godot;

static void navigation_agent3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationAgent3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_agent3d_class_def = {
    "NavigationAgent3D",
    navigation_agent3d_class_finalizer
};

static JSValue navigation_agent3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationAgent3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationAgent3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationAgent3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationAgent3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_agent3d_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_rid, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_avoidance_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_avoidance_enabled, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_avoidance_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_avoidance_enabled, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_desired_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_desired_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_desired_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_desired_distance, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_target_desired_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_target_desired_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_target_desired_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_target_desired_distance, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_radius, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_height, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_height, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_height_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_height_offset, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_height_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_height_offset, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_use_3d_avoidance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_use_3d_avoidance, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_use_3d_avoidance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_use_3d_avoidance, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_keep_y_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_keep_y_velocity, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_keep_y_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_keep_y_velocity, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_neighbor_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_neighbor_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_neighbor_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_neighbor_distance, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_max_neighbors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_max_neighbors, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_max_neighbors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_max_neighbors, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_time_horizon_agents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_time_horizon_agents, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_time_horizon_agents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_time_horizon_agents, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_time_horizon_obstacles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_time_horizon_obstacles, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_time_horizon_obstacles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_time_horizon_obstacles, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_max_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_max_speed, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_max_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_max_speed, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_max_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationAgent3D::get_path_max_distance, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_navigation_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_navigation_layers, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_navigation_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_navigation_layers, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_navigation_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_navigation_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_navigation_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_navigation_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_pathfinding_algorithm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_pathfinding_algorithm, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_pathfinding_algorithm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_pathfinding_algorithm, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_postprocessing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_postprocessing, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_postprocessing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_postprocessing, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_metadata_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_metadata_flags, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_metadata_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_metadata_flags, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_navigation_map, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_navigation_map, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_target_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_target_position, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_target_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		NavigationAgent3D *obj = static_cast<NavigationAgent3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		NavigationAgent3D *js_proxy = static_cast<NavigationAgent3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target_position(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_agent3d_class_set_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_simplify_path, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_simplify_path, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_simplify_epsilon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_simplify_epsilon, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_simplify_epsilon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_simplify_epsilon, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_return_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_return_max_length, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_return_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_return_max_length, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_return_max_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_return_max_radius, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_return_max_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_return_max_radius, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_search_max_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_search_max_polygons, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_search_max_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_search_max_polygons, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_path_search_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_path_search_max_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_path_search_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_search_max_distance, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_get_path_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_path_length, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_next_path_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationAgent3D::get_next_path_position, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_velocity_forced(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_velocity_forced, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_velocity, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		NavigationAgent3D *obj = static_cast<NavigationAgent3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_velocity();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		NavigationAgent3D *js_proxy = static_cast<NavigationAgent3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_agent3d_class_distance_to_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::distance_to_target, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_current_navigation_result(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_current_navigation_result, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_current_navigation_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_current_navigation_path, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_current_navigation_path_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_current_navigation_path_index, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_is_target_reached(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::is_target_reached, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_is_target_reachable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationAgent3D::is_target_reachable, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_is_navigation_finished(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationAgent3D::is_navigation_finished, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_final_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationAgent3D::get_final_position, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_avoidance_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_avoidance_layers, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_avoidance_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_avoidance_layers, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_avoidance_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_avoidance_mask, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_avoidance_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_avoidance_mask, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_avoidance_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_avoidance_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_avoidance_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_avoidance_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_avoidance_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_avoidance_mask_value, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_avoidance_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_avoidance_mask_value, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_set_avoidance_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_avoidance_priority, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_avoidance_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_avoidance_priority, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_debug_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_debug_enabled, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_debug_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_debug_enabled, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_debug_use_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_debug_use_custom, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_debug_use_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_debug_use_custom, ctx, this_val, argc, argv);
}
static JSValue navigation_agent3d_class_set_debug_path_custom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_debug_path_custom_color, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_debug_path_custom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		NavigationAgent3D *obj = static_cast<NavigationAgent3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_debug_path_custom_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		NavigationAgent3D *js_proxy = static_cast<NavigationAgent3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_debug_path_custom_color(value);
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
static JSValue navigation_agent3d_class_set_debug_path_custom_point_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationAgent3D::set_debug_path_custom_point_size, ctx, this_val, argc, argv);
};
static JSValue navigation_agent3d_class_get_debug_path_custom_point_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationAgent3D::get_debug_path_custom_point_size, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry navigation_agent3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_rid", 0, &navigation_agent3d_class_get_rid),
	JS_CFUNC_DEF("set_avoidance_enabled", 1, &navigation_agent3d_class_set_avoidance_enabled),
	JS_CFUNC_DEF("get_avoidance_enabled", 0, &navigation_agent3d_class_get_avoidance_enabled),
	JS_CFUNC_DEF("set_path_desired_distance", 1, &navigation_agent3d_class_set_path_desired_distance),
	JS_CFUNC_DEF("get_path_desired_distance", 0, &navigation_agent3d_class_get_path_desired_distance),
	JS_CFUNC_DEF("set_target_desired_distance", 1, &navigation_agent3d_class_set_target_desired_distance),
	JS_CFUNC_DEF("get_target_desired_distance", 0, &navigation_agent3d_class_get_target_desired_distance),
	JS_CFUNC_DEF("set_radius", 1, &navigation_agent3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &navigation_agent3d_class_get_radius),
	JS_CFUNC_DEF("set_height", 1, &navigation_agent3d_class_set_height),
	JS_CFUNC_DEF("get_height", 0, &navigation_agent3d_class_get_height),
	JS_CFUNC_DEF("set_path_height_offset", 1, &navigation_agent3d_class_set_path_height_offset),
	JS_CFUNC_DEF("get_path_height_offset", 0, &navigation_agent3d_class_get_path_height_offset),
	JS_CFUNC_DEF("set_use_3d_avoidance", 1, &navigation_agent3d_class_set_use_3d_avoidance),
	JS_CFUNC_DEF("get_use_3d_avoidance", 0, &navigation_agent3d_class_get_use_3d_avoidance),
	JS_CFUNC_DEF("set_keep_y_velocity", 1, &navigation_agent3d_class_set_keep_y_velocity),
	JS_CFUNC_DEF("get_keep_y_velocity", 0, &navigation_agent3d_class_get_keep_y_velocity),
	JS_CFUNC_DEF("set_neighbor_distance", 1, &navigation_agent3d_class_set_neighbor_distance),
	JS_CFUNC_DEF("get_neighbor_distance", 0, &navigation_agent3d_class_get_neighbor_distance),
	JS_CFUNC_DEF("set_max_neighbors", 1, &navigation_agent3d_class_set_max_neighbors),
	JS_CFUNC_DEF("get_max_neighbors", 0, &navigation_agent3d_class_get_max_neighbors),
	JS_CFUNC_DEF("set_time_horizon_agents", 1, &navigation_agent3d_class_set_time_horizon_agents),
	JS_CFUNC_DEF("get_time_horizon_agents", 0, &navigation_agent3d_class_get_time_horizon_agents),
	JS_CFUNC_DEF("set_time_horizon_obstacles", 1, &navigation_agent3d_class_set_time_horizon_obstacles),
	JS_CFUNC_DEF("get_time_horizon_obstacles", 0, &navigation_agent3d_class_get_time_horizon_obstacles),
	JS_CFUNC_DEF("set_max_speed", 1, &navigation_agent3d_class_set_max_speed),
	JS_CFUNC_DEF("get_max_speed", 0, &navigation_agent3d_class_get_max_speed),
	JS_CFUNC_DEF("set_path_max_distance", 1, &navigation_agent3d_class_set_path_max_distance),
	JS_CFUNC_DEF("get_path_max_distance", 0, &navigation_agent3d_class_get_path_max_distance),
	JS_CFUNC_DEF("set_navigation_layers", 1, &navigation_agent3d_class_set_navigation_layers),
	JS_CFUNC_DEF("get_navigation_layers", 0, &navigation_agent3d_class_get_navigation_layers),
	JS_CFUNC_DEF("set_navigation_layer_value", 2, &navigation_agent3d_class_set_navigation_layer_value),
	JS_CFUNC_DEF("get_navigation_layer_value", 1, &navigation_agent3d_class_get_navigation_layer_value),
	JS_CFUNC_DEF("set_pathfinding_algorithm", 1, &navigation_agent3d_class_set_pathfinding_algorithm),
	JS_CFUNC_DEF("get_pathfinding_algorithm", 0, &navigation_agent3d_class_get_pathfinding_algorithm),
	JS_CFUNC_DEF("set_path_postprocessing", 1, &navigation_agent3d_class_set_path_postprocessing),
	JS_CFUNC_DEF("get_path_postprocessing", 0, &navigation_agent3d_class_get_path_postprocessing),
	JS_CFUNC_DEF("set_path_metadata_flags", 1, &navigation_agent3d_class_set_path_metadata_flags),
	JS_CFUNC_DEF("get_path_metadata_flags", 0, &navigation_agent3d_class_get_path_metadata_flags),
	JS_CFUNC_DEF("set_navigation_map", 1, &navigation_agent3d_class_set_navigation_map),
	JS_CFUNC_DEF("get_navigation_map", 0, &navigation_agent3d_class_get_navigation_map),
	JS_CFUNC_DEF("set_target_position", 1, &navigation_agent3d_class_set_target_position),
	JS_CFUNC_DEF("get_target_position", 0, &navigation_agent3d_class_get_target_position),
	JS_CFUNC_DEF("set_simplify_path", 1, &navigation_agent3d_class_set_simplify_path),
	JS_CFUNC_DEF("get_simplify_path", 0, &navigation_agent3d_class_get_simplify_path),
	JS_CFUNC_DEF("set_simplify_epsilon", 1, &navigation_agent3d_class_set_simplify_epsilon),
	JS_CFUNC_DEF("get_simplify_epsilon", 0, &navigation_agent3d_class_get_simplify_epsilon),
	JS_CFUNC_DEF("set_path_return_max_length", 1, &navigation_agent3d_class_set_path_return_max_length),
	JS_CFUNC_DEF("get_path_return_max_length", 0, &navigation_agent3d_class_get_path_return_max_length),
	JS_CFUNC_DEF("set_path_return_max_radius", 1, &navigation_agent3d_class_set_path_return_max_radius),
	JS_CFUNC_DEF("get_path_return_max_radius", 0, &navigation_agent3d_class_get_path_return_max_radius),
	JS_CFUNC_DEF("set_path_search_max_polygons", 1, &navigation_agent3d_class_set_path_search_max_polygons),
	JS_CFUNC_DEF("get_path_search_max_polygons", 0, &navigation_agent3d_class_get_path_search_max_polygons),
	JS_CFUNC_DEF("set_path_search_max_distance", 1, &navigation_agent3d_class_set_path_search_max_distance),
	JS_CFUNC_DEF("get_path_search_max_distance", 0, &navigation_agent3d_class_get_path_search_max_distance),
	JS_CFUNC_DEF("get_path_length", 0, &navigation_agent3d_class_get_path_length),
	JS_CFUNC_DEF("get_next_path_position", 0, &navigation_agent3d_class_get_next_path_position),
	JS_CFUNC_DEF("set_velocity_forced", 1, &navigation_agent3d_class_set_velocity_forced),
	JS_CFUNC_DEF("set_velocity", 1, &navigation_agent3d_class_set_velocity),
	JS_CFUNC_DEF("get_velocity", 0, &navigation_agent3d_class_get_velocity),
	JS_CFUNC_DEF("distance_to_target", 0, &navigation_agent3d_class_distance_to_target),
	JS_CFUNC_DEF("get_current_navigation_result", 0, &navigation_agent3d_class_get_current_navigation_result),
	JS_CFUNC_DEF("get_current_navigation_path", 0, &navigation_agent3d_class_get_current_navigation_path),
	JS_CFUNC_DEF("get_current_navigation_path_index", 0, &navigation_agent3d_class_get_current_navigation_path_index),
	JS_CFUNC_DEF("is_target_reached", 0, &navigation_agent3d_class_is_target_reached),
	JS_CFUNC_DEF("is_target_reachable", 0, &navigation_agent3d_class_is_target_reachable),
	JS_CFUNC_DEF("is_navigation_finished", 0, &navigation_agent3d_class_is_navigation_finished),
	JS_CFUNC_DEF("get_final_position", 0, &navigation_agent3d_class_get_final_position),
	JS_CFUNC_DEF("set_avoidance_layers", 1, &navigation_agent3d_class_set_avoidance_layers),
	JS_CFUNC_DEF("get_avoidance_layers", 0, &navigation_agent3d_class_get_avoidance_layers),
	JS_CFUNC_DEF("set_avoidance_mask", 1, &navigation_agent3d_class_set_avoidance_mask),
	JS_CFUNC_DEF("get_avoidance_mask", 0, &navigation_agent3d_class_get_avoidance_mask),
	JS_CFUNC_DEF("set_avoidance_layer_value", 2, &navigation_agent3d_class_set_avoidance_layer_value),
	JS_CFUNC_DEF("get_avoidance_layer_value", 1, &navigation_agent3d_class_get_avoidance_layer_value),
	JS_CFUNC_DEF("set_avoidance_mask_value", 2, &navigation_agent3d_class_set_avoidance_mask_value),
	JS_CFUNC_DEF("get_avoidance_mask_value", 1, &navigation_agent3d_class_get_avoidance_mask_value),
	JS_CFUNC_DEF("set_avoidance_priority", 1, &navigation_agent3d_class_set_avoidance_priority),
	JS_CFUNC_DEF("get_avoidance_priority", 0, &navigation_agent3d_class_get_avoidance_priority),
	JS_CFUNC_DEF("set_debug_enabled", 1, &navigation_agent3d_class_set_debug_enabled),
	JS_CFUNC_DEF("get_debug_enabled", 0, &navigation_agent3d_class_get_debug_enabled),
	JS_CFUNC_DEF("set_debug_use_custom", 1, &navigation_agent3d_class_set_debug_use_custom),
	JS_CFUNC_DEF("get_debug_use_custom", 0, &navigation_agent3d_class_get_debug_use_custom),
	JS_CFUNC_DEF("set_debug_path_custom_color", 1, &navigation_agent3d_class_set_debug_path_custom_color),
	JS_CFUNC_DEF("get_debug_path_custom_color", 0, &navigation_agent3d_class_get_debug_path_custom_color),
	JS_CFUNC_DEF("set_debug_path_custom_point_size", 1, &navigation_agent3d_class_set_debug_path_custom_point_size),
	JS_CFUNC_DEF("get_debug_path_custom_point_size", 0, &navigation_agent3d_class_get_debug_path_custom_point_size),
};


static JSValue navigation_agent3d_class_get_path_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationAgent3D *opaque = static_cast<NavigationAgent3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "path_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "path_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "path_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue navigation_agent3d_class_get_target_reached_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationAgent3D *opaque = static_cast<NavigationAgent3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "target_reached_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "target_reached"));
		JS_DefinePropertyValueStr(ctx, this_val, "target_reached_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue navigation_agent3d_class_get_waypoint_reached_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationAgent3D *opaque = static_cast<NavigationAgent3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "waypoint_reached_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "waypoint_reached"));
		JS_DefinePropertyValueStr(ctx, this_val, "waypoint_reached_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue navigation_agent3d_class_get_link_reached_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationAgent3D *opaque = static_cast<NavigationAgent3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "link_reached_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "link_reached"));
		JS_DefinePropertyValueStr(ctx, this_val, "link_reached_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue navigation_agent3d_class_get_navigation_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationAgent3D *opaque = static_cast<NavigationAgent3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "navigation_finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "navigation_finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "navigation_finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue navigation_agent3d_class_get_velocity_computed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationAgent3D *opaque = static_cast<NavigationAgent3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "velocity_computed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "velocity_computed"));
		JS_DefinePropertyValueStr(ctx, this_val, "velocity_computed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_navigation_agent3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_position"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_target_position, "get_target_position", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_target_position, "set_target_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_desired_distance"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_desired_distance, "get_path_desired_distance", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_desired_distance, "set_path_desired_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_desired_distance"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_target_desired_distance, "get_target_desired_distance", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_target_desired_distance, "set_target_desired_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_height_offset"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_height_offset, "get_path_height_offset", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_height_offset, "set_path_height_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_max_distance"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_max_distance, "get_path_max_distance", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_max_distance, "set_path_max_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_layers"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_navigation_layers, "get_navigation_layers", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_navigation_layers, "set_navigation_layers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pathfinding_algorithm"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_pathfinding_algorithm, "get_pathfinding_algorithm", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_pathfinding_algorithm, "set_pathfinding_algorithm", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_postprocessing"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_postprocessing, "get_path_postprocessing", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_postprocessing, "set_path_postprocessing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_metadata_flags"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_metadata_flags, "get_path_metadata_flags", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_metadata_flags, "set_path_metadata_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "simplify_path"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_simplify_path, "get_simplify_path", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_simplify_path, "set_simplify_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "simplify_epsilon"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_simplify_epsilon, "get_simplify_epsilon", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_simplify_epsilon, "set_simplify_epsilon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_return_max_length"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_return_max_length, "get_path_return_max_length", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_return_max_length, "set_path_return_max_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_return_max_radius"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_return_max_radius, "get_path_return_max_radius", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_return_max_radius, "set_path_return_max_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_search_max_polygons"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_search_max_polygons, "get_path_search_max_polygons", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_search_max_polygons, "set_path_search_max_polygons", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_search_max_distance"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_path_search_max_distance, "get_path_search_max_distance", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_path_search_max_distance, "set_path_search_max_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "avoidance_enabled"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_avoidance_enabled, "get_avoidance_enabled", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_avoidance_enabled, "set_avoidance_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "velocity"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_velocity, "get_velocity", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_velocity, "set_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "neighbor_distance"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_neighbor_distance, "get_neighbor_distance", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_neighbor_distance, "set_neighbor_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_neighbors"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_max_neighbors, "get_max_neighbors", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_max_neighbors, "set_max_neighbors", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "time_horizon_agents"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_time_horizon_agents, "get_time_horizon_agents", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_time_horizon_agents, "set_time_horizon_agents", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "time_horizon_obstacles"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_time_horizon_obstacles, "get_time_horizon_obstacles", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_time_horizon_obstacles, "set_time_horizon_obstacles", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_speed"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_max_speed, "get_max_speed", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_max_speed, "set_max_speed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_3d_avoidance"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_use_3d_avoidance, "get_use_3d_avoidance", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_use_3d_avoidance, "set_use_3d_avoidance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_y_velocity"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_keep_y_velocity, "get_keep_y_velocity", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_keep_y_velocity, "set_keep_y_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "avoidance_layers"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_avoidance_layers, "get_avoidance_layers", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_avoidance_layers, "set_avoidance_layers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "avoidance_mask"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_avoidance_mask, "get_avoidance_mask", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_avoidance_mask, "set_avoidance_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "avoidance_priority"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_avoidance_priority, "get_avoidance_priority", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_avoidance_priority, "set_avoidance_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_enabled"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_debug_enabled, "get_debug_enabled", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_debug_enabled, "set_debug_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_use_custom"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_debug_use_custom, "get_debug_use_custom", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_debug_use_custom, "set_debug_use_custom", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_path_custom_color"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_debug_path_custom_color, "get_debug_path_custom_color", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_debug_path_custom_color, "set_debug_path_custom_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_path_custom_point_size"),
        JS_NewCFunction(ctx, navigation_agent3d_class_get_debug_path_custom_point_size, "get_debug_path_custom_point_size", 0),
        JS_NewCFunction(ctx, navigation_agent3d_class_set_debug_path_custom_point_size, "set_debug_path_custom_point_size", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "path_changed"),
		JS_NewCFunction(ctx, navigation_agent3d_class_get_path_changed_signal, "get_path_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "target_reached"),
		JS_NewCFunction(ctx, navigation_agent3d_class_get_target_reached_signal, "get_target_reached_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "waypoint_reached"),
		JS_NewCFunction(ctx, navigation_agent3d_class_get_waypoint_reached_signal, "get_waypoint_reached_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "link_reached"),
		JS_NewCFunction(ctx, navigation_agent3d_class_get_link_reached_signal, "get_link_reached_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "navigation_finished"),
		JS_NewCFunction(ctx, navigation_agent3d_class_get_navigation_finished_signal, "get_navigation_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "velocity_computed"),
		JS_NewCFunction(ctx, navigation_agent3d_class_get_velocity_computed_signal, "get_velocity_computed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_navigation_agent3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_navigation_agent3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationAgent3D"] = class_id;
	classes_by_id[class_id] = "NavigationAgent3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_agent3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_agent3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_agent3d_class_proto_funcs, _countof(navigation_agent3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_agent3d_class_constructor, "NavigationAgent3D", 0, JS_CFUNC_constructor, 0);
	define_navigation_agent3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationAgent3D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_agent3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_agent3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationAgent3D");
	return m;
}

JSModuleDef *js_init_navigation_agent3d_module(JSContext *ctx) {
	return _js_init_navigation_agent3d_module(ctx, "@godot/classes/navigation_agent3d");
}

void __register_navigation_agent3d() {
	js_init_navigation_agent3d_module(js_context());
}

void register_navigation_agent3d() {
	__register_navigation_agent3d();
}