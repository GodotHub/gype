#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/noise.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/fast_noise_lite.hpp>
using namespace godot;

static void fast_noise_lite_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FastNoiseLite"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef fast_noise_lite_class_def = {
    "FastNoiseLite",
    fast_noise_lite_class_finalizer
};

static JSValue fast_noise_lite_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FastNoiseLite"];
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
        instance = memnew(FastNoiseLite);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue fast_noise_lite_class_set_noise_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_noise_type, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_noise_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_noise_type, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_seed, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_seed, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_frequency, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_frequency, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_offset, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		FastNoiseLite *obj = static_cast<FastNoiseLite *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		FastNoiseLite *js_proxy = static_cast<FastNoiseLite *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue fast_noise_lite_class_set_fractal_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_fractal_type, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_fractal_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_fractal_type, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_fractal_octaves(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_fractal_octaves, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_fractal_octaves(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_fractal_octaves, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_fractal_lacunarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_fractal_lacunarity, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_fractal_lacunarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_fractal_lacunarity, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_fractal_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_fractal_gain, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_fractal_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_fractal_gain, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_fractal_weighted_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_fractal_weighted_strength, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_fractal_weighted_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_fractal_weighted_strength, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_fractal_ping_pong_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_fractal_ping_pong_strength, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_fractal_ping_pong_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_fractal_ping_pong_strength, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_cellular_distance_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_cellular_distance_function, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_cellular_distance_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_cellular_distance_function, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_cellular_jitter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_cellular_jitter, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_cellular_jitter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_cellular_jitter, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_cellular_return_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_cellular_return_type, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_cellular_return_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_cellular_return_type, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_enabled, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_is_domain_warp_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::is_domain_warp_enabled, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_type, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_type, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_amplitude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_amplitude, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_amplitude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_amplitude, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_frequency, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_frequency, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_fractal_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_fractal_type, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_fractal_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_fractal_type, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_fractal_octaves(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_fractal_octaves, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_fractal_octaves(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_fractal_octaves, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_fractal_lacunarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_fractal_lacunarity, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_fractal_lacunarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_fractal_lacunarity, ctx, this_val, argc, argv);
}
static JSValue fast_noise_lite_class_set_domain_warp_fractal_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FastNoiseLite::set_domain_warp_fractal_gain, ctx, this_val, argc, argv);
};
static JSValue fast_noise_lite_class_get_domain_warp_fractal_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FastNoiseLite::get_domain_warp_fractal_gain, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry fast_noise_lite_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_noise_type", 1, &fast_noise_lite_class_set_noise_type),
	JS_CFUNC_DEF("get_noise_type", 0, &fast_noise_lite_class_get_noise_type),
	JS_CFUNC_DEF("set_seed", 1, &fast_noise_lite_class_set_seed),
	JS_CFUNC_DEF("get_seed", 0, &fast_noise_lite_class_get_seed),
	JS_CFUNC_DEF("set_frequency", 1, &fast_noise_lite_class_set_frequency),
	JS_CFUNC_DEF("get_frequency", 0, &fast_noise_lite_class_get_frequency),
	JS_CFUNC_DEF("set_offset", 1, &fast_noise_lite_class_set_offset),
	JS_CFUNC_DEF("get_offset", 0, &fast_noise_lite_class_get_offset),
	JS_CFUNC_DEF("set_fractal_type", 1, &fast_noise_lite_class_set_fractal_type),
	JS_CFUNC_DEF("get_fractal_type", 0, &fast_noise_lite_class_get_fractal_type),
	JS_CFUNC_DEF("set_fractal_octaves", 1, &fast_noise_lite_class_set_fractal_octaves),
	JS_CFUNC_DEF("get_fractal_octaves", 0, &fast_noise_lite_class_get_fractal_octaves),
	JS_CFUNC_DEF("set_fractal_lacunarity", 1, &fast_noise_lite_class_set_fractal_lacunarity),
	JS_CFUNC_DEF("get_fractal_lacunarity", 0, &fast_noise_lite_class_get_fractal_lacunarity),
	JS_CFUNC_DEF("set_fractal_gain", 1, &fast_noise_lite_class_set_fractal_gain),
	JS_CFUNC_DEF("get_fractal_gain", 0, &fast_noise_lite_class_get_fractal_gain),
	JS_CFUNC_DEF("set_fractal_weighted_strength", 1, &fast_noise_lite_class_set_fractal_weighted_strength),
	JS_CFUNC_DEF("get_fractal_weighted_strength", 0, &fast_noise_lite_class_get_fractal_weighted_strength),
	JS_CFUNC_DEF("set_fractal_ping_pong_strength", 1, &fast_noise_lite_class_set_fractal_ping_pong_strength),
	JS_CFUNC_DEF("get_fractal_ping_pong_strength", 0, &fast_noise_lite_class_get_fractal_ping_pong_strength),
	JS_CFUNC_DEF("set_cellular_distance_function", 1, &fast_noise_lite_class_set_cellular_distance_function),
	JS_CFUNC_DEF("get_cellular_distance_function", 0, &fast_noise_lite_class_get_cellular_distance_function),
	JS_CFUNC_DEF("set_cellular_jitter", 1, &fast_noise_lite_class_set_cellular_jitter),
	JS_CFUNC_DEF("get_cellular_jitter", 0, &fast_noise_lite_class_get_cellular_jitter),
	JS_CFUNC_DEF("set_cellular_return_type", 1, &fast_noise_lite_class_set_cellular_return_type),
	JS_CFUNC_DEF("get_cellular_return_type", 0, &fast_noise_lite_class_get_cellular_return_type),
	JS_CFUNC_DEF("set_domain_warp_enabled", 1, &fast_noise_lite_class_set_domain_warp_enabled),
	JS_CFUNC_DEF("is_domain_warp_enabled", 0, &fast_noise_lite_class_is_domain_warp_enabled),
	JS_CFUNC_DEF("set_domain_warp_type", 1, &fast_noise_lite_class_set_domain_warp_type),
	JS_CFUNC_DEF("get_domain_warp_type", 0, &fast_noise_lite_class_get_domain_warp_type),
	JS_CFUNC_DEF("set_domain_warp_amplitude", 1, &fast_noise_lite_class_set_domain_warp_amplitude),
	JS_CFUNC_DEF("get_domain_warp_amplitude", 0, &fast_noise_lite_class_get_domain_warp_amplitude),
	JS_CFUNC_DEF("set_domain_warp_frequency", 1, &fast_noise_lite_class_set_domain_warp_frequency),
	JS_CFUNC_DEF("get_domain_warp_frequency", 0, &fast_noise_lite_class_get_domain_warp_frequency),
	JS_CFUNC_DEF("set_domain_warp_fractal_type", 1, &fast_noise_lite_class_set_domain_warp_fractal_type),
	JS_CFUNC_DEF("get_domain_warp_fractal_type", 0, &fast_noise_lite_class_get_domain_warp_fractal_type),
	JS_CFUNC_DEF("set_domain_warp_fractal_octaves", 1, &fast_noise_lite_class_set_domain_warp_fractal_octaves),
	JS_CFUNC_DEF("get_domain_warp_fractal_octaves", 0, &fast_noise_lite_class_get_domain_warp_fractal_octaves),
	JS_CFUNC_DEF("set_domain_warp_fractal_lacunarity", 1, &fast_noise_lite_class_set_domain_warp_fractal_lacunarity),
	JS_CFUNC_DEF("get_domain_warp_fractal_lacunarity", 0, &fast_noise_lite_class_get_domain_warp_fractal_lacunarity),
	JS_CFUNC_DEF("set_domain_warp_fractal_gain", 1, &fast_noise_lite_class_set_domain_warp_fractal_gain),
	JS_CFUNC_DEF("get_domain_warp_fractal_gain", 0, &fast_noise_lite_class_get_domain_warp_fractal_gain),
};




