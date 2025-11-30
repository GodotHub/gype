#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/resource.hpp>
using namespace godot;

static void resource_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Resource"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef resource_class_def = {
    "Resource",
    resource_class_finalizer
};

static JSValue resource_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Resource"];
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
        instance = memnew(Resource);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue resource_class_set_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::set_path, ctx, this_val, argc, argv);
};
static JSValue resource_class_take_over_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::take_over_path, ctx, this_val, argc, argv);
};
static JSValue resource_class_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::get_path, ctx, this_val, argc, argv);
}
static JSValue resource_class_set_path_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::set_path_cache, ctx, this_val, argc, argv);
};
static JSValue resource_class_set_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::set_name, ctx, this_val, argc, argv);
};
static JSValue resource_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::get_name, ctx, this_val, argc, argv);
}
static JSValue resource_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::get_rid, ctx, this_val, argc, argv);
};
static JSValue resource_class_set_local_to_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::set_local_to_scene, ctx, this_val, argc, argv);
};
static JSValue resource_class_is_local_to_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::is_local_to_scene, ctx, this_val, argc, argv);
}
static JSValue resource_class_get_local_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::get_local_scene, ctx, this_val, argc, argv);
};
static JSValue resource_class_setup_local_to_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::setup_local_to_scene, ctx, this_val, argc, argv);
};
static JSValue resource_class_reset_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::reset_state, ctx, this_val, argc, argv);
};
static JSValue resource_class_set_id_for_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::set_id_for_path, ctx, this_val, argc, argv);
};
static JSValue resource_class_get_id_for_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::get_id_for_path, ctx, this_val, argc, argv);
};
static JSValue resource_class_is_built_in(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::is_built_in, ctx, this_val, argc, argv);
};
static JSValue resource_class_set_scene_unique_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::set_scene_unique_id, ctx, this_val, argc, argv);
};
static JSValue resource_class_get_scene_unique_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::get_scene_unique_id, ctx, this_val, argc, argv);
}
static JSValue resource_class_emit_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Resource::emit_changed, ctx, this_val, argc, argv);
};
static JSValue resource_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::duplicate, ctx, this_val, argc, argv);
};
static JSValue resource_class_duplicate_deep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Resource::duplicate_deep, ctx, this_val, argc, argv);
};


static JSValue resource_class_generate_scene_unique_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Resource::generate_scene_unique_id, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry resource_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_path", 1, &resource_class_set_path),
	JS_CFUNC_DEF("take_over_path", 1, &resource_class_take_over_path),
	JS_CFUNC_DEF("get_path", 0, &resource_class_get_path),
	JS_CFUNC_DEF("set_path_cache", 1, &resource_class_set_path_cache),
	JS_CFUNC_DEF("set_name", 1, &resource_class_set_name),
	JS_CFUNC_DEF("get_name", 0, &resource_class_get_name),
	JS_CFUNC_DEF("get_rid", 0, &resource_class_get_rid),
	JS_CFUNC_DEF("set_local_to_scene", 1, &resource_class_set_local_to_scene),
	JS_CFUNC_DEF("is_local_to_scene", 0, &resource_class_is_local_to_scene),
	JS_CFUNC_DEF("get_local_scene", 0, &resource_class_get_local_scene),
	JS_CFUNC_DEF("setup_local_to_scene", 0, &resource_class_setup_local_to_scene),
	JS_CFUNC_DEF("reset_state", 0, &resource_class_reset_state),
	JS_CFUNC_DEF("set_id_for_path", 2, &resource_class_set_id_for_path),
	JS_CFUNC_DEF("get_id_for_path", 1, &resource_class_get_id_for_path),
	JS_CFUNC_DEF("is_built_in", 0, &resource_class_is_built_in),
	JS_CFUNC_DEF("set_scene_unique_id", 1, &resource_class_set_scene_unique_id),
	JS_CFUNC_DEF("get_scene_unique_id", 0, &resource_class_get_scene_unique_id),
	JS_CFUNC_DEF("emit_changed", 0, &resource_class_emit_changed),
	JS_CFUNC_DEF("duplicate", 1, &resource_class_duplicate),
	JS_CFUNC_DEF("duplicate_deep", 1, &resource_class_duplicate_deep),
};

static const JSCFunctionListEntry resource_class_static_funcs[] = {
	JS_CFUNC_DEF("generate_scene_unique_id", 0, &resource_class_generate_scene_unique_id),
};

static JSValue resource_class_get_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue resource_class_get_setup_local_to_scene_requested_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "setup_local_to_scene_requested");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_resource_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resource_local_to_scene"),
        JS_NewCFunction(ctx, resource_class_is_local_to_scene, "is_local_to_scene", 0),
        JS_NewCFunction(ctx, resource_class_set_local_to_scene, "set_local_to_scene", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resource_path"),
        JS_NewCFunction(ctx, resource_class_get_path, "get_path", 0),
        JS_NewCFunction(ctx, resource_class_set_path, "set_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resource_name"),
        JS_NewCFunction(ctx, resource_class_get_name, "get_name", 0),
        JS_NewCFunction(ctx, resource_class_set_name, "set_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resource_scene_unique_id"),
        JS_NewCFunction(ctx, resource_class_get_scene_unique_id, "get_scene_unique_id", 0),
        JS_NewCFunction(ctx, resource_class_set_scene_unique_id, "set_scene_unique_id", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "changed"),
		JS_NewCFunction(ctx, resource_class_get_changed_signal, "get_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "setup_local_to_scene_requested"),
		JS_NewCFunction(ctx, resource_class_get_setup_local_to_scene_requested_signal, "get_setup_local_to_scene_requested_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_resource_enum(JSContext *ctx, JSValue ctor) {
	JSValue DeepDuplicateMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DeepDuplicateMode_obj, "DEEP_DUPLICATE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DeepDuplicateMode_obj, "DEEP_DUPLICATE_INTERNAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DeepDuplicateMode_obj, "DEEP_DUPLICATE_ALL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DeepDuplicateMode", DeepDuplicateMode_obj);
}

static int js_resource_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Resource"] = class_id;
	classes_by_id[class_id] = "Resource";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &resource_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_resource_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, resource_class_proto_funcs, _countof(resource_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, resource_class_constructor, "Resource", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, resource_class_static_funcs, _countof(resource_class_static_funcs));
	define_resource_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Resource", ctor);
	ctor_list["Resource"] = ctor;

	return 0;
}

JSModuleDef *_js_init_resource_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_resource_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Resource");
	return m;
}

JSModuleDef *js_init_resource_module(JSContext *ctx) {
	return _js_init_resource_module(ctx, "@godot/classes/resource");
}

void __register_resource() {
	js_init_resource_module(js_context());
}

void register_resource() {
	__register_resource();
}