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
#include <godot_cpp/classes/remote_transform3d.hpp>
using namespace godot;

static void remote_transform3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RemoteTransform3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef remote_transform3d_class_def = {
    "RemoteTransform3D",
    remote_transform3d_class_finalizer
};

static JSValue remote_transform3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RemoteTransform3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RemoteTransform3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RemoteTransform3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RemoteTransform3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue remote_transform3d_class_set_remote_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RemoteTransform3D::set_remote_node, ctx, this_val, argc, argv);
};
static JSValue remote_transform3d_class_get_remote_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RemoteTransform3D::get_remote_node, ctx, this_val, argc, argv);
}
static JSValue remote_transform3d_class_force_update_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RemoteTransform3D::force_update_cache, ctx, this_val, argc, argv);
};
static JSValue remote_transform3d_class_set_use_global_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RemoteTransform3D::set_use_global_coordinates, ctx, this_val, argc, argv);
};
static JSValue remote_transform3d_class_get_use_global_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RemoteTransform3D::get_use_global_coordinates, ctx, this_val, argc, argv);
}
static JSValue remote_transform3d_class_set_update_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RemoteTransform3D::set_update_position, ctx, this_val, argc, argv);
};
static JSValue remote_transform3d_class_get_update_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RemoteTransform3D::get_update_position, ctx, this_val, argc, argv);
}
static JSValue remote_transform3d_class_set_update_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RemoteTransform3D::set_update_rotation, ctx, this_val, argc, argv);
};
static JSValue remote_transform3d_class_get_update_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RemoteTransform3D::get_update_rotation, ctx, this_val, argc, argv);
}
static JSValue remote_transform3d_class_set_update_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RemoteTransform3D::set_update_scale, ctx, this_val, argc, argv);
};
static JSValue remote_transform3d_class_get_update_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RemoteTransform3D::get_update_scale, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry remote_transform3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_remote_node", 1, &remote_transform3d_class_set_remote_node),
	JS_CFUNC_DEF("get_remote_node", 0, &remote_transform3d_class_get_remote_node),
	JS_CFUNC_DEF("force_update_cache", 0, &remote_transform3d_class_force_update_cache),
	JS_CFUNC_DEF("set_use_global_coordinates", 1, &remote_transform3d_class_set_use_global_coordinates),
	JS_CFUNC_DEF("get_use_global_coordinates", 0, &remote_transform3d_class_get_use_global_coordinates),
	JS_CFUNC_DEF("set_update_position", 1, &remote_transform3d_class_set_update_position),
	JS_CFUNC_DEF("get_update_position", 0, &remote_transform3d_class_get_update_position),
	JS_CFUNC_DEF("set_update_rotation", 1, &remote_transform3d_class_set_update_rotation),
	JS_CFUNC_DEF("get_update_rotation", 0, &remote_transform3d_class_get_update_rotation),
	JS_CFUNC_DEF("set_update_scale", 1, &remote_transform3d_class_set_update_scale),
	JS_CFUNC_DEF("get_update_scale", 0, &remote_transform3d_class_get_update_scale),
};




static void define_remote_transform3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "remote_path"),
        JS_NewCFunction(ctx, remote_transform3d_class_get_remote_node, "get_remote_node", 0),
        JS_NewCFunction(ctx, remote_transform3d_class_set_remote_node, "set_remote_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_global_coordinates"),
        JS_NewCFunction(ctx, remote_transform3d_class_get_use_global_coordinates, "get_use_global_coordinates", 0),
        JS_NewCFunction(ctx, remote_transform3d_class_set_use_global_coordinates, "set_use_global_coordinates", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "update_position"),
        JS_NewCFunction(ctx, remote_transform3d_class_get_update_position, "get_update_position", 0),
        JS_NewCFunction(ctx, remote_transform3d_class_set_update_position, "set_update_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "update_rotation"),
        JS_NewCFunction(ctx, remote_transform3d_class_get_update_rotation, "get_update_rotation", 0),
        JS_NewCFunction(ctx, remote_transform3d_class_set_update_rotation, "set_update_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "update_scale"),
        JS_NewCFunction(ctx, remote_transform3d_class_get_update_scale, "get_update_scale", 0),
        JS_NewCFunction(ctx, remote_transform3d_class_set_update_scale, "set_update_scale", 1),
        JS_PROP_GETSET
    );
}

static void define_remote_transform3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_remote_transform3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RemoteTransform3D"] = class_id;
	classes_by_id[class_id] = "RemoteTransform3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &remote_transform3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_remote_transform3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, remote_transform3d_class_proto_funcs, _countof(remote_transform3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, remote_transform3d_class_constructor, "RemoteTransform3D", 0, JS_CFUNC_constructor, 0);
	define_remote_transform3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RemoteTransform3D", ctor);

	return 0;
}

JSModuleDef *_js_init_remote_transform3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_remote_transform3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RemoteTransform3D");
	return m;
}

JSModuleDef *js_init_remote_transform3d_module(JSContext *ctx) {
	return _js_init_remote_transform3d_module(ctx, "@godot/classes/remote_transform3d");
}

void __register_remote_transform3d() {
	js_init_remote_transform3d_module(js_context());
}

void register_remote_transform3d() {
	__register_remote_transform3d();
}