#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_extension_wrapper.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xrapi_extension.hpp>
using namespace godot;

static void open_xrapi_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRAPIExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xrapi_extension_class_def = {
    "OpenXRAPIExtension",
    open_xrapi_extension_class_finalizer
};

static JSValue open_xrapi_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRAPIExtension"];
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
        instance = memnew(OpenXRAPIExtension);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xrapi_extension_class_get_instance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_instance, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_system_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_system_id, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_session(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_session, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_transform_from_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::transform_from_pose, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_xr_result(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::xr_result, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_instance_proc_addr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_instance_proc_addr, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_error_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_error_string, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_swapchain_format_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_swapchain_format_name, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_object_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_object_name, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_begin_debug_label_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::begin_debug_label_region, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_end_debug_label_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::end_debug_label_region, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_insert_debug_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::insert_debug_label, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_is_initialized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::is_initialized, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_is_running(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::is_running, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_custom_play_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_custom_play_space, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_play_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_play_space, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_predicted_display_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_predicted_display_time, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_next_frame_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_next_frame_time, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_can_render(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::can_render, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_find_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::find_action, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_action_get_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::action_get_handle, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_hand_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_hand_tracker, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_register_composition_layer_provider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::register_composition_layer_provider, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_unregister_composition_layer_provider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::unregister_composition_layer_provider, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_register_projection_views_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::register_projection_views_extension, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_unregister_projection_views_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::unregister_projection_views_extension, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_register_frame_info_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::register_frame_info_extension, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_unregister_frame_info_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::unregister_frame_info_extension, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_render_state_z_near(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_render_state_z_near, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_render_state_z_far(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_render_state_z_far, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_velocity_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_velocity_texture, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_velocity_depth_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_velocity_depth_texture, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_velocity_target_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_velocity_target_size, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_supported_swapchain_formats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_supported_swapchain_formats, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_openxr_swapchain_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::openxr_swapchain_create, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_openxr_swapchain_free(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::openxr_swapchain_free, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_openxr_swapchain_get_swapchain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::openxr_swapchain_get_swapchain, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_openxr_swapchain_acquire(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::openxr_swapchain_acquire, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_openxr_swapchain_get_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::openxr_swapchain_get_image, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_openxr_swapchain_release(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::openxr_swapchain_release, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_get_projection_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::get_projection_layer, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_render_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_render_region, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_set_emulate_environment_blend_mode_alpha_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAPIExtension::set_emulate_environment_blend_mode_alpha_blend, ctx, this_val, argc, argv);
};
static JSValue open_xrapi_extension_class_is_environment_blend_mode_alpha_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRAPIExtension::is_environment_blend_mode_alpha_supported, ctx, this_val, argc, argv);
};


static JSValue open_xrapi_extension_class_openxr_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&OpenXRAPIExtension::openxr_is_enabled, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry open_xrapi_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_instance", 0, &open_xrapi_extension_class_get_instance),
	JS_CFUNC_DEF("get_system_id", 0, &open_xrapi_extension_class_get_system_id),
	JS_CFUNC_DEF("get_session", 0, &open_xrapi_extension_class_get_session),
	JS_CFUNC_DEF("transform_from_pose", 1, &open_xrapi_extension_class_transform_from_pose),
	JS_CFUNC_DEF("xr_result", 3, &open_xrapi_extension_class_xr_result),
	JS_CFUNC_DEF("get_instance_proc_addr", 1, &open_xrapi_extension_class_get_instance_proc_addr),
	JS_CFUNC_DEF("get_error_string", 1, &open_xrapi_extension_class_get_error_string),
	JS_CFUNC_DEF("get_swapchain_format_name", 1, &open_xrapi_extension_class_get_swapchain_format_name),
	JS_CFUNC_DEF("set_object_name", 3, &open_xrapi_extension_class_set_object_name),
	JS_CFUNC_DEF("begin_debug_label_region", 1, &open_xrapi_extension_class_begin_debug_label_region),
	JS_CFUNC_DEF("end_debug_label_region", 0, &open_xrapi_extension_class_end_debug_label_region),
	JS_CFUNC_DEF("insert_debug_label", 1, &open_xrapi_extension_class_insert_debug_label),
	JS_CFUNC_DEF("is_initialized", 0, &open_xrapi_extension_class_is_initialized),
	JS_CFUNC_DEF("is_running", 0, &open_xrapi_extension_class_is_running),
	JS_CFUNC_DEF("set_custom_play_space", 1, &open_xrapi_extension_class_set_custom_play_space),
	JS_CFUNC_DEF("get_play_space", 0, &open_xrapi_extension_class_get_play_space),
	JS_CFUNC_DEF("get_predicted_display_time", 0, &open_xrapi_extension_class_get_predicted_display_time),
	JS_CFUNC_DEF("get_next_frame_time", 0, &open_xrapi_extension_class_get_next_frame_time),
	JS_CFUNC_DEF("can_render", 0, &open_xrapi_extension_class_can_render),
	JS_CFUNC_DEF("find_action", 2, &open_xrapi_extension_class_find_action),
	JS_CFUNC_DEF("action_get_handle", 1, &open_xrapi_extension_class_action_get_handle),
	JS_CFUNC_DEF("get_hand_tracker", 1, &open_xrapi_extension_class_get_hand_tracker),
	JS_CFUNC_DEF("register_composition_layer_provider", 1, &open_xrapi_extension_class_register_composition_layer_provider),
	JS_CFUNC_DEF("unregister_composition_layer_provider", 1, &open_xrapi_extension_class_unregister_composition_layer_provider),
	JS_CFUNC_DEF("register_projection_views_extension", 1, &open_xrapi_extension_class_register_projection_views_extension),
	JS_CFUNC_DEF("unregister_projection_views_extension", 1, &open_xrapi_extension_class_unregister_projection_views_extension),
	JS_CFUNC_DEF("register_frame_info_extension", 1, &open_xrapi_extension_class_register_frame_info_extension),
	JS_CFUNC_DEF("unregister_frame_info_extension", 1, &open_xrapi_extension_class_unregister_frame_info_extension),
	JS_CFUNC_DEF("get_render_state_z_near", 0, &open_xrapi_extension_class_get_render_state_z_near),
	JS_CFUNC_DEF("get_render_state_z_far", 0, &open_xrapi_extension_class_get_render_state_z_far),
	JS_CFUNC_DEF("set_velocity_texture", 1, &open_xrapi_extension_class_set_velocity_texture),
	JS_CFUNC_DEF("set_velocity_depth_texture", 1, &open_xrapi_extension_class_set_velocity_depth_texture),
	JS_CFUNC_DEF("set_velocity_target_size", 1, &open_xrapi_extension_class_set_velocity_target_size),
	JS_CFUNC_DEF("get_supported_swapchain_formats", 0, &open_xrapi_extension_class_get_supported_swapchain_formats),
	JS_CFUNC_DEF("openxr_swapchain_create", 7, &open_xrapi_extension_class_openxr_swapchain_create),
	JS_CFUNC_DEF("openxr_swapchain_free", 1, &open_xrapi_extension_class_openxr_swapchain_free),
	JS_CFUNC_DEF("openxr_swapchain_get_swapchain", 1, &open_xrapi_extension_class_openxr_swapchain_get_swapchain),
	JS_CFUNC_DEF("openxr_swapchain_acquire", 1, &open_xrapi_extension_class_openxr_swapchain_acquire),
	JS_CFUNC_DEF("openxr_swapchain_get_image", 1, &open_xrapi_extension_class_openxr_swapchain_get_image),
	JS_CFUNC_DEF("openxr_swapchain_release", 1, &open_xrapi_extension_class_openxr_swapchain_release),
	JS_CFUNC_DEF("get_projection_layer", 0, &open_xrapi_extension_class_get_projection_layer),
	JS_CFUNC_DEF("set_render_region", 1, &open_xrapi_extension_class_set_render_region),
	JS_CFUNC_DEF("set_emulate_environment_blend_mode_alpha_blend", 1, &open_xrapi_extension_class_set_emulate_environment_blend_mode_alpha_blend),
	JS_CFUNC_DEF("is_environment_blend_mode_alpha_supported", 0, &open_xrapi_extension_class_is_environment_blend_mode_alpha_supported),
};

static const JSCFunctionListEntry open_xrapi_extension_class_static_funcs[] = {
	JS_CFUNC_DEF("openxr_is_enabled", 1, &open_xrapi_extension_class_openxr_is_enabled),
};



static void define_open_xrapi_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_open_xrapi_extension_enum(JSContext *ctx, JSValue ctor) {
	JSValue OpenXRAlphaBlendModeSupport_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, OpenXRAlphaBlendModeSupport_obj, "OPENXR_ALPHA_BLEND_MODE_SUPPORT_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, OpenXRAlphaBlendModeSupport_obj, "OPENXR_ALPHA_BLEND_MODE_SUPPORT_REAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, OpenXRAlphaBlendModeSupport_obj, "OPENXR_ALPHA_BLEND_MODE_SUPPORT_EMULATING", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "OpenXRAlphaBlendModeSupport", OpenXRAlphaBlendModeSupport_obj);
}

static int js_open_xrapi_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRAPIExtension"] = class_id;
	classes_by_id[class_id] = "OpenXRAPIExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xrapi_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xrapi_extension_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xrapi_extension_class_proto_funcs, _countof(open_xrapi_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xrapi_extension_class_constructor, "OpenXRAPIExtension", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, open_xrapi_extension_class_static_funcs, _countof(open_xrapi_extension_class_static_funcs));
	define_open_xrapi_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRAPIExtension", ctor);
	ctor_list["OpenXRAPIExtension"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xrapi_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xrapi_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRAPIExtension");
	return m;
}

JSModuleDef *js_init_open_xrapi_extension_module(JSContext *ctx) {
	return _js_init_open_xrapi_extension_module(ctx, "@godot/classes/open_xrapi_extension");
}

void __register_open_xrapi_extension() {
	js_init_open_xrapi_extension_module(js_context());
}

void register_open_xrapi_extension() {
	__register_open_xrapi_extension();
}