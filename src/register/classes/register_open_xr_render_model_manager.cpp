#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/open_xr_render_model.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_render_model_manager.hpp>
using namespace godot;

static void open_xr_render_model_manager_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRRenderModelManager"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_render_model_manager_class_def = {
    "OpenXRRenderModelManager",
    open_xr_render_model_manager_class_finalizer
};

static JSValue open_xr_render_model_manager_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRRenderModelManager"];
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
        instance = memnew(OpenXRRenderModelManager);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_render_model_manager_class_get_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelManager::get_tracker, ctx, this_val, argc, argv);
}
static JSValue open_xr_render_model_manager_class_set_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRRenderModelManager::set_tracker, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_manager_class_get_make_local_to_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelManager::get_make_local_to_pose, ctx, this_val, argc, argv);
}
static JSValue open_xr_render_model_manager_class_set_make_local_to_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRRenderModelManager::set_make_local_to_pose, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_render_model_manager_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_tracker", 0, &open_xr_render_model_manager_class_get_tracker),
	JS_CFUNC_DEF("set_tracker", 1, &open_xr_render_model_manager_class_set_tracker),
	JS_CFUNC_DEF("get_make_local_to_pose", 0, &open_xr_render_model_manager_class_get_make_local_to_pose),
	JS_CFUNC_DEF("set_make_local_to_pose", 1, &open_xr_render_model_manager_class_set_make_local_to_pose),
};


static JSValue open_xr_render_model_manager_class_get_render_model_added_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	OpenXRRenderModelManager *opaque = static_cast<OpenXRRenderModelManager *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "render_model_added_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "render_model_added"));
		JS_DefinePropertyValueStr(ctx, this_val, "render_model_added_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue open_xr_render_model_manager_class_get_render_model_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	OpenXRRenderModelManager *opaque = static_cast<OpenXRRenderModelManager *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "render_model_removed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "render_model_removed"));
		JS_DefinePropertyValueStr(ctx, this_val, "render_model_removed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_open_xr_render_model_manager_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tracker"),
        JS_NewCFunction(ctx, open_xr_render_model_manager_class_get_tracker, "get_tracker", 0),
        JS_NewCFunction(ctx, open_xr_render_model_manager_class_set_tracker, "set_tracker", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "make_local_to_pose"),
        JS_NewCFunction(ctx, open_xr_render_model_manager_class_get_make_local_to_pose, "get_make_local_to_pose", 0),
        JS_NewCFunction(ctx, open_xr_render_model_manager_class_set_make_local_to_pose, "set_make_local_to_pose", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "render_model_added"),
		JS_NewCFunction(ctx, open_xr_render_model_manager_class_get_render_model_added_signal, "get_render_model_added_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "render_model_removed"),
		JS_NewCFunction(ctx, open_xr_render_model_manager_class_get_render_model_removed_signal, "get_render_model_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_open_xr_render_model_manager_enum(JSContext *ctx, JSValue ctor) {
	JSValue RenderModelTracker_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RenderModelTracker_obj, "RENDER_MODEL_TRACKER_ANY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RenderModelTracker_obj, "RENDER_MODEL_TRACKER_NONE_SET", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RenderModelTracker_obj, "RENDER_MODEL_TRACKER_LEFT_HAND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, RenderModelTracker_obj, "RENDER_MODEL_TRACKER_RIGHT_HAND", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "RenderModelTracker", RenderModelTracker_obj);
}

static int js_open_xr_render_model_manager_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRRenderModelManager"] = class_id;
	classes_by_id[class_id] = "OpenXRRenderModelManager";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_render_model_manager_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_render_model_manager_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_render_model_manager_class_proto_funcs, _countof(open_xr_render_model_manager_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_render_model_manager_class_constructor, "OpenXRRenderModelManager", 0, JS_CFUNC_constructor, 0);
	define_open_xr_render_model_manager_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRRenderModelManager", ctor);
	ctor_list["OpenXRRenderModelManager"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_render_model_manager_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_render_model_manager_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRRenderModelManager");
	return m;
}

JSModuleDef *js_init_open_xr_render_model_manager_module(JSContext *ctx) {
	return _js_init_open_xr_render_model_manager_module(ctx, "@godot/classes/open_xr_render_model_manager");
}

void __register_open_xr_render_model_manager() {
	js_init_open_xr_render_model_manager_module(js_context());
}

void register_open_xr_render_model_manager() {
	__register_open_xr_render_model_manager();
}