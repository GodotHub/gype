#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image_texture_layered.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/cubemap.hpp>
using namespace godot;

static void cubemap_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Cubemap"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef cubemap_class_def = {
    "Cubemap",
    cubemap_class_finalizer
};

static JSValue cubemap_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Cubemap"];
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
        instance = memnew(Cubemap);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue cubemap_class_create_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Cubemap::create_placeholder, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry cubemap_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_placeholder", 0, &cubemap_class_create_placeholder),
};




static void define_cubemap_property(JSContext *ctx, JSValue proto) {
}

static void define_cubemap_enum(JSContext *ctx, JSValue ctor) {
}

static int js_cubemap_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Cubemap"] = class_id;
	classes_by_id[class_id] = "Cubemap";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &cubemap_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ImageTextureLayered"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_cubemap_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, cubemap_class_proto_funcs, _countof(cubemap_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, cubemap_class_constructor, "Cubemap", 0, JS_CFUNC_constructor, 0);
	define_cubemap_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Cubemap", ctor);
	ctor_list["Cubemap"] = ctor;

	return 0;
}

JSModuleDef *_js_init_cubemap_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/image_texture_layered';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_cubemap_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Cubemap");
	return m;
}

JSModuleDef *js_init_cubemap_module(JSContext *ctx) {
	return _js_init_cubemap_module(ctx, "@godot/classes/cubemap");
}

void __register_cubemap() {
	js_init_cubemap_module(js_context());
}

void register_cubemap() {
	__register_cubemap();
}