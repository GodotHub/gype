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
#include <godot_cpp/classes/placeholder_texture2d.hpp>
using namespace godot;

static void placeholder_texture2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PlaceholderTexture2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef placeholder_texture2d_class_def = {
    "PlaceholderTexture2D",
    placeholder_texture2d_class_finalizer
};

static JSValue placeholder_texture2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PlaceholderTexture2D"];
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
        instance = memnew(PlaceholderTexture2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue placeholder_texture2d_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaceholderTexture2D::set_size, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry placeholder_texture2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &placeholder_texture2d_class_set_size),
};




static void define_placeholder_texture2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_UNDEFINED,
        JS_NewCFunction(ctx, placeholder_texture2d_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
}

static void define_placeholder_texture2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_placeholder_texture2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PlaceholderTexture2D"] = class_id;
	classes_by_id[class_id] = "PlaceholderTexture2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &placeholder_texture2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_placeholder_texture2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, placeholder_texture2d_class_proto_funcs, _countof(placeholder_texture2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, placeholder_texture2d_class_constructor, "PlaceholderTexture2D", 0, JS_CFUNC_constructor, 0);
	define_placeholder_texture2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PlaceholderTexture2D", ctor);
	ctor_list["PlaceholderTexture2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_placeholder_texture2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_placeholder_texture2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PlaceholderTexture2D");
	return m;
}

JSModuleDef *js_init_placeholder_texture2d_module(JSContext *ctx) {
	return _js_init_placeholder_texture2d_module(ctx, "@godot/classes/placeholder_texture2d");
}

void __register_placeholder_texture2d() {
	js_init_placeholder_texture2d_module(js_context());
}

void register_placeholder_texture2d() {
	__register_placeholder_texture2d();
}