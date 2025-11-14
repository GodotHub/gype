#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/jni_singleton.hpp>
using namespace godot;

static void jni_singleton_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["JNISingleton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef jni_singleton_class_def = {
    "JNISingleton",
    jni_singleton_class_finalizer
};

static JSValue jni_singleton_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["JNISingleton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    JNISingleton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<JNISingleton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(JNISingleton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}






static void define_jni_singleton_property(JSContext *ctx, JSValue proto) {
}

static void define_jni_singleton_enum(JSContext *ctx, JSValue proto) {
}

static int js_jni_singleton_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["JNISingleton"] = class_id;
	classes_by_id[class_id] = "JNISingleton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &jni_singleton_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_jni_singleton_property(ctx, proto);
	define_jni_singleton_enum(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, jni_singleton_class_constructor, "JNISingleton", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "JNISingleton", ctor);

	return 0;
}

JSModuleDef *_js_init_jni_singleton_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_jni_singleton_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "JNISingleton");
	return m;
}

JSModuleDef *js_init_jni_singleton_module(JSContext *ctx) {
	return _js_init_jni_singleton_module(ctx, "@godot/classes/jni_singleton");
}

void __register_jni_singleton() {
	js_init_jni_singleton_module(js_context());
}

void register_jni_singleton() {
	__register_jni_singleton();
}