#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/classes/gradient.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/line2d.hpp>
using namespace godot;

static void line2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Line2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef line2d_class_def = {
    "Line2D",
    line2d_class_finalizer
};

static JSValue line2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Line2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Line2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Line2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Line2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue line2d_class_set_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_points, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		Line2D *obj = static_cast<Line2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_points();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		Line2D *js_proxy = static_cast<Line2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_points(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue line2d_class_set_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_point_position, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_point_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_point_position, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_point_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_point_count, ctx, this_val, argc, argv);
};
static JSValue line2d_class_add_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::add_point, ctx, this_val, argc, argv);
};
static JSValue line2d_class_remove_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::remove_point, ctx, this_val, argc, argv);
};
static JSValue line2d_class_clear_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::clear_points, ctx, this_val, argc, argv);
};
static JSValue line2d_class_set_closed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_closed, ctx, this_val, argc, argv);
};
static JSValue line2d_class_is_closed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::is_closed, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_width, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_width, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_curve, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_curve, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_default_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_default_color, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_default_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Line2D *obj = static_cast<Line2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_default_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Line2D *js_proxy = static_cast<Line2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_default_color(value);
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
static JSValue line2d_class_set_gradient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_gradient, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_gradient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_gradient, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_texture, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_texture, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_texture_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_texture_mode, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_texture_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_texture_mode, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_joint_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_joint_mode, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_joint_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_joint_mode, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_begin_cap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_begin_cap_mode, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_begin_cap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_begin_cap_mode, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_end_cap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_end_cap_mode, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_end_cap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_end_cap_mode, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_sharp_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_sharp_limit, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_sharp_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_sharp_limit, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_round_precision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_round_precision, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_round_precision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_round_precision, ctx, this_val, argc, argv);
}
static JSValue line2d_class_set_antialiased(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Line2D::set_antialiased, ctx, this_val, argc, argv);
};
static JSValue line2d_class_get_antialiased(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Line2D::get_antialiased, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry line2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_points", 1, &line2d_class_set_points),
	JS_CFUNC_DEF("get_points", 0, &line2d_class_get_points),
	JS_CFUNC_DEF("set_point_position", 2, &line2d_class_set_point_position),
	JS_CFUNC_DEF("get_point_position", 1, &line2d_class_get_point_position),
	JS_CFUNC_DEF("get_point_count", 0, &line2d_class_get_point_count),
	JS_CFUNC_DEF("add_point", 2, &line2d_class_add_point),
	JS_CFUNC_DEF("remove_point", 1, &line2d_class_remove_point),
	JS_CFUNC_DEF("clear_points", 0, &line2d_class_clear_points),
	JS_CFUNC_DEF("set_closed", 1, &line2d_class_set_closed),
	JS_CFUNC_DEF("is_closed", 0, &line2d_class_is_closed),
	JS_CFUNC_DEF("set_width", 1, &line2d_class_set_width),
	JS_CFUNC_DEF("get_width", 0, &line2d_class_get_width),
	JS_CFUNC_DEF("set_curve", 1, &line2d_class_set_curve),
	JS_CFUNC_DEF("get_curve", 0, &line2d_class_get_curve),
	JS_CFUNC_DEF("set_default_color", 1, &line2d_class_set_default_color),
	JS_CFUNC_DEF("get_default_color", 0, &line2d_class_get_default_color),
	JS_CFUNC_DEF("set_gradient", 1, &line2d_class_set_gradient),
	JS_CFUNC_DEF("get_gradient", 0, &line2d_class_get_gradient),
	JS_CFUNC_DEF("set_texture", 1, &line2d_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &line2d_class_get_texture),
	JS_CFUNC_DEF("set_texture_mode", 1, &line2d_class_set_texture_mode),
	JS_CFUNC_DEF("get_texture_mode", 0, &line2d_class_get_texture_mode),
	JS_CFUNC_DEF("set_joint_mode", 1, &line2d_class_set_joint_mode),
	JS_CFUNC_DEF("get_joint_mode", 0, &line2d_class_get_joint_mode),
	JS_CFUNC_DEF("set_begin_cap_mode", 1, &line2d_class_set_begin_cap_mode),
	JS_CFUNC_DEF("get_begin_cap_mode", 0, &line2d_class_get_begin_cap_mode),
	JS_CFUNC_DEF("set_end_cap_mode", 1, &line2d_class_set_end_cap_mode),
	JS_CFUNC_DEF("get_end_cap_mode", 0, &line2d_class_get_end_cap_mode),
	JS_CFUNC_DEF("set_sharp_limit", 1, &line2d_class_set_sharp_limit),
	JS_CFUNC_DEF("get_sharp_limit", 0, &line2d_class_get_sharp_limit),
	JS_CFUNC_DEF("set_round_precision", 1, &line2d_class_set_round_precision),
	JS_CFUNC_DEF("get_round_precision", 0, &line2d_class_get_round_precision),
	JS_CFUNC_DEF("set_antialiased", 1, &line2d_class_set_antialiased),
	JS_CFUNC_DEF("get_antialiased", 0, &line2d_class_get_antialiased),
};




