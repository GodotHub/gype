#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/popup.hpp>
#include <godot_cpp/classes/shortcut.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/popup_menu.hpp>
using namespace godot;

static void popup_menu_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PopupMenu"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef popup_menu_class_def = {
    "PopupMenu",
    popup_menu_class_finalizer
};

static JSValue popup_menu_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PopupMenu"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PopupMenu *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PopupMenu *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PopupMenu);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue popup_menu_class_activate_item_by_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PopupMenu::activate_item_by_event, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_prefer_native_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_prefer_native_menu, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_prefer_native_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_prefer_native_menu, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_is_native_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_native_menu, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_icon_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_icon_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_check_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_icon_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_icon_check_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_radio_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_radio_check_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_icon_radio_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_icon_radio_check_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_multistate_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_multistate_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_icon_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_icon_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_check_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_check_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_icon_check_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_icon_check_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_radio_check_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_radio_check_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_icon_radio_check_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_icon_radio_check_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_submenu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_submenu_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_submenu_node_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_submenu_node_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_text, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_text_direction, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_language, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_auto_translate_mode, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_icon, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_icon_max_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_icon_max_width, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_icon_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_icon_modulate, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_checked, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_id, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_accelerator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_accelerator, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_metadata, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_disabled, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_submenu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_submenu, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_submenu_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_submenu_node, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_as_separator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_as_separator, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_as_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_as_checkable, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_as_radio_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_as_radio_checkable, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_tooltip, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_indent, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_multistate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_multistate, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_multistate_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_multistate_max, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_shortcut_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_shortcut_disabled, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_toggle_item_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::toggle_item_checked, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_toggle_item_multistate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::toggle_item_multistate, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_text, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_text_direction, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_language, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_auto_translate_mode, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_icon, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_icon_max_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_icon_max_width, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_icon_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_icon_modulate, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_item_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_item_checked, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_id, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_index, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_accelerator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_accelerator, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_metadata, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_item_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_item_disabled, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_submenu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_submenu, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_submenu_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_submenu_node, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_item_separator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_item_separator, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_item_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_item_checkable, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_item_radio_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_item_radio_checkable, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_item_shortcut_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_item_shortcut_disabled, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_tooltip, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_shortcut, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_indent, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_multistate_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_multistate_max, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_multistate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_multistate, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_focused_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_focused_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_focused_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_focused_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_item_count, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_item_count, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_scroll_to_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::scroll_to_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_remove_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::remove_item, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_add_separator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::add_separator, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::clear, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_hide_on_item_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_hide_on_item_selection, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_hide_on_item_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_hide_on_item_selection, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_set_hide_on_checkable_item_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_hide_on_checkable_item_selection, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_hide_on_checkable_item_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_hide_on_checkable_item_selection, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_set_hide_on_state_item_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_hide_on_state_item_selection, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_is_hide_on_state_item_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_hide_on_state_item_selection, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_set_submenu_popup_delay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_submenu_popup_delay, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_submenu_popup_delay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_submenu_popup_delay, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_set_allow_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_allow_search, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_allow_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_allow_search, ctx, this_val, argc, argv);
}
static JSValue popup_menu_class_is_system_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::is_system_menu, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_set_system_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PopupMenu::set_system_menu, ctx, this_val, argc, argv);
};
static JSValue popup_menu_class_get_system_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PopupMenu::get_system_menu, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry popup_menu_class_proto_funcs[] = {
	JS_CFUNC_DEF("activate_item_by_event", 2, &popup_menu_class_activate_item_by_event),
	JS_CFUNC_DEF("set_prefer_native_menu", 1, &popup_menu_class_set_prefer_native_menu),
	JS_CFUNC_DEF("is_prefer_native_menu", 0, &popup_menu_class_is_prefer_native_menu),
	JS_CFUNC_DEF("is_native_menu", 0, &popup_menu_class_is_native_menu),
	JS_CFUNC_DEF("add_item", 3, &popup_menu_class_add_item),
	JS_CFUNC_DEF("add_icon_item", 4, &popup_menu_class_add_icon_item),
	JS_CFUNC_DEF("add_check_item", 3, &popup_menu_class_add_check_item),
	JS_CFUNC_DEF("add_icon_check_item", 4, &popup_menu_class_add_icon_check_item),
	JS_CFUNC_DEF("add_radio_check_item", 3, &popup_menu_class_add_radio_check_item),
	JS_CFUNC_DEF("add_icon_radio_check_item", 4, &popup_menu_class_add_icon_radio_check_item),
	JS_CFUNC_DEF("add_multistate_item", 5, &popup_menu_class_add_multistate_item),
	JS_CFUNC_DEF("add_shortcut", 4, &popup_menu_class_add_shortcut),
	JS_CFUNC_DEF("add_icon_shortcut", 5, &popup_menu_class_add_icon_shortcut),
	JS_CFUNC_DEF("add_check_shortcut", 3, &popup_menu_class_add_check_shortcut),
	JS_CFUNC_DEF("add_icon_check_shortcut", 4, &popup_menu_class_add_icon_check_shortcut),
	JS_CFUNC_DEF("add_radio_check_shortcut", 3, &popup_menu_class_add_radio_check_shortcut),
	JS_CFUNC_DEF("add_icon_radio_check_shortcut", 4, &popup_menu_class_add_icon_radio_check_shortcut),
	JS_CFUNC_DEF("add_submenu_item", 3, &popup_menu_class_add_submenu_item),
	JS_CFUNC_DEF("add_submenu_node_item", 3, &popup_menu_class_add_submenu_node_item),
	JS_CFUNC_DEF("set_item_text", 2, &popup_menu_class_set_item_text),
	JS_CFUNC_DEF("set_item_text_direction", 2, &popup_menu_class_set_item_text_direction),
	JS_CFUNC_DEF("set_item_language", 2, &popup_menu_class_set_item_language),
	JS_CFUNC_DEF("set_item_auto_translate_mode", 2, &popup_menu_class_set_item_auto_translate_mode),
	JS_CFUNC_DEF("set_item_icon", 2, &popup_menu_class_set_item_icon),
	JS_CFUNC_DEF("set_item_icon_max_width", 2, &popup_menu_class_set_item_icon_max_width),
	JS_CFUNC_DEF("set_item_icon_modulate", 2, &popup_menu_class_set_item_icon_modulate),
	JS_CFUNC_DEF("set_item_checked", 2, &popup_menu_class_set_item_checked),
	JS_CFUNC_DEF("set_item_id", 2, &popup_menu_class_set_item_id),
	JS_CFUNC_DEF("set_item_accelerator", 2, &popup_menu_class_set_item_accelerator),
	JS_CFUNC_DEF("set_item_metadata", 2, &popup_menu_class_set_item_metadata),
	JS_CFUNC_DEF("set_item_disabled", 2, &popup_menu_class_set_item_disabled),
	JS_CFUNC_DEF("set_item_submenu", 2, &popup_menu_class_set_item_submenu),
	JS_CFUNC_DEF("set_item_submenu_node", 2, &popup_menu_class_set_item_submenu_node),
	JS_CFUNC_DEF("set_item_as_separator", 2, &popup_menu_class_set_item_as_separator),
	JS_CFUNC_DEF("set_item_as_checkable", 2, &popup_menu_class_set_item_as_checkable),
	JS_CFUNC_DEF("set_item_as_radio_checkable", 2, &popup_menu_class_set_item_as_radio_checkable),
	JS_CFUNC_DEF("set_item_tooltip", 2, &popup_menu_class_set_item_tooltip),
	JS_CFUNC_DEF("set_item_shortcut", 3, &popup_menu_class_set_item_shortcut),
	JS_CFUNC_DEF("set_item_indent", 2, &popup_menu_class_set_item_indent),
	JS_CFUNC_DEF("set_item_multistate", 2, &popup_menu_class_set_item_multistate),
	JS_CFUNC_DEF("set_item_multistate_max", 2, &popup_menu_class_set_item_multistate_max),
	JS_CFUNC_DEF("set_item_shortcut_disabled", 2, &popup_menu_class_set_item_shortcut_disabled),
	JS_CFUNC_DEF("toggle_item_checked", 1, &popup_menu_class_toggle_item_checked),
	JS_CFUNC_DEF("toggle_item_multistate", 1, &popup_menu_class_toggle_item_multistate),
	JS_CFUNC_DEF("get_item_text", 1, &popup_menu_class_get_item_text),
	JS_CFUNC_DEF("get_item_text_direction", 1, &popup_menu_class_get_item_text_direction),
	JS_CFUNC_DEF("get_item_language", 1, &popup_menu_class_get_item_language),
	JS_CFUNC_DEF("get_item_auto_translate_mode", 1, &popup_menu_class_get_item_auto_translate_mode),
	JS_CFUNC_DEF("get_item_icon", 1, &popup_menu_class_get_item_icon),
	JS_CFUNC_DEF("get_item_icon_max_width", 1, &popup_menu_class_get_item_icon_max_width),
	JS_CFUNC_DEF("get_item_icon_modulate", 1, &popup_menu_class_get_item_icon_modulate),
	JS_CFUNC_DEF("is_item_checked", 1, &popup_menu_class_is_item_checked),
	JS_CFUNC_DEF("get_item_id", 1, &popup_menu_class_get_item_id),
	JS_CFUNC_DEF("get_item_index", 1, &popup_menu_class_get_item_index),
	JS_CFUNC_DEF("get_item_accelerator", 1, &popup_menu_class_get_item_accelerator),
	JS_CFUNC_DEF("get_item_metadata", 1, &popup_menu_class_get_item_metadata),
	JS_CFUNC_DEF("is_item_disabled", 1, &popup_menu_class_is_item_disabled),
	JS_CFUNC_DEF("get_item_submenu", 1, &popup_menu_class_get_item_submenu),
	JS_CFUNC_DEF("get_item_submenu_node", 1, &popup_menu_class_get_item_submenu_node),
	JS_CFUNC_DEF("is_item_separator", 1, &popup_menu_class_is_item_separator),
	JS_CFUNC_DEF("is_item_checkable", 1, &popup_menu_class_is_item_checkable),
	JS_CFUNC_DEF("is_item_radio_checkable", 1, &popup_menu_class_is_item_radio_checkable),
	JS_CFUNC_DEF("is_item_shortcut_disabled", 1, &popup_menu_class_is_item_shortcut_disabled),
	JS_CFUNC_DEF("get_item_tooltip", 1, &popup_menu_class_get_item_tooltip),
	JS_CFUNC_DEF("get_item_shortcut", 1, &popup_menu_class_get_item_shortcut),
	JS_CFUNC_DEF("get_item_indent", 1, &popup_menu_class_get_item_indent),
	JS_CFUNC_DEF("get_item_multistate_max", 1, &popup_menu_class_get_item_multistate_max),
	JS_CFUNC_DEF("get_item_multistate", 1, &popup_menu_class_get_item_multistate),
	JS_CFUNC_DEF("set_focused_item", 1, &popup_menu_class_set_focused_item),
	JS_CFUNC_DEF("get_focused_item", 0, &popup_menu_class_get_focused_item),
	JS_CFUNC_DEF("set_item_count", 1, &popup_menu_class_set_item_count),
	JS_CFUNC_DEF("get_item_count", 0, &popup_menu_class_get_item_count),
	JS_CFUNC_DEF("scroll_to_item", 1, &popup_menu_class_scroll_to_item),
	JS_CFUNC_DEF("remove_item", 1, &popup_menu_class_remove_item),
	JS_CFUNC_DEF("add_separator", 2, &popup_menu_class_add_separator),
	JS_CFUNC_DEF("clear", 1, &popup_menu_class_clear),
	JS_CFUNC_DEF("set_hide_on_item_selection", 1, &popup_menu_class_set_hide_on_item_selection),
	JS_CFUNC_DEF("is_hide_on_item_selection", 0, &popup_menu_class_is_hide_on_item_selection),
	JS_CFUNC_DEF("set_hide_on_checkable_item_selection", 1, &popup_menu_class_set_hide_on_checkable_item_selection),
	JS_CFUNC_DEF("is_hide_on_checkable_item_selection", 0, &popup_menu_class_is_hide_on_checkable_item_selection),
	JS_CFUNC_DEF("set_hide_on_state_item_selection", 1, &popup_menu_class_set_hide_on_state_item_selection),
	JS_CFUNC_DEF("is_hide_on_state_item_selection", 0, &popup_menu_class_is_hide_on_state_item_selection),
	JS_CFUNC_DEF("set_submenu_popup_delay", 1, &popup_menu_class_set_submenu_popup_delay),
	JS_CFUNC_DEF("get_submenu_popup_delay", 0, &popup_menu_class_get_submenu_popup_delay),
	JS_CFUNC_DEF("set_allow_search", 1, &popup_menu_class_set_allow_search),
	JS_CFUNC_DEF("get_allow_search", 0, &popup_menu_class_get_allow_search),
	JS_CFUNC_DEF("is_system_menu", 0, &popup_menu_class_is_system_menu),
	JS_CFUNC_DEF("set_system_menu", 1, &popup_menu_class_set_system_menu),
	JS_CFUNC_DEF("get_system_menu", 0, &popup_menu_class_get_system_menu),
};


