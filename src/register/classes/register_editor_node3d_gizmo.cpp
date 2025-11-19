#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo_plugin.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/node3d_gizmo.hpp>
#include <godot_cpp/classes/skin_reference.hpp>
#include <godot_cpp/classes/triangle_mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo.hpp>
using namespace godot;

static void editor_node3d_gizmo_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorNode3DGizmo"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef editor_node3d_gizmo_class_def = {
    "EditorNode3DGizmo",
    editor_node3d_gizmo_class_finalizer
};

static JSValue editor_node3d_gizmo_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorNode3DGizmo"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorNode3DGizmo *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorNode3DGizmo *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorNode3DGizmo);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_node3d_gizmo_class_add_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::add_lines, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_add_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::add_mesh, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_add_collision_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::add_collision_segments, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_add_collision_triangles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::add_collision_triangles, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_add_unscaled_billboard(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::add_unscaled_billboard, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_add_handles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::add_handles, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_set_node_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::set_node_3d, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_get_node_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorNode3DGizmo::get_node_3d, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_get_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorNode3DGizmo::get_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::clear, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_set_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorNode3DGizmo::set_hidden, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_is_subgizmo_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorNode3DGizmo::is_subgizmo_selected, ctx, this_val, argc, argv);
};
static JSValue editor_node3d_gizmo_class_get_subgizmo_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorNode3DGizmo::get_subgizmo_selection, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_node3d_gizmo_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_lines", 4, &editor_node3d_gizmo_class_add_lines),
	JS_CFUNC_DEF("add_mesh", 4, &editor_node3d_gizmo_class_add_mesh),
	JS_CFUNC_DEF("add_collision_segments", 1, &editor_node3d_gizmo_class_add_collision_segments),
	JS_CFUNC_DEF("add_collision_triangles", 1, &editor_node3d_gizmo_class_add_collision_triangles),
	JS_CFUNC_DEF("add_unscaled_billboard", 3, &editor_node3d_gizmo_class_add_unscaled_billboard),
	JS_CFUNC_DEF("add_handles", 5, &editor_node3d_gizmo_class_add_handles),
	JS_CFUNC_DEF("set_node_3d", 1, &editor_node3d_gizmo_class_set_node_3d),
	JS_CFUNC_DEF("get_node_3d", 0, &editor_node3d_gizmo_class_get_node_3d),
	JS_CFUNC_DEF("get_plugin", 0, &editor_node3d_gizmo_class_get_plugin),
	JS_CFUNC_DEF("clear", 0, &editor_node3d_gizmo_class_clear),
	JS_CFUNC_DEF("set_hidden", 1, &editor_node3d_gizmo_class_set_hidden),
	JS_CFUNC_DEF("is_subgizmo_selected", 1, &editor_node3d_gizmo_class_is_subgizmo_selected),
	JS_CFUNC_DEF("get_subgizmo_selection", 0, &editor_node3d_gizmo_class_get_subgizmo_selection),
};




static void define_editor_node3d_gizmo_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_node3d_gizmo_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_node3d_gizmo_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorNode3DGizmo"] = class_id;
	classes_by_id[class_id] = "EditorNode3DGizmo";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_node3d_gizmo_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3DGizmo"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_node3d_gizmo_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_node3d_gizmo_class_proto_funcs, _countof(editor_node3d_gizmo_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_node3d_gizmo_class_constructor, "EditorNode3DGizmo", 0, JS_CFUNC_constructor, 0);
	define_editor_node3d_gizmo_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorNode3DGizmo", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_node3d_gizmo_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d_gizmo';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_node3d_gizmo_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorNode3DGizmo");
	return m;
}

JSModuleDef *js_init_editor_node3d_gizmo_module(JSContext *ctx) {
	return _js_init_editor_node3d_gizmo_module(ctx, "@godot/classes/editor_node3d_gizmo");
}

void __register_editor_node3d_gizmo() {
	js_init_editor_node3d_gizmo_module(js_context());
}

void register_editor_node3d_gizmo() {
	__register_editor_node3d_gizmo();
}