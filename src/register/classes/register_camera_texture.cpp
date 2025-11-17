#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/camera_texture.hpp>
using namespace godot;

static void camera_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CameraTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef camera_texture_class_def = {
    "CameraTexture",
    camera_texture_class_finalizer
};

static JSValue camera_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CameraTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CameraTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CameraTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CameraTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue camera_texture_class_set_camera_feed_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraTexture::set_camera_feed_id, ctx, this_val, argc, argv);
};
static JSValue camera_texture_class_get_camera_feed_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraTexture::get_camera_feed_id, ctx, this_val, argc, argv);
}
static JSValue camera_texture_class_set_which_feed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraTexture::set_which_feed, ctx, this_val, argc, argv);
};
static JSValue camera_texture_class_get_which_feed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraTexture::get_which_feed, ctx, this_val, argc, argv);
}
static JSValue camera_texture_class_set_camera_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraTexture::set_camera_active, ctx, this_val, argc, argv);
};
static JSValue camera_texture_class_get_camera_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraTexture::get_camera_active, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry camera_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_camera_feed_id", 1, &camera_texture_class_set_camera_feed_id),
	JS_CFUNC_DEF("get_camera_feed_id", 0, &camera_texture_class_get_camera_feed_id),
	JS_CFUNC_DEF("set_which_feed", 1, &camera_texture_class_set_which_feed),
	JS_CFUNC_DEF("get_which_feed", 0, &camera_texture_class_get_which_feed),
	JS_CFUNC_DEF("set_camera_active", 1, &camera_texture_class_set_camera_active),
	JS_CFUNC_DEF("get_camera_active", 0, &camera_texture_class_get_camera_active),
};




static void define_camera_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "camera_feed_id"),
        JS_NewCFunction(ctx, camera_texture_class_get_camera_feed_id, "get_camera_feed_id", 0),
        JS_NewCFunction(ctx, camera_texture_class_set_camera_feed_id, "set_camera_feed_id", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "which_feed"),
        JS_NewCFunction(ctx, camera_texture_class_get_which_feed, "get_which_feed", 0),
        JS_NewCFunction(ctx, camera_texture_class_set_which_feed, "set_which_feed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "camera_is_active"),
        JS_NewCFunction(ctx, camera_texture_class_get_camera_active, "get_camera_active", 0),
        JS_NewCFunction(ctx, camera_texture_class_set_camera_active, "set_camera_active", 1),
        JS_PROP_GETSET
    );
}

static void define_camera_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_camera_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CameraTexture"] = class_id;
	classes_by_id[class_id] = "CameraTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &camera_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_camera_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, camera_texture_class_proto_funcs, _countof(camera_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, camera_texture_class_constructor, "CameraTexture", 0, JS_CFUNC_constructor, 0);
	define_camera_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CameraTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_camera_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_camera_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CameraTexture");
	return m;
}

JSModuleDef *js_init_camera_texture_module(JSContext *ctx) {
	return _js_init_camera_texture_module(ctx, "@godot/classes/camera_texture");
}

void __register_camera_texture() {
	js_init_camera_texture_module(js_context());
}

void register_camera_texture() {
	__register_camera_texture();
}