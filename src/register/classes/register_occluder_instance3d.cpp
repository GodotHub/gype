#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/occluder3d.hpp>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/occluder_instance3d.hpp>
using namespace godot;

static void occluder_instance3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OccluderInstance3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef occluder_instance3d_class_def = {
    "OccluderInstance3D",
    occluder_instance3d_class_finalizer
};

static JSValue occluder_instance3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OccluderInstance3D"];
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
        instance = memnew(OccluderInstance3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue occluder_instance3d_class_set_bake_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderInstance3D::set_bake_mask, ctx, this_val, argc, argv);
};
static JSValue occluder_instance3d_class_get_bake_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OccluderInstance3D::get_bake_mask, ctx, this_val, argc, argv);
}
static JSValue occluder_instance3d_class_set_bake_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderInstance3D::set_bake_mask_value, ctx, this_val, argc, argv);
};
static JSValue occluder_instance3d_class_get_bake_mask_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OccluderInstance3D::get_bake_mask_value, ctx, this_val, argc, argv);
};
static JSValue occluder_instance3d_class_set_bake_simplification_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderInstance3D::set_bake_simplification_distance, ctx, this_val, argc, argv);
};
static JSValue occluder_instance3d_class_get_bake_simplification_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OccluderInstance3D::get_bake_simplification_distance, ctx, this_val, argc, argv);
}
static JSValue occluder_instance3d_class_set_occluder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderInstance3D::set_occluder, ctx, this_val, argc, argv);
};
static JSValue occluder_instance3d_class_get_occluder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OccluderInstance3D::get_occluder, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry occluder_instance3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_bake_mask", 1, &occluder_instance3d_class_set_bake_mask),
	JS_CFUNC_DEF("get_bake_mask", 0, &occluder_instance3d_class_get_bake_mask),
	JS_CFUNC_DEF("set_bake_mask_value", 2, &occluder_instance3d_class_set_bake_mask_value),
	JS_CFUNC_DEF("get_bake_mask_value", 1, &occluder_instance3d_class_get_bake_mask_value),
	JS_CFUNC_DEF("set_bake_simplification_distance", 1, &occluder_instance3d_class_set_bake_simplification_distance),
	JS_CFUNC_DEF("get_bake_simplification_distance", 0, &occluder_instance3d_class_get_bake_simplification_distance),
	JS_CFUNC_DEF("set_occluder", 1, &occluder_instance3d_class_set_occluder),
	JS_CFUNC_DEF("get_occluder", 0, &occluder_instance3d_class_get_occluder),
};




static void define_occluder_instance3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "occluder"),
        JS_NewCFunction(ctx, occluder_instance3d_class_get_occluder, "get_occluder", 0),
        JS_NewCFunction(ctx, occluder_instance3d_class_set_occluder, "set_occluder", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bake_mask"),
        JS_NewCFunction(ctx, occluder_instance3d_class_get_bake_mask, "get_bake_mask", 0),
        JS_NewCFunction(ctx, occluder_instance3d_class_set_bake_mask, "set_bake_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bake_simplification_distance"),
        JS_NewCFunction(ctx, occluder_instance3d_class_get_bake_simplification_distance, "get_bake_simplification_distance", 0),
        JS_NewCFunction(ctx, occluder_instance3d_class_set_bake_simplification_distance, "set_bake_simplification_distance", 1),
        JS_PROP_GETSET
    );
}

static void define_occluder_instance3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_occluder_instance3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OccluderInstance3D"] = class_id;
	classes_by_id[class_id] = "OccluderInstance3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &occluder_instance3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_occluder_instance3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, occluder_instance3d_class_proto_funcs, _countof(occluder_instance3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, occluder_instance3d_class_constructor, "OccluderInstance3D", 0, JS_CFUNC_constructor, 0);
	define_occluder_instance3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OccluderInstance3D", ctor);
	ctor_list["OccluderInstance3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_occluder_instance3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_occluder_instance3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OccluderInstance3D");
	return m;
}

JSModuleDef *js_init_occluder_instance3d_module(JSContext *ctx) {
	return _js_init_occluder_instance3d_module(ctx, "@godot/classes/occluder_instance3d");
}

void __register_occluder_instance3d() {
	js_init_occluder_instance3d_module(js_context());
}

void register_occluder_instance3d() {
	__register_occluder_instance3d();
}