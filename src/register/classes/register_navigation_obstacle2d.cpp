#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_obstacle2d.hpp>
using namespace godot;

static void navigation_obstacle2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationObstacle2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_obstacle2d_class_def = {
    "NavigationObstacle2D",
    navigation_obstacle2d_class_finalizer
};

static JSValue navigation_obstacle2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationObstacle2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationObstacle2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationObstacle2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationObstacle2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_obstacle2d_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_rid, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_set_avoidance_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_avoidance_enabled, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_avoidance_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_avoidance_enabled, ctx, this_val, argc, argv);
}
static JSValue navigation_obstacle2d_class_set_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_navigation_map, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_navigation_map, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_radius, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_radius, ctx, this_val, argc, argv);
}
static JSValue navigation_obstacle2d_class_set_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_velocity, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		NavigationObstacle2D *obj = static_cast<NavigationObstacle2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_velocity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		NavigationObstacle2D *js_proxy = static_cast<NavigationObstacle2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_velocity(value);
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
static JSValue navigation_obstacle2d_class_set_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_vertices, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		NavigationObstacle2D *obj = static_cast<NavigationObstacle2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_vertices();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		NavigationObstacle2D *js_proxy = static_cast<NavigationObstacle2D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue navigation_obstacle2d_class_set_avoidance_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_avoidance_layers, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_avoidance_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_avoidance_layers, ctx, this_val, argc, argv);
}
static JSValue navigation_obstacle2d_class_set_avoidance_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_avoidance_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_avoidance_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_avoidance_layer_value, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_set_affect_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_affect_navigation_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_affect_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_affect_navigation_mesh, ctx, this_val, argc, argv);
}
static JSValue navigation_obstacle2d_class_set_carve_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationObstacle2D::set_carve_navigation_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_obstacle2d_class_get_carve_navigation_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationObstacle2D::get_carve_navigation_mesh, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry navigation_obstacle2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_rid", 0, &navigation_obstacle2d_class_get_rid),
	JS_CFUNC_DEF("set_avoidance_enabled", 1, &navigation_obstacle2d_class_set_avoidance_enabled),
	JS_CFUNC_DEF("get_avoidance_enabled", 0, &navigation_obstacle2d_class_get_avoidance_enabled),
	JS_CFUNC_DEF("set_navigation_map", 1, &navigation_obstacle2d_class_set_navigation_map),
	JS_CFUNC_DEF("get_navigation_map", 0, &navigation_obstacle2d_class_get_navigation_map),
	JS_CFUNC_DEF("set_radius", 1, &navigation_obstacle2d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &navigation_obstacle2d_class_get_radius),
	JS_CFUNC_DEF("set_velocity", 1, &navigation_obstacle2d_class_set_velocity),
	JS_CFUNC_DEF("get_velocity", 0, &navigation_obstacle2d_class_get_velocity),
	JS_CFUNC_DEF("set_vertices", 1, &navigation_obstacle2d_class_set_vertices),
	JS_CFUNC_DEF("get_vertices", 0, &navigation_obstacle2d_class_get_vertices),
	JS_CFUNC_DEF("set_avoidance_layers", 1, &navigation_obstacle2d_class_set_avoidance_layers),
	JS_CFUNC_DEF("get_avoidance_layers", 0, &navigation_obstacle2d_class_get_avoidance_layers),
	JS_CFUNC_DEF("set_avoidance_layer_value", 2, &navigation_obstacle2d_class_set_avoidance_layer_value),
	JS_CFUNC_DEF("get_avoidance_layer_value", 1, &navigation_obstacle2d_class_get_avoidance_layer_value),
	JS_CFUNC_DEF("set_affect_navigation_mesh", 1, &navigation_obstacle2d_class_set_affect_navigation_mesh),
	JS_CFUNC_DEF("get_affect_navigation_mesh", 0, &navigation_obstacle2d_class_get_affect_navigation_mesh),
	JS_CFUNC_DEF("set_carve_navigation_mesh", 1, &navigation_obstacle2d_class_set_carve_navigation_mesh),
	JS_CFUNC_DEF("get_carve_navigation_mesh", 0, &navigation_obstacle2d_class_get_carve_navigation_mesh),
};




static void define_navigation_obstacle2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertices"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_vertices, "get_vertices", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_vertices, "set_vertices", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "affect_navigation_mesh"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_affect_navigation_mesh, "get_affect_navigation_mesh", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_affect_navigation_mesh, "set_affect_navigation_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "carve_navigation_mesh"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_carve_navigation_mesh, "get_carve_navigation_mesh", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_carve_navigation_mesh, "set_carve_navigation_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "avoidance_enabled"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_avoidance_enabled, "get_avoidance_enabled", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_avoidance_enabled, "set_avoidance_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "velocity"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_velocity, "get_velocity", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_velocity, "set_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "avoidance_layers"),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_get_avoidance_layers, "get_avoidance_layers", 0),
        JS_NewCFunction(ctx, navigation_obstacle2d_class_set_avoidance_layers, "set_avoidance_layers", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_obstacle2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_navigation_obstacle2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationObstacle2D"] = class_id;
	classes_by_id[class_id] = "NavigationObstacle2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_obstacle2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_obstacle2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_obstacle2d_class_proto_funcs, _countof(navigation_obstacle2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_obstacle2d_class_constructor, "NavigationObstacle2D", 0, JS_CFUNC_constructor, 0);
	define_navigation_obstacle2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationObstacle2D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_obstacle2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_obstacle2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationObstacle2D");
	return m;
}

JSModuleDef *js_init_navigation_obstacle2d_module(JSContext *ctx) {
	return _js_init_navigation_obstacle2d_module(ctx, "@godot/classes/navigation_obstacle2d");
}

void __register_navigation_obstacle2d() {
	js_init_navigation_obstacle2d_module(js_context());
}

void register_navigation_obstacle2d() {
	__register_navigation_obstacle2d();
}