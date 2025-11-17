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
#include <godot_cpp/classes/atlas_texture.hpp>
using namespace godot;

static void atlas_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AtlasTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef atlas_texture_class_def = {
    "AtlasTexture",
    atlas_texture_class_finalizer
};

static JSValue atlas_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AtlasTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AtlasTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AtlasTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AtlasTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue atlas_texture_class_set_atlas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AtlasTexture::set_atlas, ctx, this_val, argc, argv);
};
static JSValue atlas_texture_class_get_atlas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AtlasTexture::get_atlas, ctx, this_val, argc, argv);
}
static JSValue atlas_texture_class_set_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AtlasTexture::set_region, ctx, this_val, argc, argv);
};
static JSValue atlas_texture_class_get_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		AtlasTexture *obj = static_cast<AtlasTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_region();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		AtlasTexture *js_proxy = static_cast<AtlasTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_region(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue atlas_texture_class_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AtlasTexture::set_margin, ctx, this_val, argc, argv);
};
static JSValue atlas_texture_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		AtlasTexture *obj = static_cast<AtlasTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_margin();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		AtlasTexture *js_proxy = static_cast<AtlasTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_margin(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue atlas_texture_class_set_filter_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AtlasTexture::set_filter_clip, ctx, this_val, argc, argv);
};
static JSValue atlas_texture_class_has_filter_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AtlasTexture::has_filter_clip, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry atlas_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_atlas", 1, &atlas_texture_class_set_atlas),
	JS_CFUNC_DEF("get_atlas", 0, &atlas_texture_class_get_atlas),
	JS_CFUNC_DEF("set_region", 1, &atlas_texture_class_set_region),
	JS_CFUNC_DEF("get_region", 0, &atlas_texture_class_get_region),
	JS_CFUNC_DEF("set_margin", 1, &atlas_texture_class_set_margin),
	JS_CFUNC_DEF("get_margin", 0, &atlas_texture_class_get_margin),
	JS_CFUNC_DEF("set_filter_clip", 1, &atlas_texture_class_set_filter_clip),
	JS_CFUNC_DEF("has_filter_clip", 0, &atlas_texture_class_has_filter_clip),
};




static void define_atlas_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "atlas"),
        JS_NewCFunction(ctx, atlas_texture_class_get_atlas, "get_atlas", 0),
        JS_NewCFunction(ctx, atlas_texture_class_set_atlas, "set_atlas", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region"),
        JS_NewCFunction(ctx, atlas_texture_class_get_region, "get_region", 0),
        JS_NewCFunction(ctx, atlas_texture_class_set_region, "set_region", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margin"),
        JS_NewCFunction(ctx, atlas_texture_class_get_margin, "get_margin", 0),
        JS_NewCFunction(ctx, atlas_texture_class_set_margin, "set_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter_clip"),
        JS_NewCFunction(ctx, atlas_texture_class_has_filter_clip, "has_filter_clip", 0),
        JS_NewCFunction(ctx, atlas_texture_class_set_filter_clip, "set_filter_clip", 1),
        JS_PROP_GETSET
    );
}

static void define_atlas_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_atlas_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AtlasTexture"] = class_id;
	classes_by_id[class_id] = "AtlasTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &atlas_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_atlas_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, atlas_texture_class_proto_funcs, _countof(atlas_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, atlas_texture_class_constructor, "AtlasTexture", 0, JS_CFUNC_constructor, 0);
	define_atlas_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AtlasTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_atlas_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_atlas_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AtlasTexture");
	return m;
}

JSModuleDef *js_init_atlas_texture_module(JSContext *ctx) {
	return _js_init_atlas_texture_module(ctx, "@godot/classes/atlas_texture");
}

void __register_atlas_texture() {
	js_init_atlas_texture_module(js_context());
}

void register_atlas_texture() {
	__register_atlas_texture();
}