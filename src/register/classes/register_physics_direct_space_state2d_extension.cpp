#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/physics_direct_space_state2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_direct_space_state2d_extension.hpp>
using namespace godot;

static void physics_direct_space_state2d_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsDirectSpaceState2DExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_direct_space_state2d_extension_class_def = {
    "PhysicsDirectSpaceState2DExtension",
    physics_direct_space_state2d_extension_class_finalizer
};

static JSValue physics_direct_space_state2d_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsDirectSpaceState2DExtension"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicsDirectSpaceState2DExtension *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicsDirectSpaceState2DExtension *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicsDirectSpaceState2DExtension);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_direct_space_state2d_extension_class_is_body_excluded_from_query(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectSpaceState2DExtension::is_body_excluded_from_query, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry physics_direct_space_state2d_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_body_excluded_from_query", 1, &physics_direct_space_state2d_extension_class_is_body_excluded_from_query),
};




static void define_physics_direct_space_state2d_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_physics_direct_space_state2d_extension_enum(JSContext *ctx, JSValue proto) {
}

static int js_physics_direct_space_state2d_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsDirectSpaceState2DExtension"] = class_id;
	classes_by_id[class_id] = "PhysicsDirectSpaceState2DExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_direct_space_state2d_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PhysicsDirectSpaceState2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_direct_space_state2d_extension_property(ctx, proto);
	define_physics_direct_space_state2d_extension_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_direct_space_state2d_extension_class_proto_funcs, _countof(physics_direct_space_state2d_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_direct_space_state2d_extension_class_constructor, "PhysicsDirectSpaceState2DExtension", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsDirectSpaceState2DExtension", ctor);

	return 0;
}

JSModuleDef *_js_init_physics_direct_space_state2d_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/physics_direct_space_state2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_direct_space_state2d_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsDirectSpaceState2DExtension");
	return m;
}

JSModuleDef *js_init_physics_direct_space_state2d_extension_module(JSContext *ctx) {
	return _js_init_physics_direct_space_state2d_extension_module(ctx, "@godot/classes/physics_direct_space_state2d_extension");
}

void __register_physics_direct_space_state2d_extension() {
	js_init_physics_direct_space_state2d_extension_module(js_context());
}

void register_physics_direct_space_state2d_extension() {
	__register_physics_direct_space_state2d_extension();
}