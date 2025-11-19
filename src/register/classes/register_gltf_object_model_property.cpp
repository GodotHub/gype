#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/expression.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_object_model_property.hpp>
using namespace godot;

static void gltf_object_model_property_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFObjectModelProperty"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef gltf_object_model_property_class_def = {
    "GLTFObjectModelProperty",
    gltf_object_model_property_class_finalizer
};

static JSValue gltf_object_model_property_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFObjectModelProperty"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFObjectModelProperty *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFObjectModelProperty *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFObjectModelProperty);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_object_model_property_class_append_node_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::append_node_path, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_append_path_to_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::append_path_to_property, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_accessor_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_accessor_type, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_gltf_to_godot_expression(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_gltf_to_godot_expression, ctx, this_val, argc, argv);
}
static JSValue gltf_object_model_property_class_set_gltf_to_godot_expression(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_gltf_to_godot_expression, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_godot_to_gltf_expression(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_godot_to_gltf_expression, ctx, this_val, argc, argv);
}
static JSValue gltf_object_model_property_class_set_godot_to_gltf_expression(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_godot_to_gltf_expression, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_node_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_node_paths, ctx, this_val, argc, argv);
}
static JSValue gltf_object_model_property_class_has_node_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::has_node_paths, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_set_node_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_node_paths, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_object_model_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_object_model_type, ctx, this_val, argc, argv);
}
static JSValue gltf_object_model_property_class_set_object_model_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_object_model_type, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_json_pointers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_json_pointers, ctx, this_val, argc, argv);
}
static JSValue gltf_object_model_property_class_has_json_pointers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::has_json_pointers, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_set_json_pointers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_json_pointers, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_get_variant_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFObjectModelProperty::get_variant_type, ctx, this_val, argc, argv);
}
static JSValue gltf_object_model_property_class_set_variant_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_variant_type, ctx, this_val, argc, argv);
};
static JSValue gltf_object_model_property_class_set_types(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFObjectModelProperty::set_types, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_object_model_property_class_proto_funcs[] = {
	JS_CFUNC_DEF("append_node_path", 1, &gltf_object_model_property_class_append_node_path),
	JS_CFUNC_DEF("append_path_to_property", 2, &gltf_object_model_property_class_append_path_to_property),
	JS_CFUNC_DEF("get_accessor_type", 0, &gltf_object_model_property_class_get_accessor_type),
	JS_CFUNC_DEF("get_gltf_to_godot_expression", 0, &gltf_object_model_property_class_get_gltf_to_godot_expression),
	JS_CFUNC_DEF("set_gltf_to_godot_expression", 1, &gltf_object_model_property_class_set_gltf_to_godot_expression),
	JS_CFUNC_DEF("get_godot_to_gltf_expression", 0, &gltf_object_model_property_class_get_godot_to_gltf_expression),
	JS_CFUNC_DEF("set_godot_to_gltf_expression", 1, &gltf_object_model_property_class_set_godot_to_gltf_expression),
	JS_CFUNC_DEF("get_node_paths", 0, &gltf_object_model_property_class_get_node_paths),
	JS_CFUNC_DEF("has_node_paths", 0, &gltf_object_model_property_class_has_node_paths),
	JS_CFUNC_DEF("set_node_paths", 1, &gltf_object_model_property_class_set_node_paths),
	JS_CFUNC_DEF("get_object_model_type", 0, &gltf_object_model_property_class_get_object_model_type),
	JS_CFUNC_DEF("set_object_model_type", 1, &gltf_object_model_property_class_set_object_model_type),
	JS_CFUNC_DEF("get_json_pointers", 0, &gltf_object_model_property_class_get_json_pointers),
	JS_CFUNC_DEF("has_json_pointers", 0, &gltf_object_model_property_class_has_json_pointers),
	JS_CFUNC_DEF("set_json_pointers", 1, &gltf_object_model_property_class_set_json_pointers),
	JS_CFUNC_DEF("get_variant_type", 0, &gltf_object_model_property_class_get_variant_type),
	JS_CFUNC_DEF("set_variant_type", 1, &gltf_object_model_property_class_set_variant_type),
	JS_CFUNC_DEF("set_types", 2, &gltf_object_model_property_class_set_types),
};




static void define_gltf_object_model_property_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gltf_to_godot_expression"),
        JS_NewCFunction(ctx, gltf_object_model_property_class_get_gltf_to_godot_expression, "get_gltf_to_godot_expression", 0),
        JS_NewCFunction(ctx, gltf_object_model_property_class_set_gltf_to_godot_expression, "set_gltf_to_godot_expression", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "godot_to_gltf_expression"),
        JS_NewCFunction(ctx, gltf_object_model_property_class_get_godot_to_gltf_expression, "get_godot_to_gltf_expression", 0),
        JS_NewCFunction(ctx, gltf_object_model_property_class_set_godot_to_gltf_expression, "set_godot_to_gltf_expression", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "node_paths"),
        JS_NewCFunction(ctx, gltf_object_model_property_class_get_node_paths, "get_node_paths", 0),
        JS_NewCFunction(ctx, gltf_object_model_property_class_set_node_paths, "set_node_paths", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "object_model_type"),
        JS_NewCFunction(ctx, gltf_object_model_property_class_get_object_model_type, "get_object_model_type", 0),
        JS_NewCFunction(ctx, gltf_object_model_property_class_set_object_model_type, "set_object_model_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "json_pointers"),
        JS_NewCFunction(ctx, gltf_object_model_property_class_get_json_pointers, "get_json_pointers", 0),
        JS_NewCFunction(ctx, gltf_object_model_property_class_set_json_pointers, "set_json_pointers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "variant_type"),
        JS_NewCFunction(ctx, gltf_object_model_property_class_get_variant_type, "get_variant_type", 0),
        JS_NewCFunction(ctx, gltf_object_model_property_class_set_variant_type, "set_variant_type", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_object_model_property_enum(JSContext *ctx, JSValue ctor) {
	JSValue GLTFObjectModelType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_BOOL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT_ARRAY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT2", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT3", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT4", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT2X2", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT3X3", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_FLOAT4X4", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, GLTFObjectModelType_obj, "GLTF_OBJECT_MODEL_TYPE_INT", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, ctor, "GLTFObjectModelType", GLTFObjectModelType_obj);
}

static int js_gltf_object_model_property_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFObjectModelProperty"] = class_id;
	classes_by_id[class_id] = "GLTFObjectModelProperty";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_object_model_property_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_object_model_property_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_object_model_property_class_proto_funcs, _countof(gltf_object_model_property_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_object_model_property_class_constructor, "GLTFObjectModelProperty", 0, JS_CFUNC_constructor, 0);
	define_gltf_object_model_property_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFObjectModelProperty", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_object_model_property_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_object_model_property_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFObjectModelProperty");
	return m;
}

JSModuleDef *js_init_gltf_object_model_property_module(JSContext *ctx) {
	return _js_init_gltf_object_model_property_module(ctx, "@godot/classes/gltf_object_model_property");
}

void __register_gltf_object_model_property() {
	js_init_gltf_object_model_property_module(js_context());
}

void register_gltf_object_model_property() {
	__register_gltf_object_model_property();
}