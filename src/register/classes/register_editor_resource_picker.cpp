#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_resource_picker.hpp>
using namespace godot;

static void editor_resource_picker_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorResourcePicker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_resource_picker_class_def = {
    "EditorResourcePicker",
    editor_resource_picker_class_finalizer
};

static JSValue editor_resource_picker_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorResourcePicker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorResourcePicker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorResourcePicker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorResourcePicker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_resource_picker_class_set_base_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePicker::set_base_type, ctx, this_val, argc, argv);
};
static JSValue editor_resource_picker_class_get_base_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		EditorResourcePicker *obj = static_cast<EditorResourcePicker *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_base_type();
	};
	proxy->setter = [this_val](const String &value) -> void {
		EditorResourcePicker *js_proxy = static_cast<EditorResourcePicker *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_base_type(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue editor_resource_picker_class_get_allowed_types(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorResourcePicker::get_allowed_types, ctx, this_val, argc, argv);
};
static JSValue editor_resource_picker_class_set_edited_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePicker::set_edited_resource, ctx, this_val, argc, argv);
};
static JSValue editor_resource_picker_class_get_edited_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorResourcePicker::get_edited_resource, ctx, this_val, argc, argv);
}
static JSValue editor_resource_picker_class_set_toggle_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePicker::set_toggle_mode, ctx, this_val, argc, argv);
};
static JSValue editor_resource_picker_class_is_toggle_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorResourcePicker::is_toggle_mode, ctx, this_val, argc, argv);
}
static JSValue editor_resource_picker_class_set_toggle_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePicker::set_toggle_pressed, ctx, this_val, argc, argv);
};
static JSValue editor_resource_picker_class_set_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePicker::set_editable, ctx, this_val, argc, argv);
};
static JSValue editor_resource_picker_class_is_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorResourcePicker::is_editable, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry editor_resource_picker_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_base_type", 1, &editor_resource_picker_class_set_base_type),
	JS_CFUNC_DEF("get_base_type", 0, &editor_resource_picker_class_get_base_type),
	JS_CFUNC_DEF("get_allowed_types", 0, &editor_resource_picker_class_get_allowed_types),
	JS_CFUNC_DEF("set_edited_resource", 1, &editor_resource_picker_class_set_edited_resource),
	JS_CFUNC_DEF("get_edited_resource", 0, &editor_resource_picker_class_get_edited_resource),
	JS_CFUNC_DEF("set_toggle_mode", 1, &editor_resource_picker_class_set_toggle_mode),
	JS_CFUNC_DEF("is_toggle_mode", 0, &editor_resource_picker_class_is_toggle_mode),
	JS_CFUNC_DEF("set_toggle_pressed", 1, &editor_resource_picker_class_set_toggle_pressed),
	JS_CFUNC_DEF("set_editable", 1, &editor_resource_picker_class_set_editable),
	JS_CFUNC_DEF("is_editable", 0, &editor_resource_picker_class_is_editable),
};


static JSValue editor_resource_picker_class_get_resource_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorResourcePicker *opaque = static_cast<EditorResourcePicker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resource_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resource_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "resource_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_resource_picker_class_get_resource_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorResourcePicker *opaque = static_cast<EditorResourcePicker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resource_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resource_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "resource_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_resource_picker_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "base_type"),
        JS_NewCFunction(ctx, editor_resource_picker_class_get_base_type, "get_base_type", 0),
        JS_NewCFunction(ctx, editor_resource_picker_class_set_base_type, "set_base_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edited_resource"),
        JS_NewCFunction(ctx, editor_resource_picker_class_get_edited_resource, "get_edited_resource", 0),
        JS_NewCFunction(ctx, editor_resource_picker_class_set_edited_resource, "set_edited_resource", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editable"),
        JS_NewCFunction(ctx, editor_resource_picker_class_is_editable, "is_editable", 0),
        JS_NewCFunction(ctx, editor_resource_picker_class_set_editable, "set_editable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "toggle_mode"),
        JS_NewCFunction(ctx, editor_resource_picker_class_is_toggle_mode, "is_toggle_mode", 0),
        JS_NewCFunction(ctx, editor_resource_picker_class_set_toggle_mode, "set_toggle_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resource_selected"),
		JS_NewCFunction(ctx, editor_resource_picker_class_get_resource_selected_signal, "get_resource_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resource_changed"),
		JS_NewCFunction(ctx, editor_resource_picker_class_get_resource_changed_signal, "get_resource_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_resource_picker_enum(JSContext *ctx, JSValue proto) {
}

static int js_editor_resource_picker_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorResourcePicker"] = class_id;
	classes_by_id[class_id] = "EditorResourcePicker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_resource_picker_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["HBoxContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_resource_picker_property(ctx, proto);
	define_editor_resource_picker_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_resource_picker_class_proto_funcs, _countof(editor_resource_picker_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_resource_picker_class_constructor, "EditorResourcePicker", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorResourcePicker", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_resource_picker_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/h_box_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_resource_picker_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorResourcePicker");
	return m;
}

JSModuleDef *js_init_editor_resource_picker_module(JSContext *ctx) {
	return _js_init_editor_resource_picker_module(ctx, "@godot/classes/editor_resource_picker");
}

void __register_editor_resource_picker() {
	js_init_editor_resource_picker_module(js_context());
}

void register_editor_resource_picker() {
	__register_editor_resource_picker();
}