#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/geometry_instance3d.hpp>
#include <godot_cpp/classes/triangle_mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/label3d.hpp>
using namespace godot;

static void label3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Label3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef label3d_class_def = {
    "Label3D",
    label3d_class_finalizer
};

static JSValue label3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Label3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Label3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Label3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Label3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue label3d_class_set_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_horizontal_alignment, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_horizontal_alignment, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_vertical_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_vertical_alignment, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_vertical_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_vertical_alignment, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_modulate, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Label3D *obj = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_modulate();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Label3D *js_proxy = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_modulate(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue label3d_class_set_outline_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_outline_modulate, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_outline_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Label3D *obj = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_outline_modulate();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Label3D *js_proxy = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_outline_modulate(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue label3d_class_set_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_text, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_text, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_text_direction, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_text_direction, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_language, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_language, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_structured_text_bidi_override, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_structured_text_bidi_override, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_structured_text_bidi_override_options, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		Label3D *obj = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_structured_text_bidi_override_options();
	};
	proxy->setter = [this_val](const Array &value) -> void {
		Label3D *js_proxy = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue label3d_class_set_uppercase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_uppercase, ctx, this_val, argc, argv);
};
static JSValue label3d_class_is_uppercase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::is_uppercase, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_render_priority, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_render_priority, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_outline_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_outline_render_priority, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_outline_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_outline_render_priority, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_font, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_font, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_font_size, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_font_size, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_outline_size, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_outline_size, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_line_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_line_spacing, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_line_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_line_spacing, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_autowrap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_autowrap_mode, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_autowrap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_autowrap_mode, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_autowrap_trim_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_autowrap_trim_flags, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_autowrap_trim_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_autowrap_trim_flags, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_justification_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_justification_flags, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_justification_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_justification_flags, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_width, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_width, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_pixel_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_pixel_size, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_pixel_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_pixel_size, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_offset, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Label3D *obj = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Label3D *js_proxy = static_cast<Label3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset(value);
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
static JSValue label3d_class_set_draw_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_draw_flag, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_draw_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_draw_flag, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_billboard_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_billboard_mode, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_billboard_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_billboard_mode, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_alpha_cut_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_alpha_cut_mode, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_alpha_cut_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_alpha_cut_mode, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_alpha_scissor_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_alpha_scissor_threshold, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_alpha_scissor_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_alpha_scissor_threshold, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_alpha_hash_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_alpha_hash_scale, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_alpha_hash_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_alpha_hash_scale, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_alpha_antialiasing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_alpha_antialiasing, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_alpha_antialiasing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_alpha_antialiasing, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_alpha_antialiasing_edge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_alpha_antialiasing_edge, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_alpha_antialiasing_edge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_alpha_antialiasing_edge, ctx, this_val, argc, argv);
}
static JSValue label3d_class_set_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Label3D::set_texture_filter, ctx, this_val, argc, argv);
};
static JSValue label3d_class_get_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::get_texture_filter, ctx, this_val, argc, argv);
}
static JSValue label3d_class_generate_triangle_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Label3D::generate_triangle_mesh, ctx, this_val, argc, argv);
};

