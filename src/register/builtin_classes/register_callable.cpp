#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include "register/builtin_classes/builtin_callable_vararg.hpp"
#include "support/callable_jsmethod_pointer.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/string_name.hpp>


using namespace godot;

static void callable_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Callable"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef callable_class_def = {
	"Callable",
	callable_class_finalizer
};

static JSValue callable_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Callable"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Callable instance;
	if (argc == 0) {
		instance = Callable();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::CALLABLE)) {
		Callable v0 = VariantAdapter(argv[0]).get();
		instance = Callable(v0);
	}
	if (argc == 2&&VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)&&JS_IsString(argv[1])) {
		Object * v0 = VariantAdapter(argv[0]).get();
		StringName v1 = VariantAdapter(argv[1]).get();
		instance = Callable(v0, v1);
	}
if (argc == 2&&JS_IsObject(argv[0])&&JS_IsFunction(ctx, argv[1])) {
    instance = create_custom_javascript_callable(argv[0], argv[1]);
}
	VariantAdapter *adapter = memnew(VariantAdapter(instance));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue callable_class_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Callable::create, ctx, this_val, argc, argv);
}
static JSValue callable_class_callv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::callv, ctx, this_val, argc, argv);
}
static JSValue callable_class_is_null(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::is_null, ctx, this_val, argc, argv);
}
static JSValue callable_class_is_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::is_custom, ctx, this_val, argc, argv);
}
static JSValue callable_class_is_standard(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::is_standard, ctx, this_val, argc, argv);
}
static JSValue callable_class_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::is_valid, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_object, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_object_id, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_method, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_argument_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_argument_count, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_bound_arguments_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_bound_arguments_count, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_bound_arguments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_bound_arguments, ctx, this_val, argc, argv);
}
static JSValue callable_class_get_unbound_arguments_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::get_unbound_arguments_count, ctx, this_val, argc, argv);
}
static JSValue callable_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::hash, ctx, this_val, argc, argv);
}
static JSValue callable_class_bindv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Callable::bindv, ctx, this_val, argc, argv);
}
static JSValue callable_class_unbind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Callable::unbind, ctx, this_val, argc, argv);
}
static JSValue callable_class_call(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_ret<Callable>(&js_call, ctx, this_val, argc, argv);
}
static JSValue callable_class_call_deferred(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_no_ret<Callable>(&js_call_deferred, ctx, this_val, argc, argv);
}
static JSValue callable_class_rpc(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_no_ret<Callable>(&js_rpc, ctx, this_val, argc, argv);
}
static JSValue callable_class_rpc_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_vararg_method_no_ret<Callable>(&js_rpc_id, ctx, this_val, argc, argv);
}
static JSValue callable_class_bind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_ret<Callable>(&js_bind, ctx, this_val, argc, argv);
}




static const JSCFunctionListEntry callable_class_proto_funcs[] = {
	JS_CFUNC_DEF("create", 2, &callable_class_create),
	JS_CFUNC_DEF("callv", 1, &callable_class_callv),
	JS_CFUNC_DEF("is_null", 0, &callable_class_is_null),
	JS_CFUNC_DEF("is_custom", 0, &callable_class_is_custom),
	JS_CFUNC_DEF("is_standard", 0, &callable_class_is_standard),
	JS_CFUNC_DEF("is_valid", 0, &callable_class_is_valid),
	JS_CFUNC_DEF("get_object", 0, &callable_class_get_object),
	JS_CFUNC_DEF("get_object_id", 0, &callable_class_get_object_id),
	JS_CFUNC_DEF("get_method", 0, &callable_class_get_method),
	JS_CFUNC_DEF("get_argument_count", 0, &callable_class_get_argument_count),
	JS_CFUNC_DEF("get_bound_arguments_count", 0, &callable_class_get_bound_arguments_count),
	JS_CFUNC_DEF("get_bound_arguments", 0, &callable_class_get_bound_arguments),
	JS_CFUNC_DEF("get_unbound_arguments_count", 0, &callable_class_get_unbound_arguments_count),
	JS_CFUNC_DEF("hash", 0, &callable_class_hash),
	JS_CFUNC_DEF("bindv", 1, &callable_class_bindv),
	JS_CFUNC_DEF("unbind", 1, &callable_class_unbind),
	JS_CFUNC_DEF("call", 0, &callable_class_call),
	JS_CFUNC_DEF("call_deferred", 0, &callable_class_call_deferred),
	JS_CFUNC_DEF("rpc", 0, &callable_class_rpc),
	JS_CFUNC_DEF("rpc_id", 1, &callable_class_rpc_id),
	JS_CFUNC_DEF("bind", 0, &callable_class_bind),
};




