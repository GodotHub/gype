#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/image_format_loader.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/image_format_loader_extension.hpp>
using namespace godot;

static void image_format_loader_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ImageFormatLoaderExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef image_format_loader_extension_class_def = {
    "ImageFormatLoaderExtension",
    image_format_loader_extension_class_finalizer
};

static JSValue image_format_loader_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ImageFormatLoaderExtension"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ImageFormatLoaderExtension *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ImageFormatLoaderExtension *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ImageFormatLoaderExtension);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue image_format_loader_extension_class_add_format_loader(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImageFormatLoaderExtension::add_format_loader, ctx, this_val, argc, argv);
};
static JSValue image_format_loader_extension_class_remove_format_loader(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImageFormatLoaderExtension::remove_format_loader, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry image_format_loader_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_format_loader", 0, &image_format_loader_extension_class_add_format_loader),
	JS_CFUNC_DEF("remove_format_loader", 0, &image_format_loader_extension_class_remove_format_loader),
};




static void define_image_format_loader_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_image_format_loader_extension_enum(JSContext *ctx, JSValue ctor) {
}

static int js_image_format_loader_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ImageFormatLoaderExtension"] = class_id;
	classes_by_id[class_id] = "ImageFormatLoaderExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &image_format_loader_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ImageFormatLoader"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_image_format_loader_extension_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, image_format_loader_extension_class_proto_funcs, _countof(image_format_loader_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, image_format_loader_extension_class_constructor, "ImageFormatLoaderExtension", 0, JS_CFUNC_constructor, 0);
	define_image_format_loader_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ImageFormatLoaderExtension", ctor);

	return 0;
}

JSModuleDef *_js_init_image_format_loader_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/image_format_loader';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_image_format_loader_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ImageFormatLoaderExtension");
	return m;
}

JSModuleDef *js_init_image_format_loader_extension_module(JSContext *ctx) {
	return _js_init_image_format_loader_extension_module(ctx, "@godot/classes/image_format_loader_extension");
}

void __register_image_format_loader_extension() {
	js_init_image_format_loader_extension_module(js_context());
}

void register_image_format_loader_extension() {
	__register_image_format_loader_extension();
}