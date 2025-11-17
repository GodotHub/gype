#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/collision_shape3d.hpp>
#include <godot_cpp/classes/importer_mesh.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_physics_shape.hpp>
using namespace godot;

static void gltf_physics_shape_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFPhysicsShape"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_physics_shape_class_def = {
    "GLTFPhysicsShape",
    gltf_physics_shape_class_finalizer
};

static JSValue gltf_physics_shape_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFPhysicsShape"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFPhysicsShape *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFPhysicsShape *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFPhysicsShape);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_physics_shape_class_to_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFPhysicsShape::to_node, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_to_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFPhysicsShape::to_resource, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_to_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsShape::to_dictionary, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_shape_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		GLTFPhysicsShape *obj = static_cast<GLTFPhysicsShape *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shape_type();
	};
	proxy->setter = [this_val](const String &value) -> void {
		GLTFPhysicsShape *js_proxy = static_cast<GLTFPhysicsShape *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shape_type(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_physics_shape_class_set_shape_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_shape_type, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFPhysicsShape *obj = static_cast<GLTFPhysicsShape *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFPhysicsShape *js_proxy = static_cast<GLTFPhysicsShape *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_physics_shape_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_size, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsShape::get_radius, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_shape_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_radius, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsShape::get_height, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_shape_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_height, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_is_trigger(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsShape::get_is_trigger, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_shape_class_set_is_trigger(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_is_trigger, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_mesh_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsShape::get_mesh_index, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_shape_class_set_mesh_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_mesh_index, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_get_importer_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFPhysicsShape::get_importer_mesh, ctx, this_val, argc, argv);
}
static JSValue gltf_physics_shape_class_set_importer_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFPhysicsShape::set_importer_mesh, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_from_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFPhysicsShape::from_node, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_from_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFPhysicsShape::from_resource, ctx, this_val, argc, argv);
};
static JSValue gltf_physics_shape_class_from_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFPhysicsShape::from_dictionary, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gltf_physics_shape_class_proto_funcs[] = {
	JS_CFUNC_DEF("to_node", 1, &gltf_physics_shape_class_to_node),
	JS_CFUNC_DEF("to_resource", 1, &gltf_physics_shape_class_to_resource),
	JS_CFUNC_DEF("to_dictionary", 0, &gltf_physics_shape_class_to_dictionary),
	JS_CFUNC_DEF("get_shape_type", 0, &gltf_physics_shape_class_get_shape_type),
	JS_CFUNC_DEF("set_shape_type", 1, &gltf_physics_shape_class_set_shape_type),
	JS_CFUNC_DEF("get_size", 0, &gltf_physics_shape_class_get_size),
	JS_CFUNC_DEF("set_size", 1, &gltf_physics_shape_class_set_size),
	JS_CFUNC_DEF("get_radius", 0, &gltf_physics_shape_class_get_radius),
	JS_CFUNC_DEF("set_radius", 1, &gltf_physics_shape_class_set_radius),
	JS_CFUNC_DEF("get_height", 0, &gltf_physics_shape_class_get_height),
	JS_CFUNC_DEF("set_height", 1, &gltf_physics_shape_class_set_height),
	JS_CFUNC_DEF("get_is_trigger", 0, &gltf_physics_shape_class_get_is_trigger),
	JS_CFUNC_DEF("set_is_trigger", 1, &gltf_physics_shape_class_set_is_trigger),
	JS_CFUNC_DEF("get_mesh_index", 0, &gltf_physics_shape_class_get_mesh_index),
	JS_CFUNC_DEF("set_mesh_index", 1, &gltf_physics_shape_class_set_mesh_index),
	JS_CFUNC_DEF("get_importer_mesh", 0, &gltf_physics_shape_class_get_importer_mesh),
	JS_CFUNC_DEF("set_importer_mesh", 1, &gltf_physics_shape_class_set_importer_mesh),
};

static const JSCFunctionListEntry gltf_physics_shape_class_static_funcs[] = {
	JS_CFUNC_DEF("from_node", 1, &gltf_physics_shape_class_from_node),
	JS_CFUNC_DEF("from_resource", 1, &gltf_physics_shape_class_from_resource),
	JS_CFUNC_DEF("from_dictionary", 1, &gltf_physics_shape_class_from_dictionary),
};



static void define_gltf_physics_shape_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape_type"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_shape_type, "get_shape_type", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_shape_type, "set_shape_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "is_trigger"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_is_trigger, "get_is_trigger", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_is_trigger, "set_is_trigger", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh_index"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_mesh_index, "get_mesh_index", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_mesh_index, "set_mesh_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "importer_mesh"),
        JS_NewCFunction(ctx, gltf_physics_shape_class_get_importer_mesh, "get_importer_mesh", 0),
        JS_NewCFunction(ctx, gltf_physics_shape_class_set_importer_mesh, "set_importer_mesh", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_physics_shape_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_physics_shape_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFPhysicsShape"] = class_id;
	classes_by_id[class_id] = "GLTFPhysicsShape";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_physics_shape_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_physics_shape_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_physics_shape_class_proto_funcs, _countof(gltf_physics_shape_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_physics_shape_class_constructor, "GLTFPhysicsShape", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, gltf_physics_shape_class_static_funcs, _countof(gltf_physics_shape_class_static_funcs));
	define_gltf_physics_shape_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFPhysicsShape", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_physics_shape_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_physics_shape_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFPhysicsShape");
	return m;
}

JSModuleDef *js_init_gltf_physics_shape_module(JSContext *ctx) {
	return _js_init_gltf_physics_shape_module(ctx, "@godot/classes/gltf_physics_shape");
}

void __register_gltf_physics_shape() {
	js_init_gltf_physics_shape_module(js_context());
}

void register_gltf_physics_shape() {
	__register_gltf_physics_shape();
}