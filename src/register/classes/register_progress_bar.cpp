#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/progress_bar.hpp>
using namespace godot;

static void progress_bar_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ProgressBar"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef progress_bar_class_def = {
    "ProgressBar",
    progress_bar_class_finalizer
};

static JSValue progress_bar_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ProgressBar"];
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
        instance = memnew(ProgressBar);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue progress_bar_class_set_fill_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProgressBar::set_fill_mode, ctx, this_val, argc, argv);
};
static JSValue progress_bar_class_get_fill_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ProgressBar::get_fill_mode, ctx, this_val, argc, argv);
}
static JSValue progress_bar_class_set_show_percentage(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProgressBar::set_show_percentage, ctx, this_val, argc, argv);
};
static JSValue progress_bar_class_is_percentage_shown(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProgressBar::is_percentage_shown, ctx, this_val, argc, argv);
}
static JSValue progress_bar_class_set_indeterminate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProgressBar::set_indeterminate, ctx, this_val, argc, argv);
};
static JSValue progress_bar_class_is_indeterminate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProgressBar::is_indeterminate, ctx, this_val, argc, argv);
}
static JSValue progress_bar_class_set_editor_preview_indeterminate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ProgressBar::set_editor_preview_indeterminate, ctx, this_val, argc, argv);
};
static JSValue progress_bar_class_is_editor_preview_indeterminate_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ProgressBar::is_editor_preview_indeterminate_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry progress_bar_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_fill_mode", 1, &progress_bar_class_set_fill_mode),
	JS_CFUNC_DEF("get_fill_mode", 0, &progress_bar_class_get_fill_mode),
	JS_CFUNC_DEF("set_show_percentage", 1, &progress_bar_class_set_show_percentage),
	JS_CFUNC_DEF("is_percentage_shown", 0, &progress_bar_class_is_percentage_shown),
	JS_CFUNC_DEF("set_indeterminate", 1, &progress_bar_class_set_indeterminate),
	JS_CFUNC_DEF("is_indeterminate", 0, &progress_bar_class_is_indeterminate),
	JS_CFUNC_DEF("set_editor_preview_indeterminate", 1, &progress_bar_class_set_editor_preview_indeterminate),
	JS_CFUNC_DEF("is_editor_preview_indeterminate_enabled", 0, &progress_bar_class_is_editor_preview_indeterminate_enabled),
};




static void define_progress_bar_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fill_mode"),
        JS_NewCFunction(ctx, progress_bar_class_get_fill_mode, "get_fill_mode", 0),
        JS_NewCFunction(ctx, progress_bar_class_set_fill_mode, "set_fill_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_percentage"),
        JS_NewCFunction(ctx, progress_bar_class_is_percentage_shown, "is_percentage_shown", 0),
        JS_NewCFunction(ctx, progress_bar_class_set_show_percentage, "set_show_percentage", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indeterminate"),
        JS_NewCFunction(ctx, progress_bar_class_is_indeterminate, "is_indeterminate", 0),
        JS_NewCFunction(ctx, progress_bar_class_set_indeterminate, "set_indeterminate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editor_preview_indeterminate"),
        JS_NewCFunction(ctx, progress_bar_class_is_editor_preview_indeterminate_enabled, "is_editor_preview_indeterminate_enabled", 0),
        JS_NewCFunction(ctx, progress_bar_class_set_editor_preview_indeterminate, "set_editor_preview_indeterminate", 1),
        JS_PROP_GETSET
    );
}

static void define_progress_bar_enum(JSContext *ctx, JSValue ctor) {
	JSValue FillMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_BEGIN_TO_END", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_END_TO_BEGIN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_TOP_TO_BOTTOM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_BOTTOM_TO_TOP", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "FillMode", FillMode_obj);
}

static int js_progress_bar_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ProgressBar"] = class_id;
	classes_by_id[class_id] = "ProgressBar";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &progress_bar_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Range"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_progress_bar_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, progress_bar_class_proto_funcs, _countof(progress_bar_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, progress_bar_class_constructor, "ProgressBar", 0, JS_CFUNC_constructor, 0);
	define_progress_bar_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ProgressBar", ctor);
	ctor_list["ProgressBar"] = ctor;

	return 0;
}

JSModuleDef *_js_init_progress_bar_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/range';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_progress_bar_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ProgressBar");
	return m;
}

JSModuleDef *js_init_progress_bar_module(JSContext *ctx) {
	return _js_init_progress_bar_module(ctx, "@godot/classes/progress_bar");
}

void __register_progress_bar() {
	js_init_progress_bar_module(js_context());
}

void register_progress_bar() {
	__register_progress_bar();
}