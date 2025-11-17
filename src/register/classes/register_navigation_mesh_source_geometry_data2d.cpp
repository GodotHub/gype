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
#include <godot_cpp/classes/navigation_mesh_source_geometry_data2d.hpp>
using namespace godot;

static void navigation_mesh_source_geometry_data2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationMeshSourceGeometryData2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_mesh_source_geometry_data2d_class_def = {
    "NavigationMeshSourceGeometryData2D",
    navigation_mesh_source_geometry_data2d_class_finalizer
};

static JSValue navigation_mesh_source_geometry_data2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationMeshSourceGeometryData2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationMeshSourceGeometryData2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationMeshSourceGeometryData2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationMeshSourceGeometryData2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_mesh_source_geometry_data2d_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::clear, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_has_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationMeshSourceGeometryData2D::has_data, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_set_traversable_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::set_traversable_outlines, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_get_traversable_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMeshSourceGeometryData2D::get_traversable_outlines, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_source_geometry_data2d_class_set_obstruction_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::set_obstruction_outlines, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_get_obstruction_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationMeshSourceGeometryData2D::get_obstruction_outlines, ctx, this_val, argc, argv);
}
static JSValue navigation_mesh_source_geometry_data2d_class_append_traversable_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::append_traversable_outlines, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_append_obstruction_outlines(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::append_obstruction_outlines, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_add_traversable_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::add_traversable_outline, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_add_obstruction_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::add_obstruction_outline, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::merge, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_add_projected_obstruction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::add_projected_obstruction, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_clear_projected_obstructions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::clear_projected_obstructions, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_set_projected_obstructions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData2D::set_projected_obstructions, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data2d_class_get_projected_obstructions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		NavigationMeshSourceGeometryData2D *obj = static_cast<NavigationMeshSourceGeometryData2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_projected_obstructions();
	};
	proxy->setter = [this_val](const Array &value) -> void {
		NavigationMeshSourceGeometryData2D *js_proxy = static_cast<NavigationMeshSourceGeometryData2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_projected_obstructions(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_mesh_source_geometry_data2d_class_get_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationMeshSourceGeometryData2D::get_bounds, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry navigation_mesh_source_geometry_data2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &navigation_mesh_source_geometry_data2d_class_clear),
	JS_CFUNC_DEF("has_data", 0, &navigation_mesh_source_geometry_data2d_class_has_data),
	JS_CFUNC_DEF("set_traversable_outlines", 1, &navigation_mesh_source_geometry_data2d_class_set_traversable_outlines),
	JS_CFUNC_DEF("get_traversable_outlines", 0, &navigation_mesh_source_geometry_data2d_class_get_traversable_outlines),
	JS_CFUNC_DEF("set_obstruction_outlines", 1, &navigation_mesh_source_geometry_data2d_class_set_obstruction_outlines),
	JS_CFUNC_DEF("get_obstruction_outlines", 0, &navigation_mesh_source_geometry_data2d_class_get_obstruction_outlines),
	JS_CFUNC_DEF("append_traversable_outlines", 1, &navigation_mesh_source_geometry_data2d_class_append_traversable_outlines),
	JS_CFUNC_DEF("append_obstruction_outlines", 1, &navigation_mesh_source_geometry_data2d_class_append_obstruction_outlines),
	JS_CFUNC_DEF("add_traversable_outline", 1, &navigation_mesh_source_geometry_data2d_class_add_traversable_outline),
	JS_CFUNC_DEF("add_obstruction_outline", 1, &navigation_mesh_source_geometry_data2d_class_add_obstruction_outline),
	JS_CFUNC_DEF("merge", 1, &navigation_mesh_source_geometry_data2d_class_merge),
	JS_CFUNC_DEF("add_projected_obstruction", 2, &navigation_mesh_source_geometry_data2d_class_add_projected_obstruction),
	JS_CFUNC_DEF("clear_projected_obstructions", 0, &navigation_mesh_source_geometry_data2d_class_clear_projected_obstructions),
	JS_CFUNC_DEF("set_projected_obstructions", 1, &navigation_mesh_source_geometry_data2d_class_set_projected_obstructions),
	JS_CFUNC_DEF("get_projected_obstructions", 0, &navigation_mesh_source_geometry_data2d_class_get_projected_obstructions),
	JS_CFUNC_DEF("get_bounds", 0, &navigation_mesh_source_geometry_data2d_class_get_bounds),
};




static void define_navigation_mesh_source_geometry_data2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "traversable_outlines"),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data2d_class_get_traversable_outlines, "get_traversable_outlines", 0),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data2d_class_set_traversable_outlines, "set_traversable_outlines", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "obstruction_outlines"),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data2d_class_get_obstruction_outlines, "get_obstruction_outlines", 0),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data2d_class_set_obstruction_outlines, "set_obstruction_outlines", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "projected_obstructions"),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data2d_class_get_projected_obstructions, "get_projected_obstructions", 0),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data2d_class_set_projected_obstructions, "set_projected_obstructions", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_mesh_source_geometry_data2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_navigation_mesh_source_geometry_data2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationMeshSourceGeometryData2D"] = class_id;
	classes_by_id[class_id] = "NavigationMeshSourceGeometryData2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_mesh_source_geometry_data2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_mesh_source_geometry_data2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_mesh_source_geometry_data2d_class_proto_funcs, _countof(navigation_mesh_source_geometry_data2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_mesh_source_geometry_data2d_class_constructor, "NavigationMeshSourceGeometryData2D", 0, JS_CFUNC_constructor, 0);
	define_navigation_mesh_source_geometry_data2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationMeshSourceGeometryData2D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_mesh_source_geometry_data2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_mesh_source_geometry_data2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationMeshSourceGeometryData2D");
	return m;
}

JSModuleDef *js_init_navigation_mesh_source_geometry_data2d_module(JSContext *ctx) {
	return _js_init_navigation_mesh_source_geometry_data2d_module(ctx, "@godot/classes/navigation_mesh_source_geometry_data2d");
}

void __register_navigation_mesh_source_geometry_data2d() {
	js_init_navigation_mesh_source_geometry_data2d_module(js_context());
}

void register_navigation_mesh_source_geometry_data2d() {
	__register_navigation_mesh_source_geometry_data2d();
}