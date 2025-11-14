#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>


using namespace godot;

static void basis_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Basis"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef basis_class_def = {
	"Basis",
	basis_class_finalizer
};

static JSValue basis_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Basis"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Basis instance;
	if (argc == 0) {
		instance = Basis();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::BASIS)) {
		Basis v0 = VariantAdapter(argv[0]).get();
		instance = Basis(v0);
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::QUATERNION)) {
		Quaternion v0 = VariantAdapter(argv[0]).get();
		instance = Basis(v0);
	}
	if (argc == 2&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR3)&&JS_IsNumber(argv[1])) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		instance = Basis(v0, v1);
	}
	if (argc == 3&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR3)&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR3)&&VariantAdapter::can_cast(argv[2], Variant::Type::VECTOR3)) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		Vector3 v1 = VariantAdapter(argv[1]).get();
		Vector3 v2 = VariantAdapter(argv[2]).get();
		instance = Basis(v0, v1, v2);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue basis_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::inverse, ctx, this_val, argc, argv);
}
static JSValue basis_class_transposed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::transposed, ctx, this_val, argc, argv);
}
static JSValue basis_class_orthonormalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::orthonormalized, ctx, this_val, argc, argv);
}
static JSValue basis_class_determinant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::determinant, ctx, this_val, argc, argv);
}
static JSValue basis_class_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(static_cast<Basis(Basis::*)(const Vector3 &p_axis, real_t p_angle) const>(&Basis::rotated), ctx, this_val, argc, argv);
}
static JSValue basis_class_scaled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::scaled, ctx, this_val, argc, argv);
}
static JSValue basis_class_scaled_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::scaled_local, ctx, this_val, argc, argv);
}
static JSValue basis_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::get_scale, ctx, this_val, argc, argv);
}
static JSValue basis_class_get_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::get_euler, ctx, this_val, argc, argv);
}
static JSValue basis_class_tdotx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::tdotx, ctx, this_val, argc, argv);
}
static JSValue basis_class_tdoty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::tdoty, ctx, this_val, argc, argv);
}
static JSValue basis_class_tdotz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::tdotz, ctx, this_val, argc, argv);
}
static JSValue basis_class_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::slerp, ctx, this_val, argc, argv);
}
static JSValue basis_class_is_conformal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::is_conformal, ctx, this_val, argc, argv);
}
static JSValue basis_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue basis_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::is_finite, ctx, this_val, argc, argv);
}
static JSValue basis_class_get_rotation_quaternion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Basis::get_rotation_quaternion, ctx, this_val, argc, argv);
}
static JSValue basis_class_looking_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Basis::looking_at, ctx, this_val, argc, argv);
}
static JSValue basis_class_from_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Basis::from_scale, ctx, this_val, argc, argv);
}
static JSValue basis_class_from_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Basis::from_euler, ctx, this_val, argc, argv);
}

static JSValue basis_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Basis val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Basis"]))->get();
	return VariantAdapter(val.rows[0]);
	
}
static JSValue basis_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Basis"]));
    Basis val = adapter->get();
    val.rows[0] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue basis_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Basis val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Basis"]))->get();
	return VariantAdapter(val.rows[1]);
	
}
static JSValue basis_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Basis"]));
    Basis val = adapter->get();
    val.rows[1] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue basis_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Basis val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Basis"]))->get();
	return VariantAdapter(val.rows[2]);
	
}
static JSValue basis_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Basis"]));
    Basis val = adapter->get();
    val.rows[2] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry basis_class_proto_funcs[] = {
	JS_CFUNC_DEF("inverse", 0, &basis_class_inverse),
	JS_CFUNC_DEF("transposed", 0, &basis_class_transposed),
	JS_CFUNC_DEF("orthonormalized", 0, &basis_class_orthonormalized),
	JS_CFUNC_DEF("determinant", 0, &basis_class_determinant),
	JS_CFUNC_DEF("rotated", 2, &basis_class_rotated),
	JS_CFUNC_DEF("scaled", 1, &basis_class_scaled),
	JS_CFUNC_DEF("scaled_local", 1, &basis_class_scaled_local),
	JS_CFUNC_DEF("get_scale", 0, &basis_class_get_scale),
	JS_CFUNC_DEF("get_euler", 1, &basis_class_get_euler),
	JS_CFUNC_DEF("tdotx", 1, &basis_class_tdotx),
	JS_CFUNC_DEF("tdoty", 1, &basis_class_tdoty),
	JS_CFUNC_DEF("tdotz", 1, &basis_class_tdotz),
	JS_CFUNC_DEF("slerp", 2, &basis_class_slerp),
	JS_CFUNC_DEF("is_conformal", 0, &basis_class_is_conformal),
	JS_CFUNC_DEF("is_equal_approx", 1, &basis_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &basis_class_is_finite),
	JS_CFUNC_DEF("get_rotation_quaternion", 0, &basis_class_get_rotation_quaternion),
	JS_CFUNC_DEF("looking_at", 3, &basis_class_looking_at),
	JS_CFUNC_DEF("from_scale", 1, &basis_class_from_scale),
	JS_CFUNC_DEF("from_euler", 2, &basis_class_from_euler),
};

