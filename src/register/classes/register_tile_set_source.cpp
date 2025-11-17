#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tile_set_source.hpp>
using namespace godot;

static void tile_set_source_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileSetSource"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_set_source_class_def = {
    "TileSetSource",
    tile_set_source_class_finalizer
};

static JSValue tile_set_source_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileSetSource"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileSetSource *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileSetSource *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileSetSource);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_set_source_class_get_tiles_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetSource::get_tiles_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_source_class_get_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetSource::get_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_source_class_has_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetSource::has_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_source_class_get_alternative_tiles_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetSource::get_alternative_tiles_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_source_class_get_alternative_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetSource::get_alternative_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_source_class_has_alternative_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetSource::has_alternative_tile, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry tile_set_source_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_tiles_count", 0, &tile_set_source_class_get_tiles_count),
	JS_CFUNC_DEF("get_tile_id", 1, &tile_set_source_class_get_tile_id),
	JS_CFUNC_DEF("has_tile", 1, &tile_set_source_class_has_tile),
	JS_CFUNC_DEF("get_alternative_tiles_count", 1, &tile_set_source_class_get_alternative_tiles_count),
	JS_CFUNC_DEF("get_alternative_tile_id", 2, &tile_set_source_class_get_alternative_tile_id),
	JS_CFUNC_DEF("has_alternative_tile", 2, &tile_set_source_class_has_alternative_tile),
};




static void define_tile_set_source_property(JSContext *ctx, JSValue proto) {
}

static void define_tile_set_source_enum(JSContext *ctx, JSValue ctor) {
}

static int js_tile_set_source_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileSetSource"] = class_id;
	classes_by_id[class_id] = "TileSetSource";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_set_source_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_set_source_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_set_source_class_proto_funcs, _countof(tile_set_source_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_set_source_class_constructor, "TileSetSource", 0, JS_CFUNC_constructor, 0);
	define_tile_set_source_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileSetSource", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_set_source_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_set_source_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileSetSource");
	return m;
}

JSModuleDef *js_init_tile_set_source_module(JSContext *ctx) {
	return _js_init_tile_set_source_module(ctx, "@godot/classes/tile_set_source");
}

void __register_tile_set_source() {
	js_init_tile_set_source_module(js_context());
}

void register_tile_set_source() {
	__register_tile_set_source();
}