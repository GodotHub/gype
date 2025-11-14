#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/upnp_device.hpp>
using namespace godot;

static void upnp_device_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["UPNPDevice"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef upnp_device_class_def = {
    "UPNPDevice",
    upnp_device_class_finalizer
};

static JSValue upnp_device_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["UPNPDevice"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    UPNPDevice *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<UPNPDevice *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(UPNPDevice);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue upnp_device_class_is_valid_gateway(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&UPNPDevice::is_valid_gateway, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_query_external_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&UPNPDevice::query_external_address, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_add_port_mapping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&UPNPDevice::add_port_mapping, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_delete_port_mapping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&UPNPDevice::delete_port_mapping, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_set_description_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&UPNPDevice::set_description_url, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_get_description_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		UPNPDevice *obj = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_description_url();
	};
	proxy->setter = [this_val](const String &value) -> void {
		UPNPDevice *js_proxy = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_description_url(value);
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
static JSValue upnp_device_class_set_service_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&UPNPDevice::set_service_type, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_get_service_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		UPNPDevice *obj = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_service_type();
	};
	proxy->setter = [this_val](const String &value) -> void {
		UPNPDevice *js_proxy = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_service_type(value);
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
static JSValue upnp_device_class_set_igd_control_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&UPNPDevice::set_igd_control_url, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_get_igd_control_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		UPNPDevice *obj = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_igd_control_url();
	};
	proxy->setter = [this_val](const String &value) -> void {
		UPNPDevice *js_proxy = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_igd_control_url(value);
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
static JSValue upnp_device_class_set_igd_service_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&UPNPDevice::set_igd_service_type, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_get_igd_service_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		UPNPDevice *obj = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_igd_service_type();
	};
	proxy->setter = [this_val](const String &value) -> void {
		UPNPDevice *js_proxy = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_igd_service_type(value);
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
static JSValue upnp_device_class_set_igd_our_addr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&UPNPDevice::set_igd_our_addr, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_get_igd_our_addr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		UPNPDevice *obj = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_igd_our_addr();
	};
	proxy->setter = [this_val](const String &value) -> void {
		UPNPDevice *js_proxy = static_cast<UPNPDevice *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_igd_our_addr(value);
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
static JSValue upnp_device_class_set_igd_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&UPNPDevice::set_igd_status, ctx, this_val, argc, argv);
};
static JSValue upnp_device_class_get_igd_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&UPNPDevice::get_igd_status, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry upnp_device_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_valid_gateway", 0, &upnp_device_class_is_valid_gateway),
	JS_CFUNC_DEF("query_external_address", 0, &upnp_device_class_query_external_address),
	JS_CFUNC_DEF("add_port_mapping", 5, &upnp_device_class_add_port_mapping),
	JS_CFUNC_DEF("delete_port_mapping", 2, &upnp_device_class_delete_port_mapping),
	JS_CFUNC_DEF("set_description_url", 1, &upnp_device_class_set_description_url),
	JS_CFUNC_DEF("get_description_url", 0, &upnp_device_class_get_description_url),
	JS_CFUNC_DEF("set_service_type", 1, &upnp_device_class_set_service_type),
	JS_CFUNC_DEF("get_service_type", 0, &upnp_device_class_get_service_type),
	JS_CFUNC_DEF("set_igd_control_url", 1, &upnp_device_class_set_igd_control_url),
	JS_CFUNC_DEF("get_igd_control_url", 0, &upnp_device_class_get_igd_control_url),
	JS_CFUNC_DEF("set_igd_service_type", 1, &upnp_device_class_set_igd_service_type),
	JS_CFUNC_DEF("get_igd_service_type", 0, &upnp_device_class_get_igd_service_type),
	JS_CFUNC_DEF("set_igd_our_addr", 1, &upnp_device_class_set_igd_our_addr),
	JS_CFUNC_DEF("get_igd_our_addr", 0, &upnp_device_class_get_igd_our_addr),
	JS_CFUNC_DEF("set_igd_status", 1, &upnp_device_class_set_igd_status),
	JS_CFUNC_DEF("get_igd_status", 0, &upnp_device_class_get_igd_status),
};




static void define_upnp_device_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "description_url"),
        JS_NewCFunction(ctx, upnp_device_class_get_description_url, "get_description_url", 0),
        JS_NewCFunction(ctx, upnp_device_class_set_description_url, "set_description_url", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "service_type"),
        JS_NewCFunction(ctx, upnp_device_class_get_service_type, "get_service_type", 0),
        JS_NewCFunction(ctx, upnp_device_class_set_service_type, "set_service_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "igd_control_url"),
        JS_NewCFunction(ctx, upnp_device_class_get_igd_control_url, "get_igd_control_url", 0),
        JS_NewCFunction(ctx, upnp_device_class_set_igd_control_url, "set_igd_control_url", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "igd_service_type"),
        JS_NewCFunction(ctx, upnp_device_class_get_igd_service_type, "get_igd_service_type", 0),
        JS_NewCFunction(ctx, upnp_device_class_set_igd_service_type, "set_igd_service_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "igd_our_addr"),
        JS_NewCFunction(ctx, upnp_device_class_get_igd_our_addr, "get_igd_our_addr", 0),
        JS_NewCFunction(ctx, upnp_device_class_set_igd_our_addr, "set_igd_our_addr", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "igd_status"),
        JS_NewCFunction(ctx, upnp_device_class_get_igd_status, "get_igd_status", 0),
        JS_NewCFunction(ctx, upnp_device_class_set_igd_status, "set_igd_status", 1),
        JS_PROP_GETSET
    );
}

static void define_upnp_device_enum(JSContext *ctx, JSValue proto) {
	JSValue IGDStatus_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_OK", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_HTTP_ERROR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_HTTP_EMPTY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_NO_URLS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_NO_IGD", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_DISCONNECTED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_UNKNOWN_DEVICE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_INVALID_CONTROL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_MALLOC_ERROR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, IGDStatus_obj, "IGD_STATUS_UNKNOWN_ERROR", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, proto, "IGDStatus", IGDStatus_obj);
}

static int js_upnp_device_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["UPNPDevice"] = class_id;
	classes_by_id[class_id] = "UPNPDevice";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &upnp_device_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_upnp_device_property(ctx, proto);
	define_upnp_device_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, upnp_device_class_proto_funcs, _countof(upnp_device_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, upnp_device_class_constructor, "UPNPDevice", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "UPNPDevice", ctor);

	return 0;
}

JSModuleDef *_js_init_upnp_device_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_upnp_device_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "UPNPDevice");
	return m;
}

JSModuleDef *js_init_upnp_device_module(JSContext *ctx) {
	return _js_init_upnp_device_module(ctx, "@godot/classes/upnp_device");
}

void __register_upnp_device() {
	js_init_upnp_device_module(js_context());
}

void register_upnp_device() {
	__register_upnp_device();
}