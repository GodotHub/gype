#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/collision_object3d.hpp>
using namespace godot;

static void collision_object3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CollisionObject3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef collision_object3d_class_def = {
    "CollisionObject3D",
    collision_object3d_class_finalizer
};

static JSValue collision_object3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CollisionObject3D"];
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
        instance = memnew(CollisionObject3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue collision_object3d_class_set_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_collision_layer, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_collision_layer, ctx, this_val, argc, argv);
}
static JSValue collision_object3d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue collision_object3d_class_set_collision_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_collision_layer_value, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_collision_layer_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_collision_layer_value, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_set_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_collision_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_collision_mask_value, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_set_collision_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_collision_priority, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_collision_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_collision_priority, ctx, this_val, argc, argv);
}
static JSValue collision_object3d_class_set_disable_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_disable_mode, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_disable_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_disable_mode, ctx, this_val, argc, argv);
}
static JSValue collision_object3d_class_set_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_ray_pickable, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_is_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::is_ray_pickable, ctx, this_val, argc, argv);
}
static JSValue collision_object3d_class_set_capture_input_on_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::set_capture_input_on_drag, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_capture_input_on_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_capture_input_on_drag, ctx, this_val, argc, argv);
}
static JSValue collision_object3d_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::get_rid, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_create_shape_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CollisionObject3D::create_shape_owner, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_remove_shape_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::remove_shape_owner, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_get_shape_owners(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CollisionObject3D::get_shape_owners, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::shape_owner_set_transform, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::shape_owner_get_transform, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_get_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::shape_owner_get_owner, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_set_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::shape_owner_set_disabled, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_is_shape_owner_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::is_shape_owner_disabled, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_add_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::shape_owner_add_shape, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_get_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::shape_owner_get_shape_count, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::shape_owner_get_shape, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_get_shape_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::shape_owner_get_shape_index, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_remove_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::shape_owner_remove_shape, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_owner_clear_shapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionObject3D::shape_owner_clear_shapes, ctx, this_val, argc, argv);
};
static JSValue collision_object3d_class_shape_find_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionObject3D::shape_find_owner, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry collision_object3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_collision_layer", 1, &collision_object3d_class_set_collision_layer),
	JS_CFUNC_DEF("get_collision_layer", 0, &collision_object3d_class_get_collision_layer),
	JS_CFUNC_DEF("set_collision_mask", 1, &collision_object3d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &collision_object3d_class_get_collision_mask),
	JS_CFUNC_DEF("set_collision_layer_value", 2, &collision_object3d_class_set_collision_layer_value),
	JS_CFUNC_DEF("get_collision_layer_value", 1, &collision_object3d_class_get_collision_layer_value),
	JS_CFUNC_DEF("set_collision_mask_value", 2, &collision_object3d_class_set_collision_mask_value),
	JS_CFUNC_DEF("get_collision_mask_value", 1, &collision_object3d_class_get_collision_mask_value),
	JS_CFUNC_DEF("set_collision_priority", 1, &collision_object3d_class_set_collision_priority),
	JS_CFUNC_DEF("get_collision_priority", 0, &collision_object3d_class_get_collision_priority),
	JS_CFUNC_DEF("set_disable_mode", 1, &collision_object3d_class_set_disable_mode),
	JS_CFUNC_DEF("get_disable_mode", 0, &collision_object3d_class_get_disable_mode),
	JS_CFUNC_DEF("set_ray_pickable", 1, &collision_object3d_class_set_ray_pickable),
	JS_CFUNC_DEF("is_ray_pickable", 0, &collision_object3d_class_is_ray_pickable),
	JS_CFUNC_DEF("set_capture_input_on_drag", 1, &collision_object3d_class_set_capture_input_on_drag),
	JS_CFUNC_DEF("get_capture_input_on_drag", 0, &collision_object3d_class_get_capture_input_on_drag),
	JS_CFUNC_DEF("get_rid", 0, &collision_object3d_class_get_rid),
	JS_CFUNC_DEF("create_shape_owner", 1, &collision_object3d_class_create_shape_owner),
	JS_CFUNC_DEF("remove_shape_owner", 1, &collision_object3d_class_remove_shape_owner),
	JS_CFUNC_DEF("get_shape_owners", 0, &collision_object3d_class_get_shape_owners),
	JS_CFUNC_DEF("shape_owner_set_transform", 2, &collision_object3d_class_shape_owner_set_transform),
	JS_CFUNC_DEF("shape_owner_get_transform", 1, &collision_object3d_class_shape_owner_get_transform),
	JS_CFUNC_DEF("shape_owner_get_owner", 1, &collision_object3d_class_shape_owner_get_owner),
	JS_CFUNC_DEF("shape_owner_set_disabled", 2, &collision_object3d_class_shape_owner_set_disabled),
	JS_CFUNC_DEF("is_shape_owner_disabled", 1, &collision_object3d_class_is_shape_owner_disabled),
	JS_CFUNC_DEF("shape_owner_add_shape", 2, &collision_object3d_class_shape_owner_add_shape),
	JS_CFUNC_DEF("shape_owner_get_shape_count", 1, &collision_object3d_class_shape_owner_get_shape_count),
	JS_CFUNC_DEF("shape_owner_get_shape", 2, &collision_object3d_class_shape_owner_get_shape),
	JS_CFUNC_DEF("shape_owner_get_shape_index", 2, &collision_object3d_class_shape_owner_get_shape_index),
	JS_CFUNC_DEF("shape_owner_remove_shape", 2, &collision_object3d_class_shape_owner_remove_shape),
	JS_CFUNC_DEF("shape_owner_clear_shapes", 1, &collision_object3d_class_shape_owner_clear_shapes),
	JS_CFUNC_DEF("shape_find_owner", 1, &collision_object3d_class_shape_find_owner),
};


