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
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/v_scroll_bar.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/item_list.hpp>
using namespace godot;

static void item_list_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ItemList"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef item_list_class_def = {
    "ItemList",
    item_list_class_finalizer
};

static JSValue item_list_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ItemList"];
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
        instance = memnew(ItemList);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue item_list_class_add_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ItemList::add_item, ctx, this_val, argc, argv);
};
static JSValue item_list_class_add_icon_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ItemList::add_icon_item, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_text, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_text, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_icon, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_icon, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_text_direction, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_text_direction, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_language, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_language, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_auto_translate_mode, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_auto_translate_mode, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_icon_transposed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_icon_transposed, ctx, this_val, argc, argv);
};
static JSValue item_list_class_is_item_icon_transposed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::is_item_icon_transposed, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_icon_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_icon_region, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_icon_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_icon_region, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_icon_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_icon_modulate, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_icon_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_icon_modulate, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_selectable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_selectable, ctx, this_val, argc, argv);
};
static JSValue item_list_class_is_item_selectable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::is_item_selectable, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_disabled, ctx, this_val, argc, argv);
};
static JSValue item_list_class_is_item_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::is_item_disabled, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_metadata, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_metadata(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_metadata, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_custom_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_custom_bg_color, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_custom_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_custom_bg_color, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_custom_fg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_custom_fg_color, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_custom_fg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_custom_fg_color, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_rect, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_tooltip_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_tooltip_enabled, ctx, this_val, argc, argv);
};
static JSValue item_list_class_is_item_tooltip_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::is_item_tooltip_enabled, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_tooltip, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_tooltip, ctx, this_val, argc, argv);
};
static JSValue item_list_class_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::select, ctx, this_val, argc, argv);
};
static JSValue item_list_class_deselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::deselect, ctx, this_val, argc, argv);
};
static JSValue item_list_class_deselect_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::deselect_all, ctx, this_val, argc, argv);
};
static JSValue item_list_class_is_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::is_selected, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_selected_items(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ItemList::get_selected_items, ctx, this_val, argc, argv);
};
static JSValue item_list_class_move_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::move_item, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_item_count, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_count, ctx, this_val, argc, argv);
}
static JSValue item_list_class_remove_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::remove_item, ctx, this_val, argc, argv);
};
static JSValue item_list_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::clear, ctx, this_val, argc, argv);
};
static JSValue item_list_class_sort_items_by_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::sort_items_by_text, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_fixed_column_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_fixed_column_width, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_fixed_column_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_fixed_column_width, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_same_column_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_same_column_width, ctx, this_val, argc, argv);
};
static JSValue item_list_class_is_same_column_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::is_same_column_width, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_max_text_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_max_text_lines, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_max_text_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_max_text_lines, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_max_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_max_columns, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_max_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_max_columns, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_select_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_select_mode, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_select_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_select_mode, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_icon_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_icon_mode, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_icon_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_icon_mode, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_fixed_icon_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_fixed_icon_size, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_fixed_icon_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		ItemList *obj = static_cast<ItemList *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_fixed_icon_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		ItemList *js_proxy = static_cast<ItemList *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_fixed_icon_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue item_list_class_set_icon_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_icon_scale, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_icon_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_icon_scale, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_allow_rmb_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_allow_rmb_select, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_allow_rmb_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_allow_rmb_select, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_allow_reselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_allow_reselect, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_allow_reselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_allow_reselect, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_allow_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_allow_search, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_allow_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_allow_search, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_auto_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_auto_width, ctx, this_val, argc, argv);
};
static JSValue item_list_class_has_auto_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::has_auto_width, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_auto_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_auto_height, ctx, this_val, argc, argv);
};
static JSValue item_list_class_has_auto_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::has_auto_height, ctx, this_val, argc, argv);
}
static JSValue item_list_class_is_anything_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ItemList::is_anything_selected, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_item_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_item_at_position, ctx, this_val, argc, argv);
};
static JSValue item_list_class_ensure_current_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::ensure_current_is_visible, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_v_scroll_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ItemList::get_v_scroll_bar, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_h_scroll_bar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ItemList::get_h_scroll_bar, ctx, this_val, argc, argv);
};
static JSValue item_list_class_set_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_text_overrun_behavior, ctx, this_val, argc, argv);
};
static JSValue item_list_class_get_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::get_text_overrun_behavior, ctx, this_val, argc, argv);
}
static JSValue item_list_class_set_wraparound_items(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::set_wraparound_items, ctx, this_val, argc, argv);
};
static JSValue item_list_class_has_wraparound_items(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ItemList::has_wraparound_items, ctx, this_val, argc, argv);
}
static JSValue item_list_class_force_update_list_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ItemList::force_update_list_size, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry item_list_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_item", 3, &item_list_class_add_item),
	JS_CFUNC_DEF("add_icon_item", 2, &item_list_class_add_icon_item),
	JS_CFUNC_DEF("set_item_text", 2, &item_list_class_set_item_text),
	JS_CFUNC_DEF("get_item_text", 1, &item_list_class_get_item_text),
	JS_CFUNC_DEF("set_item_icon", 2, &item_list_class_set_item_icon),
	JS_CFUNC_DEF("get_item_icon", 1, &item_list_class_get_item_icon),
	JS_CFUNC_DEF("set_item_text_direction", 2, &item_list_class_set_item_text_direction),
	JS_CFUNC_DEF("get_item_text_direction", 1, &item_list_class_get_item_text_direction),
	JS_CFUNC_DEF("set_item_language", 2, &item_list_class_set_item_language),
	JS_CFUNC_DEF("get_item_language", 1, &item_list_class_get_item_language),
	JS_CFUNC_DEF("set_item_auto_translate_mode", 2, &item_list_class_set_item_auto_translate_mode),
	JS_CFUNC_DEF("get_item_auto_translate_mode", 1, &item_list_class_get_item_auto_translate_mode),
	JS_CFUNC_DEF("set_item_icon_transposed", 2, &item_list_class_set_item_icon_transposed),
	JS_CFUNC_DEF("is_item_icon_transposed", 1, &item_list_class_is_item_icon_transposed),
	JS_CFUNC_DEF("set_item_icon_region", 2, &item_list_class_set_item_icon_region),
	JS_CFUNC_DEF("get_item_icon_region", 1, &item_list_class_get_item_icon_region),
	JS_CFUNC_DEF("set_item_icon_modulate", 2, &item_list_class_set_item_icon_modulate),
	JS_CFUNC_DEF("get_item_icon_modulate", 1, &item_list_class_get_item_icon_modulate),
	JS_CFUNC_DEF("set_item_selectable", 2, &item_list_class_set_item_selectable),
	JS_CFUNC_DEF("is_item_selectable", 1, &item_list_class_is_item_selectable),
	JS_CFUNC_DEF("set_item_disabled", 2, &item_list_class_set_item_disabled),
	JS_CFUNC_DEF("is_item_disabled", 1, &item_list_class_is_item_disabled),
	JS_CFUNC_DEF("set_item_metadata", 2, &item_list_class_set_item_metadata),
	JS_CFUNC_DEF("get_item_metadata", 1, &item_list_class_get_item_metadata),
	JS_CFUNC_DEF("set_item_custom_bg_color", 2, &item_list_class_set_item_custom_bg_color),
	JS_CFUNC_DEF("get_item_custom_bg_color", 1, &item_list_class_get_item_custom_bg_color),
	JS_CFUNC_DEF("set_item_custom_fg_color", 2, &item_list_class_set_item_custom_fg_color),
	JS_CFUNC_DEF("get_item_custom_fg_color", 1, &item_list_class_get_item_custom_fg_color),
	JS_CFUNC_DEF("get_item_rect", 2, &item_list_class_get_item_rect),
	JS_CFUNC_DEF("set_item_tooltip_enabled", 2, &item_list_class_set_item_tooltip_enabled),
	JS_CFUNC_DEF("is_item_tooltip_enabled", 1, &item_list_class_is_item_tooltip_enabled),
	JS_CFUNC_DEF("set_item_tooltip", 2, &item_list_class_set_item_tooltip),
	JS_CFUNC_DEF("get_item_tooltip", 1, &item_list_class_get_item_tooltip),
	JS_CFUNC_DEF("select", 2, &item_list_class_select),
	JS_CFUNC_DEF("deselect", 1, &item_list_class_deselect),
	JS_CFUNC_DEF("deselect_all", 0, &item_list_class_deselect_all),
	JS_CFUNC_DEF("is_selected", 1, &item_list_class_is_selected),
	JS_CFUNC_DEF("get_selected_items", 0, &item_list_class_get_selected_items),
	JS_CFUNC_DEF("move_item", 2, &item_list_class_move_item),
	JS_CFUNC_DEF("set_item_count", 1, &item_list_class_set_item_count),
	JS_CFUNC_DEF("get_item_count", 0, &item_list_class_get_item_count),
	JS_CFUNC_DEF("remove_item", 1, &item_list_class_remove_item),
	JS_CFUNC_DEF("clear", 0, &item_list_class_clear),
	JS_CFUNC_DEF("sort_items_by_text", 0, &item_list_class_sort_items_by_text),
	JS_CFUNC_DEF("set_fixed_column_width", 1, &item_list_class_set_fixed_column_width),
	JS_CFUNC_DEF("get_fixed_column_width", 0, &item_list_class_get_fixed_column_width),
	JS_CFUNC_DEF("set_same_column_width", 1, &item_list_class_set_same_column_width),
	JS_CFUNC_DEF("is_same_column_width", 0, &item_list_class_is_same_column_width),
	JS_CFUNC_DEF("set_max_text_lines", 1, &item_list_class_set_max_text_lines),
	JS_CFUNC_DEF("get_max_text_lines", 0, &item_list_class_get_max_text_lines),
	JS_CFUNC_DEF("set_max_columns", 1, &item_list_class_set_max_columns),
	JS_CFUNC_DEF("get_max_columns", 0, &item_list_class_get_max_columns),
	JS_CFUNC_DEF("set_select_mode", 1, &item_list_class_set_select_mode),
	JS_CFUNC_DEF("get_select_mode", 0, &item_list_class_get_select_mode),
	JS_CFUNC_DEF("set_icon_mode", 1, &item_list_class_set_icon_mode),
	JS_CFUNC_DEF("get_icon_mode", 0, &item_list_class_get_icon_mode),
	JS_CFUNC_DEF("set_fixed_icon_size", 1, &item_list_class_set_fixed_icon_size),
	JS_CFUNC_DEF("get_fixed_icon_size", 0, &item_list_class_get_fixed_icon_size),
	JS_CFUNC_DEF("set_icon_scale", 1, &item_list_class_set_icon_scale),
	JS_CFUNC_DEF("get_icon_scale", 0, &item_list_class_get_icon_scale),
	JS_CFUNC_DEF("set_allow_rmb_select", 1, &item_list_class_set_allow_rmb_select),
	JS_CFUNC_DEF("get_allow_rmb_select", 0, &item_list_class_get_allow_rmb_select),
	JS_CFUNC_DEF("set_allow_reselect", 1, &item_list_class_set_allow_reselect),
	JS_CFUNC_DEF("get_allow_reselect", 0, &item_list_class_get_allow_reselect),
	JS_CFUNC_DEF("set_allow_search", 1, &item_list_class_set_allow_search),
	JS_CFUNC_DEF("get_allow_search", 0, &item_list_class_get_allow_search),
	JS_CFUNC_DEF("set_auto_width", 1, &item_list_class_set_auto_width),
	JS_CFUNC_DEF("has_auto_width", 0, &item_list_class_has_auto_width),
	JS_CFUNC_DEF("set_auto_height", 1, &item_list_class_set_auto_height),
	JS_CFUNC_DEF("has_auto_height", 0, &item_list_class_has_auto_height),
	JS_CFUNC_DEF("is_anything_selected", 0, &item_list_class_is_anything_selected),
	JS_CFUNC_DEF("get_item_at_position", 2, &item_list_class_get_item_at_position),
	JS_CFUNC_DEF("ensure_current_is_visible", 0, &item_list_class_ensure_current_is_visible),
	JS_CFUNC_DEF("get_v_scroll_bar", 0, &item_list_class_get_v_scroll_bar),
	JS_CFUNC_DEF("get_h_scroll_bar", 0, &item_list_class_get_h_scroll_bar),
	JS_CFUNC_DEF("set_text_overrun_behavior", 1, &item_list_class_set_text_overrun_behavior),
	JS_CFUNC_DEF("get_text_overrun_behavior", 0, &item_list_class_get_text_overrun_behavior),
	JS_CFUNC_DEF("set_wraparound_items", 1, &item_list_class_set_wraparound_items),
	JS_CFUNC_DEF("has_wraparound_items", 0, &item_list_class_has_wraparound_items),
	JS_CFUNC_DEF("force_update_list_size", 0, &item_list_class_force_update_list_size),
};


