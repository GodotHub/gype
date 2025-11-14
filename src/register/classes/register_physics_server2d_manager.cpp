#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_server2d_manager.hpp>


using namespace godot;

static void physics_server2d_manager_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef physics_server2d_manager_class_def = {
	"_PhysicsServer2DManager",
	physics_server2d_manager_class_finalizer
};

static JSValue physics_server2d_manager_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["PhysicsServer2DManager"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	PhysicsServer2DManager *physics_server2d_manager_class = PhysicsServer2DManager::get_singleton();
	if (!physics_server2d_manager_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, physics_server2d_manager_class);
	return obj;
}

static JSValue physics_server2d_manager_class_register_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer2DManager::register_server, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server2d_manager_class_set_default_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer2DManager::set_default_server, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry physics_server2d_manager_class_proto_funcs[] = {
	JS_CFUNC_DEF("register_server", 2, &physics_server2d_manager_class_register_server),
	JS_CFUNC_DEF("set_default_server", 2, &physics_server2d_manager_class_set_default_server),
};




static int js_physics_server2d_manager_class_init(JSContext *ctx) {
	JSClassID class_id = classes["PhysicsServer2DManager"];
	classes["PhysicsServer2DManager"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_server2d_manager_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, physics_server2d_manager_class_proto_funcs, _countof(physics_server2d_manager_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, physics_server2d_manager_class_constructor, "_PhysicsServer2DManager", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_PhysicsServer2DManager", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_physics_server2d_manager() {
	js_physics_server2d_manager_class_init(js_context());
}