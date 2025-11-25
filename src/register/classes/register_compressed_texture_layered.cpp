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
#include <godot_cpp/classes/compressed_texture_layered.hpp>
using namespace godot;

static void compressed_texture_layered_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CompressedTextureLayered"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef compressed_texture_layered_class_def = {
    "CompressedTextureLayered",
    compressed_texture_layered_class_finalizer
};

static JSValue compressed_texture_layered_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CompressedTextureLayered"];
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
        instance = memnew(CompressedTextureLayered);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue compressed_texture_layered_class_load(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CompressedTextureLayered::load, ctx, this_val, argc, argv);
};
static JSValue compressed_texture_layered_class_get_load_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CompressedTextureLayered::get_load_path, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry compressed_texture_layered_class_proto_funcs[] = {
	JS_CFUNC_DEF("load", 1, &compressed_texture_layered_class_load),
	JS_CFUNC_DEF("get_load_path", 0, &compressed_texture_layered_class_get_load_path),
};




static void define_compressed_texture_layered_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "load_path"),
        JS_NewCFunction(ctx, compressed_texture_layered_class_get_load_path, "get_load_path", 0),
        JS_NewCFunction(ctx, compressed_texture_layered_class_load, "load", 1),
        JS_PROP_GETSET
    );
}

static void define_compressed_texture_layered_enum(JSContext *ctx, JSValue ctor) {
}

static int js_compressed_texture_layered_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CompressedTextureLayered"] = class_id;
	classes_by_id[class_id] = "CompressedTextureLayered";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &compressed_texture_layered_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["TextureLayered"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_compressed_texture_layered_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, compressed_texture_layered_class_proto_funcs, _countof(compressed_texture_layered_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, compressed_texture_layered_class_constructor, "CompressedTextureLayered", 0, JS_CFUNC_constructor, 0);
	define_compressed_texture_layered_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CompressedTextureLayered", ctor);
	ctor_list["CompressedTextureLayered"] = ctor;

	return 0;
}

JSModuleDef *_js_init_compressed_texture_layered_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture_layered';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_compressed_texture_layered_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CompressedTextureLayered");
	return m;
}

JSModuleDef *js_init_compressed_texture_layered_module(JSContext *ctx) {
	return _js_init_compressed_texture_layered_module(ctx, "@godot/classes/compressed_texture_layered");
}

void __register_compressed_texture_layered() {
	js_init_compressed_texture_layered_module(js_context());
}

void register_compressed_texture_layered() {
	__register_compressed_texture_layered();
}