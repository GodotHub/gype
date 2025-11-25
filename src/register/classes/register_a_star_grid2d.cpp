#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/a_star_grid2d.hpp>
using namespace godot;

static void a_star_grid2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AStarGrid2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef a_star_grid2d_class_def = {
    "AStarGrid2D",
    a_star_grid2d_class_finalizer
};

static JSValue a_star_grid2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AStarGrid2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(AStarGrid2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue a_star_grid2d_class_set_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_region, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2i> *proxy = memnew(ObjectProxy<Rect2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2i {
		AStarGrid2D *obj = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_region();
	};
	proxy->setter = [this_val](const Rect2i &value) -> void {
		AStarGrid2D *js_proxy = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_region(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue a_star_grid2d_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_size, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		AStarGrid2D *obj = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		AStarGrid2D *js_proxy = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
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
static JSValue a_star_grid2d_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_offset, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		AStarGrid2D *obj = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		AStarGrid2D *js_proxy = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset(value);
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
static JSValue a_star_grid2d_class_set_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_cell_size, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		AStarGrid2D *obj = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_cell_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		AStarGrid2D *js_proxy = static_cast<AStarGrid2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_cell_size(value);
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
static JSValue a_star_grid2d_class_set_cell_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_cell_shape, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_cell_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_cell_shape, ctx, this_val, argc, argv);
}
static JSValue a_star_grid2d_class_is_in_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::is_in_bounds, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_is_in_boundsv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::is_in_boundsv, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_is_dirty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::is_dirty, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::update, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_set_jumping_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_jumping_enabled, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_is_jumping_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::is_jumping_enabled, ctx, this_val, argc, argv);
}
static JSValue a_star_grid2d_class_set_diagonal_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_diagonal_mode, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_diagonal_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_diagonal_mode, ctx, this_val, argc, argv);
}
static JSValue a_star_grid2d_class_set_default_compute_heuristic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_default_compute_heuristic, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_default_compute_heuristic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_default_compute_heuristic, ctx, this_val, argc, argv);
}
static JSValue a_star_grid2d_class_set_default_estimate_heuristic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_default_estimate_heuristic, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_default_estimate_heuristic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_default_estimate_heuristic, ctx, this_val, argc, argv);
}
static JSValue a_star_grid2d_class_set_point_solid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_point_solid, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_is_point_solid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::is_point_solid, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_set_point_weight_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::set_point_weight_scale, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_point_weight_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_point_weight_scale, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_fill_solid_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::fill_solid_region, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_fill_weight_scale_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::fill_weight_scale_region, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStarGrid2D::clear, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_point_position, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_point_data_in_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStarGrid2D::get_point_data_in_region, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_point_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AStarGrid2D::get_point_path, ctx, this_val, argc, argv);
};
static JSValue a_star_grid2d_class_get_id_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AStarGrid2D::get_id_path, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry a_star_grid2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_region", 1, &a_star_grid2d_class_set_region),
	JS_CFUNC_DEF("get_region", 0, &a_star_grid2d_class_get_region),
	JS_CFUNC_DEF("set_size", 1, &a_star_grid2d_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &a_star_grid2d_class_get_size),
	JS_CFUNC_DEF("set_offset", 1, &a_star_grid2d_class_set_offset),
	JS_CFUNC_DEF("get_offset", 0, &a_star_grid2d_class_get_offset),
	JS_CFUNC_DEF("set_cell_size", 1, &a_star_grid2d_class_set_cell_size),
	JS_CFUNC_DEF("get_cell_size", 0, &a_star_grid2d_class_get_cell_size),
	JS_CFUNC_DEF("set_cell_shape", 1, &a_star_grid2d_class_set_cell_shape),
	JS_CFUNC_DEF("get_cell_shape", 0, &a_star_grid2d_class_get_cell_shape),
	JS_CFUNC_DEF("is_in_bounds", 2, &a_star_grid2d_class_is_in_bounds),
	JS_CFUNC_DEF("is_in_boundsv", 1, &a_star_grid2d_class_is_in_boundsv),
	JS_CFUNC_DEF("is_dirty", 0, &a_star_grid2d_class_is_dirty),
	JS_CFUNC_DEF("update", 0, &a_star_grid2d_class_update),
	JS_CFUNC_DEF("set_jumping_enabled", 1, &a_star_grid2d_class_set_jumping_enabled),
	JS_CFUNC_DEF("is_jumping_enabled", 0, &a_star_grid2d_class_is_jumping_enabled),
	JS_CFUNC_DEF("set_diagonal_mode", 1, &a_star_grid2d_class_set_diagonal_mode),
	JS_CFUNC_DEF("get_diagonal_mode", 0, &a_star_grid2d_class_get_diagonal_mode),
	JS_CFUNC_DEF("set_default_compute_heuristic", 1, &a_star_grid2d_class_set_default_compute_heuristic),
	JS_CFUNC_DEF("get_default_compute_heuristic", 0, &a_star_grid2d_class_get_default_compute_heuristic),
	JS_CFUNC_DEF("set_default_estimate_heuristic", 1, &a_star_grid2d_class_set_default_estimate_heuristic),
	JS_CFUNC_DEF("get_default_estimate_heuristic", 0, &a_star_grid2d_class_get_default_estimate_heuristic),
	JS_CFUNC_DEF("set_point_solid", 2, &a_star_grid2d_class_set_point_solid),
	JS_CFUNC_DEF("is_point_solid", 1, &a_star_grid2d_class_is_point_solid),
	JS_CFUNC_DEF("set_point_weight_scale", 2, &a_star_grid2d_class_set_point_weight_scale),
	JS_CFUNC_DEF("get_point_weight_scale", 1, &a_star_grid2d_class_get_point_weight_scale),
	JS_CFUNC_DEF("fill_solid_region", 2, &a_star_grid2d_class_fill_solid_region),
	JS_CFUNC_DEF("fill_weight_scale_region", 2, &a_star_grid2d_class_fill_weight_scale_region),
	JS_CFUNC_DEF("clear", 0, &a_star_grid2d_class_clear),
	JS_CFUNC_DEF("get_point_position", 1, &a_star_grid2d_class_get_point_position),
	JS_CFUNC_DEF("get_point_data_in_region", 1, &a_star_grid2d_class_get_point_data_in_region),
	JS_CFUNC_DEF("get_point_path", 3, &a_star_grid2d_class_get_point_path),
	JS_CFUNC_DEF("get_id_path", 3, &a_star_grid2d_class_get_id_path),
};




