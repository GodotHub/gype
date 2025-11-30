#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/slider.hpp>
using namespace godot;

static void slider_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Slider"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef slider_class_def = {
    "Slider",
    slider_class_finalizer
};

static JSValue slider_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Slider"];
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
        instance = memnew(Slider);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue slider_class_set_ticks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Slider::set_ticks, ctx, this_val, argc, argv);
};
static JSValue slider_class_get_ticks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Slider::get_ticks, ctx, this_val, argc, argv);
}
static JSValue slider_class_get_ticks_on_borders(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Slider::get_ticks_on_borders, ctx, this_val, argc, argv);
}
static JSValue slider_class_set_ticks_on_borders(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Slider::set_ticks_on_borders, ctx, this_val, argc, argv);
};
static JSValue slider_class_get_ticks_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Slider::get_ticks_position, ctx, this_val, argc, argv);
}
static JSValue slider_class_set_ticks_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Slider::set_ticks_position, ctx, this_val, argc, argv);
};
static JSValue slider_class_set_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Slider::set_editable, ctx, this_val, argc, argv);
};
static JSValue slider_class_is_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Slider::is_editable, ctx, this_val, argc, argv);
}
static JSValue slider_class_set_scrollable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Slider::set_scrollable, ctx, this_val, argc, argv);
};
static JSValue slider_class_is_scrollable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Slider::is_scrollable, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry slider_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_ticks", 1, &slider_class_set_ticks),
	JS_CFUNC_DEF("get_ticks", 0, &slider_class_get_ticks),
	JS_CFUNC_DEF("get_ticks_on_borders", 0, &slider_class_get_ticks_on_borders),
	JS_CFUNC_DEF("set_ticks_on_borders", 1, &slider_class_set_ticks_on_borders),
	JS_CFUNC_DEF("get_ticks_position", 0, &slider_class_get_ticks_position),
	JS_CFUNC_DEF("set_ticks_position", 1, &slider_class_set_ticks_position),
	JS_CFUNC_DEF("set_editable", 1, &slider_class_set_editable),
	JS_CFUNC_DEF("is_editable", 0, &slider_class_is_editable),
	JS_CFUNC_DEF("set_scrollable", 1, &slider_class_set_scrollable),
	JS_CFUNC_DEF("is_scrollable", 0, &slider_class_is_scrollable),
};


static JSValue slider_class_get_drag_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "drag_started");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue slider_class_get_drag_ended_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "drag_ended");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_slider_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editable"),
        JS_NewCFunction(ctx, slider_class_is_editable, "is_editable", 0),
        JS_NewCFunction(ctx, slider_class_set_editable, "set_editable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scrollable"),
        JS_NewCFunction(ctx, slider_class_is_scrollable, "is_scrollable", 0),
        JS_NewCFunction(ctx, slider_class_set_scrollable, "set_scrollable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tick_count"),
        JS_NewCFunction(ctx, slider_class_get_ticks, "get_ticks", 0),
        JS_NewCFunction(ctx, slider_class_set_ticks, "set_ticks", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ticks_on_borders"),
        JS_NewCFunction(ctx, slider_class_get_ticks_on_borders, "get_ticks_on_borders", 0),
        JS_NewCFunction(ctx, slider_class_set_ticks_on_borders, "set_ticks_on_borders", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ticks_position"),
        JS_NewCFunction(ctx, slider_class_get_ticks_position, "get_ticks_position", 0),
        JS_NewCFunction(ctx, slider_class_set_ticks_position, "set_ticks_position", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "drag_started"),
		JS_NewCFunction(ctx, slider_class_get_drag_started_signal, "get_drag_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "drag_ended"),
		JS_NewCFunction(ctx, slider_class_get_drag_ended_signal, "get_drag_ended_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_slider_enum(JSContext *ctx, JSValue ctor) {
	JSValue TickPosition_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TickPosition_obj, "TICK_POSITION_BOTTOM_RIGHT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TickPosition_obj, "TICK_POSITION_TOP_LEFT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TickPosition_obj, "TICK_POSITION_BOTH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TickPosition_obj, "TICK_POSITION_CENTER", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TickPosition", TickPosition_obj);
}

static int js_slider_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Slider"] = class_id;
	classes_by_id[class_id] = "Slider";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &slider_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Range"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_slider_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, slider_class_proto_funcs, _countof(slider_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, slider_class_constructor, "Slider", 0, JS_CFUNC_constructor, 0);
	define_slider_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Slider", ctor);
	ctor_list["Slider"] = ctor;

	return 0;
}

JSModuleDef *_js_init_slider_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/range';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_slider_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Slider");
	return m;
}

JSModuleDef *js_init_slider_module(JSContext *ctx) {
	return _js_init_slider_module(ctx, "@godot/classes/slider");
}

void __register_slider() {
	js_init_slider_module(js_context());
}

void register_slider() {
	__register_slider();
}