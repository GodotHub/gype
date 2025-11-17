#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/light2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/directional_light2d.hpp>
using namespace godot;

static void directional_light2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["DirectionalLight2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef directional_light2d_class_def = {
    "DirectionalLight2D",
    directional_light2d_class_finalizer
};

static JSValue directional_light2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["DirectionalLight2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    DirectionalLight2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<DirectionalLight2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(DirectionalLight2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue directional_light2d_class_set_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DirectionalLight2D::set_max_distance, ctx, this_val, argc, argv);
};
static JSValue directional_light2d_class_get_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DirectionalLight2D::get_max_distance, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry directional_light2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_max_distance", 1, &directional_light2d_class_set_max_distance),
	JS_CFUNC_DEF("get_max_distance", 0, &directional_light2d_class_get_max_distance),
};




static void define_directional_light2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_distance"),
        JS_NewCFunction(ctx, directional_light2d_class_get_max_distance, "get_max_distance", 0),
        JS_NewCFunction(ctx, directional_light2d_class_set_max_distance, "set_max_distance", 1),
        JS_PROP_GETSET
    );
}

static void define_directional_light2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_directional_light2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["DirectionalLight2D"] = class_id;
	classes_by_id[class_id] = "DirectionalLight2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &directional_light2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Light2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_directional_light2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, directional_light2d_class_proto_funcs, _countof(directional_light2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, directional_light2d_class_constructor, "DirectionalLight2D", 0, JS_CFUNC_constructor, 0);
	define_directional_light2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "DirectionalLight2D", ctor);

	return 0;
}

JSModuleDef *_js_init_directional_light2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/light2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_directional_light2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "DirectionalLight2D");
	return m;
}

JSModuleDef *js_init_directional_light2d_module(JSContext *ctx) {
	return _js_init_directional_light2d_module(ctx, "@godot/classes/directional_light2d");
}

void __register_directional_light2d() {
	js_init_directional_light2d_module(js_context());
}

void register_directional_light2d() {
	__register_directional_light2d();
}