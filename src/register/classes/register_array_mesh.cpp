#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
using namespace godot;

static void array_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ArrayMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef array_mesh_class_def = {
    "ArrayMesh",
    array_mesh_class_finalizer
};

static JSValue array_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ArrayMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ArrayMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ArrayMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ArrayMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue array_mesh_class_add_blend_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::add_blend_shape, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_get_blend_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::get_blend_shape_count, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_get_blend_shape_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::get_blend_shape_name, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_set_blend_shape_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::set_blend_shape_name, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_clear_blend_shapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::clear_blend_shapes, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_set_blend_shape_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::set_blend_shape_mode, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_get_blend_shape_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::get_blend_shape_mode, ctx, this_val, argc, argv);
}
static JSValue array_mesh_class_add_surface_from_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::add_surface_from_arrays, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_clear_surfaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::clear_surfaces, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_remove(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::surface_remove, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_update_vertex_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::surface_update_vertex_region, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_update_attribute_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::surface_update_attribute_region, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_update_skin_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::surface_update_skin_region, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_get_array_len(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::surface_get_array_len, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_get_array_index_len(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::surface_get_array_index_len, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::surface_get_format, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_get_primitive_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::surface_get_primitive_type, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_find_by_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::surface_find_by_name, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_set_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::surface_set_name, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_surface_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::surface_get_name, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_regen_normal_maps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::regen_normal_maps, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_lightmap_unwrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ArrayMesh::lightmap_unwrap, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::set_custom_aabb, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_get_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<AABB> *proxy = memnew(ObjectProxy<AABB>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> AABB {
		ArrayMesh *obj = static_cast<ArrayMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_custom_aabb();
	};
	proxy->setter = [this_val](const AABB &value) -> void {
		ArrayMesh *js_proxy = static_cast<ArrayMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_custom_aabb(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["AABBProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "AABBProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue array_mesh_class_set_shadow_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ArrayMesh::set_shadow_mesh, ctx, this_val, argc, argv);
};
static JSValue array_mesh_class_get_shadow_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ArrayMesh::get_shadow_mesh, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry array_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_blend_shape", 1, &array_mesh_class_add_blend_shape),
	JS_CFUNC_DEF("get_blend_shape_count", 0, &array_mesh_class_get_blend_shape_count),
	JS_CFUNC_DEF("get_blend_shape_name", 1, &array_mesh_class_get_blend_shape_name),
	JS_CFUNC_DEF("set_blend_shape_name", 2, &array_mesh_class_set_blend_shape_name),
	JS_CFUNC_DEF("clear_blend_shapes", 0, &array_mesh_class_clear_blend_shapes),
	JS_CFUNC_DEF("set_blend_shape_mode", 1, &array_mesh_class_set_blend_shape_mode),
	JS_CFUNC_DEF("get_blend_shape_mode", 0, &array_mesh_class_get_blend_shape_mode),
	JS_CFUNC_DEF("add_surface_from_arrays", 5, &array_mesh_class_add_surface_from_arrays),
	JS_CFUNC_DEF("clear_surfaces", 0, &array_mesh_class_clear_surfaces),
	JS_CFUNC_DEF("surface_remove", 1, &array_mesh_class_surface_remove),
	JS_CFUNC_DEF("surface_update_vertex_region", 3, &array_mesh_class_surface_update_vertex_region),
	JS_CFUNC_DEF("surface_update_attribute_region", 3, &array_mesh_class_surface_update_attribute_region),
	JS_CFUNC_DEF("surface_update_skin_region", 3, &array_mesh_class_surface_update_skin_region),
	JS_CFUNC_DEF("surface_get_array_len", 1, &array_mesh_class_surface_get_array_len),
	JS_CFUNC_DEF("surface_get_array_index_len", 1, &array_mesh_class_surface_get_array_index_len),
	JS_CFUNC_DEF("surface_get_format", 1, &array_mesh_class_surface_get_format),
	JS_CFUNC_DEF("surface_get_primitive_type", 1, &array_mesh_class_surface_get_primitive_type),
	JS_CFUNC_DEF("surface_find_by_name", 1, &array_mesh_class_surface_find_by_name),
	JS_CFUNC_DEF("surface_set_name", 2, &array_mesh_class_surface_set_name),
	JS_CFUNC_DEF("surface_get_name", 1, &array_mesh_class_surface_get_name),
	JS_CFUNC_DEF("regen_normal_maps", 0, &array_mesh_class_regen_normal_maps),
	JS_CFUNC_DEF("lightmap_unwrap", 2, &array_mesh_class_lightmap_unwrap),
	JS_CFUNC_DEF("set_custom_aabb", 1, &array_mesh_class_set_custom_aabb),
	JS_CFUNC_DEF("get_custom_aabb", 0, &array_mesh_class_get_custom_aabb),
	JS_CFUNC_DEF("set_shadow_mesh", 1, &array_mesh_class_set_shadow_mesh),
	JS_CFUNC_DEF("get_shadow_mesh", 0, &array_mesh_class_get_shadow_mesh),
};




static void define_array_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_shape_mode"),
        JS_NewCFunction(ctx, array_mesh_class_get_blend_shape_mode, "get_blend_shape_mode", 0),
        JS_NewCFunction(ctx, array_mesh_class_set_blend_shape_mode, "set_blend_shape_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_aabb"),
        JS_NewCFunction(ctx, array_mesh_class_get_custom_aabb, "get_custom_aabb", 0),
        JS_NewCFunction(ctx, array_mesh_class_set_custom_aabb, "set_custom_aabb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_mesh"),
        JS_NewCFunction(ctx, array_mesh_class_get_shadow_mesh, "get_shadow_mesh", 0),
        JS_NewCFunction(ctx, array_mesh_class_set_shadow_mesh, "set_shadow_mesh", 1),
        JS_PROP_GETSET
    );
}

static void define_array_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_array_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ArrayMesh"] = class_id;
	classes_by_id[class_id] = "ArrayMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &array_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Mesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_array_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, array_mesh_class_proto_funcs, _countof(array_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, array_mesh_class_constructor, "ArrayMesh", 0, JS_CFUNC_constructor, 0);
	define_array_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ArrayMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_array_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_array_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ArrayMesh");
	return m;
}

JSModuleDef *js_init_array_mesh_module(JSContext *ctx) {
	return _js_init_array_mesh_module(ctx, "@godot/classes/array_mesh");
}

void __register_array_mesh() {
	js_init_array_mesh_module(js_context());
}

void register_array_mesh() {
	__register_array_mesh();
}