#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_material.hpp>
using namespace godot;

static void physics_material_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsMaterial"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_material_class_def = {
    "PhysicsMaterial",
    physics_material_class_finalizer
};

static JSValue physics_material_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsMaterial"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicsMaterial *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicsMaterial *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicsMaterial);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_material_class_set_friction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsMaterial::set_friction, ctx, this_val, argc, argv);
};
static JSValue physics_material_class_get_friction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsMaterial::get_friction, ctx, this_val, argc, argv);
}
static JSValue physics_material_class_set_rough(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsMaterial::set_rough, ctx, this_val, argc, argv);
};
static JSValue physics_material_class_is_rough(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsMaterial::is_rough, ctx, this_val, argc, argv);
}
static JSValue physics_material_class_set_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsMaterial::set_bounce, ctx, this_val, argc, argv);
};
static JSValue physics_material_class_get_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsMaterial::get_bounce, ctx, this_val, argc, argv);
}
static JSValue physics_material_class_set_absorbent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsMaterial::set_absorbent, ctx, this_val, argc, argv);
};
static JSValue physics_material_class_is_absorbent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsMaterial::is_absorbent, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry physics_material_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_friction", 1, &physics_material_class_set_friction),
	JS_CFUNC_DEF("get_friction", 0, &physics_material_class_get_friction),
	JS_CFUNC_DEF("set_rough", 1, &physics_material_class_set_rough),
	JS_CFUNC_DEF("is_rough", 0, &physics_material_class_is_rough),
	JS_CFUNC_DEF("set_bounce", 1, &physics_material_class_set_bounce),
	JS_CFUNC_DEF("get_bounce", 0, &physics_material_class_get_bounce),
	JS_CFUNC_DEF("set_absorbent", 1, &physics_material_class_set_absorbent),
	JS_CFUNC_DEF("is_absorbent", 0, &physics_material_class_is_absorbent),
};




static void define_physics_material_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "friction"),
        JS_NewCFunction(ctx, physics_material_class_get_friction, "get_friction", 0),
        JS_NewCFunction(ctx, physics_material_class_set_friction, "set_friction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rough"),
        JS_NewCFunction(ctx, physics_material_class_is_rough, "is_rough", 0),
        JS_NewCFunction(ctx, physics_material_class_set_rough, "set_rough", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bounce"),
        JS_NewCFunction(ctx, physics_material_class_get_bounce, "get_bounce", 0),
        JS_NewCFunction(ctx, physics_material_class_set_bounce, "set_bounce", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "absorbent"),
        JS_NewCFunction(ctx, physics_material_class_is_absorbent, "is_absorbent", 0),
        JS_NewCFunction(ctx, physics_material_class_set_absorbent, "set_absorbent", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_material_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_material_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsMaterial"] = class_id;
	classes_by_id[class_id] = "PhysicsMaterial";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_material_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_material_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_material_class_proto_funcs, _countof(physics_material_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_material_class_constructor, "PhysicsMaterial", 0, JS_CFUNC_constructor, 0);
	define_physics_material_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsMaterial", ctor);

	return 0;
}

JSModuleDef *_js_init_physics_material_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_material_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsMaterial");
	return m;
}

JSModuleDef *js_init_physics_material_module(JSContext *ctx) {
	return _js_init_physics_material_module(ctx, "@godot/classes/physics_material");
}

void __register_physics_material() {
	js_init_physics_material_module(js_context());
}

void register_physics_material() {
	__register_physics_material();
}