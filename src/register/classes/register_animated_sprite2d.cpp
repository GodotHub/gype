#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
using namespace godot;

static void animated_sprite2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimatedSprite2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef animated_sprite2d_class_def = {
    "AnimatedSprite2D",
    animated_sprite2d_class_finalizer
};

static JSValue animated_sprite2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimatedSprite2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimatedSprite2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimatedSprite2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimatedSprite2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animated_sprite2d_class_set_sprite_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_sprite_frames, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_sprite_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_sprite_frames, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_animation, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_animation, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_autoplay, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_autoplay, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_is_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::is_playing, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_play(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::play, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_play_backwards(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::play_backwards, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_pause(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::pause, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::stop, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_set_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_centered, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_is_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::is_centered, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_offset, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		AnimatedSprite2D *obj = static_cast<AnimatedSprite2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		AnimatedSprite2D *js_proxy = static_cast<AnimatedSprite2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue animated_sprite2d_class_set_flip_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_flip_h, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_is_flipped_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::is_flipped_h, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_flip_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_flip_v, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_is_flipped_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::is_flipped_v, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_frame, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_frame, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_frame_progress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_frame_progress, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_frame_progress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_frame_progress, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_set_frame_and_progress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_frame_and_progress, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimatedSprite2D::set_speed_scale, ctx, this_val, argc, argv);
};
static JSValue animated_sprite2d_class_get_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_speed_scale, ctx, this_val, argc, argv);
}
static JSValue animated_sprite2d_class_get_playing_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimatedSprite2D::get_playing_speed, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry animated_sprite2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_sprite_frames", 1, &animated_sprite2d_class_set_sprite_frames),
	JS_CFUNC_DEF("get_sprite_frames", 0, &animated_sprite2d_class_get_sprite_frames),
	JS_CFUNC_DEF("set_animation", 1, &animated_sprite2d_class_set_animation),
	JS_CFUNC_DEF("get_animation", 0, &animated_sprite2d_class_get_animation),
	JS_CFUNC_DEF("set_autoplay", 1, &animated_sprite2d_class_set_autoplay),
	JS_CFUNC_DEF("get_autoplay", 0, &animated_sprite2d_class_get_autoplay),
	JS_CFUNC_DEF("is_playing", 0, &animated_sprite2d_class_is_playing),
	JS_CFUNC_DEF("play", 3, &animated_sprite2d_class_play),
	JS_CFUNC_DEF("play_backwards", 1, &animated_sprite2d_class_play_backwards),
	JS_CFUNC_DEF("pause", 0, &animated_sprite2d_class_pause),
	JS_CFUNC_DEF("stop", 0, &animated_sprite2d_class_stop),
	JS_CFUNC_DEF("set_centered", 1, &animated_sprite2d_class_set_centered),
	JS_CFUNC_DEF("is_centered", 0, &animated_sprite2d_class_is_centered),
	JS_CFUNC_DEF("set_offset", 1, &animated_sprite2d_class_set_offset),
	JS_CFUNC_DEF("get_offset", 0, &animated_sprite2d_class_get_offset),
	JS_CFUNC_DEF("set_flip_h", 1, &animated_sprite2d_class_set_flip_h),
	JS_CFUNC_DEF("is_flipped_h", 0, &animated_sprite2d_class_is_flipped_h),
	JS_CFUNC_DEF("set_flip_v", 1, &animated_sprite2d_class_set_flip_v),
	JS_CFUNC_DEF("is_flipped_v", 0, &animated_sprite2d_class_is_flipped_v),
	JS_CFUNC_DEF("set_frame", 1, &animated_sprite2d_class_set_frame),
	JS_CFUNC_DEF("get_frame", 0, &animated_sprite2d_class_get_frame),
	JS_CFUNC_DEF("set_frame_progress", 1, &animated_sprite2d_class_set_frame_progress),
	JS_CFUNC_DEF("get_frame_progress", 0, &animated_sprite2d_class_get_frame_progress),
	JS_CFUNC_DEF("set_frame_and_progress", 2, &animated_sprite2d_class_set_frame_and_progress),
	JS_CFUNC_DEF("set_speed_scale", 1, &animated_sprite2d_class_set_speed_scale),
	JS_CFUNC_DEF("get_speed_scale", 0, &animated_sprite2d_class_get_speed_scale),
	JS_CFUNC_DEF("get_playing_speed", 0, &animated_sprite2d_class_get_playing_speed),
};


