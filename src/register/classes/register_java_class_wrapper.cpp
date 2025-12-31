#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/java_class.hpp>
#include <godot_cpp/classes/java_object.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/java_class_wrapper.hpp>


using namespace godot;

static void java_class_wrapper_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef java_class_wrapper_class_def = {
	"_JavaClassWrapper",
	java_class_wrapper_class_finalizer
};

static JSValue java_class_wrapper_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_JavaClassWrapper"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	JavaClassWrapper *java_class_wrapper_class = JavaClassWrapper::get_singleton();
	if (!java_class_wrapper_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(java_class_wrapper_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue java_class_wrapper_class_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaClassWrapper::wrap, ctx, this_val, argc, argv);
};
static JSValue java_class_wrapper_class_get_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaClassWrapper::get_exception, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry java_class_wrapper_class_proto_funcs[] = {
	JS_CFUNC_DEF("wrap", 1, &java_class_wrapper_class_wrap),
	JS_CFUNC_DEF("get_exception", 0, &java_class_wrapper_class_get_exception),
};




static int js_java_class_wrapper_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_JavaClassWrapper"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &java_class_wrapper_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, java_class_wrapper_class_proto_funcs, _countof(java_class_wrapper_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, java_class_wrapper_class_constructor, "_JavaClassWrapper", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "JavaClassWrapper", singleton);

	return 0;
}

JSModuleDef *_js_init_java_class_wrapper_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_java_class_wrapper_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "JavaClassWrapper");
	return m;
}

void register_java_class_wrapper() {
	_js_init_java_class_wrapper_module(js_context(), "@godot/classes/java_class_wrapper");
}