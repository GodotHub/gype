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
#include <godot_cpp/classes/spring_bone_collision_plane3d.hpp>
using namespace godot;

static void spring_bone_collision_plane3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpringBoneCollisionPlane3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spring_bone_collision_plane3d_class_def = {
    "SpringBoneCollisionPlane3D",
    spring_bone_collision_plane3d_class_finalizer
};

static JSValue spring_bone_collision_plane3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpringBoneCollisionPlane3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SpringBoneCollisionPlane3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SpringBoneCollisionPlane3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SpringBoneCollisionPlane3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}






static void define_spring_bone_collision_plane3d_property(JSContext *ctx, JSValue proto) {
}

static void define_spring_bone_collision_plane3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_spring_bone_collision_plane3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpringBoneCollisionPlane3D"] = class_id;
	classes_by_id[class_id] = "SpringBoneCollisionPlane3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spring_bone_collision_plane3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SpringBoneCollision3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spring_bone_collision_plane3d_property(ctx, proto);
	define_spring_bone_collision_plane3d_enum(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, spring_bone_collision_plane3d_class_constructor, "SpringBoneCollisionPlane3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpringBoneCollisionPlane3D", ctor);

	return 0;
}

JSModuleDef *_js_init_spring_bone_collision_plane3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/spring_bone_collision3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spring_bone_collision_plane3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpringBoneCollisionPlane3D");
	return m;
}

JSModuleDef *js_init_spring_bone_collision_plane3d_module(JSContext *ctx) {
	return _js_init_spring_bone_collision_plane3d_module(ctx, "@godot/classes/spring_bone_collision_plane3d");
}

void __register_spring_bone_collision_plane3d() {
	js_init_spring_bone_collision_plane3d_module(js_context());
}

void register_spring_bone_collision_plane3d() {
	__register_spring_bone_collision_plane3d();
}