#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/rd_attachment_format.hpp>
#include <godot_cpp/classes/rd_framebuffer_pass.hpp>
#include <godot_cpp/classes/rd_pipeline_color_blend_state.hpp>
#include <godot_cpp/classes/rd_pipeline_depth_stencil_state.hpp>
#include <godot_cpp/classes/rd_pipeline_multisample_state.hpp>
#include <godot_cpp/classes/rd_pipeline_rasterization_state.hpp>
#include <godot_cpp/classes/rd_pipeline_specialization_constant.hpp>
#include <godot_cpp/classes/rd_sampler_state.hpp>
#include <godot_cpp/classes/rd_shader_source.hpp>
#include <godot_cpp/classes/rd_shader_spirv.hpp>
#include <godot_cpp/classes/rd_texture_format.hpp>
#include <godot_cpp/classes/rd_texture_view.hpp>
#include <godot_cpp/classes/rd_uniform.hpp>
#include <godot_cpp/classes/rd_vertex_attribute.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/rendering_device.hpp>
using namespace godot;

static void rendering_device_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RenderingDevice"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef rendering_device_class_def = {
    "RenderingDevice",
    rendering_device_class_finalizer
};

static JSValue rendering_device_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RenderingDevice"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RenderingDevice *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RenderingDevice *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RenderingDevice);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rendering_device_class_texture_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_create_shared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_create_shared, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_create_shared_from_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_create_shared_from_slice, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_create_from_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_create_from_extension, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_update, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_get_data, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_get_data_async(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_get_data_async, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_is_format_supported_for_usage(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::texture_is_format_supported_for_usage, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_is_shared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_is_shared, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_is_valid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_set_discardable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::texture_set_discardable, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_is_discardable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_is_discardable, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_copy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_copy, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_clear, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_resolve_multisample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_resolve_multisample, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_get_format, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_get_native_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_get_native_handle, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_format_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_format_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_format_create_multipass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_format_create_multipass, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_format_create_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_format_create_empty, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_format_get_texture_samples(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_format_get_texture_samples, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_create_multipass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_create_multipass, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_create_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_create_empty, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::framebuffer_get_format, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_framebuffer_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::framebuffer_is_valid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_sampler_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::sampler_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_sampler_is_format_supported_for_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::sampler_is_format_supported_for_filter, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_vertex_buffer_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::vertex_buffer_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_vertex_format_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::vertex_format_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_vertex_array_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::vertex_array_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_index_buffer_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::index_buffer_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_index_array_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::index_array_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_shader_compile_spirv_from_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::shader_compile_spirv_from_source, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_shader_compile_binary_from_spirv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::shader_compile_binary_from_spirv, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_shader_create_from_spirv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::shader_create_from_spirv, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_shader_create_from_bytecode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::shader_create_from_bytecode, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_shader_create_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::shader_create_placeholder, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_shader_get_vertex_input_attribute_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::shader_get_vertex_input_attribute_mask, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_uniform_buffer_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::uniform_buffer_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_storage_buffer_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::storage_buffer_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_texture_buffer_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::texture_buffer_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_uniform_set_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::uniform_set_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_uniform_set_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::uniform_set_is_valid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_buffer_copy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::buffer_copy, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_buffer_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::buffer_update, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_buffer_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::buffer_clear, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_buffer_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::buffer_get_data, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_buffer_get_data_async(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::buffer_get_data_async, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_buffer_get_device_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::buffer_get_device_address, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_render_pipeline_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::render_pipeline_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_render_pipeline_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::render_pipeline_is_valid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_pipeline_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::compute_pipeline_create, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_pipeline_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::compute_pipeline_is_valid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_screen_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::screen_get_width, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_screen_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::screen_get_height, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_screen_get_framebuffer_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::screen_get_framebuffer_format, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_begin_for_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::draw_list_begin_for_screen, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::draw_list_begin, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_begin_split(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::draw_list_begin_split, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_set_blend_constants(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_set_blend_constants, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_bind_render_pipeline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_bind_render_pipeline, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_bind_uniform_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_bind_uniform_set, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_bind_vertex_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_bind_vertex_array, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_bind_index_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_bind_index_array, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_set_push_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_set_push_constant, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_draw, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_draw_indirect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_draw_indirect, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_enable_scissor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_enable_scissor, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_disable_scissor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_disable_scissor, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_switch_to_next_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::draw_list_switch_to_next_pass, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_switch_to_next_pass_split(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::draw_list_switch_to_next_pass_split, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_list_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_list_end, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::compute_list_begin, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_bind_compute_pipeline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_bind_compute_pipeline, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_set_push_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_set_push_constant, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_bind_uniform_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_bind_uniform_set, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_dispatch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_dispatch, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_dispatch_indirect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_dispatch_indirect, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_add_barrier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_add_barrier, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_compute_list_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::compute_list_end, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_free_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::free_rid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_capture_timestamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::capture_timestamp, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_captured_timestamps_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_captured_timestamps_count, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_captured_timestamps_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_captured_timestamps_frame, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_captured_timestamp_gpu_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_captured_timestamp_gpu_time, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_captured_timestamp_cpu_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_captured_timestamp_cpu_time, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_captured_timestamp_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_captured_timestamp_name, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_has_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::has_feature, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_limit_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::limit_get, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_frame_delay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_frame_delay, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_submit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::submit, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::sync, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_barrier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::barrier, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_full_barrier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::full_barrier, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_create_local_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::create_local_device, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_set_resource_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::set_resource_name, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_command_begin_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_command_begin_label, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_command_insert_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_command_insert_label, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_draw_command_end_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderingDevice::draw_command_end_label, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_vendor_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_vendor_name, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_name, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_pipeline_cache_uuid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_pipeline_cache_uuid, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_memory_usage(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_memory_usage, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_driver_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RenderingDevice::get_driver_resource, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_perf_report(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_perf_report, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_driver_and_device_memory_report(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_driver_and_device_memory_report, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_tracked_object_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_tracked_object_name, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_tracked_object_type_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_tracked_object_type_count, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_driver_total_memory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_driver_total_memory, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_driver_allocation_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_driver_allocation_count, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_driver_memory_by_object_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_driver_memory_by_object_type, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_driver_allocs_by_object_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_driver_allocs_by_object_type, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_total_memory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_total_memory, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_allocation_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_allocation_count, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_memory_by_object_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_memory_by_object_type, ctx, this_val, argc, argv);
};
static JSValue rendering_device_class_get_device_allocs_by_object_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderingDevice::get_device_allocs_by_object_type, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry rendering_device_class_proto_funcs[] = {
	JS_CFUNC_DEF("texture_create", 3, &rendering_device_class_texture_create),
	JS_CFUNC_DEF("texture_create_shared", 2, &rendering_device_class_texture_create_shared),
	JS_CFUNC_DEF("texture_create_shared_from_slice", 6, &rendering_device_class_texture_create_shared_from_slice),
	JS_CFUNC_DEF("texture_create_from_extension", 10, &rendering_device_class_texture_create_from_extension),
	JS_CFUNC_DEF("texture_update", 3, &rendering_device_class_texture_update),
	JS_CFUNC_DEF("texture_get_data", 2, &rendering_device_class_texture_get_data),
	JS_CFUNC_DEF("texture_get_data_async", 3, &rendering_device_class_texture_get_data_async),
	JS_CFUNC_DEF("texture_is_format_supported_for_usage", 2, &rendering_device_class_texture_is_format_supported_for_usage),
	JS_CFUNC_DEF("texture_is_shared", 1, &rendering_device_class_texture_is_shared),
	JS_CFUNC_DEF("texture_is_valid", 1, &rendering_device_class_texture_is_valid),
	JS_CFUNC_DEF("texture_set_discardable", 2, &rendering_device_class_texture_set_discardable),
	JS_CFUNC_DEF("texture_is_discardable", 1, &rendering_device_class_texture_is_discardable),
	JS_CFUNC_DEF("texture_copy", 9, &rendering_device_class_texture_copy),
	JS_CFUNC_DEF("texture_clear", 6, &rendering_device_class_texture_clear),
	JS_CFUNC_DEF("texture_resolve_multisample", 2, &rendering_device_class_texture_resolve_multisample),
	JS_CFUNC_DEF("texture_get_format", 1, &rendering_device_class_texture_get_format),
	JS_CFUNC_DEF("texture_get_native_handle", 1, &rendering_device_class_texture_get_native_handle),
	JS_CFUNC_DEF("framebuffer_format_create", 2, &rendering_device_class_framebuffer_format_create),
	JS_CFUNC_DEF("framebuffer_format_create_multipass", 3, &rendering_device_class_framebuffer_format_create_multipass),
	JS_CFUNC_DEF("framebuffer_format_create_empty", 1, &rendering_device_class_framebuffer_format_create_empty),
	JS_CFUNC_DEF("framebuffer_format_get_texture_samples", 2, &rendering_device_class_framebuffer_format_get_texture_samples),
	JS_CFUNC_DEF("framebuffer_create", 3, &rendering_device_class_framebuffer_create),
	JS_CFUNC_DEF("framebuffer_create_multipass", 4, &rendering_device_class_framebuffer_create_multipass),
	JS_CFUNC_DEF("framebuffer_create_empty", 3, &rendering_device_class_framebuffer_create_empty),
	JS_CFUNC_DEF("framebuffer_get_format", 1, &rendering_device_class_framebuffer_get_format),
	JS_CFUNC_DEF("framebuffer_is_valid", 1, &rendering_device_class_framebuffer_is_valid),
	JS_CFUNC_DEF("sampler_create", 1, &rendering_device_class_sampler_create),
	JS_CFUNC_DEF("sampler_is_format_supported_for_filter", 2, &rendering_device_class_sampler_is_format_supported_for_filter),
	JS_CFUNC_DEF("vertex_buffer_create", 3, &rendering_device_class_vertex_buffer_create),
	JS_CFUNC_DEF("vertex_format_create", 1, &rendering_device_class_vertex_format_create),
	JS_CFUNC_DEF("vertex_array_create", 4, &rendering_device_class_vertex_array_create),
	JS_CFUNC_DEF("index_buffer_create", 5, &rendering_device_class_index_buffer_create),
	JS_CFUNC_DEF("index_array_create", 3, &rendering_device_class_index_array_create),
	JS_CFUNC_DEF("shader_compile_spirv_from_source", 2, &rendering_device_class_shader_compile_spirv_from_source),
	JS_CFUNC_DEF("shader_compile_binary_from_spirv", 2, &rendering_device_class_shader_compile_binary_from_spirv),
	JS_CFUNC_DEF("shader_create_from_spirv", 2, &rendering_device_class_shader_create_from_spirv),
	JS_CFUNC_DEF("shader_create_from_bytecode", 2, &rendering_device_class_shader_create_from_bytecode),
	JS_CFUNC_DEF("shader_create_placeholder", 0, &rendering_device_class_shader_create_placeholder),
	JS_CFUNC_DEF("shader_get_vertex_input_attribute_mask", 1, &rendering_device_class_shader_get_vertex_input_attribute_mask),
	JS_CFUNC_DEF("uniform_buffer_create", 3, &rendering_device_class_uniform_buffer_create),
	JS_CFUNC_DEF("storage_buffer_create", 4, &rendering_device_class_storage_buffer_create),
	JS_CFUNC_DEF("texture_buffer_create", 3, &rendering_device_class_texture_buffer_create),
	JS_CFUNC_DEF("uniform_set_create", 3, &rendering_device_class_uniform_set_create),
	JS_CFUNC_DEF("uniform_set_is_valid", 1, &rendering_device_class_uniform_set_is_valid),
	JS_CFUNC_DEF("buffer_copy", 5, &rendering_device_class_buffer_copy),
	JS_CFUNC_DEF("buffer_update", 4, &rendering_device_class_buffer_update),
	JS_CFUNC_DEF("buffer_clear", 3, &rendering_device_class_buffer_clear),
	JS_CFUNC_DEF("buffer_get_data", 3, &rendering_device_class_buffer_get_data),
	JS_CFUNC_DEF("buffer_get_data_async", 4, &rendering_device_class_buffer_get_data_async),
	JS_CFUNC_DEF("buffer_get_device_address", 1, &rendering_device_class_buffer_get_device_address),
	JS_CFUNC_DEF("render_pipeline_create", 11, &rendering_device_class_render_pipeline_create),
	JS_CFUNC_DEF("render_pipeline_is_valid", 1, &rendering_device_class_render_pipeline_is_valid),
	JS_CFUNC_DEF("compute_pipeline_create", 2, &rendering_device_class_compute_pipeline_create),
	JS_CFUNC_DEF("compute_pipeline_is_valid", 1, &rendering_device_class_compute_pipeline_is_valid),
	JS_CFUNC_DEF("screen_get_width", 1, &rendering_device_class_screen_get_width),
	JS_CFUNC_DEF("screen_get_height", 1, &rendering_device_class_screen_get_height),
	JS_CFUNC_DEF("screen_get_framebuffer_format", 1, &rendering_device_class_screen_get_framebuffer_format),
	JS_CFUNC_DEF("draw_list_begin_for_screen", 2, &rendering_device_class_draw_list_begin_for_screen),
	JS_CFUNC_DEF("draw_list_begin", 7, &rendering_device_class_draw_list_begin),
	JS_CFUNC_DEF("draw_list_begin_split", 11, &rendering_device_class_draw_list_begin_split),
	JS_CFUNC_DEF("draw_list_set_blend_constants", 2, &rendering_device_class_draw_list_set_blend_constants),
	JS_CFUNC_DEF("draw_list_bind_render_pipeline", 2, &rendering_device_class_draw_list_bind_render_pipeline),
	JS_CFUNC_DEF("draw_list_bind_uniform_set", 3, &rendering_device_class_draw_list_bind_uniform_set),
	JS_CFUNC_DEF("draw_list_bind_vertex_array", 2, &rendering_device_class_draw_list_bind_vertex_array),
	JS_CFUNC_DEF("draw_list_bind_index_array", 2, &rendering_device_class_draw_list_bind_index_array),
	JS_CFUNC_DEF("draw_list_set_push_constant", 3, &rendering_device_class_draw_list_set_push_constant),
	JS_CFUNC_DEF("draw_list_draw", 4, &rendering_device_class_draw_list_draw),
	JS_CFUNC_DEF("draw_list_draw_indirect", 6, &rendering_device_class_draw_list_draw_indirect),
	JS_CFUNC_DEF("draw_list_enable_scissor", 2, &rendering_device_class_draw_list_enable_scissor),
	JS_CFUNC_DEF("draw_list_disable_scissor", 1, &rendering_device_class_draw_list_disable_scissor),
	JS_CFUNC_DEF("draw_list_switch_to_next_pass", 0, &rendering_device_class_draw_list_switch_to_next_pass),
	JS_CFUNC_DEF("draw_list_switch_to_next_pass_split", 1, &rendering_device_class_draw_list_switch_to_next_pass_split),
	JS_CFUNC_DEF("draw_list_end", 0, &rendering_device_class_draw_list_end),
	JS_CFUNC_DEF("compute_list_begin", 0, &rendering_device_class_compute_list_begin),
	JS_CFUNC_DEF("compute_list_bind_compute_pipeline", 2, &rendering_device_class_compute_list_bind_compute_pipeline),
	JS_CFUNC_DEF("compute_list_set_push_constant", 3, &rendering_device_class_compute_list_set_push_constant),
	JS_CFUNC_DEF("compute_list_bind_uniform_set", 3, &rendering_device_class_compute_list_bind_uniform_set),
	JS_CFUNC_DEF("compute_list_dispatch", 4, &rendering_device_class_compute_list_dispatch),
	JS_CFUNC_DEF("compute_list_dispatch_indirect", 3, &rendering_device_class_compute_list_dispatch_indirect),
	JS_CFUNC_DEF("compute_list_add_barrier", 1, &rendering_device_class_compute_list_add_barrier),
	JS_CFUNC_DEF("compute_list_end", 0, &rendering_device_class_compute_list_end),
	JS_CFUNC_DEF("free_rid", 1, &rendering_device_class_free_rid),
	JS_CFUNC_DEF("capture_timestamp", 1, &rendering_device_class_capture_timestamp),
	JS_CFUNC_DEF("get_captured_timestamps_count", 0, &rendering_device_class_get_captured_timestamps_count),
	JS_CFUNC_DEF("get_captured_timestamps_frame", 0, &rendering_device_class_get_captured_timestamps_frame),
	JS_CFUNC_DEF("get_captured_timestamp_gpu_time", 1, &rendering_device_class_get_captured_timestamp_gpu_time),
	JS_CFUNC_DEF("get_captured_timestamp_cpu_time", 1, &rendering_device_class_get_captured_timestamp_cpu_time),
	JS_CFUNC_DEF("get_captured_timestamp_name", 1, &rendering_device_class_get_captured_timestamp_name),
	JS_CFUNC_DEF("has_feature", 1, &rendering_device_class_has_feature),
	JS_CFUNC_DEF("limit_get", 1, &rendering_device_class_limit_get),
	JS_CFUNC_DEF("get_frame_delay", 0, &rendering_device_class_get_frame_delay),
	JS_CFUNC_DEF("submit", 0, &rendering_device_class_submit),
	JS_CFUNC_DEF("sync", 0, &rendering_device_class_sync),
	JS_CFUNC_DEF("barrier", 2, &rendering_device_class_barrier),
	JS_CFUNC_DEF("full_barrier", 0, &rendering_device_class_full_barrier),
	JS_CFUNC_DEF("create_local_device", 0, &rendering_device_class_create_local_device),
	JS_CFUNC_DEF("set_resource_name", 2, &rendering_device_class_set_resource_name),
	JS_CFUNC_DEF("draw_command_begin_label", 2, &rendering_device_class_draw_command_begin_label),
	JS_CFUNC_DEF("draw_command_insert_label", 2, &rendering_device_class_draw_command_insert_label),
	JS_CFUNC_DEF("draw_command_end_label", 0, &rendering_device_class_draw_command_end_label),
	JS_CFUNC_DEF("get_device_vendor_name", 0, &rendering_device_class_get_device_vendor_name),
	JS_CFUNC_DEF("get_device_name", 0, &rendering_device_class_get_device_name),
	JS_CFUNC_DEF("get_device_pipeline_cache_uuid", 0, &rendering_device_class_get_device_pipeline_cache_uuid),
	JS_CFUNC_DEF("get_memory_usage", 1, &rendering_device_class_get_memory_usage),
	JS_CFUNC_DEF("get_driver_resource", 3, &rendering_device_class_get_driver_resource),
	JS_CFUNC_DEF("get_perf_report", 0, &rendering_device_class_get_perf_report),
	JS_CFUNC_DEF("get_driver_and_device_memory_report", 0, &rendering_device_class_get_driver_and_device_memory_report),
	JS_CFUNC_DEF("get_tracked_object_name", 1, &rendering_device_class_get_tracked_object_name),
	JS_CFUNC_DEF("get_tracked_object_type_count", 0, &rendering_device_class_get_tracked_object_type_count),
	JS_CFUNC_DEF("get_driver_total_memory", 0, &rendering_device_class_get_driver_total_memory),
	JS_CFUNC_DEF("get_driver_allocation_count", 0, &rendering_device_class_get_driver_allocation_count),
	JS_CFUNC_DEF("get_driver_memory_by_object_type", 1, &rendering_device_class_get_driver_memory_by_object_type),
	JS_CFUNC_DEF("get_driver_allocs_by_object_type", 1, &rendering_device_class_get_driver_allocs_by_object_type),
	JS_CFUNC_DEF("get_device_total_memory", 0, &rendering_device_class_get_device_total_memory),
	JS_CFUNC_DEF("get_device_allocation_count", 0, &rendering_device_class_get_device_allocation_count),
	JS_CFUNC_DEF("get_device_memory_by_object_type", 1, &rendering_device_class_get_device_memory_by_object_type),
	JS_CFUNC_DEF("get_device_allocs_by_object_type", 1, &rendering_device_class_get_device_allocs_by_object_type),
};




