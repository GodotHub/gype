#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input_event.hpp>
using namespace godot;

static void input_event_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["InputEvent"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef input_event_class_def = {
    "InputEvent",
    input_event_class_finalizer
};

static JSValue input_event_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["InputEvent"];
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
        instance = memnew(InputEvent);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue input_event_class_set_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&InputEvent::set_device, ctx, this_val, argc, argv);
};
static JSValue input_event_class_get_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::get_device, ctx, this_val, argc, argv);
}
static JSValue input_event_class_is_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_action, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_action_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_action_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_action_released(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_action_released, ctx, this_val, argc, argv);
};
static JSValue input_event_class_get_action_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::get_action_strength, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_canceled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_canceled, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_pressed, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_released(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_released, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_echo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_echo, ctx, this_val, argc, argv);
};
static JSValue input_event_class_as_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::as_text, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_match(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_match, ctx, this_val, argc, argv);
};
static JSValue input_event_class_is_action_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::is_action_type, ctx, this_val, argc, argv);
};
static JSValue input_event_class_accumulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&InputEvent::accumulate, ctx, this_val, argc, argv);
};
static JSValue input_event_class_xformed_by(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&InputEvent::xformed_by, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry input_event_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_device", 1, &input_event_class_set_device),
	JS_CFUNC_DEF("get_device", 0, &input_event_class_get_device),
	JS_CFUNC_DEF("is_action", 2, &input_event_class_is_action),
	JS_CFUNC_DEF("is_action_pressed", 3, &input_event_class_is_action_pressed),
	JS_CFUNC_DEF("is_action_released", 2, &input_event_class_is_action_released),
	JS_CFUNC_DEF("get_action_strength", 2, &input_event_class_get_action_strength),
	JS_CFUNC_DEF("is_canceled", 0, &input_event_class_is_canceled),
	JS_CFUNC_DEF("is_pressed", 0, &input_event_class_is_pressed),
	JS_CFUNC_DEF("is_released", 0, &input_event_class_is_released),
	JS_CFUNC_DEF("is_echo", 0, &input_event_class_is_echo),
	JS_CFUNC_DEF("as_text", 0, &input_event_class_as_text),
	JS_CFUNC_DEF("is_match", 2, &input_event_class_is_match),
	JS_CFUNC_DEF("is_action_type", 0, &input_event_class_is_action_type),
	JS_CFUNC_DEF("accumulate", 1, &input_event_class_accumulate),
	JS_CFUNC_DEF("xformed_by", 2, &input_event_class_xformed_by),
};




static void define_input_event_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "device"),
        JS_NewCFunction(ctx, input_event_class_get_device, "get_device", 0),
        JS_NewCFunction(ctx, input_event_class_set_device, "set_device", 1),
        JS_PROP_GETSET
    );
}

static void define_input_event_enum(JSContext *ctx, JSValue ctor) {
}

static int js_input_event_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["InputEvent"] = class_id;
	classes_by_id[class_id] = "InputEvent";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_event_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_input_event_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, input_event_class_proto_funcs, _countof(input_event_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, input_event_class_constructor, "InputEvent", 0, JS_CFUNC_constructor, 0);
	define_input_event_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "InputEvent", ctor);
	ctor_list["InputEvent"] = ctor;

	return 0;
}

JSModuleDef *_js_init_input_event_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_input_event_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "InputEvent");
	return m;
}

JSModuleDef *js_init_input_event_module(JSContext *ctx) {
	return _js_init_input_event_module(ctx, "@godot/classes/input_event");
}

void __register_input_event() {
	js_init_input_event_module(js_context());
}

void register_input_event() {
	__register_input_event();
}