#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/color_picker.hpp>
using namespace godot;

static void color_picker_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ColorPicker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef color_picker_class_def = {
    "ColorPicker",
    color_picker_class_finalizer
};

static JSValue color_picker_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ColorPicker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ColorPicker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ColorPicker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ColorPicker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue color_picker_class_set_pick_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_pick_color, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_get_pick_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ColorPicker *obj = static_cast<ColorPicker *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_pick_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ColorPicker *js_proxy = static_cast<ColorPicker *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_pick_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue color_picker_class_set_deferred_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_deferred_mode, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_is_deferred_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::is_deferred_mode, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_color_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_color_mode, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_get_color_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::get_color_mode, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_edit_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_edit_alpha, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_is_editing_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::is_editing_alpha, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_edit_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_edit_intensity, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_is_editing_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::is_editing_intensity, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_can_add_swatches(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_can_add_swatches, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_are_swatches_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::are_swatches_enabled, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_presets_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_presets_visible, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_are_presets_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::are_presets_visible, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_modes_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_modes_visible, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_are_modes_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::are_modes_visible, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_sampler_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_sampler_visible, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_is_sampler_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::is_sampler_visible, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_sliders_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_sliders_visible, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_are_sliders_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::are_sliders_visible, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_set_hex_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_hex_visible, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_is_hex_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::is_hex_visible, ctx, this_val, argc, argv);
}
static JSValue color_picker_class_add_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::add_preset, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_erase_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::erase_preset, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_get_presets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::get_presets, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_add_recent_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::add_recent_preset, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_erase_recent_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::erase_recent_preset, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_get_recent_presets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::get_recent_presets, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_set_picker_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPicker::set_picker_shape, ctx, this_val, argc, argv);
};
static JSValue color_picker_class_get_picker_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPicker::get_picker_shape, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry color_picker_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_pick_color", 1, &color_picker_class_set_pick_color),
	JS_CFUNC_DEF("get_pick_color", 0, &color_picker_class_get_pick_color),
	JS_CFUNC_DEF("set_deferred_mode", 1, &color_picker_class_set_deferred_mode),
	JS_CFUNC_DEF("is_deferred_mode", 0, &color_picker_class_is_deferred_mode),
	JS_CFUNC_DEF("set_color_mode", 1, &color_picker_class_set_color_mode),
	JS_CFUNC_DEF("get_color_mode", 0, &color_picker_class_get_color_mode),
	JS_CFUNC_DEF("set_edit_alpha", 1, &color_picker_class_set_edit_alpha),
	JS_CFUNC_DEF("is_editing_alpha", 0, &color_picker_class_is_editing_alpha),
	JS_CFUNC_DEF("set_edit_intensity", 1, &color_picker_class_set_edit_intensity),
	JS_CFUNC_DEF("is_editing_intensity", 0, &color_picker_class_is_editing_intensity),
	JS_CFUNC_DEF("set_can_add_swatches", 1, &color_picker_class_set_can_add_swatches),
	JS_CFUNC_DEF("are_swatches_enabled", 0, &color_picker_class_are_swatches_enabled),
	JS_CFUNC_DEF("set_presets_visible", 1, &color_picker_class_set_presets_visible),
	JS_CFUNC_DEF("are_presets_visible", 0, &color_picker_class_are_presets_visible),
	JS_CFUNC_DEF("set_modes_visible", 1, &color_picker_class_set_modes_visible),
	JS_CFUNC_DEF("are_modes_visible", 0, &color_picker_class_are_modes_visible),
	JS_CFUNC_DEF("set_sampler_visible", 1, &color_picker_class_set_sampler_visible),
	JS_CFUNC_DEF("is_sampler_visible", 0, &color_picker_class_is_sampler_visible),
	JS_CFUNC_DEF("set_sliders_visible", 1, &color_picker_class_set_sliders_visible),
	JS_CFUNC_DEF("are_sliders_visible", 0, &color_picker_class_are_sliders_visible),
	JS_CFUNC_DEF("set_hex_visible", 1, &color_picker_class_set_hex_visible),
	JS_CFUNC_DEF("is_hex_visible", 0, &color_picker_class_is_hex_visible),
	JS_CFUNC_DEF("add_preset", 1, &color_picker_class_add_preset),
	JS_CFUNC_DEF("erase_preset", 1, &color_picker_class_erase_preset),
	JS_CFUNC_DEF("get_presets", 0, &color_picker_class_get_presets),
	JS_CFUNC_DEF("add_recent_preset", 1, &color_picker_class_add_recent_preset),
	JS_CFUNC_DEF("erase_recent_preset", 1, &color_picker_class_erase_recent_preset),
	JS_CFUNC_DEF("get_recent_presets", 0, &color_picker_class_get_recent_presets),
	JS_CFUNC_DEF("set_picker_shape", 1, &color_picker_class_set_picker_shape),
	JS_CFUNC_DEF("get_picker_shape", 0, &color_picker_class_get_picker_shape),
};


