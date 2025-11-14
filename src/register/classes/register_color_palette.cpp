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
#include <godot_cpp/classes/color_palette.hpp>
using namespace godot;

static void color_palette_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ColorPalette"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef color_palette_class_def = {
    "ColorPalette",
    color_palette_class_finalizer
};

static JSValue color_palette_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ColorPalette"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ColorPalette *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ColorPalette *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ColorPalette);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue color_palette_class_set_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPalette::set_colors, ctx, this_val, argc, argv);
};
static JSValue color_palette_class_get_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedColorArray> *proxy = memnew(ObjectProxy<PackedColorArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedColorArray {
		ColorPalette *obj = static_cast<ColorPalette *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_colors();
	};
	proxy->setter = [this_val](const PackedColorArray &value) -> void {
		ColorPalette *js_proxy = static_cast<ColorPalette *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_colors(PackedColorArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedColorArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedColorArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry color_palette_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_colors", 1, &color_palette_class_set_colors),
	JS_CFUNC_DEF("get_colors", 0, &color_palette_class_get_colors),
};




static void define_color_palette_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "colors"),
        JS_NewCFunction(ctx, color_palette_class_get_colors, "get_colors", 0),
        JS_NewCFunction(ctx, color_palette_class_set_colors, "set_colors", 1),
        JS_PROP_GETSET
    );
}

static void define_color_palette_enum(JSContext *ctx, JSValue proto) {
}

static int js_color_palette_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ColorPalette"] = class_id;
	classes_by_id[class_id] = "ColorPalette";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &color_palette_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_color_palette_property(ctx, proto);
	define_color_palette_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, color_palette_class_proto_funcs, _countof(color_palette_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, color_palette_class_constructor, "ColorPalette", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ColorPalette", ctor);

	return 0;
}

JSModuleDef *_js_init_color_palette_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_color_palette_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ColorPalette");
	return m;
}

JSModuleDef *js_init_color_palette_module(JSContext *ctx) {
	return _js_init_color_palette_module(ctx, "@godot/classes/color_palette");
}

void __register_color_palette() {
	js_init_color_palette_module(js_context());
}

void register_color_palette() {
	__register_color_palette();
}