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
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/line_edit.hpp>
using namespace godot;

static void line_edit_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["LineEdit"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef line_edit_class_def = {
    "LineEdit",
    line_edit_class_finalizer
};

static JSValue line_edit_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["LineEdit"];
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
        instance = memnew(LineEdit);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue line_edit_class_has_ime_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::has_ime_text, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_cancel_ime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::cancel_ime, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_apply_ime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::apply_ime, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_horizontal_alignment, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_horizontal_alignment, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::edit, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_unedit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::unedit, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_editing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_editing, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_keep_editing_on_text_submit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_keep_editing_on_text_submit, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_editing_kept_on_text_submit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_editing_kept_on_text_submit, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::clear, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::select, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_select_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::select_all, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_deselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::deselect, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_has_undo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::has_undo, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_has_redo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::has_redo, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_has_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::has_selection, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_selected_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&LineEdit::get_selected_text, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_selection_from_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_selection_from_column, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_selection_to_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_selection_to_column, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_text, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_text, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_get_draw_control_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_draw_control_chars, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_draw_control_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_draw_control_chars, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_text_direction, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_text_direction, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_language, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_language, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_structured_text_bidi_override, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_structured_text_bidi_override, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_structured_text_bidi_override_options, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		LineEdit *obj = static_cast<LineEdit *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_structured_text_bidi_override_options();
	};
	proxy->setter = [this_val](const Array &value) -> void {
		LineEdit *js_proxy = static_cast<LineEdit *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_structured_text_bidi_override_options(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue line_edit_class_set_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_placeholder, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_placeholder, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_caret_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_caret_column, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_caret_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_caret_column, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_get_next_composite_character_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_next_composite_character_column, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_previous_composite_character_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_previous_composite_character_column, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_scroll_offset, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_expand_to_text_length_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_expand_to_text_length_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_expand_to_text_length_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_expand_to_text_length_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_caret_blink_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_caret_blink_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_caret_blink_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_caret_blink_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_caret_mid_grapheme_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_caret_mid_grapheme_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_caret_mid_grapheme_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_caret_mid_grapheme_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_caret_force_displayed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_caret_force_displayed, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_caret_force_displayed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_caret_force_displayed, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_caret_blink_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_caret_blink_interval, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_caret_blink_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_caret_blink_interval, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_max_length, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_max_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_max_length, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_insert_text_at_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::insert_text_at_caret, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_delete_char_at_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::delete_char_at_caret, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_delete_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::delete_text, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_editable, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_editable, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_secret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_secret, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_secret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_secret, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_secret_character(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_secret_character, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_secret_character(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_secret_character, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_menu_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::menu_option, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_menu, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_menu_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_menu_visible, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_set_context_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_context_menu_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_context_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&LineEdit::is_context_menu_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_emoji_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_emoji_menu_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_emoji_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_emoji_menu_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_backspace_deletes_composite_character_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_backspace_deletes_composite_character_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_backspace_deletes_composite_character_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_backspace_deletes_composite_character_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_virtual_keyboard_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_virtual_keyboard_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_virtual_keyboard_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_virtual_keyboard_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_virtual_keyboard_show_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_virtual_keyboard_show_on_focus, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_virtual_keyboard_show_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_virtual_keyboard_show_on_focus, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_virtual_keyboard_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_virtual_keyboard_type, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_virtual_keyboard_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::get_virtual_keyboard_type, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_clear_button_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_clear_button_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_clear_button_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_clear_button_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_shortcut_keys_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_shortcut_keys_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_shortcut_keys_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_shortcut_keys_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_middle_mouse_paste_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_middle_mouse_paste_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_middle_mouse_paste_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_middle_mouse_paste_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_selecting_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_selecting_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_selecting_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_selecting_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_deselect_on_focus_loss_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_deselect_on_focus_loss_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_deselect_on_focus_loss_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_deselect_on_focus_loss_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_drag_and_drop_selection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_drag_and_drop_selection_enabled, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_drag_and_drop_selection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_drag_and_drop_selection_enabled, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_right_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_right_icon, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_get_right_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&LineEdit::get_right_icon, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_flat, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_flat, ctx, this_val, argc, argv);
}
static JSValue line_edit_class_set_select_all_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LineEdit::set_select_all_on_focus, ctx, this_val, argc, argv);
};
static JSValue line_edit_class_is_select_all_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LineEdit::is_select_all_on_focus, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry line_edit_class_proto_funcs[] = {
	JS_CFUNC_DEF("has_ime_text", 0, &line_edit_class_has_ime_text),
	JS_CFUNC_DEF("cancel_ime", 0, &line_edit_class_cancel_ime),
	JS_CFUNC_DEF("apply_ime", 0, &line_edit_class_apply_ime),
	JS_CFUNC_DEF("set_horizontal_alignment", 1, &line_edit_class_set_horizontal_alignment),
	JS_CFUNC_DEF("get_horizontal_alignment", 0, &line_edit_class_get_horizontal_alignment),
	JS_CFUNC_DEF("edit", 0, &line_edit_class_edit),
	JS_CFUNC_DEF("unedit", 0, &line_edit_class_unedit),
	JS_CFUNC_DEF("is_editing", 0, &line_edit_class_is_editing),
	JS_CFUNC_DEF("set_keep_editing_on_text_submit", 1, &line_edit_class_set_keep_editing_on_text_submit),
	JS_CFUNC_DEF("is_editing_kept_on_text_submit", 0, &line_edit_class_is_editing_kept_on_text_submit),
	JS_CFUNC_DEF("clear", 0, &line_edit_class_clear),
	JS_CFUNC_DEF("select", 2, &line_edit_class_select),
	JS_CFUNC_DEF("select_all", 0, &line_edit_class_select_all),
	JS_CFUNC_DEF("deselect", 0, &line_edit_class_deselect),
	JS_CFUNC_DEF("has_undo", 0, &line_edit_class_has_undo),
	JS_CFUNC_DEF("has_redo", 0, &line_edit_class_has_redo),
	JS_CFUNC_DEF("has_selection", 0, &line_edit_class_has_selection),
	JS_CFUNC_DEF("get_selected_text", 0, &line_edit_class_get_selected_text),
	JS_CFUNC_DEF("get_selection_from_column", 0, &line_edit_class_get_selection_from_column),
	JS_CFUNC_DEF("get_selection_to_column", 0, &line_edit_class_get_selection_to_column),
	JS_CFUNC_DEF("set_text", 1, &line_edit_class_set_text),
	JS_CFUNC_DEF("get_text", 0, &line_edit_class_get_text),
	JS_CFUNC_DEF("get_draw_control_chars", 0, &line_edit_class_get_draw_control_chars),
	JS_CFUNC_DEF("set_draw_control_chars", 1, &line_edit_class_set_draw_control_chars),
	JS_CFUNC_DEF("set_text_direction", 1, &line_edit_class_set_text_direction),
	JS_CFUNC_DEF("get_text_direction", 0, &line_edit_class_get_text_direction),
	JS_CFUNC_DEF("set_language", 1, &line_edit_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &line_edit_class_get_language),
	JS_CFUNC_DEF("set_structured_text_bidi_override", 1, &line_edit_class_set_structured_text_bidi_override),
	JS_CFUNC_DEF("get_structured_text_bidi_override", 0, &line_edit_class_get_structured_text_bidi_override),
	JS_CFUNC_DEF("set_structured_text_bidi_override_options", 1, &line_edit_class_set_structured_text_bidi_override_options),
	JS_CFUNC_DEF("get_structured_text_bidi_override_options", 0, &line_edit_class_get_structured_text_bidi_override_options),
	JS_CFUNC_DEF("set_placeholder", 1, &line_edit_class_set_placeholder),
	JS_CFUNC_DEF("get_placeholder", 0, &line_edit_class_get_placeholder),
	JS_CFUNC_DEF("set_caret_column", 1, &line_edit_class_set_caret_column),
	JS_CFUNC_DEF("get_caret_column", 0, &line_edit_class_get_caret_column),
	JS_CFUNC_DEF("get_next_composite_character_column", 1, &line_edit_class_get_next_composite_character_column),
	JS_CFUNC_DEF("get_previous_composite_character_column", 1, &line_edit_class_get_previous_composite_character_column),
	JS_CFUNC_DEF("get_scroll_offset", 0, &line_edit_class_get_scroll_offset),
	JS_CFUNC_DEF("set_expand_to_text_length_enabled", 1, &line_edit_class_set_expand_to_text_length_enabled),
	JS_CFUNC_DEF("is_expand_to_text_length_enabled", 0, &line_edit_class_is_expand_to_text_length_enabled),
	JS_CFUNC_DEF("set_caret_blink_enabled", 1, &line_edit_class_set_caret_blink_enabled),
	JS_CFUNC_DEF("is_caret_blink_enabled", 0, &line_edit_class_is_caret_blink_enabled),
	JS_CFUNC_DEF("set_caret_mid_grapheme_enabled", 1, &line_edit_class_set_caret_mid_grapheme_enabled),
	JS_CFUNC_DEF("is_caret_mid_grapheme_enabled", 0, &line_edit_class_is_caret_mid_grapheme_enabled),
	JS_CFUNC_DEF("set_caret_force_displayed", 1, &line_edit_class_set_caret_force_displayed),
	JS_CFUNC_DEF("is_caret_force_displayed", 0, &line_edit_class_is_caret_force_displayed),
	JS_CFUNC_DEF("set_caret_blink_interval", 1, &line_edit_class_set_caret_blink_interval),
	JS_CFUNC_DEF("get_caret_blink_interval", 0, &line_edit_class_get_caret_blink_interval),
	JS_CFUNC_DEF("set_max_length", 1, &line_edit_class_set_max_length),
	JS_CFUNC_DEF("get_max_length", 0, &line_edit_class_get_max_length),
	JS_CFUNC_DEF("insert_text_at_caret", 1, &line_edit_class_insert_text_at_caret),
	JS_CFUNC_DEF("delete_char_at_caret", 0, &line_edit_class_delete_char_at_caret),
	JS_CFUNC_DEF("delete_text", 2, &line_edit_class_delete_text),
	JS_CFUNC_DEF("set_editable", 1, &line_edit_class_set_editable),
	JS_CFUNC_DEF("is_editable", 0, &line_edit_class_is_editable),
	JS_CFUNC_DEF("set_secret", 1, &line_edit_class_set_secret),
	JS_CFUNC_DEF("is_secret", 0, &line_edit_class_is_secret),
	JS_CFUNC_DEF("set_secret_character", 1, &line_edit_class_set_secret_character),
	JS_CFUNC_DEF("get_secret_character", 0, &line_edit_class_get_secret_character),
	JS_CFUNC_DEF("menu_option", 1, &line_edit_class_menu_option),
	JS_CFUNC_DEF("get_menu", 0, &line_edit_class_get_menu),
	JS_CFUNC_DEF("is_menu_visible", 0, &line_edit_class_is_menu_visible),
	JS_CFUNC_DEF("set_context_menu_enabled", 1, &line_edit_class_set_context_menu_enabled),
	JS_CFUNC_DEF("is_context_menu_enabled", 0, &line_edit_class_is_context_menu_enabled),
	JS_CFUNC_DEF("set_emoji_menu_enabled", 1, &line_edit_class_set_emoji_menu_enabled),
	JS_CFUNC_DEF("is_emoji_menu_enabled", 0, &line_edit_class_is_emoji_menu_enabled),
	JS_CFUNC_DEF("set_backspace_deletes_composite_character_enabled", 1, &line_edit_class_set_backspace_deletes_composite_character_enabled),
	JS_CFUNC_DEF("is_backspace_deletes_composite_character_enabled", 0, &line_edit_class_is_backspace_deletes_composite_character_enabled),
	JS_CFUNC_DEF("set_virtual_keyboard_enabled", 1, &line_edit_class_set_virtual_keyboard_enabled),
	JS_CFUNC_DEF("is_virtual_keyboard_enabled", 0, &line_edit_class_is_virtual_keyboard_enabled),
	JS_CFUNC_DEF("set_virtual_keyboard_show_on_focus", 1, &line_edit_class_set_virtual_keyboard_show_on_focus),
	JS_CFUNC_DEF("get_virtual_keyboard_show_on_focus", 0, &line_edit_class_get_virtual_keyboard_show_on_focus),
	JS_CFUNC_DEF("set_virtual_keyboard_type", 1, &line_edit_class_set_virtual_keyboard_type),
	JS_CFUNC_DEF("get_virtual_keyboard_type", 0, &line_edit_class_get_virtual_keyboard_type),
	JS_CFUNC_DEF("set_clear_button_enabled", 1, &line_edit_class_set_clear_button_enabled),
	JS_CFUNC_DEF("is_clear_button_enabled", 0, &line_edit_class_is_clear_button_enabled),
	JS_CFUNC_DEF("set_shortcut_keys_enabled", 1, &line_edit_class_set_shortcut_keys_enabled),
	JS_CFUNC_DEF("is_shortcut_keys_enabled", 0, &line_edit_class_is_shortcut_keys_enabled),
	JS_CFUNC_DEF("set_middle_mouse_paste_enabled", 1, &line_edit_class_set_middle_mouse_paste_enabled),
	JS_CFUNC_DEF("is_middle_mouse_paste_enabled", 0, &line_edit_class_is_middle_mouse_paste_enabled),
	JS_CFUNC_DEF("set_selecting_enabled", 1, &line_edit_class_set_selecting_enabled),
	JS_CFUNC_DEF("is_selecting_enabled", 0, &line_edit_class_is_selecting_enabled),
	JS_CFUNC_DEF("set_deselect_on_focus_loss_enabled", 1, &line_edit_class_set_deselect_on_focus_loss_enabled),
	JS_CFUNC_DEF("is_deselect_on_focus_loss_enabled", 0, &line_edit_class_is_deselect_on_focus_loss_enabled),
	JS_CFUNC_DEF("set_drag_and_drop_selection_enabled", 1, &line_edit_class_set_drag_and_drop_selection_enabled),
	JS_CFUNC_DEF("is_drag_and_drop_selection_enabled", 0, &line_edit_class_is_drag_and_drop_selection_enabled),
	JS_CFUNC_DEF("set_right_icon", 1, &line_edit_class_set_right_icon),
	JS_CFUNC_DEF("get_right_icon", 0, &line_edit_class_get_right_icon),
	JS_CFUNC_DEF("set_flat", 1, &line_edit_class_set_flat),
	JS_CFUNC_DEF("is_flat", 0, &line_edit_class_is_flat),
	JS_CFUNC_DEF("set_select_all_on_focus", 1, &line_edit_class_set_select_all_on_focus),
	JS_CFUNC_DEF("is_select_all_on_focus", 0, &line_edit_class_is_select_all_on_focus),
};


