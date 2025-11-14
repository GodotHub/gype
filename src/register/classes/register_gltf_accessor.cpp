#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_accessor.hpp>
using namespace godot;

static void gltf_accessor_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFAccessor"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_accessor_class_def = {
    "GLTFAccessor",
    gltf_accessor_class_finalizer
};

static JSValue gltf_accessor_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFAccessor"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFAccessor *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFAccessor *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFAccessor);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_accessor_class_get_buffer_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_buffer_view, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_buffer_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_buffer_view, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_byte_offset, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_byte_offset, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_component_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_component_type, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_component_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_component_type, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_normalized, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_normalized, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_count, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_count, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_accessor_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_accessor_type, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_accessor_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_accessor_type, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_type, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_type, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat64Array> *proxy = memnew(ObjectProxy<PackedFloat64Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat64Array {
		GLTFAccessor *obj = static_cast<GLTFAccessor *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_min();
	};
	proxy->setter = [this_val](const PackedFloat64Array &value) -> void {
		GLTFAccessor *js_proxy = static_cast<GLTFAccessor *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_min(PackedFloat64Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat64ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat64ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_accessor_class_set_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_min, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat64Array> *proxy = memnew(ObjectProxy<PackedFloat64Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat64Array {
		GLTFAccessor *obj = static_cast<GLTFAccessor *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_max();
	};
	proxy->setter = [this_val](const PackedFloat64Array &value) -> void {
		GLTFAccessor *js_proxy = static_cast<GLTFAccessor *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_max(PackedFloat64Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat64ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat64ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gltf_accessor_class_set_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_max, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_sparse_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_sparse_count, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_sparse_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_sparse_count, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_sparse_indices_buffer_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_sparse_indices_buffer_view, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_sparse_indices_buffer_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_sparse_indices_buffer_view, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_sparse_indices_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_sparse_indices_byte_offset, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_sparse_indices_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_sparse_indices_byte_offset, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_sparse_indices_component_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_sparse_indices_component_type, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_sparse_indices_component_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_sparse_indices_component_type, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_sparse_values_buffer_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_sparse_values_buffer_view, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_sparse_values_buffer_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_sparse_values_buffer_view, ctx, this_val, argc, argv);
};
static JSValue gltf_accessor_class_get_sparse_values_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFAccessor::get_sparse_values_byte_offset, ctx, this_val, argc, argv);
}
static JSValue gltf_accessor_class_set_sparse_values_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFAccessor::set_sparse_values_byte_offset, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gltf_accessor_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_buffer_view", 0, &gltf_accessor_class_get_buffer_view),
	JS_CFUNC_DEF("set_buffer_view", 1, &gltf_accessor_class_set_buffer_view),
	JS_CFUNC_DEF("get_byte_offset", 0, &gltf_accessor_class_get_byte_offset),
	JS_CFUNC_DEF("set_byte_offset", 1, &gltf_accessor_class_set_byte_offset),
	JS_CFUNC_DEF("get_component_type", 0, &gltf_accessor_class_get_component_type),
	JS_CFUNC_DEF("set_component_type", 1, &gltf_accessor_class_set_component_type),
	JS_CFUNC_DEF("get_normalized", 0, &gltf_accessor_class_get_normalized),
	JS_CFUNC_DEF("set_normalized", 1, &gltf_accessor_class_set_normalized),
	JS_CFUNC_DEF("get_count", 0, &gltf_accessor_class_get_count),
	JS_CFUNC_DEF("set_count", 1, &gltf_accessor_class_set_count),
	JS_CFUNC_DEF("get_accessor_type", 0, &gltf_accessor_class_get_accessor_type),
	JS_CFUNC_DEF("set_accessor_type", 1, &gltf_accessor_class_set_accessor_type),
	JS_CFUNC_DEF("get_type", 0, &gltf_accessor_class_get_type),
	JS_CFUNC_DEF("set_type", 1, &gltf_accessor_class_set_type),
	JS_CFUNC_DEF("get_min", 0, &gltf_accessor_class_get_min),
	JS_CFUNC_DEF("set_min", 1, &gltf_accessor_class_set_min),
	JS_CFUNC_DEF("get_max", 0, &gltf_accessor_class_get_max),
	JS_CFUNC_DEF("set_max", 1, &gltf_accessor_class_set_max),
	JS_CFUNC_DEF("get_sparse_count", 0, &gltf_accessor_class_get_sparse_count),
	JS_CFUNC_DEF("set_sparse_count", 1, &gltf_accessor_class_set_sparse_count),
	JS_CFUNC_DEF("get_sparse_indices_buffer_view", 0, &gltf_accessor_class_get_sparse_indices_buffer_view),
	JS_CFUNC_DEF("set_sparse_indices_buffer_view", 1, &gltf_accessor_class_set_sparse_indices_buffer_view),
	JS_CFUNC_DEF("get_sparse_indices_byte_offset", 0, &gltf_accessor_class_get_sparse_indices_byte_offset),
	JS_CFUNC_DEF("set_sparse_indices_byte_offset", 1, &gltf_accessor_class_set_sparse_indices_byte_offset),
	JS_CFUNC_DEF("get_sparse_indices_component_type", 0, &gltf_accessor_class_get_sparse_indices_component_type),
	JS_CFUNC_DEF("set_sparse_indices_component_type", 1, &gltf_accessor_class_set_sparse_indices_component_type),
	JS_CFUNC_DEF("get_sparse_values_buffer_view", 0, &gltf_accessor_class_get_sparse_values_buffer_view),
	JS_CFUNC_DEF("set_sparse_values_buffer_view", 1, &gltf_accessor_class_set_sparse_values_buffer_view),
	JS_CFUNC_DEF("get_sparse_values_byte_offset", 0, &gltf_accessor_class_get_sparse_values_byte_offset),
	JS_CFUNC_DEF("set_sparse_values_byte_offset", 1, &gltf_accessor_class_set_sparse_values_byte_offset),
};




