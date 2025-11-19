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
#include <godot_cpp/classes/occluder_polygon2d.hpp>
using namespace godot;

static void occluder_polygon2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OccluderPolygon2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef occluder_polygon2d_class_def = {
    "OccluderPolygon2D",
    occluder_polygon2d_class_finalizer
};

static JSValue occluder_polygon2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OccluderPolygon2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OccluderPolygon2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OccluderPolygon2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OccluderPolygon2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue occluder_polygon2d_class_set_closed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderPolygon2D::set_closed, ctx, this_val, argc, argv);
};
static JSValue occluder_polygon2d_class_is_closed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OccluderPolygon2D::is_closed, ctx, this_val, argc, argv);
}
static JSValue occluder_polygon2d_class_set_cull_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderPolygon2D::set_cull_mode, ctx, this_val, argc, argv);
};
static JSValue occluder_polygon2d_class_get_cull_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OccluderPolygon2D::get_cull_mode, ctx, this_val, argc, argv);
}
static JSValue occluder_polygon2d_class_set_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OccluderPolygon2D::set_polygon, ctx, this_val, argc, argv);
};
static JSValue occluder_polygon2d_class_get_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		OccluderPolygon2D *obj = static_cast<OccluderPolygon2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_polygon();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		OccluderPolygon2D *js_proxy = static_cast<OccluderPolygon2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_polygon(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry occluder_polygon2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_closed", 1, &occluder_polygon2d_class_set_closed),
	JS_CFUNC_DEF("is_closed", 0, &occluder_polygon2d_class_is_closed),
	JS_CFUNC_DEF("set_cull_mode", 1, &occluder_polygon2d_class_set_cull_mode),
	JS_CFUNC_DEF("get_cull_mode", 0, &occluder_polygon2d_class_get_cull_mode),
	JS_CFUNC_DEF("set_polygon", 1, &occluder_polygon2d_class_set_polygon),
	JS_CFUNC_DEF("get_polygon", 0, &occluder_polygon2d_class_get_polygon),
};




static void define_occluder_polygon2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "closed"),
        JS_NewCFunction(ctx, occluder_polygon2d_class_is_closed, "is_closed", 0),
        JS_NewCFunction(ctx, occluder_polygon2d_class_set_closed, "set_closed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cull_mode"),
        JS_NewCFunction(ctx, occluder_polygon2d_class_get_cull_mode, "get_cull_mode", 0),
        JS_NewCFunction(ctx, occluder_polygon2d_class_set_cull_mode, "set_cull_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "polygon"),
        JS_NewCFunction(ctx, occluder_polygon2d_class_get_polygon, "get_polygon", 0),
        JS_NewCFunction(ctx, occluder_polygon2d_class_set_polygon, "set_polygon", 1),
        JS_PROP_GETSET
    );
}

static void define_occluder_polygon2d_enum(JSContext *ctx, JSValue ctor) {
	JSValue CullMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CullMode_obj, "CULL_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CullMode_obj, "CULL_CLOCKWISE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CullMode_obj, "CULL_COUNTER_CLOCKWISE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "CullMode", CullMode_obj);
}

static int js_occluder_polygon2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OccluderPolygon2D"] = class_id;
	classes_by_id[class_id] = "OccluderPolygon2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &occluder_polygon2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_occluder_polygon2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, occluder_polygon2d_class_proto_funcs, _countof(occluder_polygon2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, occluder_polygon2d_class_constructor, "OccluderPolygon2D", 0, JS_CFUNC_constructor, 0);
	define_occluder_polygon2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OccluderPolygon2D", ctor);

	return 0;
}

JSModuleDef *_js_init_occluder_polygon2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_occluder_polygon2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OccluderPolygon2D");
	return m;
}

JSModuleDef *js_init_occluder_polygon2d_module(JSContext *ctx) {
	return _js_init_occluder_polygon2d_module(ctx, "@godot/classes/occluder_polygon2d");
}

void __register_occluder_polygon2d() {
	js_init_occluder_polygon2d_module(js_context());
}

void register_occluder_polygon2d() {
	__register_occluder_polygon2d();
}