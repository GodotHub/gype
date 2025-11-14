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
#include <godot_cpp/classes/immediate_mesh.hpp>
using namespace godot;

static void immediate_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ImmediateMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef immediate_mesh_class_def = {
    "ImmediateMesh",
    immediate_mesh_class_finalizer
};

static JSValue immediate_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ImmediateMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ImmediateMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ImmediateMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ImmediateMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue immediate_mesh_class_surface_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_begin, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_set_color, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_set_normal, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_set_tangent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_set_tangent, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_set_uv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_set_uv, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_set_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_set_uv2, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_add_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_add_vertex, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_add_vertex_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_add_vertex_2d, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_surface_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::surface_end, ctx, this_val, argc, argv);
};
static JSValue immediate_mesh_class_clear_surfaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImmediateMesh::clear_surfaces, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry immediate_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("surface_begin", 2, &immediate_mesh_class_surface_begin),
	JS_CFUNC_DEF("surface_set_color", 1, &immediate_mesh_class_surface_set_color),
	JS_CFUNC_DEF("surface_set_normal", 1, &immediate_mesh_class_surface_set_normal),
	JS_CFUNC_DEF("surface_set_tangent", 1, &immediate_mesh_class_surface_set_tangent),
	JS_CFUNC_DEF("surface_set_uv", 1, &immediate_mesh_class_surface_set_uv),
	JS_CFUNC_DEF("surface_set_uv2", 1, &immediate_mesh_class_surface_set_uv2),
	JS_CFUNC_DEF("surface_add_vertex", 1, &immediate_mesh_class_surface_add_vertex),
	JS_CFUNC_DEF("surface_add_vertex_2d", 1, &immediate_mesh_class_surface_add_vertex_2d),
	JS_CFUNC_DEF("surface_end", 0, &immediate_mesh_class_surface_end),
	JS_CFUNC_DEF("clear_surfaces", 0, &immediate_mesh_class_clear_surfaces),
};




static void define_immediate_mesh_property(JSContext *ctx, JSValue proto) {
}

static void define_immediate_mesh_enum(JSContext *ctx, JSValue proto) {
}

static int js_immediate_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ImmediateMesh"] = class_id;
	classes_by_id[class_id] = "ImmediateMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &immediate_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Mesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_immediate_mesh_property(ctx, proto);
	define_immediate_mesh_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, immediate_mesh_class_proto_funcs, _countof(immediate_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, immediate_mesh_class_constructor, "ImmediateMesh", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ImmediateMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_immediate_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_immediate_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ImmediateMesh");
	return m;
}

JSModuleDef *js_init_immediate_mesh_module(JSContext *ctx) {
	return _js_init_immediate_mesh_module(ctx, "@godot/classes/immediate_mesh");
}

void __register_immediate_mesh() {
	js_init_immediate_mesh_module(js_context());
}

void register_immediate_mesh() {
	__register_immediate_mesh();
}