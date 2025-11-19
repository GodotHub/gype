#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event_from_window.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_event_with_modifiers.hpp>
using namespace godot;

static void input_event_with_modifiers_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventWithModifiers"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_with_modifiers_class_def = {
    "InputEventWithModifiers",
    input_event_with_modifiers_class_finalizer
};

static JSValue input_event_with_modifiers_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventWithModifiers"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    InputEventWithModifiers *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<InputEventWithModifiers *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(InputEventWithModifiers);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_with_modifiers_class_set_command_or_control_autoremap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventWithModifiers::set_command_or_control_autoremap, ctx, this_val, argc, argv);
};
static JSValue input_event_with_modifiers_class_is_command_or_control_autoremap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::is_command_or_control_autoremap, ctx, this_val, argc, argv);
}
static JSValue input_event_with_modifiers_class_is_command_or_control_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::is_command_or_control_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_with_modifiers_class_set_alt_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventWithModifiers::set_alt_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_with_modifiers_class_is_alt_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::is_alt_pressed, ctx, this_val, argc, argv);
}
static JSValue input_event_with_modifiers_class_set_shift_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventWithModifiers::set_shift_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_with_modifiers_class_is_shift_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::is_shift_pressed, ctx, this_val, argc, argv);
}
static JSValue input_event_with_modifiers_class_set_ctrl_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventWithModifiers::set_ctrl_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_with_modifiers_class_is_ctrl_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::is_ctrl_pressed, ctx, this_val, argc, argv);
}
static JSValue input_event_with_modifiers_class_set_meta_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventWithModifiers::set_meta_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_with_modifiers_class_is_meta_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::is_meta_pressed, ctx, this_val, argc, argv);
}
static JSValue input_event_with_modifiers_class_get_modifiers_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventWithModifiers::get_modifiers_mask, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry input_event_with_modifiers_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_command_or_control_autoremap", 1, &input_event_with_modifiers_class_set_command_or_control_autoremap),
	JS_CFUNC_DEF("is_command_or_control_autoremap", 0, &input_event_with_modifiers_class_is_command_or_control_autoremap),
	JS_CFUNC_DEF("is_command_or_control_pressed", 0, &input_event_with_modifiers_class_is_command_or_control_pressed),
	JS_CFUNC_DEF("set_alt_pressed", 1, &input_event_with_modifiers_class_set_alt_pressed),
	JS_CFUNC_DEF("is_alt_pressed", 0, &input_event_with_modifiers_class_is_alt_pressed),
	JS_CFUNC_DEF("set_shift_pressed", 1, &input_event_with_modifiers_class_set_shift_pressed),
	JS_CFUNC_DEF("is_shift_pressed", 0, &input_event_with_modifiers_class_is_shift_pressed),
	JS_CFUNC_DEF("set_ctrl_pressed", 1, &input_event_with_modifiers_class_set_ctrl_pressed),
	JS_CFUNC_DEF("is_ctrl_pressed", 0, &input_event_with_modifiers_class_is_ctrl_pressed),
	JS_CFUNC_DEF("set_meta_pressed", 1, &input_event_with_modifiers_class_set_meta_pressed),
	JS_CFUNC_DEF("is_meta_pressed", 0, &input_event_with_modifiers_class_is_meta_pressed),
	JS_CFUNC_DEF("get_modifiers_mask", 0, &input_event_with_modifiers_class_get_modifiers_mask),
};




static void define_input_event_with_modifiers_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "command_or_control_autoremap"),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_is_command_or_control_autoremap, "is_command_or_control_autoremap", 0),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_set_command_or_control_autoremap, "set_command_or_control_autoremap", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alt_pressed"),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_is_alt_pressed, "is_alt_pressed", 0),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_set_alt_pressed, "set_alt_pressed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shift_pressed"),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_is_shift_pressed, "is_shift_pressed", 0),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_set_shift_pressed, "set_shift_pressed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ctrl_pressed"),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_is_ctrl_pressed, "is_ctrl_pressed", 0),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_set_ctrl_pressed, "set_ctrl_pressed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "meta_pressed"),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_is_meta_pressed, "is_meta_pressed", 0),
        JS_NewCFunction(ctx, input_event_with_modifiers_class_set_meta_pressed, "set_meta_pressed", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_with_modifiers_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_with_modifiers_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventWithModifiers"] = class_id;
	classes_by_id[class_id] = "InputEventWithModifiers";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_with_modifiers_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEventFromWindow"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_with_modifiers_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_with_modifiers_class_proto_funcs, _countof(input_event_with_modifiers_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_with_modifiers_class_constructor, "InputEventWithModifiers", 0, JS_CFUNC_constructor, 0);
	define_input_event_with_modifiers_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventWithModifiers", ctor);

	return 0;
}

JSModuleDef *_js_init_input_event_with_modifiers_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event_from_window';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_with_modifiers_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventWithModifiers");
	return m;
}

JSModuleDef *js_init_input_event_with_modifiers_module(JSContext *ctx) {
	return _js_init_input_event_with_modifiers_module(ctx, "@godot/classes/input_event_with_modifiers");
}

void __register_input_event_with_modifiers() {
	js_init_input_event_with_modifiers_module(js_context());
}

void register_input_event_with_modifiers() {
	__register_input_event_with_modifiers();
}