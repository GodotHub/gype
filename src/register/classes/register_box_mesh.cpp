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
#include <godot_cpp/classes/box_mesh.hpp>
using namespace godot;

static void box_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BoxMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef box_mesh_class_def = {
    "BoxMesh",
    box_mesh_class_finalizer
};

static JSValue box_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BoxMesh"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BoxMesh *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BoxMesh *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BoxMesh);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue box_mesh_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxMesh::set_size, ctx, this_val, argc, argv);
};
static JSValue box_mesh_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		BoxMesh *obj = static_cast<BoxMesh *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		BoxMesh *js_proxy = static_cast<BoxMesh *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue box_mesh_class_set_subdivide_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxMesh::set_subdivide_width, ctx, this_val, argc, argv);
};
static JSValue box_mesh_class_get_subdivide_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoxMesh::get_subdivide_width, ctx, this_val, argc, argv);
}
static JSValue box_mesh_class_set_subdivide_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxMesh::set_subdivide_height, ctx, this_val, argc, argv);
};
static JSValue box_mesh_class_get_subdivide_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoxMesh::get_subdivide_height, ctx, this_val, argc, argv);
}
static JSValue box_mesh_class_set_subdivide_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxMesh::set_subdivide_depth, ctx, this_val, argc, argv);
};
static JSValue box_mesh_class_get_subdivide_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoxMesh::get_subdivide_depth, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry box_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &box_mesh_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &box_mesh_class_get_size),
	JS_CFUNC_DEF("set_subdivide_width", 1, &box_mesh_class_set_subdivide_width),
	JS_CFUNC_DEF("get_subdivide_width", 0, &box_mesh_class_get_subdivide_width),
	JS_CFUNC_DEF("set_subdivide_height", 1, &box_mesh_class_set_subdivide_height),
	JS_CFUNC_DEF("get_subdivide_height", 0, &box_mesh_class_get_subdivide_height),
	JS_CFUNC_DEF("set_subdivide_depth", 1, &box_mesh_class_set_subdivide_depth),
	JS_CFUNC_DEF("get_subdivide_depth", 0, &box_mesh_class_get_subdivide_depth),
};




static void define_box_mesh_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, box_mesh_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, box_mesh_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subdivide_width"),
        JS_NewCFunction(ctx, box_mesh_class_get_subdivide_width, "get_subdivide_width", 0),
        JS_NewCFunction(ctx, box_mesh_class_set_subdivide_width, "set_subdivide_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subdivide_height"),
        JS_NewCFunction(ctx, box_mesh_class_get_subdivide_height, "get_subdivide_height", 0),
        JS_NewCFunction(ctx, box_mesh_class_set_subdivide_height, "set_subdivide_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subdivide_depth"),
        JS_NewCFunction(ctx, box_mesh_class_get_subdivide_depth, "get_subdivide_depth", 0),
        JS_NewCFunction(ctx, box_mesh_class_set_subdivide_depth, "set_subdivide_depth", 1),
        JS_PROP_GETSET
    );
}

static void define_box_mesh_enum(JSContext *ctx, JSValue proto) {
}

static int js_box_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BoxMesh"] = class_id;
	classes_by_id[class_id] = "BoxMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &box_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PrimitiveMesh"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_box_mesh_property(ctx, proto);
	define_box_mesh_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, box_mesh_class_proto_funcs, _countof(box_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, box_mesh_class_constructor, "BoxMesh", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BoxMesh", ctor);

	return 0;
}

JSModuleDef *_js_init_box_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/primitive_mesh';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_box_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BoxMesh");
	return m;
}

JSModuleDef *js_init_box_mesh_module(JSContext *ctx) {
	return _js_init_box_mesh_module(ctx, "@godot/classes/box_mesh");
}

void __register_box_mesh() {
	js_init_box_mesh_module(js_context());
}

void register_box_mesh() {
	__register_box_mesh();
}