#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/curve3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/path3d.hpp>
using namespace godot;

static void path3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Path3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef path3d_class_def = {
    "Path3D",
    path3d_class_finalizer
};

static JSValue path3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Path3D"];
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
        instance = memnew(Path3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue path3d_class_set_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Path3D::set_curve, ctx, this_val, argc, argv);
};
static JSValue path3d_class_get_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Path3D::get_curve, ctx, this_val, argc, argv);
}
static JSValue path3d_class_set_debug_custom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Path3D::set_debug_custom_color, ctx, this_val, argc, argv);
};
static JSValue path3d_class_get_debug_custom_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Path3D *obj = static_cast<Path3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_debug_custom_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Path3D *js_proxy = static_cast<Path3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_debug_custom_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry path3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_curve", 1, &path3d_class_set_curve),
	JS_CFUNC_DEF("get_curve", 0, &path3d_class_get_curve),
	JS_CFUNC_DEF("set_debug_custom_color", 1, &path3d_class_set_debug_custom_color),
	JS_CFUNC_DEF("get_debug_custom_color", 0, &path3d_class_get_debug_custom_color),
};


static JSValue path3d_class_get_curve_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "curve_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue path3d_class_get_debug_color_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "debug_color_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_path3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "curve"),
        JS_NewCFunction(ctx, path3d_class_get_curve, "get_curve", 0),
        JS_NewCFunction(ctx, path3d_class_set_curve, "set_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_custom_color"),
        JS_NewCFunction(ctx, path3d_class_get_debug_custom_color, "get_debug_custom_color", 0),
        JS_NewCFunction(ctx, path3d_class_set_debug_custom_color, "set_debug_custom_color", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "curve_changed"),
		JS_NewCFunction(ctx, path3d_class_get_curve_changed_signal, "get_curve_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "debug_color_changed"),
		JS_NewCFunction(ctx, path3d_class_get_debug_color_changed_signal, "get_debug_color_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_path3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_path3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Path3D"] = class_id;
	classes_by_id[class_id] = "Path3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &path3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_path3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, path3d_class_proto_funcs, _countof(path3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, path3d_class_constructor, "Path3D", 0, JS_CFUNC_constructor, 0);
	define_path3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Path3D", ctor);
	ctor_list["Path3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_path3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_path3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Path3D");
	return m;
}

JSModuleDef *js_init_path3d_module(JSContext *ctx) {
	return _js_init_path3d_module(ctx, "@godot/classes/path3d");
}

void __register_path3d() {
	js_init_path3d_module(js_context());
}

void register_path3d() {
	__register_path3d();
}