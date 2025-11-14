#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/rd_pipeline_color_blend_state_attachment.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/rd_pipeline_color_blend_state.hpp>
using namespace godot;

static void rd_pipeline_color_blend_state_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDPipelineColorBlendState"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_pipeline_color_blend_state_class_def = {
    "RDPipelineColorBlendState",
    rd_pipeline_color_blend_state_class_finalizer
};

static JSValue rd_pipeline_color_blend_state_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDPipelineColorBlendState"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RDPipelineColorBlendState *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RDPipelineColorBlendState *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RDPipelineColorBlendState);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_pipeline_color_blend_state_class_set_enable_logic_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendState::set_enable_logic_op, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_class_get_enable_logic_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendState::get_enable_logic_op, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_class_set_logic_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendState::set_logic_op, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_class_get_logic_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendState::get_logic_op, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_class_set_blend_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendState::set_blend_constant, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_class_get_blend_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		RDPipelineColorBlendState *obj = static_cast<RDPipelineColorBlendState *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_blend_constant();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		RDPipelineColorBlendState *js_proxy = static_cast<RDPipelineColorBlendState *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_blend_constant(value);
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
static JSValue rd_pipeline_color_blend_state_class_set_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendState::set_attachments, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_class_get_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendState::get_attachments, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry rd_pipeline_color_blend_state_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_enable_logic_op", 1, &rd_pipeline_color_blend_state_class_set_enable_logic_op),
	JS_CFUNC_DEF("get_enable_logic_op", 0, &rd_pipeline_color_blend_state_class_get_enable_logic_op),
	JS_CFUNC_DEF("set_logic_op", 1, &rd_pipeline_color_blend_state_class_set_logic_op),
	JS_CFUNC_DEF("get_logic_op", 0, &rd_pipeline_color_blend_state_class_get_logic_op),
	JS_CFUNC_DEF("set_blend_constant", 1, &rd_pipeline_color_blend_state_class_set_blend_constant),
	JS_CFUNC_DEF("get_blend_constant", 0, &rd_pipeline_color_blend_state_class_get_blend_constant),
	JS_CFUNC_DEF("set_attachments", 1, &rd_pipeline_color_blend_state_class_set_attachments),
	JS_CFUNC_DEF("get_attachments", 0, &rd_pipeline_color_blend_state_class_get_attachments),
};




static void define_rd_pipeline_color_blend_state_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_logic_op"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_get_enable_logic_op, "get_enable_logic_op", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_set_enable_logic_op, "set_enable_logic_op", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "logic_op"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_get_logic_op, "get_logic_op", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_set_logic_op, "set_logic_op", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_constant"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_get_blend_constant, "get_blend_constant", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_set_blend_constant, "set_blend_constant", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "attachments"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_get_attachments, "get_attachments", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_class_set_attachments, "set_attachments", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_pipeline_color_blend_state_enum(JSContext *ctx, JSValue proto) {
}

static int js_rd_pipeline_color_blend_state_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDPipelineColorBlendState"] = class_id;
	classes_by_id[class_id] = "RDPipelineColorBlendState";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_pipeline_color_blend_state_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_pipeline_color_blend_state_property(ctx, proto);
	define_rd_pipeline_color_blend_state_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_pipeline_color_blend_state_class_proto_funcs, _countof(rd_pipeline_color_blend_state_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_pipeline_color_blend_state_class_constructor, "RDPipelineColorBlendState", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDPipelineColorBlendState", ctor);

	return 0;
}

JSModuleDef *_js_init_rd_pipeline_color_blend_state_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_pipeline_color_blend_state_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDPipelineColorBlendState");
	return m;
}

JSModuleDef *js_init_rd_pipeline_color_blend_state_module(JSContext *ctx) {
	return _js_init_rd_pipeline_color_blend_state_module(ctx, "@godot/classes/rd_pipeline_color_blend_state");
}

void __register_rd_pipeline_color_blend_state() {
	js_init_rd_pipeline_color_blend_state_module(js_context());
}

void register_rd_pipeline_color_blend_state() {
	__register_rd_pipeline_color_blend_state();
}