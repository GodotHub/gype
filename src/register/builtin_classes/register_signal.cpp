
#include "register/builtin_classes/signal_vararg_method.hpp"
#include "register/builtin_classes/register_builtin_classes.h"
#include "quickjs/quickjs.h"
#include "quickjs/env.h"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/variant_helper.hpp"
#include <godot_cpp/variant/signal.hpp>

using namespace godot;

static void signal_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Signal"];
	Signal *signal = static_cast<Signal *>(JS_GetOpaque(val, class_id));
	if (signal)
		memfree(signal);
}

static JSClassDef signal_class_def = {
	"Signal",
	.finalizer = signal_class_finalizer
};

static JSValue signal_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Signal"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Signal *signal_class = nullptr;
	
	if (argc == 0 ) {
		signal_class = memnew(Signal());
	}
	
	if (argc == 1 &&VariantAdapter(argv[0]).get_type() == Variant::Type::SIGNAL) {
		Signal v0 = VariantAdapter(argv[0]);
		signal_class = memnew(Signal(v0));
	}
	
	if (argc == 2 &&VariantAdapter(argv[0]).get_type() == Variant::Type::OBJECT&&VariantAdapter(argv[1]).get_type() == Variant::Type::STRING_NAME) {
		Object *v0 = VariantAdapter(argv[0]);
		StringName v1 = VariantAdapter(argv[1]);
		signal_class = memnew(Signal(v0,v1));
	}
	

	if (!signal_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, signal_class);
	return obj;
}
static JSValue signal_class_is_null(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::is_null, ctx, this_val, argc, argv);
};
static JSValue signal_class_get_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_object, ctx, this_val, argc, argv);
};
static JSValue signal_class_get_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_object_id, ctx, this_val, argc, argv);
};
static JSValue signal_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_name, ctx, this_val, argc, argv);
};
static JSValue signal_class_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Signal::connect, ctx, this_val, argc, argv);
};
static JSValue signal_class_disconnect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Signal::disconnect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue signal_class_is_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::is_connected, ctx, this_val, argc, argv);
};
static JSValue signal_class_get_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_connections, ctx, this_val, argc, argv);
};
static JSValue signal_class_emit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_no_ret_impl<Signal>(&js_emit, ctx, this_val, argc, argv);
}
static const JSCFunctionListEntry signal_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_null", 0, &signal_class_is_null),
	JS_CFUNC_DEF("get_object", 0, &signal_class_get_object),
	JS_CFUNC_DEF("get_object_id", 0, &signal_class_get_object_id),
	JS_CFUNC_DEF("get_name", 0, &signal_class_get_name),
	JS_CFUNC_DEF("connect", 2, &signal_class_connect),
	JS_CFUNC_DEF("disconnect", 1, &signal_class_disconnect),
	JS_CFUNC_DEF("is_connected", 1, &signal_class_is_connected),
	JS_CFUNC_DEF("get_connections", 0, &signal_class_get_connections),
	JS_CFUNC_DEF("emit", 0, &signal_class_emit),
};

static int js_signal_class_init(JSContext *ctx) {
	classes["Signal"] = 0;
	classes["Signal"] = JS_NewClassID(&classes["Signal"]);
	JSClassID class_id = classes["Signal"];

	class_id_list.insert(class_id);
	JS_NewClass(JS_GetRuntime(ctx), class_id, &signal_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, signal_class_proto_funcs, _countof(signal_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, signal_class_constructor, "Signal", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Signal", ctor);

	return 0;
}

void js_init_signal_module(JSContext *ctx) {
	js_signal_class_init(ctx);
}

void register_signal() {
	js_init_signal_module(ctx);
}