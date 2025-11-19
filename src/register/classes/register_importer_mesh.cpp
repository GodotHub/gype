#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/importer_mesh.hpp>
using namespace godot;

static void importer_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ImporterMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef importer_mesh_class_def = {
    "ImporterMesh",
    importer_mesh_class_finalizer
};

static JSValue importer_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ImporterMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ImporterMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ImporterMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ImporterMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue importer_mesh_class_add_blend_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::add_blend_shape, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_blend_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_blend_shape_count, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_blend_shape_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_blend_shape_name, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_set_blend_shape_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::set_blend_shape_mode, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_blend_shape_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_blend_shape_mode, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_add_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::add_surface, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_count, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_primitive_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ImporterMesh::get_surface_primitive_type, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_name, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_arrays, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_blend_shape_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_blend_shape_arrays, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_lod_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_lod_count, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_lod_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_lod_size, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_lod_indices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_lod_indices, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_material, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_surface_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_surface_format, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_set_surface_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::set_surface_name, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_set_surface_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::set_surface_material, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_generate_lods(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::generate_lods, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ImporterMesh::get_mesh, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::clear, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_set_lightmap_size_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMesh::set_lightmap_size_hint, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_class_get_lightmap_size_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMesh::get_lightmap_size_hint, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry importer_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_blend_shape", 1, &importer_mesh_class_add_blend_shape),
	JS_CFUNC_DEF("get_blend_shape_count", 0, &importer_mesh_class_get_blend_shape_count),
	JS_CFUNC_DEF("get_blend_shape_name", 1, &importer_mesh_class_get_blend_shape_name),
	JS_CFUNC_DEF("set_blend_shape_mode", 1, &importer_mesh_class_set_blend_shape_mode),
	JS_CFUNC_DEF("get_blend_shape_mode", 0, &importer_mesh_class_get_blend_shape_mode),
	JS_CFUNC_DEF("add_surface", 7, &importer_mesh_class_add_surface),
	JS_CFUNC_DEF("get_surface_count", 0, &importer_mesh_class_get_surface_count),
	JS_CFUNC_DEF("get_surface_primitive_type", 1, &importer_mesh_class_get_surface_primitive_type),
	JS_CFUNC_DEF("get_surface_name", 1, &importer_mesh_class_get_surface_name),
	JS_CFUNC_DEF("get_surface_arrays", 1, &importer_mesh_class_get_surface_arrays),
	JS_CFUNC_DEF("get_surface_blend_shape_arrays", 2, &importer_mesh_class_get_surface_blend_shape_arrays),
	JS_CFUNC_DEF("get_surface_lod_count", 1, &importer_mesh_class_get_surface_lod_count),
	JS_CFUNC_DEF("get_surface_lod_size", 2, &importer_mesh_class_get_surface_lod_size),
	JS_CFUNC_DEF("get_surface_lod_indices", 2, &importer_mesh_class_get_surface_lod_indices),
	JS_CFUNC_DEF("get_surface_material", 1, &importer_mesh_class_get_surface_material),
	JS_CFUNC_DEF("get_surface_format", 1, &importer_mesh_class_get_surface_format),
	JS_CFUNC_DEF("set_surface_name", 2, &importer_mesh_class_set_surface_name),
	JS_CFUNC_DEF("set_surface_material", 2, &importer_mesh_class_set_surface_material),
	JS_CFUNC_DEF("generate_lods", 3, &importer_mesh_class_generate_lods),
	JS_CFUNC_DEF("get_mesh", 1, &importer_mesh_class_get_mesh),
	JS_CFUNC_DEF("clear", 0, &importer_mesh_class_clear),
	JS_CFUNC_DEF("set_lightmap_size_hint", 1, &importer_mesh_class_set_lightmap_size_hint),
	JS_CFUNC_DEF("get_lightmap_size_hint", 0, &importer_mesh_class_get_lightmap_size_hint),
};




static void define_importer_mesh_property(JSContext *ctx, JSValue proto) {
}

static void define_importer_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_importer_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ImporterMesh"] = class_id;
	classes_by_id[class_id] = "ImporterMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &importer_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_importer_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, importer_mesh_class_proto_funcs, _countof(importer_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, importer_mesh_class_constructor, "ImporterMesh", 0, JS_CFUNC_constructor, 0);
	define_importer_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ImporterMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_importer_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_importer_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ImporterMesh");
	return m;
}

JSModuleDef *js_init_importer_mesh_module(JSContext *ctx) {
	return _js_init_importer_mesh_module(ctx, "@godot/classes/importer_mesh");
}

void __register_importer_mesh() {
	js_init_importer_mesh_module(js_context());
}

void register_importer_mesh() {
	__register_importer_mesh();
}