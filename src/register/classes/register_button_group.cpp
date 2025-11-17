#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/base_button.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/button_group.hpp>
using namespace godot;

static void button_group_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ButtonGroup"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef button_group_class_def = {
    "ButtonGroup",
    button_group_class_finalizer
};

static JSValue button_group_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ButtonGroup"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ButtonGroup *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ButtonGroup *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ButtonGroup);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue button_group_class_get_pressed_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ButtonGroup::get_pressed_button, ctx, this_val, argc, argv);
};
static JSValue button_group_class_get_buttons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ButtonGroup::get_buttons, ctx, this_val, argc, argv);
};
static JSValue button_group_class_set_allow_unpress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ButtonGroup::set_allow_unpress, ctx, this_val, argc, argv);
};
static JSValue button_group_class_is_allow_unpress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ButtonGroup::is_allow_unpress, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry button_group_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_pressed_button", 0, &button_group_class_get_pressed_button),
	JS_CFUNC_DEF("get_buttons", 0, &button_group_class_get_buttons),
	JS_CFUNC_DEF("set_allow_unpress", 1, &button_group_class_set_allow_unpress),
	JS_CFUNC_DEF("is_allow_unpress", 0, &button_group_class_is_allow_unpress),
};


static JSValue button_group_class_get_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ButtonGroup *opaque = static_cast<ButtonGroup *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_button_group_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_unpress"),
        JS_NewCFunction(ctx, button_group_class_is_allow_unpress, "is_allow_unpress", 0),
        JS_NewCFunction(ctx, button_group_class_set_allow_unpress, "set_allow_unpress", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pressed"),
		JS_NewCFunction(ctx, button_group_class_get_pressed_signal, "get_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_button_group_enum(JSContext *ctx, JSValue ctor) {
}

static int js_button_group_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ButtonGroup"] = class_id;
	classes_by_id[class_id] = "ButtonGroup";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &button_group_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_button_group_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, button_group_class_proto_funcs, _countof(button_group_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, button_group_class_constructor, "ButtonGroup", 0, JS_CFUNC_constructor, 0);
	define_button_group_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ButtonGroup", ctor);

	return 0;
}

JSModuleDef *_js_init_button_group_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_button_group_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ButtonGroup");
	return m;
}

JSModuleDef *js_init_button_group_module(JSContext *ctx) {
	return _js_init_button_group_module(ctx, "@godot/classes/button_group");
}

void __register_button_group() {
	js_init_button_group_module(js_context());
}

void register_button_group() {
	__register_button_group();
}