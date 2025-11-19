#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>
using namespace godot;

static void canvas_layer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CanvasLayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef canvas_layer_class_def = {
    "CanvasLayer",
    canvas_layer_class_finalizer
};

static JSValue canvas_layer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CanvasLayer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CanvasLayer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CanvasLayer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CanvasLayer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue canvas_layer_class_set_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_layer, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::get_layer, ctx, this_val, argc, argv);
}
static JSValue canvas_layer_class_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_visible, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::is_visible, ctx, this_val, argc, argv);
}
static JSValue canvas_layer_class_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::show, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_hide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::hide, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_transform, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform2D> *proxy = memnew(ObjectProxy<Transform2D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform2D {
		CanvasLayer *obj = static_cast<CanvasLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transform();
	};
	proxy->setter = [this_val](const Transform2D &value) -> void {
		CanvasLayer *js_proxy = static_cast<CanvasLayer *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue canvas_layer_class_get_final_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::get_final_transform, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_offset, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		CanvasLayer *obj = static_cast<CanvasLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		CanvasLayer *js_proxy = static_cast<CanvasLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset(value);
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
static JSValue canvas_layer_class_set_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_rotation, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::get_rotation, ctx, this_val, argc, argv);
}
static JSValue canvas_layer_class_set_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_scale, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		CanvasLayer *obj = static_cast<CanvasLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scale();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		CanvasLayer *js_proxy = static_cast<CanvasLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scale(value);
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
static JSValue canvas_layer_class_set_follow_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_follow_viewport, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_is_following_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::is_following_viewport, ctx, this_val, argc, argv);
}
static JSValue canvas_layer_class_set_follow_viewport_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_follow_viewport_scale, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_follow_viewport_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::get_follow_viewport_scale, ctx, this_val, argc, argv);
}
static JSValue canvas_layer_class_set_custom_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasLayer::set_custom_viewport, ctx, this_val, argc, argv);
};
static JSValue canvas_layer_class_get_custom_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::get_custom_viewport, ctx, this_val, argc, argv);
}
static JSValue canvas_layer_class_get_canvas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasLayer::get_canvas, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry canvas_layer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_layer", 1, &canvas_layer_class_set_layer),
	JS_CFUNC_DEF("get_layer", 0, &canvas_layer_class_get_layer),
	JS_CFUNC_DEF("set_visible", 1, &canvas_layer_class_set_visible),
	JS_CFUNC_DEF("is_visible", 0, &canvas_layer_class_is_visible),
	JS_CFUNC_DEF("show", 0, &canvas_layer_class_show),
	JS_CFUNC_DEF("hide", 0, &canvas_layer_class_hide),
	JS_CFUNC_DEF("set_transform", 1, &canvas_layer_class_set_transform),
	JS_CFUNC_DEF("get_transform", 0, &canvas_layer_class_get_transform),
	JS_CFUNC_DEF("get_final_transform", 0, &canvas_layer_class_get_final_transform),
	JS_CFUNC_DEF("set_offset", 1, &canvas_layer_class_set_offset),
	JS_CFUNC_DEF("get_offset", 0, &canvas_layer_class_get_offset),
	JS_CFUNC_DEF("set_rotation", 1, &canvas_layer_class_set_rotation),
	JS_CFUNC_DEF("get_rotation", 0, &canvas_layer_class_get_rotation),
	JS_CFUNC_DEF("set_scale", 1, &canvas_layer_class_set_scale),
	JS_CFUNC_DEF("get_scale", 0, &canvas_layer_class_get_scale),
	JS_CFUNC_DEF("set_follow_viewport", 1, &canvas_layer_class_set_follow_viewport),
	JS_CFUNC_DEF("is_following_viewport", 0, &canvas_layer_class_is_following_viewport),
	JS_CFUNC_DEF("set_follow_viewport_scale", 1, &canvas_layer_class_set_follow_viewport_scale),
	JS_CFUNC_DEF("get_follow_viewport_scale", 0, &canvas_layer_class_get_follow_viewport_scale),
	JS_CFUNC_DEF("set_custom_viewport", 1, &canvas_layer_class_set_custom_viewport),
	JS_CFUNC_DEF("get_custom_viewport", 0, &canvas_layer_class_get_custom_viewport),
	JS_CFUNC_DEF("get_canvas", 0, &canvas_layer_class_get_canvas),
};


static JSValue canvas_layer_class_get_visibility_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CanvasLayer *opaque = static_cast<CanvasLayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "visibility_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "visibility_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "visibility_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_canvas_layer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "layer"),
        JS_NewCFunction(ctx, canvas_layer_class_get_layer, "get_layer", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_layer, "set_layer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible"),
        JS_NewCFunction(ctx, canvas_layer_class_is_visible, "is_visible", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_visible, "set_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, canvas_layer_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation"),
        JS_NewCFunction(ctx, canvas_layer_class_get_rotation, "get_rotation", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_rotation, "set_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale"),
        JS_NewCFunction(ctx, canvas_layer_class_get_scale, "get_scale", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_scale, "set_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform"),
        JS_NewCFunction(ctx, canvas_layer_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_viewport"),
        JS_NewCFunction(ctx, canvas_layer_class_get_custom_viewport, "get_custom_viewport", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_custom_viewport, "set_custom_viewport", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "follow_viewport_enabled"),
        JS_NewCFunction(ctx, canvas_layer_class_is_following_viewport, "is_following_viewport", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_follow_viewport, "set_follow_viewport", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "follow_viewport_scale"),
        JS_NewCFunction(ctx, canvas_layer_class_get_follow_viewport_scale, "get_follow_viewport_scale", 0),
        JS_NewCFunction(ctx, canvas_layer_class_set_follow_viewport_scale, "set_follow_viewport_scale", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "visibility_changed"),
		JS_NewCFunction(ctx, canvas_layer_class_get_visibility_changed_signal, "get_visibility_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_canvas_layer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_canvas_layer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CanvasLayer"] = class_id;
	classes_by_id[class_id] = "CanvasLayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &canvas_layer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_canvas_layer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, canvas_layer_class_proto_funcs, _countof(canvas_layer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, canvas_layer_class_constructor, "CanvasLayer", 0, JS_CFUNC_constructor, 0);
	define_canvas_layer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CanvasLayer", ctor);

	return 0;
}

JSModuleDef *_js_init_canvas_layer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_canvas_layer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CanvasLayer");
	return m;
}

JSModuleDef *js_init_canvas_layer_module(JSContext *ctx) {
	return _js_init_canvas_layer_module(ctx, "@godot/classes/canvas_layer");
}

void __register_canvas_layer() {
	js_init_canvas_layer_module(js_context());
}

void register_canvas_layer() {
	__register_canvas_layer();
}