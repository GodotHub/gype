#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/light2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/point_light2d.hpp>
using namespace godot;

static void point_light2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PointLight2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef point_light2d_class_def = {
    "PointLight2D",
    point_light2d_class_finalizer
};

static JSValue point_light2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PointLight2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PointLight2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PointLight2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PointLight2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue point_light2d_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PointLight2D::set_texture, ctx, this_val, argc, argv);
};
static JSValue point_light2d_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PointLight2D::get_texture, ctx, this_val, argc, argv);
}
static JSValue point_light2d_class_set_texture_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PointLight2D::set_texture_offset, ctx, this_val, argc, argv);
};
static JSValue point_light2d_class_get_texture_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PointLight2D *obj = static_cast<PointLight2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_texture_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PointLight2D *js_proxy = static_cast<PointLight2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_texture_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue point_light2d_class_set_texture_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PointLight2D::set_texture_scale, ctx, this_val, argc, argv);
};
static JSValue point_light2d_class_get_texture_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PointLight2D::get_texture_scale, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry point_light2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture", 1, &point_light2d_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &point_light2d_class_get_texture),
	JS_CFUNC_DEF("set_texture_offset", 1, &point_light2d_class_set_texture_offset),
	JS_CFUNC_DEF("get_texture_offset", 0, &point_light2d_class_get_texture_offset),
	JS_CFUNC_DEF("set_texture_scale", 1, &point_light2d_class_set_texture_scale),
	JS_CFUNC_DEF("get_texture_scale", 0, &point_light2d_class_get_texture_scale),
};




static void define_point_light2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, point_light2d_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, point_light2d_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, point_light2d_class_get_texture_offset, "get_texture_offset", 0),
        JS_NewCFunction(ctx, point_light2d_class_set_texture_offset, "set_texture_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_scale"),
        JS_NewCFunction(ctx, point_light2d_class_get_texture_scale, "get_texture_scale", 0),
        JS_NewCFunction(ctx, point_light2d_class_set_texture_scale, "set_texture_scale", 1),
        JS_PROP_GETSET
    );
}

static void define_point_light2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_point_light2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PointLight2D"] = class_id;
	classes_by_id[class_id] = "PointLight2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &point_light2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Light2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_point_light2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, point_light2d_class_proto_funcs, _countof(point_light2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, point_light2d_class_constructor, "PointLight2D", 0, JS_CFUNC_constructor, 0);
	define_point_light2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PointLight2D", ctor);

	return 0;
}

JSModuleDef *_js_init_point_light2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/light2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_point_light2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PointLight2D");
	return m;
}

JSModuleDef *js_init_point_light2d_module(JSContext *ctx) {
	return _js_init_point_light2d_module(ctx, "@godot/classes/point_light2d");
}

void __register_point_light2d() {
	js_init_point_light2d_module(js_context());
}

void register_point_light2d() {
	__register_point_light2d();
}