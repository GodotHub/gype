#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/geometry2d.hpp>


using namespace godot;

static void geometry2d_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef geometry2d_class_def = {
	"_Geometry2D",
	geometry2d_class_finalizer
};

static JSValue geometry2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Geometry2D"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Geometry2D *geometry2d_class = Geometry2D::get_singleton();
	if (!geometry2d_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, geometry2d_class);
	return obj;
}

static JSValue geometry2d_class_is_point_in_circle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::is_point_in_circle, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_segment_intersects_circle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::segment_intersects_circle, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_segment_intersects_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::segment_intersects_segment, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_line_intersects_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::line_intersects_line, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_get_closest_points_between_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::get_closest_points_between_segments, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_get_closest_point_to_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::get_closest_point_to_segment, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_get_closest_point_to_segment_uncapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::get_closest_point_to_segment_uncapped, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_point_is_inside_triangle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Geometry2D::point_is_inside_triangle, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_is_polygon_clockwise(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::is_polygon_clockwise, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_is_point_in_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::is_point_in_polygon, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_triangulate_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::triangulate_polygon, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_triangulate_delaunay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::triangulate_delaunay, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_convex_hull(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::convex_hull, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_decompose_polygon_in_convex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::decompose_polygon_in_convex, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_merge_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::merge_polygons, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_clip_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::clip_polygons, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_intersect_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::intersect_polygons, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_exclude_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::exclude_polygons, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_clip_polyline_with_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::clip_polyline_with_polygon, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_intersect_polyline_with_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::intersect_polyline_with_polygon, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_offset_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::offset_polygon, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_offset_polyline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::offset_polyline, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_make_atlas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::make_atlas, ctx, this_val, argc, argv);
};
static JSValue geometry2d_class_bresenham_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry2D::bresenham_line, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry geometry2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_point_in_circle", 3, &geometry2d_class_is_point_in_circle),
	JS_CFUNC_DEF("segment_intersects_circle", 4, &geometry2d_class_segment_intersects_circle),
	JS_CFUNC_DEF("segment_intersects_segment", 4, &geometry2d_class_segment_intersects_segment),
	JS_CFUNC_DEF("line_intersects_line", 4, &geometry2d_class_line_intersects_line),
	JS_CFUNC_DEF("get_closest_points_between_segments", 4, &geometry2d_class_get_closest_points_between_segments),
	JS_CFUNC_DEF("get_closest_point_to_segment", 3, &geometry2d_class_get_closest_point_to_segment),
	JS_CFUNC_DEF("get_closest_point_to_segment_uncapped", 3, &geometry2d_class_get_closest_point_to_segment_uncapped),
	JS_CFUNC_DEF("point_is_inside_triangle", 4, &geometry2d_class_point_is_inside_triangle),
	JS_CFUNC_DEF("is_polygon_clockwise", 1, &geometry2d_class_is_polygon_clockwise),
	JS_CFUNC_DEF("is_point_in_polygon", 2, &geometry2d_class_is_point_in_polygon),
	JS_CFUNC_DEF("triangulate_polygon", 1, &geometry2d_class_triangulate_polygon),
	JS_CFUNC_DEF("triangulate_delaunay", 1, &geometry2d_class_triangulate_delaunay),
	JS_CFUNC_DEF("convex_hull", 1, &geometry2d_class_convex_hull),
	JS_CFUNC_DEF("decompose_polygon_in_convex", 1, &geometry2d_class_decompose_polygon_in_convex),
	JS_CFUNC_DEF("merge_polygons", 2, &geometry2d_class_merge_polygons),
	JS_CFUNC_DEF("clip_polygons", 2, &geometry2d_class_clip_polygons),
	JS_CFUNC_DEF("intersect_polygons", 2, &geometry2d_class_intersect_polygons),
	JS_CFUNC_DEF("exclude_polygons", 2, &geometry2d_class_exclude_polygons),
	JS_CFUNC_DEF("clip_polyline_with_polygon", 2, &geometry2d_class_clip_polyline_with_polygon),
	JS_CFUNC_DEF("intersect_polyline_with_polygon", 2, &geometry2d_class_intersect_polyline_with_polygon),
	JS_CFUNC_DEF("offset_polygon", 3, &geometry2d_class_offset_polygon),
	JS_CFUNC_DEF("offset_polyline", 4, &geometry2d_class_offset_polyline),
	JS_CFUNC_DEF("make_atlas", 1, &geometry2d_class_make_atlas),
	JS_CFUNC_DEF("bresenham_line", 2, &geometry2d_class_bresenham_line),
};




static int js_geometry2d_class_init(JSContext *ctx) {
	JSClassID class_id = classes["Geometry2D"];
	classes["Geometry2D"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &geometry2d_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, geometry2d_class_proto_funcs, _countof(geometry2d_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, geometry2d_class_constructor, "_Geometry2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_Geometry2D", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_geometry2d() {
	js_geometry2d_class_init(js_context());
}