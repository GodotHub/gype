#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/spring_arm3d.hpp>
using namespace godot;

static void spring_arm3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpringArm3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spring_arm3d_class_def = {
    "SpringArm3D",
    spring_arm3d_class_finalizer
};

static JSValue spring_arm3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpringArm3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SpringArm3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SpringArm3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SpringArm3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue spring_arm3d_class_get_hit_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SpringArm3D::get_hit_length, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_set_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringArm3D::set_length, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringArm3D::get_length, ctx, this_val, argc, argv);
}
static JSValue spring_arm3d_class_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringArm3D::set_shape, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringArm3D::get_shape, ctx, this_val, argc, argv);
}
static JSValue spring_arm3d_class_add_excluded_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringArm3D::add_excluded_object, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_remove_excluded_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SpringArm3D::remove_excluded_object, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_clear_excluded_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringArm3D::clear_excluded_objects, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringArm3D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SpringArm3D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue spring_arm3d_class_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringArm3D::set_margin, ctx, this_val, argc, argv);
};
static JSValue spring_arm3d_class_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SpringArm3D::get_margin, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry spring_arm3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_hit_length", 0, &spring_arm3d_class_get_hit_length),
	JS_CFUNC_DEF("set_length", 1, &spring_arm3d_class_set_length),
	JS_CFUNC_DEF("get_length", 0, &spring_arm3d_class_get_length),
	JS_CFUNC_DEF("set_shape", 1, &spring_arm3d_class_set_shape),
	JS_CFUNC_DEF("get_shape", 0, &spring_arm3d_class_get_shape),
	JS_CFUNC_DEF("add_excluded_object", 1, &spring_arm3d_class_add_excluded_object),
	JS_CFUNC_DEF("remove_excluded_object", 1, &spring_arm3d_class_remove_excluded_object),
	JS_CFUNC_DEF("clear_excluded_objects", 0, &spring_arm3d_class_clear_excluded_objects),
	JS_CFUNC_DEF("set_collision_mask", 1, &spring_arm3d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &spring_arm3d_class_get_collision_mask),
	JS_CFUNC_DEF("set_margin", 1, &spring_arm3d_class_set_margin),
	JS_CFUNC_DEF("get_margin", 0, &spring_arm3d_class_get_margin),
};




static void define_spring_arm3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, spring_arm3d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, spring_arm3d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape"),
        JS_NewCFunction(ctx, spring_arm3d_class_get_shape, "get_shape", 0),
        JS_NewCFunction(ctx, spring_arm3d_class_set_shape, "set_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spring_length"),
        JS_NewCFunction(ctx, spring_arm3d_class_get_length, "get_length", 0),
        JS_NewCFunction(ctx, spring_arm3d_class_set_length, "set_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "margin"),
        JS_NewCFunction(ctx, spring_arm3d_class_get_margin, "get_margin", 0),
        JS_NewCFunction(ctx, spring_arm3d_class_set_margin, "set_margin", 1),
        JS_PROP_GETSET
    );
}

static void define_spring_arm3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_spring_arm3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpringArm3D"] = class_id;
	classes_by_id[class_id] = "SpringArm3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spring_arm3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spring_arm3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, spring_arm3d_class_proto_funcs, _countof(spring_arm3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, spring_arm3d_class_constructor, "SpringArm3D", 0, JS_CFUNC_constructor, 0);
	define_spring_arm3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpringArm3D", ctor);

	return 0;
}

JSModuleDef *_js_init_spring_arm3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spring_arm3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpringArm3D");
	return m;
}

JSModuleDef *js_init_spring_arm3d_module(JSContext *ctx) {
	return _js_init_spring_arm3d_module(ctx, "@godot/classes/spring_arm3d");
}

void __register_spring_arm3d() {
	js_init_spring_arm3d_module(js_context());
}

void register_spring_arm3d() {
	__register_spring_arm3d();
}