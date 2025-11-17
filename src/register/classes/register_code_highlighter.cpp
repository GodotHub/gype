#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/syntax_highlighter.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/code_highlighter.hpp>
using namespace godot;

static void code_highlighter_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CodeHighlighter"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef code_highlighter_class_def = {
    "CodeHighlighter",
    code_highlighter_class_finalizer
};

static JSValue code_highlighter_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CodeHighlighter"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CodeHighlighter *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CodeHighlighter *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CodeHighlighter);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue code_highlighter_class_add_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::add_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_remove_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::remove_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_has_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeHighlighter::has_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeHighlighter::get_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_set_keyword_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_keyword_colors, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_clear_keyword_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::clear_keyword_colors, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_keyword_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_keyword_colors();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_keyword_colors(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue code_highlighter_class_add_member_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::add_member_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_remove_member_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::remove_member_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_has_member_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeHighlighter::has_member_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_member_keyword_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeHighlighter::get_member_keyword_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_set_member_keyword_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_member_keyword_colors, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_clear_member_keyword_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::clear_member_keyword_colors, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_member_keyword_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_member_keyword_colors();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_member_keyword_colors(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue code_highlighter_class_add_color_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::add_color_region, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_remove_color_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::remove_color_region, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_has_color_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CodeHighlighter::has_color_region, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_set_color_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_color_regions, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_clear_color_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::clear_color_regions, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_color_regions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color_regions();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color_regions(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue code_highlighter_class_set_function_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_function_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_function_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_function_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_function_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue code_highlighter_class_set_number_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_number_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_number_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_number_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_number_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue code_highlighter_class_set_symbol_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_symbol_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_symbol_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_symbol_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_symbol_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue code_highlighter_class_set_member_variable_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CodeHighlighter::set_member_variable_color, ctx, this_val, argc, argv);
};
static JSValue code_highlighter_class_get_member_variable_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CodeHighlighter *obj = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_member_variable_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CodeHighlighter *js_proxy = static_cast<CodeHighlighter *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_member_variable_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry code_highlighter_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_keyword_color", 2, &code_highlighter_class_add_keyword_color),
	JS_CFUNC_DEF("remove_keyword_color", 1, &code_highlighter_class_remove_keyword_color),
	JS_CFUNC_DEF("has_keyword_color", 1, &code_highlighter_class_has_keyword_color),
	JS_CFUNC_DEF("get_keyword_color", 1, &code_highlighter_class_get_keyword_color),
	JS_CFUNC_DEF("set_keyword_colors", 1, &code_highlighter_class_set_keyword_colors),
	JS_CFUNC_DEF("clear_keyword_colors", 0, &code_highlighter_class_clear_keyword_colors),
	JS_CFUNC_DEF("get_keyword_colors", 0, &code_highlighter_class_get_keyword_colors),
	JS_CFUNC_DEF("add_member_keyword_color", 2, &code_highlighter_class_add_member_keyword_color),
	JS_CFUNC_DEF("remove_member_keyword_color", 1, &code_highlighter_class_remove_member_keyword_color),
	JS_CFUNC_DEF("has_member_keyword_color", 1, &code_highlighter_class_has_member_keyword_color),
	JS_CFUNC_DEF("get_member_keyword_color", 1, &code_highlighter_class_get_member_keyword_color),
	JS_CFUNC_DEF("set_member_keyword_colors", 1, &code_highlighter_class_set_member_keyword_colors),
	JS_CFUNC_DEF("clear_member_keyword_colors", 0, &code_highlighter_class_clear_member_keyword_colors),
	JS_CFUNC_DEF("get_member_keyword_colors", 0, &code_highlighter_class_get_member_keyword_colors),
	JS_CFUNC_DEF("add_color_region", 4, &code_highlighter_class_add_color_region),
	JS_CFUNC_DEF("remove_color_region", 1, &code_highlighter_class_remove_color_region),
	JS_CFUNC_DEF("has_color_region", 1, &code_highlighter_class_has_color_region),
	JS_CFUNC_DEF("set_color_regions", 1, &code_highlighter_class_set_color_regions),
	JS_CFUNC_DEF("clear_color_regions", 0, &code_highlighter_class_clear_color_regions),
	JS_CFUNC_DEF("get_color_regions", 0, &code_highlighter_class_get_color_regions),
	JS_CFUNC_DEF("set_function_color", 1, &code_highlighter_class_set_function_color),
	JS_CFUNC_DEF("get_function_color", 0, &code_highlighter_class_get_function_color),
	JS_CFUNC_DEF("set_number_color", 1, &code_highlighter_class_set_number_color),
	JS_CFUNC_DEF("get_number_color", 0, &code_highlighter_class_get_number_color),
	JS_CFUNC_DEF("set_symbol_color", 1, &code_highlighter_class_set_symbol_color),
	JS_CFUNC_DEF("get_symbol_color", 0, &code_highlighter_class_get_symbol_color),
	JS_CFUNC_DEF("set_member_variable_color", 1, &code_highlighter_class_set_member_variable_color),
	JS_CFUNC_DEF("get_member_variable_color", 0, &code_highlighter_class_get_member_variable_color),
};




static void define_code_highlighter_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "number_color"),
        JS_NewCFunction(ctx, code_highlighter_class_get_number_color, "get_number_color", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_number_color, "set_number_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "symbol_color"),
        JS_NewCFunction(ctx, code_highlighter_class_get_symbol_color, "get_symbol_color", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_symbol_color, "set_symbol_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "function_color"),
        JS_NewCFunction(ctx, code_highlighter_class_get_function_color, "get_function_color", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_function_color, "set_function_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "member_variable_color"),
        JS_NewCFunction(ctx, code_highlighter_class_get_member_variable_color, "get_member_variable_color", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_member_variable_color, "set_member_variable_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keyword_colors"),
        JS_NewCFunction(ctx, code_highlighter_class_get_keyword_colors, "get_keyword_colors", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_keyword_colors, "set_keyword_colors", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "member_keyword_colors"),
        JS_NewCFunction(ctx, code_highlighter_class_get_member_keyword_colors, "get_member_keyword_colors", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_member_keyword_colors, "set_member_keyword_colors", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_regions"),
        JS_NewCFunction(ctx, code_highlighter_class_get_color_regions, "get_color_regions", 0),
        JS_NewCFunction(ctx, code_highlighter_class_set_color_regions, "set_color_regions", 1),
        JS_PROP_GETSET
    );
}

static void define_code_highlighter_enum(JSContext *ctx, JSValue ctor) {
}

static int js_code_highlighter_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CodeHighlighter"] = class_id;
	classes_by_id[class_id] = "CodeHighlighter";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &code_highlighter_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SyntaxHighlighter"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_code_highlighter_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, code_highlighter_class_proto_funcs, _countof(code_highlighter_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, code_highlighter_class_constructor, "CodeHighlighter", 0, JS_CFUNC_constructor, 0);
	define_code_highlighter_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CodeHighlighter", ctor);

	return 0;
}

JSModuleDef *_js_init_code_highlighter_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/syntax_highlighter';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_code_highlighter_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CodeHighlighter");
	return m;
}

JSModuleDef *js_init_code_highlighter_module(JSContext *ctx) {
	return _js_init_code_highlighter_module(ctx, "@godot/classes/code_highlighter");
}

void __register_code_highlighter() {
	js_init_code_highlighter_module(js_context());
}

void register_code_highlighter() {
	__register_code_highlighter();
}