#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/sprite_base3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/sprite3d.hpp>
using namespace godot;

static void sprite3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Sprite3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef sprite3d_class_def = {
    "Sprite3D",
    sprite3d_class_finalizer
};

static JSValue sprite3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Sprite3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Sprite3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Sprite3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Sprite3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue sprite3d_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_texture, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sprite3D::get_texture, ctx, this_val, argc, argv);
}
static JSValue sprite3d_class_set_region_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_region_enabled, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_is_region_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sprite3D::is_region_enabled, ctx, this_val, argc, argv);
}
static JSValue sprite3d_class_set_region_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_region_rect, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_get_region_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		Sprite3D *obj = static_cast<Sprite3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_region_rect();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		Sprite3D *js_proxy = static_cast<Sprite3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_region_rect(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue sprite3d_class_set_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_frame, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_get_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sprite3D::get_frame, ctx, this_val, argc, argv);
}
static JSValue sprite3d_class_set_frame_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_frame_coords, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_get_frame_coords(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Sprite3D *obj = static_cast<Sprite3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_frame_coords();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Sprite3D *js_proxy = static_cast<Sprite3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_frame_coords(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue sprite3d_class_set_vframes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_vframes, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_get_vframes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sprite3D::get_vframes, ctx, this_val, argc, argv);
}
static JSValue sprite3d_class_set_hframes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sprite3D::set_hframes, ctx, this_val, argc, argv);
};
static JSValue sprite3d_class_get_hframes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sprite3D::get_hframes, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry sprite3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture", 1, &sprite3d_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &sprite3d_class_get_texture),
	JS_CFUNC_DEF("set_region_enabled", 1, &sprite3d_class_set_region_enabled),
	JS_CFUNC_DEF("is_region_enabled", 0, &sprite3d_class_is_region_enabled),
	JS_CFUNC_DEF("set_region_rect", 1, &sprite3d_class_set_region_rect),
	JS_CFUNC_DEF("get_region_rect", 0, &sprite3d_class_get_region_rect),
	JS_CFUNC_DEF("set_frame", 1, &sprite3d_class_set_frame),
	JS_CFUNC_DEF("get_frame", 0, &sprite3d_class_get_frame),
	JS_CFUNC_DEF("set_frame_coords", 1, &sprite3d_class_set_frame_coords),
	JS_CFUNC_DEF("get_frame_coords", 0, &sprite3d_class_get_frame_coords),
	JS_CFUNC_DEF("set_vframes", 1, &sprite3d_class_set_vframes),
	JS_CFUNC_DEF("get_vframes", 0, &sprite3d_class_get_vframes),
	JS_CFUNC_DEF("set_hframes", 1, &sprite3d_class_set_hframes),
	JS_CFUNC_DEF("get_hframes", 0, &sprite3d_class_get_hframes),
};


static JSValue sprite3d_class_get_frame_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Sprite3D *opaque = static_cast<Sprite3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "frame_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "frame_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "frame_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue sprite3d_class_get_texture_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Sprite3D *opaque = static_cast<Sprite3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "texture_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "texture_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "texture_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_sprite3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, sprite3d_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hframes"),
        JS_NewCFunction(ctx, sprite3d_class_get_hframes, "get_hframes", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_hframes, "set_hframes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vframes"),
        JS_NewCFunction(ctx, sprite3d_class_get_vframes, "get_vframes", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_vframes, "set_vframes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frame"),
        JS_NewCFunction(ctx, sprite3d_class_get_frame, "get_frame", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_frame, "set_frame", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frame_coords"),
        JS_NewCFunction(ctx, sprite3d_class_get_frame_coords, "get_frame_coords", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_frame_coords, "set_frame_coords", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region_enabled"),
        JS_NewCFunction(ctx, sprite3d_class_is_region_enabled, "is_region_enabled", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_region_enabled, "set_region_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region_rect"),
        JS_NewCFunction(ctx, sprite3d_class_get_region_rect, "get_region_rect", 0),
        JS_NewCFunction(ctx, sprite3d_class_set_region_rect, "set_region_rect", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "frame_changed"),
		JS_NewCFunction(ctx, sprite3d_class_get_frame_changed_signal, "get_frame_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "texture_changed"),
		JS_NewCFunction(ctx, sprite3d_class_get_texture_changed_signal, "get_texture_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_sprite3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_sprite3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Sprite3D"] = class_id;
	classes_by_id[class_id] = "Sprite3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &sprite3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SpriteBase3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_sprite3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, sprite3d_class_proto_funcs, _countof(sprite3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, sprite3d_class_constructor, "Sprite3D", 0, JS_CFUNC_constructor, 0);
	define_sprite3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Sprite3D", ctor);

	return 0;
}

JSModuleDef *_js_init_sprite3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/sprite_base3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_sprite3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Sprite3D");
	return m;
}

JSModuleDef *js_init_sprite3d_module(JSContext *ctx) {
	return _js_init_sprite3d_module(ctx, "@godot/classes/sprite3d");
}

void __register_sprite3d() {
	js_init_sprite3d_module(js_context());
}

void register_sprite3d() {
	__register_sprite3d();
}