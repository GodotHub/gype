#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/stream_peer.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/http_client.hpp>
using namespace godot;

static void http_client_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["HTTPClient"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef http_client_class_def = {
    "HTTPClient",
    http_client_class_finalizer
};

static JSValue http_client_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["HTTPClient"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    HTTPClient *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<HTTPClient *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(HTTPClient);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue http_client_class_connect_to_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::connect_to_host, ctx, this_val, argc, argv);
};
static JSValue http_client_class_set_connection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPClient::set_connection, ctx, this_val, argc, argv);
};
static JSValue http_client_class_get_connection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::get_connection, ctx, this_val, argc, argv);
}
static JSValue http_client_class_request_raw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::request_raw, ctx, this_val, argc, argv);
};
static JSValue http_client_class_request(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::request, ctx, this_val, argc, argv);
};
static JSValue http_client_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPClient::close, ctx, this_val, argc, argv);
};
static JSValue http_client_class_has_response(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::has_response, ctx, this_val, argc, argv);
};
static JSValue http_client_class_is_response_chunked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::is_response_chunked, ctx, this_val, argc, argv);
};
static JSValue http_client_class_get_response_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::get_response_code, ctx, this_val, argc, argv);
};
static JSValue http_client_class_get_response_headers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::get_response_headers, ctx, this_val, argc, argv);
};
static JSValue http_client_class_get_response_headers_as_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::get_response_headers_as_dictionary, ctx, this_val, argc, argv);
};
static JSValue http_client_class_get_response_body_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::get_response_body_length, ctx, this_val, argc, argv);
};
static JSValue http_client_class_read_response_body_chunk(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::read_response_body_chunk, ctx, this_val, argc, argv);
};
static JSValue http_client_class_set_read_chunk_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPClient::set_read_chunk_size, ctx, this_val, argc, argv);
};
static JSValue http_client_class_get_read_chunk_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::get_read_chunk_size, ctx, this_val, argc, argv);
}
static JSValue http_client_class_set_blocking_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPClient::set_blocking_mode, ctx, this_val, argc, argv);
};
static JSValue http_client_class_is_blocking_mode_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::is_blocking_mode_enabled, ctx, this_val, argc, argv);
}
static JSValue http_client_class_get_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPClient::get_status, ctx, this_val, argc, argv);
};
static JSValue http_client_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::poll, ctx, this_val, argc, argv);
};
static JSValue http_client_class_set_http_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPClient::set_http_proxy, ctx, this_val, argc, argv);
};
static JSValue http_client_class_set_https_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPClient::set_https_proxy, ctx, this_val, argc, argv);
};
static JSValue http_client_class_query_string_from_dict(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPClient::query_string_from_dict, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry http_client_class_proto_funcs[] = {
	JS_CFUNC_DEF("connect_to_host", 3, &http_client_class_connect_to_host),
	JS_CFUNC_DEF("set_connection", 1, &http_client_class_set_connection),
	JS_CFUNC_DEF("get_connection", 0, &http_client_class_get_connection),
	JS_CFUNC_DEF("request_raw", 4, &http_client_class_request_raw),
	JS_CFUNC_DEF("request", 4, &http_client_class_request),
	JS_CFUNC_DEF("close", 0, &http_client_class_close),
	JS_CFUNC_DEF("has_response", 0, &http_client_class_has_response),
	JS_CFUNC_DEF("is_response_chunked", 0, &http_client_class_is_response_chunked),
	JS_CFUNC_DEF("get_response_code", 0, &http_client_class_get_response_code),
	JS_CFUNC_DEF("get_response_headers", 0, &http_client_class_get_response_headers),
	JS_CFUNC_DEF("get_response_headers_as_dictionary", 0, &http_client_class_get_response_headers_as_dictionary),
	JS_CFUNC_DEF("get_response_body_length", 0, &http_client_class_get_response_body_length),
	JS_CFUNC_DEF("read_response_body_chunk", 0, &http_client_class_read_response_body_chunk),
	JS_CFUNC_DEF("set_read_chunk_size", 1, &http_client_class_set_read_chunk_size),
	JS_CFUNC_DEF("get_read_chunk_size", 0, &http_client_class_get_read_chunk_size),
	JS_CFUNC_DEF("set_blocking_mode", 1, &http_client_class_set_blocking_mode),
	JS_CFUNC_DEF("is_blocking_mode_enabled", 0, &http_client_class_is_blocking_mode_enabled),
	JS_CFUNC_DEF("get_status", 0, &http_client_class_get_status),
	JS_CFUNC_DEF("poll", 0, &http_client_class_poll),
	JS_CFUNC_DEF("set_http_proxy", 2, &http_client_class_set_http_proxy),
	JS_CFUNC_DEF("set_https_proxy", 2, &http_client_class_set_https_proxy),
	JS_CFUNC_DEF("query_string_from_dict", 1, &http_client_class_query_string_from_dict),
};




static void define_http_client_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blocking_mode_enabled"),
        JS_NewCFunction(ctx, http_client_class_is_blocking_mode_enabled, "is_blocking_mode_enabled", 0),
        JS_NewCFunction(ctx, http_client_class_set_blocking_mode, "set_blocking_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "connection"),
        JS_NewCFunction(ctx, http_client_class_get_connection, "get_connection", 0),
        JS_NewCFunction(ctx, http_client_class_set_connection, "set_connection", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "read_chunk_size"),
        JS_NewCFunction(ctx, http_client_class_get_read_chunk_size, "get_read_chunk_size", 0),
        JS_NewCFunction(ctx, http_client_class_set_read_chunk_size, "set_read_chunk_size", 1),
        JS_PROP_GETSET
    );
}

