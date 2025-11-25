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
#include <godot_cpp/classes/editor_paths.hpp>
using namespace godot;

static void editor_paths_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorPaths"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_paths_class_def = {
    "EditorPaths",
    editor_paths_class_finalizer
};

static JSValue editor_paths_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorPaths"];
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
        instance = memnew(EditorPaths);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_paths_class_get_data_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPaths::get_data_dir, ctx, this_val, argc, argv);
};
static JSValue editor_paths_class_get_config_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPaths::get_config_dir, ctx, this_val, argc, argv);
};
static JSValue editor_paths_class_get_cache_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPaths::get_cache_dir, ctx, this_val, argc, argv);
};
static JSValue editor_paths_class_is_self_contained(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPaths::is_self_contained, ctx, this_val, argc, argv);
};
static JSValue editor_paths_class_get_self_contained_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPaths::get_self_contained_file, ctx, this_val, argc, argv);
};
static JSValue editor_paths_class_get_project_settings_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPaths::get_project_settings_dir, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_paths_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_data_dir", 0, &editor_paths_class_get_data_dir),
	JS_CFUNC_DEF("get_config_dir", 0, &editor_paths_class_get_config_dir),
	JS_CFUNC_DEF("get_cache_dir", 0, &editor_paths_class_get_cache_dir),
	JS_CFUNC_DEF("is_self_contained", 0, &editor_paths_class_is_self_contained),
	JS_CFUNC_DEF("get_self_contained_file", 0, &editor_paths_class_get_self_contained_file),
	JS_CFUNC_DEF("get_project_settings_dir", 0, &editor_paths_class_get_project_settings_dir),
};




static void define_editor_paths_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_paths_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_paths_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorPaths"] = class_id;
	classes_by_id[class_id] = "EditorPaths";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_paths_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_paths_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_paths_class_proto_funcs, _countof(editor_paths_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_paths_class_constructor, "EditorPaths", 0, JS_CFUNC_constructor, 0);
	define_editor_paths_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorPaths", ctor);
	ctor_list["EditorPaths"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_paths_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_paths_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorPaths");
	return m;
}

JSModuleDef *js_init_editor_paths_module(JSContext *ctx) {
	return _js_init_editor_paths_module(ctx, "@godot/classes/editor_paths");
}

void __register_editor_paths() {
	js_init_editor_paths_module(js_context());
}

void register_editor_paths() {
	__register_editor_paths();
}