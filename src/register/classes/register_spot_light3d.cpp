#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/light3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/spot_light3d.hpp>
using namespace godot;

static void spot_light3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpotLight3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spot_light3d_class_def = {
    "SpotLight3D",
    spot_light3d_class_finalizer
};

static JSValue spot_light3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpotLight3D"];
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
        instance = memnew(SpotLight3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}


static JSValue spot_light3d_class_get_spot_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&SpotLight3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue spot_light3d_class_set_spot_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&SpotLight3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue spot_light3d_class_get_spot_attenuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&SpotLight3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue spot_light3d_class_set_spot_attenuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&SpotLight3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue spot_light3d_class_get_spot_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&SpotLight3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue spot_light3d_class_set_spot_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&SpotLight3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue spot_light3d_class_get_spot_angle_attenuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&SpotLight3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue spot_light3d_class_set_spot_angle_attenuation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&SpotLight3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}






static void define_spot_light3d_property(JSContext *ctx, JSValue proto) {
}

static void define_spot_light3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_spot_light3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpotLight3D"] = class_id;
	classes_by_id[class_id] = "SpotLight3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spot_light3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Light3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spot_light3d_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, spot_light3d_class_constructor, "SpotLight3D", 0, JS_CFUNC_constructor, 0);
	define_spot_light3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpotLight3D", ctor);
	ctor_list["SpotLight3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_spot_light3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/light3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spot_light3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpotLight3D");
	return m;
}

JSModuleDef *js_init_spot_light3d_module(JSContext *ctx) {
	return _js_init_spot_light3d_module(ctx, "@godot/classes/spot_light3d");
}

void __register_spot_light3d() {
	js_init_spot_light3d_module(js_context());
}

void register_spot_light3d() {
	__register_spot_light3d();
}