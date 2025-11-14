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
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/surface_tool.hpp>
using namespace godot;

static void surface_tool_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SurfaceTool"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef surface_tool_class_def = {
    "SurfaceTool",
    surface_tool_class_finalizer
};

static JSValue surface_tool_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SurfaceTool"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SurfaceTool *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SurfaceTool *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SurfaceTool);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue surface_tool_class_set_skin_weight_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_skin_weight_count, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_get_skin_weight_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SurfaceTool::get_skin_weight_count, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_custom_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_custom_format, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_get_custom_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SurfaceTool::get_custom_format, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::begin, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_add_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::add_vertex, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_color, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_normal, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_tangent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_tangent, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_uv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_uv, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_uv2, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_bones, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_weights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_weights, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_custom, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_smooth_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_smooth_group, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_add_triangle_fan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::add_triangle_fan, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_add_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::add_index, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::index, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_deindex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::deindex, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_generate_normals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::generate_normals, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_generate_tangents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::generate_tangents, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_optimize_indices_for_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::optimize_indices_for_cache, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_get_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SurfaceTool::get_aabb, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_generate_lod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SurfaceTool::generate_lod, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::set_material, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_get_primitive_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SurfaceTool::get_primitive_type, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::clear, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_create_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::create_from, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_create_from_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::create_from_arrays, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_create_from_blend_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::create_from_blend_shape, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_append_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SurfaceTool::append_from, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_commit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SurfaceTool::commit, ctx, this_val, argc, argv);
};
static JSValue surface_tool_class_commit_to_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SurfaceTool::commit_to_arrays, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry surface_tool_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_skin_weight_count", 1, &surface_tool_class_set_skin_weight_count),
	JS_CFUNC_DEF("get_skin_weight_count", 0, &surface_tool_class_get_skin_weight_count),
	JS_CFUNC_DEF("set_custom_format", 2, &surface_tool_class_set_custom_format),
	JS_CFUNC_DEF("get_custom_format", 1, &surface_tool_class_get_custom_format),
	JS_CFUNC_DEF("begin", 1, &surface_tool_class_begin),
	JS_CFUNC_DEF("add_vertex", 1, &surface_tool_class_add_vertex),
	JS_CFUNC_DEF("set_color", 1, &surface_tool_class_set_color),
	JS_CFUNC_DEF("set_normal", 1, &surface_tool_class_set_normal),
	JS_CFUNC_DEF("set_tangent", 1, &surface_tool_class_set_tangent),
	JS_CFUNC_DEF("set_uv", 1, &surface_tool_class_set_uv),
	JS_CFUNC_DEF("set_uv2", 1, &surface_tool_class_set_uv2),
	JS_CFUNC_DEF("set_bones", 1, &surface_tool_class_set_bones),
	JS_CFUNC_DEF("set_weights", 1, &surface_tool_class_set_weights),
	JS_CFUNC_DEF("set_custom", 2, &surface_tool_class_set_custom),
	JS_CFUNC_DEF("set_smooth_group", 1, &surface_tool_class_set_smooth_group),
	JS_CFUNC_DEF("add_triangle_fan", 6, &surface_tool_class_add_triangle_fan),
	JS_CFUNC_DEF("add_index", 1, &surface_tool_class_add_index),
	JS_CFUNC_DEF("index", 0, &surface_tool_class_index),
	JS_CFUNC_DEF("deindex", 0, &surface_tool_class_deindex),
	JS_CFUNC_DEF("generate_normals", 1, &surface_tool_class_generate_normals),
	JS_CFUNC_DEF("generate_tangents", 0, &surface_tool_class_generate_tangents),
	JS_CFUNC_DEF("optimize_indices_for_cache", 0, &surface_tool_class_optimize_indices_for_cache),
	JS_CFUNC_DEF("get_aabb", 0, &surface_tool_class_get_aabb),
	JS_CFUNC_DEF("generate_lod", 2, &surface_tool_class_generate_lod),
	JS_CFUNC_DEF("set_material", 1, &surface_tool_class_set_material),
	JS_CFUNC_DEF("get_primitive_type", 0, &surface_tool_class_get_primitive_type),
	JS_CFUNC_DEF("clear", 0, &surface_tool_class_clear),
	JS_CFUNC_DEF("create_from", 2, &surface_tool_class_create_from),
	JS_CFUNC_DEF("create_from_arrays", 2, &surface_tool_class_create_from_arrays),
	JS_CFUNC_DEF("create_from_blend_shape", 3, &surface_tool_class_create_from_blend_shape),
	JS_CFUNC_DEF("append_from", 3, &surface_tool_class_append_from),
	JS_CFUNC_DEF("commit", 2, &surface_tool_class_commit),
	JS_CFUNC_DEF("commit_to_arrays", 0, &surface_tool_class_commit_to_arrays),
};




static void define_surface_tool_property(JSContext *ctx, JSValue proto) {
}

static void define_surface_tool_enum(JSContext *ctx, JSValue proto) {
	JSValue CustomFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RGBA8_UNORM", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RGBA8_SNORM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RG_HALF", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RGBA_HALF", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_R_FLOAT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RG_FLOAT", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RGB_FLOAT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_RGBA_FLOAT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CustomFormat_obj, "CUSTOM_MAX", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, proto, "CustomFormat", CustomFormat_obj);
	JSValue SkinWeightCount_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SkinWeightCount_obj, "SKIN_4_WEIGHTS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SkinWeightCount_obj, "SKIN_8_WEIGHTS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "SkinWeightCount", SkinWeightCount_obj);
}

static int js_surface_tool_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SurfaceTool"] = class_id;
	classes_by_id[class_id] = "SurfaceTool";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &surface_tool_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_surface_tool_property(ctx, proto);
	define_surface_tool_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, surface_tool_class_proto_funcs, _countof(surface_tool_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, surface_tool_class_constructor, "SurfaceTool", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SurfaceTool", ctor);

	return 0;
}

JSModuleDef *_js_init_surface_tool_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_surface_tool_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SurfaceTool");
	return m;
}

JSModuleDef *js_init_surface_tool_module(JSContext *ctx) {
	return _js_init_surface_tool_module(ctx, "@godot/classes/surface_tool");
}

void __register_surface_tool() {
	js_init_surface_tool_module(js_context());
}

void register_surface_tool() {
	__register_surface_tool();
}