#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_mixer.hpp>
#include <godot_cpp/classes/animation_root_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_tree.hpp>
using namespace godot;

static void animation_tree_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationTree"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_tree_class_def = {
    "AnimationTree",
    animation_tree_class_finalizer
};

static JSValue animation_tree_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationTree"];
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
        instance = memnew(AnimationTree);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_tree_class_set_tree_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationTree::set_tree_root, ctx, this_val, argc, argv);
};
static JSValue animation_tree_class_get_tree_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationTree::get_tree_root, ctx, this_val, argc, argv);
}
static JSValue animation_tree_class_set_advance_expression_base_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationTree::set_advance_expression_base_node, ctx, this_val, argc, argv);
};
static JSValue animation_tree_class_get_advance_expression_base_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationTree::get_advance_expression_base_node, ctx, this_val, argc, argv);
}
static JSValue animation_tree_class_set_animation_player(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationTree::set_animation_player, ctx, this_val, argc, argv);
};
static JSValue animation_tree_class_get_animation_player(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationTree::get_animation_player, ctx, this_val, argc, argv);
}
static JSValue animation_tree_class_set_process_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationTree::set_process_callback, ctx, this_val, argc, argv);
};
static JSValue animation_tree_class_get_process_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationTree::get_process_callback, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry animation_tree_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_tree_root", 1, &animation_tree_class_set_tree_root),
	JS_CFUNC_DEF("get_tree_root", 0, &animation_tree_class_get_tree_root),
	JS_CFUNC_DEF("set_advance_expression_base_node", 1, &animation_tree_class_set_advance_expression_base_node),
	JS_CFUNC_DEF("get_advance_expression_base_node", 0, &animation_tree_class_get_advance_expression_base_node),
	JS_CFUNC_DEF("set_animation_player", 1, &animation_tree_class_set_animation_player),
	JS_CFUNC_DEF("get_animation_player", 0, &animation_tree_class_get_animation_player),
	JS_CFUNC_DEF("set_process_callback", 1, &animation_tree_class_set_process_callback),
	JS_CFUNC_DEF("get_process_callback", 0, &animation_tree_class_get_process_callback),
};


static JSValue animation_tree_class_get_animation_player_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "animation_player_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_animation_tree_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tree_root"),
        JS_NewCFunction(ctx, animation_tree_class_get_tree_root, "get_tree_root", 0),
        JS_NewCFunction(ctx, animation_tree_class_set_tree_root, "set_tree_root", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "advance_expression_base_node"),
        JS_NewCFunction(ctx, animation_tree_class_get_advance_expression_base_node, "get_advance_expression_base_node", 0),
        JS_NewCFunction(ctx, animation_tree_class_set_advance_expression_base_node, "set_advance_expression_base_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "anim_player"),
        JS_NewCFunction(ctx, animation_tree_class_get_animation_player, "get_animation_player", 0),
        JS_NewCFunction(ctx, animation_tree_class_set_animation_player, "set_animation_player", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_player_changed"),
		JS_NewCFunction(ctx, animation_tree_class_get_animation_player_changed_signal, "get_animation_player_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_animation_tree_enum(JSContext *ctx, JSValue ctor) {
	JSValue AnimationProcessCallback_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AnimationProcessCallback_obj, "ANIMATION_PROCESS_PHYSICS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AnimationProcessCallback_obj, "ANIMATION_PROCESS_IDLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AnimationProcessCallback_obj, "ANIMATION_PROCESS_MANUAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AnimationProcessCallback", AnimationProcessCallback_obj);
}

static int js_animation_tree_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationTree"] = class_id;
	classes_by_id[class_id] = "AnimationTree";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_tree_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationMixer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_tree_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_tree_class_proto_funcs, _countof(animation_tree_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_tree_class_constructor, "AnimationTree", 0, JS_CFUNC_constructor, 0);
	define_animation_tree_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationTree", ctor);
	ctor_list["AnimationTree"] = ctor;

	return 0;
}

JSModuleDef *_js_init_animation_tree_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_mixer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_tree_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationTree");
	return m;
}

JSModuleDef *js_init_animation_tree_module(JSContext *ctx) {
	return _js_init_animation_tree_module(ctx, "@godot/classes/animation_tree");
}

void __register_animation_tree() {
	js_init_animation_tree_module(js_context());
}

void register_animation_tree() {
	__register_animation_tree();
}