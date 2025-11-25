#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/triangle_mesh.hpp>
using namespace godot;

static void triangle_mesh_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TriangleMesh"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef triangle_mesh_class_def = {
    "TriangleMesh",
    triangle_mesh_class_finalizer
};

static JSValue triangle_mesh_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TriangleMesh"];
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
        instance = memnew(TriangleMesh);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue triangle_mesh_class_create_from_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TriangleMesh::create_from_faces, ctx, this_val, argc, argv);
};
static JSValue triangle_mesh_class_get_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TriangleMesh::get_faces, ctx, this_val, argc, argv);
};
static JSValue triangle_mesh_class_intersect_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TriangleMesh::intersect_segment, ctx, this_val, argc, argv);
};
static JSValue triangle_mesh_class_intersect_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TriangleMesh::intersect_ray, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry triangle_mesh_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_from_faces", 1, &triangle_mesh_class_create_from_faces),
	JS_CFUNC_DEF("get_faces", 0, &triangle_mesh_class_get_faces),
	JS_CFUNC_DEF("intersect_segment", 2, &triangle_mesh_class_intersect_segment),
	JS_CFUNC_DEF("intersect_ray", 2, &triangle_mesh_class_intersect_ray),
};




static void define_triangle_mesh_property(JSContext *ctx, JSValue proto) {
}

static void define_triangle_mesh_enum(JSContext *ctx, JSValue ctor) {
}

static int js_triangle_mesh_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TriangleMesh"] = class_id;
	classes_by_id[class_id] = "TriangleMesh";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &triangle_mesh_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_triangle_mesh_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, triangle_mesh_class_proto_funcs, _countof(triangle_mesh_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, triangle_mesh_class_constructor, "TriangleMesh", 0, JS_CFUNC_constructor, 0);
	define_triangle_mesh_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TriangleMesh", ctor);
	ctor_list["TriangleMesh"] = ctor;

	return 0;
}

JSModuleDef *_js_init_triangle_mesh_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_triangle_mesh_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TriangleMesh");
	return m;
}

JSModuleDef *js_init_triangle_mesh_module(JSContext *ctx) {
	return _js_init_triangle_mesh_module(ctx, "@godot/classes/triangle_mesh");
}

void __register_triangle_mesh() {
	js_init_triangle_mesh_module(js_context());
}

void register_triangle_mesh() {
	__register_triangle_mesh();
}