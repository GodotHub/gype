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
#include <godot_cpp/classes/rd_pipeline_depth_stencil_state.hpp>
using namespace godot;

static void rd_pipeline_depth_stencil_state_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDPipelineDepthStencilState"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_pipeline_depth_stencil_state_class_def = {
    "RDPipelineDepthStencilState",
    rd_pipeline_depth_stencil_state_class_finalizer
};

static JSValue rd_pipeline_depth_stencil_state_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDPipelineDepthStencilState"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RDPipelineDepthStencilState *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RDPipelineDepthStencilState *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RDPipelineDepthStencilState);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_pipeline_depth_stencil_state_class_set_enable_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_enable_depth_test, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_enable_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_enable_depth_test, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_enable_depth_write(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_enable_depth_write, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_enable_depth_write(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_enable_depth_write, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_depth_compare_operator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_depth_compare_operator, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_depth_compare_operator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_depth_compare_operator, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_enable_depth_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_enable_depth_range, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_enable_depth_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_enable_depth_range, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_depth_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_depth_range_min, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_depth_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_depth_range_min, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_depth_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_depth_range_max, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_depth_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_depth_range_max, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_enable_stencil(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_enable_stencil, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_enable_stencil(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_enable_stencil, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_fail, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_fail, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_pass, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_pass, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_depth_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_depth_fail, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_depth_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_depth_fail, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_compare, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_compare, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_compare_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_compare_mask, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_compare_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_compare_mask, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_write_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_write_mask, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_write_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_write_mask, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_front_op_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_front_op_reference, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_front_op_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_front_op_reference, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_fail, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_fail, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_pass, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_pass, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_depth_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_depth_fail, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_depth_fail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_depth_fail, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_compare, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_compare, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_compare_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_compare_mask, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_compare_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_compare_mask, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_write_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_write_mask, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_write_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_write_mask, ctx, this_val, argc, argv);
}
static JSValue rd_pipeline_depth_stencil_state_class_set_back_op_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDPipelineDepthStencilState::set_back_op_reference, ctx, this_val, argc, argv);
};
static JSValue rd_pipeline_depth_stencil_state_class_get_back_op_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDPipelineDepthStencilState::get_back_op_reference, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_pipeline_depth_stencil_state_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_enable_depth_test", 1, &rd_pipeline_depth_stencil_state_class_set_enable_depth_test),
	JS_CFUNC_DEF("get_enable_depth_test", 0, &rd_pipeline_depth_stencil_state_class_get_enable_depth_test),
	JS_CFUNC_DEF("set_enable_depth_write", 1, &rd_pipeline_depth_stencil_state_class_set_enable_depth_write),
	JS_CFUNC_DEF("get_enable_depth_write", 0, &rd_pipeline_depth_stencil_state_class_get_enable_depth_write),
	JS_CFUNC_DEF("set_depth_compare_operator", 1, &rd_pipeline_depth_stencil_state_class_set_depth_compare_operator),
	JS_CFUNC_DEF("get_depth_compare_operator", 0, &rd_pipeline_depth_stencil_state_class_get_depth_compare_operator),
	JS_CFUNC_DEF("set_enable_depth_range", 1, &rd_pipeline_depth_stencil_state_class_set_enable_depth_range),
	JS_CFUNC_DEF("get_enable_depth_range", 0, &rd_pipeline_depth_stencil_state_class_get_enable_depth_range),
	JS_CFUNC_DEF("set_depth_range_min", 1, &rd_pipeline_depth_stencil_state_class_set_depth_range_min),
	JS_CFUNC_DEF("get_depth_range_min", 0, &rd_pipeline_depth_stencil_state_class_get_depth_range_min),
	JS_CFUNC_DEF("set_depth_range_max", 1, &rd_pipeline_depth_stencil_state_class_set_depth_range_max),
	JS_CFUNC_DEF("get_depth_range_max", 0, &rd_pipeline_depth_stencil_state_class_get_depth_range_max),
	JS_CFUNC_DEF("set_enable_stencil", 1, &rd_pipeline_depth_stencil_state_class_set_enable_stencil),
	JS_CFUNC_DEF("get_enable_stencil", 0, &rd_pipeline_depth_stencil_state_class_get_enable_stencil),
	JS_CFUNC_DEF("set_front_op_fail", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_fail),
	JS_CFUNC_DEF("get_front_op_fail", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_fail),
	JS_CFUNC_DEF("set_front_op_pass", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_pass),
	JS_CFUNC_DEF("get_front_op_pass", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_pass),
	JS_CFUNC_DEF("set_front_op_depth_fail", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_depth_fail),
	JS_CFUNC_DEF("get_front_op_depth_fail", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_depth_fail),
	JS_CFUNC_DEF("set_front_op_compare", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_compare),
	JS_CFUNC_DEF("get_front_op_compare", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_compare),
	JS_CFUNC_DEF("set_front_op_compare_mask", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_compare_mask),
	JS_CFUNC_DEF("get_front_op_compare_mask", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_compare_mask),
	JS_CFUNC_DEF("set_front_op_write_mask", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_write_mask),
	JS_CFUNC_DEF("get_front_op_write_mask", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_write_mask),
	JS_CFUNC_DEF("set_front_op_reference", 1, &rd_pipeline_depth_stencil_state_class_set_front_op_reference),
	JS_CFUNC_DEF("get_front_op_reference", 0, &rd_pipeline_depth_stencil_state_class_get_front_op_reference),
	JS_CFUNC_DEF("set_back_op_fail", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_fail),
	JS_CFUNC_DEF("get_back_op_fail", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_fail),
	JS_CFUNC_DEF("set_back_op_pass", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_pass),
	JS_CFUNC_DEF("get_back_op_pass", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_pass),
	JS_CFUNC_DEF("set_back_op_depth_fail", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_depth_fail),
	JS_CFUNC_DEF("get_back_op_depth_fail", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_depth_fail),
	JS_CFUNC_DEF("set_back_op_compare", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_compare),
	JS_CFUNC_DEF("get_back_op_compare", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_compare),
	JS_CFUNC_DEF("set_back_op_compare_mask", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_compare_mask),
	JS_CFUNC_DEF("get_back_op_compare_mask", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_compare_mask),
	JS_CFUNC_DEF("set_back_op_write_mask", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_write_mask),
	JS_CFUNC_DEF("get_back_op_write_mask", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_write_mask),
	JS_CFUNC_DEF("set_back_op_reference", 1, &rd_pipeline_depth_stencil_state_class_set_back_op_reference),
	JS_CFUNC_DEF("get_back_op_reference", 0, &rd_pipeline_depth_stencil_state_class_get_back_op_reference),
};




