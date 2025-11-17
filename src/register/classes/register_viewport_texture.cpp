#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/viewport_texture.hpp>
using namespace godot;

static void viewport_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ViewportTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef viewport_texture_class_def = {
    "ViewportTexture",
    viewport_texture_class_finalizer
};

static JSValue viewport_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ViewportTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ViewportTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ViewportTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ViewportTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue viewport_texture_class_set_viewport_path_in_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ViewportTexture::set_viewport_path_in_scene, ctx, this_val, argc, argv);
};
static JSValue viewport_texture_class_get_viewport_path_in_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		ViewportTexture *obj = static_cast<ViewportTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_viewport_path_in_scene();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		ViewportTexture *js_proxy = static_cast<ViewportTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_viewport_path_in_scene(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry viewport_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_viewport_path_in_scene", 1, &viewport_texture_class_set_viewport_path_in_scene),
	JS_CFUNC_DEF("get_viewport_path_in_scene", 0, &viewport_texture_class_get_viewport_path_in_scene),
};




static void define_viewport_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "viewport_path"),
        JS_NewCFunction(ctx, viewport_texture_class_get_viewport_path_in_scene, "get_viewport_path_in_scene", 0),
        JS_NewCFunction(ctx, viewport_texture_class_set_viewport_path_in_scene, "set_viewport_path_in_scene", 1),
        JS_PROP_GETSET
    );
}

static void define_viewport_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_viewport_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ViewportTexture"] = class_id;
	classes_by_id[class_id] = "ViewportTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &viewport_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_viewport_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, viewport_texture_class_proto_funcs, _countof(viewport_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, viewport_texture_class_constructor, "ViewportTexture", 0, JS_CFUNC_constructor, 0);
	define_viewport_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ViewportTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_viewport_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_viewport_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ViewportTexture");
	return m;
}

JSModuleDef *js_init_viewport_texture_module(JSContext *ctx) {
	return _js_init_viewport_texture_module(ctx, "@godot/classes/viewport_texture");
}

void __register_viewport_texture() {
	js_init_viewport_texture_module(js_context());
}

void register_viewport_texture() {
	__register_viewport_texture();
}