#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_resource_preview_generator.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_resource_preview.hpp>
using namespace godot;

static void editor_resource_preview_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorResourcePreview"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_resource_preview_class_def = {
    "EditorResourcePreview",
    editor_resource_preview_class_finalizer
};

static JSValue editor_resource_preview_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorResourcePreview"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorResourcePreview *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorResourcePreview *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorResourcePreview);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_resource_preview_class_queue_resource_preview(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePreview::queue_resource_preview, ctx, this_val, argc, argv);
};
static JSValue editor_resource_preview_class_queue_edited_resource_preview(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePreview::queue_edited_resource_preview, ctx, this_val, argc, argv);
};
static JSValue editor_resource_preview_class_add_preview_generator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePreview::add_preview_generator, ctx, this_val, argc, argv);
};
static JSValue editor_resource_preview_class_remove_preview_generator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePreview::remove_preview_generator, ctx, this_val, argc, argv);
};
static JSValue editor_resource_preview_class_check_for_invalidation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorResourcePreview::check_for_invalidation, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_resource_preview_class_proto_funcs[] = {
	JS_CFUNC_DEF("queue_resource_preview", 4, &editor_resource_preview_class_queue_resource_preview),
	JS_CFUNC_DEF("queue_edited_resource_preview", 4, &editor_resource_preview_class_queue_edited_resource_preview),
	JS_CFUNC_DEF("add_preview_generator", 1, &editor_resource_preview_class_add_preview_generator),
	JS_CFUNC_DEF("remove_preview_generator", 1, &editor_resource_preview_class_remove_preview_generator),
	JS_CFUNC_DEF("check_for_invalidation", 1, &editor_resource_preview_class_check_for_invalidation),
};


static JSValue editor_resource_preview_class_get_preview_invalidated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorResourcePreview *opaque = static_cast<EditorResourcePreview *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "preview_invalidated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "preview_invalidated"));
		JS_DefinePropertyValueStr(ctx, this_val, "preview_invalidated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_resource_preview_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "preview_invalidated"),
		JS_NewCFunction(ctx, editor_resource_preview_class_get_preview_invalidated_signal, "get_preview_invalidated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_resource_preview_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_resource_preview_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorResourcePreview"] = class_id;
	classes_by_id[class_id] = "EditorResourcePreview";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_resource_preview_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_resource_preview_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_resource_preview_class_proto_funcs, _countof(editor_resource_preview_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_resource_preview_class_constructor, "EditorResourcePreview", 0, JS_CFUNC_constructor, 0);
	define_editor_resource_preview_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorResourcePreview", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_resource_preview_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_resource_preview_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorResourcePreview");
	return m;
}

JSModuleDef *js_init_editor_resource_preview_module(JSContext *ctx) {
	return _js_init_editor_resource_preview_module(ctx, "@godot/classes/editor_resource_preview");
}

void __register_editor_resource_preview() {
	js_init_editor_resource_preview_module(js_context());
}

void register_editor_resource_preview() {
	__register_editor_resource_preview();
}