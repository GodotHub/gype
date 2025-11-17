#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/rigid_body3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/vehicle_body3d.hpp>
using namespace godot;

static void vehicle_body3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VehicleBody3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef vehicle_body3d_class_def = {
    "VehicleBody3D",
    vehicle_body3d_class_finalizer
};

static JSValue vehicle_body3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VehicleBody3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VehicleBody3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VehicleBody3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VehicleBody3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue vehicle_body3d_class_set_engine_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleBody3D::set_engine_force, ctx, this_val, argc, argv);
};
static JSValue vehicle_body3d_class_get_engine_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleBody3D::get_engine_force, ctx, this_val, argc, argv);
}
static JSValue vehicle_body3d_class_set_brake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleBody3D::set_brake, ctx, this_val, argc, argv);
};
static JSValue vehicle_body3d_class_get_brake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleBody3D::get_brake, ctx, this_val, argc, argv);
}
static JSValue vehicle_body3d_class_set_steering(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleBody3D::set_steering, ctx, this_val, argc, argv);
};
static JSValue vehicle_body3d_class_get_steering(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleBody3D::get_steering, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry vehicle_body3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_engine_force", 1, &vehicle_body3d_class_set_engine_force),
	JS_CFUNC_DEF("get_engine_force", 0, &vehicle_body3d_class_get_engine_force),
	JS_CFUNC_DEF("set_brake", 1, &vehicle_body3d_class_set_brake),
	JS_CFUNC_DEF("get_brake", 0, &vehicle_body3d_class_get_brake),
	JS_CFUNC_DEF("set_steering", 1, &vehicle_body3d_class_set_steering),
	JS_CFUNC_DEF("get_steering", 0, &vehicle_body3d_class_get_steering),
};




static void define_vehicle_body3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "engine_force"),
        JS_NewCFunction(ctx, vehicle_body3d_class_get_engine_force, "get_engine_force", 0),
        JS_NewCFunction(ctx, vehicle_body3d_class_set_engine_force, "set_engine_force", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "brake"),
        JS_NewCFunction(ctx, vehicle_body3d_class_get_brake, "get_brake", 0),
        JS_NewCFunction(ctx, vehicle_body3d_class_set_brake, "set_brake", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "steering"),
        JS_NewCFunction(ctx, vehicle_body3d_class_get_steering, "get_steering", 0),
        JS_NewCFunction(ctx, vehicle_body3d_class_set_steering, "set_steering", 1),
        JS_PROP_GETSET
    );
}

static void define_vehicle_body3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_vehicle_body3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VehicleBody3D"] = class_id;
	classes_by_id[class_id] = "VehicleBody3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &vehicle_body3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RigidBody3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_vehicle_body3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vehicle_body3d_class_proto_funcs, _countof(vehicle_body3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vehicle_body3d_class_constructor, "VehicleBody3D", 0, JS_CFUNC_constructor, 0);
	define_vehicle_body3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VehicleBody3D", ctor);

	return 0;
}

JSModuleDef *_js_init_vehicle_body3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/rigid_body3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_vehicle_body3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VehicleBody3D");
	return m;
}

JSModuleDef *js_init_vehicle_body3d_module(JSContext *ctx) {
	return _js_init_vehicle_body3d_module(ctx, "@godot/classes/vehicle_body3d");
}

void __register_vehicle_body3d() {
	js_init_vehicle_body3d_module(js_context());
}

void register_vehicle_body3d() {
	__register_vehicle_body3d();
}