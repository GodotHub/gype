#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_future_result.hpp>
using namespace godot;

static void open_xr_future_result_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRFutureResult"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_future_result_class_def = {
    "OpenXRFutureResult",
    open_xr_future_result_class_finalizer
};

static JSValue open_xr_future_result_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRFutureResult"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRFutureResult *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRFutureResult *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRFutureResult);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_future_result_class_get_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRFutureResult::get_status, ctx, this_val, argc, argv);
};
static JSValue open_xr_future_result_class_get_future(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRFutureResult::get_future, ctx, this_val, argc, argv);
};
static JSValue open_xr_future_result_class_cancel_future(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRFutureResult::cancel_future, ctx, this_val, argc, argv);
};
static JSValue open_xr_future_result_class_set_result_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRFutureResult::set_result_value, ctx, this_val, argc, argv);
};
static JSValue open_xr_future_result_class_get_result_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRFutureResult::get_result_value, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_future_result_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_status", 0, &open_xr_future_result_class_get_status),
	JS_CFUNC_DEF("get_future", 0, &open_xr_future_result_class_get_future),
	JS_CFUNC_DEF("cancel_future", 0, &open_xr_future_result_class_cancel_future),
	JS_CFUNC_DEF("set_result_value", 1, &open_xr_future_result_class_set_result_value),
	JS_CFUNC_DEF("get_result_value", 0, &open_xr_future_result_class_get_result_value),
};


static JSValue open_xr_future_result_class_get_completed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	OpenXRFutureResult *opaque = static_cast<OpenXRFutureResult *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "completed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "completed"));
		JS_DefinePropertyValueStr(ctx, this_val, "completed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_open_xr_future_result_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "completed"),
		JS_NewCFunction(ctx, open_xr_future_result_class_get_completed_signal, "get_completed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_open_xr_future_result_enum(JSContext *ctx, JSValue ctor) {
	JSValue ResultStatus_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ResultStatus_obj, "RESULT_RUNNING", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ResultStatus_obj, "RESULT_FINISHED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ResultStatus_obj, "RESULT_CANCELLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ResultStatus", ResultStatus_obj);
}

static int js_open_xr_future_result_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRFutureResult"] = class_id;
	classes_by_id[class_id] = "OpenXRFutureResult";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_future_result_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_future_result_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_future_result_class_proto_funcs, _countof(open_xr_future_result_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_future_result_class_constructor, "OpenXRFutureResult", 0, JS_CFUNC_constructor, 0);
	define_open_xr_future_result_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRFutureResult", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_future_result_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_future_result_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRFutureResult");
	return m;
}

JSModuleDef *js_init_open_xr_future_result_module(JSContext *ctx) {
	return _js_init_open_xr_future_result_module(ctx, "@godot/classes/open_xr_future_result");
}

void __register_open_xr_future_result() {
	js_init_open_xr_future_result_module(js_context());
}

void register_open_xr_future_result() {
	__register_open_xr_future_result();
}