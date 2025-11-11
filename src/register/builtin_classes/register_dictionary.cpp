#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/string_name.hpp>


using namespace godot;

static void dictionary_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Dictionary"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef dictionary_class_def = {
	"Dictionary",
	dictionary_class_finalizer
};

static JSValue dictionary_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Dictionary"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}

	Dictionary instance;
	if (argc == 0) {
		instance = Dictionary();
	}
	if (argc == 1 && (VariantAdapter::can_cast(argv[0], Variant::Type::DICTIONARY))) {
		Dictionary
				v0 = VariantAdapter(argv[0]).get();
		instance = Dictionary(v0);
	}
	if (argc == 7 && (VariantAdapter::can_cast(argv[0], Variant::Type::DICTIONARY)) && (VariantAdapter::can_cast(argv[1], Variant::Type::INT)) && (VariantAdapter::can_cast(argv[2], Variant::Type::STRING_NAME)) && (VariantAdapter::can_cast(argv[2], Variant::Type::STRING_NAME)) && (VariantAdapter::can_cast(argv[4], Variant::Type::INT)) && (VariantAdapter::can_cast(argv[5], Variant::Type::STRING_NAME)) && (VariantAdapter::can_cast(argv[5], Variant::Type::STRING_NAME))) {
		Dictionary
				v0 = VariantAdapter(argv[0]).get();
		int
				v1 = VariantAdapter(argv[1]).get();
		StringName
				v2 = VariantAdapter(argv[2]).get();
		Variant
				v3 = VariantAdapter(argv[3]).get();
		int
				v4 = VariantAdapter(argv[4]).get();
		StringName
				v5 = VariantAdapter(argv[5]).get();
		Variant
				v6 = VariantAdapter(argv[6]).get();
		instance = Dictionary(v0, v1, v2, v3, v4, v5, v6);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
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
	JSClassID class_id = 0;
	classes["Dictionary"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Dictionary";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &dictionary_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, dictionary_class_proto_funcs, _countof(dictionary_class_proto_funcs));
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

// ------------------DictionaryProxy------------------
static void dictionary_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["DictionaryProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Dictionary> *>(proxy));
	}
}

static JSClassDef dictionary_proxy_def = {
	.class_name = "DictionaryProxy",
	.finalizer = dictionary_proxy_finalizer
};


static JSValue dictionary_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["DictionaryProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Dictionary> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Dictionary> *>(JS_GetAnyOpaque(*argv, &opaque_id));
	} else {
		return JS_EXCEPTION;
	}

	if (!proxy) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	return obj;
}

