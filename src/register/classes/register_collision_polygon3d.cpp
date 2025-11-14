#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/collision_polygon3d.hpp>
using namespace godot;

static void collision_polygon3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CollisionPolygon3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef collision_polygon3d_class_def = {
    "CollisionPolygon3D",
    collision_polygon3d_class_finalizer
};

static JSValue collision_polygon3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CollisionPolygon3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CollisionPolygon3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CollisionPolygon3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CollisionPolygon3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue collision_polygon3d_class_set_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionPolygon3D::set_depth, ctx, this_val, argc, argv);
};
static JSValue collision_polygon3d_class_get_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionPolygon3D::get_depth, ctx, this_val, argc, argv);
}
static JSValue collision_polygon3d_class_set_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionPolygon3D::set_polygon, ctx, this_val, argc, argv);
};
static JSValue collision_polygon3d_class_get_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		CollisionPolygon3D *obj = static_cast<CollisionPolygon3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_polygon();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		CollisionPolygon3D *js_proxy = static_cast<CollisionPolygon3D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue collision_polygon3d_class_set_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionPolygon3D::set_disabled, ctx, this_val, argc, argv);
};
static JSValue collision_polygon3d_class_is_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionPolygon3D::is_disabled, ctx, this_val, argc, argv);
}
static JSValue collision_polygon3d_class_set_debug_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionPolygon3D::set_debug_color, ctx, this_val, argc, argv);
};
static JSValue collision_polygon3d_class_get_debug_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CollisionPolygon3D *obj = static_cast<CollisionPolygon3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_debug_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CollisionPolygon3D *js_proxy = static_cast<CollisionPolygon3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_debug_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue collision_polygon3d_class_set_enable_debug_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionPolygon3D::set_enable_debug_fill, ctx, this_val, argc, argv);
};
static JSValue collision_polygon3d_class_get_enable_debug_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionPolygon3D::get_enable_debug_fill, ctx, this_val, argc, argv);
}
static JSValue collision_polygon3d_class_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionPolygon3D::set_margin, ctx, this_val, argc, argv);
};
static JSValue collision_polygon3d_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionPolygon3D::get_margin, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry collision_polygon3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_depth", 1, &collision_polygon3d_class_set_depth),
	JS_CFUNC_DEF("get_depth", 0, &collision_polygon3d_class_get_depth),
	JS_CFUNC_DEF("set_polygon", 1, &collision_polygon3d_class_set_polygon),
	JS_CFUNC_DEF("get_polygon", 0, &collision_polygon3d_class_get_polygon),
	JS_CFUNC_DEF("set_disabled", 1, &collision_polygon3d_class_set_disabled),
	JS_CFUNC_DEF("is_disabled", 0, &collision_polygon3d_class_is_disabled),
	JS_CFUNC_DEF("set_debug_color", 1, &collision_polygon3d_class_set_debug_color),
	JS_CFUNC_DEF("get_debug_color", 0, &collision_polygon3d_class_get_debug_color),
	JS_CFUNC_DEF("set_enable_debug_fill", 1, &collision_polygon3d_class_set_enable_debug_fill),
	JS_CFUNC_DEF("get_enable_debug_fill", 0, &collision_polygon3d_class_get_enable_debug_fill),
	JS_CFUNC_DEF("set_margin", 1, &collision_polygon3d_class_set_margin),
	JS_CFUNC_DEF("get_margin", 0, &collision_polygon3d_class_get_margin),
};




static void define_collision_polygon3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth"),
        JS_NewCFunction(ctx, collision_polygon3d_class_get_depth, "get_depth", 0),
        JS_NewCFunction(ctx, collision_polygon3d_class_set_depth, "set_depth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "disabled"),
        JS_NewCFunction(ctx, collision_polygon3d_class_is_disabled, "is_disabled", 0),
        JS_NewCFunction(ctx, collision_polygon3d_class_set_disabled, "set_disabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "polygon"),
        JS_NewCFunction(ctx, collision_polygon3d_class_get_polygon, "get_polygon", 0),
        JS_NewCFunction(ctx, collision_polygon3d_class_set_polygon, "set_polygon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margin"),
        JS_NewCFunction(ctx, collision_polygon3d_class_get_margin, "get_margin", 0),
        JS_NewCFunction(ctx, collision_polygon3d_class_set_margin, "set_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_color"),
        JS_NewCFunction(ctx, collision_polygon3d_class_get_debug_color, "get_debug_color", 0),
        JS_NewCFunction(ctx, collision_polygon3d_class_set_debug_color, "set_debug_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_fill"),
        JS_NewCFunction(ctx, collision_polygon3d_class_get_enable_debug_fill, "get_enable_debug_fill", 0),
        JS_NewCFunction(ctx, collision_polygon3d_class_set_enable_debug_fill, "set_enable_debug_fill", 1),
        JS_PROP_GETSET
    );
}

static void define_collision_polygon3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_collision_polygon3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CollisionPolygon3D"] = class_id;
	classes_by_id[class_id] = "CollisionPolygon3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &collision_polygon3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_collision_polygon3d_property(ctx, proto);
	define_collision_polygon3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, collision_polygon3d_class_proto_funcs, _countof(collision_polygon3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, collision_polygon3d_class_constructor, "CollisionPolygon3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CollisionPolygon3D", ctor);

	return 0;
}

JSModuleDef *_js_init_collision_polygon3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_collision_polygon3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CollisionPolygon3D");
	return m;
}

JSModuleDef *js_init_collision_polygon3d_module(JSContext *ctx) {
	return _js_init_collision_polygon3d_module(ctx, "@godot/classes/collision_polygon3d");
}

void __register_collision_polygon3d() {
	js_init_collision_polygon3d_module(js_context());
}

void register_collision_polygon3d() {
	__register_collision_polygon3d();
}