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
#include <godot_cpp/classes/a_star3d.hpp>
using namespace godot;

static void a_star3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AStar3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef a_star3d_class_def = {
    "AStar3D",
    a_star3d_class_finalizer
};

static JSValue a_star3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AStar3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AStar3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AStar3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AStar3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue a_star3d_class_get_available_point_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_available_point_id, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_add_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::add_point, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_point_position, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_set_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::set_point_position, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_weight_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_point_weight_scale, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_set_point_weight_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::set_point_weight_scale, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_remove_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::remove_point, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::has_point, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AStar3D::get_point_connections, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_ids(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AStar3D::get_point_ids, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_set_point_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::set_point_disabled, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_is_point_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::is_point_disabled, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_set_neighbor_filter_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::set_neighbor_filter_enabled, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_is_neighbor_filter_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::is_neighbor_filter_enabled, ctx, this_val, argc, argv);
}
static JSValue a_star3d_class_connect_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::connect_points, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_disconnect_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::disconnect_points, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_are_points_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::are_points_connected, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_point_count, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_capacity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_point_capacity, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_reserve_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::reserve_space, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AStar3D::clear, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_closest_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_closest_point, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_closest_position_in_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AStar3D::get_closest_position_in_segment, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_point_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AStar3D::get_point_path, ctx, this_val, argc, argv);
};
static JSValue a_star3d_class_get_id_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AStar3D::get_id_path, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry a_star3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_available_point_id", 0, &a_star3d_class_get_available_point_id),
	JS_CFUNC_DEF("add_point", 3, &a_star3d_class_add_point),
	JS_CFUNC_DEF("get_point_position", 1, &a_star3d_class_get_point_position),
	JS_CFUNC_DEF("set_point_position", 2, &a_star3d_class_set_point_position),
	JS_CFUNC_DEF("get_point_weight_scale", 1, &a_star3d_class_get_point_weight_scale),
	JS_CFUNC_DEF("set_point_weight_scale", 2, &a_star3d_class_set_point_weight_scale),
	JS_CFUNC_DEF("remove_point", 1, &a_star3d_class_remove_point),
	JS_CFUNC_DEF("has_point", 1, &a_star3d_class_has_point),
	JS_CFUNC_DEF("get_point_connections", 1, &a_star3d_class_get_point_connections),
	JS_CFUNC_DEF("get_point_ids", 0, &a_star3d_class_get_point_ids),
	JS_CFUNC_DEF("set_point_disabled", 2, &a_star3d_class_set_point_disabled),
	JS_CFUNC_DEF("is_point_disabled", 1, &a_star3d_class_is_point_disabled),
	JS_CFUNC_DEF("set_neighbor_filter_enabled", 1, &a_star3d_class_set_neighbor_filter_enabled),
	JS_CFUNC_DEF("is_neighbor_filter_enabled", 0, &a_star3d_class_is_neighbor_filter_enabled),
	JS_CFUNC_DEF("connect_points", 3, &a_star3d_class_connect_points),
	JS_CFUNC_DEF("disconnect_points", 3, &a_star3d_class_disconnect_points),
	JS_CFUNC_DEF("are_points_connected", 3, &a_star3d_class_are_points_connected),
	JS_CFUNC_DEF("get_point_count", 0, &a_star3d_class_get_point_count),
	JS_CFUNC_DEF("get_point_capacity", 0, &a_star3d_class_get_point_capacity),
	JS_CFUNC_DEF("reserve_space", 1, &a_star3d_class_reserve_space),
	JS_CFUNC_DEF("clear", 0, &a_star3d_class_clear),
	JS_CFUNC_DEF("get_closest_point", 2, &a_star3d_class_get_closest_point),
	JS_CFUNC_DEF("get_closest_position_in_segment", 1, &a_star3d_class_get_closest_position_in_segment),
	JS_CFUNC_DEF("get_point_path", 3, &a_star3d_class_get_point_path),
	JS_CFUNC_DEF("get_id_path", 3, &a_star3d_class_get_id_path),
};




static void define_a_star3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "neighbor_filter_enabled"),
        JS_NewCFunction(ctx, a_star3d_class_is_neighbor_filter_enabled, "is_neighbor_filter_enabled", 0),
        JS_NewCFunction(ctx, a_star3d_class_set_neighbor_filter_enabled, "set_neighbor_filter_enabled", 1),
        JS_PROP_GETSET
    );
}

static void define_a_star3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_a_star3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AStar3D"] = class_id;
	classes_by_id[class_id] = "AStar3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &a_star3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_a_star3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, a_star3d_class_proto_funcs, _countof(a_star3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, a_star3d_class_constructor, "AStar3D", 0, JS_CFUNC_constructor, 0);
	define_a_star3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AStar3D", ctor);

	return 0;
}

JSModuleDef *_js_init_a_star3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_a_star3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AStar3D");
	return m;
}

JSModuleDef *js_init_a_star3d_module(JSContext *ctx) {
	return _js_init_a_star3d_module(ctx, "@godot/classes/a_star3d");
}

void __register_a_star3d() {
	js_init_a_star3d_module(js_context());
}

void register_a_star3d() {
	__register_a_star3d();
}