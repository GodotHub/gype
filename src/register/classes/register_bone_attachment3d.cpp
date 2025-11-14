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
#include <godot_cpp/classes/bone_attachment3d.hpp>
using namespace godot;

static void bone_attachment3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BoneAttachment3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef bone_attachment3d_class_def = {
    "BoneAttachment3D",
    bone_attachment3d_class_finalizer
};

static JSValue bone_attachment3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BoneAttachment3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BoneAttachment3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BoneAttachment3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BoneAttachment3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue bone_attachment3d_class_get_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&BoneAttachment3D::get_skeleton, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_set_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneAttachment3D::set_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_get_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		BoneAttachment3D *obj = static_cast<BoneAttachment3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_bone_name();
	};
	proxy->setter = [this_val](const String &value) -> void {
		BoneAttachment3D *js_proxy = static_cast<BoneAttachment3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_bone_name(value);
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
static JSValue bone_attachment3d_class_set_bone_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneAttachment3D::set_bone_idx, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_get_bone_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneAttachment3D::get_bone_idx, ctx, this_val, argc, argv);
}
static JSValue bone_attachment3d_class_on_skeleton_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneAttachment3D::on_skeleton_update, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_set_override_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneAttachment3D::set_override_pose, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_get_override_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneAttachment3D::get_override_pose, ctx, this_val, argc, argv);
}
static JSValue bone_attachment3d_class_set_use_external_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneAttachment3D::set_use_external_skeleton, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_get_use_external_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneAttachment3D::get_use_external_skeleton, ctx, this_val, argc, argv);
}
static JSValue bone_attachment3d_class_set_external_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneAttachment3D::set_external_skeleton, ctx, this_val, argc, argv);
};
static JSValue bone_attachment3d_class_get_external_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		BoneAttachment3D *obj = static_cast<BoneAttachment3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_external_skeleton();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		BoneAttachment3D *js_proxy = static_cast<BoneAttachment3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_external_skeleton(value);
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

static const JSCFunctionListEntry bone_attachment3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_skeleton", 0, &bone_attachment3d_class_get_skeleton),
	JS_CFUNC_DEF("set_bone_name", 1, &bone_attachment3d_class_set_bone_name),
	JS_CFUNC_DEF("get_bone_name", 0, &bone_attachment3d_class_get_bone_name),
	JS_CFUNC_DEF("set_bone_idx", 1, &bone_attachment3d_class_set_bone_idx),
	JS_CFUNC_DEF("get_bone_idx", 0, &bone_attachment3d_class_get_bone_idx),
	JS_CFUNC_DEF("on_skeleton_update", 0, &bone_attachment3d_class_on_skeleton_update),
	JS_CFUNC_DEF("set_override_pose", 1, &bone_attachment3d_class_set_override_pose),
	JS_CFUNC_DEF("get_override_pose", 0, &bone_attachment3d_class_get_override_pose),
	JS_CFUNC_DEF("set_use_external_skeleton", 1, &bone_attachment3d_class_set_use_external_skeleton),
	JS_CFUNC_DEF("get_use_external_skeleton", 0, &bone_attachment3d_class_get_use_external_skeleton),
	JS_CFUNC_DEF("set_external_skeleton", 1, &bone_attachment3d_class_set_external_skeleton),
	JS_CFUNC_DEF("get_external_skeleton", 0, &bone_attachment3d_class_get_external_skeleton),
};




static void define_bone_attachment3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_name"),
        JS_NewCFunction(ctx, bone_attachment3d_class_get_bone_name, "get_bone_name", 0),
        JS_NewCFunction(ctx, bone_attachment3d_class_set_bone_name, "set_bone_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_idx"),
        JS_NewCFunction(ctx, bone_attachment3d_class_get_bone_idx, "get_bone_idx", 0),
        JS_NewCFunction(ctx, bone_attachment3d_class_set_bone_idx, "set_bone_idx", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "override_pose"),
        JS_NewCFunction(ctx, bone_attachment3d_class_get_override_pose, "get_override_pose", 0),
        JS_NewCFunction(ctx, bone_attachment3d_class_set_override_pose, "set_override_pose", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_external_skeleton"),
        JS_NewCFunction(ctx, bone_attachment3d_class_get_use_external_skeleton, "get_use_external_skeleton", 0),
        JS_NewCFunction(ctx, bone_attachment3d_class_set_use_external_skeleton, "set_use_external_skeleton", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "external_skeleton"),
        JS_NewCFunction(ctx, bone_attachment3d_class_get_external_skeleton, "get_external_skeleton", 0),
        JS_NewCFunction(ctx, bone_attachment3d_class_set_external_skeleton, "set_external_skeleton", 1),
        JS_PROP_GETSET
    );
}

static void define_bone_attachment3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_bone_attachment3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BoneAttachment3D"] = class_id;
	classes_by_id[class_id] = "BoneAttachment3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &bone_attachment3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_bone_attachment3d_property(ctx, proto);
	define_bone_attachment3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, bone_attachment3d_class_proto_funcs, _countof(bone_attachment3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, bone_attachment3d_class_constructor, "BoneAttachment3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BoneAttachment3D", ctor);

	return 0;
}

JSModuleDef *_js_init_bone_attachment3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_bone_attachment3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BoneAttachment3D");
	return m;
}

JSModuleDef *js_init_bone_attachment3d_module(JSContext *ctx) {
	return _js_init_bone_attachment3d_module(ctx, "@godot/classes/bone_attachment3d");
}

void __register_bone_attachment3d() {
	js_init_bone_attachment3d_module(js_context());
}

void register_bone_attachment3d() {
	__register_bone_attachment3d();
}