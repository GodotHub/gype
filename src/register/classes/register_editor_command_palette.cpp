#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/confirmation_dialog.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_command_palette.hpp>
using namespace godot;

static void editor_command_palette_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorCommandPalette"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_command_palette_class_def = {
    "EditorCommandPalette",
    editor_command_palette_class_finalizer
};

static JSValue editor_command_palette_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorCommandPalette"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorCommandPalette *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorCommandPalette *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorCommandPalette);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_command_palette_class_add_command(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorCommandPalette::add_command, ctx, this_val, argc, argv);
};
static JSValue editor_command_palette_class_remove_command(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorCommandPalette::remove_command, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_command_palette_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_command", 4, &editor_command_palette_class_add_command),
	JS_CFUNC_DEF("remove_command", 1, &editor_command_palette_class_remove_command),
};




static void define_editor_command_palette_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_command_palette_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_command_palette_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorCommandPalette"] = class_id;
	classes_by_id[class_id] = "EditorCommandPalette";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_command_palette_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ConfirmationDialog"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_command_palette_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_command_palette_class_proto_funcs, _countof(editor_command_palette_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_command_palette_class_constructor, "EditorCommandPalette", 0, JS_CFUNC_constructor, 0);
	define_editor_command_palette_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorCommandPalette", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_command_palette_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/confirmation_dialog';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_command_palette_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorCommandPalette");
	return m;
}

JSModuleDef *js_init_editor_command_palette_module(JSContext *ctx) {
	return _js_init_editor_command_palette_module(ctx, "@godot/classes/editor_command_palette");
}

void __register_editor_command_palette() {
	js_init_editor_command_palette_module(js_context());
}

void register_editor_command_palette() {
	__register_editor_command_palette();
}