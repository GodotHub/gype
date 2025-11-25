#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_time_seek.hpp>
using namespace godot;

static void animation_node_time_seek_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeTimeSeek"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_time_seek_class_def = {
    "AnimationNodeTimeSeek",
    animation_node_time_seek_class_finalizer
};

static JSValue animation_node_time_seek_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeTimeSeek"];
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
        instance = memnew(AnimationNodeTimeSeek);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_time_seek_class_set_explicit_elapse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeTimeSeek::set_explicit_elapse, ctx, this_val, argc, argv);
};
static JSValue animation_node_time_seek_class_is_explicit_elapse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeTimeSeek::is_explicit_elapse, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry animation_node_time_seek_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_explicit_elapse", 1, &animation_node_time_seek_class_set_explicit_elapse),
	JS_CFUNC_DEF("is_explicit_elapse", 0, &animation_node_time_seek_class_is_explicit_elapse),
};




static void define_animation_node_time_seek_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "explicit_elapse"),
        JS_NewCFunction(ctx, animation_node_time_seek_class_is_explicit_elapse, "is_explicit_elapse", 0),
        JS_NewCFunction(ctx, animation_node_time_seek_class_set_explicit_elapse, "set_explicit_elapse", 1),
        JS_PROP_GETSET
    );
}

static void define_animation_node_time_seek_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animation_node_time_seek_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeTimeSeek"] = class_id;
	classes_by_id[class_id] = "AnimationNodeTimeSeek";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_time_seek_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_time_seek_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_time_seek_class_proto_funcs, _countof(animation_node_time_seek_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_time_seek_class_constructor, "AnimationNodeTimeSeek", 0, JS_CFUNC_constructor, 0);
	define_animation_node_time_seek_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeTimeSeek", ctor);
	ctor_list["AnimationNodeTimeSeek"] = ctor;

	return 0;
}

JSModuleDef *_js_init_animation_node_time_seek_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_time_seek_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeTimeSeek");
	return m;
}

JSModuleDef *js_init_animation_node_time_seek_module(JSContext *ctx) {
	return _js_init_animation_node_time_seek_module(ctx, "@godot/classes/animation_node_time_seek");
}

void __register_animation_node_time_seek() {
	js_init_animation_node_time_seek_module(js_context());
}

void register_animation_node_time_seek() {
	__register_animation_node_time_seek();
}