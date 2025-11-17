#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gradient.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gradient_texture2d.hpp>
using namespace godot;

static void gradient_texture2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GradientTexture2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gradient_texture2d_class_def = {
    "GradientTexture2D",
    gradient_texture2d_class_finalizer
};

static JSValue gradient_texture2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GradientTexture2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GradientTexture2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GradientTexture2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GradientTexture2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gradient_texture2d_class_set_gradient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_gradient, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_get_gradient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GradientTexture2D::get_gradient, ctx, this_val, argc, argv);
}
static JSValue gradient_texture2d_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_width, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_height, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_set_use_hdr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_use_hdr, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_is_using_hdr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GradientTexture2D::is_using_hdr, ctx, this_val, argc, argv);
}
static JSValue gradient_texture2d_class_set_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_fill, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_get_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GradientTexture2D::get_fill, ctx, this_val, argc, argv);
}
static JSValue gradient_texture2d_class_set_fill_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_fill_from, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_get_fill_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		GradientTexture2D *obj = static_cast<GradientTexture2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_fill_from();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		GradientTexture2D *js_proxy = static_cast<GradientTexture2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_fill_from(value);
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
static JSValue gradient_texture2d_class_set_fill_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_fill_to, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_get_fill_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		GradientTexture2D *obj = static_cast<GradientTexture2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_fill_to();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		GradientTexture2D *js_proxy = static_cast<GradientTexture2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_fill_to(value);
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
static JSValue gradient_texture2d_class_set_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture2D::set_repeat, ctx, this_val, argc, argv);
};
static JSValue gradient_texture2d_class_get_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GradientTexture2D::get_repeat, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry gradient_texture2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_gradient", 1, &gradient_texture2d_class_set_gradient),
	JS_CFUNC_DEF("get_gradient", 0, &gradient_texture2d_class_get_gradient),
	JS_CFUNC_DEF("set_width", 1, &gradient_texture2d_class_set_width),
	JS_CFUNC_DEF("set_height", 1, &gradient_texture2d_class_set_height),
	JS_CFUNC_DEF("set_use_hdr", 1, &gradient_texture2d_class_set_use_hdr),
	JS_CFUNC_DEF("is_using_hdr", 0, &gradient_texture2d_class_is_using_hdr),
	JS_CFUNC_DEF("set_fill", 1, &gradient_texture2d_class_set_fill),
	JS_CFUNC_DEF("get_fill", 0, &gradient_texture2d_class_get_fill),
	JS_CFUNC_DEF("set_fill_from", 1, &gradient_texture2d_class_set_fill_from),
	JS_CFUNC_DEF("get_fill_from", 0, &gradient_texture2d_class_get_fill_from),
	JS_CFUNC_DEF("set_fill_to", 1, &gradient_texture2d_class_set_fill_to),
	JS_CFUNC_DEF("get_fill_to", 0, &gradient_texture2d_class_get_fill_to),
	JS_CFUNC_DEF("set_repeat", 1, &gradient_texture2d_class_set_repeat),
	JS_CFUNC_DEF("get_repeat", 0, &gradient_texture2d_class_get_repeat),
};




static void define_gradient_texture2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gradient"),
        JS_NewCFunction(ctx, gradient_texture2d_class_get_gradient, "get_gradient", 0),
        JS_NewCFunction(ctx, gradient_texture2d_class_set_gradient, "set_gradient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, gradient_texture2d_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, gradient_texture2d_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_hdr"),
        JS_NewCFunction(ctx, gradient_texture2d_class_is_using_hdr, "is_using_hdr", 0),
        JS_NewCFunction(ctx, gradient_texture2d_class_set_use_hdr, "set_use_hdr", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fill"),
        JS_NewCFunction(ctx, gradient_texture2d_class_get_fill, "get_fill", 0),
        JS_NewCFunction(ctx, gradient_texture2d_class_set_fill, "set_fill", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fill_from"),
        JS_NewCFunction(ctx, gradient_texture2d_class_get_fill_from, "get_fill_from", 0),
        JS_NewCFunction(ctx, gradient_texture2d_class_set_fill_from, "set_fill_from", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fill_to"),
        JS_NewCFunction(ctx, gradient_texture2d_class_get_fill_to, "get_fill_to", 0),
        JS_NewCFunction(ctx, gradient_texture2d_class_set_fill_to, "set_fill_to", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "repeat"),
        JS_NewCFunction(ctx, gradient_texture2d_class_get_repeat, "get_repeat", 0),
        JS_NewCFunction(ctx, gradient_texture2d_class_set_repeat, "set_repeat", 1),
        JS_PROP_GETSET
    );
}

static void define_gradient_texture2d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Fill_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Fill_obj, "FILL_LINEAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Fill_obj, "FILL_RADIAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Fill_obj, "FILL_SQUARE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Fill", Fill_obj);
	JSValue Repeat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Repeat_obj, "REPEAT_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Repeat_obj, "REPEAT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Repeat_obj, "REPEAT_MIRROR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Repeat", Repeat_obj);
}

static int js_gradient_texture2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GradientTexture2D"] = class_id;
	classes_by_id[class_id] = "GradientTexture2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gradient_texture2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gradient_texture2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gradient_texture2d_class_proto_funcs, _countof(gradient_texture2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gradient_texture2d_class_constructor, "GradientTexture2D", 0, JS_CFUNC_constructor, 0);
	define_gradient_texture2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GradientTexture2D", ctor);

	return 0;
}

JSModuleDef *_js_init_gradient_texture2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gradient_texture2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GradientTexture2D");
	return m;
}

JSModuleDef *js_init_gradient_texture2d_module(JSContext *ctx) {
	return _js_init_gradient_texture2d_module(ctx, "@godot/classes/gradient_texture2d");
}

void __register_gradient_texture2d() {
	js_init_gradient_texture2d_module(js_context());
}

void register_gradient_texture2d() {
	__register_gradient_texture2d();
}