#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/foldable_container.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/foldable_group.hpp>
using namespace godot;

static void foldable_group_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FoldableGroup"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef foldable_group_class_def = {
    "FoldableGroup",
    foldable_group_class_finalizer
};

static JSValue foldable_group_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FoldableGroup"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FoldableGroup *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FoldableGroup *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FoldableGroup);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue foldable_group_class_get_expanded_container(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableGroup::get_expanded_container, ctx, this_val, argc, argv);
};
static JSValue foldable_group_class_get_containers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableGroup::get_containers, ctx, this_val, argc, argv);
};
static JSValue foldable_group_class_set_allow_folding_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableGroup::set_allow_folding_all, ctx, this_val, argc, argv);
};
static JSValue foldable_group_class_is_allow_folding_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableGroup::is_allow_folding_all, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry foldable_group_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_expanded_container", 0, &foldable_group_class_get_expanded_container),
	JS_CFUNC_DEF("get_containers", 0, &foldable_group_class_get_containers),
	JS_CFUNC_DEF("set_allow_folding_all", 1, &foldable_group_class_set_allow_folding_all),
	JS_CFUNC_DEF("is_allow_folding_all", 0, &foldable_group_class_is_allow_folding_all),
};


static JSValue foldable_group_class_get_expanded_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	FoldableGroup *opaque = static_cast<FoldableGroup *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "expanded_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "expanded"));
		JS_DefinePropertyValueStr(ctx, this_val, "expanded_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_foldable_group_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_folding_all"),
        JS_NewCFunction(ctx, foldable_group_class_is_allow_folding_all, "is_allow_folding_all", 0),
        JS_NewCFunction(ctx, foldable_group_class_set_allow_folding_all, "set_allow_folding_all", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "expanded"),
		JS_NewCFunction(ctx, foldable_group_class_get_expanded_signal, "get_expanded_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_foldable_group_enum(JSContext *ctx, JSValue ctor) {
}

static int js_foldable_group_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FoldableGroup"] = class_id;
	classes_by_id[class_id] = "FoldableGroup";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &foldable_group_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_foldable_group_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, foldable_group_class_proto_funcs, _countof(foldable_group_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, foldable_group_class_constructor, "FoldableGroup", 0, JS_CFUNC_constructor, 0);
	define_foldable_group_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FoldableGroup", ctor);

	return 0;
}

JSModuleDef *_js_init_foldable_group_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_foldable_group_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FoldableGroup");
	return m;
}

JSModuleDef *js_init_foldable_group_module(JSContext *ctx) {
	return _js_init_foldable_group_module(ctx, "@godot/classes/foldable_group");
}

void __register_foldable_group() {
	js_init_foldable_group_module(js_context());
}

void register_foldable_group() {
	__register_foldable_group();
}