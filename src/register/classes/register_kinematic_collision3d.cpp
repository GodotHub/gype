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
#include <godot_cpp/classes/kinematic_collision3d.hpp>
using namespace godot;

static void kinematic_collision3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["KinematicCollision3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef kinematic_collision3d_class_def = {
    "KinematicCollision3D",
    kinematic_collision3d_class_finalizer
};

static JSValue kinematic_collision3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["KinematicCollision3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    KinematicCollision3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<KinematicCollision3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(KinematicCollision3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue kinematic_collision3d_class_get_travel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_travel, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_remainder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_remainder, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_depth, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collision_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collision_count, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_position, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_normal, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_angle, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_local_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_local_shape, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collider, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collider_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collider_id, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collider_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collider_rid, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collider_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collider_shape, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collider_shape_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collider_shape_index, ctx, this_val, argc, argv);
};
static JSValue kinematic_collision3d_class_get_collider_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&KinematicCollision3D::get_collider_velocity, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry kinematic_collision3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_travel", 0, &kinematic_collision3d_class_get_travel),
	JS_CFUNC_DEF("get_remainder", 0, &kinematic_collision3d_class_get_remainder),
	JS_CFUNC_DEF("get_depth", 0, &kinematic_collision3d_class_get_depth),
	JS_CFUNC_DEF("get_collision_count", 0, &kinematic_collision3d_class_get_collision_count),
	JS_CFUNC_DEF("get_position", 1, &kinematic_collision3d_class_get_position),
	JS_CFUNC_DEF("get_normal", 1, &kinematic_collision3d_class_get_normal),
	JS_CFUNC_DEF("get_angle", 2, &kinematic_collision3d_class_get_angle),
	JS_CFUNC_DEF("get_local_shape", 1, &kinematic_collision3d_class_get_local_shape),
	JS_CFUNC_DEF("get_collider", 1, &kinematic_collision3d_class_get_collider),
	JS_CFUNC_DEF("get_collider_id", 1, &kinematic_collision3d_class_get_collider_id),
	JS_CFUNC_DEF("get_collider_rid", 1, &kinematic_collision3d_class_get_collider_rid),
	JS_CFUNC_DEF("get_collider_shape", 1, &kinematic_collision3d_class_get_collider_shape),
	JS_CFUNC_DEF("get_collider_shape_index", 1, &kinematic_collision3d_class_get_collider_shape_index),
	JS_CFUNC_DEF("get_collider_velocity", 1, &kinematic_collision3d_class_get_collider_velocity),
};




static void define_kinematic_collision3d_property(JSContext *ctx, JSValue proto) {
}

static void define_kinematic_collision3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_kinematic_collision3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["KinematicCollision3D"] = class_id;
	classes_by_id[class_id] = "KinematicCollision3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &kinematic_collision3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_kinematic_collision3d_property(ctx, proto);
	define_kinematic_collision3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, kinematic_collision3d_class_proto_funcs, _countof(kinematic_collision3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, kinematic_collision3d_class_constructor, "KinematicCollision3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "KinematicCollision3D", ctor);

	return 0;
}

JSModuleDef *_js_init_kinematic_collision3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_kinematic_collision3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "KinematicCollision3D");
	return m;
}

JSModuleDef *js_init_kinematic_collision3d_module(JSContext *ctx) {
	return _js_init_kinematic_collision3d_module(ctx, "@godot/classes/kinematic_collision3d");
}

void __register_kinematic_collision3d() {
	js_init_kinematic_collision3d_module(js_context());
}

void register_kinematic_collision3d() {
	__register_kinematic_collision3d();
}