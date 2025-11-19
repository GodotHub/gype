#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/multi_mesh.hpp>
using namespace godot;

static void multi_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MultiMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef multi_mesh_class_def = {
    "MultiMesh",
    multi_mesh_class_finalizer
};

static JSValue multi_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MultiMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MultiMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MultiMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MultiMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue multi_mesh_class_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_mesh, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_mesh, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_use_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_use_colors, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_is_using_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::is_using_colors, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_use_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_use_custom_data, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_is_using_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::is_using_custom_data, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_transform_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_transform_format, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_transform_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_transform_format, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_instance_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_instance_count, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_instance_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_instance_count, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_visible_instance_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_visible_instance_count, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_visible_instance_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_visible_instance_count, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_physics_interpolation_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_physics_interpolation_quality, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_physics_interpolation_quality(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_physics_interpolation_quality, ctx, this_val, argc, argv);
}
static JSValue multi_mesh_class_set_instance_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_instance_transform, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_set_instance_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_instance_transform_2d, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_instance_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_instance_transform, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_instance_transform_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_instance_transform_2d, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_set_instance_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_instance_color, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_instance_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_instance_color, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_set_instance_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_instance_custom_data, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_instance_custom_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_instance_custom_data, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_reset_instance_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::reset_instance_physics_interpolation, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_custom_aabb, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<AABB> *proxy = memnew(ObjectProxy<AABB>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> AABB {
		MultiMesh *obj = static_cast<MultiMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_custom_aabb();
	};
	proxy->setter = [this_val](const AABB &value) -> void {
		MultiMesh *js_proxy = static_cast<MultiMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_custom_aabb(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["AABBProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "AABBProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue multi_mesh_class_get_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiMesh::get_aabb, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_get_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat32Array> *proxy = memnew(ObjectProxy<PackedFloat32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat32Array {
		MultiMesh *obj = static_cast<MultiMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_buffer();
	};
	proxy->setter = [this_val](const PackedFloat32Array &value) -> void {
		MultiMesh *js_proxy = static_cast<MultiMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_buffer(PackedFloat32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue multi_mesh_class_set_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_buffer, ctx, this_val, argc, argv);
};
static JSValue multi_mesh_class_set_buffer_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiMesh::set_buffer_interpolated, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry multi_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mesh", 1, &multi_mesh_class_set_mesh),
	JS_CFUNC_DEF("get_mesh", 0, &multi_mesh_class_get_mesh),
	JS_CFUNC_DEF("set_use_colors", 1, &multi_mesh_class_set_use_colors),
	JS_CFUNC_DEF("is_using_colors", 0, &multi_mesh_class_is_using_colors),
	JS_CFUNC_DEF("set_use_custom_data", 1, &multi_mesh_class_set_use_custom_data),
	JS_CFUNC_DEF("is_using_custom_data", 0, &multi_mesh_class_is_using_custom_data),
	JS_CFUNC_DEF("set_transform_format", 1, &multi_mesh_class_set_transform_format),
	JS_CFUNC_DEF("get_transform_format", 0, &multi_mesh_class_get_transform_format),
	JS_CFUNC_DEF("set_instance_count", 1, &multi_mesh_class_set_instance_count),
	JS_CFUNC_DEF("get_instance_count", 0, &multi_mesh_class_get_instance_count),
	JS_CFUNC_DEF("set_visible_instance_count", 1, &multi_mesh_class_set_visible_instance_count),
	JS_CFUNC_DEF("get_visible_instance_count", 0, &multi_mesh_class_get_visible_instance_count),
	JS_CFUNC_DEF("set_physics_interpolation_quality", 1, &multi_mesh_class_set_physics_interpolation_quality),
	JS_CFUNC_DEF("get_physics_interpolation_quality", 0, &multi_mesh_class_get_physics_interpolation_quality),
	JS_CFUNC_DEF("set_instance_transform", 2, &multi_mesh_class_set_instance_transform),
	JS_CFUNC_DEF("set_instance_transform_2d", 2, &multi_mesh_class_set_instance_transform_2d),
	JS_CFUNC_DEF("get_instance_transform", 1, &multi_mesh_class_get_instance_transform),
	JS_CFUNC_DEF("get_instance_transform_2d", 1, &multi_mesh_class_get_instance_transform_2d),
	JS_CFUNC_DEF("set_instance_color", 2, &multi_mesh_class_set_instance_color),
	JS_CFUNC_DEF("get_instance_color", 1, &multi_mesh_class_get_instance_color),
	JS_CFUNC_DEF("set_instance_custom_data", 2, &multi_mesh_class_set_instance_custom_data),
	JS_CFUNC_DEF("get_instance_custom_data", 1, &multi_mesh_class_get_instance_custom_data),
	JS_CFUNC_DEF("reset_instance_physics_interpolation", 1, &multi_mesh_class_reset_instance_physics_interpolation),
	JS_CFUNC_DEF("set_custom_aabb", 1, &multi_mesh_class_set_custom_aabb),
	JS_CFUNC_DEF("get_custom_aabb", 0, &multi_mesh_class_get_custom_aabb),
	JS_CFUNC_DEF("get_aabb", 0, &multi_mesh_class_get_aabb),
	JS_CFUNC_DEF("get_buffer", 0, &multi_mesh_class_get_buffer),
	JS_CFUNC_DEF("set_buffer", 1, &multi_mesh_class_set_buffer),
	JS_CFUNC_DEF("set_buffer_interpolated", 2, &multi_mesh_class_set_buffer_interpolated),
};




static void define_multi_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform_format"),
        JS_NewCFunction(ctx, multi_mesh_class_get_transform_format, "get_transform_format", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_transform_format, "set_transform_format", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_colors"),
        JS_NewCFunction(ctx, multi_mesh_class_is_using_colors, "is_using_colors", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_use_colors, "set_use_colors", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_custom_data"),
        JS_NewCFunction(ctx, multi_mesh_class_is_using_custom_data, "is_using_custom_data", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_use_custom_data, "set_use_custom_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_aabb"),
        JS_NewCFunction(ctx, multi_mesh_class_get_custom_aabb, "get_custom_aabb", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_custom_aabb, "set_custom_aabb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "instance_count"),
        JS_NewCFunction(ctx, multi_mesh_class_get_instance_count, "get_instance_count", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_instance_count, "set_instance_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible_instance_count"),
        JS_NewCFunction(ctx, multi_mesh_class_get_visible_instance_count, "get_visible_instance_count", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_visible_instance_count, "set_visible_instance_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh"),
        JS_NewCFunction(ctx, multi_mesh_class_get_mesh, "get_mesh", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_mesh, "set_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer"),
        JS_NewCFunction(ctx, multi_mesh_class_get_buffer, "get_buffer", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_buffer, "set_buffer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "physics_interpolation_quality"),
        JS_NewCFunction(ctx, multi_mesh_class_get_physics_interpolation_quality, "get_physics_interpolation_quality", 0),
        JS_NewCFunction(ctx, multi_mesh_class_set_physics_interpolation_quality, "set_physics_interpolation_quality", 1),
        JS_PROP_GETSET
    );
}

static void define_multi_mesh_enum(JSContext *ctx, JSValue ctor) {
	JSValue TransformFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransformFormat_obj, "TRANSFORM_2D", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TransformFormat_obj, "TRANSFORM_3D", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "TransformFormat", TransformFormat_obj);
	JSValue PhysicsInterpolationQuality_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PhysicsInterpolationQuality_obj, "INTERP_QUALITY_FAST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PhysicsInterpolationQuality_obj, "INTERP_QUALITY_HIGH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "PhysicsInterpolationQuality", PhysicsInterpolationQuality_obj);
}

static int js_multi_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MultiMesh"] = class_id;
	classes_by_id[class_id] = "MultiMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &multi_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_multi_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, multi_mesh_class_proto_funcs, _countof(multi_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, multi_mesh_class_constructor, "MultiMesh", 0, JS_CFUNC_constructor, 0);
	define_multi_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MultiMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_multi_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_multi_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MultiMesh");
	return m;
}

JSModuleDef *js_init_multi_mesh_module(JSContext *ctx) {
	return _js_init_multi_mesh_module(ctx, "@godot/classes/multi_mesh");
}

void __register_multi_mesh() {
	js_init_multi_mesh_module(js_context());
}

void register_multi_mesh() {
	__register_multi_mesh();
}