static JSValue dictionary_proxy_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::size, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_empty, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue dictionary_proxy_assign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::assign, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue dictionary_proxy_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::sort, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue dictionary_proxy_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::merge, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue dictionary_proxy_merged(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::merged, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::has, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_has_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::has_all, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_find_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::find_key, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_method_ret(&Dictionary::erase, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::hash, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_keys(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::keys, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_values(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::values, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::duplicate, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_duplicate_deep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::duplicate_deep, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_or_add(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_method_ret(&Dictionary::get_or_add, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_method_ret(&Dictionary::set, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_typed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_typed, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_typed_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_typed_key, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_typed_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_typed_value, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_same_typed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_same_typed, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_same_typed_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_same_typed_key, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_is_same_typed_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_same_typed_value, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_typed_key_builtin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get_typed_key_builtin, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_typed_value_builtin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get_typed_value_builtin, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_typed_key_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get_typed_key_class_name, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_typed_value_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get_typed_value_class_name, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_typed_key_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get_typed_key_script, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_get_typed_value_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::get_typed_value_script, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_make_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Dictionary::make_read_only, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
}

static JSValue dictionary_proxy_is_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::is_read_only, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue dictionary_proxy_recursive_equal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["DictionaryProxy"]);
	ObjectProxy<Dictionary> *proxy = reinterpret_cast<ObjectProxy<Dictionary> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&Dictionary::recursive_equal, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}


static const JSCFunctionListEntry dictionary_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("size", 0, &dictionary_proxy_size),
	JS_CFUNC_DEF("is_empty", 0, &dictionary_proxy_is_empty),
	JS_CFUNC_DEF("clear", 0, &dictionary_proxy_clear),
	JS_CFUNC_DEF("assign", 1, &dictionary_proxy_assign),
	JS_CFUNC_DEF("sort", 0, &dictionary_proxy_sort),
	JS_CFUNC_DEF("merge", 2, &dictionary_proxy_merge),
	JS_CFUNC_DEF("merged", 2, &dictionary_proxy_merged),
	JS_CFUNC_DEF("has", 1, &dictionary_proxy_has),
	JS_CFUNC_DEF("has_all", 1, &dictionary_proxy_has_all),
	JS_CFUNC_DEF("find_key", 1, &dictionary_proxy_find_key),
	JS_CFUNC_DEF("erase", 1, &dictionary_proxy_erase),
	JS_CFUNC_DEF("hash", 0, &dictionary_proxy_hash),
	JS_CFUNC_DEF("keys", 0, &dictionary_proxy_keys),
	JS_CFUNC_DEF("values", 0, &dictionary_proxy_values),
	JS_CFUNC_DEF("duplicate", 1, &dictionary_proxy_duplicate),
	JS_CFUNC_DEF("duplicate_deep", 1, &dictionary_proxy_duplicate_deep),
	JS_CFUNC_DEF("get", 2, &dictionary_proxy_get),
	JS_CFUNC_DEF("get_or_add", 2, &dictionary_proxy_get_or_add),
	JS_CFUNC_DEF("set", 2, &dictionary_proxy_set),
	JS_CFUNC_DEF("is_typed", 0, &dictionary_proxy_is_typed),
	JS_CFUNC_DEF("is_typed_key", 0, &dictionary_proxy_is_typed_key),
	JS_CFUNC_DEF("is_typed_value", 0, &dictionary_proxy_is_typed_value),
	JS_CFUNC_DEF("is_same_typed", 1, &dictionary_proxy_is_same_typed),
	JS_CFUNC_DEF("is_same_typed_key", 1, &dictionary_proxy_is_same_typed_key),
	JS_CFUNC_DEF("is_same_typed_value", 1, &dictionary_proxy_is_same_typed_value),
	JS_CFUNC_DEF("get_typed_key_builtin", 0, &dictionary_proxy_get_typed_key_builtin),
	JS_CFUNC_DEF("get_typed_value_builtin", 0, &dictionary_proxy_get_typed_value_builtin),
	JS_CFUNC_DEF("get_typed_key_class_name", 0, &dictionary_proxy_get_typed_key_class_name),
	JS_CFUNC_DEF("get_typed_value_class_name", 0, &dictionary_proxy_get_typed_value_class_name),
	JS_CFUNC_DEF("get_typed_key_script", 0, &dictionary_proxy_get_typed_key_script),
	JS_CFUNC_DEF("get_typed_value_script", 0, &dictionary_proxy_get_typed_value_script),
	JS_CFUNC_DEF("make_read_only", 0, &dictionary_proxy_make_read_only),
	JS_CFUNC_DEF("is_read_only", 0, &dictionary_proxy_is_read_only),
	JS_CFUNC_DEF("recursive_equal", 2, &dictionary_proxy_recursive_equal),
};


static int js_dictionary_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["DictionaryProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "DictionaryProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &dictionary_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, dictionary_proxy_proto_funcs, _countof(dictionary_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, dictionary_proxy_constructor, "DictionaryProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "DictionaryProxy", ctor);

	return 0;
}

void js_init_dictionary_proxy_module(JSContext *ctx) {
	js_dictionary_proxy_init(ctx);
}

void register_proxy_dictionary() {
	js_init_dictionary_proxy_module(js_context());
}