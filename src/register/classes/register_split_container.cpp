#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/split_container.hpp>
using namespace godot;

static void split_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SplitContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef split_container_class_def = {
    "SplitContainer",
    split_container_class_finalizer
};

static JSValue split_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SplitContainer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SplitContainer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SplitContainer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SplitContainer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue split_container_class_set_split_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_split_offset, ctx, this_val, argc, argv);
};
static JSValue split_container_class_get_split_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::get_split_offset, ctx, this_val, argc, argv);
}
static JSValue split_container_class_clamp_split_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::clamp_split_offset, ctx, this_val, argc, argv);
};
static JSValue split_container_class_set_collapsed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_collapsed, ctx, this_val, argc, argv);
};
static JSValue split_container_class_is_collapsed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::is_collapsed, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_dragger_visibility(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_dragger_visibility, ctx, this_val, argc, argv);
};
static JSValue split_container_class_get_dragger_visibility(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::get_dragger_visibility, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_vertical(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_vertical, ctx, this_val, argc, argv);
};
static JSValue split_container_class_is_vertical(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::is_vertical, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_dragging_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_dragging_enabled, ctx, this_val, argc, argv);
};
static JSValue split_container_class_is_dragging_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::is_dragging_enabled, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_drag_area_margin_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_drag_area_margin_begin, ctx, this_val, argc, argv);
};
static JSValue split_container_class_get_drag_area_margin_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::get_drag_area_margin_begin, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_drag_area_margin_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_drag_area_margin_end, ctx, this_val, argc, argv);
};
static JSValue split_container_class_get_drag_area_margin_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::get_drag_area_margin_end, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_drag_area_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_drag_area_offset, ctx, this_val, argc, argv);
};
static JSValue split_container_class_get_drag_area_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::get_drag_area_offset, ctx, this_val, argc, argv);
}
static JSValue split_container_class_set_drag_area_highlight_in_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_drag_area_highlight_in_editor, ctx, this_val, argc, argv);
};
static JSValue split_container_class_is_drag_area_highlight_in_editor_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::is_drag_area_highlight_in_editor_enabled, ctx, this_val, argc, argv);
}
static JSValue split_container_class_get_drag_area_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SplitContainer::get_drag_area_control, ctx, this_val, argc, argv);
};
static JSValue split_container_class_set_touch_dragger_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SplitContainer::set_touch_dragger_enabled, ctx, this_val, argc, argv);
};
static JSValue split_container_class_is_touch_dragger_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SplitContainer::is_touch_dragger_enabled, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry split_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_split_offset", 1, &split_container_class_set_split_offset),
	JS_CFUNC_DEF("get_split_offset", 0, &split_container_class_get_split_offset),
	JS_CFUNC_DEF("clamp_split_offset", 0, &split_container_class_clamp_split_offset),
	JS_CFUNC_DEF("set_collapsed", 1, &split_container_class_set_collapsed),
	JS_CFUNC_DEF("is_collapsed", 0, &split_container_class_is_collapsed),
	JS_CFUNC_DEF("set_dragger_visibility", 1, &split_container_class_set_dragger_visibility),
	JS_CFUNC_DEF("get_dragger_visibility", 0, &split_container_class_get_dragger_visibility),
	JS_CFUNC_DEF("set_vertical", 1, &split_container_class_set_vertical),
	JS_CFUNC_DEF("is_vertical", 0, &split_container_class_is_vertical),
	JS_CFUNC_DEF("set_dragging_enabled", 1, &split_container_class_set_dragging_enabled),
	JS_CFUNC_DEF("is_dragging_enabled", 0, &split_container_class_is_dragging_enabled),
	JS_CFUNC_DEF("set_drag_area_margin_begin", 1, &split_container_class_set_drag_area_margin_begin),
	JS_CFUNC_DEF("get_drag_area_margin_begin", 0, &split_container_class_get_drag_area_margin_begin),
	JS_CFUNC_DEF("set_drag_area_margin_end", 1, &split_container_class_set_drag_area_margin_end),
	JS_CFUNC_DEF("get_drag_area_margin_end", 0, &split_container_class_get_drag_area_margin_end),
	JS_CFUNC_DEF("set_drag_area_offset", 1, &split_container_class_set_drag_area_offset),
	JS_CFUNC_DEF("get_drag_area_offset", 0, &split_container_class_get_drag_area_offset),
	JS_CFUNC_DEF("set_drag_area_highlight_in_editor", 1, &split_container_class_set_drag_area_highlight_in_editor),
	JS_CFUNC_DEF("is_drag_area_highlight_in_editor_enabled", 0, &split_container_class_is_drag_area_highlight_in_editor_enabled),
	JS_CFUNC_DEF("get_drag_area_control", 0, &split_container_class_get_drag_area_control),
	JS_CFUNC_DEF("set_touch_dragger_enabled", 1, &split_container_class_set_touch_dragger_enabled),
	JS_CFUNC_DEF("is_touch_dragger_enabled", 0, &split_container_class_is_touch_dragger_enabled),
};


