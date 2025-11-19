#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/tile_data.hpp>
#include <godot_cpp/classes/tile_set_source.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tile_set_atlas_source.hpp>
using namespace godot;

static void tile_set_atlas_source_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TileSetAtlasSource"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef tile_set_atlas_source_class_def = {
    "TileSetAtlasSource",
    tile_set_atlas_source_class_finalizer
};

static JSValue tile_set_atlas_source_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TileSetAtlasSource"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TileSetAtlasSource *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TileSetAtlasSource *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TileSetAtlasSource);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tile_set_atlas_source_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_texture, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_texture, ctx, this_val, argc, argv);
}
static JSValue tile_set_atlas_source_class_set_margins(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_margins, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_margins(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		TileSetAtlasSource *obj = static_cast<TileSetAtlasSource *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_margins();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		TileSetAtlasSource *js_proxy = static_cast<TileSetAtlasSource *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_margins(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue tile_set_atlas_source_class_set_separation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_separation, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_separation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		TileSetAtlasSource *obj = static_cast<TileSetAtlasSource *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_separation();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		TileSetAtlasSource *js_proxy = static_cast<TileSetAtlasSource *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_separation(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue tile_set_atlas_source_class_set_texture_region_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_texture_region_size, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_texture_region_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		TileSetAtlasSource *obj = static_cast<TileSetAtlasSource *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_texture_region_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		TileSetAtlasSource *js_proxy = static_cast<TileSetAtlasSource *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_texture_region_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue tile_set_atlas_source_class_set_use_texture_padding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_use_texture_padding, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_use_texture_padding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_use_texture_padding, ctx, this_val, argc, argv);
}
static JSValue tile_set_atlas_source_class_create_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::create_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_remove_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::remove_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_move_tile_in_atlas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::move_tile_in_atlas, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_size_in_atlas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_size_in_atlas, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_has_room_for_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::has_room_for_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tiles_to_be_removed_on_change(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSetAtlasSource::get_tiles_to_be_removed_on_change, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_at_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_at_coords, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_has_tiles_outside_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::has_tiles_outside_texture, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_clear_tiles_outside_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::clear_tiles_outside_texture, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_tile_animation_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_tile_animation_columns, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_columns, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_tile_animation_separation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_tile_animation_separation, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_separation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_separation, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_tile_animation_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_tile_animation_speed, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_speed, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_tile_animation_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_tile_animation_mode, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_mode, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_tile_animation_frames_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_tile_animation_frames_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_frames_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_frames_count, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_tile_animation_frame_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_tile_animation_frame_duration, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_frame_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_frame_duration, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_animation_total_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_animation_total_duration, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_create_alternative_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TileSetAtlasSource::create_alternative_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_remove_alternative_tile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::remove_alternative_tile, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_set_alternative_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TileSetAtlasSource::set_alternative_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_next_alternative_tile_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_next_alternative_tile_id, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_data, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_atlas_grid_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_atlas_grid_size, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_tile_texture_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_tile_texture_region, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_runtime_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_runtime_texture, ctx, this_val, argc, argv);
};
static JSValue tile_set_atlas_source_class_get_runtime_tile_texture_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TileSetAtlasSource::get_runtime_tile_texture_region, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry tile_set_atlas_source_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture", 1, &tile_set_atlas_source_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &tile_set_atlas_source_class_get_texture),
	JS_CFUNC_DEF("set_margins", 1, &tile_set_atlas_source_class_set_margins),
	JS_CFUNC_DEF("get_margins", 0, &tile_set_atlas_source_class_get_margins),
	JS_CFUNC_DEF("set_separation", 1, &tile_set_atlas_source_class_set_separation),
	JS_CFUNC_DEF("get_separation", 0, &tile_set_atlas_source_class_get_separation),
	JS_CFUNC_DEF("set_texture_region_size", 1, &tile_set_atlas_source_class_set_texture_region_size),
	JS_CFUNC_DEF("get_texture_region_size", 0, &tile_set_atlas_source_class_get_texture_region_size),
	JS_CFUNC_DEF("set_use_texture_padding", 1, &tile_set_atlas_source_class_set_use_texture_padding),
	JS_CFUNC_DEF("get_use_texture_padding", 0, &tile_set_atlas_source_class_get_use_texture_padding),
	JS_CFUNC_DEF("create_tile", 2, &tile_set_atlas_source_class_create_tile),
	JS_CFUNC_DEF("remove_tile", 1, &tile_set_atlas_source_class_remove_tile),
	JS_CFUNC_DEF("move_tile_in_atlas", 3, &tile_set_atlas_source_class_move_tile_in_atlas),
	JS_CFUNC_DEF("get_tile_size_in_atlas", 1, &tile_set_atlas_source_class_get_tile_size_in_atlas),
	JS_CFUNC_DEF("has_room_for_tile", 6, &tile_set_atlas_source_class_has_room_for_tile),
	JS_CFUNC_DEF("get_tiles_to_be_removed_on_change", 4, &tile_set_atlas_source_class_get_tiles_to_be_removed_on_change),
	JS_CFUNC_DEF("get_tile_at_coords", 1, &tile_set_atlas_source_class_get_tile_at_coords),
	JS_CFUNC_DEF("has_tiles_outside_texture", 0, &tile_set_atlas_source_class_has_tiles_outside_texture),
	JS_CFUNC_DEF("clear_tiles_outside_texture", 0, &tile_set_atlas_source_class_clear_tiles_outside_texture),
	JS_CFUNC_DEF("set_tile_animation_columns", 2, &tile_set_atlas_source_class_set_tile_animation_columns),
	JS_CFUNC_DEF("get_tile_animation_columns", 1, &tile_set_atlas_source_class_get_tile_animation_columns),
	JS_CFUNC_DEF("set_tile_animation_separation", 2, &tile_set_atlas_source_class_set_tile_animation_separation),
	JS_CFUNC_DEF("get_tile_animation_separation", 1, &tile_set_atlas_source_class_get_tile_animation_separation),
	JS_CFUNC_DEF("set_tile_animation_speed", 2, &tile_set_atlas_source_class_set_tile_animation_speed),
	JS_CFUNC_DEF("get_tile_animation_speed", 1, &tile_set_atlas_source_class_get_tile_animation_speed),
	JS_CFUNC_DEF("set_tile_animation_mode", 2, &tile_set_atlas_source_class_set_tile_animation_mode),
	JS_CFUNC_DEF("get_tile_animation_mode", 1, &tile_set_atlas_source_class_get_tile_animation_mode),
	JS_CFUNC_DEF("set_tile_animation_frames_count", 2, &tile_set_atlas_source_class_set_tile_animation_frames_count),
	JS_CFUNC_DEF("get_tile_animation_frames_count", 1, &tile_set_atlas_source_class_get_tile_animation_frames_count),
	JS_CFUNC_DEF("set_tile_animation_frame_duration", 3, &tile_set_atlas_source_class_set_tile_animation_frame_duration),
	JS_CFUNC_DEF("get_tile_animation_frame_duration", 2, &tile_set_atlas_source_class_get_tile_animation_frame_duration),
	JS_CFUNC_DEF("get_tile_animation_total_duration", 1, &tile_set_atlas_source_class_get_tile_animation_total_duration),
	JS_CFUNC_DEF("create_alternative_tile", 2, &tile_set_atlas_source_class_create_alternative_tile),
	JS_CFUNC_DEF("remove_alternative_tile", 2, &tile_set_atlas_source_class_remove_alternative_tile),
	JS_CFUNC_DEF("set_alternative_tile_id", 3, &tile_set_atlas_source_class_set_alternative_tile_id),
	JS_CFUNC_DEF("get_next_alternative_tile_id", 1, &tile_set_atlas_source_class_get_next_alternative_tile_id),
	JS_CFUNC_DEF("get_tile_data", 2, &tile_set_atlas_source_class_get_tile_data),
	JS_CFUNC_DEF("get_atlas_grid_size", 0, &tile_set_atlas_source_class_get_atlas_grid_size),
	JS_CFUNC_DEF("get_tile_texture_region", 2, &tile_set_atlas_source_class_get_tile_texture_region),
	JS_CFUNC_DEF("get_runtime_texture", 0, &tile_set_atlas_source_class_get_runtime_texture),
	JS_CFUNC_DEF("get_runtime_tile_texture_region", 2, &tile_set_atlas_source_class_get_runtime_tile_texture_region),
};




