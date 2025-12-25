#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_map.hpp>


using namespace godot;

static void input_map_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef input_map_class_def = {
	"_InputMap",
	input_map_class_finalizer
};

static JSValue input_map_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["InputMap"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	InputMap *input_map_class = InputMap::get_singleton();
	if (!input_map_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, input_map_class);
	return obj;
}

static JSValue input_map_class_has_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&InputMap::has_action, ctx, this_val, argc, argv);
};
static JSValue input_map_class_get_actions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&InputMap::get_actions, ctx, this_val, argc, argv);
};
static JSValue input_map_class_add_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::add_action, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_map_class_erase_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::erase_action, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_map_class_get_action_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&InputMap::get_action_description, ctx, this_val, argc, argv);
};
static JSValue input_map_class_action_set_deadzone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::action_set_deadzone, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_map_class_action_get_deadzone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&InputMap::action_get_deadzone, ctx, this_val, argc, argv);
};
static JSValue input_map_class_action_add_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::action_add_event, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_map_class_action_has_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&InputMap::action_has_event, ctx, this_val, argc, argv);
};
static JSValue input_map_class_action_erase_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::action_erase_event, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_map_class_action_erase_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::action_erase_events, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_map_class_action_get_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&InputMap::action_get_events, ctx, this_val, argc, argv);
};
static JSValue input_map_class_event_is_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&InputMap::event_is_action, ctx, this_val, argc, argv);
};
static JSValue input_map_class_load_from_project_settings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&InputMap::load_from_project_settings, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry input_map_class_proto_funcs[] = {
	JS_CFUNC_DEF("has_action", 1, &input_map_class_has_action),
	JS_CFUNC_DEF("get_actions", 0, &input_map_class_get_actions),
	JS_CFUNC_DEF("add_action", 2, &input_map_class_add_action),
	JS_CFUNC_DEF("erase_action", 1, &input_map_class_erase_action),
	JS_CFUNC_DEF("get_action_description", 1, &input_map_class_get_action_description),
	JS_CFUNC_DEF("action_set_deadzone", 2, &input_map_class_action_set_deadzone),
	JS_CFUNC_DEF("action_get_deadzone", 1, &input_map_class_action_get_deadzone),
	JS_CFUNC_DEF("action_add_event", 2, &input_map_class_action_add_event),
	JS_CFUNC_DEF("action_has_event", 2, &input_map_class_action_has_event),
	JS_CFUNC_DEF("action_erase_event", 2, &input_map_class_action_erase_event),
	JS_CFUNC_DEF("action_erase_events", 1, &input_map_class_action_erase_events),
	JS_CFUNC_DEF("action_get_events", 1, &input_map_class_action_get_events),
	JS_CFUNC_DEF("event_is_action", 3, &input_map_class_event_is_action),
	JS_CFUNC_DEF("load_from_project_settings", 0, &input_map_class_load_from_project_settings),
};




static int js_input_map_class_init(JSContext *ctx) {
	JSClassID class_id = classes["InputMap"];
	classes["InputMap"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_map_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, input_map_class_proto_funcs, _countof(input_map_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, input_map_class_constructor, "_InputMap", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "InputMap", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_input_map() {
	js_input_map_class_init(js_context());
}