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
#include <godot_cpp/classes/spring_bone_collision3d.hpp>
using namespace godot;

static void spring_bone_collision3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpringBoneCollision3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spring_bone_collision3d_class_def = {
    "SpringBoneCollision3D",
    spring_bone_collision3d_class_finalizer
};

static JSValue spring_bone_collision3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpringBoneCollision3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SpringBoneCollision3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SpringBoneCollision3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SpringBoneCollision3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue spring_bone_collision3d_class_get_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneCollision3D::get_skeleton, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision3d_class_set_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneCollision3D::set_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision3d_class_get_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		SpringBoneCollision3D *obj = static_cast<SpringBoneCollision3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_bone_name();
	};
	proxy->setter = [this_val](const String &value) -> void {
		SpringBoneCollision3D *js_proxy = static_cast<SpringBoneCollision3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_bone_name(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue spring_bone_collision3d_class_set_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneCollision3D::set_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision3d_class_get_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneCollision3D::get_bone, ctx, this_val, argc, argv);
}
static JSValue spring_bone_collision3d_class_set_position_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneCollision3D::set_position_offset, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision3d_class_get_position_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		SpringBoneCollision3D *obj = static_cast<SpringBoneCollision3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		SpringBoneCollision3D *js_proxy = static_cast<SpringBoneCollision3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position_offset(value);
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
static JSValue spring_bone_collision3d_class_set_rotation_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneCollision3D::set_rotation_offset, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision3d_class_get_rotation_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Quaternion> *proxy = memnew(ObjectProxy<Quaternion>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Quaternion {
		SpringBoneCollision3D *obj = static_cast<SpringBoneCollision3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_rotation_offset();
	};
	proxy->setter = [this_val](const Quaternion &value) -> void {
		SpringBoneCollision3D *js_proxy = static_cast<SpringBoneCollision3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_rotation_offset(value);
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



static const JSCFunctionListEntry spring_bone_collision3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_skeleton", 0, &spring_bone_collision3d_class_get_skeleton),
	JS_CFUNC_DEF("set_bone_name", 1, &spring_bone_collision3d_class_set_bone_name),
	JS_CFUNC_DEF("get_bone_name", 0, &spring_bone_collision3d_class_get_bone_name),
	JS_CFUNC_DEF("set_bone", 1, &spring_bone_collision3d_class_set_bone),
	JS_CFUNC_DEF("get_bone", 0, &spring_bone_collision3d_class_get_bone),
	JS_CFUNC_DEF("set_position_offset", 1, &spring_bone_collision3d_class_set_position_offset),
	JS_CFUNC_DEF("get_position_offset", 0, &spring_bone_collision3d_class_get_position_offset),
	JS_CFUNC_DEF("set_rotation_offset", 1, &spring_bone_collision3d_class_set_rotation_offset),
	JS_CFUNC_DEF("get_rotation_offset", 0, &spring_bone_collision3d_class_get_rotation_offset),
};




static void define_spring_bone_collision3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_name"),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_get_bone_name, "get_bone_name", 0),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_set_bone_name, "set_bone_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone"),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_get_bone, "get_bone", 0),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_set_bone, "set_bone", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position_offset"),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_get_position_offset, "get_position_offset", 0),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_set_position_offset, "set_position_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rotation_offset"),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_get_rotation_offset, "get_rotation_offset", 0),
        JS_NewCFunction(ctx, spring_bone_collision3d_class_set_rotation_offset, "set_rotation_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_spring_bone_collision3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_spring_bone_collision3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpringBoneCollision3D"] = class_id;
	classes_by_id[class_id] = "SpringBoneCollision3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spring_bone_collision3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spring_bone_collision3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, spring_bone_collision3d_class_proto_funcs, _countof(spring_bone_collision3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, spring_bone_collision3d_class_constructor, "SpringBoneCollision3D", 0, JS_CFUNC_constructor, 0);
	define_spring_bone_collision3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpringBoneCollision3D", ctor);

	return 0;
}

JSModuleDef *_js_init_spring_bone_collision3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spring_bone_collision3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpringBoneCollision3D");
	return m;
}

JSModuleDef *js_init_spring_bone_collision3d_module(JSContext *ctx) {
	return _js_init_spring_bone_collision3d_module(ctx, "@godot/classes/spring_bone_collision3d");
}

void __register_spring_bone_collision3d() {
	js_init_spring_bone_collision3d_module(js_context());
}

void register_spring_bone_collision3d() {
	__register_spring_bone_collision3d();
}