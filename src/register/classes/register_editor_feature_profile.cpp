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
#include <godot_cpp/classes/editor_feature_profile.hpp>
using namespace godot;

static void editor_feature_profile_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorFeatureProfile"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_feature_profile_class_def = {
    "EditorFeatureProfile",
    editor_feature_profile_class_finalizer
};

static JSValue editor_feature_profile_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorFeatureProfile"];
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
        instance = memnew(EditorFeatureProfile);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_feature_profile_class_set_disable_class(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFeatureProfile::set_disable_class, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_is_class_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFeatureProfile::is_class_disabled, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_set_disable_class_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFeatureProfile::set_disable_class_editor, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_is_class_editor_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFeatureProfile::is_class_editor_disabled, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_set_disable_class_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFeatureProfile::set_disable_class_property, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_is_class_property_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFeatureProfile::is_class_property_disabled, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_set_disable_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorFeatureProfile::set_disable_feature, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_is_feature_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorFeatureProfile::is_feature_disabled, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_get_feature_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFeatureProfile::get_feature_name, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_save_to_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFeatureProfile::save_to_file, ctx, this_val, argc, argv);
};
static JSValue editor_feature_profile_class_load_from_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorFeatureProfile::load_from_file, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_feature_profile_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_disable_class", 2, &editor_feature_profile_class_set_disable_class),
	JS_CFUNC_DEF("is_class_disabled", 1, &editor_feature_profile_class_is_class_disabled),
	JS_CFUNC_DEF("set_disable_class_editor", 2, &editor_feature_profile_class_set_disable_class_editor),
	JS_CFUNC_DEF("is_class_editor_disabled", 1, &editor_feature_profile_class_is_class_editor_disabled),
	JS_CFUNC_DEF("set_disable_class_property", 3, &editor_feature_profile_class_set_disable_class_property),
	JS_CFUNC_DEF("is_class_property_disabled", 2, &editor_feature_profile_class_is_class_property_disabled),
	JS_CFUNC_DEF("set_disable_feature", 2, &editor_feature_profile_class_set_disable_feature),
	JS_CFUNC_DEF("is_feature_disabled", 1, &editor_feature_profile_class_is_feature_disabled),
	JS_CFUNC_DEF("get_feature_name", 1, &editor_feature_profile_class_get_feature_name),
	JS_CFUNC_DEF("save_to_file", 1, &editor_feature_profile_class_save_to_file),
	JS_CFUNC_DEF("load_from_file", 1, &editor_feature_profile_class_load_from_file),
};




static void define_editor_feature_profile_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_feature_profile_enum(JSContext *ctx, JSValue ctor) {
	JSValue Feature_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_3D", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_SCRIPT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_ASSET_LIB", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_SCENE_TREE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_NODE_DOCK", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_FILESYSTEM_DOCK", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_IMPORT_DOCK", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_HISTORY_DOCK", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_GAME", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_MAX", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, ctor, "Feature", Feature_obj);
}

static int js_editor_feature_profile_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorFeatureProfile"] = class_id;
	classes_by_id[class_id] = "EditorFeatureProfile";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_feature_profile_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_feature_profile_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_feature_profile_class_proto_funcs, _countof(editor_feature_profile_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_feature_profile_class_constructor, "EditorFeatureProfile", 0, JS_CFUNC_constructor, 0);
	define_editor_feature_profile_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorFeatureProfile", ctor);
	ctor_list["EditorFeatureProfile"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_feature_profile_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_feature_profile_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorFeatureProfile");
	return m;
}

JSModuleDef *js_init_editor_feature_profile_module(JSContext *ctx) {
	return _js_init_editor_feature_profile_module(ctx, "@godot/classes/editor_feature_profile");
}

void __register_editor_feature_profile() {
	js_init_editor_feature_profile_module(js_context());
}

void register_editor_feature_profile() {
	__register_editor_feature_profile();
}