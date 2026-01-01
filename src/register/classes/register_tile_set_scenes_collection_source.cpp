#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/tile_set_source.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tile_set_scenes_collection_source.hpp>
using namespace godot;

static void tile_set_scenes_collection_source_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileSetScenesCollectionSource"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_set_scenes_collection_source_class_def = {
    "TileSetScenesCollectionSource",
    tile_set_scenes_collection_source_class_finalizer
};

static JSValue tile_set_scenes_collection_source_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileSetScenesCollectionSource"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(TileSetScenesCollectionSource);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_set_scenes_collection_source_class_get_scene_tiles_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSetScenesCollectionSource::get_scene_tiles_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_get_scene_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSetScenesCollectionSource::get_scene_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_has_scene_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSetScenesCollectionSource::has_scene_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_create_scene_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSetScenesCollectionSource::create_scene_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_set_scene_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetScenesCollectionSource::set_scene_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_set_scene_tile_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetScenesCollectionSource::set_scene_tile_scene, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_get_scene_tile_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetScenesCollectionSource::get_scene_tile_scene, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_set_scene_tile_display_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetScenesCollectionSource::set_scene_tile_display_placeholder, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_get_scene_tile_display_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetScenesCollectionSource::get_scene_tile_display_placeholder, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_remove_scene_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetScenesCollectionSource::remove_scene_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_scenes_collection_source_class_get_next_scene_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetScenesCollectionSource::get_next_scene_tile_id, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry tile_set_scenes_collection_source_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_scene_tiles_count", 0, &tile_set_scenes_collection_source_class_get_scene_tiles_count),
	JS_CFUNC_DEF("get_scene_tile_id", 1, &tile_set_scenes_collection_source_class_get_scene_tile_id),
	JS_CFUNC_DEF("has_scene_tile_id", 1, &tile_set_scenes_collection_source_class_has_scene_tile_id),
	JS_CFUNC_DEF("create_scene_tile", 2, &tile_set_scenes_collection_source_class_create_scene_tile),
	JS_CFUNC_DEF("set_scene_tile_id", 2, &tile_set_scenes_collection_source_class_set_scene_tile_id),
	JS_CFUNC_DEF("set_scene_tile_scene", 2, &tile_set_scenes_collection_source_class_set_scene_tile_scene),
	JS_CFUNC_DEF("get_scene_tile_scene", 1, &tile_set_scenes_collection_source_class_get_scene_tile_scene),
	JS_CFUNC_DEF("set_scene_tile_display_placeholder", 2, &tile_set_scenes_collection_source_class_set_scene_tile_display_placeholder),
	JS_CFUNC_DEF("get_scene_tile_display_placeholder", 1, &tile_set_scenes_collection_source_class_get_scene_tile_display_placeholder),
	JS_CFUNC_DEF("remove_scene_tile", 1, &tile_set_scenes_collection_source_class_remove_scene_tile),
	JS_CFUNC_DEF("get_next_scene_tile_id", 0, &tile_set_scenes_collection_source_class_get_next_scene_tile_id),
};




static void define_tile_set_scenes_collection_source_property(JSContext *ctx, JSValue proto) {
}

static void define_tile_set_scenes_collection_source_enum(JSContext *ctx, JSValue ctor) {
}

static int js_tile_set_scenes_collection_source_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileSetScenesCollectionSource"] = class_id;
	classes_by_id[class_id] = "TileSetScenesCollectionSource";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_set_scenes_collection_source_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["TileSetSource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_set_scenes_collection_source_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_set_scenes_collection_source_class_proto_funcs, _countof(tile_set_scenes_collection_source_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_set_scenes_collection_source_class_constructor, "TileSetScenesCollectionSource", 0, JS_CFUNC_constructor, 0);
	define_tile_set_scenes_collection_source_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileSetScenesCollectionSource", ctor);
	ctor_list["TileSetScenesCollectionSource"] = ctor;

	return 0;
}

JSModuleDef *_js_init_tile_set_scenes_collection_source_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/tile_set_source';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_set_scenes_collection_source_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileSetScenesCollectionSource");
	return m;
}

JSModuleDef *js_init_tile_set_scenes_collection_source_module(JSContext *ctx) {
	return _js_init_tile_set_scenes_collection_source_module(ctx, "@godot/classes/tile_set_scenes_collection_source");
}

void __register_tile_set_scenes_collection_source() {
	js_init_tile_set_scenes_collection_source_module(js_context());
}

void register_tile_set_scenes_collection_source() {
	__register_tile_set_scenes_collection_source();
}