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
#include <godot_cpp/classes/input_event_midi.hpp>
using namespace godot;

static void input_event_midi_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventMIDI"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_midi_class_def = {
    "InputEventMIDI",
    input_event_midi_class_finalizer
};

static JSValue input_event_midi_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventMIDI"];
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
        instance = memnew(InputEventMIDI);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_midi_class_set_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_channel, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_channel, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_message, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_message, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_pitch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_pitch, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_pitch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_pitch, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_velocity, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_velocity, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_instrument(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_instrument, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_instrument(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_instrument, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_pressure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_pressure, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_pressure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_pressure, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_controller_number(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_controller_number, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_controller_number(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_controller_number, ctx, this_val, argc, argv);
}
static JSValue input_event_midi_class_set_controller_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventMIDI::set_controller_value, ctx, this_val, argc, argv);
};
static JSValue input_event_midi_class_get_controller_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventMIDI::get_controller_value, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry input_event_midi_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_channel", 1, &input_event_midi_class_set_channel),
	JS_CFUNC_DEF("get_channel", 0, &input_event_midi_class_get_channel),
	JS_CFUNC_DEF("set_message", 1, &input_event_midi_class_set_message),
	JS_CFUNC_DEF("get_message", 0, &input_event_midi_class_get_message),
	JS_CFUNC_DEF("set_pitch", 1, &input_event_midi_class_set_pitch),
	JS_CFUNC_DEF("get_pitch", 0, &input_event_midi_class_get_pitch),
	JS_CFUNC_DEF("set_velocity", 1, &input_event_midi_class_set_velocity),
	JS_CFUNC_DEF("get_velocity", 0, &input_event_midi_class_get_velocity),
	JS_CFUNC_DEF("set_instrument", 1, &input_event_midi_class_set_instrument),
	JS_CFUNC_DEF("get_instrument", 0, &input_event_midi_class_get_instrument),
	JS_CFUNC_DEF("set_pressure", 1, &input_event_midi_class_set_pressure),
	JS_CFUNC_DEF("get_pressure", 0, &input_event_midi_class_get_pressure),
	JS_CFUNC_DEF("set_controller_number", 1, &input_event_midi_class_set_controller_number),
	JS_CFUNC_DEF("get_controller_number", 0, &input_event_midi_class_get_controller_number),
	JS_CFUNC_DEF("set_controller_value", 1, &input_event_midi_class_set_controller_value),
	JS_CFUNC_DEF("get_controller_value", 0, &input_event_midi_class_get_controller_value),
};




static void define_input_event_midi_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "channel"),
        JS_NewCFunction(ctx, input_event_midi_class_get_channel, "get_channel", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_channel, "set_channel", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "message"),
        JS_NewCFunction(ctx, input_event_midi_class_get_message, "get_message", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_message, "set_message", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pitch"),
        JS_NewCFunction(ctx, input_event_midi_class_get_pitch, "get_pitch", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_pitch, "set_pitch", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "velocity"),
        JS_NewCFunction(ctx, input_event_midi_class_get_velocity, "get_velocity", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_velocity, "set_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "instrument"),
        JS_NewCFunction(ctx, input_event_midi_class_get_instrument, "get_instrument", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_instrument, "set_instrument", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pressure"),
        JS_NewCFunction(ctx, input_event_midi_class_get_pressure, "get_pressure", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_pressure, "set_pressure", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "controller_number"),
        JS_NewCFunction(ctx, input_event_midi_class_get_controller_number, "get_controller_number", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_controller_number, "set_controller_number", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "controller_value"),
        JS_NewCFunction(ctx, input_event_midi_class_get_controller_value, "get_controller_value", 0),
        JS_NewCFunction(ctx, input_event_midi_class_set_controller_value, "set_controller_value", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_midi_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_midi_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventMIDI"] = class_id;
	classes_by_id[class_id] = "InputEventMIDI";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_midi_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEvent"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_midi_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_midi_class_proto_funcs, _countof(input_event_midi_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_midi_class_constructor, "InputEventMIDI", 0, JS_CFUNC_constructor, 0);
	define_input_event_midi_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventMIDI", ctor);
	ctor_list["InputEventMIDI"] = ctor;

	return 0;
}

JSModuleDef *_js_init_input_event_midi_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_midi_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventMIDI");
	return m;
}

JSModuleDef *js_init_input_event_midi_module(JSContext *ctx) {
	return _js_init_input_event_midi_module(ctx, "@godot/classes/input_event_midi");
}

void __register_input_event_midi() {
	js_init_input_event_midi_module(js_context());
}

void register_input_event_midi() {
	__register_input_event_midi();
}