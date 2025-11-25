#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d_gizmo.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/node3d.hpp>
using namespace godot;

static void node3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Node3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef node3d_class_def = {
    "Node3D",
    node3d_class_finalizer
};

static JSValue node3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Node3D"];
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
        instance = memnew(Node3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue node3d_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_transform, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transform();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_transform(value);
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
static JSValue node3d_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_position, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue node3d_class_set_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_rotation, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_rotation();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_rotation(value);
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
static JSValue node3d_class_set_rotation_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_rotation_degrees, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_rotation_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_rotation_degrees();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_rotation_degrees(value);
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
static JSValue node3d_class_set_rotation_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_rotation_order, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_rotation_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::get_rotation_order, ctx, this_val, argc, argv);
}
static JSValue node3d_class_set_rotation_edit_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_rotation_edit_mode, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_rotation_edit_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::get_rotation_edit_mode, ctx, this_val, argc, argv);
}
static JSValue node3d_class_set_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_scale, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scale();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue node3d_class_set_quaternion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_quaternion, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_quaternion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Quaternion> *proxy = memnew(ObjectProxy<Quaternion>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Quaternion {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_quaternion();
	};
	proxy->setter = [this_val](const Quaternion &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_quaternion(value);
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
static JSValue node3d_class_set_basis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_basis, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_basis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Basis> *proxy = memnew(ObjectProxy<Basis>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Basis {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_basis();
	};
	proxy->setter = [this_val](const Basis &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_basis(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["BasisProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "BasisProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue node3d_class_set_global_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_global_transform, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_global_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_transform();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_transform(value);
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
static JSValue node3d_class_get_global_transform_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Node3D::get_global_transform_interpolated, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_global_position, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_position();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_position(value);
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
static JSValue node3d_class_set_global_basis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_global_basis, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_global_basis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Basis> *proxy = memnew(ObjectProxy<Basis>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Basis {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_basis();
	};
	proxy->setter = [this_val](const Basis &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_basis(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["BasisProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "BasisProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue node3d_class_set_global_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_global_rotation, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_global_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_rotation();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_rotation(value);
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
static JSValue node3d_class_set_global_rotation_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_global_rotation_degrees, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_global_rotation_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Node3D *obj = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_global_rotation_degrees();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Node3D *js_proxy = static_cast<Node3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_global_rotation_degrees(value);
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
static JSValue node3d_class_get_parent_node_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::get_parent_node_3d, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_ignore_transform_notification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_ignore_transform_notification, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_as_top_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_as_top_level, ctx, this_val, argc, argv);
};
static JSValue node3d_class_is_set_as_top_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::is_set_as_top_level, ctx, this_val, argc, argv);
}
static JSValue node3d_class_set_disable_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_disable_scale, ctx, this_val, argc, argv);
};
static JSValue node3d_class_is_scale_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::is_scale_disabled, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_world_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::get_world_3d, ctx, this_val, argc, argv);
};
static JSValue node3d_class_force_update_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::force_update_transform, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_visibility_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_visibility_parent, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_visibility_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::get_visibility_parent, ctx, this_val, argc, argv);
}
static JSValue node3d_class_update_gizmos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::update_gizmos, ctx, this_val, argc, argv);
};
static JSValue node3d_class_add_gizmo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::add_gizmo, ctx, this_val, argc, argv);
};
static JSValue node3d_class_get_gizmos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::get_gizmos, ctx, this_val, argc, argv);
};
static JSValue node3d_class_clear_gizmos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::clear_gizmos, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_subgizmo_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_subgizmo_selection, ctx, this_val, argc, argv);
};
static JSValue node3d_class_clear_subgizmo_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::clear_subgizmo_selection, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_visible, ctx, this_val, argc, argv);
};
static JSValue node3d_class_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::is_visible, ctx, this_val, argc, argv);
}
static JSValue node3d_class_is_visible_in_tree(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::is_visible_in_tree, ctx, this_val, argc, argv);
};
static JSValue node3d_class_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::show, ctx, this_val, argc, argv);
};
static JSValue node3d_class_hide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::hide, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_notify_local_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_notify_local_transform, ctx, this_val, argc, argv);
};
static JSValue node3d_class_is_local_transform_notification_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::is_local_transform_notification_enabled, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_notify_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_notify_transform, ctx, this_val, argc, argv);
};
static JSValue node3d_class_is_transform_notification_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::is_transform_notification_enabled, ctx, this_val, argc, argv);
};
static JSValue node3d_class_rotate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::rotate, ctx, this_val, argc, argv);
};
static JSValue node3d_class_global_rotate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::global_rotate, ctx, this_val, argc, argv);
};
static JSValue node3d_class_global_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::global_scale, ctx, this_val, argc, argv);
};
static JSValue node3d_class_global_translate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::global_translate, ctx, this_val, argc, argv);
};
static JSValue node3d_class_rotate_object_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::rotate_object_local, ctx, this_val, argc, argv);
};
static JSValue node3d_class_scale_object_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::scale_object_local, ctx, this_val, argc, argv);
};
static JSValue node3d_class_translate_object_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::translate_object_local, ctx, this_val, argc, argv);
};
static JSValue node3d_class_rotate_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::rotate_x, ctx, this_val, argc, argv);
};
static JSValue node3d_class_rotate_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::rotate_y, ctx, this_val, argc, argv);
};
static JSValue node3d_class_rotate_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::rotate_z, ctx, this_val, argc, argv);
};
static JSValue node3d_class_translate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::translate, ctx, this_val, argc, argv);
};
static JSValue node3d_class_orthonormalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::orthonormalize, ctx, this_val, argc, argv);
};
static JSValue node3d_class_set_identity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::set_identity, ctx, this_val, argc, argv);
};
static JSValue node3d_class_look_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::look_at, ctx, this_val, argc, argv);
};
static JSValue node3d_class_look_at_from_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node3D::look_at_from_position, ctx, this_val, argc, argv);
};
static JSValue node3d_class_to_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::to_local, ctx, this_val, argc, argv);
};
static JSValue node3d_class_to_global(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node3D::to_global, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry node3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_transform", 1, &node3d_class_set_transform),
	JS_CFUNC_DEF("get_transform", 0, &node3d_class_get_transform),
	JS_CFUNC_DEF("set_position", 1, &node3d_class_set_position),
	JS_CFUNC_DEF("get_position", 0, &node3d_class_get_position),
	JS_CFUNC_DEF("set_rotation", 1, &node3d_class_set_rotation),
	JS_CFUNC_DEF("get_rotation", 0, &node3d_class_get_rotation),
	JS_CFUNC_DEF("set_rotation_degrees", 1, &node3d_class_set_rotation_degrees),
	JS_CFUNC_DEF("get_rotation_degrees", 0, &node3d_class_get_rotation_degrees),
	JS_CFUNC_DEF("set_rotation_order", 1, &node3d_class_set_rotation_order),
	JS_CFUNC_DEF("get_rotation_order", 0, &node3d_class_get_rotation_order),
	JS_CFUNC_DEF("set_rotation_edit_mode", 1, &node3d_class_set_rotation_edit_mode),
	JS_CFUNC_DEF("get_rotation_edit_mode", 0, &node3d_class_get_rotation_edit_mode),
	JS_CFUNC_DEF("set_scale", 1, &node3d_class_set_scale),
	JS_CFUNC_DEF("get_scale", 0, &node3d_class_get_scale),
	JS_CFUNC_DEF("set_quaternion", 1, &node3d_class_set_quaternion),
	JS_CFUNC_DEF("get_quaternion", 0, &node3d_class_get_quaternion),
	JS_CFUNC_DEF("set_basis", 1, &node3d_class_set_basis),
	JS_CFUNC_DEF("get_basis", 0, &node3d_class_get_basis),
	JS_CFUNC_DEF("set_global_transform", 1, &node3d_class_set_global_transform),
	JS_CFUNC_DEF("get_global_transform", 0, &node3d_class_get_global_transform),
	JS_CFUNC_DEF("get_global_transform_interpolated", 0, &node3d_class_get_global_transform_interpolated),
	JS_CFUNC_DEF("set_global_position", 1, &node3d_class_set_global_position),
	JS_CFUNC_DEF("get_global_position", 0, &node3d_class_get_global_position),
	JS_CFUNC_DEF("set_global_basis", 1, &node3d_class_set_global_basis),
	JS_CFUNC_DEF("get_global_basis", 0, &node3d_class_get_global_basis),
	JS_CFUNC_DEF("set_global_rotation", 1, &node3d_class_set_global_rotation),
	JS_CFUNC_DEF("get_global_rotation", 0, &node3d_class_get_global_rotation),
	JS_CFUNC_DEF("set_global_rotation_degrees", 1, &node3d_class_set_global_rotation_degrees),
	JS_CFUNC_DEF("get_global_rotation_degrees", 0, &node3d_class_get_global_rotation_degrees),
	JS_CFUNC_DEF("get_parent_node_3d", 0, &node3d_class_get_parent_node_3d),
	JS_CFUNC_DEF("set_ignore_transform_notification", 1, &node3d_class_set_ignore_transform_notification),
	JS_CFUNC_DEF("set_as_top_level", 1, &node3d_class_set_as_top_level),
	JS_CFUNC_DEF("is_set_as_top_level", 0, &node3d_class_is_set_as_top_level),
	JS_CFUNC_DEF("set_disable_scale", 1, &node3d_class_set_disable_scale),
	JS_CFUNC_DEF("is_scale_disabled", 0, &node3d_class_is_scale_disabled),
	JS_CFUNC_DEF("get_world_3d", 0, &node3d_class_get_world_3d),
	JS_CFUNC_DEF("force_update_transform", 0, &node3d_class_force_update_transform),
	JS_CFUNC_DEF("set_visibility_parent", 1, &node3d_class_set_visibility_parent),
	JS_CFUNC_DEF("get_visibility_parent", 0, &node3d_class_get_visibility_parent),
	JS_CFUNC_DEF("update_gizmos", 0, &node3d_class_update_gizmos),
	JS_CFUNC_DEF("add_gizmo", 1, &node3d_class_add_gizmo),
	JS_CFUNC_DEF("get_gizmos", 0, &node3d_class_get_gizmos),
	JS_CFUNC_DEF("clear_gizmos", 0, &node3d_class_clear_gizmos),
	JS_CFUNC_DEF("set_subgizmo_selection", 3, &node3d_class_set_subgizmo_selection),
	JS_CFUNC_DEF("clear_subgizmo_selection", 0, &node3d_class_clear_subgizmo_selection),
	JS_CFUNC_DEF("set_visible", 1, &node3d_class_set_visible),
	JS_CFUNC_DEF("is_visible", 0, &node3d_class_is_visible),
	JS_CFUNC_DEF("is_visible_in_tree", 0, &node3d_class_is_visible_in_tree),
	JS_CFUNC_DEF("show", 0, &node3d_class_show),
	JS_CFUNC_DEF("hide", 0, &node3d_class_hide),
	JS_CFUNC_DEF("set_notify_local_transform", 1, &node3d_class_set_notify_local_transform),
	JS_CFUNC_DEF("is_local_transform_notification_enabled", 0, &node3d_class_is_local_transform_notification_enabled),
	JS_CFUNC_DEF("set_notify_transform", 1, &node3d_class_set_notify_transform),
	JS_CFUNC_DEF("is_transform_notification_enabled", 0, &node3d_class_is_transform_notification_enabled),
	JS_CFUNC_DEF("rotate", 2, &node3d_class_rotate),
	JS_CFUNC_DEF("global_rotate", 2, &node3d_class_global_rotate),
	JS_CFUNC_DEF("global_scale", 1, &node3d_class_global_scale),
	JS_CFUNC_DEF("global_translate", 1, &node3d_class_global_translate),
	JS_CFUNC_DEF("rotate_object_local", 2, &node3d_class_rotate_object_local),
	JS_CFUNC_DEF("scale_object_local", 1, &node3d_class_scale_object_local),
	JS_CFUNC_DEF("translate_object_local", 1, &node3d_class_translate_object_local),
	JS_CFUNC_DEF("rotate_x", 1, &node3d_class_rotate_x),
	JS_CFUNC_DEF("rotate_y", 1, &node3d_class_rotate_y),
	JS_CFUNC_DEF("rotate_z", 1, &node3d_class_rotate_z),
	JS_CFUNC_DEF("translate", 1, &node3d_class_translate),
	JS_CFUNC_DEF("orthonormalize", 0, &node3d_class_orthonormalize),
	JS_CFUNC_DEF("set_identity", 0, &node3d_class_set_identity),
	JS_CFUNC_DEF("look_at", 3, &node3d_class_look_at),
	JS_CFUNC_DEF("look_at_from_position", 4, &node3d_class_look_at_from_position),
	JS_CFUNC_DEF("to_local", 1, &node3d_class_to_local),
	JS_CFUNC_DEF("to_global", 1, &node3d_class_to_global),
};


