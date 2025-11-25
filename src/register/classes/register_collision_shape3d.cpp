#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>
using namespace godot;

static void collision_shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CollisionShape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef collision_shape3d_class_def = {
    "CollisionShape3D",
    collision_shape3d_class_finalizer
};

static JSValue collision_shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CollisionShape3D"];
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
        instance = memnew(CollisionShape3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue collision_shape3d_class_resource_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionShape3D::resource_changed, ctx, this_val, argc, argv);
};
static JSValue collision_shape3d_class_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionShape3D::set_shape, ctx, this_val, argc, argv);
};
static JSValue collision_shape3d_class_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionShape3D::get_shape, ctx, this_val, argc, argv);
}
static JSValue collision_shape3d_class_set_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionShape3D::set_disabled, ctx, this_val, argc, argv);
};
static JSValue collision_shape3d_class_is_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionShape3D::is_disabled, ctx, this_val, argc, argv);
}
static JSValue collision_shape3d_class_make_convex_from_siblings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionShape3D::make_convex_from_siblings, ctx, this_val, argc, argv);
};
static JSValue collision_shape3d_class_set_debug_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionShape3D::set_debug_color, ctx, this_val, argc, argv);
};
static JSValue collision_shape3d_class_get_debug_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CollisionShape3D *obj = static_cast<CollisionShape3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_debug_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CollisionShape3D *js_proxy = static_cast<CollisionShape3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_debug_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue collision_shape3d_class_set_enable_debug_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CollisionShape3D::set_enable_debug_fill, ctx, this_val, argc, argv);
};
static JSValue collision_shape3d_class_get_enable_debug_fill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CollisionShape3D::get_enable_debug_fill, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry collision_shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("resource_changed", 1, &collision_shape3d_class_resource_changed),
	JS_CFUNC_DEF("set_shape", 1, &collision_shape3d_class_set_shape),
	JS_CFUNC_DEF("get_shape", 0, &collision_shape3d_class_get_shape),
	JS_CFUNC_DEF("set_disabled", 1, &collision_shape3d_class_set_disabled),
	JS_CFUNC_DEF("is_disabled", 0, &collision_shape3d_class_is_disabled),
	JS_CFUNC_DEF("make_convex_from_siblings", 0, &collision_shape3d_class_make_convex_from_siblings),
	JS_CFUNC_DEF("set_debug_color", 1, &collision_shape3d_class_set_debug_color),
	JS_CFUNC_DEF("get_debug_color", 0, &collision_shape3d_class_get_debug_color),
	JS_CFUNC_DEF("set_enable_debug_fill", 1, &collision_shape3d_class_set_enable_debug_fill),
	JS_CFUNC_DEF("get_enable_debug_fill", 0, &collision_shape3d_class_get_enable_debug_fill),
};




static void define_collision_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape"),
        JS_NewCFunction(ctx, collision_shape3d_class_get_shape, "get_shape", 0),
        JS_NewCFunction(ctx, collision_shape3d_class_set_shape, "set_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "disabled"),
        JS_NewCFunction(ctx, collision_shape3d_class_is_disabled, "is_disabled", 0),
        JS_NewCFunction(ctx, collision_shape3d_class_set_disabled, "set_disabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_color"),
        JS_NewCFunction(ctx, collision_shape3d_class_get_debug_color, "get_debug_color", 0),
        JS_NewCFunction(ctx, collision_shape3d_class_set_debug_color, "set_debug_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_fill"),
        JS_NewCFunction(ctx, collision_shape3d_class_get_enable_debug_fill, "get_enable_debug_fill", 0),
        JS_NewCFunction(ctx, collision_shape3d_class_set_enable_debug_fill, "set_enable_debug_fill", 1),
        JS_PROP_GETSET
    );
}

static void define_collision_shape3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_collision_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CollisionShape3D"] = class_id;
	classes_by_id[class_id] = "CollisionShape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &collision_shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_collision_shape3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, collision_shape3d_class_proto_funcs, _countof(collision_shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, collision_shape3d_class_constructor, "CollisionShape3D", 0, JS_CFUNC_constructor, 0);
	define_collision_shape3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CollisionShape3D", ctor);
	ctor_list["CollisionShape3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_collision_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_collision_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CollisionShape3D");
	return m;
}

JSModuleDef *js_init_collision_shape3d_module(JSContext *ctx) {
	return _js_init_collision_shape3d_module(ctx, "@godot/classes/collision_shape3d");
}

void __register_collision_shape3d() {
	js_init_collision_shape3d_module(js_context());
}

void register_collision_shape3d() {
	__register_collision_shape3d();
}