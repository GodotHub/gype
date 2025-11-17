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
#include <godot_cpp/classes/image_texture.hpp>
using namespace godot;

static void image_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ImageTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef image_texture_class_def = {
    "ImageTexture",
    image_texture_class_finalizer
};

static JSValue image_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ImageTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ImageTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ImageTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ImageTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue image_texture_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImageTexture::get_format, ctx, this_val, argc, argv);
};
static JSValue image_texture_class_set_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImageTexture::set_image, ctx, this_val, argc, argv);
};
static JSValue image_texture_class_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImageTexture::update, ctx, this_val, argc, argv);
};
static JSValue image_texture_class_set_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImageTexture::set_size_override, ctx, this_val, argc, argv);
};
static JSValue image_texture_class_create_from_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&ImageTexture::create_from_image, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry image_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_format", 0, &image_texture_class_get_format),
	JS_CFUNC_DEF("set_image", 1, &image_texture_class_set_image),
	JS_CFUNC_DEF("update", 1, &image_texture_class_update),
	JS_CFUNC_DEF("set_size_override", 1, &image_texture_class_set_size_override),
};

static const JSCFunctionListEntry image_texture_class_static_funcs[] = {
	JS_CFUNC_DEF("create_from_image", 1, &image_texture_class_create_from_image),
};



static void define_image_texture_property(JSContext *ctx, JSValue proto) {
}

static void define_image_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_image_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ImageTexture"] = class_id;
	classes_by_id[class_id] = "ImageTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &image_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_image_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, image_texture_class_proto_funcs, _countof(image_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, image_texture_class_constructor, "ImageTexture", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, image_texture_class_static_funcs, _countof(image_texture_class_static_funcs));
	define_image_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ImageTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_image_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_image_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ImageTexture");
	return m;
}

JSModuleDef *js_init_image_texture_module(JSContext *ctx) {
	return _js_init_image_texture_module(ctx, "@godot/classes/image_texture");
}

void __register_image_texture() {
	js_init_image_texture_module(js_context());
}

void register_image_texture() {
	__register_image_texture();
}