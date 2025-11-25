#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/shape2d.hpp>
using namespace godot;

static void shape2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Shape2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef shape2d_class_def = {
    "Shape2D",
    shape2d_class_finalizer
};

static JSValue shape2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Shape2D"];
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
        instance = memnew(Shape2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue shape2d_class_set_custom_solver_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shape2D::set_custom_solver_bias, ctx, this_val, argc, argv);
};
static JSValue shape2d_class_get_custom_solver_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shape2D::get_custom_solver_bias, ctx, this_val, argc, argv);
}
static JSValue shape2d_class_collide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Shape2D::collide, ctx, this_val, argc, argv);
};
static JSValue shape2d_class_collide_with_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Shape2D::collide_with_motion, ctx, this_val, argc, argv);
};
static JSValue shape2d_class_collide_and_get_contacts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Shape2D::collide_and_get_contacts, ctx, this_val, argc, argv);
};
static JSValue shape2d_class_collide_with_motion_and_get_contacts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Shape2D::collide_with_motion_and_get_contacts, ctx, this_val, argc, argv);
};
static JSValue shape2d_class_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shape2D::draw, ctx, this_val, argc, argv);
};
static JSValue shape2d_class_get_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shape2D::get_rect, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry shape2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_custom_solver_bias", 1, &shape2d_class_set_custom_solver_bias),
	JS_CFUNC_DEF("get_custom_solver_bias", 0, &shape2d_class_get_custom_solver_bias),
	JS_CFUNC_DEF("collide", 3, &shape2d_class_collide),
	JS_CFUNC_DEF("collide_with_motion", 5, &shape2d_class_collide_with_motion),
	JS_CFUNC_DEF("collide_and_get_contacts", 3, &shape2d_class_collide_and_get_contacts),
	JS_CFUNC_DEF("collide_with_motion_and_get_contacts", 5, &shape2d_class_collide_with_motion_and_get_contacts),
	JS_CFUNC_DEF("draw", 2, &shape2d_class_draw),
	JS_CFUNC_DEF("get_rect", 0, &shape2d_class_get_rect),
};




static void define_shape2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_solver_bias"),
        JS_NewCFunction(ctx, shape2d_class_get_custom_solver_bias, "get_custom_solver_bias", 0),
        JS_NewCFunction(ctx, shape2d_class_set_custom_solver_bias, "set_custom_solver_bias", 1),
        JS_PROP_GETSET
    );
}

static void define_shape2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_shape2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Shape2D"] = class_id;
	classes_by_id[class_id] = "Shape2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &shape2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_shape2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, shape2d_class_proto_funcs, _countof(shape2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, shape2d_class_constructor, "Shape2D", 0, JS_CFUNC_constructor, 0);
	define_shape2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Shape2D", ctor);
	ctor_list["Shape2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_shape2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_shape2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Shape2D");
	return m;
}

JSModuleDef *js_init_shape2d_module(JSContext *ctx) {
	return _js_init_shape2d_module(ctx, "@godot/classes/shape2d");
}

void __register_shape2d() {
	js_init_shape2d_module(js_context());
}

void register_shape2d() {
	__register_shape2d();
}