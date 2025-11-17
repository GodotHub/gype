#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/collision_object3d.hpp>
#include <godot_cpp/classes/kinematic_collision3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_body3d.hpp>
using namespace godot;

static void physics_body3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsBody3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_body3d_class_def = {
    "PhysicsBody3D",
    physics_body3d_class_finalizer
};

static JSValue physics_body3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsBody3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicsBody3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicsBody3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicsBody3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_body3d_class_move_and_collide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsBody3D::move_and_collide, ctx, this_val, argc, argv);
};
static JSValue physics_body3d_class_test_move(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsBody3D::test_move, ctx, this_val, argc, argv);
};
static JSValue physics_body3d_class_get_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsBody3D::get_gravity, ctx, this_val, argc, argv);
};
static JSValue physics_body3d_class_set_axis_lock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsBody3D::set_axis_lock, ctx, this_val, argc, argv);
};
static JSValue physics_body3d_class_get_axis_lock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsBody3D::get_axis_lock, ctx, this_val, argc, argv);
}
static JSValue physics_body3d_class_get_collision_exceptions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsBody3D::get_collision_exceptions, ctx, this_val, argc, argv);
};
static JSValue physics_body3d_class_add_collision_exception_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsBody3D::add_collision_exception_with, ctx, this_val, argc, argv);
};
static JSValue physics_body3d_class_remove_collision_exception_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsBody3D::remove_collision_exception_with, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry physics_body3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("move_and_collide", 5, &physics_body3d_class_move_and_collide),
	JS_CFUNC_DEF("test_move", 6, &physics_body3d_class_test_move),
	JS_CFUNC_DEF("get_gravity", 0, &physics_body3d_class_get_gravity),
	JS_CFUNC_DEF("set_axis_lock", 2, &physics_body3d_class_set_axis_lock),
	JS_CFUNC_DEF("get_axis_lock", 1, &physics_body3d_class_get_axis_lock),
	JS_CFUNC_DEF("get_collision_exceptions", 0, &physics_body3d_class_get_collision_exceptions),
	JS_CFUNC_DEF("add_collision_exception_with", 1, &physics_body3d_class_add_collision_exception_with),
	JS_CFUNC_DEF("remove_collision_exception_with", 1, &physics_body3d_class_remove_collision_exception_with),
};




static void define_physics_body3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_lock_linear_x"),
        JS_NewCFunction(ctx, physics_body3d_class_get_axis_lock, "get_axis_lock", 0),
        JS_NewCFunction(ctx, physics_body3d_class_set_axis_lock, "set_axis_lock", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_lock_linear_y"),
        JS_NewCFunction(ctx, physics_body3d_class_get_axis_lock, "get_axis_lock", 0),
        JS_NewCFunction(ctx, physics_body3d_class_set_axis_lock, "set_axis_lock", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_lock_linear_z"),
        JS_NewCFunction(ctx, physics_body3d_class_get_axis_lock, "get_axis_lock", 0),
        JS_NewCFunction(ctx, physics_body3d_class_set_axis_lock, "set_axis_lock", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_lock_angular_x"),
        JS_NewCFunction(ctx, physics_body3d_class_get_axis_lock, "get_axis_lock", 0),
        JS_NewCFunction(ctx, physics_body3d_class_set_axis_lock, "set_axis_lock", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_lock_angular_y"),
        JS_NewCFunction(ctx, physics_body3d_class_get_axis_lock, "get_axis_lock", 0),
        JS_NewCFunction(ctx, physics_body3d_class_set_axis_lock, "set_axis_lock", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_lock_angular_z"),
        JS_NewCFunction(ctx, physics_body3d_class_get_axis_lock, "get_axis_lock", 0),
        JS_NewCFunction(ctx, physics_body3d_class_set_axis_lock, "set_axis_lock", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_body3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_body3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsBody3D"] = class_id;
	classes_by_id[class_id] = "PhysicsBody3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_body3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CollisionObject3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_body3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_body3d_class_proto_funcs, _countof(physics_body3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_body3d_class_constructor, "PhysicsBody3D", 0, JS_CFUNC_constructor, 0);
	define_physics_body3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsBody3D", ctor);

	return 0;
}

JSModuleDef *_js_init_physics_body3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/collision_object3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_body3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsBody3D");
	return m;
}

JSModuleDef *js_init_physics_body3d_module(JSContext *ctx) {
	return _js_init_physics_body3d_module(ctx, "@godot/classes/physics_body3d");
}

void __register_physics_body3d() {
	js_init_physics_body3d_module(js_context());
}

void register_physics_body3d() {
	__register_physics_body3d();
}