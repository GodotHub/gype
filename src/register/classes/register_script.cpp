#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/script.hpp>
using namespace godot;

static void script_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Script"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_class_def = {
    "Script",
    script_class_finalizer
};

static JSValue script_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Script"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Script *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Script *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Script);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue script_class_can_instantiate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::can_instantiate, ctx, this_val, argc, argv);
};
static JSValue script_class_instance_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::instance_has, ctx, this_val, argc, argv);
};
static JSValue script_class_has_source_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::has_source_code, ctx, this_val, argc, argv);
};
static JSValue script_class_get_source_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		Script *obj = static_cast<Script *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_source_code();
	};
	proxy->setter = [this_val](const String &value) -> void {
		Script *js_proxy = static_cast<Script *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_source_code(value);
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
static JSValue script_class_set_source_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Script::set_source_code, ctx, this_val, argc, argv);
};
static JSValue script_class_reload(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Script::reload, ctx, this_val, argc, argv);
};
static JSValue script_class_get_base_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::get_base_script, ctx, this_val, argc, argv);
};
static JSValue script_class_get_instance_base_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::get_instance_base_type, ctx, this_val, argc, argv);
};
static JSValue script_class_get_global_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::get_global_name, ctx, this_val, argc, argv);
};
static JSValue script_class_has_script_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::has_script_signal, ctx, this_val, argc, argv);
};
static JSValue script_class_get_script_property_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Script::get_script_property_list, ctx, this_val, argc, argv);
};
static JSValue script_class_get_script_method_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Script::get_script_method_list, ctx, this_val, argc, argv);
};
static JSValue script_class_get_script_signal_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Script::get_script_signal_list, ctx, this_val, argc, argv);
};
static JSValue script_class_get_script_constant_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Script::get_script_constant_map, ctx, this_val, argc, argv);
};
static JSValue script_class_get_property_default_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Script::get_property_default_value, ctx, this_val, argc, argv);
};
static JSValue script_class_is_tool(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::is_tool, ctx, this_val, argc, argv);
};
static JSValue script_class_is_abstract(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::is_abstract, ctx, this_val, argc, argv);
};
static JSValue script_class_get_rpc_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Script::get_rpc_config, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry script_class_proto_funcs[] = {
	JS_CFUNC_DEF("can_instantiate", 0, &script_class_can_instantiate),
	JS_CFUNC_DEF("instance_has", 1, &script_class_instance_has),
	JS_CFUNC_DEF("has_source_code", 0, &script_class_has_source_code),
	JS_CFUNC_DEF("get_source_code", 0, &script_class_get_source_code),
	JS_CFUNC_DEF("set_source_code", 1, &script_class_set_source_code),
	JS_CFUNC_DEF("reload", 1, &script_class_reload),
	JS_CFUNC_DEF("get_base_script", 0, &script_class_get_base_script),
	JS_CFUNC_DEF("get_instance_base_type", 0, &script_class_get_instance_base_type),
	JS_CFUNC_DEF("get_global_name", 0, &script_class_get_global_name),
	JS_CFUNC_DEF("has_script_signal", 1, &script_class_has_script_signal),
	JS_CFUNC_DEF("get_script_property_list", 0, &script_class_get_script_property_list),
	JS_CFUNC_DEF("get_script_method_list", 0, &script_class_get_script_method_list),
	JS_CFUNC_DEF("get_script_signal_list", 0, &script_class_get_script_signal_list),
	JS_CFUNC_DEF("get_script_constant_map", 0, &script_class_get_script_constant_map),
	JS_CFUNC_DEF("get_property_default_value", 1, &script_class_get_property_default_value),
	JS_CFUNC_DEF("is_tool", 0, &script_class_is_tool),
	JS_CFUNC_DEF("is_abstract", 0, &script_class_is_abstract),
	JS_CFUNC_DEF("get_rpc_config", 0, &script_class_get_rpc_config),
};




static void define_script_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "source_code"),
        JS_NewCFunction(ctx, script_class_get_source_code, "get_source_code", 0),
        JS_NewCFunction(ctx, script_class_set_source_code, "set_source_code", 1),
        JS_PROP_GETSET
    );
}

static void define_script_enum(JSContext *ctx, JSValue proto) {
}

static int js_script_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Script"] = class_id;
	classes_by_id[class_id] = "Script";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_property(ctx, proto);
	define_script_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, script_class_proto_funcs, _countof(script_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, script_class_constructor, "Script", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Script", ctor);

	return 0;
}

JSModuleDef *_js_init_script_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Script");
	return m;
}

JSModuleDef *js_init_script_module(JSContext *ctx) {
	return _js_init_script_module(ctx, "@godot/classes/script");
}

void __register_script() {
	js_init_script_module(js_context());
}

void register_script() {
	__register_script();
}