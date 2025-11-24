#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_root_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_animation.hpp>
using namespace godot;

static void animation_node_animation_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeAnimation"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_animation_class_def = {
    "AnimationNodeAnimation",
    animation_node_animation_class_finalizer
};

static JSValue animation_node_animation_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeAnimation"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeAnimation *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeAnimation *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeAnimation);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_animation_class_set_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_animation, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_get_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::get_animation, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_play_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_play_mode, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_get_play_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::get_play_mode, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_advance_on_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_advance_on_start, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_is_advance_on_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::is_advance_on_start, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_use_custom_timeline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_use_custom_timeline, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_is_using_custom_timeline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::is_using_custom_timeline, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_timeline_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_timeline_length, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_get_timeline_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::get_timeline_length, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_stretch_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_stretch_time_scale, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_is_stretching_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::is_stretching_time_scale, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_start_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_start_offset, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_get_start_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::get_start_offset, ctx, this_val, argc, argv);
}
static JSValue animation_node_animation_class_set_loop_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeAnimation::set_loop_mode, ctx, this_val, argc, argv);
};
static JSValue animation_node_animation_class_get_loop_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeAnimation::get_loop_mode, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry animation_node_animation_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_animation", 1, &animation_node_animation_class_set_animation),
	JS_CFUNC_DEF("get_animation", 0, &animation_node_animation_class_get_animation),
	JS_CFUNC_DEF("set_play_mode", 1, &animation_node_animation_class_set_play_mode),
	JS_CFUNC_DEF("get_play_mode", 0, &animation_node_animation_class_get_play_mode),
	JS_CFUNC_DEF("set_advance_on_start", 1, &animation_node_animation_class_set_advance_on_start),
	JS_CFUNC_DEF("is_advance_on_start", 0, &animation_node_animation_class_is_advance_on_start),
	JS_CFUNC_DEF("set_use_custom_timeline", 1, &animation_node_animation_class_set_use_custom_timeline),
	JS_CFUNC_DEF("is_using_custom_timeline", 0, &animation_node_animation_class_is_using_custom_timeline),
	JS_CFUNC_DEF("set_timeline_length", 1, &animation_node_animation_class_set_timeline_length),
	JS_CFUNC_DEF("get_timeline_length", 0, &animation_node_animation_class_get_timeline_length),
	JS_CFUNC_DEF("set_stretch_time_scale", 1, &animation_node_animation_class_set_stretch_time_scale),
	JS_CFUNC_DEF("is_stretching_time_scale", 0, &animation_node_animation_class_is_stretching_time_scale),
	JS_CFUNC_DEF("set_start_offset", 1, &animation_node_animation_class_set_start_offset),
	JS_CFUNC_DEF("get_start_offset", 0, &animation_node_animation_class_get_start_offset),
	JS_CFUNC_DEF("set_loop_mode", 1, &animation_node_animation_class_set_loop_mode),
	JS_CFUNC_DEF("get_loop_mode", 0, &animation_node_animation_class_get_loop_mode),
};




static void define_animation_node_animation_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "animation"),
        JS_NewCFunction(ctx, animation_node_animation_class_get_animation, "get_animation", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_animation, "set_animation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "play_mode"),
        JS_NewCFunction(ctx, animation_node_animation_class_get_play_mode, "get_play_mode", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_play_mode, "set_play_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "advance_on_start"),
        JS_NewCFunction(ctx, animation_node_animation_class_is_advance_on_start, "is_advance_on_start", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_advance_on_start, "set_advance_on_start", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_custom_timeline"),
        JS_NewCFunction(ctx, animation_node_animation_class_is_using_custom_timeline, "is_using_custom_timeline", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_use_custom_timeline, "set_use_custom_timeline", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "timeline_length"),
        JS_NewCFunction(ctx, animation_node_animation_class_get_timeline_length, "get_timeline_length", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_timeline_length, "set_timeline_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stretch_time_scale"),
        JS_NewCFunction(ctx, animation_node_animation_class_is_stretching_time_scale, "is_stretching_time_scale", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_stretch_time_scale, "set_stretch_time_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "start_offset"),
        JS_NewCFunction(ctx, animation_node_animation_class_get_start_offset, "get_start_offset", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_start_offset, "set_start_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop_mode"),
        JS_NewCFunction(ctx, animation_node_animation_class_get_loop_mode, "get_loop_mode", 0),
        JS_NewCFunction(ctx, animation_node_animation_class_set_loop_mode, "set_loop_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_animation_node_animation_enum(JSContext *ctx, JSValue ctor) {
	JSValue PlayMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PlayMode_obj, "PLAY_MODE_FORWARD", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PlayMode_obj, "PLAY_MODE_BACKWARD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "PlayMode", PlayMode_obj);
}

static int js_animation_node_animation_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeAnimation"] = class_id;
	classes_by_id[class_id] = "AnimationNodeAnimation";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_animation_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationRootNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_animation_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_animation_class_proto_funcs, _countof(animation_node_animation_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_animation_class_constructor, "AnimationNodeAnimation", 0, JS_CFUNC_constructor, 0);
	define_animation_node_animation_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeAnimation", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_animation_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_root_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_animation_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeAnimation");
	return m;
}

JSModuleDef *js_init_animation_node_animation_module(JSContext *ctx) {
	return _js_init_animation_node_animation_module(ctx, "@godot/classes/animation_node_animation");
}

void __register_animation_node_animation() {
	js_init_animation_node_animation_module(js_context());
}

void register_animation_node_animation() {
	__register_animation_node_animation();
}