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
#include <godot_cpp/classes/visual_shader_node_particle_multiply_by_axis_angle.hpp>
using namespace godot;

static void visual_shader_node_particle_multiply_by_axis_angle_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShaderNodeParticleMultiplyByAxisAngle"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_node_particle_multiply_by_axis_angle_class_def = {
    "VisualShaderNodeParticleMultiplyByAxisAngle",
    visual_shader_node_particle_multiply_by_axis_angle_class_finalizer
};

static JSValue visual_shader_node_particle_multiply_by_axis_angle_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShaderNodeParticleMultiplyByAxisAngle"];
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
        instance = memnew(VisualShaderNodeParticleMultiplyByAxisAngle);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_node_particle_multiply_by_axis_angle_class_set_degrees_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShaderNodeParticleMultiplyByAxisAngle::set_degrees_mode, ctx, this_val, argc, argv);
};
static JSValue visual_shader_node_particle_multiply_by_axis_angle_class_is_degrees_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShaderNodeParticleMultiplyByAxisAngle::is_degrees_mode, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry visual_shader_node_particle_multiply_by_axis_angle_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_degrees_mode", 1, &visual_shader_node_particle_multiply_by_axis_angle_class_set_degrees_mode),
	JS_CFUNC_DEF("is_degrees_mode", 0, &visual_shader_node_particle_multiply_by_axis_angle_class_is_degrees_mode),
};




static void define_visual_shader_node_particle_multiply_by_axis_angle_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "degrees_mode"),
        JS_NewCFunction(ctx, visual_shader_node_particle_multiply_by_axis_angle_class_is_degrees_mode, "is_degrees_mode", 0),
        JS_NewCFunction(ctx, visual_shader_node_particle_multiply_by_axis_angle_class_set_degrees_mode, "set_degrees_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_node_particle_multiply_by_axis_angle_enum(JSContext *ctx, JSValue ctor) {
}

static int js_visual_shader_node_particle_multiply_by_axis_angle_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShaderNodeParticleMultiplyByAxisAngle"] = class_id;
	classes_by_id[class_id] = "VisualShaderNodeParticleMultiplyByAxisAngle";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_node_particle_multiply_by_axis_angle_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualShaderNode"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_node_particle_multiply_by_axis_angle_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_node_particle_multiply_by_axis_angle_class_proto_funcs, _countof(visual_shader_node_particle_multiply_by_axis_angle_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_node_particle_multiply_by_axis_angle_class_constructor, "VisualShaderNodeParticleMultiplyByAxisAngle", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_node_particle_multiply_by_axis_angle_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShaderNodeParticleMultiplyByAxisAngle", ctor);
	ctor_list["VisualShaderNodeParticleMultiplyByAxisAngle"] = ctor;

	return 0;
}

JSModuleDef *_js_init_visual_shader_node_particle_multiply_by_axis_angle_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_shader_node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_node_particle_multiply_by_axis_angle_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShaderNodeParticleMultiplyByAxisAngle");
	return m;
}

JSModuleDef *js_init_visual_shader_node_particle_multiply_by_axis_angle_module(JSContext *ctx) {
	return _js_init_visual_shader_node_particle_multiply_by_axis_angle_module(ctx, "@godot/classes/visual_shader_node_particle_multiply_by_axis_angle");
}

void __register_visual_shader_node_particle_multiply_by_axis_angle() {
	js_init_visual_shader_node_particle_multiply_by_axis_angle_module(js_context());
}

void register_visual_shader_node_particle_multiply_by_axis_angle() {
	__register_visual_shader_node_particle_multiply_by_axis_angle();
}