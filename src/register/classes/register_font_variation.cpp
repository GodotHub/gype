#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/font_variation.hpp>
using namespace godot;

static void font_variation_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FontVariation"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef font_variation_class_def = {
    "FontVariation",
    font_variation_class_finalizer
};

static JSValue font_variation_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FontVariation"];
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
        instance = memnew(FontVariation);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue font_variation_class_set_base_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_base_font, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_get_base_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontVariation::get_base_font, ctx, this_val, argc, argv);
}
static JSValue font_variation_class_set_variation_opentype(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_variation_opentype, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_get_variation_opentype(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		FontVariation *obj = static_cast<FontVariation *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_variation_opentype();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		FontVariation *js_proxy = static_cast<FontVariation *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_variation_opentype(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue font_variation_class_set_variation_embolden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_variation_embolden, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_get_variation_embolden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontVariation::get_variation_embolden, ctx, this_val, argc, argv);
}
static JSValue font_variation_class_set_variation_face_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_variation_face_index, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_get_variation_face_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontVariation::get_variation_face_index, ctx, this_val, argc, argv);
}
static JSValue font_variation_class_set_variation_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_variation_transform, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_get_variation_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform2D> *proxy = memnew(ObjectProxy<Transform2D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform2D {
		FontVariation *obj = static_cast<FontVariation *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_variation_transform();
	};
	proxy->setter = [this_val](const Transform2D &value) -> void {
		FontVariation *js_proxy = static_cast<FontVariation *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_variation_transform(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform2DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform2DProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue font_variation_class_set_opentype_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_opentype_features, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_set_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_spacing, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_set_baseline_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FontVariation::set_baseline_offset, ctx, this_val, argc, argv);
};
static JSValue font_variation_class_get_baseline_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FontVariation::get_baseline_offset, ctx, this_val, argc, argv);
}

