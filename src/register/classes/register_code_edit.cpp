#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/text_edit.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/code_edit.hpp>
using namespace godot;

static void code_edit_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CodeEdit"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef code_edit_class_def = {
    "CodeEdit",
    code_edit_class_finalizer
};

static JSValue code_edit_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CodeEdit"];
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
        instance = memnew(CodeEdit);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue code_edit_class_set_indent_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_indent_size, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_indent_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_indent_size, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_indent_using_spaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_indent_using_spaces, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_indent_using_spaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_indent_using_spaces, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_auto_indent_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_auto_indent_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_auto_indent_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_auto_indent_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_auto_indent_prefixes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_auto_indent_prefixes, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_auto_indent_prefixes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_auto_indent_prefixes, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_do_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::do_indent, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_indent_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::indent_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_unindent_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::unindent_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_convert_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::convert_indent, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_auto_brace_completion_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_auto_brace_completion_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_auto_brace_completion_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_auto_brace_completion_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_highlight_matching_braces_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_highlight_matching_braces_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_highlight_matching_braces_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_highlight_matching_braces_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_add_auto_brace_completion_pair(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::add_auto_brace_completion_pair, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_auto_brace_completion_pairs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_auto_brace_completion_pairs, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_auto_brace_completion_pairs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		CodeEdit *obj = static_cast<CodeEdit *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_auto_brace_completion_pairs();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		CodeEdit *js_proxy = static_cast<CodeEdit *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_auto_brace_completion_pairs(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue code_edit_class_has_auto_brace_completion_open_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::has_auto_brace_completion_open_key, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_has_auto_brace_completion_close_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::has_auto_brace_completion_close_key, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_auto_brace_completion_close_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_auto_brace_completion_close_key, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_draw_breakpoints_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_draw_breakpoints_gutter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_drawing_breakpoints_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_drawing_breakpoints_gutter, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_draw_bookmarks_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_draw_bookmarks_gutter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_drawing_bookmarks_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_drawing_bookmarks_gutter, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_draw_executing_lines_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_draw_executing_lines_gutter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_drawing_executing_lines_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_drawing_executing_lines_gutter, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_line_as_breakpoint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_line_as_breakpoint, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_breakpointed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_breakpointed, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_clear_breakpointed_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::clear_breakpointed_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_breakpointed_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_breakpointed_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_line_as_bookmarked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_line_as_bookmarked, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_bookmarked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_bookmarked, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_clear_bookmarked_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::clear_bookmarked_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_bookmarked_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_bookmarked_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_line_as_executing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_line_as_executing, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_executing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_executing, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_clear_executing_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::clear_executing_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_executing_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_executing_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_draw_line_numbers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_draw_line_numbers, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_draw_line_numbers_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_draw_line_numbers_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_line_numbers_zero_padded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_line_numbers_zero_padded, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_numbers_zero_padded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_numbers_zero_padded, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_draw_fold_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_draw_fold_gutter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_drawing_fold_gutter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_drawing_fold_gutter, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_line_folding_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_line_folding_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_folding_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_folding_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_can_fold_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::can_fold_line, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_fold_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::fold_line, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_unfold_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::unfold_line, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_fold_all_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::fold_all_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_unfold_all_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::unfold_all_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_toggle_foldable_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::toggle_foldable_line, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_toggle_foldable_lines_at_carets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::toggle_foldable_lines_at_carets, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_folded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_folded, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_folded_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_folded_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_create_code_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::create_code_region, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_code_region_start_tag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_code_region_start_tag, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_code_region_end_tag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_code_region_end_tag, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_code_region_tags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_code_region_tags, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_code_region_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_code_region_start, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_line_code_region_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_line_code_region_end, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_add_string_delimiter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::add_string_delimiter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_remove_string_delimiter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::remove_string_delimiter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_has_string_delimiter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::has_string_delimiter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_string_delimiters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_string_delimiters, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_clear_string_delimiters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::clear_string_delimiters, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_string_delimiters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_string_delimiters, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_is_in_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_in_string, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_add_comment_delimiter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::add_comment_delimiter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_remove_comment_delimiter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::remove_comment_delimiter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_has_comment_delimiter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::has_comment_delimiter, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_comment_delimiters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_comment_delimiters, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_clear_comment_delimiters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::clear_comment_delimiters, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_comment_delimiters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_comment_delimiters, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_is_in_comment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_in_comment, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_delimiter_start_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_delimiter_start_key, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_delimiter_end_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_delimiter_end_key, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_delimiter_start_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_delimiter_start_position, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_delimiter_end_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_delimiter_end_position, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_code_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_code_hint, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_code_hint_draw_below(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_code_hint_draw_below, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_text_for_code_completion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_text_for_code_completion, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_request_code_completion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::request_code_completion, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_add_code_completion_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::add_code_completion_option, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_update_code_completion_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::update_code_completion_options, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_code_completion_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_code_completion_options, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_code_completion_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_code_completion_option, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_code_completion_selected_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_code_completion_selected_index, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_code_completion_selected_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_code_completion_selected_index, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_confirm_code_completion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::confirm_code_completion, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_cancel_code_completion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::cancel_code_completion, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_code_completion_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_code_completion_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_code_completion_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_code_completion_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_code_completion_prefixes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_code_completion_prefixes, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_code_completion_prefixes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_code_completion_prefixes, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_line_length_guidelines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_line_length_guidelines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_line_length_guidelines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_line_length_guidelines, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_set_symbol_lookup_on_click_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_symbol_lookup_on_click_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_symbol_lookup_on_click_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_symbol_lookup_on_click_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_get_text_for_symbol_lookup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_text_for_symbol_lookup, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_get_text_with_cursor_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::get_text_with_cursor_char, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_symbol_lookup_word_as_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_symbol_lookup_word_as_valid, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_set_symbol_tooltip_on_hover_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::set_symbol_tooltip_on_hover_enabled, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_is_symbol_tooltip_on_hover_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeEdit::is_symbol_tooltip_on_hover_enabled, ctx, this_val, argc, argv);
}
static JSValue code_edit_class_move_lines_up(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::move_lines_up, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_move_lines_down(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::move_lines_down, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_delete_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::delete_lines, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_duplicate_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::duplicate_selection, ctx, this_val, argc, argv);
};
static JSValue code_edit_class_duplicate_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeEdit::duplicate_lines, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry code_edit_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_indent_size", 1, &code_edit_class_set_indent_size),
	JS_CFUNC_DEF("get_indent_size", 0, &code_edit_class_get_indent_size),
	JS_CFUNC_DEF("set_indent_using_spaces", 1, &code_edit_class_set_indent_using_spaces),
	JS_CFUNC_DEF("is_indent_using_spaces", 0, &code_edit_class_is_indent_using_spaces),
	JS_CFUNC_DEF("set_auto_indent_enabled", 1, &code_edit_class_set_auto_indent_enabled),
	JS_CFUNC_DEF("is_auto_indent_enabled", 0, &code_edit_class_is_auto_indent_enabled),
	JS_CFUNC_DEF("set_auto_indent_prefixes", 1, &code_edit_class_set_auto_indent_prefixes),
	JS_CFUNC_DEF("get_auto_indent_prefixes", 0, &code_edit_class_get_auto_indent_prefixes),
	JS_CFUNC_DEF("do_indent", 0, &code_edit_class_do_indent),
	JS_CFUNC_DEF("indent_lines", 0, &code_edit_class_indent_lines),
	JS_CFUNC_DEF("unindent_lines", 0, &code_edit_class_unindent_lines),
	JS_CFUNC_DEF("convert_indent", 2, &code_edit_class_convert_indent),
	JS_CFUNC_DEF("set_auto_brace_completion_enabled", 1, &code_edit_class_set_auto_brace_completion_enabled),
	JS_CFUNC_DEF("is_auto_brace_completion_enabled", 0, &code_edit_class_is_auto_brace_completion_enabled),
	JS_CFUNC_DEF("set_highlight_matching_braces_enabled", 1, &code_edit_class_set_highlight_matching_braces_enabled),
	JS_CFUNC_DEF("is_highlight_matching_braces_enabled", 0, &code_edit_class_is_highlight_matching_braces_enabled),
	JS_CFUNC_DEF("add_auto_brace_completion_pair", 2, &code_edit_class_add_auto_brace_completion_pair),
	JS_CFUNC_DEF("set_auto_brace_completion_pairs", 1, &code_edit_class_set_auto_brace_completion_pairs),
	JS_CFUNC_DEF("get_auto_brace_completion_pairs", 0, &code_edit_class_get_auto_brace_completion_pairs),
	JS_CFUNC_DEF("has_auto_brace_completion_open_key", 1, &code_edit_class_has_auto_brace_completion_open_key),
	JS_CFUNC_DEF("has_auto_brace_completion_close_key", 1, &code_edit_class_has_auto_brace_completion_close_key),
	JS_CFUNC_DEF("get_auto_brace_completion_close_key", 1, &code_edit_class_get_auto_brace_completion_close_key),
	JS_CFUNC_DEF("set_draw_breakpoints_gutter", 1, &code_edit_class_set_draw_breakpoints_gutter),
	JS_CFUNC_DEF("is_drawing_breakpoints_gutter", 0, &code_edit_class_is_drawing_breakpoints_gutter),
	JS_CFUNC_DEF("set_draw_bookmarks_gutter", 1, &code_edit_class_set_draw_bookmarks_gutter),
	JS_CFUNC_DEF("is_drawing_bookmarks_gutter", 0, &code_edit_class_is_drawing_bookmarks_gutter),
	JS_CFUNC_DEF("set_draw_executing_lines_gutter", 1, &code_edit_class_set_draw_executing_lines_gutter),
	JS_CFUNC_DEF("is_drawing_executing_lines_gutter", 0, &code_edit_class_is_drawing_executing_lines_gutter),
	JS_CFUNC_DEF("set_line_as_breakpoint", 2, &code_edit_class_set_line_as_breakpoint),
	JS_CFUNC_DEF("is_line_breakpointed", 1, &code_edit_class_is_line_breakpointed),
	JS_CFUNC_DEF("clear_breakpointed_lines", 0, &code_edit_class_clear_breakpointed_lines),
	JS_CFUNC_DEF("get_breakpointed_lines", 0, &code_edit_class_get_breakpointed_lines),
	JS_CFUNC_DEF("set_line_as_bookmarked", 2, &code_edit_class_set_line_as_bookmarked),
	JS_CFUNC_DEF("is_line_bookmarked", 1, &code_edit_class_is_line_bookmarked),
	JS_CFUNC_DEF("clear_bookmarked_lines", 0, &code_edit_class_clear_bookmarked_lines),
	JS_CFUNC_DEF("get_bookmarked_lines", 0, &code_edit_class_get_bookmarked_lines),
	JS_CFUNC_DEF("set_line_as_executing", 2, &code_edit_class_set_line_as_executing),
	JS_CFUNC_DEF("is_line_executing", 1, &code_edit_class_is_line_executing),
	JS_CFUNC_DEF("clear_executing_lines", 0, &code_edit_class_clear_executing_lines),
	JS_CFUNC_DEF("get_executing_lines", 0, &code_edit_class_get_executing_lines),
	JS_CFUNC_DEF("set_draw_line_numbers", 1, &code_edit_class_set_draw_line_numbers),
	JS_CFUNC_DEF("is_draw_line_numbers_enabled", 0, &code_edit_class_is_draw_line_numbers_enabled),
	JS_CFUNC_DEF("set_line_numbers_zero_padded", 1, &code_edit_class_set_line_numbers_zero_padded),
	JS_CFUNC_DEF("is_line_numbers_zero_padded", 0, &code_edit_class_is_line_numbers_zero_padded),
	JS_CFUNC_DEF("set_draw_fold_gutter", 1, &code_edit_class_set_draw_fold_gutter),
	JS_CFUNC_DEF("is_drawing_fold_gutter", 0, &code_edit_class_is_drawing_fold_gutter),
	JS_CFUNC_DEF("set_line_folding_enabled", 1, &code_edit_class_set_line_folding_enabled),
	JS_CFUNC_DEF("is_line_folding_enabled", 0, &code_edit_class_is_line_folding_enabled),
	JS_CFUNC_DEF("can_fold_line", 1, &code_edit_class_can_fold_line),
	JS_CFUNC_DEF("fold_line", 1, &code_edit_class_fold_line),
	JS_CFUNC_DEF("unfold_line", 1, &code_edit_class_unfold_line),
	JS_CFUNC_DEF("fold_all_lines", 0, &code_edit_class_fold_all_lines),
	JS_CFUNC_DEF("unfold_all_lines", 0, &code_edit_class_unfold_all_lines),
	JS_CFUNC_DEF("toggle_foldable_line", 1, &code_edit_class_toggle_foldable_line),
	JS_CFUNC_DEF("toggle_foldable_lines_at_carets", 0, &code_edit_class_toggle_foldable_lines_at_carets),
	JS_CFUNC_DEF("is_line_folded", 1, &code_edit_class_is_line_folded),
	JS_CFUNC_DEF("get_folded_lines", 0, &code_edit_class_get_folded_lines),
	JS_CFUNC_DEF("create_code_region", 0, &code_edit_class_create_code_region),
	JS_CFUNC_DEF("get_code_region_start_tag", 0, &code_edit_class_get_code_region_start_tag),
	JS_CFUNC_DEF("get_code_region_end_tag", 0, &code_edit_class_get_code_region_end_tag),
	JS_CFUNC_DEF("set_code_region_tags", 2, &code_edit_class_set_code_region_tags),
	JS_CFUNC_DEF("is_line_code_region_start", 1, &code_edit_class_is_line_code_region_start),
	JS_CFUNC_DEF("is_line_code_region_end", 1, &code_edit_class_is_line_code_region_end),
	JS_CFUNC_DEF("add_string_delimiter", 3, &code_edit_class_add_string_delimiter),
	JS_CFUNC_DEF("remove_string_delimiter", 1, &code_edit_class_remove_string_delimiter),
	JS_CFUNC_DEF("has_string_delimiter", 1, &code_edit_class_has_string_delimiter),
	JS_CFUNC_DEF("set_string_delimiters", 1, &code_edit_class_set_string_delimiters),
	JS_CFUNC_DEF("clear_string_delimiters", 0, &code_edit_class_clear_string_delimiters),
	JS_CFUNC_DEF("get_string_delimiters", 0, &code_edit_class_get_string_delimiters),
	JS_CFUNC_DEF("is_in_string", 2, &code_edit_class_is_in_string),
	JS_CFUNC_DEF("add_comment_delimiter", 3, &code_edit_class_add_comment_delimiter),
	JS_CFUNC_DEF("remove_comment_delimiter", 1, &code_edit_class_remove_comment_delimiter),
	JS_CFUNC_DEF("has_comment_delimiter", 1, &code_edit_class_has_comment_delimiter),
	JS_CFUNC_DEF("set_comment_delimiters", 1, &code_edit_class_set_comment_delimiters),
	JS_CFUNC_DEF("clear_comment_delimiters", 0, &code_edit_class_clear_comment_delimiters),
	JS_CFUNC_DEF("get_comment_delimiters", 0, &code_edit_class_get_comment_delimiters),
	JS_CFUNC_DEF("is_in_comment", 2, &code_edit_class_is_in_comment),
	JS_CFUNC_DEF("get_delimiter_start_key", 1, &code_edit_class_get_delimiter_start_key),
	JS_CFUNC_DEF("get_delimiter_end_key", 1, &code_edit_class_get_delimiter_end_key),
	JS_CFUNC_DEF("get_delimiter_start_position", 2, &code_edit_class_get_delimiter_start_position),
	JS_CFUNC_DEF("get_delimiter_end_position", 2, &code_edit_class_get_delimiter_end_position),
	JS_CFUNC_DEF("set_code_hint", 1, &code_edit_class_set_code_hint),
	JS_CFUNC_DEF("set_code_hint_draw_below", 1, &code_edit_class_set_code_hint_draw_below),
	JS_CFUNC_DEF("get_text_for_code_completion", 0, &code_edit_class_get_text_for_code_completion),
	JS_CFUNC_DEF("request_code_completion", 1, &code_edit_class_request_code_completion),
	JS_CFUNC_DEF("add_code_completion_option", 7, &code_edit_class_add_code_completion_option),
	JS_CFUNC_DEF("update_code_completion_options", 1, &code_edit_class_update_code_completion_options),
	JS_CFUNC_DEF("get_code_completion_options", 0, &code_edit_class_get_code_completion_options),
	JS_CFUNC_DEF("get_code_completion_option", 1, &code_edit_class_get_code_completion_option),
	JS_CFUNC_DEF("get_code_completion_selected_index", 0, &code_edit_class_get_code_completion_selected_index),
	JS_CFUNC_DEF("set_code_completion_selected_index", 1, &code_edit_class_set_code_completion_selected_index),
	JS_CFUNC_DEF("confirm_code_completion", 1, &code_edit_class_confirm_code_completion),
	JS_CFUNC_DEF("cancel_code_completion", 0, &code_edit_class_cancel_code_completion),
	JS_CFUNC_DEF("set_code_completion_enabled", 1, &code_edit_class_set_code_completion_enabled),
	JS_CFUNC_DEF("is_code_completion_enabled", 0, &code_edit_class_is_code_completion_enabled),
	JS_CFUNC_DEF("set_code_completion_prefixes", 1, &code_edit_class_set_code_completion_prefixes),
	JS_CFUNC_DEF("get_code_completion_prefixes", 0, &code_edit_class_get_code_completion_prefixes),
	JS_CFUNC_DEF("set_line_length_guidelines", 1, &code_edit_class_set_line_length_guidelines),
	JS_CFUNC_DEF("get_line_length_guidelines", 0, &code_edit_class_get_line_length_guidelines),
	JS_CFUNC_DEF("set_symbol_lookup_on_click_enabled", 1, &code_edit_class_set_symbol_lookup_on_click_enabled),
	JS_CFUNC_DEF("is_symbol_lookup_on_click_enabled", 0, &code_edit_class_is_symbol_lookup_on_click_enabled),
	JS_CFUNC_DEF("get_text_for_symbol_lookup", 0, &code_edit_class_get_text_for_symbol_lookup),
	JS_CFUNC_DEF("get_text_with_cursor_char", 2, &code_edit_class_get_text_with_cursor_char),
	JS_CFUNC_DEF("set_symbol_lookup_word_as_valid", 1, &code_edit_class_set_symbol_lookup_word_as_valid),
	JS_CFUNC_DEF("set_symbol_tooltip_on_hover_enabled", 1, &code_edit_class_set_symbol_tooltip_on_hover_enabled),
	JS_CFUNC_DEF("is_symbol_tooltip_on_hover_enabled", 0, &code_edit_class_is_symbol_tooltip_on_hover_enabled),
	JS_CFUNC_DEF("move_lines_up", 0, &code_edit_class_move_lines_up),
	JS_CFUNC_DEF("move_lines_down", 0, &code_edit_class_move_lines_down),
	JS_CFUNC_DEF("delete_lines", 0, &code_edit_class_delete_lines),
	JS_CFUNC_DEF("duplicate_selection", 0, &code_edit_class_duplicate_selection),
	JS_CFUNC_DEF("duplicate_lines", 0, &code_edit_class_duplicate_lines),
};


