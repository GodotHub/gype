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
#include <godot_cpp/classes/physics_test_motion_parameters3d.hpp>
using namespace godot;

static void physics_test_motion_parameters3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsTestMotionParameters3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_test_motion_parameters3d_class_def = {
    "PhysicsTestMotionParameters3D",
    physics_test_motion_parameters3d_class_finalizer
};

static JSValue physics_test_motion_parameters3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsTestMotionParameters3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicsTestMotionParameters3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicsTestMotionParameters3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicsTestMotionParameters3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_test_motion_parameters3d_class_get_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		PhysicsTestMotionParameters3D *obj = static_cast<PhysicsTestMotionParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_from();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		PhysicsTestMotionParameters3D *js_proxy = static_cast<PhysicsTestMotionParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_from(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform3DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform3DProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue physics_test_motion_parameters3d_class_set_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_from, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_get_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		PhysicsTestMotionParameters3D *obj = static_cast<PhysicsTestMotionParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_motion();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		PhysicsTestMotionParameters3D *js_proxy = static_cast<PhysicsTestMotionParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_motion(value);
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
static JSValue physics_test_motion_parameters3d_class_set_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_motion, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionParameters3D::get_margin, ctx, this_val, argc, argv);
}
static JSValue physics_test_motion_parameters3d_class_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_margin, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_get_max_collisions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionParameters3D::get_max_collisions, ctx, this_val, argc, argv);
}
static JSValue physics_test_motion_parameters3d_class_set_max_collisions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_max_collisions, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_is_collide_separation_ray_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionParameters3D::is_collide_separation_ray_enabled, ctx, this_val, argc, argv);
}
static JSValue physics_test_motion_parameters3d_class_set_collide_separation_ray_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_collide_separation_ray_enabled, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_get_exclude_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionParameters3D::get_exclude_bodies, ctx, this_val, argc, argv);
}
static JSValue physics_test_motion_parameters3d_class_set_exclude_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_exclude_bodies, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_get_exclude_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionParameters3D::get_exclude_objects, ctx, this_val, argc, argv);
}
static JSValue physics_test_motion_parameters3d_class_set_exclude_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_exclude_objects, ctx, this_val, argc, argv);
};
static JSValue physics_test_motion_parameters3d_class_is_recovery_as_collision_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsTestMotionParameters3D::is_recovery_as_collision_enabled, ctx, this_val, argc, argv);
}
static JSValue physics_test_motion_parameters3d_class_set_recovery_as_collision_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsTestMotionParameters3D::set_recovery_as_collision_enabled, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry physics_test_motion_parameters3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_from", 0, &physics_test_motion_parameters3d_class_get_from),
	JS_CFUNC_DEF("set_from", 1, &physics_test_motion_parameters3d_class_set_from),
	JS_CFUNC_DEF("get_motion", 0, &physics_test_motion_parameters3d_class_get_motion),
	JS_CFUNC_DEF("set_motion", 1, &physics_test_motion_parameters3d_class_set_motion),
	JS_CFUNC_DEF("get_margin", 0, &physics_test_motion_parameters3d_class_get_margin),
	JS_CFUNC_DEF("set_margin", 1, &physics_test_motion_parameters3d_class_set_margin),
	JS_CFUNC_DEF("get_max_collisions", 0, &physics_test_motion_parameters3d_class_get_max_collisions),
	JS_CFUNC_DEF("set_max_collisions", 1, &physics_test_motion_parameters3d_class_set_max_collisions),
	JS_CFUNC_DEF("is_collide_separation_ray_enabled", 0, &physics_test_motion_parameters3d_class_is_collide_separation_ray_enabled),
	JS_CFUNC_DEF("set_collide_separation_ray_enabled", 1, &physics_test_motion_parameters3d_class_set_collide_separation_ray_enabled),
	JS_CFUNC_DEF("get_exclude_bodies", 0, &physics_test_motion_parameters3d_class_get_exclude_bodies),
	JS_CFUNC_DEF("set_exclude_bodies", 1, &physics_test_motion_parameters3d_class_set_exclude_bodies),
	JS_CFUNC_DEF("get_exclude_objects", 0, &physics_test_motion_parameters3d_class_get_exclude_objects),
	JS_CFUNC_DEF("set_exclude_objects", 1, &physics_test_motion_parameters3d_class_set_exclude_objects),
	JS_CFUNC_DEF("is_recovery_as_collision_enabled", 0, &physics_test_motion_parameters3d_class_is_recovery_as_collision_enabled),
	JS_CFUNC_DEF("set_recovery_as_collision_enabled", 1, &physics_test_motion_parameters3d_class_set_recovery_as_collision_enabled),
};




static void define_physics_test_motion_parameters3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "from"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_get_from, "get_from", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_from, "set_from", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_get_motion, "get_motion", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_motion, "set_motion", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margin"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_get_margin, "get_margin", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_margin, "set_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_collisions"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_get_max_collisions, "get_max_collisions", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_max_collisions, "set_max_collisions", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_separation_ray"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_is_collide_separation_ray_enabled, "is_collide_separation_ray_enabled", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_collide_separation_ray_enabled, "set_collide_separation_ray_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude_bodies"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_get_exclude_bodies, "get_exclude_bodies", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_exclude_bodies, "set_exclude_bodies", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude_objects"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_get_exclude_objects, "get_exclude_objects", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_exclude_objects, "set_exclude_objects", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "recovery_as_collision"),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_is_recovery_as_collision_enabled, "is_recovery_as_collision_enabled", 0),
        JS_NewCFunction(ctx, physics_test_motion_parameters3d_class_set_recovery_as_collision_enabled, "set_recovery_as_collision_enabled", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_test_motion_parameters3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_test_motion_parameters3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsTestMotionParameters3D"] = class_id;
	classes_by_id[class_id] = "PhysicsTestMotionParameters3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_test_motion_parameters3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_test_motion_parameters3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_test_motion_parameters3d_class_proto_funcs, _countof(physics_test_motion_parameters3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_test_motion_parameters3d_class_constructor, "PhysicsTestMotionParameters3D", 0, JS_CFUNC_constructor, 0);
	define_physics_test_motion_parameters3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsTestMotionParameters3D", ctor);

	return 0;
}

JSModuleDef *_js_init_physics_test_motion_parameters3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_test_motion_parameters3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsTestMotionParameters3D");
	return m;
}

JSModuleDef *js_init_physics_test_motion_parameters3d_module(JSContext *ctx) {
	return _js_init_physics_test_motion_parameters3d_module(ctx, "@godot/classes/physics_test_motion_parameters3d");
}

void __register_physics_test_motion_parameters3d() {
	js_init_physics_test_motion_parameters3d_module(js_context());
}

void register_physics_test_motion_parameters3d() {
	__register_physics_test_motion_parameters3d();
}