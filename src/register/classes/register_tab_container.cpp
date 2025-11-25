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
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/popup.hpp>
#include <godot_cpp/classes/tab_bar.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tab_container.hpp>
using namespace godot;

static void tab_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TabContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tab_container_class_def = {
    "TabContainer",
    tab_container_class_finalizer
};

static JSValue tab_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TabContainer"];
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
        instance = memnew(TabContainer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tab_container_class_get_tab_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_count, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_current_tab(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_current_tab, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_current_tab(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_current_tab, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_get_previous_tab(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_previous_tab, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_select_previous_available(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TabContainer::select_previous_available, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_select_next_available(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TabContainer::select_next_available, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_current_tab_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_current_tab_control, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_bar, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_control, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_alignment, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_alignment, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_tabs_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tabs_position, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tabs_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tabs_position, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_clip_tabs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_clip_tabs, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_clip_tabs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_clip_tabs, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_tabs_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tabs_visible, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_are_tabs_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::are_tabs_visible, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_all_tabs_in_front(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_all_tabs_in_front, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_is_all_tabs_in_front(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::is_all_tabs_in_front, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_tab_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_title, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_title, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_tooltip, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_tooltip, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_icon, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_icon, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_icon_max_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_icon_max_width, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_icon_max_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_icon_max_width, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_disabled, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_is_tab_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::is_tab_disabled, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_hidden, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_is_tab_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::is_tab_hidden, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_metadata, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_metadata, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_tab_button_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_button_icon, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_button_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_button_icon, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_idx_at_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_idx_at_point, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_idx_from_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_idx_from_control, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_popup, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_popup, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_set_drag_to_rearrange_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_drag_to_rearrange_enabled, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_drag_to_rearrange_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_drag_to_rearrange_enabled, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_tabs_rearrange_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tabs_rearrange_group, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tabs_rearrange_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tabs_rearrange_group, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_use_hidden_tabs_for_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_use_hidden_tabs_for_min_size, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_use_hidden_tabs_for_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_use_hidden_tabs_for_min_size, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_tab_focus_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_tab_focus_mode, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_tab_focus_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_tab_focus_mode, ctx, this_val, argc, argv);
}
static JSValue tab_container_class_set_deselect_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TabContainer::set_deselect_enabled, ctx, this_val, argc, argv);
};
static JSValue tab_container_class_get_deselect_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TabContainer::get_deselect_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry tab_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_tab_count", 0, &tab_container_class_get_tab_count),
	JS_CFUNC_DEF("set_current_tab", 1, &tab_container_class_set_current_tab),
	JS_CFUNC_DEF("get_current_tab", 0, &tab_container_class_get_current_tab),
	JS_CFUNC_DEF("get_previous_tab", 0, &tab_container_class_get_previous_tab),
	JS_CFUNC_DEF("select_previous_available", 0, &tab_container_class_select_previous_available),
	JS_CFUNC_DEF("select_next_available", 0, &tab_container_class_select_next_available),
	JS_CFUNC_DEF("get_current_tab_control", 0, &tab_container_class_get_current_tab_control),
	JS_CFUNC_DEF("get_tab_bar", 0, &tab_container_class_get_tab_bar),
	JS_CFUNC_DEF("get_tab_control", 1, &tab_container_class_get_tab_control),
	JS_CFUNC_DEF("set_tab_alignment", 1, &tab_container_class_set_tab_alignment),
	JS_CFUNC_DEF("get_tab_alignment", 0, &tab_container_class_get_tab_alignment),
	JS_CFUNC_DEF("set_tabs_position", 1, &tab_container_class_set_tabs_position),
	JS_CFUNC_DEF("get_tabs_position", 0, &tab_container_class_get_tabs_position),
	JS_CFUNC_DEF("set_clip_tabs", 1, &tab_container_class_set_clip_tabs),
	JS_CFUNC_DEF("get_clip_tabs", 0, &tab_container_class_get_clip_tabs),
	JS_CFUNC_DEF("set_tabs_visible", 1, &tab_container_class_set_tabs_visible),
	JS_CFUNC_DEF("are_tabs_visible", 0, &tab_container_class_are_tabs_visible),
	JS_CFUNC_DEF("set_all_tabs_in_front", 1, &tab_container_class_set_all_tabs_in_front),
	JS_CFUNC_DEF("is_all_tabs_in_front", 0, &tab_container_class_is_all_tabs_in_front),
	JS_CFUNC_DEF("set_tab_title", 2, &tab_container_class_set_tab_title),
	JS_CFUNC_DEF("get_tab_title", 1, &tab_container_class_get_tab_title),
	JS_CFUNC_DEF("set_tab_tooltip", 2, &tab_container_class_set_tab_tooltip),
	JS_CFUNC_DEF("get_tab_tooltip", 1, &tab_container_class_get_tab_tooltip),
	JS_CFUNC_DEF("set_tab_icon", 2, &tab_container_class_set_tab_icon),
	JS_CFUNC_DEF("get_tab_icon", 1, &tab_container_class_get_tab_icon),
	JS_CFUNC_DEF("set_tab_icon_max_width", 2, &tab_container_class_set_tab_icon_max_width),
	JS_CFUNC_DEF("get_tab_icon_max_width", 1, &tab_container_class_get_tab_icon_max_width),
	JS_CFUNC_DEF("set_tab_disabled", 2, &tab_container_class_set_tab_disabled),
	JS_CFUNC_DEF("is_tab_disabled", 1, &tab_container_class_is_tab_disabled),
	JS_CFUNC_DEF("set_tab_hidden", 2, &tab_container_class_set_tab_hidden),
	JS_CFUNC_DEF("is_tab_hidden", 1, &tab_container_class_is_tab_hidden),
	JS_CFUNC_DEF("set_tab_metadata", 2, &tab_container_class_set_tab_metadata),
	JS_CFUNC_DEF("get_tab_metadata", 1, &tab_container_class_get_tab_metadata),
	JS_CFUNC_DEF("set_tab_button_icon", 2, &tab_container_class_set_tab_button_icon),
	JS_CFUNC_DEF("get_tab_button_icon", 1, &tab_container_class_get_tab_button_icon),
	JS_CFUNC_DEF("get_tab_idx_at_point", 1, &tab_container_class_get_tab_idx_at_point),
	JS_CFUNC_DEF("get_tab_idx_from_control", 1, &tab_container_class_get_tab_idx_from_control),
	JS_CFUNC_DEF("set_popup", 1, &tab_container_class_set_popup),
	JS_CFUNC_DEF("get_popup", 0, &tab_container_class_get_popup),
	JS_CFUNC_DEF("set_drag_to_rearrange_enabled", 1, &tab_container_class_set_drag_to_rearrange_enabled),
	JS_CFUNC_DEF("get_drag_to_rearrange_enabled", 0, &tab_container_class_get_drag_to_rearrange_enabled),
	JS_CFUNC_DEF("set_tabs_rearrange_group", 1, &tab_container_class_set_tabs_rearrange_group),
	JS_CFUNC_DEF("get_tabs_rearrange_group", 0, &tab_container_class_get_tabs_rearrange_group),
	JS_CFUNC_DEF("set_use_hidden_tabs_for_min_size", 1, &tab_container_class_set_use_hidden_tabs_for_min_size),
	JS_CFUNC_DEF("get_use_hidden_tabs_for_min_size", 0, &tab_container_class_get_use_hidden_tabs_for_min_size),
	JS_CFUNC_DEF("set_tab_focus_mode", 1, &tab_container_class_set_tab_focus_mode),
	JS_CFUNC_DEF("get_tab_focus_mode", 0, &tab_container_class_get_tab_focus_mode),
	JS_CFUNC_DEF("set_deselect_enabled", 1, &tab_container_class_set_deselect_enabled),
	JS_CFUNC_DEF("get_deselect_enabled", 0, &tab_container_class_get_deselect_enabled),
};


static JSValue tab_container_class_get_active_tab_rearranged_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "active_tab_rearranged_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "active_tab_rearranged"));
		JS_DefinePropertyValueStr(ctx, this_val, "active_tab_rearranged_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tab_container_class_get_tab_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tab_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tab_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "tab_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tab_container_class_get_tab_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tab_clicked_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tab_clicked"));
		JS_DefinePropertyValueStr(ctx, this_val, "tab_clicked_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tab_container_class_get_tab_hovered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tab_hovered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tab_hovered"));
		JS_DefinePropertyValueStr(ctx, this_val, "tab_hovered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tab_container_class_get_tab_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tab_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tab_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "tab_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tab_container_class_get_tab_button_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tab_button_pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tab_button_pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "tab_button_pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tab_container_class_get_pre_popup_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TabContainer *opaque = static_cast<TabContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pre_popup_pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pre_popup_pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "pre_popup_pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_tab_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tab_alignment"),
        JS_NewCFunction(ctx, tab_container_class_get_tab_alignment, "get_tab_alignment", 0),
        JS_NewCFunction(ctx, tab_container_class_set_tab_alignment, "set_tab_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_tab"),
        JS_NewCFunction(ctx, tab_container_class_get_current_tab, "get_current_tab", 0),
        JS_NewCFunction(ctx, tab_container_class_set_current_tab, "set_current_tab", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tabs_position"),
        JS_NewCFunction(ctx, tab_container_class_get_tabs_position, "get_tabs_position", 0),
        JS_NewCFunction(ctx, tab_container_class_set_tabs_position, "set_tabs_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clip_tabs"),
        JS_NewCFunction(ctx, tab_container_class_get_clip_tabs, "get_clip_tabs", 0),
        JS_NewCFunction(ctx, tab_container_class_set_clip_tabs, "set_clip_tabs", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tabs_visible"),
        JS_NewCFunction(ctx, tab_container_class_are_tabs_visible, "are_tabs_visible", 0),
        JS_NewCFunction(ctx, tab_container_class_set_tabs_visible, "set_tabs_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "all_tabs_in_front"),
        JS_NewCFunction(ctx, tab_container_class_is_all_tabs_in_front, "is_all_tabs_in_front", 0),
        JS_NewCFunction(ctx, tab_container_class_set_all_tabs_in_front, "set_all_tabs_in_front", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_to_rearrange_enabled"),
        JS_NewCFunction(ctx, tab_container_class_get_drag_to_rearrange_enabled, "get_drag_to_rearrange_enabled", 0),
        JS_NewCFunction(ctx, tab_container_class_set_drag_to_rearrange_enabled, "set_drag_to_rearrange_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tabs_rearrange_group"),
        JS_NewCFunction(ctx, tab_container_class_get_tabs_rearrange_group, "get_tabs_rearrange_group", 0),
        JS_NewCFunction(ctx, tab_container_class_set_tabs_rearrange_group, "set_tabs_rearrange_group", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_hidden_tabs_for_min_size"),
        JS_NewCFunction(ctx, tab_container_class_get_use_hidden_tabs_for_min_size, "get_use_hidden_tabs_for_min_size", 0),
        JS_NewCFunction(ctx, tab_container_class_set_use_hidden_tabs_for_min_size, "set_use_hidden_tabs_for_min_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tab_focus_mode"),
        JS_NewCFunction(ctx, tab_container_class_get_tab_focus_mode, "get_tab_focus_mode", 0),
        JS_NewCFunction(ctx, tab_container_class_set_tab_focus_mode, "set_tab_focus_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "deselect_enabled"),
        JS_NewCFunction(ctx, tab_container_class_get_deselect_enabled, "get_deselect_enabled", 0),
        JS_NewCFunction(ctx, tab_container_class_set_deselect_enabled, "set_deselect_enabled", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "active_tab_rearranged"),
		JS_NewCFunction(ctx, tab_container_class_get_active_tab_rearranged_signal, "get_active_tab_rearranged_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tab_changed"),
		JS_NewCFunction(ctx, tab_container_class_get_tab_changed_signal, "get_tab_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tab_clicked"),
		JS_NewCFunction(ctx, tab_container_class_get_tab_clicked_signal, "get_tab_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tab_hovered"),
		JS_NewCFunction(ctx, tab_container_class_get_tab_hovered_signal, "get_tab_hovered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tab_selected"),
		JS_NewCFunction(ctx, tab_container_class_get_tab_selected_signal, "get_tab_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tab_button_pressed"),
		JS_NewCFunction(ctx, tab_container_class_get_tab_button_pressed_signal, "get_tab_button_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pre_popup_pressed"),
		JS_NewCFunction(ctx, tab_container_class_get_pre_popup_pressed_signal, "get_pre_popup_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_tab_container_enum(JSContext *ctx, JSValue ctor) {
	JSValue TabPosition_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TabPosition_obj, "POSITION_TOP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TabPosition_obj, "POSITION_BOTTOM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TabPosition_obj, "POSITION_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TabPosition", TabPosition_obj);
}

static int js_tab_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TabContainer"] = class_id;
	classes_by_id[class_id] = "TabContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tab_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tab_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tab_container_class_proto_funcs, _countof(tab_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tab_container_class_constructor, "TabContainer", 0, JS_CFUNC_constructor, 0);
	define_tab_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TabContainer", ctor);
	ctor_list["TabContainer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_tab_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tab_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TabContainer");
	return m;
}

JSModuleDef *js_init_tab_container_module(JSContext *ctx) {
	return _js_init_tab_container_module(ctx, "@godot/classes/tab_container");
}

void __register_tab_container() {
	js_init_tab_container_module(js_context());
}

void register_tab_container() {
	__register_tab_container();
}