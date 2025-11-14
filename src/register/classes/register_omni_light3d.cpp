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
#include <godot_cpp/classes/omni_light3d.hpp>
using namespace godot;

static void omni_light3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OmniLight3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef omni_light3d_class_def = {
    "OmniLight3D",
    omni_light3d_class_finalizer
};

static JSValue omni_light3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OmniLight3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OmniLight3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OmniLight3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OmniLight3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue omni_light3d_class_set_shadow_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OmniLight3D::set_shadow_mode, ctx, this_val, argc, argv);
};
static JSValue omni_light3d_class_get_shadow_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OmniLight3D::get_shadow_mode, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry omni_light3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_shadow_mode", 1, &omni_light3d_class_set_shadow_mode),
	JS_CFUNC_DEF("get_shadow_mode", 0, &omni_light3d_class_get_shadow_mode),
};




static void define_omni_light3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "omni_shadow_mode"),
        JS_NewCFunction(ctx, omni_light3d_class_get_shadow_mode, "get_shadow_mode", 0),
        JS_NewCFunction(ctx, omni_light3d_class_set_shadow_mode, "set_shadow_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_omni_light3d_enum(JSContext *ctx, JSValue proto) {
	JSValue ShadowMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShadowMode_obj, "SHADOW_DUAL_PARABOLOID", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShadowMode_obj, "SHADOW_CUBE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "ShadowMode", ShadowMode_obj);
}

static int js_omni_light3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OmniLight3D"] = class_id;
	classes_by_id[class_id] = "OmniLight3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &omni_light3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Light3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_omni_light3d_property(ctx, proto);
	define_omni_light3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, omni_light3d_class_proto_funcs, _countof(omni_light3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, omni_light3d_class_constructor, "OmniLight3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OmniLight3D", ctor);

	return 0;
}

JSModuleDef *_js_init_omni_light3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/light3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_omni_light3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OmniLight3D");
	return m;
}

JSModuleDef *js_init_omni_light3d_module(JSContext *ctx) {
	return _js_init_omni_light3d_module(ctx, "@godot/classes/omni_light3d");
}

void __register_omni_light3d() {
	js_init_omni_light3d_module(js_context());
}

void register_omni_light3d() {
	__register_omni_light3d();
}