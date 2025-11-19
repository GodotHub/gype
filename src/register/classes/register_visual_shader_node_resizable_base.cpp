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
#include <godot_cpp/classes/visual_shader_node_resizable_base.hpp>
using namespace godot;

static void visual_shader_node_resizable_base_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeResizableBase"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef visual_shader_node_resizable_base_class_def = {
    "VisualShaderNodeResizableBase",
    visual_shader_node_resizable_base_class_finalizer
};

static JSValue visual_shader_node_resizable_base_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeResizableBase"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeResizableBase *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeResizableBase *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeResizableBase);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_resizable_base_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeResizableBase::set_size, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_resizable_base_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		VisualShaderNodeResizableBase *obj = static_cast<VisualShaderNodeResizableBase *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		VisualShaderNodeResizableBase *js_proxy = static_cast<VisualShaderNodeResizableBase *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry visual_shader_node_resizable_base_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &visual_shader_node_resizable_base_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &visual_shader_node_resizable_base_class_get_size),
};




static void define_visual_shader_node_resizable_base_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, visual_shader_node_resizable_base_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, visual_shader_node_resizable_base_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_resizable_base_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visual_shader_node_resizable_base_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeResizableBase"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeResizableBase";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_resizable_base_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_resizable_base_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_resizable_base_class_proto_funcs, _countof(visual_shader_node_resizable_base_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_resizable_base_class_constructor, "VisualShaderNodeResizableBase", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_resizable_base_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeResizableBase", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_resizable_base_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_resizable_base_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeResizableBase");
	return m;
}

JSModuleDef *js_init_visual_shader_node_resizable_base_module(JSContext *ctx) {
	return _js_init_visual_shader_node_resizable_base_module(ctx, "@godot/classes/visual_shader_node_resizable_base");
}

void __register_visual_shader_node_resizable_base() {
	js_init_visual_shader_node_resizable_base_module(js_context());
}

void register_visual_shader_node_resizable_base() {
	__register_visual_shader_node_resizable_base();
}