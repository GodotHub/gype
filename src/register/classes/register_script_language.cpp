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
#include <godot_cpp/classes/script_language.hpp>
using namespace godot;

static void script_language_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScriptLanguage"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_language_class_def = {
    "ScriptLanguage",
    script_language_class_finalizer
};

static JSValue script_language_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScriptLanguage"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ScriptLanguage *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ScriptLanguage *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ScriptLanguage);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}






static void define_script_language_property(JSContext *ctx, JSValue proto) {
}

static void define_script_language_enum(JSContext *ctx, JSValue ctor) {
	JSValue ScriptNameCasing_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ScriptNameCasing_obj, "SCRIPT_NAME_CASING_AUTO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ScriptNameCasing_obj, "SCRIPT_NAME_CASING_PASCAL_CASE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ScriptNameCasing_obj, "SCRIPT_NAME_CASING_SNAKE_CASE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ScriptNameCasing_obj, "SCRIPT_NAME_CASING_KEBAB_CASE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ScriptNameCasing_obj, "SCRIPT_NAME_CASING_CAMEL_CASE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "ScriptNameCasing", ScriptNameCasing_obj);
}

static int js_script_language_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScriptLanguage"] = class_id;
	classes_by_id[class_id] = "ScriptLanguage";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_language_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_language_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, script_language_class_constructor, "ScriptLanguage", 0, JS_CFUNC_constructor, 0);
	define_script_language_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScriptLanguage", ctor);

	return 0;
}

JSModuleDef *_js_init_script_language_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_language_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScriptLanguage");
	return m;
}

JSModuleDef *js_init_script_language_module(JSContext *ctx) {
	return _js_init_script_language_module(ctx, "@godot/classes/script_language");
}

void __register_script_language() {
	js_init_script_language_module(js_context());
}

void register_script_language() {
	__register_script_language();
}