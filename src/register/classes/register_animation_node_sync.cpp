#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_sync.hpp>
using namespace godot;

static void animation_node_sync_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeSync"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_sync_class_def = {
    "AnimationNodeSync",
    animation_node_sync_class_finalizer
};

static JSValue animation_node_sync_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeSync"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeSync *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeSync *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeSync);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_sync_class_set_use_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeSync::set_use_sync, ctx, this_val, argc, argv);
};
static JSValue animation_node_sync_class_is_using_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeSync::is_using_sync, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry animation_node_sync_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_use_sync", 1, &animation_node_sync_class_set_use_sync),
	JS_CFUNC_DEF("is_using_sync", 0, &animation_node_sync_class_is_using_sync),
};




static void define_animation_node_sync_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sync"),
        JS_NewCFunction(ctx, animation_node_sync_class_is_using_sync, "is_using_sync", 0),
        JS_NewCFunction(ctx, animation_node_sync_class_set_use_sync, "set_use_sync", 1),
        JS_PROP_GETSET
    );
}

static void define_animation_node_sync_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animation_node_sync_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeSync"] = class_id;
	classes_by_id[class_id] = "AnimationNodeSync";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_sync_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_sync_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_sync_class_proto_funcs, _countof(animation_node_sync_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_sync_class_constructor, "AnimationNodeSync", 0, JS_CFUNC_constructor, 0);
	define_animation_node_sync_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeSync", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_sync_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_sync_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeSync");
	return m;
}

JSModuleDef *js_init_animation_node_sync_module(JSContext *ctx) {
	return _js_init_animation_node_sync_module(ctx, "@godot/classes/animation_node_sync");
}

void __register_animation_node_sync() {
	js_init_animation_node_sync_module(js_context());
}

void register_animation_node_sync() {
	__register_animation_node_sync();
}