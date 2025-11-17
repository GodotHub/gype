#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_toaster.hpp>
using namespace godot;

static void editor_toaster_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorToaster"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_toaster_class_def = {
    "EditorToaster",
    editor_toaster_class_finalizer
};

static JSValue editor_toaster_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorToaster"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorToaster *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorToaster *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorToaster);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_toaster_class_push_toast(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorToaster::push_toast, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_toaster_class_proto_funcs[] = {
	JS_CFUNC_DEF("push_toast", 3, &editor_toaster_class_push_toast),
};




static void define_editor_toaster_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_toaster_enum(JSContext *ctx, JSValue ctor) {
	JSValue Severity_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Severity_obj, "SEVERITY_INFO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Severity_obj, "SEVERITY_WARNING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Severity_obj, "SEVERITY_ERROR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Severity", Severity_obj);
}

static int js_editor_toaster_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorToaster"] = class_id;
	classes_by_id[class_id] = "EditorToaster";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_toaster_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["HBoxContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_toaster_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_toaster_class_proto_funcs, _countof(editor_toaster_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_toaster_class_constructor, "EditorToaster", 0, JS_CFUNC_constructor, 0);
	define_editor_toaster_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorToaster", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_toaster_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/h_box_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_toaster_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorToaster");
	return m;
}

JSModuleDef *js_init_editor_toaster_module(JSContext *ctx) {
	return _js_init_editor_toaster_module(ctx, "@godot/classes/editor_toaster");
}

void __register_editor_toaster() {
	js_init_editor_toaster_module(js_context());
}

void register_editor_toaster() {
	__register_editor_toaster();
}