#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/collision_object3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/ray_cast3d.hpp>
using namespace godot;

static void ray_cast3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RayCast3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef ray_cast3d_class_def = {
    "RayCast3D",
    ray_cast3d_class_finalizer
};

static JSValue ray_cast3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RayCast3D"];
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
        instance = memnew(RayCast3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue ray_cast3d_class_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_enabled, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::is_enabled, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_target_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_target_position, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_target_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		RayCast3D *obj = static_cast<RayCast3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		RayCast3D *js_proxy = static_cast<RayCast3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target_position(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue ray_cast3d_class_is_colliding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::is_colliding, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_force_raycast_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::force_raycast_update, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collider, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collider_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collider_rid, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collider_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collider_shape, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collision_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collision_point, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collision_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collision_normal, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collision_face_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collision_face_index, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_add_exception_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::add_exception_rid, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_add_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::add_exception, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_remove_exception_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::remove_exception_rid, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_remove_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::remove_exception, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_clear_exceptions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::clear_exceptions, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_set_exclude_parent_body(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_exclude_parent_body, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_exclude_parent_body(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_exclude_parent_body, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_collide_with_areas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_collide_with_areas, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_is_collide_with_areas_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::is_collide_with_areas_enabled, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_collide_with_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_collide_with_bodies, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_is_collide_with_bodies_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::is_collide_with_bodies_enabled, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_hit_from_inside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_hit_from_inside, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_is_hit_from_inside_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::is_hit_from_inside_enabled, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_hit_back_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_hit_back_faces, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_is_hit_back_faces_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::is_hit_back_faces_enabled, ctx, this_val, argc, argv);
}
static JSValue ray_cast3d_class_set_debug_shape_custom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_debug_shape_custom_color, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_debug_shape_custom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		RayCast3D *obj = static_cast<RayCast3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_debug_shape_custom_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		RayCast3D *js_proxy = static_cast<RayCast3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_debug_shape_custom_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue ray_cast3d_class_set_debug_shape_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RayCast3D::set_debug_shape_thickness, ctx, this_val, argc, argv);
};
static JSValue ray_cast3d_class_get_debug_shape_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RayCast3D::get_debug_shape_thickness, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry ray_cast3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_enabled", 1, &ray_cast3d_class_set_enabled),
	JS_CFUNC_DEF("is_enabled", 0, &ray_cast3d_class_is_enabled),
	JS_CFUNC_DEF("set_target_position", 1, &ray_cast3d_class_set_target_position),
	JS_CFUNC_DEF("get_target_position", 0, &ray_cast3d_class_get_target_position),
	JS_CFUNC_DEF("is_colliding", 0, &ray_cast3d_class_is_colliding),
	JS_CFUNC_DEF("force_raycast_update", 0, &ray_cast3d_class_force_raycast_update),
	JS_CFUNC_DEF("get_collider", 0, &ray_cast3d_class_get_collider),
	JS_CFUNC_DEF("get_collider_rid", 0, &ray_cast3d_class_get_collider_rid),
	JS_CFUNC_DEF("get_collider_shape", 0, &ray_cast3d_class_get_collider_shape),
	JS_CFUNC_DEF("get_collision_point", 0, &ray_cast3d_class_get_collision_point),
	JS_CFUNC_DEF("get_collision_normal", 0, &ray_cast3d_class_get_collision_normal),
	JS_CFUNC_DEF("get_collision_face_index", 0, &ray_cast3d_class_get_collision_face_index),
	JS_CFUNC_DEF("add_exception_rid", 1, &ray_cast3d_class_add_exception_rid),
	JS_CFUNC_DEF("add_exception", 1, &ray_cast3d_class_add_exception),
	JS_CFUNC_DEF("remove_exception_rid", 1, &ray_cast3d_class_remove_exception_rid),
	JS_CFUNC_DEF("remove_exception", 1, &ray_cast3d_class_remove_exception),
	JS_CFUNC_DEF("clear_exceptions", 0, &ray_cast3d_class_clear_exceptions),
	JS_CFUNC_DEF("set_collision_mask", 1, &ray_cast3d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &ray_cast3d_class_get_collision_mask),
	JS_CFUNC_DEF("set_collision_mask_value", 2, &ray_cast3d_class_set_collision_mask_value),
	JS_CFUNC_DEF("get_collision_mask_value", 1, &ray_cast3d_class_get_collision_mask_value),
	JS_CFUNC_DEF("set_exclude_parent_body", 1, &ray_cast3d_class_set_exclude_parent_body),
	JS_CFUNC_DEF("get_exclude_parent_body", 0, &ray_cast3d_class_get_exclude_parent_body),
	JS_CFUNC_DEF("set_collide_with_areas", 1, &ray_cast3d_class_set_collide_with_areas),
	JS_CFUNC_DEF("is_collide_with_areas_enabled", 0, &ray_cast3d_class_is_collide_with_areas_enabled),
	JS_CFUNC_DEF("set_collide_with_bodies", 1, &ray_cast3d_class_set_collide_with_bodies),
	JS_CFUNC_DEF("is_collide_with_bodies_enabled", 0, &ray_cast3d_class_is_collide_with_bodies_enabled),
	JS_CFUNC_DEF("set_hit_from_inside", 1, &ray_cast3d_class_set_hit_from_inside),
	JS_CFUNC_DEF("is_hit_from_inside_enabled", 0, &ray_cast3d_class_is_hit_from_inside_enabled),
	JS_CFUNC_DEF("set_hit_back_faces", 1, &ray_cast3d_class_set_hit_back_faces),
	JS_CFUNC_DEF("is_hit_back_faces_enabled", 0, &ray_cast3d_class_is_hit_back_faces_enabled),
	JS_CFUNC_DEF("set_debug_shape_custom_color", 1, &ray_cast3d_class_set_debug_shape_custom_color),
	JS_CFUNC_DEF("get_debug_shape_custom_color", 0, &ray_cast3d_class_get_debug_shape_custom_color),
	JS_CFUNC_DEF("set_debug_shape_thickness", 1, &ray_cast3d_class_set_debug_shape_thickness),
	JS_CFUNC_DEF("get_debug_shape_thickness", 0, &ray_cast3d_class_get_debug_shape_thickness),
};




