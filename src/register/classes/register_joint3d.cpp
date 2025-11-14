#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/joint3d.hpp>
using namespace godot;

static void joint3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Joint3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef joint3d_class_def = {
    "Joint3D",
    joint3d_class_finalizer
};

static JSValue joint3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Joint3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Joint3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Joint3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Joint3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue joint3d_class_set_node_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Joint3D::set_node_a, ctx, this_val, argc, argv);
};
static JSValue joint3d_class_get_node_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		Joint3D *obj = static_cast<Joint3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_node_a();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		Joint3D *js_proxy = static_cast<Joint3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_node_a(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue joint3d_class_set_node_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Joint3D::set_node_b, ctx, this_val, argc, argv);
};
static JSValue joint3d_class_get_node_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		Joint3D *obj = static_cast<Joint3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_node_b();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		Joint3D *js_proxy = static_cast<Joint3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_node_b(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue joint3d_class_set_solver_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Joint3D::set_solver_priority, ctx, this_val, argc, argv);
};
static JSValue joint3d_class_get_solver_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Joint3D::get_solver_priority, ctx, this_val, argc, argv);
}
static JSValue joint3d_class_set_exclude_nodes_from_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Joint3D::set_exclude_nodes_from_collision, ctx, this_val, argc, argv);
};
static JSValue joint3d_class_get_exclude_nodes_from_collision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Joint3D::get_exclude_nodes_from_collision, ctx, this_val, argc, argv);
}
static JSValue joint3d_class_get_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Joint3D::get_rid, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry joint3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_node_a", 1, &joint3d_class_set_node_a),
	JS_CFUNC_DEF("get_node_a", 0, &joint3d_class_get_node_a),
	JS_CFUNC_DEF("set_node_b", 1, &joint3d_class_set_node_b),
	JS_CFUNC_DEF("get_node_b", 0, &joint3d_class_get_node_b),
	JS_CFUNC_DEF("set_solver_priority", 1, &joint3d_class_set_solver_priority),
	JS_CFUNC_DEF("get_solver_priority", 0, &joint3d_class_get_solver_priority),
	JS_CFUNC_DEF("set_exclude_nodes_from_collision", 1, &joint3d_class_set_exclude_nodes_from_collision),
	JS_CFUNC_DEF("get_exclude_nodes_from_collision", 0, &joint3d_class_get_exclude_nodes_from_collision),
	JS_CFUNC_DEF("get_rid", 0, &joint3d_class_get_rid),
};




static void define_joint3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "node_a"),
        JS_NewCFunction(ctx, joint3d_class_get_node_a, "get_node_a", 0),
        JS_NewCFunction(ctx, joint3d_class_set_node_a, "set_node_a", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "node_b"),
        JS_NewCFunction(ctx, joint3d_class_get_node_b, "get_node_b", 0),
        JS_NewCFunction(ctx, joint3d_class_set_node_b, "set_node_b", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "solver_priority"),
        JS_NewCFunction(ctx, joint3d_class_get_solver_priority, "get_solver_priority", 0),
        JS_NewCFunction(ctx, joint3d_class_set_solver_priority, "set_solver_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude_nodes_from_collision"),
        JS_NewCFunction(ctx, joint3d_class_get_exclude_nodes_from_collision, "get_exclude_nodes_from_collision", 0),
        JS_NewCFunction(ctx, joint3d_class_set_exclude_nodes_from_collision, "set_exclude_nodes_from_collision", 1),
        JS_PROP_GETSET
    );
}

static void define_joint3d_enum(JSContext *ctx, JSValue proto) {
}

static int js_joint3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Joint3D"] = class_id;
	classes_by_id[class_id] = "Joint3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &joint3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_joint3d_property(ctx, proto);
	define_joint3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, joint3d_class_proto_funcs, _countof(joint3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, joint3d_class_constructor, "Joint3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Joint3D", ctor);

	return 0;
}

JSModuleDef *_js_init_joint3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_joint3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Joint3D");
	return m;
}

JSModuleDef *js_init_joint3d_module(JSContext *ctx) {
	return _js_init_joint3d_module(ctx, "@godot/classes/joint3d");
}

void __register_joint3d() {
	js_init_joint3d_module(js_context());
}

void register_joint3d() {
	__register_joint3d();
}