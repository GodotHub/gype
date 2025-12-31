#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/marshalls.hpp>


using namespace godot;

static void marshalls_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef marshalls_class_def = {
	"_Marshalls",
	marshalls_class_finalizer
};

static JSValue marshalls_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_Marshalls"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Marshalls *marshalls_class = Marshalls::get_singleton();
	if (!marshalls_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(marshalls_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue marshalls_class_variant_to_base64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Marshalls::variant_to_base64, ctx, this_val, argc, argv);
};
static JSValue marshalls_class_base64_to_variant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Marshalls::base64_to_variant, ctx, this_val, argc, argv);
};
static JSValue marshalls_class_raw_to_base64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Marshalls::raw_to_base64, ctx, this_val, argc, argv);
};
static JSValue marshalls_class_base64_to_raw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Marshalls::base64_to_raw, ctx, this_val, argc, argv);
};
static JSValue marshalls_class_utf8_to_base64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Marshalls::utf8_to_base64, ctx, this_val, argc, argv);
};
static JSValue marshalls_class_base64_to_utf8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Marshalls::base64_to_utf8, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry marshalls_class_proto_funcs[] = {
	JS_CFUNC_DEF("variant_to_base64", 2, &marshalls_class_variant_to_base64),
	JS_CFUNC_DEF("base64_to_variant", 2, &marshalls_class_base64_to_variant),
	JS_CFUNC_DEF("raw_to_base64", 1, &marshalls_class_raw_to_base64),
	JS_CFUNC_DEF("base64_to_raw", 1, &marshalls_class_base64_to_raw),
	JS_CFUNC_DEF("utf8_to_base64", 1, &marshalls_class_utf8_to_base64),
	JS_CFUNC_DEF("base64_to_utf8", 1, &marshalls_class_base64_to_utf8),
};




static int js_marshalls_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_Marshalls"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &marshalls_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, marshalls_class_proto_funcs, _countof(marshalls_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, marshalls_class_constructor, "_Marshalls", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "Marshalls", singleton);

	return 0;
}

JSModuleDef *_js_init_marshalls_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_marshalls_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Marshalls");
	return m;
}

void register_marshalls() {
	_js_init_marshalls_module(js_context(), "@godot/classes/marshalls");
}