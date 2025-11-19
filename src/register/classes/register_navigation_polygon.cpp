#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/navigation_mesh.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_polygon.hpp>
using namespace godot;

static void navigation_polygon_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationPolygon"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_polygon_class_def = {
    "NavigationPolygon",
    navigation_polygon_class_finalizer
};

static JSValue navigation_polygon_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationPolygon"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationPolygon *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationPolygon *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationPolygon);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_polygon_class_set_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_vertices, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		NavigationPolygon *obj = static_cast<NavigationPolygon *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_vertices();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		NavigationPolygon *js_proxy = static_cast<NavigationPolygon *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_vertices(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_polygon_class_add_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::add_polygon, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_polygon_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_polygon_count, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationPolygon::get_polygon, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_clear_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::clear_polygons, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationPolygon::get_navigation_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_add_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::add_outline, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_add_outline_at_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::add_outline_at_index, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_outline_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_outline_count, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_set_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_outline, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_outline, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_remove_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::remove_outline, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_clear_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::clear_outlines, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_make_polygons_from_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::make_polygons_from_outlines, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_set_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_cell_size, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_cell_size, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_border_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_border_size, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_border_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_border_size, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_sample_partition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_sample_partition_type, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_sample_partition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_sample_partition_type, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_parsed_geometry_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_parsed_geometry_type, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_parsed_geometry_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_parsed_geometry_type, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_parsed_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_parsed_collision_mask, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_parsed_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_parsed_collision_mask, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_parsed_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_parsed_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_parsed_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_parsed_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_set_source_geometry_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_source_geometry_mode, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_source_geometry_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_source_geometry_mode, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_source_geometry_group_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_source_geometry_group_name, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_source_geometry_group_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_source_geometry_group_name, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_agent_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_agent_radius, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_agent_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPolygon::get_agent_radius, ctx, this_val, argc, argv);
}
static JSValue navigation_polygon_class_set_baking_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_baking_rect, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_baking_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		NavigationPolygon *obj = static_cast<NavigationPolygon *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_baking_rect();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		NavigationPolygon *js_proxy = static_cast<NavigationPolygon *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_baking_rect(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_polygon_class_set_baking_rect_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::set_baking_rect_offset, ctx, this_val, argc, argv);
};
static JSValue navigation_polygon_class_get_baking_rect_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		NavigationPolygon *obj = static_cast<NavigationPolygon *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_baking_rect_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		NavigationPolygon *js_proxy = static_cast<NavigationPolygon *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_baking_rect_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_polygon_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPolygon::clear, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry navigation_polygon_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_vertices", 1, &navigation_polygon_class_set_vertices),
	JS_CFUNC_DEF("get_vertices", 0, &navigation_polygon_class_get_vertices),
	JS_CFUNC_DEF("add_polygon", 1, &navigation_polygon_class_add_polygon),
	JS_CFUNC_DEF("get_polygon_count", 0, &navigation_polygon_class_get_polygon_count),
	JS_CFUNC_DEF("get_polygon", 1, &navigation_polygon_class_get_polygon),
	JS_CFUNC_DEF("clear_polygons", 0, &navigation_polygon_class_clear_polygons),
	JS_CFUNC_DEF("get_navigation_mesh", 0, &navigation_polygon_class_get_navigation_mesh),
	JS_CFUNC_DEF("add_outline", 1, &navigation_polygon_class_add_outline),
	JS_CFUNC_DEF("add_outline_at_index", 2, &navigation_polygon_class_add_outline_at_index),
	JS_CFUNC_DEF("get_outline_count", 0, &navigation_polygon_class_get_outline_count),
	JS_CFUNC_DEF("set_outline", 2, &navigation_polygon_class_set_outline),
	JS_CFUNC_DEF("get_outline", 1, &navigation_polygon_class_get_outline),
	JS_CFUNC_DEF("remove_outline", 1, &navigation_polygon_class_remove_outline),
	JS_CFUNC_DEF("clear_outlines", 0, &navigation_polygon_class_clear_outlines),
	JS_CFUNC_DEF("make_polygons_from_outlines", 0, &navigation_polygon_class_make_polygons_from_outlines),
	JS_CFUNC_DEF("set_cell_size", 1, &navigation_polygon_class_set_cell_size),
	JS_CFUNC_DEF("get_cell_size", 0, &navigation_polygon_class_get_cell_size),
	JS_CFUNC_DEF("set_border_size", 1, &navigation_polygon_class_set_border_size),
	JS_CFUNC_DEF("get_border_size", 0, &navigation_polygon_class_get_border_size),
	JS_CFUNC_DEF("set_sample_partition_type", 1, &navigation_polygon_class_set_sample_partition_type),
	JS_CFUNC_DEF("get_sample_partition_type", 0, &navigation_polygon_class_get_sample_partition_type),
	JS_CFUNC_DEF("set_parsed_geometry_type", 1, &navigation_polygon_class_set_parsed_geometry_type),
	JS_CFUNC_DEF("get_parsed_geometry_type", 0, &navigation_polygon_class_get_parsed_geometry_type),
	JS_CFUNC_DEF("set_parsed_collision_mask", 1, &navigation_polygon_class_set_parsed_collision_mask),
	JS_CFUNC_DEF("get_parsed_collision_mask", 0, &navigation_polygon_class_get_parsed_collision_mask),
	JS_CFUNC_DEF("set_parsed_collision_mask_value", 2, &navigation_polygon_class_set_parsed_collision_mask_value),
	JS_CFUNC_DEF("get_parsed_collision_mask_value", 1, &navigation_polygon_class_get_parsed_collision_mask_value),
	JS_CFUNC_DEF("set_source_geometry_mode", 1, &navigation_polygon_class_set_source_geometry_mode),
	JS_CFUNC_DEF("get_source_geometry_mode", 0, &navigation_polygon_class_get_source_geometry_mode),
	JS_CFUNC_DEF("set_source_geometry_group_name", 1, &navigation_polygon_class_set_source_geometry_group_name),
	JS_CFUNC_DEF("get_source_geometry_group_name", 0, &navigation_polygon_class_get_source_geometry_group_name),
	JS_CFUNC_DEF("set_agent_radius", 1, &navigation_polygon_class_set_agent_radius),
	JS_CFUNC_DEF("get_agent_radius", 0, &navigation_polygon_class_get_agent_radius),
	JS_CFUNC_DEF("set_baking_rect", 1, &navigation_polygon_class_set_baking_rect),
	JS_CFUNC_DEF("get_baking_rect", 0, &navigation_polygon_class_get_baking_rect),
	JS_CFUNC_DEF("set_baking_rect_offset", 1, &navigation_polygon_class_set_baking_rect_offset),
	JS_CFUNC_DEF("get_baking_rect_offset", 0, &navigation_polygon_class_get_baking_rect_offset),
	JS_CFUNC_DEF("clear", 0, &navigation_polygon_class_clear),
};