static JSValue label3d_class_get_shaded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Label3D::get_draw_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue label3d_class_set_shaded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Label3D::set_draw_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue label3d_class_get_double_sided(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Label3D::get_draw_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue label3d_class_set_double_sided(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Label3D::set_draw_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue label3d_class_get_no_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Label3D::get_draw_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue label3d_class_set_no_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Label3D::set_draw_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue label3d_class_get_fixed_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Label3D::get_draw_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue label3d_class_set_fixed_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Label3D::set_draw_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry label3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_horizontal_alignment", 1, &label3d_class_set_horizontal_alignment),
	JS_CFUNC_DEF("get_horizontal_alignment", 0, &label3d_class_get_horizontal_alignment),
	JS_CFUNC_DEF("set_vertical_alignment", 1, &label3d_class_set_vertical_alignment),
	JS_CFUNC_DEF("get_vertical_alignment", 0, &label3d_class_get_vertical_alignment),
	JS_CFUNC_DEF("set_modulate", 1, &label3d_class_set_modulate),
	JS_CFUNC_DEF("get_modulate", 0, &label3d_class_get_modulate),
	JS_CFUNC_DEF("set_outline_modulate", 1, &label3d_class_set_outline_modulate),
	JS_CFUNC_DEF("get_outline_modulate", 0, &label3d_class_get_outline_modulate),
	JS_CFUNC_DEF("set_text", 1, &label3d_class_set_text),
	JS_CFUNC_DEF("get_text", 0, &label3d_class_get_text),
	JS_CFUNC_DEF("set_text_direction", 1, &label3d_class_set_text_direction),
	JS_CFUNC_DEF("get_text_direction", 0, &label3d_class_get_text_direction),
	JS_CFUNC_DEF("set_language", 1, &label3d_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &label3d_class_get_language),
	JS_CFUNC_DEF("set_structured_text_bidi_override", 1, &label3d_class_set_structured_text_bidi_override),
	JS_CFUNC_DEF("get_structured_text_bidi_override", 0, &label3d_class_get_structured_text_bidi_override),
	JS_CFUNC_DEF("set_structured_text_bidi_override_options", 1, &label3d_class_set_structured_text_bidi_override_options),
	JS_CFUNC_DEF("get_structured_text_bidi_override_options", 0, &label3d_class_get_structured_text_bidi_override_options),
	JS_CFUNC_DEF("set_uppercase", 1, &label3d_class_set_uppercase),
	JS_CFUNC_DEF("is_uppercase", 0, &label3d_class_is_uppercase),
	JS_CFUNC_DEF("set_render_priority", 1, &label3d_class_set_render_priority),
	JS_CFUNC_DEF("get_render_priority", 0, &label3d_class_get_render_priority),
	JS_CFUNC_DEF("set_outline_render_priority", 1, &label3d_class_set_outline_render_priority),
	JS_CFUNC_DEF("get_outline_render_priority", 0, &label3d_class_get_outline_render_priority),
	JS_CFUNC_DEF("set_font", 1, &label3d_class_set_font),
	JS_CFUNC_DEF("get_font", 0, &label3d_class_get_font),
	JS_CFUNC_DEF("set_font_size", 1, &label3d_class_set_font_size),
	JS_CFUNC_DEF("get_font_size", 0, &label3d_class_get_font_size),
	JS_CFUNC_DEF("set_outline_size", 1, &label3d_class_set_outline_size),
	JS_CFUNC_DEF("get_outline_size", 0, &label3d_class_get_outline_size),
	JS_CFUNC_DEF("set_line_spacing", 1, &label3d_class_set_line_spacing),
	JS_CFUNC_DEF("get_line_spacing", 0, &label3d_class_get_line_spacing),
	JS_CFUNC_DEF("set_autowrap_mode", 1, &label3d_class_set_autowrap_mode),
	JS_CFUNC_DEF("get_autowrap_mode", 0, &label3d_class_get_autowrap_mode),
	JS_CFUNC_DEF("set_autowrap_trim_flags", 1, &label3d_class_set_autowrap_trim_flags),
	JS_CFUNC_DEF("get_autowrap_trim_flags", 0, &label3d_class_get_autowrap_trim_flags),
	JS_CFUNC_DEF("set_justification_flags", 1, &label3d_class_set_justification_flags),
	JS_CFUNC_DEF("get_justification_flags", 0, &label3d_class_get_justification_flags),
	JS_CFUNC_DEF("set_width", 1, &label3d_class_set_width),
	JS_CFUNC_DEF("get_width", 0, &label3d_class_get_width),
	JS_CFUNC_DEF("set_pixel_size", 1, &label3d_class_set_pixel_size),
	JS_CFUNC_DEF("get_pixel_size", 0, &label3d_class_get_pixel_size),
	JS_CFUNC_DEF("set_offset", 1, &label3d_class_set_offset),
	JS_CFUNC_DEF("get_offset", 0, &label3d_class_get_offset),
	JS_CFUNC_DEF("set_draw_flag", 2, &label3d_class_set_draw_flag),
	JS_CFUNC_DEF("get_draw_flag", 1, &label3d_class_get_draw_flag),
	JS_CFUNC_DEF("set_billboard_mode", 1, &label3d_class_set_billboard_mode),
	JS_CFUNC_DEF("get_billboard_mode", 0, &label3d_class_get_billboard_mode),
	JS_CFUNC_DEF("set_alpha_cut_mode", 1, &label3d_class_set_alpha_cut_mode),
	JS_CFUNC_DEF("get_alpha_cut_mode", 0, &label3d_class_get_alpha_cut_mode),
	JS_CFUNC_DEF("set_alpha_scissor_threshold", 1, &label3d_class_set_alpha_scissor_threshold),
	JS_CFUNC_DEF("get_alpha_scissor_threshold", 0, &label3d_class_get_alpha_scissor_threshold),
	JS_CFUNC_DEF("set_alpha_hash_scale", 1, &label3d_class_set_alpha_hash_scale),
	JS_CFUNC_DEF("get_alpha_hash_scale", 0, &label3d_class_get_alpha_hash_scale),
	JS_CFUNC_DEF("set_alpha_antialiasing", 1, &label3d_class_set_alpha_antialiasing),
	JS_CFUNC_DEF("get_alpha_antialiasing", 0, &label3d_class_get_alpha_antialiasing),
	JS_CFUNC_DEF("set_alpha_antialiasing_edge", 1, &label3d_class_set_alpha_antialiasing_edge),
	JS_CFUNC_DEF("get_alpha_antialiasing_edge", 0, &label3d_class_get_alpha_antialiasing_edge),
	JS_CFUNC_DEF("set_texture_filter", 1, &label3d_class_set_texture_filter),
	JS_CFUNC_DEF("get_texture_filter", 0, &label3d_class_get_texture_filter),
	JS_CFUNC_DEF("generate_triangle_mesh", 0, &label3d_class_generate_triangle_mesh),
    JS_CFUNC_MAGIC_DEF("get_double_sided", 0, &label3d_class_get_double_sided, 1),
    JS_CFUNC_MAGIC_DEF("set_double_sided", 1, &label3d_class_set_double_sided, 1),
    JS_CFUNC_MAGIC_DEF("get_no_depth_test", 0, &label3d_class_get_no_depth_test, 2),
    JS_CFUNC_MAGIC_DEF("set_no_depth_test", 1, &label3d_class_set_no_depth_test, 2),
    JS_CFUNC_MAGIC_DEF("get_fixed_size", 0, &label3d_class_get_fixed_size, 3),
    JS_CFUNC_MAGIC_DEF("set_fixed_size", 1, &label3d_class_set_fixed_size, 3),
};




static void define_label3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pixel_size"),
        JS_NewCFunction(ctx, label3d_class_get_pixel_size, "get_pixel_size", 0),
        JS_NewCFunction(ctx, label3d_class_set_pixel_size, "set_pixel_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, label3d_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, label3d_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "billboard"),
        JS_NewCFunction(ctx, label3d_class_get_billboard_mode, "get_billboard_mode", 0),
        JS_NewCFunction(ctx, label3d_class_set_billboard_mode, "set_billboard_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "shaded"),
		JS_NewCFunctionMagic(ctx, label3d_class_get_shaded, "get_shaded", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, label3d_class_set_shaded, "set_shaded", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "double_sided"),
		JS_NewCFunctionMagic(ctx, label3d_class_get_double_sided, "get_double_sided", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, label3d_class_set_double_sided, "set_double_sided", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "no_depth_test"),
		JS_NewCFunctionMagic(ctx, label3d_class_get_no_depth_test, "get_no_depth_test", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, label3d_class_set_no_depth_test, "set_no_depth_test", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "fixed_size"),
		JS_NewCFunctionMagic(ctx, label3d_class_get_fixed_size, "get_fixed_size", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, label3d_class_set_fixed_size, "set_fixed_size", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_cut"),
        JS_NewCFunction(ctx, label3d_class_get_alpha_cut_mode, "get_alpha_cut_mode", 0),
        JS_NewCFunction(ctx, label3d_class_set_alpha_cut_mode, "set_alpha_cut_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_scissor_threshold"),
        JS_NewCFunction(ctx, label3d_class_get_alpha_scissor_threshold, "get_alpha_scissor_threshold", 0),
        JS_NewCFunction(ctx, label3d_class_set_alpha_scissor_threshold, "set_alpha_scissor_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_hash_scale"),
        JS_NewCFunction(ctx, label3d_class_get_alpha_hash_scale, "get_alpha_hash_scale", 0),
        JS_NewCFunction(ctx, label3d_class_set_alpha_hash_scale, "set_alpha_hash_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_antialiasing_mode"),
        JS_NewCFunction(ctx, label3d_class_get_alpha_antialiasing, "get_alpha_antialiasing", 0),
        JS_NewCFunction(ctx, label3d_class_set_alpha_antialiasing, "set_alpha_antialiasing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_antialiasing_edge"),
        JS_NewCFunction(ctx, label3d_class_get_alpha_antialiasing_edge, "get_alpha_antialiasing_edge", 0),
        JS_NewCFunction(ctx, label3d_class_set_alpha_antialiasing_edge, "set_alpha_antialiasing_edge", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_filter"),
        JS_NewCFunction(ctx, label3d_class_get_texture_filter, "get_texture_filter", 0),
        JS_NewCFunction(ctx, label3d_class_set_texture_filter, "set_texture_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_priority"),
        JS_NewCFunction(ctx, label3d_class_get_render_priority, "get_render_priority", 0),
        JS_NewCFunction(ctx, label3d_class_set_render_priority, "set_render_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outline_render_priority"),
        JS_NewCFunction(ctx, label3d_class_get_outline_render_priority, "get_outline_render_priority", 0),
        JS_NewCFunction(ctx, label3d_class_set_outline_render_priority, "set_outline_render_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modulate"),
        JS_NewCFunction(ctx, label3d_class_get_modulate, "get_modulate", 0),
        JS_NewCFunction(ctx, label3d_class_set_modulate, "set_modulate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outline_modulate"),
        JS_NewCFunction(ctx, label3d_class_get_outline_modulate, "get_outline_modulate", 0),
        JS_NewCFunction(ctx, label3d_class_set_outline_modulate, "set_outline_modulate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text"),
        JS_NewCFunction(ctx, label3d_class_get_text, "get_text", 0),
        JS_NewCFunction(ctx, label3d_class_set_text, "set_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font"),
        JS_NewCFunction(ctx, label3d_class_get_font, "get_font", 0),
        JS_NewCFunction(ctx, label3d_class_set_font, "set_font", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_size"),
        JS_NewCFunction(ctx, label3d_class_get_font_size, "get_font_size", 0),
        JS_NewCFunction(ctx, label3d_class_set_font_size, "set_font_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outline_size"),
        JS_NewCFunction(ctx, label3d_class_get_outline_size, "get_outline_size", 0),
        JS_NewCFunction(ctx, label3d_class_set_outline_size, "set_outline_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "horizontal_alignment"),
        JS_NewCFunction(ctx, label3d_class_get_horizontal_alignment, "get_horizontal_alignment", 0),
        JS_NewCFunction(ctx, label3d_class_set_horizontal_alignment, "set_horizontal_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertical_alignment"),
        JS_NewCFunction(ctx, label3d_class_get_vertical_alignment, "get_vertical_alignment", 0),
        JS_NewCFunction(ctx, label3d_class_set_vertical_alignment, "set_vertical_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uppercase"),
        JS_NewCFunction(ctx, label3d_class_is_uppercase, "is_uppercase", 0),
        JS_NewCFunction(ctx, label3d_class_set_uppercase, "set_uppercase", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "line_spacing"),
        JS_NewCFunction(ctx, label3d_class_get_line_spacing, "get_line_spacing", 0),
        JS_NewCFunction(ctx, label3d_class_set_line_spacing, "set_line_spacing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autowrap_mode"),
        JS_NewCFunction(ctx, label3d_class_get_autowrap_mode, "get_autowrap_mode", 0),
        JS_NewCFunction(ctx, label3d_class_set_autowrap_mode, "set_autowrap_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autowrap_trim_flags"),
        JS_NewCFunction(ctx, label3d_class_get_autowrap_trim_flags, "get_autowrap_trim_flags", 0),
        JS_NewCFunction(ctx, label3d_class_set_autowrap_trim_flags, "set_autowrap_trim_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "justification_flags"),
        JS_NewCFunction(ctx, label3d_class_get_justification_flags, "get_justification_flags", 0),
        JS_NewCFunction(ctx, label3d_class_set_justification_flags, "set_justification_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_NewCFunction(ctx, label3d_class_get_width, "get_width", 0),
        JS_NewCFunction(ctx, label3d_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_direction"),
        JS_NewCFunction(ctx, label3d_class_get_text_direction, "get_text_direction", 0),
        JS_NewCFunction(ctx, label3d_class_set_text_direction, "set_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, label3d_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, label3d_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override"),
        JS_NewCFunction(ctx, label3d_class_get_structured_text_bidi_override, "get_structured_text_bidi_override", 0),
        JS_NewCFunction(ctx, label3d_class_set_structured_text_bidi_override, "set_structured_text_bidi_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override_options"),
        JS_NewCFunction(ctx, label3d_class_get_structured_text_bidi_override_options, "get_structured_text_bidi_override_options", 0),
        JS_NewCFunction(ctx, label3d_class_set_structured_text_bidi_override_options, "set_structured_text_bidi_override_options", 1),
        JS_PROP_GETSET
    );
}

static void define_label3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue DrawFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DrawFlags_obj, "FLAG_SHADED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "FLAG_DOUBLE_SIDED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "FLAG_DISABLE_DEPTH_TEST", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "FLAG_FIXED_SIZE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "FLAG_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "DrawFlags", DrawFlags_obj);
	JSValue AlphaCutMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AlphaCutMode_obj, "ALPHA_CUT_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AlphaCutMode_obj, "ALPHA_CUT_DISCARD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AlphaCutMode_obj, "ALPHA_CUT_OPAQUE_PREPASS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, AlphaCutMode_obj, "ALPHA_CUT_HASH", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "AlphaCutMode", AlphaCutMode_obj);
}

static int js_label3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Label3D"] = class_id;
	classes_by_id[class_id] = "Label3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &label3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GeometryInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_label3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, label3d_class_proto_funcs, _countof(label3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, label3d_class_constructor, "Label3D", 0, JS_CFUNC_constructor, 0);
	define_label3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Label3D", ctor);

	return 0;
}

JSModuleDef *_js_init_label3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/geometry_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_label3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Label3D");
	return m;
}

JSModuleDef *js_init_label3d_module(JSContext *ctx) {
	return _js_init_label3d_module(ctx, "@godot/classes/label3d");
}

void __register_label3d() {
	js_init_label3d_module(js_context());
}

void register_label3d() {
	__register_label3d();
}