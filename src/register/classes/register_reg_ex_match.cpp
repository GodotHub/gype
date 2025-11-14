#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/reg_ex_match.hpp>
using namespace godot;

static void reg_ex_match_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RegExMatch"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef reg_ex_match_class_def = {
    "RegExMatch",
    reg_ex_match_class_finalizer
};

static JSValue reg_ex_match_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RegExMatch"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RegExMatch *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RegExMatch *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RegExMatch);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue reg_ex_match_class_get_subject(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		RegExMatch *obj = static_cast<RegExMatch *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_subject();
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
static JSValue reg_ex_match_class_get_group_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegExMatch::get_group_count, ctx, this_val, argc, argv);
};
static JSValue reg_ex_match_class_get_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		RegExMatch *obj = static_cast<RegExMatch *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_names();
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
static JSValue reg_ex_match_class_get_strings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		RegExMatch *obj = static_cast<RegExMatch *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_strings();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue reg_ex_match_class_get_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegExMatch::get_string, ctx, this_val, argc, argv);
};
static JSValue reg_ex_match_class_get_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegExMatch::get_start, ctx, this_val, argc, argv);
};
static JSValue reg_ex_match_class_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RegExMatch::get_end, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry reg_ex_match_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_subject", 0, &reg_ex_match_class_get_subject),
	JS_CFUNC_DEF("get_group_count", 0, &reg_ex_match_class_get_group_count),
	JS_CFUNC_DEF("get_names", 0, &reg_ex_match_class_get_names),
	JS_CFUNC_DEF("get_strings", 0, &reg_ex_match_class_get_strings),
	JS_CFUNC_DEF("get_string", 1, &reg_ex_match_class_get_string),
	JS_CFUNC_DEF("get_start", 1, &reg_ex_match_class_get_start),
	JS_CFUNC_DEF("get_end", 1, &reg_ex_match_class_get_end),
};




static void define_reg_ex_match_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subject"),
        JS_NewCFunction(ctx, reg_ex_match_class_get_subject, "get_subject", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "names"),
        JS_NewCFunction(ctx, reg_ex_match_class_get_names, "get_names", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "strings"),
        JS_NewCFunction(ctx, reg_ex_match_class_get_strings, "get_strings", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
}

static void define_reg_ex_match_enum(JSContext *ctx, JSValue proto) {
}

static int js_reg_ex_match_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RegExMatch"] = class_id;
	classes_by_id[class_id] = "RegExMatch";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &reg_ex_match_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_reg_ex_match_property(ctx, proto);
	define_reg_ex_match_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, reg_ex_match_class_proto_funcs, _countof(reg_ex_match_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, reg_ex_match_class_constructor, "RegExMatch", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RegExMatch", ctor);

	return 0;
}

JSModuleDef *_js_init_reg_ex_match_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_reg_ex_match_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RegExMatch");
	return m;
}

JSModuleDef *js_init_reg_ex_match_module(JSContext *ctx) {
	return _js_init_reg_ex_match_module(ctx, "@godot/classes/reg_ex_match");
}

void __register_reg_ex_match() {
	js_init_reg_ex_match_module(js_context());
}

void register_reg_ex_match() {
	__register_reg_ex_match();
}