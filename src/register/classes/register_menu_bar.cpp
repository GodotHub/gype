#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/menu_bar.hpp>
using namespace godot;

static void menu_bar_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MenuBar"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef menu_bar_class_def = {
    "MenuBar",
    menu_bar_class_finalizer
};

static JSValue menu_bar_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MenuBar"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MenuBar *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MenuBar *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MenuBar);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue menu_bar_class_set_switch_on_hover(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_switch_on_hover, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_is_switch_on_hover(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MenuBar::is_switch_on_hover, ctx, this_val, argc, argv);
}
static JSValue menu_bar_class_set_disable_shortcuts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_disable_shortcuts, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_set_prefer_global_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_prefer_global_menu, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_is_prefer_global_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::is_prefer_global_menu, ctx, this_val, argc, argv);
}
static JSValue menu_bar_class_is_native_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::is_native_menu, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_menu_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::get_menu_count, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_set_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_text_direction, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::get_text_direction, ctx, this_val, argc, argv);
}
static JSValue menu_bar_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_language, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		MenuBar *obj = static_cast<MenuBar *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_language();
	};
	proxy->setter = [this_val](const String &value) -> void {
		MenuBar *js_proxy = static_cast<MenuBar *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_language(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue menu_bar_class_set_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_flat, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_is_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::is_flat, ctx, this_val, argc, argv);
}
static JSValue menu_bar_class_set_start_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_start_index, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_start_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::get_start_index, ctx, this_val, argc, argv);
}
static JSValue menu_bar_class_set_menu_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_menu_title, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_menu_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::get_menu_title, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_set_menu_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_menu_tooltip, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_menu_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::get_menu_tooltip, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_set_menu_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_menu_disabled, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_is_menu_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::is_menu_disabled, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_set_menu_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MenuBar::set_menu_hidden, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_is_menu_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::is_menu_hidden, ctx, this_val, argc, argv);
};
static JSValue menu_bar_class_get_menu_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MenuBar::get_menu_popup, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry menu_bar_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_switch_on_hover", 1, &menu_bar_class_set_switch_on_hover),
	JS_CFUNC_DEF("is_switch_on_hover", 0, &menu_bar_class_is_switch_on_hover),
	JS_CFUNC_DEF("set_disable_shortcuts", 1, &menu_bar_class_set_disable_shortcuts),
	JS_CFUNC_DEF("set_prefer_global_menu", 1, &menu_bar_class_set_prefer_global_menu),
	JS_CFUNC_DEF("is_prefer_global_menu", 0, &menu_bar_class_is_prefer_global_menu),
	JS_CFUNC_DEF("is_native_menu", 0, &menu_bar_class_is_native_menu),
	JS_CFUNC_DEF("get_menu_count", 0, &menu_bar_class_get_menu_count),
	JS_CFUNC_DEF("set_text_direction", 1, &menu_bar_class_set_text_direction),
	JS_CFUNC_DEF("get_text_direction", 0, &menu_bar_class_get_text_direction),
	JS_CFUNC_DEF("set_language", 1, &menu_bar_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &menu_bar_class_get_language),
	JS_CFUNC_DEF("set_flat", 1, &menu_bar_class_set_flat),
	JS_CFUNC_DEF("is_flat", 0, &menu_bar_class_is_flat),
	JS_CFUNC_DEF("set_start_index", 1, &menu_bar_class_set_start_index),
	JS_CFUNC_DEF("get_start_index", 0, &menu_bar_class_get_start_index),
	JS_CFUNC_DEF("set_menu_title", 2, &menu_bar_class_set_menu_title),
	JS_CFUNC_DEF("get_menu_title", 1, &menu_bar_class_get_menu_title),
	JS_CFUNC_DEF("set_menu_tooltip", 2, &menu_bar_class_set_menu_tooltip),
	JS_CFUNC_DEF("get_menu_tooltip", 1, &menu_bar_class_get_menu_tooltip),
	JS_CFUNC_DEF("set_menu_disabled", 2, &menu_bar_class_set_menu_disabled),
	JS_CFUNC_DEF("is_menu_disabled", 1, &menu_bar_class_is_menu_disabled),
	JS_CFUNC_DEF("set_menu_hidden", 2, &menu_bar_class_set_menu_hidden),
	JS_CFUNC_DEF("is_menu_hidden", 1, &menu_bar_class_is_menu_hidden),
	JS_CFUNC_DEF("get_menu_popup", 1, &menu_bar_class_get_menu_popup),
};




static void define_menu_bar_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flat"),
        JS_NewCFunction(ctx, menu_bar_class_is_flat, "is_flat", 0),
        JS_NewCFunction(ctx, menu_bar_class_set_flat, "set_flat", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "start_index"),
        JS_NewCFunction(ctx, menu_bar_class_get_start_index, "get_start_index", 0),
        JS_NewCFunction(ctx, menu_bar_class_set_start_index, "set_start_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "switch_on_hover"),
        JS_NewCFunction(ctx, menu_bar_class_is_switch_on_hover, "is_switch_on_hover", 0),
        JS_NewCFunction(ctx, menu_bar_class_set_switch_on_hover, "set_switch_on_hover", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "prefer_global_menu"),
        JS_NewCFunction(ctx, menu_bar_class_is_prefer_global_menu, "is_prefer_global_menu", 0),
        JS_NewCFunction(ctx, menu_bar_class_set_prefer_global_menu, "set_prefer_global_menu", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_direction"),
        JS_NewCFunction(ctx, menu_bar_class_get_text_direction, "get_text_direction", 0),
        JS_NewCFunction(ctx, menu_bar_class_set_text_direction, "set_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, menu_bar_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, menu_bar_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
}

static void define_menu_bar_enum(JSContext *ctx, JSValue proto) {
}

static int js_menu_bar_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MenuBar"] = class_id;
	classes_by_id[class_id] = "MenuBar";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &menu_bar_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_menu_bar_property(ctx, proto);
	define_menu_bar_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, menu_bar_class_proto_funcs, _countof(menu_bar_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, menu_bar_class_constructor, "MenuBar", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MenuBar", ctor);

	return 0;
}

JSModuleDef *_js_init_menu_bar_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_menu_bar_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MenuBar");
	return m;
}

JSModuleDef *js_init_menu_bar_module(JSContext *ctx) {
	return _js_init_menu_bar_module(ctx, "@godot/classes/menu_bar");
}

void __register_menu_bar() {
	js_init_menu_bar_module(js_context());
}

void register_menu_bar() {
	__register_menu_bar();
}