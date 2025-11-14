#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
using namespace godot;

static void sub_viewport_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SubViewport"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef sub_viewport_class_def = {
    "SubViewport",
    sub_viewport_class_finalizer
};

static JSValue sub_viewport_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SubViewport"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SubViewport *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SubViewport *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SubViewport);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue sub_viewport_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewport::set_size, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		SubViewport *obj = static_cast<SubViewport *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		SubViewport *js_proxy = static_cast<SubViewport *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue sub_viewport_class_set_size_2d_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewport::set_size_2d_override, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_class_get_size_2d_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		SubViewport *obj = static_cast<SubViewport *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size_2d_override();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		SubViewport *js_proxy = static_cast<SubViewport *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size_2d_override(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue sub_viewport_class_set_size_2d_override_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewport::set_size_2d_override_stretch, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_class_is_size_2d_override_stretch_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SubViewport::is_size_2d_override_stretch_enabled, ctx, this_val, argc, argv);
}
static JSValue sub_viewport_class_set_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewport::set_update_mode, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_class_get_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SubViewport::get_update_mode, ctx, this_val, argc, argv);
}
static JSValue sub_viewport_class_set_clear_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SubViewport::set_clear_mode, ctx, this_val, argc, argv);
};
static JSValue sub_viewport_class_get_clear_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SubViewport::get_clear_mode, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry sub_viewport_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &sub_viewport_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &sub_viewport_class_get_size),
	JS_CFUNC_DEF("set_size_2d_override", 1, &sub_viewport_class_set_size_2d_override),
	JS_CFUNC_DEF("get_size_2d_override", 0, &sub_viewport_class_get_size_2d_override),
	JS_CFUNC_DEF("set_size_2d_override_stretch", 1, &sub_viewport_class_set_size_2d_override_stretch),
	JS_CFUNC_DEF("is_size_2d_override_stretch_enabled", 0, &sub_viewport_class_is_size_2d_override_stretch_enabled),
	JS_CFUNC_DEF("set_update_mode", 1, &sub_viewport_class_set_update_mode),
	JS_CFUNC_DEF("get_update_mode", 0, &sub_viewport_class_get_update_mode),
	JS_CFUNC_DEF("set_clear_mode", 1, &sub_viewport_class_set_clear_mode),
	JS_CFUNC_DEF("get_clear_mode", 0, &sub_viewport_class_get_clear_mode),
};




static void define_sub_viewport_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, sub_viewport_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, sub_viewport_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size_2d_override"),
        JS_NewCFunction(ctx, sub_viewport_class_get_size_2d_override, "get_size_2d_override", 0),
        JS_NewCFunction(ctx, sub_viewport_class_set_size_2d_override, "set_size_2d_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size_2d_override_stretch"),
        JS_NewCFunction(ctx, sub_viewport_class_is_size_2d_override_stretch_enabled, "is_size_2d_override_stretch_enabled", 0),
        JS_NewCFunction(ctx, sub_viewport_class_set_size_2d_override_stretch, "set_size_2d_override_stretch", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_target_clear_mode"),
        JS_NewCFunction(ctx, sub_viewport_class_get_clear_mode, "get_clear_mode", 0),
        JS_NewCFunction(ctx, sub_viewport_class_set_clear_mode, "set_clear_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_target_update_mode"),
        JS_NewCFunction(ctx, sub_viewport_class_get_update_mode, "get_update_mode", 0),
        JS_NewCFunction(ctx, sub_viewport_class_set_update_mode, "set_update_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_sub_viewport_enum(JSContext *ctx, JSValue proto) {
	JSValue ClearMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ClearMode_obj, "CLEAR_MODE_ALWAYS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ClearMode_obj, "CLEAR_MODE_NEVER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ClearMode_obj, "CLEAR_MODE_ONCE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "ClearMode", ClearMode_obj);
	JSValue UpdateMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_ONCE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_WHEN_VISIBLE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_WHEN_PARENT_VISIBLE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_ALWAYS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "UpdateMode", UpdateMode_obj);
}

static int js_sub_viewport_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SubViewport"] = class_id;
	classes_by_id[class_id] = "SubViewport";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &sub_viewport_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Viewport"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_sub_viewport_property(ctx, proto);
	define_sub_viewport_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, sub_viewport_class_proto_funcs, _countof(sub_viewport_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, sub_viewport_class_constructor, "SubViewport", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SubViewport", ctor);

	return 0;
}

JSModuleDef *_js_init_sub_viewport_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/viewport';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_sub_viewport_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SubViewport");
	return m;
}

JSModuleDef *js_init_sub_viewport_module(JSContext *ctx) {
	return _js_init_sub_viewport_module(ctx, "@godot/classes/sub_viewport");
}

void __register_sub_viewport() {
	js_init_sub_viewport_module(js_context());
}

void register_sub_viewport() {
	__register_sub_viewport();
}