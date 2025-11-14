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
#include <godot_cpp/classes/text_line.hpp>
using namespace godot;

static void text_line_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TextLine"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef text_line_class_def = {
    "TextLine",
    text_line_class_finalizer
};

static JSValue text_line_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TextLine"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TextLine *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TextLine *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TextLine);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue text_line_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::clear, ctx, this_val, argc, argv);
};
static JSValue text_line_class_set_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_direction, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_direction, ctx, this_val, argc, argv);
}
static JSValue text_line_class_get_inferred_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_inferred_direction, ctx, this_val, argc, argv);
};
static JSValue text_line_class_set_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_orientation, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_orientation, ctx, this_val, argc, argv);
}
static JSValue text_line_class_set_preserve_invalid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_preserve_invalid, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_preserve_invalid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_preserve_invalid, ctx, this_val, argc, argv);
}
static JSValue text_line_class_set_preserve_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_preserve_control, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_preserve_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_preserve_control, ctx, this_val, argc, argv);
}
static JSValue text_line_class_set_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_bidi_override, ctx, this_val, argc, argv);
};
static JSValue text_line_class_add_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextLine::add_string, ctx, this_val, argc, argv);
};
static JSValue text_line_class_add_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextLine::add_object, ctx, this_val, argc, argv);
};
static JSValue text_line_class_resize_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextLine::resize_object, ctx, this_val, argc, argv);
};
static JSValue text_line_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_width, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_width, ctx, this_val, argc, argv);
}
static JSValue text_line_class_set_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_horizontal_alignment, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_horizontal_alignment, ctx, this_val, argc, argv);
}
static JSValue text_line_class_tab_align(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::tab_align, ctx, this_val, argc, argv);
};
static JSValue text_line_class_set_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_flags, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_flags, ctx, this_val, argc, argv);
}
static JSValue text_line_class_set_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_text_overrun_behavior, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_text_overrun_behavior, ctx, this_val, argc, argv);
}
static JSValue text_line_class_set_ellipsis_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextLine::set_ellipsis_char, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_ellipsis_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		TextLine *obj = static_cast<TextLine *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_ellipsis_char();
	};
	proxy->setter = [this_val](const String &value) -> void {
		TextLine *js_proxy = static_cast<TextLine *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_ellipsis_char(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue text_line_class_get_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_objects, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_object_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_object_rect, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_size, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_rid, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_line_ascent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_line_ascent, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_line_descent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_line_descent, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_line_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_line_width, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_line_underline_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_line_underline_position, ctx, this_val, argc, argv);
};
static JSValue text_line_class_get_line_underline_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::get_line_underline_thickness, ctx, this_val, argc, argv);
};
static JSValue text_line_class_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextLine::draw, ctx, this_val, argc, argv);
};
static JSValue text_line_class_draw_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&TextLine::draw_outline, ctx, this_val, argc, argv);
};
static JSValue text_line_class_hit_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextLine::hit_test, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry text_line_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &text_line_class_clear),
	JS_CFUNC_DEF("set_direction", 1, &text_line_class_set_direction),
	JS_CFUNC_DEF("get_direction", 0, &text_line_class_get_direction),
	JS_CFUNC_DEF("get_inferred_direction", 0, &text_line_class_get_inferred_direction),
	JS_CFUNC_DEF("set_orientation", 1, &text_line_class_set_orientation),
	JS_CFUNC_DEF("get_orientation", 0, &text_line_class_get_orientation),
	JS_CFUNC_DEF("set_preserve_invalid", 1, &text_line_class_set_preserve_invalid),
	JS_CFUNC_DEF("get_preserve_invalid", 0, &text_line_class_get_preserve_invalid),
	JS_CFUNC_DEF("set_preserve_control", 1, &text_line_class_set_preserve_control),
	JS_CFUNC_DEF("get_preserve_control", 0, &text_line_class_get_preserve_control),
	JS_CFUNC_DEF("set_bidi_override", 1, &text_line_class_set_bidi_override),
	JS_CFUNC_DEF("add_string", 5, &text_line_class_add_string),
	JS_CFUNC_DEF("add_object", 5, &text_line_class_add_object),
	JS_CFUNC_DEF("resize_object", 4, &text_line_class_resize_object),
	JS_CFUNC_DEF("set_width", 1, &text_line_class_set_width),
	JS_CFUNC_DEF("get_width", 0, &text_line_class_get_width),
	JS_CFUNC_DEF("set_horizontal_alignment", 1, &text_line_class_set_horizontal_alignment),
	JS_CFUNC_DEF("get_horizontal_alignment", 0, &text_line_class_get_horizontal_alignment),
	JS_CFUNC_DEF("tab_align", 1, &text_line_class_tab_align),
	JS_CFUNC_DEF("set_flags", 1, &text_line_class_set_flags),
	JS_CFUNC_DEF("get_flags", 0, &text_line_class_get_flags),
	JS_CFUNC_DEF("set_text_overrun_behavior", 1, &text_line_class_set_text_overrun_behavior),
	JS_CFUNC_DEF("get_text_overrun_behavior", 0, &text_line_class_get_text_overrun_behavior),
	JS_CFUNC_DEF("set_ellipsis_char", 1, &text_line_class_set_ellipsis_char),
	JS_CFUNC_DEF("get_ellipsis_char", 0, &text_line_class_get_ellipsis_char),
	JS_CFUNC_DEF("get_objects", 0, &text_line_class_get_objects),
	JS_CFUNC_DEF("get_object_rect", 1, &text_line_class_get_object_rect),
	JS_CFUNC_DEF("get_size", 0, &text_line_class_get_size),
	JS_CFUNC_DEF("get_rid", 0, &text_line_class_get_rid),
	JS_CFUNC_DEF("get_line_ascent", 0, &text_line_class_get_line_ascent),
	JS_CFUNC_DEF("get_line_descent", 0, &text_line_class_get_line_descent),
	JS_CFUNC_DEF("get_line_width", 0, &text_line_class_get_line_width),
	JS_CFUNC_DEF("get_line_underline_position", 0, &text_line_class_get_line_underline_position),
	JS_CFUNC_DEF("get_line_underline_thickness", 0, &text_line_class_get_line_underline_thickness),
	JS_CFUNC_DEF("draw", 4, &text_line_class_draw),
	JS_CFUNC_DEF("draw_outline", 5, &text_line_class_draw_outline),
	JS_CFUNC_DEF("hit_test", 1, &text_line_class_hit_test),
};




