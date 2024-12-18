
#include "register/builtin_classes/register_builtin_classes.h"
#include "quickjs/quickjs.h"
#include "quickjs/env.h"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/variant_helper.hpp"
#include <godot_cpp/variant/vector3i.hpp>

using namespace godot;

static void vector3i_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Vector3i"];
	Vector3i *vector3i = static_cast<Vector3i *>(JS_GetOpaque(val, class_id));
	if (vector3i)
		memfree(vector3i);
}

static JSClassDef vector3i_class_def = {
	"Vector3i",
	.finalizer = vector3i_class_finalizer
};

static JSValue vector3i_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector3i"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Vector3i *vector3i_class = nullptr;
	
	if (argc == 0 ) {
		vector3i_class = memnew(Vector3i());
	}
	
	if (argc == 1 &&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3I) {
		Vector3i v0 = VariantAdapter(argv[0]);
		vector3i_class = memnew(Vector3i(v0));
	}
	
	if (argc == 1 &&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3) {
		Vector3 v0 = VariantAdapter(argv[0]);
		vector3i_class = memnew(Vector3i(v0));
	}
	
	if (argc == 3 &&VariantAdapter(argv[0]).get_type() == Variant::Type::INT&&VariantAdapter(argv[1]).get_type() == Variant::Type::INT&&VariantAdapter(argv[2]).get_type() == Variant::Type::INT) {
		int v0 = VariantAdapter(argv[0]);
		int v1 = VariantAdapter(argv[1]);
		int v2 = VariantAdapter(argv[2]);
		vector3i_class = memnew(Vector3i(v0,v1,v2));
	}
	

	if (!vector3i_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, vector3i_class);
	return obj;
}
static JSValue vector3i_class_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::min_axis_index, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::max_axis_index, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::distance_to, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::distance_squared_to, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::length, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::length_squared, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::sign, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::abs, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::clamp, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::clampi, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::snapped, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::snappedi, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::min, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::mini, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::max, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::maxi, ctx, this_val, argc, argv);
};
static JSValue vector3i_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes["Vector3i"]));
	return VariantAdapter(val.x);
}
static JSValue vector3i_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes["Vector3i"]));
	val.x = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static JSValue vector3i_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes["Vector3i"]));
	return VariantAdapter(val.y);
}
static JSValue vector3i_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes["Vector3i"]));
	val.y = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static JSValue vector3i_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes["Vector3i"]));
	return VariantAdapter(val.z);
}
static JSValue vector3i_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes["Vector3i"]));
	val.z = VariantAdapter(*argv);
	return JS_UNDEFINED;
}
static const JSCFunctionListEntry vector3i_class_proto_funcs[] = {
	JS_CFUNC_DEF("min_axis_index", 0, &vector3i_class_min_axis_index),
	JS_CFUNC_DEF("max_axis_index", 0, &vector3i_class_max_axis_index),
	JS_CFUNC_DEF("distance_to", 1, &vector3i_class_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector3i_class_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector3i_class_length),
	JS_CFUNC_DEF("length_squared", 0, &vector3i_class_length_squared),
	JS_CFUNC_DEF("sign", 0, &vector3i_class_sign),
	JS_CFUNC_DEF("abs", 0, &vector3i_class_abs),
	JS_CFUNC_DEF("clamp", 2, &vector3i_class_clamp),
	JS_CFUNC_DEF("clampi", 2, &vector3i_class_clampi),
	JS_CFUNC_DEF("snapped", 1, &vector3i_class_snapped),
	JS_CFUNC_DEF("snappedi", 1, &vector3i_class_snappedi),
	JS_CFUNC_DEF("min", 1, &vector3i_class_min),
	JS_CFUNC_DEF("mini", 1, &vector3i_class_mini),
	JS_CFUNC_DEF("max", 1, &vector3i_class_max),
	JS_CFUNC_DEF("maxi", 1, &vector3i_class_maxi),
};
void define_vector3i_property(JSContext *ctx, JSValue obj) {
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "x"),
        JS_NewCFunction(ctx, vector3i_class_get_x, "get_x", 0),
        JS_NewCFunction(ctx, vector3i_class_set_x, "set_x", 1),
		JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "y"),
        JS_NewCFunction(ctx, vector3i_class_get_y, "get_y", 0),
        JS_NewCFunction(ctx, vector3i_class_set_y, "set_y", 1),
		JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        obj,
        JS_NewAtom(ctx, "z"),
        JS_NewCFunction(ctx, vector3i_class_get_z, "get_z", 0),
        JS_NewCFunction(ctx, vector3i_class_set_z, "set_z", 1),
		JS_PROP_GETSET
    );
}
void define_vector3i_constants(JSContext *ctx, JSValue ctor) {
	JS_DefinePropertyValueStr(ctx, ctor, "AXIS_X", VariantAdapter(0), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "AXIS_Y", VariantAdapter(1), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "AXIS_Z", VariantAdapter(2), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "ZERO", VariantAdapter(Vector3i(0, 0, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "ONE", VariantAdapter(Vector3i(1, 1, 1)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "MIN", VariantAdapter(Vector3i(-2147483648, -2147483648, -2147483648)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "MAX", VariantAdapter(Vector3i(2147483647, 2147483647, 2147483647)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "LEFT", VariantAdapter(Vector3i(-1, 0, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "RIGHT", VariantAdapter(Vector3i(1, 0, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "UP", VariantAdapter(Vector3i(0, 1, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "DOWN", VariantAdapter(Vector3i(0, -1, 0)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "FORWARD", VariantAdapter(Vector3i(0, 0, -1)), JS_PROP_ENUMERABLE);
	JS_DefinePropertyValueStr(ctx, ctor, "BACK", VariantAdapter(Vector3i(0, 0, 1)), JS_PROP_ENUMERABLE);
}

static int js_vector3i_class_init(JSContext *ctx) {
	classes["Vector3i"] = 0;
	classes["Vector3i"] = JS_NewClassID(&classes["Vector3i"]);
	JSClassID class_id = classes["Vector3i"];

	class_id_list.insert(class_id);
	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector3i_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_vector3i_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vector3i_class_proto_funcs, _countof(vector3i_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, vector3i_class_constructor, "Vector3i", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	define_vector3i_constants(ctx, ctor);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector3i", ctor);

	return 0;
}

void js_init_vector3i_module(JSContext *ctx) {
	js_vector3i_class_init(ctx);
}

void register_vector3i() {
	js_init_vector3i_module(ctx);
}