static void define_ray_cast3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled"),
        JS_NewCFunction(ctx, ray_cast3d_class_is_enabled, "is_enabled", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_enabled, "set_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude_parent"),
        JS_NewCFunction(ctx, ray_cast3d_class_get_exclude_parent_body, "get_exclude_parent_body", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_exclude_parent_body, "set_exclude_parent_body", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_position"),
        JS_NewCFunction(ctx, ray_cast3d_class_get_target_position, "get_target_position", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_target_position, "set_target_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, ray_cast3d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hit_from_inside"),
        JS_NewCFunction(ctx, ray_cast3d_class_is_hit_from_inside_enabled, "is_hit_from_inside_enabled", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_hit_from_inside, "set_hit_from_inside", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hit_back_faces"),
        JS_NewCFunction(ctx, ray_cast3d_class_is_hit_back_faces_enabled, "is_hit_back_faces_enabled", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_hit_back_faces, "set_hit_back_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_areas"),
        JS_NewCFunction(ctx, ray_cast3d_class_is_collide_with_areas_enabled, "is_collide_with_areas_enabled", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_collide_with_areas, "set_collide_with_areas", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_bodies"),
        JS_NewCFunction(ctx, ray_cast3d_class_is_collide_with_bodies_enabled, "is_collide_with_bodies_enabled", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_collide_with_bodies, "set_collide_with_bodies", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_shape_custom_color"),
        JS_NewCFunction(ctx, ray_cast3d_class_get_debug_shape_custom_color, "get_debug_shape_custom_color", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_debug_shape_custom_color, "set_debug_shape_custom_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_shape_thickness"),
        JS_NewCFunction(ctx, ray_cast3d_class_get_debug_shape_thickness, "get_debug_shape_thickness", 0),
        JS_NewCFunction(ctx, ray_cast3d_class_set_debug_shape_thickness, "set_debug_shape_thickness", 1),
        JS_PROP_GETSET
    );
}

static void define_ray_cast3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_ray_cast3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RayCast3D"] = class_id;
	classes_by_id[class_id] = "RayCast3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &ray_cast3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_ray_cast3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, ray_cast3d_class_proto_funcs, _countof(ray_cast3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, ray_cast3d_class_constructor, "RayCast3D", 0, JS_CFUNC_constructor, 0);
	define_ray_cast3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RayCast3D", ctor);
	ctor_list["RayCast3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_ray_cast3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_ray_cast3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RayCast3D");
	return m;
}

JSModuleDef *js_init_ray_cast3d_module(JSContext *ctx) {
	return _js_init_ray_cast3d_module(ctx, "@godot/classes/ray_cast3d");
}

void __register_ray_cast3d() {
	js_init_ray_cast3d_module(js_context());
}

void register_ray_cast3d() {
	__register_ray_cast3d();
}