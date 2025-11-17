#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture_layered.hpp>
#include <godot_cpp/classes/visual_shader_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader_node_cubemap.hpp>
using namespace godot;

static void visual_shader_node_cubemap_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeCubemap"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_cubemap_class_def = {
    "VisualShaderNodeCubemap",
    visual_shader_node_cubemap_class_finalizer
};

static JSValue visual_shader_node_cubemap_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeCubemap"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeCubemap *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeCubemap *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeCubemap);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_cubemap_class_set_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeCubemap::set_source, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_cubemap_class_get_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeCubemap::get_source, ctx, this_val, argc, argv);
}
static JSValue visual_shader_node_cubemap_class_set_cube_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeCubemap::set_cube_map, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_cubemap_class_get_cube_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeCubemap::get_cube_map, ctx, this_val, argc, argv);
}
static JSValue visual_shader_node_cubemap_class_set_texture_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeCubemap::set_texture_type, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_cubemap_class_get_texture_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeCubemap::get_texture_type, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry visual_shader_node_cubemap_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_source", 1, &visual_shader_node_cubemap_class_set_source),
	JS_CFUNC_DEF("get_source", 0, &visual_shader_node_cubemap_class_get_source),
	JS_CFUNC_DEF("set_cube_map", 1, &visual_shader_node_cubemap_class_set_cube_map),
	JS_CFUNC_DEF("get_cube_map", 0, &visual_shader_node_cubemap_class_get_cube_map),
	JS_CFUNC_DEF("set_texture_type", 1, &visual_shader_node_cubemap_class_set_texture_type),
	JS_CFUNC_DEF("get_texture_type", 0, &visual_shader_node_cubemap_class_get_texture_type),
};




static void define_visual_shader_node_cubemap_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "source"),
        JS_NewCFunction(ctx, visual_shader_node_cubemap_class_get_source, "get_source", 0),
        JS_NewCFunction(ctx, visual_shader_node_cubemap_class_set_source, "set_source", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cube_map"),
        JS_NewCFunction(ctx, visual_shader_node_cubemap_class_get_cube_map, "get_cube_map", 0),
        JS_NewCFunction(ctx, visual_shader_node_cubemap_class_set_cube_map, "set_cube_map", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_type"),
        JS_NewCFunction(ctx, visual_shader_node_cubemap_class_get_texture_type, "get_texture_type", 0),
        JS_NewCFunction(ctx, visual_shader_node_cubemap_class_set_texture_type, "set_texture_type", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_cubemap_enum(JSContext *ctx, JSValue ctor) {
	JSValue Source_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Source_obj, "SOURCE_TEXTURE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Source_obj, "SOURCE_PORT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Source_obj, "SOURCE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Source", Source_obj);
	JSValue TextureType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureType_obj, "TYPE_DATA", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureType_obj, "TYPE_COLOR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureType_obj, "TYPE_NORMAL_MAP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureType_obj, "TYPE_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TextureType", TextureType_obj);
}

static int js_visual_shader_node_cubemap_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeCubemap"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeCubemap";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_cubemap_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_cubemap_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_cubemap_class_proto_funcs, _countof(visual_shader_node_cubemap_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_cubemap_class_constructor, "VisualShaderNodeCubemap", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_cubemap_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeCubemap", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_cubemap_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_cubemap_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeCubemap");
	return m;
}

JSModuleDef *js_init_visual_shader_node_cubemap_module(JSContext *ctx) {
	return _js_init_visual_shader_node_cubemap_module(ctx, "@godot/classes/visual_shader_node_cubemap");
}

void __register_visual_shader_node_cubemap() {
	js_init_visual_shader_node_cubemap_module(js_context());
}

void register_visual_shader_node_cubemap() {
	__register_visual_shader_node_cubemap();
}