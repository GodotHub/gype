#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera_attributes.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/classes/voxel_gi_data.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/voxel_gi.hpp>
using namespace godot;

static void voxel_gi_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VoxelGI"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef voxel_gi_class_def = {
    "VoxelGI",
    voxel_gi_class_finalizer
};

static JSValue voxel_gi_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VoxelGI"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VoxelGI *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VoxelGI *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VoxelGI);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue voxel_gi_class_set_probe_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VoxelGI::set_probe_data, ctx, this_val, argc, argv);
};
static JSValue voxel_gi_class_get_probe_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VoxelGI::get_probe_data, ctx, this_val, argc, argv);
}
static JSValue voxel_gi_class_set_subdiv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VoxelGI::set_subdiv, ctx, this_val, argc, argv);
};
static JSValue voxel_gi_class_get_subdiv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VoxelGI::get_subdiv, ctx, this_val, argc, argv);
}
static JSValue voxel_gi_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VoxelGI::set_size, ctx, this_val, argc, argv);
};
static JSValue voxel_gi_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		VoxelGI *obj = static_cast<VoxelGI *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		VoxelGI *js_proxy = static_cast<VoxelGI *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue voxel_gi_class_set_camera_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VoxelGI::set_camera_attributes, ctx, this_val, argc, argv);
};
static JSValue voxel_gi_class_get_camera_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VoxelGI::get_camera_attributes, ctx, this_val, argc, argv);
}
static JSValue voxel_gi_class_bake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VoxelGI::bake, ctx, this_val, argc, argv);
};
static JSValue voxel_gi_class_debug_bake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VoxelGI::debug_bake, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry voxel_gi_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_probe_data", 1, &voxel_gi_class_set_probe_data),
	JS_CFUNC_DEF("get_probe_data", 0, &voxel_gi_class_get_probe_data),
	JS_CFUNC_DEF("set_subdiv", 1, &voxel_gi_class_set_subdiv),
	JS_CFUNC_DEF("get_subdiv", 0, &voxel_gi_class_get_subdiv),
	JS_CFUNC_DEF("set_size", 1, &voxel_gi_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &voxel_gi_class_get_size),
	JS_CFUNC_DEF("set_camera_attributes", 1, &voxel_gi_class_set_camera_attributes),
	JS_CFUNC_DEF("get_camera_attributes", 0, &voxel_gi_class_get_camera_attributes),
	JS_CFUNC_DEF("bake", 2, &voxel_gi_class_bake),
	JS_CFUNC_DEF("debug_bake", 0, &voxel_gi_class_debug_bake),
};




static void define_voxel_gi_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subdiv"),
        JS_NewCFunction(ctx, voxel_gi_class_get_subdiv, "get_subdiv", 0),
        JS_NewCFunction(ctx, voxel_gi_class_set_subdiv, "set_subdiv", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, voxel_gi_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, voxel_gi_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "camera_attributes"),
        JS_NewCFunction(ctx, voxel_gi_class_get_camera_attributes, "get_camera_attributes", 0),
        JS_NewCFunction(ctx, voxel_gi_class_set_camera_attributes, "set_camera_attributes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "data"),
        JS_NewCFunction(ctx, voxel_gi_class_get_probe_data, "get_probe_data", 0),
        JS_NewCFunction(ctx, voxel_gi_class_set_probe_data, "set_probe_data", 1),
        JS_PROP_GETSET
    );
}

static void define_voxel_gi_enum(JSContext *ctx, JSValue proto) {
	JSValue Subdiv_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Subdiv_obj, "SUBDIV_64", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Subdiv_obj, "SUBDIV_128", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Subdiv_obj, "SUBDIV_256", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Subdiv_obj, "SUBDIV_512", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Subdiv_obj, "SUBDIV_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "Subdiv", Subdiv_obj);
}

static int js_voxel_gi_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VoxelGI"] = class_id;
	classes_by_id[class_id] = "VoxelGI";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &voxel_gi_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_voxel_gi_property(ctx, proto);
	define_voxel_gi_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, voxel_gi_class_proto_funcs, _countof(voxel_gi_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, voxel_gi_class_constructor, "VoxelGI", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VoxelGI", ctor);

	return 0;
}

JSModuleDef *_js_init_voxel_gi_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_voxel_gi_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VoxelGI");
	return m;
}

JSModuleDef *js_init_voxel_gi_module(JSContext *ctx) {
	return _js_init_voxel_gi_module(ctx, "@godot/classes/voxel_gi");
}

void __register_voxel_gi() {
	js_init_voxel_gi_module(js_context());
}

void register_voxel_gi() {
	__register_voxel_gi();
}