#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gltf_state.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_node.hpp>
using namespace godot;

static void gltf_node_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFNode"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_node_class_def = {
    "GLTFNode",
    gltf_node_class_finalizer
};

static JSValue gltf_node_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFNode"];
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
        instance = memnew(GLTFNode);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_node_class_get_original_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_original_name, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_original_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_original_name, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_parent, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_parent, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_height, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_height, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_xform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		GLTFNode *obj = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_xform();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		GLTFNode *js_proxy = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_xform(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform3DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform3DProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_node_class_set_xform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_xform, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_mesh, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_mesh, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_camera(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_camera, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_camera(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_camera, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_skin, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_skin, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_skeleton, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_skeleton, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFNode *obj = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFNode *js_proxy = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_node_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_position, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Quaternion> *proxy = memnew(ObjectProxy<Quaternion>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Quaternion {
		GLTFNode *obj = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_rotation();
	};
	proxy->setter = [this_val](const Quaternion &value) -> void {
		GLTFNode *js_proxy = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_rotation(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["QuaternionProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "QuaternionProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_node_class_set_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_rotation, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		GLTFNode *obj = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scale();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		GLTFNode *js_proxy = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scale(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_node_class_set_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_scale, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_children(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFNode *obj = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_children();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFNode *js_proxy = static_cast<GLTFNode *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_children(PackedInt32Array
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
static JSValue gltf_node_class_set_children(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_children, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_append_child_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::append_child_index, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_light, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_light, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_visible, ctx, this_val, argc, argv);
}
static JSValue gltf_node_class_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_visible, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_set_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFNode::set_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_node_class_get_scene_node_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFNode::get_scene_node_path, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_node_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_original_name", 0, &gltf_node_class_get_original_name),
	JS_CFUNC_DEF("set_original_name", 1, &gltf_node_class_set_original_name),
	JS_CFUNC_DEF("get_parent", 0, &gltf_node_class_get_parent),
	JS_CFUNC_DEF("set_parent", 1, &gltf_node_class_set_parent),
	JS_CFUNC_DEF("get_height", 0, &gltf_node_class_get_height),
	JS_CFUNC_DEF("set_height", 1, &gltf_node_class_set_height),
	JS_CFUNC_DEF("get_xform", 0, &gltf_node_class_get_xform),
	JS_CFUNC_DEF("set_xform", 1, &gltf_node_class_set_xform),
	JS_CFUNC_DEF("get_mesh", 0, &gltf_node_class_get_mesh),
	JS_CFUNC_DEF("set_mesh", 1, &gltf_node_class_set_mesh),
	JS_CFUNC_DEF("get_camera", 0, &gltf_node_class_get_camera),
	JS_CFUNC_DEF("set_camera", 1, &gltf_node_class_set_camera),
	JS_CFUNC_DEF("get_skin", 0, &gltf_node_class_get_skin),
	JS_CFUNC_DEF("set_skin", 1, &gltf_node_class_set_skin),
	JS_CFUNC_DEF("get_skeleton", 0, &gltf_node_class_get_skeleton),
	JS_CFUNC_DEF("set_skeleton", 1, &gltf_node_class_set_skeleton),
	JS_CFUNC_DEF("get_position", 0, &gltf_node_class_get_position),
	JS_CFUNC_DEF("set_position", 1, &gltf_node_class_set_position),
	JS_CFUNC_DEF("get_rotation", 0, &gltf_node_class_get_rotation),
	JS_CFUNC_DEF("set_rotation", 1, &gltf_node_class_set_rotation),
	JS_CFUNC_DEF("get_scale", 0, &gltf_node_class_get_scale),
	JS_CFUNC_DEF("set_scale", 1, &gltf_node_class_set_scale),
	JS_CFUNC_DEF("get_children", 0, &gltf_node_class_get_children),
	JS_CFUNC_DEF("set_children", 1, &gltf_node_class_set_children),
	JS_CFUNC_DEF("append_child_index", 1, &gltf_node_class_append_child_index),
	JS_CFUNC_DEF("get_light", 0, &gltf_node_class_get_light),
	JS_CFUNC_DEF("set_light", 1, &gltf_node_class_set_light),
	JS_CFUNC_DEF("get_visible", 0, &gltf_node_class_get_visible),
	JS_CFUNC_DEF("set_visible", 1, &gltf_node_class_set_visible),
	JS_CFUNC_DEF("get_additional_data", 1, &gltf_node_class_get_additional_data),
	JS_CFUNC_DEF("set_additional_data", 2, &gltf_node_class_set_additional_data),
	JS_CFUNC_DEF("get_scene_node_path", 2, &gltf_node_class_get_scene_node_path),
};




static void define_gltf_node_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "original_name"),
        JS_NewCFunction(ctx, gltf_node_class_get_original_name, "get_original_name", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_original_name, "set_original_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "parent"),
        JS_NewCFunction(ctx, gltf_node_class_get_parent, "get_parent", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_parent, "set_parent", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, gltf_node_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "xform"),
        JS_NewCFunction(ctx, gltf_node_class_get_xform, "get_xform", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_xform, "set_xform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh"),
        JS_NewCFunction(ctx, gltf_node_class_get_mesh, "get_mesh", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_mesh, "set_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "camera"),
        JS_NewCFunction(ctx, gltf_node_class_get_camera, "get_camera", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_camera, "set_camera", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skin"),
        JS_NewCFunction(ctx, gltf_node_class_get_skin, "get_skin", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_skin, "set_skin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skeleton"),
        JS_NewCFunction(ctx, gltf_node_class_get_skeleton, "get_skeleton", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_skeleton, "set_skeleton", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position"),
        JS_NewCFunction(ctx, gltf_node_class_get_position, "get_position", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_position, "set_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation"),
        JS_NewCFunction(ctx, gltf_node_class_get_rotation, "get_rotation", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_rotation, "set_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale"),
        JS_NewCFunction(ctx, gltf_node_class_get_scale, "get_scale", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_scale, "set_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "children"),
        JS_NewCFunction(ctx, gltf_node_class_get_children, "get_children", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_children, "set_children", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light"),
        JS_NewCFunction(ctx, gltf_node_class_get_light, "get_light", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_light, "set_light", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible"),
        JS_NewCFunction(ctx, gltf_node_class_get_visible, "get_visible", 0),
        JS_NewCFunction(ctx, gltf_node_class_set_visible, "set_visible", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_node_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_node_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFNode"] = class_id;
	classes_by_id[class_id] = "GLTFNode";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_node_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_node_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_node_class_proto_funcs, _countof(gltf_node_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_node_class_constructor, "GLTFNode", 0, JS_CFUNC_constructor, 0);
	define_gltf_node_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFNode", ctor);
	ctor_list["GLTFNode"] = ctor;

	return 0;
}

JSModuleDef *_js_init_gltf_node_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_node_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFNode");
	return m;
}

JSModuleDef *js_init_gltf_node_module(JSContext *ctx) {
	return _js_init_gltf_node_module(ctx, "@godot/classes/gltf_node");
}

void __register_gltf_node() {
	js_init_gltf_node_module(js_context());
}

void register_gltf_node() {
	__register_gltf_node();
}