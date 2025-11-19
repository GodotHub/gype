#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_test_motion_result2d.hpp>
using namespace godot;

static void physics_test_motion_result2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsTestMotionResult2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_test_motion_result2d_class_def = {
    "PhysicsTestMotionResult2D",
    physics_test_motion_result2d_class_finalizer
};

static JSValue physics_test_motion_result2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsTestMotionResult2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicsTestMotionResult2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicsTestMotionResult2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicsTestMotionResult2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_test_motion_result2d_class_get_travel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_travel, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_remainder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_remainder, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collision_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collision_point, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collision_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collision_normal, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collider_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collider_velocity, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collider_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collider_id, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collider_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collider_rid, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collider, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collider_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collider_shape, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collision_local_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collision_local_shape, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collision_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collision_depth, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collision_safe_fraction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collision_safe_fraction, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_result2d_class_get_collision_unsafe_fraction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionResult2D::get_collision_unsafe_fraction, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry physics_test_motion_result2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_travel", 0, &physics_test_motion_result2d_class_get_travel),
	JS_CFUNC_DEF("get_remainder", 0, &physics_test_motion_result2d_class_get_remainder),
	JS_CFUNC_DEF("get_collision_point", 0, &physics_test_motion_result2d_class_get_collision_point),
	JS_CFUNC_DEF("get_collision_normal", 0, &physics_test_motion_result2d_class_get_collision_normal),
	JS_CFUNC_DEF("get_collider_velocity", 0, &physics_test_motion_result2d_class_get_collider_velocity),
	JS_CFUNC_DEF("get_collider_id", 0, &physics_test_motion_result2d_class_get_collider_id),
	JS_CFUNC_DEF("get_collider_rid", 0, &physics_test_motion_result2d_class_get_collider_rid),
	JS_CFUNC_DEF("get_collider", 0, &physics_test_motion_result2d_class_get_collider),
	JS_CFUNC_DEF("get_collider_shape", 0, &physics_test_motion_result2d_class_get_collider_shape),
	JS_CFUNC_DEF("get_collision_local_shape", 0, &physics_test_motion_result2d_class_get_collision_local_shape),
	JS_CFUNC_DEF("get_collision_depth", 0, &physics_test_motion_result2d_class_get_collision_depth),
	JS_CFUNC_DEF("get_collision_safe_fraction", 0, &physics_test_motion_result2d_class_get_collision_safe_fraction),
	JS_CFUNC_DEF("get_collision_unsafe_fraction", 0, &physics_test_motion_result2d_class_get_collision_unsafe_fraction),
};




static void define_physics_test_motion_result2d_property(JSContext *ctx, JSValue proto) {
}

static void define_physics_test_motion_result2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_test_motion_result2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsTestMotionResult2D"] = class_id;
	classes_by_id[class_id] = "PhysicsTestMotionResult2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_test_motion_result2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_test_motion_result2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_test_motion_result2d_class_proto_funcs, _countof(physics_test_motion_result2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_test_motion_result2d_class_constructor, "PhysicsTestMotionResult2D", 0, JS_CFUNC_constructor, 0);
	define_physics_test_motion_result2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsTestMotionResult2D", ctor);

	return 0;
}

JSModuleDef *_js_init_physics_test_motion_result2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_test_motion_result2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsTestMotionResult2D");
	return m;
}

JSModuleDef *js_init_physics_test_motion_result2d_module(JSContext *ctx) {
	return _js_init_physics_test_motion_result2d_module(ctx, "@godot/classes/physics_test_motion_result2d");
}

void __register_physics_test_motion_result2d() {
	js_init_physics_test_motion_result2d_module(js_context());
}

void register_physics_test_motion_result2d() {
	__register_physics_test_motion_result2d();
}