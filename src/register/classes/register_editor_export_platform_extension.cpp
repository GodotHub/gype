#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_export_platform.hpp>
#include <godot_cpp/classes/editor_export_preset.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_export_platform_extension.hpp>
using namespace godot;

static void editor_export_platform_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorExportPlatformExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_export_platform_extension_class_def = {
    "EditorExportPlatformExtension",
    editor_export_platform_extension_class_finalizer
};

static JSValue editor_export_platform_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorExportPlatformExtension"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorExportPlatformExtension *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorExportPlatformExtension *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorExportPlatformExtension);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_export_platform_extension_class_set_config_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&EditorExportPlatformExtension::set_config_error, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_extension_class_get_config_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatformExtension::get_config_error, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_extension_class_set_config_missing_templates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&EditorExportPlatformExtension::set_config_missing_templates, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_extension_class_get_config_missing_templates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatformExtension::get_config_missing_templates, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_export_platform_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_config_error", 1, &editor_export_platform_extension_class_set_config_error),
	JS_CFUNC_DEF("get_config_error", 0, &editor_export_platform_extension_class_get_config_error),
	JS_CFUNC_DEF("set_config_missing_templates", 1, &editor_export_platform_extension_class_set_config_missing_templates),
	JS_CFUNC_DEF("get_config_missing_templates", 0, &editor_export_platform_extension_class_get_config_missing_templates),
};




static void define_editor_export_platform_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_export_platform_extension_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_export_platform_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorExportPlatformExtension"] = class_id;
	classes_by_id[class_id] = "EditorExportPlatformExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_export_platform_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["EditorExportPlatform"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_export_platform_extension_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_export_platform_extension_class_proto_funcs, _countof(editor_export_platform_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_export_platform_extension_class_constructor, "EditorExportPlatformExtension", 0, JS_CFUNC_constructor, 0);
	define_editor_export_platform_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorExportPlatformExtension", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_export_platform_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/editor_export_platform';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_export_platform_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorExportPlatformExtension");
	return m;
}

JSModuleDef *js_init_editor_export_platform_extension_module(JSContext *ctx) {
	return _js_init_editor_export_platform_extension_module(ctx, "@godot/classes/editor_export_platform_extension");
}

void __register_editor_export_platform_extension() {
	js_init_editor_export_platform_extension_module(js_context());
}

void register_editor_export_platform_extension() {
	__register_editor_export_platform_extension();
}