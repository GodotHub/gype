#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/center_container.hpp>
using namespace godot;

static void center_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CenterContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef center_container_class_def = {
    "CenterContainer",
    center_container_class_finalizer
};

static JSValue center_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CenterContainer"];
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
        instance = memnew(CenterContainer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue center_container_class_set_use_top_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CenterContainer::set_use_top_left, ctx, this_val, argc, argv);
};
static JSValue center_container_class_is_using_top_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CenterContainer::is_using_top_left, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry center_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_use_top_left", 1, &center_container_class_set_use_top_left),
	JS_CFUNC_DEF("is_using_top_left", 0, &center_container_class_is_using_top_left),
};




static void define_center_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_top_left"),
        JS_NewCFunction(ctx, center_container_class_is_using_top_left, "is_using_top_left", 0),
        JS_NewCFunction(ctx, center_container_class_set_use_top_left, "set_use_top_left", 1),
        JS_PROP_GETSET
    );
}

static void define_center_container_enum(JSContext *ctx, JSValue ctor) {
}

static int js_center_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CenterContainer"] = class_id;
	classes_by_id[class_id] = "CenterContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &center_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_center_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, center_container_class_proto_funcs, _countof(center_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, center_container_class_constructor, "CenterContainer", 0, JS_CFUNC_constructor, 0);
	define_center_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CenterContainer", ctor);
	ctor_list["CenterContainer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_center_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_center_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CenterContainer");
	return m;
}

JSModuleDef *js_init_center_container_module(JSContext *ctx) {
	return _js_init_center_container_module(ctx, "@godot/classes/center_container");
}

void __register_center_container() {
	js_init_center_container_module(js_context());
}

void register_center_container() {
	__register_center_container();
}