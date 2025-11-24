#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/physics_body3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/soft_body3d.hpp>
using namespace godot;

static void soft_body3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SoftBody3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef soft_body3d_class_def = {
    "SoftBody3D",
    soft_body3d_class_finalizer
};

static JSValue soft_body3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SoftBody3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SoftBody3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SoftBody3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SoftBody3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue soft_body3d_class_get_physics_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_physics_rid, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_collision_layer, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_collision_layer, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_set_collision_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_collision_layer_value, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_collision_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_collision_layer_value, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_set_parent_collision_ignore(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_parent_collision_ignore, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_parent_collision_ignore(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_parent_collision_ignore, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_disable_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_disable_mode, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_disable_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::get_disable_mode, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_get_collision_exceptions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_collision_exceptions, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_add_collision_exception_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::add_collision_exception_with, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_remove_collision_exception_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::remove_collision_exception_with, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_set_simulation_precision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_simulation_precision, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_simulation_precision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_simulation_precision, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_total_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_total_mass, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_total_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_total_mass, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_linear_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_linear_stiffness, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_linear_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_linear_stiffness, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_shrinking_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_shrinking_factor, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_shrinking_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_shrinking_factor, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_pressure_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_pressure_coefficient, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_pressure_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_pressure_coefficient, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_damping_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_damping_coefficient, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_damping_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_damping_coefficient, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_set_drag_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_drag_coefficient, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_get_drag_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_drag_coefficient, ctx, this_val, argc, argv);
}
static JSValue soft_body3d_class_get_point_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SoftBody3D::get_point_transform, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_apply_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::apply_impulse, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_apply_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::apply_force, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_apply_central_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::apply_central_impulse, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_apply_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::apply_central_force, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_set_point_pinned(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_point_pinned, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_is_point_pinned(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::is_point_pinned, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_set_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SoftBody3D::set_ray_pickable, ctx, this_val, argc, argv);
};
static JSValue soft_body3d_class_is_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SoftBody3D::is_ray_pickable, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry soft_body3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_physics_rid", 0, &soft_body3d_class_get_physics_rid),
	JS_CFUNC_DEF("set_collision_mask", 1, &soft_body3d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &soft_body3d_class_get_collision_mask),
	JS_CFUNC_DEF("set_collision_layer", 1, &soft_body3d_class_set_collision_layer),
	JS_CFUNC_DEF("get_collision_layer", 0, &soft_body3d_class_get_collision_layer),
	JS_CFUNC_DEF("set_collision_mask_value", 2, &soft_body3d_class_set_collision_mask_value),
	JS_CFUNC_DEF("get_collision_mask_value", 1, &soft_body3d_class_get_collision_mask_value),
	JS_CFUNC_DEF("set_collision_layer_value", 2, &soft_body3d_class_set_collision_layer_value),
	JS_CFUNC_DEF("get_collision_layer_value", 1, &soft_body3d_class_get_collision_layer_value),
	JS_CFUNC_DEF("set_parent_collision_ignore", 1, &soft_body3d_class_set_parent_collision_ignore),
	JS_CFUNC_DEF("get_parent_collision_ignore", 0, &soft_body3d_class_get_parent_collision_ignore),
	JS_CFUNC_DEF("set_disable_mode", 1, &soft_body3d_class_set_disable_mode),
	JS_CFUNC_DEF("get_disable_mode", 0, &soft_body3d_class_get_disable_mode),
	JS_CFUNC_DEF("get_collision_exceptions", 0, &soft_body3d_class_get_collision_exceptions),
	JS_CFUNC_DEF("add_collision_exception_with", 1, &soft_body3d_class_add_collision_exception_with),
	JS_CFUNC_DEF("remove_collision_exception_with", 1, &soft_body3d_class_remove_collision_exception_with),
	JS_CFUNC_DEF("set_simulation_precision", 1, &soft_body3d_class_set_simulation_precision),
	JS_CFUNC_DEF("get_simulation_precision", 0, &soft_body3d_class_get_simulation_precision),
	JS_CFUNC_DEF("set_total_mass", 1, &soft_body3d_class_set_total_mass),
	JS_CFUNC_DEF("get_total_mass", 0, &soft_body3d_class_get_total_mass),
	JS_CFUNC_DEF("set_linear_stiffness", 1, &soft_body3d_class_set_linear_stiffness),
	JS_CFUNC_DEF("get_linear_stiffness", 0, &soft_body3d_class_get_linear_stiffness),
	JS_CFUNC_DEF("set_shrinking_factor", 1, &soft_body3d_class_set_shrinking_factor),
	JS_CFUNC_DEF("get_shrinking_factor", 0, &soft_body3d_class_get_shrinking_factor),
	JS_CFUNC_DEF("set_pressure_coefficient", 1, &soft_body3d_class_set_pressure_coefficient),
	JS_CFUNC_DEF("get_pressure_coefficient", 0, &soft_body3d_class_get_pressure_coefficient),
	JS_CFUNC_DEF("set_damping_coefficient", 1, &soft_body3d_class_set_damping_coefficient),
	JS_CFUNC_DEF("get_damping_coefficient", 0, &soft_body3d_class_get_damping_coefficient),
	JS_CFUNC_DEF("set_drag_coefficient", 1, &soft_body3d_class_set_drag_coefficient),
	JS_CFUNC_DEF("get_drag_coefficient", 0, &soft_body3d_class_get_drag_coefficient),
	JS_CFUNC_DEF("get_point_transform", 1, &soft_body3d_class_get_point_transform),
	JS_CFUNC_DEF("apply_impulse", 2, &soft_body3d_class_apply_impulse),
	JS_CFUNC_DEF("apply_force", 2, &soft_body3d_class_apply_force),
	JS_CFUNC_DEF("apply_central_impulse", 1, &soft_body3d_class_apply_central_impulse),
	JS_CFUNC_DEF("apply_central_force", 1, &soft_body3d_class_apply_central_force),
	JS_CFUNC_DEF("set_point_pinned", 4, &soft_body3d_class_set_point_pinned),
	JS_CFUNC_DEF("is_point_pinned", 1, &soft_body3d_class_is_point_pinned),
	JS_CFUNC_DEF("set_ray_pickable", 1, &soft_body3d_class_set_ray_pickable),
	JS_CFUNC_DEF("is_ray_pickable", 0, &soft_body3d_class_is_ray_pickable),
};




