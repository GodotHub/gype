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
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_property.hpp>
using namespace godot;

static void editor_property_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorProperty"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_property_class_def = {
    "EditorProperty",
    editor_property_class_finalizer
};

static JSValue editor_property_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorProperty"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorProperty *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorProperty *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorProperty);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_property_class_set_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_label, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_get_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::get_label, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_read_only, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_read_only, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_draw_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_draw_label, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_draw_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_draw_label, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_draw_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_draw_background, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_draw_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_draw_background, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_checkable, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_checkable, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_checked, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_checked, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_draw_warning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_draw_warning, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_draw_warning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_draw_warning, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_keying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_keying, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_keying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_keying, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_deletable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_deletable, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_deletable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_deletable, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_get_edited_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::get_edited_property, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_get_edited_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorProperty::get_edited_object, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_update_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::update_property, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_add_focusable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::add_focusable, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_set_bottom_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_bottom_editor, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_set_selectable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_selectable, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_selectable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_selectable, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_use_folding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_use_folding, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_using_folding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_using_folding, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_set_name_split_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_name_split_ratio, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_get_name_split_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::get_name_split_ratio, ctx, this_val, argc, argv);
}
static JSValue editor_property_class_deselect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::deselect, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_is_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorProperty::is_selected, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_select(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::select, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_set_object_and_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_object_and_property, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_set_label_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::set_label_reference, ctx, this_val, argc, argv);
};
static JSValue editor_property_class_emit_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorProperty::emit_changed, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_property_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_label", 1, &editor_property_class_set_label),
	JS_CFUNC_DEF("get_label", 0, &editor_property_class_get_label),
	JS_CFUNC_DEF("set_read_only", 1, &editor_property_class_set_read_only),
	JS_CFUNC_DEF("is_read_only", 0, &editor_property_class_is_read_only),
	JS_CFUNC_DEF("set_draw_label", 1, &editor_property_class_set_draw_label),
	JS_CFUNC_DEF("is_draw_label", 0, &editor_property_class_is_draw_label),
	JS_CFUNC_DEF("set_draw_background", 1, &editor_property_class_set_draw_background),
	JS_CFUNC_DEF("is_draw_background", 0, &editor_property_class_is_draw_background),
	JS_CFUNC_DEF("set_checkable", 1, &editor_property_class_set_checkable),
	JS_CFUNC_DEF("is_checkable", 0, &editor_property_class_is_checkable),
	JS_CFUNC_DEF("set_checked", 1, &editor_property_class_set_checked),
	JS_CFUNC_DEF("is_checked", 0, &editor_property_class_is_checked),
	JS_CFUNC_DEF("set_draw_warning", 1, &editor_property_class_set_draw_warning),
	JS_CFUNC_DEF("is_draw_warning", 0, &editor_property_class_is_draw_warning),
	JS_CFUNC_DEF("set_keying", 1, &editor_property_class_set_keying),
	JS_CFUNC_DEF("is_keying", 0, &editor_property_class_is_keying),
	JS_CFUNC_DEF("set_deletable", 1, &editor_property_class_set_deletable),
	JS_CFUNC_DEF("is_deletable", 0, &editor_property_class_is_deletable),
	JS_CFUNC_DEF("get_edited_property", 0, &editor_property_class_get_edited_property),
	JS_CFUNC_DEF("get_edited_object", 0, &editor_property_class_get_edited_object),
	JS_CFUNC_DEF("update_property", 0, &editor_property_class_update_property),
	JS_CFUNC_DEF("add_focusable", 1, &editor_property_class_add_focusable),
	JS_CFUNC_DEF("set_bottom_editor", 1, &editor_property_class_set_bottom_editor),
	JS_CFUNC_DEF("set_selectable", 1, &editor_property_class_set_selectable),
	JS_CFUNC_DEF("is_selectable", 0, &editor_property_class_is_selectable),
	JS_CFUNC_DEF("set_use_folding", 1, &editor_property_class_set_use_folding),
	JS_CFUNC_DEF("is_using_folding", 0, &editor_property_class_is_using_folding),
	JS_CFUNC_DEF("set_name_split_ratio", 1, &editor_property_class_set_name_split_ratio),
	JS_CFUNC_DEF("get_name_split_ratio", 0, &editor_property_class_get_name_split_ratio),
	JS_CFUNC_DEF("deselect", 0, &editor_property_class_deselect),
	JS_CFUNC_DEF("is_selected", 0, &editor_property_class_is_selected),
	JS_CFUNC_DEF("select", 1, &editor_property_class_select),
	JS_CFUNC_DEF("set_object_and_property", 2, &editor_property_class_set_object_and_property),
	JS_CFUNC_DEF("set_label_reference", 1, &editor_property_class_set_label_reference),
	JS_CFUNC_DEF("emit_changed", 4, &editor_property_class_emit_changed),
};


