#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_export_preset.hpp>
using namespace godot;

static void editor_export_preset_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorExportPreset"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_export_preset_class_def = {
    "EditorExportPreset",
    editor_export_preset_class_finalizer
};

static JSValue editor_export_preset_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorExportPreset"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorExportPreset *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorExportPreset *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorExportPreset);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_export_preset_class_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::has, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_files_to_export(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_files_to_export, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_customized_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_customized_files, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_customized_files_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_customized_files_count, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_has_export_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPreset::has_export_file, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_file_export_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_file_export_mode, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_project_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPreset::get_project_setting, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_preset_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_preset_name, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_is_runnable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::is_runnable, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_are_advanced_options_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::are_advanced_options_enabled, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_is_dedicated_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::is_dedicated_server, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_export_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_export_filter, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_include_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_include_filter, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_exclude_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_exclude_filter, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_custom_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_custom_features, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_patches(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_patches, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_export_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_export_path, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_encryption_in_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_encryption_in_filter, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_encryption_ex_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_encryption_ex_filter, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_encrypt_pck(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_encrypt_pck, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_encrypt_directory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_encrypt_directory, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_encryption_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_encryption_key, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_script_export_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_script_export_mode, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_or_env(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_or_env, ctx, this_val, argc, argv);
};
static JSValue editor_export_preset_class_get_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPreset::get_version, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_export_preset_class_proto_funcs[] = {
	JS_CFUNC_DEF("has", 1, &editor_export_preset_class_has),
	JS_CFUNC_DEF("get_files_to_export", 0, &editor_export_preset_class_get_files_to_export),
	JS_CFUNC_DEF("get_customized_files", 0, &editor_export_preset_class_get_customized_files),
	JS_CFUNC_DEF("get_customized_files_count", 0, &editor_export_preset_class_get_customized_files_count),
	JS_CFUNC_DEF("has_export_file", 1, &editor_export_preset_class_has_export_file),
	JS_CFUNC_DEF("get_file_export_mode", 2, &editor_export_preset_class_get_file_export_mode),
	JS_CFUNC_DEF("get_project_setting", 1, &editor_export_preset_class_get_project_setting),
	JS_CFUNC_DEF("get_preset_name", 0, &editor_export_preset_class_get_preset_name),
	JS_CFUNC_DEF("is_runnable", 0, &editor_export_preset_class_is_runnable),
	JS_CFUNC_DEF("are_advanced_options_enabled", 0, &editor_export_preset_class_are_advanced_options_enabled),
	JS_CFUNC_DEF("is_dedicated_server", 0, &editor_export_preset_class_is_dedicated_server),
	JS_CFUNC_DEF("get_export_filter", 0, &editor_export_preset_class_get_export_filter),
	JS_CFUNC_DEF("get_include_filter", 0, &editor_export_preset_class_get_include_filter),
	JS_CFUNC_DEF("get_exclude_filter", 0, &editor_export_preset_class_get_exclude_filter),
	JS_CFUNC_DEF("get_custom_features", 0, &editor_export_preset_class_get_custom_features),
	JS_CFUNC_DEF("get_patches", 0, &editor_export_preset_class_get_patches),
	JS_CFUNC_DEF("get_export_path", 0, &editor_export_preset_class_get_export_path),
	JS_CFUNC_DEF("get_encryption_in_filter", 0, &editor_export_preset_class_get_encryption_in_filter),
	JS_CFUNC_DEF("get_encryption_ex_filter", 0, &editor_export_preset_class_get_encryption_ex_filter),
	JS_CFUNC_DEF("get_encrypt_pck", 0, &editor_export_preset_class_get_encrypt_pck),
	JS_CFUNC_DEF("get_encrypt_directory", 0, &editor_export_preset_class_get_encrypt_directory),
	JS_CFUNC_DEF("get_encryption_key", 0, &editor_export_preset_class_get_encryption_key),
	JS_CFUNC_DEF("get_script_export_mode", 0, &editor_export_preset_class_get_script_export_mode),
	JS_CFUNC_DEF("get_or_env", 2, &editor_export_preset_class_get_or_env),
	JS_CFUNC_DEF("get_version", 2, &editor_export_preset_class_get_version),
};




static void define_editor_export_preset_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_export_preset_enum(JSContext *ctx, JSValue ctor) {
	JSValue ExportFilter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ExportFilter_obj, "EXPORT_ALL_RESOURCES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ExportFilter_obj, "EXPORT_SELECTED_SCENES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ExportFilter_obj, "EXPORT_SELECTED_RESOURCES", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ExportFilter_obj, "EXCLUDE_SELECTED_RESOURCES", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ExportFilter_obj, "EXPORT_CUSTOMIZED", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "ExportFilter", ExportFilter_obj);
	JSValue FileExportMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FileExportMode_obj, "MODE_FILE_NOT_CUSTOMIZED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FileExportMode_obj, "MODE_FILE_STRIP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FileExportMode_obj, "MODE_FILE_KEEP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FileExportMode_obj, "MODE_FILE_REMOVE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "FileExportMode", FileExportMode_obj);
	JSValue ScriptExportMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ScriptExportMode_obj, "MODE_SCRIPT_TEXT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ScriptExportMode_obj, "MODE_SCRIPT_BINARY_TOKENS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ScriptExportMode_obj, "MODE_SCRIPT_BINARY_TOKENS_COMPRESSED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ScriptExportMode", ScriptExportMode_obj);
}

static int js_editor_export_preset_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorExportPreset"] = class_id;
	classes_by_id[class_id] = "EditorExportPreset";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_export_preset_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_export_preset_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_export_preset_class_proto_funcs, _countof(editor_export_preset_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_export_preset_class_constructor, "EditorExportPreset", 0, JS_CFUNC_constructor, 0);
	define_editor_export_preset_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorExportPreset", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_export_preset_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_export_preset_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorExportPreset");
	return m;
}

JSModuleDef *js_init_editor_export_preset_module(JSContext *ctx) {
	return _js_init_editor_export_preset_module(ctx, "@godot/classes/editor_export_preset");
}

void __register_editor_export_preset() {
	js_init_editor_export_preset_module(js_context());
}

void register_editor_export_preset() {
	__register_editor_export_preset();
}