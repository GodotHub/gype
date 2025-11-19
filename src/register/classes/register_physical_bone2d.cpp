#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/joint2d.hpp>
#include <godot_cpp/classes/rigid_body2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physical_bone2d.hpp>
using namespace godot;

static void physical_bone2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicalBone2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physical_bone2d_class_def = {
    "PhysicalBone2D",
    physical_bone2d_class_finalizer
};

static JSValue physical_bone2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicalBone2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicalBone2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicalBone2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicalBone2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physical_bone2d_class_get_joint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone2D::get_joint, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_get_auto_configure_joint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone2D::get_auto_configure_joint, ctx, this_val, argc, argv);
}
static JSValue physical_bone2d_class_set_auto_configure_joint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone2D::set_auto_configure_joint, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_set_simulate_physics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone2D::set_simulate_physics, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_get_simulate_physics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone2D::get_simulate_physics, ctx, this_val, argc, argv);
}
static JSValue physical_bone2d_class_is_simulating_physics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone2D::is_simulating_physics, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_set_bone2d_nodepath(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone2D::set_bone2d_nodepath, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_get_bone2d_nodepath(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		PhysicalBone2D *obj = static_cast<PhysicalBone2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_bone2d_nodepath();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		PhysicalBone2D *js_proxy = static_cast<PhysicalBone2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_bone2d_nodepath(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physical_bone2d_class_set_bone2d_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone2D::set_bone2d_index, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_get_bone2d_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone2D::get_bone2d_index, ctx, this_val, argc, argv);
}
static JSValue physical_bone2d_class_set_follow_bone_when_simulating(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone2D::set_follow_bone_when_simulating, ctx, this_val, argc, argv);
};
static JSValue physical_bone2d_class_get_follow_bone_when_simulating(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone2D::get_follow_bone_when_simulating, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry physical_bone2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_joint", 0, &physical_bone2d_class_get_joint),
	JS_CFUNC_DEF("get_auto_configure_joint", 0, &physical_bone2d_class_get_auto_configure_joint),
	JS_CFUNC_DEF("set_auto_configure_joint", 1, &physical_bone2d_class_set_auto_configure_joint),
	JS_CFUNC_DEF("set_simulate_physics", 1, &physical_bone2d_class_set_simulate_physics),
	JS_CFUNC_DEF("get_simulate_physics", 0, &physical_bone2d_class_get_simulate_physics),
	JS_CFUNC_DEF("is_simulating_physics", 0, &physical_bone2d_class_is_simulating_physics),
	JS_CFUNC_DEF("set_bone2d_nodepath", 1, &physical_bone2d_class_set_bone2d_nodepath),
	JS_CFUNC_DEF("get_bone2d_nodepath", 0, &physical_bone2d_class_get_bone2d_nodepath),
	JS_CFUNC_DEF("set_bone2d_index", 1, &physical_bone2d_class_set_bone2d_index),
	JS_CFUNC_DEF("get_bone2d_index", 0, &physical_bone2d_class_get_bone2d_index),
	JS_CFUNC_DEF("set_follow_bone_when_simulating", 1, &physical_bone2d_class_set_follow_bone_when_simulating),
	JS_CFUNC_DEF("get_follow_bone_when_simulating", 0, &physical_bone2d_class_get_follow_bone_when_simulating),
};




static void define_physical_bone2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone2d_nodepath"),
        JS_NewCFunction(ctx, physical_bone2d_class_get_bone2d_nodepath, "get_bone2d_nodepath", 0),
        JS_NewCFunction(ctx, physical_bone2d_class_set_bone2d_nodepath, "set_bone2d_nodepath", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone2d_index"),
        JS_NewCFunction(ctx, physical_bone2d_class_get_bone2d_index, "get_bone2d_index", 0),
        JS_NewCFunction(ctx, physical_bone2d_class_set_bone2d_index, "set_bone2d_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_configure_joint"),
        JS_NewCFunction(ctx, physical_bone2d_class_get_auto_configure_joint, "get_auto_configure_joint", 0),
        JS_NewCFunction(ctx, physical_bone2d_class_set_auto_configure_joint, "set_auto_configure_joint", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "simulate_physics"),
        JS_NewCFunction(ctx, physical_bone2d_class_get_simulate_physics, "get_simulate_physics", 0),
        JS_NewCFunction(ctx, physical_bone2d_class_set_simulate_physics, "set_simulate_physics", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "follow_bone_when_simulating"),
        JS_NewCFunction(ctx, physical_bone2d_class_get_follow_bone_when_simulating, "get_follow_bone_when_simulating", 0),
        JS_NewCFunction(ctx, physical_bone2d_class_set_follow_bone_when_simulating, "set_follow_bone_when_simulating", 1),
        JS_PROP_GETSET
    );
}

static void define_physical_bone2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physical_bone2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicalBone2D"] = class_id;
	classes_by_id[class_id] = "PhysicalBone2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physical_bone2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RigidBody2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physical_bone2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physical_bone2d_class_proto_funcs, _countof(physical_bone2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physical_bone2d_class_constructor, "PhysicalBone2D", 0, JS_CFUNC_constructor, 0);
	define_physical_bone2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicalBone2D", ctor);

	return 0;
}

JSModuleDef *_js_init_physical_bone2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/rigid_body2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physical_bone2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicalBone2D");
	return m;
}

JSModuleDef *js_init_physical_bone2d_module(JSContext *ctx) {
	return _js_init_physical_bone2d_module(ctx, "@godot/classes/physical_bone2d");
}

void __register_physical_bone2d() {
	js_init_physical_bone2d_module(js_context());
}

void register_physical_bone2d() {
	__register_physical_bone2d();
}