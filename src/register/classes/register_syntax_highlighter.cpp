#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/text_edit.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/syntax_highlighter.hpp>
using namespace godot;

static void syntax_highlighter_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SyntaxHighlighter"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef syntax_highlighter_class_def = {
    "SyntaxHighlighter",
    syntax_highlighter_class_finalizer
};

static JSValue syntax_highlighter_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SyntaxHighlighter"];
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
        instance = memnew(SyntaxHighlighter);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue syntax_highlighter_class_get_line_syntax_highlighting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SyntaxHighlighter::get_line_syntax_highlighting, ctx, this_val, argc, argv);
};
static JSValue syntax_highlighter_class_update_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SyntaxHighlighter::update_cache, ctx, this_val, argc, argv);
};
static JSValue syntax_highlighter_class_clear_highlighting_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SyntaxHighlighter::clear_highlighting_cache, ctx, this_val, argc, argv);
};
static JSValue syntax_highlighter_class_get_text_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SyntaxHighlighter::get_text_edit, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry syntax_highlighter_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_line_syntax_highlighting", 1, &syntax_highlighter_class_get_line_syntax_highlighting),
	JS_CFUNC_DEF("update_cache", 0, &syntax_highlighter_class_update_cache),
	JS_CFUNC_DEF("clear_highlighting_cache", 0, &syntax_highlighter_class_clear_highlighting_cache),
	JS_CFUNC_DEF("get_text_edit", 0, &syntax_highlighter_class_get_text_edit),
};




static void define_syntax_highlighter_property(JSContext *ctx, JSValue proto) {
}

static void define_syntax_highlighter_enum(JSContext *ctx, JSValue ctor) {
}

static int js_syntax_highlighter_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SyntaxHighlighter"] = class_id;
	classes_by_id[class_id] = "SyntaxHighlighter";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &syntax_highlighter_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_syntax_highlighter_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, syntax_highlighter_class_proto_funcs, _countof(syntax_highlighter_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, syntax_highlighter_class_constructor, "SyntaxHighlighter", 0, JS_CFUNC_constructor, 0);
	define_syntax_highlighter_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SyntaxHighlighter", ctor);
	ctor_list["SyntaxHighlighter"] = ctor;

	return 0;
}

JSModuleDef *_js_init_syntax_highlighter_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_syntax_highlighter_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SyntaxHighlighter");
	return m;
}

JSModuleDef *js_init_syntax_highlighter_module(JSContext *ctx) {
	return _js_init_syntax_highlighter_module(ctx, "@godot/classes/syntax_highlighter");
}

void __register_syntax_highlighter() {
	js_init_syntax_highlighter_module(js_context());
}

void register_syntax_highlighter() {
	__register_syntax_highlighter();
}