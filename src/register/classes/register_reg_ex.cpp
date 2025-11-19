#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/reg_ex_match.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/reg_ex.hpp>
using namespace godot;

static void reg_ex_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RegEx"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef reg_ex_class_def = {
    "RegEx",
    reg_ex_class_finalizer
};

static JSValue reg_ex_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RegEx"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RegEx *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RegEx *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RegEx);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue reg_ex_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RegEx::clear, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_compile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RegEx::compile, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_search(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::search, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_search_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::search_all, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_sub(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::sub, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::is_valid, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_get_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::get_pattern, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_get_group_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::get_group_count, ctx, this_val, argc, argv);
};
static JSValue reg_ex_class_get_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegEx::get_names, ctx, this_val, argc, argv);
};


static JSValue reg_ex_class_create_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&RegEx::create_from_string, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry reg_ex_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &reg_ex_class_clear),
	JS_CFUNC_DEF("compile", 2, &reg_ex_class_compile),
	JS_CFUNC_DEF("search", 3, &reg_ex_class_search),
	JS_CFUNC_DEF("search_all", 3, &reg_ex_class_search_all),
	JS_CFUNC_DEF("sub", 5, &reg_ex_class_sub),
	JS_CFUNC_DEF("is_valid", 0, &reg_ex_class_is_valid),
	JS_CFUNC_DEF("get_pattern", 0, &reg_ex_class_get_pattern),
	JS_CFUNC_DEF("get_group_count", 0, &reg_ex_class_get_group_count),
	JS_CFUNC_DEF("get_names", 0, &reg_ex_class_get_names),
};

static const JSCFunctionListEntry reg_ex_class_static_funcs[] = {
	JS_CFUNC_DEF("create_from_string", 2, &reg_ex_class_create_from_string),
};



static void define_reg_ex_property(JSContext *ctx, JSValue proto) {
}

static void define_reg_ex_enum(JSContext *ctx, JSValue ctor) {
}

static int js_reg_ex_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RegEx"] = class_id;
	classes_by_id[class_id] = "RegEx";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &reg_ex_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_reg_ex_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, reg_ex_class_proto_funcs, _countof(reg_ex_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, reg_ex_class_constructor, "RegEx", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, reg_ex_class_static_funcs, _countof(reg_ex_class_static_funcs));
	define_reg_ex_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RegEx", ctor);

	return 0;
}

JSModuleDef *_js_init_reg_ex_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_reg_ex_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RegEx");
	return m;
}

JSModuleDef *js_init_reg_ex_module(JSContext *ctx) {
	return _js_init_reg_ex_module(ctx, "@godot/classes/reg_ex");
}

void __register_reg_ex() {
	js_init_reg_ex_module(js_context());
}

void register_reg_ex() {
	__register_reg_ex();
}