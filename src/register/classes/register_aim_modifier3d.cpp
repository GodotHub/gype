#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/bone_constraint3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/aim_modifier3d.hpp>
using namespace godot;

static void aim_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AimModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef aim_modifier3d_class_def = {
    "AimModifier3D",
    aim_modifier3d_class_finalizer
};

static JSValue aim_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AimModifier3D"];
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
        instance = memnew(AimModifier3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue aim_modifier3d_class_set_forward_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AimModifier3D::set_forward_axis, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_get_forward_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AimModifier3D::get_forward_axis, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_set_use_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AimModifier3D::set_use_euler, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_is_using_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AimModifier3D::is_using_euler, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_set_primary_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AimModifier3D::set_primary_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_get_primary_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AimModifier3D::get_primary_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_set_use_secondary_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AimModifier3D::set_use_secondary_rotation, ctx, this_val, argc, argv);
};
static JSValue aim_modifier3d_class_is_using_secondary_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AimModifier3D::is_using_secondary_rotation, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry aim_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_forward_axis", 2, &aim_modifier3d_class_set_forward_axis),
	JS_CFUNC_DEF("get_forward_axis", 1, &aim_modifier3d_class_get_forward_axis),
	JS_CFUNC_DEF("set_use_euler", 2, &aim_modifier3d_class_set_use_euler),
	JS_CFUNC_DEF("is_using_euler", 1, &aim_modifier3d_class_is_using_euler),
	JS_CFUNC_DEF("set_primary_rotation_axis", 2, &aim_modifier3d_class_set_primary_rotation_axis),
	JS_CFUNC_DEF("get_primary_rotation_axis", 1, &aim_modifier3d_class_get_primary_rotation_axis),
	JS_CFUNC_DEF("set_use_secondary_rotation", 2, &aim_modifier3d_class_set_use_secondary_rotation),
	JS_CFUNC_DEF("is_using_secondary_rotation", 1, &aim_modifier3d_class_is_using_secondary_rotation),
};




static void define_aim_modifier3d_property(JSContext *ctx, JSValue proto) {
}

static void define_aim_modifier3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_aim_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AimModifier3D"] = class_id;
	classes_by_id[class_id] = "AimModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &aim_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["BoneConstraint3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_aim_modifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, aim_modifier3d_class_proto_funcs, _countof(aim_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, aim_modifier3d_class_constructor, "AimModifier3D", 0, JS_CFUNC_constructor, 0);
	define_aim_modifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AimModifier3D", ctor);
	ctor_list["AimModifier3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_aim_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/bone_constraint3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_aim_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AimModifier3D");
	return m;
}

JSModuleDef *js_init_aim_modifier3d_module(JSContext *ctx) {
	return _js_init_aim_modifier3d_module(ctx, "@godot/classes/aim_modifier3d");
}

void __register_aim_modifier3d() {
	js_init_aim_modifier3d_module(js_context());
}

void register_aim_modifier3d() {
	__register_aim_modifier3d();
}