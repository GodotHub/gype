#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shape2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/capsule_shape2d.hpp>
using namespace godot;

static void capsule_shape2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CapsuleShape2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef capsule_shape2d_class_def = {
    "CapsuleShape2D",
    capsule_shape2d_class_finalizer
};

static JSValue capsule_shape2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CapsuleShape2D"];
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
        instance = memnew(CapsuleShape2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue capsule_shape2d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleShape2D::set_radius, ctx, this_val, argc, argv);
};
static JSValue capsule_shape2d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleShape2D::get_radius, ctx, this_val, argc, argv);
}
static JSValue capsule_shape2d_class_set_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleShape2D::set_height, ctx, this_val, argc, argv);
};
static JSValue capsule_shape2d_class_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleShape2D::get_height, ctx, this_val, argc, argv);
}
static JSValue capsule_shape2d_class_set_mid_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CapsuleShape2D::set_mid_height, ctx, this_val, argc, argv);
};
static JSValue capsule_shape2d_class_get_mid_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CapsuleShape2D::get_mid_height, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry capsule_shape2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &capsule_shape2d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &capsule_shape2d_class_get_radius),
	JS_CFUNC_DEF("set_height", 1, &capsule_shape2d_class_set_height),
	JS_CFUNC_DEF("get_height", 0, &capsule_shape2d_class_get_height),
	JS_CFUNC_DEF("set_mid_height", 1, &capsule_shape2d_class_set_mid_height),
	JS_CFUNC_DEF("get_mid_height", 0, &capsule_shape2d_class_get_mid_height),
};




static void define_capsule_shape2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, capsule_shape2d_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, capsule_shape2d_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height"),
        JS_NewCFunction(ctx, capsule_shape2d_class_get_height, "get_height", 0),
        JS_NewCFunction(ctx, capsule_shape2d_class_set_height, "set_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mid_height"),
        JS_NewCFunction(ctx, capsule_shape2d_class_get_mid_height, "get_mid_height", 0),
        JS_NewCFunction(ctx, capsule_shape2d_class_set_mid_height, "set_mid_height", 1),
        JS_PROP_GETSET
    );
}

static void define_capsule_shape2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_capsule_shape2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CapsuleShape2D"] = class_id;
	classes_by_id[class_id] = "CapsuleShape2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &capsule_shape2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_capsule_shape2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, capsule_shape2d_class_proto_funcs, _countof(capsule_shape2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, capsule_shape2d_class_constructor, "CapsuleShape2D", 0, JS_CFUNC_constructor, 0);
	define_capsule_shape2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CapsuleShape2D", ctor);
	ctor_list["CapsuleShape2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_capsule_shape2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_capsule_shape2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CapsuleShape2D");
	return m;
}

JSModuleDef *js_init_capsule_shape2d_module(JSContext *ctx) {
	return _js_init_capsule_shape2d_module(ctx, "@godot/classes/capsule_shape2d");
}

void __register_capsule_shape2d() {
	js_init_capsule_shape2d_module(js_context());
}

void register_capsule_shape2d() {
	__register_capsule_shape2d();
}