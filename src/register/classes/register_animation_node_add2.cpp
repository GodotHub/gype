#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_node_sync.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_add2.hpp>
using namespace godot;

static void animation_node_add2_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeAdd2"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_node_add2_class_def = {
    "AnimationNodeAdd2",
    animation_node_add2_class_finalizer
};

static JSValue animation_node_add2_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeAdd2"];
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
        instance = memnew(AnimationNodeAdd2);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_animation_node_add2_property(JSContext *ctx, JSValue proto) {
}

static void define_animation_node_add2_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animation_node_add2_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeAdd2"] = class_id;
	classes_by_id[class_id] = "AnimationNodeAdd2";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_add2_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationNodeSync"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_add2_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_add2_class_constructor, "AnimationNodeAdd2", 0, JS_CFUNC_constructor, 0);
	define_animation_node_add2_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeAdd2", ctor);
	ctor_list["AnimationNodeAdd2"] = ctor;

	return 0;
}

JSModuleDef *_js_init_animation_node_add2_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_node_sync';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_add2_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeAdd2");
	return m;
}

JSModuleDef *js_init_animation_node_add2_module(JSContext *ctx) {
	return _js_init_animation_node_add2_module(ctx, "@godot/classes/animation_node_add2");
}

void __register_animation_node_add2() {
	js_init_animation_node_add2_module(js_context());
}

void register_animation_node_add2() {
	__register_animation_node_add2();
}