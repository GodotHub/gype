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
#include <godot_cpp/classes/curve_xyz_texture.hpp>
using namespace godot;

static void curve_xyz_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CurveXYZTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef curve_xyz_texture_class_def = {
    "CurveXYZTexture",
    curve_xyz_texture_class_finalizer
};

static JSValue curve_xyz_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CurveXYZTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CurveXYZTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CurveXYZTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CurveXYZTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue curve_xyz_texture_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveXYZTexture::set_width, ctx, this_val, argc, argv);
};
static JSValue curve_xyz_texture_class_set_curve_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveXYZTexture::set_curve_x, ctx, this_val, argc, argv);
};
static JSValue curve_xyz_texture_class_get_curve_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CurveXYZTexture::get_curve_x, ctx, this_val, argc, argv);
}
static JSValue curve_xyz_texture_class_set_curve_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveXYZTexture::set_curve_y, ctx, this_val, argc, argv);
};
static JSValue curve_xyz_texture_class_get_curve_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CurveXYZTexture::get_curve_y, ctx, this_val, argc, argv);
}
static JSValue curve_xyz_texture_class_set_curve_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CurveXYZTexture::set_curve_z, ctx, this_val, argc, argv);
};
static JSValue curve_xyz_texture_class_get_curve_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CurveXYZTexture::get_curve_z, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry curve_xyz_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_width", 1, &curve_xyz_texture_class_set_width),
	JS_CFUNC_DEF("set_curve_x", 1, &curve_xyz_texture_class_set_curve_x),
	JS_CFUNC_DEF("get_curve_x", 0, &curve_xyz_texture_class_get_curve_x),
	JS_CFUNC_DEF("set_curve_y", 1, &curve_xyz_texture_class_set_curve_y),
	JS_CFUNC_DEF("get_curve_y", 0, &curve_xyz_texture_class_get_curve_y),
	JS_CFUNC_DEF("set_curve_z", 1, &curve_xyz_texture_class_set_curve_z),
	JS_CFUNC_DEF("get_curve_z", 0, &curve_xyz_texture_class_get_curve_z),
};




static void define_curve_xyz_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, curve_xyz_texture_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "curve_x"),
        JS_NewCFunction(ctx, curve_xyz_texture_class_get_curve_x, "get_curve_x", 0),
        JS_NewCFunction(ctx, curve_xyz_texture_class_set_curve_x, "set_curve_x", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "curve_y"),
        JS_NewCFunction(ctx, curve_xyz_texture_class_get_curve_y, "get_curve_y", 0),
        JS_NewCFunction(ctx, curve_xyz_texture_class_set_curve_y, "set_curve_y", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "curve_z"),
        JS_NewCFunction(ctx, curve_xyz_texture_class_get_curve_z, "get_curve_z", 0),
        JS_NewCFunction(ctx, curve_xyz_texture_class_set_curve_z, "set_curve_z", 1),
        JS_PROP_GETSET
    );
}

static void define_curve_xyz_texture_enum(JSContext *ctx, JSValue proto) {
}

static int js_curve_xyz_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CurveXYZTexture"] = class_id;
	classes_by_id[class_id] = "CurveXYZTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &curve_xyz_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_curve_xyz_texture_property(ctx, proto);
	define_curve_xyz_texture_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, curve_xyz_texture_class_proto_funcs, _countof(curve_xyz_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, curve_xyz_texture_class_constructor, "CurveXYZTexture", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CurveXYZTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_curve_xyz_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_curve_xyz_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CurveXYZTexture");
	return m;
}

JSModuleDef *js_init_curve_xyz_texture_module(JSContext *ctx) {
	return _js_init_curve_xyz_texture_module(ctx, "@godot/classes/curve_xyz_texture");
}

void __register_curve_xyz_texture() {
	js_init_curve_xyz_texture_module(js_context());
}

void register_curve_xyz_texture() {
	__register_curve_xyz_texture();
}