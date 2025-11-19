#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/image.hpp>
using namespace godot;

static void image_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Image"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef image_class_def = {
    "Image",
    image_class_finalizer
};

static JSValue image_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Image"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Image *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Image *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Image);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue image_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_width, ctx, this_val, argc, argv);
};
static JSValue image_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_height, ctx, this_val, argc, argv);
};
static JSValue image_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_size, ctx, this_val, argc, argv);
};
static JSValue image_class_has_mipmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::has_mipmaps, ctx, this_val, argc, argv);
};
static JSValue image_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_format, ctx, this_val, argc, argv);
};
static JSValue image_class_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_data, ctx, this_val, argc, argv);
};
static JSValue image_class_get_data_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_data_size, ctx, this_val, argc, argv);
};
static JSValue image_class_convert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::convert, ctx, this_val, argc, argv);
};
static JSValue image_class_get_mipmap_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_mipmap_count, ctx, this_val, argc, argv);
};
static JSValue image_class_get_mipmap_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_mipmap_offset, ctx, this_val, argc, argv);
};
static JSValue image_class_resize_to_po2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::resize_to_po2, ctx, this_val, argc, argv);
};
static JSValue image_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::resize, ctx, this_val, argc, argv);
};
static JSValue image_class_shrink_x2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::shrink_x2, ctx, this_val, argc, argv);
};
static JSValue image_class_crop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::crop, ctx, this_val, argc, argv);
};
static JSValue image_class_flip_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::flip_x, ctx, this_val, argc, argv);
};
static JSValue image_class_flip_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::flip_y, ctx, this_val, argc, argv);
};
static JSValue image_class_generate_mipmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::generate_mipmaps, ctx, this_val, argc, argv);
};
static JSValue image_class_clear_mipmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::clear_mipmaps, ctx, this_val, argc, argv);
};
static JSValue image_class_set_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::set_data, ctx, this_val, argc, argv);
};
static JSValue image_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::is_empty, ctx, this_val, argc, argv);
};
static JSValue image_class_load(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load, ctx, this_val, argc, argv);
};
static JSValue image_class_save_png(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_png, ctx, this_val, argc, argv);
};
static JSValue image_class_save_png_to_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_png_to_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_save_jpg(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_jpg, ctx, this_val, argc, argv);
};
static JSValue image_class_save_jpg_to_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_jpg_to_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_save_exr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_exr, ctx, this_val, argc, argv);
};
static JSValue image_class_save_exr_to_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_exr_to_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_save_dds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_dds, ctx, this_val, argc, argv);
};
static JSValue image_class_save_dds_to_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_dds_to_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_save_webp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_webp, ctx, this_val, argc, argv);
};
static JSValue image_class_save_webp_to_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::save_webp_to_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_detect_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::detect_alpha, ctx, this_val, argc, argv);
};
static JSValue image_class_is_invisible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::is_invisible, ctx, this_val, argc, argv);
};
static JSValue image_class_detect_used_channels(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::detect_used_channels, ctx, this_val, argc, argv);
};
static JSValue image_class_compress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::compress, ctx, this_val, argc, argv);
};
static JSValue image_class_compress_from_channels(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::compress_from_channels, ctx, this_val, argc, argv);
};
static JSValue image_class_decompress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::decompress, ctx, this_val, argc, argv);
};
static JSValue image_class_is_compressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::is_compressed, ctx, this_val, argc, argv);
};
static JSValue image_class_rotate_90(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::rotate_90, ctx, this_val, argc, argv);
};
static JSValue image_class_rotate_180(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::rotate_180, ctx, this_val, argc, argv);
};
static JSValue image_class_fix_alpha_edges(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::fix_alpha_edges, ctx, this_val, argc, argv);
};
static JSValue image_class_premultiply_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::premultiply_alpha, ctx, this_val, argc, argv);
};
static JSValue image_class_srgb_to_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::srgb_to_linear, ctx, this_val, argc, argv);
};
static JSValue image_class_linear_to_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::linear_to_srgb, ctx, this_val, argc, argv);
};
static JSValue image_class_normal_map_to_xy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::normal_map_to_xy, ctx, this_val, argc, argv);
};
static JSValue image_class_rgbe_to_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::rgbe_to_srgb, ctx, this_val, argc, argv);
};
static JSValue image_class_bump_map_to_normal_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::bump_map_to_normal_map, ctx, this_val, argc, argv);
};
static JSValue image_class_compute_image_metrics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::compute_image_metrics, ctx, this_val, argc, argv);
};
static JSValue image_class_blit_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::blit_rect, ctx, this_val, argc, argv);
};
static JSValue image_class_blit_rect_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::blit_rect_mask, ctx, this_val, argc, argv);
};
static JSValue image_class_blend_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::blend_rect, ctx, this_val, argc, argv);
};
static JSValue image_class_blend_rect_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::blend_rect_mask, ctx, this_val, argc, argv);
};
static JSValue image_class_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::fill, ctx, this_val, argc, argv);
};
static JSValue image_class_fill_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::fill_rect, ctx, this_val, argc, argv);
};
static JSValue image_class_get_used_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_used_rect, ctx, this_val, argc, argv);
};
static JSValue image_class_get_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_region, ctx, this_val, argc, argv);
};
static JSValue image_class_copy_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::copy_from, ctx, this_val, argc, argv);
};
static JSValue image_class_get_pixelv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_pixelv, ctx, this_val, argc, argv);
};
static JSValue image_class_get_pixel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Image::get_pixel, ctx, this_val, argc, argv);
};
static JSValue image_class_set_pixelv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::set_pixelv, ctx, this_val, argc, argv);
};
static JSValue image_class_set_pixel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::set_pixel, ctx, this_val, argc, argv);
};
static JSValue image_class_adjust_bcs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Image::adjust_bcs, ctx, this_val, argc, argv);
};
static JSValue image_class_load_png_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_png_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_jpg_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_jpg_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_webp_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_webp_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_tga_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_tga_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_bmp_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_bmp_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_ktx_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_ktx_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_dds_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_dds_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_svg_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_svg_from_buffer, ctx, this_val, argc, argv);
};
static JSValue image_class_load_svg_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Image::load_svg_from_string, ctx, this_val, argc, argv);
};