static void define_rd_pipeline_depth_stencil_state_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_depth_test"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_enable_depth_test, "get_enable_depth_test", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_enable_depth_test, "set_enable_depth_test", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_depth_write"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_enable_depth_write, "get_enable_depth_write", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_enable_depth_write, "set_enable_depth_write", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth_compare_operator"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_depth_compare_operator, "get_depth_compare_operator", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_depth_compare_operator, "set_depth_compare_operator", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_depth_range"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_enable_depth_range, "get_enable_depth_range", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_enable_depth_range, "set_enable_depth_range", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth_range_min"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_depth_range_min, "get_depth_range_min", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_depth_range_min, "set_depth_range_min", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth_range_max"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_depth_range_max, "get_depth_range_max", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_depth_range_max, "set_depth_range_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_stencil"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_enable_stencil, "get_enable_stencil", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_enable_stencil, "set_enable_stencil", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_fail"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_fail, "get_front_op_fail", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_fail, "set_front_op_fail", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_pass"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_pass, "get_front_op_pass", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_pass, "set_front_op_pass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_depth_fail"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_depth_fail, "get_front_op_depth_fail", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_depth_fail, "set_front_op_depth_fail", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_compare"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_compare, "get_front_op_compare", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_compare, "set_front_op_compare", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_compare_mask"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_compare_mask, "get_front_op_compare_mask", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_compare_mask, "set_front_op_compare_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_write_mask"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_write_mask, "get_front_op_write_mask", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_write_mask, "set_front_op_write_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "front_op_reference"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_front_op_reference, "get_front_op_reference", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_front_op_reference, "set_front_op_reference", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_fail"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_fail, "get_back_op_fail", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_fail, "set_back_op_fail", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_pass"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_pass, "get_back_op_pass", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_pass, "set_back_op_pass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_depth_fail"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_depth_fail, "get_back_op_depth_fail", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_depth_fail, "set_back_op_depth_fail", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_compare"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_compare, "get_back_op_compare", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_compare, "set_back_op_compare", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_compare_mask"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_compare_mask, "get_back_op_compare_mask", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_compare_mask, "set_back_op_compare_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_write_mask"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_write_mask, "get_back_op_write_mask", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_write_mask, "set_back_op_write_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "back_op_reference"),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_get_back_op_reference, "get_back_op_reference", 0),
        JS_NewCFunction(ctx, rd_pipeline_depth_stencil_state_class_set_back_op_reference, "set_back_op_reference", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_pipeline_depth_stencil_state_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_pipeline_depth_stencil_state_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDPipelineDepthStencilState"] = class_id;
	classes_by_id[class_id] = "RDPipelineDepthStencilState";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_pipeline_depth_stencil_state_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_pipeline_depth_stencil_state_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_pipeline_depth_stencil_state_class_proto_funcs, _countof(rd_pipeline_depth_stencil_state_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_pipeline_depth_stencil_state_class_constructor, "RDPipelineDepthStencilState", 0, JS_CFUNC_constructor, 0);
	define_rd_pipeline_depth_stencil_state_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDPipelineDepthStencilState", ctor);

	return 0;
}

JSModuleDef *_js_init_rd_pipeline_depth_stencil_state_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_pipeline_depth_stencil_state_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDPipelineDepthStencilState");
	return m;
}

JSModuleDef *js_init_rd_pipeline_depth_stencil_state_module(JSContext *ctx) {
	return _js_init_rd_pipeline_depth_stencil_state_module(ctx, "@godot/classes/rd_pipeline_depth_stencil_state");
}

void __register_rd_pipeline_depth_stencil_state() {
	js_init_rd_pipeline_depth_stencil_state_module(js_context());
}

void register_rd_pipeline_depth_stencil_state() {
	__register_rd_pipeline_depth_stencil_state();
}