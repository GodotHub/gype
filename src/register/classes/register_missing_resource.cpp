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
#include <godot_cpp/classes/missing_resource.hpp>
using namespace godot;

static void missing_resource_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MissingResource"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef missing_resource_class_def = {
    "MissingResource",
    missing_resource_class_finalizer
};

static JSValue missing_resource_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MissingResource"];
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
        instance = memnew(MissingResource);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue missing_resource_class_set_original_class(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MissingResource::set_original_class, ctx, this_val, argc, argv);
};
static JSValue missing_resource_class_get_original_class(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MissingResource::get_original_class, ctx, this_val, argc, argv);
}
static JSValue missing_resource_class_set_recording_properties(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MissingResource::set_recording_properties, ctx, this_val, argc, argv);
};
static JSValue missing_resource_class_is_recording_properties(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MissingResource::is_recording_properties, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry missing_resource_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_original_class", 1, &missing_resource_class_set_original_class),
	JS_CFUNC_DEF("get_original_class", 0, &missing_resource_class_get_original_class),
	JS_CFUNC_DEF("set_recording_properties", 1, &missing_resource_class_set_recording_properties),
	JS_CFUNC_DEF("is_recording_properties", 0, &missing_resource_class_is_recording_properties),
};




static void define_missing_resource_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "original_class"),
        JS_NewCFunction(ctx, missing_resource_class_get_original_class, "get_original_class", 0),
        JS_NewCFunction(ctx, missing_resource_class_set_original_class, "set_original_class", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "recording_properties"),
        JS_NewCFunction(ctx, missing_resource_class_is_recording_properties, "is_recording_properties", 0),
        JS_NewCFunction(ctx, missing_resource_class_set_recording_properties, "set_recording_properties", 1),
        JS_PROP_GETSET
    );
}

static void define_missing_resource_enum(JSContext *ctx, JSValue ctor) {
}

static int js_missing_resource_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MissingResource"] = class_id;
	classes_by_id[class_id] = "MissingResource";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &missing_resource_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_missing_resource_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, missing_resource_class_proto_funcs, _countof(missing_resource_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, missing_resource_class_constructor, "MissingResource", 0, JS_CFUNC_constructor, 0);
	define_missing_resource_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MissingResource", ctor);
	ctor_list["MissingResource"] = ctor;

	return 0;
}

JSModuleDef *_js_init_missing_resource_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_missing_resource_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MissingResource");
	return m;
}

JSModuleDef *js_init_missing_resource_module(JSContext *ctx) {
	return _js_init_missing_resource_module(ctx, "@godot/classes/missing_resource");
}

void __register_missing_resource() {
	js_init_missing_resource_module(js_context());
}

void register_missing_resource() {
	__register_missing_resource();
}