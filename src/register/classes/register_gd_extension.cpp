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
#include <godot_cpp/classes/gd_extension.hpp>
using namespace godot;

static void gd_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GDExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef gd_extension_class_def = {
    "GDExtension",
    gd_extension_class_finalizer
};

static JSValue gd_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GDExtension"];
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
        instance = memnew(GDExtension);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gd_extension_class_is_library_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GDExtension::is_library_open, ctx, this_val, argc, argv);
};
static JSValue gd_extension_class_get_minimum_library_initialization_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GDExtension::get_minimum_library_initialization_level, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gd_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_library_open", 0, &gd_extension_class_is_library_open),
	JS_CFUNC_DEF("get_minimum_library_initialization_level", 0, &gd_extension_class_get_minimum_library_initialization_level),
};




static void define_gd_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_gd_extension_enum(JSContext *ctx, JSValue ctor) {
	JSValue InitializationLevel_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, InitializationLevel_obj, "INITIALIZATION_LEVEL_CORE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InitializationLevel_obj, "INITIALIZATION_LEVEL_SERVERS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InitializationLevel_obj, "INITIALIZATION_LEVEL_SCENE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, InitializationLevel_obj, "INITIALIZATION_LEVEL_EDITOR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "InitializationLevel", InitializationLevel_obj);
}

static int js_gd_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GDExtension"] = class_id;
	classes_by_id[class_id] = "GDExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gd_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gd_extension_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gd_extension_class_proto_funcs, _countof(gd_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gd_extension_class_constructor, "GDExtension", 0, JS_CFUNC_constructor, 0);
	define_gd_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GDExtension", ctor);
	ctor_list["GDExtension"] = ctor;

	return 0;
}

JSModuleDef *_js_init_gd_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gd_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GDExtension");
	return m;
}

JSModuleDef *js_init_gd_extension_module(JSContext *ctx) {
	return _js_init_gd_extension_module(ctx, "@godot/classes/gd_extension");
}

void __register_gd_extension() {
	js_init_gd_extension_module(js_context());
}

void register_gd_extension() {
	__register_gd_extension();
}