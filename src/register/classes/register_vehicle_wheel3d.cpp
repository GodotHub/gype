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
#include <godot_cpp/classes/vehicle_wheel3d.hpp>
using namespace godot;

static void vehicle_wheel3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VehicleWheel3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef vehicle_wheel3d_class_def = {
    "VehicleWheel3D",
    vehicle_wheel3d_class_finalizer
};

static JSValue vehicle_wheel3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VehicleWheel3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VehicleWheel3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VehicleWheel3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VehicleWheel3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue vehicle_wheel3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_radius, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_suspension_rest_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_suspension_rest_length, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_suspension_rest_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_suspension_rest_length, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_suspension_travel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_suspension_travel, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_suspension_travel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_suspension_travel, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_suspension_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_suspension_stiffness, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_suspension_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_suspension_stiffness, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_suspension_max_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_suspension_max_force, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_suspension_max_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_suspension_max_force, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_damping_compression(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_damping_compression, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_damping_compression(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_damping_compression, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_damping_relaxation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_damping_relaxation, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_damping_relaxation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_damping_relaxation, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_use_as_traction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_use_as_traction, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_is_used_as_traction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::is_used_as_traction, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_use_as_steering(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_use_as_steering, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_is_used_as_steering(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::is_used_as_steering, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_friction_slip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_friction_slip, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_friction_slip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_friction_slip, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_is_in_contact(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::is_in_contact, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_contact_body(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_contact_body, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_contact_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_contact_point, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_contact_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_contact_normal, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_set_roll_influence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_roll_influence, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_roll_influence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_roll_influence, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_get_skidinfo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_skidinfo, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_rpm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_rpm, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_set_engine_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_engine_force, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_engine_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_engine_force, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_brake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_brake, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_brake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_brake, ctx, this_val, argc, argv);
}
static JSValue vehicle_wheel3d_class_set_steering(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VehicleWheel3D::set_steering, ctx, this_val, argc, argv);
};
static JSValue vehicle_wheel3d_class_get_steering(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VehicleWheel3D::get_steering, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry vehicle_wheel3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &vehicle_wheel3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &vehicle_wheel3d_class_get_radius),
	JS_CFUNC_DEF("set_suspension_rest_length", 1, &vehicle_wheel3d_class_set_suspension_rest_length),
	JS_CFUNC_DEF("get_suspension_rest_length", 0, &vehicle_wheel3d_class_get_suspension_rest_length),
	JS_CFUNC_DEF("set_suspension_travel", 1, &vehicle_wheel3d_class_set_suspension_travel),
	JS_CFUNC_DEF("get_suspension_travel", 0, &vehicle_wheel3d_class_get_suspension_travel),
	JS_CFUNC_DEF("set_suspension_stiffness", 1, &vehicle_wheel3d_class_set_suspension_stiffness),
	JS_CFUNC_DEF("get_suspension_stiffness", 0, &vehicle_wheel3d_class_get_suspension_stiffness),
	JS_CFUNC_DEF("set_suspension_max_force", 1, &vehicle_wheel3d_class_set_suspension_max_force),
	JS_CFUNC_DEF("get_suspension_max_force", 0, &vehicle_wheel3d_class_get_suspension_max_force),
	JS_CFUNC_DEF("set_damping_compression", 1, &vehicle_wheel3d_class_set_damping_compression),
	JS_CFUNC_DEF("get_damping_compression", 0, &vehicle_wheel3d_class_get_damping_compression),
	JS_CFUNC_DEF("set_damping_relaxation", 1, &vehicle_wheel3d_class_set_damping_relaxation),
	JS_CFUNC_DEF("get_damping_relaxation", 0, &vehicle_wheel3d_class_get_damping_relaxation),
	JS_CFUNC_DEF("set_use_as_traction", 1, &vehicle_wheel3d_class_set_use_as_traction),
	JS_CFUNC_DEF("is_used_as_traction", 0, &vehicle_wheel3d_class_is_used_as_traction),
	JS_CFUNC_DEF("set_use_as_steering", 1, &vehicle_wheel3d_class_set_use_as_steering),
	JS_CFUNC_DEF("is_used_as_steering", 0, &vehicle_wheel3d_class_is_used_as_steering),
	JS_CFUNC_DEF("set_friction_slip", 1, &vehicle_wheel3d_class_set_friction_slip),
	JS_CFUNC_DEF("get_friction_slip", 0, &vehicle_wheel3d_class_get_friction_slip),
	JS_CFUNC_DEF("is_in_contact", 0, &vehicle_wheel3d_class_is_in_contact),
	JS_CFUNC_DEF("get_contact_body", 0, &vehicle_wheel3d_class_get_contact_body),
	JS_CFUNC_DEF("get_contact_point", 0, &vehicle_wheel3d_class_get_contact_point),
	JS_CFUNC_DEF("get_contact_normal", 0, &vehicle_wheel3d_class_get_contact_normal),
	JS_CFUNC_DEF("set_roll_influence", 1, &vehicle_wheel3d_class_set_roll_influence),
	JS_CFUNC_DEF("get_roll_influence", 0, &vehicle_wheel3d_class_get_roll_influence),
	JS_CFUNC_DEF("get_skidinfo", 0, &vehicle_wheel3d_class_get_skidinfo),
	JS_CFUNC_DEF("get_rpm", 0, &vehicle_wheel3d_class_get_rpm),
	JS_CFUNC_DEF("set_engine_force", 1, &vehicle_wheel3d_class_set_engine_force),
	JS_CFUNC_DEF("get_engine_force", 0, &vehicle_wheel3d_class_get_engine_force),
	JS_CFUNC_DEF("set_brake", 1, &vehicle_wheel3d_class_set_brake),
	JS_CFUNC_DEF("get_brake", 0, &vehicle_wheel3d_class_get_brake),
	JS_CFUNC_DEF("set_steering", 1, &vehicle_wheel3d_class_set_steering),
	JS_CFUNC_DEF("get_steering", 0, &vehicle_wheel3d_class_get_steering),
};




static void define_vehicle_wheel3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "engine_force"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_engine_force, "get_engine_force", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_engine_force, "set_engine_force", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "brake"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_brake, "get_brake", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_brake, "set_brake", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "steering"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_steering, "get_steering", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_steering, "set_steering", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_as_traction"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_is_used_as_traction, "is_used_as_traction", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_use_as_traction, "set_use_as_traction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_as_steering"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_is_used_as_steering, "is_used_as_steering", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_use_as_steering, "set_use_as_steering", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wheel_roll_influence"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_roll_influence, "get_roll_influence", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_roll_influence, "set_roll_influence", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wheel_radius"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wheel_rest_length"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_suspension_rest_length, "get_suspension_rest_length", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_suspension_rest_length, "set_suspension_rest_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wheel_friction_slip"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_friction_slip, "get_friction_slip", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_friction_slip, "set_friction_slip", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "suspension_travel"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_suspension_travel, "get_suspension_travel", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_suspension_travel, "set_suspension_travel", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "suspension_stiffness"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_suspension_stiffness, "get_suspension_stiffness", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_suspension_stiffness, "set_suspension_stiffness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "suspension_max_force"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_suspension_max_force, "get_suspension_max_force", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_suspension_max_force, "set_suspension_max_force", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "damping_compression"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_damping_compression, "get_damping_compression", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_damping_compression, "set_damping_compression", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "damping_relaxation"),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_get_damping_relaxation, "get_damping_relaxation", 0),
        JS_NewCFunction(ctx, vehicle_wheel3d_class_set_damping_relaxation, "set_damping_relaxation", 1),
        JS_PROP_GETSET
    );
}

static void define_vehicle_wheel3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_vehicle_wheel3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VehicleWheel3D"] = class_id;
	classes_by_id[class_id] = "VehicleWheel3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &vehicle_wheel3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_vehicle_wheel3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vehicle_wheel3d_class_proto_funcs, _countof(vehicle_wheel3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vehicle_wheel3d_class_constructor, "VehicleWheel3D", 0, JS_CFUNC_constructor, 0);
	define_vehicle_wheel3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VehicleWheel3D", ctor);

	return 0;
}

JSModuleDef *_js_init_vehicle_wheel3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_vehicle_wheel3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VehicleWheel3D");
	return m;
}

JSModuleDef *js_init_vehicle_wheel3d_module(JSContext *ctx) {
	return _js_init_vehicle_wheel3d_module(ctx, "@godot/classes/vehicle_wheel3d");
}

void __register_vehicle_wheel3d() {
	js_init_vehicle_wheel3d_module(js_context());
}

void register_vehicle_wheel3d() {
	__register_vehicle_wheel3d();
}