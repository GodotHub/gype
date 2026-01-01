#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/external_texture.hpp>
using namespace godot;

static void external_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ExternalTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef external_texture_class_def = {
    "ExternalTexture",
    external_texture_class_finalizer
};

static JSValue external_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ExternalTexture"];
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
        instance = memnew(ExternalTexture);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue external_texture_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ExternalTexture::set_size, ctx, this_val, argc, argv);
};
static JSValue external_texture_class_get_external_texture_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ExternalTexture::get_external_texture_id, ctx, this_val, argc, argv);
};
static JSValue external_texture_class_set_external_buffer_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ExternalTexture::set_external_buffer_id, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry external_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &external_texture_class_set_size),
	JS_CFUNC_DEF("get_external_texture_id", 0, &external_texture_class_get_external_texture_id),
	JS_CFUNC_DEF("set_external_buffer_id", 1, &external_texture_class_set_external_buffer_id),
};




static void define_external_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, external_texture_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
}

static void define_external_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_external_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ExternalTexture"] = class_id;
	classes_by_id[class_id] = "ExternalTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &external_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_external_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, external_texture_class_proto_funcs, _countof(external_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, external_texture_class_constructor, "ExternalTexture", 0, JS_CFUNC_constructor, 0);
	define_external_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ExternalTexture", ctor);
	ctor_list["ExternalTexture"] = ctor;

	return 0;
}

JSModuleDef *_js_init_external_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_external_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ExternalTexture");
	return m;
}

JSModuleDef *js_init_external_texture_module(JSContext *ctx) {
	return _js_init_external_texture_module(ctx, "@godot/classes/external_texture");
}

void __register_external_texture() {
	js_init_external_texture_module(js_context());
}

void register_external_texture() {
	__register_external_texture();
}