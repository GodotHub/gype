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
#include <godot_cpp/classes/rd_pipeline_color_blend_state_attachment.hpp>
using namespace godot;

static void rd_pipeline_color_blend_state_attachment_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDPipelineColorBlendStateAttachment"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_pipeline_color_blend_state_attachment_class_def = {
    "RDPipelineColorBlendStateAttachment",
    rd_pipeline_color_blend_state_attachment_class_finalizer
};

static JSValue rd_pipeline_color_blend_state_attachment_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDPipelineColorBlendStateAttachment"];
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
        instance = memnew(RDPipelineColorBlendStateAttachment);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_pipeline_color_blend_state_attachment_class_set_as_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_as_mix, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_set_enable_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_enable_blend, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_enable_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_enable_blend, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_src_color_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_src_color_blend_factor, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_src_color_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_src_color_blend_factor, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_dst_color_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_dst_color_blend_factor, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_dst_color_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_dst_color_blend_factor, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_color_blend_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_color_blend_op, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_color_blend_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_color_blend_op, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_src_alpha_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_src_alpha_blend_factor, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_src_alpha_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_src_alpha_blend_factor, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_dst_alpha_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_dst_alpha_blend_factor, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_dst_alpha_blend_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_dst_alpha_blend_factor, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_alpha_blend_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_alpha_blend_op, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_alpha_blend_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_alpha_blend_op, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_write_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_write_r, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_write_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_write_r, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_write_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_write_g, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_write_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_write_g, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_write_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_write_b, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_write_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_write_b, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_color_blend_state_attachment_class_set_write_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineColorBlendStateAttachment::set_write_a, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_color_blend_state_attachment_class_get_write_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineColorBlendStateAttachment::get_write_a, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_pipeline_color_blend_state_attachment_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_as_mix", 0, &rd_pipeline_color_blend_state_attachment_class_set_as_mix),
	JS_CFUNC_DEF("set_enable_blend", 1, &rd_pipeline_color_blend_state_attachment_class_set_enable_blend),
	JS_CFUNC_DEF("get_enable_blend", 0, &rd_pipeline_color_blend_state_attachment_class_get_enable_blend),
	JS_CFUNC_DEF("set_src_color_blend_factor", 1, &rd_pipeline_color_blend_state_attachment_class_set_src_color_blend_factor),
	JS_CFUNC_DEF("get_src_color_blend_factor", 0, &rd_pipeline_color_blend_state_attachment_class_get_src_color_blend_factor),
	JS_CFUNC_DEF("set_dst_color_blend_factor", 1, &rd_pipeline_color_blend_state_attachment_class_set_dst_color_blend_factor),
	JS_CFUNC_DEF("get_dst_color_blend_factor", 0, &rd_pipeline_color_blend_state_attachment_class_get_dst_color_blend_factor),
	JS_CFUNC_DEF("set_color_blend_op", 1, &rd_pipeline_color_blend_state_attachment_class_set_color_blend_op),
	JS_CFUNC_DEF("get_color_blend_op", 0, &rd_pipeline_color_blend_state_attachment_class_get_color_blend_op),
	JS_CFUNC_DEF("set_src_alpha_blend_factor", 1, &rd_pipeline_color_blend_state_attachment_class_set_src_alpha_blend_factor),
	JS_CFUNC_DEF("get_src_alpha_blend_factor", 0, &rd_pipeline_color_blend_state_attachment_class_get_src_alpha_blend_factor),
	JS_CFUNC_DEF("set_dst_alpha_blend_factor", 1, &rd_pipeline_color_blend_state_attachment_class_set_dst_alpha_blend_factor),
	JS_CFUNC_DEF("get_dst_alpha_blend_factor", 0, &rd_pipeline_color_blend_state_attachment_class_get_dst_alpha_blend_factor),
	JS_CFUNC_DEF("set_alpha_blend_op", 1, &rd_pipeline_color_blend_state_attachment_class_set_alpha_blend_op),
	JS_CFUNC_DEF("get_alpha_blend_op", 0, &rd_pipeline_color_blend_state_attachment_class_get_alpha_blend_op),
	JS_CFUNC_DEF("set_write_r", 1, &rd_pipeline_color_blend_state_attachment_class_set_write_r),
	JS_CFUNC_DEF("get_write_r", 0, &rd_pipeline_color_blend_state_attachment_class_get_write_r),
	JS_CFUNC_DEF("set_write_g", 1, &rd_pipeline_color_blend_state_attachment_class_set_write_g),
	JS_CFUNC_DEF("get_write_g", 0, &rd_pipeline_color_blend_state_attachment_class_get_write_g),
	JS_CFUNC_DEF("set_write_b", 1, &rd_pipeline_color_blend_state_attachment_class_set_write_b),
	JS_CFUNC_DEF("get_write_b", 0, &rd_pipeline_color_blend_state_attachment_class_get_write_b),
	JS_CFUNC_DEF("set_write_a", 1, &rd_pipeline_color_blend_state_attachment_class_set_write_a),
	JS_CFUNC_DEF("get_write_a", 0, &rd_pipeline_color_blend_state_attachment_class_get_write_a),
};




