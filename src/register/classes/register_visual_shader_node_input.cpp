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
#include <godot_cpp/classes/visual_shader_node_input.hpp>
using namespace godot;

static void visual_shader_node_input_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeInput"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_input_class_def = {
    "VisualShaderNodeInput",
    visual_shader_node_input_class_finalizer
};

static JSValue visual_shader_node_input_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeInput"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeInput *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeInput *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeInput);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_input_class_set_input_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeInput::set_input_name, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_input_class_get_input_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		VisualShaderNodeInput *obj = static_cast<VisualShaderNodeInput *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_input_name();
	};
	proxy->setter = [this_val](const String &value) -> void {
		VisualShaderNodeInput *js_proxy = static_cast<VisualShaderNodeInput *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_input_name(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue visual_shader_node_input_class_get_input_real_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeInput::get_input_real_name, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry visual_shader_node_input_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_input_name", 1, &visual_shader_node_input_class_set_input_name),
	JS_CFUNC_DEF("get_input_name", 0, &visual_shader_node_input_class_get_input_name),
	JS_CFUNC_DEF("get_input_real_name", 0, &visual_shader_node_input_class_get_input_real_name),
};


static JSValue visual_shader_node_input_class_get_input_type_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	VisualShaderNodeInput *opaque = static_cast<VisualShaderNodeInput *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "input_type_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "input_type_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "input_type_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_visual_shader_node_input_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_name"),
        JS_NewCFunction(ctx, visual_shader_node_input_class_get_input_name, "get_input_name", 0),
        JS_NewCFunction(ctx, visual_shader_node_input_class_set_input_name, "set_input_name", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "input_type_changed"),
		JS_NewCFunction(ctx, visual_shader_node_input_class_get_input_type_changed_signal, "get_input_type_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_visual_shader_node_input_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visual_shader_node_input_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeInput"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeInput";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_input_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_input_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_input_class_proto_funcs, _countof(visual_shader_node_input_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_input_class_constructor, "VisualShaderNodeInput", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_input_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeInput", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_input_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_input_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeInput");
	return m;
}

JSModuleDef *js_init_visual_shader_node_input_module(JSContext *ctx) {
	return _js_init_visual_shader_node_input_module(ctx, "@godot/classes/visual_shader_node_input");
}

void __register_visual_shader_node_input() {
	js_init_visual_shader_node_input_module(js_context());
}

void register_visual_shader_node_input() {
	__register_visual_shader_node_input();
}