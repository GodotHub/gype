#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gradient.hpp>
using namespace godot;

static void gradient_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Gradient"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gradient_class_def = {
    "Gradient",
    gradient_class_finalizer
};

static JSValue gradient_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Gradient"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Gradient *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Gradient *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Gradient);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gradient_class_add_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::add_point, ctx, this_val, argc, argv);
};
static JSValue gradient_class_remove_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::remove_point, ctx, this_val, argc, argv);
};
static JSValue gradient_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::set_offset, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Gradient::get_offset, ctx, this_val, argc, argv);
};
static JSValue gradient_class_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::reverse, ctx, this_val, argc, argv);
};
static JSValue gradient_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::set_color, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Gradient::get_color, ctx, this_val, argc, argv);
};
static JSValue gradient_class_sample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Gradient::sample, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_point_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Gradient::get_point_count, ctx, this_val, argc, argv);
};
static JSValue gradient_class_set_offsets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::set_offsets, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_offsets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat32Array> *proxy = memnew(ObjectProxy<PackedFloat32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat32Array {
		Gradient *obj = static_cast<Gradient *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offsets();
	};
	proxy->setter = [this_val](const PackedFloat32Array &value) -> void {
		Gradient *js_proxy = static_cast<Gradient *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offsets(PackedFloat32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gradient_class_set_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::set_colors, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedColorArray> *proxy = memnew(ObjectProxy<PackedColorArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedColorArray {
		Gradient *obj = static_cast<Gradient *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_colors();
	};
	proxy->setter = [this_val](const PackedColorArray &value) -> void {
		Gradient *js_proxy = static_cast<Gradient *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_colors(PackedColorArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedColorArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedColorArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gradient_class_set_interpolation_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::set_interpolation_mode, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_interpolation_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Gradient::get_interpolation_mode, ctx, this_val, argc, argv);
}
static JSValue gradient_class_set_interpolation_color_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Gradient::set_interpolation_color_space, ctx, this_val, argc, argv);
};
static JSValue gradient_class_get_interpolation_color_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Gradient::get_interpolation_color_space, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry gradient_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_point", 2, &gradient_class_add_point),
	JS_CFUNC_DEF("remove_point", 1, &gradient_class_remove_point),
	JS_CFUNC_DEF("set_offset", 2, &gradient_class_set_offset),
	JS_CFUNC_DEF("get_offset", 1, &gradient_class_get_offset),
	JS_CFUNC_DEF("reverse", 0, &gradient_class_reverse),
	JS_CFUNC_DEF("set_color", 2, &gradient_class_set_color),
	JS_CFUNC_DEF("get_color", 1, &gradient_class_get_color),
	JS_CFUNC_DEF("sample", 1, &gradient_class_sample),
	JS_CFUNC_DEF("get_point_count", 0, &gradient_class_get_point_count),
	JS_CFUNC_DEF("set_offsets", 1, &gradient_class_set_offsets),
	JS_CFUNC_DEF("get_offsets", 0, &gradient_class_get_offsets),
	JS_CFUNC_DEF("set_colors", 1, &gradient_class_set_colors),
	JS_CFUNC_DEF("get_colors", 0, &gradient_class_get_colors),
	JS_CFUNC_DEF("set_interpolation_mode", 1, &gradient_class_set_interpolation_mode),
	JS_CFUNC_DEF("get_interpolation_mode", 0, &gradient_class_get_interpolation_mode),
	JS_CFUNC_DEF("set_interpolation_color_space", 1, &gradient_class_set_interpolation_color_space),
	JS_CFUNC_DEF("get_interpolation_color_space", 0, &gradient_class_get_interpolation_color_space),
};




static void define_gradient_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interpolation_mode"),
        JS_NewCFunction(ctx, gradient_class_get_interpolation_mode, "get_interpolation_mode", 0),
        JS_NewCFunction(ctx, gradient_class_set_interpolation_mode, "set_interpolation_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interpolation_color_space"),
        JS_NewCFunction(ctx, gradient_class_get_interpolation_color_space, "get_interpolation_color_space", 0),
        JS_NewCFunction(ctx, gradient_class_set_interpolation_color_space, "set_interpolation_color_space", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offsets"),
        JS_NewCFunction(ctx, gradient_class_get_offsets, "get_offsets", 0),
        JS_NewCFunction(ctx, gradient_class_set_offsets, "set_offsets", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "colors"),
        JS_NewCFunction(ctx, gradient_class_get_colors, "get_colors", 0),
        JS_NewCFunction(ctx, gradient_class_set_colors, "set_colors", 1),
        JS_PROP_GETSET
    );
}

static void define_gradient_enum(JSContext *ctx, JSValue ctor) {
	JSValue InterpolationMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, InterpolationMode_obj, "GRADIENT_INTERPOLATE_LINEAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InterpolationMode_obj, "GRADIENT_INTERPOLATE_CONSTANT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InterpolationMode_obj, "GRADIENT_INTERPOLATE_CUBIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "InterpolationMode", InterpolationMode_obj);
	JSValue ColorSpace_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ColorSpace_obj, "GRADIENT_COLOR_SPACE_SRGB", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ColorSpace_obj, "GRADIENT_COLOR_SPACE_LINEAR_SRGB", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ColorSpace_obj, "GRADIENT_COLOR_SPACE_OKLAB", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ColorSpace", ColorSpace_obj);
}

static int js_gradient_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Gradient"] = class_id;
	classes_by_id[class_id] = "Gradient";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gradient_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gradient_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gradient_class_proto_funcs, _countof(gradient_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gradient_class_constructor, "Gradient", 0, JS_CFUNC_constructor, 0);
	define_gradient_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Gradient", ctor);

	return 0;
}

JSModuleDef *_js_init_gradient_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gradient_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Gradient");
	return m;
}

JSModuleDef *js_init_gradient_module(JSContext *ctx) {
	return _js_init_gradient_module(ctx, "@godot/classes/gradient");
}

void __register_gradient() {
	js_init_gradient_module(js_context());
}

void register_gradient() {
	__register_gradient();
}