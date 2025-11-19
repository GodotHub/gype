#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/canvas_item.hpp>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/theme.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/control.hpp>
using namespace godot;

static void control_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Control"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef control_class_def = {
    "Control",
    control_class_finalizer
};

static JSValue control_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Control"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Control *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Control *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Control);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue control_class_accept_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::accept_event, ctx, this_val, argc, argv);
};
static JSValue control_class_get_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_minimum_size, ctx, this_val, argc, argv);
};
static JSValue control_class_get_combined_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_combined_minimum_size, ctx, this_val, argc, argv);
};
static JSValue control_class_set_anchors_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_anchors_preset, ctx, this_val, argc, argv);
};
static JSValue control_class_set_offsets_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_offsets_preset, ctx, this_val, argc, argv);
};
static JSValue control_class_set_anchors_and_offsets_preset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_anchors_and_offsets_preset, ctx, this_val, argc, argv);
};
static JSValue control_class_set_anchor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_anchor, ctx, this_val, argc, argv);
};
static JSValue control_class_get_anchor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_anchor, ctx, this_val, argc, argv);
}
static JSValue control_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_offset, ctx, this_val, argc, argv);
};
static JSValue control_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_offset, ctx, this_val, argc, argv);
}
static JSValue control_class_set_anchor_and_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_anchor_and_offset, ctx, this_val, argc, argv);
};
static JSValue control_class_set_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_begin, ctx, this_val, argc, argv);
};
static JSValue control_class_set_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_end, ctx, this_val, argc, argv);
};
static JSValue control_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_position, ctx, this_val, argc, argv);
};
static JSValue control_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_size, ctx, this_val, argc, argv);
};
static JSValue control_class_reset_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::reset_size, ctx, this_val, argc, argv);
};
static JSValue control_class_set_custom_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_custom_minimum_size, ctx, this_val, argc, argv);
};
static JSValue control_class_set_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_global_position, ctx, this_val, argc, argv);
};
static JSValue control_class_set_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_rotation, ctx, this_val, argc, argv);
};
static JSValue control_class_set_rotation_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_rotation_degrees, ctx, this_val, argc, argv);
};
static JSValue control_class_set_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_scale, ctx, this_val, argc, argv);
};
static JSValue control_class_set_pivot_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_pivot_offset, ctx, this_val, argc, argv);
};
static JSValue control_class_get_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_begin, ctx, this_val, argc, argv);
};
static JSValue control_class_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_end, ctx, this_val, argc, argv);
};
static JSValue control_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_rotation, ctx, this_val, argc, argv);
}
static JSValue control_class_get_rotation_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_rotation_degrees, ctx, this_val, argc, argv);
}
static JSValue control_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scale();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scale(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_get_pivot_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_pivot_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_pivot_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_get_custom_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_custom_minimum_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_custom_minimum_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_get_parent_area_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_parent_area_size, ctx, this_val, argc, argv);
};
static JSValue control_class_get_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_position();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_position(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_get_screen_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_screen_position, ctx, this_val, argc, argv);
};
static JSValue control_class_get_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_rect, ctx, this_val, argc, argv);
};
static JSValue control_class_get_global_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_global_rect, ctx, this_val, argc, argv);
};
static JSValue control_class_set_focus_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_focus_mode, ctx, this_val, argc, argv);
};
static JSValue control_class_get_focus_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_focus_mode, ctx, this_val, argc, argv);
}
static JSValue control_class_get_focus_mode_with_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_focus_mode_with_override, ctx, this_val, argc, argv);
};
static JSValue control_class_set_focus_behavior_recursive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_focus_behavior_recursive, ctx, this_val, argc, argv);
};
static JSValue control_class_get_focus_behavior_recursive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_focus_behavior_recursive, ctx, this_val, argc, argv);
}
static JSValue control_class_has_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_focus, ctx, this_val, argc, argv);
};
static JSValue control_class_grab_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::grab_focus, ctx, this_val, argc, argv);
};
static JSValue control_class_release_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::release_focus, ctx, this_val, argc, argv);
};
static JSValue control_class_find_prev_valid_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::find_prev_valid_focus, ctx, this_val, argc, argv);
};
static JSValue control_class_find_next_valid_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::find_next_valid_focus, ctx, this_val, argc, argv);
};
static JSValue control_class_find_valid_focus_neighbor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::find_valid_focus_neighbor, ctx, this_val, argc, argv);
};
static JSValue control_class_set_h_size_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_h_size_flags, ctx, this_val, argc, argv);
};
static JSValue control_class_get_h_size_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_h_size_flags, ctx, this_val, argc, argv);
}
static JSValue control_class_set_stretch_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_stretch_ratio, ctx, this_val, argc, argv);
};
static JSValue control_class_get_stretch_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_stretch_ratio, ctx, this_val, argc, argv);
}
static JSValue control_class_set_v_size_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_v_size_flags, ctx, this_val, argc, argv);
};
static JSValue control_class_get_v_size_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_v_size_flags, ctx, this_val, argc, argv);
}
static JSValue control_class_set_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_theme, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme, ctx, this_val, argc, argv);
}
static JSValue control_class_set_theme_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_theme_type_variation, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_type_variation, ctx, this_val, argc, argv);
}
static JSValue control_class_begin_bulk_theme_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::begin_bulk_theme_override, ctx, this_val, argc, argv);
};
static JSValue control_class_end_bulk_theme_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::end_bulk_theme_override, ctx, this_val, argc, argv);
};
static JSValue control_class_add_theme_icon_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::add_theme_icon_override, ctx, this_val, argc, argv);
};
static JSValue control_class_add_theme_stylebox_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::add_theme_stylebox_override, ctx, this_val, argc, argv);
};
static JSValue control_class_add_theme_font_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::add_theme_font_override, ctx, this_val, argc, argv);
};
static JSValue control_class_add_theme_font_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::add_theme_font_size_override, ctx, this_val, argc, argv);
};
static JSValue control_class_add_theme_color_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::add_theme_color_override, ctx, this_val, argc, argv);
};
static JSValue control_class_add_theme_constant_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::add_theme_constant_override, ctx, this_val, argc, argv);
};
static JSValue control_class_remove_theme_icon_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::remove_theme_icon_override, ctx, this_val, argc, argv);
};
static JSValue control_class_remove_theme_stylebox_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::remove_theme_stylebox_override, ctx, this_val, argc, argv);
};
static JSValue control_class_remove_theme_font_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::remove_theme_font_override, ctx, this_val, argc, argv);
};
static JSValue control_class_remove_theme_font_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::remove_theme_font_size_override, ctx, this_val, argc, argv);
};
static JSValue control_class_remove_theme_color_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::remove_theme_color_override, ctx, this_val, argc, argv);
};
static JSValue control_class_remove_theme_constant_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::remove_theme_constant_override, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_icon, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_stylebox, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_font, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_font_size, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_color, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_constant, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_icon_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_icon_override, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_stylebox_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_stylebox_override, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_font_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_font_override, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_font_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_font_size_override, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_color_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_color_override, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_constant_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_constant_override, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_icon, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_stylebox, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_font, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_font_size, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_color, ctx, this_val, argc, argv);
};
static JSValue control_class_has_theme_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::has_theme_constant, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_default_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_default_base_scale, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_default_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_default_font, ctx, this_val, argc, argv);
};
static JSValue control_class_get_theme_default_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_theme_default_font_size, ctx, this_val, argc, argv);
};
static JSValue control_class_get_parent_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_parent_control, ctx, this_val, argc, argv);
};
static JSValue control_class_set_h_grow_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_h_grow_direction, ctx, this_val, argc, argv);
};
static JSValue control_class_get_h_grow_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_h_grow_direction, ctx, this_val, argc, argv);
}
static JSValue control_class_set_v_grow_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_v_grow_direction, ctx, this_val, argc, argv);
};
static JSValue control_class_get_v_grow_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_v_grow_direction, ctx, this_val, argc, argv);
}
static JSValue control_class_set_tooltip_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_tooltip_auto_translate_mode, ctx, this_val, argc, argv);
};
static JSValue control_class_get_tooltip_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_tooltip_auto_translate_mode, ctx, this_val, argc, argv);
}
static JSValue control_class_set_tooltip_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_tooltip_text, ctx, this_val, argc, argv);
};
static JSValue control_class_get_tooltip_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_tooltip_text, ctx, this_val, argc, argv);
}
static JSValue control_class_get_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_tooltip, ctx, this_val, argc, argv);
};
static JSValue control_class_set_default_cursor_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_default_cursor_shape, ctx, this_val, argc, argv);
};
static JSValue control_class_get_default_cursor_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_default_cursor_shape, ctx, this_val, argc, argv);
}
static JSValue control_class_get_cursor_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_cursor_shape, ctx, this_val, argc, argv);
};
static JSValue control_class_set_focus_neighbor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_focus_neighbor, ctx, this_val, argc, argv);
};
static JSValue control_class_get_focus_neighbor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_focus_neighbor, ctx, this_val, argc, argv);
}
static JSValue control_class_set_focus_next(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_focus_next, ctx, this_val, argc, argv);
};
static JSValue control_class_get_focus_next(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_focus_next();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_focus_next(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_set_focus_previous(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_focus_previous, ctx, this_val, argc, argv);
};
static JSValue control_class_get_focus_previous(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		Control *obj = static_cast<Control *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_focus_previous();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		Control *js_proxy = static_cast<Control *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_focus_previous(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue control_class_force_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::force_drag, ctx, this_val, argc, argv);
};
static JSValue control_class_accessibility_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::accessibility_drag, ctx, this_val, argc, argv);
};
static JSValue control_class_accessibility_drop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::accessibility_drop, ctx, this_val, argc, argv);
};
static JSValue control_class_set_accessibility_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_name, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_name, ctx, this_val, argc, argv);
}
static JSValue control_class_set_accessibility_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_description, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_description, ctx, this_val, argc, argv);
}
static JSValue control_class_set_accessibility_live(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_live, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_live(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_live, ctx, this_val, argc, argv);
}
static JSValue control_class_set_accessibility_controls_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_controls_nodes, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_controls_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_controls_nodes, ctx, this_val, argc, argv);
}
static JSValue control_class_set_accessibility_described_by_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_described_by_nodes, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_described_by_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_described_by_nodes, ctx, this_val, argc, argv);
}
static JSValue control_class_set_accessibility_labeled_by_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_labeled_by_nodes, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_labeled_by_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_labeled_by_nodes, ctx, this_val, argc, argv);
}
static JSValue control_class_set_accessibility_flow_to_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_accessibility_flow_to_nodes, ctx, this_val, argc, argv);
};
static JSValue control_class_get_accessibility_flow_to_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_accessibility_flow_to_nodes, ctx, this_val, argc, argv);
}
static JSValue control_class_set_mouse_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_mouse_filter, ctx, this_val, argc, argv);
};
static JSValue control_class_get_mouse_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_mouse_filter, ctx, this_val, argc, argv);
}
static JSValue control_class_get_mouse_filter_with_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_mouse_filter_with_override, ctx, this_val, argc, argv);
};
static JSValue control_class_set_mouse_behavior_recursive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_mouse_behavior_recursive, ctx, this_val, argc, argv);
};
static JSValue control_class_get_mouse_behavior_recursive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_mouse_behavior_recursive, ctx, this_val, argc, argv);
}
static JSValue control_class_set_force_pass_scroll_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_force_pass_scroll_events, ctx, this_val, argc, argv);
};
static JSValue control_class_is_force_pass_scroll_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::is_force_pass_scroll_events, ctx, this_val, argc, argv);
}
static JSValue control_class_set_clip_contents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_clip_contents, ctx, this_val, argc, argv);
};
static JSValue control_class_is_clipping_contents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Control::is_clipping_contents, ctx, this_val, argc, argv);
}
static JSValue control_class_grab_click_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::grab_click_focus, ctx, this_val, argc, argv);
};
static JSValue control_class_set_drag_forwarding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_drag_forwarding, ctx, this_val, argc, argv);
};
static JSValue control_class_set_drag_preview(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_drag_preview, ctx, this_val, argc, argv);
};
static JSValue control_class_is_drag_successful(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::is_drag_successful, ctx, this_val, argc, argv);
};
static JSValue control_class_warp_mouse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::warp_mouse, ctx, this_val, argc, argv);
};
static JSValue control_class_set_shortcut_context(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_shortcut_context, ctx, this_val, argc, argv);
};
static JSValue control_class_get_shortcut_context(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_shortcut_context, ctx, this_val, argc, argv);
}
static JSValue control_class_update_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::update_minimum_size, ctx, this_val, argc, argv);
};
static JSValue control_class_set_layout_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_layout_direction, ctx, this_val, argc, argv);
};
static JSValue control_class_get_layout_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::get_layout_direction, ctx, this_val, argc, argv);
}
static JSValue control_class_is_layout_rtl(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::is_layout_rtl, ctx, this_val, argc, argv);
};
static JSValue control_class_set_auto_translate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_auto_translate, ctx, this_val, argc, argv);
};
static JSValue control_class_is_auto_translating(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::is_auto_translating, ctx, this_val, argc, argv);
}
static JSValue control_class_set_localize_numeral_system(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Control::set_localize_numeral_system, ctx, this_val, argc, argv);
};
static JSValue control_class_is_localizing_numeral_system(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Control::is_localizing_numeral_system, ctx, this_val, argc, argv);
}

