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
#include <godot_cpp/classes/navigation_path_query_parameters3d.hpp>
using namespace godot;

static void navigation_path_query_parameters3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationPathQueryParameters3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_path_query_parameters3d_class_def = {
    "NavigationPathQueryParameters3D",
    navigation_path_query_parameters3d_class_finalizer
};

static JSValue navigation_path_query_parameters3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationPathQueryParameters3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationPathQueryParameters3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationPathQueryParameters3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_path_query_parameters3d_class_set_pathfinding_algorithm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_pathfinding_algorithm, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_pathfinding_algorithm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_pathfinding_algorithm, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_path_postprocessing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_path_postprocessing, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_path_postprocessing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_path_postprocessing, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_map, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		NavigationPathQueryParameters3D *obj = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_map();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		NavigationPathQueryParameters3D *js_proxy = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_map(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_path_query_parameters3d_class_set_start_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_start_position, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_start_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		NavigationPathQueryParameters3D *obj = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_start_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		NavigationPathQueryParameters3D *js_proxy = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_start_position(value);
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
static JSValue navigation_path_query_parameters3d_class_set_target_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_target_position, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_target_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		NavigationPathQueryParameters3D *obj = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		NavigationPathQueryParameters3D *js_proxy = static_cast<NavigationPathQueryParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target_position(value);
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
static JSValue navigation_path_query_parameters3d_class_set_navigation_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_navigation_layers, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_navigation_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_navigation_layers, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_metadata_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_metadata_flags, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_metadata_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_metadata_flags, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_simplify_path, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_simplify_path, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_simplify_epsilon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_simplify_epsilon, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_simplify_epsilon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_simplify_epsilon, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_included_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_included_regions, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_included_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_included_regions, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_excluded_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_excluded_regions, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_excluded_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_excluded_regions, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_path_return_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_path_return_max_length, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_path_return_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_path_return_max_length, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_path_return_max_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_path_return_max_radius, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_path_return_max_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_path_return_max_radius, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_path_search_max_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_path_search_max_polygons, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_path_search_max_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_path_search_max_polygons, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_parameters3d_class_set_path_search_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryParameters3D::set_path_search_max_distance, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_parameters3d_class_get_path_search_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryParameters3D::get_path_search_max_distance, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry navigation_path_query_parameters3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_pathfinding_algorithm", 1, &navigation_path_query_parameters3d_class_set_pathfinding_algorithm),
	JS_CFUNC_DEF("get_pathfinding_algorithm", 0, &navigation_path_query_parameters3d_class_get_pathfinding_algorithm),
	JS_CFUNC_DEF("set_path_postprocessing", 1, &navigation_path_query_parameters3d_class_set_path_postprocessing),
	JS_CFUNC_DEF("get_path_postprocessing", 0, &navigation_path_query_parameters3d_class_get_path_postprocessing),
	JS_CFUNC_DEF("set_map", 1, &navigation_path_query_parameters3d_class_set_map),
	JS_CFUNC_DEF("get_map", 0, &navigation_path_query_parameters3d_class_get_map),
	JS_CFUNC_DEF("set_start_position", 1, &navigation_path_query_parameters3d_class_set_start_position),
	JS_CFUNC_DEF("get_start_position", 0, &navigation_path_query_parameters3d_class_get_start_position),
	JS_CFUNC_DEF("set_target_position", 1, &navigation_path_query_parameters3d_class_set_target_position),
	JS_CFUNC_DEF("get_target_position", 0, &navigation_path_query_parameters3d_class_get_target_position),
	JS_CFUNC_DEF("set_navigation_layers", 1, &navigation_path_query_parameters3d_class_set_navigation_layers),
	JS_CFUNC_DEF("get_navigation_layers", 0, &navigation_path_query_parameters3d_class_get_navigation_layers),
	JS_CFUNC_DEF("set_metadata_flags", 1, &navigation_path_query_parameters3d_class_set_metadata_flags),
	JS_CFUNC_DEF("get_metadata_flags", 0, &navigation_path_query_parameters3d_class_get_metadata_flags),
	JS_CFUNC_DEF("set_simplify_path", 1, &navigation_path_query_parameters3d_class_set_simplify_path),
	JS_CFUNC_DEF("get_simplify_path", 0, &navigation_path_query_parameters3d_class_get_simplify_path),
	JS_CFUNC_DEF("set_simplify_epsilon", 1, &navigation_path_query_parameters3d_class_set_simplify_epsilon),
	JS_CFUNC_DEF("get_simplify_epsilon", 0, &navigation_path_query_parameters3d_class_get_simplify_epsilon),
	JS_CFUNC_DEF("set_included_regions", 1, &navigation_path_query_parameters3d_class_set_included_regions),
	JS_CFUNC_DEF("get_included_regions", 0, &navigation_path_query_parameters3d_class_get_included_regions),
	JS_CFUNC_DEF("set_excluded_regions", 1, &navigation_path_query_parameters3d_class_set_excluded_regions),
	JS_CFUNC_DEF("get_excluded_regions", 0, &navigation_path_query_parameters3d_class_get_excluded_regions),
	JS_CFUNC_DEF("set_path_return_max_length", 1, &navigation_path_query_parameters3d_class_set_path_return_max_length),
	JS_CFUNC_DEF("get_path_return_max_length", 0, &navigation_path_query_parameters3d_class_get_path_return_max_length),
	JS_CFUNC_DEF("set_path_return_max_radius", 1, &navigation_path_query_parameters3d_class_set_path_return_max_radius),
	JS_CFUNC_DEF("get_path_return_max_radius", 0, &navigation_path_query_parameters3d_class_get_path_return_max_radius),
	JS_CFUNC_DEF("set_path_search_max_polygons", 1, &navigation_path_query_parameters3d_class_set_path_search_max_polygons),
	JS_CFUNC_DEF("get_path_search_max_polygons", 0, &navigation_path_query_parameters3d_class_get_path_search_max_polygons),
	JS_CFUNC_DEF("set_path_search_max_distance", 1, &navigation_path_query_parameters3d_class_set_path_search_max_distance),
	JS_CFUNC_DEF("get_path_search_max_distance", 0, &navigation_path_query_parameters3d_class_get_path_search_max_distance),
};




