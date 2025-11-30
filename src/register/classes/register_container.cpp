#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/container.hpp>
using namespace godot;

static void container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Container"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef container_class_def = {
    "Container",
    container_class_finalizer
};

static JSValue container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Container"];
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
        instance = memnew(Container);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue container_class_queue_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Container::queue_sort, ctx, this_val, argc, argv);
};
static JSValue container_class_fit_child_in_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Container::fit_child_in_rect, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry container_class_proto_funcs[] = {
	JS_CFUNC_DEF("queue_sort", 0, &container_class_queue_sort),
	JS_CFUNC_DEF("fit_child_in_rect", 2, &container_class_fit_child_in_rect),
};


static JSValue container_class_get_pre_sort_children_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "pre_sort_children");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue container_class_get_sort_children_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "sort_children");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_container_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pre_sort_children"),
		JS_NewCFunction(ctx, container_class_get_pre_sort_children_signal, "get_pre_sort_children_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "sort_children"),
		JS_NewCFunction(ctx, container_class_get_sort_children_signal, "get_sort_children_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_container_enum(JSContext *ctx, JSValue ctor) {
}

static int js_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Container"] = class_id;
	classes_by_id[class_id] = "Container";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, container_class_proto_funcs, _countof(container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, container_class_constructor, "Container", 0, JS_CFUNC_constructor, 0);
	define_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Container", ctor);
	ctor_list["Container"] = ctor;

	return 0;
}

JSModuleDef *_js_init_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Container");
	return m;
}

JSModuleDef *js_init_container_module(JSContext *ctx) {
	return _js_init_container_module(ctx, "@godot/classes/container");
}

void __register_container() {
	js_init_container_module(js_context());
}

void register_container() {
	__register_container();
}