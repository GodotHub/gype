#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/text_paragraph.hpp>
using namespace godot;

static void text_paragraph_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TextParagraph"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef text_paragraph_class_def = {
    "TextParagraph",
    text_paragraph_class_finalizer
};

static JSValue text_paragraph_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TextParagraph"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TextParagraph *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TextParagraph *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TextParagraph);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue text_paragraph_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::clear, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_set_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_direction, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_direction, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_get_inferred_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_inferred_direction, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_set_custom_punctuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_custom_punctuation, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_custom_punctuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_custom_punctuation, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_orientation, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_orientation, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_preserve_invalid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_preserve_invalid, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_preserve_invalid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_preserve_invalid, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_preserve_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_preserve_control, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_preserve_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_preserve_control, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_bidi_override, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_set_dropcap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextParagraph::set_dropcap, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_clear_dropcap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::clear_dropcap, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_add_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextParagraph::add_string, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_add_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextParagraph::add_object, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_resize_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextParagraph::resize_object, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_set_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_alignment, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_alignment, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_tab_align(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::tab_align, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_set_break_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_break_flags, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_break_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_break_flags, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_justification_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_justification_flags, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_justification_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_justification_flags, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_text_overrun_behavior, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_text_overrun_behavior, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_ellipsis_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_ellipsis_char, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_ellipsis_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_ellipsis_char, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_width, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_width, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_get_non_wrapped_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_non_wrapped_size, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_size, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_rid, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_rid, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_dropcap_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_dropcap_rid, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_range, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_count, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_set_max_lines_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_max_lines_visible, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_max_lines_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_max_lines_visible, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_set_line_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextParagraph::set_line_spacing, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_spacing, ctx, this_val, argc, argv);
}
static JSValue text_paragraph_class_get_line_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_objects, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_object_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_object_rect, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_size, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_range, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_ascent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_ascent, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_descent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_descent, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_width, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_underline_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_underline_position, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_line_underline_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_line_underline_thickness, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_dropcap_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_dropcap_size, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_get_dropcap_lines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::get_dropcap_lines, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextParagraph::draw, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_draw_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextParagraph::draw_outline, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_draw_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextParagraph::draw_line, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_draw_line_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextParagraph::draw_line_outline, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_draw_dropcap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextParagraph::draw_dropcap, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_draw_dropcap_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextParagraph::draw_dropcap_outline, ctx, this_val, argc, argv);
};
static JSValue text_paragraph_class_hit_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextParagraph::hit_test, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry text_paragraph_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &text_paragraph_class_clear),
	JS_CFUNC_DEF("set_direction", 1, &text_paragraph_class_set_direction),
	JS_CFUNC_DEF("get_direction", 0, &text_paragraph_class_get_direction),
	JS_CFUNC_DEF("get_inferred_direction", 0, &text_paragraph_class_get_inferred_direction),
	JS_CFUNC_DEF("set_custom_punctuation", 1, &text_paragraph_class_set_custom_punctuation),
	JS_CFUNC_DEF("get_custom_punctuation", 0, &text_paragraph_class_get_custom_punctuation),
	JS_CFUNC_DEF("set_orientation", 1, &text_paragraph_class_set_orientation),
	JS_CFUNC_DEF("get_orientation", 0, &text_paragraph_class_get_orientation),
	JS_CFUNC_DEF("set_preserve_invalid", 1, &text_paragraph_class_set_preserve_invalid),
	JS_CFUNC_DEF("get_preserve_invalid", 0, &text_paragraph_class_get_preserve_invalid),
	JS_CFUNC_DEF("set_preserve_control", 1, &text_paragraph_class_set_preserve_control),
	JS_CFUNC_DEF("get_preserve_control", 0, &text_paragraph_class_get_preserve_control),
	JS_CFUNC_DEF("set_bidi_override", 1, &text_paragraph_class_set_bidi_override),
	JS_CFUNC_DEF("set_dropcap", 5, &text_paragraph_class_set_dropcap),
	JS_CFUNC_DEF("clear_dropcap", 0, &text_paragraph_class_clear_dropcap),
	JS_CFUNC_DEF("add_string", 5, &text_paragraph_class_add_string),
	JS_CFUNC_DEF("add_object", 5, &text_paragraph_class_add_object),
	JS_CFUNC_DEF("resize_object", 4, &text_paragraph_class_resize_object),
	JS_CFUNC_DEF("set_alignment", 1, &text_paragraph_class_set_alignment),
	JS_CFUNC_DEF("get_alignment", 0, &text_paragraph_class_get_alignment),
	JS_CFUNC_DEF("tab_align", 1, &text_paragraph_class_tab_align),
	JS_CFUNC_DEF("set_break_flags", 1, &text_paragraph_class_set_break_flags),
	JS_CFUNC_DEF("get_break_flags", 0, &text_paragraph_class_get_break_flags),
	JS_CFUNC_DEF("set_justification_flags", 1, &text_paragraph_class_set_justification_flags),
	JS_CFUNC_DEF("get_justification_flags", 0, &text_paragraph_class_get_justification_flags),
	JS_CFUNC_DEF("set_text_overrun_behavior", 1, &text_paragraph_class_set_text_overrun_behavior),
	JS_CFUNC_DEF("get_text_overrun_behavior", 0, &text_paragraph_class_get_text_overrun_behavior),
	JS_CFUNC_DEF("set_ellipsis_char", 1, &text_paragraph_class_set_ellipsis_char),
	JS_CFUNC_DEF("get_ellipsis_char", 0, &text_paragraph_class_get_ellipsis_char),
	JS_CFUNC_DEF("set_width", 1, &text_paragraph_class_set_width),
	JS_CFUNC_DEF("get_width", 0, &text_paragraph_class_get_width),
	JS_CFUNC_DEF("get_non_wrapped_size", 0, &text_paragraph_class_get_non_wrapped_size),
	JS_CFUNC_DEF("get_size", 0, &text_paragraph_class_get_size),
	JS_CFUNC_DEF("get_rid", 0, &text_paragraph_class_get_rid),
	JS_CFUNC_DEF("get_line_rid", 1, &text_paragraph_class_get_line_rid),
	JS_CFUNC_DEF("get_dropcap_rid", 0, &text_paragraph_class_get_dropcap_rid),
	JS_CFUNC_DEF("get_range", 0, &text_paragraph_class_get_range),
	JS_CFUNC_DEF("get_line_count", 0, &text_paragraph_class_get_line_count),
	JS_CFUNC_DEF("set_max_lines_visible", 1, &text_paragraph_class_set_max_lines_visible),
	JS_CFUNC_DEF("get_max_lines_visible", 0, &text_paragraph_class_get_max_lines_visible),
	JS_CFUNC_DEF("set_line_spacing", 1, &text_paragraph_class_set_line_spacing),
	JS_CFUNC_DEF("get_line_spacing", 0, &text_paragraph_class_get_line_spacing),
	JS_CFUNC_DEF("get_line_objects", 1, &text_paragraph_class_get_line_objects),
	JS_CFUNC_DEF("get_line_object_rect", 2, &text_paragraph_class_get_line_object_rect),
	JS_CFUNC_DEF("get_line_size", 1, &text_paragraph_class_get_line_size),
	JS_CFUNC_DEF("get_line_range", 1, &text_paragraph_class_get_line_range),
	JS_CFUNC_DEF("get_line_ascent", 1, &text_paragraph_class_get_line_ascent),
	JS_CFUNC_DEF("get_line_descent", 1, &text_paragraph_class_get_line_descent),
	JS_CFUNC_DEF("get_line_width", 1, &text_paragraph_class_get_line_width),
	JS_CFUNC_DEF("get_line_underline_position", 1, &text_paragraph_class_get_line_underline_position),
	JS_CFUNC_DEF("get_line_underline_thickness", 1, &text_paragraph_class_get_line_underline_thickness),
	JS_CFUNC_DEF("get_dropcap_size", 0, &text_paragraph_class_get_dropcap_size),
	JS_CFUNC_DEF("get_dropcap_lines", 0, &text_paragraph_class_get_dropcap_lines),
	JS_CFUNC_DEF("draw", 5, &text_paragraph_class_draw),
	JS_CFUNC_DEF("draw_outline", 6, &text_paragraph_class_draw_outline),
	JS_CFUNC_DEF("draw_line", 5, &text_paragraph_class_draw_line),
	JS_CFUNC_DEF("draw_line_outline", 6, &text_paragraph_class_draw_line_outline),
	JS_CFUNC_DEF("draw_dropcap", 4, &text_paragraph_class_draw_dropcap),
	JS_CFUNC_DEF("draw_dropcap_outline", 5, &text_paragraph_class_draw_dropcap_outline),
	JS_CFUNC_DEF("hit_test", 1, &text_paragraph_class_hit_test),
};




