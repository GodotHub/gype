#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/parallax_layer.hpp>
using namespace godot;

static void parallax_layer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ParallaxLayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef parallax_layer_class_def = {
    "ParallaxLayer",
    parallax_layer_class_finalizer
};

static JSValue parallax_layer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ParallaxLayer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ParallaxLayer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ParallaxLayer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ParallaxLayer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue parallax_layer_class_set_motion_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxLayer::set_motion_scale, ctx, this_val, argc, argv);
};
static JSValue parallax_layer_class_get_motion_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxLayer *obj = static_cast<ParallaxLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_motion_scale();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxLayer *js_proxy = static_cast<ParallaxLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_motion_scale(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue parallax_layer_class_set_motion_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxLayer::set_motion_offset, ctx, this_val, argc, argv);
};
static JSValue parallax_layer_class_get_motion_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxLayer *obj = static_cast<ParallaxLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_motion_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxLayer *js_proxy = static_cast<ParallaxLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_motion_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue parallax_layer_class_set_mirroring(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ParallaxLayer::set_mirroring, ctx, this_val, argc, argv);
};
static JSValue parallax_layer_class_get_mirroring(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		ParallaxLayer *obj = static_cast<ParallaxLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_mirroring();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		ParallaxLayer *js_proxy = static_cast<ParallaxLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_mirroring(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry parallax_layer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_motion_scale", 1, &parallax_layer_class_set_motion_scale),
	JS_CFUNC_DEF("get_motion_scale", 0, &parallax_layer_class_get_motion_scale),
	JS_CFUNC_DEF("set_motion_offset", 1, &parallax_layer_class_set_motion_offset),
	JS_CFUNC_DEF("get_motion_offset", 0, &parallax_layer_class_get_motion_offset),
	JS_CFUNC_DEF("set_mirroring", 1, &parallax_layer_class_set_mirroring),
	JS_CFUNC_DEF("get_mirroring", 0, &parallax_layer_class_get_mirroring),
};




static void define_parallax_layer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion_scale"),
        JS_NewCFunction(ctx, parallax_layer_class_get_motion_scale, "get_motion_scale", 0),
        JS_NewCFunction(ctx, parallax_layer_class_set_motion_scale, "set_motion_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion_offset"),
        JS_NewCFunction(ctx, parallax_layer_class_get_motion_offset, "get_motion_offset", 0),
        JS_NewCFunction(ctx, parallax_layer_class_set_motion_offset, "set_motion_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion_mirroring"),
        JS_NewCFunction(ctx, parallax_layer_class_get_mirroring, "get_mirroring", 0),
        JS_NewCFunction(ctx, parallax_layer_class_set_mirroring, "set_mirroring", 1),
        JS_PROP_GETSET
    );
}

static void define_parallax_layer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_parallax_layer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ParallaxLayer"] = class_id;
	classes_by_id[class_id] = "ParallaxLayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &parallax_layer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_parallax_layer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, parallax_layer_class_proto_funcs, _countof(parallax_layer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, parallax_layer_class_constructor, "ParallaxLayer", 0, JS_CFUNC_constructor, 0);
	define_parallax_layer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ParallaxLayer", ctor);

	return 0;
}

JSModuleDef *_js_init_parallax_layer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_parallax_layer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ParallaxLayer");
	return m;
}

JSModuleDef *js_init_parallax_layer_module(JSContext *ctx) {
	return _js_init_parallax_layer_module(ctx, "@godot/classes/parallax_layer");
}

void __register_parallax_layer() {
	js_init_parallax_layer_module(js_context());
}

void register_parallax_layer() {
	__register_parallax_layer();
}