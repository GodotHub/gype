#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/concave_polygon_shape3d.hpp>
#include <godot_cpp/classes/convex_polygon_shape3d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/triangle_mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/mesh.hpp>
using namespace godot;

static void mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Mesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef mesh_class_def = {
    "Mesh",
    mesh_class_finalizer
};

static JSValue mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Mesh"];
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
        instance = memnew(Mesh);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue mesh_class_set_lightmap_size_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Mesh::set_lightmap_size_hint, ctx, this_val, argc, argv);
};
static JSValue mesh_class_get_lightmap_size_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Mesh *obj = static_cast<Mesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_lightmap_size_hint();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Mesh *js_proxy = static_cast<Mesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_lightmap_size_hint(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue mesh_class_get_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::get_aabb, ctx, this_val, argc, argv);
};
static JSValue mesh_class_get_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::get_faces, ctx, this_val, argc, argv);
};
static JSValue mesh_class_get_surface_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::get_surface_count, ctx, this_val, argc, argv);
};
static JSValue mesh_class_surface_get_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::surface_get_arrays, ctx, this_val, argc, argv);
};
static JSValue mesh_class_surface_get_blend_shape_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::surface_get_blend_shape_arrays, ctx, this_val, argc, argv);
};
static JSValue mesh_class_surface_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Mesh::surface_set_material, ctx, this_val, argc, argv);
};
static JSValue mesh_class_surface_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::surface_get_material, ctx, this_val, argc, argv);
};
static JSValue mesh_class_create_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::create_placeholder, ctx, this_val, argc, argv);
};
static JSValue mesh_class_create_trimesh_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::create_trimesh_shape, ctx, this_val, argc, argv);
};
static JSValue mesh_class_create_convex_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::create_convex_shape, ctx, this_val, argc, argv);
};
static JSValue mesh_class_create_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::create_outline, ctx, this_val, argc, argv);
};
static JSValue mesh_class_generate_triangle_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Mesh::generate_triangle_mesh, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_lightmap_size_hint", 1, &mesh_class_set_lightmap_size_hint),
	JS_CFUNC_DEF("get_lightmap_size_hint", 0, &mesh_class_get_lightmap_size_hint),
	JS_CFUNC_DEF("get_aabb", 0, &mesh_class_get_aabb),
	JS_CFUNC_DEF("get_faces", 0, &mesh_class_get_faces),
	JS_CFUNC_DEF("get_surface_count", 0, &mesh_class_get_surface_count),
	JS_CFUNC_DEF("surface_get_arrays", 1, &mesh_class_surface_get_arrays),
	JS_CFUNC_DEF("surface_get_blend_shape_arrays", 1, &mesh_class_surface_get_blend_shape_arrays),
	JS_CFUNC_DEF("surface_set_material", 2, &mesh_class_surface_set_material),
	JS_CFUNC_DEF("surface_get_material", 1, &mesh_class_surface_get_material),
	JS_CFUNC_DEF("create_placeholder", 0, &mesh_class_create_placeholder),
	JS_CFUNC_DEF("create_trimesh_shape", 0, &mesh_class_create_trimesh_shape),
	JS_CFUNC_DEF("create_convex_shape", 2, &mesh_class_create_convex_shape),
	JS_CFUNC_DEF("create_outline", 1, &mesh_class_create_outline),
	JS_CFUNC_DEF("generate_triangle_mesh", 0, &mesh_class_generate_triangle_mesh),
};




static void define_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lightmap_size_hint"),
        JS_NewCFunction(ctx, mesh_class_get_lightmap_size_hint, "get_lightmap_size_hint", 0),
        JS_NewCFunction(ctx, mesh_class_set_lightmap_size_hint, "set_lightmap_size_hint", 1),
        JS_PROP_GETSET
    );
}

static void define_mesh_enum(JSContext *ctx, JSValue ctor) {
	JSValue PrimitiveType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PrimitiveType_obj, "PRIMITIVE_POINTS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PrimitiveType_obj, "PRIMITIVE_LINES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PrimitiveType_obj, "PRIMITIVE_LINE_STRIP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PrimitiveType_obj, "PRIMITIVE_TRIANGLES", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, PrimitiveType_obj, "PRIMITIVE_TRIANGLE_STRIP", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "PrimitiveType", PrimitiveType_obj);
	JSValue ArrayType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_VERTEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_NORMAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_TANGENT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_COLOR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_TEX_UV", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_TEX_UV2", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_CUSTOM0", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_CUSTOM1", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_CUSTOM2", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_CUSTOM3", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_BONES", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_WEIGHTS", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_INDEX", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, ArrayType_obj, "ARRAY_MAX", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ctor, "ArrayType", ArrayType_obj);
	JSValue ArrayCustomFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RGBA8_UNORM", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RGBA8_SNORM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RG_HALF", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RGBA_HALF", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_R_FLOAT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RG_FLOAT", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RGB_FLOAT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_RGBA_FLOAT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ArrayCustomFormat_obj, "ARRAY_CUSTOM_MAX", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "ArrayCustomFormat", ArrayCustomFormat_obj);
	JSValue ArrayFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_VERTEX", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_NORMAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_TANGENT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_COLOR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_TEX_UV", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_TEX_UV2", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM0", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM1", JS_NewInt64(ctx, 128));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM2", JS_NewInt64(ctx, 256));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM3", JS_NewInt64(ctx, 512));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_BONES", JS_NewInt64(ctx, 1024));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_WEIGHTS", JS_NewInt64(ctx, 2048));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_INDEX", JS_NewInt64(ctx, 4096));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_BLEND_SHAPE_MASK", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM_BASE", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM_BITS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM0_SHIFT", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM1_SHIFT", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM2_SHIFT", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM3_SHIFT", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FORMAT_CUSTOM_MASK", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_COMPRESS_FLAGS_BASE", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FLAG_USE_2D_VERTICES", JS_NewInt64(ctx, 33554432));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FLAG_USE_DYNAMIC_UPDATE", JS_NewInt64(ctx, 67108864));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FLAG_USE_8_BONE_WEIGHTS", JS_NewInt64(ctx, 134217728));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FLAG_USES_EMPTY_VERTEX_ARRAY", JS_NewInt64(ctx, 268435456));
	JS_SetPropertyStr(ctx, ArrayFormat_obj, "ARRAY_FLAG_COMPRESS_ATTRIBUTES", JS_NewInt64(ctx, 536870912));
	JS_SetPropertyStr(ctx, ctor, "ArrayFormat", ArrayFormat_obj);
	JSValue BlendShapeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendShapeMode_obj, "BLEND_SHAPE_MODE_NORMALIZED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendShapeMode_obj, "BLEND_SHAPE_MODE_RELATIVE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "BlendShapeMode", BlendShapeMode_obj);
}

static int js_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Mesh"] = class_id;
	classes_by_id[class_id] = "Mesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, mesh_class_proto_funcs, _countof(mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, mesh_class_constructor, "Mesh", 0, JS_CFUNC_constructor, 0);
	define_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Mesh", ctor);
	ctor_list["Mesh"] = ctor;

	return 0;
}

JSModuleDef *_js_init_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Mesh");
	return m;
}

JSModuleDef *js_init_mesh_module(JSContext *ctx) {
	return _js_init_mesh_module(ctx, "@godot/classes/mesh");
}

void __register_mesh() {
	js_init_mesh_module(js_context());
}

void register_mesh() {
	__register_mesh();
}