static void define_basis_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, basis_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, basis_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, basis_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, basis_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, basis_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, basis_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
}

static int js_basis_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Basis"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Basis";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &basis_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_basis_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, basis_class_proto_funcs, _countof(basis_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, basis_class_constructor, "Basis", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Basis", ctor);

	return 0;
}

static void js_init_basis_module(JSContext *ctx) {
	js_basis_class_init(ctx);
}

void register_basis() {
	js_init_basis_module(js_context());
}

// ------------------BasisProxy------------------
static void basis_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["BasisProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Basis> *>(proxy));
	}
}

static JSClassDef basis_proxy_def = {
	"BasisProxy",
	basis_proxy_finalizer
};


static JSValue basis_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["BasisProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Basis> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Basis> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue basis_proxy_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::inverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_transposed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::transposed, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_orthonormalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::orthonormalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_determinant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::determinant, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(static_cast<Basis(Basis::*)(const Vector3 &p_axis, real_t p_angle) const>(&Basis::rotated), ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_scaled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::scaled, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_scaled_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::scaled_local, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::get_scale, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_get_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::get_euler, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_tdotx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::tdotx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_tdoty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::tdoty, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_tdotz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::tdotz, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::slerp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_is_conformal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::is_conformal, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::is_finite, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_get_rotation_quaternion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Basis::get_rotation_quaternion, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue basis_proxy_looking_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Basis::looking_at, ctx, this_val, argc, argv);
}
static JSValue basis_proxy_from_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Basis::from_scale, ctx, this_val, argc, argv);
}
static JSValue basis_proxy_from_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Basis::from_euler, ctx, this_val, argc, argv);
}

static JSValue basis_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Basis ret = proxy->getter();
    return VariantAdapter(ret.rows[0]);
}
static JSValue basis_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    VariantAdapter x(argv[0]);
    Basis wrapped = proxy->getter();
    wrapped.rows[0] = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue basis_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Basis ret = proxy->getter();
    return VariantAdapter(ret.rows[1]);
}
static JSValue basis_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    VariantAdapter y(argv[0]);
    Basis wrapped = proxy->getter();
    wrapped.rows[1] = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue basis_proxy_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    Basis ret = proxy->getter();
    return VariantAdapter(ret.rows[2]);
}
static JSValue basis_proxy_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["BasisProxy"]);
    ObjectProxy<Basis> *proxy = static_cast<ObjectProxy<Basis> *>(opaque);
    VariantAdapter z(argv[0]);
    Basis wrapped = proxy->getter();
    wrapped.rows[2] = z.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry basis_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("inverse", 0, &basis_proxy_inverse),
	JS_CFUNC_DEF("transposed", 0, &basis_proxy_transposed),
	JS_CFUNC_DEF("orthonormalized", 0, &basis_proxy_orthonormalized),
	JS_CFUNC_DEF("determinant", 0, &basis_proxy_determinant),
	JS_CFUNC_DEF("rotated", 2, &basis_proxy_rotated),
	JS_CFUNC_DEF("scaled", 1, &basis_proxy_scaled),
	JS_CFUNC_DEF("scaled_local", 1, &basis_proxy_scaled_local),
	JS_CFUNC_DEF("get_scale", 0, &basis_proxy_get_scale),
	JS_CFUNC_DEF("get_euler", 1, &basis_proxy_get_euler),
	JS_CFUNC_DEF("tdotx", 1, &basis_proxy_tdotx),
	JS_CFUNC_DEF("tdoty", 1, &basis_proxy_tdoty),
	JS_CFUNC_DEF("tdotz", 1, &basis_proxy_tdotz),
	JS_CFUNC_DEF("slerp", 2, &basis_proxy_slerp),
	JS_CFUNC_DEF("is_conformal", 0, &basis_proxy_is_conformal),
	JS_CFUNC_DEF("is_equal_approx", 1, &basis_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &basis_proxy_is_finite),
	JS_CFUNC_DEF("get_rotation_quaternion", 0, &basis_proxy_get_rotation_quaternion),
	JS_CFUNC_DEF("looking_at", 3, &basis_proxy_looking_at),
	JS_CFUNC_DEF("from_scale", 1, &basis_proxy_from_scale),
	JS_CFUNC_DEF("from_euler", 2, &basis_proxy_from_euler),
};

void define_basis_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, basis_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, basis_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, basis_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, basis_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, basis_proxy_get_z, "get_z", 0),
			JS_NewCFunction(ctx, basis_proxy_set_z, "set_z", 1),
			JS_PROP_GETSET);
}

static int js_basis_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["BasisProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "BasisProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &basis_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_basis_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, basis_proxy_proto_funcs, _countof(basis_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, basis_proxy_constructor, "BasisProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "BasisProxy", ctor);

	return 0;
}

void js_init_basis_proxy_module(JSContext *ctx) {
	js_basis_proxy_init(ctx);
}

void register_proxy_basis() {
	js_init_basis_proxy_module(js_context());
}