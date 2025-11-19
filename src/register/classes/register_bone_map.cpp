#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/bone_map.hpp>
using namespace godot;

static void bone_map_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BoneMap"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef bone_map_class_def = {
    "BoneMap",
    bone_map_class_finalizer
};

static JSValue bone_map_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BoneMap"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BoneMap *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BoneMap *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BoneMap);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue bone_map_class_get_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneMap::get_profile, ctx, this_val, argc, argv);
}
static JSValue bone_map_class_set_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneMap::set_profile, ctx, this_val, argc, argv);
};
static JSValue bone_map_class_get_skeleton_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneMap::get_skeleton_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_map_class_set_skeleton_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneMap::set_skeleton_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_map_class_find_profile_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneMap::find_profile_bone_name, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry bone_map_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_profile", 0, &bone_map_class_get_profile),
	JS_CFUNC_DEF("set_profile", 1, &bone_map_class_set_profile),
	JS_CFUNC_DEF("get_skeleton_bone_name", 1, &bone_map_class_get_skeleton_bone_name),
	JS_CFUNC_DEF("set_skeleton_bone_name", 2, &bone_map_class_set_skeleton_bone_name),
	JS_CFUNC_DEF("find_profile_bone_name", 1, &bone_map_class_find_profile_bone_name),
};


static JSValue bone_map_class_get_bone_map_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	BoneMap *opaque = static_cast<BoneMap *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "bone_map_updated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "bone_map_updated"));
		JS_DefinePropertyValueStr(ctx, this_val, "bone_map_updated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue bone_map_class_get_profile_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	BoneMap *opaque = static_cast<BoneMap *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "profile_updated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "profile_updated"));
		JS_DefinePropertyValueStr(ctx, this_val, "profile_updated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_bone_map_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "profile"),
        JS_NewCFunction(ctx, bone_map_class_get_profile, "get_profile", 0),
        JS_NewCFunction(ctx, bone_map_class_set_profile, "set_profile", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "bone_map_updated"),
		JS_NewCFunction(ctx, bone_map_class_get_bone_map_updated_signal, "get_bone_map_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "profile_updated"),
		JS_NewCFunction(ctx, bone_map_class_get_profile_updated_signal, "get_profile_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_bone_map_enum(JSContext *ctx, JSValue ctor) {
}

static int js_bone_map_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BoneMap"] = class_id;
	classes_by_id[class_id] = "BoneMap";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &bone_map_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_bone_map_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, bone_map_class_proto_funcs, _countof(bone_map_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, bone_map_class_constructor, "BoneMap", 0, JS_CFUNC_constructor, 0);
	define_bone_map_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BoneMap", ctor);

	return 0;
}

JSModuleDef *_js_init_bone_map_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_bone_map_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BoneMap");
	return m;
}

JSModuleDef *js_init_bone_map_module(JSContext *ctx) {
	return _js_init_bone_map_module(ctx, "@godot/classes/bone_map");
}

void __register_bone_map() {
	js_init_bone_map_module(js_context());
}

void register_bone_map() {
	__register_bone_map();
}