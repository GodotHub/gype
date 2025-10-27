#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/dictionary.hpp>

using namespace godot;

static void dictionary_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Dictionary"];
	Dictionary *opaque_ptr = static_cast<Dictionary *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef dictionary_class_def = {
	"Dictionary",
	.finalizer = dictionary_class_finalizer
};

static JSValue dictionary_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Dictionary"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	Dictionary *instance = nullptr;	if (argc == 0) {
		instance = memnew(Dictionary());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::DICTIONARY) {
		Dictionary v0 = VariantAdapter(argv[0]).get<Dictionary>();
		instance = memnew(Dictionary(v0));
	}
	if (argc == 7&&VariantAdapter(argv[0]).get_type() == Variant::Type::DICTIONARY&&VariantAdapter(argv[1]).get_type() == Variant::Type::INT&&VariantAdapter(argv[2]).get_type() == Variant::Type::STRING_NAME&&VariantAdapter(argv[3]).get_type() == Variant::Type::VARIANT&&VariantAdapter(argv[4]).get_type() == Variant::Type::INT&&VariantAdapter(argv[5]).get_type() == Variant::Type::STRING_NAME&&VariantAdapter(argv[6]).get_type() == Variant::Type::VARIANT) {
		Dictionary v0 = VariantAdapter(argv[0]).get<Dictionary>();
		int v1 = VariantAdapter(argv[1]).get<int>();
		StringName v2 = VariantAdapter(argv[2]).get<StringName>();
		Variant v3 = VariantAdapter(argv[3]).get<Variant>();
		int v4 = VariantAdapter(argv[4]).get<int>();
		StringName v5 = VariantAdapter(argv[5]).get<StringName>();
		Variant v6 = VariantAdapter(argv[6]).get<Variant>();
		instance = memnew(Dictionary(v0, v1, v2, v3, v4, v5, v6));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
	return obj;
}
static JSValue dictionary_class_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::size, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_empty, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::clear, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue dictionary_class_assign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::assign, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue dictionary_class_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::sort, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue dictionary_class_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::merge, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue dictionary_class_merged(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::merged, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::has, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_has_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::has_all, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_find_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::find_key, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Dictionary::erase, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::hash, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_keys(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::keys, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_values(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::values, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::duplicate, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_duplicate_deep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::duplicate_deep, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_or_add(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Dictionary::get_or_add, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Dictionary::set, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_typed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_typed, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_typed_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_typed_key, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_typed_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_typed_value, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_same_typed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_same_typed, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_same_typed_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_same_typed_key, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_is_same_typed_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_same_typed_value, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_typed_key_builtin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get_typed_key_builtin, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_typed_value_builtin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get_typed_value_builtin, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_typed_key_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get_typed_key_class_name, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_typed_value_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get_typed_value_class_name, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_typed_key_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get_typed_key_script, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_get_typed_value_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::get_typed_value_script, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_make_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::make_read_only, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue dictionary_class_is_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::is_read_only, ctx, this_val, argc, argv);
}
static JSValue dictionary_class_recursive_equal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Dictionary::recursive_equal, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry dictionary_class_proto_funcs[] = {
	JS_CFUNC_DEF("size", 0, &dictionary_class_size),
	JS_CFUNC_DEF("is_empty", 0, &dictionary_class_is_empty),
	JS_CFUNC_DEF("clear", 0, &dictionary_class_clear),
	JS_CFUNC_DEF("assign", 1, &dictionary_class_assign),
	JS_CFUNC_DEF("sort", 0, &dictionary_class_sort),
	JS_CFUNC_DEF("merge", 2, &dictionary_class_merge),
	JS_CFUNC_DEF("merged", 2, &dictionary_class_merged),
	JS_CFUNC_DEF("has", 1, &dictionary_class_has),
	JS_CFUNC_DEF("has_all", 1, &dictionary_class_has_all),
	JS_CFUNC_DEF("find_key", 1, &dictionary_class_find_key),
	JS_CFUNC_DEF("erase", 1, &dictionary_class_erase),
	JS_CFUNC_DEF("hash", 0, &dictionary_class_hash),
	JS_CFUNC_DEF("keys", 0, &dictionary_class_keys),
	JS_CFUNC_DEF("values", 0, &dictionary_class_values),
	JS_CFUNC_DEF("duplicate", 1, &dictionary_class_duplicate),
	JS_CFUNC_DEF("duplicate_deep", 1, &dictionary_class_duplicate_deep),
	JS_CFUNC_DEF("get", 2, &dictionary_class_get),
	JS_CFUNC_DEF("get_or_add", 2, &dictionary_class_get_or_add),
	JS_CFUNC_DEF("set", 2, &dictionary_class_set),
	JS_CFUNC_DEF("is_typed", 0, &dictionary_class_is_typed),
	JS_CFUNC_DEF("is_typed_key", 0, &dictionary_class_is_typed_key),
	JS_CFUNC_DEF("is_typed_value", 0, &dictionary_class_is_typed_value),
	JS_CFUNC_DEF("is_same_typed", 1, &dictionary_class_is_same_typed),
	JS_CFUNC_DEF("is_same_typed_key", 1, &dictionary_class_is_same_typed_key),
	JS_CFUNC_DEF("is_same_typed_value", 1, &dictionary_class_is_same_typed_value),
	JS_CFUNC_DEF("get_typed_key_builtin", 0, &dictionary_class_get_typed_key_builtin),
	JS_CFUNC_DEF("get_typed_value_builtin", 0, &dictionary_class_get_typed_value_builtin),
	JS_CFUNC_DEF("get_typed_key_class_name", 0, &dictionary_class_get_typed_key_class_name),
	JS_CFUNC_DEF("get_typed_value_class_name", 0, &dictionary_class_get_typed_value_class_name),
	JS_CFUNC_DEF("get_typed_key_script", 0, &dictionary_class_get_typed_key_script),
	JS_CFUNC_DEF("get_typed_value_script", 0, &dictionary_class_get_typed_value_script),
	JS_CFUNC_DEF("make_read_only", 0, &dictionary_class_make_read_only),
	JS_CFUNC_DEF("is_read_only", 0, &dictionary_class_is_read_only),
	JS_CFUNC_DEF("recursive_equal", 2, &dictionary_class_recursive_equal),
};


static int js_dictionary_class_init(JSContext *ctx) {
	classes["Dictionary"] = 0;
	classes["Dictionary"] = JS_NewClassID(&classes["Dictionary"]);
	JSClassID class_id = classes["Dictionary"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &dictionary_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, dictionary_class_proto_funcs, _countof(dictionary_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, dictionary_class_constructor, "Dictionary", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Dictionary", ctor);

	return 0;
}

void js_init_dictionary_module(JSContext *ctx) {
	js_dictionary_class_init(ctx);
}

void register_dictionary() {
	js_init_dictionary_module(js_context());
}