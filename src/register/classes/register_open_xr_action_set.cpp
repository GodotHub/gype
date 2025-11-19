#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_action.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_action_set.hpp>
using namespace godot;

static void open_xr_action_set_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRActionSet"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_action_set_class_def = {
    "OpenXRActionSet",
    open_xr_action_set_class_finalizer
};

static JSValue open_xr_action_set_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRActionSet"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRActionSet *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRActionSet *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRActionSet);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_action_set_class_set_localized_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionSet::set_localized_name, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_set_class_get_localized_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionSet::get_localized_name, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_set_class_set_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionSet::set_priority, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_set_class_get_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionSet::get_priority, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_set_class_get_action_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionSet::get_action_count, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_set_class_set_actions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionSet::set_actions, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_set_class_get_actions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRActionSet::get_actions, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_set_class_add_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionSet::add_action, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_set_class_remove_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRActionSet::remove_action, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_action_set_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_localized_name", 1, &open_xr_action_set_class_set_localized_name),
	JS_CFUNC_DEF("get_localized_name", 0, &open_xr_action_set_class_get_localized_name),
	JS_CFUNC_DEF("set_priority", 1, &open_xr_action_set_class_set_priority),
	JS_CFUNC_DEF("get_priority", 0, &open_xr_action_set_class_get_priority),
	JS_CFUNC_DEF("get_action_count", 0, &open_xr_action_set_class_get_action_count),
	JS_CFUNC_DEF("set_actions", 1, &open_xr_action_set_class_set_actions),
	JS_CFUNC_DEF("get_actions", 0, &open_xr_action_set_class_get_actions),
	JS_CFUNC_DEF("add_action", 1, &open_xr_action_set_class_add_action),
	JS_CFUNC_DEF("remove_action", 1, &open_xr_action_set_class_remove_action),
};




static void define_open_xr_action_set_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "localized_name"),
        JS_NewCFunction(ctx, open_xr_action_set_class_get_localized_name, "get_localized_name", 0),
        JS_NewCFunction(ctx, open_xr_action_set_class_set_localized_name, "set_localized_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "priority"),
        JS_NewCFunction(ctx, open_xr_action_set_class_get_priority, "get_priority", 0),
        JS_NewCFunction(ctx, open_xr_action_set_class_set_priority, "set_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "actions"),
        JS_NewCFunction(ctx, open_xr_action_set_class_get_actions, "get_actions", 0),
        JS_NewCFunction(ctx, open_xr_action_set_class_set_actions, "set_actions", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_action_set_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_action_set_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRActionSet"] = class_id;
	classes_by_id[class_id] = "OpenXRActionSet";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_action_set_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_action_set_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_action_set_class_proto_funcs, _countof(open_xr_action_set_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_action_set_class_constructor, "OpenXRActionSet", 0, JS_CFUNC_constructor, 0);
	define_open_xr_action_set_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRActionSet", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_action_set_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_action_set_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRActionSet");
	return m;
}

JSModuleDef *js_init_open_xr_action_set_module(JSContext *ctx) {
	return _js_init_open_xr_action_set_module(ctx, "@godot/classes/open_xr_action_set");
}

void __register_open_xr_action_set() {
	js_init_open_xr_action_set_module(js_context());
}

void register_open_xr_action_set() {
	__register_open_xr_action_set();
}