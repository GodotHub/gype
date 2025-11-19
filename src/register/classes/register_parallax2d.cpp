#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/parallax2d.hpp>
using namespace godot;

static void parallax2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Parallax2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef parallax2d_class_def = {
    "Parallax2D",
    parallax2d_class_finalizer
};

static JSValue parallax2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Parallax2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Parallax2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Parallax2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Parallax2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue parallax2d_class_set_scroll_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_scroll_scale, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_scroll_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scroll_scale();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scroll_scale(value);
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
static JSValue parallax2d_class_set_repeat_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_repeat_size, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_repeat_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_repeat_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_repeat_size(value);
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
static JSValue parallax2d_class_set_repeat_times(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_repeat_times, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_repeat_times(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Parallax2D::get_repeat_times, ctx, this_val, argc, argv);
}
static JSValue parallax2d_class_set_autoscroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_autoscroll, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_autoscroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_autoscroll();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_autoscroll(value);
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
static JSValue parallax2d_class_set_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_scroll_offset, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scroll_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue parallax2d_class_set_screen_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_screen_offset, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_screen_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_screen_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_screen_offset(value);
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
static JSValue parallax2d_class_set_limit_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_limit_begin, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_limit_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_limit_begin();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue parallax2d_class_set_limit_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_limit_end, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_limit_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		Parallax2D *obj = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_limit_end();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		Parallax2D *js_proxy = static_cast<Parallax2D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue parallax2d_class_set_follow_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_follow_viewport, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_get_follow_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Parallax2D::get_follow_viewport, ctx, this_val, argc, argv);
}
static JSValue parallax2d_class_set_ignore_camera_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Parallax2D::set_ignore_camera_scroll, ctx, this_val, argc, argv);
};
static JSValue parallax2d_class_is_ignore_camera_scroll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Parallax2D::is_ignore_camera_scroll, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry parallax2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_scroll_scale", 1, &parallax2d_class_set_scroll_scale),
	JS_CFUNC_DEF("get_scroll_scale", 0, &parallax2d_class_get_scroll_scale),
	JS_CFUNC_DEF("set_repeat_size", 1, &parallax2d_class_set_repeat_size),
	JS_CFUNC_DEF("get_repeat_size", 0, &parallax2d_class_get_repeat_size),
	JS_CFUNC_DEF("set_repeat_times", 1, &parallax2d_class_set_repeat_times),
	JS_CFUNC_DEF("get_repeat_times", 0, &parallax2d_class_get_repeat_times),
	JS_CFUNC_DEF("set_autoscroll", 1, &parallax2d_class_set_autoscroll),
	JS_CFUNC_DEF("get_autoscroll", 0, &parallax2d_class_get_autoscroll),
	JS_CFUNC_DEF("set_scroll_offset", 1, &parallax2d_class_set_scroll_offset),
	JS_CFUNC_DEF("get_scroll_offset", 0, &parallax2d_class_get_scroll_offset),
	JS_CFUNC_DEF("set_screen_offset", 1, &parallax2d_class_set_screen_offset),
	JS_CFUNC_DEF("get_screen_offset", 0, &parallax2d_class_get_screen_offset),
	JS_CFUNC_DEF("set_limit_begin", 1, &parallax2d_class_set_limit_begin),
	JS_CFUNC_DEF("get_limit_begin", 0, &parallax2d_class_get_limit_begin),
	JS_CFUNC_DEF("set_limit_end", 1, &parallax2d_class_set_limit_end),
	JS_CFUNC_DEF("get_limit_end", 0, &parallax2d_class_get_limit_end),
	JS_CFUNC_DEF("set_follow_viewport", 1, &parallax2d_class_set_follow_viewport),
	JS_CFUNC_DEF("get_follow_viewport", 0, &parallax2d_class_get_follow_viewport),
	JS_CFUNC_DEF("set_ignore_camera_scroll", 1, &parallax2d_class_set_ignore_camera_scroll),
	JS_CFUNC_DEF("is_ignore_camera_scroll", 0, &parallax2d_class_is_ignore_camera_scroll),
};




static void define_parallax2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_scale"),
        JS_NewCFunction(ctx, parallax2d_class_get_scroll_scale, "get_scroll_scale", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_scroll_scale, "set_scroll_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_offset"),
        JS_NewCFunction(ctx, parallax2d_class_get_scroll_offset, "get_scroll_offset", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_scroll_offset, "set_scroll_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "repeat_size"),
        JS_NewCFunction(ctx, parallax2d_class_get_repeat_size, "get_repeat_size", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_repeat_size, "set_repeat_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoscroll"),
        JS_NewCFunction(ctx, parallax2d_class_get_autoscroll, "get_autoscroll", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_autoscroll, "set_autoscroll", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "repeat_times"),
        JS_NewCFunction(ctx, parallax2d_class_get_repeat_times, "get_repeat_times", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_repeat_times, "set_repeat_times", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "limit_begin"),
        JS_NewCFunction(ctx, parallax2d_class_get_limit_begin, "get_limit_begin", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_limit_begin, "set_limit_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "limit_end"),
        JS_NewCFunction(ctx, parallax2d_class_get_limit_end, "get_limit_end", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_limit_end, "set_limit_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "follow_viewport"),
        JS_NewCFunction(ctx, parallax2d_class_get_follow_viewport, "get_follow_viewport", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_follow_viewport, "set_follow_viewport", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ignore_camera_scroll"),
        JS_NewCFunction(ctx, parallax2d_class_is_ignore_camera_scroll, "is_ignore_camera_scroll", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_ignore_camera_scroll, "set_ignore_camera_scroll", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "screen_offset"),
        JS_NewCFunction(ctx, parallax2d_class_get_screen_offset, "get_screen_offset", 0),
        JS_NewCFunction(ctx, parallax2d_class_set_screen_offset, "set_screen_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_parallax2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_parallax2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Parallax2D"] = class_id;
	classes_by_id[class_id] = "Parallax2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &parallax2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_parallax2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, parallax2d_class_proto_funcs, _countof(parallax2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, parallax2d_class_constructor, "Parallax2D", 0, JS_CFUNC_constructor, 0);
	define_parallax2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Parallax2D", ctor);

	return 0;
}

JSModuleDef *_js_init_parallax2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_parallax2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Parallax2D");
	return m;
}

JSModuleDef *js_init_parallax2d_module(JSContext *ctx) {
	return _js_init_parallax2d_module(ctx, "@godot/classes/parallax2d");
}

void __register_parallax2d() {
	js_init_parallax2d_module(js_context());
}

void register_parallax2d() {
	__register_parallax2d();
}