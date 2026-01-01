#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/expression.hpp>
using namespace godot;

static void expression_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Expression"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef expression_class_def = {
    "Expression",
    expression_class_finalizer
};

static JSValue expression_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Expression"];
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
        instance = memnew(Expression);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue expression_class_parse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Expression::parse, ctx, this_val, argc, argv);
};
static JSValue expression_class_execute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Expression::execute, ctx, this_val, argc, argv);
};
static JSValue expression_class_has_execute_failed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Expression::has_execute_failed, ctx, this_val, argc, argv);
};
static JSValue expression_class_get_error_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Expression::get_error_text, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry expression_class_proto_funcs[] = {
	JS_CFUNC_DEF("parse", 2, &expression_class_parse),
	JS_CFUNC_DEF("execute", 4, &expression_class_execute),
	JS_CFUNC_DEF("has_execute_failed", 0, &expression_class_has_execute_failed),
	JS_CFUNC_DEF("get_error_text", 0, &expression_class_get_error_text),
};




static void define_expression_property(JSContext *ctx, JSValue proto) {
}

static void define_expression_enum(JSContext *ctx, JSValue ctor) {
}

static int js_expression_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Expression"] = class_id;
	classes_by_id[class_id] = "Expression";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &expression_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_expression_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, expression_class_proto_funcs, _countof(expression_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, expression_class_constructor, "Expression", 0, JS_CFUNC_constructor, 0);
	define_expression_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Expression", ctor);
	ctor_list["Expression"] = ctor;

	return 0;
}

JSModuleDef *_js_init_expression_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_expression_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Expression");
	return m;
}

JSModuleDef *js_init_expression_module(JSContext *ctx) {
	return _js_init_expression_module(ctx, "@godot/classes/expression");
}

void __register_expression() {
	js_init_expression_module(js_context());
}

void register_expression() {
	__register_expression();
}