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
#include <godot_cpp/classes/shader_include.hpp>
using namespace godot;

static void shader_include_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ShaderInclude"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef shader_include_class_def = {
    "ShaderInclude",
    shader_include_class_finalizer
};

static JSValue shader_include_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ShaderInclude"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ShaderInclude *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ShaderInclude *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ShaderInclude);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue shader_include_class_set_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ShaderInclude::set_code, ctx, this_val, argc, argv);
};
static JSValue shader_include_class_get_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		ShaderInclude *obj = static_cast<ShaderInclude *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_code();
	};
	proxy->setter = [this_val](const String &value) -> void {
		ShaderInclude *js_proxy = static_cast<ShaderInclude *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_code(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry shader_include_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_code", 1, &shader_include_class_set_code),
	JS_CFUNC_DEF("get_code", 0, &shader_include_class_get_code),
};




static void define_shader_include_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "code"),
        JS_NewCFunction(ctx, shader_include_class_get_code, "get_code", 0),
        JS_NewCFunction(ctx, shader_include_class_set_code, "set_code", 1),
        JS_PROP_GETSET
    );
}

static void define_shader_include_enum(JSContext *ctx, JSValue proto) {
}

static int js_shader_include_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ShaderInclude"] = class_id;
	classes_by_id[class_id] = "ShaderInclude";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &shader_include_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_shader_include_property(ctx, proto);
	define_shader_include_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, shader_include_class_proto_funcs, _countof(shader_include_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, shader_include_class_constructor, "ShaderInclude", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ShaderInclude", ctor);

	return 0;
}

JSModuleDef *_js_init_shader_include_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_shader_include_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ShaderInclude");
	return m;
}

JSModuleDef *js_init_shader_include_module(JSContext *ctx) {
	return _js_init_shader_include_module(ctx, "@godot/classes/shader_include");
}

void __register_shader_include() {
	js_init_shader_include_module(js_context());
}

void register_shader_include() {
	__register_shader_include();
}