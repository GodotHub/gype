
#include "quickjs/quickjs.h"
#include "register/classes/register_classes.h"
#include "quickjs/env.h"
#include "utils/func_utils.h"
#include "quickjs/str_helper.h"
#include "quickjs/quickjs_helper.h"
#include <godot_cpp/classes/texture3d.hpp>
#include <godot_cpp/classes/visual_shader_node_texture3d.hpp>
#include <godot_cpp/classes/visual_shader_node_sample3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>


using namespace godot;

static void visual_shader_node_texture3d_class_finalizer(JSRuntime *rt, JSValue val) {
	
	// nothing
}

static JSClassDef visual_shader_node_texture3d_class_def = {
	"VisualShaderNodeTexture3D",
	.finalizer = visual_shader_node_texture3d_class_finalizer
};

static JSValue visual_shader_node_texture3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, VisualShaderNodeTexture3D::__class_id);
	if (JS_IsException(obj))
		return obj;
	VisualShaderNodeTexture3D *visual_shader_node_texture3d_class = memnew(VisualShaderNodeTexture3D);
	if (!visual_shader_node_texture3d_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, visual_shader_node_texture3d_class);	
	return obj;
}
static JSValue visual_shader_node_texture3d_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    call_builtin_method_no_ret(&VisualShaderNodeTexture3D::set_texture, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue visual_shader_node_texture3d_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeTexture3D::get_texture, ctx, this_val, argc, argv);
};
static const JSCFunctionListEntry visual_shader_node_texture3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture", 1, &visual_shader_node_texture3d_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &visual_shader_node_texture3d_class_get_texture),
};

void define_visual_shader_node_texture3d_property(JSContext *ctx, JSValue obj) {
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, visual_shader_node_texture3d_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, visual_shader_node_texture3d_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
}

static void define_node_enum(JSContext *ctx, JSValue proto) {
}

static int js_visual_shader_node_texture3d_class_init(JSContext *ctx, JSModuleDef *m) {
	
	JS_NewClassID(&VisualShaderNodeTexture3D::__class_id);
	classes["VisualShaderNodeTexture3D"] = VisualShaderNodeTexture3D::__class_id;
	class_id_list.insert(VisualShaderNodeTexture3D::__class_id);
	JS_NewClass(JS_GetRuntime(ctx), VisualShaderNodeTexture3D::__class_id, &visual_shader_node_texture3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, VisualShaderNodeTexture3D::__class_id);
	JSValue base_class = JS_GetClassProto(ctx, VisualShaderNodeSample3D::__class_id);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, VisualShaderNodeTexture3D::__class_id, proto);

	define_visual_shader_node_texture3d_property(ctx, proto);
	define_node_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_texture3d_class_proto_funcs, _countof(visual_shader_node_texture3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_texture3d_class_constructor, "VisualShaderNodeTexture3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JS_SetModuleExport(ctx, m, "VisualShaderNodeTexture3D", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_texture3d_module(JSContext *ctx, const char *module_name) {
	const char *code = "import * as _ from 'godot/classes/visual_shader_node_sample3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_texture3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeTexture3D");
	return m;
}

JSModuleDef *js_init_visual_shader_node_texture3d_module(JSContext *ctx) {
	return _js_init_visual_shader_node_texture3d_module(ctx, "godot/classes/visual_shader_node_texture3d");
}

void register_visual_shader_node_texture3d() {
	VisualShaderNodeTexture3D::__init_js_class_id();
	js_init_visual_shader_node_texture3d_module(ctx);
}