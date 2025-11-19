#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_action.hpp>
using namespace godot;

static void open_xr_action_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRAction"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef open_xr_action_class_def = {
    "OpenXRAction",
    open_xr_action_class_finalizer
};

static JSValue open_xr_action_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRAction"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRAction *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRAction *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRAction);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_action_class_set_localized_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAction::set_localized_name, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_class_get_localized_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRAction::get_localized_name, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_class_set_action_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAction::set_action_type, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_class_get_action_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRAction::get_action_type, ctx, this_val, argc, argv);
}
static JSValue open_xr_action_class_set_toplevel_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRAction::set_toplevel_paths, ctx, this_val, argc, argv);
};
static JSValue open_xr_action_class_get_toplevel_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		OpenXRAction *obj = static_cast<OpenXRAction *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_toplevel_paths();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		OpenXRAction *js_proxy = static_cast<OpenXRAction *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_toplevel_paths(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry open_xr_action_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_localized_name", 1, &open_xr_action_class_set_localized_name),
	JS_CFUNC_DEF("get_localized_name", 0, &open_xr_action_class_get_localized_name),
	JS_CFUNC_DEF("set_action_type", 1, &open_xr_action_class_set_action_type),
	JS_CFUNC_DEF("get_action_type", 0, &open_xr_action_class_get_action_type),
	JS_CFUNC_DEF("set_toplevel_paths", 1, &open_xr_action_class_set_toplevel_paths),
	JS_CFUNC_DEF("get_toplevel_paths", 0, &open_xr_action_class_get_toplevel_paths),
};




static void define_open_xr_action_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "localized_name"),
        JS_NewCFunction(ctx, open_xr_action_class_get_localized_name, "get_localized_name", 0),
        JS_NewCFunction(ctx, open_xr_action_class_set_localized_name, "set_localized_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action_type"),
        JS_NewCFunction(ctx, open_xr_action_class_get_action_type, "get_action_type", 0),
        JS_NewCFunction(ctx, open_xr_action_class_set_action_type, "set_action_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "toplevel_paths"),
        JS_NewCFunction(ctx, open_xr_action_class_get_toplevel_paths, "get_toplevel_paths", 0),
        JS_NewCFunction(ctx, open_xr_action_class_set_toplevel_paths, "set_toplevel_paths", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_action_enum(JSContext *ctx, JSValue ctor) {
	JSValue ActionType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ActionType_obj, "OPENXR_ACTION_BOOL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ActionType_obj, "OPENXR_ACTION_FLOAT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ActionType_obj, "OPENXR_ACTION_VECTOR2", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ActionType_obj, "OPENXR_ACTION_POSE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ActionType", ActionType_obj);
}

static int js_open_xr_action_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRAction"] = class_id;
	classes_by_id[class_id] = "OpenXRAction";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_action_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_action_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_action_class_proto_funcs, _countof(open_xr_action_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_action_class_constructor, "OpenXRAction", 0, JS_CFUNC_constructor, 0);
	define_open_xr_action_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRAction", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_action_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_action_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRAction");
	return m;
}

JSModuleDef *js_init_open_xr_action_module(JSContext *ctx) {
	return _js_init_open_xr_action_module(ctx, "@godot/classes/open_xr_action");
}

void __register_open_xr_action() {
	js_init_open_xr_action_module(js_context());
}

void register_open_xr_action() {
	__register_open_xr_action();
}