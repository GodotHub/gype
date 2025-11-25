#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera_attributes.hpp>
#include <godot_cpp/classes/compositor.hpp>
#include <godot_cpp/classes/environment.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/camera3d.hpp>
using namespace godot;

static void camera3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Camera3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef camera3d_class_def = {
    "Camera3D",
    camera3d_class_finalizer
};

static JSValue camera3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Camera3D"];
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
        instance = memnew(Camera3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue camera3d_class_project_ray_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::project_ray_normal, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_project_local_ray_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::project_local_ray_normal, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_project_ray_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::project_ray_origin, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_unproject_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::unproject_position, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_is_position_behind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::is_position_behind, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_project_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::project_position, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_perspective(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_perspective, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_orthogonal, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_frustum(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_frustum, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_make_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::make_current, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_clear_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::clear_current, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_current, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_is_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::is_current, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_get_camera_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_camera_transform, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_camera_projection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_camera_projection, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_fov, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_get_frustum_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Camera3D *obj = static_cast<Camera3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_frustum_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Camera3D *js_proxy = static_cast<Camera3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_frustum_offset(value);
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
static JSValue camera3d_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_size, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_get_far(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_far, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_get_near(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_near, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_fov, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_frustum_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_frustum_offset, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_size, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_far(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_far, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_near(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_near, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_projection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_projection, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_projection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_projection, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_h_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_h_offset, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_h_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_h_offset, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_v_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_v_offset, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_v_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_v_offset, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_cull_mask, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_cull_mask, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_environment, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_environment, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_attributes, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_attributes, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_compositor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_compositor, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_compositor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_compositor, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_keep_aspect_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_keep_aspect_mode, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_keep_aspect_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_keep_aspect_mode, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_set_doppler_tracking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_doppler_tracking, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_doppler_tracking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_doppler_tracking, ctx, this_val, argc, argv);
}
static JSValue camera3d_class_get_frustum(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_frustum, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_is_position_in_frustum(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::is_position_in_frustum, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_camera_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_camera_rid, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_pyramid_shape_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Camera3D::get_pyramid_shape_rid, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_set_cull_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Camera3D::set_cull_mask_value, ctx, this_val, argc, argv);
};
static JSValue camera3d_class_get_cull_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Camera3D::get_cull_mask_value, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry camera3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("project_ray_normal", 1, &camera3d_class_project_ray_normal),
	JS_CFUNC_DEF("project_local_ray_normal", 1, &camera3d_class_project_local_ray_normal),
	JS_CFUNC_DEF("project_ray_origin", 1, &camera3d_class_project_ray_origin),
	JS_CFUNC_DEF("unproject_position", 1, &camera3d_class_unproject_position),
	JS_CFUNC_DEF("is_position_behind", 1, &camera3d_class_is_position_behind),
	JS_CFUNC_DEF("project_position", 2, &camera3d_class_project_position),
	JS_CFUNC_DEF("set_perspective", 3, &camera3d_class_set_perspective),
	JS_CFUNC_DEF("set_orthogonal", 3, &camera3d_class_set_orthogonal),
	JS_CFUNC_DEF("set_frustum", 4, &camera3d_class_set_frustum),
	JS_CFUNC_DEF("make_current", 0, &camera3d_class_make_current),
	JS_CFUNC_DEF("clear_current", 1, &camera3d_class_clear_current),
	JS_CFUNC_DEF("set_current", 1, &camera3d_class_set_current),
	JS_CFUNC_DEF("is_current", 0, &camera3d_class_is_current),
	JS_CFUNC_DEF("get_camera_transform", 0, &camera3d_class_get_camera_transform),
	JS_CFUNC_DEF("get_camera_projection", 0, &camera3d_class_get_camera_projection),
	JS_CFUNC_DEF("get_fov", 0, &camera3d_class_get_fov),
	JS_CFUNC_DEF("get_frustum_offset", 0, &camera3d_class_get_frustum_offset),
	JS_CFUNC_DEF("get_size", 0, &camera3d_class_get_size),
	JS_CFUNC_DEF("get_far", 0, &camera3d_class_get_far),
	JS_CFUNC_DEF("get_near", 0, &camera3d_class_get_near),
	JS_CFUNC_DEF("set_fov", 1, &camera3d_class_set_fov),
	JS_CFUNC_DEF("set_frustum_offset", 1, &camera3d_class_set_frustum_offset),
	JS_CFUNC_DEF("set_size", 1, &camera3d_class_set_size),
	JS_CFUNC_DEF("set_far", 1, &camera3d_class_set_far),
	JS_CFUNC_DEF("set_near", 1, &camera3d_class_set_near),
	JS_CFUNC_DEF("get_projection", 0, &camera3d_class_get_projection),
	JS_CFUNC_DEF("set_projection", 1, &camera3d_class_set_projection),
	JS_CFUNC_DEF("set_h_offset", 1, &camera3d_class_set_h_offset),
	JS_CFUNC_DEF("get_h_offset", 0, &camera3d_class_get_h_offset),
	JS_CFUNC_DEF("set_v_offset", 1, &camera3d_class_set_v_offset),
	JS_CFUNC_DEF("get_v_offset", 0, &camera3d_class_get_v_offset),
	JS_CFUNC_DEF("set_cull_mask", 1, &camera3d_class_set_cull_mask),
	JS_CFUNC_DEF("get_cull_mask", 0, &camera3d_class_get_cull_mask),
	JS_CFUNC_DEF("set_environment", 1, &camera3d_class_set_environment),
	JS_CFUNC_DEF("get_environment", 0, &camera3d_class_get_environment),
	JS_CFUNC_DEF("set_attributes", 1, &camera3d_class_set_attributes),
	JS_CFUNC_DEF("get_attributes", 0, &camera3d_class_get_attributes),
	JS_CFUNC_DEF("set_compositor", 1, &camera3d_class_set_compositor),
	JS_CFUNC_DEF("get_compositor", 0, &camera3d_class_get_compositor),
	JS_CFUNC_DEF("set_keep_aspect_mode", 1, &camera3d_class_set_keep_aspect_mode),
	JS_CFUNC_DEF("get_keep_aspect_mode", 0, &camera3d_class_get_keep_aspect_mode),
	JS_CFUNC_DEF("set_doppler_tracking", 1, &camera3d_class_set_doppler_tracking),
	JS_CFUNC_DEF("get_doppler_tracking", 0, &camera3d_class_get_doppler_tracking),
	JS_CFUNC_DEF("get_frustum", 0, &camera3d_class_get_frustum),
	JS_CFUNC_DEF("is_position_in_frustum", 1, &camera3d_class_is_position_in_frustum),
	JS_CFUNC_DEF("get_camera_rid", 0, &camera3d_class_get_camera_rid),
	JS_CFUNC_DEF("get_pyramid_shape_rid", 0, &camera3d_class_get_pyramid_shape_rid),
	JS_CFUNC_DEF("set_cull_mask_value", 2, &camera3d_class_set_cull_mask_value),
	JS_CFUNC_DEF("get_cull_mask_value", 1, &camera3d_class_get_cull_mask_value),
};




static void define_camera3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_aspect"),
        JS_NewCFunction(ctx, camera3d_class_get_keep_aspect_mode, "get_keep_aspect_mode", 0),
        JS_NewCFunction(ctx, camera3d_class_set_keep_aspect_mode, "set_keep_aspect_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cull_mask"),
        JS_NewCFunction(ctx, camera3d_class_get_cull_mask, "get_cull_mask", 0),
        JS_NewCFunction(ctx, camera3d_class_set_cull_mask, "set_cull_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "environment"),
        JS_NewCFunction(ctx, camera3d_class_get_environment, "get_environment", 0),
        JS_NewCFunction(ctx, camera3d_class_set_environment, "set_environment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "attributes"),
        JS_NewCFunction(ctx, camera3d_class_get_attributes, "get_attributes", 0),
        JS_NewCFunction(ctx, camera3d_class_set_attributes, "set_attributes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "compositor"),
        JS_NewCFunction(ctx, camera3d_class_get_compositor, "get_compositor", 0),
        JS_NewCFunction(ctx, camera3d_class_set_compositor, "set_compositor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "h_offset"),
        JS_NewCFunction(ctx, camera3d_class_get_h_offset, "get_h_offset", 0),
        JS_NewCFunction(ctx, camera3d_class_set_h_offset, "set_h_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "v_offset"),
        JS_NewCFunction(ctx, camera3d_class_get_v_offset, "get_v_offset", 0),
        JS_NewCFunction(ctx, camera3d_class_set_v_offset, "set_v_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "doppler_tracking"),
        JS_NewCFunction(ctx, camera3d_class_get_doppler_tracking, "get_doppler_tracking", 0),
        JS_NewCFunction(ctx, camera3d_class_set_doppler_tracking, "set_doppler_tracking", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "projection"),
        JS_NewCFunction(ctx, camera3d_class_get_projection, "get_projection", 0),
        JS_NewCFunction(ctx, camera3d_class_set_projection, "set_projection", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current"),
        JS_NewCFunction(ctx, camera3d_class_is_current, "is_current", 0),
        JS_NewCFunction(ctx, camera3d_class_set_current, "set_current", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fov"),
        JS_NewCFunction(ctx, camera3d_class_get_fov, "get_fov", 0),
        JS_NewCFunction(ctx, camera3d_class_set_fov, "set_fov", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, camera3d_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, camera3d_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frustum_offset"),
        JS_NewCFunction(ctx, camera3d_class_get_frustum_offset, "get_frustum_offset", 0),
        JS_NewCFunction(ctx, camera3d_class_set_frustum_offset, "set_frustum_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "near"),
        JS_NewCFunction(ctx, camera3d_class_get_near, "get_near", 0),
        JS_NewCFunction(ctx, camera3d_class_set_near, "set_near", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "far"),
        JS_NewCFunction(ctx, camera3d_class_get_far, "get_far", 0),
        JS_NewCFunction(ctx, camera3d_class_set_far, "set_far", 1),
        JS_PROP_GETSET
    );
}

static void define_camera3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue ProjectionType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ProjectionType_obj, "PROJECTION_PERSPECTIVE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ProjectionType_obj, "PROJECTION_ORTHOGONAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ProjectionType_obj, "PROJECTION_FRUSTUM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ProjectionType", ProjectionType_obj);
	JSValue KeepAspect_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, KeepAspect_obj, "KEEP_WIDTH", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, KeepAspect_obj, "KEEP_HEIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "KeepAspect", KeepAspect_obj);
	JSValue DopplerTracking_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DopplerTracking_obj, "DOPPLER_TRACKING_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DopplerTracking_obj, "DOPPLER_TRACKING_IDLE_STEP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DopplerTracking_obj, "DOPPLER_TRACKING_PHYSICS_STEP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DopplerTracking", DopplerTracking_obj);
}

static int js_camera3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Camera3D"] = class_id;
	classes_by_id[class_id] = "Camera3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &camera3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_camera3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, camera3d_class_proto_funcs, _countof(camera3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, camera3d_class_constructor, "Camera3D", 0, JS_CFUNC_constructor, 0);
	define_camera3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Camera3D", ctor);
	ctor_list["Camera3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_camera3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_camera3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Camera3D");
	return m;
}

JSModuleDef *js_init_camera3d_module(JSContext *ctx) {
	return _js_init_camera3d_module(ctx, "@godot/classes/camera3d");
}

void __register_camera3d() {
	js_init_camera3d_module(js_context());
}

void register_camera3d() {
	__register_camera3d();
}