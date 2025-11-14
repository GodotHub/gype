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
#include <godot_cpp/classes/csg_torus3d.hpp>
using namespace godot;

static void csg_torus3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CSGTorus3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef csg_torus3d_class_def = {
    "CSGTorus3D",
    csg_torus3d_class_finalizer
};

static JSValue csg_torus3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CSGTorus3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CSGTorus3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CSGTorus3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CSGTorus3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue csg_torus3d_class_set_inner_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGTorus3D::set_inner_radius, ctx, this_val, argc, argv);
};
static JSValue csg_torus3d_class_get_inner_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGTorus3D::get_inner_radius, ctx, this_val, argc, argv);
}
static JSValue csg_torus3d_class_set_outer_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGTorus3D::set_outer_radius, ctx, this_val, argc, argv);
};
static JSValue csg_torus3d_class_get_outer_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGTorus3D::get_outer_radius, ctx, this_val, argc, argv);
}
static JSValue csg_torus3d_class_set_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGTorus3D::set_sides, ctx, this_val, argc, argv);
};
static JSValue csg_torus3d_class_get_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGTorus3D::get_sides, ctx, this_val, argc, argv);
}
static JSValue csg_torus3d_class_set_ring_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGTorus3D::set_ring_sides, ctx, this_val, argc, argv);
};
static JSValue csg_torus3d_class_get_ring_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGTorus3D::get_ring_sides, ctx, this_val, argc, argv);
}
static JSValue csg_torus3d_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGTorus3D::set_material, ctx, this_val, argc, argv);
};
static JSValue csg_torus3d_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGTorus3D::get_material, ctx, this_val, argc, argv);
}
static JSValue csg_torus3d_class_set_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGTorus3D::set_smooth_faces, ctx, this_val, argc, argv);
};
static JSValue csg_torus3d_class_get_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGTorus3D::get_smooth_faces, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry csg_torus3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_inner_radius", 1, &csg_torus3d_class_set_inner_radius),
	JS_CFUNC_DEF("get_inner_radius", 0, &csg_torus3d_class_get_inner_radius),
	JS_CFUNC_DEF("set_outer_radius", 1, &csg_torus3d_class_set_outer_radius),
	JS_CFUNC_DEF("get_outer_radius", 0, &csg_torus3d_class_get_outer_radius),
	JS_CFUNC_DEF("set_sides", 1, &csg_torus3d_class_set_sides),
	JS_CFUNC_DEF("get_sides", 0, &csg_torus3d_class_get_sides),
	JS_CFUNC_DEF("set_ring_sides", 1, &csg_torus3d_class_set_ring_sides),
	JS_CFUNC_DEF("get_ring_sides", 0, &csg_torus3d_class_get_ring_sides),
	JS_CFUNC_DEF("set_material", 1, &csg_torus3d_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &csg_torus3d_class_get_material),
	JS_CFUNC_DEF("set_smooth_faces", 1, &csg_torus3d_class_set_smooth_faces),
	JS_CFUNC_DEF("get_smooth_faces", 0, &csg_torus3d_class_get_smooth_faces),
};




static void define_csg_torus3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inner_radius"),
        JS_NewCFunction(ctx, csg_torus3d_class_get_inner_radius, "get_inner_radius", 0),
        JS_NewCFunction(ctx, csg_torus3d_class_set_inner_radius, "set_inner_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outer_radius"),
        JS_NewCFunction(ctx, csg_torus3d_class_get_outer_radius, "get_outer_radius", 0),
        JS_NewCFunction(ctx, csg_torus3d_class_set_outer_radius, "set_outer_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sides"),
        JS_NewCFunction(ctx, csg_torus3d_class_get_sides, "get_sides", 0),
        JS_NewCFunction(ctx, csg_torus3d_class_set_sides, "set_sides", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ring_sides"),
        JS_NewCFunction(ctx, csg_torus3d_class_get_ring_sides, "get_ring_sides", 0),
        JS_NewCFunction(ctx, csg_torus3d_class_set_ring_sides, "set_ring_sides", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "smooth_faces"),
        JS_NewCFunction(ctx, csg_torus3d_class_get_smooth_faces, "get_smooth_faces", 0),
        JS_NewCFunction(ctx, csg_torus3d_class_set_smooth_faces, "set_smooth_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, csg_torus3d_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, csg_torus3d_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
}

static void define_csg_torus3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_csg_torus3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CSGTorus3D"] = class_id;
	classes_by_id[class_id] = "CSGTorus3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &csg_torus3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CSGPrimitive3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_csg_torus3d_property(ctx, proto);
	define_csg_torus3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, csg_torus3d_class_proto_funcs, _countof(csg_torus3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, csg_torus3d_class_constructor, "CSGTorus3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CSGTorus3D", ctor);

	return 0;
}

JSModuleDef *_js_init_csg_torus3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/csg_primitive3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_csg_torus3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CSGTorus3D");
	return m;
}

JSModuleDef *js_init_csg_torus3d_module(JSContext *ctx) {
	return _js_init_csg_torus3d_module(ctx, "@godot/classes/csg_torus3d");
}

void __register_csg_torus3d() {
	js_init_csg_torus3d_module(js_context());
}

void register_csg_torus3d() {
	__register_csg_torus3d();
}