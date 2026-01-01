#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/curve_texture.hpp>
using namespace godot;

static void curve_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CurveTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef curve_texture_class_def = {
    "CurveTexture",
    curve_texture_class_finalizer
};

static JSValue curve_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CurveTexture"];
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
        instance = memnew(CurveTexture);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue curve_texture_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveTexture::set_width, ctx, this_val, argc, argv);
};
static JSValue curve_texture_class_set_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveTexture::set_curve, ctx, this_val, argc, argv);
};
static JSValue curve_texture_class_get_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CurveTexture::get_curve, ctx, this_val, argc, argv);
}
static JSValue curve_texture_class_set_texture_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveTexture::set_texture_mode, ctx, this_val, argc, argv);
};
static JSValue curve_texture_class_get_texture_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CurveTexture::get_texture_mode, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry curve_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_width", 1, &curve_texture_class_set_width),
	JS_CFUNC_DEF("set_curve", 1, &curve_texture_class_set_curve),
	JS_CFUNC_DEF("get_curve", 0, &curve_texture_class_get_curve),
	JS_CFUNC_DEF("set_texture_mode", 1, &curve_texture_class_set_texture_mode),
	JS_CFUNC_DEF("get_texture_mode", 0, &curve_texture_class_get_texture_mode),
};




static void define_curve_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, curve_texture_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_mode"),
        JS_NewCFunction(ctx, curve_texture_class_get_texture_mode, "get_texture_mode", 0),
        JS_NewCFunction(ctx, curve_texture_class_set_texture_mode, "set_texture_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "curve"),
        JS_NewCFunction(ctx, curve_texture_class_get_curve, "get_curve", 0),
        JS_NewCFunction(ctx, curve_texture_class_set_curve, "set_curve", 1),
        JS_PROP_GETSET
    );
}

static void define_curve_texture_enum(JSContext *ctx, JSValue ctor) {
	JSValue TextureMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureMode_obj, "TEXTURE_MODE_RGB", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureMode_obj, "TEXTURE_MODE_RED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "TextureMode", TextureMode_obj);
}

static int js_curve_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CurveTexture"] = class_id;
	classes_by_id[class_id] = "CurveTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &curve_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_curve_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, curve_texture_class_proto_funcs, _countof(curve_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, curve_texture_class_constructor, "CurveTexture", 0, JS_CFUNC_constructor, 0);
	define_curve_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CurveTexture", ctor);
	ctor_list["CurveTexture"] = ctor;

	return 0;
}

JSModuleDef *_js_init_curve_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_curve_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CurveTexture");
	return m;
}

JSModuleDef *js_init_curve_texture_module(JSContext *ctx) {
	return _js_init_curve_texture_module(ctx, "@godot/classes/curve_texture");
}

void __register_curve_texture() {
	js_init_curve_texture_module(js_context());
}

void register_curve_texture() {
	__register_curve_texture();
}