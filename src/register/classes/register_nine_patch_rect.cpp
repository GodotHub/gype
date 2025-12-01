#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/nine_patch_rect.hpp>
using namespace godot;

static void nine_patch_rect_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NinePatchRect"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef nine_patch_rect_class_def = {
    "NinePatchRect",
    nine_patch_rect_class_finalizer
};

static JSValue nine_patch_rect_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NinePatchRect"];
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
        instance = memnew(NinePatchRect);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue nine_patch_rect_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NinePatchRect::set_texture, ctx, this_val, argc, argv);
};
static JSValue nine_patch_rect_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NinePatchRect::get_texture, ctx, this_val, argc, argv);
}
static JSValue nine_patch_rect_class_set_patch_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NinePatchRect::set_patch_margin, ctx, this_val, argc, argv);
};
static JSValue nine_patch_rect_class_get_patch_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NinePatchRect::get_patch_margin, ctx, this_val, argc, argv);
}
static JSValue nine_patch_rect_class_set_region_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NinePatchRect::set_region_rect, ctx, this_val, argc, argv);
};
static JSValue nine_patch_rect_class_get_region_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		NinePatchRect *obj = static_cast<NinePatchRect *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_region_rect();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		NinePatchRect *js_proxy = static_cast<NinePatchRect *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_region_rect(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue nine_patch_rect_class_set_draw_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NinePatchRect::set_draw_center, ctx, this_val, argc, argv);
};
static JSValue nine_patch_rect_class_is_draw_center_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NinePatchRect::is_draw_center_enabled, ctx, this_val, argc, argv);
}
static JSValue nine_patch_rect_class_set_h_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NinePatchRect::set_h_axis_stretch_mode, ctx, this_val, argc, argv);
};
static JSValue nine_patch_rect_class_get_h_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NinePatchRect::get_h_axis_stretch_mode, ctx, this_val, argc, argv);
}
static JSValue nine_patch_rect_class_set_v_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NinePatchRect::set_v_axis_stretch_mode, ctx, this_val, argc, argv);
};
static JSValue nine_patch_rect_class_get_v_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NinePatchRect::get_v_axis_stretch_mode, ctx, this_val, argc, argv);
}

