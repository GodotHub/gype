#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/translation.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/translation_domain.hpp>
using namespace godot;

static void translation_domain_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TranslationDomain"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef translation_domain_class_def = {
    "TranslationDomain",
    translation_domain_class_finalizer
};

static JSValue translation_domain_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TranslationDomain"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TranslationDomain *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TranslationDomain *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TranslationDomain);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue translation_domain_class_get_translation_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::get_translation_object, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_add_translation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::add_translation, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_remove_translation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::remove_translation, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::clear, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_translate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::translate, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_translate_plural(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::translate_plural, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_get_locale_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::get_locale_override, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_set_locale_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_locale_override, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_pseudolocalization_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_pseudolocalization_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_pseudolocalization_accents_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_pseudolocalization_accents_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_accents_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_accents_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_pseudolocalization_double_vowels_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_pseudolocalization_double_vowels_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_double_vowels_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_double_vowels_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_pseudolocalization_fake_bidi_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_pseudolocalization_fake_bidi_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_fake_bidi_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_fake_bidi_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_pseudolocalization_override_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_pseudolocalization_override_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_override_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_override_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_is_pseudolocalization_skip_placeholders_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::is_pseudolocalization_skip_placeholders_enabled, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_skip_placeholders_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_skip_placeholders_enabled, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_get_pseudolocalization_expansion_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::get_pseudolocalization_expansion_ratio, ctx, this_val, argc, argv);
}
static JSValue translation_domain_class_set_pseudolocalization_expansion_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_expansion_ratio, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_get_pseudolocalization_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		TranslationDomain *obj = static_cast<TranslationDomain *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_pseudolocalization_prefix();
	};
	proxy->setter = [this_val](const String &value) -> void {
		TranslationDomain *js_proxy = static_cast<TranslationDomain *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_pseudolocalization_prefix(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue translation_domain_class_set_pseudolocalization_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_prefix, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_get_pseudolocalization_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		TranslationDomain *obj = static_cast<TranslationDomain *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_pseudolocalization_suffix();
	};
	proxy->setter = [this_val](const String &value) -> void {
		TranslationDomain *js_proxy = static_cast<TranslationDomain *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_pseudolocalization_suffix(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue translation_domain_class_set_pseudolocalization_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TranslationDomain::set_pseudolocalization_suffix, ctx, this_val, argc, argv);
};
static JSValue translation_domain_class_pseudolocalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TranslationDomain::pseudolocalize, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry translation_domain_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_translation_object", 1, &translation_domain_class_get_translation_object),
	JS_CFUNC_DEF("add_translation", 1, &translation_domain_class_add_translation),
	JS_CFUNC_DEF("remove_translation", 1, &translation_domain_class_remove_translation),
	JS_CFUNC_DEF("clear", 0, &translation_domain_class_clear),
	JS_CFUNC_DEF("translate", 2, &translation_domain_class_translate),
	JS_CFUNC_DEF("translate_plural", 4, &translation_domain_class_translate_plural),
	JS_CFUNC_DEF("get_locale_override", 0, &translation_domain_class_get_locale_override),
	JS_CFUNC_DEF("set_locale_override", 1, &translation_domain_class_set_locale_override),
	JS_CFUNC_DEF("is_enabled", 0, &translation_domain_class_is_enabled),
	JS_CFUNC_DEF("set_enabled", 1, &translation_domain_class_set_enabled),
	JS_CFUNC_DEF("is_pseudolocalization_enabled", 0, &translation_domain_class_is_pseudolocalization_enabled),
	JS_CFUNC_DEF("set_pseudolocalization_enabled", 1, &translation_domain_class_set_pseudolocalization_enabled),
	JS_CFUNC_DEF("is_pseudolocalization_accents_enabled", 0, &translation_domain_class_is_pseudolocalization_accents_enabled),
	JS_CFUNC_DEF("set_pseudolocalization_accents_enabled", 1, &translation_domain_class_set_pseudolocalization_accents_enabled),
	JS_CFUNC_DEF("is_pseudolocalization_double_vowels_enabled", 0, &translation_domain_class_is_pseudolocalization_double_vowels_enabled),
	JS_CFUNC_DEF("set_pseudolocalization_double_vowels_enabled", 1, &translation_domain_class_set_pseudolocalization_double_vowels_enabled),
	JS_CFUNC_DEF("is_pseudolocalization_fake_bidi_enabled", 0, &translation_domain_class_is_pseudolocalization_fake_bidi_enabled),
	JS_CFUNC_DEF("set_pseudolocalization_fake_bidi_enabled", 1, &translation_domain_class_set_pseudolocalization_fake_bidi_enabled),
	JS_CFUNC_DEF("is_pseudolocalization_override_enabled", 0, &translation_domain_class_is_pseudolocalization_override_enabled),
	JS_CFUNC_DEF("set_pseudolocalization_override_enabled", 1, &translation_domain_class_set_pseudolocalization_override_enabled),
	JS_CFUNC_DEF("is_pseudolocalization_skip_placeholders_enabled", 0, &translation_domain_class_is_pseudolocalization_skip_placeholders_enabled),
	JS_CFUNC_DEF("set_pseudolocalization_skip_placeholders_enabled", 1, &translation_domain_class_set_pseudolocalization_skip_placeholders_enabled),
	JS_CFUNC_DEF("get_pseudolocalization_expansion_ratio", 0, &translation_domain_class_get_pseudolocalization_expansion_ratio),
	JS_CFUNC_DEF("set_pseudolocalization_expansion_ratio", 1, &translation_domain_class_set_pseudolocalization_expansion_ratio),
	JS_CFUNC_DEF("get_pseudolocalization_prefix", 0, &translation_domain_class_get_pseudolocalization_prefix),
	JS_CFUNC_DEF("set_pseudolocalization_prefix", 1, &translation_domain_class_set_pseudolocalization_prefix),
	JS_CFUNC_DEF("get_pseudolocalization_suffix", 0, &translation_domain_class_get_pseudolocalization_suffix),
	JS_CFUNC_DEF("set_pseudolocalization_suffix", 1, &translation_domain_class_set_pseudolocalization_suffix),
	JS_CFUNC_DEF("pseudolocalize", 1, &translation_domain_class_pseudolocalize),
};




