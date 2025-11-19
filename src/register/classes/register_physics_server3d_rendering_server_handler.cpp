#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_server3d_rendering_server_handler.hpp>
using namespace godot;

static void physics_server3d_rendering_server_handler_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsServer3DRenderingServerHandler"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_server3d_rendering_server_handler_class_def = {
    "PhysicsServer3DRenderingServerHandler",
    physics_server3d_rendering_server_handler_class_finalizer
};

static JSValue physics_server3d_rendering_server_handler_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsServer3DRenderingServerHandler"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicsServer3DRenderingServerHandler *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicsServer3DRenderingServerHandler *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicsServer3DRenderingServerHandler);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_server3d_rendering_server_handler_class_set_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsServer3DRenderingServerHandler::set_vertex, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_rendering_server_handler_class_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsServer3DRenderingServerHandler::set_normal, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_rendering_server_handler_class_set_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsServer3DRenderingServerHandler::set_aabb, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry physics_server3d_rendering_server_handler_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_vertex", 2, &physics_server3d_rendering_server_handler_class_set_vertex),
	JS_CFUNC_DEF("set_normal", 2, &physics_server3d_rendering_server_handler_class_set_normal),
	JS_CFUNC_DEF("set_aabb", 1, &physics_server3d_rendering_server_handler_class_set_aabb),
};




static void define_physics_server3d_rendering_server_handler_property(JSContext *ctx, JSValue proto) {
}

static void define_physics_server3d_rendering_server_handler_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_server3d_rendering_server_handler_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsServer3DRenderingServerHandler"] = class_id;
	classes_by_id[class_id] = "PhysicsServer3DRenderingServerHandler";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_server3d_rendering_server_handler_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_server3d_rendering_server_handler_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_server3d_rendering_server_handler_class_proto_funcs, _countof(physics_server3d_rendering_server_handler_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_server3d_rendering_server_handler_class_constructor, "PhysicsServer3DRenderingServerHandler", 0, JS_CFUNC_constructor, 0);
	define_physics_server3d_rendering_server_handler_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsServer3DRenderingServerHandler", ctor);

	return 0;
}

JSModuleDef *_js_init_physics_server3d_rendering_server_handler_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_server3d_rendering_server_handler_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsServer3DRenderingServerHandler");
	return m;
}

JSModuleDef *js_init_physics_server3d_rendering_server_handler_module(JSContext *ctx) {
	return _js_init_physics_server3d_rendering_server_handler_module(ctx, "@godot/classes/physics_server3d_rendering_server_handler");
}

void __register_physics_server3d_rendering_server_handler() {
	js_init_physics_server3d_rendering_server_handler_module(js_context());
}

void register_physics_server3d_rendering_server_handler() {
	__register_physics_server3d_rendering_server_handler();
}