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
#include <godot_cpp/classes/canvas_texture.hpp>
using namespace godot;

static void canvas_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CanvasTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef canvas_texture_class_def = {
    "CanvasTexture",
    canvas_texture_class_finalizer
};

static JSValue canvas_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CanvasTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CanvasTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CanvasTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CanvasTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue canvas_texture_class_set_diffuse_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_diffuse_texture, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_diffuse_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasTexture::get_diffuse_texture, ctx, this_val, argc, argv);
}
static JSValue canvas_texture_class_set_normal_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_normal_texture, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_normal_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasTexture::get_normal_texture, ctx, this_val, argc, argv);
}
static JSValue canvas_texture_class_set_specular_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_specular_texture, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_specular_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasTexture::get_specular_texture, ctx, this_val, argc, argv);
}
static JSValue canvas_texture_class_set_specular_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_specular_color, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_specular_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CanvasTexture *obj = static_cast<CanvasTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_specular_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CanvasTexture *js_proxy = static_cast<CanvasTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_specular_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue canvas_texture_class_set_specular_shininess(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_specular_shininess, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_specular_shininess(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasTexture::get_specular_shininess, ctx, this_val, argc, argv);
}
static JSValue canvas_texture_class_set_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_texture_filter, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasTexture::get_texture_filter, ctx, this_val, argc, argv);
}
static JSValue canvas_texture_class_set_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasTexture::set_texture_repeat, ctx, this_val, argc, argv);
};
static JSValue canvas_texture_class_get_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasTexture::get_texture_repeat, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry canvas_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_diffuse_texture", 1, &canvas_texture_class_set_diffuse_texture),
	JS_CFUNC_DEF("get_diffuse_texture", 0, &canvas_texture_class_get_diffuse_texture),
	JS_CFUNC_DEF("set_normal_texture", 1, &canvas_texture_class_set_normal_texture),
	JS_CFUNC_DEF("get_normal_texture", 0, &canvas_texture_class_get_normal_texture),
	JS_CFUNC_DEF("set_specular_texture", 1, &canvas_texture_class_set_specular_texture),
	JS_CFUNC_DEF("get_specular_texture", 0, &canvas_texture_class_get_specular_texture),
	JS_CFUNC_DEF("set_specular_color", 1, &canvas_texture_class_set_specular_color),
	JS_CFUNC_DEF("get_specular_color", 0, &canvas_texture_class_get_specular_color),
	JS_CFUNC_DEF("set_specular_shininess", 1, &canvas_texture_class_set_specular_shininess),
	JS_CFUNC_DEF("get_specular_shininess", 0, &canvas_texture_class_get_specular_shininess),
	JS_CFUNC_DEF("set_texture_filter", 1, &canvas_texture_class_set_texture_filter),
	JS_CFUNC_DEF("get_texture_filter", 0, &canvas_texture_class_get_texture_filter),
	JS_CFUNC_DEF("set_texture_repeat", 1, &canvas_texture_class_set_texture_repeat),
	JS_CFUNC_DEF("get_texture_repeat", 0, &canvas_texture_class_get_texture_repeat),
};




static void define_canvas_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "diffuse_texture"),
        JS_NewCFunction(ctx, canvas_texture_class_get_diffuse_texture, "get_diffuse_texture", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_diffuse_texture, "set_diffuse_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "normal_texture"),
        JS_NewCFunction(ctx, canvas_texture_class_get_normal_texture, "get_normal_texture", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_normal_texture, "set_normal_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "specular_texture"),
        JS_NewCFunction(ctx, canvas_texture_class_get_specular_texture, "get_specular_texture", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_specular_texture, "set_specular_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "specular_color"),
        JS_NewCFunction(ctx, canvas_texture_class_get_specular_color, "get_specular_color", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_specular_color, "set_specular_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "specular_shininess"),
        JS_NewCFunction(ctx, canvas_texture_class_get_specular_shininess, "get_specular_shininess", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_specular_shininess, "set_specular_shininess", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_filter"),
        JS_NewCFunction(ctx, canvas_texture_class_get_texture_filter, "get_texture_filter", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_texture_filter, "set_texture_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_repeat"),
        JS_NewCFunction(ctx, canvas_texture_class_get_texture_repeat, "get_texture_repeat", 0),
        JS_NewCFunction(ctx, canvas_texture_class_set_texture_repeat, "set_texture_repeat", 1),
        JS_PROP_GETSET
    );
}

static void define_canvas_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_canvas_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CanvasTexture"] = class_id;
	classes_by_id[class_id] = "CanvasTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &canvas_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_canvas_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, canvas_texture_class_proto_funcs, _countof(canvas_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, canvas_texture_class_constructor, "CanvasTexture", 0, JS_CFUNC_constructor, 0);
	define_canvas_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CanvasTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_canvas_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_canvas_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CanvasTexture");
	return m;
}

JSModuleDef *js_init_canvas_texture_module(JSContext *ctx) {
	return _js_init_canvas_texture_module(ctx, "@godot/classes/canvas_texture");
}

void __register_canvas_texture() {
	js_init_canvas_texture_module(js_context());
}

void register_canvas_texture() {
	__register_canvas_texture();
}