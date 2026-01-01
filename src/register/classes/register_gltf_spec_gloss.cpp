#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_spec_gloss.hpp>
using namespace godot;

static void gltf_spec_gloss_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFSpecGloss"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_spec_gloss_class_def = {
    "GLTFSpecGloss",
    gltf_spec_gloss_class_finalizer
};

static JSValue gltf_spec_gloss_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFSpecGloss"];
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
        instance = memnew(GLTFSpecGloss);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_spec_gloss_class_get_diffuse_img(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSpecGloss::get_diffuse_img, ctx, this_val, argc, argv);
}
static JSValue gltf_spec_gloss_class_set_diffuse_img(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSpecGloss::set_diffuse_img, ctx, this_val, argc, argv);
};
static JSValue gltf_spec_gloss_class_get_diffuse_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		GLTFSpecGloss *obj = static_cast<GLTFSpecGloss *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_diffuse_factor();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		GLTFSpecGloss *js_proxy = static_cast<GLTFSpecGloss *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_diffuse_factor(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_spec_gloss_class_set_diffuse_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSpecGloss::set_diffuse_factor, ctx, this_val, argc, argv);
};
static JSValue gltf_spec_gloss_class_get_gloss_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSpecGloss::get_gloss_factor, ctx, this_val, argc, argv);
}
static JSValue gltf_spec_gloss_class_set_gloss_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSpecGloss::set_gloss_factor, ctx, this_val, argc, argv);
};
static JSValue gltf_spec_gloss_class_get_specular_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		GLTFSpecGloss *obj = static_cast<GLTFSpecGloss *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_specular_factor();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		GLTFSpecGloss *js_proxy = static_cast<GLTFSpecGloss *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_specular_factor(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_spec_gloss_class_set_specular_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSpecGloss::set_specular_factor, ctx, this_val, argc, argv);
};
static JSValue gltf_spec_gloss_class_get_spec_gloss_img(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSpecGloss::get_spec_gloss_img, ctx, this_val, argc, argv);
}
static JSValue gltf_spec_gloss_class_set_spec_gloss_img(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSpecGloss::set_spec_gloss_img, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_spec_gloss_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_diffuse_img", 0, &gltf_spec_gloss_class_get_diffuse_img),
	JS_CFUNC_DEF("set_diffuse_img", 1, &gltf_spec_gloss_class_set_diffuse_img),
	JS_CFUNC_DEF("get_diffuse_factor", 0, &gltf_spec_gloss_class_get_diffuse_factor),
	JS_CFUNC_DEF("set_diffuse_factor", 1, &gltf_spec_gloss_class_set_diffuse_factor),
	JS_CFUNC_DEF("get_gloss_factor", 0, &gltf_spec_gloss_class_get_gloss_factor),
	JS_CFUNC_DEF("set_gloss_factor", 1, &gltf_spec_gloss_class_set_gloss_factor),
	JS_CFUNC_DEF("get_specular_factor", 0, &gltf_spec_gloss_class_get_specular_factor),
	JS_CFUNC_DEF("set_specular_factor", 1, &gltf_spec_gloss_class_set_specular_factor),
	JS_CFUNC_DEF("get_spec_gloss_img", 0, &gltf_spec_gloss_class_get_spec_gloss_img),
	JS_CFUNC_DEF("set_spec_gloss_img", 1, &gltf_spec_gloss_class_set_spec_gloss_img),
};




static void define_gltf_spec_gloss_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "diffuse_img"),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_get_diffuse_img, "get_diffuse_img", 0),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_set_diffuse_img, "set_diffuse_img", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "diffuse_factor"),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_get_diffuse_factor, "get_diffuse_factor", 0),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_set_diffuse_factor, "set_diffuse_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gloss_factor"),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_get_gloss_factor, "get_gloss_factor", 0),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_set_gloss_factor, "set_gloss_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "specular_factor"),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_get_specular_factor, "get_specular_factor", 0),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_set_specular_factor, "set_specular_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spec_gloss_img"),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_get_spec_gloss_img, "get_spec_gloss_img", 0),
        JS_NewCFunction(ctx, gltf_spec_gloss_class_set_spec_gloss_img, "set_spec_gloss_img", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_spec_gloss_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_spec_gloss_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFSpecGloss"] = class_id;
	classes_by_id[class_id] = "GLTFSpecGloss";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_spec_gloss_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_spec_gloss_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_spec_gloss_class_proto_funcs, _countof(gltf_spec_gloss_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_spec_gloss_class_constructor, "GLTFSpecGloss", 0, JS_CFUNC_constructor, 0);
	define_gltf_spec_gloss_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFSpecGloss", ctor);
	ctor_list["GLTFSpecGloss"] = ctor;

	return 0;
}

JSModuleDef *_js_init_gltf_spec_gloss_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_spec_gloss_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFSpecGloss");
	return m;
}

JSModuleDef *js_init_gltf_spec_gloss_module(JSContext *ctx) {
	return _js_init_gltf_spec_gloss_module(ctx, "@godot/classes/gltf_spec_gloss");
}

void __register_gltf_spec_gloss() {
	js_init_gltf_spec_gloss_module(js_context());
}

void register_gltf_spec_gloss() {
	__register_gltf_spec_gloss();
}