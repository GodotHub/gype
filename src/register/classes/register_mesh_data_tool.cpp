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
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/mesh_data_tool.hpp>
using namespace godot;

static void mesh_data_tool_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MeshDataTool"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef mesh_data_tool_class_def = {
    "MeshDataTool",
    mesh_data_tool_class_finalizer
};

static JSValue mesh_data_tool_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MeshDataTool"];
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
        instance = memnew(MeshDataTool);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue mesh_data_tool_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::clear, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_create_from_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MeshDataTool::create_from_surface, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_commit_to_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MeshDataTool::commit_to_surface, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_format, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_count, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_edge_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_edge_count, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_face_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_face_count, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_normal, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_normal, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_tangent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_tangent, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_tangent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_tangent, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_uv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_uv, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_uv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_uv, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_uv2, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_uv2, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_color, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_color, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_bones, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_bones, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_weights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_weights, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_weights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_weights, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_vertex_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_vertex_meta, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_meta, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_edges(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_edges, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_vertex_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_vertex_faces, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_edge_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_edge_vertex, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_edge_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_edge_faces, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_edge_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_edge_meta, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_edge_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_edge_meta, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_face_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_face_vertex, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_face_edge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_face_edge, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_face_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_face_meta, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_face_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_face_meta, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_face_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_face_normal, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshDataTool::set_material, ctx, this_val, argc, argv);
};
static JSValue mesh_data_tool_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshDataTool::get_material, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry mesh_data_tool_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &mesh_data_tool_class_clear),
	JS_CFUNC_DEF("create_from_surface", 2, &mesh_data_tool_class_create_from_surface),
	JS_CFUNC_DEF("commit_to_surface", 2, &mesh_data_tool_class_commit_to_surface),
	JS_CFUNC_DEF("get_format", 0, &mesh_data_tool_class_get_format),
	JS_CFUNC_DEF("get_vertex_count", 0, &mesh_data_tool_class_get_vertex_count),
	JS_CFUNC_DEF("get_edge_count", 0, &mesh_data_tool_class_get_edge_count),
	JS_CFUNC_DEF("get_face_count", 0, &mesh_data_tool_class_get_face_count),
	JS_CFUNC_DEF("set_vertex", 2, &mesh_data_tool_class_set_vertex),
	JS_CFUNC_DEF("get_vertex", 1, &mesh_data_tool_class_get_vertex),
	JS_CFUNC_DEF("set_vertex_normal", 2, &mesh_data_tool_class_set_vertex_normal),
	JS_CFUNC_DEF("get_vertex_normal", 1, &mesh_data_tool_class_get_vertex_normal),
	JS_CFUNC_DEF("set_vertex_tangent", 2, &mesh_data_tool_class_set_vertex_tangent),
	JS_CFUNC_DEF("get_vertex_tangent", 1, &mesh_data_tool_class_get_vertex_tangent),
	JS_CFUNC_DEF("set_vertex_uv", 2, &mesh_data_tool_class_set_vertex_uv),
	JS_CFUNC_DEF("get_vertex_uv", 1, &mesh_data_tool_class_get_vertex_uv),
	JS_CFUNC_DEF("set_vertex_uv2", 2, &mesh_data_tool_class_set_vertex_uv2),
	JS_CFUNC_DEF("get_vertex_uv2", 1, &mesh_data_tool_class_get_vertex_uv2),
	JS_CFUNC_DEF("set_vertex_color", 2, &mesh_data_tool_class_set_vertex_color),
	JS_CFUNC_DEF("get_vertex_color", 1, &mesh_data_tool_class_get_vertex_color),
	JS_CFUNC_DEF("set_vertex_bones", 2, &mesh_data_tool_class_set_vertex_bones),
	JS_CFUNC_DEF("get_vertex_bones", 1, &mesh_data_tool_class_get_vertex_bones),
	JS_CFUNC_DEF("set_vertex_weights", 2, &mesh_data_tool_class_set_vertex_weights),
	JS_CFUNC_DEF("get_vertex_weights", 1, &mesh_data_tool_class_get_vertex_weights),
	JS_CFUNC_DEF("set_vertex_meta", 2, &mesh_data_tool_class_set_vertex_meta),
	JS_CFUNC_DEF("get_vertex_meta", 1, &mesh_data_tool_class_get_vertex_meta),
	JS_CFUNC_DEF("get_vertex_edges", 1, &mesh_data_tool_class_get_vertex_edges),
	JS_CFUNC_DEF("get_vertex_faces", 1, &mesh_data_tool_class_get_vertex_faces),
	JS_CFUNC_DEF("get_edge_vertex", 2, &mesh_data_tool_class_get_edge_vertex),
	JS_CFUNC_DEF("get_edge_faces", 1, &mesh_data_tool_class_get_edge_faces),
	JS_CFUNC_DEF("set_edge_meta", 2, &mesh_data_tool_class_set_edge_meta),
	JS_CFUNC_DEF("get_edge_meta", 1, &mesh_data_tool_class_get_edge_meta),
	JS_CFUNC_DEF("get_face_vertex", 2, &mesh_data_tool_class_get_face_vertex),
	JS_CFUNC_DEF("get_face_edge", 2, &mesh_data_tool_class_get_face_edge),
	JS_CFUNC_DEF("set_face_meta", 2, &mesh_data_tool_class_set_face_meta),
	JS_CFUNC_DEF("get_face_meta", 1, &mesh_data_tool_class_get_face_meta),
	JS_CFUNC_DEF("get_face_normal", 1, &mesh_data_tool_class_get_face_normal),
	JS_CFUNC_DEF("set_material", 1, &mesh_data_tool_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &mesh_data_tool_class_get_material),
};




static void define_mesh_data_tool_property(JSContext *ctx, JSValue proto) {
}

static void define_mesh_data_tool_enum(JSContext *ctx, JSValue ctor) {
}

static int js_mesh_data_tool_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MeshDataTool"] = class_id;
	classes_by_id[class_id] = "MeshDataTool";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &mesh_data_tool_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_mesh_data_tool_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, mesh_data_tool_class_proto_funcs, _countof(mesh_data_tool_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, mesh_data_tool_class_constructor, "MeshDataTool", 0, JS_CFUNC_constructor, 0);
	define_mesh_data_tool_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MeshDataTool", ctor);
	ctor_list["MeshDataTool"] = ctor;

	return 0;
}

JSModuleDef *_js_init_mesh_data_tool_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_mesh_data_tool_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MeshDataTool");
	return m;
}

JSModuleDef *js_init_mesh_data_tool_module(JSContext *ctx) {
	return _js_init_mesh_data_tool_module(ctx, "@godot/classes/mesh_data_tool");
}

void __register_mesh_data_tool() {
	js_init_mesh_data_tool_module(js_context());
}

void register_mesh_data_tool() {
	__register_mesh_data_tool();
}