#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/h_scroll_bar.hpp>
#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/classes/syntax_highlighter.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/v_scroll_bar.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/text_edit.hpp>
using namespace godot;

static void text_edit_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TextEdit"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef text_edit_class_def = {
    "TextEdit",
    text_edit_class_finalizer
};

static JSValue text_edit_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TextEdit"];
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
        instance = memnew(TextEdit);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue text_edit_class_has_ime_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::has_ime_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_cancel_ime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::cancel_ime, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_apply_ime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::apply_ime, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_editable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_editable, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_text_direction, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_text_direction, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_language, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_language, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_structured_text_bidi_override, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_structured_text_bidi_override, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_structured_text_bidi_override_options, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		TextEdit *obj = static_cast<TextEdit *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_structured_text_bidi_override_options();
	};
	proxy->setter = [this_val](const Array &value) -> void {
		TextEdit *js_proxy = static_cast<TextEdit *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue text_edit_class_set_tab_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_tab_size, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_tab_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_tab_size, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_indent_wrapped_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_indent_wrapped_lines, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_indent_wrapped_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_indent_wrapped_lines, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_tab_input_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_tab_input_mode, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_tab_input_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_tab_input_mode, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_overtype_mode_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_overtype_mode_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_overtype_mode_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_overtype_mode_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_context_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_context_menu_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_context_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_context_menu_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_emoji_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_emoji_menu_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_emoji_menu_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_emoji_menu_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_backspace_deletes_composite_character_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_backspace_deletes_composite_character_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_backspace_deletes_composite_character_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_backspace_deletes_composite_character_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_shortcut_keys_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_shortcut_keys_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_shortcut_keys_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_shortcut_keys_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_virtual_keyboard_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_virtual_keyboard_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_virtual_keyboard_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_virtual_keyboard_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_virtual_keyboard_show_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_virtual_keyboard_show_on_focus, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_virtual_keyboard_show_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_virtual_keyboard_show_on_focus, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_middle_mouse_paste_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_middle_mouse_paste_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_middle_mouse_paste_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_middle_mouse_paste_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_empty_selection_clipboard_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_empty_selection_clipboard_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_empty_selection_clipboard_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_empty_selection_clipboard_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::clear, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_text, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_get_line_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_count, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_placeholder, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_placeholder, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_with_ime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_with_ime, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_width, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_height, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_indent_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_indent_level, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_first_non_whitespace_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_first_non_whitespace_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_swap_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::swap_lines, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_insert_line_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::insert_line_at, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_remove_line_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::remove_line_at, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_insert_text_at_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::insert_text_at_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_insert_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::insert_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_remove_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::remove_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_last_unhidden_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_last_unhidden_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_next_visible_line_offset_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_next_visible_line_offset_from, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_next_visible_line_index_offset_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_next_visible_line_index_offset_from, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_backspace(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::backspace, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_cut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::cut, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_copy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::copy, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_paste(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::paste, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_paste_primary_clipboard(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::paste_primary_clipboard, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_start_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::start_action, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_end_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::end_action, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_begin_complex_operation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::begin_complex_operation, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_end_complex_operation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::end_complex_operation, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_has_undo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::has_undo, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_has_redo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::has_redo, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_undo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::undo, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_redo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::redo, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_clear_undo_history(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::clear_undo_history, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_tag_saved_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::tag_saved_version, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_version, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_saved_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_saved_version, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_search_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_search_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_search_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_search_flags, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::search, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_tooltip_request_func(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_tooltip_request_func, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_local_mouse_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_local_mouse_pos, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_word_at_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_word_at_pos, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_column_at_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_column_at_pos, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_pos_at_line_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_pos_at_line_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_rect_at_line_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_rect_at_line_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_minimap_line_at_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_minimap_line_at_pos, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_dragging_cursor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_dragging_cursor, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_mouse_over_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_mouse_over_selection, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_caret_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_caret_type, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_type, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_caret_blink_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_caret_blink_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_caret_blink_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_caret_blink_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_caret_blink_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_caret_blink_interval, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_blink_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_blink_interval, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_draw_caret_when_editable_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_draw_caret_when_editable_disabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_drawing_caret_when_editable_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_drawing_caret_when_editable_disabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_move_caret_on_right_click_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_move_caret_on_right_click_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_move_caret_on_right_click_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_move_caret_on_right_click_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_caret_mid_grapheme_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_caret_mid_grapheme_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_caret_mid_grapheme_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_caret_mid_grapheme_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_multiple_carets_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_multiple_carets_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_multiple_carets_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_multiple_carets_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_add_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextEdit::add_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_remove_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::remove_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_remove_secondary_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::remove_secondary_carets, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_count, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_add_caret_at_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::add_caret_at_carets, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_sorted_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_sorted_carets, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_collapse_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::collapse_carets, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_merge_overlapping_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::merge_overlapping_carets, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_begin_multicaret_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::begin_multicaret_edit, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_end_multicaret_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::end_multicaret_edit, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_in_mulitcaret_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_in_mulitcaret_edit, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_multicaret_edit_ignore_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::multicaret_edit_ignore_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_caret_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_caret_visible, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_draw_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_draw_pos, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_caret_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_caret_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_caret_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_caret_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_next_composite_character_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_next_composite_character_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_previous_composite_character_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_previous_composite_character_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_wrap_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_caret_wrap_index, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_word_under_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_word_under_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_use_default_word_separators(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_use_default_word_separators, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_default_word_separators_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_default_word_separators_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_use_custom_word_separators(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_use_custom_word_separators, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_custom_word_separators_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_custom_word_separators_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_custom_word_separators(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_custom_word_separators, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_custom_word_separators(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_custom_word_separators, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_selecting_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_selecting_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_selecting_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_selecting_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_deselect_on_focus_loss_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_deselect_on_focus_loss_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_deselect_on_focus_loss_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_deselect_on_focus_loss_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_drag_and_drop_selection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_drag_and_drop_selection_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_drag_and_drop_selection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_drag_and_drop_selection_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_selection_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_selection_mode, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_mode, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_select_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::select_all, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_select_word_under_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::select_word_under_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_add_selection_for_next_occurrence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::add_selection_for_next_occurrence, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_skip_selection_for_next_occurrence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::skip_selection_for_next_occurrence, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::select, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_has_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::has_selection, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selected_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextEdit::get_selected_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_at_line_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_at_line_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_ranges_from_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_ranges_from_carets, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_origin_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_origin_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_origin_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_origin_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_selection_origin_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_selection_origin_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_selection_origin_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_selection_origin_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_from_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_from_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_from_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_from_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_to_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_to_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_to_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_to_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_caret_after_selection_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_caret_after_selection_origin, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_deselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::deselect, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_delete_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::delete_selection, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_wrapping_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_wrapping_mode, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_wrapping_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_wrapping_mode, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_autowrap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_autowrap_mode, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_autowrap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_autowrap_mode, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_is_line_wrapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_line_wrapped, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_wrap_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_wrap_count, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_wrap_index_at_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_wrap_index_at_column, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_wrapped_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_wrapped_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_smooth_scroll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_smooth_scroll_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_smooth_scroll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_smooth_scroll_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_get_v_scroll_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_v_scroll_bar, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_h_scroll_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_h_scroll_bar, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_v_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_v_scroll, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_v_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_v_scroll, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_h_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_h_scroll, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_h_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_h_scroll, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_scroll_past_end_of_file_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_scroll_past_end_of_file_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_scroll_past_end_of_file_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_scroll_past_end_of_file_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_v_scroll_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_v_scroll_speed, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_v_scroll_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_v_scroll_speed, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_fit_content_height_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_fit_content_height_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_fit_content_height_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_fit_content_height_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_fit_content_width_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_fit_content_width_enabled, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_fit_content_width_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_fit_content_width_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_get_scroll_pos_for_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_scroll_pos_for_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_as_first_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_as_first_visible, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_first_visible_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_first_visible_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_as_center_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_as_center_visible, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_as_last_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_as_last_visible, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_last_full_visible_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_last_full_visible_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_last_full_visible_line_wrap_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_last_full_visible_line_wrap_index, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_visible_line_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_visible_line_count, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_visible_line_count_in_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_visible_line_count_in_range, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_total_visible_line_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_total_visible_line_count, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_adjust_viewport_to_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::adjust_viewport_to_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_center_viewport_to_caret(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::center_viewport_to_caret, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_draw_minimap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_draw_minimap, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_drawing_minimap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_drawing_minimap, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_minimap_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_minimap_width, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_minimap_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_minimap_width, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_get_minimap_visible_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_minimap_visible_lines, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_add_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::add_gutter, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_remove_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::remove_gutter, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_gutter_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_gutter_count, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_name, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_gutter_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_gutter_name, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_type, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_gutter_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_gutter_type, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_width, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_gutter_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_gutter_width, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_draw, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_gutter_drawn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_gutter_drawn, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_clickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_clickable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_gutter_clickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_gutter_clickable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_overwritable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_overwritable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_gutter_overwritable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_gutter_overwritable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_merge_gutters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::merge_gutters, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_gutter_custom_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_gutter_custom_draw, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_total_gutter_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_total_gutter_width, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_gutter_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_gutter_metadata, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_gutter_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_gutter_metadata, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_gutter_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_gutter_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_gutter_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_gutter_text, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_gutter_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_gutter_icon, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_gutter_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_gutter_icon, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_gutter_item_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_gutter_item_color, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_gutter_item_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_gutter_item_color, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_gutter_clickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_gutter_clickable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_line_gutter_clickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_line_gutter_clickable, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_line_background_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_line_background_color, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_line_background_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_line_background_color, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_syntax_highlighter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_syntax_highlighter, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_syntax_highlighter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_syntax_highlighter, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_highlight_current_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_highlight_current_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_highlight_current_line_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_highlight_current_line_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_highlight_all_occurrences(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_highlight_all_occurrences, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_highlight_all_occurrences_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_highlight_all_occurrences_enabled, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_get_draw_control_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_draw_control_chars, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_draw_control_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_draw_control_chars, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_set_draw_tabs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_draw_tabs, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_drawing_tabs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_drawing_tabs, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_set_draw_spaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::set_draw_spaces, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_drawing_spaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_drawing_spaces, ctx, this_val, argc, argv);
}
static JSValue text_edit_class_get_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_menu, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_is_menu_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::is_menu_visible, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_menu_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::menu_option, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_adjust_carets_after_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextEdit::adjust_carets_after_edit, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_caret_index_edit_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextEdit::get_caret_index_edit_order, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_line, ctx, this_val, argc, argv);
};
static JSValue text_edit_class_get_selection_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextEdit::get_selection_column, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry text_edit_class_proto_funcs[] = {
	JS_CFUNC_DEF("has_ime_text", 0, &text_edit_class_has_ime_text),
	JS_CFUNC_DEF("cancel_ime", 0, &text_edit_class_cancel_ime),
	JS_CFUNC_DEF("apply_ime", 0, &text_edit_class_apply_ime),
	JS_CFUNC_DEF("set_editable", 1, &text_edit_class_set_editable),
	JS_CFUNC_DEF("is_editable", 0, &text_edit_class_is_editable),
	JS_CFUNC_DEF("set_text_direction", 1, &text_edit_class_set_text_direction),
	JS_CFUNC_DEF("get_text_direction", 0, &text_edit_class_get_text_direction),
	JS_CFUNC_DEF("set_language", 1, &text_edit_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &text_edit_class_get_language),
	JS_CFUNC_DEF("set_structured_text_bidi_override", 1, &text_edit_class_set_structured_text_bidi_override),
	JS_CFUNC_DEF("get_structured_text_bidi_override", 0, &text_edit_class_get_structured_text_bidi_override),
	JS_CFUNC_DEF("set_structured_text_bidi_override_options", 1, &text_edit_class_set_structured_text_bidi_override_options),
	JS_CFUNC_DEF("get_structured_text_bidi_override_options", 0, &text_edit_class_get_structured_text_bidi_override_options),
	JS_CFUNC_DEF("set_tab_size", 1, &text_edit_class_set_tab_size),
	JS_CFUNC_DEF("get_tab_size", 0, &text_edit_class_get_tab_size),
	JS_CFUNC_DEF("set_indent_wrapped_lines", 1, &text_edit_class_set_indent_wrapped_lines),
	JS_CFUNC_DEF("is_indent_wrapped_lines", 0, &text_edit_class_is_indent_wrapped_lines),
	JS_CFUNC_DEF("set_tab_input_mode", 1, &text_edit_class_set_tab_input_mode),
	JS_CFUNC_DEF("get_tab_input_mode", 0, &text_edit_class_get_tab_input_mode),
	JS_CFUNC_DEF("set_overtype_mode_enabled", 1, &text_edit_class_set_overtype_mode_enabled),
	JS_CFUNC_DEF("is_overtype_mode_enabled", 0, &text_edit_class_is_overtype_mode_enabled),
	JS_CFUNC_DEF("set_context_menu_enabled", 1, &text_edit_class_set_context_menu_enabled),
	JS_CFUNC_DEF("is_context_menu_enabled", 0, &text_edit_class_is_context_menu_enabled),
	JS_CFUNC_DEF("set_emoji_menu_enabled", 1, &text_edit_class_set_emoji_menu_enabled),
	JS_CFUNC_DEF("is_emoji_menu_enabled", 0, &text_edit_class_is_emoji_menu_enabled),
	JS_CFUNC_DEF("set_backspace_deletes_composite_character_enabled", 1, &text_edit_class_set_backspace_deletes_composite_character_enabled),
	JS_CFUNC_DEF("is_backspace_deletes_composite_character_enabled", 0, &text_edit_class_is_backspace_deletes_composite_character_enabled),
	JS_CFUNC_DEF("set_shortcut_keys_enabled", 1, &text_edit_class_set_shortcut_keys_enabled),
	JS_CFUNC_DEF("is_shortcut_keys_enabled", 0, &text_edit_class_is_shortcut_keys_enabled),
	JS_CFUNC_DEF("set_virtual_keyboard_enabled", 1, &text_edit_class_set_virtual_keyboard_enabled),
	JS_CFUNC_DEF("is_virtual_keyboard_enabled", 0, &text_edit_class_is_virtual_keyboard_enabled),
	JS_CFUNC_DEF("set_virtual_keyboard_show_on_focus", 1, &text_edit_class_set_virtual_keyboard_show_on_focus),
	JS_CFUNC_DEF("get_virtual_keyboard_show_on_focus", 0, &text_edit_class_get_virtual_keyboard_show_on_focus),
	JS_CFUNC_DEF("set_middle_mouse_paste_enabled", 1, &text_edit_class_set_middle_mouse_paste_enabled),
	JS_CFUNC_DEF("is_middle_mouse_paste_enabled", 0, &text_edit_class_is_middle_mouse_paste_enabled),
	JS_CFUNC_DEF("set_empty_selection_clipboard_enabled", 1, &text_edit_class_set_empty_selection_clipboard_enabled),
	JS_CFUNC_DEF("is_empty_selection_clipboard_enabled", 0, &text_edit_class_is_empty_selection_clipboard_enabled),
	JS_CFUNC_DEF("clear", 0, &text_edit_class_clear),
	JS_CFUNC_DEF("set_text", 1, &text_edit_class_set_text),
	JS_CFUNC_DEF("get_text", 0, &text_edit_class_get_text),
	JS_CFUNC_DEF("get_line_count", 0, &text_edit_class_get_line_count),
	JS_CFUNC_DEF("set_placeholder", 1, &text_edit_class_set_placeholder),
	JS_CFUNC_DEF("get_placeholder", 0, &text_edit_class_get_placeholder),
	JS_CFUNC_DEF("set_line", 2, &text_edit_class_set_line),
	JS_CFUNC_DEF("get_line", 1, &text_edit_class_get_line),
	JS_CFUNC_DEF("get_line_with_ime", 1, &text_edit_class_get_line_with_ime),
	JS_CFUNC_DEF("get_line_width", 2, &text_edit_class_get_line_width),
	JS_CFUNC_DEF("get_line_height", 0, &text_edit_class_get_line_height),
	JS_CFUNC_DEF("get_indent_level", 1, &text_edit_class_get_indent_level),
	JS_CFUNC_DEF("get_first_non_whitespace_column", 1, &text_edit_class_get_first_non_whitespace_column),
	JS_CFUNC_DEF("swap_lines", 2, &text_edit_class_swap_lines),
	JS_CFUNC_DEF("insert_line_at", 2, &text_edit_class_insert_line_at),
	JS_CFUNC_DEF("remove_line_at", 2, &text_edit_class_remove_line_at),
	JS_CFUNC_DEF("insert_text_at_caret", 2, &text_edit_class_insert_text_at_caret),
	JS_CFUNC_DEF("insert_text", 5, &text_edit_class_insert_text),
	JS_CFUNC_DEF("remove_text", 4, &text_edit_class_remove_text),
	JS_CFUNC_DEF("get_last_unhidden_line", 0, &text_edit_class_get_last_unhidden_line),
	JS_CFUNC_DEF("get_next_visible_line_offset_from", 2, &text_edit_class_get_next_visible_line_offset_from),
	JS_CFUNC_DEF("get_next_visible_line_index_offset_from", 3, &text_edit_class_get_next_visible_line_index_offset_from),
	JS_CFUNC_DEF("backspace", 1, &text_edit_class_backspace),
	JS_CFUNC_DEF("cut", 1, &text_edit_class_cut),
	JS_CFUNC_DEF("copy", 1, &text_edit_class_copy),
	JS_CFUNC_DEF("paste", 1, &text_edit_class_paste),
	JS_CFUNC_DEF("paste_primary_clipboard", 1, &text_edit_class_paste_primary_clipboard),
	JS_CFUNC_DEF("start_action", 1, &text_edit_class_start_action),
	JS_CFUNC_DEF("end_action", 0, &text_edit_class_end_action),
	JS_CFUNC_DEF("begin_complex_operation", 0, &text_edit_class_begin_complex_operation),
	JS_CFUNC_DEF("end_complex_operation", 0, &text_edit_class_end_complex_operation),
	JS_CFUNC_DEF("has_undo", 0, &text_edit_class_has_undo),
	JS_CFUNC_DEF("has_redo", 0, &text_edit_class_has_redo),
	JS_CFUNC_DEF("undo", 0, &text_edit_class_undo),
	JS_CFUNC_DEF("redo", 0, &text_edit_class_redo),
	JS_CFUNC_DEF("clear_undo_history", 0, &text_edit_class_clear_undo_history),
	JS_CFUNC_DEF("tag_saved_version", 0, &text_edit_class_tag_saved_version),
	JS_CFUNC_DEF("get_version", 0, &text_edit_class_get_version),
	JS_CFUNC_DEF("get_saved_version", 0, &text_edit_class_get_saved_version),
	JS_CFUNC_DEF("set_search_text", 1, &text_edit_class_set_search_text),
	JS_CFUNC_DEF("set_search_flags", 1, &text_edit_class_set_search_flags),
	JS_CFUNC_DEF("search", 4, &text_edit_class_search),
	JS_CFUNC_DEF("set_tooltip_request_func", 1, &text_edit_class_set_tooltip_request_func),
	JS_CFUNC_DEF("get_local_mouse_pos", 0, &text_edit_class_get_local_mouse_pos),
	JS_CFUNC_DEF("get_word_at_pos", 1, &text_edit_class_get_word_at_pos),
	JS_CFUNC_DEF("get_line_column_at_pos", 3, &text_edit_class_get_line_column_at_pos),
	JS_CFUNC_DEF("get_pos_at_line_column", 2, &text_edit_class_get_pos_at_line_column),
	JS_CFUNC_DEF("get_rect_at_line_column", 2, &text_edit_class_get_rect_at_line_column),
	JS_CFUNC_DEF("get_minimap_line_at_pos", 1, &text_edit_class_get_minimap_line_at_pos),
	JS_CFUNC_DEF("is_dragging_cursor", 0, &text_edit_class_is_dragging_cursor),
	JS_CFUNC_DEF("is_mouse_over_selection", 2, &text_edit_class_is_mouse_over_selection),
	JS_CFUNC_DEF("set_caret_type", 1, &text_edit_class_set_caret_type),
	JS_CFUNC_DEF("get_caret_type", 0, &text_edit_class_get_caret_type),
	JS_CFUNC_DEF("set_caret_blink_enabled", 1, &text_edit_class_set_caret_blink_enabled),
	JS_CFUNC_DEF("is_caret_blink_enabled", 0, &text_edit_class_is_caret_blink_enabled),
	JS_CFUNC_DEF("set_caret_blink_interval", 1, &text_edit_class_set_caret_blink_interval),
	JS_CFUNC_DEF("get_caret_blink_interval", 0, &text_edit_class_get_caret_blink_interval),
	JS_CFUNC_DEF("set_draw_caret_when_editable_disabled", 1, &text_edit_class_set_draw_caret_when_editable_disabled),
	JS_CFUNC_DEF("is_drawing_caret_when_editable_disabled", 0, &text_edit_class_is_drawing_caret_when_editable_disabled),
	JS_CFUNC_DEF("set_move_caret_on_right_click_enabled", 1, &text_edit_class_set_move_caret_on_right_click_enabled),
	JS_CFUNC_DEF("is_move_caret_on_right_click_enabled", 0, &text_edit_class_is_move_caret_on_right_click_enabled),
	JS_CFUNC_DEF("set_caret_mid_grapheme_enabled", 1, &text_edit_class_set_caret_mid_grapheme_enabled),
	JS_CFUNC_DEF("is_caret_mid_grapheme_enabled", 0, &text_edit_class_is_caret_mid_grapheme_enabled),
	JS_CFUNC_DEF("set_multiple_carets_enabled", 1, &text_edit_class_set_multiple_carets_enabled),
	JS_CFUNC_DEF("is_multiple_carets_enabled", 0, &text_edit_class_is_multiple_carets_enabled),
	JS_CFUNC_DEF("add_caret", 2, &text_edit_class_add_caret),
	JS_CFUNC_DEF("remove_caret", 1, &text_edit_class_remove_caret),
	JS_CFUNC_DEF("remove_secondary_carets", 0, &text_edit_class_remove_secondary_carets),
	JS_CFUNC_DEF("get_caret_count", 0, &text_edit_class_get_caret_count),
	JS_CFUNC_DEF("add_caret_at_carets", 1, &text_edit_class_add_caret_at_carets),
	JS_CFUNC_DEF("get_sorted_carets", 1, &text_edit_class_get_sorted_carets),
	JS_CFUNC_DEF("collapse_carets", 5, &text_edit_class_collapse_carets),
	JS_CFUNC_DEF("merge_overlapping_carets", 0, &text_edit_class_merge_overlapping_carets),
	JS_CFUNC_DEF("begin_multicaret_edit", 0, &text_edit_class_begin_multicaret_edit),
	JS_CFUNC_DEF("end_multicaret_edit", 0, &text_edit_class_end_multicaret_edit),
	JS_CFUNC_DEF("is_in_mulitcaret_edit", 0, &text_edit_class_is_in_mulitcaret_edit),
	JS_CFUNC_DEF("multicaret_edit_ignore_caret", 1, &text_edit_class_multicaret_edit_ignore_caret),
	JS_CFUNC_DEF("is_caret_visible", 1, &text_edit_class_is_caret_visible),
	JS_CFUNC_DEF("get_caret_draw_pos", 1, &text_edit_class_get_caret_draw_pos),
	JS_CFUNC_DEF("set_caret_line", 5, &text_edit_class_set_caret_line),
	JS_CFUNC_DEF("get_caret_line", 1, &text_edit_class_get_caret_line),
	JS_CFUNC_DEF("set_caret_column", 3, &text_edit_class_set_caret_column),
	JS_CFUNC_DEF("get_caret_column", 1, &text_edit_class_get_caret_column),
	JS_CFUNC_DEF("get_next_composite_character_column", 2, &text_edit_class_get_next_composite_character_column),
	JS_CFUNC_DEF("get_previous_composite_character_column", 2, &text_edit_class_get_previous_composite_character_column),
	JS_CFUNC_DEF("get_caret_wrap_index", 1, &text_edit_class_get_caret_wrap_index),
	JS_CFUNC_DEF("get_word_under_caret", 1, &text_edit_class_get_word_under_caret),
	JS_CFUNC_DEF("set_use_default_word_separators", 1, &text_edit_class_set_use_default_word_separators),
	JS_CFUNC_DEF("is_default_word_separators_enabled", 0, &text_edit_class_is_default_word_separators_enabled),
	JS_CFUNC_DEF("set_use_custom_word_separators", 1, &text_edit_class_set_use_custom_word_separators),
	JS_CFUNC_DEF("is_custom_word_separators_enabled", 0, &text_edit_class_is_custom_word_separators_enabled),
	JS_CFUNC_DEF("set_custom_word_separators", 1, &text_edit_class_set_custom_word_separators),
	JS_CFUNC_DEF("get_custom_word_separators", 0, &text_edit_class_get_custom_word_separators),
	JS_CFUNC_DEF("set_selecting_enabled", 1, &text_edit_class_set_selecting_enabled),
	JS_CFUNC_DEF("is_selecting_enabled", 0, &text_edit_class_is_selecting_enabled),
	JS_CFUNC_DEF("set_deselect_on_focus_loss_enabled", 1, &text_edit_class_set_deselect_on_focus_loss_enabled),
	JS_CFUNC_DEF("is_deselect_on_focus_loss_enabled", 0, &text_edit_class_is_deselect_on_focus_loss_enabled),
	JS_CFUNC_DEF("set_drag_and_drop_selection_enabled", 1, &text_edit_class_set_drag_and_drop_selection_enabled),
	JS_CFUNC_DEF("is_drag_and_drop_selection_enabled", 0, &text_edit_class_is_drag_and_drop_selection_enabled),
	JS_CFUNC_DEF("set_selection_mode", 1, &text_edit_class_set_selection_mode),
	JS_CFUNC_DEF("get_selection_mode", 0, &text_edit_class_get_selection_mode),
	JS_CFUNC_DEF("select_all", 0, &text_edit_class_select_all),
	JS_CFUNC_DEF("select_word_under_caret", 1, &text_edit_class_select_word_under_caret),
	JS_CFUNC_DEF("add_selection_for_next_occurrence", 0, &text_edit_class_add_selection_for_next_occurrence),
	JS_CFUNC_DEF("skip_selection_for_next_occurrence", 0, &text_edit_class_skip_selection_for_next_occurrence),
	JS_CFUNC_DEF("select", 5, &text_edit_class_select),
	JS_CFUNC_DEF("has_selection", 1, &text_edit_class_has_selection),
	JS_CFUNC_DEF("get_selected_text", 1, &text_edit_class_get_selected_text),
	JS_CFUNC_DEF("get_selection_at_line_column", 4, &text_edit_class_get_selection_at_line_column),
	JS_CFUNC_DEF("get_line_ranges_from_carets", 2, &text_edit_class_get_line_ranges_from_carets),
	JS_CFUNC_DEF("get_selection_origin_line", 1, &text_edit_class_get_selection_origin_line),
	JS_CFUNC_DEF("get_selection_origin_column", 1, &text_edit_class_get_selection_origin_column),
	JS_CFUNC_DEF("set_selection_origin_line", 4, &text_edit_class_set_selection_origin_line),
	JS_CFUNC_DEF("set_selection_origin_column", 2, &text_edit_class_set_selection_origin_column),
	JS_CFUNC_DEF("get_selection_from_line", 1, &text_edit_class_get_selection_from_line),
	JS_CFUNC_DEF("get_selection_from_column", 1, &text_edit_class_get_selection_from_column),
	JS_CFUNC_DEF("get_selection_to_line", 1, &text_edit_class_get_selection_to_line),
	JS_CFUNC_DEF("get_selection_to_column", 1, &text_edit_class_get_selection_to_column),
	JS_CFUNC_DEF("is_caret_after_selection_origin", 1, &text_edit_class_is_caret_after_selection_origin),
	JS_CFUNC_DEF("deselect", 1, &text_edit_class_deselect),
	JS_CFUNC_DEF("delete_selection", 1, &text_edit_class_delete_selection),
	JS_CFUNC_DEF("set_line_wrapping_mode", 1, &text_edit_class_set_line_wrapping_mode),
	JS_CFUNC_DEF("get_line_wrapping_mode", 0, &text_edit_class_get_line_wrapping_mode),
	JS_CFUNC_DEF("set_autowrap_mode", 1, &text_edit_class_set_autowrap_mode),
	JS_CFUNC_DEF("get_autowrap_mode", 0, &text_edit_class_get_autowrap_mode),
	JS_CFUNC_DEF("is_line_wrapped", 1, &text_edit_class_is_line_wrapped),
	JS_CFUNC_DEF("get_line_wrap_count", 1, &text_edit_class_get_line_wrap_count),
	JS_CFUNC_DEF("get_line_wrap_index_at_column", 2, &text_edit_class_get_line_wrap_index_at_column),
	JS_CFUNC_DEF("get_line_wrapped_text", 1, &text_edit_class_get_line_wrapped_text),
	JS_CFUNC_DEF("set_smooth_scroll_enabled", 1, &text_edit_class_set_smooth_scroll_enabled),
	JS_CFUNC_DEF("is_smooth_scroll_enabled", 0, &text_edit_class_is_smooth_scroll_enabled),
	JS_CFUNC_DEF("get_v_scroll_bar", 0, &text_edit_class_get_v_scroll_bar),
	JS_CFUNC_DEF("get_h_scroll_bar", 0, &text_edit_class_get_h_scroll_bar),
	JS_CFUNC_DEF("set_v_scroll", 1, &text_edit_class_set_v_scroll),
	JS_CFUNC_DEF("get_v_scroll", 0, &text_edit_class_get_v_scroll),
	JS_CFUNC_DEF("set_h_scroll", 1, &text_edit_class_set_h_scroll),
	JS_CFUNC_DEF("get_h_scroll", 0, &text_edit_class_get_h_scroll),
	JS_CFUNC_DEF("set_scroll_past_end_of_file_enabled", 1, &text_edit_class_set_scroll_past_end_of_file_enabled),
	JS_CFUNC_DEF("is_scroll_past_end_of_file_enabled", 0, &text_edit_class_is_scroll_past_end_of_file_enabled),
	JS_CFUNC_DEF("set_v_scroll_speed", 1, &text_edit_class_set_v_scroll_speed),
	JS_CFUNC_DEF("get_v_scroll_speed", 0, &text_edit_class_get_v_scroll_speed),
	JS_CFUNC_DEF("set_fit_content_height_enabled", 1, &text_edit_class_set_fit_content_height_enabled),
	JS_CFUNC_DEF("is_fit_content_height_enabled", 0, &text_edit_class_is_fit_content_height_enabled),
	JS_CFUNC_DEF("set_fit_content_width_enabled", 1, &text_edit_class_set_fit_content_width_enabled),
	JS_CFUNC_DEF("is_fit_content_width_enabled", 0, &text_edit_class_is_fit_content_width_enabled),
	JS_CFUNC_DEF("get_scroll_pos_for_line", 2, &text_edit_class_get_scroll_pos_for_line),
	JS_CFUNC_DEF("set_line_as_first_visible", 2, &text_edit_class_set_line_as_first_visible),
	JS_CFUNC_DEF("get_first_visible_line", 0, &text_edit_class_get_first_visible_line),
	JS_CFUNC_DEF("set_line_as_center_visible", 2, &text_edit_class_set_line_as_center_visible),
	JS_CFUNC_DEF("set_line_as_last_visible", 2, &text_edit_class_set_line_as_last_visible),
	JS_CFUNC_DEF("get_last_full_visible_line", 0, &text_edit_class_get_last_full_visible_line),
	JS_CFUNC_DEF("get_last_full_visible_line_wrap_index", 0, &text_edit_class_get_last_full_visible_line_wrap_index),
	JS_CFUNC_DEF("get_visible_line_count", 0, &text_edit_class_get_visible_line_count),
	JS_CFUNC_DEF("get_visible_line_count_in_range", 2, &text_edit_class_get_visible_line_count_in_range),
	JS_CFUNC_DEF("get_total_visible_line_count", 0, &text_edit_class_get_total_visible_line_count),
	JS_CFUNC_DEF("adjust_viewport_to_caret", 1, &text_edit_class_adjust_viewport_to_caret),
	JS_CFUNC_DEF("center_viewport_to_caret", 1, &text_edit_class_center_viewport_to_caret),
	JS_CFUNC_DEF("set_draw_minimap", 1, &text_edit_class_set_draw_minimap),
	JS_CFUNC_DEF("is_drawing_minimap", 0, &text_edit_class_is_drawing_minimap),
	JS_CFUNC_DEF("set_minimap_width", 1, &text_edit_class_set_minimap_width),
	JS_CFUNC_DEF("get_minimap_width", 0, &text_edit_class_get_minimap_width),
	JS_CFUNC_DEF("get_minimap_visible_lines", 0, &text_edit_class_get_minimap_visible_lines),
	JS_CFUNC_DEF("add_gutter", 1, &text_edit_class_add_gutter),
	JS_CFUNC_DEF("remove_gutter", 1, &text_edit_class_remove_gutter),
	JS_CFUNC_DEF("get_gutter_count", 0, &text_edit_class_get_gutter_count),
	JS_CFUNC_DEF("set_gutter_name", 2, &text_edit_class_set_gutter_name),
	JS_CFUNC_DEF("get_gutter_name", 1, &text_edit_class_get_gutter_name),
	JS_CFUNC_DEF("set_gutter_type", 2, &text_edit_class_set_gutter_type),
	JS_CFUNC_DEF("get_gutter_type", 1, &text_edit_class_get_gutter_type),
	JS_CFUNC_DEF("set_gutter_width", 2, &text_edit_class_set_gutter_width),
	JS_CFUNC_DEF("get_gutter_width", 1, &text_edit_class_get_gutter_width),
	JS_CFUNC_DEF("set_gutter_draw", 2, &text_edit_class_set_gutter_draw),
	JS_CFUNC_DEF("is_gutter_drawn", 1, &text_edit_class_is_gutter_drawn),
	JS_CFUNC_DEF("set_gutter_clickable", 2, &text_edit_class_set_gutter_clickable),
	JS_CFUNC_DEF("is_gutter_clickable", 1, &text_edit_class_is_gutter_clickable),
	JS_CFUNC_DEF("set_gutter_overwritable", 2, &text_edit_class_set_gutter_overwritable),
	JS_CFUNC_DEF("is_gutter_overwritable", 1, &text_edit_class_is_gutter_overwritable),
	JS_CFUNC_DEF("merge_gutters", 2, &text_edit_class_merge_gutters),
	JS_CFUNC_DEF("set_gutter_custom_draw", 2, &text_edit_class_set_gutter_custom_draw),
	JS_CFUNC_DEF("get_total_gutter_width", 0, &text_edit_class_get_total_gutter_width),
	JS_CFUNC_DEF("set_line_gutter_metadata", 3, &text_edit_class_set_line_gutter_metadata),
	JS_CFUNC_DEF("get_line_gutter_metadata", 2, &text_edit_class_get_line_gutter_metadata),
	JS_CFUNC_DEF("set_line_gutter_text", 3, &text_edit_class_set_line_gutter_text),
	JS_CFUNC_DEF("get_line_gutter_text", 2, &text_edit_class_get_line_gutter_text),
	JS_CFUNC_DEF("set_line_gutter_icon", 3, &text_edit_class_set_line_gutter_icon),
	JS_CFUNC_DEF("get_line_gutter_icon", 2, &text_edit_class_get_line_gutter_icon),
	JS_CFUNC_DEF("set_line_gutter_item_color", 3, &text_edit_class_set_line_gutter_item_color),
	JS_CFUNC_DEF("get_line_gutter_item_color", 2, &text_edit_class_get_line_gutter_item_color),
	JS_CFUNC_DEF("set_line_gutter_clickable", 3, &text_edit_class_set_line_gutter_clickable),
	JS_CFUNC_DEF("is_line_gutter_clickable", 2, &text_edit_class_is_line_gutter_clickable),
	JS_CFUNC_DEF("set_line_background_color", 2, &text_edit_class_set_line_background_color),
	JS_CFUNC_DEF("get_line_background_color", 1, &text_edit_class_get_line_background_color),
	JS_CFUNC_DEF("set_syntax_highlighter", 1, &text_edit_class_set_syntax_highlighter),
	JS_CFUNC_DEF("get_syntax_highlighter", 0, &text_edit_class_get_syntax_highlighter),
	JS_CFUNC_DEF("set_highlight_current_line", 1, &text_edit_class_set_highlight_current_line),
	JS_CFUNC_DEF("is_highlight_current_line_enabled", 0, &text_edit_class_is_highlight_current_line_enabled),
	JS_CFUNC_DEF("set_highlight_all_occurrences", 1, &text_edit_class_set_highlight_all_occurrences),
	JS_CFUNC_DEF("is_highlight_all_occurrences_enabled", 0, &text_edit_class_is_highlight_all_occurrences_enabled),
	JS_CFUNC_DEF("get_draw_control_chars", 0, &text_edit_class_get_draw_control_chars),
	JS_CFUNC_DEF("set_draw_control_chars", 1, &text_edit_class_set_draw_control_chars),
	JS_CFUNC_DEF("set_draw_tabs", 1, &text_edit_class_set_draw_tabs),
	JS_CFUNC_DEF("is_drawing_tabs", 0, &text_edit_class_is_drawing_tabs),
	JS_CFUNC_DEF("set_draw_spaces", 1, &text_edit_class_set_draw_spaces),
	JS_CFUNC_DEF("is_drawing_spaces", 0, &text_edit_class_is_drawing_spaces),
	JS_CFUNC_DEF("get_menu", 0, &text_edit_class_get_menu),
	JS_CFUNC_DEF("is_menu_visible", 0, &text_edit_class_is_menu_visible),
	JS_CFUNC_DEF("menu_option", 1, &text_edit_class_menu_option),
	JS_CFUNC_DEF("adjust_carets_after_edit", 5, &text_edit_class_adjust_carets_after_edit),
	JS_CFUNC_DEF("get_caret_index_edit_order", 0, &text_edit_class_get_caret_index_edit_order),
	JS_CFUNC_DEF("get_selection_line", 1, &text_edit_class_get_selection_line),
	JS_CFUNC_DEF("get_selection_column", 1, &text_edit_class_get_selection_column),
};


static JSValue text_edit_class_get_text_set_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "text_set");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue text_edit_class_get_text_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "text_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue text_edit_class_get_lines_edited_from_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "lines_edited_from");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue text_edit_class_get_caret_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "caret_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue text_edit_class_get_gutter_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "gutter_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue text_edit_class_get_gutter_added_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "gutter_added");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue text_edit_class_get_gutter_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "gutter_removed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_text_edit_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text"),
        JS_NewCFunction(ctx, text_edit_class_get_text, "get_text", 0),
        JS_NewCFunction(ctx, text_edit_class_set_text, "set_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "placeholder_text"),
        JS_NewCFunction(ctx, text_edit_class_get_placeholder, "get_placeholder", 0),
        JS_NewCFunction(ctx, text_edit_class_set_placeholder, "set_placeholder", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editable"),
        JS_NewCFunction(ctx, text_edit_class_is_editable, "is_editable", 0),
        JS_NewCFunction(ctx, text_edit_class_set_editable, "set_editable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "context_menu_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_context_menu_enabled, "is_context_menu_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_context_menu_enabled, "set_context_menu_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emoji_menu_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_emoji_menu_enabled, "is_emoji_menu_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_emoji_menu_enabled, "set_emoji_menu_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "backspace_deletes_composite_character_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_backspace_deletes_composite_character_enabled, "is_backspace_deletes_composite_character_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_backspace_deletes_composite_character_enabled, "set_backspace_deletes_composite_character_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shortcut_keys_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_shortcut_keys_enabled, "is_shortcut_keys_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_shortcut_keys_enabled, "set_shortcut_keys_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "selecting_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_selecting_enabled, "is_selecting_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_selecting_enabled, "set_selecting_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "deselect_on_focus_loss_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_deselect_on_focus_loss_enabled, "is_deselect_on_focus_loss_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_deselect_on_focus_loss_enabled, "set_deselect_on_focus_loss_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_and_drop_selection_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_drag_and_drop_selection_enabled, "is_drag_and_drop_selection_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_drag_and_drop_selection_enabled, "set_drag_and_drop_selection_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "virtual_keyboard_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_virtual_keyboard_enabled, "is_virtual_keyboard_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_virtual_keyboard_enabled, "set_virtual_keyboard_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "virtual_keyboard_show_on_focus"),
        JS_NewCFunction(ctx, text_edit_class_get_virtual_keyboard_show_on_focus, "get_virtual_keyboard_show_on_focus", 0),
        JS_NewCFunction(ctx, text_edit_class_set_virtual_keyboard_show_on_focus, "set_virtual_keyboard_show_on_focus", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "middle_mouse_paste_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_middle_mouse_paste_enabled, "is_middle_mouse_paste_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_middle_mouse_paste_enabled, "set_middle_mouse_paste_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "empty_selection_clipboard_enabled"),
        JS_NewCFunction(ctx, text_edit_class_is_empty_selection_clipboard_enabled, "is_empty_selection_clipboard_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_empty_selection_clipboard_enabled, "set_empty_selection_clipboard_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wrap_mode"),
        JS_NewCFunction(ctx, text_edit_class_get_line_wrapping_mode, "get_line_wrapping_mode", 0),
        JS_NewCFunction(ctx, text_edit_class_set_line_wrapping_mode, "set_line_wrapping_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autowrap_mode"),
        JS_NewCFunction(ctx, text_edit_class_get_autowrap_mode, "get_autowrap_mode", 0),
        JS_NewCFunction(ctx, text_edit_class_set_autowrap_mode, "set_autowrap_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indent_wrapped_lines"),
        JS_NewCFunction(ctx, text_edit_class_is_indent_wrapped_lines, "is_indent_wrapped_lines", 0),
        JS_NewCFunction(ctx, text_edit_class_set_indent_wrapped_lines, "set_indent_wrapped_lines", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tab_input_mode"),
        JS_NewCFunction(ctx, text_edit_class_get_tab_input_mode, "get_tab_input_mode", 0),
        JS_NewCFunction(ctx, text_edit_class_set_tab_input_mode, "set_tab_input_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_smooth"),
        JS_NewCFunction(ctx, text_edit_class_is_smooth_scroll_enabled, "is_smooth_scroll_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_smooth_scroll_enabled, "set_smooth_scroll_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_v_scroll_speed"),
        JS_NewCFunction(ctx, text_edit_class_get_v_scroll_speed, "get_v_scroll_speed", 0),
        JS_NewCFunction(ctx, text_edit_class_set_v_scroll_speed, "set_v_scroll_speed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_past_end_of_file"),
        JS_NewCFunction(ctx, text_edit_class_is_scroll_past_end_of_file_enabled, "is_scroll_past_end_of_file_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_scroll_past_end_of_file_enabled, "set_scroll_past_end_of_file_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_vertical"),
        JS_NewCFunction(ctx, text_edit_class_get_v_scroll, "get_v_scroll", 0),
        JS_NewCFunction(ctx, text_edit_class_set_v_scroll, "set_v_scroll", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_horizontal"),
        JS_NewCFunction(ctx, text_edit_class_get_h_scroll, "get_h_scroll", 0),
        JS_NewCFunction(ctx, text_edit_class_set_h_scroll, "set_h_scroll", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_fit_content_height"),
        JS_NewCFunction(ctx, text_edit_class_is_fit_content_height_enabled, "is_fit_content_height_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_fit_content_height_enabled, "set_fit_content_height_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_fit_content_width"),
        JS_NewCFunction(ctx, text_edit_class_is_fit_content_width_enabled, "is_fit_content_width_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_fit_content_width_enabled, "set_fit_content_width_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minimap_draw"),
        JS_NewCFunction(ctx, text_edit_class_is_drawing_minimap, "is_drawing_minimap", 0),
        JS_NewCFunction(ctx, text_edit_class_set_draw_minimap, "set_draw_minimap", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minimap_width"),
        JS_NewCFunction(ctx, text_edit_class_get_minimap_width, "get_minimap_width", 0),
        JS_NewCFunction(ctx, text_edit_class_set_minimap_width, "set_minimap_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_type"),
        JS_NewCFunction(ctx, text_edit_class_get_caret_type, "get_caret_type", 0),
        JS_NewCFunction(ctx, text_edit_class_set_caret_type, "set_caret_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_blink"),
        JS_NewCFunction(ctx, text_edit_class_is_caret_blink_enabled, "is_caret_blink_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_caret_blink_enabled, "set_caret_blink_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_blink_interval"),
        JS_NewCFunction(ctx, text_edit_class_get_caret_blink_interval, "get_caret_blink_interval", 0),
        JS_NewCFunction(ctx, text_edit_class_set_caret_blink_interval, "set_caret_blink_interval", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_draw_when_editable_disabled"),
        JS_NewCFunction(ctx, text_edit_class_is_drawing_caret_when_editable_disabled, "is_drawing_caret_when_editable_disabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_draw_caret_when_editable_disabled, "set_draw_caret_when_editable_disabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_move_on_right_click"),
        JS_NewCFunction(ctx, text_edit_class_is_move_caret_on_right_click_enabled, "is_move_caret_on_right_click_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_move_caret_on_right_click_enabled, "set_move_caret_on_right_click_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_mid_grapheme"),
        JS_NewCFunction(ctx, text_edit_class_is_caret_mid_grapheme_enabled, "is_caret_mid_grapheme_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_caret_mid_grapheme_enabled, "set_caret_mid_grapheme_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "caret_multiple"),
        JS_NewCFunction(ctx, text_edit_class_is_multiple_carets_enabled, "is_multiple_carets_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_multiple_carets_enabled, "set_multiple_carets_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_default_word_separators"),
        JS_NewCFunction(ctx, text_edit_class_is_default_word_separators_enabled, "is_default_word_separators_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_use_default_word_separators, "set_use_default_word_separators", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_custom_word_separators"),
        JS_NewCFunction(ctx, text_edit_class_is_custom_word_separators_enabled, "is_custom_word_separators_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_use_custom_word_separators, "set_use_custom_word_separators", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_word_separators"),
        JS_NewCFunction(ctx, text_edit_class_get_custom_word_separators, "get_custom_word_separators", 0),
        JS_NewCFunction(ctx, text_edit_class_set_custom_word_separators, "set_custom_word_separators", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "syntax_highlighter"),
        JS_NewCFunction(ctx, text_edit_class_get_syntax_highlighter, "get_syntax_highlighter", 0),
        JS_NewCFunction(ctx, text_edit_class_set_syntax_highlighter, "set_syntax_highlighter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "highlight_all_occurrences"),
        JS_NewCFunction(ctx, text_edit_class_is_highlight_all_occurrences_enabled, "is_highlight_all_occurrences_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_highlight_all_occurrences, "set_highlight_all_occurrences", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "highlight_current_line"),
        JS_NewCFunction(ctx, text_edit_class_is_highlight_current_line_enabled, "is_highlight_current_line_enabled", 0),
        JS_NewCFunction(ctx, text_edit_class_set_highlight_current_line, "set_highlight_current_line", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_control_chars"),
        JS_NewCFunction(ctx, text_edit_class_get_draw_control_chars, "get_draw_control_chars", 0),
        JS_NewCFunction(ctx, text_edit_class_set_draw_control_chars, "set_draw_control_chars", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_tabs"),
        JS_NewCFunction(ctx, text_edit_class_is_drawing_tabs, "is_drawing_tabs", 0),
        JS_NewCFunction(ctx, text_edit_class_set_draw_tabs, "set_draw_tabs", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_spaces"),
        JS_NewCFunction(ctx, text_edit_class_is_drawing_spaces, "is_drawing_spaces", 0),
        JS_NewCFunction(ctx, text_edit_class_set_draw_spaces, "set_draw_spaces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_direction"),
        JS_NewCFunction(ctx, text_edit_class_get_text_direction, "get_text_direction", 0),
        JS_NewCFunction(ctx, text_edit_class_set_text_direction, "set_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, text_edit_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, text_edit_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override"),
        JS_NewCFunction(ctx, text_edit_class_get_structured_text_bidi_override, "get_structured_text_bidi_override", 0),
        JS_NewCFunction(ctx, text_edit_class_set_structured_text_bidi_override, "set_structured_text_bidi_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override_options"),
        JS_NewCFunction(ctx, text_edit_class_get_structured_text_bidi_override_options, "get_structured_text_bidi_override_options", 0),
        JS_NewCFunction(ctx, text_edit_class_set_structured_text_bidi_override_options, "set_structured_text_bidi_override_options", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "text_set"),
		JS_NewCFunction(ctx, text_edit_class_get_text_set_signal, "get_text_set_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "text_changed"),
		JS_NewCFunction(ctx, text_edit_class_get_text_changed_signal, "get_text_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "lines_edited_from"),
		JS_NewCFunction(ctx, text_edit_class_get_lines_edited_from_signal, "get_lines_edited_from_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "caret_changed"),
		JS_NewCFunction(ctx, text_edit_class_get_caret_changed_signal, "get_caret_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "gutter_clicked"),
		JS_NewCFunction(ctx, text_edit_class_get_gutter_clicked_signal, "get_gutter_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "gutter_added"),
		JS_NewCFunction(ctx, text_edit_class_get_gutter_added_signal, "get_gutter_added_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "gutter_removed"),
		JS_NewCFunction(ctx, text_edit_class_get_gutter_removed_signal, "get_gutter_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_text_edit_enum(JSContext *ctx, JSValue ctor) {
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
	JSValue EditAction_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EditAction_obj, "ACTION_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, EditAction_obj, "ACTION_TYPING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, EditAction_obj, "ACTION_BACKSPACE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, EditAction_obj, "ACTION_DELETE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "EditAction", EditAction_obj);
	JSValue SearchFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SearchFlags_obj, "SEARCH_MATCH_CASE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SearchFlags_obj, "SEARCH_WHOLE_WORDS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SearchFlags_obj, "SEARCH_BACKWARDS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "SearchFlags", SearchFlags_obj);
	JSValue CaretType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CaretType_obj, "CARET_TYPE_LINE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CaretType_obj, "CARET_TYPE_BLOCK", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "CaretType", CaretType_obj);
	JSValue SelectionMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SelectionMode_obj, "SELECTION_MODE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SelectionMode_obj, "SELECTION_MODE_SHIFT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SelectionMode_obj, "SELECTION_MODE_POINTER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SelectionMode_obj, "SELECTION_MODE_WORD", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SelectionMode_obj, "SELECTION_MODE_LINE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "SelectionMode", SelectionMode_obj);
	JSValue LineWrappingMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LineWrappingMode_obj, "LINE_WRAPPING_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LineWrappingMode_obj, "LINE_WRAPPING_BOUNDARY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "LineWrappingMode", LineWrappingMode_obj);
	JSValue GutterType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GutterType_obj, "GUTTER_TYPE_STRING", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GutterType_obj, "GUTTER_TYPE_ICON", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GutterType_obj, "GUTTER_TYPE_CUSTOM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "GutterType", GutterType_obj);
}

static int js_text_edit_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TextEdit"] = class_id;
	classes_by_id[class_id] = "TextEdit";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &text_edit_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_text_edit_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, text_edit_class_proto_funcs, _countof(text_edit_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, text_edit_class_constructor, "TextEdit", 0, JS_CFUNC_constructor, 0);
	define_text_edit_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TextEdit", ctor);
	ctor_list["TextEdit"] = ctor;

	return 0;
}

JSModuleDef *_js_init_text_edit_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_text_edit_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TextEdit");
	return m;
}

JSModuleDef *js_init_text_edit_module(JSContext *ctx) {
	return _js_init_text_edit_module(ctx, "@godot/classes/text_edit");
}

void __register_text_edit() {
	js_init_text_edit_module(js_context());
}

void register_text_edit() {
	__register_text_edit();
}