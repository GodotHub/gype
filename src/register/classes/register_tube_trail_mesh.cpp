#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/classes/primitive_mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tube_trail_mesh.hpp>
using namespace godot;

static void tube_trail_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TubeTrailMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tube_trail_mesh_class_def = {
    "TubeTrailMesh",
    tube_trail_mesh_class_finalizer
};

static JSValue tube_trail_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TubeTrailMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TubeTrailMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TubeTrailMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TubeTrailMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tube_trail_mesh_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_radius, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::get_radius, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_radial_steps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_radial_steps, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_get_radial_steps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::get_radial_steps, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_sections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_sections, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_get_sections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::get_sections, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_section_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_section_length, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_get_section_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::get_section_length, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_section_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_section_rings, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_get_section_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::get_section_rings, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_cap_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_cap_top, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_is_cap_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::is_cap_top, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_cap_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_cap_bottom, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_is_cap_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::is_cap_bottom, ctx, this_val, argc, argv);
}
static JSValue tube_trail_mesh_class_set_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TubeTrailMesh::set_curve, ctx, this_val, argc, argv);
};
static JSValue tube_trail_mesh_class_get_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TubeTrailMesh::get_curve, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry tube_trail_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &tube_trail_mesh_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &tube_trail_mesh_class_get_radius),
	JS_CFUNC_DEF("set_radial_steps", 1, &tube_trail_mesh_class_set_radial_steps),
	JS_CFUNC_DEF("get_radial_steps", 0, &tube_trail_mesh_class_get_radial_steps),
	JS_CFUNC_DEF("set_sections", 1, &tube_trail_mesh_class_set_sections),
	JS_CFUNC_DEF("get_sections", 0, &tube_trail_mesh_class_get_sections),
	JS_CFUNC_DEF("set_section_length", 1, &tube_trail_mesh_class_set_section_length),
	JS_CFUNC_DEF("get_section_length", 0, &tube_trail_mesh_class_get_section_length),
	JS_CFUNC_DEF("set_section_rings", 1, &tube_trail_mesh_class_set_section_rings),
	JS_CFUNC_DEF("get_section_rings", 0, &tube_trail_mesh_class_get_section_rings),
	JS_CFUNC_DEF("set_cap_top", 1, &tube_trail_mesh_class_set_cap_top),
	JS_CFUNC_DEF("is_cap_top", 0, &tube_trail_mesh_class_is_cap_top),
	JS_CFUNC_DEF("set_cap_bottom", 1, &tube_trail_mesh_class_set_cap_bottom),
	JS_CFUNC_DEF("is_cap_bottom", 0, &tube_trail_mesh_class_is_cap_bottom),
	JS_CFUNC_DEF("set_curve", 1, &tube_trail_mesh_class_set_curve),
	JS_CFUNC_DEF("get_curve", 0, &tube_trail_mesh_class_get_curve),
};




static void define_tube_trail_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_steps"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_get_radial_steps, "get_radial_steps", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_radial_steps, "set_radial_steps", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sections"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_get_sections, "get_sections", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_sections, "set_sections", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "section_length"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_get_section_length, "get_section_length", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_section_length, "set_section_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "section_rings"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_get_section_rings, "get_section_rings", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_section_rings, "set_section_rings", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cap_top"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_is_cap_top, "is_cap_top", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_cap_top, "set_cap_top", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cap_bottom"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_is_cap_bottom, "is_cap_bottom", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_cap_bottom, "set_cap_bottom", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "curve"),
        JS_NewCFunction(ctx, tube_trail_mesh_class_get_curve, "get_curve", 0),
        JS_NewCFunction(ctx, tube_trail_mesh_class_set_curve, "set_curve", 1),
        JS_PROP_GETSET
    );
}

static void define_tube_trail_mesh_enum(JSContext *ctx, JSValue proto) {
}

static int js_tube_trail_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TubeTrailMesh"] = class_id;
	classes_by_id[class_id] = "TubeTrailMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tube_trail_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PrimitiveMesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tube_trail_mesh_property(ctx, proto);
	define_tube_trail_mesh_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tube_trail_mesh_class_proto_funcs, _countof(tube_trail_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tube_trail_mesh_class_constructor, "TubeTrailMesh", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TubeTrailMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_tube_trail_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/primitive_mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tube_trail_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TubeTrailMesh");
	return m;
}

JSModuleDef *js_init_tube_trail_mesh_module(JSContext *ctx) {
	return _js_init_tube_trail_mesh_module(ctx, "@godot/classes/tube_trail_mesh");
}

void __register_tube_trail_mesh() {
	js_init_tube_trail_mesh_module(js_context());
}

void register_tube_trail_mesh() {
	__register_tube_trail_mesh();
}