static JSValue font_variation_class_get_spacing_glyph(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FontVariation::get_spacing, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue font_variation_class_set_spacing_glyph(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FontVariation::set_spacing, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue font_variation_class_get_spacing_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FontVariation::get_spacing, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue font_variation_class_set_spacing_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FontVariation::set_spacing, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue font_variation_class_get_spacing_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FontVariation::get_spacing, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue font_variation_class_set_spacing_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FontVariation::set_spacing, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue font_variation_class_get_spacing_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FontVariation::get_spacing, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue font_variation_class_set_spacing_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FontVariation::set_spacing, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry font_variation_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_base_font", 1, &font_variation_class_set_base_font),
	JS_CFUNC_DEF("get_base_font", 0, &font_variation_class_get_base_font),
	JS_CFUNC_DEF("set_variation_opentype", 1, &font_variation_class_set_variation_opentype),
	JS_CFUNC_DEF("get_variation_opentype", 0, &font_variation_class_get_variation_opentype),
	JS_CFUNC_DEF("set_variation_embolden", 1, &font_variation_class_set_variation_embolden),
	JS_CFUNC_DEF("get_variation_embolden", 0, &font_variation_class_get_variation_embolden),
	JS_CFUNC_DEF("set_variation_face_index", 1, &font_variation_class_set_variation_face_index),
	JS_CFUNC_DEF("get_variation_face_index", 0, &font_variation_class_get_variation_face_index),
	JS_CFUNC_DEF("set_variation_transform", 1, &font_variation_class_set_variation_transform),
	JS_CFUNC_DEF("get_variation_transform", 0, &font_variation_class_get_variation_transform),
	JS_CFUNC_DEF("set_opentype_features", 1, &font_variation_class_set_opentype_features),
	JS_CFUNC_DEF("set_spacing", 2, &font_variation_class_set_spacing),
	JS_CFUNC_DEF("set_baseline_offset", 1, &font_variation_class_set_baseline_offset),
	JS_CFUNC_DEF("get_baseline_offset", 0, &font_variation_class_get_baseline_offset),
    JS_CFUNC_MAGIC_DEF("get_spacing_space", 0, &font_variation_class_get_spacing_space, 1),
    JS_CFUNC_MAGIC_DEF("set_spacing_space", 1, &font_variation_class_set_spacing_space, 1),
    JS_CFUNC_MAGIC_DEF("get_spacing_top", 0, &font_variation_class_get_spacing_top, 2),
    JS_CFUNC_MAGIC_DEF("set_spacing_top", 1, &font_variation_class_set_spacing_top, 2),
    JS_CFUNC_MAGIC_DEF("get_spacing_bottom", 0, &font_variation_class_get_spacing_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_spacing_bottom", 1, &font_variation_class_set_spacing_bottom, 3),
};




static void define_font_variation_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "base_font"),
        JS_NewCFunction(ctx, font_variation_class_get_base_font, "get_base_font", 0),
        JS_NewCFunction(ctx, font_variation_class_set_base_font, "set_base_font", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "variation_opentype"),
        JS_NewCFunction(ctx, font_variation_class_get_variation_opentype, "get_variation_opentype", 0),
        JS_NewCFunction(ctx, font_variation_class_set_variation_opentype, "set_variation_opentype", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "variation_face_index"),
        JS_NewCFunction(ctx, font_variation_class_get_variation_face_index, "get_variation_face_index", 0),
        JS_NewCFunction(ctx, font_variation_class_set_variation_face_index, "set_variation_face_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "variation_embolden"),
        JS_NewCFunction(ctx, font_variation_class_get_variation_embolden, "get_variation_embolden", 0),
        JS_NewCFunction(ctx, font_variation_class_set_variation_embolden, "set_variation_embolden", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "variation_transform"),
        JS_NewCFunction(ctx, font_variation_class_get_variation_transform, "get_variation_transform", 0),
        JS_NewCFunction(ctx, font_variation_class_set_variation_transform, "set_variation_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "opentype_features"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, font_variation_class_set_opentype_features, "set_opentype_features", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "spacing_glyph"),
		JS_NewCFunctionMagic(ctx, font_variation_class_get_spacing_glyph, "get_spacing_glyph", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, font_variation_class_set_spacing_glyph, "set_spacing_glyph", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "spacing_space"),
		JS_NewCFunctionMagic(ctx, font_variation_class_get_spacing_space, "get_spacing_space", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, font_variation_class_set_spacing_space, "set_spacing_space", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "spacing_top"),
		JS_NewCFunctionMagic(ctx, font_variation_class_get_spacing_top, "get_spacing_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, font_variation_class_set_spacing_top, "set_spacing_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "spacing_bottom"),
		JS_NewCFunctionMagic(ctx, font_variation_class_get_spacing_bottom, "get_spacing_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, font_variation_class_set_spacing_bottom, "set_spacing_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "baseline_offset"),
        JS_NewCFunction(ctx, font_variation_class_get_baseline_offset, "get_baseline_offset", 0),
        JS_NewCFunction(ctx, font_variation_class_set_baseline_offset, "set_baseline_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_font_variation_enum(JSContext *ctx, JSValue ctor) {
}

static int js_font_variation_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FontVariation"] = class_id;
	classes_by_id[class_id] = "FontVariation";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &font_variation_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Font"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_font_variation_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, font_variation_class_proto_funcs, _countof(font_variation_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, font_variation_class_constructor, "FontVariation", 0, JS_CFUNC_constructor, 0);
	define_font_variation_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FontVariation", ctor);
	ctor_list["FontVariation"] = ctor;

	return 0;
}

JSModuleDef *_js_init_font_variation_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/font';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_font_variation_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FontVariation");
	return m;
}

JSModuleDef *js_init_font_variation_module(JSContext *ctx) {
	return _js_init_font_variation_module(ctx, "@godot/classes/font_variation");
}

void __register_font_variation() {
	js_init_font_variation_module(js_context());
}

void register_font_variation() {
	__register_font_variation();
}