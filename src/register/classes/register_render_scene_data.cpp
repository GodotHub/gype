#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/render_scene_data.hpp>
using namespace godot;

static void render_scene_data_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RenderSceneData"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef render_scene_data_class_def = {
    "RenderSceneData",
    render_scene_data_class_finalizer
};

static JSValue render_scene_data_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RenderSceneData"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RenderSceneData *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RenderSceneData *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RenderSceneData);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue render_scene_data_class_get_cam_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneData::get_cam_transform, ctx, this_val, argc, argv);
};
static JSValue render_scene_data_class_get_cam_projection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneData::get_cam_projection, ctx, this_val, argc, argv);
};
static JSValue render_scene_data_class_get_view_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneData::get_view_count, ctx, this_val, argc, argv);
};
static JSValue render_scene_data_class_get_view_eye_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneData::get_view_eye_offset, ctx, this_val, argc, argv);
};
static JSValue render_scene_data_class_get_view_projection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneData::get_view_projection, ctx, this_val, argc, argv);
};
static JSValue render_scene_data_class_get_uniform_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneData::get_uniform_buffer, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry render_scene_data_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_cam_transform", 0, &render_scene_data_class_get_cam_transform),
	JS_CFUNC_DEF("get_cam_projection", 0, &render_scene_data_class_get_cam_projection),
	JS_CFUNC_DEF("get_view_count", 0, &render_scene_data_class_get_view_count),
	JS_CFUNC_DEF("get_view_eye_offset", 1, &render_scene_data_class_get_view_eye_offset),
	JS_CFUNC_DEF("get_view_projection", 1, &render_scene_data_class_get_view_projection),
	JS_CFUNC_DEF("get_uniform_buffer", 0, &render_scene_data_class_get_uniform_buffer),
};




static void define_render_scene_data_property(JSContext *ctx, JSValue proto) {
}

static void define_render_scene_data_enum(JSContext *ctx, JSValue ctor) {
}

static int js_render_scene_data_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RenderSceneData"] = class_id;
	classes_by_id[class_id] = "RenderSceneData";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &render_scene_data_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_render_scene_data_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, render_scene_data_class_proto_funcs, _countof(render_scene_data_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, render_scene_data_class_constructor, "RenderSceneData", 0, JS_CFUNC_constructor, 0);
	define_render_scene_data_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RenderSceneData", ctor);

	return 0;
}

JSModuleDef *_js_init_render_scene_data_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_render_scene_data_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RenderSceneData");
	return m;
}

JSModuleDef *js_init_render_scene_data_module(JSContext *ctx) {
	return _js_init_render_scene_data_module(ctx, "@godot/classes/render_scene_data");
}

void __register_render_scene_data() {
	js_init_render_scene_data_module(js_context());
}

void register_render_scene_data() {
	__register_render_scene_data();
}