static void define_text_line_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "direction"),
        JS_NewCFunction(ctx, text_line_class_get_direction, "get_direction", 0),
        JS_NewCFunction(ctx, text_line_class_set_direction, "set_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "orientation"),
        JS_NewCFunction(ctx, text_line_class_get_orientation, "get_orientation", 0),
        JS_NewCFunction(ctx, text_line_class_set_orientation, "set_orientation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preserve_invalid"),
        JS_NewCFunction(ctx, text_line_class_get_preserve_invalid, "get_preserve_invalid", 0),
        JS_NewCFunction(ctx, text_line_class_set_preserve_invalid, "set_preserve_invalid", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preserve_control"),
        JS_NewCFunction(ctx, text_line_class_get_preserve_control, "get_preserve_control", 0),
        JS_NewCFunction(ctx, text_line_class_set_preserve_control, "set_preserve_control", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_NewCFunction(ctx, text_line_class_get_width, "get_width", 0),
        JS_NewCFunction(ctx, text_line_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alignment"),
        JS_NewCFunction(ctx, text_line_class_get_horizontal_alignment, "get_horizontal_alignment", 0),
        JS_NewCFunction(ctx, text_line_class_set_horizontal_alignment, "set_horizontal_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flags"),
        JS_NewCFunction(ctx, text_line_class_get_flags, "get_flags", 0),
        JS_NewCFunction(ctx, text_line_class_set_flags, "set_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_overrun_behavior"),
        JS_NewCFunction(ctx, text_line_class_get_text_overrun_behavior, "get_text_overrun_behavior", 0),
        JS_NewCFunction(ctx, text_line_class_set_text_overrun_behavior, "set_text_overrun_behavior", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ellipsis_char"),
        JS_NewCFunction(ctx, text_line_class_get_ellipsis_char, "get_ellipsis_char", 0),
        JS_NewCFunction(ctx, text_line_class_set_ellipsis_char, "set_ellipsis_char", 1),
        JS_PROP_GETSET
    );
}

static void define_text_line_enum(JSContext *ctx, JSValue proto) {
}

static int js_text_line_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TextLine"] = class_id;
	classes_by_id[class_id] = "TextLine";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &text_line_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_text_line_property(ctx, proto);
	define_text_line_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, text_line_class_proto_funcs, _countof(text_line_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, text_line_class_constructor, "TextLine", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TextLine", ctor);

	return 0;
}

JSModuleDef *_js_init_text_line_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_text_line_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TextLine");
	return m;
}

JSModuleDef *js_init_text_line_module(JSContext *ctx) {
	return _js_init_text_line_module(ctx, "@godot/classes/text_line");
}

void __register_text_line() {
	js_init_text_line_module(js_context());
}

void register_text_line() {
	__register_text_line();
}