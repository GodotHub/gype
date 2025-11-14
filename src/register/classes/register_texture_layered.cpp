#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/texture_layered.hpp>
using namespace godot;

static void texture_layered_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TextureLayered"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef texture_layered_class_def = {
    "TextureLayered",
    texture_layered_class_finalizer
};

static JSValue texture_layered_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TextureLayered"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TextureLayered *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TextureLayered *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TextureLayered);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue texture_layered_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::get_format, ctx, this_val, argc, argv);
};
static JSValue texture_layered_class_get_layered_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::get_layered_type, ctx, this_val, argc, argv);
};
static JSValue texture_layered_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::get_width, ctx, this_val, argc, argv);
};
static JSValue texture_layered_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::get_height, ctx, this_val, argc, argv);
};
static JSValue texture_layered_class_get_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::get_layers, ctx, this_val, argc, argv);
};
static JSValue texture_layered_class_has_mipmaps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::has_mipmaps, ctx, this_val, argc, argv);
};
static JSValue texture_layered_class_get_layer_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureLayered::get_layer_data, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry texture_layered_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_format", 0, &texture_layered_class_get_format),
	JS_CFUNC_DEF("get_layered_type", 0, &texture_layered_class_get_layered_type),
	JS_CFUNC_DEF("get_width", 0, &texture_layered_class_get_width),
	JS_CFUNC_DEF("get_height", 0, &texture_layered_class_get_height),
	JS_CFUNC_DEF("get_layers", 0, &texture_layered_class_get_layers),
	JS_CFUNC_DEF("has_mipmaps", 0, &texture_layered_class_has_mipmaps),
	JS_CFUNC_DEF("get_layer_data", 1, &texture_layered_class_get_layer_data),
};




static void define_texture_layered_property(JSContext *ctx, JSValue proto) {
}

static void define_texture_layered_enum(JSContext *ctx, JSValue proto) {
	JSValue LayeredType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LayeredType_obj, "LAYERED_TYPE_2D_ARRAY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LayeredType_obj, "LAYERED_TYPE_CUBEMAP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LayeredType_obj, "LAYERED_TYPE_CUBEMAP_ARRAY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "LayeredType", LayeredType_obj);
}

static int js_texture_layered_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TextureLayered"] = class_id;
	classes_by_id[class_id] = "TextureLayered";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &texture_layered_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_texture_layered_property(ctx, proto);
	define_texture_layered_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, texture_layered_class_proto_funcs, _countof(texture_layered_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, texture_layered_class_constructor, "TextureLayered", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TextureLayered", ctor);

	return 0;
}

JSModuleDef *_js_init_texture_layered_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_texture_layered_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TextureLayered");
	return m;
}

JSModuleDef *js_init_texture_layered_module(JSContext *ctx) {
	return _js_init_texture_layered_module(ctx, "@godot/classes/texture_layered");
}

void __register_texture_layered() {
	js_init_texture_layered_module(js_context());
}

void register_texture_layered() {
	__register_texture_layered();
}