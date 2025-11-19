#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/geometry_instance3d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/mesh_convex_decomposition_settings.hpp>
#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/classes/skin_reference.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
using namespace godot;

static void mesh_instance3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MeshInstance3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef mesh_instance3d_class_def = {
    "MeshInstance3D",
    mesh_instance3d_class_finalizer
};

static JSValue mesh_instance3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MeshInstance3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MeshInstance3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MeshInstance3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MeshInstance3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue mesh_instance3d_class_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::set_mesh, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_mesh, ctx, this_val, argc, argv);
}
static JSValue mesh_instance3d_class_set_skeleton_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::set_skeleton_path, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_skeleton_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		MeshInstance3D *obj = static_cast<MeshInstance3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_skeleton_path();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		MeshInstance3D *js_proxy = static_cast<MeshInstance3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_skeleton_path(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue mesh_instance3d_class_set_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::set_skin, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_skin, ctx, this_val, argc, argv);
}
static JSValue mesh_instance3d_class_get_skin_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_skin_reference, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_surface_override_material_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_surface_override_material_count, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_set_surface_override_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::set_surface_override_material, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_surface_override_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_surface_override_material, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_active_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_active_material, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_create_trimesh_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::create_trimesh_collision, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_create_convex_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::create_convex_collision, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_create_multiple_convex_collisions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::create_multiple_convex_collisions, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_blend_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_blend_shape_count, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_find_blend_shape_by_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MeshInstance3D::find_blend_shape_by_name, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_get_blend_shape_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshInstance3D::get_blend_shape_value, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_set_blend_shape_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::set_blend_shape_value, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_create_debug_tangents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshInstance3D::create_debug_tangents, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_bake_mesh_from_current_blend_shape_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MeshInstance3D::bake_mesh_from_current_blend_shape_mix, ctx, this_val, argc, argv);
};
static JSValue mesh_instance3d_class_bake_mesh_from_current_skeleton_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MeshInstance3D::bake_mesh_from_current_skeleton_pose, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry mesh_instance3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mesh", 1, &mesh_instance3d_class_set_mesh),
	JS_CFUNC_DEF("get_mesh", 0, &mesh_instance3d_class_get_mesh),
	JS_CFUNC_DEF("set_skeleton_path", 1, &mesh_instance3d_class_set_skeleton_path),
	JS_CFUNC_DEF("get_skeleton_path", 0, &mesh_instance3d_class_get_skeleton_path),
	JS_CFUNC_DEF("set_skin", 1, &mesh_instance3d_class_set_skin),
	JS_CFUNC_DEF("get_skin", 0, &mesh_instance3d_class_get_skin),
	JS_CFUNC_DEF("get_skin_reference", 0, &mesh_instance3d_class_get_skin_reference),
	JS_CFUNC_DEF("get_surface_override_material_count", 0, &mesh_instance3d_class_get_surface_override_material_count),
	JS_CFUNC_DEF("set_surface_override_material", 2, &mesh_instance3d_class_set_surface_override_material),
	JS_CFUNC_DEF("get_surface_override_material", 1, &mesh_instance3d_class_get_surface_override_material),
	JS_CFUNC_DEF("get_active_material", 1, &mesh_instance3d_class_get_active_material),
	JS_CFUNC_DEF("create_trimesh_collision", 0, &mesh_instance3d_class_create_trimesh_collision),
	JS_CFUNC_DEF("create_convex_collision", 2, &mesh_instance3d_class_create_convex_collision),
	JS_CFUNC_DEF("create_multiple_convex_collisions", 1, &mesh_instance3d_class_create_multiple_convex_collisions),
	JS_CFUNC_DEF("get_blend_shape_count", 0, &mesh_instance3d_class_get_blend_shape_count),
	JS_CFUNC_DEF("find_blend_shape_by_name", 1, &mesh_instance3d_class_find_blend_shape_by_name),
	JS_CFUNC_DEF("get_blend_shape_value", 1, &mesh_instance3d_class_get_blend_shape_value),
	JS_CFUNC_DEF("set_blend_shape_value", 2, &mesh_instance3d_class_set_blend_shape_value),
	JS_CFUNC_DEF("create_debug_tangents", 0, &mesh_instance3d_class_create_debug_tangents),
	JS_CFUNC_DEF("bake_mesh_from_current_blend_shape_mix", 1, &mesh_instance3d_class_bake_mesh_from_current_blend_shape_mix),
	JS_CFUNC_DEF("bake_mesh_from_current_skeleton_pose", 1, &mesh_instance3d_class_bake_mesh_from_current_skeleton_pose),
};




static void define_mesh_instance3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh"),
        JS_NewCFunction(ctx, mesh_instance3d_class_get_mesh, "get_mesh", 0),
        JS_NewCFunction(ctx, mesh_instance3d_class_set_mesh, "set_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skin"),
        JS_NewCFunction(ctx, mesh_instance3d_class_get_skin, "get_skin", 0),
        JS_NewCFunction(ctx, mesh_instance3d_class_set_skin, "set_skin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skeleton"),
        JS_NewCFunction(ctx, mesh_instance3d_class_get_skeleton_path, "get_skeleton_path", 0),
        JS_NewCFunction(ctx, mesh_instance3d_class_set_skeleton_path, "set_skeleton_path", 1),
        JS_PROP_GETSET
    );
}

static void define_mesh_instance3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_mesh_instance3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MeshInstance3D"] = class_id;
	classes_by_id[class_id] = "MeshInstance3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &mesh_instance3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GeometryInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_mesh_instance3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, mesh_instance3d_class_proto_funcs, _countof(mesh_instance3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, mesh_instance3d_class_constructor, "MeshInstance3D", 0, JS_CFUNC_constructor, 0);
	define_mesh_instance3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MeshInstance3D", ctor);

	return 0;
}

JSModuleDef *_js_init_mesh_instance3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/geometry_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_mesh_instance3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MeshInstance3D");
	return m;
}

JSModuleDef *js_init_mesh_instance3d_module(JSContext *ctx) {
	return _js_init_mesh_instance3d_module(ctx, "@godot/classes/mesh_instance3d");
}

void __register_mesh_instance3d() {
	js_init_mesh_instance3d_module(js_context());
}

void register_mesh_instance3d() {
	__register_mesh_instance3d();
}