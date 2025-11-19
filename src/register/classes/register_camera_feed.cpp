#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/camera_feed.hpp>
using namespace godot;

static void camera_feed_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CameraFeed"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef camera_feed_class_def = {
    "CameraFeed",
    camera_feed_class_finalizer
};

static JSValue camera_feed_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CameraFeed"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CameraFeed *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CameraFeed *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CameraFeed);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue camera_feed_class_get_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraFeed::get_id, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraFeed::is_active, ctx, this_val, argc, argv);
}
static JSValue camera_feed_class_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_active, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraFeed::get_name, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_set_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_name, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraFeed::get_position, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_position, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform2D> *proxy = memnew(ObjectProxy<Transform2D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform2D {
		CameraFeed *obj = static_cast<CameraFeed *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transform();
	};
	proxy->setter = [this_val](const Transform2D &value) -> void {
		CameraFeed *js_proxy = static_cast<CameraFeed *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_transform(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform2DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform2DProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue camera_feed_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_transform, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_set_rgb_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_rgb_image, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_set_ycbcr_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_ycbcr_image, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_set_external(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraFeed::set_external, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_get_texture_tex_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CameraFeed::get_texture_tex_id, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_get_datatype(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraFeed::get_datatype, ctx, this_val, argc, argv);
};
static JSValue camera_feed_class_get_formats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		CameraFeed *obj = static_cast<CameraFeed *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_formats();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue camera_feed_class_set_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CameraFeed::set_format, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry camera_feed_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_id", 0, &camera_feed_class_get_id),
	JS_CFUNC_DEF("is_active", 0, &camera_feed_class_is_active),
	JS_CFUNC_DEF("set_active", 1, &camera_feed_class_set_active),
	JS_CFUNC_DEF("get_name", 0, &camera_feed_class_get_name),
	JS_CFUNC_DEF("set_name", 1, &camera_feed_class_set_name),
	JS_CFUNC_DEF("get_position", 0, &camera_feed_class_get_position),
	JS_CFUNC_DEF("set_position", 1, &camera_feed_class_set_position),
	JS_CFUNC_DEF("get_transform", 0, &camera_feed_class_get_transform),
	JS_CFUNC_DEF("set_transform", 1, &camera_feed_class_set_transform),
	JS_CFUNC_DEF("set_rgb_image", 1, &camera_feed_class_set_rgb_image),
	JS_CFUNC_DEF("set_ycbcr_image", 1, &camera_feed_class_set_ycbcr_image),
	JS_CFUNC_DEF("set_external", 2, &camera_feed_class_set_external),
	JS_CFUNC_DEF("get_texture_tex_id", 1, &camera_feed_class_get_texture_tex_id),
	JS_CFUNC_DEF("get_datatype", 0, &camera_feed_class_get_datatype),
	JS_CFUNC_DEF("get_formats", 0, &camera_feed_class_get_formats),
	JS_CFUNC_DEF("set_format", 2, &camera_feed_class_set_format),
};


static JSValue camera_feed_class_get_frame_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CameraFeed *opaque = static_cast<CameraFeed *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "frame_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "frame_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "frame_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue camera_feed_class_get_format_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CameraFeed *opaque = static_cast<CameraFeed *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "format_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "format_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "format_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_camera_feed_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feed_is_active"),
        JS_NewCFunction(ctx, camera_feed_class_is_active, "is_active", 0),
        JS_NewCFunction(ctx, camera_feed_class_set_active, "set_active", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feed_transform"),
        JS_NewCFunction(ctx, camera_feed_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, camera_feed_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "formats"),
        JS_NewCFunction(ctx, camera_feed_class_get_formats, "get_formats", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "frame_changed"),
		JS_NewCFunction(ctx, camera_feed_class_get_frame_changed_signal, "get_frame_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "format_changed"),
		JS_NewCFunction(ctx, camera_feed_class_get_format_changed_signal, "get_format_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_camera_feed_enum(JSContext *ctx, JSValue ctor) {
	JSValue FeedDataType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FeedDataType_obj, "FEED_NOIMAGE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FeedDataType_obj, "FEED_RGB", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FeedDataType_obj, "FEED_YCBCR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FeedDataType_obj, "FEED_YCBCR_SEP", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, FeedDataType_obj, "FEED_EXTERNAL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "FeedDataType", FeedDataType_obj);
	JSValue FeedPosition_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FeedPosition_obj, "FEED_UNSPECIFIED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FeedPosition_obj, "FEED_FRONT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FeedPosition_obj, "FEED_BACK", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "FeedPosition", FeedPosition_obj);
}

static int js_camera_feed_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CameraFeed"] = class_id;
	classes_by_id[class_id] = "CameraFeed";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &camera_feed_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_camera_feed_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, camera_feed_class_proto_funcs, _countof(camera_feed_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, camera_feed_class_constructor, "CameraFeed", 0, JS_CFUNC_constructor, 0);
	define_camera_feed_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CameraFeed", ctor);

	return 0;
}

JSModuleDef *_js_init_camera_feed_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_camera_feed_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CameraFeed");
	return m;
}

JSModuleDef *js_init_camera_feed_module(JSContext *ctx) {
	return _js_init_camera_feed_module(ctx, "@godot/classes/camera_feed");
}

void __register_camera_feed() {
	js_init_camera_feed_module(js_context());
}

void register_camera_feed() {
	__register_camera_feed();
}