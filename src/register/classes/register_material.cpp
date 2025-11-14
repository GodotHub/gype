#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/material.hpp>
using namespace godot;

static void material_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Material"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef material_class_def = {
    "Material",
    material_class_finalizer
};

static JSValue material_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Material"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Material *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Material *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Material);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue material_class_set_next_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Material::set_next_pass, ctx, this_val, argc, argv);
};
static JSValue material_class_get_next_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Material::get_next_pass, ctx, this_val, argc, argv);
}
static JSValue material_class_set_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Material::set_render_priority, ctx, this_val, argc, argv);
};
static JSValue material_class_get_render_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Material::get_render_priority, ctx, this_val, argc, argv);
}
static JSValue material_class_inspect_native_shader_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Material::inspect_native_shader_code, ctx, this_val, argc, argv);
};
static JSValue material_class_create_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Material::create_placeholder, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry material_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_next_pass", 1, &material_class_set_next_pass),
	JS_CFUNC_DEF("get_next_pass", 0, &material_class_get_next_pass),
	JS_CFUNC_DEF("set_render_priority", 1, &material_class_set_render_priority),
	JS_CFUNC_DEF("get_render_priority", 0, &material_class_get_render_priority),
	JS_CFUNC_DEF("inspect_native_shader_code", 0, &material_class_inspect_native_shader_code),
	JS_CFUNC_DEF("create_placeholder", 0, &material_class_create_placeholder),
};




static void define_material_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_priority"),
        JS_NewCFunction(ctx, material_class_get_render_priority, "get_render_priority", 0),
        JS_NewCFunction(ctx, material_class_set_render_priority, "set_render_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "next_pass"),
        JS_NewCFunction(ctx, material_class_get_next_pass, "get_next_pass", 0),
        JS_NewCFunction(ctx, material_class_set_next_pass, "set_next_pass", 1),
        JS_PROP_GETSET
    );
}

static void define_material_enum(JSContext *ctx, JSValue proto) {
}

static int js_material_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Material"] = class_id;
	classes_by_id[class_id] = "Material";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &material_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_material_property(ctx, proto);
	define_material_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, material_class_proto_funcs, _countof(material_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, material_class_constructor, "Material", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Material", ctor);

	return 0;
}

JSModuleDef *_js_init_material_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_material_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Material");
	return m;
}

JSModuleDef *js_init_material_module(JSContext *ctx) {
	return _js_init_material_module(ctx, "@godot/classes/material");
}

void __register_material() {
	js_init_material_module(js_context());
}

void register_material() {
	__register_material();
}