#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/translation.hpp>
using namespace godot;

static void translation_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Translation"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef translation_class_def = {
    "Translation",
    translation_class_finalizer
};

static JSValue translation_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Translation"];
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
        instance = memnew(Translation);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue translation_class_set_locale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Translation::set_locale, ctx, this_val, argc, argv);
};
static JSValue translation_class_get_locale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Translation::get_locale, ctx, this_val, argc, argv);
}
static JSValue translation_class_add_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Translation::add_message, ctx, this_val, argc, argv);
};
static JSValue translation_class_add_plural_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Translation::add_plural_message, ctx, this_val, argc, argv);
};
static JSValue translation_class_get_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Translation::get_message, ctx, this_val, argc, argv);
};
static JSValue translation_class_get_plural_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Translation::get_plural_message, ctx, this_val, argc, argv);
};
static JSValue translation_class_erase_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Translation::erase_message, ctx, this_val, argc, argv);
};
static JSValue translation_class_get_message_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Translation::get_message_list, ctx, this_val, argc, argv);
};
static JSValue translation_class_get_translated_message_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Translation::get_translated_message_list, ctx, this_val, argc, argv);
};
static JSValue translation_class_get_message_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Translation::get_message_count, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry translation_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_locale", 1, &translation_class_set_locale),
	JS_CFUNC_DEF("get_locale", 0, &translation_class_get_locale),
	JS_CFUNC_DEF("add_message", 3, &translation_class_add_message),
	JS_CFUNC_DEF("add_plural_message", 3, &translation_class_add_plural_message),
	JS_CFUNC_DEF("get_message", 2, &translation_class_get_message),
	JS_CFUNC_DEF("get_plural_message", 4, &translation_class_get_plural_message),
	JS_CFUNC_DEF("erase_message", 2, &translation_class_erase_message),
	JS_CFUNC_DEF("get_message_list", 0, &translation_class_get_message_list),
	JS_CFUNC_DEF("get_translated_message_list", 0, &translation_class_get_translated_message_list),
	JS_CFUNC_DEF("get_message_count", 0, &translation_class_get_message_count),
};




static void define_translation_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "locale"),
        JS_NewCFunction(ctx, translation_class_get_locale, "get_locale", 0),
        JS_NewCFunction(ctx, translation_class_set_locale, "set_locale", 1),
        JS_PROP_GETSET
    );
}

static void define_translation_enum(JSContext *ctx, JSValue ctor) {
}

static int js_translation_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Translation"] = class_id;
	classes_by_id[class_id] = "Translation";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &translation_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_translation_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, translation_class_proto_funcs, _countof(translation_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, translation_class_constructor, "Translation", 0, JS_CFUNC_constructor, 0);
	define_translation_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Translation", ctor);
	ctor_list["Translation"] = ctor;

	return 0;
}

JSModuleDef *_js_init_translation_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_translation_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Translation");
	return m;
}

JSModuleDef *js_init_translation_module(JSContext *ctx) {
	return _js_init_translation_module(ctx, "@godot/classes/translation");
}

void __register_translation() {
	js_init_translation_module(js_context());
}

void register_translation() {
	__register_translation();
}