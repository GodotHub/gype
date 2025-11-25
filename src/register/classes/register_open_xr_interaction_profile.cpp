#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xrip_binding.hpp>
#include <godot_cpp/classes/open_xrip_binding_modifier.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_interaction_profile.hpp>
using namespace godot;

static void open_xr_interaction_profile_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRInteractionProfile"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_interaction_profile_class_def = {
    "OpenXRInteractionProfile",
    open_xr_interaction_profile_class_finalizer
};

static JSValue open_xr_interaction_profile_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRInteractionProfile"];
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
        instance = memnew(OpenXRInteractionProfile);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_interaction_profile_class_set_interaction_profile_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInteractionProfile::set_interaction_profile_path, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_get_interaction_profile_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_interaction_profile_path, ctx, this_val, argc, argv);
}
static JSValue open_xr_interaction_profile_class_get_binding_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_binding_count, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_get_binding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_binding, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_set_bindings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInteractionProfile::set_bindings, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_get_bindings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_bindings, ctx, this_val, argc, argv);
}
static JSValue open_xr_interaction_profile_class_get_binding_modifier_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_binding_modifier_count, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_get_binding_modifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_binding_modifier, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_set_binding_modifiers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInteractionProfile::set_binding_modifiers, ctx, this_val, argc, argv);
};
static JSValue open_xr_interaction_profile_class_get_binding_modifiers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInteractionProfile::get_binding_modifiers, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry open_xr_interaction_profile_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_interaction_profile_path", 1, &open_xr_interaction_profile_class_set_interaction_profile_path),
	JS_CFUNC_DEF("get_interaction_profile_path", 0, &open_xr_interaction_profile_class_get_interaction_profile_path),
	JS_CFUNC_DEF("get_binding_count", 0, &open_xr_interaction_profile_class_get_binding_count),
	JS_CFUNC_DEF("get_binding", 1, &open_xr_interaction_profile_class_get_binding),
	JS_CFUNC_DEF("set_bindings", 1, &open_xr_interaction_profile_class_set_bindings),
	JS_CFUNC_DEF("get_bindings", 0, &open_xr_interaction_profile_class_get_bindings),
	JS_CFUNC_DEF("get_binding_modifier_count", 0, &open_xr_interaction_profile_class_get_binding_modifier_count),
	JS_CFUNC_DEF("get_binding_modifier", 1, &open_xr_interaction_profile_class_get_binding_modifier),
	JS_CFUNC_DEF("set_binding_modifiers", 1, &open_xr_interaction_profile_class_set_binding_modifiers),
	JS_CFUNC_DEF("get_binding_modifiers", 0, &open_xr_interaction_profile_class_get_binding_modifiers),
};




static void define_open_xr_interaction_profile_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interaction_profile_path"),
        JS_NewCFunction(ctx, open_xr_interaction_profile_class_get_interaction_profile_path, "get_interaction_profile_path", 0),
        JS_NewCFunction(ctx, open_xr_interaction_profile_class_set_interaction_profile_path, "set_interaction_profile_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bindings"),
        JS_NewCFunction(ctx, open_xr_interaction_profile_class_get_bindings, "get_bindings", 0),
        JS_NewCFunction(ctx, open_xr_interaction_profile_class_set_bindings, "set_bindings", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "binding_modifiers"),
        JS_NewCFunction(ctx, open_xr_interaction_profile_class_get_binding_modifiers, "get_binding_modifiers", 0),
        JS_NewCFunction(ctx, open_xr_interaction_profile_class_set_binding_modifiers, "set_binding_modifiers", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_interaction_profile_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_interaction_profile_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRInteractionProfile"] = class_id;
	classes_by_id[class_id] = "OpenXRInteractionProfile";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_interaction_profile_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_interaction_profile_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_interaction_profile_class_proto_funcs, _countof(open_xr_interaction_profile_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_interaction_profile_class_constructor, "OpenXRInteractionProfile", 0, JS_CFUNC_constructor, 0);
	define_open_xr_interaction_profile_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRInteractionProfile", ctor);
	ctor_list["OpenXRInteractionProfile"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_interaction_profile_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_interaction_profile_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRInteractionProfile");
	return m;
}

JSModuleDef *js_init_open_xr_interaction_profile_module(JSContext *ctx) {
	return _js_init_open_xr_interaction_profile_module(ctx, "@godot/classes/open_xr_interaction_profile");
}

void __register_open_xr_interaction_profile() {
	js_init_open_xr_interaction_profile_module(js_context());
}

void register_open_xr_interaction_profile() {
	__register_open_xr_interaction_profile();
}