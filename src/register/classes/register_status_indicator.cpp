#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/status_indicator.hpp>
using namespace godot;

static void status_indicator_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StatusIndicator"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef status_indicator_class_def = {
    "StatusIndicator",
    status_indicator_class_finalizer
};

static JSValue status_indicator_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StatusIndicator"];
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
        instance = memnew(StatusIndicator);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue status_indicator_class_set_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StatusIndicator::set_tooltip, ctx, this_val, argc, argv);
};
static JSValue status_indicator_class_get_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StatusIndicator::get_tooltip, ctx, this_val, argc, argv);
}
static JSValue status_indicator_class_set_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StatusIndicator::set_icon, ctx, this_val, argc, argv);
};
static JSValue status_indicator_class_get_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StatusIndicator::get_icon, ctx, this_val, argc, argv);
}
static JSValue status_indicator_class_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StatusIndicator::set_visible, ctx, this_val, argc, argv);
};
static JSValue status_indicator_class_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StatusIndicator::is_visible, ctx, this_val, argc, argv);
}
static JSValue status_indicator_class_set_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StatusIndicator::set_menu, ctx, this_val, argc, argv);
};
static JSValue status_indicator_class_get_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StatusIndicator::get_menu, ctx, this_val, argc, argv);
}
static JSValue status_indicator_class_get_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StatusIndicator::get_rect, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry status_indicator_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_tooltip", 1, &status_indicator_class_set_tooltip),
	JS_CFUNC_DEF("get_tooltip", 0, &status_indicator_class_get_tooltip),
	JS_CFUNC_DEF("set_icon", 1, &status_indicator_class_set_icon),
	JS_CFUNC_DEF("get_icon", 0, &status_indicator_class_get_icon),
	JS_CFUNC_DEF("set_visible", 1, &status_indicator_class_set_visible),
	JS_CFUNC_DEF("is_visible", 0, &status_indicator_class_is_visible),
	JS_CFUNC_DEF("set_menu", 1, &status_indicator_class_set_menu),
	JS_CFUNC_DEF("get_menu", 0, &status_indicator_class_get_menu),
	JS_CFUNC_DEF("get_rect", 0, &status_indicator_class_get_rect),
};


static JSValue status_indicator_class_get_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	StatusIndicator *opaque = static_cast<StatusIndicator *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_status_indicator_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tooltip"),
        JS_NewCFunction(ctx, status_indicator_class_get_tooltip, "get_tooltip", 0),
        JS_NewCFunction(ctx, status_indicator_class_set_tooltip, "set_tooltip", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "icon"),
        JS_NewCFunction(ctx, status_indicator_class_get_icon, "get_icon", 0),
        JS_NewCFunction(ctx, status_indicator_class_set_icon, "set_icon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "menu"),
        JS_NewCFunction(ctx, status_indicator_class_get_menu, "get_menu", 0),
        JS_NewCFunction(ctx, status_indicator_class_set_menu, "set_menu", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible"),
        JS_NewCFunction(ctx, status_indicator_class_is_visible, "is_visible", 0),
        JS_NewCFunction(ctx, status_indicator_class_set_visible, "set_visible", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pressed"),
		JS_NewCFunction(ctx, status_indicator_class_get_pressed_signal, "get_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_status_indicator_enum(JSContext *ctx, JSValue ctor) {
}

static int js_status_indicator_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StatusIndicator"] = class_id;
	classes_by_id[class_id] = "StatusIndicator";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &status_indicator_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_status_indicator_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, status_indicator_class_proto_funcs, _countof(status_indicator_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, status_indicator_class_constructor, "StatusIndicator", 0, JS_CFUNC_constructor, 0);
	define_status_indicator_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StatusIndicator", ctor);
	ctor_list["StatusIndicator"] = ctor;

	return 0;
}

JSModuleDef *_js_init_status_indicator_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_status_indicator_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StatusIndicator");
	return m;
}

JSModuleDef *js_init_status_indicator_module(JSContext *ctx) {
	return _js_init_status_indicator_module(ctx, "@godot/classes/status_indicator");
}

void __register_status_indicator() {
	js_init_status_indicator_module(js_context());
}

void register_status_indicator() {
	__register_status_indicator();
}