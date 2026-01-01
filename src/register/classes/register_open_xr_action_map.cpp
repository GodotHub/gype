#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_action_set.hpp>
#include <godot_cpp/classes/open_xr_interaction_profile.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_action_map.hpp>
using namespace godot;

static void open_xr_action_map_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRActionMap"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_action_map_class_def = {
    "OpenXRActionMap",
    open_xr_action_map_class_finalizer
};

static JSValue open_xr_action_map_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRActionMap"];
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
        instance = memnew(OpenXRActionMap);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_action_map_class_set_action_sets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::set_action_sets, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_get_action_sets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::get_action_sets, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_map_class_get_action_set_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::get_action_set_count, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_find_action_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::find_action_set, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_get_action_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::get_action_set, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_add_action_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::add_action_set, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_remove_action_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::remove_action_set, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_set_interaction_profiles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::set_interaction_profiles, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_get_interaction_profiles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::get_interaction_profiles, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_map_class_get_interaction_profile_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::get_interaction_profile_count, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_find_interaction_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::find_interaction_profile, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_get_interaction_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionMap::get_interaction_profile, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_add_interaction_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::add_interaction_profile, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_remove_interaction_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::remove_interaction_profile, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_map_class_create_default_action_sets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionMap::create_default_action_sets, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_action_map_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_action_sets", 1, &open_xr_action_map_class_set_action_sets),
	JS_CFUNC_DEF("get_action_sets", 0, &open_xr_action_map_class_get_action_sets),
	JS_CFUNC_DEF("get_action_set_count", 0, &open_xr_action_map_class_get_action_set_count),
	JS_CFUNC_DEF("find_action_set", 1, &open_xr_action_map_class_find_action_set),
	JS_CFUNC_DEF("get_action_set", 1, &open_xr_action_map_class_get_action_set),
	JS_CFUNC_DEF("add_action_set", 1, &open_xr_action_map_class_add_action_set),
	JS_CFUNC_DEF("remove_action_set", 1, &open_xr_action_map_class_remove_action_set),
	JS_CFUNC_DEF("set_interaction_profiles", 1, &open_xr_action_map_class_set_interaction_profiles),
	JS_CFUNC_DEF("get_interaction_profiles", 0, &open_xr_action_map_class_get_interaction_profiles),
	JS_CFUNC_DEF("get_interaction_profile_count", 0, &open_xr_action_map_class_get_interaction_profile_count),
	JS_CFUNC_DEF("find_interaction_profile", 1, &open_xr_action_map_class_find_interaction_profile),
	JS_CFUNC_DEF("get_interaction_profile", 1, &open_xr_action_map_class_get_interaction_profile),
	JS_CFUNC_DEF("add_interaction_profile", 1, &open_xr_action_map_class_add_interaction_profile),
	JS_CFUNC_DEF("remove_interaction_profile", 1, &open_xr_action_map_class_remove_interaction_profile),
	JS_CFUNC_DEF("create_default_action_sets", 0, &open_xr_action_map_class_create_default_action_sets),
};




static void define_open_xr_action_map_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action_sets"),
        JS_NewCFunction(ctx, open_xr_action_map_class_get_action_sets, "get_action_sets", 0),
        JS_NewCFunction(ctx, open_xr_action_map_class_set_action_sets, "set_action_sets", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interaction_profiles"),
        JS_NewCFunction(ctx, open_xr_action_map_class_get_interaction_profiles, "get_interaction_profiles", 0),
        JS_NewCFunction(ctx, open_xr_action_map_class_set_interaction_profiles, "set_interaction_profiles", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_action_map_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_action_map_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRActionMap"] = class_id;
	classes_by_id[class_id] = "OpenXRActionMap";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_action_map_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_action_map_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_action_map_class_proto_funcs, _countof(open_xr_action_map_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_action_map_class_constructor, "OpenXRActionMap", 0, JS_CFUNC_constructor, 0);
	define_open_xr_action_map_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRActionMap", ctor);
	ctor_list["OpenXRActionMap"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_action_map_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_action_map_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRActionMap");
	return m;
}

JSModuleDef *js_init_open_xr_action_map_module(JSContext *ctx) {
	return _js_init_open_xr_action_map_module(ctx, "@godot/classes/open_xr_action_map");
}

void __register_open_xr_action_map() {
	js_init_open_xr_action_map_module(js_context());
}

void register_open_xr_action_map() {
	__register_open_xr_action_map();
}