#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/menu_button.hpp>
using namespace godot;

static void menu_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MenuButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef menu_button_class_def = {
    "MenuButton",
    menu_button_class_finalizer
};

static JSValue menu_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MenuButton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MenuButton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MenuButton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MenuButton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue menu_button_class_get_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuButton::get_popup, ctx, this_val, argc, argv);
};
static JSValue menu_button_class_show_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuButton::show_popup, ctx, this_val, argc, argv);
};
static JSValue menu_button_class_set_switch_on_hover(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuButton::set_switch_on_hover, ctx, this_val, argc, argv);
};
static JSValue menu_button_class_is_switch_on_hover(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MenuButton::is_switch_on_hover, ctx, this_val, argc, argv);
}
static JSValue menu_button_class_set_disable_shortcuts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuButton::set_disable_shortcuts, ctx, this_val, argc, argv);
};
static JSValue menu_button_class_set_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuButton::set_item_count, ctx, this_val, argc, argv);
};
static JSValue menu_button_class_get_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuButton::get_item_count, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry menu_button_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_popup", 0, &menu_button_class_get_popup),
	JS_CFUNC_DEF("show_popup", 0, &menu_button_class_show_popup),
	JS_CFUNC_DEF("set_switch_on_hover", 1, &menu_button_class_set_switch_on_hover),
	JS_CFUNC_DEF("is_switch_on_hover", 0, &menu_button_class_is_switch_on_hover),
	JS_CFUNC_DEF("set_disable_shortcuts", 1, &menu_button_class_set_disable_shortcuts),
	JS_CFUNC_DEF("set_item_count", 1, &menu_button_class_set_item_count),
	JS_CFUNC_DEF("get_item_count", 0, &menu_button_class_get_item_count),
};


static JSValue menu_button_class_get_about_to_popup_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MenuButton *opaque = static_cast<MenuButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "about_to_popup_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "about_to_popup"));
		JS_DefinePropertyValueStr(ctx, this_val, "about_to_popup_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_menu_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "switch_on_hover"),
        JS_NewCFunction(ctx, menu_button_class_is_switch_on_hover, "is_switch_on_hover", 0),
        JS_NewCFunction(ctx, menu_button_class_set_switch_on_hover, "set_switch_on_hover", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "item_count"),
        JS_NewCFunction(ctx, menu_button_class_get_item_count, "get_item_count", 0),
        JS_NewCFunction(ctx, menu_button_class_set_item_count, "set_item_count", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "about_to_popup"),
		JS_NewCFunction(ctx, menu_button_class_get_about_to_popup_signal, "get_about_to_popup_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_menu_button_enum(JSContext *ctx, JSValue proto) {
}

static int js_menu_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MenuButton"] = class_id;
	classes_by_id[class_id] = "MenuButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &menu_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Button"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_menu_button_property(ctx, proto);
	define_menu_button_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, menu_button_class_proto_funcs, _countof(menu_button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, menu_button_class_constructor, "MenuButton", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MenuButton", ctor);

	return 0;
}

JSModuleDef *_js_init_menu_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/button';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_menu_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MenuButton");
	return m;
}

JSModuleDef *js_init_menu_button_module(JSContext *ctx) {
	return _js_init_menu_button_module(ctx, "@godot/classes/menu_button");
}

void __register_menu_button() {
	js_init_menu_button_module(js_context());
}

void register_menu_button() {
	__register_menu_button();
}