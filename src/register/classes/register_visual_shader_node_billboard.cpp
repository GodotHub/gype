#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_shader_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader_node_billboard.hpp>
using namespace godot;

static void visual_shader_node_billboard_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeBillboard"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_billboard_class_def = {
    "VisualShaderNodeBillboard",
    visual_shader_node_billboard_class_finalizer
};

static JSValue visual_shader_node_billboard_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeBillboard"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeBillboard *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeBillboard *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeBillboard);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_billboard_class_set_billboard_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeBillboard::set_billboard_type, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_billboard_class_get_billboard_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeBillboard::get_billboard_type, ctx, this_val, argc, argv);
}
static JSValue visual_shader_node_billboard_class_set_keep_scale_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeBillboard::set_keep_scale_enabled, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_billboard_class_is_keep_scale_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeBillboard::is_keep_scale_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry visual_shader_node_billboard_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_billboard_type", 1, &visual_shader_node_billboard_class_set_billboard_type),
	JS_CFUNC_DEF("get_billboard_type", 0, &visual_shader_node_billboard_class_get_billboard_type),
	JS_CFUNC_DEF("set_keep_scale_enabled", 1, &visual_shader_node_billboard_class_set_keep_scale_enabled),
	JS_CFUNC_DEF("is_keep_scale_enabled", 0, &visual_shader_node_billboard_class_is_keep_scale_enabled),
};




static void define_visual_shader_node_billboard_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "billboard_type"),
        JS_NewCFunction(ctx, visual_shader_node_billboard_class_get_billboard_type, "get_billboard_type", 0),
        JS_NewCFunction(ctx, visual_shader_node_billboard_class_set_billboard_type, "set_billboard_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_scale"),
        JS_NewCFunction(ctx, visual_shader_node_billboard_class_is_keep_scale_enabled, "is_keep_scale_enabled", 0),
        JS_NewCFunction(ctx, visual_shader_node_billboard_class_set_keep_scale_enabled, "set_keep_scale_enabled", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_billboard_enum(JSContext *ctx, JSValue ctor) {
	JSValue BillboardType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BillboardType_obj, "BILLBOARD_TYPE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BillboardType_obj, "BILLBOARD_TYPE_ENABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BillboardType_obj, "BILLBOARD_TYPE_FIXED_Y", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BillboardType_obj, "BILLBOARD_TYPE_PARTICLES", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BillboardType_obj, "BILLBOARD_TYPE_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "BillboardType", BillboardType_obj);
}

static int js_visual_shader_node_billboard_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeBillboard"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeBillboard";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_billboard_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_billboard_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_billboard_class_proto_funcs, _countof(visual_shader_node_billboard_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_billboard_class_constructor, "VisualShaderNodeBillboard", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_billboard_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeBillboard", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_billboard_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_billboard_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeBillboard");
	return m;
}

JSModuleDef *js_init_visual_shader_node_billboard_module(JSContext *ctx) {
	return _js_init_visual_shader_node_billboard_module(ctx, "@godot/classes/visual_shader_node_billboard");
}

void __register_visual_shader_node_billboard() {
	js_init_visual_shader_node_billboard_module(js_context());
}

void register_visual_shader_node_billboard() {
	__register_visual_shader_node_billboard();
}