static JSValue line_edit_class_get_text_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	LineEdit *opaque = static_cast<LineEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "text_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "text_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "text_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue line_edit_class_get_text_change_rejected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	LineEdit *opaque = static_cast<LineEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "text_change_rejected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "text_change_rejected"));
		JS_DefinePropertyValueStr(ctx, this_val, "text_change_rejected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue line_edit_class_get_text_submitted_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	LineEdit *opaque = static_cast<LineEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "text_submitted_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "text_submitted"));
		JS_DefinePropertyValueStr(ctx, this_val, "text_submitted_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue line_edit_class_get_editing_toggled_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	LineEdit *opaque = static_cast<LineEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "editing_toggled_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "editing_toggled"));
		JS_DefinePropertyValueStr(ctx, this_val, "editing_toggled_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_line_edit_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text"),
        JS_NewCFunction(ctx, line_edit_class_get_text, "get_text", 0),
        JS_NewCFunction(ctx, line_edit_class_set_text, "set_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "placeholder_text"),
        JS_NewCFunction(ctx, line_edit_class_get_placeholder, "get_placeholder", 0),
        JS_NewCFunction(ctx, line_edit_class_set_placeholder, "set_placeholder", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alignment"),
        JS_NewCFunction(ctx, line_edit_class_get_horizontal_alignment, "get_horizontal_alignment", 0),
        JS_NewCFunction(ctx, line_edit_class_set_horizontal_alignment, "set_horizontal_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_length"),
        JS_NewCFunction(ctx, line_edit_class_get_max_length, "get_max_length", 0),
        JS_NewCFunction(ctx, line_edit_class_set_max_length, "set_max_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editable"),
        JS_NewCFunction(ctx, line_edit_class_is_editable, "is_editable", 0),
        JS_NewCFunction(ctx, line_edit_class_set_editable, "set_editable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_editing_on_text_submit"),
        JS_NewCFunction(ctx, line_edit_class_is_editing_kept_on_text_submit, "is_editing_kept_on_text_submit", 0),
        JS_NewCFunction(ctx, line_edit_class_set_keep_editing_on_text_submit, "set_keep_editing_on_text_submit", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "expand_to_text_length"),
        JS_NewCFunction(ctx, line_edit_class_is_expand_to_text_length_enabled, "is_expand_to_text_length_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_expand_to_text_length_enabled, "set_expand_to_text_length_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "context_menu_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_context_menu_enabled, "is_context_menu_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_context_menu_enabled, "set_context_menu_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emoji_menu_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_emoji_menu_enabled, "is_emoji_menu_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_emoji_menu_enabled, "set_emoji_menu_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "backspace_deletes_composite_character_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_backspace_deletes_composite_character_enabled, "is_backspace_deletes_composite_character_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_backspace_deletes_composite_character_enabled, "set_backspace_deletes_composite_character_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "virtual_keyboard_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_virtual_keyboard_enabled, "is_virtual_keyboard_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_virtual_keyboard_enabled, "set_virtual_keyboard_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "virtual_keyboard_show_on_focus"),
        JS_NewCFunction(ctx, line_edit_class_get_virtual_keyboard_show_on_focus, "get_virtual_keyboard_show_on_focus", 0),
        JS_NewCFunction(ctx, line_edit_class_set_virtual_keyboard_show_on_focus, "set_virtual_keyboard_show_on_focus", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "virtual_keyboard_type"),
        JS_NewCFunction(ctx, line_edit_class_get_virtual_keyboard_type, "get_virtual_keyboard_type", 0),
        JS_NewCFunction(ctx, line_edit_class_set_virtual_keyboard_type, "set_virtual_keyboard_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clear_button_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_clear_button_enabled, "is_clear_button_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_clear_button_enabled, "set_clear_button_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shortcut_keys_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_shortcut_keys_enabled, "is_shortcut_keys_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_shortcut_keys_enabled, "set_shortcut_keys_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "middle_mouse_paste_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_middle_mouse_paste_enabled, "is_middle_mouse_paste_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_middle_mouse_paste_enabled, "set_middle_mouse_paste_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "selecting_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_selecting_enabled, "is_selecting_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_selecting_enabled, "set_selecting_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "deselect_on_focus_loss_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_deselect_on_focus_loss_enabled, "is_deselect_on_focus_loss_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_deselect_on_focus_loss_enabled, "set_deselect_on_focus_loss_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_and_drop_selection_enabled"),
        JS_NewCFunction(ctx, line_edit_class_is_drag_and_drop_selection_enabled, "is_drag_and_drop_selection_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_drag_and_drop_selection_enabled, "set_drag_and_drop_selection_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "right_icon"),
        JS_NewCFunction(ctx, line_edit_class_get_right_icon, "get_right_icon", 0),
        JS_NewCFunction(ctx, line_edit_class_set_right_icon, "set_right_icon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flat"),
        JS_NewCFunction(ctx, line_edit_class_is_flat, "is_flat", 0),
        JS_NewCFunction(ctx, line_edit_class_set_flat, "set_flat", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_control_chars"),
        JS_NewCFunction(ctx, line_edit_class_get_draw_control_chars, "get_draw_control_chars", 0),
        JS_NewCFunction(ctx, line_edit_class_set_draw_control_chars, "set_draw_control_chars", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "select_all_on_focus"),
        JS_NewCFunction(ctx, line_edit_class_is_select_all_on_focus, "is_select_all_on_focus", 0),
        JS_NewCFunction(ctx, line_edit_class_set_select_all_on_focus, "set_select_all_on_focus", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_blink"),
        JS_NewCFunction(ctx, line_edit_class_is_caret_blink_enabled, "is_caret_blink_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_caret_blink_enabled, "set_caret_blink_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_blink_interval"),
        JS_NewCFunction(ctx, line_edit_class_get_caret_blink_interval, "get_caret_blink_interval", 0),
        JS_NewCFunction(ctx, line_edit_class_set_caret_blink_interval, "set_caret_blink_interval", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_column"),
        JS_NewCFunction(ctx, line_edit_class_get_caret_column, "get_caret_column", 0),
        JS_NewCFunction(ctx, line_edit_class_set_caret_column, "set_caret_column", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_force_displayed"),
        JS_NewCFunction(ctx, line_edit_class_is_caret_force_displayed, "is_caret_force_displayed", 0),
        JS_NewCFunction(ctx, line_edit_class_set_caret_force_displayed, "set_caret_force_displayed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_mid_grapheme"),
        JS_NewCFunction(ctx, line_edit_class_is_caret_mid_grapheme_enabled, "is_caret_mid_grapheme_enabled", 0),
        JS_NewCFunction(ctx, line_edit_class_set_caret_mid_grapheme_enabled, "set_caret_mid_grapheme_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secret"),
        JS_NewCFunction(ctx, line_edit_class_is_secret, "is_secret", 0),
        JS_NewCFunction(ctx, line_edit_class_set_secret, "set_secret", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secret_character"),
        JS_NewCFunction(ctx, line_edit_class_get_secret_character, "get_secret_character", 0),
        JS_NewCFunction(ctx, line_edit_class_set_secret_character, "set_secret_character", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_direction"),
        JS_NewCFunction(ctx, line_edit_class_get_text_direction, "get_text_direction", 0),
        JS_NewCFunction(ctx, line_edit_class_set_text_direction, "set_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, line_edit_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, line_edit_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override"),
        JS_NewCFunction(ctx, line_edit_class_get_structured_text_bidi_override, "get_structured_text_bidi_override", 0),
        JS_NewCFunction(ctx, line_edit_class_set_structured_text_bidi_override, "set_structured_text_bidi_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override_options"),
        JS_NewCFunction(ctx, line_edit_class_get_structured_text_bidi_override_options, "get_structured_text_bidi_override_options", 0),
        JS_NewCFunction(ctx, line_edit_class_set_structured_text_bidi_override_options, "set_structured_text_bidi_override_options", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "text_changed"),
		JS_NewCFunction(ctx, line_edit_class_get_text_changed_signal, "get_text_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "text_change_rejected"),
		JS_NewCFunction(ctx, line_edit_class_get_text_change_rejected_signal, "get_text_change_rejected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "text_submitted"),
		JS_NewCFunction(ctx, line_edit_class_get_text_submitted_signal, "get_text_submitted_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "editing_toggled"),
		JS_NewCFunction(ctx, line_edit_class_get_editing_toggled_signal, "get_editing_toggled_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_line_edit_enum(JSContext *ctx, JSValue ctor) {
	JSValue MenuItems_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_CUT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_COPY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_PASTE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_CLEAR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_SELECT_ALL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_UNDO", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_REDO", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_SUBMENU_TEXT_DIR", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_DIR_INHERITED", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_DIR_AUTO", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_DIR_LTR", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_DIR_RTL", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_DISPLAY_UCC", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_SUBMENU_INSERT_UCC", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_LRM", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_RLM", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_LRE", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_RLE", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_LRO", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_RLO", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_PDF", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_ALM", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_LRI", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_RLI", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_FSI", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_PDI", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_ZWJ", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_ZWNJ", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_WJ", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_INSERT_SHY", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_EMOJI_AND_SYMBOL", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, MenuItems_obj, "MENU_MAX", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, ctor, "MenuItems", MenuItems_obj);
	JSValue VirtualKeyboardType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_DEFAULT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_MULTILINE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_NUMBER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_NUMBER_DECIMAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_PHONE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_EMAIL_ADDRESS", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_PASSWORD", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, VirtualKeyboardType_obj, "KEYBOARD_TYPE_URL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "VirtualKeyboardType", VirtualKeyboardType_obj);
}

static int js_line_edit_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["LineEdit"] = class_id;
	classes_by_id[class_id] = "LineEdit";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &line_edit_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_line_edit_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, line_edit_class_proto_funcs, _countof(line_edit_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, line_edit_class_constructor, "LineEdit", 0, JS_CFUNC_constructor, 0);
	define_line_edit_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "LineEdit", ctor);
	ctor_list["LineEdit"] = ctor;

	return 0;
}

JSModuleDef *_js_init_line_edit_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_line_edit_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "LineEdit");
	return m;
}

JSModuleDef *js_init_line_edit_module(JSContext *ctx) {
	return _js_init_line_edit_module(ctx, "@godot/classes/line_edit");
}

void __register_line_edit() {
	js_init_line_edit_module(js_context());
}

void register_line_edit() {
	__register_line_edit();
}