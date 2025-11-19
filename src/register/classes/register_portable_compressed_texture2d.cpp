#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/portable_compressed_texture2d.hpp>
using namespace godot;

static void portable_compressed_texture2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PortableCompressedTexture2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef portable_compressed_texture2d_class_def = {
    "PortableCompressedTexture2D",
    portable_compressed_texture2d_class_finalizer
};

static JSValue portable_compressed_texture2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PortableCompressedTexture2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PortableCompressedTexture2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PortableCompressedTexture2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PortableCompressedTexture2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue portable_compressed_texture2d_class_create_from_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PortableCompressedTexture2D::create_from_image, ctx, this_val, argc, argv);
};
static JSValue portable_compressed_texture2d_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PortableCompressedTexture2D::get_format, ctx, this_val, argc, argv);
};
static JSValue portable_compressed_texture2d_class_get_compression_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PortableCompressedTexture2D::get_compression_mode, ctx, this_val, argc, argv);
};
static JSValue portable_compressed_texture2d_class_set_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PortableCompressedTexture2D::set_size_override, ctx, this_val, argc, argv);
};
static JSValue portable_compressed_texture2d_class_get_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PortableCompressedTexture2D *obj = static_cast<PortableCompressedTexture2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size_override();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PortableCompressedTexture2D *js_proxy = static_cast<PortableCompressedTexture2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size_override(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue portable_compressed_texture2d_class_set_keep_compressed_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PortableCompressedTexture2D::set_keep_compressed_buffer, ctx, this_val, argc, argv);
};
static JSValue portable_compressed_texture2d_class_is_keeping_compressed_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PortableCompressedTexture2D::is_keeping_compressed_buffer, ctx, this_val, argc, argv);
}
static JSValue portable_compressed_texture2d_class_set_basisu_compressor_params(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PortableCompressedTexture2D::set_basisu_compressor_params, ctx, this_val, argc, argv);
};


static JSValue portable_compressed_texture2d_class_set_keep_all_compressed_buffers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&PortableCompressedTexture2D::set_keep_all_compressed_buffers, ctx, this_val, argc, argv);
};
static JSValue portable_compressed_texture2d_class_is_keeping_all_compressed_buffers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&PortableCompressedTexture2D::is_keeping_all_compressed_buffers, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry portable_compressed_texture2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_from_image", 4, &portable_compressed_texture2d_class_create_from_image),
	JS_CFUNC_DEF("get_format", 0, &portable_compressed_texture2d_class_get_format),
	JS_CFUNC_DEF("get_compression_mode", 0, &portable_compressed_texture2d_class_get_compression_mode),
	JS_CFUNC_DEF("set_size_override", 1, &portable_compressed_texture2d_class_set_size_override),
	JS_CFUNC_DEF("get_size_override", 0, &portable_compressed_texture2d_class_get_size_override),
	JS_CFUNC_DEF("set_keep_compressed_buffer", 1, &portable_compressed_texture2d_class_set_keep_compressed_buffer),
	JS_CFUNC_DEF("is_keeping_compressed_buffer", 0, &portable_compressed_texture2d_class_is_keeping_compressed_buffer),
	JS_CFUNC_DEF("set_basisu_compressor_params", 2, &portable_compressed_texture2d_class_set_basisu_compressor_params),
};

static const JSCFunctionListEntry portable_compressed_texture2d_class_static_funcs[] = {
	JS_CFUNC_DEF("set_keep_all_compressed_buffers", 1, &portable_compressed_texture2d_class_set_keep_all_compressed_buffers),
	JS_CFUNC_DEF("is_keeping_all_compressed_buffers", 0, &portable_compressed_texture2d_class_is_keeping_all_compressed_buffers),
};



static void define_portable_compressed_texture2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size_override"),
        JS_NewCFunction(ctx, portable_compressed_texture2d_class_get_size_override, "get_size_override", 0),
        JS_NewCFunction(ctx, portable_compressed_texture2d_class_set_size_override, "set_size_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_compressed_buffer"),
        JS_NewCFunction(ctx, portable_compressed_texture2d_class_is_keeping_compressed_buffer, "is_keeping_compressed_buffer", 0),
        JS_NewCFunction(ctx, portable_compressed_texture2d_class_set_keep_compressed_buffer, "set_keep_compressed_buffer", 1),
        JS_PROP_GETSET
    );
}

static void define_portable_compressed_texture2d_enum(JSContext *ctx, JSValue ctor) {
	JSValue CompressionMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_LOSSLESS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_LOSSY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_BASIS_UNIVERSAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_S3TC", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_ETC2", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_BPTC", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_MODE_ASTC", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "CompressionMode", CompressionMode_obj);
}

static int js_portable_compressed_texture2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PortableCompressedTexture2D"] = class_id;
	classes_by_id[class_id] = "PortableCompressedTexture2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &portable_compressed_texture2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_portable_compressed_texture2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, portable_compressed_texture2d_class_proto_funcs, _countof(portable_compressed_texture2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, portable_compressed_texture2d_class_constructor, "PortableCompressedTexture2D", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, portable_compressed_texture2d_class_static_funcs, _countof(portable_compressed_texture2d_class_static_funcs));
	define_portable_compressed_texture2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PortableCompressedTexture2D", ctor);

	return 0;
}

JSModuleDef *_js_init_portable_compressed_texture2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_portable_compressed_texture2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PortableCompressedTexture2D");
	return m;
}

JSModuleDef *js_init_portable_compressed_texture2d_module(JSContext *ctx) {
	return _js_init_portable_compressed_texture2d_module(ctx, "@godot/classes/portable_compressed_texture2d");
}

void __register_portable_compressed_texture2d() {
	js_init_portable_compressed_texture2d_module(js_context());
}

void register_portable_compressed_texture2d() {
	__register_portable_compressed_texture2d();
}