#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_body_modifier3d.hpp>
using namespace godot;

static void xr_body_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRBodyModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_body_modifier3d_class_def = {
    "XRBodyModifier3D",
    xr_body_modifier3d_class_finalizer
};

static JSValue xr_body_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRBodyModifier3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XRBodyModifier3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XRBodyModifier3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XRBodyModifier3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_body_modifier3d_class_set_body_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRBodyModifier3D::set_body_tracker, ctx, this_val, argc, argv);
};
static JSValue xr_body_modifier3d_class_get_body_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<StringName> *proxy = memnew(ObjectProxy<StringName>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> StringName {
		XRBodyModifier3D *obj = static_cast<XRBodyModifier3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_body_tracker();
	};
	proxy->setter = [this_val](const StringName &value) -> void {
		XRBodyModifier3D *js_proxy = static_cast<XRBodyModifier3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_body_tracker(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringNameProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringNameProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue xr_body_modifier3d_class_set_body_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRBodyModifier3D::set_body_update, ctx, this_val, argc, argv);
};
static JSValue xr_body_modifier3d_class_get_body_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRBodyModifier3D::get_body_update, ctx, this_val, argc, argv);
}
static JSValue xr_body_modifier3d_class_set_bone_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRBodyModifier3D::set_bone_update, ctx, this_val, argc, argv);
};
static JSValue xr_body_modifier3d_class_get_bone_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRBodyModifier3D::get_bone_update, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry xr_body_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_body_tracker", 1, &xr_body_modifier3d_class_set_body_tracker),
	JS_CFUNC_DEF("get_body_tracker", 0, &xr_body_modifier3d_class_get_body_tracker),
	JS_CFUNC_DEF("set_body_update", 1, &xr_body_modifier3d_class_set_body_update),
	JS_CFUNC_DEF("get_body_update", 0, &xr_body_modifier3d_class_get_body_update),
	JS_CFUNC_DEF("set_bone_update", 1, &xr_body_modifier3d_class_set_bone_update),
	JS_CFUNC_DEF("get_bone_update", 0, &xr_body_modifier3d_class_get_bone_update),
};




static void define_xr_body_modifier3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "body_tracker"),
        JS_NewCFunction(ctx, xr_body_modifier3d_class_get_body_tracker, "get_body_tracker", 0),
        JS_NewCFunction(ctx, xr_body_modifier3d_class_set_body_tracker, "set_body_tracker", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "body_update"),
        JS_NewCFunction(ctx, xr_body_modifier3d_class_get_body_update, "get_body_update", 0),
        JS_NewCFunction(ctx, xr_body_modifier3d_class_set_body_update, "set_body_update", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_update"),
        JS_NewCFunction(ctx, xr_body_modifier3d_class_get_bone_update, "get_bone_update", 0),
        JS_NewCFunction(ctx, xr_body_modifier3d_class_set_bone_update, "set_bone_update", 1),
        JS_PROP_GETSET
    );
}

static void define_xr_body_modifier3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue BodyUpdate_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BodyUpdate_obj, "BODY_UPDATE_UPPER_BODY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BodyUpdate_obj, "BODY_UPDATE_LOWER_BODY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BodyUpdate_obj, "BODY_UPDATE_HANDS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "BodyUpdate", BodyUpdate_obj);
	JSValue BoneUpdate_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BoneUpdate_obj, "BONE_UPDATE_FULL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BoneUpdate_obj, "BONE_UPDATE_ROTATION_ONLY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BoneUpdate_obj, "BONE_UPDATE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "BoneUpdate", BoneUpdate_obj);
}

static int js_xr_body_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRBodyModifier3D"] = class_id;
	classes_by_id[class_id] = "XRBodyModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_body_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModifier3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_body_modifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_body_modifier3d_class_proto_funcs, _countof(xr_body_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_body_modifier3d_class_constructor, "XRBodyModifier3D", 0, JS_CFUNC_constructor, 0);
	define_xr_body_modifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRBodyModifier3D", ctor);

	return 0;
}

JSModuleDef *_js_init_xr_body_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modifier3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_body_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRBodyModifier3D");
	return m;
}

JSModuleDef *js_init_xr_body_modifier3d_module(JSContext *ctx) {
	return _js_init_xr_body_modifier3d_module(ctx, "@godot/classes/xr_body_modifier3d");
}

void __register_xr_body_modifier3d() {
	js_init_xr_body_modifier3d_module(js_context());
}

void register_xr_body_modifier3d() {
	__register_xr_body_modifier3d();
}