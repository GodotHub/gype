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
#include <godot_cpp/classes/shader_include_db.hpp>
using namespace godot;

static void shader_include_db_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ShaderIncludeDB"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef shader_include_db_class_def = {
    "ShaderIncludeDB",
    shader_include_db_class_finalizer
};

static JSValue shader_include_db_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ShaderIncludeDB"];
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
        instance = memnew(ShaderIncludeDB);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}



static JSValue shader_include_db_class_list_built_in_include_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&ShaderIncludeDB::list_built_in_include_files, ctx, this_val, argc, argv);
};
static JSValue shader_include_db_class_has_built_in_include_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&ShaderIncludeDB::has_built_in_include_file, ctx, this_val, argc, argv);
};
static JSValue shader_include_db_class_get_built_in_include_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&ShaderIncludeDB::get_built_in_include_file, ctx, this_val, argc, argv);
};


static const JSCFunctionListEntry shader_include_db_class_static_funcs[] = {
	JS_CFUNC_DEF("list_built_in_include_files", 0, &shader_include_db_class_list_built_in_include_files),
	JS_CFUNC_DEF("has_built_in_include_file", 1, &shader_include_db_class_has_built_in_include_file),
	JS_CFUNC_DEF("get_built_in_include_file", 1, &shader_include_db_class_get_built_in_include_file),
};



static void define_shader_include_db_property(JSContext *ctx, JSValue proto) {
}

static void define_shader_include_db_enum(JSContext *ctx, JSValue ctor) {
}

static int js_shader_include_db_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ShaderIncludeDB"] = class_id;
	classes_by_id[class_id] = "ShaderIncludeDB";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &shader_include_db_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_shader_include_db_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, shader_include_db_class_constructor, "ShaderIncludeDB", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, shader_include_db_class_static_funcs, _countof(shader_include_db_class_static_funcs));
	define_shader_include_db_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ShaderIncludeDB", ctor);
	ctor_list["ShaderIncludeDB"] = ctor;

	return 0;
}

JSModuleDef *_js_init_shader_include_db_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_shader_include_db_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ShaderIncludeDB");
	return m;
}

JSModuleDef *js_init_shader_include_db_module(JSContext *ctx) {
	return _js_init_shader_include_db_module(ctx, "@godot/classes/shader_include_db");
}

void __register_shader_include_db() {
	js_init_shader_include_db_module(js_context());
}

void register_shader_include_db() {
	__register_shader_include_db();
}