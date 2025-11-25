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
#include <godot_cpp/classes/csg_cylinder3d.hpp>
using namespace godot;

static void csg_cylinder3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CSGCylinder3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef csg_cylinder3d_class_def = {
    "CSGCylinder3D",
    csg_cylinder3d_class_finalizer
};

static JSValue csg_cylinder3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CSGCylinder3D"];
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
        instance = memnew(CSGCylinder3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue csg_cylinder3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGCylinder3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue csg_cylinder3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGCylinder3D::get_radius, ctx, this_val, argc, argv);
}
static JSValue csg_cylinder3d_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGCylinder3D::set_height, ctx, this_val, argc, argv);
};
static JSValue csg_cylinder3d_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGCylinder3D::get_height, ctx, this_val, argc, argv);
}
static JSValue csg_cylinder3d_class_set_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGCylinder3D::set_sides, ctx, this_val, argc, argv);
};
static JSValue csg_cylinder3d_class_get_sides(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGCylinder3D::get_sides, ctx, this_val, argc, argv);
}
static JSValue csg_cylinder3d_class_set_cone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGCylinder3D::set_cone, ctx, this_val, argc, argv);
};
static JSValue csg_cylinder3d_class_is_cone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGCylinder3D::is_cone, ctx, this_val, argc, argv);
}
static JSValue csg_cylinder3d_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGCylinder3D::set_material, ctx, this_val, argc, argv);
};
static JSValue csg_cylinder3d_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGCylinder3D::get_material, ctx, this_val, argc, argv);
}
static JSValue csg_cylinder3d_class_set_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CSGCylinder3D::set_smooth_faces, ctx, this_val, argc, argv);
};
static JSValue csg_cylinder3d_class_get_smooth_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CSGCylinder3D::get_smooth_faces, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry csg_cylinder3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &csg_cylinder3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &csg_cylinder3d_class_get_radius),
	JS_CFUNC_DEF("set_height", 1, &csg_cylinder3d_class_set_height),
	JS_CFUNC_DEF("get_height", 0, &csg_cylinder3d_class_get_height),
	JS_CFUNC_DEF("set_sides", 1, &csg_cylinder3d_class_set_sides),
	JS_CFUNC_DEF("get_sides", 0, &csg_cylinder3d_class_get_sides),
	JS_CFUNC_DEF("set_cone", 1, &csg_cylinder3d_class_set_cone),
	JS_CFUNC_DEF("is_cone", 0, &csg_cylinder3d_class_is_cone),
	JS_CFUNC_DEF("set_material", 1, &csg_cylinder3d_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &csg_cylinder3d_class_get_material),
	JS_CFUNC_DEF("set_smooth_faces", 1, &csg_cylinder3d_class_set_smooth_faces),
	JS_CFUNC_DEF("get_smooth_faces", 0, &csg_cylinder3d_class_get_smooth_faces),
};




static void define_csg_cylinder3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, csg_cylinder3d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, csg_cylinder3d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, csg_cylinder3d_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, csg_cylinder3d_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sides"),
        JS_NewCFunction(ctx, csg_cylinder3d_class_get_sides, "get_sides", 0),
        JS_NewCFunction(ctx, csg_cylinder3d_class_set_sides, "set_sides", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cone"),
        JS_NewCFunction(ctx, csg_cylinder3d_class_is_cone, "is_cone", 0),
        JS_NewCFunction(ctx, csg_cylinder3d_class_set_cone, "set_cone", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "smooth_faces"),
        JS_NewCFunction(ctx, csg_cylinder3d_class_get_smooth_faces, "get_smooth_faces", 0),
        JS_NewCFunction(ctx, csg_cylinder3d_class_set_smooth_faces, "set_smooth_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, csg_cylinder3d_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, csg_cylinder3d_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
}

static void define_csg_cylinder3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_csg_cylinder3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CSGCylinder3D"] = class_id;
	classes_by_id[class_id] = "CSGCylinder3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &csg_cylinder3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CSGPrimitive3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_csg_cylinder3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, csg_cylinder3d_class_proto_funcs, _countof(csg_cylinder3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, csg_cylinder3d_class_constructor, "CSGCylinder3D", 0, JS_CFUNC_constructor, 0);
	define_csg_cylinder3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CSGCylinder3D", ctor);
	ctor_list["CSGCylinder3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_csg_cylinder3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/csg_primitive3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_csg_cylinder3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CSGCylinder3D");
	return m;
}

JSModuleDef *js_init_csg_cylinder3d_module(JSContext *ctx) {
	return _js_init_csg_cylinder3d_module(ctx, "@godot/classes/csg_cylinder3d");
}

void __register_csg_cylinder3d() {
	js_init_csg_cylinder3d_module(js_context());
}

void register_csg_cylinder3d() {
	__register_csg_cylinder3d();
}