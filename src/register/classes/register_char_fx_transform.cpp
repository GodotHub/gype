#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/char_fx_transform.hpp>
using namespace godot;

static void char_fx_transform_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CharFXTransform"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef char_fx_transform_class_def = {
    "CharFXTransform",
    char_fx_transform_class_finalizer
};

static JSValue char_fx_transform_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CharFXTransform"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CharFXTransform *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CharFXTransform *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CharFXTransform);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue char_fx_transform_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform2D> *proxy = memnew(ObjectProxy<Transform2D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform2D {
		CharFXTransform *obj = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transform();
	};
	proxy->setter = [this_val](const Transform2D &value) -> void {
		CharFXTransform *js_proxy = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_transform(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform2DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform2DProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue char_fx_transform_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_transform, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		CharFXTransform *obj = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_range();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		CharFXTransform *js_proxy = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_range(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue char_fx_transform_class_set_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_range, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_elapsed_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CharFXTransform::get_elapsed_time, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_elapsed_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_elapsed_time, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CharFXTransform::is_visible, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_visibility(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_visibility, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_is_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CharFXTransform::is_outline, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_outline, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		CharFXTransform *obj = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		CharFXTransform *js_proxy = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset(value);
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
static JSValue char_fx_transform_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_offset, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CharFXTransform *obj = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CharFXTransform *js_proxy = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue char_fx_transform_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_color, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		CharFXTransform *obj = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_environment();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		CharFXTransform *js_proxy = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_environment(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue char_fx_transform_class_set_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_environment, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_glyph_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CharFXTransform::get_glyph_index, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_glyph_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_glyph_index, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_relative_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CharFXTransform::get_relative_index, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_relative_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_relative_index, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_glyph_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CharFXTransform::get_glyph_count, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_glyph_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_glyph_count, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_glyph_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CharFXTransform::get_glyph_flags, ctx, this_val, argc, argv);
}
static JSValue char_fx_transform_class_set_glyph_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_glyph_flags, ctx, this_val, argc, argv);
};
static JSValue char_fx_transform_class_get_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		CharFXTransform *obj = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_font();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		CharFXTransform *js_proxy = static_cast<CharFXTransform *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_font(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue char_fx_transform_class_set_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CharFXTransform::set_font, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry char_fx_transform_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_transform", 0, &char_fx_transform_class_get_transform),
	JS_CFUNC_DEF("set_transform", 1, &char_fx_transform_class_set_transform),
	JS_CFUNC_DEF("get_range", 0, &char_fx_transform_class_get_range),
	JS_CFUNC_DEF("set_range", 1, &char_fx_transform_class_set_range),
	JS_CFUNC_DEF("get_elapsed_time", 0, &char_fx_transform_class_get_elapsed_time),
	JS_CFUNC_DEF("set_elapsed_time", 1, &char_fx_transform_class_set_elapsed_time),
	JS_CFUNC_DEF("is_visible", 0, &char_fx_transform_class_is_visible),
	JS_CFUNC_DEF("set_visibility", 1, &char_fx_transform_class_set_visibility),
	JS_CFUNC_DEF("is_outline", 0, &char_fx_transform_class_is_outline),
	JS_CFUNC_DEF("set_outline", 1, &char_fx_transform_class_set_outline),
	JS_CFUNC_DEF("get_offset", 0, &char_fx_transform_class_get_offset),
	JS_CFUNC_DEF("set_offset", 1, &char_fx_transform_class_set_offset),
	JS_CFUNC_DEF("get_color", 0, &char_fx_transform_class_get_color),
	JS_CFUNC_DEF("set_color", 1, &char_fx_transform_class_set_color),
	JS_CFUNC_DEF("get_environment", 0, &char_fx_transform_class_get_environment),
	JS_CFUNC_DEF("set_environment", 1, &char_fx_transform_class_set_environment),
	JS_CFUNC_DEF("get_glyph_index", 0, &char_fx_transform_class_get_glyph_index),
	JS_CFUNC_DEF("set_glyph_index", 1, &char_fx_transform_class_set_glyph_index),
	JS_CFUNC_DEF("get_relative_index", 0, &char_fx_transform_class_get_relative_index),
	JS_CFUNC_DEF("set_relative_index", 1, &char_fx_transform_class_set_relative_index),
	JS_CFUNC_DEF("get_glyph_count", 0, &char_fx_transform_class_get_glyph_count),
	JS_CFUNC_DEF("set_glyph_count", 1, &char_fx_transform_class_set_glyph_count),
	JS_CFUNC_DEF("get_glyph_flags", 0, &char_fx_transform_class_get_glyph_flags),
	JS_CFUNC_DEF("set_glyph_flags", 1, &char_fx_transform_class_set_glyph_flags),
	JS_CFUNC_DEF("get_font", 0, &char_fx_transform_class_get_font),
	JS_CFUNC_DEF("set_font", 1, &char_fx_transform_class_set_font),
};




static void define_char_fx_transform_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_range, "get_range", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_range, "set_range", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "elapsed_time"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_elapsed_time, "get_elapsed_time", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_elapsed_time, "set_elapsed_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible"),
        JS_NewCFunction(ctx, char_fx_transform_class_is_visible, "is_visible", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_visibility, "set_visibility", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outline"),
        JS_NewCFunction(ctx, char_fx_transform_class_is_outline, "is_outline", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_outline, "set_outline", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "env"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_environment, "get_environment", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_environment, "set_environment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glyph_index"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_glyph_index, "get_glyph_index", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_glyph_index, "set_glyph_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glyph_count"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_glyph_count, "get_glyph_count", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_glyph_count, "set_glyph_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glyph_flags"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_glyph_flags, "get_glyph_flags", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_glyph_flags, "set_glyph_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "relative_index"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_relative_index, "get_relative_index", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_relative_index, "set_relative_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font"),
        JS_NewCFunction(ctx, char_fx_transform_class_get_font, "get_font", 0),
        JS_NewCFunction(ctx, char_fx_transform_class_set_font, "set_font", 1),
        JS_PROP_GETSET
    );
}

static void define_char_fx_transform_enum(JSContext *ctx, JSValue ctor) {
}

static int js_char_fx_transform_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CharFXTransform"] = class_id;
	classes_by_id[class_id] = "CharFXTransform";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &char_fx_transform_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_char_fx_transform_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, char_fx_transform_class_proto_funcs, _countof(char_fx_transform_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, char_fx_transform_class_constructor, "CharFXTransform", 0, JS_CFUNC_constructor, 0);
	define_char_fx_transform_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CharFXTransform", ctor);

	return 0;
}

JSModuleDef *_js_init_char_fx_transform_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_char_fx_transform_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CharFXTransform");
	return m;
}

JSModuleDef *js_init_char_fx_transform_module(JSContext *ctx) {
	return _js_init_char_fx_transform_module(ctx, "@godot/classes/char_fx_transform");
}

void __register_char_fx_transform() {
	js_init_char_fx_transform_module(js_context());
}

void register_char_fx_transform() {
	__register_char_fx_transform();
}