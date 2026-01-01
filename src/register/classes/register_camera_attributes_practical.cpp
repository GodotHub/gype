#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera_attributes.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/camera_attributes_practical.hpp>
using namespace godot;

static void camera_attributes_practical_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CameraAttributesPractical"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef camera_attributes_practical_class_def = {
    "CameraAttributesPractical",
    camera_attributes_practical_class_finalizer
};

static JSValue camera_attributes_practical_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CameraAttributesPractical"];
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
        instance = memnew(CameraAttributesPractical);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue camera_attributes_practical_class_set_dof_blur_far_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_far_enabled, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_is_dof_blur_far_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::is_dof_blur_far_enabled, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_dof_blur_far_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_far_distance, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_dof_blur_far_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_dof_blur_far_distance, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_dof_blur_far_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_far_transition, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_dof_blur_far_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_dof_blur_far_transition, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_dof_blur_near_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_near_enabled, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_is_dof_blur_near_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::is_dof_blur_near_enabled, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_dof_blur_near_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_near_distance, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_dof_blur_near_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_dof_blur_near_distance, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_dof_blur_near_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_near_transition, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_dof_blur_near_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_dof_blur_near_transition, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_dof_blur_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_dof_blur_amount, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_dof_blur_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_dof_blur_amount, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_auto_exposure_max_sensitivity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_auto_exposure_max_sensitivity, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_auto_exposure_max_sensitivity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_auto_exposure_max_sensitivity, ctx, this_val, argc, argv);
}
static JSValue camera_attributes_practical_class_set_auto_exposure_min_sensitivity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CameraAttributesPractical::set_auto_exposure_min_sensitivity, ctx, this_val, argc, argv);
};
static JSValue camera_attributes_practical_class_get_auto_exposure_min_sensitivity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CameraAttributesPractical::get_auto_exposure_min_sensitivity, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry camera_attributes_practical_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_dof_blur_far_enabled", 1, &camera_attributes_practical_class_set_dof_blur_far_enabled),
	JS_CFUNC_DEF("is_dof_blur_far_enabled", 0, &camera_attributes_practical_class_is_dof_blur_far_enabled),
	JS_CFUNC_DEF("set_dof_blur_far_distance", 1, &camera_attributes_practical_class_set_dof_blur_far_distance),
	JS_CFUNC_DEF("get_dof_blur_far_distance", 0, &camera_attributes_practical_class_get_dof_blur_far_distance),
	JS_CFUNC_DEF("set_dof_blur_far_transition", 1, &camera_attributes_practical_class_set_dof_blur_far_transition),
	JS_CFUNC_DEF("get_dof_blur_far_transition", 0, &camera_attributes_practical_class_get_dof_blur_far_transition),
	JS_CFUNC_DEF("set_dof_blur_near_enabled", 1, &camera_attributes_practical_class_set_dof_blur_near_enabled),
	JS_CFUNC_DEF("is_dof_blur_near_enabled", 0, &camera_attributes_practical_class_is_dof_blur_near_enabled),
	JS_CFUNC_DEF("set_dof_blur_near_distance", 1, &camera_attributes_practical_class_set_dof_blur_near_distance),
	JS_CFUNC_DEF("get_dof_blur_near_distance", 0, &camera_attributes_practical_class_get_dof_blur_near_distance),
	JS_CFUNC_DEF("set_dof_blur_near_transition", 1, &camera_attributes_practical_class_set_dof_blur_near_transition),
	JS_CFUNC_DEF("get_dof_blur_near_transition", 0, &camera_attributes_practical_class_get_dof_blur_near_transition),
	JS_CFUNC_DEF("set_dof_blur_amount", 1, &camera_attributes_practical_class_set_dof_blur_amount),
	JS_CFUNC_DEF("get_dof_blur_amount", 0, &camera_attributes_practical_class_get_dof_blur_amount),
	JS_CFUNC_DEF("set_auto_exposure_max_sensitivity", 1, &camera_attributes_practical_class_set_auto_exposure_max_sensitivity),
	JS_CFUNC_DEF("get_auto_exposure_max_sensitivity", 0, &camera_attributes_practical_class_get_auto_exposure_max_sensitivity),
	JS_CFUNC_DEF("set_auto_exposure_min_sensitivity", 1, &camera_attributes_practical_class_set_auto_exposure_min_sensitivity),
	JS_CFUNC_DEF("get_auto_exposure_min_sensitivity", 0, &camera_attributes_practical_class_get_auto_exposure_min_sensitivity),
};




static void define_camera_attributes_practical_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_far_enabled"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_is_dof_blur_far_enabled, "is_dof_blur_far_enabled", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_far_enabled, "set_dof_blur_far_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_far_distance"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_dof_blur_far_distance, "get_dof_blur_far_distance", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_far_distance, "set_dof_blur_far_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_far_transition"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_dof_blur_far_transition, "get_dof_blur_far_transition", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_far_transition, "set_dof_blur_far_transition", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_near_enabled"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_is_dof_blur_near_enabled, "is_dof_blur_near_enabled", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_near_enabled, "set_dof_blur_near_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_near_distance"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_dof_blur_near_distance, "get_dof_blur_near_distance", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_near_distance, "set_dof_blur_near_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_near_transition"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_dof_blur_near_transition, "get_dof_blur_near_transition", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_near_transition, "set_dof_blur_near_transition", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dof_blur_amount"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_dof_blur_amount, "get_dof_blur_amount", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_dof_blur_amount, "set_dof_blur_amount", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_exposure_min_sensitivity"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_auto_exposure_min_sensitivity, "get_auto_exposure_min_sensitivity", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_auto_exposure_min_sensitivity, "set_auto_exposure_min_sensitivity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_exposure_max_sensitivity"),
        JS_NewCFunction(ctx, camera_attributes_practical_class_get_auto_exposure_max_sensitivity, "get_auto_exposure_max_sensitivity", 0),
        JS_NewCFunction(ctx, camera_attributes_practical_class_set_auto_exposure_max_sensitivity, "set_auto_exposure_max_sensitivity", 1),
        JS_PROP_GETSET
    );
}

static void define_camera_attributes_practical_enum(JSContext *ctx, JSValue ctor) {
}

static int js_camera_attributes_practical_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CameraAttributesPractical"] = class_id;
	classes_by_id[class_id] = "CameraAttributesPractical";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &camera_attributes_practical_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CameraAttributes"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_camera_attributes_practical_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, camera_attributes_practical_class_proto_funcs, _countof(camera_attributes_practical_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, camera_attributes_practical_class_constructor, "CameraAttributesPractical", 0, JS_CFUNC_constructor, 0);
	define_camera_attributes_practical_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CameraAttributesPractical", ctor);
	ctor_list["CameraAttributesPractical"] = ctor;

	return 0;
}

JSModuleDef *_js_init_camera_attributes_practical_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/camera_attributes';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_camera_attributes_practical_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CameraAttributesPractical");
	return m;
}

JSModuleDef *js_init_camera_attributes_practical_module(JSContext *ctx) {
	return _js_init_camera_attributes_practical_module(ctx, "@godot/classes/camera_attributes_practical");
}

void __register_camera_attributes_practical() {
	js_init_camera_attributes_practical_module(js_context());
}

void register_camera_attributes_practical() {
	__register_camera_attributes_practical();
}