static void define_fast_noise_lite_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "noise_type"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_noise_type, "get_noise_type", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_noise_type, "set_noise_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "seed"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_seed, "get_seed", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_seed, "set_seed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frequency"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_frequency, "get_frequency", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_frequency, "set_frequency", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fractal_type"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_fractal_type, "get_fractal_type", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_fractal_type, "set_fractal_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fractal_octaves"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_fractal_octaves, "get_fractal_octaves", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_fractal_octaves, "set_fractal_octaves", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fractal_lacunarity"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_fractal_lacunarity, "get_fractal_lacunarity", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_fractal_lacunarity, "set_fractal_lacunarity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fractal_gain"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_fractal_gain, "get_fractal_gain", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_fractal_gain, "set_fractal_gain", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fractal_weighted_strength"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_fractal_weighted_strength, "get_fractal_weighted_strength", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_fractal_weighted_strength, "set_fractal_weighted_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fractal_ping_pong_strength"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_fractal_ping_pong_strength, "get_fractal_ping_pong_strength", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_fractal_ping_pong_strength, "set_fractal_ping_pong_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cellular_distance_function"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_cellular_distance_function, "get_cellular_distance_function", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_cellular_distance_function, "set_cellular_distance_function", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cellular_jitter"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_cellular_jitter, "get_cellular_jitter", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_cellular_jitter, "set_cellular_jitter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cellular_return_type"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_cellular_return_type, "get_cellular_return_type", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_cellular_return_type, "set_cellular_return_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_enabled"),
        JS_NewCFunction(ctx, fast_noise_lite_class_is_domain_warp_enabled, "is_domain_warp_enabled", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_enabled, "set_domain_warp_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_type"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_type, "get_domain_warp_type", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_type, "set_domain_warp_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_amplitude"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_amplitude, "get_domain_warp_amplitude", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_amplitude, "set_domain_warp_amplitude", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_frequency"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_frequency, "get_domain_warp_frequency", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_frequency, "set_domain_warp_frequency", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_fractal_type"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_fractal_type, "get_domain_warp_fractal_type", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_fractal_type, "set_domain_warp_fractal_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_fractal_octaves"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_fractal_octaves, "get_domain_warp_fractal_octaves", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_fractal_octaves, "set_domain_warp_fractal_octaves", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_fractal_lacunarity"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_fractal_lacunarity, "get_domain_warp_fractal_lacunarity", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_fractal_lacunarity, "set_domain_warp_fractal_lacunarity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "domain_warp_fractal_gain"),
        JS_NewCFunction(ctx, fast_noise_lite_class_get_domain_warp_fractal_gain, "get_domain_warp_fractal_gain", 0),
        JS_NewCFunction(ctx, fast_noise_lite_class_set_domain_warp_fractal_gain, "set_domain_warp_fractal_gain", 1),
        JS_PROP_GETSET
    );
}