static int js_callable_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Callable"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Callable";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &callable_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, callable_class_proto_funcs, _countof(callable_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, callable_class_constructor, "Callable", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Callable", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_callable_module(JSContext *ctx) {
	js_callable_class_init(ctx);
}

void register_callable() {
	js_init_callable_module(js_context());
}

// ------------------CallableProxy------------------
static void callable_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["CallableProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Callable> *>(proxy));
	}
}

static JSClassDef callable_proxy_def = {
	"CallableProxy",
	callable_proxy_finalizer
};


static JSValue callable_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["CallableProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Callable> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Callable> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue callable_proxy_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Callable::create, ctx, this_val, argc, argv);
}
static JSValue callable_proxy_callv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::callv, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_is_null(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::is_null, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_is_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::is_custom, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_is_standard(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::is_standard, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::is_valid, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_object, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_object_id, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_method, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_argument_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_argument_count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_bound_arguments_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_bound_arguments_count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_bound_arguments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_bound_arguments, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_get_unbound_arguments_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::get_unbound_arguments_count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::hash, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_bindv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&Callable::bindv, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_unbind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Callable::unbind, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_call(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
JSValue ret = call_builtin_free_opaque_no_fixed_vararg_method_ret<Callable>(&js_call, ctx, this_val, argc, argv);
JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue callable_proxy_call_deferred(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_free_opaque_no_fixed_vararg_method_no_ret<Callable>(&js_call_deferred, ctx, this_val, argc, argv);
JS_FreeValue(ctx, this_val);
    return JS_UNDEFINED;
}
static JSValue callable_proxy_rpc(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_free_opaque_no_fixed_vararg_method_no_ret<Callable>(&js_rpc, ctx, this_val, argc, argv);
JS_FreeValue(ctx, this_val);
    return JS_UNDEFINED;
}
static JSValue callable_proxy_rpc_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_free_opaque_vararg_method_no_ret<Callable>(&js_rpc_id, ctx, this_val, argc, argv);
JS_FreeValue(ctx, this_val);
    return JS_UNDEFINED;
}
static JSValue callable_proxy_bind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["CallableProxy"]);
    ObjectProxy<Callable> *proxy = static_cast<ObjectProxy<Callable> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
JSValue ret = call_builtin_free_opaque_no_fixed_vararg_method_ret<Callable>(&js_bind, ctx, this_val, argc, argv);
JS_FreeValue(ctx, this_val);
    return ret;
}


static const JSCFunctionListEntry callable_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("create", 2, &callable_proxy_create),
	JS_CFUNC_DEF("callv", 1, &callable_proxy_callv),
	JS_CFUNC_DEF("is_null", 0, &callable_proxy_is_null),
	JS_CFUNC_DEF("is_custom", 0, &callable_proxy_is_custom),
	JS_CFUNC_DEF("is_standard", 0, &callable_proxy_is_standard),
	JS_CFUNC_DEF("is_valid", 0, &callable_proxy_is_valid),
	JS_CFUNC_DEF("get_object", 0, &callable_proxy_get_object),
	JS_CFUNC_DEF("get_object_id", 0, &callable_proxy_get_object_id),
	JS_CFUNC_DEF("get_method", 0, &callable_proxy_get_method),
	JS_CFUNC_DEF("get_argument_count", 0, &callable_proxy_get_argument_count),
	JS_CFUNC_DEF("get_bound_arguments_count", 0, &callable_proxy_get_bound_arguments_count),
	JS_CFUNC_DEF("get_bound_arguments", 0, &callable_proxy_get_bound_arguments),
	JS_CFUNC_DEF("get_unbound_arguments_count", 0, &callable_proxy_get_unbound_arguments_count),
	JS_CFUNC_DEF("hash", 0, &callable_proxy_hash),
	JS_CFUNC_DEF("bindv", 1, &callable_proxy_bindv),
	JS_CFUNC_DEF("unbind", 1, &callable_proxy_unbind),
	JS_CFUNC_DEF("call", 0, &callable_proxy_call),
	JS_CFUNC_DEF("call_deferred", 0, &callable_proxy_call_deferred),
	JS_CFUNC_DEF("rpc", 0, &callable_proxy_rpc),
	JS_CFUNC_DEF("rpc_id", 1, &callable_proxy_rpc_id),
	JS_CFUNC_DEF("bind", 0, &callable_proxy_bind),
};


static int js_callable_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["CallableProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "CallableProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &callable_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, callable_proxy_proto_funcs, _countof(callable_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, callable_proxy_constructor, "CallableProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "CallableProxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_callable_proxy_module(JSContext *ctx) {
	js_callable_proxy_init(ctx);
}

void register_proxy_callable() {
	js_init_callable_proxy_module(js_context());
}
