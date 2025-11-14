#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event_mouse.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_event_mouse_motion.hpp>
using namespace godot;

static void input_event_mouse_motion_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventMouseMotion"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_mouse_motion_class_def = {
    "InputEventMouseMotion",
    input_event_mouse_motion_class_finalizer
};

static JSValue input_event_mouse_motion_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventMouseMotion"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    InputEventMouseMotion *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<InputEventMouseMotion *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(InputEventMouseMotion);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_mouse_motion_class_set_tilt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_tilt, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_tilt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouseMotion *obj = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tilt();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouseMotion *js_proxy = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tilt(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue input_event_mouse_motion_class_set_pressure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_pressure, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_pressure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMouseMotion::get_pressure, ctx, this_val, argc, argv);
}
static JSValue input_event_mouse_motion_class_set_pen_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_pen_inverted, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_pen_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMouseMotion::get_pen_inverted, ctx, this_val, argc, argv);
}
static JSValue input_event_mouse_motion_class_set_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_relative, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouseMotion *obj = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_relative();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouseMotion *js_proxy = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_relative(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue input_event_mouse_motion_class_set_screen_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_screen_relative, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_screen_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouseMotion *obj = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_screen_relative();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouseMotion *js_proxy = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_screen_relative(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue input_event_mouse_motion_class_set_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_velocity, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouseMotion *obj = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_velocity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouseMotion *js_proxy = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue input_event_mouse_motion_class_set_screen_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouseMotion::set_screen_velocity, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_motion_class_get_screen_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouseMotion *obj = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_screen_velocity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouseMotion *js_proxy = static_cast<InputEventMouseMotion *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_screen_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry input_event_mouse_motion_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_tilt", 1, &input_event_mouse_motion_class_set_tilt),
	JS_CFUNC_DEF("get_tilt", 0, &input_event_mouse_motion_class_get_tilt),
	JS_CFUNC_DEF("set_pressure", 1, &input_event_mouse_motion_class_set_pressure),
	JS_CFUNC_DEF("get_pressure", 0, &input_event_mouse_motion_class_get_pressure),
	JS_CFUNC_DEF("set_pen_inverted", 1, &input_event_mouse_motion_class_set_pen_inverted),
	JS_CFUNC_DEF("get_pen_inverted", 0, &input_event_mouse_motion_class_get_pen_inverted),
	JS_CFUNC_DEF("set_relative", 1, &input_event_mouse_motion_class_set_relative),
	JS_CFUNC_DEF("get_relative", 0, &input_event_mouse_motion_class_get_relative),
	JS_CFUNC_DEF("set_screen_relative", 1, &input_event_mouse_motion_class_set_screen_relative),
	JS_CFUNC_DEF("get_screen_relative", 0, &input_event_mouse_motion_class_get_screen_relative),
	JS_CFUNC_DEF("set_velocity", 1, &input_event_mouse_motion_class_set_velocity),
	JS_CFUNC_DEF("get_velocity", 0, &input_event_mouse_motion_class_get_velocity),
	JS_CFUNC_DEF("set_screen_velocity", 1, &input_event_mouse_motion_class_set_screen_velocity),
	JS_CFUNC_DEF("get_screen_velocity", 0, &input_event_mouse_motion_class_get_screen_velocity),
};




static void define_input_event_mouse_motion_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tilt"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_tilt, "get_tilt", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_tilt, "set_tilt", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pressure"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_pressure, "get_pressure", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_pressure, "set_pressure", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pen_inverted"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_pen_inverted, "get_pen_inverted", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_pen_inverted, "set_pen_inverted", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "relative"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_relative, "get_relative", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_relative, "set_relative", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "screen_relative"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_screen_relative, "get_screen_relative", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_screen_relative, "set_screen_relative", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "velocity"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_velocity, "get_velocity", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_velocity, "set_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "screen_velocity"),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_get_screen_velocity, "get_screen_velocity", 0),
        JS_NewCFunction(ctx, input_event_mouse_motion_class_set_screen_velocity, "set_screen_velocity", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_mouse_motion_enum(JSContext *ctx, JSValue proto) {
}

static int js_input_event_mouse_motion_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventMouseMotion"] = class_id;
	classes_by_id[class_id] = "InputEventMouseMotion";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_mouse_motion_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEventMouse"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_mouse_motion_property(ctx, proto);
	define_input_event_mouse_motion_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_mouse_motion_class_proto_funcs, _countof(input_event_mouse_motion_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_mouse_motion_class_constructor, "InputEventMouseMotion", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventMouseMotion", ctor);

	return 0;
}

JSModuleDef *_js_init_input_event_mouse_motion_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event_mouse';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_mouse_motion_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventMouseMotion");
	return m;
}

JSModuleDef *js_init_input_event_mouse_motion_module(JSContext *ctx) {
	return _js_init_input_event_mouse_motion_module(ctx, "@godot/classes/input_event_mouse_motion");
}

void __register_input_event_mouse_motion() {
	js_init_input_event_mouse_motion_module(js_context());
}

void register_input_event_mouse_motion() {
	__register_input_event_mouse_motion();
}