static void define_tile_set_atlas_source_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margins"),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_get_margins, "get_margins", 0),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_set_margins, "set_margins", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "separation"),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_get_separation, "get_separation", 0),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_set_separation, "set_separation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_region_size"),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_get_texture_region_size, "get_texture_region_size", 0),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_set_texture_region_size, "set_texture_region_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_texture_padding"),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_get_use_texture_padding, "get_use_texture_padding", 0),
        JS_NewCFunction(ctx, tile_set_atlas_source_class_set_use_texture_padding, "set_use_texture_padding", 1),
        JS_PROP_GETSET
    );
}

static void define_tile_set_atlas_source_enum(JSContext *ctx, JSValue ctor) {
	JSValue TileAnimationMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TileAnimationMode_obj, "TILE_ANIMATION_MODE_DEFAULT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TileAnimationMode_obj, "TILE_ANIMATION_MODE_RANDOM_START_TIMES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TileAnimationMode_obj, "TILE_ANIMATION_MODE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TileAnimationMode", TileAnimationMode_obj);
}

static int js_tile_set_atlas_source_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TileSetAtlasSource"] = class_id;
	classes_by_id[class_id] = "TileSetAtlasSource";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tile_set_atlas_source_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["TileSetSource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tile_set_atlas_source_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tile_set_atlas_source_class_proto_funcs, _countof(tile_set_atlas_source_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tile_set_atlas_source_class_constructor, "TileSetAtlasSource", 0, JS_CFUNC_constructor, 0);
	define_tile_set_atlas_source_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TileSetAtlasSource", ctor);

	return 0;
}

JSModuleDef *_js_init_tile_set_atlas_source_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/tile_set_source';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tile_set_atlas_source_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TileSetAtlasSource");
	return m;
}

JSModuleDef *js_init_tile_set_atlas_source_module(JSContext *ctx) {
	return _js_init_tile_set_atlas_source_module(ctx, "@godot/classes/tile_set_atlas_source");
}

void __register_tile_set_atlas_source() {
	js_init_tile_set_atlas_source_module(js_context());
}

void register_tile_set_atlas_source() {
	__register_tile_set_atlas_source();
}