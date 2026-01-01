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
#include <godot_cpp/classes/crypto.hpp>
using namespace godot;

static void crypto_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Crypto"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef crypto_class_def = {
    "Crypto",
    crypto_class_finalizer
};

static JSValue crypto_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Crypto"];
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
        instance = memnew(Crypto);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue crypto_class_generate_random_bytes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::generate_random_bytes, ctx, this_val, argc, argv);
};
static JSValue crypto_class_generate_rsa(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::generate_rsa, ctx, this_val, argc, argv);
};
static JSValue crypto_class_generate_self_signed_certificate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::generate_self_signed_certificate, ctx, this_val, argc, argv);
};
static JSValue crypto_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::sign, ctx, this_val, argc, argv);
};
static JSValue crypto_class_verify(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::verify, ctx, this_val, argc, argv);
};
static JSValue crypto_class_encrypt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::encrypt, ctx, this_val, argc, argv);
};
static JSValue crypto_class_decrypt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::decrypt, ctx, this_val, argc, argv);
};
static JSValue crypto_class_hmac_digest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::hmac_digest, ctx, this_val, argc, argv);
};
static JSValue crypto_class_constant_time_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Crypto::constant_time_compare, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry crypto_class_proto_funcs[] = {
	JS_CFUNC_DEF("generate_random_bytes", 1, &crypto_class_generate_random_bytes),
	JS_CFUNC_DEF("generate_rsa", 1, &crypto_class_generate_rsa),
	JS_CFUNC_DEF("generate_self_signed_certificate", 4, &crypto_class_generate_self_signed_certificate),
	JS_CFUNC_DEF("sign", 3, &crypto_class_sign),
	JS_CFUNC_DEF("verify", 4, &crypto_class_verify),
	JS_CFUNC_DEF("encrypt", 2, &crypto_class_encrypt),
	JS_CFUNC_DEF("decrypt", 2, &crypto_class_decrypt),
	JS_CFUNC_DEF("hmac_digest", 3, &crypto_class_hmac_digest),
	JS_CFUNC_DEF("constant_time_compare", 2, &crypto_class_constant_time_compare),
};




static void define_crypto_property(JSContext *ctx, JSValue proto) {
}

static void define_crypto_enum(JSContext *ctx, JSValue ctor) {
}

static int js_crypto_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Crypto"] = class_id;
	classes_by_id[class_id] = "Crypto";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &crypto_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_crypto_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, crypto_class_proto_funcs, _countof(crypto_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, crypto_class_constructor, "Crypto", 0, JS_CFUNC_constructor, 0);
	define_crypto_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Crypto", ctor);
	ctor_list["Crypto"] = ctor;

	return 0;
}

JSModuleDef *_js_init_crypto_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_crypto_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Crypto");
	return m;
}

JSModuleDef *js_init_crypto_module(JSContext *ctx) {
	return _js_init_crypto_module(ctx, "@godot/classes/crypto");
}

void __register_crypto() {
	js_init_crypto_module(js_context());
}

void register_crypto() {
	__register_crypto();
}