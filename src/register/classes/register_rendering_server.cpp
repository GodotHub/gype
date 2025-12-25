#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/rendering_device.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/rendering_server.hpp>


using namespace godot;

static void rendering_server_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef rendering_server_class_def = {
	"_RenderingServer",
	rendering_server_class_finalizer
};

static JSValue rendering_server_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["RenderingServer"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	RenderingServer *rendering_server_class = RenderingServer::get_singleton();
	if (!rendering_server_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, rendering_server_class);
	return obj;
}

static JSValue rendering_server_class_texture_2d_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_2d_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_2d_layered_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_2d_layered_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_3d_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_3d_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_proxy_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_proxy_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_create_from_native_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_create_from_native_handle, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_2d_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_2d_update, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_3d_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_3d_update, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_proxy_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_proxy_update, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_2d_placeholder_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_2d_placeholder_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_2d_layered_placeholder_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_2d_layered_placeholder_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_3d_placeholder_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_3d_placeholder_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_2d_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_2d_get, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_2d_layer_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_2d_layer_get, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_3d_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_3d_get, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_replace(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_replace, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_set_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_set_size_override, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_set_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_set_path, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_get_path, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_get_format, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_set_force_redraw_if_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::texture_set_force_redraw_if_visible, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_texture_rd_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::texture_rd_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_get_rd_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_get_rd_texture, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_texture_get_native_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::texture_get_native_handle, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_shader_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::shader_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_shader_set_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::shader_set_code, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_shader_set_path_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::shader_set_path_hint, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_shader_get_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::shader_get_code, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_shader_parameter_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_shader_parameter_list, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_shader_get_parameter_default(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::shader_get_parameter_default, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_shader_set_default_texture_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::shader_set_default_texture_parameter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_shader_get_default_texture_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::shader_get_default_texture_parameter, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_material_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::material_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_material_set_shader(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::material_set_shader, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_material_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::material_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_material_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::material_get_param, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_material_set_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::material_set_render_priority, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_material_set_next_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::material_set_next_pass, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_create_from_surfaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::mesh_create_from_surfaces, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::mesh_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_format_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_format_offset, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_format_vertex_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_format_vertex_stride, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_format_normal_tangent_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_format_normal_tangent_stride, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_format_attribute_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_format_attribute_stride, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_format_skin_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_format_skin_stride, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_format_index_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_format_index_stride, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_add_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_add_surface, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_add_surface_from_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_add_surface_from_arrays, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_get_blend_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_get_blend_shape_count, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_set_blend_shape_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_set_blend_shape_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_get_blend_shape_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_get_blend_shape_mode, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_surface_set_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_surface_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_material, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_get_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::mesh_get_surface, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_arrays, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_get_blend_shape_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_surface_get_blend_shape_arrays, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_get_surface_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_get_surface_count, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_set_custom_aabb, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_get_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::mesh_get_custom_aabb, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_mesh_surface_remove(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_surface_remove, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_surface_update_vertex_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_surface_update_vertex_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_surface_update_attribute_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_surface_update_attribute_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_surface_update_skin_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_surface_update_skin_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_surface_update_index_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_surface_update_index_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_mesh_set_shadow_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::mesh_set_shadow_mesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::multimesh_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_allocate_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_allocate_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_get_instance_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_instance_count, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_mesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_instance_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_instance_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_instance_set_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_instance_set_transform_2d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_instance_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_instance_set_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_instance_set_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_instance_set_custom_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_mesh, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_get_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_aabb, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_custom_aabb, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_get_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_custom_aabb, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_instance_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_instance_get_transform, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_instance_get_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_instance_get_transform_2d, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_instance_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_instance_get_color, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_instance_get_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_instance_get_custom_data, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_set_visible_instances(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_visible_instances, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_get_visible_instances(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_visible_instances, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_set_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_buffer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_get_command_buffer_rd_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_command_buffer_rd_rid, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_get_buffer_rd_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_buffer_rd_rid, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_get_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::multimesh_get_buffer, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_multimesh_set_buffer_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_buffer_interpolated, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_set_physics_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_physics_interpolated, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_set_physics_interpolation_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_set_physics_interpolation_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_multimesh_instance_reset_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::multimesh_instance_reset_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_skeleton_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::skeleton_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_skeleton_allocate_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::skeleton_allocate_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_skeleton_get_bone_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::skeleton_get_bone_count, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_skeleton_bone_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::skeleton_bone_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_skeleton_bone_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::skeleton_bone_get_transform, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_skeleton_bone_set_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::skeleton_bone_set_transform_2d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_skeleton_bone_get_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::skeleton_bone_get_transform_2d, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_skeleton_set_base_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::skeleton_set_base_transform_2d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_directional_light_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::directional_light_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_omni_light_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::omni_light_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_spot_light_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::spot_light_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_light_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_shadow, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_projector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_projector, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_negative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_negative, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_distance_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_distance_fade, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_reverse_cull_face_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_reverse_cull_face_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_shadow_caster_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_shadow_caster_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_bake_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_bake_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_set_max_sdfgi_cascade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_set_max_sdfgi_cascade, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_omni_set_shadow_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_omni_set_shadow_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_directional_set_shadow_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_directional_set_shadow_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_directional_set_blend_splits(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_directional_set_blend_splits, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_directional_set_sky_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_directional_set_sky_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_light_projectors_set_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::light_projectors_set_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmaps_set_bicubic_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmaps_set_bicubic_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_positional_soft_shadow_filter_set_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::positional_soft_shadow_filter_set_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_directional_soft_shadow_filter_set_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::directional_soft_shadow_filter_set_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_directional_shadow_atlas_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::directional_shadow_atlas_set_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::reflection_probe_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_reflection_probe_set_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_update_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_intensity, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_blend_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_blend_distance, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_ambient_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_ambient_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_ambient_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_ambient_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_ambient_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_ambient_energy, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_max_distance, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_origin_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_origin_offset, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_as_interior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_as_interior, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_enable_box_projection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_enable_box_projection, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_enable_shadows(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_enable_shadows, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_reflection_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_reflection_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_resolution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_resolution, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_reflection_probe_set_mesh_lod_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::reflection_probe_set_mesh_lod_threshold, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::decal_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_decal_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_texture, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_emission_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_emission_energy, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_albedo_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_albedo_mix, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_modulate, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_distance_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_distance_fade, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_fade, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decal_set_normal_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decal_set_normal_fade, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_decals_set_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::decals_set_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_gi_set_use_half_resolution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::gi_set_use_half_resolution, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::voxel_gi_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_allocate_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_allocate_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_get_octree_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::voxel_gi_get_octree_size, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_get_octree_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::voxel_gi_get_octree_cells, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_get_data_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::voxel_gi_get_data_cells, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_get_distance_field(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::voxel_gi_get_distance_field, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_get_level_counts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::voxel_gi_get_level_counts, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_get_to_cell_xform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::voxel_gi_get_to_cell_xform, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_voxel_gi_set_dynamic_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_dynamic_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_propagation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_propagation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_energy, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_baked_exposure_normalization(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_baked_exposure_normalization, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_bias, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_normal_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_normal_bias, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_interior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_interior, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_use_two_bounces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_use_two_bounces, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_voxel_gi_set_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::voxel_gi_set_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmap_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::lightmap_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_lightmap_set_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmap_set_textures, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmap_set_probe_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmap_set_probe_bounds, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmap_set_probe_interior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmap_set_probe_interior, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmap_set_probe_capture_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmap_set_probe_capture_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmap_get_probe_capture_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::lightmap_get_probe_capture_points, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_lightmap_get_probe_capture_sh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::lightmap_get_probe_capture_sh, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_lightmap_get_probe_capture_tetrahedra(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::lightmap_get_probe_capture_tetrahedra, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_lightmap_get_probe_capture_bsp_tree(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::lightmap_get_probe_capture_bsp_tree, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_lightmap_set_baked_exposure_normalization(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmap_set_baked_exposure_normalization, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_lightmap_set_probe_capture_update_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::lightmap_set_probe_capture_update_speed, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::particles_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_particles_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_emitting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_emitting, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_get_emitting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::particles_get_emitting, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_particles_set_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_amount, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_amount_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_amount_ratio, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_lifetime, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_one_shot, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_pre_process_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_pre_process_time, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_request_process_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_request_process_time, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_explosiveness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_explosiveness_ratio, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_randomness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_randomness_ratio, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_interp_to_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_interp_to_end, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_emitter_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_emitter_velocity, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_custom_aabb, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_speed_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_use_local_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_use_local_coordinates, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_process_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_process_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_fixed_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_fixed_fps, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_interpolate, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_fractional_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_fractional_delta, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_collision_base_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_collision_base_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_transform_align(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_transform_align, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_trails(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_trails, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_trail_bind_poses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_trail_bind_poses, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_is_inactive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::particles_is_inactive, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_particles_request_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_request_process, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_restart(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_restart, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_subemitter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_subemitter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_emit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_emit, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_draw_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_draw_order, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_draw_passes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_draw_passes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_set_draw_pass_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_draw_pass_mesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_get_current_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::particles_get_current_aabb, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_particles_set_emission_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_set_emission_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::particles_collision_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_particles_collision_set_collision_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_collision_type, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_sphere_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_sphere_radius, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_box_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_box_extents, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_attractor_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_attractor_strength, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_attractor_directionality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_attractor_directionality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_attractor_attenuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_attractor_attenuation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_field_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_field_texture, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_height_field_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_height_field_update, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_height_field_resolution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_height_field_resolution, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_particles_collision_set_height_field_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::particles_collision_set_height_field_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_fog_volume_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::fog_volume_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_fog_volume_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::fog_volume_set_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_fog_volume_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::fog_volume_set_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_fog_volume_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::fog_volume_set_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_visibility_notifier_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::visibility_notifier_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_visibility_notifier_set_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::visibility_notifier_set_aabb, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_visibility_notifier_set_callbacks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::visibility_notifier_set_callbacks, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_occluder_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::occluder_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_occluder_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::occluder_set_mesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::camera_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_camera_set_perspective(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_perspective, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_orthogonal, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_frustum(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_frustum, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_environment, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_camera_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_camera_attributes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_compositor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_compositor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_set_use_vertical_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_set_use_vertical_aspect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::viewport_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_set_use_xr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_use_xr, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_active, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_parent_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_parent_viewport, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_attach_to_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_attach_to_screen, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_render_direct_to_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_render_direct_to_screen, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_canvas_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_canvas_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_scaling_3d_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_scaling_3d_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_scaling_3d_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_scaling_3d_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_fsr_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_fsr_sharpness, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_texture_mipmap_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_texture_mipmap_bias, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_anisotropic_filtering_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_anisotropic_filtering_level, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_update_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_get_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::viewport_get_update_mode, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_set_clear_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_clear_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_get_render_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::viewport_get_render_target, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::viewport_get_texture, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_set_disable_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_disable_3d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_disable_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_disable_2d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_environment_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_environment_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_attach_camera(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_attach_camera, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_scenario(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_scenario, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_attach_canvas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_attach_canvas, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_remove_canvas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_remove_canvas, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_snap_2d_transforms_to_pixel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_snap_2d_transforms_to_pixel, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_snap_2d_vertices_to_pixel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_snap_2d_vertices_to_pixel, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_default_canvas_item_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_default_canvas_item_texture_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_default_canvas_item_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_default_canvas_item_texture_repeat, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_canvas_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_canvas_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_canvas_stacking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_canvas_stacking, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_transparent_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_transparent_background, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_global_canvas_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_global_canvas_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_sdf_oversize_and_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_sdf_oversize_and_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_positional_shadow_atlas_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_positional_shadow_atlas_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_positional_shadow_atlas_quadrant_subdivision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_positional_shadow_atlas_quadrant_subdivision, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_msaa_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_msaa_3d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_msaa_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_msaa_2d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_use_hdr_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_use_hdr_2d, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_screen_space_aa(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_screen_space_aa, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_use_taa(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_use_taa, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_use_debanding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_use_debanding, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_use_occlusion_culling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_use_occlusion_culling, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_occlusion_rays_per_thread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_occlusion_rays_per_thread, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_occlusion_culling_build_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_occlusion_culling_build_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_get_render_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::viewport_get_render_info, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_set_debug_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_debug_draw, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_measure_render_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_measure_render_time, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_get_measured_render_time_cpu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::viewport_get_measured_render_time_cpu, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_get_measured_render_time_gpu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::viewport_get_measured_render_time_gpu, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_viewport_set_vrs_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_vrs_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_vrs_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_vrs_update_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_viewport_set_vrs_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::viewport_set_vrs_texture, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_sky_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::sky_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_sky_set_radiance_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::sky_set_radiance_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_sky_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::sky_set_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_sky_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::sky_set_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_sky_bake_panorama(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::sky_bake_panorama, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_compositor_effect_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::compositor_effect_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_compositor_effect_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::compositor_effect_set_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_compositor_effect_set_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::compositor_effect_set_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_compositor_effect_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::compositor_effect_set_flag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_compositor_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::compositor_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_compositor_set_compositor_effects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::compositor_set_compositor_effects, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::environment_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_environment_set_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_background, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_camera_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_camera_id, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sky(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sky, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sky_custom_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sky_custom_fov, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sky_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sky_orientation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_bg_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_bg_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_bg_energy, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_canvas_max_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_canvas_max_layer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_ambient_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_ambient_light, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_glow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_glow, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_tonemap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_tonemap, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_adjustment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_adjustment, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_ssr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_ssr, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_ssao(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_ssao, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_fog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_fog, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_fog_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_fog_depth, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sdfgi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sdfgi, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_volumetric_fog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_volumetric_fog, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_glow_set_use_bicubic_upscale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_glow_set_use_bicubic_upscale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_ssr_roughness_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_ssr_roughness_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_ssao_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_ssao_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_ssil_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_ssil_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sdfgi_ray_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sdfgi_ray_count, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sdfgi_frames_to_converge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sdfgi_frames_to_converge, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_sdfgi_frames_to_update_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_sdfgi_frames_to_update_light, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_volumetric_fog_volume_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_volumetric_fog_volume_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_set_volumetric_fog_filter_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::environment_set_volumetric_fog_filter_active, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_environment_bake_panorama(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::environment_bake_panorama, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_screen_space_roughness_limiter_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::screen_space_roughness_limiter_set_active, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_sub_surface_scattering_set_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::sub_surface_scattering_set_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_sub_surface_scattering_set_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::sub_surface_scattering_set_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_attributes_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::camera_attributes_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_camera_attributes_set_dof_blur_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_attributes_set_dof_blur_quality, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_attributes_set_dof_blur_bokeh_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_attributes_set_dof_blur_bokeh_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_attributes_set_dof_blur(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_attributes_set_dof_blur, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_attributes_set_exposure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_attributes_set_exposure, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_camera_attributes_set_auto_exposure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::camera_attributes_set_auto_exposure, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_scenario_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::scenario_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_scenario_set_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::scenario_set_environment, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_scenario_set_fallback_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::scenario_set_fallback_environment, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_scenario_set_camera_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::scenario_set_camera_attributes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_scenario_set_compositor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::scenario_set_compositor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_create2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::instance_create2, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instance_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::instance_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instance_set_base(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_base, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_scenario(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_scenario, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_layer_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_layer_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_pivot_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_pivot_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_attach_object_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_attach_object_instance_id, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_blend_shape_weight(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_blend_shape_weight, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_surface_override_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_surface_override_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_visible, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_transparency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_transparency, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_teleport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_teleport, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_custom_aabb, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_attach_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_attach_skeleton, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_extra_visibility_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_extra_visibility_margin, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_visibility_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_visibility_parent, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_set_ignore_culling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_set_ignore_culling, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_flag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_cast_shadows_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_cast_shadows_setting, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_material_override, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_material_overlay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_material_overlay, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_visibility_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_visibility_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_lightmap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_lightmap, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_lod_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_lod_bias, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_set_shader_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::instance_geometry_set_shader_parameter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_instance_geometry_get_shader_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::instance_geometry_get_shader_parameter, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instance_geometry_get_shader_parameter_default_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::instance_geometry_get_shader_parameter_default_value, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instance_geometry_get_shader_parameter_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::instance_geometry_get_shader_parameter_list, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instances_cull_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::instances_cull_aabb, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instances_cull_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::instances_cull_ray, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_instances_cull_convex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::instances_cull_convex, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_bake_render_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::bake_render_uv2, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::canvas_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_set_item_mirroring(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_set_item_mirroring, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_set_item_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_set_item_repeat, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_set_modulate, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_set_disable_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_set_disable_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_texture_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::canvas_texture_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_texture_set_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_texture_set_channel, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_texture_set_shading_parameters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_texture_set_shading_parameters, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_texture_set_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_texture_set_texture_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_texture_set_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_texture_set_texture_repeat, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::canvas_item_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_item_set_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_parent, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_default_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_default_texture_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_default_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_default_texture_repeat, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_visible, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_light_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_light_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_visibility_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_visibility_layer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_clip, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_distance_field_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_distance_field_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_custom_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_custom_rect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_modulate, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_self_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_self_modulate, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_draw_behind_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_draw_behind_parent, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_interpolated, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_reset_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_reset_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_transform_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_transform_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_line, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_polyline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_polyline, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_multiline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_multiline, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_rect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_circle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_circle, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_texture_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_texture_rect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_msdf_texture_rect_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_msdf_texture_rect_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_lcd_texture_rect_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_lcd_texture_rect_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_texture_rect_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_texture_rect_region, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_nine_patch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_nine_patch, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_primitive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_primitive, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_polygon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_triangle_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_triangle_array, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_mesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_multimesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_multimesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_particles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_particles, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_clip_ignore(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_clip_ignore, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_add_animation_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_add_animation_slice, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_sort_children_by_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_sort_children_by_y, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_z_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_z_index, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_z_as_relative_to_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_z_as_relative_to_parent, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_copy_to_backbuffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_copy_to_backbuffer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_attach_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_attach_skeleton, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_draw_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_draw_index, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_use_parent_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_use_parent_material, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_instance_shader_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_instance_shader_parameter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_get_instance_shader_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::canvas_item_get_instance_shader_parameter, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_item_get_instance_shader_parameter_default_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::canvas_item_get_instance_shader_parameter_default_value, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_item_get_instance_shader_parameter_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::canvas_item_get_instance_shader_parameter_list, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_item_set_visibility_notifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_visibility_notifier, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_item_set_canvas_group_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_item_set_canvas_group_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_debug_canvas_item_get_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::debug_canvas_item_get_rect, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_light_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::canvas_light_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_light_attach_to_canvas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_attach_to_canvas, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_texture_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_texture_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_texture, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_texture_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_texture_offset, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_height, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_energy, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_z_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_z_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_layer_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_layer_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_item_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_item_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_item_shadow_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_item_shadow_cull_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_shadow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_shadow_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_shadow_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_shadow_filter, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_shadow_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_shadow_smooth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_shadow_smooth, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_blend_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_set_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_set_interpolated, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_reset_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_reset_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_transform_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_transform_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::canvas_light_occluder_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_light_occluder_attach_to_canvas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_attach_to_canvas, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_set_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_set_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_set_polygon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_set_as_sdf_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_set_as_sdf_collision, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_set_light_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_set_light_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_set_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_set_interpolated, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_reset_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_reset_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_light_occluder_transform_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_light_occluder_transform_physics_interpolation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_occluder_polygon_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::canvas_occluder_polygon_create, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_canvas_occluder_polygon_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_occluder_polygon_set_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_occluder_polygon_set_cull_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_occluder_polygon_set_cull_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_canvas_set_shadow_texture_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::canvas_set_shadow_texture_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_global_shader_parameter_add(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::global_shader_parameter_add, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_global_shader_parameter_remove(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::global_shader_parameter_remove, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_global_shader_parameter_get_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::global_shader_parameter_get_list, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_global_shader_parameter_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::global_shader_parameter_set, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_global_shader_parameter_set_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::global_shader_parameter_set_override, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_global_shader_parameter_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::global_shader_parameter_get, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_global_shader_parameter_get_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::global_shader_parameter_get_type, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_free_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::free_rid, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_request_frame_drawn_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::request_frame_drawn_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_has_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::has_changed, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_rendering_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::get_rendering_info, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_video_adapter_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_video_adapter_name, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_video_adapter_vendor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_video_adapter_vendor, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_video_adapter_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_video_adapter_type, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_video_adapter_api_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_video_adapter_api_version, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_current_rendering_driver_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_current_rendering_driver_name, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_current_rendering_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_current_rendering_method, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_make_sphere_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::make_sphere_mesh, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_test_cube(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::get_test_cube, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_test_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::get_test_texture, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_get_white_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::get_white_texture, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_set_boot_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::set_boot_image, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_get_default_clear_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::get_default_clear_color, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_set_default_clear_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::set_default_clear_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_has_os_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::has_os_feature, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_set_debug_generate_wireframes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::set_debug_generate_wireframes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_is_render_loop_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::is_render_loop_enabled, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_set_render_loop_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::set_render_loop_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_get_frame_setup_time_cpu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_frame_setup_time_cpu, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_force_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::force_sync, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_force_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::force_draw, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_get_rendering_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::get_rendering_device, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_create_local_rendering_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::create_local_rendering_device, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_is_on_render_thread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&RenderingServer::is_on_render_thread, ctx, this_val, argc, argv);
};
static JSValue rendering_server_class_call_on_render_thread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&RenderingServer::call_on_render_thread, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue rendering_server_class_has_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RenderingServer::has_feature, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry rendering_server_class_proto_funcs[] = {
	JS_CFUNC_DEF("texture_2d_create", 1, &rendering_server_class_texture_2d_create),
	JS_CFUNC_DEF("texture_2d_layered_create", 2, &rendering_server_class_texture_2d_layered_create),
	JS_CFUNC_DEF("texture_3d_create", 6, &rendering_server_class_texture_3d_create),
	JS_CFUNC_DEF("texture_proxy_create", 1, &rendering_server_class_texture_proxy_create),
	JS_CFUNC_DEF("texture_create_from_native_handle", 8, &rendering_server_class_texture_create_from_native_handle),
	JS_CFUNC_DEF("texture_2d_update", 3, &rendering_server_class_texture_2d_update),
	JS_CFUNC_DEF("texture_3d_update", 2, &rendering_server_class_texture_3d_update),
	JS_CFUNC_DEF("texture_proxy_update", 2, &rendering_server_class_texture_proxy_update),
	JS_CFUNC_DEF("texture_2d_placeholder_create", 0, &rendering_server_class_texture_2d_placeholder_create),
	JS_CFUNC_DEF("texture_2d_layered_placeholder_create", 1, &rendering_server_class_texture_2d_layered_placeholder_create),
	JS_CFUNC_DEF("texture_3d_placeholder_create", 0, &rendering_server_class_texture_3d_placeholder_create),
	JS_CFUNC_DEF("texture_2d_get", 1, &rendering_server_class_texture_2d_get),
	JS_CFUNC_DEF("texture_2d_layer_get", 2, &rendering_server_class_texture_2d_layer_get),
	JS_CFUNC_DEF("texture_3d_get", 1, &rendering_server_class_texture_3d_get),
	JS_CFUNC_DEF("texture_replace", 2, &rendering_server_class_texture_replace),
	JS_CFUNC_DEF("texture_set_size_override", 3, &rendering_server_class_texture_set_size_override),
	JS_CFUNC_DEF("texture_set_path", 2, &rendering_server_class_texture_set_path),
	JS_CFUNC_DEF("texture_get_path", 1, &rendering_server_class_texture_get_path),
	JS_CFUNC_DEF("texture_get_format", 1, &rendering_server_class_texture_get_format),
	JS_CFUNC_DEF("texture_set_force_redraw_if_visible", 2, &rendering_server_class_texture_set_force_redraw_if_visible),
	JS_CFUNC_DEF("texture_rd_create", 2, &rendering_server_class_texture_rd_create),
	JS_CFUNC_DEF("texture_get_rd_texture", 2, &rendering_server_class_texture_get_rd_texture),
	JS_CFUNC_DEF("texture_get_native_handle", 2, &rendering_server_class_texture_get_native_handle),
	JS_CFUNC_DEF("shader_create", 0, &rendering_server_class_shader_create),
	JS_CFUNC_DEF("shader_set_code", 2, &rendering_server_class_shader_set_code),
	JS_CFUNC_DEF("shader_set_path_hint", 2, &rendering_server_class_shader_set_path_hint),
	JS_CFUNC_DEF("shader_get_code", 1, &rendering_server_class_shader_get_code),
	JS_CFUNC_DEF("get_shader_parameter_list", 1, &rendering_server_class_get_shader_parameter_list),
	JS_CFUNC_DEF("shader_get_parameter_default", 2, &rendering_server_class_shader_get_parameter_default),
	JS_CFUNC_DEF("shader_set_default_texture_parameter", 4, &rendering_server_class_shader_set_default_texture_parameter),
	JS_CFUNC_DEF("shader_get_default_texture_parameter", 3, &rendering_server_class_shader_get_default_texture_parameter),
	JS_CFUNC_DEF("material_create", 0, &rendering_server_class_material_create),
	JS_CFUNC_DEF("material_set_shader", 2, &rendering_server_class_material_set_shader),
	JS_CFUNC_DEF("material_set_param", 3, &rendering_server_class_material_set_param),
	JS_CFUNC_DEF("material_get_param", 2, &rendering_server_class_material_get_param),
	JS_CFUNC_DEF("material_set_render_priority", 2, &rendering_server_class_material_set_render_priority),
	JS_CFUNC_DEF("material_set_next_pass", 2, &rendering_server_class_material_set_next_pass),
	JS_CFUNC_DEF("mesh_create_from_surfaces", 2, &rendering_server_class_mesh_create_from_surfaces),
	JS_CFUNC_DEF("mesh_create", 0, &rendering_server_class_mesh_create),
	JS_CFUNC_DEF("mesh_surface_get_format_offset", 3, &rendering_server_class_mesh_surface_get_format_offset),
	JS_CFUNC_DEF("mesh_surface_get_format_vertex_stride", 2, &rendering_server_class_mesh_surface_get_format_vertex_stride),
	JS_CFUNC_DEF("mesh_surface_get_format_normal_tangent_stride", 2, &rendering_server_class_mesh_surface_get_format_normal_tangent_stride),
	JS_CFUNC_DEF("mesh_surface_get_format_attribute_stride", 2, &rendering_server_class_mesh_surface_get_format_attribute_stride),
	JS_CFUNC_DEF("mesh_surface_get_format_skin_stride", 2, &rendering_server_class_mesh_surface_get_format_skin_stride),
	JS_CFUNC_DEF("mesh_surface_get_format_index_stride", 2, &rendering_server_class_mesh_surface_get_format_index_stride),
	JS_CFUNC_DEF("mesh_add_surface", 2, &rendering_server_class_mesh_add_surface),
	JS_CFUNC_DEF("mesh_add_surface_from_arrays", 6, &rendering_server_class_mesh_add_surface_from_arrays),
	JS_CFUNC_DEF("mesh_get_blend_shape_count", 1, &rendering_server_class_mesh_get_blend_shape_count),
	JS_CFUNC_DEF("mesh_set_blend_shape_mode", 2, &rendering_server_class_mesh_set_blend_shape_mode),
	JS_CFUNC_DEF("mesh_get_blend_shape_mode", 1, &rendering_server_class_mesh_get_blend_shape_mode),
	JS_CFUNC_DEF("mesh_surface_set_material", 3, &rendering_server_class_mesh_surface_set_material),
	JS_CFUNC_DEF("mesh_surface_get_material", 2, &rendering_server_class_mesh_surface_get_material),
	JS_CFUNC_DEF("mesh_get_surface", 2, &rendering_server_class_mesh_get_surface),
	JS_CFUNC_DEF("mesh_surface_get_arrays", 2, &rendering_server_class_mesh_surface_get_arrays),
	JS_CFUNC_DEF("mesh_surface_get_blend_shape_arrays", 2, &rendering_server_class_mesh_surface_get_blend_shape_arrays),
	JS_CFUNC_DEF("mesh_get_surface_count", 1, &rendering_server_class_mesh_get_surface_count),
	JS_CFUNC_DEF("mesh_set_custom_aabb", 2, &rendering_server_class_mesh_set_custom_aabb),
	JS_CFUNC_DEF("mesh_get_custom_aabb", 1, &rendering_server_class_mesh_get_custom_aabb),
	JS_CFUNC_DEF("mesh_surface_remove", 2, &rendering_server_class_mesh_surface_remove),
	JS_CFUNC_DEF("mesh_clear", 1, &rendering_server_class_mesh_clear),
	JS_CFUNC_DEF("mesh_surface_update_vertex_region", 4, &rendering_server_class_mesh_surface_update_vertex_region),
	JS_CFUNC_DEF("mesh_surface_update_attribute_region", 4, &rendering_server_class_mesh_surface_update_attribute_region),
	JS_CFUNC_DEF("mesh_surface_update_skin_region", 4, &rendering_server_class_mesh_surface_update_skin_region),
	JS_CFUNC_DEF("mesh_surface_update_index_region", 4, &rendering_server_class_mesh_surface_update_index_region),
	JS_CFUNC_DEF("mesh_set_shadow_mesh", 2, &rendering_server_class_mesh_set_shadow_mesh),
	JS_CFUNC_DEF("multimesh_create", 0, &rendering_server_class_multimesh_create),
	JS_CFUNC_DEF("multimesh_allocate_data", 6, &rendering_server_class_multimesh_allocate_data),
	JS_CFUNC_DEF("multimesh_get_instance_count", 1, &rendering_server_class_multimesh_get_instance_count),
	JS_CFUNC_DEF("multimesh_set_mesh", 2, &rendering_server_class_multimesh_set_mesh),
	JS_CFUNC_DEF("multimesh_instance_set_transform", 3, &rendering_server_class_multimesh_instance_set_transform),
	JS_CFUNC_DEF("multimesh_instance_set_transform_2d", 3, &rendering_server_class_multimesh_instance_set_transform_2d),
	JS_CFUNC_DEF("multimesh_instance_set_color", 3, &rendering_server_class_multimesh_instance_set_color),
	JS_CFUNC_DEF("multimesh_instance_set_custom_data", 3, &rendering_server_class_multimesh_instance_set_custom_data),
	JS_CFUNC_DEF("multimesh_get_mesh", 1, &rendering_server_class_multimesh_get_mesh),
	JS_CFUNC_DEF("multimesh_get_aabb", 1, &rendering_server_class_multimesh_get_aabb),
	JS_CFUNC_DEF("multimesh_set_custom_aabb", 2, &rendering_server_class_multimesh_set_custom_aabb),
	JS_CFUNC_DEF("multimesh_get_custom_aabb", 1, &rendering_server_class_multimesh_get_custom_aabb),
	JS_CFUNC_DEF("multimesh_instance_get_transform", 2, &rendering_server_class_multimesh_instance_get_transform),
	JS_CFUNC_DEF("multimesh_instance_get_transform_2d", 2, &rendering_server_class_multimesh_instance_get_transform_2d),
	JS_CFUNC_DEF("multimesh_instance_get_color", 2, &rendering_server_class_multimesh_instance_get_color),
	JS_CFUNC_DEF("multimesh_instance_get_custom_data", 2, &rendering_server_class_multimesh_instance_get_custom_data),
	JS_CFUNC_DEF("multimesh_set_visible_instances", 2, &rendering_server_class_multimesh_set_visible_instances),
	JS_CFUNC_DEF("multimesh_get_visible_instances", 1, &rendering_server_class_multimesh_get_visible_instances),
	JS_CFUNC_DEF("multimesh_set_buffer", 2, &rendering_server_class_multimesh_set_buffer),
	JS_CFUNC_DEF("multimesh_get_command_buffer_rd_rid", 1, &rendering_server_class_multimesh_get_command_buffer_rd_rid),
	JS_CFUNC_DEF("multimesh_get_buffer_rd_rid", 1, &rendering_server_class_multimesh_get_buffer_rd_rid),
	JS_CFUNC_DEF("multimesh_get_buffer", 1, &rendering_server_class_multimesh_get_buffer),
	JS_CFUNC_DEF("multimesh_set_buffer_interpolated", 3, &rendering_server_class_multimesh_set_buffer_interpolated),
	JS_CFUNC_DEF("multimesh_set_physics_interpolated", 2, &rendering_server_class_multimesh_set_physics_interpolated),
	JS_CFUNC_DEF("multimesh_set_physics_interpolation_quality", 2, &rendering_server_class_multimesh_set_physics_interpolation_quality),
	JS_CFUNC_DEF("multimesh_instance_reset_physics_interpolation", 2, &rendering_server_class_multimesh_instance_reset_physics_interpolation),
	JS_CFUNC_DEF("skeleton_create", 0, &rendering_server_class_skeleton_create),
	JS_CFUNC_DEF("skeleton_allocate_data", 3, &rendering_server_class_skeleton_allocate_data),
	JS_CFUNC_DEF("skeleton_get_bone_count", 1, &rendering_server_class_skeleton_get_bone_count),
	JS_CFUNC_DEF("skeleton_bone_set_transform", 3, &rendering_server_class_skeleton_bone_set_transform),
	JS_CFUNC_DEF("skeleton_bone_get_transform", 2, &rendering_server_class_skeleton_bone_get_transform),
	JS_CFUNC_DEF("skeleton_bone_set_transform_2d", 3, &rendering_server_class_skeleton_bone_set_transform_2d),
	JS_CFUNC_DEF("skeleton_bone_get_transform_2d", 2, &rendering_server_class_skeleton_bone_get_transform_2d),
	JS_CFUNC_DEF("skeleton_set_base_transform_2d", 2, &rendering_server_class_skeleton_set_base_transform_2d),
	JS_CFUNC_DEF("directional_light_create", 0, &rendering_server_class_directional_light_create),
	JS_CFUNC_DEF("omni_light_create", 0, &rendering_server_class_omni_light_create),
	JS_CFUNC_DEF("spot_light_create", 0, &rendering_server_class_spot_light_create),
	JS_CFUNC_DEF("light_set_color", 2, &rendering_server_class_light_set_color),
	JS_CFUNC_DEF("light_set_param", 3, &rendering_server_class_light_set_param),
	JS_CFUNC_DEF("light_set_shadow", 2, &rendering_server_class_light_set_shadow),
	JS_CFUNC_DEF("light_set_projector", 2, &rendering_server_class_light_set_projector),
	JS_CFUNC_DEF("light_set_negative", 2, &rendering_server_class_light_set_negative),
	JS_CFUNC_DEF("light_set_cull_mask", 2, &rendering_server_class_light_set_cull_mask),
	JS_CFUNC_DEF("light_set_distance_fade", 5, &rendering_server_class_light_set_distance_fade),
	JS_CFUNC_DEF("light_set_reverse_cull_face_mode", 2, &rendering_server_class_light_set_reverse_cull_face_mode),
	JS_CFUNC_DEF("light_set_shadow_caster_mask", 2, &rendering_server_class_light_set_shadow_caster_mask),
	JS_CFUNC_DEF("light_set_bake_mode", 2, &rendering_server_class_light_set_bake_mode),
	JS_CFUNC_DEF("light_set_max_sdfgi_cascade", 2, &rendering_server_class_light_set_max_sdfgi_cascade),
	JS_CFUNC_DEF("light_omni_set_shadow_mode", 2, &rendering_server_class_light_omni_set_shadow_mode),
	JS_CFUNC_DEF("light_directional_set_shadow_mode", 2, &rendering_server_class_light_directional_set_shadow_mode),
	JS_CFUNC_DEF("light_directional_set_blend_splits", 2, &rendering_server_class_light_directional_set_blend_splits),
	JS_CFUNC_DEF("light_directional_set_sky_mode", 2, &rendering_server_class_light_directional_set_sky_mode),
	JS_CFUNC_DEF("light_projectors_set_filter", 1, &rendering_server_class_light_projectors_set_filter),
	JS_CFUNC_DEF("lightmaps_set_bicubic_filter", 1, &rendering_server_class_lightmaps_set_bicubic_filter),
	JS_CFUNC_DEF("positional_soft_shadow_filter_set_quality", 1, &rendering_server_class_positional_soft_shadow_filter_set_quality),
	JS_CFUNC_DEF("directional_soft_shadow_filter_set_quality", 1, &rendering_server_class_directional_soft_shadow_filter_set_quality),
	JS_CFUNC_DEF("directional_shadow_atlas_set_size", 2, &rendering_server_class_directional_shadow_atlas_set_size),
	JS_CFUNC_DEF("reflection_probe_create", 0, &rendering_server_class_reflection_probe_create),
	JS_CFUNC_DEF("reflection_probe_set_update_mode", 2, &rendering_server_class_reflection_probe_set_update_mode),
	JS_CFUNC_DEF("reflection_probe_set_intensity", 2, &rendering_server_class_reflection_probe_set_intensity),
	JS_CFUNC_DEF("reflection_probe_set_blend_distance", 2, &rendering_server_class_reflection_probe_set_blend_distance),
	JS_CFUNC_DEF("reflection_probe_set_ambient_mode", 2, &rendering_server_class_reflection_probe_set_ambient_mode),
	JS_CFUNC_DEF("reflection_probe_set_ambient_color", 2, &rendering_server_class_reflection_probe_set_ambient_color),
	JS_CFUNC_DEF("reflection_probe_set_ambient_energy", 2, &rendering_server_class_reflection_probe_set_ambient_energy),
	JS_CFUNC_DEF("reflection_probe_set_max_distance", 2, &rendering_server_class_reflection_probe_set_max_distance),
	JS_CFUNC_DEF("reflection_probe_set_size", 2, &rendering_server_class_reflection_probe_set_size),
	JS_CFUNC_DEF("reflection_probe_set_origin_offset", 2, &rendering_server_class_reflection_probe_set_origin_offset),
	JS_CFUNC_DEF("reflection_probe_set_as_interior", 2, &rendering_server_class_reflection_probe_set_as_interior),
	JS_CFUNC_DEF("reflection_probe_set_enable_box_projection", 2, &rendering_server_class_reflection_probe_set_enable_box_projection),
	JS_CFUNC_DEF("reflection_probe_set_enable_shadows", 2, &rendering_server_class_reflection_probe_set_enable_shadows),
	JS_CFUNC_DEF("reflection_probe_set_cull_mask", 2, &rendering_server_class_reflection_probe_set_cull_mask),
	JS_CFUNC_DEF("reflection_probe_set_reflection_mask", 2, &rendering_server_class_reflection_probe_set_reflection_mask),
	JS_CFUNC_DEF("reflection_probe_set_resolution", 2, &rendering_server_class_reflection_probe_set_resolution),
	JS_CFUNC_DEF("reflection_probe_set_mesh_lod_threshold", 2, &rendering_server_class_reflection_probe_set_mesh_lod_threshold),
	JS_CFUNC_DEF("decal_create", 0, &rendering_server_class_decal_create),
	JS_CFUNC_DEF("decal_set_size", 2, &rendering_server_class_decal_set_size),
	JS_CFUNC_DEF("decal_set_texture", 3, &rendering_server_class_decal_set_texture),
	JS_CFUNC_DEF("decal_set_emission_energy", 2, &rendering_server_class_decal_set_emission_energy),
	JS_CFUNC_DEF("decal_set_albedo_mix", 2, &rendering_server_class_decal_set_albedo_mix),
	JS_CFUNC_DEF("decal_set_modulate", 2, &rendering_server_class_decal_set_modulate),
	JS_CFUNC_DEF("decal_set_cull_mask", 2, &rendering_server_class_decal_set_cull_mask),
	JS_CFUNC_DEF("decal_set_distance_fade", 4, &rendering_server_class_decal_set_distance_fade),
	JS_CFUNC_DEF("decal_set_fade", 3, &rendering_server_class_decal_set_fade),
	JS_CFUNC_DEF("decal_set_normal_fade", 2, &rendering_server_class_decal_set_normal_fade),
	JS_CFUNC_DEF("decals_set_filter", 1, &rendering_server_class_decals_set_filter),
	JS_CFUNC_DEF("gi_set_use_half_resolution", 1, &rendering_server_class_gi_set_use_half_resolution),
	JS_CFUNC_DEF("voxel_gi_create", 0, &rendering_server_class_voxel_gi_create),
	JS_CFUNC_DEF("voxel_gi_allocate_data", 8, &rendering_server_class_voxel_gi_allocate_data),
	JS_CFUNC_DEF("voxel_gi_get_octree_size", 1, &rendering_server_class_voxel_gi_get_octree_size),
	JS_CFUNC_DEF("voxel_gi_get_octree_cells", 1, &rendering_server_class_voxel_gi_get_octree_cells),
	JS_CFUNC_DEF("voxel_gi_get_data_cells", 1, &rendering_server_class_voxel_gi_get_data_cells),
	JS_CFUNC_DEF("voxel_gi_get_distance_field", 1, &rendering_server_class_voxel_gi_get_distance_field),
	JS_CFUNC_DEF("voxel_gi_get_level_counts", 1, &rendering_server_class_voxel_gi_get_level_counts),
	JS_CFUNC_DEF("voxel_gi_get_to_cell_xform", 1, &rendering_server_class_voxel_gi_get_to_cell_xform),
	JS_CFUNC_DEF("voxel_gi_set_dynamic_range", 2, &rendering_server_class_voxel_gi_set_dynamic_range),
	JS_CFUNC_DEF("voxel_gi_set_propagation", 2, &rendering_server_class_voxel_gi_set_propagation),
	JS_CFUNC_DEF("voxel_gi_set_energy", 2, &rendering_server_class_voxel_gi_set_energy),
	JS_CFUNC_DEF("voxel_gi_set_baked_exposure_normalization", 2, &rendering_server_class_voxel_gi_set_baked_exposure_normalization),
	JS_CFUNC_DEF("voxel_gi_set_bias", 2, &rendering_server_class_voxel_gi_set_bias),
	JS_CFUNC_DEF("voxel_gi_set_normal_bias", 2, &rendering_server_class_voxel_gi_set_normal_bias),
	JS_CFUNC_DEF("voxel_gi_set_interior", 2, &rendering_server_class_voxel_gi_set_interior),
	JS_CFUNC_DEF("voxel_gi_set_use_two_bounces", 2, &rendering_server_class_voxel_gi_set_use_two_bounces),
	JS_CFUNC_DEF("voxel_gi_set_quality", 1, &rendering_server_class_voxel_gi_set_quality),
	JS_CFUNC_DEF("lightmap_create", 0, &rendering_server_class_lightmap_create),
	JS_CFUNC_DEF("lightmap_set_textures", 3, &rendering_server_class_lightmap_set_textures),
	JS_CFUNC_DEF("lightmap_set_probe_bounds", 2, &rendering_server_class_lightmap_set_probe_bounds),
	JS_CFUNC_DEF("lightmap_set_probe_interior", 2, &rendering_server_class_lightmap_set_probe_interior),
	JS_CFUNC_DEF("lightmap_set_probe_capture_data", 5, &rendering_server_class_lightmap_set_probe_capture_data),
	JS_CFUNC_DEF("lightmap_get_probe_capture_points", 1, &rendering_server_class_lightmap_get_probe_capture_points),
	JS_CFUNC_DEF("lightmap_get_probe_capture_sh", 1, &rendering_server_class_lightmap_get_probe_capture_sh),
	JS_CFUNC_DEF("lightmap_get_probe_capture_tetrahedra", 1, &rendering_server_class_lightmap_get_probe_capture_tetrahedra),
	JS_CFUNC_DEF("lightmap_get_probe_capture_bsp_tree", 1, &rendering_server_class_lightmap_get_probe_capture_bsp_tree),
	JS_CFUNC_DEF("lightmap_set_baked_exposure_normalization", 2, &rendering_server_class_lightmap_set_baked_exposure_normalization),
	JS_CFUNC_DEF("lightmap_set_probe_capture_update_speed", 1, &rendering_server_class_lightmap_set_probe_capture_update_speed),
	JS_CFUNC_DEF("particles_create", 0, &rendering_server_class_particles_create),
	JS_CFUNC_DEF("particles_set_mode", 2, &rendering_server_class_particles_set_mode),
	JS_CFUNC_DEF("particles_set_emitting", 2, &rendering_server_class_particles_set_emitting),
	JS_CFUNC_DEF("particles_get_emitting", 1, &rendering_server_class_particles_get_emitting),
	JS_CFUNC_DEF("particles_set_amount", 2, &rendering_server_class_particles_set_amount),
	JS_CFUNC_DEF("particles_set_amount_ratio", 2, &rendering_server_class_particles_set_amount_ratio),
	JS_CFUNC_DEF("particles_set_lifetime", 2, &rendering_server_class_particles_set_lifetime),
	JS_CFUNC_DEF("particles_set_one_shot", 2, &rendering_server_class_particles_set_one_shot),
	JS_CFUNC_DEF("particles_set_pre_process_time", 2, &rendering_server_class_particles_set_pre_process_time),
	JS_CFUNC_DEF("particles_request_process_time", 2, &rendering_server_class_particles_request_process_time),
	JS_CFUNC_DEF("particles_set_explosiveness_ratio", 2, &rendering_server_class_particles_set_explosiveness_ratio),
	JS_CFUNC_DEF("particles_set_randomness_ratio", 2, &rendering_server_class_particles_set_randomness_ratio),
	JS_CFUNC_DEF("particles_set_interp_to_end", 2, &rendering_server_class_particles_set_interp_to_end),
	JS_CFUNC_DEF("particles_set_emitter_velocity", 2, &rendering_server_class_particles_set_emitter_velocity),
	JS_CFUNC_DEF("particles_set_custom_aabb", 2, &rendering_server_class_particles_set_custom_aabb),
	JS_CFUNC_DEF("particles_set_speed_scale", 2, &rendering_server_class_particles_set_speed_scale),
	JS_CFUNC_DEF("particles_set_use_local_coordinates", 2, &rendering_server_class_particles_set_use_local_coordinates),
	JS_CFUNC_DEF("particles_set_process_material", 2, &rendering_server_class_particles_set_process_material),
	JS_CFUNC_DEF("particles_set_fixed_fps", 2, &rendering_server_class_particles_set_fixed_fps),
	JS_CFUNC_DEF("particles_set_interpolate", 2, &rendering_server_class_particles_set_interpolate),
	JS_CFUNC_DEF("particles_set_fractional_delta", 2, &rendering_server_class_particles_set_fractional_delta),
	JS_CFUNC_DEF("particles_set_collision_base_size", 2, &rendering_server_class_particles_set_collision_base_size),
	JS_CFUNC_DEF("particles_set_transform_align", 2, &rendering_server_class_particles_set_transform_align),
	JS_CFUNC_DEF("particles_set_trails", 3, &rendering_server_class_particles_set_trails),
	JS_CFUNC_DEF("particles_set_trail_bind_poses", 2, &rendering_server_class_particles_set_trail_bind_poses),
	JS_CFUNC_DEF("particles_is_inactive", 1, &rendering_server_class_particles_is_inactive),
	JS_CFUNC_DEF("particles_request_process", 1, &rendering_server_class_particles_request_process),
	JS_CFUNC_DEF("particles_restart", 1, &rendering_server_class_particles_restart),
	JS_CFUNC_DEF("particles_set_subemitter", 2, &rendering_server_class_particles_set_subemitter),
	JS_CFUNC_DEF("particles_emit", 6, &rendering_server_class_particles_emit),
	JS_CFUNC_DEF("particles_set_draw_order", 2, &rendering_server_class_particles_set_draw_order),
	JS_CFUNC_DEF("particles_set_draw_passes", 2, &rendering_server_class_particles_set_draw_passes),
	JS_CFUNC_DEF("particles_set_draw_pass_mesh", 3, &rendering_server_class_particles_set_draw_pass_mesh),
	JS_CFUNC_DEF("particles_get_current_aabb", 1, &rendering_server_class_particles_get_current_aabb),
	JS_CFUNC_DEF("particles_set_emission_transform", 2, &rendering_server_class_particles_set_emission_transform),
	JS_CFUNC_DEF("particles_collision_create", 0, &rendering_server_class_particles_collision_create),
	JS_CFUNC_DEF("particles_collision_set_collision_type", 2, &rendering_server_class_particles_collision_set_collision_type),
	JS_CFUNC_DEF("particles_collision_set_cull_mask", 2, &rendering_server_class_particles_collision_set_cull_mask),
	JS_CFUNC_DEF("particles_collision_set_sphere_radius", 2, &rendering_server_class_particles_collision_set_sphere_radius),
	JS_CFUNC_DEF("particles_collision_set_box_extents", 2, &rendering_server_class_particles_collision_set_box_extents),
	JS_CFUNC_DEF("particles_collision_set_attractor_strength", 2, &rendering_server_class_particles_collision_set_attractor_strength),
	JS_CFUNC_DEF("particles_collision_set_attractor_directionality", 2, &rendering_server_class_particles_collision_set_attractor_directionality),
	JS_CFUNC_DEF("particles_collision_set_attractor_attenuation", 2, &rendering_server_class_particles_collision_set_attractor_attenuation),
	JS_CFUNC_DEF("particles_collision_set_field_texture", 2, &rendering_server_class_particles_collision_set_field_texture),
	JS_CFUNC_DEF("particles_collision_height_field_update", 1, &rendering_server_class_particles_collision_height_field_update),
	JS_CFUNC_DEF("particles_collision_set_height_field_resolution", 2, &rendering_server_class_particles_collision_set_height_field_resolution),
	JS_CFUNC_DEF("particles_collision_set_height_field_mask", 2, &rendering_server_class_particles_collision_set_height_field_mask),
	JS_CFUNC_DEF("fog_volume_create", 0, &rendering_server_class_fog_volume_create),
	JS_CFUNC_DEF("fog_volume_set_shape", 2, &rendering_server_class_fog_volume_set_shape),
	JS_CFUNC_DEF("fog_volume_set_size", 2, &rendering_server_class_fog_volume_set_size),
	JS_CFUNC_DEF("fog_volume_set_material", 2, &rendering_server_class_fog_volume_set_material),
	JS_CFUNC_DEF("visibility_notifier_create", 0, &rendering_server_class_visibility_notifier_create),
	JS_CFUNC_DEF("visibility_notifier_set_aabb", 2, &rendering_server_class_visibility_notifier_set_aabb),
	JS_CFUNC_DEF("visibility_notifier_set_callbacks", 3, &rendering_server_class_visibility_notifier_set_callbacks),
	JS_CFUNC_DEF("occluder_create", 0, &rendering_server_class_occluder_create),
	JS_CFUNC_DEF("occluder_set_mesh", 3, &rendering_server_class_occluder_set_mesh),
	JS_CFUNC_DEF("camera_create", 0, &rendering_server_class_camera_create),
	JS_CFUNC_DEF("camera_set_perspective", 4, &rendering_server_class_camera_set_perspective),
	JS_CFUNC_DEF("camera_set_orthogonal", 4, &rendering_server_class_camera_set_orthogonal),
	JS_CFUNC_DEF("camera_set_frustum", 5, &rendering_server_class_camera_set_frustum),
	JS_CFUNC_DEF("camera_set_transform", 2, &rendering_server_class_camera_set_transform),
	JS_CFUNC_DEF("camera_set_cull_mask", 2, &rendering_server_class_camera_set_cull_mask),
	JS_CFUNC_DEF("camera_set_environment", 2, &rendering_server_class_camera_set_environment),
	JS_CFUNC_DEF("camera_set_camera_attributes", 2, &rendering_server_class_camera_set_camera_attributes),
	JS_CFUNC_DEF("camera_set_compositor", 2, &rendering_server_class_camera_set_compositor),
	JS_CFUNC_DEF("camera_set_use_vertical_aspect", 2, &rendering_server_class_camera_set_use_vertical_aspect),
	JS_CFUNC_DEF("viewport_create", 0, &rendering_server_class_viewport_create),
	JS_CFUNC_DEF("viewport_set_use_xr", 2, &rendering_server_class_viewport_set_use_xr),
	JS_CFUNC_DEF("viewport_set_size", 3, &rendering_server_class_viewport_set_size),
	JS_CFUNC_DEF("viewport_set_active", 2, &rendering_server_class_viewport_set_active),
	JS_CFUNC_DEF("viewport_set_parent_viewport", 2, &rendering_server_class_viewport_set_parent_viewport),
	JS_CFUNC_DEF("viewport_attach_to_screen", 3, &rendering_server_class_viewport_attach_to_screen),
	JS_CFUNC_DEF("viewport_set_render_direct_to_screen", 2, &rendering_server_class_viewport_set_render_direct_to_screen),
	JS_CFUNC_DEF("viewport_set_canvas_cull_mask", 2, &rendering_server_class_viewport_set_canvas_cull_mask),
	JS_CFUNC_DEF("viewport_set_scaling_3d_mode", 2, &rendering_server_class_viewport_set_scaling_3d_mode),
	JS_CFUNC_DEF("viewport_set_scaling_3d_scale", 2, &rendering_server_class_viewport_set_scaling_3d_scale),
	JS_CFUNC_DEF("viewport_set_fsr_sharpness", 2, &rendering_server_class_viewport_set_fsr_sharpness),
	JS_CFUNC_DEF("viewport_set_texture_mipmap_bias", 2, &rendering_server_class_viewport_set_texture_mipmap_bias),
	JS_CFUNC_DEF("viewport_set_anisotropic_filtering_level", 2, &rendering_server_class_viewport_set_anisotropic_filtering_level),
	JS_CFUNC_DEF("viewport_set_update_mode", 2, &rendering_server_class_viewport_set_update_mode),
	JS_CFUNC_DEF("viewport_get_update_mode", 1, &rendering_server_class_viewport_get_update_mode),
	JS_CFUNC_DEF("viewport_set_clear_mode", 2, &rendering_server_class_viewport_set_clear_mode),
	JS_CFUNC_DEF("viewport_get_render_target", 1, &rendering_server_class_viewport_get_render_target),
	JS_CFUNC_DEF("viewport_get_texture", 1, &rendering_server_class_viewport_get_texture),
	JS_CFUNC_DEF("viewport_set_disable_3d", 2, &rendering_server_class_viewport_set_disable_3d),
	JS_CFUNC_DEF("viewport_set_disable_2d", 2, &rendering_server_class_viewport_set_disable_2d),
	JS_CFUNC_DEF("viewport_set_environment_mode", 2, &rendering_server_class_viewport_set_environment_mode),
	JS_CFUNC_DEF("viewport_attach_camera", 2, &rendering_server_class_viewport_attach_camera),
	JS_CFUNC_DEF("viewport_set_scenario", 2, &rendering_server_class_viewport_set_scenario),
	JS_CFUNC_DEF("viewport_attach_canvas", 2, &rendering_server_class_viewport_attach_canvas),
	JS_CFUNC_DEF("viewport_remove_canvas", 2, &rendering_server_class_viewport_remove_canvas),
	JS_CFUNC_DEF("viewport_set_snap_2d_transforms_to_pixel", 2, &rendering_server_class_viewport_set_snap_2d_transforms_to_pixel),
	JS_CFUNC_DEF("viewport_set_snap_2d_vertices_to_pixel", 2, &rendering_server_class_viewport_set_snap_2d_vertices_to_pixel),
	JS_CFUNC_DEF("viewport_set_default_canvas_item_texture_filter", 2, &rendering_server_class_viewport_set_default_canvas_item_texture_filter),
	JS_CFUNC_DEF("viewport_set_default_canvas_item_texture_repeat", 2, &rendering_server_class_viewport_set_default_canvas_item_texture_repeat),
	JS_CFUNC_DEF("viewport_set_canvas_transform", 3, &rendering_server_class_viewport_set_canvas_transform),
	JS_CFUNC_DEF("viewport_set_canvas_stacking", 4, &rendering_server_class_viewport_set_canvas_stacking),
	JS_CFUNC_DEF("viewport_set_transparent_background", 2, &rendering_server_class_viewport_set_transparent_background),
	JS_CFUNC_DEF("viewport_set_global_canvas_transform", 2, &rendering_server_class_viewport_set_global_canvas_transform),
	JS_CFUNC_DEF("viewport_set_sdf_oversize_and_scale", 3, &rendering_server_class_viewport_set_sdf_oversize_and_scale),
	JS_CFUNC_DEF("viewport_set_positional_shadow_atlas_size", 3, &rendering_server_class_viewport_set_positional_shadow_atlas_size),
	JS_CFUNC_DEF("viewport_set_positional_shadow_atlas_quadrant_subdivision", 3, &rendering_server_class_viewport_set_positional_shadow_atlas_quadrant_subdivision),
	JS_CFUNC_DEF("viewport_set_msaa_3d", 2, &rendering_server_class_viewport_set_msaa_3d),
	JS_CFUNC_DEF("viewport_set_msaa_2d", 2, &rendering_server_class_viewport_set_msaa_2d),
	JS_CFUNC_DEF("viewport_set_use_hdr_2d", 2, &rendering_server_class_viewport_set_use_hdr_2d),
	JS_CFUNC_DEF("viewport_set_screen_space_aa", 2, &rendering_server_class_viewport_set_screen_space_aa),
	JS_CFUNC_DEF("viewport_set_use_taa", 2, &rendering_server_class_viewport_set_use_taa),
	JS_CFUNC_DEF("viewport_set_use_debanding", 2, &rendering_server_class_viewport_set_use_debanding),
	JS_CFUNC_DEF("viewport_set_use_occlusion_culling", 2, &rendering_server_class_viewport_set_use_occlusion_culling),
	JS_CFUNC_DEF("viewport_set_occlusion_rays_per_thread", 1, &rendering_server_class_viewport_set_occlusion_rays_per_thread),
	JS_CFUNC_DEF("viewport_set_occlusion_culling_build_quality", 1, &rendering_server_class_viewport_set_occlusion_culling_build_quality),
	JS_CFUNC_DEF("viewport_get_render_info", 3, &rendering_server_class_viewport_get_render_info),
	JS_CFUNC_DEF("viewport_set_debug_draw", 2, &rendering_server_class_viewport_set_debug_draw),
	JS_CFUNC_DEF("viewport_set_measure_render_time", 2, &rendering_server_class_viewport_set_measure_render_time),
	JS_CFUNC_DEF("viewport_get_measured_render_time_cpu", 1, &rendering_server_class_viewport_get_measured_render_time_cpu),
	JS_CFUNC_DEF("viewport_get_measured_render_time_gpu", 1, &rendering_server_class_viewport_get_measured_render_time_gpu),
	JS_CFUNC_DEF("viewport_set_vrs_mode", 2, &rendering_server_class_viewport_set_vrs_mode),
	JS_CFUNC_DEF("viewport_set_vrs_update_mode", 2, &rendering_server_class_viewport_set_vrs_update_mode),
	JS_CFUNC_DEF("viewport_set_vrs_texture", 2, &rendering_server_class_viewport_set_vrs_texture),
	JS_CFUNC_DEF("sky_create", 0, &rendering_server_class_sky_create),
	JS_CFUNC_DEF("sky_set_radiance_size", 2, &rendering_server_class_sky_set_radiance_size),
	JS_CFUNC_DEF("sky_set_mode", 2, &rendering_server_class_sky_set_mode),
	JS_CFUNC_DEF("sky_set_material", 2, &rendering_server_class_sky_set_material),
	JS_CFUNC_DEF("sky_bake_panorama", 4, &rendering_server_class_sky_bake_panorama),
	JS_CFUNC_DEF("compositor_effect_create", 0, &rendering_server_class_compositor_effect_create),
	JS_CFUNC_DEF("compositor_effect_set_enabled", 2, &rendering_server_class_compositor_effect_set_enabled),
	JS_CFUNC_DEF("compositor_effect_set_callback", 3, &rendering_server_class_compositor_effect_set_callback),
	JS_CFUNC_DEF("compositor_effect_set_flag", 3, &rendering_server_class_compositor_effect_set_flag),
	JS_CFUNC_DEF("compositor_create", 0, &rendering_server_class_compositor_create),
	JS_CFUNC_DEF("compositor_set_compositor_effects", 2, &rendering_server_class_compositor_set_compositor_effects),
	JS_CFUNC_DEF("environment_create", 0, &rendering_server_class_environment_create),
	JS_CFUNC_DEF("environment_set_background", 2, &rendering_server_class_environment_set_background),
	JS_CFUNC_DEF("environment_set_camera_id", 2, &rendering_server_class_environment_set_camera_id),
	JS_CFUNC_DEF("environment_set_sky", 2, &rendering_server_class_environment_set_sky),
	JS_CFUNC_DEF("environment_set_sky_custom_fov", 2, &rendering_server_class_environment_set_sky_custom_fov),
	JS_CFUNC_DEF("environment_set_sky_orientation", 2, &rendering_server_class_environment_set_sky_orientation),
	JS_CFUNC_DEF("environment_set_bg_color", 2, &rendering_server_class_environment_set_bg_color),
	JS_CFUNC_DEF("environment_set_bg_energy", 3, &rendering_server_class_environment_set_bg_energy),
	JS_CFUNC_DEF("environment_set_canvas_max_layer", 2, &rendering_server_class_environment_set_canvas_max_layer),
	JS_CFUNC_DEF("environment_set_ambient_light", 6, &rendering_server_class_environment_set_ambient_light),
	JS_CFUNC_DEF("environment_set_glow", 13, &rendering_server_class_environment_set_glow),
	JS_CFUNC_DEF("environment_set_tonemap", 4, &rendering_server_class_environment_set_tonemap),
	JS_CFUNC_DEF("environment_set_adjustment", 7, &rendering_server_class_environment_set_adjustment),
	JS_CFUNC_DEF("environment_set_ssr", 6, &rendering_server_class_environment_set_ssr),
	JS_CFUNC_DEF("environment_set_ssao", 10, &rendering_server_class_environment_set_ssao),
	JS_CFUNC_DEF("environment_set_fog", 11, &rendering_server_class_environment_set_fog),
	JS_CFUNC_DEF("environment_set_fog_depth", 4, &rendering_server_class_environment_set_fog_depth),
	JS_CFUNC_DEF("environment_set_sdfgi", 11, &rendering_server_class_environment_set_sdfgi),
	JS_CFUNC_DEF("environment_set_volumetric_fog", 14, &rendering_server_class_environment_set_volumetric_fog),
	JS_CFUNC_DEF("environment_glow_set_use_bicubic_upscale", 1, &rendering_server_class_environment_glow_set_use_bicubic_upscale),
	JS_CFUNC_DEF("environment_set_ssr_roughness_quality", 1, &rendering_server_class_environment_set_ssr_roughness_quality),
	JS_CFUNC_DEF("environment_set_ssao_quality", 6, &rendering_server_class_environment_set_ssao_quality),
	JS_CFUNC_DEF("environment_set_ssil_quality", 6, &rendering_server_class_environment_set_ssil_quality),
	JS_CFUNC_DEF("environment_set_sdfgi_ray_count", 1, &rendering_server_class_environment_set_sdfgi_ray_count),
	JS_CFUNC_DEF("environment_set_sdfgi_frames_to_converge", 1, &rendering_server_class_environment_set_sdfgi_frames_to_converge),
	JS_CFUNC_DEF("environment_set_sdfgi_frames_to_update_light", 1, &rendering_server_class_environment_set_sdfgi_frames_to_update_light),
	JS_CFUNC_DEF("environment_set_volumetric_fog_volume_size", 2, &rendering_server_class_environment_set_volumetric_fog_volume_size),
	JS_CFUNC_DEF("environment_set_volumetric_fog_filter_active", 1, &rendering_server_class_environment_set_volumetric_fog_filter_active),
	JS_CFUNC_DEF("environment_bake_panorama", 3, &rendering_server_class_environment_bake_panorama),
	JS_CFUNC_DEF("screen_space_roughness_limiter_set_active", 3, &rendering_server_class_screen_space_roughness_limiter_set_active),
	JS_CFUNC_DEF("sub_surface_scattering_set_quality", 1, &rendering_server_class_sub_surface_scattering_set_quality),
	JS_CFUNC_DEF("sub_surface_scattering_set_scale", 2, &rendering_server_class_sub_surface_scattering_set_scale),
	JS_CFUNC_DEF("camera_attributes_create", 0, &rendering_server_class_camera_attributes_create),
	JS_CFUNC_DEF("camera_attributes_set_dof_blur_quality", 2, &rendering_server_class_camera_attributes_set_dof_blur_quality),
	JS_CFUNC_DEF("camera_attributes_set_dof_blur_bokeh_shape", 1, &rendering_server_class_camera_attributes_set_dof_blur_bokeh_shape),
	JS_CFUNC_DEF("camera_attributes_set_dof_blur", 8, &rendering_server_class_camera_attributes_set_dof_blur),
	JS_CFUNC_DEF("camera_attributes_set_exposure", 3, &rendering_server_class_camera_attributes_set_exposure),
	JS_CFUNC_DEF("camera_attributes_set_auto_exposure", 6, &rendering_server_class_camera_attributes_set_auto_exposure),
	JS_CFUNC_DEF("scenario_create", 0, &rendering_server_class_scenario_create),
	JS_CFUNC_DEF("scenario_set_environment", 2, &rendering_server_class_scenario_set_environment),
	JS_CFUNC_DEF("scenario_set_fallback_environment", 2, &rendering_server_class_scenario_set_fallback_environment),
	JS_CFUNC_DEF("scenario_set_camera_attributes", 2, &rendering_server_class_scenario_set_camera_attributes),
	JS_CFUNC_DEF("scenario_set_compositor", 2, &rendering_server_class_scenario_set_compositor),
	JS_CFUNC_DEF("instance_create2", 2, &rendering_server_class_instance_create2),
	JS_CFUNC_DEF("instance_create", 0, &rendering_server_class_instance_create),
	JS_CFUNC_DEF("instance_set_base", 2, &rendering_server_class_instance_set_base),
	JS_CFUNC_DEF("instance_set_scenario", 2, &rendering_server_class_instance_set_scenario),
	JS_CFUNC_DEF("instance_set_layer_mask", 2, &rendering_server_class_instance_set_layer_mask),
	JS_CFUNC_DEF("instance_set_pivot_data", 3, &rendering_server_class_instance_set_pivot_data),
	JS_CFUNC_DEF("instance_set_transform", 2, &rendering_server_class_instance_set_transform),
	JS_CFUNC_DEF("instance_attach_object_instance_id", 2, &rendering_server_class_instance_attach_object_instance_id),
	JS_CFUNC_DEF("instance_set_blend_shape_weight", 3, &rendering_server_class_instance_set_blend_shape_weight),
	JS_CFUNC_DEF("instance_set_surface_override_material", 3, &rendering_server_class_instance_set_surface_override_material),
	JS_CFUNC_DEF("instance_set_visible", 2, &rendering_server_class_instance_set_visible),
	JS_CFUNC_DEF("instance_geometry_set_transparency", 2, &rendering_server_class_instance_geometry_set_transparency),
	JS_CFUNC_DEF("instance_teleport", 1, &rendering_server_class_instance_teleport),
	JS_CFUNC_DEF("instance_set_custom_aabb", 2, &rendering_server_class_instance_set_custom_aabb),
	JS_CFUNC_DEF("instance_attach_skeleton", 2, &rendering_server_class_instance_attach_skeleton),
	JS_CFUNC_DEF("instance_set_extra_visibility_margin", 2, &rendering_server_class_instance_set_extra_visibility_margin),
	JS_CFUNC_DEF("instance_set_visibility_parent", 2, &rendering_server_class_instance_set_visibility_parent),
	JS_CFUNC_DEF("instance_set_ignore_culling", 2, &rendering_server_class_instance_set_ignore_culling),
	JS_CFUNC_DEF("instance_geometry_set_flag", 3, &rendering_server_class_instance_geometry_set_flag),
	JS_CFUNC_DEF("instance_geometry_set_cast_shadows_setting", 2, &rendering_server_class_instance_geometry_set_cast_shadows_setting),
	JS_CFUNC_DEF("instance_geometry_set_material_override", 2, &rendering_server_class_instance_geometry_set_material_override),
	JS_CFUNC_DEF("instance_geometry_set_material_overlay", 2, &rendering_server_class_instance_geometry_set_material_overlay),
	JS_CFUNC_DEF("instance_geometry_set_visibility_range", 6, &rendering_server_class_instance_geometry_set_visibility_range),
	JS_CFUNC_DEF("instance_geometry_set_lightmap", 4, &rendering_server_class_instance_geometry_set_lightmap),
	JS_CFUNC_DEF("instance_geometry_set_lod_bias", 2, &rendering_server_class_instance_geometry_set_lod_bias),
	JS_CFUNC_DEF("instance_geometry_set_shader_parameter", 3, &rendering_server_class_instance_geometry_set_shader_parameter),
	JS_CFUNC_DEF("instance_geometry_get_shader_parameter", 2, &rendering_server_class_instance_geometry_get_shader_parameter),
	JS_CFUNC_DEF("instance_geometry_get_shader_parameter_default_value", 2, &rendering_server_class_instance_geometry_get_shader_parameter_default_value),
	JS_CFUNC_DEF("instance_geometry_get_shader_parameter_list", 1, &rendering_server_class_instance_geometry_get_shader_parameter_list),
	JS_CFUNC_DEF("instances_cull_aabb", 2, &rendering_server_class_instances_cull_aabb),
	JS_CFUNC_DEF("instances_cull_ray", 3, &rendering_server_class_instances_cull_ray),
	JS_CFUNC_DEF("instances_cull_convex", 2, &rendering_server_class_instances_cull_convex),
	JS_CFUNC_DEF("bake_render_uv2", 3, &rendering_server_class_bake_render_uv2),
	JS_CFUNC_DEF("canvas_create", 0, &rendering_server_class_canvas_create),
	JS_CFUNC_DEF("canvas_set_item_mirroring", 3, &rendering_server_class_canvas_set_item_mirroring),
	JS_CFUNC_DEF("canvas_set_item_repeat", 3, &rendering_server_class_canvas_set_item_repeat),
	JS_CFUNC_DEF("canvas_set_modulate", 2, &rendering_server_class_canvas_set_modulate),
	JS_CFUNC_DEF("canvas_set_disable_scale", 1, &rendering_server_class_canvas_set_disable_scale),
	JS_CFUNC_DEF("canvas_texture_create", 0, &rendering_server_class_canvas_texture_create),
	JS_CFUNC_DEF("canvas_texture_set_channel", 3, &rendering_server_class_canvas_texture_set_channel),
	JS_CFUNC_DEF("canvas_texture_set_shading_parameters", 3, &rendering_server_class_canvas_texture_set_shading_parameters),
	JS_CFUNC_DEF("canvas_texture_set_texture_filter", 2, &rendering_server_class_canvas_texture_set_texture_filter),
	JS_CFUNC_DEF("canvas_texture_set_texture_repeat", 2, &rendering_server_class_canvas_texture_set_texture_repeat),
	JS_CFUNC_DEF("canvas_item_create", 0, &rendering_server_class_canvas_item_create),
	JS_CFUNC_DEF("canvas_item_set_parent", 2, &rendering_server_class_canvas_item_set_parent),
	JS_CFUNC_DEF("canvas_item_set_default_texture_filter", 2, &rendering_server_class_canvas_item_set_default_texture_filter),
	JS_CFUNC_DEF("canvas_item_set_default_texture_repeat", 2, &rendering_server_class_canvas_item_set_default_texture_repeat),
	JS_CFUNC_DEF("canvas_item_set_visible", 2, &rendering_server_class_canvas_item_set_visible),
	JS_CFUNC_DEF("canvas_item_set_light_mask", 2, &rendering_server_class_canvas_item_set_light_mask),
	JS_CFUNC_DEF("canvas_item_set_visibility_layer", 2, &rendering_server_class_canvas_item_set_visibility_layer),
	JS_CFUNC_DEF("canvas_item_set_transform", 2, &rendering_server_class_canvas_item_set_transform),
	JS_CFUNC_DEF("canvas_item_set_clip", 2, &rendering_server_class_canvas_item_set_clip),
	JS_CFUNC_DEF("canvas_item_set_distance_field_mode", 2, &rendering_server_class_canvas_item_set_distance_field_mode),
	JS_CFUNC_DEF("canvas_item_set_custom_rect", 3, &rendering_server_class_canvas_item_set_custom_rect),
	JS_CFUNC_DEF("canvas_item_set_modulate", 2, &rendering_server_class_canvas_item_set_modulate),
	JS_CFUNC_DEF("canvas_item_set_self_modulate", 2, &rendering_server_class_canvas_item_set_self_modulate),
	JS_CFUNC_DEF("canvas_item_set_draw_behind_parent", 2, &rendering_server_class_canvas_item_set_draw_behind_parent),
	JS_CFUNC_DEF("canvas_item_set_interpolated", 2, &rendering_server_class_canvas_item_set_interpolated),
	JS_CFUNC_DEF("canvas_item_reset_physics_interpolation", 1, &rendering_server_class_canvas_item_reset_physics_interpolation),
	JS_CFUNC_DEF("canvas_item_transform_physics_interpolation", 2, &rendering_server_class_canvas_item_transform_physics_interpolation),
	JS_CFUNC_DEF("canvas_item_add_line", 6, &rendering_server_class_canvas_item_add_line),
	JS_CFUNC_DEF("canvas_item_add_polyline", 5, &rendering_server_class_canvas_item_add_polyline),
	JS_CFUNC_DEF("canvas_item_add_multiline", 5, &rendering_server_class_canvas_item_add_multiline),
	JS_CFUNC_DEF("canvas_item_add_rect", 4, &rendering_server_class_canvas_item_add_rect),
	JS_CFUNC_DEF("canvas_item_add_circle", 5, &rendering_server_class_canvas_item_add_circle),
	JS_CFUNC_DEF("canvas_item_add_texture_rect", 6, &rendering_server_class_canvas_item_add_texture_rect),
	JS_CFUNC_DEF("canvas_item_add_msdf_texture_rect_region", 8, &rendering_server_class_canvas_item_add_msdf_texture_rect_region),
	JS_CFUNC_DEF("canvas_item_add_lcd_texture_rect_region", 5, &rendering_server_class_canvas_item_add_lcd_texture_rect_region),
	JS_CFUNC_DEF("canvas_item_add_texture_rect_region", 7, &rendering_server_class_canvas_item_add_texture_rect_region),
	JS_CFUNC_DEF("canvas_item_add_nine_patch", 10, &rendering_server_class_canvas_item_add_nine_patch),
	JS_CFUNC_DEF("canvas_item_add_primitive", 5, &rendering_server_class_canvas_item_add_primitive),
	JS_CFUNC_DEF("canvas_item_add_polygon", 5, &rendering_server_class_canvas_item_add_polygon),
	JS_CFUNC_DEF("canvas_item_add_triangle_array", 9, &rendering_server_class_canvas_item_add_triangle_array),
	JS_CFUNC_DEF("canvas_item_add_mesh", 5, &rendering_server_class_canvas_item_add_mesh),
	JS_CFUNC_DEF("canvas_item_add_multimesh", 3, &rendering_server_class_canvas_item_add_multimesh),
	JS_CFUNC_DEF("canvas_item_add_particles", 3, &rendering_server_class_canvas_item_add_particles),
	JS_CFUNC_DEF("canvas_item_add_set_transform", 2, &rendering_server_class_canvas_item_add_set_transform),
	JS_CFUNC_DEF("canvas_item_add_clip_ignore", 2, &rendering_server_class_canvas_item_add_clip_ignore),
	JS_CFUNC_DEF("canvas_item_add_animation_slice", 5, &rendering_server_class_canvas_item_add_animation_slice),
	JS_CFUNC_DEF("canvas_item_set_sort_children_by_y", 2, &rendering_server_class_canvas_item_set_sort_children_by_y),
	JS_CFUNC_DEF("canvas_item_set_z_index", 2, &rendering_server_class_canvas_item_set_z_index),
	JS_CFUNC_DEF("canvas_item_set_z_as_relative_to_parent", 2, &rendering_server_class_canvas_item_set_z_as_relative_to_parent),
	JS_CFUNC_DEF("canvas_item_set_copy_to_backbuffer", 3, &rendering_server_class_canvas_item_set_copy_to_backbuffer),
	JS_CFUNC_DEF("canvas_item_attach_skeleton", 2, &rendering_server_class_canvas_item_attach_skeleton),
	JS_CFUNC_DEF("canvas_item_clear", 1, &rendering_server_class_canvas_item_clear),
	JS_CFUNC_DEF("canvas_item_set_draw_index", 2, &rendering_server_class_canvas_item_set_draw_index),
	JS_CFUNC_DEF("canvas_item_set_material", 2, &rendering_server_class_canvas_item_set_material),
	JS_CFUNC_DEF("canvas_item_set_use_parent_material", 2, &rendering_server_class_canvas_item_set_use_parent_material),
	JS_CFUNC_DEF("canvas_item_set_instance_shader_parameter", 3, &rendering_server_class_canvas_item_set_instance_shader_parameter),
	JS_CFUNC_DEF("canvas_item_get_instance_shader_parameter", 2, &rendering_server_class_canvas_item_get_instance_shader_parameter),
	JS_CFUNC_DEF("canvas_item_get_instance_shader_parameter_default_value", 2, &rendering_server_class_canvas_item_get_instance_shader_parameter_default_value),
	JS_CFUNC_DEF("canvas_item_get_instance_shader_parameter_list", 1, &rendering_server_class_canvas_item_get_instance_shader_parameter_list),
	JS_CFUNC_DEF("canvas_item_set_visibility_notifier", 5, &rendering_server_class_canvas_item_set_visibility_notifier),
	JS_CFUNC_DEF("canvas_item_set_canvas_group_mode", 6, &rendering_server_class_canvas_item_set_canvas_group_mode),
	JS_CFUNC_DEF("debug_canvas_item_get_rect", 1, &rendering_server_class_debug_canvas_item_get_rect),
	JS_CFUNC_DEF("canvas_light_create", 0, &rendering_server_class_canvas_light_create),
	JS_CFUNC_DEF("canvas_light_attach_to_canvas", 2, &rendering_server_class_canvas_light_attach_to_canvas),
	JS_CFUNC_DEF("canvas_light_set_enabled", 2, &rendering_server_class_canvas_light_set_enabled),
	JS_CFUNC_DEF("canvas_light_set_texture_scale", 2, &rendering_server_class_canvas_light_set_texture_scale),
	JS_CFUNC_DEF("canvas_light_set_transform", 2, &rendering_server_class_canvas_light_set_transform),
	JS_CFUNC_DEF("canvas_light_set_texture", 2, &rendering_server_class_canvas_light_set_texture),
	JS_CFUNC_DEF("canvas_light_set_texture_offset", 2, &rendering_server_class_canvas_light_set_texture_offset),
	JS_CFUNC_DEF("canvas_light_set_color", 2, &rendering_server_class_canvas_light_set_color),
	JS_CFUNC_DEF("canvas_light_set_height", 2, &rendering_server_class_canvas_light_set_height),
	JS_CFUNC_DEF("canvas_light_set_energy", 2, &rendering_server_class_canvas_light_set_energy),
	JS_CFUNC_DEF("canvas_light_set_z_range", 3, &rendering_server_class_canvas_light_set_z_range),
	JS_CFUNC_DEF("canvas_light_set_layer_range", 3, &rendering_server_class_canvas_light_set_layer_range),
	JS_CFUNC_DEF("canvas_light_set_item_cull_mask", 2, &rendering_server_class_canvas_light_set_item_cull_mask),
	JS_CFUNC_DEF("canvas_light_set_item_shadow_cull_mask", 2, &rendering_server_class_canvas_light_set_item_shadow_cull_mask),
	JS_CFUNC_DEF("canvas_light_set_mode", 2, &rendering_server_class_canvas_light_set_mode),
	JS_CFUNC_DEF("canvas_light_set_shadow_enabled", 2, &rendering_server_class_canvas_light_set_shadow_enabled),
	JS_CFUNC_DEF("canvas_light_set_shadow_filter", 2, &rendering_server_class_canvas_light_set_shadow_filter),
	JS_CFUNC_DEF("canvas_light_set_shadow_color", 2, &rendering_server_class_canvas_light_set_shadow_color),
	JS_CFUNC_DEF("canvas_light_set_shadow_smooth", 2, &rendering_server_class_canvas_light_set_shadow_smooth),
	JS_CFUNC_DEF("canvas_light_set_blend_mode", 2, &rendering_server_class_canvas_light_set_blend_mode),
	JS_CFUNC_DEF("canvas_light_set_interpolated", 2, &rendering_server_class_canvas_light_set_interpolated),
	JS_CFUNC_DEF("canvas_light_reset_physics_interpolation", 1, &rendering_server_class_canvas_light_reset_physics_interpolation),
	JS_CFUNC_DEF("canvas_light_transform_physics_interpolation", 2, &rendering_server_class_canvas_light_transform_physics_interpolation),
	JS_CFUNC_DEF("canvas_light_occluder_create", 0, &rendering_server_class_canvas_light_occluder_create),
	JS_CFUNC_DEF("canvas_light_occluder_attach_to_canvas", 2, &rendering_server_class_canvas_light_occluder_attach_to_canvas),
	JS_CFUNC_DEF("canvas_light_occluder_set_enabled", 2, &rendering_server_class_canvas_light_occluder_set_enabled),
	JS_CFUNC_DEF("canvas_light_occluder_set_polygon", 2, &rendering_server_class_canvas_light_occluder_set_polygon),
	JS_CFUNC_DEF("canvas_light_occluder_set_as_sdf_collision", 2, &rendering_server_class_canvas_light_occluder_set_as_sdf_collision),
	JS_CFUNC_DEF("canvas_light_occluder_set_transform", 2, &rendering_server_class_canvas_light_occluder_set_transform),
	JS_CFUNC_DEF("canvas_light_occluder_set_light_mask", 2, &rendering_server_class_canvas_light_occluder_set_light_mask),
	JS_CFUNC_DEF("canvas_light_occluder_set_interpolated", 2, &rendering_server_class_canvas_light_occluder_set_interpolated),
	JS_CFUNC_DEF("canvas_light_occluder_reset_physics_interpolation", 1, &rendering_server_class_canvas_light_occluder_reset_physics_interpolation),
	JS_CFUNC_DEF("canvas_light_occluder_transform_physics_interpolation", 2, &rendering_server_class_canvas_light_occluder_transform_physics_interpolation),
	JS_CFUNC_DEF("canvas_occluder_polygon_create", 0, &rendering_server_class_canvas_occluder_polygon_create),
	JS_CFUNC_DEF("canvas_occluder_polygon_set_shape", 3, &rendering_server_class_canvas_occluder_polygon_set_shape),
	JS_CFUNC_DEF("canvas_occluder_polygon_set_cull_mode", 2, &rendering_server_class_canvas_occluder_polygon_set_cull_mode),
	JS_CFUNC_DEF("canvas_set_shadow_texture_size", 1, &rendering_server_class_canvas_set_shadow_texture_size),
	JS_CFUNC_DEF("global_shader_parameter_add", 3, &rendering_server_class_global_shader_parameter_add),
	JS_CFUNC_DEF("global_shader_parameter_remove", 1, &rendering_server_class_global_shader_parameter_remove),
	JS_CFUNC_DEF("global_shader_parameter_get_list", 0, &rendering_server_class_global_shader_parameter_get_list),
	JS_CFUNC_DEF("global_shader_parameter_set", 2, &rendering_server_class_global_shader_parameter_set),
	JS_CFUNC_DEF("global_shader_parameter_set_override", 2, &rendering_server_class_global_shader_parameter_set_override),
	JS_CFUNC_DEF("global_shader_parameter_get", 1, &rendering_server_class_global_shader_parameter_get),
	JS_CFUNC_DEF("global_shader_parameter_get_type", 1, &rendering_server_class_global_shader_parameter_get_type),
	JS_CFUNC_DEF("free_rid", 1, &rendering_server_class_free_rid),
	JS_CFUNC_DEF("request_frame_drawn_callback", 1, &rendering_server_class_request_frame_drawn_callback),
	JS_CFUNC_DEF("has_changed", 0, &rendering_server_class_has_changed),
	JS_CFUNC_DEF("get_rendering_info", 1, &rendering_server_class_get_rendering_info),
	JS_CFUNC_DEF("get_video_adapter_name", 0, &rendering_server_class_get_video_adapter_name),
	JS_CFUNC_DEF("get_video_adapter_vendor", 0, &rendering_server_class_get_video_adapter_vendor),
	JS_CFUNC_DEF("get_video_adapter_type", 0, &rendering_server_class_get_video_adapter_type),
	JS_CFUNC_DEF("get_video_adapter_api_version", 0, &rendering_server_class_get_video_adapter_api_version),
	JS_CFUNC_DEF("get_current_rendering_driver_name", 0, &rendering_server_class_get_current_rendering_driver_name),
	JS_CFUNC_DEF("get_current_rendering_method", 0, &rendering_server_class_get_current_rendering_method),
	JS_CFUNC_DEF("make_sphere_mesh", 3, &rendering_server_class_make_sphere_mesh),
	JS_CFUNC_DEF("get_test_cube", 0, &rendering_server_class_get_test_cube),
	JS_CFUNC_DEF("get_test_texture", 0, &rendering_server_class_get_test_texture),
	JS_CFUNC_DEF("get_white_texture", 0, &rendering_server_class_get_white_texture),
	JS_CFUNC_DEF("set_boot_image", 4, &rendering_server_class_set_boot_image),
	JS_CFUNC_DEF("get_default_clear_color", 0, &rendering_server_class_get_default_clear_color),
	JS_CFUNC_DEF("set_default_clear_color", 1, &rendering_server_class_set_default_clear_color),
	JS_CFUNC_DEF("has_os_feature", 1, &rendering_server_class_has_os_feature),
	JS_CFUNC_DEF("set_debug_generate_wireframes", 1, &rendering_server_class_set_debug_generate_wireframes),
	JS_CFUNC_DEF("is_render_loop_enabled", 0, &rendering_server_class_is_render_loop_enabled),
	JS_CFUNC_DEF("set_render_loop_enabled", 1, &rendering_server_class_set_render_loop_enabled),
	JS_CFUNC_DEF("get_frame_setup_time_cpu", 0, &rendering_server_class_get_frame_setup_time_cpu),
	JS_CFUNC_DEF("force_sync", 0, &rendering_server_class_force_sync),
	JS_CFUNC_DEF("force_draw", 2, &rendering_server_class_force_draw),
	JS_CFUNC_DEF("get_rendering_device", 0, &rendering_server_class_get_rendering_device),
	JS_CFUNC_DEF("create_local_rendering_device", 0, &rendering_server_class_create_local_rendering_device),
	JS_CFUNC_DEF("is_on_render_thread", 0, &rendering_server_class_is_on_render_thread),
	JS_CFUNC_DEF("call_on_render_thread", 1, &rendering_server_class_call_on_render_thread),
	JS_CFUNC_DEF("has_feature", 1, &rendering_server_class_has_feature),
};




static int js_rendering_server_class_init(JSContext *ctx) {
	JSClassID class_id = classes["RenderingServer"];
	classes["RenderingServer"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rendering_server_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, rendering_server_class_proto_funcs, _countof(rendering_server_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, rendering_server_class_constructor, "_RenderingServer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "RenderingServer", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_rendering_server() {
	js_rendering_server_class_init(js_context());
}