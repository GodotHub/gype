#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>
using namespace godot;

static void sprite_frames_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpriteFrames"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef sprite_frames_class_def = {
    "SpriteFrames",
    sprite_frames_class_finalizer
};

static JSValue sprite_frames_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpriteFrames"];
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
        instance = memnew(SpriteFrames);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue sprite_frames_class_add_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::add_animation, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_has_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::has_animation, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_duplicate_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::duplicate_animation, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_remove_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::remove_animation, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_rename_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::rename_animation, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_get_animation_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::get_animation_names, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_set_animation_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::set_animation_speed, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_get_animation_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::get_animation_speed, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_set_animation_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::set_animation_loop, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_get_animation_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::get_animation_loop, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_add_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::add_frame, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_set_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::set_frame, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_remove_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::remove_frame, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_get_frame_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::get_frame_count, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_get_frame_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::get_frame_texture, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_get_frame_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpriteFrames::get_frame_duration, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::clear, ctx, this_val, argc, argv);
};
static JSValue sprite_frames_class_clear_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpriteFrames::clear_all, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry sprite_frames_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_animation", 1, &sprite_frames_class_add_animation),
	JS_CFUNC_DEF("has_animation", 1, &sprite_frames_class_has_animation),
	JS_CFUNC_DEF("duplicate_animation", 2, &sprite_frames_class_duplicate_animation),
	JS_CFUNC_DEF("remove_animation", 1, &sprite_frames_class_remove_animation),
	JS_CFUNC_DEF("rename_animation", 2, &sprite_frames_class_rename_animation),
	JS_CFUNC_DEF("get_animation_names", 0, &sprite_frames_class_get_animation_names),
	JS_CFUNC_DEF("set_animation_speed", 2, &sprite_frames_class_set_animation_speed),
	JS_CFUNC_DEF("get_animation_speed", 1, &sprite_frames_class_get_animation_speed),
	JS_CFUNC_DEF("set_animation_loop", 2, &sprite_frames_class_set_animation_loop),
	JS_CFUNC_DEF("get_animation_loop", 1, &sprite_frames_class_get_animation_loop),
	JS_CFUNC_DEF("add_frame", 4, &sprite_frames_class_add_frame),
	JS_CFUNC_DEF("set_frame", 4, &sprite_frames_class_set_frame),
	JS_CFUNC_DEF("remove_frame", 2, &sprite_frames_class_remove_frame),
	JS_CFUNC_DEF("get_frame_count", 1, &sprite_frames_class_get_frame_count),
	JS_CFUNC_DEF("get_frame_texture", 2, &sprite_frames_class_get_frame_texture),
	JS_CFUNC_DEF("get_frame_duration", 2, &sprite_frames_class_get_frame_duration),
	JS_CFUNC_DEF("clear", 1, &sprite_frames_class_clear),
	JS_CFUNC_DEF("clear_all", 0, &sprite_frames_class_clear_all),
};




static void define_sprite_frames_property(JSContext *ctx, JSValue proto) {
}

static void define_sprite_frames_enum(JSContext *ctx, JSValue ctor) {
}

static int js_sprite_frames_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpriteFrames"] = class_id;
	classes_by_id[class_id] = "SpriteFrames";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &sprite_frames_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_sprite_frames_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, sprite_frames_class_proto_funcs, _countof(sprite_frames_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, sprite_frames_class_constructor, "SpriteFrames", 0, JS_CFUNC_constructor, 0);
	define_sprite_frames_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpriteFrames", ctor);
	ctor_list["SpriteFrames"] = ctor;

	return 0;
}

JSModuleDef *_js_init_sprite_frames_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_sprite_frames_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpriteFrames");
	return m;
}

JSModuleDef *js_init_sprite_frames_module(JSContext *ctx) {
	return _js_init_sprite_frames_module(ctx, "@godot/classes/sprite_frames");
}

void __register_sprite_frames() {
	js_init_sprite_frames_module(js_context());
}

void register_sprite_frames() {
	__register_sprite_frames();
}