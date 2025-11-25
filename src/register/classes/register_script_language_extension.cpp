#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/classes/script_language.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/script_language_extension.hpp>
using namespace godot;

static void script_language_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScriptLanguageExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_language_extension_class_def = {
    "ScriptLanguageExtension",
    script_language_extension_class_finalizer
};

static JSValue script_language_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScriptLanguageExtension"];
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
        instance = memnew(ScriptLanguageExtension);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_script_language_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_script_language_extension_enum(JSContext *ctx, JSValue ctor) {
	JSValue LookupResultType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_SCRIPT_LOCATION", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_CONSTANT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_PROPERTY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_METHOD", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_SIGNAL", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_ENUM", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_TBD_GLOBALSCOPE", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_CLASS_ANNOTATION", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_LOCAL_CONSTANT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_LOCAL_VARIABLE", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, LookupResultType_obj, "LOOKUP_RESULT_MAX", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, ctor, "LookupResultType", LookupResultType_obj);
	JSValue CodeCompletionLocation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_LOCAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_PARENT_MASK", JS_NewInt64(ctx, 256));
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_OTHER_USER_CODE", JS_NewInt64(ctx, 512));
	JS_SetPropertyStr(ctx, CodeCompletionLocation_obj, "LOCATION_OTHER", JS_NewInt64(ctx, 1024));
	JS_SetPropertyStr(ctx, ctor, "CodeCompletionLocation", CodeCompletionLocation_obj);
	JSValue CodeCompletionKind_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_CLASS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_FUNCTION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_SIGNAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_VARIABLE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_MEMBER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_ENUM", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_CONSTANT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_NODE_PATH", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_FILE_PATH", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_PLAIN_TEXT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, CodeCompletionKind_obj, "CODE_COMPLETION_KIND_MAX", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, ctor, "CodeCompletionKind", CodeCompletionKind_obj);
}

static int js_script_language_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScriptLanguageExtension"] = class_id;
	classes_by_id[class_id] = "ScriptLanguageExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_language_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ScriptLanguage"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_language_extension_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, script_language_extension_class_constructor, "ScriptLanguageExtension", 0, JS_CFUNC_constructor, 0);
	define_script_language_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScriptLanguageExtension", ctor);
	ctor_list["ScriptLanguageExtension"] = ctor;

	return 0;
}

JSModuleDef *_js_init_script_language_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/script_language';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_language_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScriptLanguageExtension");
	return m;
}

JSModuleDef *js_init_script_language_extension_module(JSContext *ctx) {
	return _js_init_script_language_extension_module(ctx, "@godot/classes/script_language_extension");
}

void __register_script_language_extension() {
	js_init_script_language_extension_module(js_context());
}

void register_script_language_extension() {
	__register_script_language_extension();
}