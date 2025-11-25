#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_event_joypad_button.hpp>
using namespace godot;

static void input_event_joypad_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventJoypadButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_joypad_button_class_def = {
    "InputEventJoypadButton",
    input_event_joypad_button_class_finalizer
};

static JSValue input_event_joypad_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventJoypadButton"];
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
        instance = memnew(InputEventJoypadButton);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_joypad_button_class_set_button_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventJoypadButton::set_button_index, ctx, this_val, argc, argv);
};
static JSValue input_event_joypad_button_class_get_button_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventJoypadButton::get_button_index, ctx, this_val, argc, argv);
}
static JSValue input_event_joypad_button_class_set_pressure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventJoypadButton::set_pressure, ctx, this_val, argc, argv);
};
static JSValue input_event_joypad_button_class_get_pressure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventJoypadButton::get_pressure, ctx, this_val, argc, argv);
}
static JSValue input_event_joypad_button_class_set_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventJoypadButton::set_pressed, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry input_event_joypad_button_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_button_index", 1, &input_event_joypad_button_class_set_button_index),
	JS_CFUNC_DEF("get_button_index", 0, &input_event_joypad_button_class_get_button_index),
	JS_CFUNC_DEF("set_pressure", 1, &input_event_joypad_button_class_set_pressure),
	JS_CFUNC_DEF("get_pressure", 0, &input_event_joypad_button_class_get_pressure),
	JS_CFUNC_DEF("set_pressed", 1, &input_event_joypad_button_class_set_pressed),
};




static void define_input_event_joypad_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "button_index"),
        JS_NewCFunction(ctx, input_event_joypad_button_class_get_button_index, "get_button_index", 0),
        JS_NewCFunction(ctx, input_event_joypad_button_class_set_button_index, "set_button_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pressure"),
        JS_NewCFunction(ctx, input_event_joypad_button_class_get_pressure, "get_pressure", 0),
        JS_NewCFunction(ctx, input_event_joypad_button_class_set_pressure, "set_pressure", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pressed"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, input_event_joypad_button_class_set_pressed, "set_pressed", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_joypad_button_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_joypad_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventJoypadButton"] = class_id;
	classes_by_id[class_id] = "InputEventJoypadButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_joypad_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEvent"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_joypad_button_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_joypad_button_class_proto_funcs, _countof(input_event_joypad_button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_joypad_button_class_constructor, "InputEventJoypadButton", 0, JS_CFUNC_constructor, 0);
	define_input_event_joypad_button_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventJoypadButton", ctor);
	ctor_list["InputEventJoypadButton"] = ctor;

	return 0;
}

JSModuleDef *_js_init_input_event_joypad_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_joypad_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventJoypadButton");
	return m;
}

JSModuleDef *js_init_input_event_joypad_button_module(JSContext *ctx) {
	return _js_init_input_event_joypad_button_module(ctx, "@godot/classes/input_event_joypad_button");
}

void __register_input_event_joypad_button() {
	js_init_input_event_joypad_button_module(js_context());
}

void register_input_event_joypad_button() {
	__register_input_event_joypad_button();
}