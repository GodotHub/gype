#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/vector4.hpp>


using namespace godot;

static void packed_vector4_array_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PackedVector4Array"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef packed_vector4_array_class_def = {
	"PackedVector4Array",
	packed_vector4_array_class_finalizer
};

static JSValue packed_vector4_array_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["PackedVector4Array"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	PackedVector4Array instance;
	if (argc == 0) {
		instance = PackedVector4Array();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::PACKED_VECTOR4_ARRAY)) {
		PackedVector4Array v0 = VariantAdapter(argv[0]).get();
		instance = PackedVector4Array(v0);
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::ARRAY)) {
		Array v0 = VariantAdapter(argv[0]).get();
		instance = PackedVector4Array(v0);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue packed_vector4_array_class_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::get, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::set, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::size, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::is_empty, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_push_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::push_back, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_append(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::append, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_append_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::append_array, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_remove_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::remove_at, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::insert, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::fill, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::resize, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::clear, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::has, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::reverse, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::slice, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_to_byte_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::to_byte_array, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::sort, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_class_bsearch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::bsearch, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::duplicate, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::find, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::rfind, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedVector4Array::count, ctx, this_val, argc, argv);
}
static JSValue packed_vector4_array_class_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedVector4Array::erase, ctx, this_val, argc, argv);
}




static const JSCFunctionListEntry packed_vector4_array_class_proto_funcs[] = {
	JS_CFUNC_DEF("get", 1, &packed_vector4_array_class_get),
	JS_CFUNC_DEF("set", 2, &packed_vector4_array_class_set),
	JS_CFUNC_DEF("size", 0, &packed_vector4_array_class_size),
	JS_CFUNC_DEF("is_empty", 0, &packed_vector4_array_class_is_empty),
	JS_CFUNC_DEF("push_back", 1, &packed_vector4_array_class_push_back),
	JS_CFUNC_DEF("append", 1, &packed_vector4_array_class_append),
	JS_CFUNC_DEF("append_array", 1, &packed_vector4_array_class_append_array),
	JS_CFUNC_DEF("remove_at", 1, &packed_vector4_array_class_remove_at),
	JS_CFUNC_DEF("insert", 2, &packed_vector4_array_class_insert),
	JS_CFUNC_DEF("fill", 1, &packed_vector4_array_class_fill),
	JS_CFUNC_DEF("resize", 1, &packed_vector4_array_class_resize),
	JS_CFUNC_DEF("clear", 0, &packed_vector4_array_class_clear),
	JS_CFUNC_DEF("has", 1, &packed_vector4_array_class_has),
	JS_CFUNC_DEF("reverse", 0, &packed_vector4_array_class_reverse),
	JS_CFUNC_DEF("slice", 2, &packed_vector4_array_class_slice),
	JS_CFUNC_DEF("to_byte_array", 0, &packed_vector4_array_class_to_byte_array),
	JS_CFUNC_DEF("sort", 0, &packed_vector4_array_class_sort),
	JS_CFUNC_DEF("bsearch", 2, &packed_vector4_array_class_bsearch),
	JS_CFUNC_DEF("duplicate", 0, &packed_vector4_array_class_duplicate),
	JS_CFUNC_DEF("find", 2, &packed_vector4_array_class_find),
	JS_CFUNC_DEF("rfind", 2, &packed_vector4_array_class_rfind),
	JS_CFUNC_DEF("count", 1, &packed_vector4_array_class_count),
	JS_CFUNC_DEF("erase", 1, &packed_vector4_array_class_erase),
};




