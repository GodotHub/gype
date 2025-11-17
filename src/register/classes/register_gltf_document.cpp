#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gltf_document_extension.hpp>
#include <godot_cpp/classes/gltf_object_model_property.hpp>
#include <godot_cpp/classes/gltf_state.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_document.hpp>
using namespace godot;

static void gltf_document_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFDocument"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_document_class_def = {
    "GLTFDocument",
    gltf_document_class_finalizer
};

static JSValue gltf_document_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFDocument"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFDocument *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFDocument *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFDocument);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_document_class_set_image_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFDocument::set_image_format, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_image_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		GLTFDocument *obj = static_cast<GLTFDocument *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_image_format();
	};
	proxy->setter = [this_val](const String &value) -> void {
		GLTFDocument *js_proxy = static_cast<GLTFDocument *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_image_format(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_document_class_set_lossy_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFDocument::set_lossy_quality, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_lossy_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFDocument::get_lossy_quality, ctx, this_val, argc, argv);
}
static JSValue gltf_document_class_set_fallback_image_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFDocument::set_fallback_image_format, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_fallback_image_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		GLTFDocument *obj = static_cast<GLTFDocument *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_fallback_image_format();
	};
	proxy->setter = [this_val](const String &value) -> void {
		GLTFDocument *js_proxy = static_cast<GLTFDocument *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_fallback_image_format(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_document_class_set_fallback_image_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFDocument::set_fallback_image_quality, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_fallback_image_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFDocument::get_fallback_image_quality, ctx, this_val, argc, argv);
}
static JSValue gltf_document_class_set_root_node_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFDocument::set_root_node_mode, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_root_node_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFDocument::get_root_node_mode, ctx, this_val, argc, argv);
}
static JSValue gltf_document_class_set_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFDocument::set_visibility_mode, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFDocument::get_visibility_mode, ctx, this_val, argc, argv);
}
static JSValue gltf_document_class_append_from_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFDocument::append_from_file, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_append_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFDocument::append_from_buffer, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_append_from_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFDocument::append_from_scene, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_generate_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFDocument::generate_scene, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_generate_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFDocument::generate_buffer, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_write_to_filesystem(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFDocument::write_to_filesystem, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_import_object_model_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFDocument::import_object_model_property, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_export_object_model_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFDocument::export_object_model_property, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_register_gltf_document_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&GLTFDocument::register_gltf_document_extension, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_unregister_gltf_document_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&GLTFDocument::unregister_gltf_document_extension, ctx, this_val, argc, argv);
};
static JSValue gltf_document_class_get_supported_gltf_extensions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFDocument::get_supported_gltf_extensions, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gltf_document_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_image_format", 1, &gltf_document_class_set_image_format),
	JS_CFUNC_DEF("get_image_format", 0, &gltf_document_class_get_image_format),
	JS_CFUNC_DEF("set_lossy_quality", 1, &gltf_document_class_set_lossy_quality),
	JS_CFUNC_DEF("get_lossy_quality", 0, &gltf_document_class_get_lossy_quality),
	JS_CFUNC_DEF("set_fallback_image_format", 1, &gltf_document_class_set_fallback_image_format),
	JS_CFUNC_DEF("get_fallback_image_format", 0, &gltf_document_class_get_fallback_image_format),
	JS_CFUNC_DEF("set_fallback_image_quality", 1, &gltf_document_class_set_fallback_image_quality),
	JS_CFUNC_DEF("get_fallback_image_quality", 0, &gltf_document_class_get_fallback_image_quality),
	JS_CFUNC_DEF("set_root_node_mode", 1, &gltf_document_class_set_root_node_mode),
	JS_CFUNC_DEF("get_root_node_mode", 0, &gltf_document_class_get_root_node_mode),
	JS_CFUNC_DEF("set_visibility_mode", 1, &gltf_document_class_set_visibility_mode),
	JS_CFUNC_DEF("get_visibility_mode", 0, &gltf_document_class_get_visibility_mode),
	JS_CFUNC_DEF("append_from_file", 4, &gltf_document_class_append_from_file),
	JS_CFUNC_DEF("append_from_buffer", 4, &gltf_document_class_append_from_buffer),
	JS_CFUNC_DEF("append_from_scene", 3, &gltf_document_class_append_from_scene),
	JS_CFUNC_DEF("generate_scene", 4, &gltf_document_class_generate_scene),
	JS_CFUNC_DEF("generate_buffer", 1, &gltf_document_class_generate_buffer),
	JS_CFUNC_DEF("write_to_filesystem", 2, &gltf_document_class_write_to_filesystem),
};

