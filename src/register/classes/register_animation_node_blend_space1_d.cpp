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
#include <godot_cpp/classes/animation_node_blend_space1_d.hpp>
using namespace godot;

static void animation_node_blend_space1_d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeBlendSpace1D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_blend_space1_d_class_def = {
    "AnimationNodeBlendSpace1D",
    animation_node_blend_space1_d_class_finalizer
};

static JSValue animation_node_blend_space1_d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeBlendSpace1D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeBlendSpace1D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeBlendSpace1D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeBlendSpace1D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_blend_space1_d_class_add_blend_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::add_blend_point, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_set_blend_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_blend_point_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_blend_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_blend_point_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_set_blend_point_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_blend_point_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_blend_point_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_blend_point_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_remove_blend_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::remove_blend_point, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_blend_point_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_blend_point_count, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_set_min_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_min_space, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_min_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_min_space, ctx, this_val, argc, argv);
}
static JSValue animation_node_blend_space1_d_class_set_max_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_max_space, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_max_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_max_space, ctx, this_val, argc, argv);
}
static JSValue animation_node_blend_space1_d_class_set_snap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_snap, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_snap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_snap, ctx, this_val, argc, argv);
}
static JSValue animation_node_blend_space1_d_class_set_value_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_value_label, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_value_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		AnimationNodeBlendSpace1D *obj = static_cast<AnimationNodeBlendSpace1D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_value_label();
	};
	proxy->setter = [this_val](const String &value) -> void {
		AnimationNodeBlendSpace1D *js_proxy = static_cast<AnimationNodeBlendSpace1D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_value_label(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue animation_node_blend_space1_d_class_set_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_blend_mode, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_get_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::get_blend_mode, ctx, this_val, argc, argv);
}
static JSValue animation_node_blend_space1_d_class_set_use_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeBlendSpace1D::set_use_sync, ctx, this_val, argc, argv);
};
static JSValue animation_node_blend_space1_d_class_is_using_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeBlendSpace1D::is_using_sync, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry animation_node_blend_space1_d_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_blend_point", 3, &animation_node_blend_space1_d_class_add_blend_point),
	JS_CFUNC_DEF("set_blend_point_position", 2, &animation_node_blend_space1_d_class_set_blend_point_position),
	JS_CFUNC_DEF("get_blend_point_position", 1, &animation_node_blend_space1_d_class_get_blend_point_position),
	JS_CFUNC_DEF("set_blend_point_node", 2, &animation_node_blend_space1_d_class_set_blend_point_node),
	JS_CFUNC_DEF("get_blend_point_node", 1, &animation_node_blend_space1_d_class_get_blend_point_node),
	JS_CFUNC_DEF("remove_blend_point", 1, &animation_node_blend_space1_d_class_remove_blend_point),
	JS_CFUNC_DEF("get_blend_point_count", 0, &animation_node_blend_space1_d_class_get_blend_point_count),
	JS_CFUNC_DEF("set_min_space", 1, &animation_node_blend_space1_d_class_set_min_space),
	JS_CFUNC_DEF("get_min_space", 0, &animation_node_blend_space1_d_class_get_min_space),
	JS_CFUNC_DEF("set_max_space", 1, &animation_node_blend_space1_d_class_set_max_space),
	JS_CFUNC_DEF("get_max_space", 0, &animation_node_blend_space1_d_class_get_max_space),
	JS_CFUNC_DEF("set_snap", 1, &animation_node_blend_space1_d_class_set_snap),
	JS_CFUNC_DEF("get_snap", 0, &animation_node_blend_space1_d_class_get_snap),
	JS_CFUNC_DEF("set_value_label", 1, &animation_node_blend_space1_d_class_set_value_label),
	JS_CFUNC_DEF("get_value_label", 0, &animation_node_blend_space1_d_class_get_value_label),
	JS_CFUNC_DEF("set_blend_mode", 1, &animation_node_blend_space1_d_class_set_blend_mode),
	JS_CFUNC_DEF("get_blend_mode", 0, &animation_node_blend_space1_d_class_get_blend_mode),
	JS_CFUNC_DEF("set_use_sync", 1, &animation_node_blend_space1_d_class_set_use_sync),
	JS_CFUNC_DEF("is_using_sync", 0, &animation_node_blend_space1_d_class_is_using_sync),
};




static void define_animation_node_blend_space1_d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "min_space"),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_get_min_space, "get_min_space", 0),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_set_min_space, "set_min_space", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_space"),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_get_max_space, "get_max_space", 0),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_set_max_space, "set_max_space", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "snap"),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_get_snap, "get_snap", 0),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_set_snap, "set_snap", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "value_label"),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_get_value_label, "get_value_label", 0),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_set_value_label, "set_value_label", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_mode"),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_get_blend_mode, "get_blend_mode", 0),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_set_blend_mode, "set_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sync"),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_is_using_sync, "is_using_sync", 0),
        JS_NewCFunction(ctx, animation_node_blend_space1_d_class_set_use_sync, "set_use_sync", 1),
        JS_PROP_GETSET
    );
}

static void define_animation_node_blend_space1_d_enum(JSContext *ctx, JSValue ctor) {
	JSValue BlendMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_INTERPOLATED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_DISCRETE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_DISCRETE_CARRY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "BlendMode", BlendMode_obj);
}

static int js_animation_node_blend_space1_d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeBlendSpace1D"] = class_id;
	classes_by_id[class_id] = "AnimationNodeBlendSpace1D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_blend_space1_d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationRootNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_blend_space1_d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_blend_space1_d_class_proto_funcs, _countof(animation_node_blend_space1_d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_blend_space1_d_class_constructor, "AnimationNodeBlendSpace1D", 0, JS_CFUNC_constructor, 0);
	define_animation_node_blend_space1_d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeBlendSpace1D", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_blend_space1_d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_root_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_blend_space1_d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeBlendSpace1D");
	return m;
}

JSModuleDef *js_init_animation_node_blend_space1_d_module(JSContext *ctx) {
	return _js_init_animation_node_blend_space1_d_module(ctx, "@godot/classes/animation_node_blend_space1_d");
}

void __register_animation_node_blend_space1_d() {
	js_init_animation_node_blend_space1_d_module(js_context());
}

void register_animation_node_blend_space1_d() {
	__register_animation_node_blend_space1_d();
}