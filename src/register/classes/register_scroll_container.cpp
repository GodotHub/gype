#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/h_scroll_bar.hpp>
#include <godot_cpp/classes/v_scroll_bar.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/scroll_container.hpp>
using namespace godot;

static void scroll_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScrollContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef scroll_container_class_def = {
    "ScrollContainer",
    scroll_container_class_finalizer
};

static JSValue scroll_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScrollContainer"];
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
        instance = memnew(ScrollContainer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue scroll_container_class_set_h_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_h_scroll, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_h_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_h_scroll, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_v_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_v_scroll, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_v_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_v_scroll, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_horizontal_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_horizontal_custom_step, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_horizontal_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_horizontal_custom_step, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_vertical_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_vertical_custom_step, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_vertical_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_vertical_custom_step, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_horizontal_scroll_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_horizontal_scroll_mode, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_horizontal_scroll_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_horizontal_scroll_mode, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_vertical_scroll_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_vertical_scroll_mode, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_vertical_scroll_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_vertical_scroll_mode, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_deadzone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_deadzone, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_deadzone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::get_deadzone, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_set_follow_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_follow_focus, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_is_following_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollContainer::is_following_focus, ctx, this_val, argc, argv);
}
static JSValue scroll_container_class_get_h_scroll_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ScrollContainer::get_h_scroll_bar, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_v_scroll_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ScrollContainer::get_v_scroll_bar, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_ensure_control_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::ensure_control_visible, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_set_draw_focus_border(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollContainer::set_draw_focus_border, ctx, this_val, argc, argv);
};
static JSValue scroll_container_class_get_draw_focus_border(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ScrollContainer::get_draw_focus_border, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry scroll_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_h_scroll", 1, &scroll_container_class_set_h_scroll),
	JS_CFUNC_DEF("get_h_scroll", 0, &scroll_container_class_get_h_scroll),
	JS_CFUNC_DEF("set_v_scroll", 1, &scroll_container_class_set_v_scroll),
	JS_CFUNC_DEF("get_v_scroll", 0, &scroll_container_class_get_v_scroll),
	JS_CFUNC_DEF("set_horizontal_custom_step", 1, &scroll_container_class_set_horizontal_custom_step),
	JS_CFUNC_DEF("get_horizontal_custom_step", 0, &scroll_container_class_get_horizontal_custom_step),
	JS_CFUNC_DEF("set_vertical_custom_step", 1, &scroll_container_class_set_vertical_custom_step),
	JS_CFUNC_DEF("get_vertical_custom_step", 0, &scroll_container_class_get_vertical_custom_step),
	JS_CFUNC_DEF("set_horizontal_scroll_mode", 1, &scroll_container_class_set_horizontal_scroll_mode),
	JS_CFUNC_DEF("get_horizontal_scroll_mode", 0, &scroll_container_class_get_horizontal_scroll_mode),
	JS_CFUNC_DEF("set_vertical_scroll_mode", 1, &scroll_container_class_set_vertical_scroll_mode),
	JS_CFUNC_DEF("get_vertical_scroll_mode", 0, &scroll_container_class_get_vertical_scroll_mode),
	JS_CFUNC_DEF("set_deadzone", 1, &scroll_container_class_set_deadzone),
	JS_CFUNC_DEF("get_deadzone", 0, &scroll_container_class_get_deadzone),
	JS_CFUNC_DEF("set_follow_focus", 1, &scroll_container_class_set_follow_focus),
	JS_CFUNC_DEF("is_following_focus", 0, &scroll_container_class_is_following_focus),
	JS_CFUNC_DEF("get_h_scroll_bar", 0, &scroll_container_class_get_h_scroll_bar),
	JS_CFUNC_DEF("get_v_scroll_bar", 0, &scroll_container_class_get_v_scroll_bar),
	JS_CFUNC_DEF("ensure_control_visible", 1, &scroll_container_class_ensure_control_visible),
	JS_CFUNC_DEF("set_draw_focus_border", 1, &scroll_container_class_set_draw_focus_border),
	JS_CFUNC_DEF("get_draw_focus_border", 0, &scroll_container_class_get_draw_focus_border),
};


