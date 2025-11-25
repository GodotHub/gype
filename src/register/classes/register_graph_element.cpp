#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/graph_element.hpp>
using namespace godot;

static void graph_element_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GraphElement"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef graph_element_class_def = {
    "GraphElement",
    graph_element_class_finalizer
};

static JSValue graph_element_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GraphElement"];
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
        instance = memnew(GraphElement);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue graph_element_class_set_resizable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphElement::set_resizable, ctx, this_val, argc, argv);
};
static JSValue graph_element_class_is_resizable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphElement::is_resizable, ctx, this_val, argc, argv);
}
static JSValue graph_element_class_set_draggable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphElement::set_draggable, ctx, this_val, argc, argv);
};
static JSValue graph_element_class_is_draggable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphElement::is_draggable, ctx, this_val, argc, argv);
}
static JSValue graph_element_class_set_selectable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphElement::set_selectable, ctx, this_val, argc, argv);
};
static JSValue graph_element_class_is_selectable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphElement::is_selectable, ctx, this_val, argc, argv);
}
static JSValue graph_element_class_set_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphElement::set_selected, ctx, this_val, argc, argv);
};
static JSValue graph_element_class_is_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphElement::is_selected, ctx, this_val, argc, argv);
}
static JSValue graph_element_class_set_position_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphElement::set_position_offset, ctx, this_val, argc, argv);
};
static JSValue graph_element_class_get_position_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		GraphElement *obj = static_cast<GraphElement *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		GraphElement *js_proxy = static_cast<GraphElement *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry graph_element_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_resizable", 1, &graph_element_class_set_resizable),
	JS_CFUNC_DEF("is_resizable", 0, &graph_element_class_is_resizable),
	JS_CFUNC_DEF("set_draggable", 1, &graph_element_class_set_draggable),
	JS_CFUNC_DEF("is_draggable", 0, &graph_element_class_is_draggable),
	JS_CFUNC_DEF("set_selectable", 1, &graph_element_class_set_selectable),
	JS_CFUNC_DEF("is_selectable", 0, &graph_element_class_is_selectable),
	JS_CFUNC_DEF("set_selected", 1, &graph_element_class_set_selected),
	JS_CFUNC_DEF("is_selected", 0, &graph_element_class_is_selected),
	JS_CFUNC_DEF("set_position_offset", 1, &graph_element_class_set_position_offset),
	JS_CFUNC_DEF("get_position_offset", 0, &graph_element_class_get_position_offset),
};


static JSValue graph_element_class_get_node_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_node_deselected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_deselected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_deselected"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_deselected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_raise_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "raise_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "raise_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "raise_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_delete_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "delete_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "delete_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "delete_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_resize_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resize_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resize_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "resize_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_resize_end_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resize_end_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resize_end"));
		JS_DefinePropertyValueStr(ctx, this_val, "resize_end_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_dragged_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "dragged_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "dragged"));
		JS_DefinePropertyValueStr(ctx, this_val, "dragged_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_element_class_get_position_offset_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphElement *opaque = static_cast<GraphElement *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "position_offset_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "position_offset_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "position_offset_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_graph_element_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position_offset"),
        JS_NewCFunction(ctx, graph_element_class_get_position_offset, "get_position_offset", 0),
        JS_NewCFunction(ctx, graph_element_class_set_position_offset, "set_position_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resizable"),
        JS_NewCFunction(ctx, graph_element_class_is_resizable, "is_resizable", 0),
        JS_NewCFunction(ctx, graph_element_class_set_resizable, "set_resizable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draggable"),
        JS_NewCFunction(ctx, graph_element_class_is_draggable, "is_draggable", 0),
        JS_NewCFunction(ctx, graph_element_class_set_draggable, "set_draggable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "selectable"),
        JS_NewCFunction(ctx, graph_element_class_is_selectable, "is_selectable", 0),
        JS_NewCFunction(ctx, graph_element_class_set_selectable, "set_selectable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "selected"),
        JS_NewCFunction(ctx, graph_element_class_is_selected, "is_selected", 0),
        JS_NewCFunction(ctx, graph_element_class_set_selected, "set_selected", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_selected"),
		JS_NewCFunction(ctx, graph_element_class_get_node_selected_signal, "get_node_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_deselected"),
		JS_NewCFunction(ctx, graph_element_class_get_node_deselected_signal, "get_node_deselected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "raise_request"),
		JS_NewCFunction(ctx, graph_element_class_get_raise_request_signal, "get_raise_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "delete_request"),
		JS_NewCFunction(ctx, graph_element_class_get_delete_request_signal, "get_delete_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resize_request"),
		JS_NewCFunction(ctx, graph_element_class_get_resize_request_signal, "get_resize_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resize_end"),
		JS_NewCFunction(ctx, graph_element_class_get_resize_end_signal, "get_resize_end_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "dragged"),
		JS_NewCFunction(ctx, graph_element_class_get_dragged_signal, "get_dragged_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "position_offset_changed"),
		JS_NewCFunction(ctx, graph_element_class_get_position_offset_changed_signal, "get_position_offset_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_graph_element_enum(JSContext *ctx, JSValue ctor) {
}

static int js_graph_element_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GraphElement"] = class_id;
	classes_by_id[class_id] = "GraphElement";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &graph_element_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_graph_element_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, graph_element_class_proto_funcs, _countof(graph_element_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, graph_element_class_constructor, "GraphElement", 0, JS_CFUNC_constructor, 0);
	define_graph_element_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GraphElement", ctor);
	ctor_list["GraphElement"] = ctor;

	return 0;
}

JSModuleDef *_js_init_graph_element_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_graph_element_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GraphElement");
	return m;
}

JSModuleDef *js_init_graph_element_module(JSContext *ctx) {
	return _js_init_graph_element_module(ctx, "@godot/classes/graph_element");
}

void __register_graph_element() {
	js_init_graph_element_module(js_context());
}

void register_graph_element() {
	__register_graph_element();
}