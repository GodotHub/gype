#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_node_sync.hpp>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_transition.hpp>
using namespace godot;

static void animation_node_transition_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeTransition"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef animation_node_transition_class_def = {
    "AnimationNodeTransition",
    animation_node_transition_class_finalizer
};

static JSValue animation_node_transition_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeTransition"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeTransition *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeTransition *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeTransition);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_transition_class_set_input_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_input_count, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_set_input_as_auto_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_input_as_auto_advance, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_is_input_set_as_auto_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTransition::is_input_set_as_auto_advance, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_set_input_break_loop_at_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_input_break_loop_at_end, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_is_input_loop_broken_at_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTransition::is_input_loop_broken_at_end, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_set_input_reset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_input_reset, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_is_input_reset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTransition::is_input_reset, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_set_xfade_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_xfade_time, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_get_xfade_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTransition::get_xfade_time, ctx, this_val, argc, argv);
}
static JSValue animation_node_transition_class_set_xfade_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_xfade_curve, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_get_xfade_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTransition::get_xfade_curve, ctx, this_val, argc, argv);
}
static JSValue animation_node_transition_class_set_allow_transition_to_self(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTransition::set_allow_transition_to_self, ctx, this_val, argc, argv);
};
static JSValue animation_node_transition_class_is_allow_transition_to_self(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTransition::is_allow_transition_to_self, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry animation_node_transition_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_input_count", 1, &animation_node_transition_class_set_input_count),
	JS_CFUNC_DEF("set_input_as_auto_advance", 2, &animation_node_transition_class_set_input_as_auto_advance),
	JS_CFUNC_DEF("is_input_set_as_auto_advance", 1, &animation_node_transition_class_is_input_set_as_auto_advance),
	JS_CFUNC_DEF("set_input_break_loop_at_end", 2, &animation_node_transition_class_set_input_break_loop_at_end),
	JS_CFUNC_DEF("is_input_loop_broken_at_end", 1, &animation_node_transition_class_is_input_loop_broken_at_end),
	JS_CFUNC_DEF("set_input_reset", 2, &animation_node_transition_class_set_input_reset),
	JS_CFUNC_DEF("is_input_reset", 1, &animation_node_transition_class_is_input_reset),
	JS_CFUNC_DEF("set_xfade_time", 1, &animation_node_transition_class_set_xfade_time),
	JS_CFUNC_DEF("get_xfade_time", 0, &animation_node_transition_class_get_xfade_time),
	JS_CFUNC_DEF("set_xfade_curve", 1, &animation_node_transition_class_set_xfade_curve),
	JS_CFUNC_DEF("get_xfade_curve", 0, &animation_node_transition_class_get_xfade_curve),
	JS_CFUNC_DEF("set_allow_transition_to_self", 1, &animation_node_transition_class_set_allow_transition_to_self),
	JS_CFUNC_DEF("is_allow_transition_to_self", 0, &animation_node_transition_class_is_allow_transition_to_self),
};




static void define_animation_node_transition_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "xfade_time"),
        JS_NewCFunction(ctx, animation_node_transition_class_get_xfade_time, "get_xfade_time", 0),
        JS_NewCFunction(ctx, animation_node_transition_class_set_xfade_time, "set_xfade_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "xfade_curve"),
        JS_NewCFunction(ctx, animation_node_transition_class_get_xfade_curve, "get_xfade_curve", 0),
        JS_NewCFunction(ctx, animation_node_transition_class_set_xfade_curve, "set_xfade_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_transition_to_self"),
        JS_NewCFunction(ctx, animation_node_transition_class_is_allow_transition_to_self, "is_allow_transition_to_self", 0),
        JS_NewCFunction(ctx, animation_node_transition_class_set_allow_transition_to_self, "set_allow_transition_to_self", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_count"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, animation_node_transition_class_set_input_count, "set_input_count", 1),
        JS_PROP_GETSET
    );
}

static void define_animation_node_transition_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animation_node_transition_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeTransition"] = class_id;
	classes_by_id[class_id] = "AnimationNodeTransition";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_transition_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationNodeSync"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_transition_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_transition_class_proto_funcs, _countof(animation_node_transition_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_transition_class_constructor, "AnimationNodeTransition", 0, JS_CFUNC_constructor, 0);
	define_animation_node_transition_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeTransition", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_transition_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_node_sync';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_transition_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeTransition");
	return m;
}

JSModuleDef *js_init_animation_node_transition_module(JSContext *ctx) {
	return _js_init_animation_node_transition_module(ctx, "@godot/classes/animation_node_transition");
}

void __register_animation_node_transition() {
	js_init_animation_node_transition_module(js_context());
}

void register_animation_node_transition() {
	__register_animation_node_transition();
}