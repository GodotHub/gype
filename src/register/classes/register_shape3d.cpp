#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/shape3d.hpp>
using namespace godot;

static void shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Shape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef shape3d_class_def = {
    "Shape3D",
    shape3d_class_finalizer
};

static JSValue shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Shape3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Shape3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Shape3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Shape3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue shape3d_class_set_custom_solver_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shape3D::set_custom_solver_bias, ctx, this_val, argc, argv);
};
static JSValue shape3d_class_get_custom_solver_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shape3D::get_custom_solver_bias, ctx, this_val, argc, argv);
}
static JSValue shape3d_class_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shape3D::set_margin, ctx, this_val, argc, argv);
};
static JSValue shape3d_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shape3D::get_margin, ctx, this_val, argc, argv);
}
static JSValue shape3d_class_get_debug_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Shape3D::get_debug_mesh, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_custom_solver_bias", 1, &shape3d_class_set_custom_solver_bias),
	JS_CFUNC_DEF("get_custom_solver_bias", 0, &shape3d_class_get_custom_solver_bias),
	JS_CFUNC_DEF("set_margin", 1, &shape3d_class_set_margin),
	JS_CFUNC_DEF("get_margin", 0, &shape3d_class_get_margin),
	JS_CFUNC_DEF("get_debug_mesh", 0, &shape3d_class_get_debug_mesh),
};




static void define_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_solver_bias"),
        JS_NewCFunction(ctx, shape3d_class_get_custom_solver_bias, "get_custom_solver_bias", 0),
        JS_NewCFunction(ctx, shape3d_class_set_custom_solver_bias, "set_custom_solver_bias", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margin"),
        JS_NewCFunction(ctx, shape3d_class_get_margin, "get_margin", 0),
        JS_NewCFunction(ctx, shape3d_class_set_margin, "set_margin", 1),
        JS_PROP_GETSET
    );
}

static void define_shape3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Shape3D"] = class_id;
	classes_by_id[class_id] = "Shape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_shape3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, shape3d_class_proto_funcs, _countof(shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, shape3d_class_constructor, "Shape3D", 0, JS_CFUNC_constructor, 0);
	define_shape3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Shape3D", ctor);

	return 0;
}

JSModuleDef *_js_init_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Shape3D");
	return m;
}

JSModuleDef *js_init_shape3d_module(JSContext *ctx) {
	return _js_init_shape3d_module(ctx, "@godot/classes/shape3d");
}

void __register_shape3d() {
	js_init_shape3d_module(js_context());
}

void register_shape3d() {
	__register_shape3d();
}