static void define_http_client_enum(JSContext *ctx, JSValue proto) {
	JSValue Method_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_GET", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_HEAD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_POST", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_PUT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_DELETE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_OPTIONS", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_TRACE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_CONNECT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_PATCH", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Method_obj, "METHOD_MAX", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, proto, "Method", Method_obj);
	JSValue Status_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_DISCONNECTED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_RESOLVING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CANT_RESOLVE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTING", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CANT_CONNECT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_REQUESTING", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_BODY", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTION_ERROR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_TLS_HANDSHAKE_ERROR", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, proto, "Status", Status_obj);
	JSValue ResponseCode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_CONTINUE", JS_NewInt64(ctx, 100));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_SWITCHING_PROTOCOLS", JS_NewInt64(ctx, 101));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PROCESSING", JS_NewInt64(ctx, 102));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_OK", JS_NewInt64(ctx, 200));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_CREATED", JS_NewInt64(ctx, 201));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_ACCEPTED", JS_NewInt64(ctx, 202));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NON_AUTHORITATIVE_INFORMATION", JS_NewInt64(ctx, 203));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NO_CONTENT", JS_NewInt64(ctx, 204));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_RESET_CONTENT", JS_NewInt64(ctx, 205));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PARTIAL_CONTENT", JS_NewInt64(ctx, 206));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_MULTI_STATUS", JS_NewInt64(ctx, 207));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_ALREADY_REPORTED", JS_NewInt64(ctx, 208));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_IM_USED", JS_NewInt64(ctx, 226));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_MULTIPLE_CHOICES", JS_NewInt64(ctx, 300));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_MOVED_PERMANENTLY", JS_NewInt64(ctx, 301));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_FOUND", JS_NewInt64(ctx, 302));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_SEE_OTHER", JS_NewInt64(ctx, 303));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NOT_MODIFIED", JS_NewInt64(ctx, 304));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_USE_PROXY", JS_NewInt64(ctx, 305));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_SWITCH_PROXY", JS_NewInt64(ctx, 306));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_TEMPORARY_REDIRECT", JS_NewInt64(ctx, 307));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PERMANENT_REDIRECT", JS_NewInt64(ctx, 308));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_BAD_REQUEST", JS_NewInt64(ctx, 400));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_UNAUTHORIZED", JS_NewInt64(ctx, 401));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PAYMENT_REQUIRED", JS_NewInt64(ctx, 402));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_FORBIDDEN", JS_NewInt64(ctx, 403));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NOT_FOUND", JS_NewInt64(ctx, 404));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_METHOD_NOT_ALLOWED", JS_NewInt64(ctx, 405));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NOT_ACCEPTABLE", JS_NewInt64(ctx, 406));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PROXY_AUTHENTICATION_REQUIRED", JS_NewInt64(ctx, 407));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_REQUEST_TIMEOUT", JS_NewInt64(ctx, 408));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_CONFLICT", JS_NewInt64(ctx, 409));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_GONE", JS_NewInt64(ctx, 410));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_LENGTH_REQUIRED", JS_NewInt64(ctx, 411));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PRECONDITION_FAILED", JS_NewInt64(ctx, 412));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_REQUEST_ENTITY_TOO_LARGE", JS_NewInt64(ctx, 413));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_REQUEST_URI_TOO_LONG", JS_NewInt64(ctx, 414));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_UNSUPPORTED_MEDIA_TYPE", JS_NewInt64(ctx, 415));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_REQUESTED_RANGE_NOT_SATISFIABLE", JS_NewInt64(ctx, 416));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_EXPECTATION_FAILED", JS_NewInt64(ctx, 417));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_IM_A_TEAPOT", JS_NewInt64(ctx, 418));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_MISDIRECTED_REQUEST", JS_NewInt64(ctx, 421));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_UNPROCESSABLE_ENTITY", JS_NewInt64(ctx, 422));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_LOCKED", JS_NewInt64(ctx, 423));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_FAILED_DEPENDENCY", JS_NewInt64(ctx, 424));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_UPGRADE_REQUIRED", JS_NewInt64(ctx, 426));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_PRECONDITION_REQUIRED", JS_NewInt64(ctx, 428));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_TOO_MANY_REQUESTS", JS_NewInt64(ctx, 429));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_REQUEST_HEADER_FIELDS_TOO_LARGE", JS_NewInt64(ctx, 431));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_UNAVAILABLE_FOR_LEGAL_REASONS", JS_NewInt64(ctx, 451));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_INTERNAL_SERVER_ERROR", JS_NewInt64(ctx, 500));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NOT_IMPLEMENTED", JS_NewInt64(ctx, 501));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_BAD_GATEWAY", JS_NewInt64(ctx, 502));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_SERVICE_UNAVAILABLE", JS_NewInt64(ctx, 503));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_GATEWAY_TIMEOUT", JS_NewInt64(ctx, 504));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_HTTP_VERSION_NOT_SUPPORTED", JS_NewInt64(ctx, 505));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_VARIANT_ALSO_NEGOTIATES", JS_NewInt64(ctx, 506));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_INSUFFICIENT_STORAGE", JS_NewInt64(ctx, 507));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_LOOP_DETECTED", JS_NewInt64(ctx, 508));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NOT_EXTENDED", JS_NewInt64(ctx, 510));
	JS_SetPropertyStr(ctx, ResponseCode_obj, "RESPONSE_NETWORK_AUTH_REQUIRED", JS_NewInt64(ctx, 511));
	JS_SetPropertyStr(ctx, proto, "ResponseCode", ResponseCode_obj);
}

static int js_http_client_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["HTTPClient"] = class_id;
	classes_by_id[class_id] = "HTTPClient";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &http_client_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_http_client_property(ctx, proto);
	define_http_client_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, http_client_class_proto_funcs, _countof(http_client_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, http_client_class_constructor, "HTTPClient", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "HTTPClient", ctor);

	return 0;
}

JSModuleDef *_js_init_http_client_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_http_client_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "HTTPClient");
	return m;
}

JSModuleDef *js_init_http_client_module(JSContext *ctx) {
	return _js_init_http_client_module(ctx, "@godot/classes/http_client");
}

void __register_http_client() {
	js_init_http_client_module(js_context());
}

void register_http_client() {
	__register_http_client();
}