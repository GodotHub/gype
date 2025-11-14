#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shape2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/segment_shape2d.hpp>
using namespace godot;

static void segment_shape2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SegmentShape2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef segment_shape2d_class_def = {
    "SegmentShape2D",
    segment_shape2d_class_finalizer
};

static JSValue segment_shape2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SegmentShape2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SegmentShape2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SegmentShape2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SegmentShape2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue segment_shape2d_class_set_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SegmentShape2D::set_a, ctx, this_val, argc, argv);
};
static JSValue segment_shape2d_class_get_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		SegmentShape2D *obj = static_cast<SegmentShape2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_a();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		SegmentShape2D *js_proxy = static_cast<SegmentShape2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_a(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue segment_shape2d_class_set_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SegmentShape2D::set_b, ctx, this_val, argc, argv);
};
static JSValue segment_shape2d_class_get_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		SegmentShape2D *obj = static_cast<SegmentShape2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_b();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		SegmentShape2D *js_proxy = static_cast<SegmentShape2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_b(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry segment_shape2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_a", 1, &segment_shape2d_class_set_a),
	JS_CFUNC_DEF("get_a", 0, &segment_shape2d_class_get_a),
	JS_CFUNC_DEF("set_b", 1, &segment_shape2d_class_set_b),
	JS_CFUNC_DEF("get_b", 0, &segment_shape2d_class_get_b),
};




static void define_segment_shape2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "a"),
        JS_NewCFunction(ctx, segment_shape2d_class_get_a, "get_a", 0),
        JS_NewCFunction(ctx, segment_shape2d_class_set_a, "set_a", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "b"),
        JS_NewCFunction(ctx, segment_shape2d_class_get_b, "get_b", 0),
        JS_NewCFunction(ctx, segment_shape2d_class_set_b, "set_b", 1),
        JS_PROP_GETSET
    );
}

static void define_segment_shape2d_enum(JSContext *ctx, JSValue proto) {
}

static int js_segment_shape2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SegmentShape2D"] = class_id;
	classes_by_id[class_id] = "SegmentShape2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &segment_shape2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_segment_shape2d_property(ctx, proto);
	define_segment_shape2d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, segment_shape2d_class_proto_funcs, _countof(segment_shape2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, segment_shape2d_class_constructor, "SegmentShape2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SegmentShape2D", ctor);

	return 0;
}

JSModuleDef *_js_init_segment_shape2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_segment_shape2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SegmentShape2D");
	return m;
}

JSModuleDef *js_init_segment_shape2d_module(JSContext *ctx) {
	return _js_init_segment_shape2d_module(ctx, "@godot/classes/segment_shape2d");
}

void __register_segment_shape2d() {
	js_init_segment_shape2d_module(js_context());
}

void register_segment_shape2d() {
	__register_segment_shape2d();
}