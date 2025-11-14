#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
using namespace godot;

static void skeleton_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_modifier3d_class_def = {
    "SkeletonModifier3D",
    skeleton_modifier3d_class_finalizer
};

static JSValue skeleton_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModifier3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SkeletonModifier3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SkeletonModifier3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SkeletonModifier3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modifier3d_class_get_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModifier3D::get_skeleton, ctx, this_val, argc, argv);
};
static JSValue skeleton_modifier3d_class_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModifier3D::set_active, ctx, this_val, argc, argv);
};
static JSValue skeleton_modifier3d_class_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModifier3D::is_active, ctx, this_val, argc, argv);
}
static JSValue skeleton_modifier3d_class_set_influence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModifier3D::set_influence, ctx, this_val, argc, argv);
};
static JSValue skeleton_modifier3d_class_get_influence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModifier3D::get_influence, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry skeleton_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_skeleton", 0, &skeleton_modifier3d_class_get_skeleton),
	JS_CFUNC_DEF("set_active", 1, &skeleton_modifier3d_class_set_active),
	JS_CFUNC_DEF("is_active", 0, &skeleton_modifier3d_class_is_active),
	JS_CFUNC_DEF("set_influence", 1, &skeleton_modifier3d_class_set_influence),
	JS_CFUNC_DEF("get_influence", 0, &skeleton_modifier3d_class_get_influence),
};


static JSValue skeleton_modifier3d_class_get_modification_processed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SkeletonModifier3D *opaque = static_cast<SkeletonModifier3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "modification_processed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "modification_processed"));
		JS_DefinePropertyValueStr(ctx, this_val, "modification_processed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_skeleton_modifier3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "active"),
        JS_NewCFunction(ctx, skeleton_modifier3d_class_is_active, "is_active", 0),
        JS_NewCFunction(ctx, skeleton_modifier3d_class_set_active, "set_active", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "influence"),
        JS_NewCFunction(ctx, skeleton_modifier3d_class_get_influence, "get_influence", 0),
        JS_NewCFunction(ctx, skeleton_modifier3d_class_set_influence, "set_influence", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "modification_processed"),
		JS_NewCFunction(ctx, skeleton_modifier3d_class_get_modification_processed_signal, "get_modification_processed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_skeleton_modifier3d_enum(JSContext *ctx, JSValue proto) {
	JSValue BoneAxis_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BoneAxis_obj, "BONE_AXIS_PLUS_X", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BoneAxis_obj, "BONE_AXIS_MINUS_X", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BoneAxis_obj, "BONE_AXIS_PLUS_Y", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BoneAxis_obj, "BONE_AXIS_MINUS_Y", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BoneAxis_obj, "BONE_AXIS_PLUS_Z", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BoneAxis_obj, "BONE_AXIS_MINUS_Z", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, proto, "BoneAxis", BoneAxis_obj);
}

static int js_skeleton_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModifier3D"] = class_id;
	classes_by_id[class_id] = "SkeletonModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modifier3d_property(ctx, proto);
	define_skeleton_modifier3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modifier3d_class_proto_funcs, _countof(skeleton_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modifier3d_class_constructor, "SkeletonModifier3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModifier3D", ctor);

	return 0;
}

JSModuleDef *_js_init_skeleton_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModifier3D");
	return m;
}

JSModuleDef *js_init_skeleton_modifier3d_module(JSContext *ctx) {
	return _js_init_skeleton_modifier3d_module(ctx, "@godot/classes/skeleton_modifier3d");
}

void __register_skeleton_modifier3d() {
	js_init_skeleton_modifier3d_module(js_context());
}

void register_skeleton_modifier3d() {
	__register_skeleton_modifier3d();
}