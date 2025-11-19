#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_node.hpp>
#include <godot_cpp/classes/animation_node_state_machine_transition.hpp>
#include <godot_cpp/classes/animation_root_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_state_machine.hpp>
using namespace godot;

static void animation_node_state_machine_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeStateMachine"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_state_machine_class_def = {
    "AnimationNodeStateMachine",
    animation_node_state_machine_class_finalizer
};

static JSValue animation_node_state_machine_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeStateMachine"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeStateMachine *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeStateMachine *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeStateMachine);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_state_machine_class_add_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::add_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_replace_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::replace_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_remove_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::remove_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_rename_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::rename_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_has_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::has_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_node_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_node_name, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_node_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_node_list, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_set_node_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::set_node_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_node_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_node_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_has_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::has_transition, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_add_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::add_transition, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_transition, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_transition_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_transition_from, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_transition_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_transition_to, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_transition_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_transition_count, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_remove_transition_by_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::remove_transition_by_index, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_remove_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::remove_transition, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_set_graph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::set_graph_offset, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_graph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_graph_offset, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_set_state_machine_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::set_state_machine_type, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_get_state_machine_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::get_state_machine_type, ctx, this_val, argc, argv);
}
static JSValue animation_node_state_machine_class_set_allow_transition_to_self(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::set_allow_transition_to_self, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_is_allow_transition_to_self(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::is_allow_transition_to_self, ctx, this_val, argc, argv);
}
static JSValue animation_node_state_machine_class_set_reset_ends(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachine::set_reset_ends, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_class_are_ends_reset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachine::are_ends_reset, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry animation_node_state_machine_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_node", 3, &animation_node_state_machine_class_add_node),
	JS_CFUNC_DEF("replace_node", 2, &animation_node_state_machine_class_replace_node),
	JS_CFUNC_DEF("get_node", 1, &animation_node_state_machine_class_get_node),
	JS_CFUNC_DEF("remove_node", 1, &animation_node_state_machine_class_remove_node),
	JS_CFUNC_DEF("rename_node", 2, &animation_node_state_machine_class_rename_node),
	JS_CFUNC_DEF("has_node", 1, &animation_node_state_machine_class_has_node),
	JS_CFUNC_DEF("get_node_name", 1, &animation_node_state_machine_class_get_node_name),
	JS_CFUNC_DEF("get_node_list", 0, &animation_node_state_machine_class_get_node_list),
	JS_CFUNC_DEF("set_node_position", 2, &animation_node_state_machine_class_set_node_position),
	JS_CFUNC_DEF("get_node_position", 1, &animation_node_state_machine_class_get_node_position),
	JS_CFUNC_DEF("has_transition", 2, &animation_node_state_machine_class_has_transition),
	JS_CFUNC_DEF("add_transition", 3, &animation_node_state_machine_class_add_transition),
	JS_CFUNC_DEF("get_transition", 1, &animation_node_state_machine_class_get_transition),
	JS_CFUNC_DEF("get_transition_from", 1, &animation_node_state_machine_class_get_transition_from),
	JS_CFUNC_DEF("get_transition_to", 1, &animation_node_state_machine_class_get_transition_to),
	JS_CFUNC_DEF("get_transition_count", 0, &animation_node_state_machine_class_get_transition_count),
	JS_CFUNC_DEF("remove_transition_by_index", 1, &animation_node_state_machine_class_remove_transition_by_index),
	JS_CFUNC_DEF("remove_transition", 2, &animation_node_state_machine_class_remove_transition),
	JS_CFUNC_DEF("set_graph_offset", 1, &animation_node_state_machine_class_set_graph_offset),
	JS_CFUNC_DEF("get_graph_offset", 0, &animation_node_state_machine_class_get_graph_offset),
	JS_CFUNC_DEF("set_state_machine_type", 1, &animation_node_state_machine_class_set_state_machine_type),
	JS_CFUNC_DEF("get_state_machine_type", 0, &animation_node_state_machine_class_get_state_machine_type),
	JS_CFUNC_DEF("set_allow_transition_to_self", 1, &animation_node_state_machine_class_set_allow_transition_to_self),
	JS_CFUNC_DEF("is_allow_transition_to_self", 0, &animation_node_state_machine_class_is_allow_transition_to_self),
	JS_CFUNC_DEF("set_reset_ends", 1, &animation_node_state_machine_class_set_reset_ends),
	JS_CFUNC_DEF("are_ends_reset", 0, &animation_node_state_machine_class_are_ends_reset),
};




static void define_animation_node_state_machine_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "state_machine_type"),
        JS_NewCFunction(ctx, animation_node_state_machine_class_get_state_machine_type, "get_state_machine_type", 0),
        JS_NewCFunction(ctx, animation_node_state_machine_class_set_state_machine_type, "set_state_machine_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_transition_to_self"),
        JS_NewCFunction(ctx, animation_node_state_machine_class_is_allow_transition_to_self, "is_allow_transition_to_self", 0),
        JS_NewCFunction(ctx, animation_node_state_machine_class_set_allow_transition_to_self, "set_allow_transition_to_self", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reset_ends"),
        JS_NewCFunction(ctx, animation_node_state_machine_class_are_ends_reset, "are_ends_reset", 0),
        JS_NewCFunction(ctx, animation_node_state_machine_class_set_reset_ends, "set_reset_ends", 1),
        JS_PROP_GETSET
    );
}

static void define_animation_node_state_machine_enum(JSContext *ctx, JSValue ctor) {
	JSValue StateMachineType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, StateMachineType_obj, "STATE_MACHINE_TYPE_ROOT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, StateMachineType_obj, "STATE_MACHINE_TYPE_NESTED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, StateMachineType_obj, "STATE_MACHINE_TYPE_GROUPED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "StateMachineType", StateMachineType_obj);
}

static int js_animation_node_state_machine_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeStateMachine"] = class_id;
	classes_by_id[class_id] = "AnimationNodeStateMachine";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_state_machine_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationRootNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_state_machine_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_state_machine_class_proto_funcs, _countof(animation_node_state_machine_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_state_machine_class_constructor, "AnimationNodeStateMachine", 0, JS_CFUNC_constructor, 0);
	define_animation_node_state_machine_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeStateMachine", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_state_machine_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_root_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_state_machine_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeStateMachine");
	return m;
}

JSModuleDef *js_init_animation_node_state_machine_module(JSContext *ctx) {
	return _js_init_animation_node_state_machine_module(ctx, "@godot/classes/animation_node_state_machine");
}

void __register_animation_node_state_machine() {
	js_init_animation_node_state_machine_module(js_context());
}

void register_animation_node_state_machine() {
	__register_animation_node_state_machine();
}