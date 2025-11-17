#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/csg_primitive3d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/csg_polygon3d.hpp>
using namespace godot;

static void csg_polygon3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CSGPolygon3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef csg_polygon3d_class_def = {
    "CSGPolygon3D",
    csg_polygon3d_class_finalizer
};

static JSValue csg_polygon3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CSGPolygon3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CSGPolygon3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CSGPolygon3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CSGPolygon3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue csg_polygon3d_class_set_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_polygon, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		CSGPolygon3D *obj = static_cast<CSGPolygon3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_polygon();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		CSGPolygon3D *js_proxy = static_cast<CSGPolygon3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_polygon(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue csg_polygon3d_class_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_mode, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_mode, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_depth, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_depth, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_spin_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_spin_degrees, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_spin_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_spin_degrees, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_spin_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_spin_sides, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_spin_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_spin_sides, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_node, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		CSGPolygon3D *obj = static_cast<CSGPolygon3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_path_node();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		CSGPolygon3D *js_proxy = static_cast<CSGPolygon3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_path_node(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue csg_polygon3d_class_set_path_interval_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_interval_type, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_interval_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_path_interval_type, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_interval, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_path_interval, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_simplify_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_simplify_angle, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_simplify_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_path_simplify_angle, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_rotation, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_path_rotation, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_rotation_accurate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_rotation_accurate, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_rotation_accurate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_path_rotation_accurate, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_local, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_is_path_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::is_path_local, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_continuous_u(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_continuous_u, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_is_path_continuous_u(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::is_path_continuous_u, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_u_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_u_distance, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_path_u_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_path_u_distance, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_path_joined(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_path_joined, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_is_path_joined(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::is_path_joined, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_material, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_material, ctx, this_val, argc, argv);
}
static JSValue csg_polygon3d_class_set_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGPolygon3D::set_smooth_faces, ctx, this_val, argc, argv);
};
static JSValue csg_polygon3d_class_get_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGPolygon3D::get_smooth_faces, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry csg_polygon3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_polygon", 1, &csg_polygon3d_class_set_polygon),
	JS_CFUNC_DEF("get_polygon", 0, &csg_polygon3d_class_get_polygon),
	JS_CFUNC_DEF("set_mode", 1, &csg_polygon3d_class_set_mode),
	JS_CFUNC_DEF("get_mode", 0, &csg_polygon3d_class_get_mode),
	JS_CFUNC_DEF("set_depth", 1, &csg_polygon3d_class_set_depth),
	JS_CFUNC_DEF("get_depth", 0, &csg_polygon3d_class_get_depth),
	JS_CFUNC_DEF("set_spin_degrees", 1, &csg_polygon3d_class_set_spin_degrees),
	JS_CFUNC_DEF("get_spin_degrees", 0, &csg_polygon3d_class_get_spin_degrees),
	JS_CFUNC_DEF("set_spin_sides", 1, &csg_polygon3d_class_set_spin_sides),
	JS_CFUNC_DEF("get_spin_sides", 0, &csg_polygon3d_class_get_spin_sides),
	JS_CFUNC_DEF("set_path_node", 1, &csg_polygon3d_class_set_path_node),
	JS_CFUNC_DEF("get_path_node", 0, &csg_polygon3d_class_get_path_node),
	JS_CFUNC_DEF("set_path_interval_type", 1, &csg_polygon3d_class_set_path_interval_type),
	JS_CFUNC_DEF("get_path_interval_type", 0, &csg_polygon3d_class_get_path_interval_type),
	JS_CFUNC_DEF("set_path_interval", 1, &csg_polygon3d_class_set_path_interval),
	JS_CFUNC_DEF("get_path_interval", 0, &csg_polygon3d_class_get_path_interval),
	JS_CFUNC_DEF("set_path_simplify_angle", 1, &csg_polygon3d_class_set_path_simplify_angle),
	JS_CFUNC_DEF("get_path_simplify_angle", 0, &csg_polygon3d_class_get_path_simplify_angle),
	JS_CFUNC_DEF("set_path_rotation", 1, &csg_polygon3d_class_set_path_rotation),
	JS_CFUNC_DEF("get_path_rotation", 0, &csg_polygon3d_class_get_path_rotation),
	JS_CFUNC_DEF("set_path_rotation_accurate", 1, &csg_polygon3d_class_set_path_rotation_accurate),
	JS_CFUNC_DEF("get_path_rotation_accurate", 0, &csg_polygon3d_class_get_path_rotation_accurate),
	JS_CFUNC_DEF("set_path_local", 1, &csg_polygon3d_class_set_path_local),
	JS_CFUNC_DEF("is_path_local", 0, &csg_polygon3d_class_is_path_local),
	JS_CFUNC_DEF("set_path_continuous_u", 1, &csg_polygon3d_class_set_path_continuous_u),
	JS_CFUNC_DEF("is_path_continuous_u", 0, &csg_polygon3d_class_is_path_continuous_u),
	JS_CFUNC_DEF("set_path_u_distance", 1, &csg_polygon3d_class_set_path_u_distance),
	JS_CFUNC_DEF("get_path_u_distance", 0, &csg_polygon3d_class_get_path_u_distance),
	JS_CFUNC_DEF("set_path_joined", 1, &csg_polygon3d_class_set_path_joined),
	JS_CFUNC_DEF("is_path_joined", 0, &csg_polygon3d_class_is_path_joined),
	JS_CFUNC_DEF("set_material", 1, &csg_polygon3d_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &csg_polygon3d_class_get_material),
	JS_CFUNC_DEF("set_smooth_faces", 1, &csg_polygon3d_class_set_smooth_faces),
	JS_CFUNC_DEF("get_smooth_faces", 0, &csg_polygon3d_class_get_smooth_faces),
};




static void define_csg_polygon3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "polygon"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_polygon, "get_polygon", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_polygon, "set_polygon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mode"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_mode, "get_mode", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_mode, "set_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_depth, "get_depth", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_depth, "set_depth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spin_degrees"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_spin_degrees, "get_spin_degrees", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_spin_degrees, "set_spin_degrees", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spin_sides"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_spin_sides, "get_spin_sides", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_spin_sides, "set_spin_sides", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_node"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_node, "get_path_node", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_node, "set_path_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_interval_type"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_interval_type, "get_path_interval_type", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_interval_type, "set_path_interval_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_interval"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_interval, "get_path_interval", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_interval, "set_path_interval", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_simplify_angle"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_simplify_angle, "get_path_simplify_angle", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_simplify_angle, "set_path_simplify_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_rotation"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_rotation, "get_path_rotation", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_rotation, "set_path_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_rotation_accurate"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_rotation_accurate, "get_path_rotation_accurate", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_rotation_accurate, "set_path_rotation_accurate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_local"),
        JS_NewCFunction(ctx, csg_polygon3d_class_is_path_local, "is_path_local", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_local, "set_path_local", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_continuous_u"),
        JS_NewCFunction(ctx, csg_polygon3d_class_is_path_continuous_u, "is_path_continuous_u", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_continuous_u, "set_path_continuous_u", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_u_distance"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_path_u_distance, "get_path_u_distance", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_u_distance, "set_path_u_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_joined"),
        JS_NewCFunction(ctx, csg_polygon3d_class_is_path_joined, "is_path_joined", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_path_joined, "set_path_joined", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "smooth_faces"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_smooth_faces, "get_smooth_faces", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_smooth_faces, "set_smooth_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, csg_polygon3d_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, csg_polygon3d_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
}

static void define_csg_polygon3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Mode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_DEPTH", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_SPIN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_PATH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Mode", Mode_obj);
	JSValue PathRotation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PathRotation_obj, "PATH_ROTATION_POLYGON", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PathRotation_obj, "PATH_ROTATION_PATH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PathRotation_obj, "PATH_ROTATION_PATH_FOLLOW", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PathRotation", PathRotation_obj);
	JSValue PathIntervalType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PathIntervalType_obj, "PATH_INTERVAL_DISTANCE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PathIntervalType_obj, "PATH_INTERVAL_SUBDIVIDE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "PathIntervalType", PathIntervalType_obj);
}

static int js_csg_polygon3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CSGPolygon3D"] = class_id;
	classes_by_id[class_id] = "CSGPolygon3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &csg_polygon3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CSGPrimitive3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_csg_polygon3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, csg_polygon3d_class_proto_funcs, _countof(csg_polygon3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, csg_polygon3d_class_constructor, "CSGPolygon3D", 0, JS_CFUNC_constructor, 0);
	define_csg_polygon3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CSGPolygon3D", ctor);

	return 0;
}

JSModuleDef *_js_init_csg_polygon3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/csg_primitive3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_csg_polygon3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CSGPolygon3D");
	return m;
}

JSModuleDef *js_init_csg_polygon3d_module(JSContext *ctx) {
	return _js_init_csg_polygon3d_module(ctx, "@godot/classes/csg_polygon3d");
}

void __register_csg_polygon3d() {
	js_init_csg_polygon3d_module(js_context());
}

void register_csg_polygon3d() {
	__register_csg_polygon3d();
}