static void define_fast_noise_lite_enum(JSContext *ctx, JSValue ctor) {
	JSValue NoiseType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, NoiseType_obj, "TYPE_VALUE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, NoiseType_obj, "TYPE_VALUE_CUBIC", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, NoiseType_obj, "TYPE_PERLIN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, NoiseType_obj, "TYPE_CELLULAR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, NoiseType_obj, "TYPE_SIMPLEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, NoiseType_obj, "TYPE_SIMPLEX_SMOOTH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "NoiseType", NoiseType_obj);
	JSValue FractalType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FractalType_obj, "FRACTAL_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FractalType_obj, "FRACTAL_FBM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FractalType_obj, "FRACTAL_RIDGED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FractalType_obj, "FRACTAL_PING_PONG", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "FractalType", FractalType_obj);
	JSValue CellularDistanceFunction_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CellularDistanceFunction_obj, "DISTANCE_EUCLIDEAN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CellularDistanceFunction_obj, "DISTANCE_EUCLIDEAN_SQUARED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CellularDistanceFunction_obj, "DISTANCE_MANHATTAN", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CellularDistanceFunction_obj, "DISTANCE_HYBRID", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "CellularDistanceFunction", CellularDistanceFunction_obj);
	JSValue CellularReturnType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_CELL_VALUE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_DISTANCE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_DISTANCE2", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_DISTANCE2_ADD", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_DISTANCE2_SUB", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_DISTANCE2_MUL", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CellularReturnType_obj, "RETURN_DISTANCE2_DIV", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "CellularReturnType", CellularReturnType_obj);
	JSValue DomainWarpType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DomainWarpType_obj, "DOMAIN_WARP_SIMPLEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DomainWarpType_obj, "DOMAIN_WARP_SIMPLEX_REDUCED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DomainWarpType_obj, "DOMAIN_WARP_BASIC_GRID", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DomainWarpType", DomainWarpType_obj);
	JSValue DomainWarpFractalType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DomainWarpFractalType_obj, "DOMAIN_WARP_FRACTAL_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DomainWarpFractalType_obj, "DOMAIN_WARP_FRACTAL_PROGRESSIVE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DomainWarpFractalType_obj, "DOMAIN_WARP_FRACTAL_INDEPENDENT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DomainWarpFractalType", DomainWarpFractalType_obj);
}

static int js_fast_noise_lite_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FastNoiseLite"] = class_id;
	classes_by_id[class_id] = "FastNoiseLite";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &fast_noise_lite_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Noise"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_fast_noise_lite_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, fast_noise_lite_class_proto_funcs, _countof(fast_noise_lite_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, fast_noise_lite_class_constructor, "FastNoiseLite", 0, JS_CFUNC_constructor, 0);
	define_fast_noise_lite_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FastNoiseLite", ctor);
	ctor_list["FastNoiseLite"] = ctor;

	return 0;
}

JSModuleDef *_js_init_fast_noise_lite_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/noise';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_fast_noise_lite_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FastNoiseLite");
	return m;
}

JSModuleDef *js_init_fast_noise_lite_module(JSContext *ctx) {
	return _js_init_fast_noise_lite_module(ctx, "@godot/classes/fast_noise_lite");
}

void __register_fast_noise_lite() {
	js_init_fast_noise_lite_module(js_context());
}

void register_fast_noise_lite() {
	__register_fast_noise_lite();
}