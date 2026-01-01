#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/texture2d.hpp>
using namespace godot;

static void texture2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Texture2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef texture2d_class_def = {
    "Texture2D",
    texture2d_class_finalizer
};

static JSValue texture2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Texture2D"];
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
        instance = memnew(Texture2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue texture2d_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Texture2D::get_width, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Texture2D::get_height, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Texture2D::get_size, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_has_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Texture2D::has_alpha, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&Texture2D::draw, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_draw_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&Texture2D::draw_rect, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_draw_rect_region(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&Texture2D::draw_rect_region, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_get_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Texture2D::get_image, ctx, this_val, argc, argv);
};
static JSValue texture2d_class_create_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Texture2D::create_placeholder, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry texture2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_width", 0, &texture2d_class_get_width),
	JS_CFUNC_DEF("get_height", 0, &texture2d_class_get_height),
	JS_CFUNC_DEF("get_size", 0, &texture2d_class_get_size),
	JS_CFUNC_DEF("has_alpha", 0, &texture2d_class_has_alpha),
	JS_CFUNC_DEF("draw", 4, &texture2d_class_draw),
	JS_CFUNC_DEF("draw_rect", 5, &texture2d_class_draw_rect),
	JS_CFUNC_DEF("draw_rect_region", 6, &texture2d_class_draw_rect_region),
	JS_CFUNC_DEF("get_image", 0, &texture2d_class_get_image),
	JS_CFUNC_DEF("create_placeholder", 0, &texture2d_class_create_placeholder),
};




static void define_texture2d_property(JSContext *ctx, JSValue proto) {
}

static void define_texture2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_texture2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Texture2D"] = class_id;
	classes_by_id[class_id] = "Texture2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &texture2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_texture2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, texture2d_class_proto_funcs, _countof(texture2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, texture2d_class_constructor, "Texture2D", 0, JS_CFUNC_constructor, 0);
	define_texture2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Texture2D", ctor);
	ctor_list["Texture2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_texture2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_texture2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Texture2D");
	return m;
}

JSModuleDef *js_init_texture2d_module(JSContext *ctx) {
	return _js_init_texture2d_module(ctx, "@godot/classes/texture2d");
}

void __register_texture2d() {
	js_init_texture2d_module(js_context());
}

void register_texture2d() {
	__register_texture2d();
}