#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters3d.hpp>
using namespace godot;

static void physics_shape_query_parameters3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsShapeQueryParameters3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_shape_query_parameters3d_class_def = {
    "PhysicsShapeQueryParameters3D",
    physics_shape_query_parameters3d_class_finalizer
};

static JSValue physics_shape_query_parameters3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsShapeQueryParameters3D"];
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
        instance = memnew(PhysicsShapeQueryParameters3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_shape_query_parameters3d_class_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_shape, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsShapeQueryParameters3D::get_shape, ctx, this_val, argc, argv);
}
static JSValue physics_shape_query_parameters3d_class_set_shape_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_shape_rid, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_shape_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		PhysicsShapeQueryParameters3D *obj = static_cast<PhysicsShapeQueryParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shape_rid();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		PhysicsShapeQueryParameters3D *js_proxy = static_cast<PhysicsShapeQueryParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shape_rid(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_shape_query_parameters3d_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_transform, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		PhysicsShapeQueryParameters3D *obj = static_cast<PhysicsShapeQueryParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transform();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		PhysicsShapeQueryParameters3D *js_proxy = static_cast<PhysicsShapeQueryParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_transform(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform3DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform3DProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_shape_query_parameters3d_class_set_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_motion, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		PhysicsShapeQueryParameters3D *obj = static_cast<PhysicsShapeQueryParameters3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_motion();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		PhysicsShapeQueryParameters3D *js_proxy = static_cast<PhysicsShapeQueryParameters3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_motion(value);
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
static JSValue physics_shape_query_parameters3d_class_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_margin, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsShapeQueryParameters3D::get_margin, ctx, this_val, argc, argv);
}
static JSValue physics_shape_query_parameters3d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsShapeQueryParameters3D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue physics_shape_query_parameters3d_class_set_exclude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_exclude, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_get_exclude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsShapeQueryParameters3D::get_exclude, ctx, this_val, argc, argv);
}
static JSValue physics_shape_query_parameters3d_class_set_collide_with_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_collide_with_bodies, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_is_collide_with_bodies_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsShapeQueryParameters3D::is_collide_with_bodies_enabled, ctx, this_val, argc, argv);
}
static JSValue physics_shape_query_parameters3d_class_set_collide_with_areas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsShapeQueryParameters3D::set_collide_with_areas, ctx, this_val, argc, argv);
};
static JSValue physics_shape_query_parameters3d_class_is_collide_with_areas_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsShapeQueryParameters3D::is_collide_with_areas_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry physics_shape_query_parameters3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_shape", 1, &physics_shape_query_parameters3d_class_set_shape),
	JS_CFUNC_DEF("get_shape", 0, &physics_shape_query_parameters3d_class_get_shape),
	JS_CFUNC_DEF("set_shape_rid", 1, &physics_shape_query_parameters3d_class_set_shape_rid),
	JS_CFUNC_DEF("get_shape_rid", 0, &physics_shape_query_parameters3d_class_get_shape_rid),
	JS_CFUNC_DEF("set_transform", 1, &physics_shape_query_parameters3d_class_set_transform),
	JS_CFUNC_DEF("get_transform", 0, &physics_shape_query_parameters3d_class_get_transform),
	JS_CFUNC_DEF("set_motion", 1, &physics_shape_query_parameters3d_class_set_motion),
	JS_CFUNC_DEF("get_motion", 0, &physics_shape_query_parameters3d_class_get_motion),
	JS_CFUNC_DEF("set_margin", 1, &physics_shape_query_parameters3d_class_set_margin),
	JS_CFUNC_DEF("get_margin", 0, &physics_shape_query_parameters3d_class_get_margin),
	JS_CFUNC_DEF("set_collision_mask", 1, &physics_shape_query_parameters3d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &physics_shape_query_parameters3d_class_get_collision_mask),
	JS_CFUNC_DEF("set_exclude", 1, &physics_shape_query_parameters3d_class_set_exclude),
	JS_CFUNC_DEF("get_exclude", 0, &physics_shape_query_parameters3d_class_get_exclude),
	JS_CFUNC_DEF("set_collide_with_bodies", 1, &physics_shape_query_parameters3d_class_set_collide_with_bodies),
	JS_CFUNC_DEF("is_collide_with_bodies_enabled", 0, &physics_shape_query_parameters3d_class_is_collide_with_bodies_enabled),
	JS_CFUNC_DEF("set_collide_with_areas", 1, &physics_shape_query_parameters3d_class_set_collide_with_areas),
	JS_CFUNC_DEF("is_collide_with_areas_enabled", 0, &physics_shape_query_parameters3d_class_is_collide_with_areas_enabled),
};




static void define_physics_shape_query_parameters3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_exclude, "get_exclude", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_exclude, "set_exclude", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margin"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_margin, "get_margin", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_margin, "set_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_motion, "get_motion", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_motion, "set_motion", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_shape, "get_shape", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_shape, "set_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape_rid"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_shape_rid, "get_shape_rid", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_shape_rid, "set_shape_rid", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_bodies"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_is_collide_with_bodies_enabled, "is_collide_with_bodies_enabled", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_collide_with_bodies, "set_collide_with_bodies", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collide_with_areas"),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_is_collide_with_areas_enabled, "is_collide_with_areas_enabled", 0),
        JS_NewCFunction(ctx, physics_shape_query_parameters3d_class_set_collide_with_areas, "set_collide_with_areas", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_shape_query_parameters3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_shape_query_parameters3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsShapeQueryParameters3D"] = class_id;
	classes_by_id[class_id] = "PhysicsShapeQueryParameters3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_shape_query_parameters3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_shape_query_parameters3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_shape_query_parameters3d_class_proto_funcs, _countof(physics_shape_query_parameters3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_shape_query_parameters3d_class_constructor, "PhysicsShapeQueryParameters3D", 0, JS_CFUNC_constructor, 0);
	define_physics_shape_query_parameters3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsShapeQueryParameters3D", ctor);
	ctor_list["PhysicsShapeQueryParameters3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_physics_shape_query_parameters3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_shape_query_parameters3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsShapeQueryParameters3D");
	return m;
}

JSModuleDef *js_init_physics_shape_query_parameters3d_module(JSContext *ctx) {
	return _js_init_physics_shape_query_parameters3d_module(ctx, "@godot/classes/physics_shape_query_parameters3d");
}

void __register_physics_shape_query_parameters3d() {
	js_init_physics_shape_query_parameters3d_module(js_context());
}

void register_physics_shape_query_parameters3d() {
	__register_physics_shape_query_parameters3d();
}