static JSValue control_class_get_anchor_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_anchor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_get_anchor_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_anchor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_get_anchor_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_anchor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_get_anchor_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_anchor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_get_offset_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_offset, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_offset_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_offset, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_offset_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_offset, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_offset_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_offset, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_offset_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_offset, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_offset_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_offset, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_offset_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_offset, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_offset_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_offset, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_focus_neighbor_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_focus_neighbor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_focus_neighbor_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_focus_neighbor, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_focus_neighbor_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_focus_neighbor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_focus_neighbor_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_focus_neighbor, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_focus_neighbor_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_focus_neighbor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_focus_neighbor_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_focus_neighbor, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue control_class_get_focus_neighbor_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Control::get_focus_neighbor, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue control_class_set_focus_neighbor_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Control::set_focus_neighbor, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry control_class_proto_funcs[] = {
	JS_CFUNC_DEF("accept_event", 0, &control_class_accept_event),
	JS_CFUNC_DEF("get_minimum_size", 0, &control_class_get_minimum_size),
	JS_CFUNC_DEF("get_combined_minimum_size", 0, &control_class_get_combined_minimum_size),
	JS_CFUNC_DEF("set_anchors_preset", 2, &control_class_set_anchors_preset),
	JS_CFUNC_DEF("set_offsets_preset", 3, &control_class_set_offsets_preset),
	JS_CFUNC_DEF("set_anchors_and_offsets_preset", 3, &control_class_set_anchors_and_offsets_preset),
	JS_CFUNC_DEF("set_anchor", 4, &control_class_set_anchor),
	JS_CFUNC_DEF("get_anchor", 1, &control_class_get_anchor),
	JS_CFUNC_DEF("set_offset", 2, &control_class_set_offset),
	JS_CFUNC_DEF("get_offset", 1, &control_class_get_offset),
	JS_CFUNC_DEF("set_anchor_and_offset", 4, &control_class_set_anchor_and_offset),
	JS_CFUNC_DEF("set_begin", 1, &control_class_set_begin),
	JS_CFUNC_DEF("set_end", 1, &control_class_set_end),
	JS_CFUNC_DEF("set_position", 2, &control_class_set_position),
	JS_CFUNC_DEF("set_size", 2, &control_class_set_size),
	JS_CFUNC_DEF("reset_size", 0, &control_class_reset_size),
	JS_CFUNC_DEF("set_custom_minimum_size", 1, &control_class_set_custom_minimum_size),
	JS_CFUNC_DEF("set_global_position", 2, &control_class_set_global_position),
	JS_CFUNC_DEF("set_rotation", 1, &control_class_set_rotation),
	JS_CFUNC_DEF("set_rotation_degrees", 1, &control_class_set_rotation_degrees),
	JS_CFUNC_DEF("set_scale", 1, &control_class_set_scale),
	JS_CFUNC_DEF("set_pivot_offset", 1, &control_class_set_pivot_offset),
	JS_CFUNC_DEF("get_begin", 0, &control_class_get_begin),
	JS_CFUNC_DEF("get_end", 0, &control_class_get_end),
	JS_CFUNC_DEF("get_position", 0, &control_class_get_position),
	JS_CFUNC_DEF("get_size", 0, &control_class_get_size),
	JS_CFUNC_DEF("get_rotation", 0, &control_class_get_rotation),
	JS_CFUNC_DEF("get_rotation_degrees", 0, &control_class_get_rotation_degrees),
	JS_CFUNC_DEF("get_scale", 0, &control_class_get_scale),
	JS_CFUNC_DEF("get_pivot_offset", 0, &control_class_get_pivot_offset),
	JS_CFUNC_DEF("get_custom_minimum_size", 0, &control_class_get_custom_minimum_size),
	JS_CFUNC_DEF("get_parent_area_size", 0, &control_class_get_parent_area_size),
	JS_CFUNC_DEF("get_global_position", 0, &control_class_get_global_position),
	JS_CFUNC_DEF("get_screen_position", 0, &control_class_get_screen_position),
	JS_CFUNC_DEF("get_rect", 0, &control_class_get_rect),
	JS_CFUNC_DEF("get_global_rect", 0, &control_class_get_global_rect),
	JS_CFUNC_DEF("set_focus_mode", 1, &control_class_set_focus_mode),
	JS_CFUNC_DEF("get_focus_mode", 0, &control_class_get_focus_mode),
	JS_CFUNC_DEF("get_focus_mode_with_override", 0, &control_class_get_focus_mode_with_override),
	JS_CFUNC_DEF("set_focus_behavior_recursive", 1, &control_class_set_focus_behavior_recursive),
	JS_CFUNC_DEF("get_focus_behavior_recursive", 0, &control_class_get_focus_behavior_recursive),
	JS_CFUNC_DEF("has_focus", 0, &control_class_has_focus),
	JS_CFUNC_DEF("grab_focus", 0, &control_class_grab_focus),
	JS_CFUNC_DEF("release_focus", 0, &control_class_release_focus),
	JS_CFUNC_DEF("find_prev_valid_focus", 0, &control_class_find_prev_valid_focus),
	JS_CFUNC_DEF("find_next_valid_focus", 0, &control_class_find_next_valid_focus),
	JS_CFUNC_DEF("find_valid_focus_neighbor", 1, &control_class_find_valid_focus_neighbor),
	JS_CFUNC_DEF("set_h_size_flags", 1, &control_class_set_h_size_flags),
	JS_CFUNC_DEF("get_h_size_flags", 0, &control_class_get_h_size_flags),
	JS_CFUNC_DEF("set_stretch_ratio", 1, &control_class_set_stretch_ratio),
	JS_CFUNC_DEF("get_stretch_ratio", 0, &control_class_get_stretch_ratio),
	JS_CFUNC_DEF("set_v_size_flags", 1, &control_class_set_v_size_flags),
	JS_CFUNC_DEF("get_v_size_flags", 0, &control_class_get_v_size_flags),
	JS_CFUNC_DEF("set_theme", 1, &control_class_set_theme),
	JS_CFUNC_DEF("get_theme", 0, &control_class_get_theme),
	JS_CFUNC_DEF("set_theme_type_variation", 1, &control_class_set_theme_type_variation),
	JS_CFUNC_DEF("get_theme_type_variation", 0, &control_class_get_theme_type_variation),
	JS_CFUNC_DEF("begin_bulk_theme_override", 0, &control_class_begin_bulk_theme_override),
	JS_CFUNC_DEF("end_bulk_theme_override", 0, &control_class_end_bulk_theme_override),
	JS_CFUNC_DEF("add_theme_icon_override", 2, &control_class_add_theme_icon_override),
	JS_CFUNC_DEF("add_theme_stylebox_override", 2, &control_class_add_theme_stylebox_override),
	JS_CFUNC_DEF("add_theme_font_override", 2, &control_class_add_theme_font_override),
	JS_CFUNC_DEF("add_theme_font_size_override", 2, &control_class_add_theme_font_size_override),
	JS_CFUNC_DEF("add_theme_color_override", 2, &control_class_add_theme_color_override),
	JS_CFUNC_DEF("add_theme_constant_override", 2, &control_class_add_theme_constant_override),
	JS_CFUNC_DEF("remove_theme_icon_override", 1, &control_class_remove_theme_icon_override),
	JS_CFUNC_DEF("remove_theme_stylebox_override", 1, &control_class_remove_theme_stylebox_override),
	JS_CFUNC_DEF("remove_theme_font_override", 1, &control_class_remove_theme_font_override),
	JS_CFUNC_DEF("remove_theme_font_size_override", 1, &control_class_remove_theme_font_size_override),
	JS_CFUNC_DEF("remove_theme_color_override", 1, &control_class_remove_theme_color_override),
	JS_CFUNC_DEF("remove_theme_constant_override", 1, &control_class_remove_theme_constant_override),
	JS_CFUNC_DEF("get_theme_icon", 2, &control_class_get_theme_icon),
	JS_CFUNC_DEF("get_theme_stylebox", 2, &control_class_get_theme_stylebox),
	JS_CFUNC_DEF("get_theme_font", 2, &control_class_get_theme_font),
	JS_CFUNC_DEF("get_theme_font_size", 2, &control_class_get_theme_font_size),
	JS_CFUNC_DEF("get_theme_color", 2, &control_class_get_theme_color),
	JS_CFUNC_DEF("get_theme_constant", 2, &control_class_get_theme_constant),
	JS_CFUNC_DEF("has_theme_icon_override", 1, &control_class_has_theme_icon_override),
	JS_CFUNC_DEF("has_theme_stylebox_override", 1, &control_class_has_theme_stylebox_override),
	JS_CFUNC_DEF("has_theme_font_override", 1, &control_class_has_theme_font_override),
	JS_CFUNC_DEF("has_theme_font_size_override", 1, &control_class_has_theme_font_size_override),
	JS_CFUNC_DEF("has_theme_color_override", 1, &control_class_has_theme_color_override),
	JS_CFUNC_DEF("has_theme_constant_override", 1, &control_class_has_theme_constant_override),
	JS_CFUNC_DEF("has_theme_icon", 2, &control_class_has_theme_icon),
	JS_CFUNC_DEF("has_theme_stylebox", 2, &control_class_has_theme_stylebox),
	JS_CFUNC_DEF("has_theme_font", 2, &control_class_has_theme_font),
	JS_CFUNC_DEF("has_theme_font_size", 2, &control_class_has_theme_font_size),
	JS_CFUNC_DEF("has_theme_color", 2, &control_class_has_theme_color),
	JS_CFUNC_DEF("has_theme_constant", 2, &control_class_has_theme_constant),
	JS_CFUNC_DEF("get_theme_default_base_scale", 0, &control_class_get_theme_default_base_scale),
	JS_CFUNC_DEF("get_theme_default_font", 0, &control_class_get_theme_default_font),
	JS_CFUNC_DEF("get_theme_default_font_size", 0, &control_class_get_theme_default_font_size),
	JS_CFUNC_DEF("get_parent_control", 0, &control_class_get_parent_control),
	JS_CFUNC_DEF("set_h_grow_direction", 1, &control_class_set_h_grow_direction),
	JS_CFUNC_DEF("get_h_grow_direction", 0, &control_class_get_h_grow_direction),
	JS_CFUNC_DEF("set_v_grow_direction", 1, &control_class_set_v_grow_direction),
	JS_CFUNC_DEF("get_v_grow_direction", 0, &control_class_get_v_grow_direction),
	JS_CFUNC_DEF("set_tooltip_auto_translate_mode", 1, &control_class_set_tooltip_auto_translate_mode),
	JS_CFUNC_DEF("get_tooltip_auto_translate_mode", 0, &control_class_get_tooltip_auto_translate_mode),
	JS_CFUNC_DEF("set_tooltip_text", 1, &control_class_set_tooltip_text),
	JS_CFUNC_DEF("get_tooltip_text", 0, &control_class_get_tooltip_text),
	JS_CFUNC_DEF("get_tooltip", 1, &control_class_get_tooltip),
	JS_CFUNC_DEF("set_default_cursor_shape", 1, &control_class_set_default_cursor_shape),
	JS_CFUNC_DEF("get_default_cursor_shape", 0, &control_class_get_default_cursor_shape),
	JS_CFUNC_DEF("get_cursor_shape", 1, &control_class_get_cursor_shape),
	JS_CFUNC_DEF("set_focus_neighbor", 2, &control_class_set_focus_neighbor),
	JS_CFUNC_DEF("get_focus_neighbor", 1, &control_class_get_focus_neighbor),
	JS_CFUNC_DEF("set_focus_next", 1, &control_class_set_focus_next),
	JS_CFUNC_DEF("get_focus_next", 0, &control_class_get_focus_next),
	JS_CFUNC_DEF("set_focus_previous", 1, &control_class_set_focus_previous),
	JS_CFUNC_DEF("get_focus_previous", 0, &control_class_get_focus_previous),
	JS_CFUNC_DEF("force_drag", 2, &control_class_force_drag),
	JS_CFUNC_DEF("accessibility_drag", 0, &control_class_accessibility_drag),
	JS_CFUNC_DEF("accessibility_drop", 0, &control_class_accessibility_drop),
	JS_CFUNC_DEF("set_accessibility_name", 1, &control_class_set_accessibility_name),
	JS_CFUNC_DEF("get_accessibility_name", 0, &control_class_get_accessibility_name),
	JS_CFUNC_DEF("set_accessibility_description", 1, &control_class_set_accessibility_description),
	JS_CFUNC_DEF("get_accessibility_description", 0, &control_class_get_accessibility_description),
	JS_CFUNC_DEF("set_accessibility_live", 1, &control_class_set_accessibility_live),
	JS_CFUNC_DEF("get_accessibility_live", 0, &control_class_get_accessibility_live),
	JS_CFUNC_DEF("set_accessibility_controls_nodes", 1, &control_class_set_accessibility_controls_nodes),
	JS_CFUNC_DEF("get_accessibility_controls_nodes", 0, &control_class_get_accessibility_controls_nodes),
	JS_CFUNC_DEF("set_accessibility_described_by_nodes", 1, &control_class_set_accessibility_described_by_nodes),
	JS_CFUNC_DEF("get_accessibility_described_by_nodes", 0, &control_class_get_accessibility_described_by_nodes),
	JS_CFUNC_DEF("set_accessibility_labeled_by_nodes", 1, &control_class_set_accessibility_labeled_by_nodes),
	JS_CFUNC_DEF("get_accessibility_labeled_by_nodes", 0, &control_class_get_accessibility_labeled_by_nodes),
	JS_CFUNC_DEF("set_accessibility_flow_to_nodes", 1, &control_class_set_accessibility_flow_to_nodes),
	JS_CFUNC_DEF("get_accessibility_flow_to_nodes", 0, &control_class_get_accessibility_flow_to_nodes),
	JS_CFUNC_DEF("set_mouse_filter", 1, &control_class_set_mouse_filter),
	JS_CFUNC_DEF("get_mouse_filter", 0, &control_class_get_mouse_filter),
	JS_CFUNC_DEF("get_mouse_filter_with_override", 0, &control_class_get_mouse_filter_with_override),
	JS_CFUNC_DEF("set_mouse_behavior_recursive", 1, &control_class_set_mouse_behavior_recursive),
	JS_CFUNC_DEF("get_mouse_behavior_recursive", 0, &control_class_get_mouse_behavior_recursive),
	JS_CFUNC_DEF("set_force_pass_scroll_events", 1, &control_class_set_force_pass_scroll_events),
	JS_CFUNC_DEF("is_force_pass_scroll_events", 0, &control_class_is_force_pass_scroll_events),
	JS_CFUNC_DEF("set_clip_contents", 1, &control_class_set_clip_contents),
	JS_CFUNC_DEF("is_clipping_contents", 0, &control_class_is_clipping_contents),
	JS_CFUNC_DEF("grab_click_focus", 0, &control_class_grab_click_focus),
	JS_CFUNC_DEF("set_drag_forwarding", 3, &control_class_set_drag_forwarding),
	JS_CFUNC_DEF("set_drag_preview", 1, &control_class_set_drag_preview),
	JS_CFUNC_DEF("is_drag_successful", 0, &control_class_is_drag_successful),
	JS_CFUNC_DEF("warp_mouse", 1, &control_class_warp_mouse),
	JS_CFUNC_DEF("set_shortcut_context", 1, &control_class_set_shortcut_context),
	JS_CFUNC_DEF("get_shortcut_context", 0, &control_class_get_shortcut_context),
	JS_CFUNC_DEF("update_minimum_size", 0, &control_class_update_minimum_size),
	JS_CFUNC_DEF("set_layout_direction", 1, &control_class_set_layout_direction),
	JS_CFUNC_DEF("get_layout_direction", 0, &control_class_get_layout_direction),
	JS_CFUNC_DEF("is_layout_rtl", 0, &control_class_is_layout_rtl),
	JS_CFUNC_DEF("set_auto_translate", 1, &control_class_set_auto_translate),
	JS_CFUNC_DEF("is_auto_translating", 0, &control_class_is_auto_translating),
	JS_CFUNC_DEF("set_localize_numeral_system", 1, &control_class_set_localize_numeral_system),
	JS_CFUNC_DEF("is_localizing_numeral_system", 0, &control_class_is_localizing_numeral_system),
    JS_CFUNC_MAGIC_DEF("get_anchor_top", 0, &control_class_get_anchor_top, 1),
    JS_CFUNC_MAGIC_DEF("get_anchor_right", 0, &control_class_get_anchor_right, 2),
    JS_CFUNC_MAGIC_DEF("get_anchor_bottom", 0, &control_class_get_anchor_bottom, 3),
    JS_CFUNC_MAGIC_DEF("get_offset_top", 0, &control_class_get_offset_top, 1),
    JS_CFUNC_MAGIC_DEF("set_offset_top", 1, &control_class_set_offset_top, 1),
    JS_CFUNC_MAGIC_DEF("get_offset_right", 0, &control_class_get_offset_right, 2),
    JS_CFUNC_MAGIC_DEF("set_offset_right", 1, &control_class_set_offset_right, 2),
    JS_CFUNC_MAGIC_DEF("get_offset_bottom", 0, &control_class_get_offset_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_offset_bottom", 1, &control_class_set_offset_bottom, 3),
    JS_CFUNC_MAGIC_DEF("get_focus_neighbor_top", 0, &control_class_get_focus_neighbor_top, 1),
    JS_CFUNC_MAGIC_DEF("set_focus_neighbor_top", 1, &control_class_set_focus_neighbor_top, 1),
    JS_CFUNC_MAGIC_DEF("get_focus_neighbor_right", 0, &control_class_get_focus_neighbor_right, 2),
    JS_CFUNC_MAGIC_DEF("set_focus_neighbor_right", 1, &control_class_set_focus_neighbor_right, 2),
    JS_CFUNC_MAGIC_DEF("get_focus_neighbor_bottom", 0, &control_class_get_focus_neighbor_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_focus_neighbor_bottom", 1, &control_class_set_focus_neighbor_bottom, 3),
};


static JSValue control_class_get_resized_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resized_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resized"));
		JS_DefinePropertyValueStr(ctx, this_val, "resized_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_gui_input_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "gui_input_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "gui_input"));
		JS_DefinePropertyValueStr(ctx, this_val, "gui_input_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_mouse_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "mouse_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "mouse_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "mouse_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_mouse_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "mouse_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "mouse_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "mouse_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_focus_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "focus_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "focus_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "focus_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_focus_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "focus_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "focus_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "focus_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_size_flags_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "size_flags_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "size_flags_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "size_flags_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_minimum_size_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "minimum_size_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "minimum_size_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "minimum_size_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue control_class_get_theme_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Control *opaque = static_cast<Control *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "theme_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "theme_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "theme_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_control_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clip_contents"),
        JS_NewCFunction(ctx, control_class_is_clipping_contents, "is_clipping_contents", 0),
        JS_NewCFunction(ctx, control_class_set_clip_contents, "set_clip_contents", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_minimum_size"),
        JS_NewCFunction(ctx, control_class_get_custom_minimum_size, "get_custom_minimum_size", 0),
        JS_NewCFunction(ctx, control_class_set_custom_minimum_size, "set_custom_minimum_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "layout_direction"),
        JS_NewCFunction(ctx, control_class_get_layout_direction, "get_layout_direction", 0),
        JS_NewCFunction(ctx, control_class_set_layout_direction, "set_layout_direction", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anchor_left"),
		JS_NewCFunctionMagic(ctx, control_class_get_anchor_left, "get_anchor_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_UNDEFINED,
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anchor_top"),
		JS_NewCFunctionMagic(ctx, control_class_get_anchor_top, "get_anchor_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_UNDEFINED,
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anchor_right"),
		JS_NewCFunctionMagic(ctx, control_class_get_anchor_right, "get_anchor_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_UNDEFINED,
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anchor_bottom"),
		JS_NewCFunctionMagic(ctx, control_class_get_anchor_bottom, "get_anchor_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_UNDEFINED,
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "offset_left"),
		JS_NewCFunctionMagic(ctx, control_class_get_offset_left, "get_offset_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, control_class_set_offset_left, "set_offset_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "offset_top"),
		JS_NewCFunctionMagic(ctx, control_class_get_offset_top, "get_offset_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, control_class_set_offset_top, "set_offset_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "offset_right"),
		JS_NewCFunctionMagic(ctx, control_class_get_offset_right, "get_offset_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, control_class_set_offset_right, "set_offset_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "offset_bottom"),
		JS_NewCFunctionMagic(ctx, control_class_get_offset_bottom, "get_offset_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, control_class_set_offset_bottom, "set_offset_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "grow_horizontal"),
        JS_NewCFunction(ctx, control_class_get_h_grow_direction, "get_h_grow_direction", 0),
        JS_NewCFunction(ctx, control_class_set_h_grow_direction, "set_h_grow_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "grow_vertical"),
        JS_NewCFunction(ctx, control_class_get_v_grow_direction, "get_v_grow_direction", 0),
        JS_NewCFunction(ctx, control_class_set_v_grow_direction, "set_v_grow_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, control_class_get_size, "get_size", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position"),
        JS_NewCFunction(ctx, control_class_get_position, "get_position", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_position"),
        JS_NewCFunction(ctx, control_class_get_global_position, "get_global_position", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation"),
        JS_NewCFunction(ctx, control_class_get_rotation, "get_rotation", 0),
        JS_NewCFunction(ctx, control_class_set_rotation, "set_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation_degrees"),
        JS_NewCFunction(ctx, control_class_get_rotation_degrees, "get_rotation_degrees", 0),
        JS_NewCFunction(ctx, control_class_set_rotation_degrees, "set_rotation_degrees", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale"),
        JS_NewCFunction(ctx, control_class_get_scale, "get_scale", 0),
        JS_NewCFunction(ctx, control_class_set_scale, "set_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pivot_offset"),
        JS_NewCFunction(ctx, control_class_get_pivot_offset, "get_pivot_offset", 0),
        JS_NewCFunction(ctx, control_class_set_pivot_offset, "set_pivot_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size_flags_horizontal"),
        JS_NewCFunction(ctx, control_class_get_h_size_flags, "get_h_size_flags", 0),
        JS_NewCFunction(ctx, control_class_set_h_size_flags, "set_h_size_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size_flags_vertical"),
        JS_NewCFunction(ctx, control_class_get_v_size_flags, "get_v_size_flags", 0),
        JS_NewCFunction(ctx, control_class_set_v_size_flags, "set_v_size_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size_flags_stretch_ratio"),
        JS_NewCFunction(ctx, control_class_get_stretch_ratio, "get_stretch_ratio", 0),
        JS_NewCFunction(ctx, control_class_set_stretch_ratio, "set_stretch_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "localize_numeral_system"),
        JS_NewCFunction(ctx, control_class_is_localizing_numeral_system, "is_localizing_numeral_system", 0),
        JS_NewCFunction(ctx, control_class_set_localize_numeral_system, "set_localize_numeral_system", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_translate"),
        JS_NewCFunction(ctx, control_class_is_auto_translating, "is_auto_translating", 0),
        JS_NewCFunction(ctx, control_class_set_auto_translate, "set_auto_translate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tooltip_text"),
        JS_NewCFunction(ctx, control_class_get_tooltip_text, "get_tooltip_text", 0),
        JS_NewCFunction(ctx, control_class_set_tooltip_text, "set_tooltip_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tooltip_auto_translate_mode"),
        JS_NewCFunction(ctx, control_class_get_tooltip_auto_translate_mode, "get_tooltip_auto_translate_mode", 0),
        JS_NewCFunction(ctx, control_class_set_tooltip_auto_translate_mode, "set_tooltip_auto_translate_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "focus_neighbor_left"),
		JS_NewCFunctionMagic(ctx, control_class_get_focus_neighbor_left, "get_focus_neighbor_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, control_class_set_focus_neighbor_left, "set_focus_neighbor_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "focus_neighbor_top"),
		JS_NewCFunctionMagic(ctx, control_class_get_focus_neighbor_top, "get_focus_neighbor_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, control_class_set_focus_neighbor_top, "set_focus_neighbor_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "focus_neighbor_right"),
		JS_NewCFunctionMagic(ctx, control_class_get_focus_neighbor_right, "get_focus_neighbor_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, control_class_set_focus_neighbor_right, "set_focus_neighbor_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "focus_neighbor_bottom"),
		JS_NewCFunctionMagic(ctx, control_class_get_focus_neighbor_bottom, "get_focus_neighbor_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, control_class_set_focus_neighbor_bottom, "set_focus_neighbor_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "focus_next"),
        JS_NewCFunction(ctx, control_class_get_focus_next, "get_focus_next", 0),
        JS_NewCFunction(ctx, control_class_set_focus_next, "set_focus_next", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "focus_previous"),
        JS_NewCFunction(ctx, control_class_get_focus_previous, "get_focus_previous", 0),
        JS_NewCFunction(ctx, control_class_set_focus_previous, "set_focus_previous", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "focus_mode"),
        JS_NewCFunction(ctx, control_class_get_focus_mode, "get_focus_mode", 0),
        JS_NewCFunction(ctx, control_class_set_focus_mode, "set_focus_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "focus_behavior_recursive"),
        JS_NewCFunction(ctx, control_class_get_focus_behavior_recursive, "get_focus_behavior_recursive", 0),
        JS_NewCFunction(ctx, control_class_set_focus_behavior_recursive, "set_focus_behavior_recursive", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_filter"),
        JS_NewCFunction(ctx, control_class_get_mouse_filter, "get_mouse_filter", 0),
        JS_NewCFunction(ctx, control_class_set_mouse_filter, "set_mouse_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_behavior_recursive"),
        JS_NewCFunction(ctx, control_class_get_mouse_behavior_recursive, "get_mouse_behavior_recursive", 0),
        JS_NewCFunction(ctx, control_class_set_mouse_behavior_recursive, "set_mouse_behavior_recursive", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_force_pass_scroll_events"),
        JS_NewCFunction(ctx, control_class_is_force_pass_scroll_events, "is_force_pass_scroll_events", 0),
        JS_NewCFunction(ctx, control_class_set_force_pass_scroll_events, "set_force_pass_scroll_events", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_default_cursor_shape"),
        JS_NewCFunction(ctx, control_class_get_default_cursor_shape, "get_default_cursor_shape", 0),
        JS_NewCFunction(ctx, control_class_set_default_cursor_shape, "set_default_cursor_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shortcut_context"),
        JS_NewCFunction(ctx, control_class_get_shortcut_context, "get_shortcut_context", 0),
        JS_NewCFunction(ctx, control_class_set_shortcut_context, "set_shortcut_context", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_name"),
        JS_NewCFunction(ctx, control_class_get_accessibility_name, "get_accessibility_name", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_name, "set_accessibility_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_description"),
        JS_NewCFunction(ctx, control_class_get_accessibility_description, "get_accessibility_description", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_description, "set_accessibility_description", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_live"),
        JS_NewCFunction(ctx, control_class_get_accessibility_live, "get_accessibility_live", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_live, "set_accessibility_live", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_controls_nodes"),
        JS_NewCFunction(ctx, control_class_get_accessibility_controls_nodes, "get_accessibility_controls_nodes", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_controls_nodes, "set_accessibility_controls_nodes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_described_by_nodes"),
        JS_NewCFunction(ctx, control_class_get_accessibility_described_by_nodes, "get_accessibility_described_by_nodes", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_described_by_nodes, "set_accessibility_described_by_nodes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_labeled_by_nodes"),
        JS_NewCFunction(ctx, control_class_get_accessibility_labeled_by_nodes, "get_accessibility_labeled_by_nodes", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_labeled_by_nodes, "set_accessibility_labeled_by_nodes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_flow_to_nodes"),
        JS_NewCFunction(ctx, control_class_get_accessibility_flow_to_nodes, "get_accessibility_flow_to_nodes", 0),
        JS_NewCFunction(ctx, control_class_set_accessibility_flow_to_nodes, "set_accessibility_flow_to_nodes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "theme"),
        JS_NewCFunction(ctx, control_class_get_theme, "get_theme", 0),
        JS_NewCFunction(ctx, control_class_set_theme, "set_theme", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "theme_type_variation"),
        JS_NewCFunction(ctx, control_class_get_theme_type_variation, "get_theme_type_variation", 0),
        JS_NewCFunction(ctx, control_class_set_theme_type_variation, "set_theme_type_variation", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resized"),
		JS_NewCFunction(ctx, control_class_get_resized_signal, "get_resized_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "gui_input"),
		JS_NewCFunction(ctx, control_class_get_gui_input_signal, "get_gui_input_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "mouse_entered"),
		JS_NewCFunction(ctx, control_class_get_mouse_entered_signal, "get_mouse_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "mouse_exited"),
		JS_NewCFunction(ctx, control_class_get_mouse_exited_signal, "get_mouse_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "focus_entered"),
		JS_NewCFunction(ctx, control_class_get_focus_entered_signal, "get_focus_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "focus_exited"),
		JS_NewCFunction(ctx, control_class_get_focus_exited_signal, "get_focus_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "size_flags_changed"),
		JS_NewCFunction(ctx, control_class_get_size_flags_changed_signal, "get_size_flags_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "minimum_size_changed"),
		JS_NewCFunction(ctx, control_class_get_minimum_size_changed_signal, "get_minimum_size_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "theme_changed"),
		JS_NewCFunction(ctx, control_class_get_theme_changed_signal, "get_theme_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_control_enum(JSContext *ctx, JSValue ctor) {
	JSValue FocusMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FocusMode_obj, "FOCUS_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FocusMode_obj, "FOCUS_CLICK", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FocusMode_obj, "FOCUS_ALL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FocusMode_obj, "FOCUS_ACCESSIBILITY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "FocusMode", FocusMode_obj);
	JSValue FocusBehaviorRecursive_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FocusBehaviorRecursive_obj, "FOCUS_BEHAVIOR_INHERITED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FocusBehaviorRecursive_obj, "FOCUS_BEHAVIOR_DISABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FocusBehaviorRecursive_obj, "FOCUS_BEHAVIOR_ENABLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "FocusBehaviorRecursive", FocusBehaviorRecursive_obj);
	JSValue MouseBehaviorRecursive_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, MouseBehaviorRecursive_obj, "MOUSE_BEHAVIOR_INHERITED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, MouseBehaviorRecursive_obj, "MOUSE_BEHAVIOR_DISABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, MouseBehaviorRecursive_obj, "MOUSE_BEHAVIOR_ENABLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "MouseBehaviorRecursive", MouseBehaviorRecursive_obj);
	JSValue CursorShape_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_ARROW", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_IBEAM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_POINTING_HAND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_CROSS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_WAIT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_BUSY", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_DRAG", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_CAN_DROP", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_FORBIDDEN", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_VSIZE", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_HSIZE", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_BDIAGSIZE", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_FDIAGSIZE", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_MOVE", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_VSPLIT", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_HSPLIT", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, CursorShape_obj, "CURSOR_HELP", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ctor, "CursorShape", CursorShape_obj);
	JSValue LayoutPreset_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_TOP_LEFT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_TOP_RIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_BOTTOM_LEFT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_BOTTOM_RIGHT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_CENTER_LEFT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_CENTER_TOP", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_CENTER_RIGHT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_CENTER_BOTTOM", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_CENTER", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_LEFT_WIDE", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_TOP_WIDE", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_RIGHT_WIDE", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_BOTTOM_WIDE", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_VCENTER_WIDE", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_HCENTER_WIDE", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, LayoutPreset_obj, "PRESET_FULL_RECT", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, ctor, "LayoutPreset", LayoutPreset_obj);
	JSValue LayoutPresetMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LayoutPresetMode_obj, "PRESET_MODE_MINSIZE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LayoutPresetMode_obj, "PRESET_MODE_KEEP_WIDTH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LayoutPresetMode_obj, "PRESET_MODE_KEEP_HEIGHT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LayoutPresetMode_obj, "PRESET_MODE_KEEP_SIZE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "LayoutPresetMode", LayoutPresetMode_obj);
	JSValue SizeFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SizeFlags_obj, "SIZE_SHRINK_BEGIN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SizeFlags_obj, "SIZE_FILL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SizeFlags_obj, "SIZE_EXPAND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SizeFlags_obj, "SIZE_EXPAND_FILL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SizeFlags_obj, "SIZE_SHRINK_CENTER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, SizeFlags_obj, "SIZE_SHRINK_END", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "SizeFlags", SizeFlags_obj);
	JSValue MouseFilter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, MouseFilter_obj, "MOUSE_FILTER_STOP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, MouseFilter_obj, "MOUSE_FILTER_PASS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, MouseFilter_obj, "MOUSE_FILTER_IGNORE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "MouseFilter", MouseFilter_obj);
	JSValue GrowDirection_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GrowDirection_obj, "GROW_DIRECTION_BEGIN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GrowDirection_obj, "GROW_DIRECTION_END", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GrowDirection_obj, "GROW_DIRECTION_BOTH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "GrowDirection", GrowDirection_obj);
	JSValue Anchor_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Anchor_obj, "ANCHOR_BEGIN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Anchor_obj, "ANCHOR_END", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "Anchor", Anchor_obj);
	JSValue LayoutDirection_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_INHERITED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_APPLICATION_LOCALE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_LTR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_RTL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_SYSTEM_LOCALE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_LOCALE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "LayoutDirection", LayoutDirection_obj);
	JSValue TextDirection_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextDirection_obj, "TEXT_DIRECTION_INHERITED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextDirection_obj, "TEXT_DIRECTION_AUTO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextDirection_obj, "TEXT_DIRECTION_LTR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextDirection_obj, "TEXT_DIRECTION_RTL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TextDirection", TextDirection_obj);
}

static int js_control_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Control"] = class_id;
	classes_by_id[class_id] = "Control";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &control_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CanvasItem"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_control_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, control_class_proto_funcs, _countof(control_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, control_class_constructor, "Control", 0, JS_CFUNC_constructor, 0);
	define_control_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Control", ctor);

	return 0;
}

JSModuleDef *_js_init_control_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/canvas_item';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_control_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Control");
	return m;
}

JSModuleDef *js_init_control_module(JSContext *ctx) {
	return _js_init_control_module(ctx, "@godot/classes/control");
}

void __register_control() {
	js_init_control_module(js_context());
}

void register_control() {
	__register_control();
}