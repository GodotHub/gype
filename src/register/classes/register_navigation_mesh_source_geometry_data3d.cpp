#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_mesh_source_geometry_data3d.hpp>
using namespace godot;

static void navigation_mesh_source_geometry_data3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationMeshSourceGeometryData3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_mesh_source_geometry_data3d_class_def = {
    "NavigationMeshSourceGeometryData3D",
    navigation_mesh_source_geometry_data3d_class_finalizer
};

static JSValue navigation_mesh_source_geometry_data3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationMeshSourceGeometryData3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationMeshSourceGeometryData3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationMeshSourceGeometryData3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_mesh_source_geometry_data3d_class_set_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::set_vertices, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_get_vertices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat32Array> *proxy = memnew(ObjectProxy<PackedFloat32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat32Array {
		NavigationMeshSourceGeometryData3D *obj = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_vertices();
	};
	proxy->setter = [this_val](const PackedFloat32Array &value) -> void {
		NavigationMeshSourceGeometryData3D *js_proxy = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_vertices(PackedFloat32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_mesh_source_geometry_data3d_class_set_indices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::set_indices, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_get_indices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		NavigationMeshSourceGeometryData3D *obj = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_indices();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		NavigationMeshSourceGeometryData3D *js_proxy = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_indices(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_mesh_source_geometry_data3d_class_append_arrays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::append_arrays, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::clear, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_has_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationMeshSourceGeometryData3D::has_data, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_add_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::add_mesh, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_add_mesh_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::add_mesh_array, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_add_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::add_faces, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::merge, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_add_projected_obstruction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::add_projected_obstruction, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_clear_projected_obstructions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::clear_projected_obstructions, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_set_projected_obstructions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationMeshSourceGeometryData3D::set_projected_obstructions, ctx, this_val, argc, argv);
};
static JSValue navigation_mesh_source_geometry_data3d_class_get_projected_obstructions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Array> *proxy = memnew(ObjectProxy<Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Array {
		NavigationMeshSourceGeometryData3D *obj = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_projected_obstructions();
	};
	proxy->setter = [this_val](const Array &value) -> void {
		NavigationMeshSourceGeometryData3D *js_proxy = static_cast<NavigationMeshSourceGeometryData3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_projected_obstructions(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue navigation_mesh_source_geometry_data3d_class_get_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&NavigationMeshSourceGeometryData3D::get_bounds, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry navigation_mesh_source_geometry_data3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_vertices", 1, &navigation_mesh_source_geometry_data3d_class_set_vertices),
	JS_CFUNC_DEF("get_vertices", 0, &navigation_mesh_source_geometry_data3d_class_get_vertices),
	JS_CFUNC_DEF("set_indices", 1, &navigation_mesh_source_geometry_data3d_class_set_indices),
	JS_CFUNC_DEF("get_indices", 0, &navigation_mesh_source_geometry_data3d_class_get_indices),
	JS_CFUNC_DEF("append_arrays", 2, &navigation_mesh_source_geometry_data3d_class_append_arrays),
	JS_CFUNC_DEF("clear", 0, &navigation_mesh_source_geometry_data3d_class_clear),
	JS_CFUNC_DEF("has_data", 0, &navigation_mesh_source_geometry_data3d_class_has_data),
	JS_CFUNC_DEF("add_mesh", 2, &navigation_mesh_source_geometry_data3d_class_add_mesh),
	JS_CFUNC_DEF("add_mesh_array", 2, &navigation_mesh_source_geometry_data3d_class_add_mesh_array),
	JS_CFUNC_DEF("add_faces", 2, &navigation_mesh_source_geometry_data3d_class_add_faces),
	JS_CFUNC_DEF("merge", 1, &navigation_mesh_source_geometry_data3d_class_merge),
	JS_CFUNC_DEF("add_projected_obstruction", 4, &navigation_mesh_source_geometry_data3d_class_add_projected_obstruction),
	JS_CFUNC_DEF("clear_projected_obstructions", 0, &navigation_mesh_source_geometry_data3d_class_clear_projected_obstructions),
	JS_CFUNC_DEF("set_projected_obstructions", 1, &navigation_mesh_source_geometry_data3d_class_set_projected_obstructions),
	JS_CFUNC_DEF("get_projected_obstructions", 0, &navigation_mesh_source_geometry_data3d_class_get_projected_obstructions),
	JS_CFUNC_DEF("get_bounds", 0, &navigation_mesh_source_geometry_data3d_class_get_bounds),
};




static void define_navigation_mesh_source_geometry_data3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertices"),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data3d_class_get_vertices, "get_vertices", 0),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data3d_class_set_vertices, "set_vertices", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indices"),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data3d_class_get_indices, "get_indices", 0),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data3d_class_set_indices, "set_indices", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "projected_obstructions"),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data3d_class_get_projected_obstructions, "get_projected_obstructions", 0),
        JS_NewCFunction(ctx, navigation_mesh_source_geometry_data3d_class_set_projected_obstructions, "set_projected_obstructions", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_mesh_source_geometry_data3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_navigation_mesh_source_geometry_data3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationMeshSourceGeometryData3D"] = class_id;
	classes_by_id[class_id] = "NavigationMeshSourceGeometryData3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_mesh_source_geometry_data3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_mesh_source_geometry_data3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_mesh_source_geometry_data3d_class_proto_funcs, _countof(navigation_mesh_source_geometry_data3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_mesh_source_geometry_data3d_class_constructor, "NavigationMeshSourceGeometryData3D", 0, JS_CFUNC_constructor, 0);
	define_navigation_mesh_source_geometry_data3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationMeshSourceGeometryData3D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_mesh_source_geometry_data3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_mesh_source_geometry_data3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationMeshSourceGeometryData3D");
	return m;
}

JSModuleDef *js_init_navigation_mesh_source_geometry_data3d_module(JSContext *ctx) {
	return _js_init_navigation_mesh_source_geometry_data3d_module(ctx, "@godot/classes/navigation_mesh_source_geometry_data3d");
}

void __register_navigation_mesh_source_geometry_data3d() {
	js_init_navigation_mesh_source_geometry_data3d_module(js_context());
}

void register_navigation_mesh_source_geometry_data3d() {
	__register_navigation_mesh_source_geometry_data3d();
}