#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/font_file.hpp>
using namespace godot;

static void font_file_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FontFile"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef font_file_class_def = {
    "FontFile",
    font_file_class_finalizer
};

static JSValue font_file_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FontFile"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FontFile *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FontFile *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FontFile);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue font_file_class_load_bitmap_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FontFile::load_bitmap_font, ctx, this_val, argc, argv);
};
static JSValue font_file_class_load_dynamic_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FontFile::load_dynamic_font, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_data, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedByteArray> *proxy = memnew(ObjectProxy<PackedByteArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedByteArray {
		FontFile *obj = static_cast<FontFile *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_data();
	};
	proxy->setter = [this_val](const PackedByteArray &value) -> void {
		FontFile *js_proxy = static_cast<FontFile *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_data(PackedByteArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedByteArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedByteArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue font_file_class_set_font_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_font_name, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_font_style_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_font_style_name, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_font_style(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_font_style, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_font_weight(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_font_weight, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_font_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_font_stretch, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_antialiasing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_antialiasing, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_antialiasing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_antialiasing, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_disable_embedded_bitmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_disable_embedded_bitmaps, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_disable_embedded_bitmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_disable_embedded_bitmaps, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_generate_mipmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_generate_mipmaps, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_generate_mipmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_generate_mipmaps, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_multichannel_signed_distance_field(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_multichannel_signed_distance_field, ctx, this_val, argc, argv);
};
static JSValue font_file_class_is_multichannel_signed_distance_field(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::is_multichannel_signed_distance_field, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_msdf_pixel_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_msdf_pixel_range, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_msdf_pixel_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_msdf_pixel_range, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_msdf_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_msdf_size, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_msdf_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_msdf_size, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_fixed_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_fixed_size, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_fixed_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_fixed_size, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_fixed_size_scale_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_fixed_size_scale_mode, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_fixed_size_scale_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_fixed_size_scale_mode, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_allow_system_fallback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_allow_system_fallback, ctx, this_val, argc, argv);
};
static JSValue font_file_class_is_allow_system_fallback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::is_allow_system_fallback, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_force_autohinter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_force_autohinter, ctx, this_val, argc, argv);
};
static JSValue font_file_class_is_force_autohinter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::is_force_autohinter, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_modulate_color_glyphs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_modulate_color_glyphs, ctx, this_val, argc, argv);
};
static JSValue font_file_class_is_modulate_color_glyphs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::is_modulate_color_glyphs, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_hinting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_hinting, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_hinting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_hinting, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_subpixel_positioning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_subpixel_positioning, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_subpixel_positioning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_subpixel_positioning, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_keep_rounding_remainders(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_keep_rounding_remainders, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_keep_rounding_remainders(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_keep_rounding_remainders, ctx, this_val, argc, argv);
}
static JSValue font_file_class_set_oversampling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_oversampling, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_oversampling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_oversampling, ctx, this_val, argc, argv);
}
static JSValue font_file_class_get_cache_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_cache_count, ctx, this_val, argc, argv);
};
static JSValue font_file_class_clear_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::clear_cache, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_cache, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_size_cache_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_size_cache_list, ctx, this_val, argc, argv);
};
static JSValue font_file_class_clear_size_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::clear_size_cache, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_size_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_size_cache, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_variation_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_variation_coordinates, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_variation_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_variation_coordinates, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_embolden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_embolden, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_embolden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_embolden, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_transform, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_transform, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_extra_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_extra_spacing, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_extra_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_extra_spacing, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_extra_baseline_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_extra_baseline_offset, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_extra_baseline_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_extra_baseline_offset, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_face_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_face_index, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_face_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_face_index, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_cache_ascent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_cache_ascent, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_cache_ascent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_cache_ascent, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_cache_descent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_cache_descent, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_cache_descent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_cache_descent, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_cache_underline_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_cache_underline_position, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_cache_underline_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_cache_underline_position, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_cache_underline_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_cache_underline_thickness, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_cache_underline_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_cache_underline_thickness, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_cache_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_cache_scale, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_cache_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_cache_scale, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_texture_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_texture_count, ctx, this_val, argc, argv);
};
static JSValue font_file_class_clear_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::clear_textures, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_texture, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_texture_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_texture_image, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_texture_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_texture_image, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_texture_offsets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_texture_offsets, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_texture_offsets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_texture_offsets, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_glyph_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_list, ctx, this_val, argc, argv);
};
static JSValue font_file_class_clear_glyphs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::clear_glyphs, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_glyph(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_glyph, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_glyph_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_glyph_advance, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_glyph_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_advance, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_glyph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_glyph_offset, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_glyph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_offset, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_glyph_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_glyph_size, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_glyph_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_size, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_glyph_uv_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_glyph_uv_rect, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_glyph_uv_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_uv_rect, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_glyph_texture_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_glyph_texture_idx, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_glyph_texture_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_texture_idx, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_kerning_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_kerning_list, ctx, this_val, argc, argv);
};
static JSValue font_file_class_clear_kerning_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::clear_kerning_map, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_kerning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_kerning, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_kerning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_kerning, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_kerning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_kerning, ctx, this_val, argc, argv);
};
static JSValue font_file_class_render_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::render_range, ctx, this_val, argc, argv);
};
static JSValue font_file_class_render_glyph(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::render_glyph, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_language_support_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_language_support_override, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_language_support_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_language_support_override, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_language_support_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_language_support_override, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_language_support_overrides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_language_support_overrides, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_script_support_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_script_support_override, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_script_support_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_script_support_override, ctx, this_val, argc, argv);
};
static JSValue font_file_class_remove_script_support_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::remove_script_support_override, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_script_support_overrides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_script_support_overrides, ctx, this_val, argc, argv);
};
static JSValue font_file_class_set_opentype_feature_overrides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontFile::set_opentype_feature_overrides, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_opentype_feature_overrides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		FontFile *obj = static_cast<FontFile *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_opentype_feature_overrides();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		FontFile *js_proxy = static_cast<FontFile *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_opentype_feature_overrides(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue font_file_class_get_glyph_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_glyph_index, ctx, this_val, argc, argv);
};
static JSValue font_file_class_get_char_from_glyph_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontFile::get_char_from_glyph_index, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry font_file_class_proto_funcs[] = {
	JS_CFUNC_DEF("load_bitmap_font", 1, &font_file_class_load_bitmap_font),
	JS_CFUNC_DEF("load_dynamic_font", 1, &font_file_class_load_dynamic_font),
	JS_CFUNC_DEF("set_data", 1, &font_file_class_set_data),
	JS_CFUNC_DEF("get_data", 0, &font_file_class_get_data),
	JS_CFUNC_DEF("set_font_name", 1, &font_file_class_set_font_name),
	JS_CFUNC_DEF("set_font_style_name", 1, &font_file_class_set_font_style_name),
	JS_CFUNC_DEF("set_font_style", 1, &font_file_class_set_font_style),
	JS_CFUNC_DEF("set_font_weight", 1, &font_file_class_set_font_weight),
	JS_CFUNC_DEF("set_font_stretch", 1, &font_file_class_set_font_stretch),
	JS_CFUNC_DEF("set_antialiasing", 1, &font_file_class_set_antialiasing),
	JS_CFUNC_DEF("get_antialiasing", 0, &font_file_class_get_antialiasing),
	JS_CFUNC_DEF("set_disable_embedded_bitmaps", 1, &font_file_class_set_disable_embedded_bitmaps),
	JS_CFUNC_DEF("get_disable_embedded_bitmaps", 0, &font_file_class_get_disable_embedded_bitmaps),
	JS_CFUNC_DEF("set_generate_mipmaps", 1, &font_file_class_set_generate_mipmaps),
	JS_CFUNC_DEF("get_generate_mipmaps", 0, &font_file_class_get_generate_mipmaps),
	JS_CFUNC_DEF("set_multichannel_signed_distance_field", 1, &font_file_class_set_multichannel_signed_distance_field),
	JS_CFUNC_DEF("is_multichannel_signed_distance_field", 0, &font_file_class_is_multichannel_signed_distance_field),
	JS_CFUNC_DEF("set_msdf_pixel_range", 1, &font_file_class_set_msdf_pixel_range),
	JS_CFUNC_DEF("get_msdf_pixel_range", 0, &font_file_class_get_msdf_pixel_range),
	JS_CFUNC_DEF("set_msdf_size", 1, &font_file_class_set_msdf_size),
	JS_CFUNC_DEF("get_msdf_size", 0, &font_file_class_get_msdf_size),
	JS_CFUNC_DEF("set_fixed_size", 1, &font_file_class_set_fixed_size),
	JS_CFUNC_DEF("get_fixed_size", 0, &font_file_class_get_fixed_size),
	JS_CFUNC_DEF("set_fixed_size_scale_mode", 1, &font_file_class_set_fixed_size_scale_mode),
	JS_CFUNC_DEF("get_fixed_size_scale_mode", 0, &font_file_class_get_fixed_size_scale_mode),
	JS_CFUNC_DEF("set_allow_system_fallback", 1, &font_file_class_set_allow_system_fallback),
	JS_CFUNC_DEF("is_allow_system_fallback", 0, &font_file_class_is_allow_system_fallback),
	JS_CFUNC_DEF("set_force_autohinter", 1, &font_file_class_set_force_autohinter),
	JS_CFUNC_DEF("is_force_autohinter", 0, &font_file_class_is_force_autohinter),
	JS_CFUNC_DEF("set_modulate_color_glyphs", 1, &font_file_class_set_modulate_color_glyphs),
	JS_CFUNC_DEF("is_modulate_color_glyphs", 0, &font_file_class_is_modulate_color_glyphs),
	JS_CFUNC_DEF("set_hinting", 1, &font_file_class_set_hinting),
	JS_CFUNC_DEF("get_hinting", 0, &font_file_class_get_hinting),
	JS_CFUNC_DEF("set_subpixel_positioning", 1, &font_file_class_set_subpixel_positioning),
	JS_CFUNC_DEF("get_subpixel_positioning", 0, &font_file_class_get_subpixel_positioning),
	JS_CFUNC_DEF("set_keep_rounding_remainders", 1, &font_file_class_set_keep_rounding_remainders),
	JS_CFUNC_DEF("get_keep_rounding_remainders", 0, &font_file_class_get_keep_rounding_remainders),
	JS_CFUNC_DEF("set_oversampling", 1, &font_file_class_set_oversampling),
	JS_CFUNC_DEF("get_oversampling", 0, &font_file_class_get_oversampling),
	JS_CFUNC_DEF("get_cache_count", 0, &font_file_class_get_cache_count),
	JS_CFUNC_DEF("clear_cache", 0, &font_file_class_clear_cache),
	JS_CFUNC_DEF("remove_cache", 1, &font_file_class_remove_cache),
	JS_CFUNC_DEF("get_size_cache_list", 1, &font_file_class_get_size_cache_list),
	JS_CFUNC_DEF("clear_size_cache", 1, &font_file_class_clear_size_cache),
	JS_CFUNC_DEF("remove_size_cache", 2, &font_file_class_remove_size_cache),
	JS_CFUNC_DEF("set_variation_coordinates", 2, &font_file_class_set_variation_coordinates),
	JS_CFUNC_DEF("get_variation_coordinates", 1, &font_file_class_get_variation_coordinates),
	JS_CFUNC_DEF("set_embolden", 2, &font_file_class_set_embolden),
	JS_CFUNC_DEF("get_embolden", 1, &font_file_class_get_embolden),
	JS_CFUNC_DEF("set_transform", 2, &font_file_class_set_transform),
	JS_CFUNC_DEF("get_transform", 1, &font_file_class_get_transform),
	JS_CFUNC_DEF("set_extra_spacing", 3, &font_file_class_set_extra_spacing),
	JS_CFUNC_DEF("get_extra_spacing", 2, &font_file_class_get_extra_spacing),
	JS_CFUNC_DEF("set_extra_baseline_offset", 2, &font_file_class_set_extra_baseline_offset),
	JS_CFUNC_DEF("get_extra_baseline_offset", 1, &font_file_class_get_extra_baseline_offset),
	JS_CFUNC_DEF("set_face_index", 2, &font_file_class_set_face_index),
	JS_CFUNC_DEF("get_face_index", 1, &font_file_class_get_face_index),
	JS_CFUNC_DEF("set_cache_ascent", 3, &font_file_class_set_cache_ascent),
	JS_CFUNC_DEF("get_cache_ascent", 2, &font_file_class_get_cache_ascent),
	JS_CFUNC_DEF("set_cache_descent", 3, &font_file_class_set_cache_descent),
	JS_CFUNC_DEF("get_cache_descent", 2, &font_file_class_get_cache_descent),
	JS_CFUNC_DEF("set_cache_underline_position", 3, &font_file_class_set_cache_underline_position),
	JS_CFUNC_DEF("get_cache_underline_position", 2, &font_file_class_get_cache_underline_position),
	JS_CFUNC_DEF("set_cache_underline_thickness", 3, &font_file_class_set_cache_underline_thickness),
	JS_CFUNC_DEF("get_cache_underline_thickness", 2, &font_file_class_get_cache_underline_thickness),
	JS_CFUNC_DEF("set_cache_scale", 3, &font_file_class_set_cache_scale),
	JS_CFUNC_DEF("get_cache_scale", 2, &font_file_class_get_cache_scale),
	JS_CFUNC_DEF("get_texture_count", 2, &font_file_class_get_texture_count),
	JS_CFUNC_DEF("clear_textures", 2, &font_file_class_clear_textures),
	JS_CFUNC_DEF("remove_texture", 3, &font_file_class_remove_texture),
	JS_CFUNC_DEF("set_texture_image", 4, &font_file_class_set_texture_image),
	JS_CFUNC_DEF("get_texture_image", 3, &font_file_class_get_texture_image),
	JS_CFUNC_DEF("set_texture_offsets", 4, &font_file_class_set_texture_offsets),
	JS_CFUNC_DEF("get_texture_offsets", 3, &font_file_class_get_texture_offsets),
	JS_CFUNC_DEF("get_glyph_list", 2, &font_file_class_get_glyph_list),
	JS_CFUNC_DEF("clear_glyphs", 2, &font_file_class_clear_glyphs),
	JS_CFUNC_DEF("remove_glyph", 3, &font_file_class_remove_glyph),
	JS_CFUNC_DEF("set_glyph_advance", 4, &font_file_class_set_glyph_advance),
	JS_CFUNC_DEF("get_glyph_advance", 3, &font_file_class_get_glyph_advance),
	JS_CFUNC_DEF("set_glyph_offset", 4, &font_file_class_set_glyph_offset),
	JS_CFUNC_DEF("get_glyph_offset", 3, &font_file_class_get_glyph_offset),
	JS_CFUNC_DEF("set_glyph_size", 4, &font_file_class_set_glyph_size),
	JS_CFUNC_DEF("get_glyph_size", 3, &font_file_class_get_glyph_size),
	JS_CFUNC_DEF("set_glyph_uv_rect", 4, &font_file_class_set_glyph_uv_rect),
	JS_CFUNC_DEF("get_glyph_uv_rect", 3, &font_file_class_get_glyph_uv_rect),
	JS_CFUNC_DEF("set_glyph_texture_idx", 4, &font_file_class_set_glyph_texture_idx),
	JS_CFUNC_DEF("get_glyph_texture_idx", 3, &font_file_class_get_glyph_texture_idx),
	JS_CFUNC_DEF("get_kerning_list", 2, &font_file_class_get_kerning_list),
	JS_CFUNC_DEF("clear_kerning_map", 2, &font_file_class_clear_kerning_map),
	JS_CFUNC_DEF("remove_kerning", 3, &font_file_class_remove_kerning),
	JS_CFUNC_DEF("set_kerning", 4, &font_file_class_set_kerning),
	JS_CFUNC_DEF("get_kerning", 3, &font_file_class_get_kerning),
	JS_CFUNC_DEF("render_range", 4, &font_file_class_render_range),
	JS_CFUNC_DEF("render_glyph", 3, &font_file_class_render_glyph),
	JS_CFUNC_DEF("set_language_support_override", 2, &font_file_class_set_language_support_override),
	JS_CFUNC_DEF("get_language_support_override", 1, &font_file_class_get_language_support_override),
	JS_CFUNC_DEF("remove_language_support_override", 1, &font_file_class_remove_language_support_override),
	JS_CFUNC_DEF("get_language_support_overrides", 0, &font_file_class_get_language_support_overrides),
	JS_CFUNC_DEF("set_script_support_override", 2, &font_file_class_set_script_support_override),
	JS_CFUNC_DEF("get_script_support_override", 1, &font_file_class_get_script_support_override),
	JS_CFUNC_DEF("remove_script_support_override", 1, &font_file_class_remove_script_support_override),
	JS_CFUNC_DEF("get_script_support_overrides", 0, &font_file_class_get_script_support_overrides),
	JS_CFUNC_DEF("set_opentype_feature_overrides", 1, &font_file_class_set_opentype_feature_overrides),
	JS_CFUNC_DEF("get_opentype_feature_overrides", 0, &font_file_class_get_opentype_feature_overrides),
	JS_CFUNC_DEF("get_glyph_index", 3, &font_file_class_get_glyph_index),
	JS_CFUNC_DEF("get_char_from_glyph_index", 2, &font_file_class_get_char_from_glyph_index),
};




