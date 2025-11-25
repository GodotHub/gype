#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/crypto_key.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/x509_certificate.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tls_options.hpp>
using namespace godot;

static void tls_options_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TLSOptions"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef tls_options_class_def = {
    "TLSOptions",
    tls_options_class_finalizer
};

static JSValue tls_options_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TLSOptions"];
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
        instance = memnew(TLSOptions);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tls_options_class_is_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TLSOptions::is_server, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_is_unsafe_client(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TLSOptions::is_unsafe_client, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_get_common_name_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TLSOptions::get_common_name_override, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_get_trusted_ca_chain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TLSOptions::get_trusted_ca_chain, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_get_private_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TLSOptions::get_private_key, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_get_own_certificate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TLSOptions::get_own_certificate, ctx, this_val, argc, argv);
};


static JSValue tls_options_class_client(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&TLSOptions::client, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_client_unsafe(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&TLSOptions::client_unsafe, ctx, this_val, argc, argv);
};
static JSValue tls_options_class_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&TLSOptions::server, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry tls_options_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_server", 0, &tls_options_class_is_server),
	JS_CFUNC_DEF("is_unsafe_client", 0, &tls_options_class_is_unsafe_client),
	JS_CFUNC_DEF("get_common_name_override", 0, &tls_options_class_get_common_name_override),
	JS_CFUNC_DEF("get_trusted_ca_chain", 0, &tls_options_class_get_trusted_ca_chain),
	JS_CFUNC_DEF("get_private_key", 0, &tls_options_class_get_private_key),
	JS_CFUNC_DEF("get_own_certificate", 0, &tls_options_class_get_own_certificate),
};

static const JSCFunctionListEntry tls_options_class_static_funcs[] = {
	JS_CFUNC_DEF("client", 2, &tls_options_class_client),
	JS_CFUNC_DEF("client_unsafe", 1, &tls_options_class_client_unsafe),
	JS_CFUNC_DEF("server", 2, &tls_options_class_server),
};



static void define_tls_options_property(JSContext *ctx, JSValue proto) {
}

static void define_tls_options_enum(JSContext *ctx, JSValue ctor) {
}

static int js_tls_options_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TLSOptions"] = class_id;
	classes_by_id[class_id] = "TLSOptions";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tls_options_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tls_options_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tls_options_class_proto_funcs, _countof(tls_options_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tls_options_class_constructor, "TLSOptions", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, tls_options_class_static_funcs, _countof(tls_options_class_static_funcs));
	define_tls_options_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TLSOptions", ctor);
	ctor_list["TLSOptions"] = ctor;

	return 0;
}

JSModuleDef *_js_init_tls_options_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tls_options_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TLSOptions");
	return m;
}

JSModuleDef *js_init_tls_options_module(JSContext *ctx) {
	return _js_init_tls_options_module(ctx, "@godot/classes/tls_options");
}

void __register_tls_options() {
	js_init_tls_options_module(js_context());
}

void register_tls_options() {
	__register_tls_options();
}