static JSValue popup_menu_class_get_id_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	PopupMenu *opaque = static_cast<PopupMenu *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "id_pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "id_pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "id_pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue popup_menu_class_get_id_focused_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	PopupMenu *opaque = static_cast<PopupMenu *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "id_focused_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "id_focused"));
		JS_DefinePropertyValueStr(ctx, this_val, "id_focused_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue popup_menu_class_get_index_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	PopupMenu *opaque = static_cast<PopupMenu *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "index_pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "index_pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "index_pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue popup_menu_class_get_menu_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	PopupMenu *opaque = static_cast<PopupMenu *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "menu_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "menu_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "menu_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_popup_menu_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hide_on_item_selection"),
        JS_NewCFunction(ctx, popup_menu_class_is_hide_on_item_selection, "is_hide_on_item_selection", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_hide_on_item_selection, "set_hide_on_item_selection", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hide_on_checkable_item_selection"),
        JS_NewCFunction(ctx, popup_menu_class_is_hide_on_checkable_item_selection, "is_hide_on_checkable_item_selection", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_hide_on_checkable_item_selection, "set_hide_on_checkable_item_selection", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hide_on_state_item_selection"),
        JS_NewCFunction(ctx, popup_menu_class_is_hide_on_state_item_selection, "is_hide_on_state_item_selection", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_hide_on_state_item_selection, "set_hide_on_state_item_selection", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "submenu_popup_delay"),
        JS_NewCFunction(ctx, popup_menu_class_get_submenu_popup_delay, "get_submenu_popup_delay", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_submenu_popup_delay, "set_submenu_popup_delay", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_search"),
        JS_NewCFunction(ctx, popup_menu_class_get_allow_search, "get_allow_search", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_allow_search, "set_allow_search", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "system_menu_id"),
        JS_NewCFunction(ctx, popup_menu_class_get_system_menu, "get_system_menu", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_system_menu, "set_system_menu", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "prefer_native_menu"),
        JS_NewCFunction(ctx, popup_menu_class_is_prefer_native_menu, "is_prefer_native_menu", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_prefer_native_menu, "set_prefer_native_menu", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "item_count"),
        JS_NewCFunction(ctx, popup_menu_class_get_item_count, "get_item_count", 0),
        JS_NewCFunction(ctx, popup_menu_class_set_item_count, "set_item_count", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "id_pressed"),
		JS_NewCFunction(ctx, popup_menu_class_get_id_pressed_signal, "get_id_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "id_focused"),
		JS_NewCFunction(ctx, popup_menu_class_get_id_focused_signal, "get_id_focused_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "index_pressed"),
		JS_NewCFunction(ctx, popup_menu_class_get_index_pressed_signal, "get_index_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "menu_changed"),
		JS_NewCFunction(ctx, popup_menu_class_get_menu_changed_signal, "get_menu_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_popup_menu_enum(JSContext *ctx, JSValue ctor) {
}

static int js_popup_menu_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PopupMenu"] = class_id;
	classes_by_id[class_id] = "PopupMenu";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &popup_menu_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Popup"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_popup_menu_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, popup_menu_class_proto_funcs, _countof(popup_menu_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, popup_menu_class_constructor, "PopupMenu", 0, JS_CFUNC_constructor, 0);
	define_popup_menu_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PopupMenu", ctor);

	return 0;
}

JSModuleDef *_js_init_popup_menu_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/popup';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_popup_menu_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PopupMenu");
	return m;
}

JSModuleDef *js_init_popup_menu_module(JSContext *ctx) {
	return _js_init_popup_menu_module(ctx, "@godot/classes/popup_menu");
}

void __register_popup_menu() {
	js_init_popup_menu_module(js_context());
}

void register_popup_menu() {
	__register_popup_menu();
}