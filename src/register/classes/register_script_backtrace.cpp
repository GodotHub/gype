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
#include <godot_cpp/classes/script_backtrace.hpp>
using namespace godot;

static void script_backtrace_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScriptBacktrace"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_backtrace_class_def = {
    "ScriptBacktrace",
    script_backtrace_class_finalizer
};

static JSValue script_backtrace_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScriptBacktrace"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ScriptBacktrace *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ScriptBacktrace *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ScriptBacktrace);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue script_backtrace_class_get_language_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_language_name, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::is_empty, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_frame_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_frame_count, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_frame_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_frame_function, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_frame_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_frame_file, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_frame_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_frame_line, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_global_variable_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_global_variable_count, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_global_variable_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_global_variable_name, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_global_variable_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_global_variable_value, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_local_variable_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_local_variable_count, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_local_variable_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_local_variable_name, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_local_variable_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_local_variable_value, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_member_variable_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_member_variable_count, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_member_variable_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_member_variable_name, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_get_member_variable_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::get_member_variable_value, ctx, this_val, argc, argv);
};
static JSValue script_backtrace_class_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptBacktrace::format, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry script_backtrace_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_language_name", 0, &script_backtrace_class_get_language_name),
	JS_CFUNC_DEF("is_empty", 0, &script_backtrace_class_is_empty),
	JS_CFUNC_DEF("get_frame_count", 0, &script_backtrace_class_get_frame_count),
	JS_CFUNC_DEF("get_frame_function", 1, &script_backtrace_class_get_frame_function),
	JS_CFUNC_DEF("get_frame_file", 1, &script_backtrace_class_get_frame_file),
	JS_CFUNC_DEF("get_frame_line", 1, &script_backtrace_class_get_frame_line),
	JS_CFUNC_DEF("get_global_variable_count", 0, &script_backtrace_class_get_global_variable_count),
	JS_CFUNC_DEF("get_global_variable_name", 1, &script_backtrace_class_get_global_variable_name),
	JS_CFUNC_DEF("get_global_variable_value", 1, &script_backtrace_class_get_global_variable_value),
	JS_CFUNC_DEF("get_local_variable_count", 1, &script_backtrace_class_get_local_variable_count),
	JS_CFUNC_DEF("get_local_variable_name", 2, &script_backtrace_class_get_local_variable_name),
	JS_CFUNC_DEF("get_local_variable_value", 2, &script_backtrace_class_get_local_variable_value),
	JS_CFUNC_DEF("get_member_variable_count", 1, &script_backtrace_class_get_member_variable_count),
	JS_CFUNC_DEF("get_member_variable_name", 2, &script_backtrace_class_get_member_variable_name),
	JS_CFUNC_DEF("get_member_variable_value", 2, &script_backtrace_class_get_member_variable_value),
	JS_CFUNC_DEF("format", 2, &script_backtrace_class_format),
};




static void define_script_backtrace_property(JSContext *ctx, JSValue proto) {
}

static void define_script_backtrace_enum(JSContext *ctx, JSValue proto) {
}

static int js_script_backtrace_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScriptBacktrace"] = class_id;
	classes_by_id[class_id] = "ScriptBacktrace";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_backtrace_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_backtrace_property(ctx, proto);
	define_script_backtrace_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, script_backtrace_class_proto_funcs, _countof(script_backtrace_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, script_backtrace_class_constructor, "ScriptBacktrace", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScriptBacktrace", ctor);

	return 0;
}

JSModuleDef *_js_init_script_backtrace_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_backtrace_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScriptBacktrace");
	return m;
}

JSModuleDef *js_init_script_backtrace_module(JSContext *ctx) {
	return _js_init_script_backtrace_module(ctx, "@godot/classes/script_backtrace");
}

void __register_script_backtrace() {
	js_init_script_backtrace_module(js_context());
}

void register_script_backtrace() {
	__register_script_backtrace();
}