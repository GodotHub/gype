#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_resource_tooltip_plugin.hpp>
using namespace godot;

static void editor_resource_tooltip_plugin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorResourceTooltipPlugin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_resource_tooltip_plugin_class_def = {
    "EditorResourceTooltipPlugin",
    editor_resource_tooltip_plugin_class_finalizer
};

static JSValue editor_resource_tooltip_plugin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorResourceTooltipPlugin"];
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
        instance = memnew(EditorResourceTooltipPlugin);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_resource_tooltip_plugin_class_request_thumbnail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&EditorResourceTooltipPlugin::request_thumbnail, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_resource_tooltip_plugin_class_proto_funcs[] = {
	JS_CFUNC_DEF("request_thumbnail", 2, &editor_resource_tooltip_plugin_class_request_thumbnail),
};




static void define_editor_resource_tooltip_plugin_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_resource_tooltip_plugin_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_resource_tooltip_plugin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorResourceTooltipPlugin"] = class_id;
	classes_by_id[class_id] = "EditorResourceTooltipPlugin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_resource_tooltip_plugin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_resource_tooltip_plugin_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_resource_tooltip_plugin_class_proto_funcs, _countof(editor_resource_tooltip_plugin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_resource_tooltip_plugin_class_constructor, "EditorResourceTooltipPlugin", 0, JS_CFUNC_constructor, 0);
	define_editor_resource_tooltip_plugin_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorResourceTooltipPlugin", ctor);
	ctor_list["EditorResourceTooltipPlugin"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_resource_tooltip_plugin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_resource_tooltip_plugin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorResourceTooltipPlugin");
	return m;
}

JSModuleDef *js_init_editor_resource_tooltip_plugin_module(JSContext *ctx) {
	return _js_init_editor_resource_tooltip_plugin_module(ctx, "@godot/classes/editor_resource_tooltip_plugin");
}

void __register_editor_resource_tooltip_plugin() {
	js_init_editor_resource_tooltip_plugin_module(js_context());
}

void register_editor_resource_tooltip_plugin() {
	__register_editor_resource_tooltip_plugin();
}