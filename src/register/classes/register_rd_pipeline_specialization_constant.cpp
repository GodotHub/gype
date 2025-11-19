#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/rd_pipeline_specialization_constant.hpp>
using namespace godot;

static void rd_pipeline_specialization_constant_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDPipelineSpecializationConstant"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_pipeline_specialization_constant_class_def = {
    "RDPipelineSpecializationConstant",
    rd_pipeline_specialization_constant_class_finalizer
};

static JSValue rd_pipeline_specialization_constant_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDPipelineSpecializationConstant"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RDPipelineSpecializationConstant *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RDPipelineSpecializationConstant *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RDPipelineSpecializationConstant);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_pipeline_specialization_constant_class_set_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineSpecializationConstant::set_value, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_specialization_constant_class_get_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineSpecializationConstant::get_value, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_specialization_constant_class_set_constant_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineSpecializationConstant::set_constant_id, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_specialization_constant_class_get_constant_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineSpecializationConstant::get_constant_id, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_pipeline_specialization_constant_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_value", 1, &rd_pipeline_specialization_constant_class_set_value),
	JS_CFUNC_DEF("get_value", 0, &rd_pipeline_specialization_constant_class_get_value),
	JS_CFUNC_DEF("set_constant_id", 1, &rd_pipeline_specialization_constant_class_set_constant_id),
	JS_CFUNC_DEF("get_constant_id", 0, &rd_pipeline_specialization_constant_class_get_constant_id),
};




static void define_rd_pipeline_specialization_constant_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "value"),
        JS_NewCFunction(ctx, rd_pipeline_specialization_constant_class_get_value, "get_value", 0),
        JS_NewCFunction(ctx, rd_pipeline_specialization_constant_class_set_value, "set_value", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "constant_id"),
        JS_NewCFunction(ctx, rd_pipeline_specialization_constant_class_get_constant_id, "get_constant_id", 0),
        JS_NewCFunction(ctx, rd_pipeline_specialization_constant_class_set_constant_id, "set_constant_id", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_pipeline_specialization_constant_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_pipeline_specialization_constant_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDPipelineSpecializationConstant"] = class_id;
	classes_by_id[class_id] = "RDPipelineSpecializationConstant";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_pipeline_specialization_constant_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_pipeline_specialization_constant_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_pipeline_specialization_constant_class_proto_funcs, _countof(rd_pipeline_specialization_constant_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_pipeline_specialization_constant_class_constructor, "RDPipelineSpecializationConstant", 0, JS_CFUNC_constructor, 0);
	define_rd_pipeline_specialization_constant_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDPipelineSpecializationConstant", ctor);

	return 0;
}

JSModuleDef *_js_init_rd_pipeline_specialization_constant_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_pipeline_specialization_constant_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDPipelineSpecializationConstant");
	return m;
}

JSModuleDef *js_init_rd_pipeline_specialization_constant_module(JSContext *ctx) {
	return _js_init_rd_pipeline_specialization_constant_module(ctx, "@godot/classes/rd_pipeline_specialization_constant");
}

void __register_rd_pipeline_specialization_constant() {
	js_init_rd_pipeline_specialization_constant_module(js_context());
}

void register_rd_pipeline_specialization_constant() {
	__register_rd_pipeline_specialization_constant();
}