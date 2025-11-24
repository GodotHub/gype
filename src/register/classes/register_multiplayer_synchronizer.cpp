#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_replication_config.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/multiplayer_synchronizer.hpp>
using namespace godot;

static void multiplayer_synchronizer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MultiplayerSynchronizer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef multiplayer_synchronizer_class_def = {
    "MultiplayerSynchronizer",
    multiplayer_synchronizer_class_finalizer
};

static JSValue multiplayer_synchronizer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MultiplayerSynchronizer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MultiplayerSynchronizer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MultiplayerSynchronizer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MultiplayerSynchronizer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue multiplayer_synchronizer_class_set_root_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_root_path, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_get_root_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSynchronizer::get_root_path, ctx, this_val, argc, argv);
}
static JSValue multiplayer_synchronizer_class_set_replication_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_replication_interval, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_get_replication_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSynchronizer::get_replication_interval, ctx, this_val, argc, argv);
}
static JSValue multiplayer_synchronizer_class_set_delta_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_delta_interval, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_get_delta_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSynchronizer::get_delta_interval, ctx, this_val, argc, argv);
}
static JSValue multiplayer_synchronizer_class_set_replication_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_replication_config, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_get_replication_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerSynchronizer::get_replication_config, ctx, this_val, argc, argv);
}
static JSValue multiplayer_synchronizer_class_set_visibility_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_visibility_update_mode, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_get_visibility_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSynchronizer::get_visibility_update_mode, ctx, this_val, argc, argv);
}
static JSValue multiplayer_synchronizer_class_update_visibility(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::update_visibility, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_set_visibility_public(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_visibility_public, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_is_visibility_public(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSynchronizer::is_visibility_public, ctx, this_val, argc, argv);
}
static JSValue multiplayer_synchronizer_class_add_visibility_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::add_visibility_filter, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_remove_visibility_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::remove_visibility_filter, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_set_visibility_for(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSynchronizer::set_visibility_for, ctx, this_val, argc, argv);
};
static JSValue multiplayer_synchronizer_class_get_visibility_for(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSynchronizer::get_visibility_for, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry multiplayer_synchronizer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_root_path", 1, &multiplayer_synchronizer_class_set_root_path),
	JS_CFUNC_DEF("get_root_path", 0, &multiplayer_synchronizer_class_get_root_path),
	JS_CFUNC_DEF("set_replication_interval", 1, &multiplayer_synchronizer_class_set_replication_interval),
	JS_CFUNC_DEF("get_replication_interval", 0, &multiplayer_synchronizer_class_get_replication_interval),
	JS_CFUNC_DEF("set_delta_interval", 1, &multiplayer_synchronizer_class_set_delta_interval),
	JS_CFUNC_DEF("get_delta_interval", 0, &multiplayer_synchronizer_class_get_delta_interval),
	JS_CFUNC_DEF("set_replication_config", 1, &multiplayer_synchronizer_class_set_replication_config),
	JS_CFUNC_DEF("get_replication_config", 0, &multiplayer_synchronizer_class_get_replication_config),
	JS_CFUNC_DEF("set_visibility_update_mode", 1, &multiplayer_synchronizer_class_set_visibility_update_mode),
	JS_CFUNC_DEF("get_visibility_update_mode", 0, &multiplayer_synchronizer_class_get_visibility_update_mode),
	JS_CFUNC_DEF("update_visibility", 1, &multiplayer_synchronizer_class_update_visibility),
	JS_CFUNC_DEF("set_visibility_public", 1, &multiplayer_synchronizer_class_set_visibility_public),
	JS_CFUNC_DEF("is_visibility_public", 0, &multiplayer_synchronizer_class_is_visibility_public),
	JS_CFUNC_DEF("add_visibility_filter", 1, &multiplayer_synchronizer_class_add_visibility_filter),
	JS_CFUNC_DEF("remove_visibility_filter", 1, &multiplayer_synchronizer_class_remove_visibility_filter),
	JS_CFUNC_DEF("set_visibility_for", 2, &multiplayer_synchronizer_class_set_visibility_for),
	JS_CFUNC_DEF("get_visibility_for", 1, &multiplayer_synchronizer_class_get_visibility_for),
};


static JSValue multiplayer_synchronizer_class_get_synchronized_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerSynchronizer *opaque = static_cast<MultiplayerSynchronizer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "synchronized_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "synchronized"));
		JS_DefinePropertyValueStr(ctx, this_val, "synchronized_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_synchronizer_class_get_delta_synchronized_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerSynchronizer *opaque = static_cast<MultiplayerSynchronizer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "delta_synchronized_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "delta_synchronized"));
		JS_DefinePropertyValueStr(ctx, this_val, "delta_synchronized_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_synchronizer_class_get_visibility_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerSynchronizer *opaque = static_cast<MultiplayerSynchronizer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "visibility_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "visibility_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "visibility_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_multiplayer_synchronizer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root_path"),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_root_path, "get_root_path", 0),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_set_root_path, "set_root_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "replication_interval"),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_replication_interval, "get_replication_interval", 0),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_set_replication_interval, "set_replication_interval", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "delta_interval"),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_delta_interval, "get_delta_interval", 0),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_set_delta_interval, "set_delta_interval", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "replication_config"),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_replication_config, "get_replication_config", 0),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_set_replication_config, "set_replication_config", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_update_mode"),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_visibility_update_mode, "get_visibility_update_mode", 0),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_set_visibility_update_mode, "set_visibility_update_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "public_visibility"),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_is_visibility_public, "is_visibility_public", 0),
        JS_NewCFunction(ctx, multiplayer_synchronizer_class_set_visibility_public, "set_visibility_public", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "synchronized"),
		JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_synchronized_signal, "get_synchronized_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "delta_synchronized"),
		JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_delta_synchronized_signal, "get_delta_synchronized_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "visibility_changed"),
		JS_NewCFunction(ctx, multiplayer_synchronizer_class_get_visibility_changed_signal, "get_visibility_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_multiplayer_synchronizer_enum(JSContext *ctx, JSValue ctor) {
	JSValue VisibilityUpdateMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VisibilityUpdateMode_obj, "VISIBILITY_PROCESS_IDLE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VisibilityUpdateMode_obj, "VISIBILITY_PROCESS_PHYSICS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VisibilityUpdateMode_obj, "VISIBILITY_PROCESS_NONE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "VisibilityUpdateMode", VisibilityUpdateMode_obj);
}

static int js_multiplayer_synchronizer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MultiplayerSynchronizer"] = class_id;
	classes_by_id[class_id] = "MultiplayerSynchronizer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &multiplayer_synchronizer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_multiplayer_synchronizer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, multiplayer_synchronizer_class_proto_funcs, _countof(multiplayer_synchronizer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, multiplayer_synchronizer_class_constructor, "MultiplayerSynchronizer", 0, JS_CFUNC_constructor, 0);
	define_multiplayer_synchronizer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MultiplayerSynchronizer", ctor);

	return 0;
}

JSModuleDef *_js_init_multiplayer_synchronizer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_multiplayer_synchronizer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MultiplayerSynchronizer");
	return m;
}

JSModuleDef *js_init_multiplayer_synchronizer_module(JSContext *ctx) {
	return _js_init_multiplayer_synchronizer_module(ctx, "@godot/classes/multiplayer_synchronizer");
}

void __register_multiplayer_synchronizer() {
	js_init_multiplayer_synchronizer_module(js_context());
}

void register_multiplayer_synchronizer() {
	__register_multiplayer_synchronizer();
}