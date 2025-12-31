#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/theme.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/theme_db.hpp>


using namespace godot;

static void theme_db_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef theme_db_class_def = {
	"_ThemeDB",
	theme_db_class_finalizer
};

static JSValue theme_db_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_ThemeDB"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	ThemeDB *theme_db_class = ThemeDB::get_singleton();
	if (!theme_db_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(theme_db_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue theme_db_class_get_default_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_default_theme, ctx, this_val, argc, argv);
};
static JSValue theme_db_class_get_project_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_project_theme, ctx, this_val, argc, argv);
};
static JSValue theme_db_class_set_fallback_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ThemeDB::set_fallback_base_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue theme_db_class_get_fallback_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_fallback_base_scale, ctx, this_val, argc, argv);
};
static JSValue theme_db_class_set_fallback_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ThemeDB::set_fallback_font, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue theme_db_class_get_fallback_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_fallback_font, ctx, this_val, argc, argv);
};
static JSValue theme_db_class_set_fallback_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ThemeDB::set_fallback_font_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue theme_db_class_get_fallback_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_fallback_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_db_class_set_fallback_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ThemeDB::set_fallback_icon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue theme_db_class_get_fallback_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_fallback_icon, ctx, this_val, argc, argv);
};
static JSValue theme_db_class_set_fallback_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ThemeDB::set_fallback_stylebox, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue theme_db_class_get_fallback_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ThemeDB::get_fallback_stylebox, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry theme_db_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_default_theme", 0, &theme_db_class_get_default_theme),
	JS_CFUNC_DEF("get_project_theme", 0, &theme_db_class_get_project_theme),
	JS_CFUNC_DEF("set_fallback_base_scale", 1, &theme_db_class_set_fallback_base_scale),
	JS_CFUNC_DEF("get_fallback_base_scale", 0, &theme_db_class_get_fallback_base_scale),
	JS_CFUNC_DEF("set_fallback_font", 1, &theme_db_class_set_fallback_font),
	JS_CFUNC_DEF("get_fallback_font", 0, &theme_db_class_get_fallback_font),
	JS_CFUNC_DEF("set_fallback_font_size", 1, &theme_db_class_set_fallback_font_size),
	JS_CFUNC_DEF("get_fallback_font_size", 0, &theme_db_class_get_fallback_font_size),
	JS_CFUNC_DEF("set_fallback_icon", 1, &theme_db_class_set_fallback_icon),
	JS_CFUNC_DEF("get_fallback_icon", 0, &theme_db_class_get_fallback_icon),
	JS_CFUNC_DEF("set_fallback_stylebox", 1, &theme_db_class_set_fallback_stylebox),
	JS_CFUNC_DEF("get_fallback_stylebox", 0, &theme_db_class_get_fallback_stylebox),
};




static int js_theme_db_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_ThemeDB"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &theme_db_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, theme_db_class_proto_funcs, _countof(theme_db_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, theme_db_class_constructor, "_ThemeDB", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "ThemeDB", singleton);

	return 0;
}

JSModuleDef *_js_init_theme_db_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_theme_db_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ThemeDB");
	return m;
}

void register_theme_db() {
	_js_init_theme_db_module(js_context(), "@godot/classes/theme_db");
}