#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/dpi_texture.hpp>
using namespace godot;

static void dpi_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["DPITexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef dpi_texture_class_def = {
    "DPITexture",
    dpi_texture_class_finalizer
};

static JSValue dpi_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["DPITexture"];
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
        instance = memnew(DPITexture);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue dpi_texture_class_set_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DPITexture::set_source, ctx, this_val, argc, argv);
};
static JSValue dpi_texture_class_get_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DPITexture::get_source, ctx, this_val, argc, argv);
};
static JSValue dpi_texture_class_set_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DPITexture::set_base_scale, ctx, this_val, argc, argv);
};
static JSValue dpi_texture_class_get_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DPITexture::get_base_scale, ctx, this_val, argc, argv);
}
static JSValue dpi_texture_class_set_saturation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DPITexture::set_saturation, ctx, this_val, argc, argv);
};
static JSValue dpi_texture_class_get_saturation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DPITexture::get_saturation, ctx, this_val, argc, argv);
}
static JSValue dpi_texture_class_set_color_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DPITexture::set_color_map, ctx, this_val, argc, argv);
};
static JSValue dpi_texture_class_get_color_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DPITexture::get_color_map, ctx, this_val, argc, argv);
}
static JSValue dpi_texture_class_set_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DPITexture::set_size_override, ctx, this_val, argc, argv);
};
static JSValue dpi_texture_class_get_scaled_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DPITexture::get_scaled_rid, ctx, this_val, argc, argv);
};


static JSValue dpi_texture_class_create_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&DPITexture::create_from_string, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry dpi_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_source", 1, &dpi_texture_class_set_source),
	JS_CFUNC_DEF("get_source", 0, &dpi_texture_class_get_source),
	JS_CFUNC_DEF("set_base_scale", 1, &dpi_texture_class_set_base_scale),
	JS_CFUNC_DEF("get_base_scale", 0, &dpi_texture_class_get_base_scale),
	JS_CFUNC_DEF("set_saturation", 1, &dpi_texture_class_set_saturation),
	JS_CFUNC_DEF("get_saturation", 0, &dpi_texture_class_get_saturation),
	JS_CFUNC_DEF("set_color_map", 1, &dpi_texture_class_set_color_map),
	JS_CFUNC_DEF("get_color_map", 0, &dpi_texture_class_get_color_map),
	JS_CFUNC_DEF("set_size_override", 1, &dpi_texture_class_set_size_override),
	JS_CFUNC_DEF("get_scaled_rid", 0, &dpi_texture_class_get_scaled_rid),
};

static const JSCFunctionListEntry dpi_texture_class_static_funcs[] = {
	JS_CFUNC_DEF("create_from_string", 4, &dpi_texture_class_create_from_string),
};



static void define_dpi_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "base_scale"),
        JS_NewCFunction(ctx, dpi_texture_class_get_base_scale, "get_base_scale", 0),
        JS_NewCFunction(ctx, dpi_texture_class_set_base_scale, "set_base_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "saturation"),
        JS_NewCFunction(ctx, dpi_texture_class_get_saturation, "get_saturation", 0),
        JS_NewCFunction(ctx, dpi_texture_class_set_saturation, "set_saturation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_map"),
        JS_NewCFunction(ctx, dpi_texture_class_get_color_map, "get_color_map", 0),
        JS_NewCFunction(ctx, dpi_texture_class_set_color_map, "set_color_map", 1),
        JS_PROP_GETSET
    );
}

static void define_dpi_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_dpi_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["DPITexture"] = class_id;
	classes_by_id[class_id] = "DPITexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &dpi_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_dpi_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, dpi_texture_class_proto_funcs, _countof(dpi_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, dpi_texture_class_constructor, "DPITexture", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, dpi_texture_class_static_funcs, _countof(dpi_texture_class_static_funcs));
	define_dpi_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "DPITexture", ctor);
	ctor_list["DPITexture"] = ctor;

	return 0;
}

JSModuleDef *_js_init_dpi_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_dpi_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "DPITexture");
	return m;
}

JSModuleDef *js_init_dpi_texture_module(JSContext *ctx) {
	return _js_init_dpi_texture_module(ctx, "@godot/classes/dpi_texture");
}

void __register_dpi_texture() {
	js_init_dpi_texture_module(js_context());
}

void register_dpi_texture() {
	__register_dpi_texture();
}