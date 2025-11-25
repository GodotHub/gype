#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/parallax_background.hpp>
using namespace godot;

static void parallax_background_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ParallaxBackground"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef parallax_background_class_def = {
    "ParallaxBackground",
    parallax_background_class_finalizer
};

static JSValue parallax_background_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ParallaxBackground"];
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
        instance = memnew(ParallaxBackground);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue parallax_background_class_set_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxBackground::set_scroll_offset, ctx, this_val, argc, argv);
};
static JSValue parallax_background_class_get_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxBackground *obj = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scroll_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxBackground *js_proxy = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scroll_offset(value);
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
static JSValue parallax_background_class_set_scroll_base_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxBackground::set_scroll_base_offset, ctx, this_val, argc, argv);
};
static JSValue parallax_background_class_get_scroll_base_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxBackground *obj = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scroll_base_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxBackground *js_proxy = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scroll_base_offset(value);
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
static JSValue parallax_background_class_set_scroll_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxBackground::set_scroll_base_scale, ctx, this_val, argc, argv);
};
static JSValue parallax_background_class_get_scroll_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxBackground *obj = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scroll_base_scale();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxBackground *js_proxy = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scroll_base_scale(value);
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
static JSValue parallax_background_class_set_limit_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxBackground::set_limit_begin, ctx, this_val, argc, argv);
};
static JSValue parallax_background_class_get_limit_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxBackground *obj = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_limit_begin();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxBackground *js_proxy = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_limit_begin(value);
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
static JSValue parallax_background_class_set_limit_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxBackground::set_limit_end, ctx, this_val, argc, argv);
};
static JSValue parallax_background_class_get_limit_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxBackground *obj = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_limit_end();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxBackground *js_proxy = static_cast<ParallaxBackground *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_limit_end(value);
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
static JSValue parallax_background_class_set_ignore_camera_zoom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxBackground::set_ignore_camera_zoom, ctx, this_val, argc, argv);
};
static JSValue parallax_background_class_is_ignore_camera_zoom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ParallaxBackground::is_ignore_camera_zoom, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry parallax_background_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_scroll_offset", 1, &parallax_background_class_set_scroll_offset),
	JS_CFUNC_DEF("get_scroll_offset", 0, &parallax_background_class_get_scroll_offset),
	JS_CFUNC_DEF("set_scroll_base_offset", 1, &parallax_background_class_set_scroll_base_offset),
	JS_CFUNC_DEF("get_scroll_base_offset", 0, &parallax_background_class_get_scroll_base_offset),
	JS_CFUNC_DEF("set_scroll_base_scale", 1, &parallax_background_class_set_scroll_base_scale),
	JS_CFUNC_DEF("get_scroll_base_scale", 0, &parallax_background_class_get_scroll_base_scale),
	JS_CFUNC_DEF("set_limit_begin", 1, &parallax_background_class_set_limit_begin),
	JS_CFUNC_DEF("get_limit_begin", 0, &parallax_background_class_get_limit_begin),
	JS_CFUNC_DEF("set_limit_end", 1, &parallax_background_class_set_limit_end),
	JS_CFUNC_DEF("get_limit_end", 0, &parallax_background_class_get_limit_end),
	JS_CFUNC_DEF("set_ignore_camera_zoom", 1, &parallax_background_class_set_ignore_camera_zoom),
	JS_CFUNC_DEF("is_ignore_camera_zoom", 0, &parallax_background_class_is_ignore_camera_zoom),
};




static void define_parallax_background_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_offset"),
        JS_NewCFunction(ctx, parallax_background_class_get_scroll_offset, "get_scroll_offset", 0),
        JS_NewCFunction(ctx, parallax_background_class_set_scroll_offset, "set_scroll_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_base_offset"),
        JS_NewCFunction(ctx, parallax_background_class_get_scroll_base_offset, "get_scroll_base_offset", 0),
        JS_NewCFunction(ctx, parallax_background_class_set_scroll_base_offset, "set_scroll_base_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_base_scale"),
        JS_NewCFunction(ctx, parallax_background_class_get_scroll_base_scale, "get_scroll_base_scale", 0),
        JS_NewCFunction(ctx, parallax_background_class_set_scroll_base_scale, "set_scroll_base_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_limit_begin"),
        JS_NewCFunction(ctx, parallax_background_class_get_limit_begin, "get_limit_begin", 0),
        JS_NewCFunction(ctx, parallax_background_class_set_limit_begin, "set_limit_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_limit_end"),
        JS_NewCFunction(ctx, parallax_background_class_get_limit_end, "get_limit_end", 0),
        JS_NewCFunction(ctx, parallax_background_class_set_limit_end, "set_limit_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_ignore_camera_zoom"),
        JS_NewCFunction(ctx, parallax_background_class_is_ignore_camera_zoom, "is_ignore_camera_zoom", 0),
        JS_NewCFunction(ctx, parallax_background_class_set_ignore_camera_zoom, "set_ignore_camera_zoom", 1),
        JS_PROP_GETSET
    );
}

static void define_parallax_background_enum(JSContext *ctx, JSValue ctor) {
}

static int js_parallax_background_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ParallaxBackground"] = class_id;
	classes_by_id[class_id] = "ParallaxBackground";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &parallax_background_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CanvasLayer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_parallax_background_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, parallax_background_class_proto_funcs, _countof(parallax_background_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, parallax_background_class_constructor, "ParallaxBackground", 0, JS_CFUNC_constructor, 0);
	define_parallax_background_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ParallaxBackground", ctor);
	ctor_list["ParallaxBackground"] = ctor;

	return 0;
}

JSModuleDef *_js_init_parallax_background_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/canvas_layer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_parallax_background_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ParallaxBackground");
	return m;
}

JSModuleDef *js_init_parallax_background_module(JSContext *ctx) {
	return _js_init_parallax_background_module(ctx, "@godot/classes/parallax_background");
}

void __register_parallax_background() {
	js_init_parallax_background_module(js_context());
}

void register_parallax_background() {
	__register_parallax_background();
}