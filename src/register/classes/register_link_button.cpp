#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/base_button.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/link_button.hpp>
using namespace godot;

static void link_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["LinkButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef link_button_class_def = {
    "LinkButton",
    link_button_class_finalizer
};

static JSValue link_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["LinkButton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    LinkButton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<LinkButton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(LinkButton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue link_button_class_set_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_text, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LinkButton::get_text, ctx, this_val, argc, argv);
}
static JSValue link_button_class_set_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_text_direction, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LinkButton::get_text_direction, ctx, this_val, argc, argv);
}
static JSValue link_button_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_language, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LinkButton::get_language, ctx, this_val, argc, argv);
}
static JSValue link_button_class_set_uri(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_uri, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_uri(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LinkButton::get_uri, ctx, this_val, argc, argv);
}
static JSValue link_button_class_set_underline_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_underline_mode, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_underline_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LinkButton::get_underline_mode, ctx, this_val, argc, argv);
}
static JSValue link_button_class_set_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_structured_text_bidi_override, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_structured_text_bidi_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LinkButton::get_structured_text_bidi_override, ctx, this_val, argc, argv);
}
static JSValue link_button_class_set_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LinkButton::set_structured_text_bidi_override_options, ctx, this_val, argc, argv);
};
static JSValue link_button_class_get_structured_text_bidi_override_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		LinkButton *obj = static_cast<LinkButton *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_structured_text_bidi_override_options();
	};
	proxy->setter = [this_val](const Array &value) -> void {
		LinkButton *js_proxy = static_cast<LinkButton *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_structured_text_bidi_override_options(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry link_button_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_text", 1, &link_button_class_set_text),
	JS_CFUNC_DEF("get_text", 0, &link_button_class_get_text),
	JS_CFUNC_DEF("set_text_direction", 1, &link_button_class_set_text_direction),
	JS_CFUNC_DEF("get_text_direction", 0, &link_button_class_get_text_direction),
	JS_CFUNC_DEF("set_language", 1, &link_button_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &link_button_class_get_language),
	JS_CFUNC_DEF("set_uri", 1, &link_button_class_set_uri),
	JS_CFUNC_DEF("get_uri", 0, &link_button_class_get_uri),
	JS_CFUNC_DEF("set_underline_mode", 1, &link_button_class_set_underline_mode),
	JS_CFUNC_DEF("get_underline_mode", 0, &link_button_class_get_underline_mode),
	JS_CFUNC_DEF("set_structured_text_bidi_override", 1, &link_button_class_set_structured_text_bidi_override),
	JS_CFUNC_DEF("get_structured_text_bidi_override", 0, &link_button_class_get_structured_text_bidi_override),
	JS_CFUNC_DEF("set_structured_text_bidi_override_options", 1, &link_button_class_set_structured_text_bidi_override_options),
	JS_CFUNC_DEF("get_structured_text_bidi_override_options", 0, &link_button_class_get_structured_text_bidi_override_options),
};




static void define_link_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text"),
        JS_NewCFunction(ctx, link_button_class_get_text, "get_text", 0),
        JS_NewCFunction(ctx, link_button_class_set_text, "set_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "underline"),
        JS_NewCFunction(ctx, link_button_class_get_underline_mode, "get_underline_mode", 0),
        JS_NewCFunction(ctx, link_button_class_set_underline_mode, "set_underline_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uri"),
        JS_NewCFunction(ctx, link_button_class_get_uri, "get_uri", 0),
        JS_NewCFunction(ctx, link_button_class_set_uri, "set_uri", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "text_direction"),
        JS_NewCFunction(ctx, link_button_class_get_text_direction, "get_text_direction", 0),
        JS_NewCFunction(ctx, link_button_class_set_text_direction, "set_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, link_button_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, link_button_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override"),
        JS_NewCFunction(ctx, link_button_class_get_structured_text_bidi_override, "get_structured_text_bidi_override", 0),
        JS_NewCFunction(ctx, link_button_class_set_structured_text_bidi_override, "set_structured_text_bidi_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "structured_text_bidi_override_options"),
        JS_NewCFunction(ctx, link_button_class_get_structured_text_bidi_override_options, "get_structured_text_bidi_override_options", 0),
        JS_NewCFunction(ctx, link_button_class_set_structured_text_bidi_override_options, "set_structured_text_bidi_override_options", 1),
        JS_PROP_GETSET
    );
}

static void define_link_button_enum(JSContext *ctx, JSValue ctor) {
	JSValue UnderlineMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UnderlineMode_obj, "UNDERLINE_MODE_ALWAYS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, UnderlineMode_obj, "UNDERLINE_MODE_ON_HOVER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, UnderlineMode_obj, "UNDERLINE_MODE_NEVER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "UnderlineMode", UnderlineMode_obj);
}

static int js_link_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["LinkButton"] = class_id;
	classes_by_id[class_id] = "LinkButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &link_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["BaseButton"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_link_button_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, link_button_class_proto_funcs, _countof(link_button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, link_button_class_constructor, "LinkButton", 0, JS_CFUNC_constructor, 0);
	define_link_button_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "LinkButton", ctor);

	return 0;
}

JSModuleDef *_js_init_link_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/base_button';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_link_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "LinkButton");
	return m;
}

JSModuleDef *js_init_link_button_module(JSContext *ctx) {
	return _js_init_link_button_module(ctx, "@godot/classes/link_button");
}

void __register_link_button() {
	js_init_link_button_module(js_context());
}

void register_link_button() {
	__register_link_button();
}