static JSValue code_edit_class_get_breakpoint_toggled_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CodeEdit *opaque = static_cast<CodeEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "breakpoint_toggled_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "breakpoint_toggled"));
		JS_DefinePropertyValueStr(ctx, this_val, "breakpoint_toggled_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue code_edit_class_get_code_completion_requested_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CodeEdit *opaque = static_cast<CodeEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "code_completion_requested_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "code_completion_requested"));
		JS_DefinePropertyValueStr(ctx, this_val, "code_completion_requested_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue code_edit_class_get_symbol_lookup_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CodeEdit *opaque = static_cast<CodeEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "symbol_lookup_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "symbol_lookup"));
		JS_DefinePropertyValueStr(ctx, this_val, "symbol_lookup_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue code_edit_class_get_symbol_validate_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CodeEdit *opaque = static_cast<CodeEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "symbol_validate_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "symbol_validate"));
		JS_DefinePropertyValueStr(ctx, this_val, "symbol_validate_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue code_edit_class_get_symbol_hovered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CodeEdit *opaque = static_cast<CodeEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "symbol_hovered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "symbol_hovered"));
		JS_DefinePropertyValueStr(ctx, this_val, "symbol_hovered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_code_edit_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "symbol_lookup_on_click"),
        JS_NewCFunction(ctx, code_edit_class_is_symbol_lookup_on_click_enabled, "is_symbol_lookup_on_click_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_symbol_lookup_on_click_enabled, "set_symbol_lookup_on_click_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "symbol_tooltip_on_hover"),
        JS_NewCFunction(ctx, code_edit_class_is_symbol_tooltip_on_hover_enabled, "is_symbol_tooltip_on_hover_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_symbol_tooltip_on_hover_enabled, "set_symbol_tooltip_on_hover_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "line_folding"),
        JS_NewCFunction(ctx, code_edit_class_is_line_folding_enabled, "is_line_folding_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_line_folding_enabled, "set_line_folding_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "line_length_guidelines"),
        JS_NewCFunction(ctx, code_edit_class_get_line_length_guidelines, "get_line_length_guidelines", 0),
        JS_NewCFunction(ctx, code_edit_class_set_line_length_guidelines, "set_line_length_guidelines", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gutters_draw_breakpoints_gutter"),
        JS_NewCFunction(ctx, code_edit_class_is_drawing_breakpoints_gutter, "is_drawing_breakpoints_gutter", 0),
        JS_NewCFunction(ctx, code_edit_class_set_draw_breakpoints_gutter, "set_draw_breakpoints_gutter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gutters_draw_bookmarks"),
        JS_NewCFunction(ctx, code_edit_class_is_drawing_bookmarks_gutter, "is_drawing_bookmarks_gutter", 0),
        JS_NewCFunction(ctx, code_edit_class_set_draw_bookmarks_gutter, "set_draw_bookmarks_gutter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gutters_draw_executing_lines"),
        JS_NewCFunction(ctx, code_edit_class_is_drawing_executing_lines_gutter, "is_drawing_executing_lines_gutter", 0),
        JS_NewCFunction(ctx, code_edit_class_set_draw_executing_lines_gutter, "set_draw_executing_lines_gutter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gutters_draw_line_numbers"),
        JS_NewCFunction(ctx, code_edit_class_is_draw_line_numbers_enabled, "is_draw_line_numbers_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_draw_line_numbers, "set_draw_line_numbers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gutters_zero_pad_line_numbers"),
        JS_NewCFunction(ctx, code_edit_class_is_line_numbers_zero_padded, "is_line_numbers_zero_padded", 0),
        JS_NewCFunction(ctx, code_edit_class_set_line_numbers_zero_padded, "set_line_numbers_zero_padded", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gutters_draw_fold_gutter"),
        JS_NewCFunction(ctx, code_edit_class_is_drawing_fold_gutter, "is_drawing_fold_gutter", 0),
        JS_NewCFunction(ctx, code_edit_class_set_draw_fold_gutter, "set_draw_fold_gutter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "delimiter_strings"),
        JS_NewCFunction(ctx, code_edit_class_get_string_delimiters, "get_string_delimiters", 0),
        JS_NewCFunction(ctx, code_edit_class_set_string_delimiters, "set_string_delimiters", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "delimiter_comments"),
        JS_NewCFunction(ctx, code_edit_class_get_comment_delimiters, "get_comment_delimiters", 0),
        JS_NewCFunction(ctx, code_edit_class_set_comment_delimiters, "set_comment_delimiters", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "code_completion_enabled"),
        JS_NewCFunction(ctx, code_edit_class_is_code_completion_enabled, "is_code_completion_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_code_completion_enabled, "set_code_completion_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "code_completion_prefixes"),
        JS_NewCFunction(ctx, code_edit_class_get_code_completion_prefixes, "get_code_completion_prefixes", 0),
        JS_NewCFunction(ctx, code_edit_class_set_code_completion_prefixes, "set_code_completion_prefixes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indent_size"),
        JS_NewCFunction(ctx, code_edit_class_get_indent_size, "get_indent_size", 0),
        JS_NewCFunction(ctx, code_edit_class_set_indent_size, "set_indent_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indent_use_spaces"),
        JS_NewCFunction(ctx, code_edit_class_is_indent_using_spaces, "is_indent_using_spaces", 0),
        JS_NewCFunction(ctx, code_edit_class_set_indent_using_spaces, "set_indent_using_spaces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indent_automatic"),
        JS_NewCFunction(ctx, code_edit_class_is_auto_indent_enabled, "is_auto_indent_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_auto_indent_enabled, "set_auto_indent_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indent_automatic_prefixes"),
        JS_NewCFunction(ctx, code_edit_class_get_auto_indent_prefixes, "get_auto_indent_prefixes", 0),
        JS_NewCFunction(ctx, code_edit_class_set_auto_indent_prefixes, "set_auto_indent_prefixes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_brace_completion_enabled"),
        JS_NewCFunction(ctx, code_edit_class_is_auto_brace_completion_enabled, "is_auto_brace_completion_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_auto_brace_completion_enabled, "set_auto_brace_completion_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_brace_completion_highlight_matching"),
        JS_NewCFunction(ctx, code_edit_class_is_highlight_matching_braces_enabled, "is_highlight_matching_braces_enabled", 0),
        JS_NewCFunction(ctx, code_edit_class_set_highlight_matching_braces_enabled, "set_highlight_matching_braces_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_brace_completion_pairs"),
        JS_NewCFunction(ctx, code_edit_class_get_auto_brace_completion_pairs, "get_auto_brace_completion_pairs", 0),
        JS_NewCFunction(ctx, code_edit_class_set_auto_brace_completion_pairs, "set_auto_brace_completion_pairs", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "breakpoint_toggled"),
		JS_NewCFunction(ctx, code_edit_class_get_breakpoint_toggled_signal, "get_breakpoint_toggled_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "code_completion_requested"),
		JS_NewCFunction(ctx, code_edit_class_get_code_completion_requested_signal, "get_code_completion_requested_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "symbol_lookup"),
		JS_NewCFunction(ctx, code_edit_class_get_symbol_lookup_signal, "get_symbol_lookup_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "symbol_validate"),
		JS_NewCFunction(ctx, code_edit_class_get_symbol_validate_signal, "get_symbol_validate_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "symbol_hovered"),
		JS_NewCFunction(ctx, code_edit_class_get_symbol_hovered_signal, "get_symbol_hovered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_code_edit_enum(JSContext *ctx, JSValue ctor) {
	JSValue CodeCompletionKind_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_CLASS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_FUNCTION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_SIGNAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_VARIABLE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_MEMBER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_ENUM", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_CONSTANT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_NODE_PATH", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_FILE_PATH", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "KIND_PLAIN_TEXT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, ctor, "CodeCompletionKind", CodeCompletionKind_obj);
	JSValue CodeCompletionLocation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_LOCAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_PARENT_MASK", JS_NewInt64(ctx, 256));
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_OTHER_USER_CODE", JS_NewInt64(ctx, 512));
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_OTHER", JS_NewInt64(ctx, 1024));
	JS_SetPropertyStr(ctx, ctor, "CodeCompletionLocation", CodeCompletionLocation_obj);
}

static int js_code_edit_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CodeEdit"] = class_id;
	classes_by_id[class_id] = "CodeEdit";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &code_edit_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["TextEdit"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_code_edit_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, code_edit_class_proto_funcs, _countof(code_edit_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, code_edit_class_constructor, "CodeEdit", 0, JS_CFUNC_constructor, 0);
	define_code_edit_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CodeEdit", ctor);
	ctor_list["CodeEdit"] = ctor;

	return 0;
}

JSModuleDef *_js_init_code_edit_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/text_edit';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_code_edit_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CodeEdit");
	return m;
}

JSModuleDef *js_init_code_edit_module(JSContext *ctx) {
	return _js_init_code_edit_module(ctx, "@godot/classes/code_edit");
}

void __register_code_edit() {
	js_init_code_edit_module(js_context());
}

void register_code_edit() {
	__register_code_edit();
}