
#include "register/builtin_classes/register_builtin_classes.h"
#include "quickjs/quickjs.h"
#include "quickjs/env.h"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/variant_helper.hpp"
#include <godot_cpp/variant/plane.hpp>

using namespace godot;

static void plane_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Plane"];
	Plane *plane = static_cast<Plane *>(JS_GetOpaque(val, class_id));
	if (plane)
		memfree(plane);
}

static JSClassDef plane_class_def = {
	"Plane",
	.finalizer = plane_class_finalizer
};

static JSValue plane_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Plane"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Plane *plane_class = nullptr;
	
	if (argc == 0 ) {
		plane_class = memnew(Plane());
	}
	
	if (argc == 1 &&VariantAdapter(argv[0]).get_type() == Variant::Type::PLANE) {
		Plane v0 = VariantAdapter(argv[0]);
		plane_class = memnew(Plane(v0));
	}
	
	if (argc == 1 &&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3) {
		Vector3 v0 = VariantAdapter(argv[0]);
		plane_class = memnew(Plane(v0));
	}
	
	if (argc == 2 &&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT||VariantAdapter(argv[1]).get_type() == Variant::Type::INT)) {
		Vector3 v0 = VariantAdapter(argv[0]);
		float v1 = VariantAdapter(argv[1]);
		plane_class = memnew(Plane(v0,v1));
	}
	
	if (argc == 2 &&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3&&VariantAdapter(argv[1]).get_type() == Variant::Type::VECTOR3) {
		Vector3 v0 = VariantAdapter(argv[0]);
		Vector3 v1 = VariantAdapter(argv[1]);
		plane_class = memnew(Plane(v0,v1));
	}
	
	if (argc == 3 &&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3&&VariantAdapter(argv[1]).get_type() == Variant::Type::VECTOR3&&VariantAdapter(argv[2]).get_type() == Variant::Type::VECTOR3) {
		Vector3 v0 = VariantAdapter(argv[0]);
		Vector3 v1 = VariantAdapter(argv[1]);
		Vector3 v2 = VariantAdapter(argv[2]);
		plane_class = memnew(Plane(v0,v1,v2));
	}
	
	if (argc == 4 &&(VariantAdapter(argv[0]).get_type() == Variant::Type::FLOAT||VariantAdapter(argv[0]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT||VariantAdapter(argv[1]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[2]).get_type() == Variant::Type::FLOAT||VariantAdapter(argv[2]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[3]).get_type() == Variant::Type::FLOAT||VariantAdapter(argv[3]).get_type() == Variant::Type::INT)) {
		float v0 = VariantAdapter(argv[0]);
		float v1 = VariantAdapter(argv[1]);
		float v2 = VariantAdapter(argv[2]);
		float v3 = VariantAdapter(argv[3]);
		plane_class = memnew(Plane(v0,v1,v2,v3));
	}
	

	if (!plane_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, plane_class);
	return obj;
}
static JSValue plane_class_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::normalized, ctx, this_val, argc, argv);
};
static JSValue plane_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::is_equal_approx, ctx, this_val, argc, argv);
};
static JSValue plane_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::is_finite, ctx, this_val, argc, argv);
};
static JSValue plane_class_is_point_over(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::is_point_over, ctx, this_val, argc, argv);
};
static JSValue plane_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::distance_to, ctx, this_val, argc, argv);
};
static JSValue plane_class_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::has_point, ctx, this_val, argc, argv);
};
static JSValue plane_class_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::project, ctx, this_val, argc, argv);
};
static JSValue plane_class_intersect_3(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::intersect_3, ctx, this_val, argc, argv);
};
static JSValue plane_class_intersects_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::intersects_ray, ctx, this_val, argc, argv);
};
static JSValue plane_class_intersects_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::intersects_segment, ctx, this_val, argc, argv);
};
static JSValue plane_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	return VariantAdapter(val.normal.x);
}
static JSValue plane_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	val.normal.x = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static JSValue plane_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	return VariantAdapter(val.normal.y);
}
static JSValue plane_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	val.normal.y = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static JSValue plane_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	return VariantAdapter(val.normal.z);
}
static JSValue plane_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	val.normal.z = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static JSValue plane_class_get_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	return VariantAdapter(val.d);
}
static JSValue plane_class_set_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	val.d = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static JSValue plane_class_get_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	return VariantAdapter(val.normal);
}
static JSValue plane_class_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes["Plane"]));
	val.normal = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static const JSCFunctionListEntry plane_class_proto_funcs[] = {
	JS_CFUNC_DEF("normalized", 0, &plane_class_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &plane_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &plane_class_is_finite),
	JS_CFUNC_DEF("is_point_over", 1, &plane_class_is_point_over),
	JS_CFUNC_DEF("distance_to", 1, &plane_class_distance_to),
	JS_CFUNC_DEF("has_point", 2, &plane_class_has_point),
	JS_CFUNC_DEF("project", 1, &plane_class_project),
	JS_CFUNC_DEF("intersect_3", 2, &plane_class_intersect_3),
	JS_CFUNC_DEF("intersects_ray", 2, &plane_class_intersects_ray),
	JS_CFUNC_DEF("intersects_segment", 2, &plane_class_intersects_segment),
};
void define_plane_property(JSContext *ctx, JSValue obj) {
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "x"),
        JS_NewCFunction(ctx, plane_class_get_x, "get_x", 0),
        JS_NewCFunction(ctx, plane_class_set_x, "set_x", 1),
		JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "y"),
        JS_NewCFunction(ctx, plane_class_get_y, "get_y", 0),
        JS_NewCFunction(ctx, plane_class_set_y, "set_y", 1),
		JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "z"),
        JS_NewCFunction(ctx, plane_class_get_z, "get_z", 0),
        JS_NewCFunction(ctx, plane_class_set_z, "set_z", 1),
		JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "d"),
        JS_NewCFunction(ctx, plane_class_get_d, "get_d", 0),
        JS_NewCFunction(ctx, plane_class_set_d, "set_d", 1),
		JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "normal"),
        JS_NewCFunction(ctx, plane_class_get_normal, "get_normal", 0),
        JS_NewCFunction(ctx, plane_class_set_normal, "set_normal", 1),
		JS_PROP_GETSET
    );
}
void define_plane_constants(JSContext *ctx, JSValue ctor) {
	JS_DefinePropertyValueStr(ctx, ctor, "PLANE_YZ", VariantAdapter(Plane(1, 0, 0, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "PLANE_XZ", VariantAdapter(Plane(0, 1, 0, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "PLANE_XY", VariantAdapter(Plane(0, 0, 1, 0)), JS_PROP_ENUMERABLE);
}

static int js_plane_class_init(JSContext *ctx) {
	classes["Plane"] = 0;
	classes["Plane"] = JS_NewClassID(&classes["Plane"]);
	JSClassID class_id = classes["Plane"];

	class_id_list.insert(class_id);
	JS_NewClass(JS_GetRuntime(ctx), class_id, &plane_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_plane_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, plane_class_proto_funcs, _countof(plane_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, plane_class_constructor, "Plane", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	define_plane_constants(ctx, ctor);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Plane", ctor);

	return 0;
}

void js_init_plane_module(JSContext *ctx) {
	js_plane_class_init(ctx);
}

void register_plane() {
	js_init_plane_module(ctx);
}