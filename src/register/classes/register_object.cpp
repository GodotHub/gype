#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include "register/classes/class_object_vararg.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/object.hpp>
using namespace godot;

static void godot_object_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GodotObject"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef godot_object_class_def = {
    "GodotObject",
    godot_object_class_finalizer
};

static JSValue godot_object_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GodotObject"];
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
        instance = memnew(Object);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue godot_object_class_get_class(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_class, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_is_class(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::is_class, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_indexed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_indexed, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_indexed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_indexed, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_property_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_property_list, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_method_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_method_list, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_property_can_revert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::property_can_revert, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_property_get_revert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::property_get_revert, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_notification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::notification, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_to_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Object::to_string, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_instance_id, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_script, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_script, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_meta, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_remove_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::remove_meta, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_meta, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_has_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::has_meta, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_meta_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_meta_list, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_add_user_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::add_user_signal, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_has_user_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::has_user_signal, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_remove_user_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::remove_user_signal, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_deferred(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_deferred, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_callv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Object::callv, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_has_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::has_method, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_method_argument_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_method_argument_count, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_has_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::has_signal, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_signal_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_signal_list, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_signal_connection_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_signal_connection_list, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_incoming_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_incoming_connections, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Object::connect, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_disconnect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::disconnect, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_is_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::is_connected, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_has_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::has_connections, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_block_signals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_block_signals, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_is_blocking_signals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::is_blocking_signals, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_notify_property_list_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::notify_property_list_changed, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_message_translation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_message_translation, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_can_translate_messages(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::can_translate_messages, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_tr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::tr, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_tr_n(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::tr_n, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_get_translation_domain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::get_translation_domain, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_set_translation_domain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::set_translation_domain, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_is_queued_for_deletion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Object::is_queued_for_deletion, ctx, this_val, argc, argv);
};
static JSValue godot_object_class_cancel_free(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Object::cancel_free, ctx, this_val, argc, argv);
};


static JSValue godot_object_class_emit_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_emit_signal, ctx, this_val, argc, argv);
}
static JSValue godot_object_class_call(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_call, ctx, this_val, argc, argv);
}
static JSValue godot_object_class_call_deferred(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_call_deferred, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry godot_object_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_class", 0, &godot_object_class_get_class),
	JS_CFUNC_DEF("is_class", 1, &godot_object_class_is_class),
	JS_CFUNC_DEF("set", 2, &godot_object_class_set),
	JS_CFUNC_DEF("get", 1, &godot_object_class_get),
	JS_CFUNC_DEF("set_indexed", 2, &godot_object_class_set_indexed),
	JS_CFUNC_DEF("get_indexed", 1, &godot_object_class_get_indexed),
	JS_CFUNC_DEF("get_property_list", 0, &godot_object_class_get_property_list),
	JS_CFUNC_DEF("get_method_list", 0, &godot_object_class_get_method_list),
	JS_CFUNC_DEF("property_can_revert", 1, &godot_object_class_property_can_revert),
	JS_CFUNC_DEF("property_get_revert", 1, &godot_object_class_property_get_revert),
	JS_CFUNC_DEF("notification", 2, &godot_object_class_notification),
	JS_CFUNC_DEF("to_string", 0, &godot_object_class_to_string),
	JS_CFUNC_DEF("get_instance_id", 0, &godot_object_class_get_instance_id),
	JS_CFUNC_DEF("set_script", 1, &godot_object_class_set_script),
	JS_CFUNC_DEF("get_script", 0, &godot_object_class_get_script),
	JS_CFUNC_DEF("set_meta", 2, &godot_object_class_set_meta),
	JS_CFUNC_DEF("remove_meta", 1, &godot_object_class_remove_meta),
	JS_CFUNC_DEF("get_meta", 2, &godot_object_class_get_meta),
	JS_CFUNC_DEF("has_meta", 1, &godot_object_class_has_meta),
	JS_CFUNC_DEF("get_meta_list", 0, &godot_object_class_get_meta_list),
	JS_CFUNC_DEF("add_user_signal", 2, &godot_object_class_add_user_signal),
	JS_CFUNC_DEF("has_user_signal", 1, &godot_object_class_has_user_signal),
	JS_CFUNC_DEF("remove_user_signal", 1, &godot_object_class_remove_user_signal),
	JS_CFUNC_DEF("set_deferred", 2, &godot_object_class_set_deferred),
	JS_CFUNC_DEF("callv", 2, &godot_object_class_callv),
	JS_CFUNC_DEF("has_method", 1, &godot_object_class_has_method),
	JS_CFUNC_DEF("get_method_argument_count", 1, &godot_object_class_get_method_argument_count),
	JS_CFUNC_DEF("has_signal", 1, &godot_object_class_has_signal),
	JS_CFUNC_DEF("get_signal_list", 0, &godot_object_class_get_signal_list),
	JS_CFUNC_DEF("get_signal_connection_list", 1, &godot_object_class_get_signal_connection_list),
	JS_CFUNC_DEF("get_incoming_connections", 0, &godot_object_class_get_incoming_connections),
	JS_CFUNC_DEF("connect", 3, &godot_object_class_connect),
	JS_CFUNC_DEF("disconnect", 2, &godot_object_class_disconnect),
	JS_CFUNC_DEF("is_connected", 2, &godot_object_class_is_connected),
	JS_CFUNC_DEF("has_connections", 1, &godot_object_class_has_connections),
	JS_CFUNC_DEF("set_block_signals", 1, &godot_object_class_set_block_signals),
	JS_CFUNC_DEF("is_blocking_signals", 0, &godot_object_class_is_blocking_signals),
	JS_CFUNC_DEF("notify_property_list_changed", 0, &godot_object_class_notify_property_list_changed),
	JS_CFUNC_DEF("set_message_translation", 1, &godot_object_class_set_message_translation),
	JS_CFUNC_DEF("can_translate_messages", 0, &godot_object_class_can_translate_messages),
	JS_CFUNC_DEF("tr", 2, &godot_object_class_tr),
	JS_CFUNC_DEF("tr_n", 4, &godot_object_class_tr_n),
	JS_CFUNC_DEF("get_translation_domain", 0, &godot_object_class_get_translation_domain),
	JS_CFUNC_DEF("set_translation_domain", 1, &godot_object_class_set_translation_domain),
	JS_CFUNC_DEF("is_queued_for_deletion", 0, &godot_object_class_is_queued_for_deletion),
	JS_CFUNC_DEF("cancel_free", 0, &godot_object_class_cancel_free),
	JS_CFUNC_DEF("emit_signal", 1, &godot_object_class_emit_signal),
	JS_CFUNC_DEF("call", 1, &godot_object_class_call),
	JS_CFUNC_DEF("call_deferred", 1, &godot_object_class_call_deferred),
};


