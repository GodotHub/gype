#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shader.hpp>
#include <godot_cpp/classes/visual_shader_node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/visual_shader.hpp>
using namespace godot;

static void visual_shader_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VisualShader"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef visual_shader_class_def = {
    "VisualShader",
    visual_shader_class_finalizer
};

static JSValue visual_shader_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VisualShader"];
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
        instance = memnew(VisualShader);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue visual_shader_class_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::set_mode, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_add_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::add_node, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_get_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::get_node, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_set_node_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::set_node_position, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_get_node_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::get_node_position, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_get_node_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::get_node_list, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_get_valid_node_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::get_valid_node_id, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_remove_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::remove_node, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_replace_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::replace_node, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_is_node_connection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::is_node_connection, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_can_connect_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::can_connect_nodes, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_connect_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&VisualShader::connect_nodes, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_disconnect_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::disconnect_nodes, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_connect_nodes_forced(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::connect_nodes_forced, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_get_node_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::get_node_connections, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_attach_node_to_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::attach_node_to_frame, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_detach_node_from_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::detach_node_from_frame, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_add_varying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::add_varying, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_remove_varying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::remove_varying, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_has_varying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VisualShader::has_varying, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_set_graph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VisualShader::set_graph_offset, ctx, this_val, argc, argv);
};
static JSValue visual_shader_class_get_graph_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		VisualShader *obj = static_cast<VisualShader *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_graph_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		VisualShader *js_proxy = static_cast<VisualShader *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_graph_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry visual_shader_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mode", 1, &visual_shader_class_set_mode),
	JS_CFUNC_DEF("add_node", 4, &visual_shader_class_add_node),
	JS_CFUNC_DEF("get_node", 2, &visual_shader_class_get_node),
	JS_CFUNC_DEF("set_node_position", 3, &visual_shader_class_set_node_position),
	JS_CFUNC_DEF("get_node_position", 2, &visual_shader_class_get_node_position),
	JS_CFUNC_DEF("get_node_list", 1, &visual_shader_class_get_node_list),
	JS_CFUNC_DEF("get_valid_node_id", 1, &visual_shader_class_get_valid_node_id),
	JS_CFUNC_DEF("remove_node", 2, &visual_shader_class_remove_node),
	JS_CFUNC_DEF("replace_node", 3, &visual_shader_class_replace_node),
	JS_CFUNC_DEF("is_node_connection", 5, &visual_shader_class_is_node_connection),
	JS_CFUNC_DEF("can_connect_nodes", 5, &visual_shader_class_can_connect_nodes),
	JS_CFUNC_DEF("connect_nodes", 5, &visual_shader_class_connect_nodes),
	JS_CFUNC_DEF("disconnect_nodes", 5, &visual_shader_class_disconnect_nodes),
	JS_CFUNC_DEF("connect_nodes_forced", 5, &visual_shader_class_connect_nodes_forced),
	JS_CFUNC_DEF("get_node_connections", 1, &visual_shader_class_get_node_connections),
	JS_CFUNC_DEF("attach_node_to_frame", 3, &visual_shader_class_attach_node_to_frame),
	JS_CFUNC_DEF("detach_node_from_frame", 2, &visual_shader_class_detach_node_from_frame),
	JS_CFUNC_DEF("add_varying", 3, &visual_shader_class_add_varying),
	JS_CFUNC_DEF("remove_varying", 1, &visual_shader_class_remove_varying),
	JS_CFUNC_DEF("has_varying", 1, &visual_shader_class_has_varying),
	JS_CFUNC_DEF("set_graph_offset", 1, &visual_shader_class_set_graph_offset),
	JS_CFUNC_DEF("get_graph_offset", 0, &visual_shader_class_get_graph_offset),
};




static void define_visual_shader_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "graph_offset"),
        JS_NewCFunction(ctx, visual_shader_class_get_graph_offset, "get_graph_offset", 0),
        JS_NewCFunction(ctx, visual_shader_class_set_graph_offset, "set_graph_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_visual_shader_enum(JSContext *ctx, JSValue ctor) {
	JSValue Type_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_VERTEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_FRAGMENT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_LIGHT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_START", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_PROCESS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_COLLIDE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_START_CUSTOM", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_PROCESS_CUSTOM", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_SKY", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_FOG", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Type_obj, "TYPE_MAX", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, ctor, "Type", Type_obj);
	JSValue VaryingMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VaryingMode_obj, "VARYING_MODE_VERTEX_TO_FRAG_LIGHT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VaryingMode_obj, "VARYING_MODE_FRAG_TO_LIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VaryingMode_obj, "VARYING_MODE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "VaryingMode", VaryingMode_obj);
	JSValue VaryingType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_FLOAT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_INT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_UINT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_VECTOR_2D", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_VECTOR_3D", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_VECTOR_4D", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_BOOLEAN", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_TRANSFORM", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, VaryingType_obj, "VARYING_TYPE_MAX", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "VaryingType", VaryingType_obj);
}

static int js_visual_shader_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VisualShader"] = class_id;
	classes_by_id[class_id] = "VisualShader";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &visual_shader_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shader"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_visual_shader_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, visual_shader_class_proto_funcs, _countof(visual_shader_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, visual_shader_class_constructor, "VisualShader", 0, JS_CFUNC_constructor, 0);
	define_visual_shader_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VisualShader", ctor);
	ctor_list["VisualShader"] = ctor;

	return 0;
}

JSModuleDef *_js_init_visual_shader_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shader';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_visual_shader_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VisualShader");
	return m;
}

JSModuleDef *js_init_visual_shader_module(JSContext *ctx) {
	return _js_init_visual_shader_module(ctx, "@godot/classes/visual_shader");
}

void __register_visual_shader() {
	js_init_visual_shader_module(js_context());
}

void register_visual_shader() {
	__register_visual_shader();
}