static const JSCFunctionListEntry gltf_document_class_static_funcs[] = {
	JS_CFUNC_DEF("import_object_model_property", 2, &gltf_document_class_import_object_model_property),
	JS_CFUNC_DEF("export_object_model_property", 4, &gltf_document_class_export_object_model_property),
	JS_CFUNC_DEF("register_gltf_document_extension", 2, &gltf_document_class_register_gltf_document_extension),
	JS_CFUNC_DEF("unregister_gltf_document_extension", 1, &gltf_document_class_unregister_gltf_document_extension),
	JS_CFUNC_DEF("get_supported_gltf_extensions", 0, &gltf_document_class_get_supported_gltf_extensions),
};



static void define_gltf_document_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "image_format"),
        JS_NewCFunction(ctx, gltf_document_class_get_image_format, "get_image_format", 0),
        JS_NewCFunction(ctx, gltf_document_class_set_image_format, "set_image_format", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lossy_quality"),
        JS_NewCFunction(ctx, gltf_document_class_get_lossy_quality, "get_lossy_quality", 0),
        JS_NewCFunction(ctx, gltf_document_class_set_lossy_quality, "set_lossy_quality", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fallback_image_format"),
        JS_NewCFunction(ctx, gltf_document_class_get_fallback_image_format, "get_fallback_image_format", 0),
        JS_NewCFunction(ctx, gltf_document_class_set_fallback_image_format, "set_fallback_image_format", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fallback_image_quality"),
        JS_NewCFunction(ctx, gltf_document_class_get_fallback_image_quality, "get_fallback_image_quality", 0),
        JS_NewCFunction(ctx, gltf_document_class_set_fallback_image_quality, "set_fallback_image_quality", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root_node_mode"),
        JS_NewCFunction(ctx, gltf_document_class_get_root_node_mode, "get_root_node_mode", 0),
        JS_NewCFunction(ctx, gltf_document_class_set_root_node_mode, "set_root_node_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_mode"),
        JS_NewCFunction(ctx, gltf_document_class_get_visibility_mode, "get_visibility_mode", 0),
        JS_NewCFunction(ctx, gltf_document_class_set_visibility_mode, "set_visibility_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_document_enum(JSContext *ctx, JSValue ctor) {
	JSValue RootNodeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RootNodeMode_obj, "ROOT_NODE_MODE_SINGLE_ROOT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RootNodeMode_obj, "ROOT_NODE_MODE_KEEP_ROOT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RootNodeMode_obj, "ROOT_NODE_MODE_MULTI_ROOT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "RootNodeMode", RootNodeMode_obj);
	JSValue VisibilityMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_MODE_INCLUDE_REQUIRED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_MODE_INCLUDE_OPTIONAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_MODE_EXCLUDE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "VisibilityMode", VisibilityMode_obj);
}

static int js_gltf_document_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFDocument"] = class_id;
	classes_by_id[class_id] = "GLTFDocument";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_document_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_document_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_document_class_proto_funcs, _countof(gltf_document_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_document_class_constructor, "GLTFDocument", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, gltf_document_class_static_funcs, _countof(gltf_document_class_static_funcs));
	define_gltf_document_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFDocument", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_document_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_document_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFDocument");
	return m;
}

JSModuleDef *js_init_gltf_document_module(JSContext *ctx) {
	return _js_init_gltf_document_module(ctx, "@godot/classes/gltf_document");
}

void __register_gltf_document() {
	js_init_gltf_document_module(js_context());
}

void register_gltf_document() {
	__register_gltf_document();
}