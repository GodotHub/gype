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
#include <godot_cpp/classes/gltf_texture_sampler.hpp>
using namespace godot;

static void gltf_texture_sampler_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFTextureSampler"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_texture_sampler_class_def = {
    "GLTFTextureSampler",
    gltf_texture_sampler_class_finalizer
};

static JSValue gltf_texture_sampler_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFTextureSampler"];
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
        instance = memnew(GLTFTextureSampler);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_texture_sampler_class_get_mag_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFTextureSampler::get_mag_filter, ctx, this_val, argc, argv);
}
static JSValue gltf_texture_sampler_class_set_mag_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFTextureSampler::set_mag_filter, ctx, this_val, argc, argv);
};
static JSValue gltf_texture_sampler_class_get_min_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFTextureSampler::get_min_filter, ctx, this_val, argc, argv);
}
static JSValue gltf_texture_sampler_class_set_min_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFTextureSampler::set_min_filter, ctx, this_val, argc, argv);
};
static JSValue gltf_texture_sampler_class_get_wrap_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFTextureSampler::get_wrap_s, ctx, this_val, argc, argv);
}
static JSValue gltf_texture_sampler_class_set_wrap_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFTextureSampler::set_wrap_s, ctx, this_val, argc, argv);
};
static JSValue gltf_texture_sampler_class_get_wrap_t(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFTextureSampler::get_wrap_t, ctx, this_val, argc, argv);
}
static JSValue gltf_texture_sampler_class_set_wrap_t(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFTextureSampler::set_wrap_t, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_texture_sampler_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_mag_filter", 0, &gltf_texture_sampler_class_get_mag_filter),
	JS_CFUNC_DEF("set_mag_filter", 1, &gltf_texture_sampler_class_set_mag_filter),
	JS_CFUNC_DEF("get_min_filter", 0, &gltf_texture_sampler_class_get_min_filter),
	JS_CFUNC_DEF("set_min_filter", 1, &gltf_texture_sampler_class_set_min_filter),
	JS_CFUNC_DEF("get_wrap_s", 0, &gltf_texture_sampler_class_get_wrap_s),
	JS_CFUNC_DEF("set_wrap_s", 1, &gltf_texture_sampler_class_set_wrap_s),
	JS_CFUNC_DEF("get_wrap_t", 0, &gltf_texture_sampler_class_get_wrap_t),
	JS_CFUNC_DEF("set_wrap_t", 1, &gltf_texture_sampler_class_set_wrap_t),
};




static void define_gltf_texture_sampler_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mag_filter"),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_get_mag_filter, "get_mag_filter", 0),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_set_mag_filter, "set_mag_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "min_filter"),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_get_min_filter, "get_min_filter", 0),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_set_min_filter, "set_min_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wrap_s"),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_get_wrap_s, "get_wrap_s", 0),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_set_wrap_s, "set_wrap_s", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wrap_t"),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_get_wrap_t, "get_wrap_t", 0),
        JS_NewCFunction(ctx, gltf_texture_sampler_class_set_wrap_t, "set_wrap_t", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_texture_sampler_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_texture_sampler_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFTextureSampler"] = class_id;
	classes_by_id[class_id] = "GLTFTextureSampler";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_texture_sampler_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_texture_sampler_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_texture_sampler_class_proto_funcs, _countof(gltf_texture_sampler_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_texture_sampler_class_constructor, "GLTFTextureSampler", 0, JS_CFUNC_constructor, 0);
	define_gltf_texture_sampler_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFTextureSampler", ctor);
	ctor_list["GLTFTextureSampler"] = ctor;

	return 0;
}

JSModuleDef *_js_init_gltf_texture_sampler_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_texture_sampler_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFTextureSampler");
	return m;
}

JSModuleDef *js_init_gltf_texture_sampler_module(JSContext *ctx) {
	return _js_init_gltf_texture_sampler_module(ctx, "@godot/classes/gltf_texture_sampler");
}

void __register_gltf_texture_sampler() {
	js_init_gltf_texture_sampler_module(js_context());
}

void register_gltf_texture_sampler() {
	__register_gltf_texture_sampler();
}