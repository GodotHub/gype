#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_library.hpp>
using namespace godot;

static void animation_library_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationLibrary"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_library_class_def = {
    "AnimationLibrary",
    animation_library_class_finalizer
};

static JSValue animation_library_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationLibrary"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationLibrary *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationLibrary *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationLibrary);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_library_class_add_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AnimationLibrary::add_animation, ctx, this_val, argc, argv);
};
static JSValue animation_library_class_remove_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationLibrary::remove_animation, ctx, this_val, argc, argv);
};
static JSValue animation_library_class_rename_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationLibrary::rename_animation, ctx, this_val, argc, argv);
};
static JSValue animation_library_class_has_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationLibrary::has_animation, ctx, this_val, argc, argv);
};
static JSValue animation_library_class_get_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationLibrary::get_animation, ctx, this_val, argc, argv);
};
static JSValue animation_library_class_get_animation_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationLibrary::get_animation_list, ctx, this_val, argc, argv);
};
static JSValue animation_library_class_get_animation_list_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationLibrary::get_animation_list_size, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry animation_library_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_animation", 2, &animation_library_class_add_animation),
	JS_CFUNC_DEF("remove_animation", 1, &animation_library_class_remove_animation),
	JS_CFUNC_DEF("rename_animation", 2, &animation_library_class_rename_animation),
	JS_CFUNC_DEF("has_animation", 1, &animation_library_class_has_animation),
	JS_CFUNC_DEF("get_animation", 1, &animation_library_class_get_animation),
	JS_CFUNC_DEF("get_animation_list", 0, &animation_library_class_get_animation_list),
	JS_CFUNC_DEF("get_animation_list_size", 0, &animation_library_class_get_animation_list_size),
};


static JSValue animation_library_class_get_animation_added_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationLibrary *opaque = static_cast<AnimationLibrary *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_added_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_added"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_added_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animation_library_class_get_animation_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationLibrary *opaque = static_cast<AnimationLibrary *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_removed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_removed"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_removed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animation_library_class_get_animation_renamed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationLibrary *opaque = static_cast<AnimationLibrary *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_renamed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_renamed"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_renamed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animation_library_class_get_animation_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationLibrary *opaque = static_cast<AnimationLibrary *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_animation_library_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_added"),
		JS_NewCFunction(ctx, animation_library_class_get_animation_added_signal, "get_animation_added_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_removed"),
		JS_NewCFunction(ctx, animation_library_class_get_animation_removed_signal, "get_animation_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_renamed"),
		JS_NewCFunction(ctx, animation_library_class_get_animation_renamed_signal, "get_animation_renamed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_changed"),
		JS_NewCFunction(ctx, animation_library_class_get_animation_changed_signal, "get_animation_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_animation_library_enum(JSContext *ctx, JSValue proto) {
}

static int js_animation_library_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationLibrary"] = class_id;
	classes_by_id[class_id] = "AnimationLibrary";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_library_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_library_property(ctx, proto);
	define_animation_library_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_library_class_proto_funcs, _countof(animation_library_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_library_class_constructor, "AnimationLibrary", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationLibrary", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_library_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_library_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationLibrary");
	return m;
}

JSModuleDef *js_init_animation_library_module(JSContext *ctx) {
	return _js_init_animation_library_module(ctx, "@godot/classes/animation_library");
}

void __register_animation_library() {
	js_init_animation_library_module(js_context());
}

void register_animation_library() {
	__register_animation_library();
}