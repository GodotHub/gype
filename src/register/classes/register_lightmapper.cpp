#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/lightmapper.hpp>
using namespace godot;

static void lightmapper_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Lightmapper"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef lightmapper_class_def = {
    "Lightmapper",
    lightmapper_class_finalizer
};

static JSValue lightmapper_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Lightmapper"];
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
        instance = memnew(Lightmapper);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_lightmapper_property(JSContext *ctx, JSValue proto) {
}

static void define_lightmapper_enum(JSContext *ctx, JSValue ctor) {
}

static int js_lightmapper_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Lightmapper"] = class_id;
	classes_by_id[class_id] = "Lightmapper";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &lightmapper_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_lightmapper_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, lightmapper_class_constructor, "Lightmapper", 0, JS_CFUNC_constructor, 0);
	define_lightmapper_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Lightmapper", ctor);
	ctor_list["Lightmapper"] = ctor;

	return 0;
}

JSModuleDef *_js_init_lightmapper_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_lightmapper_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Lightmapper");
	return m;
}

JSModuleDef *js_init_lightmapper_module(JSContext *ctx) {
	return _js_init_lightmapper_module(ctx, "@godot/classes/lightmapper");
}

void __register_lightmapper() {
	js_init_lightmapper_module(js_context());
}

void register_lightmapper() {
	__register_lightmapper();
}