static JSValue scroll_container_class_get_scroll_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScrollContainer *opaque = static_cast<ScrollContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scroll_started_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scroll_started"));
		JS_DefinePropertyValueStr(ctx, this_val, "scroll_started_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scroll_container_class_get_scroll_ended_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScrollContainer *opaque = static_cast<ScrollContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scroll_ended_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scroll_ended"));
		JS_DefinePropertyValueStr(ctx, this_val, "scroll_ended_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_scroll_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "follow_focus"),
        JS_NewCFunction(ctx, scroll_container_class_is_following_focus, "is_following_focus", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_follow_focus, "set_follow_focus", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_focus_border"),
        JS_NewCFunction(ctx, scroll_container_class_get_draw_focus_border, "get_draw_focus_border", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_draw_focus_border, "set_draw_focus_border", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_horizontal"),
        JS_NewCFunction(ctx, scroll_container_class_get_h_scroll, "get_h_scroll", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_h_scroll, "set_h_scroll", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_vertical"),
        JS_NewCFunction(ctx, scroll_container_class_get_v_scroll, "get_v_scroll", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_v_scroll, "set_v_scroll", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_horizontal_custom_step"),
        JS_NewCFunction(ctx, scroll_container_class_get_horizontal_custom_step, "get_horizontal_custom_step", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_horizontal_custom_step, "set_horizontal_custom_step", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_vertical_custom_step"),
        JS_NewCFunction(ctx, scroll_container_class_get_vertical_custom_step, "get_vertical_custom_step", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_vertical_custom_step, "set_vertical_custom_step", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "horizontal_scroll_mode"),
        JS_NewCFunction(ctx, scroll_container_class_get_horizontal_scroll_mode, "get_horizontal_scroll_mode", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_horizontal_scroll_mode, "set_horizontal_scroll_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertical_scroll_mode"),
        JS_NewCFunction(ctx, scroll_container_class_get_vertical_scroll_mode, "get_vertical_scroll_mode", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_vertical_scroll_mode, "set_vertical_scroll_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_deadzone"),
        JS_NewCFunction(ctx, scroll_container_class_get_deadzone, "get_deadzone", 0),
        JS_NewCFunction(ctx, scroll_container_class_set_deadzone, "set_deadzone", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scroll_started"),
		JS_NewCFunction(ctx, scroll_container_class_get_scroll_started_signal, "get_scroll_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scroll_ended"),
		JS_NewCFunction(ctx, scroll_container_class_get_scroll_ended_signal, "get_scroll_ended_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_scroll_container_enum(JSContext *ctx, JSValue ctor) {
	JSValue ScrollMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ScrollMode_obj, "SCROLL_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ScrollMode_obj, "SCROLL_MODE_AUTO", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ScrollMode_obj, "SCROLL_MODE_SHOW_ALWAYS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ScrollMode_obj, "SCROLL_MODE_SHOW_NEVER", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ScrollMode_obj, "SCROLL_MODE_RESERVE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "ScrollMode", ScrollMode_obj);
}

static int js_scroll_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScrollContainer"] = class_id;
	classes_by_id[class_id] = "ScrollContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &scroll_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_scroll_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, scroll_container_class_proto_funcs, _countof(scroll_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, scroll_container_class_constructor, "ScrollContainer", 0, JS_CFUNC_constructor, 0);
	define_scroll_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScrollContainer", ctor);
	ctor_list["ScrollContainer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_scroll_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_scroll_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScrollContainer");
	return m;
}

JSModuleDef *js_init_scroll_container_module(JSContext *ctx) {
	return _js_init_scroll_container_module(ctx, "@godot/classes/scroll_container");
}

void __register_scroll_container() {
	js_init_scroll_container_module(js_context());
}

void register_scroll_container() {
	__register_scroll_container();
}