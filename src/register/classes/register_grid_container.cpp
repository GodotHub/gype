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
#include <godot_cpp/classes/grid_container.hpp>
using namespace godot;

static void grid_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GridContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef grid_container_class_def = {
    "GridContainer",
    grid_container_class_finalizer
};

static JSValue grid_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GridContainer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GridContainer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GridContainer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GridContainer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue grid_container_class_set_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GridContainer::set_columns, ctx, this_val, argc, argv);
};
static JSValue grid_container_class_get_columns(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GridContainer::get_columns, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry grid_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_columns", 1, &grid_container_class_set_columns),
	JS_CFUNC_DEF("get_columns", 0, &grid_container_class_get_columns),
};




static void define_grid_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "columns"),
        JS_NewCFunction(ctx, grid_container_class_get_columns, "get_columns", 0),
        JS_NewCFunction(ctx, grid_container_class_set_columns, "set_columns", 1),
        JS_PROP_GETSET
    );
}

static void define_grid_container_enum(JSContext *ctx, JSValue proto) {
}

static int js_grid_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GridContainer"] = class_id;
	classes_by_id[class_id] = "GridContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &grid_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_grid_container_property(ctx, proto);
	define_grid_container_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, grid_container_class_proto_funcs, _countof(grid_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, grid_container_class_constructor, "GridContainer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GridContainer", ctor);

	return 0;
}

JSModuleDef *_js_init_grid_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_grid_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GridContainer");
	return m;
}

JSModuleDef *js_init_grid_container_module(JSContext *ctx) {
	return _js_init_grid_container_module(ctx, "@godot/classes/grid_container");
}

void __register_grid_container() {
	js_init_grid_container_module(js_context());
}

void register_grid_container() {
	__register_grid_container();
}