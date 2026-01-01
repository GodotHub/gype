#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shape2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/convex_polygon_shape2d.hpp>
using namespace godot;

static void convex_polygon_shape2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ConvexPolygonShape2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef convex_polygon_shape2d_class_def = {
    "ConvexPolygonShape2D",
    convex_polygon_shape2d_class_finalizer
};

static JSValue convex_polygon_shape2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ConvexPolygonShape2D"];
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
        instance = memnew(ConvexPolygonShape2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue convex_polygon_shape2d_class_set_point_cloud(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvexPolygonShape2D::set_point_cloud, ctx, this_val, argc, argv);
};
static JSValue convex_polygon_shape2d_class_set_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvexPolygonShape2D::set_points, ctx, this_val, argc, argv);
};
static JSValue convex_polygon_shape2d_class_get_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		ConvexPolygonShape2D *obj = static_cast<ConvexPolygonShape2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_points();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		ConvexPolygonShape2D *js_proxy = static_cast<ConvexPolygonShape2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_points(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry convex_polygon_shape2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_point_cloud", 1, &convex_polygon_shape2d_class_set_point_cloud),
	JS_CFUNC_DEF("set_points", 1, &convex_polygon_shape2d_class_set_points),
	JS_CFUNC_DEF("get_points", 0, &convex_polygon_shape2d_class_get_points),
};




static void define_convex_polygon_shape2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "points"),
        JS_NewCFunction(ctx, convex_polygon_shape2d_class_get_points, "get_points", 0),
        JS_NewCFunction(ctx, convex_polygon_shape2d_class_set_points, "set_points", 1),
        JS_PROP_GETSET
    );
}

static void define_convex_polygon_shape2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_convex_polygon_shape2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ConvexPolygonShape2D"] = class_id;
	classes_by_id[class_id] = "ConvexPolygonShape2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &convex_polygon_shape2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_convex_polygon_shape2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, convex_polygon_shape2d_class_proto_funcs, _countof(convex_polygon_shape2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, convex_polygon_shape2d_class_constructor, "ConvexPolygonShape2D", 0, JS_CFUNC_constructor, 0);
	define_convex_polygon_shape2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ConvexPolygonShape2D", ctor);
	ctor_list["ConvexPolygonShape2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_convex_polygon_shape2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_convex_polygon_shape2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ConvexPolygonShape2D");
	return m;
}

JSModuleDef *js_init_convex_polygon_shape2d_module(JSContext *ctx) {
	return _js_init_convex_polygon_shape2d_module(ctx, "@godot/classes/convex_polygon_shape2d");
}

void __register_convex_polygon_shape2d() {
	js_init_convex_polygon_shape2d_module(js_context());
}

void register_convex_polygon_shape2d() {
	__register_convex_polygon_shape2d();
}