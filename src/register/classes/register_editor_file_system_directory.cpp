#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_file_system_directory.hpp>
using namespace godot;

static void editor_file_system_directory_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorFileSystemDirectory"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_file_system_directory_class_def = {
    "EditorFileSystemDirectory",
    editor_file_system_directory_class_finalizer
};

static JSValue editor_file_system_directory_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorFileSystemDirectory"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorFileSystemDirectory *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorFileSystemDirectory *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorFileSystemDirectory);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_file_system_directory_class_get_subdir_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_subdir_count, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_subdir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFileSystemDirectory::get_subdir, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file_count, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file_path, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file_type, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file_script_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file_script_class_name, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file_script_class_extends(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file_script_class_extends, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_file_import_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_file_import_is_valid, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFileSystemDirectory::get_name, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::get_path, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_get_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFileSystemDirectory::get_parent, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_find_file_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::find_file_index, ctx, this_val, argc, argv);
};
static JSValue editor_file_system_directory_class_find_dir_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFileSystemDirectory::find_dir_index, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_file_system_directory_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_subdir_count", 0, &editor_file_system_directory_class_get_subdir_count),
	JS_CFUNC_DEF("get_subdir", 1, &editor_file_system_directory_class_get_subdir),
	JS_CFUNC_DEF("get_file_count", 0, &editor_file_system_directory_class_get_file_count),
	JS_CFUNC_DEF("get_file", 1, &editor_file_system_directory_class_get_file),
	JS_CFUNC_DEF("get_file_path", 1, &editor_file_system_directory_class_get_file_path),
	JS_CFUNC_DEF("get_file_type", 1, &editor_file_system_directory_class_get_file_type),
	JS_CFUNC_DEF("get_file_script_class_name", 1, &editor_file_system_directory_class_get_file_script_class_name),
	JS_CFUNC_DEF("get_file_script_class_extends", 1, &editor_file_system_directory_class_get_file_script_class_extends),
	JS_CFUNC_DEF("get_file_import_is_valid", 1, &editor_file_system_directory_class_get_file_import_is_valid),
	JS_CFUNC_DEF("get_name", 0, &editor_file_system_directory_class_get_name),
	JS_CFUNC_DEF("get_path", 0, &editor_file_system_directory_class_get_path),
	JS_CFUNC_DEF("get_parent", 0, &editor_file_system_directory_class_get_parent),
	JS_CFUNC_DEF("find_file_index", 1, &editor_file_system_directory_class_find_file_index),
	JS_CFUNC_DEF("find_dir_index", 1, &editor_file_system_directory_class_find_dir_index),
};




static void define_editor_file_system_directory_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_file_system_directory_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_file_system_directory_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorFileSystemDirectory"] = class_id;
	classes_by_id[class_id] = "EditorFileSystemDirectory";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_file_system_directory_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_file_system_directory_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_file_system_directory_class_proto_funcs, _countof(editor_file_system_directory_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_file_system_directory_class_constructor, "EditorFileSystemDirectory", 0, JS_CFUNC_constructor, 0);
	define_editor_file_system_directory_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorFileSystemDirectory", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_file_system_directory_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_file_system_directory_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorFileSystemDirectory");
	return m;
}

JSModuleDef *js_init_editor_file_system_directory_module(JSContext *ctx) {
	return _js_init_editor_file_system_directory_module(ctx, "@godot/classes/editor_file_system_directory");
}

void __register_editor_file_system_directory() {
	js_init_editor_file_system_directory_module(js_context());
}

void register_editor_file_system_directory() {
	__register_editor_file_system_directory();
}