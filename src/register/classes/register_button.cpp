#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/base_button.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/button.hpp>
using namespace godot;

static void button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Button"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef button_class_def = {
    "Button",
    button_class_finalizer
};

static JSValue button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Button"];
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
        instance = memnew(Button);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue button_class_set_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_text, ctx, this_val, argc, argv);
};
static JSValue button_class_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_text, ctx, this_val, argc, argv);
}
static JSValue button_class_set_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_text_overrun_behavior, ctx, this_val, argc, argv);
};
static JSValue button_class_get_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_text_overrun_behavior, ctx, this_val, argc, argv);
}
static JSValue button_class_set_autowrap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_autowrap_mode, ctx, this_val, argc, argv);
};
static JSValue button_class_get_autowrap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_autowrap_mode, ctx, this_val, argc, argv);
}
static JSValue button_class_set_autowrap_trim_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_autowrap_trim_flags, ctx, this_val, argc, argv);
};
static JSValue button_class_get_autowrap_trim_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_autowrap_trim_flags, ctx, this_val, argc, argv);
}
static JSValue button_class_set_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_text_direction, ctx, this_val, argc, argv);
};
static JSValue button_class_get_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_text_direction, ctx, this_val, argc, argv);
}
static JSValue button_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_language, ctx, this_val, argc, argv);
};
static JSValue button_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_language, ctx, this_val, argc, argv);
}
static JSValue button_class_set_button_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_button_icon, ctx, this_val, argc, argv);
};
static JSValue button_class_get_button_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_button_icon, ctx, this_val, argc, argv);
}
static JSValue button_class_set_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_flat, ctx, this_val, argc, argv);
};
static JSValue button_class_is_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::is_flat, ctx, this_val, argc, argv);
}
static JSValue button_class_set_clip_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_clip_text, ctx, this_val, argc, argv);
};
static JSValue button_class_get_clip_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_clip_text, ctx, this_val, argc, argv);
}
static JSValue button_class_set_text_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_text_alignment, ctx, this_val, argc, argv);
};
static JSValue button_class_get_text_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_text_alignment, ctx, this_val, argc, argv);
}
static JSValue button_class_set_icon_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_icon_alignment, ctx, this_val, argc, argv);
};
static JSValue button_class_get_icon_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_icon_alignment, ctx, this_val, argc, argv);
}
static JSValue button_class_set_vertical_icon_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_vertical_icon_alignment, ctx, this_val, argc, argv);
};
static JSValue button_class_get_vertical_icon_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::get_vertical_icon_alignment, ctx, this_val, argc, argv);
}
static JSValue button_class_set_expand_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Button::set_expand_icon, ctx, this_val, argc, argv);
};
static JSValue button_class_is_expand_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Button::is_expand_icon, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry button_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_text", 1, &button_class_set_text),
	JS_CFUNC_DEF("get_text", 0, &button_class_get_text),
	JS_CFUNC_DEF("set_text_overrun_behavior", 1, &button_class_set_text_overrun_behavior),
	JS_CFUNC_DEF("get_text_overrun_behavior", 0, &button_class_get_text_overrun_behavior),
	JS_CFUNC_DEF("set_autowrap_mode", 1, &button_class_set_autowrap_mode),
	JS_CFUNC_DEF("get_autowrap_mode", 0, &button_class_get_autowrap_mode),
	JS_CFUNC_DEF("set_autowrap_trim_flags", 1, &button_class_set_autowrap_trim_flags),
	JS_CFUNC_DEF("get_autowrap_trim_flags", 0, &button_class_get_autowrap_trim_flags),
	JS_CFUNC_DEF("set_text_direction", 1, &button_class_set_text_direction),
	JS_CFUNC_DEF("get_text_direction", 0, &button_class_get_text_direction),
	JS_CFUNC_DEF("set_language", 1, &button_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &button_class_get_language),
	JS_CFUNC_DEF("set_button_icon", 1, &button_class_set_button_icon),
	JS_CFUNC_DEF("get_button_icon", 0, &button_class_get_button_icon),
	JS_CFUNC_DEF("set_flat", 1, &button_class_set_flat),
	JS_CFUNC_DEF("is_flat", 0, &button_class_is_flat),
	JS_CFUNC_DEF("set_clip_text", 1, &button_class_set_clip_text),
	JS_CFUNC_DEF("get_clip_text", 0, &button_class_get_clip_text),
	JS_CFUNC_DEF("set_text_alignment", 1, &button_class_set_text_alignment),
	JS_CFUNC_DEF("get_text_alignment", 0, &button_class_get_text_alignment),
	JS_CFUNC_DEF("set_icon_alignment", 1, &button_class_set_icon_alignment),
	JS_CFUNC_DEF("get_icon_alignment", 0, &button_class_get_icon_alignment),
	JS_CFUNC_DEF("set_vertical_icon_alignment", 1, &button_class_set_vertical_icon_alignment),
	JS_CFUNC_DEF("get_vertical_icon_alignment", 0, &button_class_get_vertical_icon_alignment),
	JS_CFUNC_DEF("set_expand_icon", 1, &button_class_set_expand_icon),
	JS_CFUNC_DEF("is_expand_icon", 0, &button_class_is_expand_icon),
};




