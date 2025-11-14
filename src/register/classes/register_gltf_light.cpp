#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/light3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_light.hpp>
using namespace godot;

static void gltf_light_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFLight"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_light_class_def = {
    "GLTFLight",
    gltf_light_class_finalizer
};

static JSValue gltf_light_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFLight"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFLight *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFLight *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFLight);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_light_class_to_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFLight::to_node, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_to_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFLight::to_dictionary, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		GLTFLight *obj = static_cast<GLTFLight *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		GLTFLight *js_proxy = static_cast<GLTFLight *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color(value);
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
static JSValue gltf_light_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_color, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFLight::get_intensity, ctx, this_val, argc, argv);
}
static JSValue gltf_light_class_set_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_intensity, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_light_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		GLTFLight *obj = static_cast<GLTFLight *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_light_type();
	};
	proxy->setter = [this_val](const String &value) -> void {
		GLTFLight *js_proxy = static_cast<GLTFLight *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_light_type(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_light_class_set_light_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_light_type, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFLight::get_range, ctx, this_val, argc, argv);
}
static JSValue gltf_light_class_set_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_range, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_inner_cone_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFLight::get_inner_cone_angle, ctx, this_val, argc, argv);
}
static JSValue gltf_light_class_set_inner_cone_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_inner_cone_angle, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_outer_cone_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFLight::get_outer_cone_angle, ctx, this_val, argc, argv);
}
static JSValue gltf_light_class_set_outer_cone_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_outer_cone_angle, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_get_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFLight::get_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_set_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFLight::set_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_from_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFLight::from_node, ctx, this_val, argc, argv);
};
static JSValue gltf_light_class_from_dictionary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&GLTFLight::from_dictionary, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gltf_light_class_proto_funcs[] = {
	JS_CFUNC_DEF("to_node", 0, &gltf_light_class_to_node),
	JS_CFUNC_DEF("to_dictionary", 0, &gltf_light_class_to_dictionary),
	JS_CFUNC_DEF("get_color", 0, &gltf_light_class_get_color),
	JS_CFUNC_DEF("set_color", 1, &gltf_light_class_set_color),
	JS_CFUNC_DEF("get_intensity", 0, &gltf_light_class_get_intensity),
	JS_CFUNC_DEF("set_intensity", 1, &gltf_light_class_set_intensity),
	JS_CFUNC_DEF("get_light_type", 0, &gltf_light_class_get_light_type),
	JS_CFUNC_DEF("set_light_type", 1, &gltf_light_class_set_light_type),
	JS_CFUNC_DEF("get_range", 0, &gltf_light_class_get_range),
	JS_CFUNC_DEF("set_range", 1, &gltf_light_class_set_range),
	JS_CFUNC_DEF("get_inner_cone_angle", 0, &gltf_light_class_get_inner_cone_angle),
	JS_CFUNC_DEF("set_inner_cone_angle", 1, &gltf_light_class_set_inner_cone_angle),
	JS_CFUNC_DEF("get_outer_cone_angle", 0, &gltf_light_class_get_outer_cone_angle),
	JS_CFUNC_DEF("set_outer_cone_angle", 1, &gltf_light_class_set_outer_cone_angle),
	JS_CFUNC_DEF("get_additional_data", 1, &gltf_light_class_get_additional_data),
	JS_CFUNC_DEF("set_additional_data", 2, &gltf_light_class_set_additional_data),
};

static const JSCFunctionListEntry gltf_light_class_static_funcs[] = {
	JS_CFUNC_DEF("from_node", 1, &gltf_light_class_from_node),
	JS_CFUNC_DEF("from_dictionary", 1, &gltf_light_class_from_dictionary),
};



static void define_gltf_light_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, gltf_light_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, gltf_light_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "intensity"),
        JS_NewCFunction(ctx, gltf_light_class_get_intensity, "get_intensity", 0),
        JS_NewCFunction(ctx, gltf_light_class_set_intensity, "set_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_type"),
        JS_NewCFunction(ctx, gltf_light_class_get_light_type, "get_light_type", 0),
        JS_NewCFunction(ctx, gltf_light_class_set_light_type, "set_light_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range"),
        JS_NewCFunction(ctx, gltf_light_class_get_range, "get_range", 0),
        JS_NewCFunction(ctx, gltf_light_class_set_range, "set_range", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inner_cone_angle"),
        JS_NewCFunction(ctx, gltf_light_class_get_inner_cone_angle, "get_inner_cone_angle", 0),
        JS_NewCFunction(ctx, gltf_light_class_set_inner_cone_angle, "set_inner_cone_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outer_cone_angle"),
        JS_NewCFunction(ctx, gltf_light_class_get_outer_cone_angle, "get_outer_cone_angle", 0),
        JS_NewCFunction(ctx, gltf_light_class_set_outer_cone_angle, "set_outer_cone_angle", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_light_enum(JSContext *ctx, JSValue proto) {
}

static int js_gltf_light_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFLight"] = class_id;
	classes_by_id[class_id] = "GLTFLight";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_light_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_light_property(ctx, proto);
	define_gltf_light_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_light_class_proto_funcs, _countof(gltf_light_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_light_class_constructor, "GLTFLight", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, gltf_light_class_static_funcs, _countof(gltf_light_class_static_funcs));
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFLight", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_light_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_light_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFLight");
	return m;
}

JSModuleDef *js_init_gltf_light_module(JSContext *ctx) {
	return _js_init_gltf_light_module(ctx, "@godot/classes/gltf_light");
}

void __register_gltf_light() {
	js_init_gltf_light_module(js_context());
}

void register_gltf_light() {
	__register_gltf_light();
}