static void define_line2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "points"),
        JS_NewCFunction(ctx, line2d_class_get_points, "get_points", 0),
        JS_NewCFunction(ctx, line2d_class_set_points, "set_points", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "closed"),
        JS_NewCFunction(ctx, line2d_class_is_closed, "is_closed", 0),
        JS_NewCFunction(ctx, line2d_class_set_closed, "set_closed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width"),
        JS_NewCFunction(ctx, line2d_class_get_width, "get_width", 0),
        JS_NewCFunction(ctx, line2d_class_set_width, "set_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "width_curve"),
        JS_NewCFunction(ctx, line2d_class_get_curve, "get_curve", 0),
        JS_NewCFunction(ctx, line2d_class_set_curve, "set_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_color"),
        JS_NewCFunction(ctx, line2d_class_get_default_color, "get_default_color", 0),
        JS_NewCFunction(ctx, line2d_class_set_default_color, "set_default_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gradient"),
        JS_NewCFunction(ctx, line2d_class_get_gradient, "get_gradient", 0),
        JS_NewCFunction(ctx, line2d_class_set_gradient, "set_gradient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, line2d_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, line2d_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_mode"),
        JS_NewCFunction(ctx, line2d_class_get_texture_mode, "get_texture_mode", 0),
        JS_NewCFunction(ctx, line2d_class_set_texture_mode, "set_texture_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joint_mode"),
        JS_NewCFunction(ctx, line2d_class_get_joint_mode, "get_joint_mode", 0),
        JS_NewCFunction(ctx, line2d_class_set_joint_mode, "set_joint_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "begin_cap_mode"),
        JS_NewCFunction(ctx, line2d_class_get_begin_cap_mode, "get_begin_cap_mode", 0),
        JS_NewCFunction(ctx, line2d_class_set_begin_cap_mode, "set_begin_cap_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "end_cap_mode"),
        JS_NewCFunction(ctx, line2d_class_get_end_cap_mode, "get_end_cap_mode", 0),
        JS_NewCFunction(ctx, line2d_class_set_end_cap_mode, "set_end_cap_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sharp_limit"),
        JS_NewCFunction(ctx, line2d_class_get_sharp_limit, "get_sharp_limit", 0),
        JS_NewCFunction(ctx, line2d_class_set_sharp_limit, "set_sharp_limit", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "round_precision"),
        JS_NewCFunction(ctx, line2d_class_get_round_precision, "get_round_precision", 0),
        JS_NewCFunction(ctx, line2d_class_set_round_precision, "set_round_precision", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "antialiased"),
        JS_NewCFunction(ctx, line2d_class_get_antialiased, "get_antialiased", 0),
        JS_NewCFunction(ctx, line2d_class_set_antialiased, "set_antialiased", 1),
        JS_PROP_GETSET
    );
}

static void define_line2d_enum(JSContext *ctx, JSValue proto) {
	JSValue LineJointMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LineJointMode_obj, "LINE_JOINT_SHARP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LineJointMode_obj, "LINE_JOINT_BEVEL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LineJointMode_obj, "LINE_JOINT_ROUND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "LineJointMode", LineJointMode_obj);
	JSValue LineCapMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LineCapMode_obj, "LINE_CAP_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LineCapMode_obj, "LINE_CAP_BOX", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LineCapMode_obj, "LINE_CAP_ROUND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "LineCapMode", LineCapMode_obj);
	JSValue LineTextureMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LineTextureMode_obj, "LINE_TEXTURE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LineTextureMode_obj, "LINE_TEXTURE_TILE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LineTextureMode_obj, "LINE_TEXTURE_STRETCH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "LineTextureMode", LineTextureMode_obj);
}

static int js_line2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Line2D"] = class_id;
	classes_by_id[class_id] = "Line2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &line2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_line2d_property(ctx, proto);
	define_line2d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, line2d_class_proto_funcs, _countof(line2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, line2d_class_constructor, "Line2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Line2D", ctor);

	return 0;
}

JSModuleDef *_js_init_line2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_line2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Line2D");
	return m;
}

JSModuleDef *js_init_line2d_module(JSContext *ctx) {
	return _js_init_line2d_module(ctx, "@godot/classes/line2d");
}

void __register_line2d() {
	js_init_line2d_module(js_context());
}

void register_line2d() {
	__register_line2d();
}