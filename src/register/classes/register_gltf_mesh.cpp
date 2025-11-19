#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/importer_mesh.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_mesh.hpp>
using namespace godot;

static void gltf_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef gltf_mesh_class_def = {
    "GLTFMesh",
    gltf_mesh_class_finalizer
};

static JSValue gltf_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_mesh_class_get_original_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFMesh::get_original_name, ctx, this_val, argc, argv);
}
static JSValue gltf_mesh_class_set_original_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFMesh::set_original_name, ctx, this_val, argc, argv);
};
static JSValue gltf_mesh_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFMesh::get_mesh, ctx, this_val, argc, argv);
}
static JSValue gltf_mesh_class_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFMesh::set_mesh, ctx, this_val, argc, argv);
};
static JSValue gltf_mesh_class_get_blend_weights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat32Array> *proxy = memnew(ObjectProxy<PackedFloat32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat32Array {
		GLTFMesh *obj = static_cast<GLTFMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_blend_weights();
	};
	proxy->setter = [this_val](const PackedFloat32Array &value) -> void {
		GLTFMesh *js_proxy = static_cast<GLTFMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_blend_weights(PackedFloat32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_mesh_class_set_blend_weights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFMesh::set_blend_weights, ctx, this_val, argc, argv);
};
static JSValue gltf_mesh_class_get_instance_materials(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFMesh::get_instance_materials, ctx, this_val, argc, argv);
}
static JSValue gltf_mesh_class_set_instance_materials(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFMesh::set_instance_materials, ctx, this_val, argc, argv);
};
static JSValue gltf_mesh_class_get_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFMesh::get_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_mesh_class_set_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFMesh::set_additional_data, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_original_name", 0, &gltf_mesh_class_get_original_name),
	JS_CFUNC_DEF("set_original_name", 1, &gltf_mesh_class_set_original_name),
	JS_CFUNC_DEF("get_mesh", 0, &gltf_mesh_class_get_mesh),
	JS_CFUNC_DEF("set_mesh", 1, &gltf_mesh_class_set_mesh),
	JS_CFUNC_DEF("get_blend_weights", 0, &gltf_mesh_class_get_blend_weights),
	JS_CFUNC_DEF("set_blend_weights", 1, &gltf_mesh_class_set_blend_weights),
	JS_CFUNC_DEF("get_instance_materials", 0, &gltf_mesh_class_get_instance_materials),
	JS_CFUNC_DEF("set_instance_materials", 1, &gltf_mesh_class_set_instance_materials),
	JS_CFUNC_DEF("get_additional_data", 1, &gltf_mesh_class_get_additional_data),
	JS_CFUNC_DEF("set_additional_data", 2, &gltf_mesh_class_set_additional_data),
};




static void define_gltf_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "original_name"),
        JS_NewCFunction(ctx, gltf_mesh_class_get_original_name, "get_original_name", 0),
        JS_NewCFunction(ctx, gltf_mesh_class_set_original_name, "set_original_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh"),
        JS_NewCFunction(ctx, gltf_mesh_class_get_mesh, "get_mesh", 0),
        JS_NewCFunction(ctx, gltf_mesh_class_set_mesh, "set_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_weights"),
        JS_NewCFunction(ctx, gltf_mesh_class_get_blend_weights, "get_blend_weights", 0),
        JS_NewCFunction(ctx, gltf_mesh_class_set_blend_weights, "set_blend_weights", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "instance_materials"),
        JS_NewCFunction(ctx, gltf_mesh_class_get_instance_materials, "get_instance_materials", 0),
        JS_NewCFunction(ctx, gltf_mesh_class_set_instance_materials, "set_instance_materials", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFMesh"] = class_id;
	classes_by_id[class_id] = "GLTFMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_mesh_class_proto_funcs, _countof(gltf_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_mesh_class_constructor, "GLTFMesh", 0, JS_CFUNC_constructor, 0);
	define_gltf_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFMesh");
	return m;
}

JSModuleDef *js_init_gltf_mesh_module(JSContext *ctx) {
	return _js_init_gltf_mesh_module(ctx, "@godot/classes/gltf_mesh");
}

void __register_gltf_mesh() {
	js_init_gltf_mesh_module(js_context());
}

void register_gltf_mesh() {
	__register_gltf_mesh();
}