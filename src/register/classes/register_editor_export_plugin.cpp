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
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_export_plugin.hpp>
using namespace godot;

static void editor_export_plugin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorExportPlugin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_export_plugin_class_def = {
    "EditorExportPlugin",
    editor_export_plugin_class_finalizer
};

static JSValue editor_export_plugin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorExportPlugin"];
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
        instance = memnew(EditorExportPlugin);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_export_plugin_class_add_shared_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_shared_object, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_file, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_project_static_lib(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_project_static_lib, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_framework(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_framework, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_embedded_framework(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_embedded_framework, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_plist_content(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_plist_content, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_linker_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_linker_flags, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_bundle_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_bundle_file, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_apple_embedded_platform_cpp_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_apple_embedded_platform_cpp_code, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_project_static_lib(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_project_static_lib, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_framework(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_framework, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_embedded_framework(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_embedded_framework, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_plist_content(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_plist_content, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_linker_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_linker_flags, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_bundle_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_bundle_file, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_ios_cpp_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_ios_cpp_code, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_add_macos_plugin_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::add_macos_plugin_file, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_skip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorExportPlugin::skip, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_get_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlugin::get_option, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_get_export_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlugin::get_export_preset, ctx, this_val, argc, argv);
};
static JSValue editor_export_plugin_class_get_export_platform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorExportPlugin::get_export_platform, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_export_plugin_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_shared_object", 3, &editor_export_plugin_class_add_shared_object),
	JS_CFUNC_DEF("add_file", 3, &editor_export_plugin_class_add_file),
	JS_CFUNC_DEF("add_apple_embedded_platform_project_static_lib", 1, &editor_export_plugin_class_add_apple_embedded_platform_project_static_lib),
	JS_CFUNC_DEF("add_apple_embedded_platform_framework", 1, &editor_export_plugin_class_add_apple_embedded_platform_framework),
	JS_CFUNC_DEF("add_apple_embedded_platform_embedded_framework", 1, &editor_export_plugin_class_add_apple_embedded_platform_embedded_framework),
	JS_CFUNC_DEF("add_apple_embedded_platform_plist_content", 1, &editor_export_plugin_class_add_apple_embedded_platform_plist_content),
	JS_CFUNC_DEF("add_apple_embedded_platform_linker_flags", 1, &editor_export_plugin_class_add_apple_embedded_platform_linker_flags),
	JS_CFUNC_DEF("add_apple_embedded_platform_bundle_file", 1, &editor_export_plugin_class_add_apple_embedded_platform_bundle_file),
	JS_CFUNC_DEF("add_apple_embedded_platform_cpp_code", 1, &editor_export_plugin_class_add_apple_embedded_platform_cpp_code),
	JS_CFUNC_DEF("add_ios_project_static_lib", 1, &editor_export_plugin_class_add_ios_project_static_lib),
	JS_CFUNC_DEF("add_ios_framework", 1, &editor_export_plugin_class_add_ios_framework),
	JS_CFUNC_DEF("add_ios_embedded_framework", 1, &editor_export_plugin_class_add_ios_embedded_framework),
	JS_CFUNC_DEF("add_ios_plist_content", 1, &editor_export_plugin_class_add_ios_plist_content),
	JS_CFUNC_DEF("add_ios_linker_flags", 1, &editor_export_plugin_class_add_ios_linker_flags),
	JS_CFUNC_DEF("add_ios_bundle_file", 1, &editor_export_plugin_class_add_ios_bundle_file),
	JS_CFUNC_DEF("add_ios_cpp_code", 1, &editor_export_plugin_class_add_ios_cpp_code),
	JS_CFUNC_DEF("add_macos_plugin_file", 1, &editor_export_plugin_class_add_macos_plugin_file),
	JS_CFUNC_DEF("skip", 0, &editor_export_plugin_class_skip),
	JS_CFUNC_DEF("get_option", 1, &editor_export_plugin_class_get_option),
	JS_CFUNC_DEF("get_export_preset", 0, &editor_export_plugin_class_get_export_preset),
	JS_CFUNC_DEF("get_export_platform", 0, &editor_export_plugin_class_get_export_platform),
};




static void define_editor_export_plugin_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_export_plugin_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_export_plugin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorExportPlugin"] = class_id;
	classes_by_id[class_id] = "EditorExportPlugin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_export_plugin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_export_plugin_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_export_plugin_class_proto_funcs, _countof(editor_export_plugin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_export_plugin_class_constructor, "EditorExportPlugin", 0, JS_CFUNC_constructor, 0);
	define_editor_export_plugin_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorExportPlugin", ctor);
	ctor_list["EditorExportPlugin"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_export_plugin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_export_plugin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorExportPlugin");
	return m;
}

JSModuleDef *js_init_editor_export_plugin_module(JSContext *ctx) {
	return _js_init_editor_export_plugin_module(ctx, "@godot/classes/editor_export_plugin");
}

void __register_editor_export_plugin() {
	js_init_editor_export_plugin_module(js_context());
}

void register_editor_export_plugin() {
	__register_editor_export_plugin();
}