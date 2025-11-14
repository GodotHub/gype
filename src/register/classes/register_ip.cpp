#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/ip.hpp>


using namespace godot;

static void ip_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef ip_class_def = {
	"_IP",
	ip_class_finalizer
};

static JSValue ip_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["IP"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	IP *ip_class = IP::get_singleton();
	if (!ip_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, ip_class);
	return obj;
}

static JSValue ip_class_resolve_hostname(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&IP::resolve_hostname, ctx, this_val, argc, argv);
};
static JSValue ip_class_resolve_hostname_addresses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&IP::resolve_hostname_addresses, ctx, this_val, argc, argv);
};
static JSValue ip_class_resolve_hostname_queue_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&IP::resolve_hostname_queue_item, ctx, this_val, argc, argv);
};
static JSValue ip_class_get_resolve_item_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&IP::get_resolve_item_status, ctx, this_val, argc, argv);
};
static JSValue ip_class_get_resolve_item_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&IP::get_resolve_item_address, ctx, this_val, argc, argv);
};
static JSValue ip_class_get_resolve_item_addresses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&IP::get_resolve_item_addresses, ctx, this_val, argc, argv);
};
static JSValue ip_class_erase_resolve_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&IP::erase_resolve_item, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue ip_class_get_local_addresses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&IP::get_local_addresses, ctx, this_val, argc, argv);
};
static JSValue ip_class_get_local_interfaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&IP::get_local_interfaces, ctx, this_val, argc, argv);
};
static JSValue ip_class_clear_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&IP::clear_cache, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry ip_class_proto_funcs[] = {
	JS_CFUNC_DEF("resolve_hostname", 2, &ip_class_resolve_hostname),
	JS_CFUNC_DEF("resolve_hostname_addresses", 2, &ip_class_resolve_hostname_addresses),
	JS_CFUNC_DEF("resolve_hostname_queue_item", 2, &ip_class_resolve_hostname_queue_item),
	JS_CFUNC_DEF("get_resolve_item_status", 1, &ip_class_get_resolve_item_status),
	JS_CFUNC_DEF("get_resolve_item_address", 1, &ip_class_get_resolve_item_address),
	JS_CFUNC_DEF("get_resolve_item_addresses", 1, &ip_class_get_resolve_item_addresses),
	JS_CFUNC_DEF("erase_resolve_item", 1, &ip_class_erase_resolve_item),
	JS_CFUNC_DEF("get_local_addresses", 0, &ip_class_get_local_addresses),
	JS_CFUNC_DEF("get_local_interfaces", 0, &ip_class_get_local_interfaces),
	JS_CFUNC_DEF("clear_cache", 1, &ip_class_clear_cache),
};




static int js_ip_class_init(JSContext *ctx) {
	JSClassID class_id = classes["IP"];
	classes["IP"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &ip_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, ip_class_proto_funcs, _countof(ip_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, ip_class_constructor, "_IP", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_IP", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_ip() {
	js_ip_class_init(js_context());
}