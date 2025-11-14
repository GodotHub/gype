#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/vector3.hpp>


using namespace godot;

static void quaternion_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Quaternion"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef quaternion_class_def = {
	"Quaternion",
	quaternion_class_finalizer
};

static JSValue quaternion_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Quaternion"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Quaternion instance;
	if (argc == 0) {
		instance = Quaternion();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::QUATERNION)) {
		Quaternion v0 = VariantAdapter(argv[0]).get();
		instance = Quaternion(v0);
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::BASIS)) {
		Basis v0 = VariantAdapter(argv[0]).get();
		instance = Quaternion(v0);
	}
	if (argc == 2&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR3)&&JS_IsNumber(argv[1])) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		instance = Quaternion(v0, v1);
	}
	if (argc == 2&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR3)&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR3)) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		Vector3 v1 = VariantAdapter(argv[1]).get();
		instance = Quaternion(v0, v1);
	}
	if (argc == 4&&JS_IsNumber(argv[0])&&JS_IsNumber(argv[1])&&JS_IsNumber(argv[2])&&JS_IsNumber(argv[3])) {
		double v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		double v3 = VariantAdapter(argv[3]).get();
		instance = Quaternion(v0, v1, v2, v3);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue quaternion_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::length, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::length_squared, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::normalized, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::is_normalized, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::is_finite, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::inverse, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::log, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_exp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::exp, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::angle_to, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_dot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::dot, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::slerp, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_slerpni(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::slerpni, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_spherical_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::spherical_cubic_interpolate, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_spherical_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::spherical_cubic_interpolate_in_time, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_get_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::get_euler, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_from_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Quaternion::from_euler, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_get_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::get_axis, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_get_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::get_angle, ctx, this_val, argc, argv);
}

static JSValue quaternion_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]))->get();
	return VariantAdapter(val.x);
	
}
static JSValue quaternion_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]));
    Quaternion val = adapter->get();
    val.x = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue quaternion_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]))->get();
	return VariantAdapter(val.y);
	
}
static JSValue quaternion_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]));
    Quaternion val = adapter->get();
    val.y = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue quaternion_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]))->get();
	return VariantAdapter(val.z);
	
}
static JSValue quaternion_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]));
    Quaternion val = adapter->get();
    val.z = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue quaternion_class_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]))->get();
	return VariantAdapter(val.w);
	
}
static JSValue quaternion_class_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Quaternion"]));
    Quaternion val = adapter->get();
    val.w = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry quaternion_class_proto_funcs[] = {
	JS_CFUNC_DEF("length", 0, &quaternion_class_length),
	JS_CFUNC_DEF("length_squared", 0, &quaternion_class_length_squared),
	JS_CFUNC_DEF("normalized", 0, &quaternion_class_normalized),
	JS_CFUNC_DEF("is_normalized", 0, &quaternion_class_is_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &quaternion_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &quaternion_class_is_finite),
	JS_CFUNC_DEF("inverse", 0, &quaternion_class_inverse),
	JS_CFUNC_DEF("log", 0, &quaternion_class_log),
	JS_CFUNC_DEF("exp", 0, &quaternion_class_exp),
	JS_CFUNC_DEF("angle_to", 1, &quaternion_class_angle_to),
	JS_CFUNC_DEF("dot", 1, &quaternion_class_dot),
	JS_CFUNC_DEF("slerp", 2, &quaternion_class_slerp),
	JS_CFUNC_DEF("slerpni", 2, &quaternion_class_slerpni),
	JS_CFUNC_DEF("spherical_cubic_interpolate", 4, &quaternion_class_spherical_cubic_interpolate),
	JS_CFUNC_DEF("spherical_cubic_interpolate_in_time", 7, &quaternion_class_spherical_cubic_interpolate_in_time),
	JS_CFUNC_DEF("get_euler", 1, &quaternion_class_get_euler),
	JS_CFUNC_DEF("from_euler", 1, &quaternion_class_from_euler),
	JS_CFUNC_DEF("get_axis", 0, &quaternion_class_get_axis),
	JS_CFUNC_DEF("get_angle", 0, &quaternion_class_get_angle),
};

static void define_quaternion_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, quaternion_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, quaternion_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, quaternion_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, quaternion_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, quaternion_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, quaternion_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, quaternion_class_get_w, "get_w", 0),
			JS_NewCFunction(ctx, quaternion_class_set_w, "set_w", 1),
			JS_PROP_GETSET);
}

static int js_quaternion_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Quaternion"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Quaternion";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &quaternion_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_quaternion_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, quaternion_class_proto_funcs, _countof(quaternion_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, quaternion_class_constructor, "Quaternion", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Quaternion", ctor);

	return 0;
}

static void js_init_quaternion_module(JSContext *ctx) {
	js_quaternion_class_init(ctx);
}

void register_quaternion() {
	js_init_quaternion_module(js_context());
}

