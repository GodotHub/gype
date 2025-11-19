#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_vcs_interface.hpp>
using namespace godot;

static void editor_vcs_interface_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorVCSInterface"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_vcs_interface_class_def = {
    "EditorVCSInterface",
    editor_vcs_interface_class_finalizer
};

static JSValue editor_vcs_interface_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorVCSInterface"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorVCSInterface *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorVCSInterface *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorVCSInterface);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_vcs_interface_class_create_diff_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::create_diff_line, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_create_diff_hunk(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::create_diff_hunk, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_create_diff_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::create_diff_file, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_create_commit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::create_commit, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_create_status_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::create_status_file, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_add_diff_hunks_into_diff_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::add_diff_hunks_into_diff_file, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_add_line_diffs_into_diff_hunk(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorVCSInterface::add_line_diffs_into_diff_hunk, ctx, this_val, argc, argv);
};
static JSValue editor_vcs_interface_class_popup_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorVCSInterface::popup_error, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_vcs_interface_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_diff_line", 4, &editor_vcs_interface_class_create_diff_line),
	JS_CFUNC_DEF("create_diff_hunk", 4, &editor_vcs_interface_class_create_diff_hunk),
	JS_CFUNC_DEF("create_diff_file", 2, &editor_vcs_interface_class_create_diff_file),
	JS_CFUNC_DEF("create_commit", 5, &editor_vcs_interface_class_create_commit),
	JS_CFUNC_DEF("create_status_file", 3, &editor_vcs_interface_class_create_status_file),
	JS_CFUNC_DEF("add_diff_hunks_into_diff_file", 2, &editor_vcs_interface_class_add_diff_hunks_into_diff_file),
	JS_CFUNC_DEF("add_line_diffs_into_diff_hunk", 2, &editor_vcs_interface_class_add_line_diffs_into_diff_hunk),
	JS_CFUNC_DEF("popup_error", 1, &editor_vcs_interface_class_popup_error),
};




static void define_editor_vcs_interface_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_vcs_interface_enum(JSContext *ctx, JSValue ctor) {
	JSValue ChangeType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ChangeType_obj, "CHANGE_TYPE_NEW", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ChangeType_obj, "CHANGE_TYPE_MODIFIED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ChangeType_obj, "CHANGE_TYPE_RENAMED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ChangeType_obj, "CHANGE_TYPE_DELETED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ChangeType_obj, "CHANGE_TYPE_TYPECHANGE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ChangeType_obj, "CHANGE_TYPE_UNMERGED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "ChangeType", ChangeType_obj);
	JSValue TreeArea_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TreeArea_obj, "TREE_AREA_COMMIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TreeArea_obj, "TREE_AREA_STAGED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TreeArea_obj, "TREE_AREA_UNSTAGED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TreeArea", TreeArea_obj);
}

static int js_editor_vcs_interface_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorVCSInterface"] = class_id;
	classes_by_id[class_id] = "EditorVCSInterface";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_vcs_interface_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_vcs_interface_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_vcs_interface_class_proto_funcs, _countof(editor_vcs_interface_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_vcs_interface_class_constructor, "EditorVCSInterface", 0, JS_CFUNC_constructor, 0);
	define_editor_vcs_interface_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorVCSInterface", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_vcs_interface_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_vcs_interface_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorVCSInterface");
	return m;
}

JSModuleDef *js_init_editor_vcs_interface_module(JSContext *ctx) {
	return _js_init_editor_vcs_interface_module(ctx, "@godot/classes/editor_vcs_interface");
}

void __register_editor_vcs_interface() {
	js_init_editor_vcs_interface_module(js_context());
}

void register_editor_vcs_interface() {
	__register_editor_vcs_interface();
}