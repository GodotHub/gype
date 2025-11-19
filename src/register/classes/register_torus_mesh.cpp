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
#include <godot_cpp/classes/torus_mesh.hpp>
using namespace godot;

static void torus_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TorusMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef torus_mesh_class_def = {
    "TorusMesh",
    torus_mesh_class_finalizer
};

static JSValue torus_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TorusMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TorusMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TorusMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TorusMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue torus_mesh_class_set_inner_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TorusMesh::set_inner_radius, ctx, this_val, argc, argv);
};
static JSValue torus_mesh_class_get_inner_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TorusMesh::get_inner_radius, ctx, this_val, argc, argv);
}
static JSValue torus_mesh_class_set_outer_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TorusMesh::set_outer_radius, ctx, this_val, argc, argv);
};
static JSValue torus_mesh_class_get_outer_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TorusMesh::get_outer_radius, ctx, this_val, argc, argv);
}
static JSValue torus_mesh_class_set_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TorusMesh::set_rings, ctx, this_val, argc, argv);
};
static JSValue torus_mesh_class_get_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TorusMesh::get_rings, ctx, this_val, argc, argv);
}
static JSValue torus_mesh_class_set_ring_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TorusMesh::set_ring_segments, ctx, this_val, argc, argv);
};
static JSValue torus_mesh_class_get_ring_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TorusMesh::get_ring_segments, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry torus_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_inner_radius", 1, &torus_mesh_class_set_inner_radius),
	JS_CFUNC_DEF("get_inner_radius", 0, &torus_mesh_class_get_inner_radius),
	JS_CFUNC_DEF("set_outer_radius", 1, &torus_mesh_class_set_outer_radius),
	JS_CFUNC_DEF("get_outer_radius", 0, &torus_mesh_class_get_outer_radius),
	JS_CFUNC_DEF("set_rings", 1, &torus_mesh_class_set_rings),
	JS_CFUNC_DEF("get_rings", 0, &torus_mesh_class_get_rings),
	JS_CFUNC_DEF("set_ring_segments", 1, &torus_mesh_class_set_ring_segments),
	JS_CFUNC_DEF("get_ring_segments", 0, &torus_mesh_class_get_ring_segments),
};




static void define_torus_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inner_radius"),
        JS_NewCFunction(ctx, torus_mesh_class_get_inner_radius, "get_inner_radius", 0),
        JS_NewCFunction(ctx, torus_mesh_class_set_inner_radius, "set_inner_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outer_radius"),
        JS_NewCFunction(ctx, torus_mesh_class_get_outer_radius, "get_outer_radius", 0),
        JS_NewCFunction(ctx, torus_mesh_class_set_outer_radius, "set_outer_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rings"),
        JS_NewCFunction(ctx, torus_mesh_class_get_rings, "get_rings", 0),
        JS_NewCFunction(ctx, torus_mesh_class_set_rings, "set_rings", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ring_segments"),
        JS_NewCFunction(ctx, torus_mesh_class_get_ring_segments, "get_ring_segments", 0),
        JS_NewCFunction(ctx, torus_mesh_class_set_ring_segments, "set_ring_segments", 1),
        JS_PROP_GETSET
    );
}

static void define_torus_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_torus_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TorusMesh"] = class_id;
	classes_by_id[class_id] = "TorusMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &torus_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PrimitiveMesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_torus_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, torus_mesh_class_proto_funcs, _countof(torus_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, torus_mesh_class_constructor, "TorusMesh", 0, JS_CFUNC_constructor, 0);
	define_torus_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TorusMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_torus_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/primitive_mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_torus_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TorusMesh");
	return m;
}

JSModuleDef *js_init_torus_mesh_module(JSContext *ctx) {
	return _js_init_torus_mesh_module(ctx, "@godot/classes/torus_mesh");
}

void __register_torus_mesh() {
	js_init_torus_mesh_module(js_context());
}

void register_torus_mesh() {
	__register_torus_mesh();
}