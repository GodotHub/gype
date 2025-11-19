#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/bone_attachment3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_skeleton.hpp>
using namespace godot;

static void gltf_skeleton_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFSkeleton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_skeleton_class_def = {
    "GLTFSkeleton",
    gltf_skeleton_class_finalizer
};

static JSValue gltf_skeleton_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFSkeleton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFSkeleton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFSkeleton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFSkeleton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_skeleton_class_get_joints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFSkeleton *obj = static_cast<GLTFSkeleton *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joints();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFSkeleton *js_proxy = static_cast<GLTFSkeleton *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joints(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_skeleton_class_set_joints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkeleton::set_joints, ctx, this_val, argc, argv);
};
static JSValue gltf_skeleton_class_get_roots(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFSkeleton *obj = static_cast<GLTFSkeleton *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_roots();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFSkeleton *js_proxy = static_cast<GLTFSkeleton *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_roots(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_skeleton_class_set_roots(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkeleton::set_roots, ctx, this_val, argc, argv);
};
static JSValue gltf_skeleton_class_get_godot_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkeleton::get_godot_skeleton, ctx, this_val, argc, argv);
};
static JSValue gltf_skeleton_class_get_unique_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkeleton::get_unique_names, ctx, this_val, argc, argv);
}
static JSValue gltf_skeleton_class_set_unique_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkeleton::set_unique_names, ctx, this_val, argc, argv);
};
static JSValue gltf_skeleton_class_get_godot_bone_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		GLTFSkeleton *obj = static_cast<GLTFSkeleton *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_godot_bone_node();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		GLTFSkeleton *js_proxy = static_cast<GLTFSkeleton *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_godot_bone_node(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_skeleton_class_set_godot_bone_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFSkeleton::set_godot_bone_node, ctx, this_val, argc, argv);
};
static JSValue gltf_skeleton_class_get_bone_attachment_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkeleton::get_bone_attachment_count, ctx, this_val, argc, argv);
};
static JSValue gltf_skeleton_class_get_bone_attachment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFSkeleton::get_bone_attachment, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_skeleton_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_joints", 0, &gltf_skeleton_class_get_joints),
	JS_CFUNC_DEF("set_joints", 1, &gltf_skeleton_class_set_joints),
	JS_CFUNC_DEF("get_roots", 0, &gltf_skeleton_class_get_roots),
	JS_CFUNC_DEF("set_roots", 1, &gltf_skeleton_class_set_roots),
	JS_CFUNC_DEF("get_godot_skeleton", 0, &gltf_skeleton_class_get_godot_skeleton),
	JS_CFUNC_DEF("get_unique_names", 0, &gltf_skeleton_class_get_unique_names),
	JS_CFUNC_DEF("set_unique_names", 1, &gltf_skeleton_class_set_unique_names),
	JS_CFUNC_DEF("get_godot_bone_node", 0, &gltf_skeleton_class_get_godot_bone_node),
	JS_CFUNC_DEF("set_godot_bone_node", 1, &gltf_skeleton_class_set_godot_bone_node),
	JS_CFUNC_DEF("get_bone_attachment_count", 0, &gltf_skeleton_class_get_bone_attachment_count),
	JS_CFUNC_DEF("get_bone_attachment", 1, &gltf_skeleton_class_get_bone_attachment),
};




static void define_gltf_skeleton_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joints"),
        JS_NewCFunction(ctx, gltf_skeleton_class_get_joints, "get_joints", 0),
        JS_NewCFunction(ctx, gltf_skeleton_class_set_joints, "set_joints", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "roots"),
        JS_NewCFunction(ctx, gltf_skeleton_class_get_roots, "get_roots", 0),
        JS_NewCFunction(ctx, gltf_skeleton_class_set_roots, "set_roots", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unique_names"),
        JS_NewCFunction(ctx, gltf_skeleton_class_get_unique_names, "get_unique_names", 0),
        JS_NewCFunction(ctx, gltf_skeleton_class_set_unique_names, "set_unique_names", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "godot_bone_node"),
        JS_NewCFunction(ctx, gltf_skeleton_class_get_godot_bone_node, "get_godot_bone_node", 0),
        JS_NewCFunction(ctx, gltf_skeleton_class_set_godot_bone_node, "set_godot_bone_node", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_skeleton_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_skeleton_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFSkeleton"] = class_id;
	classes_by_id[class_id] = "GLTFSkeleton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_skeleton_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_skeleton_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_skeleton_class_proto_funcs, _countof(gltf_skeleton_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_skeleton_class_constructor, "GLTFSkeleton", 0, JS_CFUNC_constructor, 0);
	define_gltf_skeleton_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFSkeleton", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_skeleton_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_skeleton_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFSkeleton");
	return m;
}

JSModuleDef *js_init_gltf_skeleton_module(JSContext *ctx) {
	return _js_init_gltf_skeleton_module(ctx, "@godot/classes/gltf_skeleton");
}

void __register_gltf_skeleton() {
	js_init_gltf_skeleton_module(js_context());
}

void register_gltf_skeleton() {
	__register_gltf_skeleton();
}