#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/tree_item.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tree.hpp>
using namespace godot;

static void tree_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Tree"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tree_class_def = {
    "Tree",
    tree_class_finalizer
};

static JSValue tree_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Tree"];
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
        instance = memnew(Tree);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tree_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::clear, ctx, this_val, argc, argv);
};
static JSValue tree_class_create_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tree::create_item, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_root, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_custom_minimum_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_custom_minimum_width, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_expand, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_expand_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_expand_ratio, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_clip_content(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_clip_content, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_column_expanding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_column_expanding, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_column_clipping_content(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_column_clipping_content, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_expand_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_expand_ratio, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_width, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_hide_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_hide_root, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_root_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_root_hidden, ctx, this_val, argc, argv);
}
static JSValue tree_class_get_next_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tree::get_next_selected, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_selected, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_selected, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_selected_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_selected_column, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_pressed_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_pressed_button, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_select_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_select_mode, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_select_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_select_mode, ctx, this_val, argc, argv);
}
static JSValue tree_class_deselect_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::deselect_all, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_columns, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_columns, ctx, this_val, argc, argv);
}
static JSValue tree_class_get_edited(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_edited, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_edited_column(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_edited_column, ctx, this_val, argc, argv);
};
static JSValue tree_class_edit_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tree::edit_selected, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_custom_popup_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_custom_popup_rect, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_item_area_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_item_area_rect, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_item_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_item_at_position, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_at_position, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_drop_section_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_drop_section_at_position, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_button_id_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_button_id_at_position, ctx, this_val, argc, argv);
};
static JSValue tree_class_ensure_cursor_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::ensure_cursor_is_visible, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_titles_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_titles_visible, ctx, this_val, argc, argv);
};
static JSValue tree_class_are_column_titles_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::are_column_titles_visible, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_column_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_title, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_title, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_title_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_title_alignment, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_title_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_title_alignment, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_title_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_title_direction, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_title_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_title_direction, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_column_title_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_column_title_language, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_column_title_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_column_title_language, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_scroll, ctx, this_val, argc, argv);
};
static JSValue tree_class_scroll_to_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::scroll_to_item, ctx, this_val, argc, argv);
};
static JSValue tree_class_set_h_scroll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_h_scroll_enabled, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_h_scroll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_h_scroll_enabled, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_v_scroll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_v_scroll_enabled, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_v_scroll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_v_scroll_enabled, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_hide_folding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_hide_folding, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_folding_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_folding_hidden, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_enable_recursive_folding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_enable_recursive_folding, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_recursive_folding_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_recursive_folding_enabled, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_drop_mode_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_drop_mode_flags, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_drop_mode_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_drop_mode_flags, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_allow_rmb_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_allow_rmb_select, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_allow_rmb_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_allow_rmb_select, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_allow_reselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_allow_reselect, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_allow_reselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_allow_reselect, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_allow_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_allow_search, ctx, this_val, argc, argv);
};
static JSValue tree_class_get_allow_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::get_allow_search, ctx, this_val, argc, argv);
}
static JSValue tree_class_set_auto_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tree::set_auto_tooltip, ctx, this_val, argc, argv);
};
static JSValue tree_class_is_auto_tooltip_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tree::is_auto_tooltip_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry tree_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &tree_class_clear),
	JS_CFUNC_DEF("create_item", 2, &tree_class_create_item),
	JS_CFUNC_DEF("get_root", 0, &tree_class_get_root),
	JS_CFUNC_DEF("set_column_custom_minimum_width", 2, &tree_class_set_column_custom_minimum_width),
	JS_CFUNC_DEF("set_column_expand", 2, &tree_class_set_column_expand),
	JS_CFUNC_DEF("set_column_expand_ratio", 2, &tree_class_set_column_expand_ratio),
	JS_CFUNC_DEF("set_column_clip_content", 2, &tree_class_set_column_clip_content),
	JS_CFUNC_DEF("is_column_expanding", 1, &tree_class_is_column_expanding),
	JS_CFUNC_DEF("is_column_clipping_content", 1, &tree_class_is_column_clipping_content),
	JS_CFUNC_DEF("get_column_expand_ratio", 1, &tree_class_get_column_expand_ratio),
	JS_CFUNC_DEF("get_column_width", 1, &tree_class_get_column_width),
	JS_CFUNC_DEF("set_hide_root", 1, &tree_class_set_hide_root),
	JS_CFUNC_DEF("is_root_hidden", 0, &tree_class_is_root_hidden),
	JS_CFUNC_DEF("get_next_selected", 1, &tree_class_get_next_selected),
	JS_CFUNC_DEF("get_selected", 0, &tree_class_get_selected),
	JS_CFUNC_DEF("set_selected", 2, &tree_class_set_selected),
	JS_CFUNC_DEF("get_selected_column", 0, &tree_class_get_selected_column),
	JS_CFUNC_DEF("get_pressed_button", 0, &tree_class_get_pressed_button),
	JS_CFUNC_DEF("set_select_mode", 1, &tree_class_set_select_mode),
	JS_CFUNC_DEF("get_select_mode", 0, &tree_class_get_select_mode),
	JS_CFUNC_DEF("deselect_all", 0, &tree_class_deselect_all),
	JS_CFUNC_DEF("set_columns", 1, &tree_class_set_columns),
	JS_CFUNC_DEF("get_columns", 0, &tree_class_get_columns),
	JS_CFUNC_DEF("get_edited", 0, &tree_class_get_edited),
	JS_CFUNC_DEF("get_edited_column", 0, &tree_class_get_edited_column),
	JS_CFUNC_DEF("edit_selected", 1, &tree_class_edit_selected),
	JS_CFUNC_DEF("get_custom_popup_rect", 0, &tree_class_get_custom_popup_rect),
	JS_CFUNC_DEF("get_item_area_rect", 3, &tree_class_get_item_area_rect),
	JS_CFUNC_DEF("get_item_at_position", 1, &tree_class_get_item_at_position),
	JS_CFUNC_DEF("get_column_at_position", 1, &tree_class_get_column_at_position),
	JS_CFUNC_DEF("get_drop_section_at_position", 1, &tree_class_get_drop_section_at_position),
	JS_CFUNC_DEF("get_button_id_at_position", 1, &tree_class_get_button_id_at_position),
	JS_CFUNC_DEF("ensure_cursor_is_visible", 0, &tree_class_ensure_cursor_is_visible),
	JS_CFUNC_DEF("set_column_titles_visible", 1, &tree_class_set_column_titles_visible),
	JS_CFUNC_DEF("are_column_titles_visible", 0, &tree_class_are_column_titles_visible),
	JS_CFUNC_DEF("set_column_title", 2, &tree_class_set_column_title),
	JS_CFUNC_DEF("get_column_title", 1, &tree_class_get_column_title),
	JS_CFUNC_DEF("set_column_title_alignment", 2, &tree_class_set_column_title_alignment),
	JS_CFUNC_DEF("get_column_title_alignment", 1, &tree_class_get_column_title_alignment),
	JS_CFUNC_DEF("set_column_title_direction", 2, &tree_class_set_column_title_direction),
	JS_CFUNC_DEF("get_column_title_direction", 1, &tree_class_get_column_title_direction),
	JS_CFUNC_DEF("set_column_title_language", 2, &tree_class_set_column_title_language),
	JS_CFUNC_DEF("get_column_title_language", 1, &tree_class_get_column_title_language),
	JS_CFUNC_DEF("get_scroll", 0, &tree_class_get_scroll),
	JS_CFUNC_DEF("scroll_to_item", 2, &tree_class_scroll_to_item),
	JS_CFUNC_DEF("set_h_scroll_enabled", 1, &tree_class_set_h_scroll_enabled),
	JS_CFUNC_DEF("is_h_scroll_enabled", 0, &tree_class_is_h_scroll_enabled),
	JS_CFUNC_DEF("set_v_scroll_enabled", 1, &tree_class_set_v_scroll_enabled),
	JS_CFUNC_DEF("is_v_scroll_enabled", 0, &tree_class_is_v_scroll_enabled),
	JS_CFUNC_DEF("set_hide_folding", 1, &tree_class_set_hide_folding),
	JS_CFUNC_DEF("is_folding_hidden", 0, &tree_class_is_folding_hidden),
	JS_CFUNC_DEF("set_enable_recursive_folding", 1, &tree_class_set_enable_recursive_folding),
	JS_CFUNC_DEF("is_recursive_folding_enabled", 0, &tree_class_is_recursive_folding_enabled),
	JS_CFUNC_DEF("set_drop_mode_flags", 1, &tree_class_set_drop_mode_flags),
	JS_CFUNC_DEF("get_drop_mode_flags", 0, &tree_class_get_drop_mode_flags),
	JS_CFUNC_DEF("set_allow_rmb_select", 1, &tree_class_set_allow_rmb_select),
	JS_CFUNC_DEF("get_allow_rmb_select", 0, &tree_class_get_allow_rmb_select),
	JS_CFUNC_DEF("set_allow_reselect", 1, &tree_class_set_allow_reselect),
	JS_CFUNC_DEF("get_allow_reselect", 0, &tree_class_get_allow_reselect),
	JS_CFUNC_DEF("set_allow_search", 1, &tree_class_set_allow_search),
	JS_CFUNC_DEF("get_allow_search", 0, &tree_class_get_allow_search),
	JS_CFUNC_DEF("set_auto_tooltip", 1, &tree_class_set_auto_tooltip),
	JS_CFUNC_DEF("is_auto_tooltip_enabled", 0, &tree_class_is_auto_tooltip_enabled),
};


