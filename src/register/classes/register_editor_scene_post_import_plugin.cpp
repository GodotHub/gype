#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_scene_post_import_plugin.hpp>
using namespace godot;

static void editor_scene_post_import_plugin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorScenePostImportPlugin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_scene_post_import_plugin_class_def = {
    "EditorScenePostImportPlugin",
    editor_scene_post_import_plugin_class_finalizer
};

static JSValue editor_scene_post_import_plugin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorScenePostImportPlugin"];
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
        instance = memnew(EditorScenePostImportPlugin);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_scene_post_import_plugin_class_get_option_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorScenePostImportPlugin::get_option_value, ctx, this_val, argc, argv);
};
static JSValue editor_scene_post_import_plugin_class_add_import_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorScenePostImportPlugin::add_import_option, ctx, this_val, argc, argv);
};
static JSValue editor_scene_post_import_plugin_class_add_import_option_advanced(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorScenePostImportPlugin::add_import_option_advanced, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_scene_post_import_plugin_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_option_value", 1, &editor_scene_post_import_plugin_class_get_option_value),
	JS_CFUNC_DEF("add_import_option", 2, &editor_scene_post_import_plugin_class_add_import_option),
	JS_CFUNC_DEF("add_import_option_advanced", 6, &editor_scene_post_import_plugin_class_add_import_option_advanced),
};




static void define_editor_scene_post_import_plugin_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_scene_post_import_plugin_enum(JSContext *ctx, JSValue ctor) {
	JSValue InternalImportCategory_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_NODE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_MESH_3D_NODE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_MESH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_MATERIAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_ANIMATION", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_ANIMATION_NODE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_SKELETON_3D_NODE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, InternalImportCategory_obj, "INTERNAL_IMPORT_CATEGORY_MAX", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "InternalImportCategory", InternalImportCategory_obj);
}

static int js_editor_scene_post_import_plugin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorScenePostImportPlugin"] = class_id;
	classes_by_id[class_id] = "EditorScenePostImportPlugin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_scene_post_import_plugin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_scene_post_import_plugin_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_scene_post_import_plugin_class_proto_funcs, _countof(editor_scene_post_import_plugin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_scene_post_import_plugin_class_constructor, "EditorScenePostImportPlugin", 0, JS_CFUNC_constructor, 0);
	define_editor_scene_post_import_plugin_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorScenePostImportPlugin", ctor);
	ctor_list["EditorScenePostImportPlugin"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_scene_post_import_plugin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_scene_post_import_plugin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorScenePostImportPlugin");
	return m;
}

JSModuleDef *js_init_editor_scene_post_import_plugin_module(JSContext *ctx) {
	return _js_init_editor_scene_post_import_plugin_module(ctx, "@godot/classes/editor_scene_post_import_plugin");
}

void __register_editor_scene_post_import_plugin() {
	js_init_editor_scene_post_import_plugin_module(js_context());
}

void register_editor_scene_post_import_plugin() {
	__register_editor_scene_post_import_plugin();
}