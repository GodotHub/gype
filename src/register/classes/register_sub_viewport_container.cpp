#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/sub_viewport_container.hpp>
using namespace godot;

static void sub_viewport_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SubViewportContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef sub_viewport_container_class_def = {
    "SubViewportContainer",
    sub_viewport_container_class_finalizer
};

static JSValue sub_viewport_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SubViewportContainer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SubViewportContainer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SubViewportContainer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SubViewportContainer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue sub_viewport_container_class_set_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewportContainer::set_stretch, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_container_class_is_stretch_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SubViewportContainer::is_stretch_enabled, ctx, this_val, argc, argv);
}
static JSValue sub_viewport_container_class_set_stretch_shrink(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewportContainer::set_stretch_shrink, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_container_class_get_stretch_shrink(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SubViewportContainer::get_stretch_shrink, ctx, this_val, argc, argv);
}
static JSValue sub_viewport_container_class_set_mouse_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewportContainer::set_mouse_target, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_container_class_is_mouse_target_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SubViewportContainer::is_mouse_target_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry sub_viewport_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stretch", 1, &sub_viewport_container_class_set_stretch),
	JS_CFUNC_DEF("is_stretch_enabled", 0, &sub_viewport_container_class_is_stretch_enabled),
	JS_CFUNC_DEF("set_stretch_shrink", 1, &sub_viewport_container_class_set_stretch_shrink),
	JS_CFUNC_DEF("get_stretch_shrink", 0, &sub_viewport_container_class_get_stretch_shrink),
	JS_CFUNC_DEF("set_mouse_target", 1, &sub_viewport_container_class_set_mouse_target),
	JS_CFUNC_DEF("is_mouse_target_enabled", 0, &sub_viewport_container_class_is_mouse_target_enabled),
};




static void define_sub_viewport_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stretch"),
        JS_NewCFunction(ctx, sub_viewport_container_class_is_stretch_enabled, "is_stretch_enabled", 0),
        JS_NewCFunction(ctx, sub_viewport_container_class_set_stretch, "set_stretch", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stretch_shrink"),
        JS_NewCFunction(ctx, sub_viewport_container_class_get_stretch_shrink, "get_stretch_shrink", 0),
        JS_NewCFunction(ctx, sub_viewport_container_class_set_stretch_shrink, "set_stretch_shrink", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_target"),
        JS_NewCFunction(ctx, sub_viewport_container_class_is_mouse_target_enabled, "is_mouse_target_enabled", 0),
        JS_NewCFunction(ctx, sub_viewport_container_class_set_mouse_target, "set_mouse_target", 1),
        JS_PROP_GETSET
    );
}

static void define_sub_viewport_container_enum(JSContext *ctx, JSValue ctor) {
}

static int js_sub_viewport_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SubViewportContainer"] = class_id;
	classes_by_id[class_id] = "SubViewportContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &sub_viewport_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_sub_viewport_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, sub_viewport_container_class_proto_funcs, _countof(sub_viewport_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, sub_viewport_container_class_constructor, "SubViewportContainer", 0, JS_CFUNC_constructor, 0);
	define_sub_viewport_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SubViewportContainer", ctor);

	return 0;
}

JSModuleDef *_js_init_sub_viewport_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_sub_viewport_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SubViewportContainer");
	return m;
}

JSModuleDef *js_init_sub_viewport_container_module(JSContext *ctx) {
	return _js_init_sub_viewport_container_module(ctx, "@godot/classes/sub_viewport_container");
}

void __register_sub_viewport_container() {
	js_init_sub_viewport_container_module(js_context());
}

void register_sub_viewport_container() {
	__register_sub_viewport_container();
}