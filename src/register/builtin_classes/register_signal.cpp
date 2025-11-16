#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include "register/builtin_classes/builtin_signal_vararg.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/string_name.hpp>


using namespace godot;

static void signal_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Signal"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef signal_class_def = {
	"Signal",
	signal_class_finalizer
};

static JSValue signal_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Signal"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}

	Signal instance;
	if (argc == 0) {
		instance = Signal();
	}
	if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::SIGNAL)) {
		Signal v0 = VariantAdapter(argv[0]).get();
		instance = Signal(v0);
	}
	if (argc == 2 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT) && JS_IsString(argv[1])) {
		Object *v0 = VariantAdapter(argv[0]).get();
		StringName v1 = VariantAdapter(argv[1]).get();
		instance = Signal(v0, v1);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue signal_class_is_null(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::is_null, ctx, this_val, argc, argv);
}

static JSValue signal_class_get_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_object, ctx, this_val, argc, argv);
}

static JSValue signal_class_get_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_object_id, ctx, this_val, argc, argv);
}

static JSValue signal_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_name, ctx, this_val, argc, argv);
}

static JSValue signal_class_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Signal::connect, ctx, this_val, argc, argv);
}

static JSValue signal_class_disconnect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Signal::disconnect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue signal_class_is_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::is_connected, ctx, this_val, argc, argv);
}
  
static JSValue signal_class_get_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::get_connections, ctx, this_val, argc, argv);
}

static JSValue signal_class_has_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Signal::has_connections, ctx, this_val, argc, argv);
}

static JSValue signal_class_emit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_no_ret<Signal>(&js_emit, ctx, this_val, argc, argv);
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
	JS_CFUNC_DEF("has_connections", 0, &signal_class_has_connections),
	JS_CFUNC_DEF("emit", 0, &signal_class_emit),
};


static int js_signal_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Signal"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Signal";

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

static void js_init_signal_module(JSContext *ctx) {
	js_signal_class_init(ctx);
}

void register_signal() {
	js_init_signal_module(js_context());
}

// ------------------SignalProxy------------------
static void signal_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["SignalProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Signal> *>(proxy));
	}
}

static JSClassDef signal_proxy_def = {
	"SignalProxy",
	signal_proxy_finalizer
};


static JSValue signal_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["SignalProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Signal> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Signal> *>(JS_GetAnyOpaque(*argv, &opaque_id));
	} else {
		return JS_EXCEPTION;
	}

	if (!proxy) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	return obj;
}

static JSValue signal_proxy_is_null(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::is_null, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_get_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::get_object, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_get_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::get_object_id, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::get_name, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_method_ret(&Signal::connect, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_disconnect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Signal::disconnect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue signal_proxy_is_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::is_connected, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_get_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::get_connections, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_has_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["SignalProxy"]);
	ObjectProxy<Signal> *proxy = static_cast<ObjectProxy<Signal> *>(opaque);
	Object *wrapped = proxy->wrapped;
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Signal::has_connections, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue signal_proxy_emit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_free_opaque_no_fixed_vararg_method_no_ret<Signal>(&js_emit, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry signal_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("is_null", 0, &signal_proxy_is_null),
	JS_CFUNC_DEF("get_object", 0, &signal_proxy_get_object),
	JS_CFUNC_DEF("get_object_id", 0, &signal_proxy_get_object_id),
	JS_CFUNC_DEF("get_name", 0, &signal_proxy_get_name),
	JS_CFUNC_DEF("connect", 2, &signal_proxy_connect),
	JS_CFUNC_DEF("disconnect", 1, &signal_proxy_disconnect),
	JS_CFUNC_DEF("is_connected", 1, &signal_proxy_is_connected),
	JS_CFUNC_DEF("get_connections", 0, &signal_proxy_get_connections),
	JS_CFUNC_DEF("has_connections", 0, &signal_proxy_has_connections),
	JS_CFUNC_DEF("emit", 0, &signal_proxy_emit),
};


static int js_signal_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["SignalProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "SignalProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &signal_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, signal_proxy_proto_funcs, _countof(signal_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, signal_proxy_constructor, "SignalProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "SignalProxy", ctor);

	return 0;
}

void js_init_signal_proxy_module(JSContext *ctx) {
	js_signal_proxy_init(ctx);
}

void register_proxy_signal() {
	js_init_signal_proxy_module(js_context());
}