static void define_font_file_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "data"),
        JS_NewCFunction(ctx, font_file_class_get_data, "get_data", 0),
        JS_NewCFunction(ctx, font_file_class_set_data, "set_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "generate_mipmaps"),
        JS_NewCFunction(ctx, font_file_class_get_generate_mipmaps, "get_generate_mipmaps", 0),
        JS_NewCFunction(ctx, font_file_class_set_generate_mipmaps, "set_generate_mipmaps", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "disable_embedded_bitmaps"),
        JS_NewCFunction(ctx, font_file_class_get_disable_embedded_bitmaps, "get_disable_embedded_bitmaps", 0),
        JS_NewCFunction(ctx, font_file_class_set_disable_embedded_bitmaps, "set_disable_embedded_bitmaps", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "antialiasing"),
        JS_NewCFunction(ctx, font_file_class_get_antialiasing, "get_antialiasing", 0),
        JS_NewCFunction(ctx, font_file_class_set_antialiasing, "set_antialiasing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_name"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, font_file_class_set_font_name, "set_font_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "style_name"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, font_file_class_set_font_style_name, "set_font_style_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_style"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, font_file_class_set_font_style, "set_font_style", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_weight"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, font_file_class_set_font_weight, "set_font_weight", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_stretch"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, font_file_class_set_font_stretch, "set_font_stretch", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subpixel_positioning"),
        JS_NewCFunction(ctx, font_file_class_get_subpixel_positioning, "get_subpixel_positioning", 0),
        JS_NewCFunction(ctx, font_file_class_set_subpixel_positioning, "set_subpixel_positioning", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_rounding_remainders"),
        JS_NewCFunction(ctx, font_file_class_get_keep_rounding_remainders, "get_keep_rounding_remainders", 0),
        JS_NewCFunction(ctx, font_file_class_set_keep_rounding_remainders, "set_keep_rounding_remainders", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "multichannel_signed_distance_field"),
        JS_NewCFunction(ctx, font_file_class_is_multichannel_signed_distance_field, "is_multichannel_signed_distance_field", 0),
        JS_NewCFunction(ctx, font_file_class_set_multichannel_signed_distance_field, "set_multichannel_signed_distance_field", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "msdf_pixel_range"),
        JS_NewCFunction(ctx, font_file_class_get_msdf_pixel_range, "get_msdf_pixel_range", 0),
        JS_NewCFunction(ctx, font_file_class_set_msdf_pixel_range, "set_msdf_pixel_range", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "msdf_size"),
        JS_NewCFunction(ctx, font_file_class_get_msdf_size, "get_msdf_size", 0),
        JS_NewCFunction(ctx, font_file_class_set_msdf_size, "set_msdf_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_system_fallback"),
        JS_NewCFunction(ctx, font_file_class_is_allow_system_fallback, "is_allow_system_fallback", 0),
        JS_NewCFunction(ctx, font_file_class_set_allow_system_fallback, "set_allow_system_fallback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "force_autohinter"),
        JS_NewCFunction(ctx, font_file_class_is_force_autohinter, "is_force_autohinter", 0),
        JS_NewCFunction(ctx, font_file_class_set_force_autohinter, "set_force_autohinter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modulate_color_glyphs"),
        JS_NewCFunction(ctx, font_file_class_is_modulate_color_glyphs, "is_modulate_color_glyphs", 0),
        JS_NewCFunction(ctx, font_file_class_set_modulate_color_glyphs, "set_modulate_color_glyphs", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hinting"),
        JS_NewCFunction(ctx, font_file_class_get_hinting, "get_hinting", 0),
        JS_NewCFunction(ctx, font_file_class_set_hinting, "set_hinting", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fixed_size"),
        JS_NewCFunction(ctx, font_file_class_get_fixed_size, "get_fixed_size", 0),
        JS_NewCFunction(ctx, font_file_class_set_fixed_size, "set_fixed_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fixed_size_scale_mode"),
        JS_NewCFunction(ctx, font_file_class_get_fixed_size_scale_mode, "get_fixed_size_scale_mode", 0),
        JS_NewCFunction(ctx, font_file_class_set_fixed_size_scale_mode, "set_fixed_size_scale_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "opentype_feature_overrides"),
        JS_NewCFunction(ctx, font_file_class_get_opentype_feature_overrides, "get_opentype_feature_overrides", 0),
        JS_NewCFunction(ctx, font_file_class_set_opentype_feature_overrides, "set_opentype_feature_overrides", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "oversampling"),
        JS_NewCFunction(ctx, font_file_class_get_oversampling, "get_oversampling", 0),
        JS_NewCFunction(ctx, font_file_class_set_oversampling, "set_oversampling", 1),
        JS_PROP_GETSET
    );
}

static void define_font_file_enum(JSContext *ctx, JSValue ctor) {
}

static int js_font_file_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FontFile"] = class_id;
	classes_by_id[class_id] = "FontFile";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &font_file_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Font"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_font_file_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, font_file_class_proto_funcs, _countof(font_file_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, font_file_class_constructor, "FontFile", 0, JS_CFUNC_constructor, 0);
	define_font_file_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FontFile", ctor);

	return 0;
}

JSModuleDef *_js_init_font_file_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/font';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_font_file_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FontFile");
	return m;
}

JSModuleDef *js_init_font_file_module(JSContext *ctx) {
	return _js_init_font_file_module(ctx, "@godot/classes/font_file");
}

void __register_font_file() {
	js_init_font_file_module(js_context());
}

void register_font_file() {
	__register_font_file();
}