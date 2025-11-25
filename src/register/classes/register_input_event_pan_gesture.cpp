#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event_gesture.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_event_pan_gesture.hpp>
using namespace godot;

static void input_event_pan_gesture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventPanGesture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_pan_gesture_class_def = {
    "InputEventPanGesture",
    input_event_pan_gesture_class_finalizer
};

static JSValue input_event_pan_gesture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventPanGesture"];
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
        instance = memnew(InputEventPanGesture);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_pan_gesture_class_set_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventPanGesture::set_delta, ctx, this_val, argc, argv);
};
static JSValue input_event_pan_gesture_class_get_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		InputEventPanGesture *obj = static_cast<InputEventPanGesture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_delta();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		InputEventPanGesture *js_proxy = static_cast<InputEventPanGesture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_delta(value);
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



static const JSCFunctionListEntry input_event_pan_gesture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_delta", 1, &input_event_pan_gesture_class_set_delta),
	JS_CFUNC_DEF("get_delta", 0, &input_event_pan_gesture_class_get_delta),
};




static void define_input_event_pan_gesture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "delta"),
        JS_NewCFunction(ctx, input_event_pan_gesture_class_get_delta, "get_delta", 0),
        JS_NewCFunction(ctx, input_event_pan_gesture_class_set_delta, "set_delta", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_pan_gesture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_pan_gesture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventPanGesture"] = class_id;
	classes_by_id[class_id] = "InputEventPanGesture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_pan_gesture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEventGesture"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_pan_gesture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_pan_gesture_class_proto_funcs, _countof(input_event_pan_gesture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_pan_gesture_class_constructor, "InputEventPanGesture", 0, JS_CFUNC_constructor, 0);
	define_input_event_pan_gesture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventPanGesture", ctor);
	ctor_list["InputEventPanGesture"] = ctor;

	return 0;
}

JSModuleDef *_js_init_input_event_pan_gesture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event_gesture';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_pan_gesture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventPanGesture");
	return m;
}

JSModuleDef *js_init_input_event_pan_gesture_module(JSContext *ctx) {
	return _js_init_input_event_pan_gesture_module(ctx, "@godot/classes/input_event_pan_gesture");
}

void __register_input_event_pan_gesture() {
	js_init_input_event_pan_gesture_module(js_context());
}

void register_input_event_pan_gesture() {
	__register_input_event_pan_gesture();
}