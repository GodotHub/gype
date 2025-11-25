#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_shader_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader_node_float_func.hpp>
using namespace godot;

static void visual_shader_node_float_func_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeFloatFunc"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_float_func_class_def = {
    "VisualShaderNodeFloatFunc",
    visual_shader_node_float_func_class_finalizer
};

static JSValue visual_shader_node_float_func_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeFloatFunc"];
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
        instance = memnew(VisualShaderNodeFloatFunc);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_float_func_class_set_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeFloatFunc::set_function, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_float_func_class_get_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeFloatFunc::get_function, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry visual_shader_node_float_func_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_function", 1, &visual_shader_node_float_func_class_set_function),
	JS_CFUNC_DEF("get_function", 0, &visual_shader_node_float_func_class_get_function),
};




static void define_visual_shader_node_float_func_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "function"),
        JS_NewCFunction(ctx, visual_shader_node_float_func_class_get_function, "get_function", 0),
        JS_NewCFunction(ctx, visual_shader_node_float_func_class_set_function, "set_function", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_float_func_enum(JSContext *ctx, JSValue ctor) {
	JSValue Function_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_SIN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_COS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_TAN", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ASIN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ACOS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ATAN", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_SINH", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_COSH", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_TANH", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_LOG", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_EXP", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_SQRT", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ABS", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_SIGN", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_FLOOR", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ROUND", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_CEIL", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_FRACT", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_SATURATE", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_NEGATE", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ACOSH", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ASINH", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ATANH", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_DEGREES", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_EXP2", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_INVERSE_SQRT", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_LOG2", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_RADIANS", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_RECIPROCAL", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ROUNDEVEN", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_TRUNC", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_ONEMINUS", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, Function_obj, "FUNC_MAX", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, ctor, "Function", Function_obj);
}

static int js_visual_shader_node_float_func_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeFloatFunc"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeFloatFunc";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_float_func_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_float_func_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_float_func_class_proto_funcs, _countof(visual_shader_node_float_func_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_float_func_class_constructor, "VisualShaderNodeFloatFunc", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_float_func_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeFloatFunc", ctor);
	ctor_list["VisualShaderNodeFloatFunc"] = ctor;

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_float_func_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_float_func_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeFloatFunc");
	return m;
}

JSModuleDef *js_init_visual_shader_node_float_func_module(JSContext *ctx) {
	return _js_init_visual_shader_node_float_func_module(ctx, "@godot/classes/visual_shader_node_float_func");
}

void __register_visual_shader_node_float_func() {
	js_init_visual_shader_node_float_func_module(js_context());
}

void register_visual_shader_node_float_func() {
	__register_visual_shader_node_float_func();
}