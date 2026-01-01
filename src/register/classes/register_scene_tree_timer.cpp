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
#include <godot_cpp/classes/scene_tree_timer.hpp>
using namespace godot;

static void scene_tree_timer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SceneTreeTimer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef scene_tree_timer_class_def = {
    "SceneTreeTimer",
    scene_tree_timer_class_finalizer
};

static JSValue scene_tree_timer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SceneTreeTimer"];
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
        instance = memnew(SceneTreeTimer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue scene_tree_timer_class_set_time_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTreeTimer::set_time_left, ctx, this_val, argc, argv);
};
static JSValue scene_tree_timer_class_get_time_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTreeTimer::get_time_left, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry scene_tree_timer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_time_left", 1, &scene_tree_timer_class_set_time_left),
	JS_CFUNC_DEF("get_time_left", 0, &scene_tree_timer_class_get_time_left),
};


static JSValue scene_tree_timer_class_get_timeout_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "timeout");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_scene_tree_timer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "time_left"),
        JS_NewCFunction(ctx, scene_tree_timer_class_get_time_left, "get_time_left", 0),
        JS_NewCFunction(ctx, scene_tree_timer_class_set_time_left, "set_time_left", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "timeout"),
		JS_NewCFunction(ctx, scene_tree_timer_class_get_timeout_signal, "get_timeout_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_scene_tree_timer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_scene_tree_timer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SceneTreeTimer"] = class_id;
	classes_by_id[class_id] = "SceneTreeTimer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &scene_tree_timer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_scene_tree_timer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, scene_tree_timer_class_proto_funcs, _countof(scene_tree_timer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, scene_tree_timer_class_constructor, "SceneTreeTimer", 0, JS_CFUNC_constructor, 0);
	define_scene_tree_timer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SceneTreeTimer", ctor);
	ctor_list["SceneTreeTimer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_scene_tree_timer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_scene_tree_timer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SceneTreeTimer");
	return m;
}

JSModuleDef *js_init_scene_tree_timer_module(JSContext *ctx) {
	return _js_init_scene_tree_timer_module(ctx, "@godot/classes/scene_tree_timer");
}

void __register_scene_tree_timer() {
	js_init_scene_tree_timer_module(js_context());
}

void register_scene_tree_timer() {
	__register_scene_tree_timer();
}