static JSValue animated_sprite2d_class_get_sprite_frames_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimatedSprite2D *opaque = static_cast<AnimatedSprite2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "sprite_frames_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "sprite_frames_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "sprite_frames_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animated_sprite2d_class_get_animation_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimatedSprite2D *opaque = static_cast<AnimatedSprite2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animated_sprite2d_class_get_frame_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimatedSprite2D *opaque = static_cast<AnimatedSprite2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "frame_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "frame_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "frame_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animated_sprite2d_class_get_animation_looped_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimatedSprite2D *opaque = static_cast<AnimatedSprite2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_looped_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_looped"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_looped_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animated_sprite2d_class_get_animation_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimatedSprite2D *opaque = static_cast<AnimatedSprite2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_animated_sprite2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sprite_frames"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_sprite_frames, "get_sprite_frames", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_sprite_frames, "set_sprite_frames", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "animation"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_animation, "get_animation", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_animation, "set_animation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoplay"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_autoplay, "get_autoplay", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_autoplay, "set_autoplay", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frame"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_frame, "get_frame", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_frame, "set_frame", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frame_progress"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_frame_progress, "get_frame_progress", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_frame_progress, "set_frame_progress", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "speed_scale"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_speed_scale, "get_speed_scale", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_speed_scale, "set_speed_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "centered"),
        JS_NewCFunction(ctx, animated_sprite2d_class_is_centered, "is_centered", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_centered, "set_centered", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, animated_sprite2d_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flip_h"),
        JS_NewCFunction(ctx, animated_sprite2d_class_is_flipped_h, "is_flipped_h", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_flip_h, "set_flip_h", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flip_v"),
        JS_NewCFunction(ctx, animated_sprite2d_class_is_flipped_v, "is_flipped_v", 0),
        JS_NewCFunction(ctx, animated_sprite2d_class_set_flip_v, "set_flip_v", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "sprite_frames_changed"),
		JS_NewCFunction(ctx, animated_sprite2d_class_get_sprite_frames_changed_signal, "get_sprite_frames_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_changed"),
		JS_NewCFunction(ctx, animated_sprite2d_class_get_animation_changed_signal, "get_animation_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "frame_changed"),
		JS_NewCFunction(ctx, animated_sprite2d_class_get_frame_changed_signal, "get_frame_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_looped"),
		JS_NewCFunction(ctx, animated_sprite2d_class_get_animation_looped_signal, "get_animation_looped_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_finished"),
		JS_NewCFunction(ctx, animated_sprite2d_class_get_animation_finished_signal, "get_animation_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_animated_sprite2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animated_sprite2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimatedSprite2D"] = class_id;
	classes_by_id[class_id] = "AnimatedSprite2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animated_sprite2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animated_sprite2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animated_sprite2d_class_proto_funcs, _countof(animated_sprite2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animated_sprite2d_class_constructor, "AnimatedSprite2D", 0, JS_CFUNC_constructor, 0);
	define_animated_sprite2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimatedSprite2D", ctor);

	return 0;
}

JSModuleDef *_js_init_animated_sprite2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animated_sprite2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimatedSprite2D");
	return m;
}

JSModuleDef *js_init_animated_sprite2d_module(JSContext *ctx) {
	return _js_init_animated_sprite2d_module(ctx, "@godot/classes/animated_sprite2d");
}

void __register_animated_sprite2d() {
	js_init_animated_sprite2d_module(js_context());
}

void register_animated_sprite2d() {
	__register_animated_sprite2d();
}