static void define_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text"),
        JS_NewCFunction(ctx, button_class_get_text, "get_text", 0),
        JS_NewCFunction(ctx, button_class_set_text, "set_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "icon"),
        JS_NewCFunction(ctx, button_class_get_button_icon, "get_button_icon", 0),
        JS_NewCFunction(ctx, button_class_set_button_icon, "set_button_icon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flat"),
        JS_NewCFunction(ctx, button_class_is_flat, "is_flat", 0),
        JS_NewCFunction(ctx, button_class_set_flat, "set_flat", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alignment"),
        JS_NewCFunction(ctx, button_class_get_text_alignment, "get_text_alignment", 0),
        JS_NewCFunction(ctx, button_class_set_text_alignment, "set_text_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_overrun_behavior"),
        JS_NewCFunction(ctx, button_class_get_text_overrun_behavior, "get_text_overrun_behavior", 0),
        JS_NewCFunction(ctx, button_class_set_text_overrun_behavior, "set_text_overrun_behavior", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autowrap_mode"),
        JS_NewCFunction(ctx, button_class_get_autowrap_mode, "get_autowrap_mode", 0),
        JS_NewCFunction(ctx, button_class_set_autowrap_mode, "set_autowrap_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autowrap_trim_flags"),
        JS_NewCFunction(ctx, button_class_get_autowrap_trim_flags, "get_autowrap_trim_flags", 0),
        JS_NewCFunction(ctx, button_class_set_autowrap_trim_flags, "set_autowrap_trim_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clip_text"),
        JS_NewCFunction(ctx, button_class_get_clip_text, "get_clip_text", 0),
        JS_NewCFunction(ctx, button_class_set_clip_text, "set_clip_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "icon_alignment"),
        JS_NewCFunction(ctx, button_class_get_icon_alignment, "get_icon_alignment", 0),
        JS_NewCFunction(ctx, button_class_set_icon_alignment, "set_icon_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertical_icon_alignment"),
        JS_NewCFunction(ctx, button_class_get_vertical_icon_alignment, "get_vertical_icon_alignment", 0),
        JS_NewCFunction(ctx, button_class_set_vertical_icon_alignment, "set_vertical_icon_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "expand_icon"),
        JS_NewCFunction(ctx, button_class_is_expand_icon, "is_expand_icon", 0),
        JS_NewCFunction(ctx, button_class_set_expand_icon, "set_expand_icon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_direction"),
        JS_NewCFunction(ctx, button_class_get_text_direction, "get_text_direction", 0),
        JS_NewCFunction(ctx, button_class_set_text_direction, "set_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, button_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, button_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
}

static void define_button_enum(JSContext *ctx, JSValue ctor) {
}

static int js_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Button"] = class_id;
	classes_by_id[class_id] = "Button";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["BaseButton"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_button_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, button_class_proto_funcs, _countof(button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, button_class_constructor, "Button", 0, JS_CFUNC_constructor, 0);
	define_button_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Button", ctor);
	ctor_list["Button"] = ctor;

	return 0;
}

JSModuleDef *_js_init_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/base_button';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Button");
	return m;
}

JSModuleDef *js_init_button_module(JSContext *ctx) {
	return _js_init_button_module(ctx, "@godot/classes/button");
}

void __register_button() {
	js_init_button_module(js_context());
}

void register_button() {
	__register_button();
}