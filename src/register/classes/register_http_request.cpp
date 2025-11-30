#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/http_request.hpp>
using namespace godot;

static void http_request_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["HTTPRequest"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef http_request_class_def = {
    "HTTPRequest",
    http_request_class_finalizer
};

static JSValue http_request_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["HTTPRequest"];
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
        instance = memnew(HTTPRequest);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue http_request_class_request(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPRequest::request, ctx, this_val, argc, argv);
};
static JSValue http_request_class_request_raw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPRequest::request_raw, ctx, this_val, argc, argv);
};
static JSValue http_request_class_cancel_request(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::cancel_request, ctx, this_val, argc, argv);
};
static JSValue http_request_class_set_tls_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_tls_options, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_http_client_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_http_client_status, ctx, this_val, argc, argv);
};
static JSValue http_request_class_set_use_threads(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_use_threads, ctx, this_val, argc, argv);
};
static JSValue http_request_class_is_using_threads(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::is_using_threads, ctx, this_val, argc, argv);
}
static JSValue http_request_class_set_accept_gzip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_accept_gzip, ctx, this_val, argc, argv);
};
static JSValue http_request_class_is_accepting_gzip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::is_accepting_gzip, ctx, this_val, argc, argv);
}
static JSValue http_request_class_set_body_size_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_body_size_limit, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_body_size_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_body_size_limit, ctx, this_val, argc, argv);
}
static JSValue http_request_class_set_max_redirects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_max_redirects, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_max_redirects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_max_redirects, ctx, this_val, argc, argv);
}
static JSValue http_request_class_set_download_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_download_file, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_download_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_download_file, ctx, this_val, argc, argv);
}
static JSValue http_request_class_get_downloaded_bytes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_downloaded_bytes, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_body_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_body_size, ctx, this_val, argc, argv);
};
static JSValue http_request_class_set_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_timeout, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&HTTPRequest::get_timeout, ctx, this_val, argc, argv);
}
static JSValue http_request_class_set_download_chunk_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_download_chunk_size, ctx, this_val, argc, argv);
};
static JSValue http_request_class_get_download_chunk_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HTTPRequest::get_download_chunk_size, ctx, this_val, argc, argv);
}
static JSValue http_request_class_set_http_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_http_proxy, ctx, this_val, argc, argv);
};
static JSValue http_request_class_set_https_proxy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HTTPRequest::set_https_proxy, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry http_request_class_proto_funcs[] = {
	JS_CFUNC_DEF("request", 4, &http_request_class_request),
	JS_CFUNC_DEF("request_raw", 4, &http_request_class_request_raw),
	JS_CFUNC_DEF("cancel_request", 0, &http_request_class_cancel_request),
	JS_CFUNC_DEF("set_tls_options", 1, &http_request_class_set_tls_options),
	JS_CFUNC_DEF("get_http_client_status", 0, &http_request_class_get_http_client_status),
	JS_CFUNC_DEF("set_use_threads", 1, &http_request_class_set_use_threads),
	JS_CFUNC_DEF("is_using_threads", 0, &http_request_class_is_using_threads),
	JS_CFUNC_DEF("set_accept_gzip", 1, &http_request_class_set_accept_gzip),
	JS_CFUNC_DEF("is_accepting_gzip", 0, &http_request_class_is_accepting_gzip),
	JS_CFUNC_DEF("set_body_size_limit", 1, &http_request_class_set_body_size_limit),
	JS_CFUNC_DEF("get_body_size_limit", 0, &http_request_class_get_body_size_limit),
	JS_CFUNC_DEF("set_max_redirects", 1, &http_request_class_set_max_redirects),
	JS_CFUNC_DEF("get_max_redirects", 0, &http_request_class_get_max_redirects),
	JS_CFUNC_DEF("set_download_file", 1, &http_request_class_set_download_file),
	JS_CFUNC_DEF("get_download_file", 0, &http_request_class_get_download_file),
	JS_CFUNC_DEF("get_downloaded_bytes", 0, &http_request_class_get_downloaded_bytes),
	JS_CFUNC_DEF("get_body_size", 0, &http_request_class_get_body_size),
	JS_CFUNC_DEF("set_timeout", 1, &http_request_class_set_timeout),
	JS_CFUNC_DEF("get_timeout", 0, &http_request_class_get_timeout),
	JS_CFUNC_DEF("set_download_chunk_size", 1, &http_request_class_set_download_chunk_size),
	JS_CFUNC_DEF("get_download_chunk_size", 0, &http_request_class_get_download_chunk_size),
	JS_CFUNC_DEF("set_http_proxy", 2, &http_request_class_set_http_proxy),
	JS_CFUNC_DEF("set_https_proxy", 2, &http_request_class_set_https_proxy),
};


