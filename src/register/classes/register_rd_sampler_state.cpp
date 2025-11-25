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
#include <godot_cpp/classes/rd_sampler_state.hpp>
using namespace godot;

static void rd_sampler_state_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDSamplerState"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_sampler_state_class_def = {
    "RDSamplerState",
    rd_sampler_state_class_finalizer
};

static JSValue rd_sampler_state_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDSamplerState"];
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
        instance = memnew(RDSamplerState);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_sampler_state_class_set_mag_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_mag_filter, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_mag_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_mag_filter, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_min_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_min_filter, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_min_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_min_filter, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_mip_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_mip_filter, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_mip_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_mip_filter, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_repeat_u(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_repeat_u, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_repeat_u(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_repeat_u, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_repeat_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_repeat_v, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_repeat_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_repeat_v, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_repeat_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_repeat_w, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_repeat_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_repeat_w, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_lod_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_lod_bias, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_lod_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_lod_bias, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_use_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_use_anisotropy, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_use_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_use_anisotropy, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_anisotropy_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_anisotropy_max, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_anisotropy_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_anisotropy_max, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_enable_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_enable_compare, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_enable_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_enable_compare, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_compare_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_compare_op, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_compare_op(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_compare_op, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_min_lod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_min_lod, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_min_lod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_min_lod, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_max_lod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_max_lod, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_max_lod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_max_lod, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_border_color, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_border_color, ctx, this_val, argc, argv);
}
static JSValue rd_sampler_state_class_set_unnormalized_uvw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDSamplerState::set_unnormalized_uvw, ctx, this_val, argc, argv);
};
static JSValue rd_sampler_state_class_get_unnormalized_uvw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDSamplerState::get_unnormalized_uvw, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_sampler_state_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mag_filter", 1, &rd_sampler_state_class_set_mag_filter),
	JS_CFUNC_DEF("get_mag_filter", 0, &rd_sampler_state_class_get_mag_filter),
	JS_CFUNC_DEF("set_min_filter", 1, &rd_sampler_state_class_set_min_filter),
	JS_CFUNC_DEF("get_min_filter", 0, &rd_sampler_state_class_get_min_filter),
	JS_CFUNC_DEF("set_mip_filter", 1, &rd_sampler_state_class_set_mip_filter),
	JS_CFUNC_DEF("get_mip_filter", 0, &rd_sampler_state_class_get_mip_filter),
	JS_CFUNC_DEF("set_repeat_u", 1, &rd_sampler_state_class_set_repeat_u),
	JS_CFUNC_DEF("get_repeat_u", 0, &rd_sampler_state_class_get_repeat_u),
	JS_CFUNC_DEF("set_repeat_v", 1, &rd_sampler_state_class_set_repeat_v),
	JS_CFUNC_DEF("get_repeat_v", 0, &rd_sampler_state_class_get_repeat_v),
	JS_CFUNC_DEF("set_repeat_w", 1, &rd_sampler_state_class_set_repeat_w),
	JS_CFUNC_DEF("get_repeat_w", 0, &rd_sampler_state_class_get_repeat_w),
	JS_CFUNC_DEF("set_lod_bias", 1, &rd_sampler_state_class_set_lod_bias),
	JS_CFUNC_DEF("get_lod_bias", 0, &rd_sampler_state_class_get_lod_bias),
	JS_CFUNC_DEF("set_use_anisotropy", 1, &rd_sampler_state_class_set_use_anisotropy),
	JS_CFUNC_DEF("get_use_anisotropy", 0, &rd_sampler_state_class_get_use_anisotropy),
	JS_CFUNC_DEF("set_anisotropy_max", 1, &rd_sampler_state_class_set_anisotropy_max),
	JS_CFUNC_DEF("get_anisotropy_max", 0, &rd_sampler_state_class_get_anisotropy_max),
	JS_CFUNC_DEF("set_enable_compare", 1, &rd_sampler_state_class_set_enable_compare),
	JS_CFUNC_DEF("get_enable_compare", 0, &rd_sampler_state_class_get_enable_compare),
	JS_CFUNC_DEF("set_compare_op", 1, &rd_sampler_state_class_set_compare_op),
	JS_CFUNC_DEF("get_compare_op", 0, &rd_sampler_state_class_get_compare_op),
	JS_CFUNC_DEF("set_min_lod", 1, &rd_sampler_state_class_set_min_lod),
	JS_CFUNC_DEF("get_min_lod", 0, &rd_sampler_state_class_get_min_lod),
	JS_CFUNC_DEF("set_max_lod", 1, &rd_sampler_state_class_set_max_lod),
	JS_CFUNC_DEF("get_max_lod", 0, &rd_sampler_state_class_get_max_lod),
	JS_CFUNC_DEF("set_border_color", 1, &rd_sampler_state_class_set_border_color),
	JS_CFUNC_DEF("get_border_color", 0, &rd_sampler_state_class_get_border_color),
	JS_CFUNC_DEF("set_unnormalized_uvw", 1, &rd_sampler_state_class_set_unnormalized_uvw),
	JS_CFUNC_DEF("get_unnormalized_uvw", 0, &rd_sampler_state_class_get_unnormalized_uvw),
};