static JSValue split_container_class_get_dragged_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SplitContainer *opaque = static_cast<SplitContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "dragged_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "dragged"));
		JS_DefinePropertyValueStr(ctx, this_val, "dragged_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue split_container_class_get_drag_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SplitContainer *opaque = static_cast<SplitContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "drag_started_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "drag_started"));
		JS_DefinePropertyValueStr(ctx, this_val, "drag_started_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue split_container_class_get_drag_ended_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SplitContainer *opaque = static_cast<SplitContainer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "drag_ended_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "drag_ended"));
		JS_DefinePropertyValueStr(ctx, this_val, "drag_ended_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_split_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "split_offset"),
        JS_NewCFunction(ctx, split_container_class_get_split_offset, "get_split_offset", 0),
        JS_NewCFunction(ctx, split_container_class_set_split_offset, "set_split_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collapsed"),
        JS_NewCFunction(ctx, split_container_class_is_collapsed, "is_collapsed", 0),
        JS_NewCFunction(ctx, split_container_class_set_collapsed, "set_collapsed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dragging_enabled"),
        JS_NewCFunction(ctx, split_container_class_is_dragging_enabled, "is_dragging_enabled", 0),
        JS_NewCFunction(ctx, split_container_class_set_dragging_enabled, "set_dragging_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dragger_visibility"),
        JS_NewCFunction(ctx, split_container_class_get_dragger_visibility, "get_dragger_visibility", 0),
        JS_NewCFunction(ctx, split_container_class_set_dragger_visibility, "set_dragger_visibility", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertical"),
        JS_NewCFunction(ctx, split_container_class_is_vertical, "is_vertical", 0),
        JS_NewCFunction(ctx, split_container_class_set_vertical, "set_vertical", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "touch_dragger_enabled"),
        JS_NewCFunction(ctx, split_container_class_is_touch_dragger_enabled, "is_touch_dragger_enabled", 0),
        JS_NewCFunction(ctx, split_container_class_set_touch_dragger_enabled, "set_touch_dragger_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_area_margin_begin"),
        JS_NewCFunction(ctx, split_container_class_get_drag_area_margin_begin, "get_drag_area_margin_begin", 0),
        JS_NewCFunction(ctx, split_container_class_set_drag_area_margin_begin, "set_drag_area_margin_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_area_margin_end"),
        JS_NewCFunction(ctx, split_container_class_get_drag_area_margin_end, "get_drag_area_margin_end", 0),
        JS_NewCFunction(ctx, split_container_class_set_drag_area_margin_end, "set_drag_area_margin_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_area_offset"),
        JS_NewCFunction(ctx, split_container_class_get_drag_area_offset, "get_drag_area_offset", 0),
        JS_NewCFunction(ctx, split_container_class_set_drag_area_offset, "set_drag_area_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drag_area_highlight_in_editor"),
        JS_NewCFunction(ctx, split_container_class_is_drag_area_highlight_in_editor_enabled, "is_drag_area_highlight_in_editor_enabled", 0),
        JS_NewCFunction(ctx, split_container_class_set_drag_area_highlight_in_editor, "set_drag_area_highlight_in_editor", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "dragged"),
		JS_NewCFunction(ctx, split_container_class_get_dragged_signal, "get_dragged_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "drag_started"),
		JS_NewCFunction(ctx, split_container_class_get_drag_started_signal, "get_drag_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "drag_ended"),
		JS_NewCFunction(ctx, split_container_class_get_drag_ended_signal, "get_drag_ended_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_split_container_enum(JSContext *ctx, JSValue proto) {
	JSValue DraggerVisibility_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DraggerVisibility_obj, "DRAGGER_VISIBLE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DraggerVisibility_obj, "DRAGGER_HIDDEN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DraggerVisibility_obj, "DRAGGER_HIDDEN_COLLAPSED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "DraggerVisibility", DraggerVisibility_obj);
}

static int js_split_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SplitContainer"] = class_id;
	classes_by_id[class_id] = "SplitContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &split_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_split_container_property(ctx, proto);
	define_split_container_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, split_container_class_proto_funcs, _countof(split_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, split_container_class_constructor, "SplitContainer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SplitContainer", ctor);

	return 0;
}

JSModuleDef *_js_init_split_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_split_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SplitContainer");
	return m;
}

JSModuleDef *js_init_split_container_module(JSContext *ctx) {
	return _js_init_split_container_module(ctx, "@godot/classes/split_container");
}

void __register_split_container() {
	js_init_split_container_module(js_context());
}

void register_split_container() {
	__register_split_container();
}