// ------------------QuaternionProxy------------------
static void quaternion_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["QuaternionProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Quaternion> *>(proxy));
	}
}

static JSClassDef quaternion_proxy_def = {
	"QuaternionProxy",
	quaternion_proxy_finalizer
};


static JSValue quaternion_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["QuaternionProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Quaternion> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Quaternion> *>(JS_GetAnyOpaque(*argv, &opaque_id));
	} else {
		return JS_EXCEPTION;
	}

	if (!proxy) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	return obj;
}

static JSValue quaternion_proxy_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::length, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::length_squared, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::normalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::is_normalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::is_finite, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::inverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::log, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_exp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::exp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::angle_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_dot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::dot, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::slerp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_slerpni(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::slerpni, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_spherical_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::spherical_cubic_interpolate, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_spherical_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::spherical_cubic_interpolate_in_time, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_get_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::get_euler, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_from_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Quaternion::from_euler, ctx, this_val, argc, argv);
}
static JSValue quaternion_proxy_get_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::get_axis, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue quaternion_proxy_get_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Quaternion::get_angle, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue quaternion_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Quaternion ret = proxy->getter();
    return VariantAdapter(ret.x);
}
static JSValue quaternion_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    VariantAdapter x(argv[0]);
    Quaternion wrapped = proxy->getter();
    wrapped.x = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue quaternion_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Quaternion ret = proxy->getter();
    return VariantAdapter(ret.y);
}
static JSValue quaternion_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    VariantAdapter y(argv[0]);
    Quaternion wrapped = proxy->getter();
    wrapped.y = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue quaternion_proxy_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Quaternion ret = proxy->getter();
    return VariantAdapter(ret.z);
}
static JSValue quaternion_proxy_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    VariantAdapter z(argv[0]);
    Quaternion wrapped = proxy->getter();
    wrapped.z = z.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue quaternion_proxy_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    Quaternion ret = proxy->getter();
    return VariantAdapter(ret.w);
}
static JSValue quaternion_proxy_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["QuaternionProxy"]);
    ObjectProxy<Quaternion> *proxy = static_cast<ObjectProxy<Quaternion> *>(opaque);
    VariantAdapter w(argv[0]);
    Quaternion wrapped = proxy->getter();
    wrapped.w = w.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry quaternion_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("length", 0, &quaternion_proxy_length),
	JS_CFUNC_DEF("length_squared", 0, &quaternion_proxy_length_squared),
	JS_CFUNC_DEF("normalized", 0, &quaternion_proxy_normalized),
	JS_CFUNC_DEF("is_normalized", 0, &quaternion_proxy_is_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &quaternion_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &quaternion_proxy_is_finite),
	JS_CFUNC_DEF("inverse", 0, &quaternion_proxy_inverse),
	JS_CFUNC_DEF("log", 0, &quaternion_proxy_log),
	JS_CFUNC_DEF("exp", 0, &quaternion_proxy_exp),
	JS_CFUNC_DEF("angle_to", 1, &quaternion_proxy_angle_to),
	JS_CFUNC_DEF("dot", 1, &quaternion_proxy_dot),
	JS_CFUNC_DEF("slerp", 2, &quaternion_proxy_slerp),
	JS_CFUNC_DEF("slerpni", 2, &quaternion_proxy_slerpni),
	JS_CFUNC_DEF("spherical_cubic_interpolate", 4, &quaternion_proxy_spherical_cubic_interpolate),
	JS_CFUNC_DEF("spherical_cubic_interpolate_in_time", 7, &quaternion_proxy_spherical_cubic_interpolate_in_time),
	JS_CFUNC_DEF("get_euler", 1, &quaternion_proxy_get_euler),
	JS_CFUNC_DEF("from_euler", 1, &quaternion_proxy_from_euler),
	JS_CFUNC_DEF("get_axis", 0, &quaternion_proxy_get_axis),
	JS_CFUNC_DEF("get_angle", 0, &quaternion_proxy_get_angle),
};

void define_quaternion_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, quaternion_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, quaternion_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, quaternion_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, quaternion_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, quaternion_proxy_get_z, "get_z", 0),
			JS_NewCFunction(ctx, quaternion_proxy_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, quaternion_proxy_get_w, "get_w", 0),
			JS_NewCFunction(ctx, quaternion_proxy_set_w, "set_w", 1),
			JS_PROP_GETSET);
}

static int js_quaternion_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["QuaternionProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "QuaternionProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &quaternion_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_quaternion_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, quaternion_proxy_proto_funcs, _countof(quaternion_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, quaternion_proxy_constructor, "QuaternionProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "QuaternionProxy", ctor);

	return 0;
}

void js_init_quaternion_proxy_module(JSContext *ctx) {
	js_quaternion_proxy_init(ctx);
}

void register_proxy_quaternion() {
	js_init_quaternion_proxy_module(js_context());
}