static void define_rd_sampler_state_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mag_filter"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_mag_filter, "get_mag_filter", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_mag_filter, "set_mag_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "min_filter"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_min_filter, "get_min_filter", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_min_filter, "set_min_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mip_filter"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_mip_filter, "get_mip_filter", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_mip_filter, "set_mip_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "repeat_u"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_repeat_u, "get_repeat_u", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_repeat_u, "set_repeat_u", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "repeat_v"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_repeat_v, "get_repeat_v", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_repeat_v, "set_repeat_v", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "repeat_w"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_repeat_w, "get_repeat_w", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_repeat_w, "set_repeat_w", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lod_bias"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_lod_bias, "get_lod_bias", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_lod_bias, "set_lod_bias", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_anisotropy"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_use_anisotropy, "get_use_anisotropy", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_use_anisotropy, "set_use_anisotropy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "anisotropy_max"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_anisotropy_max, "get_anisotropy_max", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_anisotropy_max, "set_anisotropy_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_compare"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_enable_compare, "get_enable_compare", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_enable_compare, "set_enable_compare", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "compare_op"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_compare_op, "get_compare_op", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_compare_op, "set_compare_op", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "min_lod"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_min_lod, "get_min_lod", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_min_lod, "set_min_lod", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_lod"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_max_lod, "get_max_lod", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_max_lod, "set_max_lod", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_color"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_border_color, "get_border_color", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_border_color, "set_border_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unnormalized_uvw"),
        JS_NewCFunction(ctx, rd_sampler_state_class_get_unnormalized_uvw, "get_unnormalized_uvw", 0),
        JS_NewCFunction(ctx, rd_sampler_state_class_set_unnormalized_uvw, "set_unnormalized_uvw", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_sampler_state_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_sampler_state_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDSamplerState"] = class_id;
	classes_by_id[class_id] = "RDSamplerState";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_sampler_state_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_sampler_state_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_sampler_state_class_proto_funcs, _countof(rd_sampler_state_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_sampler_state_class_constructor, "RDSamplerState", 0, JS_CFUNC_constructor, 0);
	define_rd_sampler_state_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDSamplerState", ctor);
	ctor_list["RDSamplerState"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_sampler_state_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_sampler_state_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDSamplerState");
	return m;
}

JSModuleDef *js_init_rd_sampler_state_module(JSContext *ctx) {
	return _js_init_rd_sampler_state_module(ctx, "@godot/classes/rd_sampler_state");
}

void __register_rd_sampler_state() {
	js_init_rd_sampler_state_module(js_context());
}

void register_rd_sampler_state() {
	__register_rd_sampler_state();
}