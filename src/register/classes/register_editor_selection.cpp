#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_selection.hpp>
using namespace godot;

static void editor_selection_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorSelection"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_selection_class_def = {
    "EditorSelection",
    editor_selection_class_finalizer
};

static JSValue editor_selection_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorSelection"];
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
        instance = memnew(EditorSelection);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_selection_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSelection::clear, ctx, this_val, argc, argv);
};
static JSValue editor_selection_class_add_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSelection::add_node, ctx, this_val, argc, argv);
};
static JSValue editor_selection_class_remove_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSelection::remove_node, ctx, this_val, argc, argv);
};
static JSValue editor_selection_class_get_selected_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorSelection::get_selected_nodes, ctx, this_val, argc, argv);
};
static JSValue editor_selection_class_get_top_selected_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorSelection::get_top_selected_nodes, ctx, this_val, argc, argv);
};
static JSValue editor_selection_class_get_transformable_selected_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorSelection::get_transformable_selected_nodes, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_selection_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear", 0, &editor_selection_class_clear),
	JS_CFUNC_DEF("add_node", 1, &editor_selection_class_add_node),
	JS_CFUNC_DEF("remove_node", 1, &editor_selection_class_remove_node),
	JS_CFUNC_DEF("get_selected_nodes", 0, &editor_selection_class_get_selected_nodes),
	JS_CFUNC_DEF("get_top_selected_nodes", 0, &editor_selection_class_get_top_selected_nodes),
	JS_CFUNC_DEF("get_transformable_selected_nodes", 0, &editor_selection_class_get_transformable_selected_nodes),
};


static JSValue editor_selection_class_get_selection_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "selection_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_editor_selection_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "selection_changed"),
		JS_NewCFunction(ctx, editor_selection_class_get_selection_changed_signal, "get_selection_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_selection_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_selection_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorSelection"] = class_id;
	classes_by_id[class_id] = "EditorSelection";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_selection_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_selection_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_selection_class_proto_funcs, _countof(editor_selection_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_selection_class_constructor, "EditorSelection", 0, JS_CFUNC_constructor, 0);
	define_editor_selection_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorSelection", ctor);
	ctor_list["EditorSelection"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_selection_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_selection_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorSelection");
	return m;
}

JSModuleDef *js_init_editor_selection_module(JSContext *ctx) {
	return _js_init_editor_selection_module(ctx, "@godot/classes/editor_selection");
}

void __register_editor_selection() {
	js_init_editor_selection_module(js_context());
}

void register_editor_selection() {
	__register_editor_selection();
}