static JSValue editor_property_class_get_property_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_multiple_properties_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "multiple_properties_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "multiple_properties_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "multiple_properties_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_keyed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_keyed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_keyed"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_keyed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_deleted_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_deleted_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_deleted"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_deleted_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_keyed_with_value_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_keyed_with_value_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_keyed_with_value"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_keyed_with_value_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_checked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_checked_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_checked"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_checked_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_overridden_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_overridden_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_overridden"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_overridden_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_favorited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_favorited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_favorited"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_favorited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_pinned_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_pinned_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_pinned"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_pinned_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_property_can_revert_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "property_can_revert_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "property_can_revert_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "property_can_revert_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_resource_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resource_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resource_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "resource_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_object_id_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "object_id_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "object_id_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "object_id_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_property_class_get_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorProperty *opaque = static_cast<EditorProperty *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_property_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "label"),
        JS_NewCFunction(ctx, editor_property_class_get_label, "get_label", 0),
        JS_NewCFunction(ctx, editor_property_class_set_label, "set_label", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "read_only"),
        JS_NewCFunction(ctx, editor_property_class_is_read_only, "is_read_only", 0),
        JS_NewCFunction(ctx, editor_property_class_set_read_only, "set_read_only", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_label"),
        JS_NewCFunction(ctx, editor_property_class_is_draw_label, "is_draw_label", 0),
        JS_NewCFunction(ctx, editor_property_class_set_draw_label, "set_draw_label", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_background"),
        JS_NewCFunction(ctx, editor_property_class_is_draw_background, "is_draw_background", 0),
        JS_NewCFunction(ctx, editor_property_class_set_draw_background, "set_draw_background", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "checkable"),
        JS_NewCFunction(ctx, editor_property_class_is_checkable, "is_checkable", 0),
        JS_NewCFunction(ctx, editor_property_class_set_checkable, "set_checkable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "checked"),
        JS_NewCFunction(ctx, editor_property_class_is_checked, "is_checked", 0),
        JS_NewCFunction(ctx, editor_property_class_set_checked, "set_checked", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_warning"),
        JS_NewCFunction(ctx, editor_property_class_is_draw_warning, "is_draw_warning", 0),
        JS_NewCFunction(ctx, editor_property_class_set_draw_warning, "set_draw_warning", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keying"),
        JS_NewCFunction(ctx, editor_property_class_is_keying, "is_keying", 0),
        JS_NewCFunction(ctx, editor_property_class_set_keying, "set_keying", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "deletable"),
        JS_NewCFunction(ctx, editor_property_class_is_deletable, "is_deletable", 0),
        JS_NewCFunction(ctx, editor_property_class_set_deletable, "set_deletable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "selectable"),
        JS_NewCFunction(ctx, editor_property_class_is_selectable, "is_selectable", 0),
        JS_NewCFunction(ctx, editor_property_class_set_selectable, "set_selectable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_folding"),
        JS_NewCFunction(ctx, editor_property_class_is_using_folding, "is_using_folding", 0),
        JS_NewCFunction(ctx, editor_property_class_set_use_folding, "set_use_folding", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "name_split_ratio"),
        JS_NewCFunction(ctx, editor_property_class_get_name_split_ratio, "get_name_split_ratio", 0),
        JS_NewCFunction(ctx, editor_property_class_set_name_split_ratio, "set_name_split_ratio", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_changed"),
		JS_NewCFunction(ctx, editor_property_class_get_property_changed_signal, "get_property_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "multiple_properties_changed"),
		JS_NewCFunction(ctx, editor_property_class_get_multiple_properties_changed_signal, "get_multiple_properties_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_keyed"),
		JS_NewCFunction(ctx, editor_property_class_get_property_keyed_signal, "get_property_keyed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_deleted"),
		JS_NewCFunction(ctx, editor_property_class_get_property_deleted_signal, "get_property_deleted_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_keyed_with_value"),
		JS_NewCFunction(ctx, editor_property_class_get_property_keyed_with_value_signal, "get_property_keyed_with_value_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_checked"),
		JS_NewCFunction(ctx, editor_property_class_get_property_checked_signal, "get_property_checked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_overridden"),
		JS_NewCFunction(ctx, editor_property_class_get_property_overridden_signal, "get_property_overridden_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_favorited"),
		JS_NewCFunction(ctx, editor_property_class_get_property_favorited_signal, "get_property_favorited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_pinned"),
		JS_NewCFunction(ctx, editor_property_class_get_property_pinned_signal, "get_property_pinned_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "property_can_revert_changed"),
		JS_NewCFunction(ctx, editor_property_class_get_property_can_revert_changed_signal, "get_property_can_revert_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resource_selected"),
		JS_NewCFunction(ctx, editor_property_class_get_resource_selected_signal, "get_resource_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "object_id_selected"),
		JS_NewCFunction(ctx, editor_property_class_get_object_id_selected_signal, "get_object_id_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "selected"),
		JS_NewCFunction(ctx, editor_property_class_get_selected_signal, "get_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_property_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_property_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorProperty"] = class_id;
	classes_by_id[class_id] = "EditorProperty";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_property_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_property_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_property_class_proto_funcs, _countof(editor_property_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_property_class_constructor, "EditorProperty", 0, JS_CFUNC_constructor, 0);
	define_editor_property_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorProperty", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_property_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_property_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorProperty");
	return m;
}

JSModuleDef *js_init_editor_property_module(JSContext *ctx) {
	return _js_init_editor_property_module(ctx, "@godot/classes/editor_property");
}

void __register_editor_property() {
	js_init_editor_property_module(js_context());
}

void register_editor_property() {
	__register_editor_property();
}