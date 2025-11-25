#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/x509_certificate.hpp>
using namespace godot;

static void x509_certificate_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["X509Certificate"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef x509_certificate_class_def = {
    "X509Certificate",
    x509_certificate_class_finalizer
};

static JSValue x509_certificate_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["X509Certificate"];
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
        instance = memnew(X509Certificate);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue x509_certificate_class_save(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&X509Certificate::save, ctx, this_val, argc, argv);
};
static JSValue x509_certificate_class_load(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&X509Certificate::load, ctx, this_val, argc, argv);
};
static JSValue x509_certificate_class_save_to_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&X509Certificate::save_to_string, ctx, this_val, argc, argv);
};
static JSValue x509_certificate_class_load_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&X509Certificate::load_from_string, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry x509_certificate_class_proto_funcs[] = {
	JS_CFUNC_DEF("save", 1, &x509_certificate_class_save),
	JS_CFUNC_DEF("load", 1, &x509_certificate_class_load),
	JS_CFUNC_DEF("save_to_string", 0, &x509_certificate_class_save_to_string),
	JS_CFUNC_DEF("load_from_string", 1, &x509_certificate_class_load_from_string),
};




static void define_x509_certificate_property(JSContext *ctx, JSValue proto) {
}

static void define_x509_certificate_enum(JSContext *ctx, JSValue ctor) {
}

static int js_x509_certificate_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["X509Certificate"] = class_id;
	classes_by_id[class_id] = "X509Certificate";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &x509_certificate_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_x509_certificate_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, x509_certificate_class_proto_funcs, _countof(x509_certificate_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, x509_certificate_class_constructor, "X509Certificate", 0, JS_CFUNC_constructor, 0);
	define_x509_certificate_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "X509Certificate", ctor);
	ctor_list["X509Certificate"] = ctor;

	return 0;
}

JSModuleDef *_js_init_x509_certificate_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_x509_certificate_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "X509Certificate");
	return m;
}

JSModuleDef *js_init_x509_certificate_module(JSContext *ctx) {
	return _js_init_x509_certificate_module(ctx, "@godot/classes/x509_certificate");
}

void __register_x509_certificate() {
	js_init_x509_certificate_module(js_context());
}

void register_x509_certificate() {
	__register_x509_certificate();
}