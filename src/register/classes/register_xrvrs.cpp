#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xrvrs.hpp>
using namespace godot;

static void xrvrs_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRVRS"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef xrvrs_class_def = {
    "XRVRS",
    xrvrs_class_finalizer
};

static JSValue xrvrs_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRVRS"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XRVRS *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XRVRS *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XRVRS);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xrvrs_class_get_vrs_min_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRVRS::get_vrs_min_radius, ctx, this_val, argc, argv);
}
static JSValue xrvrs_class_set_vrs_min_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRVRS::set_vrs_min_radius, ctx, this_val, argc, argv);
};
static JSValue xrvrs_class_get_vrs_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRVRS::get_vrs_strength, ctx, this_val, argc, argv);
}
static JSValue xrvrs_class_set_vrs_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRVRS::set_vrs_strength, ctx, this_val, argc, argv);
};
static JSValue xrvrs_class_get_vrs_render_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2i> *proxy = memnew(ObjectProxy<Rect2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2i {
		XRVRS *obj = static_cast<XRVRS *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_vrs_render_region();
	};
	proxy->setter = [this_val](const Rect2i &value) -> void {
		XRVRS *js_proxy = static_cast<XRVRS *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_vrs_render_region(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue xrvrs_class_set_vrs_render_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRVRS::set_vrs_render_region, ctx, this_val, argc, argv);
};
static JSValue xrvrs_class_make_vrs_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRVRS::make_vrs_texture, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xrvrs_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_vrs_min_radius", 0, &xrvrs_class_get_vrs_min_radius),
	JS_CFUNC_DEF("set_vrs_min_radius", 1, &xrvrs_class_set_vrs_min_radius),
	JS_CFUNC_DEF("get_vrs_strength", 0, &xrvrs_class_get_vrs_strength),
	JS_CFUNC_DEF("set_vrs_strength", 1, &xrvrs_class_set_vrs_strength),
	JS_CFUNC_DEF("get_vrs_render_region", 0, &xrvrs_class_get_vrs_render_region),
	JS_CFUNC_DEF("set_vrs_render_region", 1, &xrvrs_class_set_vrs_render_region),
	JS_CFUNC_DEF("make_vrs_texture", 2, &xrvrs_class_make_vrs_texture),
};




static void define_xrvrs_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_min_radius"),
        JS_NewCFunction(ctx, xrvrs_class_get_vrs_min_radius, "get_vrs_min_radius", 0),
        JS_NewCFunction(ctx, xrvrs_class_set_vrs_min_radius, "set_vrs_min_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_strength"),
        JS_NewCFunction(ctx, xrvrs_class_get_vrs_strength, "get_vrs_strength", 0),
        JS_NewCFunction(ctx, xrvrs_class_set_vrs_strength, "set_vrs_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_render_region"),
        JS_NewCFunction(ctx, xrvrs_class_get_vrs_render_region, "get_vrs_render_region", 0),
        JS_NewCFunction(ctx, xrvrs_class_set_vrs_render_region, "set_vrs_render_region", 1),
        JS_PROP_GETSET
    );
}

static void define_xrvrs_enum(JSContext *ctx, JSValue ctor) {
}

static int js_xrvrs_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRVRS"] = class_id;
	classes_by_id[class_id] = "XRVRS";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xrvrs_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xrvrs_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xrvrs_class_proto_funcs, _countof(xrvrs_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xrvrs_class_constructor, "XRVRS", 0, JS_CFUNC_constructor, 0);
	define_xrvrs_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRVRS", ctor);

	return 0;
}

JSModuleDef *_js_init_xrvrs_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xrvrs_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRVRS");
	return m;
}

JSModuleDef *js_init_xrvrs_module(JSContext *ctx) {
	return _js_init_xrvrs_module(ctx, "@godot/classes/xrvrs");
}

void __register_xrvrs() {
	js_init_xrvrs_module(js_context());
}

void register_xrvrs() {
	__register_xrvrs();
}