static void define_navigation_polygon_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertices"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_vertices, "get_vertices", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_vertices, "set_vertices", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sample_partition_type"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_sample_partition_type, "get_sample_partition_type", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_sample_partition_type, "set_sample_partition_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "parsed_geometry_type"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_parsed_geometry_type, "get_parsed_geometry_type", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_parsed_geometry_type, "set_parsed_geometry_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "parsed_collision_mask"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_parsed_collision_mask, "get_parsed_collision_mask", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_parsed_collision_mask, "set_parsed_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "source_geometry_mode"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_source_geometry_mode, "get_source_geometry_mode", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_source_geometry_mode, "set_source_geometry_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "source_geometry_group_name"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_source_geometry_group_name, "get_source_geometry_group_name", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_source_geometry_group_name, "set_source_geometry_group_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cell_size"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_cell_size, "get_cell_size", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_cell_size, "set_cell_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_size"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_border_size, "get_border_size", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_border_size, "set_border_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "agent_radius"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_agent_radius, "get_agent_radius", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_agent_radius, "set_agent_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "baking_rect"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_baking_rect, "get_baking_rect", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_baking_rect, "set_baking_rect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "baking_rect_offset"),
        JS_NewCFunction(ctx, navigation_polygon_class_get_baking_rect_offset, "get_baking_rect_offset", 0),
        JS_NewCFunction(ctx, navigation_polygon_class_set_baking_rect_offset, "set_baking_rect_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_polygon_enum(JSContext *ctx, JSValue ctor) {
	JSValue SamplePartitionType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_CONVEX_PARTITION", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_TRIANGULATE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SamplePartitionType_obj, "SAMPLE_PARTITION_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SamplePartitionType", SamplePartitionType_obj);
	JSValue ParsedGeometryType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_MESH_INSTANCES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_STATIC_COLLIDERS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_BOTH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ParsedGeometryType_obj, "PARSED_GEOMETRY_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ParsedGeometryType", ParsedGeometryType_obj);
	JSValue SourceGeometryMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_ROOT_NODE_CHILDREN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_GROUPS_WITH_CHILDREN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_GROUPS_EXPLICIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SourceGeometryMode_obj, "SOURCE_GEOMETRY_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "SourceGeometryMode", SourceGeometryMode_obj);
}

static int js_navigation_polygon_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationPolygon"] = class_id;
	classes_by_id[class_id] = "NavigationPolygon";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_polygon_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_polygon_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_polygon_class_proto_funcs, _countof(navigation_polygon_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_polygon_class_constructor, "NavigationPolygon", 0, JS_CFUNC_constructor, 0);
	define_navigation_polygon_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationPolygon", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_polygon_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_polygon_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationPolygon");
	return m;
}

JSModuleDef *js_init_navigation_polygon_module(JSContext *ctx) {
	return _js_init_navigation_polygon_module(ctx, "@godot/classes/navigation_polygon");
}

void __register_navigation_polygon() {
	js_init_navigation_polygon_module(js_context());
}

void register_navigation_polygon() {
	__register_navigation_polygon();
}