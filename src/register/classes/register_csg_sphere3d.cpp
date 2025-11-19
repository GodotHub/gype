#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/csg_primitive3d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/csg_sphere3d.hpp>
using namespace godot;

static void csg_sphere3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CSGSphere3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef csg_sphere3d_class_def = {
    "CSGSphere3D",
    csg_sphere3d_class_finalizer
};

static JSValue csg_sphere3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CSGSphere3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CSGSphere3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CSGSphere3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CSGSphere3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue csg_sphere3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGSphere3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue csg_sphere3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGSphere3D::get_radius, ctx, this_val, argc, argv);
}
static JSValue csg_sphere3d_class_set_radial_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGSphere3D::set_radial_segments, ctx, this_val, argc, argv);
};
static JSValue csg_sphere3d_class_get_radial_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGSphere3D::get_radial_segments, ctx, this_val, argc, argv);
}
static JSValue csg_sphere3d_class_set_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGSphere3D::set_rings, ctx, this_val, argc, argv);
};
static JSValue csg_sphere3d_class_get_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGSphere3D::get_rings, ctx, this_val, argc, argv);
}
static JSValue csg_sphere3d_class_set_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGSphere3D::set_smooth_faces, ctx, this_val, argc, argv);
};
static JSValue csg_sphere3d_class_get_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGSphere3D::get_smooth_faces, ctx, this_val, argc, argv);
}
static JSValue csg_sphere3d_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGSphere3D::set_material, ctx, this_val, argc, argv);
};
static JSValue csg_sphere3d_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGSphere3D::get_material, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry csg_sphere3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &csg_sphere3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &csg_sphere3d_class_get_radius),
	JS_CFUNC_DEF("set_radial_segments", 1, &csg_sphere3d_class_set_radial_segments),
	JS_CFUNC_DEF("get_radial_segments", 0, &csg_sphere3d_class_get_radial_segments),
	JS_CFUNC_DEF("set_rings", 1, &csg_sphere3d_class_set_rings),
	JS_CFUNC_DEF("get_rings", 0, &csg_sphere3d_class_get_rings),
	JS_CFUNC_DEF("set_smooth_faces", 1, &csg_sphere3d_class_set_smooth_faces),
	JS_CFUNC_DEF("get_smooth_faces", 0, &csg_sphere3d_class_get_smooth_faces),
	JS_CFUNC_DEF("set_material", 1, &csg_sphere3d_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &csg_sphere3d_class_get_material),
};




static void define_csg_sphere3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, csg_sphere3d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, csg_sphere3d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_segments"),
        JS_NewCFunction(ctx, csg_sphere3d_class_get_radial_segments, "get_radial_segments", 0),
        JS_NewCFunction(ctx, csg_sphere3d_class_set_radial_segments, "set_radial_segments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rings"),
        JS_NewCFunction(ctx, csg_sphere3d_class_get_rings, "get_rings", 0),
        JS_NewCFunction(ctx, csg_sphere3d_class_set_rings, "set_rings", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "smooth_faces"),
        JS_NewCFunction(ctx, csg_sphere3d_class_get_smooth_faces, "get_smooth_faces", 0),
        JS_NewCFunction(ctx, csg_sphere3d_class_set_smooth_faces, "set_smooth_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, csg_sphere3d_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, csg_sphere3d_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
}

static void define_csg_sphere3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_csg_sphere3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CSGSphere3D"] = class_id;
	classes_by_id[class_id] = "CSGSphere3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &csg_sphere3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CSGPrimitive3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_csg_sphere3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, csg_sphere3d_class_proto_funcs, _countof(csg_sphere3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, csg_sphere3d_class_constructor, "CSGSphere3D", 0, JS_CFUNC_constructor, 0);
	define_csg_sphere3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CSGSphere3D", ctor);

	return 0;
}

JSModuleDef *_js_init_csg_sphere3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/csg_primitive3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_csg_sphere3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CSGSphere3D");
	return m;
}

JSModuleDef *js_init_csg_sphere3d_module(JSContext *ctx) {
	return _js_init_csg_sphere3d_module(ctx, "@godot/classes/csg_sphere3d");
}

void __register_csg_sphere3d() {
	js_init_csg_sphere3d_module(js_context());
}

void register_csg_sphere3d() {
	__register_csg_sphere3d();
}