static JSValue http_request_class_get_request_completed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "request_completed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_http_request_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "download_file"),
        JS_NewCFunction(ctx, http_request_class_get_download_file, "get_download_file", 0),
        JS_NewCFunction(ctx, http_request_class_set_download_file, "set_download_file", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "download_chunk_size"),
        JS_NewCFunction(ctx, http_request_class_get_download_chunk_size, "get_download_chunk_size", 0),
        JS_NewCFunction(ctx, http_request_class_set_download_chunk_size, "set_download_chunk_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_threads"),
        JS_NewCFunction(ctx, http_request_class_is_using_threads, "is_using_threads", 0),
        JS_NewCFunction(ctx, http_request_class_set_use_threads, "set_use_threads", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accept_gzip"),
        JS_NewCFunction(ctx, http_request_class_is_accepting_gzip, "is_accepting_gzip", 0),
        JS_NewCFunction(ctx, http_request_class_set_accept_gzip, "set_accept_gzip", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "body_size_limit"),
        JS_NewCFunction(ctx, http_request_class_get_body_size_limit, "get_body_size_limit", 0),
        JS_NewCFunction(ctx, http_request_class_set_body_size_limit, "set_body_size_limit", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_redirects"),
        JS_NewCFunction(ctx, http_request_class_get_max_redirects, "get_max_redirects", 0),
        JS_NewCFunction(ctx, http_request_class_set_max_redirects, "set_max_redirects", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "timeout"),
        JS_NewCFunction(ctx, http_request_class_get_timeout, "get_timeout", 0),
        JS_NewCFunction(ctx, http_request_class_set_timeout, "set_timeout", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "request_completed"),
		JS_NewCFunction(ctx, http_request_class_get_request_completed_signal, "get_request_completed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_http_request_enum(JSContext *ctx, JSValue ctor) {
	JSValue Result_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_SUCCESS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_CHUNKED_BODY_SIZE_MISMATCH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_CANT_CONNECT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_CANT_RESOLVE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_CONNECTION_ERROR", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_TLS_HANDSHAKE_ERROR", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_NO_RESPONSE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_BODY_SIZE_LIMIT_EXCEEDED", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_BODY_DECOMPRESS_FAILED", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_REQUEST_FAILED", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_DOWNLOAD_FILE_CANT_OPEN", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_DOWNLOAD_FILE_WRITE_ERROR", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_REDIRECT_LIMIT_REACHED", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Result_obj, "RESULT_TIMEOUT", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ctor, "Result", Result_obj);
}

static int js_http_request_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["HTTPRequest"] = class_id;
	classes_by_id[class_id] = "HTTPRequest";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &http_request_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_http_request_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, http_request_class_proto_funcs, _countof(http_request_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, http_request_class_constructor, "HTTPRequest", 0, JS_CFUNC_constructor, 0);
	define_http_request_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "HTTPRequest", ctor);
	ctor_list["HTTPRequest"] = ctor;

	return 0;
}

JSModuleDef *_js_init_http_request_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_http_request_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "HTTPRequest");
	return m;
}

JSModuleDef *js_init_http_request_module(JSContext *ctx) {
	return _js_init_http_request_module(ctx, "@godot/classes/http_request");
}

void __register_http_request() {
	js_init_http_request_module(js_context());
}

void register_http_request() {
	__register_http_request();
}