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
#include <godot_cpp/classes/image_format_loader.hpp>
using namespace godot;

static void image_format_loader_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ImageFormatLoader"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef image_format_loader_class_def = {
    "ImageFormatLoader",
    image_format_loader_class_finalizer
};

static JSValue image_format_loader_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ImageFormatLoader"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ImageFormatLoader *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ImageFormatLoader *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ImageFormatLoader);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_image_format_loader_property(JSContext *ctx, JSValue proto) {
}

static void define_image_format_loader_enum(JSContext *ctx, JSValue ctor) {
	JSValue LoaderFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LoaderFlags_obj, "FLAG_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LoaderFlags_obj, "FLAG_FORCE_LINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LoaderFlags_obj, "FLAG_CONVERT_COLORS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "LoaderFlags", LoaderFlags_obj);
}

static int js_image_format_loader_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ImageFormatLoader"] = class_id;
	classes_by_id[class_id] = "ImageFormatLoader";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &image_format_loader_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_image_format_loader_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, image_format_loader_class_constructor, "ImageFormatLoader", 0, JS_CFUNC_constructor, 0);
	define_image_format_loader_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ImageFormatLoader", ctor);

	return 0;
}

JSModuleDef *_js_init_image_format_loader_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_image_format_loader_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ImageFormatLoader");
	return m;
}

JSModuleDef *js_init_image_format_loader_module(JSContext *ctx) {
	return _js_init_image_format_loader_module(ctx, "@godot/classes/image_format_loader");
}

void __register_image_format_loader() {
	js_init_image_format_loader_module(js_context());
}

void register_image_format_loader() {
	__register_image_format_loader();
}