static void define_text_paragraph_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "direction"),
        JS_NewCFunction(ctx, text_paragraph_class_get_direction, "get_direction", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_direction, "set_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_punctuation"),
        JS_NewCFunction(ctx, text_paragraph_class_get_custom_punctuation, "get_custom_punctuation", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_custom_punctuation, "set_custom_punctuation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "orientation"),
        JS_NewCFunction(ctx, text_paragraph_class_get_orientation, "get_orientation", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_orientation, "set_orientation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preserve_invalid"),
        JS_NewCFunction(ctx, text_paragraph_class_get_preserve_invalid, "get_preserve_invalid", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_preserve_invalid, "set_preserve_invalid", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preserve_control"),
        JS_NewCFunction(ctx, text_paragraph_class_get_preserve_control, "get_preserve_control", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_preserve_control, "set_preserve_control", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alignment"),
        JS_NewCFunction(ctx, text_paragraph_class_get_alignment, "get_alignment", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_alignment, "set_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "break_flags"),
        JS_NewCFunction(ctx, text_paragraph_class_get_break_flags, "get_break_flags", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_break_flags, "set_break_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "justification_flags"),
        JS_NewCFunction(ctx, text_paragraph_class_get_justification_flags, "get_justification_flags", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_justification_flags, "set_justification_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_overrun_behavior"),
        JS_NewCFunction(ctx, text_paragraph_class_get_text_overrun_behavior, "get_text_overrun_behavior", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_text_overrun_behavior, "set_text_overrun_behavior", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ellipsis_char"),
        JS_NewCFunction(ctx, text_paragraph_class_get_ellipsis_char, "get_ellipsis_char", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_ellipsis_char, "set_ellipsis_char", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_NewCFunction(ctx, text_paragraph_class_get_width, "get_width", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_lines_visible"),
        JS_NewCFunction(ctx, text_paragraph_class_get_max_lines_visible, "get_max_lines_visible", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_max_lines_visible, "set_max_lines_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "line_spacing"),
        JS_NewCFunction(ctx, text_paragraph_class_get_line_spacing, "get_line_spacing", 0),
        JS_NewCFunction(ctx, text_paragraph_class_set_line_spacing, "set_line_spacing", 1),
        JS_PROP_GETSET
    );
}

static void define_text_paragraph_enum(JSContext *ctx, JSValue ctor) {
}

static int js_text_paragraph_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TextParagraph"] = class_id;
	classes_by_id[class_id] = "TextParagraph";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &text_paragraph_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_text_paragraph_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, text_paragraph_class_proto_funcs, _countof(text_paragraph_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, text_paragraph_class_constructor, "TextParagraph", 0, JS_CFUNC_constructor, 0);
	define_text_paragraph_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TextParagraph", ctor);

	return 0;
}

JSModuleDef *_js_init_text_paragraph_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_text_paragraph_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TextParagraph");
	return m;
}

JSModuleDef *js_init_text_paragraph_module(JSContext *ctx) {
	return _js_init_text_paragraph_module(ctx, "@godot/classes/text_paragraph");
}

void __register_text_paragraph() {
	js_init_text_paragraph_module(js_context());
}

void register_text_paragraph() {
	__register_text_paragraph();
}