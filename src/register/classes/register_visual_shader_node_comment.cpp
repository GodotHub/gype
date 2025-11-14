#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_shader_node_frame.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader_node_comment.hpp>
using namespace godot;

static void visual_shader_node_comment_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeComment"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_comment_class_def = {
    "VisualShaderNodeComment",
    visual_shader_node_comment_class_finalizer
};

static JSValue visual_shader_node_comment_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeComment"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeComment *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeComment *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeComment);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_comment_class_set_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeComment::set_description, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_comment_class_get_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		VisualShaderNodeComment *obj = static_cast<VisualShaderNodeComment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_description();
	};
	proxy->setter = [this_val](const String &value) -> void {
		VisualShaderNodeComment *js_proxy = static_cast<VisualShaderNodeComment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_description(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry visual_shader_node_comment_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_description", 1, &visual_shader_node_comment_class_set_description),
	JS_CFUNC_DEF("get_description", 0, &visual_shader_node_comment_class_get_description),
};




static void define_visual_shader_node_comment_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "description"),
        JS_NewCFunction(ctx, visual_shader_node_comment_class_get_description, "get_description", 0),
        JS_NewCFunction(ctx, visual_shader_node_comment_class_set_description, "set_description", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_comment_enum(JSContext *ctx, JSValue proto) {
}

static int js_visual_shader_node_comment_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeComment"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeComment";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_comment_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNodeFrame"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_comment_property(ctx, proto);
	define_visual_shader_node_comment_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_comment_class_proto_funcs, _countof(visual_shader_node_comment_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_comment_class_constructor, "VisualShaderNodeComment", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeComment", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_comment_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node_frame';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_comment_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeComment");
	return m;
}

JSModuleDef *js_init_visual_shader_node_comment_module(JSContext *ctx) {
	return _js_init_visual_shader_node_comment_module(ctx, "@godot/classes/visual_shader_node_comment");
}

void __register_visual_shader_node_comment() {
	js_init_visual_shader_node_comment_module(js_context());
}

void register_visual_shader_node_comment() {
	__register_visual_shader_node_comment();
}