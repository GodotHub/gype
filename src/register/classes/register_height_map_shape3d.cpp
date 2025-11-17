#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/height_map_shape3d.hpp>
using namespace godot;

static void height_map_shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["HeightMapShape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef height_map_shape3d_class_def = {
    "HeightMapShape3D",
    height_map_shape3d_class_finalizer
};

static JSValue height_map_shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["HeightMapShape3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    HeightMapShape3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<HeightMapShape3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(HeightMapShape3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue height_map_shape3d_class_set_map_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HeightMapShape3D::set_map_width, ctx, this_val, argc, argv);
};
static JSValue height_map_shape3d_class_get_map_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HeightMapShape3D::get_map_width, ctx, this_val, argc, argv);
}
static JSValue height_map_shape3d_class_set_map_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HeightMapShape3D::set_map_depth, ctx, this_val, argc, argv);
};
static JSValue height_map_shape3d_class_get_map_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HeightMapShape3D::get_map_depth, ctx, this_val, argc, argv);
}
static JSValue height_map_shape3d_class_set_map_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HeightMapShape3D::set_map_data, ctx, this_val, argc, argv);
};
static JSValue height_map_shape3d_class_get_map_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat32Array> *proxy = memnew(ObjectProxy<PackedFloat32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat32Array {
		HeightMapShape3D *obj = static_cast<HeightMapShape3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_map_data();
	};
	proxy->setter = [this_val](const PackedFloat32Array &value) -> void {
		HeightMapShape3D *js_proxy = static_cast<HeightMapShape3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_map_data(PackedFloat32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat32ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue height_map_shape3d_class_get_min_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HeightMapShape3D::get_min_height, ctx, this_val, argc, argv);
};
static JSValue height_map_shape3d_class_get_max_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&HeightMapShape3D::get_max_height, ctx, this_val, argc, argv);
};
static JSValue height_map_shape3d_class_update_map_data_from_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&HeightMapShape3D::update_map_data_from_image, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry height_map_shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_map_width", 1, &height_map_shape3d_class_set_map_width),
	JS_CFUNC_DEF("get_map_width", 0, &height_map_shape3d_class_get_map_width),
	JS_CFUNC_DEF("set_map_depth", 1, &height_map_shape3d_class_set_map_depth),
	JS_CFUNC_DEF("get_map_depth", 0, &height_map_shape3d_class_get_map_depth),
	JS_CFUNC_DEF("set_map_data", 1, &height_map_shape3d_class_set_map_data),
	JS_CFUNC_DEF("get_map_data", 0, &height_map_shape3d_class_get_map_data),
	JS_CFUNC_DEF("get_min_height", 0, &height_map_shape3d_class_get_min_height),
	JS_CFUNC_DEF("get_max_height", 0, &height_map_shape3d_class_get_max_height),
	JS_CFUNC_DEF("update_map_data_from_image", 3, &height_map_shape3d_class_update_map_data_from_image),
};




static void define_height_map_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "map_width"),
        JS_NewCFunction(ctx, height_map_shape3d_class_get_map_width, "get_map_width", 0),
        JS_NewCFunction(ctx, height_map_shape3d_class_set_map_width, "set_map_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "map_depth"),
        JS_NewCFunction(ctx, height_map_shape3d_class_get_map_depth, "get_map_depth", 0),
        JS_NewCFunction(ctx, height_map_shape3d_class_set_map_depth, "set_map_depth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "map_data"),
        JS_NewCFunction(ctx, height_map_shape3d_class_get_map_data, "get_map_data", 0),
        JS_NewCFunction(ctx, height_map_shape3d_class_set_map_data, "set_map_data", 1),
        JS_PROP_GETSET
    );
}

static void define_height_map_shape3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_height_map_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["HeightMapShape3D"] = class_id;
	classes_by_id[class_id] = "HeightMapShape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &height_map_shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_height_map_shape3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, height_map_shape3d_class_proto_funcs, _countof(height_map_shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, height_map_shape3d_class_constructor, "HeightMapShape3D", 0, JS_CFUNC_constructor, 0);
	define_height_map_shape3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "HeightMapShape3D", ctor);

	return 0;
}

JSModuleDef *_js_init_height_map_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_height_map_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "HeightMapShape3D");
	return m;
}

JSModuleDef *js_init_height_map_shape3d_module(JSContext *ctx) {
	return _js_init_height_map_shape3d_module(ctx, "@godot/classes/height_map_shape3d");
}

void __register_height_map_shape3d() {
	js_init_height_map_shape3d_module(js_context());
}

void register_height_map_shape3d() {
	__register_height_map_shape3d();
}