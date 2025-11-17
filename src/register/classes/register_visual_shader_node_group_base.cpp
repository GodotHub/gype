#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_shader_node_resizable_base.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader_node_group_base.hpp>
using namespace godot;

static void visual_shader_node_group_base_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeGroupBase"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_group_base_class_def = {
    "VisualShaderNodeGroupBase",
    visual_shader_node_group_base_class_finalizer
};

static JSValue visual_shader_node_group_base_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeGroupBase"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VisualShaderNodeGroupBase *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VisualShaderNodeGroupBase *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VisualShaderNodeGroupBase);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_group_base_class_set_inputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::set_inputs, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_get_inputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::get_inputs, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_set_outputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::set_outputs, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_get_outputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::get_outputs, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_is_valid_port_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::is_valid_port_name, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_add_input_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::add_input_port, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_remove_input_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::remove_input_port, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_get_input_port_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::get_input_port_count, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_has_input_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::has_input_port, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_clear_input_ports(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::clear_input_ports, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_add_output_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::add_output_port, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_remove_output_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::remove_output_port, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_get_output_port_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::get_output_port_count, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_has_output_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::has_output_port, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_clear_output_ports(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::clear_output_ports, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_set_input_port_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::set_input_port_name, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_set_input_port_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::set_input_port_type, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_set_output_port_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::set_output_port_name, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_set_output_port_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeGroupBase::set_output_port_type, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_get_free_input_port_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::get_free_input_port_id, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_group_base_class_get_free_output_port_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeGroupBase::get_free_output_port_id, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry visual_shader_node_group_base_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_inputs", 1, &visual_shader_node_group_base_class_set_inputs),
	JS_CFUNC_DEF("get_inputs", 0, &visual_shader_node_group_base_class_get_inputs),
	JS_CFUNC_DEF("set_outputs", 1, &visual_shader_node_group_base_class_set_outputs),
	JS_CFUNC_DEF("get_outputs", 0, &visual_shader_node_group_base_class_get_outputs),
	JS_CFUNC_DEF("is_valid_port_name", 1, &visual_shader_node_group_base_class_is_valid_port_name),
	JS_CFUNC_DEF("add_input_port", 3, &visual_shader_node_group_base_class_add_input_port),
	JS_CFUNC_DEF("remove_input_port", 1, &visual_shader_node_group_base_class_remove_input_port),
	JS_CFUNC_DEF("get_input_port_count", 0, &visual_shader_node_group_base_class_get_input_port_count),
	JS_CFUNC_DEF("has_input_port", 1, &visual_shader_node_group_base_class_has_input_port),
	JS_CFUNC_DEF("clear_input_ports", 0, &visual_shader_node_group_base_class_clear_input_ports),
	JS_CFUNC_DEF("add_output_port", 3, &visual_shader_node_group_base_class_add_output_port),
	JS_CFUNC_DEF("remove_output_port", 1, &visual_shader_node_group_base_class_remove_output_port),
	JS_CFUNC_DEF("get_output_port_count", 0, &visual_shader_node_group_base_class_get_output_port_count),
	JS_CFUNC_DEF("has_output_port", 1, &visual_shader_node_group_base_class_has_output_port),
	JS_CFUNC_DEF("clear_output_ports", 0, &visual_shader_node_group_base_class_clear_output_ports),
	JS_CFUNC_DEF("set_input_port_name", 2, &visual_shader_node_group_base_class_set_input_port_name),
	JS_CFUNC_DEF("set_input_port_type", 2, &visual_shader_node_group_base_class_set_input_port_type),
	JS_CFUNC_DEF("set_output_port_name", 2, &visual_shader_node_group_base_class_set_output_port_name),
	JS_CFUNC_DEF("set_output_port_type", 2, &visual_shader_node_group_base_class_set_output_port_type),
	JS_CFUNC_DEF("get_free_input_port_id", 0, &visual_shader_node_group_base_class_get_free_input_port_id),
	JS_CFUNC_DEF("get_free_output_port_id", 0, &visual_shader_node_group_base_class_get_free_output_port_id),
};




static void define_visual_shader_node_group_base_property(JSContext *ctx, JSValue proto) {
}

static void define_visual_shader_node_group_base_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visual_shader_node_group_base_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeGroupBase"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeGroupBase";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_group_base_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNodeResizableBase"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_group_base_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_group_base_class_proto_funcs, _countof(visual_shader_node_group_base_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_group_base_class_constructor, "VisualShaderNodeGroupBase", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_group_base_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeGroupBase", ctor);

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_group_base_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node_resizable_base';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_group_base_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeGroupBase");
	return m;
}

JSModuleDef *js_init_visual_shader_node_group_base_module(JSContext *ctx) {
	return _js_init_visual_shader_node_group_base_module(ctx, "@godot/classes/visual_shader_node_group_base");
}

void __register_visual_shader_node_group_base() {
	js_init_visual_shader_node_group_base_module(js_context());
}

void register_visual_shader_node_group_base() {
	__register_visual_shader_node_group_base();
}