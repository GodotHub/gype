#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/navigation_mesh.hpp>
#include <godot_cpp/classes/navigation_mesh_source_geometry_data3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/navigation_mesh_generator.hpp>


using namespace godot;

static void navigation_mesh_generator_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef navigation_mesh_generator_class_def = {
	"_NavigationMeshGenerator",
	navigation_mesh_generator_class_finalizer
};

static JSValue navigation_mesh_generator_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_NavigationMeshGenerator"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	NavigationMeshGenerator *navigation_mesh_generator_class = NavigationMeshGenerator::get_singleton();
	if (!navigation_mesh_generator_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(navigation_mesh_generator_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue navigation_mesh_generator_class_bake(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&NavigationMeshGenerator::bake, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue navigation_mesh_generator_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&NavigationMeshGenerator::clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue navigation_mesh_generator_class_parse_source_geometry_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&NavigationMeshGenerator::parse_source_geometry_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue navigation_mesh_generator_class_bake_from_source_geometry_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&NavigationMeshGenerator::bake_from_source_geometry_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry navigation_mesh_generator_class_proto_funcs[] = {
	JS_CFUNC_DEF("bake", 2, &navigation_mesh_generator_class_bake),
	JS_CFUNC_DEF("clear", 1, &navigation_mesh_generator_class_clear),
	JS_CFUNC_DEF("parse_source_geometry_data", 4, &navigation_mesh_generator_class_parse_source_geometry_data),
	JS_CFUNC_DEF("bake_from_source_geometry_data", 3, &navigation_mesh_generator_class_bake_from_source_geometry_data),
};




static int js_navigation_mesh_generator_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_NavigationMeshGenerator"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_mesh_generator_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, navigation_mesh_generator_class_proto_funcs, _countof(navigation_mesh_generator_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, navigation_mesh_generator_class_constructor, "_NavigationMeshGenerator", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "NavigationMeshGenerator", singleton);

	return 0;
}

JSModuleDef *_js_init_navigation_mesh_generator_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_mesh_generator_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationMeshGenerator");
	return m;
}

void register_navigation_mesh_generator() {
	_js_init_navigation_mesh_generator_module(js_context(), "@godot/classes/navigation_mesh_generator");
}