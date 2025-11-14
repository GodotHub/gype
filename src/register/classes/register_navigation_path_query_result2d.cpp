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
#include <godot_cpp/classes/navigation_path_query_result2d.hpp>
using namespace godot;

static void navigation_path_query_result2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["NavigationPathQueryResult2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef navigation_path_query_result2d_class_def = {
    "NavigationPathQueryResult2D",
    navigation_path_query_result2d_class_finalizer
};

static JSValue navigation_path_query_result2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["NavigationPathQueryResult2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    NavigationPathQueryResult2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(NavigationPathQueryResult2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue navigation_path_query_result2d_class_set_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryResult2D::set_path, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_result2d_class_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		NavigationPathQueryResult2D *obj = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_path();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		NavigationPathQueryResult2D *js_proxy = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_path(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_path_query_result2d_class_set_path_types(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryResult2D::set_path_types, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_result2d_class_get_path_types(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		NavigationPathQueryResult2D *obj = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_path_types();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		NavigationPathQueryResult2D *js_proxy = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_path_types(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_path_query_result2d_class_set_path_rids(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryResult2D::set_path_rids, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_result2d_class_get_path_rids(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryResult2D::get_path_rids, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_result2d_class_set_path_owner_ids(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryResult2D::set_path_owner_ids, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_result2d_class_get_path_owner_ids(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt64Array> *proxy = memnew(ObjectProxy<PackedInt64Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt64Array {
		NavigationPathQueryResult2D *obj = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_path_owner_ids();
	};
	proxy->setter = [this_val](const PackedInt64Array &value) -> void {
		NavigationPathQueryResult2D *js_proxy = static_cast<NavigationPathQueryResult2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_path_owner_ids(PackedInt64Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt64ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt64ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue navigation_path_query_result2d_class_set_path_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryResult2D::set_path_length, ctx, this_val, argc, argv);
};
static JSValue navigation_path_query_result2d_class_get_path_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&NavigationPathQueryResult2D::get_path_length, ctx, this_val, argc, argv);
}
static JSValue navigation_path_query_result2d_class_reset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&NavigationPathQueryResult2D::reset, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry navigation_path_query_result2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_path", 1, &navigation_path_query_result2d_class_set_path),
	JS_CFUNC_DEF("get_path", 0, &navigation_path_query_result2d_class_get_path),
	JS_CFUNC_DEF("set_path_types", 1, &navigation_path_query_result2d_class_set_path_types),
	JS_CFUNC_DEF("get_path_types", 0, &navigation_path_query_result2d_class_get_path_types),
	JS_CFUNC_DEF("set_path_rids", 1, &navigation_path_query_result2d_class_set_path_rids),
	JS_CFUNC_DEF("get_path_rids", 0, &navigation_path_query_result2d_class_get_path_rids),
	JS_CFUNC_DEF("set_path_owner_ids", 1, &navigation_path_query_result2d_class_set_path_owner_ids),
	JS_CFUNC_DEF("get_path_owner_ids", 0, &navigation_path_query_result2d_class_get_path_owner_ids),
	JS_CFUNC_DEF("set_path_length", 1, &navigation_path_query_result2d_class_set_path_length),
	JS_CFUNC_DEF("get_path_length", 0, &navigation_path_query_result2d_class_get_path_length),
	JS_CFUNC_DEF("reset", 0, &navigation_path_query_result2d_class_reset),
};




static void define_navigation_path_query_result2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path"),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_get_path, "get_path", 0),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_set_path, "set_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_types"),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_get_path_types, "get_path_types", 0),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_set_path_types, "set_path_types", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_rids"),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_get_path_rids, "get_path_rids", 0),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_set_path_rids, "set_path_rids", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_owner_ids"),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_get_path_owner_ids, "get_path_owner_ids", 0),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_set_path_owner_ids, "set_path_owner_ids", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "path_length"),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_get_path_length, "get_path_length", 0),
        JS_NewCFunction(ctx, navigation_path_query_result2d_class_set_path_length, "set_path_length", 1),
        JS_PROP_GETSET
    );
}

static void define_navigation_path_query_result2d_enum(JSContext *ctx, JSValue proto) {
	JSValue PathSegmentType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PathSegmentType_obj, "PATH_SEGMENT_TYPE_REGION", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PathSegmentType_obj, "PATH_SEGMENT_TYPE_LINK", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "PathSegmentType", PathSegmentType_obj);
}

static int js_navigation_path_query_result2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["NavigationPathQueryResult2D"] = class_id;
	classes_by_id[class_id] = "NavigationPathQueryResult2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &navigation_path_query_result2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_navigation_path_query_result2d_property(ctx, proto);
	define_navigation_path_query_result2d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, navigation_path_query_result2d_class_proto_funcs, _countof(navigation_path_query_result2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, navigation_path_query_result2d_class_constructor, "NavigationPathQueryResult2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "NavigationPathQueryResult2D", ctor);

	return 0;
}

JSModuleDef *_js_init_navigation_path_query_result2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_navigation_path_query_result2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "NavigationPathQueryResult2D");
	return m;
}

JSModuleDef *js_init_navigation_path_query_result2d_module(JSContext *ctx) {
	return _js_init_navigation_path_query_result2d_module(ctx, "@godot/classes/navigation_path_query_result2d");
}

void __register_navigation_path_query_result2d() {
	js_init_navigation_path_query_result2d_module(js_context());
}

void register_navigation_path_query_result2d() {
	__register_navigation_path_query_result2d();
}