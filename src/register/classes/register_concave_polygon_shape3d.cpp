#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/concave_polygon_shape3d.hpp>
using namespace godot;

static void concave_polygon_shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ConcavePolygonShape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef concave_polygon_shape3d_class_def = {
    "ConcavePolygonShape3D",
    concave_polygon_shape3d_class_finalizer
};

static JSValue concave_polygon_shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ConcavePolygonShape3D"];
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
        instance = memnew(ConcavePolygonShape3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue concave_polygon_shape3d_class_set_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConcavePolygonShape3D::set_faces, ctx, this_val, argc, argv);
};
static JSValue concave_polygon_shape3d_class_get_faces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector3Array> *proxy = memnew(ObjectProxy<PackedVector3Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector3Array {
		ConcavePolygonShape3D *obj = static_cast<ConcavePolygonShape3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_faces();
	};
	proxy->setter = [this_val](const PackedVector3Array &value) -> void {
		ConcavePolygonShape3D *js_proxy = static_cast<ConcavePolygonShape3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_faces(PackedVector3Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector3ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector3ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue concave_polygon_shape3d_class_set_backface_collision_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConcavePolygonShape3D::set_backface_collision_enabled, ctx, this_val, argc, argv);
};
static JSValue concave_polygon_shape3d_class_is_backface_collision_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConcavePolygonShape3D::is_backface_collision_enabled, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry concave_polygon_shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_faces", 1, &concave_polygon_shape3d_class_set_faces),
	JS_CFUNC_DEF("get_faces", 0, &concave_polygon_shape3d_class_get_faces),
	JS_CFUNC_DEF("set_backface_collision_enabled", 1, &concave_polygon_shape3d_class_set_backface_collision_enabled),
	JS_CFUNC_DEF("is_backface_collision_enabled", 0, &concave_polygon_shape3d_class_is_backface_collision_enabled),
};




static void define_concave_polygon_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "data"),
        JS_NewCFunction(ctx, concave_polygon_shape3d_class_get_faces, "get_faces", 0),
        JS_NewCFunction(ctx, concave_polygon_shape3d_class_set_faces, "set_faces", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "backface_collision"),
        JS_NewCFunction(ctx, concave_polygon_shape3d_class_is_backface_collision_enabled, "is_backface_collision_enabled", 0),
        JS_NewCFunction(ctx, concave_polygon_shape3d_class_set_backface_collision_enabled, "set_backface_collision_enabled", 1),
        JS_PROP_GETSET
    );
}

static void define_concave_polygon_shape3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_concave_polygon_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ConcavePolygonShape3D"] = class_id;
	classes_by_id[class_id] = "ConcavePolygonShape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &concave_polygon_shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_concave_polygon_shape3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, concave_polygon_shape3d_class_proto_funcs, _countof(concave_polygon_shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, concave_polygon_shape3d_class_constructor, "ConcavePolygonShape3D", 0, JS_CFUNC_constructor, 0);
	define_concave_polygon_shape3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ConcavePolygonShape3D", ctor);
	ctor_list["ConcavePolygonShape3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_concave_polygon_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_concave_polygon_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ConcavePolygonShape3D");
	return m;
}

JSModuleDef *js_init_concave_polygon_shape3d_module(JSContext *ctx) {
	return _js_init_concave_polygon_shape3d_module(ctx, "@godot/classes/concave_polygon_shape3d");
}

void __register_concave_polygon_shape3d() {
	js_init_concave_polygon_shape3d_module(js_context());
}

void register_concave_polygon_shape3d() {
	__register_concave_polygon_shape3d();
}