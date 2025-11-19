#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/graph_element.hpp>
#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/graph_frame.hpp>
using namespace godot;

static void graph_frame_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GraphFrame"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef graph_frame_class_def = {
    "GraphFrame",
    graph_frame_class_finalizer
};

static JSValue graph_frame_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GraphFrame"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GraphFrame *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GraphFrame *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GraphFrame);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue graph_frame_class_set_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphFrame::set_title, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_get_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphFrame::get_title, ctx, this_val, argc, argv);
}
static JSValue graph_frame_class_get_titlebar_hbox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphFrame::get_titlebar_hbox, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_set_autoshrink_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphFrame::set_autoshrink_enabled, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_is_autoshrink_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphFrame::is_autoshrink_enabled, ctx, this_val, argc, argv);
}
static JSValue graph_frame_class_set_autoshrink_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphFrame::set_autoshrink_margin, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_get_autoshrink_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphFrame::get_autoshrink_margin, ctx, this_val, argc, argv);
}
static JSValue graph_frame_class_set_drag_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphFrame::set_drag_margin, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_get_drag_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphFrame::get_drag_margin, ctx, this_val, argc, argv);
}
static JSValue graph_frame_class_set_tint_color_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphFrame::set_tint_color_enabled, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_is_tint_color_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphFrame::is_tint_color_enabled, ctx, this_val, argc, argv);
}
static JSValue graph_frame_class_set_tint_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphFrame::set_tint_color, ctx, this_val, argc, argv);
};
static JSValue graph_frame_class_get_tint_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		GraphFrame *obj = static_cast<GraphFrame *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tint_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		GraphFrame *js_proxy = static_cast<GraphFrame *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tint_color(value);
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



static const JSCFunctionListEntry graph_frame_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_title", 1, &graph_frame_class_set_title),
	JS_CFUNC_DEF("get_title", 0, &graph_frame_class_get_title),
	JS_CFUNC_DEF("get_titlebar_hbox", 0, &graph_frame_class_get_titlebar_hbox),
	JS_CFUNC_DEF("set_autoshrink_enabled", 1, &graph_frame_class_set_autoshrink_enabled),
	JS_CFUNC_DEF("is_autoshrink_enabled", 0, &graph_frame_class_is_autoshrink_enabled),
	JS_CFUNC_DEF("set_autoshrink_margin", 1, &graph_frame_class_set_autoshrink_margin),
	JS_CFUNC_DEF("get_autoshrink_margin", 0, &graph_frame_class_get_autoshrink_margin),
	JS_CFUNC_DEF("set_drag_margin", 1, &graph_frame_class_set_drag_margin),
	JS_CFUNC_DEF("get_drag_margin", 0, &graph_frame_class_get_drag_margin),
	JS_CFUNC_DEF("set_tint_color_enabled", 1, &graph_frame_class_set_tint_color_enabled),
	JS_CFUNC_DEF("is_tint_color_enabled", 0, &graph_frame_class_is_tint_color_enabled),
	JS_CFUNC_DEF("set_tint_color", 1, &graph_frame_class_set_tint_color),
	JS_CFUNC_DEF("get_tint_color", 0, &graph_frame_class_get_tint_color),
};


static JSValue graph_frame_class_get_autoshrink_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphFrame *opaque = static_cast<GraphFrame *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "autoshrink_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "autoshrink_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "autoshrink_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_graph_frame_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title"),
        JS_NewCFunction(ctx, graph_frame_class_get_title, "get_title", 0),
        JS_NewCFunction(ctx, graph_frame_class_set_title, "set_title", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoshrink_enabled"),
        JS_NewCFunction(ctx, graph_frame_class_is_autoshrink_enabled, "is_autoshrink_enabled", 0),
        JS_NewCFunction(ctx, graph_frame_class_set_autoshrink_enabled, "set_autoshrink_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoshrink_margin"),
        JS_NewCFunction(ctx, graph_frame_class_get_autoshrink_margin, "get_autoshrink_margin", 0),
        JS_NewCFunction(ctx, graph_frame_class_set_autoshrink_margin, "set_autoshrink_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_margin"),
        JS_NewCFunction(ctx, graph_frame_class_get_drag_margin, "get_drag_margin", 0),
        JS_NewCFunction(ctx, graph_frame_class_set_drag_margin, "set_drag_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tint_color_enabled"),
        JS_NewCFunction(ctx, graph_frame_class_is_tint_color_enabled, "is_tint_color_enabled", 0),
        JS_NewCFunction(ctx, graph_frame_class_set_tint_color_enabled, "set_tint_color_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tint_color"),
        JS_NewCFunction(ctx, graph_frame_class_get_tint_color, "get_tint_color", 0),
        JS_NewCFunction(ctx, graph_frame_class_set_tint_color, "set_tint_color", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "autoshrink_changed"),
		JS_NewCFunction(ctx, graph_frame_class_get_autoshrink_changed_signal, "get_autoshrink_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_graph_frame_enum(JSContext *ctx, JSValue ctor) {
}

static int js_graph_frame_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GraphFrame"] = class_id;
	classes_by_id[class_id] = "GraphFrame";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &graph_frame_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GraphElement"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_graph_frame_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, graph_frame_class_proto_funcs, _countof(graph_frame_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, graph_frame_class_constructor, "GraphFrame", 0, JS_CFUNC_constructor, 0);
	define_graph_frame_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GraphFrame", ctor);

	return 0;
}

JSModuleDef *_js_init_graph_frame_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/graph_element';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_graph_frame_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GraphFrame");
	return m;
}

JSModuleDef *js_init_graph_frame_module(JSContext *ctx) {
	return _js_init_graph_frame_module(ctx, "@godot/classes/graph_frame");
}

void __register_graph_frame() {
	js_init_graph_frame_module(js_context());
}

void register_graph_frame() {
	__register_graph_frame();
}