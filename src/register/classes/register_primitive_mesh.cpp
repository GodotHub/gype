#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/primitive_mesh.hpp>
using namespace godot;

static void primitive_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PrimitiveMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef primitive_mesh_class_def = {
    "PrimitiveMesh",
    primitive_mesh_class_finalizer
};

static JSValue primitive_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PrimitiveMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PrimitiveMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PrimitiveMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PrimitiveMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue primitive_mesh_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PrimitiveMesh::set_material, ctx, this_val, argc, argv);
};
static JSValue primitive_mesh_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PrimitiveMesh::get_material, ctx, this_val, argc, argv);
}
static JSValue primitive_mesh_class_get_mesh_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PrimitiveMesh::get_mesh_arrays, ctx, this_val, argc, argv);
};
static JSValue primitive_mesh_class_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PrimitiveMesh::set_custom_aabb, ctx, this_val, argc, argv);
};
static JSValue primitive_mesh_class_get_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<AABB> *proxy = memnew(ObjectProxy<AABB>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> AABB {
		PrimitiveMesh *obj = static_cast<PrimitiveMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_custom_aabb();
	};
	proxy->setter = [this_val](const AABB &value) -> void {
		PrimitiveMesh *js_proxy = static_cast<PrimitiveMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_custom_aabb(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["AABBProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "AABBProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue primitive_mesh_class_set_flip_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PrimitiveMesh::set_flip_faces, ctx, this_val, argc, argv);
};
static JSValue primitive_mesh_class_get_flip_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PrimitiveMesh::get_flip_faces, ctx, this_val, argc, argv);
}
static JSValue primitive_mesh_class_set_add_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PrimitiveMesh::set_add_uv2, ctx, this_val, argc, argv);
};
static JSValue primitive_mesh_class_get_add_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PrimitiveMesh::get_add_uv2, ctx, this_val, argc, argv);
}
static JSValue primitive_mesh_class_set_uv2_padding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PrimitiveMesh::set_uv2_padding, ctx, this_val, argc, argv);
};
static JSValue primitive_mesh_class_get_uv2_padding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PrimitiveMesh::get_uv2_padding, ctx, this_val, argc, argv);
}
static JSValue primitive_mesh_class_request_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PrimitiveMesh::request_update, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry primitive_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_material", 1, &primitive_mesh_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &primitive_mesh_class_get_material),
	JS_CFUNC_DEF("get_mesh_arrays", 0, &primitive_mesh_class_get_mesh_arrays),
	JS_CFUNC_DEF("set_custom_aabb", 1, &primitive_mesh_class_set_custom_aabb),
	JS_CFUNC_DEF("get_custom_aabb", 0, &primitive_mesh_class_get_custom_aabb),
	JS_CFUNC_DEF("set_flip_faces", 1, &primitive_mesh_class_set_flip_faces),
	JS_CFUNC_DEF("get_flip_faces", 0, &primitive_mesh_class_get_flip_faces),
	JS_CFUNC_DEF("set_add_uv2", 1, &primitive_mesh_class_set_add_uv2),
	JS_CFUNC_DEF("get_add_uv2", 0, &primitive_mesh_class_get_add_uv2),
	JS_CFUNC_DEF("set_uv2_padding", 1, &primitive_mesh_class_set_uv2_padding),
	JS_CFUNC_DEF("get_uv2_padding", 0, &primitive_mesh_class_get_uv2_padding),
	JS_CFUNC_DEF("request_update", 0, &primitive_mesh_class_request_update),
};




static void define_primitive_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, primitive_mesh_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, primitive_mesh_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_aabb"),
        JS_NewCFunction(ctx, primitive_mesh_class_get_custom_aabb, "get_custom_aabb", 0),
        JS_NewCFunction(ctx, primitive_mesh_class_set_custom_aabb, "set_custom_aabb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flip_faces"),
        JS_NewCFunction(ctx, primitive_mesh_class_get_flip_faces, "get_flip_faces", 0),
        JS_NewCFunction(ctx, primitive_mesh_class_set_flip_faces, "set_flip_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "add_uv2"),
        JS_NewCFunction(ctx, primitive_mesh_class_get_add_uv2, "get_add_uv2", 0),
        JS_NewCFunction(ctx, primitive_mesh_class_set_add_uv2, "set_add_uv2", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv2_padding"),
        JS_NewCFunction(ctx, primitive_mesh_class_get_uv2_padding, "get_uv2_padding", 0),
        JS_NewCFunction(ctx, primitive_mesh_class_set_uv2_padding, "set_uv2_padding", 1),
        JS_PROP_GETSET
    );
}

static void define_primitive_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_primitive_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PrimitiveMesh"] = class_id;
	classes_by_id[class_id] = "PrimitiveMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &primitive_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Mesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_primitive_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, primitive_mesh_class_proto_funcs, _countof(primitive_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, primitive_mesh_class_constructor, "PrimitiveMesh", 0, JS_CFUNC_constructor, 0);
	define_primitive_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PrimitiveMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_primitive_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_primitive_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PrimitiveMesh");
	return m;
}

JSModuleDef *js_init_primitive_mesh_module(JSContext *ctx) {
	return _js_init_primitive_mesh_module(ctx, "@godot/classes/primitive_mesh");
}

void __register_primitive_mesh() {
	js_init_primitive_mesh_module(js_context());
}

void register_primitive_mesh() {
	__register_primitive_mesh();
}