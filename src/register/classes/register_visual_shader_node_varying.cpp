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
#include <godot_cpp/classes/visual_shader_node_varying.hpp>
using namespace godot;

static void visual_shader_node_varying_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeVarying"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_varying_class_def = {
    "VisualShaderNodeVarying",
    visual_shader_node_varying_class_finalizer
};

static JSValue visual_shader_node_varying_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeVarying"];
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
        instance = memnew(VisualShaderNodeVarying);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_varying_class_set_varying_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeVarying::set_varying_name, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_varying_class_get_varying_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeVarying::get_varying_name, ctx, this_val, argc, argv);
}
static JSValue visual_shader_node_varying_class_set_varying_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeVarying::set_varying_type, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_varying_class_get_varying_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeVarying::get_varying_type, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry visual_shader_node_varying_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_varying_name", 1, &visual_shader_node_varying_class_set_varying_name),
	JS_CFUNC_DEF("get_varying_name", 0, &visual_shader_node_varying_class_get_varying_name),
	JS_CFUNC_DEF("set_varying_type", 1, &visual_shader_node_varying_class_set_varying_type),
	JS_CFUNC_DEF("get_varying_type", 0, &visual_shader_node_varying_class_get_varying_type),
};




static void define_visual_shader_node_varying_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "varying_name"),
        JS_NewCFunction(ctx, visual_shader_node_varying_class_get_varying_name, "get_varying_name", 0),
        JS_NewCFunction(ctx, visual_shader_node_varying_class_set_varying_name, "set_varying_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "varying_type"),
        JS_NewCFunction(ctx, visual_shader_node_varying_class_get_varying_type, "get_varying_type", 0),
        JS_NewCFunction(ctx, visual_shader_node_varying_class_set_varying_type, "set_varying_type", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_varying_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visual_shader_node_varying_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeVarying"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeVarying";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_varying_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_varying_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_varying_class_proto_funcs, _countof(visual_shader_node_varying_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_varying_class_constructor, "VisualShaderNodeVarying", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_varying_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeVarying", ctor);
	ctor_list["VisualShaderNodeVarying"] = ctor;

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_varying_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_varying_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeVarying");
	return m;
}

JSModuleDef *js_init_visual_shader_node_varying_module(JSContext *ctx) {
	return _js_init_visual_shader_node_varying_module(ctx, "@godot/classes/visual_shader_node_varying");
}

void __register_visual_shader_node_varying() {
	js_init_visual_shader_node_varying_module(js_context());
}

void register_visual_shader_node_varying() {
	__register_visual_shader_node_varying();
}