static JSValue nine_patch_rect_class_get_patch_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&NinePatchRect::get_patch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue nine_patch_rect_class_set_patch_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&NinePatchRect::set_patch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue nine_patch_rect_class_get_patch_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&NinePatchRect::get_patch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue nine_patch_rect_class_set_patch_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&NinePatchRect::set_patch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue nine_patch_rect_class_get_patch_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&NinePatchRect::get_patch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue nine_patch_rect_class_set_patch_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&NinePatchRect::set_patch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue nine_patch_rect_class_get_patch_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&NinePatchRect::get_patch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue nine_patch_rect_class_set_patch_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&NinePatchRect::set_patch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry nine_patch_rect_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture", 1, &nine_patch_rect_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &nine_patch_rect_class_get_texture),
	JS_CFUNC_DEF("set_patch_margin", 2, &nine_patch_rect_class_set_patch_margin),
	JS_CFUNC_DEF("get_patch_margin", 1, &nine_patch_rect_class_get_patch_margin),
	JS_CFUNC_DEF("set_region_rect", 1, &nine_patch_rect_class_set_region_rect),
	JS_CFUNC_DEF("get_region_rect", 0, &nine_patch_rect_class_get_region_rect),
	JS_CFUNC_DEF("set_draw_center", 1, &nine_patch_rect_class_set_draw_center),
	JS_CFUNC_DEF("is_draw_center_enabled", 0, &nine_patch_rect_class_is_draw_center_enabled),
	JS_CFUNC_DEF("set_h_axis_stretch_mode", 1, &nine_patch_rect_class_set_h_axis_stretch_mode),
	JS_CFUNC_DEF("get_h_axis_stretch_mode", 0, &nine_patch_rect_class_get_h_axis_stretch_mode),
	JS_CFUNC_DEF("set_v_axis_stretch_mode", 1, &nine_patch_rect_class_set_v_axis_stretch_mode),
	JS_CFUNC_DEF("get_v_axis_stretch_mode", 0, &nine_patch_rect_class_get_v_axis_stretch_mode),
    JS_CFUNC_MAGIC_DEF("get_patch_margin_top", 0, &nine_patch_rect_class_get_patch_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("set_patch_margin_top", 1, &nine_patch_rect_class_set_patch_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("get_patch_margin_right", 0, &nine_patch_rect_class_get_patch_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("set_patch_margin_right", 1, &nine_patch_rect_class_set_patch_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("get_patch_margin_bottom", 0, &nine_patch_rect_class_get_patch_margin_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_patch_margin_bottom", 1, &nine_patch_rect_class_set_patch_margin_bottom, 3),
};


static JSValue nine_patch_rect_class_get_texture_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "texture_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_nine_patch_rect_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, nine_patch_rect_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, nine_patch_rect_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_center"),
        JS_NewCFunction(ctx, nine_patch_rect_class_is_draw_center_enabled, "is_draw_center_enabled", 0),
        JS_NewCFunction(ctx, nine_patch_rect_class_set_draw_center, "set_draw_center", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region_rect"),
        JS_NewCFunction(ctx, nine_patch_rect_class_get_region_rect, "get_region_rect", 0),
        JS_NewCFunction(ctx, nine_patch_rect_class_set_region_rect, "set_region_rect", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "patch_margin_left"),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_get_patch_margin_left, "get_patch_margin_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_set_patch_margin_left, "set_patch_margin_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "patch_margin_top"),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_get_patch_margin_top, "get_patch_margin_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_set_patch_margin_top, "set_patch_margin_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "patch_margin_right"),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_get_patch_margin_right, "get_patch_margin_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_set_patch_margin_right, "set_patch_margin_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "patch_margin_bottom"),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_get_patch_margin_bottom, "get_patch_margin_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, nine_patch_rect_class_set_patch_margin_bottom, "set_patch_margin_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_stretch_horizontal"),
        JS_NewCFunction(ctx, nine_patch_rect_class_get_h_axis_stretch_mode, "get_h_axis_stretch_mode", 0),
        JS_NewCFunction(ctx, nine_patch_rect_class_set_h_axis_stretch_mode, "set_h_axis_stretch_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_stretch_vertical"),
        JS_NewCFunction(ctx, nine_patch_rect_class_get_v_axis_stretch_mode, "get_v_axis_stretch_mode", 0),
        JS_NewCFunction(ctx, nine_patch_rect_class_set_v_axis_stretch_mode, "set_v_axis_stretch_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "texture_changed"),
		JS_NewCFunction(ctx, nine_patch_rect_class_get_texture_changed_signal, "get_texture_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_nine_patch_rect_enum(JSContext *ctx, JSValue ctor) {
	JSValue AxisStretchMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AxisStretchMode_obj, "AXIS_STRETCH_MODE_STRETCH", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AxisStretchMode_obj, "AXIS_STRETCH_MODE_TILE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AxisStretchMode_obj, "AXIS_STRETCH_MODE_TILE_FIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AxisStretchMode", AxisStretchMode_obj);
}

static int js_nine_patch_rect_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NinePatchRect"] = class_id;
	classes_by_id[class_id] = "NinePatchRect";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &nine_patch_rect_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_nine_patch_rect_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, nine_patch_rect_class_proto_funcs, _countof(nine_patch_rect_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, nine_patch_rect_class_constructor, "NinePatchRect", 0, JS_CFUNC_constructor, 0);
	define_nine_patch_rect_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NinePatchRect", ctor);
	ctor_list["NinePatchRect"] = ctor;

	return 0;
}

JSModuleDef *_js_init_nine_patch_rect_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_nine_patch_rect_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NinePatchRect");
	return m;
}

JSModuleDef *js_init_nine_patch_rect_module(JSContext *ctx) {
	return _js_init_nine_patch_rect_module(ctx, "@godot/classes/nine_patch_rect");
}

void __register_nine_patch_rect() {
	js_init_nine_patch_rect_module(js_context());
}

void register_nine_patch_rect() {
	__register_nine_patch_rect();
}