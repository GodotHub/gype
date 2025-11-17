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
#include <godot_cpp/classes/world_boundary_shape3d.hpp>
using namespace godot;

static void world_boundary_shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WorldBoundaryShape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef world_boundary_shape3d_class_def = {
    "WorldBoundaryShape3D",
    world_boundary_shape3d_class_finalizer
};

static JSValue world_boundary_shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WorldBoundaryShape3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WorldBoundaryShape3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WorldBoundaryShape3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WorldBoundaryShape3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue world_boundary_shape3d_class_set_plane(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WorldBoundaryShape3D::set_plane, ctx, this_val, argc, argv);
};
static JSValue world_boundary_shape3d_class_get_plane(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Plane> *proxy = memnew(ObjectProxy<Plane>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Plane {
		WorldBoundaryShape3D *obj = static_cast<WorldBoundaryShape3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_plane();
	};
	proxy->setter = [this_val](const Plane &value) -> void {
		WorldBoundaryShape3D *js_proxy = static_cast<WorldBoundaryShape3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_plane(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PlaneProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PlaneProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry world_boundary_shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_plane", 1, &world_boundary_shape3d_class_set_plane),
	JS_CFUNC_DEF("get_plane", 0, &world_boundary_shape3d_class_get_plane),
};




static void define_world_boundary_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "plane"),
        JS_NewCFunction(ctx, world_boundary_shape3d_class_get_plane, "get_plane", 0),
        JS_NewCFunction(ctx, world_boundary_shape3d_class_set_plane, "set_plane", 1),
        JS_PROP_GETSET
    );
}

static void define_world_boundary_shape3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_world_boundary_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WorldBoundaryShape3D"] = class_id;
	classes_by_id[class_id] = "WorldBoundaryShape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &world_boundary_shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_world_boundary_shape3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, world_boundary_shape3d_class_proto_funcs, _countof(world_boundary_shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, world_boundary_shape3d_class_constructor, "WorldBoundaryShape3D", 0, JS_CFUNC_constructor, 0);
	define_world_boundary_shape3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WorldBoundaryShape3D", ctor);

	return 0;
}

JSModuleDef *_js_init_world_boundary_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_world_boundary_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WorldBoundaryShape3D");
	return m;
}

JSModuleDef *js_init_world_boundary_shape3d_module(JSContext *ctx) {
	return _js_init_world_boundary_shape3d_module(ctx, "@godot/classes/world_boundary_shape3d");
}

void __register_world_boundary_shape3d() {
	js_init_world_boundary_shape3d_module(js_context());
}

void register_world_boundary_shape3d() {
	__register_world_boundary_shape3d();
}