#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/primitive_mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/cylinder_mesh.hpp>
using namespace godot;

static void cylinder_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CylinderMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef cylinder_mesh_class_def = {
    "CylinderMesh",
    cylinder_mesh_class_finalizer
};

static JSValue cylinder_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CylinderMesh"];
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
        instance = memnew(CylinderMesh);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue cylinder_mesh_class_set_top_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_top_radius, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_get_top_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::get_top_radius, ctx, this_val, argc, argv);
}
static JSValue cylinder_mesh_class_set_bottom_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_bottom_radius, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_get_bottom_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::get_bottom_radius, ctx, this_val, argc, argv);
}
static JSValue cylinder_mesh_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_height, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::get_height, ctx, this_val, argc, argv);
}
static JSValue cylinder_mesh_class_set_radial_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_radial_segments, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_get_radial_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::get_radial_segments, ctx, this_val, argc, argv);
}
static JSValue cylinder_mesh_class_set_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_rings, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_get_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::get_rings, ctx, this_val, argc, argv);
}
static JSValue cylinder_mesh_class_set_cap_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_cap_top, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_is_cap_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::is_cap_top, ctx, this_val, argc, argv);
}
static JSValue cylinder_mesh_class_set_cap_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CylinderMesh::set_cap_bottom, ctx, this_val, argc, argv);
};
static JSValue cylinder_mesh_class_is_cap_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CylinderMesh::is_cap_bottom, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry cylinder_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_top_radius", 1, &cylinder_mesh_class_set_top_radius),
	JS_CFUNC_DEF("get_top_radius", 0, &cylinder_mesh_class_get_top_radius),
	JS_CFUNC_DEF("set_bottom_radius", 1, &cylinder_mesh_class_set_bottom_radius),
	JS_CFUNC_DEF("get_bottom_radius", 0, &cylinder_mesh_class_get_bottom_radius),
	JS_CFUNC_DEF("set_height", 1, &cylinder_mesh_class_set_height),
	JS_CFUNC_DEF("get_height", 0, &cylinder_mesh_class_get_height),
	JS_CFUNC_DEF("set_radial_segments", 1, &cylinder_mesh_class_set_radial_segments),
	JS_CFUNC_DEF("get_radial_segments", 0, &cylinder_mesh_class_get_radial_segments),
	JS_CFUNC_DEF("set_rings", 1, &cylinder_mesh_class_set_rings),
	JS_CFUNC_DEF("get_rings", 0, &cylinder_mesh_class_get_rings),
	JS_CFUNC_DEF("set_cap_top", 1, &cylinder_mesh_class_set_cap_top),
	JS_CFUNC_DEF("is_cap_top", 0, &cylinder_mesh_class_is_cap_top),
	JS_CFUNC_DEF("set_cap_bottom", 1, &cylinder_mesh_class_set_cap_bottom),
	JS_CFUNC_DEF("is_cap_bottom", 0, &cylinder_mesh_class_is_cap_bottom),
};




static void define_cylinder_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "top_radius"),
        JS_NewCFunction(ctx, cylinder_mesh_class_get_top_radius, "get_top_radius", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_top_radius, "set_top_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bottom_radius"),
        JS_NewCFunction(ctx, cylinder_mesh_class_get_bottom_radius, "get_bottom_radius", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_bottom_radius, "set_bottom_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, cylinder_mesh_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_segments"),
        JS_NewCFunction(ctx, cylinder_mesh_class_get_radial_segments, "get_radial_segments", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_radial_segments, "set_radial_segments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rings"),
        JS_NewCFunction(ctx, cylinder_mesh_class_get_rings, "get_rings", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_rings, "set_rings", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cap_top"),
        JS_NewCFunction(ctx, cylinder_mesh_class_is_cap_top, "is_cap_top", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_cap_top, "set_cap_top", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cap_bottom"),
        JS_NewCFunction(ctx, cylinder_mesh_class_is_cap_bottom, "is_cap_bottom", 0),
        JS_NewCFunction(ctx, cylinder_mesh_class_set_cap_bottom, "set_cap_bottom", 1),
        JS_PROP_GETSET
    );
}

static void define_cylinder_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_cylinder_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CylinderMesh"] = class_id;
	classes_by_id[class_id] = "CylinderMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &cylinder_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PrimitiveMesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_cylinder_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, cylinder_mesh_class_proto_funcs, _countof(cylinder_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, cylinder_mesh_class_constructor, "CylinderMesh", 0, JS_CFUNC_constructor, 0);
	define_cylinder_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CylinderMesh", ctor);
	ctor_list["CylinderMesh"] = ctor;

	return 0;
}

JSModuleDef *_js_init_cylinder_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/primitive_mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_cylinder_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CylinderMesh");
	return m;
}

JSModuleDef *js_init_cylinder_mesh_module(JSContext *ctx) {
	return _js_init_cylinder_mesh_module(ctx, "@godot/classes/cylinder_mesh");
}

void __register_cylinder_mesh() {
	js_init_cylinder_mesh_module(js_context());
}

void register_cylinder_mesh() {
	__register_cylinder_mesh();
}