#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/grid_map.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/grid_map_editor_plugin.hpp>
using namespace godot;

static void grid_map_editor_plugin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GridMapEditorPlugin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef grid_map_editor_plugin_class_def = {
    "GridMapEditorPlugin",
    grid_map_editor_plugin_class_finalizer
};

static JSValue grid_map_editor_plugin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GridMapEditorPlugin"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GridMapEditorPlugin *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GridMapEditorPlugin *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GridMapEditorPlugin);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue grid_map_editor_plugin_class_get_current_grid_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GridMapEditorPlugin::get_current_grid_map, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_set_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GridMapEditorPlugin::set_selection, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_clear_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GridMapEditorPlugin::clear_selection, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_get_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GridMapEditorPlugin::get_selection, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_has_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GridMapEditorPlugin::has_selection, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_get_selected_cells(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GridMapEditorPlugin::get_selected_cells, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_set_selected_palette_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_const_method_no_ret(&GridMapEditorPlugin::set_selected_palette_item, ctx, this_val, argc, argv);
};
static JSValue grid_map_editor_plugin_class_get_selected_palette_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GridMapEditorPlugin::get_selected_palette_item, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry grid_map_editor_plugin_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_current_grid_map", 0, &grid_map_editor_plugin_class_get_current_grid_map),
	JS_CFUNC_DEF("set_selection", 2, &grid_map_editor_plugin_class_set_selection),
	JS_CFUNC_DEF("clear_selection", 0, &grid_map_editor_plugin_class_clear_selection),
	JS_CFUNC_DEF("get_selection", 0, &grid_map_editor_plugin_class_get_selection),
	JS_CFUNC_DEF("has_selection", 0, &grid_map_editor_plugin_class_has_selection),
	JS_CFUNC_DEF("get_selected_cells", 0, &grid_map_editor_plugin_class_get_selected_cells),
	JS_CFUNC_DEF("set_selected_palette_item", 1, &grid_map_editor_plugin_class_set_selected_palette_item),
	JS_CFUNC_DEF("get_selected_palette_item", 0, &grid_map_editor_plugin_class_get_selected_palette_item),
};




static void define_grid_map_editor_plugin_property(JSContext *ctx, JSValue proto) {
}

static void define_grid_map_editor_plugin_enum(JSContext *ctx, JSValue ctor) {
}

static int js_grid_map_editor_plugin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GridMapEditorPlugin"] = class_id;
	classes_by_id[class_id] = "GridMapEditorPlugin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &grid_map_editor_plugin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["EditorPlugin"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_grid_map_editor_plugin_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, grid_map_editor_plugin_class_proto_funcs, _countof(grid_map_editor_plugin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, grid_map_editor_plugin_class_constructor, "GridMapEditorPlugin", 0, JS_CFUNC_constructor, 0);
	define_grid_map_editor_plugin_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GridMapEditorPlugin", ctor);

	return 0;
}

JSModuleDef *_js_init_grid_map_editor_plugin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/editor_plugin';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_grid_map_editor_plugin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GridMapEditorPlugin");
	return m;
}

JSModuleDef *js_init_grid_map_editor_plugin_module(JSContext *ctx) {
	return _js_init_grid_map_editor_plugin_module(ctx, "@godot/classes/grid_map_editor_plugin");
}

void __register_grid_map_editor_plugin() {
	js_init_grid_map_editor_plugin_module(js_context());
}

void register_grid_map_editor_plugin() {
	__register_grid_map_editor_plugin();
}