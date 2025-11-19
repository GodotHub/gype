#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/navigation_mesh.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_region3d.hpp>
using namespace godot;

static void navigation_region3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationRegion3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_region3d_class_def = {
    "NavigationRegion3D",
    navigation_region3d_class_finalizer
};

static JSValue navigation_region3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationRegion3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationRegion3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationRegion3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationRegion3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_region3d_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_rid, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_set_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_navigation_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_navigation_mesh, ctx, this_val, argc, argv);
}
static JSValue navigation_region3d_class_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_enabled, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::is_enabled, ctx, this_val, argc, argv);
}
static JSValue navigation_region3d_class_set_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_navigation_map, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_navigation_map, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_set_use_edge_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_use_edge_connections, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_use_edge_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_use_edge_connections, ctx, this_val, argc, argv);
}
static JSValue navigation_region3d_class_set_navigation_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_navigation_layers, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_navigation_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_navigation_layers, ctx, this_val, argc, argv);
}
static JSValue navigation_region3d_class_set_navigation_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_navigation_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_navigation_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_navigation_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_region_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_region_rid, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_set_enter_cost(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_enter_cost, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_enter_cost(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_enter_cost, ctx, this_val, argc, argv);
}
static JSValue navigation_region3d_class_set_travel_cost(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::set_travel_cost, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_travel_cost(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_travel_cost, ctx, this_val, argc, argv);
}
static JSValue navigation_region3d_class_bake_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationRegion3D::bake_navigation_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_is_baking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::is_baking, ctx, this_val, argc, argv);
};
static JSValue navigation_region3d_class_get_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationRegion3D::get_bounds, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry navigation_region3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_rid", 0, &navigation_region3d_class_get_rid),
	JS_CFUNC_DEF("set_navigation_mesh", 1, &navigation_region3d_class_set_navigation_mesh),
	JS_CFUNC_DEF("get_navigation_mesh", 0, &navigation_region3d_class_get_navigation_mesh),
	JS_CFUNC_DEF("set_enabled", 1, &navigation_region3d_class_set_enabled),
	JS_CFUNC_DEF("is_enabled", 0, &navigation_region3d_class_is_enabled),
	JS_CFUNC_DEF("set_navigation_map", 1, &navigation_region3d_class_set_navigation_map),
	JS_CFUNC_DEF("get_navigation_map", 0, &navigation_region3d_class_get_navigation_map),
	JS_CFUNC_DEF("set_use_edge_connections", 1, &navigation_region3d_class_set_use_edge_connections),
	JS_CFUNC_DEF("get_use_edge_connections", 0, &navigation_region3d_class_get_use_edge_connections),
	JS_CFUNC_DEF("set_navigation_layers", 1, &navigation_region3d_class_set_navigation_layers),
	JS_CFUNC_DEF("get_navigation_layers", 0, &navigation_region3d_class_get_navigation_layers),
	JS_CFUNC_DEF("set_navigation_layer_value", 2, &navigation_region3d_class_set_navigation_layer_value),
	JS_CFUNC_DEF("get_navigation_layer_value", 1, &navigation_region3d_class_get_navigation_layer_value),
	JS_CFUNC_DEF("get_region_rid", 0, &navigation_region3d_class_get_region_rid),
	JS_CFUNC_DEF("set_enter_cost", 1, &navigation_region3d_class_set_enter_cost),
	JS_CFUNC_DEF("get_enter_cost", 0, &navigation_region3d_class_get_enter_cost),
	JS_CFUNC_DEF("set_travel_cost", 1, &navigation_region3d_class_set_travel_cost),
	JS_CFUNC_DEF("get_travel_cost", 0, &navigation_region3d_class_get_travel_cost),
	JS_CFUNC_DEF("bake_navigation_mesh", 1, &navigation_region3d_class_bake_navigation_mesh),
	JS_CFUNC_DEF("is_baking", 0, &navigation_region3d_class_is_baking),
	JS_CFUNC_DEF("get_bounds", 0, &navigation_region3d_class_get_bounds),
};


static JSValue navigation_region3d_class_get_navigation_mesh_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationRegion3D *opaque = static_cast<NavigationRegion3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "navigation_mesh_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "navigation_mesh_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "navigation_mesh_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue navigation_region3d_class_get_bake_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	NavigationRegion3D *opaque = static_cast<NavigationRegion3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "bake_finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "bake_finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "bake_finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_navigation_region3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_mesh"),
        JS_NewCFunction(ctx, navigation_region3d_class_get_navigation_mesh, "get_navigation_mesh", 0),
        JS_NewCFunction(ctx, navigation_region3d_class_set_navigation_mesh, "set_navigation_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled"),
        JS_NewCFunction(ctx, navigation_region3d_class_is_enabled, "is_enabled", 0),
        JS_NewCFunction(ctx, navigation_region3d_class_set_enabled, "set_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_edge_connections"),
        JS_NewCFunction(ctx, navigation_region3d_class_get_use_edge_connections, "get_use_edge_connections", 0),
        JS_NewCFunction(ctx, navigation_region3d_class_set_use_edge_connections, "set_use_edge_connections", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_layers"),
        JS_NewCFunction(ctx, navigation_region3d_class_get_navigation_layers, "get_navigation_layers", 0),
        JS_NewCFunction(ctx, navigation_region3d_class_set_navigation_layers, "set_navigation_layers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enter_cost"),
        JS_NewCFunction(ctx, navigation_region3d_class_get_enter_cost, "get_enter_cost", 0),
        JS_NewCFunction(ctx, navigation_region3d_class_set_enter_cost, "set_enter_cost", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "travel_cost"),
        JS_NewCFunction(ctx, navigation_region3d_class_get_travel_cost, "get_travel_cost", 0),
        JS_NewCFunction(ctx, navigation_region3d_class_set_travel_cost, "set_travel_cost", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "navigation_mesh_changed"),
		JS_NewCFunction(ctx, navigation_region3d_class_get_navigation_mesh_changed_signal, "get_navigation_mesh_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "bake_finished"),
		JS_NewCFunction(ctx, navigation_region3d_class_get_bake_finished_signal, "get_bake_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_navigation_region3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_navigation_region3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationRegion3D"] = class_id;
	classes_by_id[class_id] = "NavigationRegion3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_region3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_region3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_region3d_class_proto_funcs, _countof(navigation_region3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_region3d_class_constructor, "NavigationRegion3D", 0, JS_CFUNC_constructor, 0);
	define_navigation_region3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationRegion3D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_region3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_region3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationRegion3D");
	return m;
}

JSModuleDef *js_init_navigation_region3d_module(JSContext *ctx) {
	return _js_init_navigation_region3d_module(ctx, "@godot/classes/navigation_region3d");
}

void __register_navigation_region3d() {
	js_init_navigation_region3d_module(js_context());
}

void register_navigation_region3d() {
	__register_navigation_region3d();
}