static JSValue node3d_class_get_visibility_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Node3D *opaque = static_cast<Node3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "visibility_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "visibility_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "visibility_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_node3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform"),
        JS_NewCFunction(ctx, node3d_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, node3d_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_transform"),
        JS_NewCFunction(ctx, node3d_class_get_global_transform, "get_global_transform", 0),
        JS_NewCFunction(ctx, node3d_class_set_global_transform, "set_global_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position"),
        JS_NewCFunction(ctx, node3d_class_get_position, "get_position", 0),
        JS_NewCFunction(ctx, node3d_class_set_position, "set_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation"),
        JS_NewCFunction(ctx, node3d_class_get_rotation, "get_rotation", 0),
        JS_NewCFunction(ctx, node3d_class_set_rotation, "set_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation_degrees"),
        JS_NewCFunction(ctx, node3d_class_get_rotation_degrees, "get_rotation_degrees", 0),
        JS_NewCFunction(ctx, node3d_class_set_rotation_degrees, "set_rotation_degrees", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "quaternion"),
        JS_NewCFunction(ctx, node3d_class_get_quaternion, "get_quaternion", 0),
        JS_NewCFunction(ctx, node3d_class_set_quaternion, "set_quaternion", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "basis"),
        JS_NewCFunction(ctx, node3d_class_get_basis, "get_basis", 0),
        JS_NewCFunction(ctx, node3d_class_set_basis, "set_basis", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale"),
        JS_NewCFunction(ctx, node3d_class_get_scale, "get_scale", 0),
        JS_NewCFunction(ctx, node3d_class_set_scale, "set_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation_edit_mode"),
        JS_NewCFunction(ctx, node3d_class_get_rotation_edit_mode, "get_rotation_edit_mode", 0),
        JS_NewCFunction(ctx, node3d_class_set_rotation_edit_mode, "set_rotation_edit_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation_order"),
        JS_NewCFunction(ctx, node3d_class_get_rotation_order, "get_rotation_order", 0),
        JS_NewCFunction(ctx, node3d_class_set_rotation_order, "set_rotation_order", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "top_level"),
        JS_NewCFunction(ctx, node3d_class_is_set_as_top_level, "is_set_as_top_level", 0),
        JS_NewCFunction(ctx, node3d_class_set_as_top_level, "set_as_top_level", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_position"),
        JS_NewCFunction(ctx, node3d_class_get_global_position, "get_global_position", 0),
        JS_NewCFunction(ctx, node3d_class_set_global_position, "set_global_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_basis"),
        JS_NewCFunction(ctx, node3d_class_get_global_basis, "get_global_basis", 0),
        JS_NewCFunction(ctx, node3d_class_set_global_basis, "set_global_basis", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_rotation"),
        JS_NewCFunction(ctx, node3d_class_get_global_rotation, "get_global_rotation", 0),
        JS_NewCFunction(ctx, node3d_class_set_global_rotation, "set_global_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "global_rotation_degrees"),
        JS_NewCFunction(ctx, node3d_class_get_global_rotation_degrees, "get_global_rotation_degrees", 0),
        JS_NewCFunction(ctx, node3d_class_set_global_rotation_degrees, "set_global_rotation_degrees", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible"),
        JS_NewCFunction(ctx, node3d_class_is_visible, "is_visible", 0),
        JS_NewCFunction(ctx, node3d_class_set_visible, "set_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_parent"),
        JS_NewCFunction(ctx, node3d_class_get_visibility_parent, "get_visibility_parent", 0),
        JS_NewCFunction(ctx, node3d_class_set_visibility_parent, "set_visibility_parent", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "visibility_changed"),
		JS_NewCFunction(ctx, node3d_class_get_visibility_changed_signal, "get_visibility_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_node3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue RotationEditMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RotationEditMode_obj, "ROTATION_EDIT_MODE_EULER", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RotationEditMode_obj, "ROTATION_EDIT_MODE_QUATERNION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RotationEditMode_obj, "ROTATION_EDIT_MODE_BASIS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "RotationEditMode", RotationEditMode_obj);
}

static int js_node3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Node3D"] = class_id;
	classes_by_id[class_id] = "Node3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &node3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_node3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, node3d_class_proto_funcs, _countof(node3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, node3d_class_constructor, "Node3D", 0, JS_CFUNC_constructor, 0);
	define_node3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Node3D", ctor);
	ctor_list["Node3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_node3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_node3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Node3D");
	return m;
}

JSModuleDef *js_init_node3d_module(JSContext *ctx) {
	return _js_init_node3d_module(ctx, "@godot/classes/node3d");
}

void __register_node3d() {
	js_init_node3d_module(js_context());
}

void register_node3d() {
	__register_node3d();
}