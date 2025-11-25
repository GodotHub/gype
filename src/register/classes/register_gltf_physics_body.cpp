#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/collision_object3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_physics_body.hpp>
using namespace godot;

static void gltf_physics_body_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFPhysicsBody"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_physics_body_class_def = {
    "GLTFPhysicsBody",
    gltf_physics_body_class_finalizer
};

static JSValue gltf_physics_body_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFPhysicsBody"];
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
        instance = memnew(GLTFPhysicsBody);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_physics_body_class_to_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsBody::to_node, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_to_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsBody::to_dictionary, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_body_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsBody::get_body_type, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_body_class_set_body_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_body_type, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsBody::get_mass, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_body_class_set_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_mass, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFPhysicsBody *obj = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_linear_velocity();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFPhysicsBody *js_proxy = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_linear_velocity(value);
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
static JSValue gltf_physics_body_class_set_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFPhysicsBody *obj = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_angular_velocity();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFPhysicsBody *js_proxy = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_angular_velocity(value);
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
static JSValue gltf_physics_body_class_set_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_center_of_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFPhysicsBody *obj = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_center_of_mass();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFPhysicsBody *js_proxy = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_center_of_mass(value);
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
static JSValue gltf_physics_body_class_set_center_of_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_center_of_mass, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_inertia_diagonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFPhysicsBody *obj = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_inertia_diagonal();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFPhysicsBody *js_proxy = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_inertia_diagonal(value);
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
static JSValue gltf_physics_body_class_set_inertia_diagonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_inertia_diagonal, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_inertia_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Quaternion> *proxy = memnew(ObjectProxy<Quaternion>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Quaternion {
		GLTFPhysicsBody *obj = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_inertia_orientation();
	};
	proxy->setter = [this_val](const Quaternion &value) -> void {
		GLTFPhysicsBody *js_proxy = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_inertia_orientation(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["QuaternionProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "QuaternionProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_physics_body_class_set_inertia_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_inertia_orientation, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_get_inertia_tensor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Basis> *proxy = memnew(ObjectProxy<Basis>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Basis {
		GLTFPhysicsBody *obj = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_inertia_tensor();
	};
	proxy->setter = [this_val](const Basis &value) -> void {
		GLTFPhysicsBody *js_proxy = static_cast<GLTFPhysicsBody *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_inertia_tensor(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["BasisProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "BasisProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_physics_body_class_set_inertia_tensor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsBody::set_inertia_tensor, ctx, this_val, argc, argv);
};


static JSValue gltf_physics_body_class_from_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFPhysicsBody::from_node, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_body_class_from_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFPhysicsBody::from_dictionary, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gltf_physics_body_class_proto_funcs[] = {
	JS_CFUNC_DEF("to_node", 0, &gltf_physics_body_class_to_node),
	JS_CFUNC_DEF("to_dictionary", 0, &gltf_physics_body_class_to_dictionary),
	JS_CFUNC_DEF("get_body_type", 0, &gltf_physics_body_class_get_body_type),
	JS_CFUNC_DEF("set_body_type", 1, &gltf_physics_body_class_set_body_type),
	JS_CFUNC_DEF("get_mass", 0, &gltf_physics_body_class_get_mass),
	JS_CFUNC_DEF("set_mass", 1, &gltf_physics_body_class_set_mass),
	JS_CFUNC_DEF("get_linear_velocity", 0, &gltf_physics_body_class_get_linear_velocity),
	JS_CFUNC_DEF("set_linear_velocity", 1, &gltf_physics_body_class_set_linear_velocity),
	JS_CFUNC_DEF("get_angular_velocity", 0, &gltf_physics_body_class_get_angular_velocity),
	JS_CFUNC_DEF("set_angular_velocity", 1, &gltf_physics_body_class_set_angular_velocity),
	JS_CFUNC_DEF("get_center_of_mass", 0, &gltf_physics_body_class_get_center_of_mass),
	JS_CFUNC_DEF("set_center_of_mass", 1, &gltf_physics_body_class_set_center_of_mass),
	JS_CFUNC_DEF("get_inertia_diagonal", 0, &gltf_physics_body_class_get_inertia_diagonal),
	JS_CFUNC_DEF("set_inertia_diagonal", 1, &gltf_physics_body_class_set_inertia_diagonal),
	JS_CFUNC_DEF("get_inertia_orientation", 0, &gltf_physics_body_class_get_inertia_orientation),
	JS_CFUNC_DEF("set_inertia_orientation", 1, &gltf_physics_body_class_set_inertia_orientation),
	JS_CFUNC_DEF("get_inertia_tensor", 0, &gltf_physics_body_class_get_inertia_tensor),
	JS_CFUNC_DEF("set_inertia_tensor", 1, &gltf_physics_body_class_set_inertia_tensor),
};

static const JSCFunctionListEntry gltf_physics_body_class_static_funcs[] = {
	JS_CFUNC_DEF("from_node", 1, &gltf_physics_body_class_from_node),
	JS_CFUNC_DEF("from_dictionary", 1, &gltf_physics_body_class_from_dictionary),
};



static void define_gltf_physics_body_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "body_type"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_body_type, "get_body_type", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_body_type, "set_body_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mass"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_mass, "get_mass", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_mass, "set_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_velocity"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_linear_velocity, "get_linear_velocity", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_linear_velocity, "set_linear_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_angular_velocity, "get_angular_velocity", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_angular_velocity, "set_angular_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_of_mass"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_center_of_mass, "get_center_of_mass", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_center_of_mass, "set_center_of_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inertia_diagonal"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_inertia_diagonal, "get_inertia_diagonal", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_inertia_diagonal, "set_inertia_diagonal", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inertia_orientation"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_inertia_orientation, "get_inertia_orientation", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_inertia_orientation, "set_inertia_orientation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inertia_tensor"),
        JS_NewCFunction(ctx, gltf_physics_body_class_get_inertia_tensor, "get_inertia_tensor", 0),
        JS_NewCFunction(ctx, gltf_physics_body_class_set_inertia_tensor, "set_inertia_tensor", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_physics_body_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_physics_body_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFPhysicsBody"] = class_id;
	classes_by_id[class_id] = "GLTFPhysicsBody";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_physics_body_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_physics_body_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_physics_body_class_proto_funcs, _countof(gltf_physics_body_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_physics_body_class_constructor, "GLTFPhysicsBody", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, gltf_physics_body_class_static_funcs, _countof(gltf_physics_body_class_static_funcs));
	define_gltf_physics_body_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFPhysicsBody", ctor);
	ctor_list["GLTFPhysicsBody"] = ctor;

	return 0;
}

JSModuleDef *_js_init_gltf_physics_body_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_physics_body_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFPhysicsBody");
	return m;
}

JSModuleDef *js_init_gltf_physics_body_module(JSContext *ctx) {
	return _js_init_gltf_physics_body_module(ctx, "@godot/classes/gltf_physics_body");
}

void __register_gltf_physics_body() {
	js_init_gltf_physics_body_module(js_context());
}

void register_gltf_physics_body() {
	__register_gltf_physics_body();
}