static void define_rendering_device_property(JSContext *ctx, JSValue proto) {
}

static void define_rendering_device_enum(JSContext *ctx, JSValue ctor) {
	JSValue DeviceType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DeviceType_obj, "DEVICE_TYPE_OTHER", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DeviceType_obj, "DEVICE_TYPE_INTEGRATED_GPU", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DeviceType_obj, "DEVICE_TYPE_DISCRETE_GPU", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DeviceType_obj, "DEVICE_TYPE_VIRTUAL_GPU", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DeviceType_obj, "DEVICE_TYPE_CPU", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DeviceType_obj, "DEVICE_TYPE_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "DeviceType", DeviceType_obj);
	JSValue DriverResource_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_LOGICAL_DEVICE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_PHYSICAL_DEVICE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_TOPMOST_OBJECT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_COMMAND_QUEUE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_QUEUE_FAMILY", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_TEXTURE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_TEXTURE_VIEW", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_TEXTURE_DATA_FORMAT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_SAMPLER", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_UNIFORM_SET", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_BUFFER", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_COMPUTE_PIPELINE", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_RENDER_PIPELINE", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_DEVICE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_PHYSICAL_DEVICE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_INSTANCE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_QUEUE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_QUEUE_FAMILY_INDEX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_IMAGE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_IMAGE_VIEW", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_IMAGE_NATIVE_TEXTURE_FORMAT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_SAMPLER", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_DESCRIPTOR_SET", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_BUFFER", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_COMPUTE_PIPELINE", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, DriverResource_obj, "DRIVER_RESOURCE_VULKAN_RENDER_PIPELINE", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, ctor, "DriverResource", DriverResource_obj);
	JSValue DataFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R4G4_UNORM_PACK8", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R4G4B4A4_UNORM_PACK16", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B4G4R4A4_UNORM_PACK16", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R5G6B5_UNORM_PACK16", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B5G6R5_UNORM_PACK16", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R5G5B5A1_UNORM_PACK16", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B5G5R5A1_UNORM_PACK16", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A1R5G5B5_UNORM_PACK16", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_UNORM", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_SNORM", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_USCALED", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_SSCALED", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_UINT", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_SINT", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8_SRGB", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_UNORM", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_SNORM", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_USCALED", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_SSCALED", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_UINT", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_SINT", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8_SRGB", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_UNORM", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_SNORM", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_USCALED", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_SSCALED", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_UINT", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_SINT", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8_SRGB", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_UNORM", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_SNORM", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_USCALED", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_SSCALED", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_UINT", JS_NewInt64(ctx, 33));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_SINT", JS_NewInt64(ctx, 34));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8_SRGB", JS_NewInt64(ctx, 35));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_UNORM", JS_NewInt64(ctx, 36));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_SNORM", JS_NewInt64(ctx, 37));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_USCALED", JS_NewInt64(ctx, 38));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_SSCALED", JS_NewInt64(ctx, 39));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_UINT", JS_NewInt64(ctx, 40));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_SINT", JS_NewInt64(ctx, 41));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R8G8B8A8_SRGB", JS_NewInt64(ctx, 42));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_UNORM", JS_NewInt64(ctx, 43));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_SNORM", JS_NewInt64(ctx, 44));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_USCALED", JS_NewInt64(ctx, 45));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_SSCALED", JS_NewInt64(ctx, 46));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_UINT", JS_NewInt64(ctx, 47));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_SINT", JS_NewInt64(ctx, 48));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8A8_SRGB", JS_NewInt64(ctx, 49));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_UNORM_PACK32", JS_NewInt64(ctx, 50));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_SNORM_PACK32", JS_NewInt64(ctx, 51));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_USCALED_PACK32", JS_NewInt64(ctx, 52));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_SSCALED_PACK32", JS_NewInt64(ctx, 53));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_UINT_PACK32", JS_NewInt64(ctx, 54));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_SINT_PACK32", JS_NewInt64(ctx, 55));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A8B8G8R8_SRGB_PACK32", JS_NewInt64(ctx, 56));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2R10G10B10_UNORM_PACK32", JS_NewInt64(ctx, 57));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2R10G10B10_SNORM_PACK32", JS_NewInt64(ctx, 58));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2R10G10B10_USCALED_PACK32", JS_NewInt64(ctx, 59));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2R10G10B10_SSCALED_PACK32", JS_NewInt64(ctx, 60));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2R10G10B10_UINT_PACK32", JS_NewInt64(ctx, 61));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2R10G10B10_SINT_PACK32", JS_NewInt64(ctx, 62));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2B10G10R10_UNORM_PACK32", JS_NewInt64(ctx, 63));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2B10G10R10_SNORM_PACK32", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2B10G10R10_USCALED_PACK32", JS_NewInt64(ctx, 65));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2B10G10R10_SSCALED_PACK32", JS_NewInt64(ctx, 66));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2B10G10R10_UINT_PACK32", JS_NewInt64(ctx, 67));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_A2B10G10R10_SINT_PACK32", JS_NewInt64(ctx, 68));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_UNORM", JS_NewInt64(ctx, 69));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_SNORM", JS_NewInt64(ctx, 70));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_USCALED", JS_NewInt64(ctx, 71));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_SSCALED", JS_NewInt64(ctx, 72));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_UINT", JS_NewInt64(ctx, 73));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_SINT", JS_NewInt64(ctx, 74));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16_SFLOAT", JS_NewInt64(ctx, 75));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_UNORM", JS_NewInt64(ctx, 76));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_SNORM", JS_NewInt64(ctx, 77));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_USCALED", JS_NewInt64(ctx, 78));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_SSCALED", JS_NewInt64(ctx, 79));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_UINT", JS_NewInt64(ctx, 80));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_SINT", JS_NewInt64(ctx, 81));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16_SFLOAT", JS_NewInt64(ctx, 82));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_UNORM", JS_NewInt64(ctx, 83));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_SNORM", JS_NewInt64(ctx, 84));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_USCALED", JS_NewInt64(ctx, 85));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_SSCALED", JS_NewInt64(ctx, 86));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_UINT", JS_NewInt64(ctx, 87));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_SINT", JS_NewInt64(ctx, 88));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16_SFLOAT", JS_NewInt64(ctx, 89));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_UNORM", JS_NewInt64(ctx, 90));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_SNORM", JS_NewInt64(ctx, 91));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_USCALED", JS_NewInt64(ctx, 92));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_SSCALED", JS_NewInt64(ctx, 93));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_UINT", JS_NewInt64(ctx, 94));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_SINT", JS_NewInt64(ctx, 95));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R16G16B16A16_SFLOAT", JS_NewInt64(ctx, 96));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32_UINT", JS_NewInt64(ctx, 97));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32_SINT", JS_NewInt64(ctx, 98));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32_SFLOAT", JS_NewInt64(ctx, 99));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32_UINT", JS_NewInt64(ctx, 100));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32_SINT", JS_NewInt64(ctx, 101));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32_SFLOAT", JS_NewInt64(ctx, 102));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32B32_UINT", JS_NewInt64(ctx, 103));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32B32_SINT", JS_NewInt64(ctx, 104));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32B32_SFLOAT", JS_NewInt64(ctx, 105));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32B32A32_UINT", JS_NewInt64(ctx, 106));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32B32A32_SINT", JS_NewInt64(ctx, 107));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R32G32B32A32_SFLOAT", JS_NewInt64(ctx, 108));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64_UINT", JS_NewInt64(ctx, 109));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64_SINT", JS_NewInt64(ctx, 110));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64_SFLOAT", JS_NewInt64(ctx, 111));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64_UINT", JS_NewInt64(ctx, 112));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64_SINT", JS_NewInt64(ctx, 113));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64_SFLOAT", JS_NewInt64(ctx, 114));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64B64_UINT", JS_NewInt64(ctx, 115));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64B64_SINT", JS_NewInt64(ctx, 116));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64B64_SFLOAT", JS_NewInt64(ctx, 117));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64B64A64_UINT", JS_NewInt64(ctx, 118));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64B64A64_SINT", JS_NewInt64(ctx, 119));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R64G64B64A64_SFLOAT", JS_NewInt64(ctx, 120));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B10G11R11_UFLOAT_PACK32", JS_NewInt64(ctx, 121));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_E5B9G9R9_UFLOAT_PACK32", JS_NewInt64(ctx, 122));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_D16_UNORM", JS_NewInt64(ctx, 123));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_X8_D24_UNORM_PACK32", JS_NewInt64(ctx, 124));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_D32_SFLOAT", JS_NewInt64(ctx, 125));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_S8_UINT", JS_NewInt64(ctx, 126));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_D16_UNORM_S8_UINT", JS_NewInt64(ctx, 127));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_D24_UNORM_S8_UINT", JS_NewInt64(ctx, 128));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_D32_SFLOAT_S8_UINT", JS_NewInt64(ctx, 129));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC1_RGB_UNORM_BLOCK", JS_NewInt64(ctx, 130));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC1_RGB_SRGB_BLOCK", JS_NewInt64(ctx, 131));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC1_RGBA_UNORM_BLOCK", JS_NewInt64(ctx, 132));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC1_RGBA_SRGB_BLOCK", JS_NewInt64(ctx, 133));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC2_UNORM_BLOCK", JS_NewInt64(ctx, 134));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC2_SRGB_BLOCK", JS_NewInt64(ctx, 135));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC3_UNORM_BLOCK", JS_NewInt64(ctx, 136));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC3_SRGB_BLOCK", JS_NewInt64(ctx, 137));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC4_UNORM_BLOCK", JS_NewInt64(ctx, 138));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC4_SNORM_BLOCK", JS_NewInt64(ctx, 139));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC5_UNORM_BLOCK", JS_NewInt64(ctx, 140));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC5_SNORM_BLOCK", JS_NewInt64(ctx, 141));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC6H_UFLOAT_BLOCK", JS_NewInt64(ctx, 142));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC6H_SFLOAT_BLOCK", JS_NewInt64(ctx, 143));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC7_UNORM_BLOCK", JS_NewInt64(ctx, 144));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_BC7_SRGB_BLOCK", JS_NewInt64(ctx, 145));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ETC2_R8G8B8_UNORM_BLOCK", JS_NewInt64(ctx, 146));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ETC2_R8G8B8_SRGB_BLOCK", JS_NewInt64(ctx, 147));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK", JS_NewInt64(ctx, 148));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK", JS_NewInt64(ctx, 149));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK", JS_NewInt64(ctx, 150));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK", JS_NewInt64(ctx, 151));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_EAC_R11_UNORM_BLOCK", JS_NewInt64(ctx, 152));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_EAC_R11_SNORM_BLOCK", JS_NewInt64(ctx, 153));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_EAC_R11G11_UNORM_BLOCK", JS_NewInt64(ctx, 154));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_EAC_R11G11_SNORM_BLOCK", JS_NewInt64(ctx, 155));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_4x4_UNORM_BLOCK", JS_NewInt64(ctx, 156));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_4x4_SRGB_BLOCK", JS_NewInt64(ctx, 157));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_5x4_UNORM_BLOCK", JS_NewInt64(ctx, 158));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_5x4_SRGB_BLOCK", JS_NewInt64(ctx, 159));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_5x5_UNORM_BLOCK", JS_NewInt64(ctx, 160));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_5x5_SRGB_BLOCK", JS_NewInt64(ctx, 161));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_6x5_UNORM_BLOCK", JS_NewInt64(ctx, 162));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_6x5_SRGB_BLOCK", JS_NewInt64(ctx, 163));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_6x6_UNORM_BLOCK", JS_NewInt64(ctx, 164));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_6x6_SRGB_BLOCK", JS_NewInt64(ctx, 165));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x5_UNORM_BLOCK", JS_NewInt64(ctx, 166));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x5_SRGB_BLOCK", JS_NewInt64(ctx, 167));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x6_UNORM_BLOCK", JS_NewInt64(ctx, 168));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x6_SRGB_BLOCK", JS_NewInt64(ctx, 169));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x8_UNORM_BLOCK", JS_NewInt64(ctx, 170));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x8_SRGB_BLOCK", JS_NewInt64(ctx, 171));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x5_UNORM_BLOCK", JS_NewInt64(ctx, 172));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x5_SRGB_BLOCK", JS_NewInt64(ctx, 173));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x6_UNORM_BLOCK", JS_NewInt64(ctx, 174));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x6_SRGB_BLOCK", JS_NewInt64(ctx, 175));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x8_UNORM_BLOCK", JS_NewInt64(ctx, 176));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x8_SRGB_BLOCK", JS_NewInt64(ctx, 177));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x10_UNORM_BLOCK", JS_NewInt64(ctx, 178));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x10_SRGB_BLOCK", JS_NewInt64(ctx, 179));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_12x10_UNORM_BLOCK", JS_NewInt64(ctx, 180));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_12x10_SRGB_BLOCK", JS_NewInt64(ctx, 181));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_12x12_UNORM_BLOCK", JS_NewInt64(ctx, 182));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_12x12_SRGB_BLOCK", JS_NewInt64(ctx, 183));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G8B8G8R8_422_UNORM", JS_NewInt64(ctx, 184));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B8G8R8G8_422_UNORM", JS_NewInt64(ctx, 185));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G8_B8_R8_3PLANE_420_UNORM", JS_NewInt64(ctx, 186));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G8_B8R8_2PLANE_420_UNORM", JS_NewInt64(ctx, 187));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G8_B8_R8_3PLANE_422_UNORM", JS_NewInt64(ctx, 188));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G8_B8R8_2PLANE_422_UNORM", JS_NewInt64(ctx, 189));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G8_B8_R8_3PLANE_444_UNORM", JS_NewInt64(ctx, 190));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R10X6_UNORM_PACK16", JS_NewInt64(ctx, 191));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R10X6G10X6_UNORM_2PACK16", JS_NewInt64(ctx, 192));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16", JS_NewInt64(ctx, 193));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16", JS_NewInt64(ctx, 194));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16", JS_NewInt64(ctx, 195));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16", JS_NewInt64(ctx, 196));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16", JS_NewInt64(ctx, 197));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16", JS_NewInt64(ctx, 198));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16", JS_NewInt64(ctx, 199));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16", JS_NewInt64(ctx, 200));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R12X4_UNORM_PACK16", JS_NewInt64(ctx, 201));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R12X4G12X4_UNORM_2PACK16", JS_NewInt64(ctx, 202));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16", JS_NewInt64(ctx, 203));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16", JS_NewInt64(ctx, 204));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16", JS_NewInt64(ctx, 205));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16", JS_NewInt64(ctx, 206));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16", JS_NewInt64(ctx, 207));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16", JS_NewInt64(ctx, 208));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16", JS_NewInt64(ctx, 209));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16", JS_NewInt64(ctx, 210));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G16B16G16R16_422_UNORM", JS_NewInt64(ctx, 211));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_B16G16R16G16_422_UNORM", JS_NewInt64(ctx, 212));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G16_B16_R16_3PLANE_420_UNORM", JS_NewInt64(ctx, 213));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G16_B16R16_2PLANE_420_UNORM", JS_NewInt64(ctx, 214));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G16_B16_R16_3PLANE_422_UNORM", JS_NewInt64(ctx, 215));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G16_B16R16_2PLANE_422_UNORM", JS_NewInt64(ctx, 216));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_G16_B16_R16_3PLANE_444_UNORM", JS_NewInt64(ctx, 217));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_4x4_SFLOAT_BLOCK", JS_NewInt64(ctx, 218));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_5x4_SFLOAT_BLOCK", JS_NewInt64(ctx, 219));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_5x5_SFLOAT_BLOCK", JS_NewInt64(ctx, 220));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_6x5_SFLOAT_BLOCK", JS_NewInt64(ctx, 221));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_6x6_SFLOAT_BLOCK", JS_NewInt64(ctx, 222));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x5_SFLOAT_BLOCK", JS_NewInt64(ctx, 223));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x6_SFLOAT_BLOCK", JS_NewInt64(ctx, 224));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_8x8_SFLOAT_BLOCK", JS_NewInt64(ctx, 225));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x5_SFLOAT_BLOCK", JS_NewInt64(ctx, 226));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x6_SFLOAT_BLOCK", JS_NewInt64(ctx, 227));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x8_SFLOAT_BLOCK", JS_NewInt64(ctx, 228));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_10x10_SFLOAT_BLOCK", JS_NewInt64(ctx, 229));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_12x10_SFLOAT_BLOCK", JS_NewInt64(ctx, 230));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_ASTC_12x12_SFLOAT_BLOCK", JS_NewInt64(ctx, 231));
	JS_SetPropertyStr(ctx, DataFormat_obj, "DATA_FORMAT_MAX", JS_NewInt64(ctx, 232));
	JS_SetPropertyStr(ctx, ctor, "DataFormat", DataFormat_obj);
	JSValue BarrierMask_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_VERTEX", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_FRAGMENT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_COMPUTE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_TRANSFER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_RASTER", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_ALL_BARRIERS", JS_NewInt64(ctx, 32767));
	JS_SetPropertyStr(ctx, BarrierMask_obj, "BARRIER_MASK_NO_BARRIER", JS_NewInt64(ctx, 32768));
	JS_SetPropertyStr(ctx, ctor, "BarrierMask", BarrierMask_obj);
	JSValue TextureType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_1D", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_2D", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_3D", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_CUBE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_1D_ARRAY", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_2D_ARRAY", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_CUBE_ARRAY", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, TextureType_obj, "TEXTURE_TYPE_MAX", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "TextureType", TextureType_obj);
	JSValue TextureSamples_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_1", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_2", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_4", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_8", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_16", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_32", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_64", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, TextureSamples_obj, "TEXTURE_SAMPLES_MAX", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "TextureSamples", TextureSamples_obj);
	JSValue TextureUsageBits_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_SAMPLING_BIT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_COLOR_ATTACHMENT_BIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_STORAGE_BIT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_STORAGE_ATOMIC_BIT", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_CPU_READ_BIT", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_CAN_UPDATE_BIT", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_CAN_COPY_FROM_BIT", JS_NewInt64(ctx, 128));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_CAN_COPY_TO_BIT", JS_NewInt64(ctx, 256));
	JS_SetPropertyStr(ctx, TextureUsageBits_obj, "TEXTURE_USAGE_INPUT_ATTACHMENT_BIT", JS_NewInt64(ctx, 512));
	JS_SetPropertyStr(ctx, ctor, "TextureUsageBits", TextureUsageBits_obj);
	JSValue TextureSwizzle_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_IDENTITY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_ZERO", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_ONE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_R", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_G", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_B", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_A", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, TextureSwizzle_obj, "TEXTURE_SWIZZLE_MAX", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "TextureSwizzle", TextureSwizzle_obj);
	JSValue TextureSliceType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureSliceType_obj, "TEXTURE_SLICE_2D", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureSliceType_obj, "TEXTURE_SLICE_CUBEMAP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureSliceType_obj, "TEXTURE_SLICE_3D", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TextureSliceType", TextureSliceType_obj);
	JSValue SamplerFilter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SamplerFilter_obj, "SAMPLER_FILTER_NEAREST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SamplerFilter_obj, "SAMPLER_FILTER_LINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "SamplerFilter", SamplerFilter_obj);
	JSValue SamplerRepeatMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SamplerRepeatMode_obj, "SAMPLER_REPEAT_MODE_REPEAT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SamplerRepeatMode_obj, "SAMPLER_REPEAT_MODE_MIRRORED_REPEAT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SamplerRepeatMode_obj, "SAMPLER_REPEAT_MODE_CLAMP_TO_EDGE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SamplerRepeatMode_obj, "SAMPLER_REPEAT_MODE_CLAMP_TO_BORDER", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SamplerRepeatMode_obj, "SAMPLER_REPEAT_MODE_MIRROR_CLAMP_TO_EDGE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, SamplerRepeatMode_obj, "SAMPLER_REPEAT_MODE_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "SamplerRepeatMode", SamplerRepeatMode_obj);
	JSValue SamplerBorderColor_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_INT_TRANSPARENT_BLACK", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_FLOAT_OPAQUE_BLACK", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_INT_OPAQUE_BLACK", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_FLOAT_OPAQUE_WHITE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_INT_OPAQUE_WHITE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, SamplerBorderColor_obj, "SAMPLER_BORDER_COLOR_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "SamplerBorderColor", SamplerBorderColor_obj);
	JSValue VertexFrequency_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VertexFrequency_obj, "VERTEX_FREQUENCY_VERTEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VertexFrequency_obj, "VERTEX_FREQUENCY_INSTANCE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "VertexFrequency", VertexFrequency_obj);
	JSValue IndexBufferFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, IndexBufferFormat_obj, "INDEX_BUFFER_FORMAT_UINT16", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, IndexBufferFormat_obj, "INDEX_BUFFER_FORMAT_UINT32", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "IndexBufferFormat", IndexBufferFormat_obj);
	JSValue StorageBufferUsage_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, StorageBufferUsage_obj, "STORAGE_BUFFER_USAGE_DISPATCH_INDIRECT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "StorageBufferUsage", StorageBufferUsage_obj);
	JSValue BufferCreationBits_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BufferCreationBits_obj, "BUFFER_CREATION_DEVICE_ADDRESS_BIT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BufferCreationBits_obj, "BUFFER_CREATION_AS_STORAGE_BIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "BufferCreationBits", BufferCreationBits_obj);
	JSValue UniformType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_SAMPLER", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_SAMPLER_WITH_TEXTURE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_TEXTURE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_IMAGE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_TEXTURE_BUFFER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_SAMPLER_WITH_TEXTURE_BUFFER", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_IMAGE_BUFFER", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_UNIFORM_BUFFER", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_STORAGE_BUFFER", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_INPUT_ATTACHMENT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, UniformType_obj, "UNIFORM_TYPE_MAX", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, ctor, "UniformType", UniformType_obj);
	JSValue RenderPrimitive_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_POINTS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_LINES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_LINES_WITH_ADJACENCY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_LINESTRIPS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_LINESTRIPS_WITH_ADJACENCY", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_TRIANGLES", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_TRIANGLES_WITH_ADJACENCY", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_TRIANGLE_STRIPS", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_TRIANGLE_STRIPS_WITH_AJACENCY", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_TRIANGLE_STRIPS_WITH_RESTART_INDEX", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_TESSELATION_PATCH", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, RenderPrimitive_obj, "RENDER_PRIMITIVE_MAX", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, ctor, "RenderPrimitive", RenderPrimitive_obj);
	JSValue PolygonCullMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PolygonCullMode_obj, "POLYGON_CULL_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PolygonCullMode_obj, "POLYGON_CULL_FRONT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PolygonCullMode_obj, "POLYGON_CULL_BACK", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PolygonCullMode", PolygonCullMode_obj);
	JSValue PolygonFrontFace_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PolygonFrontFace_obj, "POLYGON_FRONT_FACE_CLOCKWISE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PolygonFrontFace_obj, "POLYGON_FRONT_FACE_COUNTER_CLOCKWISE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "PolygonFrontFace", PolygonFrontFace_obj);
	JSValue StencilOperation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_KEEP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_ZERO", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_REPLACE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_INCREMENT_AND_CLAMP", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_DECREMENT_AND_CLAMP", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_INVERT", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_INCREMENT_AND_WRAP", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_DECREMENT_AND_WRAP", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, StencilOperation_obj, "STENCIL_OP_MAX", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "StencilOperation", StencilOperation_obj);
	JSValue CompareOperator_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_NEVER", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_LESS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_EQUAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_LESS_OR_EQUAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_GREATER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_NOT_EQUAL", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_GREATER_OR_EQUAL", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_ALWAYS", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CompareOperator_obj, "COMPARE_OP_MAX", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "CompareOperator", CompareOperator_obj);
	JSValue LogicOperation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_CLEAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_AND", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_AND_REVERSE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_COPY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_AND_INVERTED", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_NO_OP", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_XOR", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_OR", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_NOR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_EQUIVALENT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_INVERT", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_OR_REVERSE", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_COPY_INVERTED", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_OR_INVERTED", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_NAND", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_SET", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, LogicOperation_obj, "LOGIC_OP_MAX", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ctor, "LogicOperation", LogicOperation_obj);
	JSValue BlendFactor_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ZERO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_SRC_COLOR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_SRC_COLOR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_DST_COLOR", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_DST_COLOR", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_SRC_ALPHA", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_SRC_ALPHA", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_DST_ALPHA", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_DST_ALPHA", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_CONSTANT_COLOR", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_CONSTANT_ALPHA", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_SRC_ALPHA_SATURATE", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_SRC1_COLOR", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_SRC1_COLOR", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_SRC1_ALPHA", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, BlendFactor_obj, "BLEND_FACTOR_MAX", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, ctor, "BlendFactor", BlendFactor_obj);
	JSValue BlendOperation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendOperation_obj, "BLEND_OP_ADD", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendOperation_obj, "BLEND_OP_SUBTRACT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendOperation_obj, "BLEND_OP_REVERSE_SUBTRACT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BlendOperation_obj, "BLEND_OP_MINIMUM", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BlendOperation_obj, "BLEND_OP_MAXIMUM", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BlendOperation_obj, "BLEND_OP_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "BlendOperation", BlendOperation_obj);
	JSValue PipelineDynamicStateFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_LINE_WIDTH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_DEPTH_BIAS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_BLEND_CONSTANTS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_DEPTH_BOUNDS", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_STENCIL_COMPARE_MASK", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_STENCIL_WRITE_MASK", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, PipelineDynamicStateFlags_obj, "DYNAMIC_STATE_STENCIL_REFERENCE", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, ctor, "PipelineDynamicStateFlags", PipelineDynamicStateFlags_obj);
	JSValue InitialAction_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_LOAD", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_CLEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_DISCARD", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_CLEAR_REGION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_CLEAR_REGION_CONTINUE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_KEEP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_DROP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, InitialAction_obj, "INITIAL_ACTION_CONTINUE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ctor, "InitialAction", InitialAction_obj);
	JSValue FinalAction_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FinalAction_obj, "FINAL_ACTION_STORE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FinalAction_obj, "FINAL_ACTION_DISCARD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FinalAction_obj, "FINAL_ACTION_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FinalAction_obj, "FINAL_ACTION_READ", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FinalAction_obj, "FINAL_ACTION_CONTINUE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ctor, "FinalAction", FinalAction_obj);
	JSValue ShaderStage_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_VERTEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_FRAGMENT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_TESSELATION_CONTROL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_TESSELATION_EVALUATION", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_COMPUTE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_VERTEX_BIT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_FRAGMENT_BIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_TESSELATION_CONTROL_BIT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_TESSELATION_EVALUATION_BIT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ShaderStage_obj, "SHADER_STAGE_COMPUTE_BIT", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ctor, "ShaderStage", ShaderStage_obj);
	JSValue ShaderLanguage_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShaderLanguage_obj, "SHADER_LANGUAGE_GLSL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShaderLanguage_obj, "SHADER_LANGUAGE_HLSL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "ShaderLanguage", ShaderLanguage_obj);
	JSValue PipelineSpecializationConstantType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PipelineSpecializationConstantType_obj, "PIPELINE_SPECIALIZATION_CONSTANT_TYPE_BOOL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PipelineSpecializationConstantType_obj, "PIPELINE_SPECIALIZATION_CONSTANT_TYPE_INT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PipelineSpecializationConstantType_obj, "PIPELINE_SPECIALIZATION_CONSTANT_TYPE_FLOAT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PipelineSpecializationConstantType", PipelineSpecializationConstantType_obj);
	JSValue Features_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Features_obj, "SUPPORTS_METALFX_SPATIAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Features_obj, "SUPPORTS_METALFX_TEMPORAL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Features_obj, "SUPPORTS_BUFFER_DEVICE_ADDRESS", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Features_obj, "SUPPORTS_IMAGE_ATOMIC_32_BIT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "Features", Features_obj);
	JSValue Limit_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_BOUND_UNIFORM_SETS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_FRAMEBUFFER_COLOR_ATTACHMENTS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURES_PER_UNIFORM_SET", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_SAMPLERS_PER_UNIFORM_SET", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_STORAGE_BUFFERS_PER_UNIFORM_SET", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_STORAGE_IMAGES_PER_UNIFORM_SET", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_UNIFORM_BUFFERS_PER_UNIFORM_SET", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_DRAW_INDEXED_INDEX", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_FRAMEBUFFER_HEIGHT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_FRAMEBUFFER_WIDTH", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURE_ARRAY_LAYERS", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURE_SIZE_1D", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURE_SIZE_2D", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURE_SIZE_3D", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURE_SIZE_CUBE", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_TEXTURES_PER_SHADER_STAGE", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_SAMPLERS_PER_SHADER_STAGE", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_STORAGE_BUFFERS_PER_SHADER_STAGE", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_STORAGE_IMAGES_PER_SHADER_STAGE", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_UNIFORM_BUFFERS_PER_SHADER_STAGE", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_PUSH_CONSTANT_SIZE", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_UNIFORM_BUFFER_SIZE", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_VERTEX_INPUT_ATTRIBUTES", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_VERTEX_INPUT_BINDINGS", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_VERTEX_INPUT_BINDING_STRIDE", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MIN_UNIFORM_BUFFER_OFFSET_ALIGNMENT", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_SHARED_MEMORY_SIZE", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_COUNT_X", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_COUNT_Y", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_COUNT_Z", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_INVOCATIONS", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_SIZE_X", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_SIZE_Y", JS_NewInt64(ctx, 33));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_COMPUTE_WORKGROUP_SIZE_Z", JS_NewInt64(ctx, 34));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_VIEWPORT_DIMENSIONS_X", JS_NewInt64(ctx, 35));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_MAX_VIEWPORT_DIMENSIONS_Y", JS_NewInt64(ctx, 36));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_METALFX_TEMPORAL_SCALER_MIN_SCALE", JS_NewInt64(ctx, 46));
	JS_SetPropertyStr(ctx, Limit_obj, "LIMIT_METALFX_TEMPORAL_SCALER_MAX_SCALE", JS_NewInt64(ctx, 47));
	JS_SetPropertyStr(ctx, ctor, "Limit", Limit_obj);
	JSValue MemoryType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, MemoryType_obj, "MEMORY_TEXTURES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, MemoryType_obj, "MEMORY_BUFFERS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, MemoryType_obj, "MEMORY_TOTAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "MemoryType", MemoryType_obj);
	JSValue BreadcrumbMarker_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "REFLECTION_PROBES", JS_NewInt64(ctx, 65536));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "SKY_PASS", JS_NewInt64(ctx, 131072));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "LIGHTMAPPER_PASS", JS_NewInt64(ctx, 196608));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "SHADOW_PASS_DIRECTIONAL", JS_NewInt64(ctx, 262144));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "SHADOW_PASS_CUBE", JS_NewInt64(ctx, 327680));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "OPAQUE_PASS", JS_NewInt64(ctx, 393216));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "ALPHA_PASS", JS_NewInt64(ctx, 458752));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "TRANSPARENT_PASS", JS_NewInt64(ctx, 524288));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "POST_PROCESSING_PASS", JS_NewInt64(ctx, 589824));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "BLIT_PASS", JS_NewInt64(ctx, 655360));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "UI_PASS", JS_NewInt64(ctx, 720896));
	JS_SetPropertyStr(ctx, BreadcrumbMarker_obj, "DEBUG_PASS", JS_NewInt64(ctx, 786432));
	JS_SetPropertyStr(ctx, ctor, "BreadcrumbMarker", BreadcrumbMarker_obj);
	JSValue DrawFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_DEFAULT_ALL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_0", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_1", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_2", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_3", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_4", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_5", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_6", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_7", JS_NewInt64(ctx, 128));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_MASK", JS_NewInt64(ctx, 255));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_COLOR_ALL", JS_NewInt64(ctx, 255));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_0", JS_NewInt64(ctx, 256));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_1", JS_NewInt64(ctx, 512));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_2", JS_NewInt64(ctx, 1024));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_3", JS_NewInt64(ctx, 2048));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_4", JS_NewInt64(ctx, 4096));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_5", JS_NewInt64(ctx, 8192));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_6", JS_NewInt64(ctx, 16384));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_7", JS_NewInt64(ctx, 32768));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_MASK", JS_NewInt64(ctx, 65280));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_COLOR_ALL", JS_NewInt64(ctx, 65280));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_DEPTH", JS_NewInt64(ctx, 65536));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_DEPTH", JS_NewInt64(ctx, 131072));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_STENCIL", JS_NewInt64(ctx, 262144));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_STENCIL", JS_NewInt64(ctx, 524288));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_CLEAR_ALL", JS_NewInt64(ctx, 327935));
	JS_SetPropertyStr(ctx, DrawFlags_obj, "DRAW_IGNORE_ALL", JS_NewInt64(ctx, 720640));
	JS_SetPropertyStr(ctx, ctor, "DrawFlags", DrawFlags_obj);
}

static int js_rendering_device_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RenderingDevice"] = class_id;
	classes_by_id[class_id] = "RenderingDevice";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rendering_device_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rendering_device_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rendering_device_class_proto_funcs, _countof(rendering_device_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rendering_device_class_constructor, "RenderingDevice", 0, JS_CFUNC_constructor, 0);
	define_rendering_device_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RenderingDevice", ctor);

	return 0;
}

JSModuleDef *_js_init_rendering_device_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rendering_device_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RenderingDevice");
	return m;
}

JSModuleDef *js_init_rendering_device_module(JSContext *ctx) {
	return _js_init_rendering_device_module(ctx, "@godot/classes/rendering_device");
}

void __register_rendering_device() {
	js_init_rendering_device_module(js_context());
}

void register_rendering_device() {
	__register_rendering_device();
}