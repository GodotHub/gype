#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gpu_particles_collision3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gpu_particles_collision_height_field3d.hpp>
using namespace godot;

static void gpu_particles_collision_height_field3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GPUParticlesCollisionHeightField3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gpu_particles_collision_height_field3d_class_def = {
    "GPUParticlesCollisionHeightField3D",
    gpu_particles_collision_height_field3d_class_finalizer
};

static JSValue gpu_particles_collision_height_field3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GPUParticlesCollisionHeightField3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GPUParticlesCollisionHeightField3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GPUParticlesCollisionHeightField3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GPUParticlesCollisionHeightField3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gpu_particles_collision_height_field3d_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticlesCollisionHeightField3D::set_size, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GPUParticlesCollisionHeightField3D *obj = static_cast<GPUParticlesCollisionHeightField3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GPUParticlesCollisionHeightField3D *js_proxy = static_cast<GPUParticlesCollisionHeightField3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gpu_particles_collision_height_field3d_class_set_resolution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticlesCollisionHeightField3D::set_resolution, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_get_resolution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticlesCollisionHeightField3D::get_resolution, ctx, this_val, argc, argv);
}
static JSValue gpu_particles_collision_height_field3d_class_set_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticlesCollisionHeightField3D::set_update_mode, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_get_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticlesCollisionHeightField3D::get_update_mode, ctx, this_val, argc, argv);
}
static JSValue gpu_particles_collision_height_field3d_class_set_heightfield_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticlesCollisionHeightField3D::set_heightfield_mask, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_get_heightfield_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticlesCollisionHeightField3D::get_heightfield_mask, ctx, this_val, argc, argv);
}
static JSValue gpu_particles_collision_height_field3d_class_set_heightfield_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticlesCollisionHeightField3D::set_heightfield_mask_value, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_get_heightfield_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticlesCollisionHeightField3D::get_heightfield_mask_value, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_set_follow_camera_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticlesCollisionHeightField3D::set_follow_camera_enabled, ctx, this_val, argc, argv);
};
static JSValue gpu_particles_collision_height_field3d_class_is_follow_camera_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticlesCollisionHeightField3D::is_follow_camera_enabled, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry gpu_particles_collision_height_field3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &gpu_particles_collision_height_field3d_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &gpu_particles_collision_height_field3d_class_get_size),
	JS_CFUNC_DEF("set_resolution", 1, &gpu_particles_collision_height_field3d_class_set_resolution),
	JS_CFUNC_DEF("get_resolution", 0, &gpu_particles_collision_height_field3d_class_get_resolution),
	JS_CFUNC_DEF("set_update_mode", 1, &gpu_particles_collision_height_field3d_class_set_update_mode),
	JS_CFUNC_DEF("get_update_mode", 0, &gpu_particles_collision_height_field3d_class_get_update_mode),
	JS_CFUNC_DEF("set_heightfield_mask", 1, &gpu_particles_collision_height_field3d_class_set_heightfield_mask),
	JS_CFUNC_DEF("get_heightfield_mask", 0, &gpu_particles_collision_height_field3d_class_get_heightfield_mask),
	JS_CFUNC_DEF("set_heightfield_mask_value", 2, &gpu_particles_collision_height_field3d_class_set_heightfield_mask_value),
	JS_CFUNC_DEF("get_heightfield_mask_value", 1, &gpu_particles_collision_height_field3d_class_get_heightfield_mask_value),
	JS_CFUNC_DEF("set_follow_camera_enabled", 1, &gpu_particles_collision_height_field3d_class_set_follow_camera_enabled),
	JS_CFUNC_DEF("is_follow_camera_enabled", 0, &gpu_particles_collision_height_field3d_class_is_follow_camera_enabled),
};




static void define_gpu_particles_collision_height_field3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resolution"),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_get_resolution, "get_resolution", 0),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_set_resolution, "set_resolution", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "update_mode"),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_get_update_mode, "get_update_mode", 0),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_set_update_mode, "set_update_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "follow_camera_enabled"),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_is_follow_camera_enabled, "is_follow_camera_enabled", 0),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_set_follow_camera_enabled, "set_follow_camera_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightfield_mask"),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_get_heightfield_mask, "get_heightfield_mask", 0),
        JS_NewCFunction(ctx, gpu_particles_collision_height_field3d_class_set_heightfield_mask, "set_heightfield_mask", 1),
        JS_PROP_GETSET
    );
}

static void define_gpu_particles_collision_height_field3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Resolution_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_256", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_512", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_1024", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_2048", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_4096", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_8192", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Resolution_obj, "RESOLUTION_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "Resolution", Resolution_obj);
	JSValue UpdateMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_MODE_WHEN_MOVED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_MODE_ALWAYS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "UpdateMode", UpdateMode_obj);
}

static int js_gpu_particles_collision_height_field3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GPUParticlesCollisionHeightField3D"] = class_id;
	classes_by_id[class_id] = "GPUParticlesCollisionHeightField3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gpu_particles_collision_height_field3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GPUParticlesCollision3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gpu_particles_collision_height_field3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gpu_particles_collision_height_field3d_class_proto_funcs, _countof(gpu_particles_collision_height_field3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gpu_particles_collision_height_field3d_class_constructor, "GPUParticlesCollisionHeightField3D", 0, JS_CFUNC_constructor, 0);
	define_gpu_particles_collision_height_field3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GPUParticlesCollisionHeightField3D", ctor);

	return 0;
}

JSModuleDef *_js_init_gpu_particles_collision_height_field3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/gpu_particles_collision3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gpu_particles_collision_height_field3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GPUParticlesCollisionHeightField3D");
	return m;
}

JSModuleDef *js_init_gpu_particles_collision_height_field3d_module(JSContext *ctx) {
	return _js_init_gpu_particles_collision_height_field3d_module(ctx, "@godot/classes/gpu_particles_collision_height_field3d");
}

void __register_gpu_particles_collision_height_field3d() {
	js_init_gpu_particles_collision_height_field3d_module(js_context());
}

void register_gpu_particles_collision_height_field3d() {
	__register_gpu_particles_collision_height_field3d();
}