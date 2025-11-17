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
#include <godot_cpp/classes/input_event_magnify_gesture.hpp>
using namespace godot;

static void input_event_magnify_gesture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventMagnifyGesture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_magnify_gesture_class_def = {
    "InputEventMagnifyGesture",
    input_event_magnify_gesture_class_finalizer
};

static JSValue input_event_magnify_gesture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventMagnifyGesture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    InputEventMagnifyGesture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<InputEventMagnifyGesture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(InputEventMagnifyGesture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_magnify_gesture_class_set_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMagnifyGesture::set_factor, ctx, this_val, argc, argv);
};
static JSValue input_event_magnify_gesture_class_get_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMagnifyGesture::get_factor, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry input_event_magnify_gesture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_factor", 1, &input_event_magnify_gesture_class_set_factor),
	JS_CFUNC_DEF("get_factor", 0, &input_event_magnify_gesture_class_get_factor),
};




static void define_input_event_magnify_gesture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "factor"),
        JS_NewCFunction(ctx, input_event_magnify_gesture_class_get_factor, "get_factor", 0),
        JS_NewCFunction(ctx, input_event_magnify_gesture_class_set_factor, "set_factor", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_magnify_gesture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_magnify_gesture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventMagnifyGesture"] = class_id;
	classes_by_id[class_id] = "InputEventMagnifyGesture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_magnify_gesture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEventGesture"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_magnify_gesture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_magnify_gesture_class_proto_funcs, _countof(input_event_magnify_gesture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_magnify_gesture_class_constructor, "InputEventMagnifyGesture", 0, JS_CFUNC_constructor, 0);
	define_input_event_magnify_gesture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventMagnifyGesture", ctor);

	return 0;
}

JSModuleDef *_js_init_input_event_magnify_gesture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event_gesture';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_magnify_gesture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventMagnifyGesture");
	return m;
}

JSModuleDef *js_init_input_event_magnify_gesture_module(JSContext *ctx) {
	return _js_init_input_event_magnify_gesture_module(ctx, "@godot/classes/input_event_magnify_gesture");
}

void __register_input_event_magnify_gesture() {
	js_init_input_event_magnify_gesture_module(js_context());
}

void register_input_event_magnify_gesture() {
	__register_input_event_magnify_gesture();
}