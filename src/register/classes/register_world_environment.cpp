#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera_attributes.hpp>
#include <godot_cpp/classes/compositor.hpp>
#include <godot_cpp/classes/environment.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/world_environment.hpp>
using namespace godot;

static void world_environment_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WorldEnvironment"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef world_environment_class_def = {
    "WorldEnvironment",
    world_environment_class_finalizer
};

static JSValue world_environment_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WorldEnvironment"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WorldEnvironment *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WorldEnvironment *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WorldEnvironment);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue world_environment_class_set_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WorldEnvironment::set_environment, ctx, this_val, argc, argv);
};
static JSValue world_environment_class_get_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WorldEnvironment::get_environment, ctx, this_val, argc, argv);
}
static JSValue world_environment_class_set_camera_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WorldEnvironment::set_camera_attributes, ctx, this_val, argc, argv);
};
static JSValue world_environment_class_get_camera_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WorldEnvironment::get_camera_attributes, ctx, this_val, argc, argv);
}
static JSValue world_environment_class_set_compositor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WorldEnvironment::set_compositor, ctx, this_val, argc, argv);
};
static JSValue world_environment_class_get_compositor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WorldEnvironment::get_compositor, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry world_environment_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_environment", 1, &world_environment_class_set_environment),
	JS_CFUNC_DEF("get_environment", 0, &world_environment_class_get_environment),
	JS_CFUNC_DEF("set_camera_attributes", 1, &world_environment_class_set_camera_attributes),
	JS_CFUNC_DEF("get_camera_attributes", 0, &world_environment_class_get_camera_attributes),
	JS_CFUNC_DEF("set_compositor", 1, &world_environment_class_set_compositor),
	JS_CFUNC_DEF("get_compositor", 0, &world_environment_class_get_compositor),
};




static void define_world_environment_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "environment"),
        JS_NewCFunction(ctx, world_environment_class_get_environment, "get_environment", 0),
        JS_NewCFunction(ctx, world_environment_class_set_environment, "set_environment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "camera_attributes"),
        JS_NewCFunction(ctx, world_environment_class_get_camera_attributes, "get_camera_attributes", 0),
        JS_NewCFunction(ctx, world_environment_class_set_camera_attributes, "set_camera_attributes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "compositor"),
        JS_NewCFunction(ctx, world_environment_class_get_compositor, "get_compositor", 0),
        JS_NewCFunction(ctx, world_environment_class_set_compositor, "set_compositor", 1),
        JS_PROP_GETSET
    );
}

static void define_world_environment_enum(JSContext *ctx, JSValue ctor) {
}

static int js_world_environment_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WorldEnvironment"] = class_id;
	classes_by_id[class_id] = "WorldEnvironment";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &world_environment_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_world_environment_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, world_environment_class_proto_funcs, _countof(world_environment_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, world_environment_class_constructor, "WorldEnvironment", 0, JS_CFUNC_constructor, 0);
	define_world_environment_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WorldEnvironment", ctor);

	return 0;
}

JSModuleDef *_js_init_world_environment_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_world_environment_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WorldEnvironment");
	return m;
}

JSModuleDef *js_init_world_environment_module(JSContext *ctx) {
	return _js_init_world_environment_module(ctx, "@godot/classes/world_environment");
}

void __register_world_environment() {
	js_init_world_environment_module(js_context());
}

void register_world_environment() {
	__register_world_environment();
}