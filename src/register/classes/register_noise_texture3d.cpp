#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gradient.hpp>
#include <godot_cpp/classes/noise.hpp>
#include <godot_cpp/classes/texture3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/noise_texture3d.hpp>
using namespace godot;

static void noise_texture3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NoiseTexture3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef noise_texture3d_class_def = {
    "NoiseTexture3D",
    noise_texture3d_class_finalizer
};

static JSValue noise_texture3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NoiseTexture3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NoiseTexture3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NoiseTexture3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NoiseTexture3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue noise_texture3d_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_width, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_height, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_set_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_depth, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_set_noise(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_noise, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_get_noise(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NoiseTexture3D::get_noise, ctx, this_val, argc, argv);
}
static JSValue noise_texture3d_class_set_color_ramp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_color_ramp, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_get_color_ramp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NoiseTexture3D::get_color_ramp, ctx, this_val, argc, argv);
}
static JSValue noise_texture3d_class_set_seamless(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_seamless, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_get_seamless(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NoiseTexture3D::get_seamless, ctx, this_val, argc, argv);
}
static JSValue noise_texture3d_class_set_invert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_invert, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_get_invert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NoiseTexture3D::get_invert, ctx, this_val, argc, argv);
}
static JSValue noise_texture3d_class_set_normalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_normalize, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NoiseTexture3D::is_normalized, ctx, this_val, argc, argv);
}
static JSValue noise_texture3d_class_set_seamless_blend_skirt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NoiseTexture3D::set_seamless_blend_skirt, ctx, this_val, argc, argv);
};
static JSValue noise_texture3d_class_get_seamless_blend_skirt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NoiseTexture3D::get_seamless_blend_skirt, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry noise_texture3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_width", 1, &noise_texture3d_class_set_width),
	JS_CFUNC_DEF("set_height", 1, &noise_texture3d_class_set_height),
	JS_CFUNC_DEF("set_depth", 1, &noise_texture3d_class_set_depth),
	JS_CFUNC_DEF("set_noise", 1, &noise_texture3d_class_set_noise),
	JS_CFUNC_DEF("get_noise", 0, &noise_texture3d_class_get_noise),
	JS_CFUNC_DEF("set_color_ramp", 1, &noise_texture3d_class_set_color_ramp),
	JS_CFUNC_DEF("get_color_ramp", 0, &noise_texture3d_class_get_color_ramp),
	JS_CFUNC_DEF("set_seamless", 1, &noise_texture3d_class_set_seamless),
	JS_CFUNC_DEF("get_seamless", 0, &noise_texture3d_class_get_seamless),
	JS_CFUNC_DEF("set_invert", 1, &noise_texture3d_class_set_invert),
	JS_CFUNC_DEF("get_invert", 0, &noise_texture3d_class_get_invert),
	JS_CFUNC_DEF("set_normalize", 1, &noise_texture3d_class_set_normalize),
	JS_CFUNC_DEF("is_normalized", 0, &noise_texture3d_class_is_normalized),
	JS_CFUNC_DEF("set_seamless_blend_skirt", 1, &noise_texture3d_class_set_seamless_blend_skirt),
	JS_CFUNC_DEF("get_seamless_blend_skirt", 0, &noise_texture3d_class_get_seamless_blend_skirt),
};




static void define_noise_texture3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, noise_texture3d_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, noise_texture3d_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, noise_texture3d_class_set_depth, "set_depth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "noise"),
        JS_NewCFunction(ctx, noise_texture3d_class_get_noise, "get_noise", 0),
        JS_NewCFunction(ctx, noise_texture3d_class_set_noise, "set_noise", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_ramp"),
        JS_NewCFunction(ctx, noise_texture3d_class_get_color_ramp, "get_color_ramp", 0),
        JS_NewCFunction(ctx, noise_texture3d_class_set_color_ramp, "set_color_ramp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "seamless"),
        JS_NewCFunction(ctx, noise_texture3d_class_get_seamless, "get_seamless", 0),
        JS_NewCFunction(ctx, noise_texture3d_class_set_seamless, "set_seamless", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "invert"),
        JS_NewCFunction(ctx, noise_texture3d_class_get_invert, "get_invert", 0),
        JS_NewCFunction(ctx, noise_texture3d_class_set_invert, "set_invert", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "normalize"),
        JS_NewCFunction(ctx, noise_texture3d_class_is_normalized, "is_normalized", 0),
        JS_NewCFunction(ctx, noise_texture3d_class_set_normalize, "set_normalize", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "seamless_blend_skirt"),
        JS_NewCFunction(ctx, noise_texture3d_class_get_seamless_blend_skirt, "get_seamless_blend_skirt", 0),
        JS_NewCFunction(ctx, noise_texture3d_class_set_seamless_blend_skirt, "set_seamless_blend_skirt", 1),
        JS_PROP_GETSET
    );
}

static void define_noise_texture3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_noise_texture3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NoiseTexture3D"] = class_id;
	classes_by_id[class_id] = "NoiseTexture3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &noise_texture3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_noise_texture3d_property(ctx, proto);
	define_noise_texture3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, noise_texture3d_class_proto_funcs, _countof(noise_texture3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, noise_texture3d_class_constructor, "NoiseTexture3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NoiseTexture3D", ctor);

	return 0;
}

JSModuleDef *_js_init_noise_texture3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_noise_texture3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NoiseTexture3D");
	return m;
}

JSModuleDef *js_init_noise_texture3d_module(JSContext *ctx) {
	return _js_init_noise_texture3d_module(ctx, "@godot/classes/noise_texture3d");
}

void __register_noise_texture3d() {
	js_init_noise_texture3d_module(js_context());
}

void register_noise_texture3d() {
	__register_noise_texture3d();
}