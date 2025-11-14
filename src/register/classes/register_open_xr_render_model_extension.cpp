#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/open_xr_extension_wrapper.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_render_model_extension.hpp>
using namespace godot;

static void open_xr_render_model_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRRenderModelExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_render_model_extension_class_def = {
    "OpenXRRenderModelExtension",
    open_xr_render_model_extension_class_finalizer
};

static JSValue open_xr_render_model_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRRenderModelExtension"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRRenderModelExtension *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRRenderModelExtension *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRRenderModelExtension);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_render_model_extension_class_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::is_active, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRRenderModelExtension::render_model_create, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_destroy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRRenderModelExtension::render_model_destroy, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRRenderModelExtension::render_model_get_all, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_new_scene_instance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_new_scene_instance, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_subaction_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRRenderModelExtension::render_model_get_subaction_paths, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_top_level_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_get_top_level_path, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_confidence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_get_confidence, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_root_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_get_root_transform, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_animatable_node_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_get_animatable_node_count, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_animatable_node_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_get_animatable_node_name, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_is_animatable_node_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_is_animatable_node_visible, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_extension_class_render_model_get_animatable_node_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModelExtension::render_model_get_animatable_node_transform, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry open_xr_render_model_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_active", 0, &open_xr_render_model_extension_class_is_active),
	JS_CFUNC_DEF("render_model_create", 1, &open_xr_render_model_extension_class_render_model_create),
	JS_CFUNC_DEF("render_model_destroy", 1, &open_xr_render_model_extension_class_render_model_destroy),
	JS_CFUNC_DEF("render_model_get_all", 0, &open_xr_render_model_extension_class_render_model_get_all),
	JS_CFUNC_DEF("render_model_new_scene_instance", 1, &open_xr_render_model_extension_class_render_model_new_scene_instance),
	JS_CFUNC_DEF("render_model_get_subaction_paths", 1, &open_xr_render_model_extension_class_render_model_get_subaction_paths),
	JS_CFUNC_DEF("render_model_get_top_level_path", 1, &open_xr_render_model_extension_class_render_model_get_top_level_path),
	JS_CFUNC_DEF("render_model_get_confidence", 1, &open_xr_render_model_extension_class_render_model_get_confidence),
	JS_CFUNC_DEF("render_model_get_root_transform", 1, &open_xr_render_model_extension_class_render_model_get_root_transform),
	JS_CFUNC_DEF("render_model_get_animatable_node_count", 1, &open_xr_render_model_extension_class_render_model_get_animatable_node_count),
	JS_CFUNC_DEF("render_model_get_animatable_node_name", 2, &open_xr_render_model_extension_class_render_model_get_animatable_node_name),
	JS_CFUNC_DEF("render_model_is_animatable_node_visible", 2, &open_xr_render_model_extension_class_render_model_is_animatable_node_visible),
	JS_CFUNC_DEF("render_model_get_animatable_node_transform", 2, &open_xr_render_model_extension_class_render_model_get_animatable_node_transform),
};


static JSValue open_xr_render_model_extension_class_get_render_model_added_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	OpenXRRenderModelExtension *opaque = static_cast<OpenXRRenderModelExtension *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "render_model_added_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "render_model_added"));
		JS_DefinePropertyValueStr(ctx, this_val, "render_model_added_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue open_xr_render_model_extension_class_get_render_model_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	OpenXRRenderModelExtension *opaque = static_cast<OpenXRRenderModelExtension *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "render_model_removed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "render_model_removed"));
		JS_DefinePropertyValueStr(ctx, this_val, "render_model_removed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue open_xr_render_model_extension_class_get_render_model_top_level_path_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	OpenXRRenderModelExtension *opaque = static_cast<OpenXRRenderModelExtension *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "render_model_top_level_path_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "render_model_top_level_path_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "render_model_top_level_path_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_open_xr_render_model_extension_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "render_model_added"),
		JS_NewCFunction(ctx, open_xr_render_model_extension_class_get_render_model_added_signal, "get_render_model_added_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "render_model_removed"),
		JS_NewCFunction(ctx, open_xr_render_model_extension_class_get_render_model_removed_signal, "get_render_model_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "render_model_top_level_path_changed"),
		JS_NewCFunction(ctx, open_xr_render_model_extension_class_get_render_model_top_level_path_changed_signal, "get_render_model_top_level_path_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_open_xr_render_model_extension_enum(JSContext *ctx, JSValue proto) {
}

static int js_open_xr_render_model_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRRenderModelExtension"] = class_id;
	classes_by_id[class_id] = "OpenXRRenderModelExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_render_model_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["OpenXRExtensionWrapper"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_render_model_extension_property(ctx, proto);
	define_open_xr_render_model_extension_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_render_model_extension_class_proto_funcs, _countof(open_xr_render_model_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_render_model_extension_class_constructor, "OpenXRRenderModelExtension", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRRenderModelExtension", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_render_model_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/open_xr_extension_wrapper';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_render_model_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRRenderModelExtension");
	return m;
}

JSModuleDef *js_init_open_xr_render_model_extension_module(JSContext *ctx) {
	return _js_init_open_xr_render_model_extension_module(ctx, "@godot/classes/open_xr_render_model_extension");
}

void __register_open_xr_render_model_extension() {
	js_init_open_xr_render_model_extension_module(js_context());
}

void register_open_xr_render_model_extension() {
	__register_open_xr_render_model_extension();
}