static JSValue image_class_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Image::create, ctx, this_val, argc, argv);
};
static JSValue image_class_create_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Image::create_empty, ctx, this_val, argc, argv);
};
static JSValue image_class_create_from_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Image::create_from_data, ctx, this_val, argc, argv);
};
static JSValue image_class_load_from_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Image::load_from_file, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry image_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_width", 0, &image_class_get_width),
	JS_CFUNC_DEF("get_height", 0, &image_class_get_height),
	JS_CFUNC_DEF("get_size", 0, &image_class_get_size),
	JS_CFUNC_DEF("has_mipmaps", 0, &image_class_has_mipmaps),
	JS_CFUNC_DEF("get_format", 0, &image_class_get_format),
	JS_CFUNC_DEF("get_data", 0, &image_class_get_data),
	JS_CFUNC_DEF("get_data_size", 0, &image_class_get_data_size),
	JS_CFUNC_DEF("convert", 1, &image_class_convert),
	JS_CFUNC_DEF("get_mipmap_count", 0, &image_class_get_mipmap_count),
	JS_CFUNC_DEF("get_mipmap_offset", 1, &image_class_get_mipmap_offset),
	JS_CFUNC_DEF("resize_to_po2", 2, &image_class_resize_to_po2),
	JS_CFUNC_DEF("resize", 3, &image_class_resize),
	JS_CFUNC_DEF("shrink_x2", 0, &image_class_shrink_x2),
	JS_CFUNC_DEF("crop", 2, &image_class_crop),
	JS_CFUNC_DEF("flip_x", 0, &image_class_flip_x),
	JS_CFUNC_DEF("flip_y", 0, &image_class_flip_y),
	JS_CFUNC_DEF("generate_mipmaps", 1, &image_class_generate_mipmaps),
	JS_CFUNC_DEF("clear_mipmaps", 0, &image_class_clear_mipmaps),
	JS_CFUNC_DEF("set_data", 5, &image_class_set_data),
	JS_CFUNC_DEF("is_empty", 0, &image_class_is_empty),
	JS_CFUNC_DEF("load", 1, &image_class_load),
	JS_CFUNC_DEF("save_png", 1, &image_class_save_png),
	JS_CFUNC_DEF("save_png_to_buffer", 0, &image_class_save_png_to_buffer),
	JS_CFUNC_DEF("save_jpg", 2, &image_class_save_jpg),
	JS_CFUNC_DEF("save_jpg_to_buffer", 1, &image_class_save_jpg_to_buffer),
	JS_CFUNC_DEF("save_exr", 2, &image_class_save_exr),
	JS_CFUNC_DEF("save_exr_to_buffer", 1, &image_class_save_exr_to_buffer),
	JS_CFUNC_DEF("save_dds", 1, &image_class_save_dds),
	JS_CFUNC_DEF("save_dds_to_buffer", 0, &image_class_save_dds_to_buffer),
	JS_CFUNC_DEF("save_webp", 3, &image_class_save_webp),
	JS_CFUNC_DEF("save_webp_to_buffer", 2, &image_class_save_webp_to_buffer),
	JS_CFUNC_DEF("detect_alpha", 0, &image_class_detect_alpha),
	JS_CFUNC_DEF("is_invisible", 0, &image_class_is_invisible),
	JS_CFUNC_DEF("detect_used_channels", 1, &image_class_detect_used_channels),
	JS_CFUNC_DEF("compress", 3, &image_class_compress),
	JS_CFUNC_DEF("compress_from_channels", 3, &image_class_compress_from_channels),
	JS_CFUNC_DEF("decompress", 0, &image_class_decompress),
	JS_CFUNC_DEF("is_compressed", 0, &image_class_is_compressed),
	JS_CFUNC_DEF("rotate_90", 1, &image_class_rotate_90),
	JS_CFUNC_DEF("rotate_180", 0, &image_class_rotate_180),
	JS_CFUNC_DEF("fix_alpha_edges", 0, &image_class_fix_alpha_edges),
	JS_CFUNC_DEF("premultiply_alpha", 0, &image_class_premultiply_alpha),
	JS_CFUNC_DEF("srgb_to_linear", 0, &image_class_srgb_to_linear),
	JS_CFUNC_DEF("linear_to_srgb", 0, &image_class_linear_to_srgb),
	JS_CFUNC_DEF("normal_map_to_xy", 0, &image_class_normal_map_to_xy),
	JS_CFUNC_DEF("rgbe_to_srgb", 0, &image_class_rgbe_to_srgb),
	JS_CFUNC_DEF("bump_map_to_normal_map", 1, &image_class_bump_map_to_normal_map),
	JS_CFUNC_DEF("compute_image_metrics", 2, &image_class_compute_image_metrics),
	JS_CFUNC_DEF("blit_rect", 3, &image_class_blit_rect),
	JS_CFUNC_DEF("blit_rect_mask", 4, &image_class_blit_rect_mask),
	JS_CFUNC_DEF("blend_rect", 3, &image_class_blend_rect),
	JS_CFUNC_DEF("blend_rect_mask", 4, &image_class_blend_rect_mask),
	JS_CFUNC_DEF("fill", 1, &image_class_fill),
	JS_CFUNC_DEF("fill_rect", 2, &image_class_fill_rect),
	JS_CFUNC_DEF("get_used_rect", 0, &image_class_get_used_rect),
	JS_CFUNC_DEF("get_region", 1, &image_class_get_region),
	JS_CFUNC_DEF("copy_from", 1, &image_class_copy_from),
	JS_CFUNC_DEF("get_pixelv", 1, &image_class_get_pixelv),
	JS_CFUNC_DEF("get_pixel", 2, &image_class_get_pixel),
	JS_CFUNC_DEF("set_pixelv", 2, &image_class_set_pixelv),
	JS_CFUNC_DEF("set_pixel", 3, &image_class_set_pixel),
	JS_CFUNC_DEF("adjust_bcs", 3, &image_class_adjust_bcs),
	JS_CFUNC_DEF("load_png_from_buffer", 1, &image_class_load_png_from_buffer),
	JS_CFUNC_DEF("load_jpg_from_buffer", 1, &image_class_load_jpg_from_buffer),
	JS_CFUNC_DEF("load_webp_from_buffer", 1, &image_class_load_webp_from_buffer),
	JS_CFUNC_DEF("load_tga_from_buffer", 1, &image_class_load_tga_from_buffer),
	JS_CFUNC_DEF("load_bmp_from_buffer", 1, &image_class_load_bmp_from_buffer),
	JS_CFUNC_DEF("load_ktx_from_buffer", 1, &image_class_load_ktx_from_buffer),
	JS_CFUNC_DEF("load_dds_from_buffer", 1, &image_class_load_dds_from_buffer),
	JS_CFUNC_DEF("load_svg_from_buffer", 2, &image_class_load_svg_from_buffer),
	JS_CFUNC_DEF("load_svg_from_string", 2, &image_class_load_svg_from_string),
};

