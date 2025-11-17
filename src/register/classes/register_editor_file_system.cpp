#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_file_system_directory.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_file_system.hpp>
using namespace godot;

static void editor_file_system_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorFileSystem"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_file_system_class_def = {
    "EditorFileSystem",
    editor_file_system_class_finalizer
};

static JSValue editor_file_system_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorFileSystem"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorFileSystem *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorFileSystem *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorFileSystem);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_file_system_class_get_filesystem(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFileSystem::get_filesystem, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_is_scanning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystem::is_scanning, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_get_scanning_progress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystem::get_scanning_progress, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_scan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFileSystem::scan, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_scan_sources(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFileSystem::scan_sources, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_update_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFileSystem::update_file, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_get_filesystem_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFileSystem::get_filesystem_path, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_get_file_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystem::get_file_type, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_class_reimport_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFileSystem::reimport_files, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_file_system_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_filesystem", 0, &editor_file_system_class_get_filesystem),
	JS_CFUNC_DEF("is_scanning", 0, &editor_file_system_class_is_scanning),
	JS_CFUNC_DEF("get_scanning_progress", 0, &editor_file_system_class_get_scanning_progress),
	JS_CFUNC_DEF("scan", 0, &editor_file_system_class_scan),
	JS_CFUNC_DEF("scan_sources", 0, &editor_file_system_class_scan_sources),
	JS_CFUNC_DEF("update_file", 1, &editor_file_system_class_update_file),
	JS_CFUNC_DEF("get_filesystem_path", 1, &editor_file_system_class_get_filesystem_path),
	JS_CFUNC_DEF("get_file_type", 1, &editor_file_system_class_get_file_type),
	JS_CFUNC_DEF("reimport_files", 1, &editor_file_system_class_reimport_files),
};


static JSValue editor_file_system_class_get_filesystem_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorFileSystem *opaque = static_cast<EditorFileSystem *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "filesystem_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "filesystem_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "filesystem_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_file_system_class_get_script_classes_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorFileSystem *opaque = static_cast<EditorFileSystem *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "script_classes_updated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "script_classes_updated"));
		JS_DefinePropertyValueStr(ctx, this_val, "script_classes_updated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_file_system_class_get_sources_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorFileSystem *opaque = static_cast<EditorFileSystem *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "sources_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "sources_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "sources_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_file_system_class_get_resources_reimporting_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorFileSystem *opaque = static_cast<EditorFileSystem *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resources_reimporting_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resources_reimporting"));
		JS_DefinePropertyValueStr(ctx, this_val, "resources_reimporting_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_file_system_class_get_resources_reimported_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorFileSystem *opaque = static_cast<EditorFileSystem *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resources_reimported_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resources_reimported"));
		JS_DefinePropertyValueStr(ctx, this_val, "resources_reimported_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_file_system_class_get_resources_reload_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorFileSystem *opaque = static_cast<EditorFileSystem *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resources_reload_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resources_reload"));
		JS_DefinePropertyValueStr(ctx, this_val, "resources_reload_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_file_system_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "filesystem_changed"),
		JS_NewCFunction(ctx, editor_file_system_class_get_filesystem_changed_signal, "get_filesystem_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "script_classes_updated"),
		JS_NewCFunction(ctx, editor_file_system_class_get_script_classes_updated_signal, "get_script_classes_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "sources_changed"),
		JS_NewCFunction(ctx, editor_file_system_class_get_sources_changed_signal, "get_sources_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resources_reimporting"),
		JS_NewCFunction(ctx, editor_file_system_class_get_resources_reimporting_signal, "get_resources_reimporting_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resources_reimported"),
		JS_NewCFunction(ctx, editor_file_system_class_get_resources_reimported_signal, "get_resources_reimported_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resources_reload"),
		JS_NewCFunction(ctx, editor_file_system_class_get_resources_reload_signal, "get_resources_reload_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_file_system_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_file_system_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorFileSystem"] = class_id;
	classes_by_id[class_id] = "EditorFileSystem";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_file_system_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_file_system_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_file_system_class_proto_funcs, _countof(editor_file_system_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_file_system_class_constructor, "EditorFileSystem", 0, JS_CFUNC_constructor, 0);
	define_editor_file_system_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorFileSystem", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_file_system_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_file_system_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorFileSystem");
	return m;
}

JSModuleDef *js_init_editor_file_system_module(JSContext *ctx) {
	return _js_init_editor_file_system_module(ctx, "@godot/classes/editor_file_system");
}

void __register_editor_file_system() {
	js_init_editor_file_system_module(js_context());
}

void register_editor_file_system() {
	__register_editor_file_system();
}