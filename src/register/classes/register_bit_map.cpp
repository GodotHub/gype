#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/bit_map.hpp>
using namespace godot;

static void bit_map_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BitMap"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef bit_map_class_def = {
    "BitMap",
    bit_map_class_finalizer
};

static JSValue bit_map_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BitMap"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BitMap *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BitMap *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BitMap);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue bit_map_class_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::create, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_create_from_image_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::create_from_image_alpha, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_set_bitv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::set_bitv, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_set_bit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::set_bit, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_get_bitv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BitMap::get_bitv, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_get_bit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BitMap::get_bit, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_set_bit_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::set_bit_rect, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_get_true_bit_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BitMap::get_true_bit_count, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BitMap::get_size, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::resize, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_grow_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BitMap::grow_mask, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_convert_to_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BitMap::convert_to_image, ctx, this_val, argc, argv);
};
static JSValue bit_map_class_opaque_to_polygons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BitMap::opaque_to_polygons, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry bit_map_class_proto_funcs[] = {
	JS_CFUNC_DEF("create", 1, &bit_map_class_create),
	JS_CFUNC_DEF("create_from_image_alpha", 2, &bit_map_class_create_from_image_alpha),
	JS_CFUNC_DEF("set_bitv", 2, &bit_map_class_set_bitv),
	JS_CFUNC_DEF("set_bit", 3, &bit_map_class_set_bit),
	JS_CFUNC_DEF("get_bitv", 1, &bit_map_class_get_bitv),
	JS_CFUNC_DEF("get_bit", 2, &bit_map_class_get_bit),
	JS_CFUNC_DEF("set_bit_rect", 2, &bit_map_class_set_bit_rect),
	JS_CFUNC_DEF("get_true_bit_count", 0, &bit_map_class_get_true_bit_count),
	JS_CFUNC_DEF("get_size", 0, &bit_map_class_get_size),
	JS_CFUNC_DEF("resize", 1, &bit_map_class_resize),
	JS_CFUNC_DEF("grow_mask", 2, &bit_map_class_grow_mask),
	JS_CFUNC_DEF("convert_to_image", 0, &bit_map_class_convert_to_image),
	JS_CFUNC_DEF("opaque_to_polygons", 2, &bit_map_class_opaque_to_polygons),
};




static void define_bit_map_property(JSContext *ctx, JSValue proto) {
}

static void define_bit_map_enum(JSContext *ctx, JSValue ctor) {
}

static int js_bit_map_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BitMap"] = class_id;
	classes_by_id[class_id] = "BitMap";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &bit_map_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_bit_map_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, bit_map_class_proto_funcs, _countof(bit_map_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, bit_map_class_constructor, "BitMap", 0, JS_CFUNC_constructor, 0);
	define_bit_map_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BitMap", ctor);

	return 0;
}

JSModuleDef *_js_init_bit_map_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_bit_map_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BitMap");
	return m;
}

JSModuleDef *js_init_bit_map_module(JSContext *ctx) {
	return _js_init_bit_map_module(ctx, "@godot/classes/bit_map");
}

void __register_bit_map() {
	js_init_bit_map_module(js_context());
}

void register_bit_map() {
	__register_bit_map();
}