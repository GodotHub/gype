#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/polygon_path_finder.hpp>
using namespace godot;

static void polygon_path_finder_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PolygonPathFinder"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef polygon_path_finder_class_def = {
    "PolygonPathFinder",
    polygon_path_finder_class_finalizer
};

static JSValue polygon_path_finder_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PolygonPathFinder"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PolygonPathFinder *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PolygonPathFinder *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PolygonPathFinder);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue polygon_path_finder_class_setup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PolygonPathFinder::setup, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_find_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PolygonPathFinder::find_path, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_get_intersections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PolygonPathFinder::get_intersections, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_get_closest_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PolygonPathFinder::get_closest_point, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_is_point_inside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PolygonPathFinder::is_point_inside, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_set_point_penalty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PolygonPathFinder::set_point_penalty, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_get_point_penalty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PolygonPathFinder::get_point_penalty, ctx, this_val, argc, argv);
};
static JSValue polygon_path_finder_class_get_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PolygonPathFinder::get_bounds, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry polygon_path_finder_class_proto_funcs[] = {
	JS_CFUNC_DEF("setup", 2, &polygon_path_finder_class_setup),
	JS_CFUNC_DEF("find_path", 2, &polygon_path_finder_class_find_path),
	JS_CFUNC_DEF("get_intersections", 2, &polygon_path_finder_class_get_intersections),
	JS_CFUNC_DEF("get_closest_point", 1, &polygon_path_finder_class_get_closest_point),
	JS_CFUNC_DEF("is_point_inside", 1, &polygon_path_finder_class_is_point_inside),
	JS_CFUNC_DEF("set_point_penalty", 2, &polygon_path_finder_class_set_point_penalty),
	JS_CFUNC_DEF("get_point_penalty", 1, &polygon_path_finder_class_get_point_penalty),
	JS_CFUNC_DEF("get_bounds", 0, &polygon_path_finder_class_get_bounds),
};




static void define_polygon_path_finder_property(JSContext *ctx, JSValue proto) {
}

static void define_polygon_path_finder_enum(JSContext *ctx, JSValue proto) {
}

static int js_polygon_path_finder_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PolygonPathFinder"] = class_id;
	classes_by_id[class_id] = "PolygonPathFinder";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &polygon_path_finder_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_polygon_path_finder_property(ctx, proto);
	define_polygon_path_finder_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, polygon_path_finder_class_proto_funcs, _countof(polygon_path_finder_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, polygon_path_finder_class_constructor, "PolygonPathFinder", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PolygonPathFinder", ctor);

	return 0;
}

JSModuleDef *_js_init_polygon_path_finder_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_polygon_path_finder_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PolygonPathFinder");
	return m;
}

JSModuleDef *js_init_polygon_path_finder_module(JSContext *ctx) {
	return _js_init_polygon_path_finder_module(ctx, "@godot/classes/polygon_path_finder");
}

void __register_polygon_path_finder() {
	js_init_polygon_path_finder_module(js_context());
}

void register_polygon_path_finder() {
	__register_polygon_path_finder();
}