static JSValue godot_object_class_get_script_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Object *opaque = static_cast<Object *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "script_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "script_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "script_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue godot_object_class_get_property_list_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Object *opaque = static_cast<Object *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_list_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_list_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_list_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_godot_object_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "script_changed"),
		JS_NewCFunction(ctx, godot_object_class_get_script_changed_signal, "get_script_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_list_changed"),
		JS_NewCFunction(ctx, godot_object_class_get_property_list_changed_signal, "get_property_list_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_godot_object_enum(JSContext *ctx, JSValue ctor) {
	JSValue ConnectFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ConnectFlags_obj, "CONNECT_DEFERRED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ConnectFlags_obj, "CONNECT_PERSIST", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ConnectFlags_obj, "CONNECT_ONE_SHOT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ConnectFlags_obj, "CONNECT_REFERENCE_COUNTED", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ConnectFlags_obj, "CONNECT_APPEND_SOURCE_OBJECT", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ctor, "ConnectFlags", ConnectFlags_obj);
}

static int js_godot_object_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GodotObject"] = class_id;
	classes_by_id[class_id] = "GodotObject";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &godot_object_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JS_SetClassProto(ctx, class_id, proto);

	define_godot_object_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, godot_object_class_proto_funcs, _countof(godot_object_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, godot_object_class_constructor, "GodotObject", 0, JS_CFUNC_constructor, 0);
	define_godot_object_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GodotObject", ctor);
	ctor_list["Object"] = ctor;

	return 0;
}

JSModuleDef *_js_init_godot_object_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_godot_object_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GodotObject");
	return m;
}

JSModuleDef *js_init_godot_object_module(JSContext *ctx) {
	return _js_init_godot_object_module(ctx, "@godot/classes/godot_object");
}

void __register_godot_object() {
	js_init_godot_object_module(js_context());
}

void register_godot_object() {
	__register_godot_object();
}