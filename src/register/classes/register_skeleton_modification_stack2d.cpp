#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/skeleton2d.hpp>
#include <godot_cpp/classes/skeleton_modification2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skeleton_modification_stack2d.hpp>
using namespace godot;

static void skeleton_modification_stack2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModificationStack2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef skeleton_modification_stack2d_class_def = {
    "SkeletonModificationStack2D",
    skeleton_modification_stack2d_class_finalizer
};

static JSValue skeleton_modification_stack2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModificationStack2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SkeletonModificationStack2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SkeletonModificationStack2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SkeletonModificationStack2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification_stack2d_class_setup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::setup, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_execute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::execute, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_enable_all_modifications(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::enable_all_modifications, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_get_modification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModificationStack2D::get_modification, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_add_modification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::add_modification, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_delete_modification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::delete_modification, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_set_modification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::set_modification, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_set_modification_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::set_modification_count, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_get_modification_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModificationStack2D::get_modification_count, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification_stack2d_class_get_is_setup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModificationStack2D::get_is_setup, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::set_enabled, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_get_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModificationStack2D::get_enabled, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification_stack2d_class_set_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModificationStack2D::set_strength, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification_stack2d_class_get_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModificationStack2D::get_strength, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification_stack2d_class_get_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModificationStack2D::get_skeleton, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry skeleton_modification_stack2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("setup", 0, &skeleton_modification_stack2d_class_setup),
	JS_CFUNC_DEF("execute", 2, &skeleton_modification_stack2d_class_execute),
	JS_CFUNC_DEF("enable_all_modifications", 1, &skeleton_modification_stack2d_class_enable_all_modifications),
	JS_CFUNC_DEF("get_modification", 1, &skeleton_modification_stack2d_class_get_modification),
	JS_CFUNC_DEF("add_modification", 1, &skeleton_modification_stack2d_class_add_modification),
	JS_CFUNC_DEF("delete_modification", 1, &skeleton_modification_stack2d_class_delete_modification),
	JS_CFUNC_DEF("set_modification", 2, &skeleton_modification_stack2d_class_set_modification),
	JS_CFUNC_DEF("set_modification_count", 1, &skeleton_modification_stack2d_class_set_modification_count),
	JS_CFUNC_DEF("get_modification_count", 0, &skeleton_modification_stack2d_class_get_modification_count),
	JS_CFUNC_DEF("get_is_setup", 0, &skeleton_modification_stack2d_class_get_is_setup),
	JS_CFUNC_DEF("set_enabled", 1, &skeleton_modification_stack2d_class_set_enabled),
	JS_CFUNC_DEF("get_enabled", 0, &skeleton_modification_stack2d_class_get_enabled),
	JS_CFUNC_DEF("set_strength", 1, &skeleton_modification_stack2d_class_set_strength),
	JS_CFUNC_DEF("get_strength", 0, &skeleton_modification_stack2d_class_get_strength),
	JS_CFUNC_DEF("get_skeleton", 0, &skeleton_modification_stack2d_class_get_skeleton),
};




static void define_skeleton_modification_stack2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled"),
        JS_NewCFunction(ctx, skeleton_modification_stack2d_class_get_enabled, "get_enabled", 0),
        JS_NewCFunction(ctx, skeleton_modification_stack2d_class_set_enabled, "set_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "strength"),
        JS_NewCFunction(ctx, skeleton_modification_stack2d_class_get_strength, "get_strength", 0),
        JS_NewCFunction(ctx, skeleton_modification_stack2d_class_set_strength, "set_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modification_count"),
        JS_NewCFunction(ctx, skeleton_modification_stack2d_class_get_modification_count, "get_modification_count", 0),
        JS_NewCFunction(ctx, skeleton_modification_stack2d_class_set_modification_count, "set_modification_count", 1),
        JS_PROP_GETSET
    );
}

static void define_skeleton_modification_stack2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_skeleton_modification_stack2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModificationStack2D"] = class_id;
	classes_by_id[class_id] = "SkeletonModificationStack2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification_stack2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification_stack2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification_stack2d_class_proto_funcs, _countof(skeleton_modification_stack2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification_stack2d_class_constructor, "SkeletonModificationStack2D", 0, JS_CFUNC_constructor, 0);
	define_skeleton_modification_stack2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModificationStack2D", ctor);

	return 0;
}

JSModuleDef *_js_init_skeleton_modification_stack2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification_stack2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModificationStack2D");
	return m;
}

JSModuleDef *js_init_skeleton_modification_stack2d_module(JSContext *ctx) {
	return _js_init_skeleton_modification_stack2d_module(ctx, "@godot/classes/skeleton_modification_stack2d");
}

void __register_skeleton_modification_stack2d() {
	js_init_skeleton_modification_stack2d_module(js_context());
}

void register_skeleton_modification_stack2d() {
	__register_skeleton_modification_stack2d();
}