static JSValue tree_class_get_item_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_cell_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "cell_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_multi_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "multi_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_item_mouse_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_mouse_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_empty_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "empty_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_item_edited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_edited");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_custom_item_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "custom_item_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_item_icon_double_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_icon_double_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_item_collapsed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_collapsed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_check_propagated_to_item_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "check_propagated_to_item");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_button_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "button_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_custom_popup_edited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "custom_popup_edited");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_item_activated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_activated");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_column_title_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "column_title_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue tree_class_get_nothing_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "nothing_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_tree_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "columns"),
        JS_NewCFunction(ctx, tree_class_get_columns, "get_columns", 0),
        JS_NewCFunction(ctx, tree_class_set_columns, "set_columns", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "column_titles_visible"),
        JS_NewCFunction(ctx, tree_class_are_column_titles_visible, "are_column_titles_visible", 0),
        JS_NewCFunction(ctx, tree_class_set_column_titles_visible, "set_column_titles_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_reselect"),
        JS_NewCFunction(ctx, tree_class_get_allow_reselect, "get_allow_reselect", 0),
        JS_NewCFunction(ctx, tree_class_set_allow_reselect, "set_allow_reselect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_rmb_select"),
        JS_NewCFunction(ctx, tree_class_get_allow_rmb_select, "get_allow_rmb_select", 0),
        JS_NewCFunction(ctx, tree_class_set_allow_rmb_select, "set_allow_rmb_select", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_search"),
        JS_NewCFunction(ctx, tree_class_get_allow_search, "get_allow_search", 0),
        JS_NewCFunction(ctx, tree_class_set_allow_search, "set_allow_search", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hide_folding"),
        JS_NewCFunction(ctx, tree_class_is_folding_hidden, "is_folding_hidden", 0),
        JS_NewCFunction(ctx, tree_class_set_hide_folding, "set_hide_folding", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_recursive_folding"),
        JS_NewCFunction(ctx, tree_class_is_recursive_folding_enabled, "is_recursive_folding_enabled", 0),
        JS_NewCFunction(ctx, tree_class_set_enable_recursive_folding, "set_enable_recursive_folding", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hide_root"),
        JS_NewCFunction(ctx, tree_class_is_root_hidden, "is_root_hidden", 0),
        JS_NewCFunction(ctx, tree_class_set_hide_root, "set_hide_root", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drop_mode_flags"),
        JS_NewCFunction(ctx, tree_class_get_drop_mode_flags, "get_drop_mode_flags", 0),
        JS_NewCFunction(ctx, tree_class_set_drop_mode_flags, "set_drop_mode_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "select_mode"),
        JS_NewCFunction(ctx, tree_class_get_select_mode, "get_select_mode", 0),
        JS_NewCFunction(ctx, tree_class_set_select_mode, "set_select_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_horizontal_enabled"),
        JS_NewCFunction(ctx, tree_class_is_h_scroll_enabled, "is_h_scroll_enabled", 0),
        JS_NewCFunction(ctx, tree_class_set_h_scroll_enabled, "set_h_scroll_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_vertical_enabled"),
        JS_NewCFunction(ctx, tree_class_is_v_scroll_enabled, "is_v_scroll_enabled", 0),
        JS_NewCFunction(ctx, tree_class_set_v_scroll_enabled, "set_v_scroll_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_tooltip"),
        JS_NewCFunction(ctx, tree_class_is_auto_tooltip_enabled, "is_auto_tooltip_enabled", 0),
        JS_NewCFunction(ctx, tree_class_set_auto_tooltip, "set_auto_tooltip", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_selected"),
		JS_NewCFunction(ctx, tree_class_get_item_selected_signal, "get_item_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "cell_selected"),
		JS_NewCFunction(ctx, tree_class_get_cell_selected_signal, "get_cell_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "multi_selected"),
		JS_NewCFunction(ctx, tree_class_get_multi_selected_signal, "get_multi_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_mouse_selected"),
		JS_NewCFunction(ctx, tree_class_get_item_mouse_selected_signal, "get_item_mouse_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "empty_clicked"),
		JS_NewCFunction(ctx, tree_class_get_empty_clicked_signal, "get_empty_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_edited"),
		JS_NewCFunction(ctx, tree_class_get_item_edited_signal, "get_item_edited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "custom_item_clicked"),
		JS_NewCFunction(ctx, tree_class_get_custom_item_clicked_signal, "get_custom_item_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_icon_double_clicked"),
		JS_NewCFunction(ctx, tree_class_get_item_icon_double_clicked_signal, "get_item_icon_double_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_collapsed"),
		JS_NewCFunction(ctx, tree_class_get_item_collapsed_signal, "get_item_collapsed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "check_propagated_to_item"),
		JS_NewCFunction(ctx, tree_class_get_check_propagated_to_item_signal, "get_check_propagated_to_item_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_clicked"),
		JS_NewCFunction(ctx, tree_class_get_button_clicked_signal, "get_button_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "custom_popup_edited"),
		JS_NewCFunction(ctx, tree_class_get_custom_popup_edited_signal, "get_custom_popup_edited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_activated"),
		JS_NewCFunction(ctx, tree_class_get_item_activated_signal, "get_item_activated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "column_title_clicked"),
		JS_NewCFunction(ctx, tree_class_get_column_title_clicked_signal, "get_column_title_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "nothing_selected"),
		JS_NewCFunction(ctx, tree_class_get_nothing_selected_signal, "get_nothing_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_tree_enum(JSContext *ctx, JSValue ctor) {
	JSValue SelectMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SelectMode_obj, "SELECT_SINGLE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SelectMode_obj, "SELECT_ROW", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SelectMode_obj, "SELECT_MULTI", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SelectMode", SelectMode_obj);
	JSValue DropModeFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DropModeFlags_obj, "DROP_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DropModeFlags_obj, "DROP_MODE_ON_ITEM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DropModeFlags_obj, "DROP_MODE_INBETWEEN", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DropModeFlags", DropModeFlags_obj);
}

static int js_tree_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Tree"] = class_id;
	classes_by_id[class_id] = "Tree";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tree_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tree_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tree_class_proto_funcs, _countof(tree_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tree_class_constructor, "Tree", 0, JS_CFUNC_constructor, 0);
	define_tree_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Tree", ctor);
	ctor_list["Tree"] = ctor;

	return 0;
}

JSModuleDef *_js_init_tree_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tree_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Tree");
	return m;
}

JSModuleDef *js_init_tree_module(JSContext *ctx) {
	return _js_init_tree_module(ctx, "@godot/classes/tree");
}

void __register_tree() {
	js_init_tree_module(js_context());
}

void register_tree() {
	__register_tree();
}