static JSValue item_list_class_get_item_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue item_list_class_get_empty_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "empty_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue item_list_class_get_item_clicked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_clicked");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue item_list_class_get_multi_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "multi_selected");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue item_list_class_get_item_activated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "item_activated");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_item_list_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "select_mode"),
        JS_NewCFunction(ctx, item_list_class_get_select_mode, "get_select_mode", 0),
        JS_NewCFunction(ctx, item_list_class_set_select_mode, "set_select_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_reselect"),
        JS_NewCFunction(ctx, item_list_class_get_allow_reselect, "get_allow_reselect", 0),
        JS_NewCFunction(ctx, item_list_class_set_allow_reselect, "set_allow_reselect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_rmb_select"),
        JS_NewCFunction(ctx, item_list_class_get_allow_rmb_select, "get_allow_rmb_select", 0),
        JS_NewCFunction(ctx, item_list_class_set_allow_rmb_select, "set_allow_rmb_select", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_search"),
        JS_NewCFunction(ctx, item_list_class_get_allow_search, "get_allow_search", 0),
        JS_NewCFunction(ctx, item_list_class_set_allow_search, "set_allow_search", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_text_lines"),
        JS_NewCFunction(ctx, item_list_class_get_max_text_lines, "get_max_text_lines", 0),
        JS_NewCFunction(ctx, item_list_class_set_max_text_lines, "set_max_text_lines", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_width"),
        JS_NewCFunction(ctx, item_list_class_has_auto_width, "has_auto_width", 0),
        JS_NewCFunction(ctx, item_list_class_set_auto_width, "set_auto_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_height"),
        JS_NewCFunction(ctx, item_list_class_has_auto_height, "has_auto_height", 0),
        JS_NewCFunction(ctx, item_list_class_set_auto_height, "set_auto_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_overrun_behavior"),
        JS_NewCFunction(ctx, item_list_class_get_text_overrun_behavior, "get_text_overrun_behavior", 0),
        JS_NewCFunction(ctx, item_list_class_set_text_overrun_behavior, "set_text_overrun_behavior", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wraparound_items"),
        JS_NewCFunction(ctx, item_list_class_has_wraparound_items, "has_wraparound_items", 0),
        JS_NewCFunction(ctx, item_list_class_set_wraparound_items, "set_wraparound_items", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "item_count"),
        JS_NewCFunction(ctx, item_list_class_get_item_count, "get_item_count", 0),
        JS_NewCFunction(ctx, item_list_class_set_item_count, "set_item_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_columns"),
        JS_NewCFunction(ctx, item_list_class_get_max_columns, "get_max_columns", 0),
        JS_NewCFunction(ctx, item_list_class_set_max_columns, "set_max_columns", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "same_column_width"),
        JS_NewCFunction(ctx, item_list_class_is_same_column_width, "is_same_column_width", 0),
        JS_NewCFunction(ctx, item_list_class_set_same_column_width, "set_same_column_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fixed_column_width"),
        JS_NewCFunction(ctx, item_list_class_get_fixed_column_width, "get_fixed_column_width", 0),
        JS_NewCFunction(ctx, item_list_class_set_fixed_column_width, "set_fixed_column_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "icon_mode"),
        JS_NewCFunction(ctx, item_list_class_get_icon_mode, "get_icon_mode", 0),
        JS_NewCFunction(ctx, item_list_class_set_icon_mode, "set_icon_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "icon_scale"),
        JS_NewCFunction(ctx, item_list_class_get_icon_scale, "get_icon_scale", 0),
        JS_NewCFunction(ctx, item_list_class_set_icon_scale, "set_icon_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fixed_icon_size"),
        JS_NewCFunction(ctx, item_list_class_get_fixed_icon_size, "get_fixed_icon_size", 0),
        JS_NewCFunction(ctx, item_list_class_set_fixed_icon_size, "set_fixed_icon_size", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_selected"),
		JS_NewCFunction(ctx, item_list_class_get_item_selected_signal, "get_item_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "empty_clicked"),
		JS_NewCFunction(ctx, item_list_class_get_empty_clicked_signal, "get_empty_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_clicked"),
		JS_NewCFunction(ctx, item_list_class_get_item_clicked_signal, "get_item_clicked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "multi_selected"),
		JS_NewCFunction(ctx, item_list_class_get_multi_selected_signal, "get_multi_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "item_activated"),
		JS_NewCFunction(ctx, item_list_class_get_item_activated_signal, "get_item_activated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_item_list_enum(JSContext *ctx, JSValue ctor) {
	JSValue IconMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, IconMode_obj, "ICON_MODE_TOP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, IconMode_obj, "ICON_MODE_LEFT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "IconMode", IconMode_obj);
	JSValue SelectMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SelectMode_obj, "SELECT_SINGLE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SelectMode_obj, "SELECT_MULTI", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SelectMode_obj, "SELECT_TOGGLE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SelectMode", SelectMode_obj);
}

static int js_item_list_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ItemList"] = class_id;
	classes_by_id[class_id] = "ItemList";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &item_list_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_item_list_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, item_list_class_proto_funcs, _countof(item_list_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, item_list_class_constructor, "ItemList", 0, JS_CFUNC_constructor, 0);
	define_item_list_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ItemList", ctor);
	ctor_list["ItemList"] = ctor;

	return 0;
}

JSModuleDef *_js_init_item_list_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_item_list_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ItemList");
	return m;
}

JSModuleDef *js_init_item_list_module(JSContext *ctx) {
	return _js_init_item_list_module(ctx, "@godot/classes/item_list");
}

void __register_item_list() {
	js_init_item_list_module(js_context());
}

void register_item_list() {
	__register_item_list();
}