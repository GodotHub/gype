#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/shortcut.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_context_menu_plugin.hpp>
using namespace godot;

static void editor_context_menu_plugin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorContextMenuPlugin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_context_menu_plugin_class_def = {
    "EditorContextMenuPlugin",
    editor_context_menu_plugin_class_finalizer
};

static JSValue editor_context_menu_plugin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorContextMenuPlugin"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorContextMenuPlugin *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorContextMenuPlugin *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorContextMenuPlugin);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_context_menu_plugin_class_add_menu_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorContextMenuPlugin::add_menu_shortcut, ctx, this_val, argc, argv);
};
static JSValue editor_context_menu_plugin_class_add_context_menu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorContextMenuPlugin::add_context_menu_item, ctx, this_val, argc, argv);
};
static JSValue editor_context_menu_plugin_class_add_context_menu_item_from_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorContextMenuPlugin::add_context_menu_item_from_shortcut, ctx, this_val, argc, argv);
};
static JSValue editor_context_menu_plugin_class_add_context_submenu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorContextMenuPlugin::add_context_submenu_item, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_context_menu_plugin_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_menu_shortcut", 2, &editor_context_menu_plugin_class_add_menu_shortcut),
	JS_CFUNC_DEF("add_context_menu_item", 3, &editor_context_menu_plugin_class_add_context_menu_item),
	JS_CFUNC_DEF("add_context_menu_item_from_shortcut", 3, &editor_context_menu_plugin_class_add_context_menu_item_from_shortcut),
	JS_CFUNC_DEF("add_context_submenu_item", 3, &editor_context_menu_plugin_class_add_context_submenu_item),
};




static void define_editor_context_menu_plugin_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_context_menu_plugin_enum(JSContext *ctx, JSValue ctor) {
	JSValue ContextMenuSlot_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_SCENE_TREE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_FILESYSTEM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_SCRIPT_EDITOR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_FILESYSTEM_CREATE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_SCRIPT_EDITOR_CODE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_SCENE_TABS", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ContextMenuSlot_obj, "CONTEXT_SLOT_2D_EDITOR", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "ContextMenuSlot", ContextMenuSlot_obj);
}

static int js_editor_context_menu_plugin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorContextMenuPlugin"] = class_id;
	classes_by_id[class_id] = "EditorContextMenuPlugin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_context_menu_plugin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_context_menu_plugin_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_context_menu_plugin_class_proto_funcs, _countof(editor_context_menu_plugin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_context_menu_plugin_class_constructor, "EditorContextMenuPlugin", 0, JS_CFUNC_constructor, 0);
	define_editor_context_menu_plugin_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorContextMenuPlugin", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_context_menu_plugin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_context_menu_plugin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorContextMenuPlugin");
	return m;
}

JSModuleDef *js_init_editor_context_menu_plugin_module(JSContext *ctx) {
	return _js_init_editor_context_menu_plugin_module(ctx, "@godot/classes/editor_context_menu_plugin");
}

void __register_editor_context_menu_plugin() {
	js_init_editor_context_menu_plugin_module(js_context());
}

void register_editor_context_menu_plugin() {
	__register_editor_context_menu_plugin();
}