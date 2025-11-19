#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_node.hpp>
#include <godot_cpp/classes/animation_root_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_blend_tree.hpp>
using namespace godot;

static void animation_node_blend_tree_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeBlendTree"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_blend_tree_class_def = {
    "AnimationNodeBlendTree",
    animation_node_blend_tree_class_finalizer
};

static JSValue animation_node_blend_tree_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeBlendTree"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeBlendTree *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeBlendTree *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeBlendTree);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_blend_tree_class_add_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::add_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_get_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendTree::get_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_remove_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::remove_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_rename_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::rename_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_has_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendTree::has_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_connect_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::connect_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_disconnect_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::disconnect_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_get_node_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendTree::get_node_list, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_set_node_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::set_node_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_get_node_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendTree::get_node_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_set_graph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendTree::set_graph_offset, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_tree_class_get_graph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		AnimationNodeBlendTree *obj = static_cast<AnimationNodeBlendTree *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_graph_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		AnimationNodeBlendTree *js_proxy = static_cast<AnimationNodeBlendTree *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_graph_offset(value);
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



static const JSCFunctionListEntry animation_node_blend_tree_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_node", 3, &animation_node_blend_tree_class_add_node),
	JS_CFUNC_DEF("get_node", 1, &animation_node_blend_tree_class_get_node),
	JS_CFUNC_DEF("remove_node", 1, &animation_node_blend_tree_class_remove_node),
	JS_CFUNC_DEF("rename_node", 2, &animation_node_blend_tree_class_rename_node),
	JS_CFUNC_DEF("has_node", 1, &animation_node_blend_tree_class_has_node),
	JS_CFUNC_DEF("connect_node", 3, &animation_node_blend_tree_class_connect_node),
	JS_CFUNC_DEF("disconnect_node", 2, &animation_node_blend_tree_class_disconnect_node),
	JS_CFUNC_DEF("get_node_list", 0, &animation_node_blend_tree_class_get_node_list),
	JS_CFUNC_DEF("set_node_position", 2, &animation_node_blend_tree_class_set_node_position),
	JS_CFUNC_DEF("get_node_position", 1, &animation_node_blend_tree_class_get_node_position),
	JS_CFUNC_DEF("set_graph_offset", 1, &animation_node_blend_tree_class_set_graph_offset),
	JS_CFUNC_DEF("get_graph_offset", 0, &animation_node_blend_tree_class_get_graph_offset),
};


static JSValue animation_node_blend_tree_class_get_node_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationNodeBlendTree *opaque = static_cast<AnimationNodeBlendTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_animation_node_blend_tree_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "graph_offset"),
        JS_NewCFunction(ctx, animation_node_blend_tree_class_get_graph_offset, "get_graph_offset", 0),
        JS_NewCFunction(ctx, animation_node_blend_tree_class_set_graph_offset, "set_graph_offset", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_changed"),
		JS_NewCFunction(ctx, animation_node_blend_tree_class_get_node_changed_signal, "get_node_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_animation_node_blend_tree_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animation_node_blend_tree_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeBlendTree"] = class_id;
	classes_by_id[class_id] = "AnimationNodeBlendTree";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_blend_tree_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationRootNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_blend_tree_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_blend_tree_class_proto_funcs, _countof(animation_node_blend_tree_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_blend_tree_class_constructor, "AnimationNodeBlendTree", 0, JS_CFUNC_constructor, 0);
	define_animation_node_blend_tree_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeBlendTree", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_blend_tree_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_root_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_blend_tree_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeBlendTree");
	return m;
}

JSModuleDef *js_init_animation_node_blend_tree_module(JSContext *ctx) {
	return _js_init_animation_node_blend_tree_module(ctx, "@godot/classes/animation_node_blend_tree");
}

void __register_animation_node_blend_tree() {
	js_init_animation_node_blend_tree_module(js_context());
}

void register_animation_node_blend_tree() {
	__register_animation_node_blend_tree();
}