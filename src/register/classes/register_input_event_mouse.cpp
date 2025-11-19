#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event_with_modifiers.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_event_mouse.hpp>
using namespace godot;

static void input_event_mouse_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventMouse"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_mouse_class_def = {
    "InputEventMouse",
    input_event_mouse_class_finalizer
};

static JSValue input_event_mouse_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventMouse"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    InputEventMouse *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<InputEventMouse *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(InputEventMouse);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_mouse_class_set_button_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouse::set_button_mask, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_class_get_button_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMouse::get_button_mask, ctx, this_val, argc, argv);
}
static JSValue input_event_mouse_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouse::set_position, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouse *obj = static_cast<InputEventMouse *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouse *js_proxy = static_cast<InputEventMouse *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position(value);
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
static JSValue input_event_mouse_class_set_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMouse::set_global_position, ctx, this_val, argc, argv);
};
static JSValue input_event_mouse_class_get_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventMouse *obj = static_cast<InputEventMouse *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_position();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventMouse *js_proxy = static_cast<InputEventMouse *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_position(value);
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



static const JSCFunctionListEntry input_event_mouse_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_button_mask", 1, &input_event_mouse_class_set_button_mask),
	JS_CFUNC_DEF("get_button_mask", 0, &input_event_mouse_class_get_button_mask),
	JS_CFUNC_DEF("set_position", 1, &input_event_mouse_class_set_position),
	JS_CFUNC_DEF("get_position", 0, &input_event_mouse_class_get_position),
	JS_CFUNC_DEF("set_global_position", 1, &input_event_mouse_class_set_global_position),
	JS_CFUNC_DEF("get_global_position", 0, &input_event_mouse_class_get_global_position),
};




static void define_input_event_mouse_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "button_mask"),
        JS_NewCFunction(ctx, input_event_mouse_class_get_button_mask, "get_button_mask", 0),
        JS_NewCFunction(ctx, input_event_mouse_class_set_button_mask, "set_button_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position"),
        JS_NewCFunction(ctx, input_event_mouse_class_get_position, "get_position", 0),
        JS_NewCFunction(ctx, input_event_mouse_class_set_position, "set_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_position"),
        JS_NewCFunction(ctx, input_event_mouse_class_get_global_position, "get_global_position", 0),
        JS_NewCFunction(ctx, input_event_mouse_class_set_global_position, "set_global_position", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_mouse_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_mouse_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventMouse"] = class_id;
	classes_by_id[class_id] = "InputEventMouse";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_mouse_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEventWithModifiers"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_mouse_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_mouse_class_proto_funcs, _countof(input_event_mouse_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_mouse_class_constructor, "InputEventMouse", 0, JS_CFUNC_constructor, 0);
	define_input_event_mouse_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventMouse", ctor);

	return 0;
}

JSModuleDef *_js_init_input_event_mouse_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event_with_modifiers';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_mouse_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventMouse");
	return m;
}

JSModuleDef *js_init_input_event_mouse_module(JSContext *ctx) {
	return _js_init_input_event_mouse_module(ctx, "@godot/classes/input_event_mouse");
}

void __register_input_event_mouse() {
	js_init_input_event_mouse_module(js_context());
}

void register_input_event_mouse() {
	__register_input_event_mouse();
}