static void define_navigation_path_query_parameters3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "map"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_map, "get_map", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_map, "set_map", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "start_position"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_start_position, "get_start_position", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_start_position, "set_start_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_position"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_target_position, "get_target_position", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_target_position, "set_target_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_layers"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_navigation_layers, "get_navigation_layers", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_navigation_layers, "set_navigation_layers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pathfinding_algorithm"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_pathfinding_algorithm, "get_pathfinding_algorithm", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_pathfinding_algorithm, "set_pathfinding_algorithm", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_postprocessing"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_path_postprocessing, "get_path_postprocessing", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_path_postprocessing, "set_path_postprocessing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "metadata_flags"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_metadata_flags, "get_metadata_flags", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_metadata_flags, "set_metadata_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "simplify_path"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_simplify_path, "get_simplify_path", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_simplify_path, "set_simplify_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "simplify_epsilon"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_simplify_epsilon, "get_simplify_epsilon", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_simplify_epsilon, "set_simplify_epsilon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "excluded_regions"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_excluded_regions, "get_excluded_regions", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_excluded_regions, "set_excluded_regions", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "included_regions"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_included_regions, "get_included_regions", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_included_regions, "set_included_regions", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_return_max_length"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_path_return_max_length, "get_path_return_max_length", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_path_return_max_length, "set_path_return_max_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_return_max_radius"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_path_return_max_radius, "get_path_return_max_radius", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_path_return_max_radius, "set_path_return_max_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_search_max_polygons"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_path_search_max_polygons, "get_path_search_max_polygons", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_path_search_max_polygons, "set_path_search_max_polygons", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_search_max_distance"),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_get_path_search_max_distance, "get_path_search_max_distance", 0),
        JS_NewCFunction(ctx, navigation_path_query_parameters3d_class_set_path_search_max_distance, "set_path_search_max_distance", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_path_query_parameters3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue PathfindingAlgorithm_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PathfindingAlgorithm_obj, "PATHFINDING_ALGORITHM_ASTAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ctor, "PathfindingAlgorithm", PathfindingAlgorithm_obj);
	JSValue PathPostProcessing_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PathPostProcessing_obj, "PATH_POSTPROCESSING_CORRIDORFUNNEL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PathPostProcessing_obj, "PATH_POSTPROCESSING_EDGECENTERED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PathPostProcessing_obj, "PATH_POSTPROCESSING_NONE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PathPostProcessing", PathPostProcessing_obj);
	JSValue PathMetadataFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PathMetadataFlags_obj, "PATH_METADATA_INCLUDE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PathMetadataFlags_obj, "PATH_METADATA_INCLUDE_TYPES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PathMetadataFlags_obj, "PATH_METADATA_INCLUDE_RIDS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PathMetadataFlags_obj, "PATH_METADATA_INCLUDE_OWNERS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, PathMetadataFlags_obj, "PATH_METADATA_INCLUDE_ALL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "PathMetadataFlags", PathMetadataFlags_obj);
}

static int js_navigation_path_query_parameters3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationPathQueryParameters3D"] = class_id;
	classes_by_id[class_id] = "NavigationPathQueryParameters3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_path_query_parameters3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_path_query_parameters3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_path_query_parameters3d_class_proto_funcs, _countof(navigation_path_query_parameters3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_path_query_parameters3d_class_constructor, "NavigationPathQueryParameters3D", 0, JS_CFUNC_constructor, 0);
	define_navigation_path_query_parameters3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationPathQueryParameters3D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_path_query_parameters3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_path_query_parameters3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationPathQueryParameters3D");
	return m;
}

JSModuleDef *js_init_navigation_path_query_parameters3d_module(JSContext *ctx) {
	return _js_init_navigation_path_query_parameters3d_module(ctx, "@godot/classes/navigation_path_query_parameters3d");
}

void __register_navigation_path_query_parameters3d() {
	js_init_navigation_path_query_parameters3d_module(js_context());
}

void register_navigation_path_query_parameters3d() {
	__register_navigation_path_query_parameters3d();
}