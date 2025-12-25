#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/geometry3d.hpp>


using namespace godot;

static void geometry3d_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef geometry3d_class_def = {
	"_Geometry3D",
	geometry3d_class_finalizer
};

static JSValue geometry3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Geometry3D"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Geometry3D *geometry3d_class = Geometry3D::get_singleton();
	if (!geometry3d_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, geometry3d_class);
	return obj;
}

static JSValue geometry3d_class_compute_convex_mesh_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::compute_convex_mesh_points, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_build_box_planes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::build_box_planes, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_build_cylinder_planes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::build_cylinder_planes, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_build_capsule_planes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::build_capsule_planes, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_get_closest_points_between_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::get_closest_points_between_segments, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_get_closest_point_to_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::get_closest_point_to_segment, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_get_closest_point_to_segment_uncapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::get_closest_point_to_segment_uncapped, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_get_triangle_barycentric_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::get_triangle_barycentric_coords, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_ray_intersects_triangle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::ray_intersects_triangle, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_segment_intersects_triangle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::segment_intersects_triangle, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_segment_intersects_sphere(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::segment_intersects_sphere, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_segment_intersects_cylinder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::segment_intersects_cylinder, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_segment_intersects_convex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::segment_intersects_convex, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_clip_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::clip_polygon, ctx, this_val, argc, argv);
};
static JSValue geometry3d_class_tetrahedralize_delaunay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Geometry3D::tetrahedralize_delaunay, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry geometry3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("compute_convex_mesh_points", 1, &geometry3d_class_compute_convex_mesh_points),
	JS_CFUNC_DEF("build_box_planes", 1, &geometry3d_class_build_box_planes),
	JS_CFUNC_DEF("build_cylinder_planes", 4, &geometry3d_class_build_cylinder_planes),
	JS_CFUNC_DEF("build_capsule_planes", 5, &geometry3d_class_build_capsule_planes),
	JS_CFUNC_DEF("get_closest_points_between_segments", 4, &geometry3d_class_get_closest_points_between_segments),
	JS_CFUNC_DEF("get_closest_point_to_segment", 3, &geometry3d_class_get_closest_point_to_segment),
	JS_CFUNC_DEF("get_closest_point_to_segment_uncapped", 3, &geometry3d_class_get_closest_point_to_segment_uncapped),
	JS_CFUNC_DEF("get_triangle_barycentric_coords", 4, &geometry3d_class_get_triangle_barycentric_coords),
	JS_CFUNC_DEF("ray_intersects_triangle", 5, &geometry3d_class_ray_intersects_triangle),
	JS_CFUNC_DEF("segment_intersects_triangle", 5, &geometry3d_class_segment_intersects_triangle),
	JS_CFUNC_DEF("segment_intersects_sphere", 4, &geometry3d_class_segment_intersects_sphere),
	JS_CFUNC_DEF("segment_intersects_cylinder", 4, &geometry3d_class_segment_intersects_cylinder),
	JS_CFUNC_DEF("segment_intersects_convex", 3, &geometry3d_class_segment_intersects_convex),
	JS_CFUNC_DEF("clip_polygon", 2, &geometry3d_class_clip_polygon),
	JS_CFUNC_DEF("tetrahedralize_delaunay", 1, &geometry3d_class_tetrahedralize_delaunay),
};




static int js_geometry3d_class_init(JSContext *ctx) {
	JSClassID class_id = classes["Geometry3D"];
	classes["Geometry3D"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &geometry3d_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, geometry3d_class_proto_funcs, _countof(geometry3d_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, geometry3d_class_constructor, "_Geometry3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Geometry3D", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_geometry3d() {
	js_geometry3d_class_init(js_context());
}