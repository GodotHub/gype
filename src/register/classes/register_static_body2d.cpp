#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/physics_body2d.hpp>
#include <godot_cpp/classes/physics_material.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/static_body2d.hpp>
using namespace godot;

static void static_body2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StaticBody2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef static_body2d_class_def = {
    "StaticBody2D",
    static_body2d_class_finalizer
};

static JSValue static_body2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StaticBody2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    StaticBody2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<StaticBody2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(StaticBody2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue static_body2d_class_set_constant_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StaticBody2D::set_constant_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue static_body2d_class_set_constant_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StaticBody2D::set_constant_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue static_body2d_class_get_constant_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		StaticBody2D *obj = static_cast<StaticBody2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_constant_linear_velocity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		StaticBody2D *js_proxy = static_cast<StaticBody2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_constant_linear_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue static_body2d_class_get_constant_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StaticBody2D::get_constant_angular_velocity, ctx, this_val, argc, argv);
}
static JSValue static_body2d_class_set_physics_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StaticBody2D::set_physics_material_override, ctx, this_val, argc, argv);
};
static JSValue static_body2d_class_get_physics_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StaticBody2D::get_physics_material_override, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry static_body2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_constant_linear_velocity", 1, &static_body2d_class_set_constant_linear_velocity),
	JS_CFUNC_DEF("set_constant_angular_velocity", 1, &static_body2d_class_set_constant_angular_velocity),
	JS_CFUNC_DEF("get_constant_linear_velocity", 0, &static_body2d_class_get_constant_linear_velocity),
	JS_CFUNC_DEF("get_constant_angular_velocity", 0, &static_body2d_class_get_constant_angular_velocity),
	JS_CFUNC_DEF("set_physics_material_override", 1, &static_body2d_class_set_physics_material_override),
	JS_CFUNC_DEF("get_physics_material_override", 0, &static_body2d_class_get_physics_material_override),
};




static void define_static_body2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "physics_material_override"),
        JS_NewCFunction(ctx, static_body2d_class_get_physics_material_override, "get_physics_material_override", 0),
        JS_NewCFunction(ctx, static_body2d_class_set_physics_material_override, "set_physics_material_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "constant_linear_velocity"),
        JS_NewCFunction(ctx, static_body2d_class_get_constant_linear_velocity, "get_constant_linear_velocity", 0),
        JS_NewCFunction(ctx, static_body2d_class_set_constant_linear_velocity, "set_constant_linear_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "constant_angular_velocity"),
        JS_NewCFunction(ctx, static_body2d_class_get_constant_angular_velocity, "get_constant_angular_velocity", 0),
        JS_NewCFunction(ctx, static_body2d_class_set_constant_angular_velocity, "set_constant_angular_velocity", 1),
        JS_PROP_GETSET
    );
}

static void define_static_body2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_static_body2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StaticBody2D"] = class_id;
	classes_by_id[class_id] = "StaticBody2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &static_body2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PhysicsBody2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_static_body2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, static_body2d_class_proto_funcs, _countof(static_body2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, static_body2d_class_constructor, "StaticBody2D", 0, JS_CFUNC_constructor, 0);
	define_static_body2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StaticBody2D", ctor);

	return 0;
}

JSModuleDef *_js_init_static_body2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/physics_body2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_static_body2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StaticBody2D");
	return m;
}

JSModuleDef *js_init_static_body2d_module(JSContext *ctx) {
	return _js_init_static_body2d_module(ctx, "@godot/classes/static_body2d");
}

void __register_static_body2d() {
	js_init_static_body2d_module(js_context());
}

void register_static_body2d() {
	__register_static_body2d();
}