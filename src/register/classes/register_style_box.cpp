#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/canvas_item.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/style_box.hpp>
using namespace godot;

static void style_box_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StyleBox"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef style_box_class_def = {
    "StyleBox",
    style_box_class_finalizer
};

static JSValue style_box_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StyleBox"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    StyleBox *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<StyleBox *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(StyleBox);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue style_box_class_get_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBox::get_minimum_size, ctx, this_val, argc, argv);
};
static JSValue style_box_class_set_content_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBox::set_content_margin, ctx, this_val, argc, argv);
};
static JSValue style_box_class_set_content_margin_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBox::set_content_margin_all, ctx, this_val, argc, argv);
};
static JSValue style_box_class_get_content_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBox::get_content_margin, ctx, this_val, argc, argv);
}
static JSValue style_box_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBox::get_margin, ctx, this_val, argc, argv);
};
static JSValue style_box_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBox::get_offset, ctx, this_val, argc, argv);
};
static JSValue style_box_class_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&StyleBox::draw, ctx, this_val, argc, argv);
};
static JSValue style_box_class_get_current_item_drawn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBox::get_current_item_drawn, ctx, this_val, argc, argv);
};
static JSValue style_box_class_test_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBox::test_mask, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry style_box_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_minimum_size", 0, &style_box_class_get_minimum_size),
	JS_CFUNC_DEF("set_content_margin", 2, &style_box_class_set_content_margin),
	JS_CFUNC_DEF("set_content_margin_all", 1, &style_box_class_set_content_margin_all),
	JS_CFUNC_DEF("get_content_margin", 1, &style_box_class_get_content_margin),
	JS_CFUNC_DEF("get_margin", 1, &style_box_class_get_margin),
	JS_CFUNC_DEF("get_offset", 0, &style_box_class_get_offset),
	JS_CFUNC_DEF("draw", 2, &style_box_class_draw),
	JS_CFUNC_DEF("get_current_item_drawn", 0, &style_box_class_get_current_item_drawn),
	JS_CFUNC_DEF("test_mask", 2, &style_box_class_test_mask),
};




static void define_style_box_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_margin_left"),
        JS_NewCFunction(ctx, style_box_class_get_content_margin, "get_content_margin", 0),
        JS_NewCFunction(ctx, style_box_class_set_content_margin, "set_content_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_margin_top"),
        JS_NewCFunction(ctx, style_box_class_get_content_margin, "get_content_margin", 0),
        JS_NewCFunction(ctx, style_box_class_set_content_margin, "set_content_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_margin_right"),
        JS_NewCFunction(ctx, style_box_class_get_content_margin, "get_content_margin", 0),
        JS_NewCFunction(ctx, style_box_class_set_content_margin, "set_content_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_margin_bottom"),
        JS_NewCFunction(ctx, style_box_class_get_content_margin, "get_content_margin", 0),
        JS_NewCFunction(ctx, style_box_class_set_content_margin, "set_content_margin", 1),
        JS_PROP_GETSET
    );
}

static void define_style_box_enum(JSContext *ctx, JSValue proto) {
}

static int js_style_box_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StyleBox"] = class_id;
	classes_by_id[class_id] = "StyleBox";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &style_box_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_style_box_property(ctx, proto);
	define_style_box_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, style_box_class_proto_funcs, _countof(style_box_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, style_box_class_constructor, "StyleBox", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StyleBox", ctor);

	return 0;
}

JSModuleDef *_js_init_style_box_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_style_box_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StyleBox");
	return m;
}

JSModuleDef *js_init_style_box_module(JSContext *ctx) {
	return _js_init_style_box_module(ctx, "@godot/classes/style_box");
}

void __register_style_box() {
	js_init_style_box_module(js_context());
}

void register_style_box() {
	__register_style_box();
}