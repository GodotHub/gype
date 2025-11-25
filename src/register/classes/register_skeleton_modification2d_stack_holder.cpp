#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modification2d.hpp>
#include <godot_cpp/classes/skeleton_modification_stack2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skeleton_modification2d_stack_holder.hpp>
using namespace godot;

static void skeleton_modification2d_stack_holder_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModification2DStackHolder"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_modification2d_stack_holder_class_def = {
    "SkeletonModification2DStackHolder",
    skeleton_modification2d_stack_holder_class_finalizer
};

static JSValue skeleton_modification2d_stack_holder_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModification2DStackHolder"];
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
        instance = memnew(SkeletonModification2DStackHolder);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification2d_stack_holder_class_set_held_modification_stack(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DStackHolder::set_held_modification_stack, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_stack_holder_class_get_held_modification_stack(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DStackHolder::get_held_modification_stack, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry skeleton_modification2d_stack_holder_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_held_modification_stack", 1, &skeleton_modification2d_stack_holder_class_set_held_modification_stack),
	JS_CFUNC_DEF("get_held_modification_stack", 0, &skeleton_modification2d_stack_holder_class_get_held_modification_stack),
};




static void define_skeleton_modification2d_stack_holder_property(JSContext *ctx, JSValue proto) {
}

static void define_skeleton_modification2d_stack_holder_enum(JSContext *ctx, JSValue ctor) {
}

static int js_skeleton_modification2d_stack_holder_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModification2DStackHolder"] = class_id;
	classes_by_id[class_id] = "SkeletonModification2DStackHolder";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification2d_stack_holder_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModification2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification2d_stack_holder_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification2d_stack_holder_class_proto_funcs, _countof(skeleton_modification2d_stack_holder_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification2d_stack_holder_class_constructor, "SkeletonModification2DStackHolder", 0, JS_CFUNC_constructor, 0);
	define_skeleton_modification2d_stack_holder_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModification2DStackHolder", ctor);
	ctor_list["SkeletonModification2DStackHolder"] = ctor;

	return 0;
}

JSModuleDef *_js_init_skeleton_modification2d_stack_holder_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modification2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification2d_stack_holder_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModification2DStackHolder");
	return m;
}

JSModuleDef *js_init_skeleton_modification2d_stack_holder_module(JSContext *ctx) {
	return _js_init_skeleton_modification2d_stack_holder_module(ctx, "@godot/classes/skeleton_modification2d_stack_holder");
}

void __register_skeleton_modification2d_stack_holder() {
	js_init_skeleton_modification2d_stack_holder_module(js_context());
}

void register_skeleton_modification2d_stack_holder() {
	__register_skeleton_modification2d_stack_holder();
}