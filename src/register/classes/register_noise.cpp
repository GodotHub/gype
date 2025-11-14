#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/noise.hpp>
using namespace godot;

static void noise_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Noise"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef noise_class_def = {
    "Noise",
    noise_class_finalizer
};

static JSValue noise_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Noise"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Noise *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Noise *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Noise);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue noise_class_get_noise_1d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_noise_1d, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_noise_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_noise_2d, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_noise_2dv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_noise_2dv, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_noise_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_noise_3d, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_noise_3dv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_noise_3dv, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_image, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_seamless_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_seamless_image, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_image_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_image_3d, ctx, this_val, argc, argv);
};
static JSValue noise_class_get_seamless_image_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Noise::get_seamless_image_3d, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry noise_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_noise_1d", 1, &noise_class_get_noise_1d),
	JS_CFUNC_DEF("get_noise_2d", 2, &noise_class_get_noise_2d),
	JS_CFUNC_DEF("get_noise_2dv", 1, &noise_class_get_noise_2dv),
	JS_CFUNC_DEF("get_noise_3d", 3, &noise_class_get_noise_3d),
	JS_CFUNC_DEF("get_noise_3dv", 1, &noise_class_get_noise_3dv),
	JS_CFUNC_DEF("get_image", 5, &noise_class_get_image),
	JS_CFUNC_DEF("get_seamless_image", 6, &noise_class_get_seamless_image),
	JS_CFUNC_DEF("get_image_3d", 5, &noise_class_get_image_3d),
	JS_CFUNC_DEF("get_seamless_image_3d", 6, &noise_class_get_seamless_image_3d),
};




static void define_noise_property(JSContext *ctx, JSValue proto) {
}

static void define_noise_enum(JSContext *ctx, JSValue proto) {
}

static int js_noise_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Noise"] = class_id;
	classes_by_id[class_id] = "Noise";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &noise_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_noise_property(ctx, proto);
	define_noise_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, noise_class_proto_funcs, _countof(noise_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, noise_class_constructor, "Noise", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Noise", ctor);

	return 0;
}

JSModuleDef *_js_init_noise_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_noise_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Noise");
	return m;
}

JSModuleDef *js_init_noise_module(JSContext *ctx) {
	return _js_init_noise_module(ctx, "@godot/classes/noise");
}

void __register_noise() {
	js_init_noise_module(js_context());
}

void register_noise() {
	__register_noise();
}