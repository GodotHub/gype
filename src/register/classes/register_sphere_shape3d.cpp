#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/sphere_shape3d.hpp>
using namespace godot;

static void sphere_shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SphereShape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef sphere_shape3d_class_def = {
    "SphereShape3D",
    sphere_shape3d_class_finalizer
};

static JSValue sphere_shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SphereShape3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SphereShape3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SphereShape3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SphereShape3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue sphere_shape3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SphereShape3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue sphere_shape3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SphereShape3D::get_radius, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry sphere_shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &sphere_shape3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &sphere_shape3d_class_get_radius),
};




static void define_sphere_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, sphere_shape3d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, sphere_shape3d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
}

static void define_sphere_shape3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_sphere_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SphereShape3D"] = class_id;
	classes_by_id[class_id] = "SphereShape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &sphere_shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_sphere_shape3d_property(ctx, proto);
	define_sphere_shape3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, sphere_shape3d_class_proto_funcs, _countof(sphere_shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, sphere_shape3d_class_constructor, "SphereShape3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SphereShape3D", ctor);

	return 0;
}

JSModuleDef *_js_init_sphere_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_sphere_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SphereShape3D");
	return m;
}

JSModuleDef *js_init_sphere_shape3d_module(JSContext *ctx) {
	return _js_init_sphere_shape3d_module(ctx, "@godot/classes/sphere_shape3d");
}

void __register_sphere_shape3d() {
	js_init_sphere_shape3d_module(js_context());
}

void register_sphere_shape3d() {
	__register_sphere_shape3d();
}