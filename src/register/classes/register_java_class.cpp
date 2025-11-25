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
#include <godot_cpp/classes/java_class.hpp>
using namespace godot;

static void java_class_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["JavaClass"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef java_class_class_def = {
    "JavaClass",
    java_class_class_finalizer
};

static JSValue java_class_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["JavaClass"];
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
        instance = memnew(JavaClass);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue java_class_class_get_java_class_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&JavaClass::get_java_class_name, ctx, this_val, argc, argv);
};
static JSValue java_class_class_get_java_method_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&JavaClass::get_java_method_list, ctx, this_val, argc, argv);
};
static JSValue java_class_class_get_java_parent_class(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&JavaClass::get_java_parent_class, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry java_class_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_java_class_name", 0, &java_class_class_get_java_class_name),
	JS_CFUNC_DEF("get_java_method_list", 0, &java_class_class_get_java_method_list),
	JS_CFUNC_DEF("get_java_parent_class", 0, &java_class_class_get_java_parent_class),
};




static void define_java_class_property(JSContext *ctx, JSValue proto) {
}

static void define_java_class_enum(JSContext *ctx, JSValue ctor) {
}

static int js_java_class_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["JavaClass"] = class_id;
	classes_by_id[class_id] = "JavaClass";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &java_class_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_java_class_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, java_class_class_proto_funcs, _countof(java_class_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, java_class_class_constructor, "JavaClass", 0, JS_CFUNC_constructor, 0);
	define_java_class_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "JavaClass", ctor);
	ctor_list["JavaClass"] = ctor;

	return 0;
}

JSModuleDef *_js_init_java_class_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_java_class_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "JavaClass");
	return m;
}

JSModuleDef *js_init_java_class_module(JSContext *ctx) {
	return _js_init_java_class_module(ctx, "@godot/classes/java_class");
}

void __register_java_class() {
	js_init_java_class_module(js_context());
}

void register_java_class() {
	__register_java_class();
}