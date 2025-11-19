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
#include <godot_cpp/classes/gltf_animation.hpp>
using namespace godot;

static void gltf_animation_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFAnimation"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_animation_class_def = {
    "GLTFAnimation",
    gltf_animation_class_finalizer
};

static JSValue gltf_animation_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFAnimation"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFAnimation *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFAnimation *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFAnimation);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_animation_class_get_original_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFAnimation::get_original_name, ctx, this_val, argc, argv);
}
static JSValue gltf_animation_class_set_original_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAnimation::set_original_name, ctx, this_val, argc, argv);
};
static JSValue gltf_animation_class_get_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAnimation::get_loop, ctx, this_val, argc, argv);
}
static JSValue gltf_animation_class_set_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAnimation::set_loop, ctx, this_val, argc, argv);
};
static JSValue gltf_animation_class_get_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFAnimation::get_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_animation_class_set_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAnimation::set_additional_data, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_animation_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_original_name", 0, &gltf_animation_class_get_original_name),
	JS_CFUNC_DEF("set_original_name", 1, &gltf_animation_class_set_original_name),
	JS_CFUNC_DEF("get_loop", 0, &gltf_animation_class_get_loop),
	JS_CFUNC_DEF("set_loop", 1, &gltf_animation_class_set_loop),
	JS_CFUNC_DEF("get_additional_data", 1, &gltf_animation_class_get_additional_data),
	JS_CFUNC_DEF("set_additional_data", 2, &gltf_animation_class_set_additional_data),
};




static void define_gltf_animation_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "original_name"),
        JS_NewCFunction(ctx, gltf_animation_class_get_original_name, "get_original_name", 0),
        JS_NewCFunction(ctx, gltf_animation_class_set_original_name, "set_original_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop"),
        JS_NewCFunction(ctx, gltf_animation_class_get_loop, "get_loop", 0),
        JS_NewCFunction(ctx, gltf_animation_class_set_loop, "set_loop", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_animation_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_animation_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFAnimation"] = class_id;
	classes_by_id[class_id] = "GLTFAnimation";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_animation_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_animation_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_animation_class_proto_funcs, _countof(gltf_animation_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_animation_class_constructor, "GLTFAnimation", 0, JS_CFUNC_constructor, 0);
	define_gltf_animation_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFAnimation", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_animation_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_animation_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFAnimation");
	return m;
}

JSModuleDef *js_init_gltf_animation_module(JSContext *ctx) {
	return _js_init_gltf_animation_module(ctx, "@godot/classes/gltf_animation");
}

void __register_gltf_animation() {
	js_init_gltf_animation_module(js_context());
}

void register_gltf_animation() {
	__register_gltf_animation();
}