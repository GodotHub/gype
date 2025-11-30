#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include "register/classes/class_editor_undo_redo_manager_vararg.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/undo_redo.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_undo_redo_manager.hpp>
using namespace godot;

static void editor_undo_redo_manager_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorUndoRedoManager"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_undo_redo_manager_class_def = {
    "EditorUndoRedoManager",
    editor_undo_redo_manager_class_finalizer
};

static JSValue editor_undo_redo_manager_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorUndoRedoManager"];
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
        instance = memnew(EditorUndoRedoManager);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_undo_redo_manager_class_create_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::create_action, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_commit_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::commit_action, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_is_committing_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorUndoRedoManager::is_committing_action, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_force_fixed_history(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::force_fixed_history, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_add_do_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::add_do_property, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_add_undo_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::add_undo_property, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_add_do_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::add_do_reference, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_add_undo_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::add_undo_reference, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_get_object_history_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorUndoRedoManager::get_object_history_id, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_get_history_undo_redo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorUndoRedoManager::get_history_undo_redo, ctx, this_val, argc, argv);
};
static JSValue editor_undo_redo_manager_class_clear_history(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorUndoRedoManager::clear_history, ctx, this_val, argc, argv);
};


static JSValue editor_undo_redo_manager_class_add_do_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_free_owner_vararg_method_no_ret(&js_add_do_method, ctx, this_val, argc, argv);
}
static JSValue editor_undo_redo_manager_class_add_undo_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_free_owner_vararg_method_no_ret(&js_add_undo_method, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry editor_undo_redo_manager_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_action", 5, &editor_undo_redo_manager_class_create_action),
	JS_CFUNC_DEF("commit_action", 1, &editor_undo_redo_manager_class_commit_action),
	JS_CFUNC_DEF("is_committing_action", 0, &editor_undo_redo_manager_class_is_committing_action),
	JS_CFUNC_DEF("force_fixed_history", 0, &editor_undo_redo_manager_class_force_fixed_history),
	JS_CFUNC_DEF("add_do_property", 3, &editor_undo_redo_manager_class_add_do_property),
	JS_CFUNC_DEF("add_undo_property", 3, &editor_undo_redo_manager_class_add_undo_property),
	JS_CFUNC_DEF("add_do_reference", 1, &editor_undo_redo_manager_class_add_do_reference),
	JS_CFUNC_DEF("add_undo_reference", 1, &editor_undo_redo_manager_class_add_undo_reference),
	JS_CFUNC_DEF("get_object_history_id", 1, &editor_undo_redo_manager_class_get_object_history_id),
	JS_CFUNC_DEF("get_history_undo_redo", 1, &editor_undo_redo_manager_class_get_history_undo_redo),
	JS_CFUNC_DEF("clear_history", 2, &editor_undo_redo_manager_class_clear_history),
	JS_CFUNC_DEF("add_do_method", 2, &editor_undo_redo_manager_class_add_do_method),
	JS_CFUNC_DEF("add_undo_method", 2, &editor_undo_redo_manager_class_add_undo_method),
};


static JSValue editor_undo_redo_manager_class_get_history_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "history_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue editor_undo_redo_manager_class_get_version_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "version_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_editor_undo_redo_manager_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "history_changed"),
		JS_NewCFunction(ctx, editor_undo_redo_manager_class_get_history_changed_signal, "get_history_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "version_changed"),
		JS_NewCFunction(ctx, editor_undo_redo_manager_class_get_version_changed_signal, "get_version_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_undo_redo_manager_enum(JSContext *ctx, JSValue ctor) {
	JSValue SpecialHistory_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SpecialHistory_obj, "GLOBAL_HISTORY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SpecialHistory_obj, "REMOTE_HISTORY", JS_NewInt64(ctx, -9));
	JS_SetPropertyStr(ctx, SpecialHistory_obj, "INVALID_HISTORY", JS_NewInt64(ctx, -99));
	JS_SetPropertyStr(ctx, ctor, "SpecialHistory", SpecialHistory_obj);
}

static int js_editor_undo_redo_manager_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorUndoRedoManager"] = class_id;
	classes_by_id[class_id] = "EditorUndoRedoManager";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_undo_redo_manager_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_undo_redo_manager_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_undo_redo_manager_class_proto_funcs, _countof(editor_undo_redo_manager_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_undo_redo_manager_class_constructor, "EditorUndoRedoManager", 0, JS_CFUNC_constructor, 0);
	define_editor_undo_redo_manager_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorUndoRedoManager", ctor);
	ctor_list["EditorUndoRedoManager"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_undo_redo_manager_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_undo_redo_manager_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorUndoRedoManager");
	return m;
}

JSModuleDef *js_init_editor_undo_redo_manager_module(JSContext *ctx) {
	return _js_init_editor_undo_redo_manager_module(ctx, "@godot/classes/editor_undo_redo_manager");
}

void __register_editor_undo_redo_manager() {
	js_init_editor_undo_redo_manager_module(js_context());
}

void register_editor_undo_redo_manager() {
	__register_editor_undo_redo_manager();
}