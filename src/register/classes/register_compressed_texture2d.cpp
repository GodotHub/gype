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
#include <godot_cpp/classes/compressed_texture2d.hpp>
using namespace godot;

static void compressed_texture2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CompressedTexture2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef compressed_texture2d_class_def = {
    "CompressedTexture2D",
    compressed_texture2d_class_finalizer
};

static JSValue compressed_texture2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CompressedTexture2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CompressedTexture2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CompressedTexture2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CompressedTexture2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue compressed_texture2d_class_load(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CompressedTexture2D::load, ctx, this_val, argc, argv);
};
static JSValue compressed_texture2d_class_get_load_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		CompressedTexture2D *obj = static_cast<CompressedTexture2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_load_path();
	};
	proxy->setter = [this_val](const String &value) -> void {
		CompressedTexture2D *js_proxy = static_cast<CompressedTexture2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->load(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry compressed_texture2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("load", 1, &compressed_texture2d_class_load),
	JS_CFUNC_DEF("get_load_path", 0, &compressed_texture2d_class_get_load_path),
};




static void define_compressed_texture2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "load_path"),
        JS_NewCFunction(ctx, compressed_texture2d_class_get_load_path, "get_load_path", 0),
        JS_NewCFunction(ctx, compressed_texture2d_class_load, "load", 1),
        JS_PROP_GETSET
    );
}

static void define_compressed_texture2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_compressed_texture2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CompressedTexture2D"] = class_id;
	classes_by_id[class_id] = "CompressedTexture2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &compressed_texture2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_compressed_texture2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, compressed_texture2d_class_proto_funcs, _countof(compressed_texture2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, compressed_texture2d_class_constructor, "CompressedTexture2D", 0, JS_CFUNC_constructor, 0);
	define_compressed_texture2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CompressedTexture2D", ctor);

	return 0;
}

JSModuleDef *_js_init_compressed_texture2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_compressed_texture2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CompressedTexture2D");
	return m;
}

JSModuleDef *js_init_compressed_texture2d_module(JSContext *ctx) {
	return _js_init_compressed_texture2d_module(ctx, "@godot/classes/compressed_texture2d");
}

void __register_compressed_texture2d() {
	js_init_compressed_texture2d_module(js_context());
}

void register_compressed_texture2d() {
	__register_compressed_texture2d();
}