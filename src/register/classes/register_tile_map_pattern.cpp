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
#include <godot_cpp/classes/tile_map_pattern.hpp>
using namespace godot;

static void tile_map_pattern_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileMapPattern"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef tile_map_pattern_class_def = {
    "TileMapPattern",
    tile_map_pattern_class_finalizer
};

static JSValue tile_map_pattern_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileMapPattern"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileMapPattern *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileMapPattern *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileMapPattern);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_map_pattern_class_set_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapPattern::set_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_has_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::has_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_remove_cell(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapPattern::remove_cell, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_get_cell_source_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::get_cell_source_id, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_get_cell_atlas_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::get_cell_atlas_coords, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_get_cell_alternative_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::get_cell_alternative_tile, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_get_used_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::get_used_cells, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::get_size, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileMapPattern::set_size, ctx, this_val, argc, argv);
};
static JSValue tile_map_pattern_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileMapPattern::is_empty, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry tile_map_pattern_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_cell", 4, &tile_map_pattern_class_set_cell),
	JS_CFUNC_DEF("has_cell", 1, &tile_map_pattern_class_has_cell),
	JS_CFUNC_DEF("remove_cell", 2, &tile_map_pattern_class_remove_cell),
	JS_CFUNC_DEF("get_cell_source_id", 1, &tile_map_pattern_class_get_cell_source_id),
	JS_CFUNC_DEF("get_cell_atlas_coords", 1, &tile_map_pattern_class_get_cell_atlas_coords),
	JS_CFUNC_DEF("get_cell_alternative_tile", 1, &tile_map_pattern_class_get_cell_alternative_tile),
	JS_CFUNC_DEF("get_used_cells", 0, &tile_map_pattern_class_get_used_cells),
	JS_CFUNC_DEF("get_size", 0, &tile_map_pattern_class_get_size),
	JS_CFUNC_DEF("set_size", 1, &tile_map_pattern_class_set_size),
	JS_CFUNC_DEF("is_empty", 0, &tile_map_pattern_class_is_empty),
};




static void define_tile_map_pattern_property(JSContext *ctx, JSValue proto) {
}

static void define_tile_map_pattern_enum(JSContext *ctx, JSValue ctor) {
}

static int js_tile_map_pattern_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileMapPattern"] = class_id;
	classes_by_id[class_id] = "TileMapPattern";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_map_pattern_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_map_pattern_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_map_pattern_class_proto_funcs, _countof(tile_map_pattern_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_map_pattern_class_constructor, "TileMapPattern", 0, JS_CFUNC_constructor, 0);
	define_tile_map_pattern_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileMapPattern", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_map_pattern_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_map_pattern_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileMapPattern");
	return m;
}

JSModuleDef *js_init_tile_map_pattern_module(JSContext *ctx) {
	return _js_init_tile_map_pattern_module(ctx, "@godot/classes/tile_map_pattern");
}

void __register_tile_map_pattern() {
	js_init_tile_map_pattern_module(js_context());
}

void register_tile_map_pattern() {
	__register_tile_map_pattern();
}