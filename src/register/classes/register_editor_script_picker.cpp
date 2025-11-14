#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_resource_picker.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_script_picker.hpp>
using namespace godot;

static void editor_script_picker_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorScriptPicker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_script_picker_class_def = {
    "EditorScriptPicker",
    editor_script_picker_class_finalizer
};

static JSValue editor_script_picker_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorScriptPicker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorScriptPicker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorScriptPicker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorScriptPicker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_script_picker_class_set_script_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorScriptPicker::set_script_owner, ctx, this_val, argc, argv);
};
static JSValue editor_script_picker_class_get_script_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorScriptPicker::get_script_owner, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry editor_script_picker_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_script_owner", 1, &editor_script_picker_class_set_script_owner),
	JS_CFUNC_DEF("get_script_owner", 0, &editor_script_picker_class_get_script_owner),
};




static void define_editor_script_picker_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "script_owner"),
        JS_NewCFunction(ctx, editor_script_picker_class_get_script_owner, "get_script_owner", 0),
        JS_NewCFunction(ctx, editor_script_picker_class_set_script_owner, "set_script_owner", 1),
        JS_PROP_GETSET
    );
}

static void define_editor_script_picker_enum(JSContext *ctx, JSValue proto) {
}

static int js_editor_script_picker_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorScriptPicker"] = class_id;
	classes_by_id[class_id] = "EditorScriptPicker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_script_picker_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["EditorResourcePicker"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_script_picker_property(ctx, proto);
	define_editor_script_picker_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_script_picker_class_proto_funcs, _countof(editor_script_picker_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_script_picker_class_constructor, "EditorScriptPicker", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorScriptPicker", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_script_picker_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/editor_resource_picker';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_script_picker_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorScriptPicker");
	return m;
}

JSModuleDef *js_init_editor_script_picker_module(JSContext *ctx) {
	return _js_init_editor_script_picker_module(ctx, "@godot/classes/editor_script_picker");
}

void __register_editor_script_picker() {
	js_init_editor_script_picker_module(js_context());
}

void register_editor_script_picker() {
	__register_editor_script_picker();
}