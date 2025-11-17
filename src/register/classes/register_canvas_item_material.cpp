#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/canvas_item_material.hpp>
using namespace godot;

static void canvas_item_material_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CanvasItemMaterial"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef canvas_item_material_class_def = {
    "CanvasItemMaterial",
    canvas_item_material_class_finalizer
};

static JSValue canvas_item_material_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CanvasItemMaterial"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CanvasItemMaterial *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CanvasItemMaterial *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CanvasItemMaterial);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue canvas_item_material_class_set_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasItemMaterial::set_blend_mode, ctx, this_val, argc, argv);
};
static JSValue canvas_item_material_class_get_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasItemMaterial::get_blend_mode, ctx, this_val, argc, argv);
}
static JSValue canvas_item_material_class_set_light_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasItemMaterial::set_light_mode, ctx, this_val, argc, argv);
};
static JSValue canvas_item_material_class_get_light_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasItemMaterial::get_light_mode, ctx, this_val, argc, argv);
}
static JSValue canvas_item_material_class_set_particles_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasItemMaterial::set_particles_animation, ctx, this_val, argc, argv);
};
static JSValue canvas_item_material_class_get_particles_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasItemMaterial::get_particles_animation, ctx, this_val, argc, argv);
}
static JSValue canvas_item_material_class_set_particles_anim_h_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasItemMaterial::set_particles_anim_h_frames, ctx, this_val, argc, argv);
};
static JSValue canvas_item_material_class_get_particles_anim_h_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasItemMaterial::get_particles_anim_h_frames, ctx, this_val, argc, argv);
}
static JSValue canvas_item_material_class_set_particles_anim_v_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasItemMaterial::set_particles_anim_v_frames, ctx, this_val, argc, argv);
};
static JSValue canvas_item_material_class_get_particles_anim_v_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasItemMaterial::get_particles_anim_v_frames, ctx, this_val, argc, argv);
}
static JSValue canvas_item_material_class_set_particles_anim_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasItemMaterial::set_particles_anim_loop, ctx, this_val, argc, argv);
};
static JSValue canvas_item_material_class_get_particles_anim_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CanvasItemMaterial::get_particles_anim_loop, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry canvas_item_material_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_blend_mode", 1, &canvas_item_material_class_set_blend_mode),
	JS_CFUNC_DEF("get_blend_mode", 0, &canvas_item_material_class_get_blend_mode),
	JS_CFUNC_DEF("set_light_mode", 1, &canvas_item_material_class_set_light_mode),
	JS_CFUNC_DEF("get_light_mode", 0, &canvas_item_material_class_get_light_mode),
	JS_CFUNC_DEF("set_particles_animation", 1, &canvas_item_material_class_set_particles_animation),
	JS_CFUNC_DEF("get_particles_animation", 0, &canvas_item_material_class_get_particles_animation),
	JS_CFUNC_DEF("set_particles_anim_h_frames", 1, &canvas_item_material_class_set_particles_anim_h_frames),
	JS_CFUNC_DEF("get_particles_anim_h_frames", 0, &canvas_item_material_class_get_particles_anim_h_frames),
	JS_CFUNC_DEF("set_particles_anim_v_frames", 1, &canvas_item_material_class_set_particles_anim_v_frames),
	JS_CFUNC_DEF("get_particles_anim_v_frames", 0, &canvas_item_material_class_get_particles_anim_v_frames),
	JS_CFUNC_DEF("set_particles_anim_loop", 1, &canvas_item_material_class_set_particles_anim_loop),
	JS_CFUNC_DEF("get_particles_anim_loop", 0, &canvas_item_material_class_get_particles_anim_loop),
};




static void define_canvas_item_material_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_mode"),
        JS_NewCFunction(ctx, canvas_item_material_class_get_blend_mode, "get_blend_mode", 0),
        JS_NewCFunction(ctx, canvas_item_material_class_set_blend_mode, "set_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_mode"),
        JS_NewCFunction(ctx, canvas_item_material_class_get_light_mode, "get_light_mode", 0),
        JS_NewCFunction(ctx, canvas_item_material_class_set_light_mode, "set_light_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_animation"),
        JS_NewCFunction(ctx, canvas_item_material_class_get_particles_animation, "get_particles_animation", 0),
        JS_NewCFunction(ctx, canvas_item_material_class_set_particles_animation, "set_particles_animation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_anim_h_frames"),
        JS_NewCFunction(ctx, canvas_item_material_class_get_particles_anim_h_frames, "get_particles_anim_h_frames", 0),
        JS_NewCFunction(ctx, canvas_item_material_class_set_particles_anim_h_frames, "set_particles_anim_h_frames", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_anim_v_frames"),
        JS_NewCFunction(ctx, canvas_item_material_class_get_particles_anim_v_frames, "get_particles_anim_v_frames", 0),
        JS_NewCFunction(ctx, canvas_item_material_class_set_particles_anim_v_frames, "set_particles_anim_v_frames", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_anim_loop"),
        JS_NewCFunction(ctx, canvas_item_material_class_get_particles_anim_loop, "get_particles_anim_loop", 0),
        JS_NewCFunction(ctx, canvas_item_material_class_set_particles_anim_loop, "set_particles_anim_loop", 1),
        JS_PROP_GETSET
    );
}

static void define_canvas_item_material_enum(JSContext *ctx, JSValue ctor) {
	JSValue BlendMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_MIX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_ADD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_SUB", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_MUL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_PREMULT_ALPHA", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "BlendMode", BlendMode_obj);
	JSValue LightMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LightMode_obj, "LIGHT_MODE_NORMAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LightMode_obj, "LIGHT_MODE_UNSHADED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LightMode_obj, "LIGHT_MODE_LIGHT_ONLY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "LightMode", LightMode_obj);
}

static int js_canvas_item_material_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CanvasItemMaterial"] = class_id;
	classes_by_id[class_id] = "CanvasItemMaterial";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &canvas_item_material_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Material"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_canvas_item_material_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, canvas_item_material_class_proto_funcs, _countof(canvas_item_material_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, canvas_item_material_class_constructor, "CanvasItemMaterial", 0, JS_CFUNC_constructor, 0);
	define_canvas_item_material_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CanvasItemMaterial", ctor);

	return 0;
}

JSModuleDef *_js_init_canvas_item_material_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/material';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_canvas_item_material_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CanvasItemMaterial");
	return m;
}

JSModuleDef *js_init_canvas_item_material_module(JSContext *ctx) {
	return _js_init_canvas_item_material_module(ctx, "@godot/classes/canvas_item_material");
}

void __register_canvas_item_material() {
	js_init_canvas_item_material_module(js_context());
}

void register_canvas_item_material() {
	__register_canvas_item_material();
}