static const JSCFunctionListEntry image_class_static_funcs[] = {
	JS_CFUNC_DEF("create", 4, &image_class_create),
	JS_CFUNC_DEF("create_empty", 4, &image_class_create_empty),
	JS_CFUNC_DEF("create_from_data", 5, &image_class_create_from_data),
	JS_CFUNC_DEF("load_from_file", 1, &image_class_load_from_file),
};



static void define_image_property(JSContext *ctx, JSValue proto) {
}

static void define_image_enum(JSContext *ctx, JSValue ctor) {
	JSValue Format_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_L8", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_LA8", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_R8", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RG8", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGB8", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBA8", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBA4444", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGB565", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RF", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGF", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBF", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBAF", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RH", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGH", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBH", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBAH", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGBE9995", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_DXT1", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_DXT3", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_DXT5", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGTC_R", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_RGTC_RG", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_BPTC_RGBA", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_BPTC_RGBF", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_BPTC_RGBFU", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_R11", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_R11S", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_RG11", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_RG11S", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_RGB8", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_RGBA8", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_RGB8A1", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ETC2_RA_AS_RG", JS_NewInt64(ctx, 33));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_DXT5_RA_AS_RG", JS_NewInt64(ctx, 34));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ASTC_4x4", JS_NewInt64(ctx, 35));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ASTC_4x4_HDR", JS_NewInt64(ctx, 36));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ASTC_8x8", JS_NewInt64(ctx, 37));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_ASTC_8x8_HDR", JS_NewInt64(ctx, 38));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_MAX", JS_NewInt64(ctx, 39));
	JS_SetPropertyStr(ctx, ctor, "Format", Format_obj);
	JSValue Interpolation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Interpolation_obj, "INTERPOLATE_NEAREST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Interpolation_obj, "INTERPOLATE_BILINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Interpolation_obj, "INTERPOLATE_CUBIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Interpolation_obj, "INTERPOLATE_TRILINEAR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Interpolation_obj, "INTERPOLATE_LANCZOS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "Interpolation", Interpolation_obj);
	JSValue AlphaMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AlphaMode_obj, "ALPHA_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AlphaMode_obj, "ALPHA_BIT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AlphaMode_obj, "ALPHA_BLEND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AlphaMode", AlphaMode_obj);
	JSValue CompressMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompressMode_obj, "COMPRESS_S3TC", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompressMode_obj, "COMPRESS_ETC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompressMode_obj, "COMPRESS_ETC2", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CompressMode_obj, "COMPRESS_BPTC", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CompressMode_obj, "COMPRESS_ASTC", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CompressMode_obj, "COMPRESS_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "CompressMode", CompressMode_obj);
	JSValue UsedChannels_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UsedChannels_obj, "USED_CHANNELS_L", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, UsedChannels_obj, "USED_CHANNELS_LA", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, UsedChannels_obj, "USED_CHANNELS_R", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, UsedChannels_obj, "USED_CHANNELS_RG", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, UsedChannels_obj, "USED_CHANNELS_RGB", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, UsedChannels_obj, "USED_CHANNELS_RGBA", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "UsedChannels", UsedChannels_obj);
	JSValue CompressSource_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompressSource_obj, "COMPRESS_SOURCE_GENERIC", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompressSource_obj, "COMPRESS_SOURCE_SRGB", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompressSource_obj, "COMPRESS_SOURCE_NORMAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "CompressSource", CompressSource_obj);
	JSValue ASTCFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ASTCFormat_obj, "ASTC_FORMAT_4x4", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ASTCFormat_obj, "ASTC_FORMAT_8x8", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "ASTCFormat", ASTCFormat_obj);
}

static int js_image_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Image"] = class_id;
	classes_by_id[class_id] = "Image";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &image_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_image_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, image_class_proto_funcs, _countof(image_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, image_class_constructor, "Image", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, image_class_static_funcs, _countof(image_class_static_funcs));
	define_image_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Image", ctor);

	return 0;
}

JSModuleDef *_js_init_image_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_image_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Image");
	return m;
}

JSModuleDef *js_init_image_module(JSContext *ctx) {
	return _js_init_image_module(ctx, "@godot/classes/image");
}

void __register_image() {
	js_init_image_module(js_context());
}

void register_image() {
	__register_image();
}