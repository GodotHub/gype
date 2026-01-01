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
#include <godot_cpp/classes/physics_point_query_parameters2d.hpp>
using namespace godot;

static void physics_point_query_parameters2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsPointQueryParameters2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_point_query_parameters2d_class_def = {
    "PhysicsPointQueryParameters2D",
    physics_point_query_parameters2d_class_finalizer
};

static JSValue physics_point_query_parameters2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsPointQueryParameters2D"];
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
        instance = memnew(PhysicsPointQueryParameters2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_point_query_parameters2d_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsPointQueryParameters2D::set_position, ctx, this_val, argc, argv);
};
static JSValue physics_point_query_parameters2d_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsPointQueryParameters2D *obj = static_cast<PhysicsPointQueryParameters2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PhysicsPointQueryParameters2D *js_proxy = static_cast<PhysicsPointQueryParameters2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position(value);
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
static JSValue physics_point_query_parameters2d_class_set_canvas_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsPointQueryParameters2D::set_canvas_instance_id, ctx, this_val, argc, argv);
};
static JSValue physics_point_query_parameters2d_class_get_canvas_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsPointQueryParameters2D::get_canvas_instance_id, ctx, this_val, argc, argv);
}
static JSValue physics_point_query_parameters2d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsPointQueryParameters2D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_point_query_parameters2d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsPointQueryParameters2D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue physics_point_query_parameters2d_class_set_exclude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsPointQueryParameters2D::set_exclude, ctx, this_val, argc, argv);
};
static JSValue physics_point_query_parameters2d_class_get_exclude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsPointQueryParameters2D::get_exclude, ctx, this_val, argc, argv);
}
static JSValue physics_point_query_parameters2d_class_set_collide_with_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsPointQueryParameters2D::set_collide_with_bodies, ctx, this_val, argc, argv);
};
static JSValue physics_point_query_parameters2d_class_is_collide_with_bodies_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsPointQueryParameters2D::is_collide_with_bodies_enabled, ctx, this_val, argc, argv);
}
static JSValue physics_point_query_parameters2d_class_set_collide_with_areas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsPointQueryParameters2D::set_collide_with_areas, ctx, this_val, argc, argv);
};
static JSValue physics_point_query_parameters2d_class_is_collide_with_areas_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsPointQueryParameters2D::is_collide_with_areas_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry physics_point_query_parameters2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_position", 1, &physics_point_query_parameters2d_class_set_position),
	JS_CFUNC_DEF("get_position", 0, &physics_point_query_parameters2d_class_get_position),
	JS_CFUNC_DEF("set_canvas_instance_id", 1, &physics_point_query_parameters2d_class_set_canvas_instance_id),
	JS_CFUNC_DEF("get_canvas_instance_id", 0, &physics_point_query_parameters2d_class_get_canvas_instance_id),
	JS_CFUNC_DEF("set_collision_mask", 1, &physics_point_query_parameters2d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &physics_point_query_parameters2d_class_get_collision_mask),
	JS_CFUNC_DEF("set_exclude", 1, &physics_point_query_parameters2d_class_set_exclude),
	JS_CFUNC_DEF("get_exclude", 0, &physics_point_query_parameters2d_class_get_exclude),
	JS_CFUNC_DEF("set_collide_with_bodies", 1, &physics_point_query_parameters2d_class_set_collide_with_bodies),
	JS_CFUNC_DEF("is_collide_with_bodies_enabled", 0, &physics_point_query_parameters2d_class_is_collide_with_bodies_enabled),
	JS_CFUNC_DEF("set_collide_with_areas", 1, &physics_point_query_parameters2d_class_set_collide_with_areas),
	JS_CFUNC_DEF("is_collide_with_areas_enabled", 0, &physics_point_query_parameters2d_class_is_collide_with_areas_enabled),
};




static void define_physics_point_query_parameters2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position"),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_get_position, "get_position", 0),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_set_position, "set_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "canvas_instance_id"),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_get_canvas_instance_id, "get_canvas_instance_id", 0),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_set_canvas_instance_id, "set_canvas_instance_id", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude"),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_get_exclude, "get_exclude", 0),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_set_exclude, "set_exclude", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_bodies"),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_is_collide_with_bodies_enabled, "is_collide_with_bodies_enabled", 0),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_set_collide_with_bodies, "set_collide_with_bodies", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_areas"),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_is_collide_with_areas_enabled, "is_collide_with_areas_enabled", 0),
        JS_NewCFunction(ctx, physics_point_query_parameters2d_class_set_collide_with_areas, "set_collide_with_areas", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_point_query_parameters2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_point_query_parameters2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsPointQueryParameters2D"] = class_id;
	classes_by_id[class_id] = "PhysicsPointQueryParameters2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_point_query_parameters2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_point_query_parameters2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_point_query_parameters2d_class_proto_funcs, _countof(physics_point_query_parameters2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_point_query_parameters2d_class_constructor, "PhysicsPointQueryParameters2D", 0, JS_CFUNC_constructor, 0);
	define_physics_point_query_parameters2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsPointQueryParameters2D", ctor);
	ctor_list["PhysicsPointQueryParameters2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_physics_point_query_parameters2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_point_query_parameters2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsPointQueryParameters2D");
	return m;
}

JSModuleDef *js_init_physics_point_query_parameters2d_module(JSContext *ctx) {
	return _js_init_physics_point_query_parameters2d_module(ctx, "@godot/classes/physics_point_query_parameters2d");
}

void __register_physics_point_query_parameters2d() {
	js_init_physics_point_query_parameters2d_module(js_context());
}

void register_physics_point_query_parameters2d() {
	__register_physics_point_query_parameters2d();
}