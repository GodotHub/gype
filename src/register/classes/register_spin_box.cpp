#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/spin_box.hpp>
using namespace godot;

static void spin_box_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpinBox"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spin_box_class_def = {
    "SpinBox",
    spin_box_class_finalizer
};

static JSValue spin_box_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpinBox"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SpinBox *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SpinBox *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SpinBox);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue spin_box_class_set_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_horizontal_alignment, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_get_horizontal_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpinBox::get_horizontal_alignment, ctx, this_val, argc, argv);
}
static JSValue spin_box_class_set_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_suffix, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_get_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		SpinBox *obj = static_cast<SpinBox *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_suffix();
	};
	proxy->setter = [this_val](const String &value) -> void {
		SpinBox *js_proxy = static_cast<SpinBox *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_suffix(value);
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
static JSValue spin_box_class_set_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_prefix, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_get_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		SpinBox *obj = static_cast<SpinBox *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_prefix();
	};
	proxy->setter = [this_val](const String &value) -> void {
		SpinBox *js_proxy = static_cast<SpinBox *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_prefix(value);
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
static JSValue spin_box_class_set_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_editable, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_set_custom_arrow_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_custom_arrow_step, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_get_custom_arrow_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpinBox::get_custom_arrow_step, ctx, this_val, argc, argv);
}
static JSValue spin_box_class_is_editable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpinBox::is_editable, ctx, this_val, argc, argv);
}
static JSValue spin_box_class_set_update_on_text_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_update_on_text_changed, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_get_update_on_text_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpinBox::get_update_on_text_changed, ctx, this_val, argc, argv);
}
static JSValue spin_box_class_set_select_all_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::set_select_all_on_focus, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_is_select_all_on_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpinBox::is_select_all_on_focus, ctx, this_val, argc, argv);
}
static JSValue spin_box_class_apply(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpinBox::apply, ctx, this_val, argc, argv);
};
static JSValue spin_box_class_get_line_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SpinBox::get_line_edit, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry spin_box_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_horizontal_alignment", 1, &spin_box_class_set_horizontal_alignment),
	JS_CFUNC_DEF("get_horizontal_alignment", 0, &spin_box_class_get_horizontal_alignment),
	JS_CFUNC_DEF("set_suffix", 1, &spin_box_class_set_suffix),
	JS_CFUNC_DEF("get_suffix", 0, &spin_box_class_get_suffix),
	JS_CFUNC_DEF("set_prefix", 1, &spin_box_class_set_prefix),
	JS_CFUNC_DEF("get_prefix", 0, &spin_box_class_get_prefix),
	JS_CFUNC_DEF("set_editable", 1, &spin_box_class_set_editable),
	JS_CFUNC_DEF("set_custom_arrow_step", 1, &spin_box_class_set_custom_arrow_step),
	JS_CFUNC_DEF("get_custom_arrow_step", 0, &spin_box_class_get_custom_arrow_step),
	JS_CFUNC_DEF("is_editable", 0, &spin_box_class_is_editable),
	JS_CFUNC_DEF("set_update_on_text_changed", 1, &spin_box_class_set_update_on_text_changed),
	JS_CFUNC_DEF("get_update_on_text_changed", 0, &spin_box_class_get_update_on_text_changed),
	JS_CFUNC_DEF("set_select_all_on_focus", 1, &spin_box_class_set_select_all_on_focus),
	JS_CFUNC_DEF("is_select_all_on_focus", 0, &spin_box_class_is_select_all_on_focus),
	JS_CFUNC_DEF("apply", 0, &spin_box_class_apply),
	JS_CFUNC_DEF("get_line_edit", 0, &spin_box_class_get_line_edit),
};




static void define_spin_box_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alignment"),
        JS_NewCFunction(ctx, spin_box_class_get_horizontal_alignment, "get_horizontal_alignment", 0),
        JS_NewCFunction(ctx, spin_box_class_set_horizontal_alignment, "set_horizontal_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editable"),
        JS_NewCFunction(ctx, spin_box_class_is_editable, "is_editable", 0),
        JS_NewCFunction(ctx, spin_box_class_set_editable, "set_editable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "update_on_text_changed"),
        JS_NewCFunction(ctx, spin_box_class_get_update_on_text_changed, "get_update_on_text_changed", 0),
        JS_NewCFunction(ctx, spin_box_class_set_update_on_text_changed, "set_update_on_text_changed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "prefix"),
        JS_NewCFunction(ctx, spin_box_class_get_prefix, "get_prefix", 0),
        JS_NewCFunction(ctx, spin_box_class_set_prefix, "set_prefix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "suffix"),
        JS_NewCFunction(ctx, spin_box_class_get_suffix, "get_suffix", 0),
        JS_NewCFunction(ctx, spin_box_class_set_suffix, "set_suffix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_arrow_step"),
        JS_NewCFunction(ctx, spin_box_class_get_custom_arrow_step, "get_custom_arrow_step", 0),
        JS_NewCFunction(ctx, spin_box_class_set_custom_arrow_step, "set_custom_arrow_step", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "select_all_on_focus"),
        JS_NewCFunction(ctx, spin_box_class_is_select_all_on_focus, "is_select_all_on_focus", 0),
        JS_NewCFunction(ctx, spin_box_class_set_select_all_on_focus, "set_select_all_on_focus", 1),
        JS_PROP_GETSET
    );
}

static void define_spin_box_enum(JSContext *ctx, JSValue ctor) {
}

static int js_spin_box_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpinBox"] = class_id;
	classes_by_id[class_id] = "SpinBox";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spin_box_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Range"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spin_box_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, spin_box_class_proto_funcs, _countof(spin_box_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, spin_box_class_constructor, "SpinBox", 0, JS_CFUNC_constructor, 0);
	define_spin_box_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpinBox", ctor);

	return 0;
}

JSModuleDef *_js_init_spin_box_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/range';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spin_box_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpinBox");
	return m;
}

JSModuleDef *js_init_spin_box_module(JSContext *ctx) {
	return _js_init_spin_box_module(ctx, "@godot/classes/spin_box");
}

void __register_spin_box() {
	js_init_spin_box_module(js_context());
}

void register_spin_box() {
	__register_spin_box();
}