static void define_soft_body3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_layer"),
        JS_NewCFunction(ctx, soft_body3d_class_get_collision_layer, "get_collision_layer", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_collision_layer, "set_collision_layer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, soft_body3d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "parent_collision_ignore"),
        JS_NewCFunction(ctx, soft_body3d_class_get_parent_collision_ignore, "get_parent_collision_ignore", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_parent_collision_ignore, "set_parent_collision_ignore", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "simulation_precision"),
        JS_NewCFunction(ctx, soft_body3d_class_get_simulation_precision, "get_simulation_precision", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_simulation_precision, "set_simulation_precision", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "total_mass"),
        JS_NewCFunction(ctx, soft_body3d_class_get_total_mass, "get_total_mass", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_total_mass, "set_total_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_stiffness"),
        JS_NewCFunction(ctx, soft_body3d_class_get_linear_stiffness, "get_linear_stiffness", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_linear_stiffness, "set_linear_stiffness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shrinking_factor"),
        JS_NewCFunction(ctx, soft_body3d_class_get_shrinking_factor, "get_shrinking_factor", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_shrinking_factor, "set_shrinking_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pressure_coefficient"),
        JS_NewCFunction(ctx, soft_body3d_class_get_pressure_coefficient, "get_pressure_coefficient", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_pressure_coefficient, "set_pressure_coefficient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "damping_coefficient"),
        JS_NewCFunction(ctx, soft_body3d_class_get_damping_coefficient, "get_damping_coefficient", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_damping_coefficient, "set_damping_coefficient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_coefficient"),
        JS_NewCFunction(ctx, soft_body3d_class_get_drag_coefficient, "get_drag_coefficient", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_drag_coefficient, "set_drag_coefficient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ray_pickable"),
        JS_NewCFunction(ctx, soft_body3d_class_is_ray_pickable, "is_ray_pickable", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_ray_pickable, "set_ray_pickable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "disable_mode"),
        JS_NewCFunction(ctx, soft_body3d_class_get_disable_mode, "get_disable_mode", 0),
        JS_NewCFunction(ctx, soft_body3d_class_set_disable_mode, "set_disable_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_soft_body3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue DisableMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DisableMode_obj, "DISABLE_MODE_REMOVE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DisableMode_obj, "DISABLE_MODE_KEEP_ACTIVE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "DisableMode", DisableMode_obj);
}

static int js_soft_body3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SoftBody3D"] = class_id;
	classes_by_id[class_id] = "SoftBody3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &soft_body3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["MeshInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_soft_body3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, soft_body3d_class_proto_funcs, _countof(soft_body3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, soft_body3d_class_constructor, "SoftBody3D", 0, JS_CFUNC_constructor, 0);
	define_soft_body3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SoftBody3D", ctor);

	return 0;
}

JSModuleDef *_js_init_soft_body3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/mesh_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_soft_body3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SoftBody3D");
	return m;
}

JSModuleDef *js_init_soft_body3d_module(JSContext *ctx) {
	return _js_init_soft_body3d_module(ctx, "@godot/classes/soft_body3d");
}

void __register_soft_body3d() {
	js_init_soft_body3d_module(js_context());
}

void register_soft_body3d() {
	__register_soft_body3d();
}