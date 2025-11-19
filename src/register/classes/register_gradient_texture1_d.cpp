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
#include <godot_cpp/classes/gradient_texture1_d.hpp>
using namespace godot;

static void gradient_texture1_d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GradientTexture1D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gradient_texture1_d_class_def = {
    "GradientTexture1D",
    gradient_texture1_d_class_finalizer
};

static JSValue gradient_texture1_d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GradientTexture1D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GradientTexture1D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GradientTexture1D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GradientTexture1D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gradient_texture1_d_class_set_gradient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture1D::set_gradient, ctx, this_val, argc, argv);
};
static JSValue gradient_texture1_d_class_get_gradient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GradientTexture1D::get_gradient, ctx, this_val, argc, argv);
}
static JSValue gradient_texture1_d_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture1D::set_width, ctx, this_val, argc, argv);
};
static JSValue gradient_texture1_d_class_set_use_hdr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GradientTexture1D::set_use_hdr, ctx, this_val, argc, argv);
};
static JSValue gradient_texture1_d_class_is_using_hdr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GradientTexture1D::is_using_hdr, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry gradient_texture1_d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_gradient", 1, &gradient_texture1_d_class_set_gradient),
	JS_CFUNC_DEF("get_gradient", 0, &gradient_texture1_d_class_get_gradient),
	JS_CFUNC_DEF("set_width", 1, &gradient_texture1_d_class_set_width),
	JS_CFUNC_DEF("set_use_hdr", 1, &gradient_texture1_d_class_set_use_hdr),
	JS_CFUNC_DEF("is_using_hdr", 0, &gradient_texture1_d_class_is_using_hdr),
};




static void define_gradient_texture1_d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gradient"),
        JS_NewCFunction(ctx, gradient_texture1_d_class_get_gradient, "get_gradient", 0),
        JS_NewCFunction(ctx, gradient_texture1_d_class_set_gradient, "set_gradient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, gradient_texture1_d_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_hdr"),
        JS_NewCFunction(ctx, gradient_texture1_d_class_is_using_hdr, "is_using_hdr", 0),
        JS_NewCFunction(ctx, gradient_texture1_d_class_set_use_hdr, "set_use_hdr", 1),
        JS_PROP_GETSET
    );
}

static void define_gradient_texture1_d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gradient_texture1_d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GradientTexture1D"] = class_id;
	classes_by_id[class_id] = "GradientTexture1D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gradient_texture1_d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gradient_texture1_d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gradient_texture1_d_class_proto_funcs, _countof(gradient_texture1_d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gradient_texture1_d_class_constructor, "GradientTexture1D", 0, JS_CFUNC_constructor, 0);
	define_gradient_texture1_d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GradientTexture1D", ctor);

	return 0;
}

JSModuleDef *_js_init_gradient_texture1_d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gradient_texture1_d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GradientTexture1D");
	return m;
}

JSModuleDef *js_init_gradient_texture1_d_module(JSContext *ctx) {
	return _js_init_gradient_texture1_d_module(ctx, "@godot/classes/gradient_texture1_d");
}

void __register_gradient_texture1_d() {
	js_init_gradient_texture1_d_module(js_context());
}

void register_gradient_texture1_d() {
	__register_gradient_texture1_d();
}