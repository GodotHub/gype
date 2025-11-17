#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/bone2d.hpp>
using namespace godot;

static void bone2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Bone2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef bone2d_class_def = {
    "Bone2D",
    bone2d_class_finalizer
};

static JSValue bone2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Bone2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Bone2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Bone2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Bone2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue bone2d_class_set_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Bone2D::set_rest, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_get_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform2D> *proxy = memnew(ObjectProxy<Transform2D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform2D {
		Bone2D *obj = static_cast<Bone2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_rest();
	};
	proxy->setter = [this_val](const Transform2D &value) -> void {
		Bone2D *js_proxy = static_cast<Bone2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_rest(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform2DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform2DProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue bone2d_class_apply_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Bone2D::apply_rest, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_get_skeleton_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Bone2D::get_skeleton_rest, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_get_index_in_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Bone2D::get_index_in_skeleton, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_set_autocalculate_length_and_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Bone2D::set_autocalculate_length_and_angle, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_get_autocalculate_length_and_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Bone2D::get_autocalculate_length_and_angle, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_set_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Bone2D::set_length, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Bone2D::get_length, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_set_bone_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Bone2D::set_bone_angle, ctx, this_val, argc, argv);
};
static JSValue bone2d_class_get_bone_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Bone2D::get_bone_angle, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry bone2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_rest", 1, &bone2d_class_set_rest),
	JS_CFUNC_DEF("get_rest", 0, &bone2d_class_get_rest),
	JS_CFUNC_DEF("apply_rest", 0, &bone2d_class_apply_rest),
	JS_CFUNC_DEF("get_skeleton_rest", 0, &bone2d_class_get_skeleton_rest),
	JS_CFUNC_DEF("get_index_in_skeleton", 0, &bone2d_class_get_index_in_skeleton),
	JS_CFUNC_DEF("set_autocalculate_length_and_angle", 1, &bone2d_class_set_autocalculate_length_and_angle),
	JS_CFUNC_DEF("get_autocalculate_length_and_angle", 0, &bone2d_class_get_autocalculate_length_and_angle),
	JS_CFUNC_DEF("set_length", 1, &bone2d_class_set_length),
	JS_CFUNC_DEF("get_length", 0, &bone2d_class_get_length),
	JS_CFUNC_DEF("set_bone_angle", 1, &bone2d_class_set_bone_angle),
	JS_CFUNC_DEF("get_bone_angle", 0, &bone2d_class_get_bone_angle),
};




static void define_bone2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rest"),
        JS_NewCFunction(ctx, bone2d_class_get_rest, "get_rest", 0),
        JS_NewCFunction(ctx, bone2d_class_set_rest, "set_rest", 1),
        JS_PROP_GETSET
    );
}

static void define_bone2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_bone2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Bone2D"] = class_id;
	classes_by_id[class_id] = "Bone2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &bone2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_bone2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, bone2d_class_proto_funcs, _countof(bone2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, bone2d_class_constructor, "Bone2D", 0, JS_CFUNC_constructor, 0);
	define_bone2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Bone2D", ctor);

	return 0;
}

JSModuleDef *_js_init_bone2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_bone2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Bone2D");
	return m;
}

JSModuleDef *js_init_bone2d_module(JSContext *ctx) {
	return _js_init_bone2d_module(ctx, "@godot/classes/bone2d");
}

void __register_bone2d() {
	js_init_bone2d_module(js_context());
}

void register_bone2d() {
	__register_bone2d();
}