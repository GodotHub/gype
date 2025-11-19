#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture_layered.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/placeholder_texture_layered.hpp>
using namespace godot;

static void placeholder_texture_layered_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PlaceholderTextureLayered"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef placeholder_texture_layered_class_def = {
    "PlaceholderTextureLayered",
    placeholder_texture_layered_class_finalizer
};

static JSValue placeholder_texture_layered_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PlaceholderTextureLayered"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PlaceholderTextureLayered *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PlaceholderTextureLayered *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PlaceholderTextureLayered);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue placeholder_texture_layered_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaceholderTextureLayered::set_size, ctx, this_val, argc, argv);
};
static JSValue placeholder_texture_layered_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		PlaceholderTextureLayered *obj = static_cast<PlaceholderTextureLayered *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		PlaceholderTextureLayered *js_proxy = static_cast<PlaceholderTextureLayered *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue placeholder_texture_layered_class_set_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaceholderTextureLayered::set_layers, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry placeholder_texture_layered_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &placeholder_texture_layered_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &placeholder_texture_layered_class_get_size),
	JS_CFUNC_DEF("set_layers", 1, &placeholder_texture_layered_class_set_layers),
};




static void define_placeholder_texture_layered_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, placeholder_texture_layered_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, placeholder_texture_layered_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "layers"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, placeholder_texture_layered_class_set_layers, "set_layers", 1),
        JS_PROP_GETSET
    );
}

static void define_placeholder_texture_layered_enum(JSContext *ctx, JSValue ctor) {
}

static int js_placeholder_texture_layered_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PlaceholderTextureLayered"] = class_id;
	classes_by_id[class_id] = "PlaceholderTextureLayered";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &placeholder_texture_layered_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["TextureLayered"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_placeholder_texture_layered_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, placeholder_texture_layered_class_proto_funcs, _countof(placeholder_texture_layered_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, placeholder_texture_layered_class_constructor, "PlaceholderTextureLayered", 0, JS_CFUNC_constructor, 0);
	define_placeholder_texture_layered_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PlaceholderTextureLayered", ctor);

	return 0;
}

JSModuleDef *_js_init_placeholder_texture_layered_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture_layered';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_placeholder_texture_layered_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PlaceholderTextureLayered");
	return m;
}

JSModuleDef *js_init_placeholder_texture_layered_module(JSContext *ctx) {
	return _js_init_placeholder_texture_layered_module(ctx, "@godot/classes/placeholder_texture_layered");
}

void __register_placeholder_texture_layered() {
	js_init_placeholder_texture_layered_module(js_context());
}

void register_placeholder_texture_layered() {
	__register_placeholder_texture_layered();
}