#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/physics_point_query_parameters3d.hpp>
#include <godot_cpp/classes/physics_ray_query_parameters3d.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
using namespace godot;

static void physics_direct_space_state3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsDirectSpaceState3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_direct_space_state3d_class_def = {
    "PhysicsDirectSpaceState3D",
    physics_direct_space_state3d_class_finalizer
};

static JSValue physics_direct_space_state3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsDirectSpaceState3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(PhysicsDirectSpaceState3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_direct_space_state3d_class_intersect_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectSpaceState3D::intersect_point, ctx, this_val, argc, argv);
};
static JSValue physics_direct_space_state3d_class_intersect_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectSpaceState3D::intersect_ray, ctx, this_val, argc, argv);
};
static JSValue physics_direct_space_state3d_class_intersect_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectSpaceState3D::intersect_shape, ctx, this_val, argc, argv);
};
static JSValue physics_direct_space_state3d_class_cast_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectSpaceState3D::cast_motion, ctx, this_val, argc, argv);
};
static JSValue physics_direct_space_state3d_class_collide_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectSpaceState3D::collide_shape, ctx, this_val, argc, argv);
};
static JSValue physics_direct_space_state3d_class_get_rest_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectSpaceState3D::get_rest_info, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry physics_direct_space_state3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("intersect_point", 2, &physics_direct_space_state3d_class_intersect_point),
	JS_CFUNC_DEF("intersect_ray", 1, &physics_direct_space_state3d_class_intersect_ray),
	JS_CFUNC_DEF("intersect_shape", 2, &physics_direct_space_state3d_class_intersect_shape),
	JS_CFUNC_DEF("cast_motion", 1, &physics_direct_space_state3d_class_cast_motion),
	JS_CFUNC_DEF("collide_shape", 2, &physics_direct_space_state3d_class_collide_shape),
	JS_CFUNC_DEF("get_rest_info", 1, &physics_direct_space_state3d_class_get_rest_info),
};




static void define_physics_direct_space_state3d_property(JSContext *ctx, JSValue proto) {
}

static void define_physics_direct_space_state3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_direct_space_state3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsDirectSpaceState3D"] = class_id;
	classes_by_id[class_id] = "PhysicsDirectSpaceState3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_direct_space_state3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_direct_space_state3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_direct_space_state3d_class_proto_funcs, _countof(physics_direct_space_state3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_direct_space_state3d_class_constructor, "PhysicsDirectSpaceState3D", 0, JS_CFUNC_constructor, 0);
	define_physics_direct_space_state3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsDirectSpaceState3D", ctor);
	ctor_list["PhysicsDirectSpaceState3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_physics_direct_space_state3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_direct_space_state3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsDirectSpaceState3D");
	return m;
}

JSModuleDef *js_init_physics_direct_space_state3d_module(JSContext *ctx) {
	return _js_init_physics_direct_space_state3d_module(ctx, "@godot/classes/physics_direct_space_state3d");
}

void __register_physics_direct_space_state3d() {
	js_init_physics_direct_space_state3d_module(js_context());
}

void register_physics_direct_space_state3d() {
	__register_physics_direct_space_state3d();
}