#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visible_on_screen_notifier3d.hpp>
using namespace godot;

static void visible_on_screen_notifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisibleOnScreenNotifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef visible_on_screen_notifier3d_class_def = {
    "VisibleOnScreenNotifier3D",
    visible_on_screen_notifier3d_class_finalizer
};

static JSValue visible_on_screen_notifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisibleOnScreenNotifier3D"];
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
        instance = memnew(VisibleOnScreenNotifier3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visible_on_screen_notifier3d_class_set_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisibleOnScreenNotifier3D::set_aabb, ctx, this_val, argc, argv);
};
static JSValue visible_on_screen_notifier3d_class_is_on_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisibleOnScreenNotifier3D::is_on_screen, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry visible_on_screen_notifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_aabb", 1, &visible_on_screen_notifier3d_class_set_aabb),
	JS_CFUNC_DEF("is_on_screen", 0, &visible_on_screen_notifier3d_class_is_on_screen),
};


static JSValue visible_on_screen_notifier3d_class_get_screen_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "screen_entered");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue visible_on_screen_notifier3d_class_get_screen_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "screen_exited");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_visible_on_screen_notifier3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "aabb"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, visible_on_screen_notifier3d_class_set_aabb, "set_aabb", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "screen_entered"),
		JS_NewCFunction(ctx, visible_on_screen_notifier3d_class_get_screen_entered_signal, "get_screen_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "screen_exited"),
		JS_NewCFunction(ctx, visible_on_screen_notifier3d_class_get_screen_exited_signal, "get_screen_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_visible_on_screen_notifier3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visible_on_screen_notifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisibleOnScreenNotifier3D"] = class_id;
	classes_by_id[class_id] = "VisibleOnScreenNotifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visible_on_screen_notifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visible_on_screen_notifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visible_on_screen_notifier3d_class_proto_funcs, _countof(visible_on_screen_notifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visible_on_screen_notifier3d_class_constructor, "VisibleOnScreenNotifier3D", 0, JS_CFUNC_constructor, 0);
	define_visible_on_screen_notifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisibleOnScreenNotifier3D", ctor);
	ctor_list["VisibleOnScreenNotifier3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_visible_on_screen_notifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visible_on_screen_notifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisibleOnScreenNotifier3D");
	return m;
}

JSModuleDef *js_init_visible_on_screen_notifier3d_module(JSContext *ctx) {
	return _js_init_visible_on_screen_notifier3d_module(ctx, "@godot/classes/visible_on_screen_notifier3d");
}

void __register_visible_on_screen_notifier3d() {
	js_init_visible_on_screen_notifier3d_module(js_context());
}

void register_visible_on_screen_notifier3d() {
	__register_visible_on_screen_notifier3d();
}