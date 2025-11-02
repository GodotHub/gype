#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/string_name.hpp>

using namespace godot;

static void array_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes[typeid(Array)];
	GDVariantAdapter<Array> *opaque_ptr = static_cast<GDVariantAdapter<Array> *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr && opaque_ptr->can_memfree) {
		memfree(const_cast<Array *>(opaque_ptr->m_active_variant));
	}
}

static JSClassDef array_class_def = {
	"Array",
	.finalizer = array_class_finalizer
};

static JSValue array_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes[typeid(Array)];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}
	
	Array *instance = nullptr;
	GDVariantAdapter<Array> *adapter = reinterpret_cast<GDVariantAdapter<Array> *>(memalloc(sizeof(GDVariantAdapter<Array>)));
	if (argc == 0) {
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array();
	}
	if (argc == 1&&(JSValueAdapter<Array>::can_cast(argv[0]))) {
		Array v0 = *JSValueAdapter<Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 4&&(JSValueAdapter<Array>::can_cast(argv[0]))&&(JSValueAdapter<int>::can_cast(argv[1]))&&(JSValueAdapter<StringName>::can_cast(argv[2]))&&(JSValueAdapter<Variant>::can_cast(argv[3]))) {
		Array v0 = *JSValueAdapter<Array>(argv[0]).get();
		int v1 = *JSValueAdapter<int>(argv[1]).get();
		StringName v2 = *JSValueAdapter<StringName>(argv[2]).get();
		Variant v3 = *JSValueAdapter<Variant>(argv[3]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0, v1, v2, v3);
	}
	if (argc == 1&&(JSValueAdapter<PackedByteArray>::can_cast(argv[0]))) {
		PackedByteArray v0 = *JSValueAdapter<PackedByteArray>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedInt32Array>::can_cast(argv[0]))) {
		PackedInt32Array v0 = *JSValueAdapter<PackedInt32Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedInt64Array>::can_cast(argv[0]))) {
		PackedInt64Array v0 = *JSValueAdapter<PackedInt64Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedFloat32Array>::can_cast(argv[0]))) {
		PackedFloat32Array v0 = *JSValueAdapter<PackedFloat32Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedFloat64Array>::can_cast(argv[0]))) {
		PackedFloat64Array v0 = *JSValueAdapter<PackedFloat64Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedStringArray>::can_cast(argv[0]))) {
		PackedStringArray v0 = *JSValueAdapter<PackedStringArray>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedVector2Array>::can_cast(argv[0]))) {
		PackedVector2Array v0 = *JSValueAdapter<PackedVector2Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedVector3Array>::can_cast(argv[0]))) {
		PackedVector3Array v0 = *JSValueAdapter<PackedVector3Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedColorArray>::can_cast(argv[0]))) {
		PackedColorArray v0 = *JSValueAdapter<PackedColorArray>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	if (argc == 1&&(JSValueAdapter<PackedVector4Array>::can_cast(argv[0]))) {
		PackedVector4Array v0 = *JSValueAdapter<PackedVector4Array>(argv[0]).get();
		instance = reinterpret_cast<Array *>(memalloc(sizeof(Array)));
		instance = new (instance) Array(v0);
	}
	adapter = new (adapter) GDVariantAdapter<Array>(*instance, true);

	if (!instance || !adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue array_class_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::size, ctx, this_val, argc, argv);
}
static JSValue array_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::is_empty, ctx, this_val, argc, argv);
}
static JSValue array_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::clear, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::hash, ctx, this_val, argc, argv);
}
static JSValue array_class_assign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::assign, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::get, ctx, this_val, argc, argv);
}
static JSValue array_class_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::set, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_push_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::push_back, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_push_front(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::push_front, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_append(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::append, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_append_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::append_array, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Array::resize, ctx, this_val, argc, argv);
}
static JSValue array_class_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Array::insert, ctx, this_val, argc, argv);
}
static JSValue array_class_remove_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::remove_at, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::fill, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::erase, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_front(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::front, ctx, this_val, argc, argv);
}
static JSValue array_class_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::back, ctx, this_val, argc, argv);
}
static JSValue array_class_pick_random(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::pick_random, ctx, this_val, argc, argv);
}
static JSValue array_class_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::find, ctx, this_val, argc, argv);
}
static JSValue array_class_find_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::find_custom, ctx, this_val, argc, argv);
}
static JSValue array_class_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::rfind, ctx, this_val, argc, argv);
}
static JSValue array_class_rfind_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::rfind_custom, ctx, this_val, argc, argv);
}
static JSValue array_class_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::count, ctx, this_val, argc, argv);
}
static JSValue array_class_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::has, ctx, this_val, argc, argv);
}
static JSValue array_class_pop_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Array::pop_back, ctx, this_val, argc, argv);
}
static JSValue array_class_pop_front(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Array::pop_front, ctx, this_val, argc, argv);
}
static JSValue array_class_pop_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Array::pop_at, ctx, this_val, argc, argv);
}
static JSValue array_class_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::sort, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_sort_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::sort_custom, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_shuffle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::shuffle, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_bsearch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::bsearch, ctx, this_val, argc, argv);
}
static JSValue array_class_bsearch_custom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::bsearch_custom, ctx, this_val, argc, argv);
}
static JSValue array_class_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::reverse, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::duplicate, ctx, this_val, argc, argv);
}
static JSValue array_class_duplicate_deep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::duplicate_deep, ctx, this_val, argc, argv);
}
static JSValue array_class_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::slice, ctx, this_val, argc, argv);
}
static JSValue array_class_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::filter, ctx, this_val, argc, argv);
}
static JSValue array_class_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::map, ctx, this_val, argc, argv);
}
static JSValue array_class_reduce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::reduce, ctx, this_val, argc, argv);
}
static JSValue array_class_any(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::any, ctx, this_val, argc, argv);
}
static JSValue array_class_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::all, ctx, this_val, argc, argv);
}
static JSValue array_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::max, ctx, this_val, argc, argv);
}
static JSValue array_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::min, ctx, this_val, argc, argv);
}
static JSValue array_class_is_typed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::is_typed, ctx, this_val, argc, argv);
}
static JSValue array_class_is_same_typed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::is_same_typed, ctx, this_val, argc, argv);
}
static JSValue array_class_get_typed_builtin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::get_typed_builtin, ctx, this_val, argc, argv);
}
static JSValue array_class_get_typed_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::get_typed_class_name, ctx, this_val, argc, argv);
}
static JSValue array_class_get_typed_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::get_typed_script, ctx, this_val, argc, argv);
}
static JSValue array_class_make_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&Array::make_read_only, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue array_class_is_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Array::is_read_only, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry array_class_proto_funcs[] = {
	JS_CFUNC_DEF("size", 0, &array_class_size),
	JS_CFUNC_DEF("is_empty", 0, &array_class_is_empty),
	JS_CFUNC_DEF("clear", 0, &array_class_clear),
	JS_CFUNC_DEF("hash", 0, &array_class_hash),
	JS_CFUNC_DEF("assign", 1, &array_class_assign),
	JS_CFUNC_DEF("get", 1, &array_class_get),
	JS_CFUNC_DEF("set", 2, &array_class_set),
	JS_CFUNC_DEF("push_back", 1, &array_class_push_back),
	JS_CFUNC_DEF("push_front", 1, &array_class_push_front),
	JS_CFUNC_DEF("append", 1, &array_class_append),
	JS_CFUNC_DEF("append_array", 1, &array_class_append_array),
	JS_CFUNC_DEF("resize", 1, &array_class_resize),
	JS_CFUNC_DEF("insert", 2, &array_class_insert),
	JS_CFUNC_DEF("remove_at", 1, &array_class_remove_at),
	JS_CFUNC_DEF("fill", 1, &array_class_fill),
	JS_CFUNC_DEF("erase", 1, &array_class_erase),
	JS_CFUNC_DEF("front", 0, &array_class_front),
	JS_CFUNC_DEF("back", 0, &array_class_back),
	JS_CFUNC_DEF("pick_random", 0, &array_class_pick_random),
	JS_CFUNC_DEF("find", 2, &array_class_find),
	JS_CFUNC_DEF("find_custom", 2, &array_class_find_custom),
	JS_CFUNC_DEF("rfind", 2, &array_class_rfind),
	JS_CFUNC_DEF("rfind_custom", 2, &array_class_rfind_custom),
	JS_CFUNC_DEF("count", 1, &array_class_count),
	JS_CFUNC_DEF("has", 1, &array_class_has),
	JS_CFUNC_DEF("pop_back", 0, &array_class_pop_back),
	JS_CFUNC_DEF("pop_front", 0, &array_class_pop_front),
	JS_CFUNC_DEF("pop_at", 1, &array_class_pop_at),
	JS_CFUNC_DEF("sort", 0, &array_class_sort),
	JS_CFUNC_DEF("sort_custom", 1, &array_class_sort_custom),
	JS_CFUNC_DEF("shuffle", 0, &array_class_shuffle),
	JS_CFUNC_DEF("bsearch", 2, &array_class_bsearch),
	JS_CFUNC_DEF("bsearch_custom", 3, &array_class_bsearch_custom),
	JS_CFUNC_DEF("reverse", 0, &array_class_reverse),
	JS_CFUNC_DEF("duplicate", 1, &array_class_duplicate),
	JS_CFUNC_DEF("duplicate_deep", 1, &array_class_duplicate_deep),
	JS_CFUNC_DEF("slice", 4, &array_class_slice),
	JS_CFUNC_DEF("filter", 1, &array_class_filter),
	JS_CFUNC_DEF("map", 1, &array_class_map),
	JS_CFUNC_DEF("reduce", 2, &array_class_reduce),
	JS_CFUNC_DEF("any", 1, &array_class_any),
	JS_CFUNC_DEF("all", 1, &array_class_all),
	JS_CFUNC_DEF("max", 0, &array_class_max),
	JS_CFUNC_DEF("min", 0, &array_class_min),
	JS_CFUNC_DEF("is_typed", 0, &array_class_is_typed),
	JS_CFUNC_DEF("is_same_typed", 1, &array_class_is_same_typed),
	JS_CFUNC_DEF("get_typed_builtin", 0, &array_class_get_typed_builtin),
	JS_CFUNC_DEF("get_typed_class_name", 0, &array_class_get_typed_class_name),
	JS_CFUNC_DEF("get_typed_script", 0, &array_class_get_typed_script),
	JS_CFUNC_DEF("make_read_only", 0, &array_class_make_read_only),
	JS_CFUNC_DEF("is_read_only", 0, &array_class_is_read_only),
};


static int js_array_class_init(JSContext *ctx) {
	JSClassID class_id;
	class_id = JS_NewClassID(&class_id);
	classes[typeid(Array)] = class_id;

	JS_NewClass(JS_GetRuntime(ctx), class_id, &array_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, array_class_proto_funcs, _countof(array_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, array_class_constructor, "Array", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Array", ctor);

	return 0;
}

void js_init_array_module(JSContext *ctx) {
	js_array_class_init(ctx);
}

void register_array() {
	js_init_array_module(js_context());
}