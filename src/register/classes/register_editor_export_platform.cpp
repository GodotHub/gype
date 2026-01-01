#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_export_preset.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_export_platform.hpp>
using namespace godot;

static void editor_export_platform_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorExportPlatform"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_export_platform_class_def = {
    "EditorExportPlatform",
    editor_export_platform_class_finalizer
};

static JSValue editor_export_platform_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorExportPlatform"];
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
        instance = memnew(EditorExportPlatform);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_export_platform_class_get_os_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_os_name, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_create_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::create_preset, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_find_export_template(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::find_export_template, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_current_presets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_current_presets, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_save_pack(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::save_pack, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_save_zip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::save_zip, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_save_pack_patch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::save_pack_patch, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_save_zip_patch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::save_zip_patch, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_gen_export_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::gen_export_flags, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_export_project_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::export_project_files, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_export_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::export_project, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_export_pack(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::export_pack, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_export_zip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::export_zip, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_export_pack_patch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::export_pack_patch, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_export_zip_patch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::export_zip_patch, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_clear_messages(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlatform::clear_messages, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_add_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlatform::add_message, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_message_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_message_count, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_message_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_message_type, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_message_category(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_message_category, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_message_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_message_text, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_worst_message_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::get_worst_message_type, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_ssh_run_on_remote(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::ssh_run_on_remote, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_ssh_run_on_remote_no_wait(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::ssh_run_on_remote_no_wait, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_ssh_push_to_remote(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlatform::ssh_push_to_remote, ctx, this_val, argc, argv);
};
static JSValue editor_export_platform_class_get_internal_export_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorExportPlatform::get_internal_export_files, ctx, this_val, argc, argv);
};


static JSValue editor_export_platform_class_get_forced_export_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&EditorExportPlatform::get_forced_export_files, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_export_platform_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_os_name", 0, &editor_export_platform_class_get_os_name),
	JS_CFUNC_DEF("create_preset", 0, &editor_export_platform_class_create_preset),
	JS_CFUNC_DEF("find_export_template", 1, &editor_export_platform_class_find_export_template),
	JS_CFUNC_DEF("get_current_presets", 0, &editor_export_platform_class_get_current_presets),
	JS_CFUNC_DEF("save_pack", 4, &editor_export_platform_class_save_pack),
	JS_CFUNC_DEF("save_zip", 3, &editor_export_platform_class_save_zip),
	JS_CFUNC_DEF("save_pack_patch", 3, &editor_export_platform_class_save_pack_patch),
	JS_CFUNC_DEF("save_zip_patch", 3, &editor_export_platform_class_save_zip_patch),
	JS_CFUNC_DEF("gen_export_flags", 1, &editor_export_platform_class_gen_export_flags),
	JS_CFUNC_DEF("export_project_files", 4, &editor_export_platform_class_export_project_files),
	JS_CFUNC_DEF("export_project", 4, &editor_export_platform_class_export_project),
	JS_CFUNC_DEF("export_pack", 4, &editor_export_platform_class_export_pack),
	JS_CFUNC_DEF("export_zip", 4, &editor_export_platform_class_export_zip),
	JS_CFUNC_DEF("export_pack_patch", 5, &editor_export_platform_class_export_pack_patch),
	JS_CFUNC_DEF("export_zip_patch", 5, &editor_export_platform_class_export_zip_patch),
	JS_CFUNC_DEF("clear_messages", 0, &editor_export_platform_class_clear_messages),
	JS_CFUNC_DEF("add_message", 3, &editor_export_platform_class_add_message),
	JS_CFUNC_DEF("get_message_count", 0, &editor_export_platform_class_get_message_count),
	JS_CFUNC_DEF("get_message_type", 1, &editor_export_platform_class_get_message_type),
	JS_CFUNC_DEF("get_message_category", 1, &editor_export_platform_class_get_message_category),
	JS_CFUNC_DEF("get_message_text", 1, &editor_export_platform_class_get_message_text),
	JS_CFUNC_DEF("get_worst_message_type", 0, &editor_export_platform_class_get_worst_message_type),
	JS_CFUNC_DEF("ssh_run_on_remote", 6, &editor_export_platform_class_ssh_run_on_remote),
	JS_CFUNC_DEF("ssh_run_on_remote_no_wait", 5, &editor_export_platform_class_ssh_run_on_remote_no_wait),
	JS_CFUNC_DEF("ssh_push_to_remote", 5, &editor_export_platform_class_ssh_push_to_remote),
	JS_CFUNC_DEF("get_internal_export_files", 2, &editor_export_platform_class_get_internal_export_files),
};

static const JSCFunctionListEntry editor_export_platform_class_static_funcs[] = {
	JS_CFUNC_DEF("get_forced_export_files", 1, &editor_export_platform_class_get_forced_export_files),
};



static void define_editor_export_platform_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_export_platform_enum(JSContext *ctx, JSValue ctor) {
	JSValue ExportMessageType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ExportMessageType_obj, "EXPORT_MESSAGE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ExportMessageType_obj, "EXPORT_MESSAGE_INFO", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ExportMessageType_obj, "EXPORT_MESSAGE_WARNING", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ExportMessageType_obj, "EXPORT_MESSAGE_ERROR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ExportMessageType", ExportMessageType_obj);
	JSValue DebugFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DebugFlags_obj, "DEBUG_FLAG_DUMB_CLIENT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DebugFlags_obj, "DEBUG_FLAG_REMOTE_DEBUG", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DebugFlags_obj, "DEBUG_FLAG_REMOTE_DEBUG_LOCALHOST", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DebugFlags_obj, "DEBUG_FLAG_VIEW_COLLISIONS", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, DebugFlags_obj, "DEBUG_FLAG_VIEW_NAVIGATION", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ctor, "DebugFlags", DebugFlags_obj);
}

static int js_editor_export_platform_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorExportPlatform"] = class_id;
	classes_by_id[class_id] = "EditorExportPlatform";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_export_platform_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_export_platform_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_export_platform_class_proto_funcs, _countof(editor_export_platform_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_export_platform_class_constructor, "EditorExportPlatform", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, editor_export_platform_class_static_funcs, _countof(editor_export_platform_class_static_funcs));
	define_editor_export_platform_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorExportPlatform", ctor);
	ctor_list["EditorExportPlatform"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_export_platform_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_export_platform_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorExportPlatform");
	return m;
}

JSModuleDef *js_init_editor_export_platform_module(JSContext *ctx) {
	return _js_init_editor_export_platform_module(ctx, "@godot/classes/editor_export_platform");
}

void __register_editor_export_platform() {
	js_init_editor_export_platform_module(js_context());
}

void register_editor_export_platform() {
	__register_editor_export_platform();
}