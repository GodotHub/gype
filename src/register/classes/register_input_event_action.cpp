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
#include <godot_cpp/classes/input_event_action.hpp>
using namespace godot;

static void input_event_action_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEventAction"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_action_class_def = {
    "InputEventAction",
    input_event_action_class_finalizer
};

static JSValue input_event_action_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEventAction"];
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
        instance = memnew(InputEventAction);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_action_class_set_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventAction::set_action, ctx, this_val, argc, argv);
};
static JSValue input_event_action_class_get_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventAction::get_action, ctx, this_val, argc, argv);
}
static JSValue input_event_action_class_set_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventAction::set_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_action_class_set_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventAction::set_strength, ctx, this_val, argc, argv);
};
static JSValue input_event_action_class_get_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventAction::get_strength, ctx, this_val, argc, argv);
}
static JSValue input_event_action_class_set_event_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEventAction::set_event_index, ctx, this_val, argc, argv);
};
static JSValue input_event_action_class_get_event_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEventAction::get_event_index, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry input_event_action_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_action", 1, &input_event_action_class_set_action),
	JS_CFUNC_DEF("get_action", 0, &input_event_action_class_get_action),
	JS_CFUNC_DEF("set_pressed", 1, &input_event_action_class_set_pressed),
	JS_CFUNC_DEF("set_strength", 1, &input_event_action_class_set_strength),
	JS_CFUNC_DEF("get_strength", 0, &input_event_action_class_get_strength),
	JS_CFUNC_DEF("set_event_index", 1, &input_event_action_class_set_event_index),
	JS_CFUNC_DEF("get_event_index", 0, &input_event_action_class_get_event_index),
};




static void define_input_event_action_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action"),
        JS_NewCFunction(ctx, input_event_action_class_get_action, "get_action", 0),
        JS_NewCFunction(ctx, input_event_action_class_set_action, "set_action", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pressed"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, input_event_action_class_set_pressed, "set_pressed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "strength"),
        JS_NewCFunction(ctx, input_event_action_class_get_strength, "get_strength", 0),
        JS_NewCFunction(ctx, input_event_action_class_set_strength, "set_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "event_index"),
        JS_NewCFunction(ctx, input_event_action_class_get_event_index, "get_event_index", 0),
        JS_NewCFunction(ctx, input_event_action_class_set_event_index, "set_event_index", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_action_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_action_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEventAction"] = class_id;
	classes_by_id[class_id] = "InputEventAction";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_action_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["InputEvent"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_action_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_action_class_proto_funcs, _countof(input_event_action_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_action_class_constructor, "InputEventAction", 0, JS_CFUNC_constructor, 0);
	define_input_event_action_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEventAction", ctor);
	ctor_list["InputEventAction"] = ctor;

	return 0;
}

JSModuleDef *_js_init_input_event_action_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/input_event';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_action_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEventAction");
	return m;
}

JSModuleDef *js_init_input_event_action_module(JSContext *ctx) {
	return _js_init_input_event_action_module(ctx, "@godot/classes/input_event_action");
}

void __register_input_event_action() {
	js_init_input_event_action_module(js_context());
}

void register_input_event_action() {
	__register_input_event_action();
}