static JSValue color_picker_class_get_color_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ColorPicker *opaque = static_cast<ColorPicker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "color_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "color_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "color_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue color_picker_class_get_preset_added_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ColorPicker *opaque = static_cast<ColorPicker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "preset_added_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "preset_added"));
		JS_DefinePropertyValueStr(ctx, this_val, "preset_added_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue color_picker_class_get_preset_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ColorPicker *opaque = static_cast<ColorPicker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "preset_removed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "preset_removed"));
		JS_DefinePropertyValueStr(ctx, this_val, "preset_removed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_color_picker_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, color_picker_class_get_pick_color, "get_pick_color", 0),
        JS_NewCFunction(ctx, color_picker_class_set_pick_color, "set_pick_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edit_alpha"),
        JS_NewCFunction(ctx, color_picker_class_is_editing_alpha, "is_editing_alpha", 0),
        JS_NewCFunction(ctx, color_picker_class_set_edit_alpha, "set_edit_alpha", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edit_intensity"),
        JS_NewCFunction(ctx, color_picker_class_is_editing_intensity, "is_editing_intensity", 0),
        JS_NewCFunction(ctx, color_picker_class_set_edit_intensity, "set_edit_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_mode"),
        JS_NewCFunction(ctx, color_picker_class_get_color_mode, "get_color_mode", 0),
        JS_NewCFunction(ctx, color_picker_class_set_color_mode, "set_color_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "deferred_mode"),
        JS_NewCFunction(ctx, color_picker_class_is_deferred_mode, "is_deferred_mode", 0),
        JS_NewCFunction(ctx, color_picker_class_set_deferred_mode, "set_deferred_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "picker_shape"),
        JS_NewCFunction(ctx, color_picker_class_get_picker_shape, "get_picker_shape", 0),
        JS_NewCFunction(ctx, color_picker_class_set_picker_shape, "set_picker_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "can_add_swatches"),
        JS_NewCFunction(ctx, color_picker_class_are_swatches_enabled, "are_swatches_enabled", 0),
        JS_NewCFunction(ctx, color_picker_class_set_can_add_swatches, "set_can_add_swatches", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sampler_visible"),
        JS_NewCFunction(ctx, color_picker_class_is_sampler_visible, "is_sampler_visible", 0),
        JS_NewCFunction(ctx, color_picker_class_set_sampler_visible, "set_sampler_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_modes_visible"),
        JS_NewCFunction(ctx, color_picker_class_are_modes_visible, "are_modes_visible", 0),
        JS_NewCFunction(ctx, color_picker_class_set_modes_visible, "set_modes_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sliders_visible"),
        JS_NewCFunction(ctx, color_picker_class_are_sliders_visible, "are_sliders_visible", 0),
        JS_NewCFunction(ctx, color_picker_class_set_sliders_visible, "set_sliders_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hex_visible"),
        JS_NewCFunction(ctx, color_picker_class_is_hex_visible, "is_hex_visible", 0),
        JS_NewCFunction(ctx, color_picker_class_set_hex_visible, "set_hex_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "presets_visible"),
        JS_NewCFunction(ctx, color_picker_class_are_presets_visible, "are_presets_visible", 0),
        JS_NewCFunction(ctx, color_picker_class_set_presets_visible, "set_presets_visible", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "color_changed"),
		JS_NewCFunction(ctx, color_picker_class_get_color_changed_signal, "get_color_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "preset_added"),
		JS_NewCFunction(ctx, color_picker_class_get_preset_added_signal, "get_preset_added_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "preset_removed"),
		JS_NewCFunction(ctx, color_picker_class_get_preset_removed_signal, "get_preset_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_color_picker_enum(JSContext *ctx, JSValue proto) {
	JSValue ColorModeType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ColorModeType_obj, "MODE_RGB", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ColorModeType_obj, "MODE_HSV", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ColorModeType_obj, "MODE_RAW", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ColorModeType_obj, "MODE_LINEAR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ColorModeType_obj, "MODE_OKHSL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "ColorModeType", ColorModeType_obj);
	JSValue PickerShapeType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_HSV_RECTANGLE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_HSV_WHEEL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_VHS_CIRCLE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_OKHSL_CIRCLE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_NONE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_OK_HS_RECTANGLE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, PickerShapeType_obj, "SHAPE_OK_HL_RECTANGLE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, proto, "PickerShapeType", PickerShapeType_obj);
}

static int js_color_picker_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ColorPicker"] = class_id;
	classes_by_id[class_id] = "ColorPicker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &color_picker_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VBoxContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_color_picker_property(ctx, proto);
	define_color_picker_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, color_picker_class_proto_funcs, _countof(color_picker_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, color_picker_class_constructor, "ColorPicker", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ColorPicker", ctor);

	return 0;
}

JSModuleDef *_js_init_color_picker_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/v_box_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_color_picker_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ColorPicker");
	return m;
}

JSModuleDef *js_init_color_picker_module(JSContext *ctx) {
	return _js_init_color_picker_module(ctx, "@godot/classes/color_picker");
}

void __register_color_picker() {
	js_init_color_picker_module(js_context());
}

void register_color_picker() {
	__register_color_picker();
}