#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/project_settings.hpp>


using namespace godot;

static void project_settings_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef project_settings_class_def = {
	"_ProjectSettings",
	project_settings_class_finalizer
};

static JSValue project_settings_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_ProjectSettings"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	ProjectSettings *project_settings_class = ProjectSettings::get_singleton();
	if (!project_settings_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(project_settings_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue project_settings_class_has_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::has_setting, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_set_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::set_setting, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_get_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::get_setting, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_get_setting_with_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::get_setting_with_override, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_get_global_class_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ProjectSettings::get_global_class_list, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_get_setting_with_override_and_custom_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::get_setting_with_override_and_custom_features, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_set_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::set_order, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_get_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::get_order, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_set_initial_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::set_initial_value, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_set_as_basic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::set_as_basic, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_set_as_internal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::set_as_internal, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_add_property_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::add_property_info, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_set_restart_if_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::set_restart_if_changed, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ProjectSettings::clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue project_settings_class_localize_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::localize_path, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_globalize_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&ProjectSettings::globalize_path, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_save(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ProjectSettings::save, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_load_resource_pack(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ProjectSettings::load_resource_pack, ctx, this_val, argc, argv);
};
static JSValue project_settings_class_save_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ProjectSettings::save_custom, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry project_settings_class_proto_funcs[] = {
	JS_CFUNC_DEF("has_setting", 1, &project_settings_class_has_setting),
	JS_CFUNC_DEF("set_setting", 2, &project_settings_class_set_setting),
	JS_CFUNC_DEF("get_setting", 2, &project_settings_class_get_setting),
	JS_CFUNC_DEF("get_setting_with_override", 1, &project_settings_class_get_setting_with_override),
	JS_CFUNC_DEF("get_global_class_list", 0, &project_settings_class_get_global_class_list),
	JS_CFUNC_DEF("get_setting_with_override_and_custom_features", 2, &project_settings_class_get_setting_with_override_and_custom_features),
	JS_CFUNC_DEF("set_order", 2, &project_settings_class_set_order),
	JS_CFUNC_DEF("get_order", 1, &project_settings_class_get_order),
	JS_CFUNC_DEF("set_initial_value", 2, &project_settings_class_set_initial_value),
	JS_CFUNC_DEF("set_as_basic", 2, &project_settings_class_set_as_basic),
	JS_CFUNC_DEF("set_as_internal", 2, &project_settings_class_set_as_internal),
	JS_CFUNC_DEF("add_property_info", 1, &project_settings_class_add_property_info),
	JS_CFUNC_DEF("set_restart_if_changed", 2, &project_settings_class_set_restart_if_changed),
	JS_CFUNC_DEF("clear", 1, &project_settings_class_clear),
	JS_CFUNC_DEF("localize_path", 1, &project_settings_class_localize_path),
	JS_CFUNC_DEF("globalize_path", 1, &project_settings_class_globalize_path),
	JS_CFUNC_DEF("save", 0, &project_settings_class_save),
	JS_CFUNC_DEF("load_resource_pack", 3, &project_settings_class_load_resource_pack),
	JS_CFUNC_DEF("save_custom", 1, &project_settings_class_save_custom),
};




static int js_project_settings_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_ProjectSettings"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &project_settings_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, project_settings_class_proto_funcs, _countof(project_settings_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, project_settings_class_constructor, "_ProjectSettings", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "ProjectSettings", singleton);

	return 0;
}

JSModuleDef *_js_init_project_settings_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_project_settings_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ProjectSettings");
	return m;
}

void register_project_settings() {
	_js_init_project_settings_module(js_context(), "@godot/classes/project_settings");
}