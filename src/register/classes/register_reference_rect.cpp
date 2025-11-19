#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/reference_rect.hpp>
using namespace godot;

static void reference_rect_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ReferenceRect"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef reference_rect_class_def = {
    "ReferenceRect",
    reference_rect_class_finalizer
};

static JSValue reference_rect_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ReferenceRect"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ReferenceRect *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ReferenceRect *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ReferenceRect);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue reference_rect_class_get_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ReferenceRect *obj = static_cast<ReferenceRect *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_border_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ReferenceRect *js_proxy = static_cast<ReferenceRect *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_border_color(value);
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
static JSValue reference_rect_class_set_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ReferenceRect::set_border_color, ctx, this_val, argc, argv);
};
static JSValue reference_rect_class_get_border_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ReferenceRect::get_border_width, ctx, this_val, argc, argv);
}
static JSValue reference_rect_class_set_border_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ReferenceRect::set_border_width, ctx, this_val, argc, argv);
};
static JSValue reference_rect_class_get_editor_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ReferenceRect::get_editor_only, ctx, this_val, argc, argv);
}
static JSValue reference_rect_class_set_editor_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ReferenceRect::set_editor_only, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry reference_rect_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_border_color", 0, &reference_rect_class_get_border_color),
	JS_CFUNC_DEF("set_border_color", 1, &reference_rect_class_set_border_color),
	JS_CFUNC_DEF("get_border_width", 0, &reference_rect_class_get_border_width),
	JS_CFUNC_DEF("set_border_width", 1, &reference_rect_class_set_border_width),
	JS_CFUNC_DEF("get_editor_only", 0, &reference_rect_class_get_editor_only),
	JS_CFUNC_DEF("set_editor_only", 1, &reference_rect_class_set_editor_only),
};




static void define_reference_rect_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_color"),
        JS_NewCFunction(ctx, reference_rect_class_get_border_color, "get_border_color", 0),
        JS_NewCFunction(ctx, reference_rect_class_set_border_color, "set_border_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_width"),
        JS_NewCFunction(ctx, reference_rect_class_get_border_width, "get_border_width", 0),
        JS_NewCFunction(ctx, reference_rect_class_set_border_width, "set_border_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editor_only"),
        JS_NewCFunction(ctx, reference_rect_class_get_editor_only, "get_editor_only", 0),
        JS_NewCFunction(ctx, reference_rect_class_set_editor_only, "set_editor_only", 1),
        JS_PROP_GETSET
    );
}

static void define_reference_rect_enum(JSContext *ctx, JSValue ctor) {
}

static int js_reference_rect_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ReferenceRect"] = class_id;
	classes_by_id[class_id] = "ReferenceRect";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &reference_rect_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_reference_rect_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, reference_rect_class_proto_funcs, _countof(reference_rect_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, reference_rect_class_constructor, "ReferenceRect", 0, JS_CFUNC_constructor, 0);
	define_reference_rect_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ReferenceRect", ctor);

	return 0;
}

JSModuleDef *_js_init_reference_rect_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_reference_rect_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ReferenceRect");
	return m;
}

JSModuleDef *js_init_reference_rect_module(JSContext *ctx) {
	return _js_init_reference_rect_module(ctx, "@godot/classes/reference_rect");
}

void __register_reference_rect() {
	js_init_reference_rect_module(js_context());
}

void register_reference_rect() {
	__register_reference_rect();
}