static int js_packed_vector4_array_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["PackedVector4Array"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "PackedVector4Array";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &packed_vector4_array_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, packed_vector4_array_class_proto_funcs, _countof(packed_vector4_array_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, packed_vector4_array_class_constructor, "PackedVector4Array", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "PackedVector4Array", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_packed_vector4_array_module(JSContext *ctx) {
	js_packed_vector4_array_class_init(ctx);
}

void register_packed_vector4_array() {
	js_init_packed_vector4_array_module(js_context());
}

// ------------------PackedVector4ArrayProxy------------------
static void packed_vector4_array_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["PackedVector4ArrayProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<PackedVector4Array> *>(proxy));
	}
}

static JSClassDef packed_vector4_array_proxy_def = {
	"PackedVector4ArrayProxy",
	packed_vector4_array_proxy_finalizer
};


static JSValue packed_vector4_array_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["PackedVector4ArrayProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<PackedVector4Array> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<PackedVector4Array> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue packed_vector4_array_proxy_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::get, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::set, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::size, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::is_empty, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_push_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::push_back, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_append(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::append, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_append_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::append_array, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_remove_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::remove_at, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::insert, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::fill, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::resize, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::clear, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::has, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::reverse, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::slice, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_to_byte_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::to_byte_array, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedVector4Array::sort, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_vector4_array_proxy_bsearch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::bsearch, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::duplicate, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::find, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::rfind, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&PackedVector4Array::count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue packed_vector4_array_proxy_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PackedVector4ArrayProxy"]);
    ObjectProxy<PackedVector4Array> *proxy = static_cast<ObjectProxy<PackedVector4Array> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_method_ret(&PackedVector4Array::erase, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}


static const JSCFunctionListEntry packed_vector4_array_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("get", 1, &packed_vector4_array_proxy_get),
	JS_CFUNC_DEF("set", 2, &packed_vector4_array_proxy_set),
	JS_CFUNC_DEF("size", 0, &packed_vector4_array_proxy_size),
	JS_CFUNC_DEF("is_empty", 0, &packed_vector4_array_proxy_is_empty),
	JS_CFUNC_DEF("push_back", 1, &packed_vector4_array_proxy_push_back),
	JS_CFUNC_DEF("append", 1, &packed_vector4_array_proxy_append),
	JS_CFUNC_DEF("append_array", 1, &packed_vector4_array_proxy_append_array),
	JS_CFUNC_DEF("remove_at", 1, &packed_vector4_array_proxy_remove_at),
	JS_CFUNC_DEF("insert", 2, &packed_vector4_array_proxy_insert),
	JS_CFUNC_DEF("fill", 1, &packed_vector4_array_proxy_fill),
	JS_CFUNC_DEF("resize", 1, &packed_vector4_array_proxy_resize),
	JS_CFUNC_DEF("clear", 0, &packed_vector4_array_proxy_clear),
	JS_CFUNC_DEF("has", 1, &packed_vector4_array_proxy_has),
	JS_CFUNC_DEF("reverse", 0, &packed_vector4_array_proxy_reverse),
	JS_CFUNC_DEF("slice", 2, &packed_vector4_array_proxy_slice),
	JS_CFUNC_DEF("to_byte_array", 0, &packed_vector4_array_proxy_to_byte_array),
	JS_CFUNC_DEF("sort", 0, &packed_vector4_array_proxy_sort),
	JS_CFUNC_DEF("bsearch", 2, &packed_vector4_array_proxy_bsearch),
	JS_CFUNC_DEF("duplicate", 0, &packed_vector4_array_proxy_duplicate),
	JS_CFUNC_DEF("find", 2, &packed_vector4_array_proxy_find),
	JS_CFUNC_DEF("rfind", 2, &packed_vector4_array_proxy_rfind),
	JS_CFUNC_DEF("count", 1, &packed_vector4_array_proxy_count),
	JS_CFUNC_DEF("erase", 1, &packed_vector4_array_proxy_erase),
};


static int js_packed_vector4_array_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["PackedVector4ArrayProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "PackedVector4ArrayProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &packed_vector4_array_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, packed_vector4_array_proxy_proto_funcs, _countof(packed_vector4_array_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, packed_vector4_array_proxy_constructor, "PackedVector4ArrayProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "PackedVector4ArrayProxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_packed_vector4_array_proxy_module(JSContext *ctx) {
	js_packed_vector4_array_proxy_init(ctx);
}

void register_proxy_packed_vector4_array() {
	js_init_packed_vector4_array_proxy_module(js_context());
}