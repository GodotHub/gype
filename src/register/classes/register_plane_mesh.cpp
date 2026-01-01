#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/primitive_mesh.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/plane_mesh.hpp>
using namespace godot;

static void plane_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PlaneMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef plane_mesh_class_def = {
    "PlaneMesh",
    plane_mesh_class_finalizer
};

static JSValue plane_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PlaneMesh"];
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
        instance = memnew(PlaneMesh);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue plane_mesh_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaneMesh::set_size, ctx, this_val, argc, argv);
};
static JSValue plane_mesh_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PlaneMesh *obj = static_cast<PlaneMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PlaneMesh *js_proxy = static_cast<PlaneMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
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
static JSValue plane_mesh_class_set_subdivide_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaneMesh::set_subdivide_width, ctx, this_val, argc, argv);
};
static JSValue plane_mesh_class_get_subdivide_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PlaneMesh::get_subdivide_width, ctx, this_val, argc, argv);
}
static JSValue plane_mesh_class_set_subdivide_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaneMesh::set_subdivide_depth, ctx, this_val, argc, argv);
};
static JSValue plane_mesh_class_get_subdivide_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PlaneMesh::get_subdivide_depth, ctx, this_val, argc, argv);
}
static JSValue plane_mesh_class_set_center_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaneMesh::set_center_offset, ctx, this_val, argc, argv);
};
static JSValue plane_mesh_class_get_center_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		PlaneMesh *obj = static_cast<PlaneMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_center_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		PlaneMesh *js_proxy = static_cast<PlaneMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_center_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue plane_mesh_class_set_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PlaneMesh::set_orientation, ctx, this_val, argc, argv);
};
static JSValue plane_mesh_class_get_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PlaneMesh::get_orientation, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry plane_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &plane_mesh_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &plane_mesh_class_get_size),
	JS_CFUNC_DEF("set_subdivide_width", 1, &plane_mesh_class_set_subdivide_width),
	JS_CFUNC_DEF("get_subdivide_width", 0, &plane_mesh_class_get_subdivide_width),
	JS_CFUNC_DEF("set_subdivide_depth", 1, &plane_mesh_class_set_subdivide_depth),
	JS_CFUNC_DEF("get_subdivide_depth", 0, &plane_mesh_class_get_subdivide_depth),
	JS_CFUNC_DEF("set_center_offset", 1, &plane_mesh_class_set_center_offset),
	JS_CFUNC_DEF("get_center_offset", 0, &plane_mesh_class_get_center_offset),
	JS_CFUNC_DEF("set_orientation", 1, &plane_mesh_class_set_orientation),
	JS_CFUNC_DEF("get_orientation", 0, &plane_mesh_class_get_orientation),
};




static void define_plane_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, plane_mesh_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, plane_mesh_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subdivide_width"),
        JS_NewCFunction(ctx, plane_mesh_class_get_subdivide_width, "get_subdivide_width", 0),
        JS_NewCFunction(ctx, plane_mesh_class_set_subdivide_width, "set_subdivide_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subdivide_depth"),
        JS_NewCFunction(ctx, plane_mesh_class_get_subdivide_depth, "get_subdivide_depth", 0),
        JS_NewCFunction(ctx, plane_mesh_class_set_subdivide_depth, "set_subdivide_depth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_offset"),
        JS_NewCFunction(ctx, plane_mesh_class_get_center_offset, "get_center_offset", 0),
        JS_NewCFunction(ctx, plane_mesh_class_set_center_offset, "set_center_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "orientation"),
        JS_NewCFunction(ctx, plane_mesh_class_get_orientation, "get_orientation", 0),
        JS_NewCFunction(ctx, plane_mesh_class_set_orientation, "set_orientation", 1),
        JS_PROP_GETSET
    );
}

static void define_plane_mesh_enum(JSContext *ctx, JSValue ctor) {
	JSValue Orientation_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Orientation_obj, "FACE_X", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Orientation_obj, "FACE_Y", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Orientation_obj, "FACE_Z", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Orientation", Orientation_obj);
}

static int js_plane_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PlaneMesh"] = class_id;
	classes_by_id[class_id] = "PlaneMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &plane_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PrimitiveMesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_plane_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, plane_mesh_class_proto_funcs, _countof(plane_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, plane_mesh_class_constructor, "PlaneMesh", 0, JS_CFUNC_constructor, 0);
	define_plane_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PlaneMesh", ctor);
	ctor_list["PlaneMesh"] = ctor;

	return 0;
}

JSModuleDef *_js_init_plane_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/primitive_mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_plane_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PlaneMesh");
	return m;
}

JSModuleDef *js_init_plane_mesh_module(JSContext *ctx) {
	return _js_init_plane_mesh_module(ctx, "@godot/classes/plane_mesh");
}

void __register_plane_mesh() {
	js_init_plane_mesh_module(js_context());
}

void register_plane_mesh() {
	__register_plane_mesh();
}