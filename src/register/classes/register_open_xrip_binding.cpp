#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_action.hpp>
#include <godot_cpp/classes/open_xr_action_binding_modifier.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xrip_binding.hpp>
using namespace godot;

static void open_xrip_binding_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRIPBinding"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xrip_binding_class_def = {
    "OpenXRIPBinding",
    open_xrip_binding_class_finalizer
};

static JSValue open_xrip_binding_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRIPBinding"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRIPBinding *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRIPBinding *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRIPBinding);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xrip_binding_class_set_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRIPBinding::set_action, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_get_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRIPBinding::get_action, ctx, this_val, argc, argv);
}
static JSValue open_xrip_binding_class_set_binding_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRIPBinding::set_binding_path, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_get_binding_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		OpenXRIPBinding *obj = static_cast<OpenXRIPBinding *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_binding_path();
	};
	proxy->setter = [this_val](const String &value) -> void {
		OpenXRIPBinding *js_proxy = static_cast<OpenXRIPBinding *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_binding_path(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue open_xrip_binding_class_get_binding_modifier_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRIPBinding::get_binding_modifier_count, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_get_binding_modifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRIPBinding::get_binding_modifier, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_set_binding_modifiers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRIPBinding::set_binding_modifiers, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_get_binding_modifiers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRIPBinding::get_binding_modifiers, ctx, this_val, argc, argv);
}
static JSValue open_xrip_binding_class_set_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRIPBinding::set_paths, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_get_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		OpenXRIPBinding *obj = static_cast<OpenXRIPBinding *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_paths();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		OpenXRIPBinding *js_proxy = static_cast<OpenXRIPBinding *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_paths(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue open_xrip_binding_class_get_path_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRIPBinding::get_path_count, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_has_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRIPBinding::has_path, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_add_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRIPBinding::add_path, ctx, this_val, argc, argv);
};
static JSValue open_xrip_binding_class_remove_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRIPBinding::remove_path, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry open_xrip_binding_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_action", 1, &open_xrip_binding_class_set_action),
	JS_CFUNC_DEF("get_action", 0, &open_xrip_binding_class_get_action),
	JS_CFUNC_DEF("set_binding_path", 1, &open_xrip_binding_class_set_binding_path),
	JS_CFUNC_DEF("get_binding_path", 0, &open_xrip_binding_class_get_binding_path),
	JS_CFUNC_DEF("get_binding_modifier_count", 0, &open_xrip_binding_class_get_binding_modifier_count),
	JS_CFUNC_DEF("get_binding_modifier", 1, &open_xrip_binding_class_get_binding_modifier),
	JS_CFUNC_DEF("set_binding_modifiers", 1, &open_xrip_binding_class_set_binding_modifiers),
	JS_CFUNC_DEF("get_binding_modifiers", 0, &open_xrip_binding_class_get_binding_modifiers),
	JS_CFUNC_DEF("set_paths", 1, &open_xrip_binding_class_set_paths),
	JS_CFUNC_DEF("get_paths", 0, &open_xrip_binding_class_get_paths),
	JS_CFUNC_DEF("get_path_count", 0, &open_xrip_binding_class_get_path_count),
	JS_CFUNC_DEF("has_path", 1, &open_xrip_binding_class_has_path),
	JS_CFUNC_DEF("add_path", 1, &open_xrip_binding_class_add_path),
	JS_CFUNC_DEF("remove_path", 1, &open_xrip_binding_class_remove_path),
};




static void define_open_xrip_binding_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action"),
        JS_NewCFunction(ctx, open_xrip_binding_class_get_action, "get_action", 0),
        JS_NewCFunction(ctx, open_xrip_binding_class_set_action, "set_action", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "binding_path"),
        JS_NewCFunction(ctx, open_xrip_binding_class_get_binding_path, "get_binding_path", 0),
        JS_NewCFunction(ctx, open_xrip_binding_class_set_binding_path, "set_binding_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "binding_modifiers"),
        JS_NewCFunction(ctx, open_xrip_binding_class_get_binding_modifiers, "get_binding_modifiers", 0),
        JS_NewCFunction(ctx, open_xrip_binding_class_set_binding_modifiers, "set_binding_modifiers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "paths"),
        JS_NewCFunction(ctx, open_xrip_binding_class_get_paths, "get_paths", 0),
        JS_NewCFunction(ctx, open_xrip_binding_class_set_paths, "set_paths", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xrip_binding_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xrip_binding_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRIPBinding"] = class_id;
	classes_by_id[class_id] = "OpenXRIPBinding";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xrip_binding_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xrip_binding_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xrip_binding_class_proto_funcs, _countof(open_xrip_binding_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xrip_binding_class_constructor, "OpenXRIPBinding", 0, JS_CFUNC_constructor, 0);
	define_open_xrip_binding_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRIPBinding", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xrip_binding_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xrip_binding_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRIPBinding");
	return m;
}

JSModuleDef *js_init_open_xrip_binding_module(JSContext *ctx) {
	return _js_init_open_xrip_binding_module(ctx, "@godot/classes/open_xrip_binding");
}

void __register_open_xrip_binding() {
	js_init_open_xrip_binding_module(js_context());
}

void register_open_xrip_binding() {
	__register_open_xrip_binding();
}