static void define_translation_domain_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_enabled, "is_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_enabled, "set_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_pseudolocalization_enabled, "is_pseudolocalization_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_enabled, "set_pseudolocalization_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_accents_enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_pseudolocalization_accents_enabled, "is_pseudolocalization_accents_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_accents_enabled, "set_pseudolocalization_accents_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_double_vowels_enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_pseudolocalization_double_vowels_enabled, "is_pseudolocalization_double_vowels_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_double_vowels_enabled, "set_pseudolocalization_double_vowels_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_fake_bidi_enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_pseudolocalization_fake_bidi_enabled, "is_pseudolocalization_fake_bidi_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_fake_bidi_enabled, "set_pseudolocalization_fake_bidi_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_override_enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_pseudolocalization_override_enabled, "is_pseudolocalization_override_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_override_enabled, "set_pseudolocalization_override_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_skip_placeholders_enabled"),
        JS_NewCFunction(ctx, translation_domain_class_is_pseudolocalization_skip_placeholders_enabled, "is_pseudolocalization_skip_placeholders_enabled", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_skip_placeholders_enabled, "set_pseudolocalization_skip_placeholders_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_expansion_ratio"),
        JS_NewCFunction(ctx, translation_domain_class_get_pseudolocalization_expansion_ratio, "get_pseudolocalization_expansion_ratio", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_expansion_ratio, "set_pseudolocalization_expansion_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_prefix"),
        JS_NewCFunction(ctx, translation_domain_class_get_pseudolocalization_prefix, "get_pseudolocalization_prefix", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_prefix, "set_pseudolocalization_prefix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pseudolocalization_suffix"),
        JS_NewCFunction(ctx, translation_domain_class_get_pseudolocalization_suffix, "get_pseudolocalization_suffix", 0),
        JS_NewCFunction(ctx, translation_domain_class_set_pseudolocalization_suffix, "set_pseudolocalization_suffix", 1),
        JS_PROP_GETSET
    );
}

static void define_translation_domain_enum(JSContext *ctx, JSValue proto) {
}

static int js_translation_domain_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TranslationDomain"] = class_id;
	classes_by_id[class_id] = "TranslationDomain";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &translation_domain_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_translation_domain_property(ctx, proto);
	define_translation_domain_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, translation_domain_class_proto_funcs, _countof(translation_domain_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, translation_domain_class_constructor, "TranslationDomain", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TranslationDomain", ctor);

	return 0;
}

JSModuleDef *_js_init_translation_domain_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_translation_domain_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TranslationDomain");
	return m;
}

JSModuleDef *js_init_translation_domain_module(JSContext *ctx) {
	return _js_init_translation_domain_module(ctx, "@godot/classes/translation_domain");
}

void __register_translation_domain() {
	js_init_translation_domain_module(js_context());
}

void register_translation_domain() {
	__register_translation_domain();
}