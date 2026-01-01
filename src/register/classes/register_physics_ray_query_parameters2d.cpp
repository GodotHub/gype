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
#include <godot_cpp/classes/physics_ray_query_parameters2d.hpp>
using namespace godot;

static void physics_ray_query_parameters2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsRayQueryParameters2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_ray_query_parameters2d_class_def = {
    "PhysicsRayQueryParameters2D",
    physics_ray_query_parameters2d_class_finalizer
};

static JSValue physics_ray_query_parameters2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsRayQueryParameters2D"];
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
        instance = memnew(PhysicsRayQueryParameters2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_ray_query_parameters2d_class_set_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_from, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_get_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsRayQueryParameters2D *obj = static_cast<PhysicsRayQueryParameters2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_from();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PhysicsRayQueryParameters2D *js_proxy = static_cast<PhysicsRayQueryParameters2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_from(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_ray_query_parameters2d_class_set_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_to, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_get_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsRayQueryParameters2D *obj = static_cast<PhysicsRayQueryParameters2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_to();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PhysicsRayQueryParameters2D *js_proxy = static_cast<PhysicsRayQueryParameters2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_to(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_ray_query_parameters2d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsRayQueryParameters2D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue physics_ray_query_parameters2d_class_set_exclude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_exclude, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_get_exclude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsRayQueryParameters2D::get_exclude, ctx, this_val, argc, argv);
}
static JSValue physics_ray_query_parameters2d_class_set_collide_with_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_collide_with_bodies, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_is_collide_with_bodies_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsRayQueryParameters2D::is_collide_with_bodies_enabled, ctx, this_val, argc, argv);
}
static JSValue physics_ray_query_parameters2d_class_set_collide_with_areas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_collide_with_areas, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_is_collide_with_areas_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsRayQueryParameters2D::is_collide_with_areas_enabled, ctx, this_val, argc, argv);
}
static JSValue physics_ray_query_parameters2d_class_set_hit_from_inside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsRayQueryParameters2D::set_hit_from_inside, ctx, this_val, argc, argv);
};
static JSValue physics_ray_query_parameters2d_class_is_hit_from_inside_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsRayQueryParameters2D::is_hit_from_inside_enabled, ctx, this_val, argc, argv);
}


static JSValue physics_ray_query_parameters2d_class_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&PhysicsRayQueryParameters2D::create, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry physics_ray_query_parameters2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_from", 1, &physics_ray_query_parameters2d_class_set_from),
	JS_CFUNC_DEF("get_from", 0, &physics_ray_query_parameters2d_class_get_from),
	JS_CFUNC_DEF("set_to", 1, &physics_ray_query_parameters2d_class_set_to),
	JS_CFUNC_DEF("get_to", 0, &physics_ray_query_parameters2d_class_get_to),
	JS_CFUNC_DEF("set_collision_mask", 1, &physics_ray_query_parameters2d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &physics_ray_query_parameters2d_class_get_collision_mask),
	JS_CFUNC_DEF("set_exclude", 1, &physics_ray_query_parameters2d_class_set_exclude),
	JS_CFUNC_DEF("get_exclude", 0, &physics_ray_query_parameters2d_class_get_exclude),
	JS_CFUNC_DEF("set_collide_with_bodies", 1, &physics_ray_query_parameters2d_class_set_collide_with_bodies),
	JS_CFUNC_DEF("is_collide_with_bodies_enabled", 0, &physics_ray_query_parameters2d_class_is_collide_with_bodies_enabled),
	JS_CFUNC_DEF("set_collide_with_areas", 1, &physics_ray_query_parameters2d_class_set_collide_with_areas),
	JS_CFUNC_DEF("is_collide_with_areas_enabled", 0, &physics_ray_query_parameters2d_class_is_collide_with_areas_enabled),
	JS_CFUNC_DEF("set_hit_from_inside", 1, &physics_ray_query_parameters2d_class_set_hit_from_inside),
	JS_CFUNC_DEF("is_hit_from_inside_enabled", 0, &physics_ray_query_parameters2d_class_is_hit_from_inside_enabled),
};

static const JSCFunctionListEntry physics_ray_query_parameters2d_class_static_funcs[] = {
	JS_CFUNC_DEF("create", 4, &physics_ray_query_parameters2d_class_create),
};



static void define_physics_ray_query_parameters2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "from"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_get_from, "get_from", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_from, "set_from", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "to"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_get_to, "get_to", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_to, "set_to", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_get_exclude, "get_exclude", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_exclude, "set_exclude", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_bodies"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_is_collide_with_bodies_enabled, "is_collide_with_bodies_enabled", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_collide_with_bodies, "set_collide_with_bodies", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_areas"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_is_collide_with_areas_enabled, "is_collide_with_areas_enabled", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_collide_with_areas, "set_collide_with_areas", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hit_from_inside"),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_is_hit_from_inside_enabled, "is_hit_from_inside_enabled", 0),
        JS_NewCFunction(ctx, physics_ray_query_parameters2d_class_set_hit_from_inside, "set_hit_from_inside", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_ray_query_parameters2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_ray_query_parameters2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsRayQueryParameters2D"] = class_id;
	classes_by_id[class_id] = "PhysicsRayQueryParameters2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_ray_query_parameters2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_ray_query_parameters2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_ray_query_parameters2d_class_proto_funcs, _countof(physics_ray_query_parameters2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_ray_query_parameters2d_class_constructor, "PhysicsRayQueryParameters2D", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, physics_ray_query_parameters2d_class_static_funcs, _countof(physics_ray_query_parameters2d_class_static_funcs));
	define_physics_ray_query_parameters2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsRayQueryParameters2D", ctor);
	ctor_list["PhysicsRayQueryParameters2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_physics_ray_query_parameters2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_ray_query_parameters2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsRayQueryParameters2D");
	return m;
}

JSModuleDef *js_init_physics_ray_query_parameters2d_module(JSContext *ctx) {
	return _js_init_physics_ray_query_parameters2d_module(ctx, "@godot/classes/physics_ray_query_parameters2d");
}

void __register_physics_ray_query_parameters2d() {
	js_init_physics_ray_query_parameters2d_module(js_context());
}

void register_physics_ray_query_parameters2d() {
	__register_physics_ray_query_parameters2d();
}