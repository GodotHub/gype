#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/shader.hpp>
using namespace godot;

static void shader_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Shader"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef shader_class_def = {
    "Shader",
    shader_class_finalizer
};

static JSValue shader_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Shader"];
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
        instance = memnew(Shader);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue shader_class_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shader::get_mode, ctx, this_val, argc, argv);
};
static JSValue shader_class_set_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shader::set_code, ctx, this_val, argc, argv);
};
static JSValue shader_class_get_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shader::get_code, ctx, this_val, argc, argv);
}
static JSValue shader_class_set_default_texture_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shader::set_default_texture_parameter, ctx, this_val, argc, argv);
};
static JSValue shader_class_get_default_texture_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shader::get_default_texture_parameter, ctx, this_val, argc, argv);
};
static JSValue shader_class_get_shader_uniform_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Shader::get_shader_uniform_list, ctx, this_val, argc, argv);
};
static JSValue shader_class_inspect_native_shader_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shader::inspect_native_shader_code, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry shader_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_mode", 0, &shader_class_get_mode),
	JS_CFUNC_DEF("set_code", 1, &shader_class_set_code),
	JS_CFUNC_DEF("get_code", 0, &shader_class_get_code),
	JS_CFUNC_DEF("set_default_texture_parameter", 3, &shader_class_set_default_texture_parameter),
	JS_CFUNC_DEF("get_default_texture_parameter", 2, &shader_class_get_default_texture_parameter),
	JS_CFUNC_DEF("get_shader_uniform_list", 1, &shader_class_get_shader_uniform_list),
	JS_CFUNC_DEF("inspect_native_shader_code", 0, &shader_class_inspect_native_shader_code),
};




static void define_shader_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "code"),
        JS_NewCFunction(ctx, shader_class_get_code, "get_code", 0),
        JS_NewCFunction(ctx, shader_class_set_code, "set_code", 1),
        JS_PROP_GETSET
    );
}

static void define_shader_enum(JSContext *ctx, JSValue ctor) {
	JSValue Mode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_SPATIAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_CANVAS_ITEM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_PARTICLES", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_SKY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_FOG", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "Mode", Mode_obj);
}

static int js_shader_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Shader"] = class_id;
	classes_by_id[class_id] = "Shader";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &shader_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_shader_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, shader_class_proto_funcs, _countof(shader_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, shader_class_constructor, "Shader", 0, JS_CFUNC_constructor, 0);
	define_shader_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Shader", ctor);
	ctor_list["Shader"] = ctor;

	return 0;
}

JSModuleDef *_js_init_shader_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_shader_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Shader");
	return m;
}

JSModuleDef *js_init_shader_module(JSContext *ctx) {
	return _js_init_shader_module(ctx, "@godot/classes/shader");
}

void __register_shader() {
	js_init_shader_module(js_context());
}

void register_shader() {
	__register_shader();
}