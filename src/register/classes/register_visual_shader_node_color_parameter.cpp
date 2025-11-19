#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_shader_node_parameter.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader_node_color_parameter.hpp>
using namespace godot;

static void visual_shader_node_color_parameter_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeColorParameter"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_color_parameter_class_def = {
    "VisualShaderNodeColorParameter",
    visual_shader_node_color_parameter_class_finalizer
};

static JSValue visual_shader_node_color_parameter_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeColorParameter"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeColorParameter *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeColorParameter *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeColorParameter);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_color_parameter_class_set_default_value_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeColorParameter::set_default_value_enabled, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_color_parameter_class_is_default_value_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeColorParameter::is_default_value_enabled, ctx, this_val, argc, argv);
}
static JSValue visual_shader_node_color_parameter_class_set_default_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeColorParameter::set_default_value, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_color_parameter_class_get_default_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		VisualShaderNodeColorParameter *obj = static_cast<VisualShaderNodeColorParameter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_default_value();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		VisualShaderNodeColorParameter *js_proxy = static_cast<VisualShaderNodeColorParameter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_default_value(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry visual_shader_node_color_parameter_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_default_value_enabled", 1, &visual_shader_node_color_parameter_class_set_default_value_enabled),
	JS_CFUNC_DEF("is_default_value_enabled", 0, &visual_shader_node_color_parameter_class_is_default_value_enabled),
	JS_CFUNC_DEF("set_default_value", 1, &visual_shader_node_color_parameter_class_set_default_value),
	JS_CFUNC_DEF("get_default_value", 0, &visual_shader_node_color_parameter_class_get_default_value),
};




static void define_visual_shader_node_color_parameter_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_value_enabled"),
        JS_NewCFunction(ctx, visual_shader_node_color_parameter_class_is_default_value_enabled, "is_default_value_enabled", 0),
        JS_NewCFunction(ctx, visual_shader_node_color_parameter_class_set_default_value_enabled, "set_default_value_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_value"),
        JS_NewCFunction(ctx, visual_shader_node_color_parameter_class_get_default_value, "get_default_value", 0),
        JS_NewCFunction(ctx, visual_shader_node_color_parameter_class_set_default_value, "set_default_value", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_color_parameter_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visual_shader_node_color_parameter_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeColorParameter"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeColorParameter";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_color_parameter_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNodeParameter"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_color_parameter_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_color_parameter_class_proto_funcs, _countof(visual_shader_node_color_parameter_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_color_parameter_class_constructor, "VisualShaderNodeColorParameter", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_color_parameter_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeColorParameter", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_color_parameter_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node_parameter';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_color_parameter_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeColorParameter");
	return m;
}

JSModuleDef *js_init_visual_shader_node_color_parameter_module(JSContext *ctx) {
	return _js_init_visual_shader_node_color_parameter_module(ctx, "@godot/classes/visual_shader_node_color_parameter");
}

void __register_visual_shader_node_color_parameter() {
	js_init_visual_shader_node_color_parameter_module(js_context());
}

void register_visual_shader_node_color_parameter() {
	__register_visual_shader_node_color_parameter();
}