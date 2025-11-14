#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_face_modifier3d.hpp>
using namespace godot;

static void xr_face_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRFaceModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_face_modifier3d_class_def = {
    "XRFaceModifier3D",
    xr_face_modifier3d_class_finalizer
};

static JSValue xr_face_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRFaceModifier3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XRFaceModifier3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XRFaceModifier3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XRFaceModifier3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_face_modifier3d_class_set_face_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRFaceModifier3D::set_face_tracker, ctx, this_val, argc, argv);
};
static JSValue xr_face_modifier3d_class_get_face_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<StringName> *proxy = memnew(ObjectProxy<StringName>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> StringName {
		XRFaceModifier3D *obj = static_cast<XRFaceModifier3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_face_tracker();
	};
	proxy->setter = [this_val](const StringName &value) -> void {
		XRFaceModifier3D *js_proxy = static_cast<XRFaceModifier3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_face_tracker(value);
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
static JSValue xr_face_modifier3d_class_set_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRFaceModifier3D::set_target, ctx, this_val, argc, argv);
};
static JSValue xr_face_modifier3d_class_get_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		XRFaceModifier3D *obj = static_cast<XRFaceModifier3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		XRFaceModifier3D *js_proxy = static_cast<XRFaceModifier3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry xr_face_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_face_tracker", 1, &xr_face_modifier3d_class_set_face_tracker),
	JS_CFUNC_DEF("get_face_tracker", 0, &xr_face_modifier3d_class_get_face_tracker),
	JS_CFUNC_DEF("set_target", 1, &xr_face_modifier3d_class_set_target),
	JS_CFUNC_DEF("get_target", 0, &xr_face_modifier3d_class_get_target),
};




static void define_xr_face_modifier3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "face_tracker"),
        JS_NewCFunction(ctx, xr_face_modifier3d_class_get_face_tracker, "get_face_tracker", 0),
        JS_NewCFunction(ctx, xr_face_modifier3d_class_set_face_tracker, "set_face_tracker", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target"),
        JS_NewCFunction(ctx, xr_face_modifier3d_class_get_target, "get_target", 0),
        JS_NewCFunction(ctx, xr_face_modifier3d_class_set_target, "set_target", 1),
        JS_PROP_GETSET
    );
}

static void define_xr_face_modifier3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_xr_face_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRFaceModifier3D"] = class_id;
	classes_by_id[class_id] = "XRFaceModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_face_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_face_modifier3d_property(ctx, proto);
	define_xr_face_modifier3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_face_modifier3d_class_proto_funcs, _countof(xr_face_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_face_modifier3d_class_constructor, "XRFaceModifier3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRFaceModifier3D", ctor);

	return 0;
}

JSModuleDef *_js_init_xr_face_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_face_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRFaceModifier3D");
	return m;
}

JSModuleDef *js_init_xr_face_modifier3d_module(JSContext *ctx) {
	return _js_init_xr_face_modifier3d_module(ctx, "@godot/classes/xr_face_modifier3d");
}

void __register_xr_face_modifier3d() {
	js_init_xr_face_modifier3d_module(js_context());
}

void register_xr_face_modifier3d() {
	__register_xr_face_modifier3d();
}