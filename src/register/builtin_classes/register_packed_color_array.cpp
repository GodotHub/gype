#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/packed_color_array.hpp>

using namespace godot;

static void packed_color_array_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PackedColorArray"];
	PackedColorArray *opaque_ptr = static_cast<PackedColorArray *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef packed_color_array_class_def = {
	"PackedColorArray",
	.finalizer = packed_color_array_class_finalizer
};

static JSValue packed_color_array_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["PackedColorArray"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	PackedColorArray *instance = nullptr;	if (argc == 0) {
		instance = memnew(PackedColorArray());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::PACKED_COLOR_ARRAY) {
		PackedColorArray v0 = VariantAdapter(argv[0]).get<PackedColorArray>();
		instance = memnew(PackedColorArray(v0));
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::ARRAY) {
		Array v0 = VariantAdapter(argv[0]).get<Array>();
		instance = memnew(PackedColorArray(v0));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
	return obj;
}
static JSValue packed_color_array_class_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::get, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::set, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::size, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::is_empty, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_push_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::push_back, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_append(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::append, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_append_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::append_array, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_remove_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::remove_at, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::insert, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::fill, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::resize, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::clear, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::has, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::reverse, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::slice, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_to_byte_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::to_byte_array, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_sort(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	call_builtin_method_no_ret(&PackedColorArray::sort, ctx, this_val, argc, argv);
    return JS_UNDEFINED;
}
static JSValue packed_color_array_class_bsearch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::bsearch, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::duplicate, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::find, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::rfind, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PackedColorArray::count, ctx, this_val, argc, argv);
}
static JSValue packed_color_array_class_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PackedColorArray::erase, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry packed_color_array_class_proto_funcs[] = {
	JS_CFUNC_DEF("get", 1, &packed_color_array_class_get),
	JS_CFUNC_DEF("set", 2, &packed_color_array_class_set),
	JS_CFUNC_DEF("size", 0, &packed_color_array_class_size),
	JS_CFUNC_DEF("is_empty", 0, &packed_color_array_class_is_empty),
	JS_CFUNC_DEF("push_back", 1, &packed_color_array_class_push_back),
	JS_CFUNC_DEF("append", 1, &packed_color_array_class_append),
	JS_CFUNC_DEF("append_array", 1, &packed_color_array_class_append_array),
	JS_CFUNC_DEF("remove_at", 1, &packed_color_array_class_remove_at),
	JS_CFUNC_DEF("insert", 2, &packed_color_array_class_insert),
	JS_CFUNC_DEF("fill", 1, &packed_color_array_class_fill),
	JS_CFUNC_DEF("resize", 1, &packed_color_array_class_resize),
	JS_CFUNC_DEF("clear", 0, &packed_color_array_class_clear),
	JS_CFUNC_DEF("has", 1, &packed_color_array_class_has),
	JS_CFUNC_DEF("reverse", 0, &packed_color_array_class_reverse),
	JS_CFUNC_DEF("slice", 2, &packed_color_array_class_slice),
	JS_CFUNC_DEF("to_byte_array", 0, &packed_color_array_class_to_byte_array),
	JS_CFUNC_DEF("sort", 0, &packed_color_array_class_sort),
	JS_CFUNC_DEF("bsearch", 2, &packed_color_array_class_bsearch),
	JS_CFUNC_DEF("duplicate", 0, &packed_color_array_class_duplicate),
	JS_CFUNC_DEF("find", 2, &packed_color_array_class_find),
	JS_CFUNC_DEF("rfind", 2, &packed_color_array_class_rfind),
	JS_CFUNC_DEF("count", 1, &packed_color_array_class_count),
	JS_CFUNC_DEF("erase", 1, &packed_color_array_class_erase),
};


static int js_packed_color_array_class_init(JSContext *ctx) {
	classes["PackedColorArray"] = 0;
	classes["PackedColorArray"] = JS_NewClassID(&classes["PackedColorArray"]);
	JSClassID class_id = classes["PackedColorArray"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &packed_color_array_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, packed_color_array_class_proto_funcs, _countof(packed_color_array_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, packed_color_array_class_constructor, "PackedColorArray", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "PackedColorArray", ctor);

	return 0;
}

void js_init_packed_color_array_module(JSContext *ctx) {
	js_packed_color_array_class_init(ctx);
}

void register_packed_color_array() {
	js_init_packed_color_array_module(js_context());
}