static void define_rd_pipeline_color_blend_state_attachment_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_blend"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_enable_blend, "get_enable_blend", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_enable_blend, "set_enable_blend", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "src_color_blend_factor"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_src_color_blend_factor, "get_src_color_blend_factor", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_src_color_blend_factor, "set_src_color_blend_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dst_color_blend_factor"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_dst_color_blend_factor, "get_dst_color_blend_factor", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_dst_color_blend_factor, "set_dst_color_blend_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_blend_op"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_color_blend_op, "get_color_blend_op", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_color_blend_op, "set_color_blend_op", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "src_alpha_blend_factor"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_src_alpha_blend_factor, "get_src_alpha_blend_factor", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_src_alpha_blend_factor, "set_src_alpha_blend_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dst_alpha_blend_factor"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_dst_alpha_blend_factor, "get_dst_alpha_blend_factor", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_dst_alpha_blend_factor, "set_dst_alpha_blend_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_blend_op"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_alpha_blend_op, "get_alpha_blend_op", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_alpha_blend_op, "set_alpha_blend_op", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "write_r"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_write_r, "get_write_r", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_write_r, "set_write_r", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "write_g"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_write_g, "get_write_g", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_write_g, "set_write_g", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "write_b"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_write_b, "get_write_b", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_write_b, "set_write_b", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "write_a"),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_get_write_a, "get_write_a", 0),
        JS_NewCFunction(ctx, rd_pipeline_color_blend_state_attachment_class_set_write_a, "set_write_a", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_pipeline_color_blend_state_attachment_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_pipeline_color_blend_state_attachment_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDPipelineColorBlendStateAttachment"] = class_id;
	classes_by_id[class_id] = "RDPipelineColorBlendStateAttachment";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_pipeline_color_blend_state_attachment_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_pipeline_color_blend_state_attachment_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_pipeline_color_blend_state_attachment_class_proto_funcs, _countof(rd_pipeline_color_blend_state_attachment_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_pipeline_color_blend_state_attachment_class_constructor, "RDPipelineColorBlendStateAttachment", 0, JS_CFUNC_constructor, 0);
	define_rd_pipeline_color_blend_state_attachment_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDPipelineColorBlendStateAttachment", ctor);
	ctor_list["RDPipelineColorBlendStateAttachment"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_pipeline_color_blend_state_attachment_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_pipeline_color_blend_state_attachment_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDPipelineColorBlendStateAttachment");
	return m;
}

JSModuleDef *js_init_rd_pipeline_color_blend_state_attachment_module(JSContext *ctx) {
	return _js_init_rd_pipeline_color_blend_state_attachment_module(ctx, "@godot/classes/rd_pipeline_color_blend_state_attachment");
}

void __register_rd_pipeline_color_blend_state_attachment() {
	js_init_rd_pipeline_color_blend_state_attachment_module(js_context());
}

void register_rd_pipeline_color_blend_state_attachment() {
	__register_rd_pipeline_color_blend_state_attachment();
}