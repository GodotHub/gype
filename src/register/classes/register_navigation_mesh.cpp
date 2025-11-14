#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_mesh.hpp>
using namespace godot;

static void navigation_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_mesh_class_def = {
    "NavigationMesh",
    navigation_mesh_class_finalizer
};

static JSValue navigation_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_mesh_class_set_sample_partition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_sample_partition_type, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_sample_partition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_sample_partition_type, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_parsed_geometry_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_parsed_geometry_type, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_parsed_geometry_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_parsed_geometry_type, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_set_source_geometry_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_source_geometry_mode, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_source_geometry_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_source_geometry_mode, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_source_group_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_source_group_name, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_source_group_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<StringName> *proxy = memnew(ObjectProxy<StringName>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> StringName {
		NavigationMesh *obj = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_source_group_name();
	};
	proxy->setter = [this_val](const StringName &value) -> void {
		NavigationMesh *js_proxy = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_source_group_name(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringNameProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringNameProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_mesh_class_set_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_cell_size, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_cell_size, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_cell_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_cell_height, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_cell_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_cell_height, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_border_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_border_size, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_border_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_border_size, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_agent_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_agent_height, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_agent_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_agent_height, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_agent_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_agent_radius, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_agent_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationMesh::get_agent_radius, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_agent_max_climb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_agent_max_climb, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_agent_max_climb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_agent_max_climb, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_agent_max_slope(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_agent_max_slope, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_agent_max_slope(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_agent_max_slope, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_region_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_region_min_size, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_region_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_region_min_size, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_region_merge_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_region_merge_size, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_region_merge_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_region_merge_size, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_edge_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_edge_max_length, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_edge_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_edge_max_length, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_edge_max_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_edge_max_error, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_edge_max_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_edge_max_error, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_vertices_per_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_vertices_per_polygon, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_vertices_per_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_vertices_per_polygon, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_detail_sample_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_detail_sample_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_detail_sample_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_detail_sample_distance, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_detail_sample_max_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_detail_sample_max_error, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_detail_sample_max_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_detail_sample_max_error, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_filter_low_hanging_obstacles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_filter_low_hanging_obstacles, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_filter_low_hanging_obstacles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_filter_low_hanging_obstacles, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_filter_ledge_spans(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_filter_ledge_spans, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_filter_ledge_spans(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_filter_ledge_spans, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_filter_walkable_low_height_spans(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_filter_walkable_low_height_spans, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_filter_walkable_low_height_spans(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_filter_walkable_low_height_spans, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_class_set_filter_baking_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_filter_baking_aabb, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_filter_baking_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<AABB> *proxy = memnew(ObjectProxy<AABB>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> AABB {
		NavigationMesh *obj = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_filter_baking_aabb();
	};
	proxy->setter = [this_val](const AABB &value) -> void {
		NavigationMesh *js_proxy = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_filter_baking_aabb(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["AABBProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "AABBProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_mesh_class_set_filter_baking_aabb_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_filter_baking_aabb_offset, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_filter_baking_aabb_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		NavigationMesh *obj = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_filter_baking_aabb_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		NavigationMesh *js_proxy = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_filter_baking_aabb_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_mesh_class_set_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::set_vertices, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector3Array> *proxy = memnew(ObjectProxy<PackedVector3Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector3Array {
		NavigationMesh *obj = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_vertices();
	};
	proxy->setter = [this_val](const PackedVector3Array &value) -> void {
		NavigationMesh *js_proxy = static_cast<NavigationMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_vertices(PackedVector3Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector3ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector3ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_mesh_class_add_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::add_polygon, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_polygon_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMesh::get_polygon_count, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_get_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationMesh::get_polygon, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_clear_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::clear_polygons, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_create_from_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::create_from_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMesh::clear, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry navigation_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_sample_partition_type", 1, &navigation_mesh_class_set_sample_partition_type),
	JS_CFUNC_DEF("get_sample_partition_type", 0, &navigation_mesh_class_get_sample_partition_type),
	JS_CFUNC_DEF("set_parsed_geometry_type", 1, &navigation_mesh_class_set_parsed_geometry_type),
	JS_CFUNC_DEF("get_parsed_geometry_type", 0, &navigation_mesh_class_get_parsed_geometry_type),
	JS_CFUNC_DEF("set_collision_mask", 1, &navigation_mesh_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &navigation_mesh_class_get_collision_mask),
	JS_CFUNC_DEF("set_collision_mask_value", 2, &navigation_mesh_class_set_collision_mask_value),
	JS_CFUNC_DEF("get_collision_mask_value", 1, &navigation_mesh_class_get_collision_mask_value),
	JS_CFUNC_DEF("set_source_geometry_mode", 1, &navigation_mesh_class_set_source_geometry_mode),
	JS_CFUNC_DEF("get_source_geometry_mode", 0, &navigation_mesh_class_get_source_geometry_mode),
	JS_CFUNC_DEF("set_source_group_name", 1, &navigation_mesh_class_set_source_group_name),
	JS_CFUNC_DEF("get_source_group_name", 0, &navigation_mesh_class_get_source_group_name),
	JS_CFUNC_DEF("set_cell_size", 1, &navigation_mesh_class_set_cell_size),
	JS_CFUNC_DEF("get_cell_size", 0, &navigation_mesh_class_get_cell_size),
	JS_CFUNC_DEF("set_cell_height", 1, &navigation_mesh_class_set_cell_height),
	JS_CFUNC_DEF("get_cell_height", 0, &navigation_mesh_class_get_cell_height),
	JS_CFUNC_DEF("set_border_size", 1, &navigation_mesh_class_set_border_size),
	JS_CFUNC_DEF("get_border_size", 0, &navigation_mesh_class_get_border_size),
	JS_CFUNC_DEF("set_agent_height", 1, &navigation_mesh_class_set_agent_height),
	JS_CFUNC_DEF("get_agent_height", 0, &navigation_mesh_class_get_agent_height),
	JS_CFUNC_DEF("set_agent_radius", 1, &navigation_mesh_class_set_agent_radius),
	JS_CFUNC_DEF("get_agent_radius", 0, &navigation_mesh_class_get_agent_radius),
	JS_CFUNC_DEF("set_agent_max_climb", 1, &navigation_mesh_class_set_agent_max_climb),
	JS_CFUNC_DEF("get_agent_max_climb", 0, &navigation_mesh_class_get_agent_max_climb),
	JS_CFUNC_DEF("set_agent_max_slope", 1, &navigation_mesh_class_set_agent_max_slope),
	JS_CFUNC_DEF("get_agent_max_slope", 0, &navigation_mesh_class_get_agent_max_slope),
	JS_CFUNC_DEF("set_region_min_size", 1, &navigation_mesh_class_set_region_min_size),
	JS_CFUNC_DEF("get_region_min_size", 0, &navigation_mesh_class_get_region_min_size),
	JS_CFUNC_DEF("set_region_merge_size", 1, &navigation_mesh_class_set_region_merge_size),
	JS_CFUNC_DEF("get_region_merge_size", 0, &navigation_mesh_class_get_region_merge_size),
	JS_CFUNC_DEF("set_edge_max_length", 1, &navigation_mesh_class_set_edge_max_length),
	JS_CFUNC_DEF("get_edge_max_length", 0, &navigation_mesh_class_get_edge_max_length),
	JS_CFUNC_DEF("set_edge_max_error", 1, &navigation_mesh_class_set_edge_max_error),
	JS_CFUNC_DEF("get_edge_max_error", 0, &navigation_mesh_class_get_edge_max_error),
	JS_CFUNC_DEF("set_vertices_per_polygon", 1, &navigation_mesh_class_set_vertices_per_polygon),
	JS_CFUNC_DEF("get_vertices_per_polygon", 0, &navigation_mesh_class_get_vertices_per_polygon),
	JS_CFUNC_DEF("set_detail_sample_distance", 1, &navigation_mesh_class_set_detail_sample_distance),
	JS_CFUNC_DEF("get_detail_sample_distance", 0, &navigation_mesh_class_get_detail_sample_distance),
	JS_CFUNC_DEF("set_detail_sample_max_error", 1, &navigation_mesh_class_set_detail_sample_max_error),
	JS_CFUNC_DEF("get_detail_sample_max_error", 0, &navigation_mesh_class_get_detail_sample_max_error),
	JS_CFUNC_DEF("set_filter_low_hanging_obstacles", 1, &navigation_mesh_class_set_filter_low_hanging_obstacles),
	JS_CFUNC_DEF("get_filter_low_hanging_obstacles", 0, &navigation_mesh_class_get_filter_low_hanging_obstacles),
	JS_CFUNC_DEF("set_filter_ledge_spans", 1, &navigation_mesh_class_set_filter_ledge_spans),
	JS_CFUNC_DEF("get_filter_ledge_spans", 0, &navigation_mesh_class_get_filter_ledge_spans),
	JS_CFUNC_DEF("set_filter_walkable_low_height_spans", 1, &navigation_mesh_class_set_filter_walkable_low_height_spans),
	JS_CFUNC_DEF("get_filter_walkable_low_height_spans", 0, &navigation_mesh_class_get_filter_walkable_low_height_spans),
	JS_CFUNC_DEF("set_filter_baking_aabb", 1, &navigation_mesh_class_set_filter_baking_aabb),
	JS_CFUNC_DEF("get_filter_baking_aabb", 0, &navigation_mesh_class_get_filter_baking_aabb),
	JS_CFUNC_DEF("set_filter_baking_aabb_offset", 1, &navigation_mesh_class_set_filter_baking_aabb_offset),
	JS_CFUNC_DEF("get_filter_baking_aabb_offset", 0, &navigation_mesh_class_get_filter_baking_aabb_offset),
	JS_CFUNC_DEF("set_vertices", 1, &navigation_mesh_class_set_vertices),
	JS_CFUNC_DEF("get_vertices", 0, &navigation_mesh_class_get_vertices),
	JS_CFUNC_DEF("add_polygon", 1, &navigation_mesh_class_add_polygon),
	JS_CFUNC_DEF("get_polygon_count", 0, &navigation_mesh_class_get_polygon_count),
	JS_CFUNC_DEF("get_polygon", 1, &navigation_mesh_class_get_polygon),
	JS_CFUNC_DEF("clear_polygons", 0, &navigation_mesh_class_clear_polygons),
	JS_CFUNC_DEF("create_from_mesh", 1, &navigation_mesh_class_create_from_mesh),
	JS_CFUNC_DEF("clear", 0, &navigation_mesh_class_clear),
};




static void define_navigation_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertices"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_vertices, "get_vertices", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_vertices, "set_vertices", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sample_partition_type"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_sample_partition_type, "get_sample_partition_type", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_sample_partition_type, "set_sample_partition_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "geometry_parsed_geometry_type"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_parsed_geometry_type, "get_parsed_geometry_type", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_parsed_geometry_type, "set_parsed_geometry_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "geometry_collision_mask"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "geometry_source_geometry_mode"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_source_geometry_mode, "get_source_geometry_mode", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_source_geometry_mode, "set_source_geometry_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "geometry_source_group_name"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_source_group_name, "get_source_group_name", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_source_group_name, "set_source_group_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cell_size"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_cell_size, "get_cell_size", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_cell_size, "set_cell_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cell_height"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_cell_height, "get_cell_height", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_cell_height, "set_cell_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_size"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_border_size, "get_border_size", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_border_size, "set_border_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "agent_height"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_agent_height, "get_agent_height", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_agent_height, "set_agent_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "agent_radius"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_agent_radius, "get_agent_radius", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_agent_radius, "set_agent_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "agent_max_climb"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_agent_max_climb, "get_agent_max_climb", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_agent_max_climb, "set_agent_max_climb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "agent_max_slope"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_agent_max_slope, "get_agent_max_slope", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_agent_max_slope, "set_agent_max_slope", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region_min_size"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_region_min_size, "get_region_min_size", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_region_min_size, "set_region_min_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region_merge_size"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_region_merge_size, "get_region_merge_size", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_region_merge_size, "set_region_merge_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edge_max_length"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_edge_max_length, "get_edge_max_length", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_edge_max_length, "set_edge_max_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edge_max_error"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_edge_max_error, "get_edge_max_error", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_edge_max_error, "set_edge_max_error", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertices_per_polygon"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_vertices_per_polygon, "get_vertices_per_polygon", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_vertices_per_polygon, "set_vertices_per_polygon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "detail_sample_distance"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_detail_sample_distance, "get_detail_sample_distance", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_detail_sample_distance, "set_detail_sample_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "detail_sample_max_error"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_detail_sample_max_error, "get_detail_sample_max_error", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_detail_sample_max_error, "set_detail_sample_max_error", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter_low_hanging_obstacles"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_filter_low_hanging_obstacles, "get_filter_low_hanging_obstacles", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_filter_low_hanging_obstacles, "set_filter_low_hanging_obstacles", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter_ledge_spans"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_filter_ledge_spans, "get_filter_ledge_spans", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_filter_ledge_spans, "set_filter_ledge_spans", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter_walkable_low_height_spans"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_filter_walkable_low_height_spans, "get_filter_walkable_low_height_spans", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_filter_walkable_low_height_spans, "set_filter_walkable_low_height_spans", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter_baking_aabb"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_filter_baking_aabb, "get_filter_baking_aabb", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_filter_baking_aabb, "set_filter_baking_aabb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter_baking_aabb_offset"),
        JS_NewCFunction(ctx, navigation_mesh_class_get_filter_baking_aabb_offset, "get_filter_baking_aabb_offset", 0),
        JS_NewCFunction(ctx, navigation_mesh_class_set_filter_baking_aabb_offset, "set_filter_baking_aabb_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_mesh_enum(JSContext *ctx, JSValue proto) {
	JSValue SamplePartitionType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_WATERSHED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_MONOTONE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_LAYERS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "SamplePartitionType", SamplePartitionType_obj);
	JSValue ParsedGeometryType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_MESH_INSTANCES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_STATIC_COLLIDERS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_BOTH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "ParsedGeometryType", ParsedGeometryType_obj);
	JSValue SourceGeometryMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_ROOT_NODE_CHILDREN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_GROUPS_WITH_CHILDREN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_GROUPS_EXPLICIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "SourceGeometryMode", SourceGeometryMode_obj);
}

static int js_navigation_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationMesh"] = class_id;
	classes_by_id[class_id] = "NavigationMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_mesh_property(ctx, proto);
	define_navigation_mesh_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_mesh_class_proto_funcs, _countof(navigation_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_mesh_class_constructor, "NavigationMesh", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationMesh");
	return m;
}

JSModuleDef *js_init_navigation_mesh_module(JSContext *ctx) {
	return _js_init_navigation_mesh_module(ctx, "@godot/classes/navigation_mesh");
}

void __register_navigation_mesh() {
	js_init_navigation_mesh_module(js_context());
}

void register_navigation_mesh() {
	__register_navigation_mesh();
}