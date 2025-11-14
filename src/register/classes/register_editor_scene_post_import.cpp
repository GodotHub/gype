#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_scene_post_import.hpp>
using namespace godot;

static void editor_scene_post_import_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorScenePostImport"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_scene_post_import_class_def = {
    "EditorScenePostImport",
    editor_scene_post_import_class_finalizer
};

static JSValue editor_scene_post_import_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorScenePostImport"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorScenePostImport *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorScenePostImport *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorScenePostImport);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_scene_post_import_class_get_source_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorScenePostImport::get_source_file, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_scene_post_import_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_source_file", 0, &editor_scene_post_import_class_get_source_file),
};




static void define_editor_scene_post_import_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_scene_post_import_enum(JSContext *ctx, JSValue proto) {
}

static int js_editor_scene_post_import_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorScenePostImport"] = class_id;
	classes_by_id[class_id] = "EditorScenePostImport";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_scene_post_import_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_scene_post_import_property(ctx, proto);
	define_editor_scene_post_import_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_scene_post_import_class_proto_funcs, _countof(editor_scene_post_import_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_scene_post_import_class_constructor, "EditorScenePostImport", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorScenePostImport", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_scene_post_import_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_scene_post_import_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorScenePostImport");
	return m;
}

JSModuleDef *js_init_editor_scene_post_import_module(JSContext *ctx) {
	return _js_init_editor_scene_post_import_module(ctx, "@godot/classes/editor_scene_post_import");
}

void __register_editor_scene_post_import() {
	js_init_editor_scene_post_import_module(js_context());
}

void register_editor_scene_post_import() {
	__register_editor_scene_post_import();
}