#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_skin.hpp>
using namespace godot;

static void gltf_skin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFSkin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_skin_class_def = {
    "GLTFSkin",
    gltf_skin_class_finalizer
};

static JSValue gltf_skin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFSkin"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFSkin *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFSkin *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFSkin);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_skin_class_get_skin_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkin::get_skin_root, ctx, this_val, argc, argv);
}
static JSValue gltf_skin_class_set_skin_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_skin_root, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_joints_original(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFSkin *obj = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joints_original();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFSkin *js_proxy = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joints_original(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_skin_class_set_joints_original(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_joints_original, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_inverse_binds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkin::get_inverse_binds, ctx, this_val, argc, argv);
}
static JSValue gltf_skin_class_set_inverse_binds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_inverse_binds, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_joints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFSkin *obj = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joints();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFSkin *js_proxy = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joints(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_skin_class_set_joints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_joints, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_non_joints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFSkin *obj = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_non_joints();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFSkin *js_proxy = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_non_joints(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_skin_class_set_non_joints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_non_joints, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_roots(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFSkin *obj = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_roots();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFSkin *js_proxy = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_roots(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_skin_class_set_roots(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_roots, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkin::get_skeleton, ctx, this_val, argc, argv);
}
static JSValue gltf_skin_class_set_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_skeleton, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_joint_i_to_bone_i(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		GLTFSkin *obj = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joint_i_to_bone_i();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		GLTFSkin *js_proxy = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joint_i_to_bone_i(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_skin_class_set_joint_i_to_bone_i(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_joint_i_to_bone_i, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_joint_i_to_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		GLTFSkin *obj = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joint_i_to_name();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		GLTFSkin *js_proxy = static_cast<GLTFSkin *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joint_i_to_name(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_skin_class_set_joint_i_to_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_joint_i_to_name, ctx, this_val, argc, argv);
};
static JSValue gltf_skin_class_get_godot_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkin::get_godot_skin, ctx, this_val, argc, argv);
}
static JSValue gltf_skin_class_set_godot_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkin::set_godot_skin, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gltf_skin_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_skin_root", 0, &gltf_skin_class_get_skin_root),
	JS_CFUNC_DEF("set_skin_root", 1, &gltf_skin_class_set_skin_root),
	JS_CFUNC_DEF("get_joints_original", 0, &gltf_skin_class_get_joints_original),
	JS_CFUNC_DEF("set_joints_original", 1, &gltf_skin_class_set_joints_original),
	JS_CFUNC_DEF("get_inverse_binds", 0, &gltf_skin_class_get_inverse_binds),
	JS_CFUNC_DEF("set_inverse_binds", 1, &gltf_skin_class_set_inverse_binds),
	JS_CFUNC_DEF("get_joints", 0, &gltf_skin_class_get_joints),
	JS_CFUNC_DEF("set_joints", 1, &gltf_skin_class_set_joints),
	JS_CFUNC_DEF("get_non_joints", 0, &gltf_skin_class_get_non_joints),
	JS_CFUNC_DEF("set_non_joints", 1, &gltf_skin_class_set_non_joints),
	JS_CFUNC_DEF("get_roots", 0, &gltf_skin_class_get_roots),
	JS_CFUNC_DEF("set_roots", 1, &gltf_skin_class_set_roots),
	JS_CFUNC_DEF("get_skeleton", 0, &gltf_skin_class_get_skeleton),
	JS_CFUNC_DEF("set_skeleton", 1, &gltf_skin_class_set_skeleton),
	JS_CFUNC_DEF("get_joint_i_to_bone_i", 0, &gltf_skin_class_get_joint_i_to_bone_i),
	JS_CFUNC_DEF("set_joint_i_to_bone_i", 1, &gltf_skin_class_set_joint_i_to_bone_i),
	JS_CFUNC_DEF("get_joint_i_to_name", 0, &gltf_skin_class_get_joint_i_to_name),
	JS_CFUNC_DEF("set_joint_i_to_name", 1, &gltf_skin_class_set_joint_i_to_name),
	JS_CFUNC_DEF("get_godot_skin", 0, &gltf_skin_class_get_godot_skin),
	JS_CFUNC_DEF("set_godot_skin", 1, &gltf_skin_class_set_godot_skin),
};




static void define_gltf_skin_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skin_root"),
        JS_NewCFunction(ctx, gltf_skin_class_get_skin_root, "get_skin_root", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_skin_root, "set_skin_root", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joints_original"),
        JS_NewCFunction(ctx, gltf_skin_class_get_joints_original, "get_joints_original", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_joints_original, "set_joints_original", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inverse_binds"),
        JS_NewCFunction(ctx, gltf_skin_class_get_inverse_binds, "get_inverse_binds", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_inverse_binds, "set_inverse_binds", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joints"),
        JS_NewCFunction(ctx, gltf_skin_class_get_joints, "get_joints", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_joints, "set_joints", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "non_joints"),
        JS_NewCFunction(ctx, gltf_skin_class_get_non_joints, "get_non_joints", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_non_joints, "set_non_joints", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "roots"),
        JS_NewCFunction(ctx, gltf_skin_class_get_roots, "get_roots", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_roots, "set_roots", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skeleton"),
        JS_NewCFunction(ctx, gltf_skin_class_get_skeleton, "get_skeleton", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_skeleton, "set_skeleton", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joint_i_to_bone_i"),
        JS_NewCFunction(ctx, gltf_skin_class_get_joint_i_to_bone_i, "get_joint_i_to_bone_i", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_joint_i_to_bone_i, "set_joint_i_to_bone_i", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joint_i_to_name"),
        JS_NewCFunction(ctx, gltf_skin_class_get_joint_i_to_name, "get_joint_i_to_name", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_joint_i_to_name, "set_joint_i_to_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "godot_skin"),
        JS_NewCFunction(ctx, gltf_skin_class_get_godot_skin, "get_godot_skin", 0),
        JS_NewCFunction(ctx, gltf_skin_class_set_godot_skin, "set_godot_skin", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_skin_enum(JSContext *ctx, JSValue proto) {
}

static int js_gltf_skin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFSkin"] = class_id;
	classes_by_id[class_id] = "GLTFSkin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_skin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_skin_property(ctx, proto);
	define_gltf_skin_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_skin_class_proto_funcs, _countof(gltf_skin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_skin_class_constructor, "GLTFSkin", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFSkin", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_skin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_skin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFSkin");
	return m;
}

JSModuleDef *js_init_gltf_skin_module(JSContext *ctx) {
	return _js_init_gltf_skin_module(ctx, "@godot/classes/gltf_skin");
}

void __register_gltf_skin() {
	js_init_gltf_skin_module(js_context());
}

void register_gltf_skin() {
	__register_gltf_skin();
}