static void define_gltf_accessor_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer_view"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_buffer_view, "get_buffer_view", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_buffer_view, "set_buffer_view", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "byte_offset"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_byte_offset, "get_byte_offset", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_byte_offset, "set_byte_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "component_type"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_component_type, "get_component_type", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_component_type, "set_component_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "normalized"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_normalized, "get_normalized", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_normalized, "set_normalized", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "count"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_count, "get_count", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_count, "set_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessor_type"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_accessor_type, "get_accessor_type", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_accessor_type, "set_accessor_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "type"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_type, "get_type", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_type, "set_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "min"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_min, "get_min", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_min, "set_min", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_max, "get_max", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_max, "set_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sparse_count"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_sparse_count, "get_sparse_count", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_sparse_count, "set_sparse_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sparse_indices_buffer_view"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_sparse_indices_buffer_view, "get_sparse_indices_buffer_view", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_sparse_indices_buffer_view, "set_sparse_indices_buffer_view", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sparse_indices_byte_offset"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_sparse_indices_byte_offset, "get_sparse_indices_byte_offset", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_sparse_indices_byte_offset, "set_sparse_indices_byte_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sparse_indices_component_type"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_sparse_indices_component_type, "get_sparse_indices_component_type", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_sparse_indices_component_type, "set_sparse_indices_component_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sparse_values_buffer_view"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_sparse_values_buffer_view, "get_sparse_values_buffer_view", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_sparse_values_buffer_view, "set_sparse_values_buffer_view", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sparse_values_byte_offset"),
        JS_NewCFunction(ctx, gltf_accessor_class_get_sparse_values_byte_offset, "get_sparse_values_byte_offset", 0),
        JS_NewCFunction(ctx, gltf_accessor_class_set_sparse_values_byte_offset, "set_sparse_values_byte_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_accessor_enum(JSContext *ctx, JSValue proto) {
	JSValue GLTFAccessorType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_SCALAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_VEC2", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_VEC3", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_VEC4", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_MAT2", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_MAT3", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, GLTFAccessorType_obj, "TYPE_MAT4", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, proto, "GLTFAccessorType", GLTFAccessorType_obj);
	JSValue GLTFComponentType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_SIGNED_BYTE", JS_NewInt64(ctx, 5120));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_UNSIGNED_BYTE", JS_NewInt64(ctx, 5121));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_SIGNED_SHORT", JS_NewInt64(ctx, 5122));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_UNSIGNED_SHORT", JS_NewInt64(ctx, 5123));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_SIGNED_INT", JS_NewInt64(ctx, 5124));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_UNSIGNED_INT", JS_NewInt64(ctx, 5125));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_SINGLE_FLOAT", JS_NewInt64(ctx, 5126));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_DOUBLE_FLOAT", JS_NewInt64(ctx, 5130));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_HALF_FLOAT", JS_NewInt64(ctx, 5131));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_SIGNED_LONG", JS_NewInt64(ctx, 5134));
	JS_SetPropertyStr(ctx, GLTFComponentType_obj, "COMPONENT_TYPE_UNSIGNED_LONG", JS_NewInt64(ctx, 5135));
	JS_SetPropertyStr(ctx, proto, "GLTFComponentType", GLTFComponentType_obj);
}

static int js_gltf_accessor_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFAccessor"] = class_id;
	classes_by_id[class_id] = "GLTFAccessor";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_accessor_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_accessor_property(ctx, proto);
	define_gltf_accessor_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_accessor_class_proto_funcs, _countof(gltf_accessor_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_accessor_class_constructor, "GLTFAccessor", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFAccessor", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_accessor_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_accessor_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFAccessor");
	return m;
}

JSModuleDef *js_init_gltf_accessor_module(JSContext *ctx) {
	return _js_init_gltf_accessor_module(ctx, "@godot/classes/gltf_accessor");
}

void __register_gltf_accessor() {
	js_init_gltf_accessor_module(js_context());
}

void register_gltf_accessor() {
	__register_gltf_accessor();
}