static void define_a_star_grid2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_region, "get_region", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_region, "set_region", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cell_size"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_cell_size, "get_cell_size", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_cell_size, "set_cell_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cell_shape"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_cell_shape, "get_cell_shape", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_cell_shape, "set_cell_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "jumping_enabled"),
        JS_NewCFunction(ctx, a_star_grid2d_class_is_jumping_enabled, "is_jumping_enabled", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_jumping_enabled, "set_jumping_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_compute_heuristic"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_default_compute_heuristic, "get_default_compute_heuristic", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_default_compute_heuristic, "set_default_compute_heuristic", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_estimate_heuristic"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_default_estimate_heuristic, "get_default_estimate_heuristic", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_default_estimate_heuristic, "set_default_estimate_heuristic", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "diagonal_mode"),
        JS_NewCFunction(ctx, a_star_grid2d_class_get_diagonal_mode, "get_diagonal_mode", 0),
        JS_NewCFunction(ctx, a_star_grid2d_class_set_diagonal_mode, "set_diagonal_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_a_star_grid2d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Heuristic_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Heuristic_obj, "HEURISTIC_EUCLIDEAN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Heuristic_obj, "HEURISTIC_MANHATTAN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Heuristic_obj, "HEURISTIC_OCTILE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Heuristic_obj, "HEURISTIC_CHEBYSHEV", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Heuristic_obj, "HEURISTIC_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "Heuristic", Heuristic_obj);
	JSValue DiagonalMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DiagonalMode_obj, "DIAGONAL_MODE_ALWAYS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DiagonalMode_obj, "DIAGONAL_MODE_NEVER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DiagonalMode_obj, "DIAGONAL_MODE_AT_LEAST_ONE_WALKABLE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DiagonalMode_obj, "DIAGONAL_MODE_ONLY_IF_NO_OBSTACLES", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DiagonalMode_obj, "DIAGONAL_MODE_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "DiagonalMode", DiagonalMode_obj);
	JSValue CellShape_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CellShape_obj, "CELL_SHAPE_SQUARE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CellShape_obj, "CELL_SHAPE_ISOMETRIC_RIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CellShape_obj, "CELL_SHAPE_ISOMETRIC_DOWN", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CellShape_obj, "CELL_SHAPE_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "CellShape", CellShape_obj);
}

static int js_a_star_grid2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AStarGrid2D"] = class_id;
	classes_by_id[class_id] = "AStarGrid2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &a_star_grid2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_a_star_grid2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, a_star_grid2d_class_proto_funcs, _countof(a_star_grid2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, a_star_grid2d_class_constructor, "AStarGrid2D", 0, JS_CFUNC_constructor, 0);
	define_a_star_grid2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AStarGrid2D", ctor);
	ctor_list["AStarGrid2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_a_star_grid2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_a_star_grid2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AStarGrid2D");
	return m;
}

JSModuleDef *js_init_a_star_grid2d_module(JSContext *ctx) {
	return _js_init_a_star_grid2d_module(ctx, "@godot/classes/a_star_grid2d");
}

void __register_a_star_grid2d() {
	js_init_a_star_grid2d_module(js_context());
}

void register_a_star_grid2d() {
	__register_a_star_grid2d();
}