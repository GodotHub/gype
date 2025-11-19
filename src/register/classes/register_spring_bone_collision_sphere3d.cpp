#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/spring_bone_collision3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/spring_bone_collision_sphere3d.hpp>
using namespace godot;

static void spring_bone_collision_sphere3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpringBoneCollisionSphere3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spring_bone_collision_sphere3d_class_def = {
    "SpringBoneCollisionSphere3D",
    spring_bone_collision_sphere3d_class_finalizer
};

static JSValue spring_bone_collision_sphere3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpringBoneCollisionSphere3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SpringBoneCollisionSphere3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SpringBoneCollisionSphere3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SpringBoneCollisionSphere3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue spring_bone_collision_sphere3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneCollisionSphere3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision_sphere3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneCollisionSphere3D::get_radius, ctx, this_val, argc, argv);
}
static JSValue spring_bone_collision_sphere3d_class_set_inside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneCollisionSphere3D::set_inside, ctx, this_val, argc, argv);
};
static JSValue spring_bone_collision_sphere3d_class_is_inside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneCollisionSphere3D::is_inside, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry spring_bone_collision_sphere3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &spring_bone_collision_sphere3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &spring_bone_collision_sphere3d_class_get_radius),
	JS_CFUNC_DEF("set_inside", 1, &spring_bone_collision_sphere3d_class_set_inside),
	JS_CFUNC_DEF("is_inside", 0, &spring_bone_collision_sphere3d_class_is_inside),
};




static void define_spring_bone_collision_sphere3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, spring_bone_collision_sphere3d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, spring_bone_collision_sphere3d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inside"),
        JS_NewCFunction(ctx, spring_bone_collision_sphere3d_class_is_inside, "is_inside", 0),
        JS_NewCFunction(ctx, spring_bone_collision_sphere3d_class_set_inside, "set_inside", 1),
        JS_PROP_GETSET
    );
}

static void define_spring_bone_collision_sphere3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_spring_bone_collision_sphere3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpringBoneCollisionSphere3D"] = class_id;
	classes_by_id[class_id] = "SpringBoneCollisionSphere3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spring_bone_collision_sphere3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SpringBoneCollision3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spring_bone_collision_sphere3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, spring_bone_collision_sphere3d_class_proto_funcs, _countof(spring_bone_collision_sphere3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, spring_bone_collision_sphere3d_class_constructor, "SpringBoneCollisionSphere3D", 0, JS_CFUNC_constructor, 0);
	define_spring_bone_collision_sphere3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpringBoneCollisionSphere3D", ctor);

	return 0;
}

JSModuleDef *_js_init_spring_bone_collision_sphere3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/spring_bone_collision3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spring_bone_collision_sphere3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpringBoneCollisionSphere3D");
	return m;
}

JSModuleDef *js_init_spring_bone_collision_sphere3d_module(JSContext *ctx) {
	return _js_init_spring_bone_collision_sphere3d_module(ctx, "@godot/classes/spring_bone_collision_sphere3d");
}

void __register_spring_bone_collision_sphere3d() {
	js_init_spring_bone_collision_sphere3d_module(js_context());
}

void register_spring_bone_collision_sphere3d() {
	__register_spring_bone_collision_sphere3d();
}