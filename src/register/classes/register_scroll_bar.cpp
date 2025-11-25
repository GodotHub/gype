#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/scroll_bar.hpp>
using namespace godot;

static void scroll_bar_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScrollBar"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef scroll_bar_class_def = {
    "ScrollBar",
    scroll_bar_class_finalizer
};

static JSValue scroll_bar_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScrollBar"];
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
        instance = memnew(ScrollBar);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue scroll_bar_class_set_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScrollBar::set_custom_step, ctx, this_val, argc, argv);
};
static JSValue scroll_bar_class_get_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScrollBar::get_custom_step, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry scroll_bar_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_custom_step", 1, &scroll_bar_class_set_custom_step),
	JS_CFUNC_DEF("get_custom_step", 0, &scroll_bar_class_get_custom_step),
};


static JSValue scroll_bar_class_get_scrolling_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScrollBar *opaque = static_cast<ScrollBar *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scrolling_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scrolling"));
		JS_DefinePropertyValueStr(ctx, this_val, "scrolling_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_scroll_bar_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_step"),
        JS_NewCFunction(ctx, scroll_bar_class_get_custom_step, "get_custom_step", 0),
        JS_NewCFunction(ctx, scroll_bar_class_set_custom_step, "set_custom_step", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scrolling"),
		JS_NewCFunction(ctx, scroll_bar_class_get_scrolling_signal, "get_scrolling_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_scroll_bar_enum(JSContext *ctx, JSValue ctor) {
}

static int js_scroll_bar_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScrollBar"] = class_id;
	classes_by_id[class_id] = "ScrollBar";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &scroll_bar_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Range"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_scroll_bar_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, scroll_bar_class_proto_funcs, _countof(scroll_bar_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, scroll_bar_class_constructor, "ScrollBar", 0, JS_CFUNC_constructor, 0);
	define_scroll_bar_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScrollBar", ctor);
	ctor_list["ScrollBar"] = ctor;

	return 0;
}

JSModuleDef *_js_init_scroll_bar_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/range';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_scroll_bar_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScrollBar");
	return m;
}

JSModuleDef *js_init_scroll_bar_module(JSContext *ctx) {
	return _js_init_scroll_bar_module(ctx, "@godot/classes/scroll_bar");
}

void __register_scroll_bar() {
	js_init_scroll_bar_module(js_context());
}

void register_scroll_bar() {
	__register_scroll_bar();
}