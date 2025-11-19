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
#include <godot_cpp/classes/capsule_mesh.hpp>
using namespace godot;

static void capsule_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CapsuleMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef capsule_mesh_class_def = {
    "CapsuleMesh",
    capsule_mesh_class_finalizer
};

static JSValue capsule_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CapsuleMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CapsuleMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CapsuleMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CapsuleMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue capsule_mesh_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleMesh::set_radius, ctx, this_val, argc, argv);
};
static JSValue capsule_mesh_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleMesh::get_radius, ctx, this_val, argc, argv);
}
static JSValue capsule_mesh_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleMesh::set_height, ctx, this_val, argc, argv);
};
static JSValue capsule_mesh_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleMesh::get_height, ctx, this_val, argc, argv);
}
static JSValue capsule_mesh_class_set_radial_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleMesh::set_radial_segments, ctx, this_val, argc, argv);
};
static JSValue capsule_mesh_class_get_radial_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleMesh::get_radial_segments, ctx, this_val, argc, argv);
}
static JSValue capsule_mesh_class_set_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleMesh::set_rings, ctx, this_val, argc, argv);
};
static JSValue capsule_mesh_class_get_rings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleMesh::get_rings, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry capsule_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &capsule_mesh_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &capsule_mesh_class_get_radius),
	JS_CFUNC_DEF("set_height", 1, &capsule_mesh_class_set_height),
	JS_CFUNC_DEF("get_height", 0, &capsule_mesh_class_get_height),
	JS_CFUNC_DEF("set_radial_segments", 1, &capsule_mesh_class_set_radial_segments),
	JS_CFUNC_DEF("get_radial_segments", 0, &capsule_mesh_class_get_radial_segments),
	JS_CFUNC_DEF("set_rings", 1, &capsule_mesh_class_set_rings),
	JS_CFUNC_DEF("get_rings", 0, &capsule_mesh_class_get_rings),
};




static void define_capsule_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, capsule_mesh_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, capsule_mesh_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, capsule_mesh_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, capsule_mesh_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_segments"),
        JS_NewCFunction(ctx, capsule_mesh_class_get_radial_segments, "get_radial_segments", 0),
        JS_NewCFunction(ctx, capsule_mesh_class_set_radial_segments, "set_radial_segments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rings"),
        JS_NewCFunction(ctx, capsule_mesh_class_get_rings, "get_rings", 0),
        JS_NewCFunction(ctx, capsule_mesh_class_set_rings, "set_rings", 1),
        JS_PROP_GETSET
    );
}

static void define_capsule_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_capsule_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CapsuleMesh"] = class_id;
	classes_by_id[class_id] = "CapsuleMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &capsule_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PrimitiveMesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_capsule_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, capsule_mesh_class_proto_funcs, _countof(capsule_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, capsule_mesh_class_constructor, "CapsuleMesh", 0, JS_CFUNC_constructor, 0);
	define_capsule_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CapsuleMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_capsule_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/primitive_mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_capsule_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CapsuleMesh");
	return m;
}

JSModuleDef *js_init_capsule_mesh_module(JSContext *ctx) {
	return _js_init_capsule_mesh_module(ctx, "@godot/classes/capsule_mesh");
}

void __register_capsule_mesh() {
	js_init_capsule_mesh_module(js_context());
}

void register_capsule_mesh() {
	__register_capsule_mesh();
}