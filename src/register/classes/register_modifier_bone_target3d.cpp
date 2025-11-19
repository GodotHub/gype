#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/modifier_bone_target3d.hpp>
using namespace godot;

static void modifier_bone_target3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ModifierBoneTarget3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef modifier_bone_target3d_class_def = {
    "ModifierBoneTarget3D",
    modifier_bone_target3d_class_finalizer
};

static JSValue modifier_bone_target3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ModifierBoneTarget3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ModifierBoneTarget3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ModifierBoneTarget3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ModifierBoneTarget3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue modifier_bone_target3d_class_set_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ModifierBoneTarget3D::set_bone_name, ctx, this_val, argc, argv);
};
static JSValue modifier_bone_target3d_class_get_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ModifierBoneTarget3D::get_bone_name, ctx, this_val, argc, argv);
}
static JSValue modifier_bone_target3d_class_set_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ModifierBoneTarget3D::set_bone, ctx, this_val, argc, argv);
};
static JSValue modifier_bone_target3d_class_get_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ModifierBoneTarget3D::get_bone, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry modifier_bone_target3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_bone_name", 1, &modifier_bone_target3d_class_set_bone_name),
	JS_CFUNC_DEF("get_bone_name", 0, &modifier_bone_target3d_class_get_bone_name),
	JS_CFUNC_DEF("set_bone", 1, &modifier_bone_target3d_class_set_bone),
	JS_CFUNC_DEF("get_bone", 0, &modifier_bone_target3d_class_get_bone),
};




static void define_modifier_bone_target3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_name"),
        JS_NewCFunction(ctx, modifier_bone_target3d_class_get_bone_name, "get_bone_name", 0),
        JS_NewCFunction(ctx, modifier_bone_target3d_class_set_bone_name, "set_bone_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone"),
        JS_NewCFunction(ctx, modifier_bone_target3d_class_get_bone, "get_bone", 0),
        JS_NewCFunction(ctx, modifier_bone_target3d_class_set_bone, "set_bone", 1),
        JS_PROP_GETSET
    );
}

static void define_modifier_bone_target3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_modifier_bone_target3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ModifierBoneTarget3D"] = class_id;
	classes_by_id[class_id] = "ModifierBoneTarget3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &modifier_bone_target3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModifier3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_modifier_bone_target3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, modifier_bone_target3d_class_proto_funcs, _countof(modifier_bone_target3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, modifier_bone_target3d_class_constructor, "ModifierBoneTarget3D", 0, JS_CFUNC_constructor, 0);
	define_modifier_bone_target3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ModifierBoneTarget3D", ctor);

	return 0;
}

JSModuleDef *_js_init_modifier_bone_target3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modifier3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_modifier_bone_target3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ModifierBoneTarget3D");
	return m;
}

JSModuleDef *js_init_modifier_bone_target3d_module(JSContext *ctx) {
	return _js_init_modifier_bone_target3d_module(ctx, "@godot/classes/modifier_bone_target3d");
}

void __register_modifier_bone_target3d() {
	js_init_modifier_bone_target3d_module(js_context());
}

void register_modifier_bone_target3d() {
	__register_modifier_bone_target3d();
}