static JSValue collision_object3d_class_get_input_event_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CollisionObject3D *opaque = static_cast<CollisionObject3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "input_event_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "input_event"));
		JS_DefinePropertyValueStr(ctx, this_val, "input_event_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue collision_object3d_class_get_mouse_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CollisionObject3D *opaque = static_cast<CollisionObject3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "mouse_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "mouse_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "mouse_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue collision_object3d_class_get_mouse_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CollisionObject3D *opaque = static_cast<CollisionObject3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "mouse_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "mouse_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "mouse_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_collision_object3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "disable_mode"),
        JS_NewCFunction(ctx, collision_object3d_class_get_disable_mode, "get_disable_mode", 0),
        JS_NewCFunction(ctx, collision_object3d_class_set_disable_mode, "set_disable_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_layer"),
        JS_NewCFunction(ctx, collision_object3d_class_get_collision_layer, "get_collision_layer", 0),
        JS_NewCFunction(ctx, collision_object3d_class_set_collision_layer, "set_collision_layer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, collision_object3d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, collision_object3d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_priority"),
        JS_NewCFunction(ctx, collision_object3d_class_get_collision_priority, "get_collision_priority", 0),
        JS_NewCFunction(ctx, collision_object3d_class_set_collision_priority, "set_collision_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_ray_pickable"),
        JS_NewCFunction(ctx, collision_object3d_class_is_ray_pickable, "is_ray_pickable", 0),
        JS_NewCFunction(ctx, collision_object3d_class_set_ray_pickable, "set_ray_pickable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_capture_on_drag"),
        JS_NewCFunction(ctx, collision_object3d_class_get_capture_input_on_drag, "get_capture_input_on_drag", 0),
        JS_NewCFunction(ctx, collision_object3d_class_set_capture_input_on_drag, "set_capture_input_on_drag", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "input_event"),
		JS_NewCFunction(ctx, collision_object3d_class_get_input_event_signal, "get_input_event_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "mouse_entered"),
		JS_NewCFunction(ctx, collision_object3d_class_get_mouse_entered_signal, "get_mouse_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "mouse_exited"),
		JS_NewCFunction(ctx, collision_object3d_class_get_mouse_exited_signal, "get_mouse_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_collision_object3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue DisableMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DisableMode_obj, "DISABLE_MODE_REMOVE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DisableMode_obj, "DISABLE_MODE_MAKE_STATIC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DisableMode_obj, "DISABLE_MODE_KEEP_ACTIVE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DisableMode", DisableMode_obj);
}

static int js_collision_object3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CollisionObject3D"] = class_id;
	classes_by_id[class_id] = "CollisionObject3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &collision_object3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_collision_object3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, collision_object3d_class_proto_funcs, _countof(collision_object3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, collision_object3d_class_constructor, "CollisionObject3D", 0, JS_CFUNC_constructor, 0);
	define_collision_object3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CollisionObject3D", ctor);
	ctor_list["CollisionObject3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_collision_object3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_collision_object3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CollisionObject3D");
	return m;
}

JSModuleDef *js_init_collision_object3d_module(JSContext *ctx) {
	return _js_init_collision_object3d_module(ctx, "@godot/classes/collision_object3d");
}

void __register_collision_object3d() {
	js_init_collision_object3d_module(js_context());
}

void register_collision_object3d() {
	__register_collision_object3d();
}