#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/jsonrpc.hpp>
using namespace godot;

static void jsonrpc_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["JSONRPC"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef jsonrpc_class_def = {
    "JSONRPC",
    jsonrpc_class_finalizer
};

static JSValue jsonrpc_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["JSONRPC"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    JSONRPC *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<JSONRPC *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(JSONRPC);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue jsonrpc_class_set_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&JSONRPC::set_method, ctx, this_val, argc, argv);
};
static JSValue jsonrpc_class_process_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&JSONRPC::process_action, ctx, this_val, argc, argv);
};
static JSValue jsonrpc_class_process_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&JSONRPC::process_string, ctx, this_val, argc, argv);
};
static JSValue jsonrpc_class_make_request(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&JSONRPC::make_request, ctx, this_val, argc, argv);
};
static JSValue jsonrpc_class_make_response(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&JSONRPC::make_response, ctx, this_val, argc, argv);
};
static JSValue jsonrpc_class_make_notification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&JSONRPC::make_notification, ctx, this_val, argc, argv);
};
static JSValue jsonrpc_class_make_response_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&JSONRPC::make_response_error, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry jsonrpc_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_method", 2, &jsonrpc_class_set_method),
	JS_CFUNC_DEF("process_action", 2, &jsonrpc_class_process_action),
	JS_CFUNC_DEF("process_string", 1, &jsonrpc_class_process_string),
	JS_CFUNC_DEF("make_request", 3, &jsonrpc_class_make_request),
	JS_CFUNC_DEF("make_response", 2, &jsonrpc_class_make_response),
	JS_CFUNC_DEF("make_notification", 2, &jsonrpc_class_make_notification),
	JS_CFUNC_DEF("make_response_error", 3, &jsonrpc_class_make_response_error),
};




static void define_jsonrpc_property(JSContext *ctx, JSValue proto) {
}

static void define_jsonrpc_enum(JSContext *ctx, JSValue ctor) {
	JSValue ErrorCode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ErrorCode_obj, "PARSE_ERROR", JS_NewInt64(ctx, -32700));
	JS_SetPropertyStr(ctx, ErrorCode_obj, "INVALID_REQUEST", JS_NewInt64(ctx, -32600));
	JS_SetPropertyStr(ctx, ErrorCode_obj, "METHOD_NOT_FOUND", JS_NewInt64(ctx, -32601));
	JS_SetPropertyStr(ctx, ErrorCode_obj, "INVALID_PARAMS", JS_NewInt64(ctx, -32602));
	JS_SetPropertyStr(ctx, ErrorCode_obj, "INTERNAL_ERROR", JS_NewInt64(ctx, -32603));
	JS_SetPropertyStr(ctx, ctor, "ErrorCode", ErrorCode_obj);
}

static int js_jsonrpc_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["JSONRPC"] = class_id;
	classes_by_id[class_id] = "JSONRPC";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &jsonrpc_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_jsonrpc_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, jsonrpc_class_proto_funcs, _countof(jsonrpc_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, jsonrpc_class_constructor, "JSONRPC", 0, JS_CFUNC_constructor, 0);
	define_jsonrpc_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "JSONRPC", ctor);

	return 0;
}

JSModuleDef *_js_init_jsonrpc_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_jsonrpc_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "JSONRPC");
	return m;
}

JSModuleDef *js_init_jsonrpc_module(JSContext *ctx) {
	return _js_init_jsonrpc_module(ctx, "@godot/classes/jsonrpc");
}

void __register_jsonrpc() {
	js_init_jsonrpc_module(js_context());
}

void register_jsonrpc() {
	__register_jsonrpc();
}