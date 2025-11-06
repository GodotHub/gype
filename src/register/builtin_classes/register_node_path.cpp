#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/string_name.hpp>


using namespace godot;

static void node_path_class_finalizer(JSRuntime *rt, JSValue val) {
	// 处于栈内存的变量不需要释放,除了对象
}

static JSClassDef node_path_class_def = {
	"NodePath",
	.finalizer = node_path_class_finalizer
};

static JSValue node_path_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["NodePath"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	NodePath *instance = nullptr;
	if (argc == 0) {
		instance = memnew(NodePath());
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::NODE_PATH))) {
		NodePath v0 = VariantAdapter(argv[0]).get();
		instance = memnew(NodePath(v0));
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::STRING))) {
		String v0 = VariantAdapter(argv[0]).get();
		instance = memnew(NodePath(v0));
	}
	VariantAdapter *adapter = memnew(VariantAdapter(*instance, true));

	if (!instance || !adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue node_path_class_is_absolute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::is_absolute, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_name_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_name_count, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_name, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_subname_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_subname_count, ctx, this_val, argc, argv);
}
static JSValue node_path_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::hash, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_subname(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_subname, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_concatenated_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_concatenated_names, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_concatenated_subnames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_concatenated_subnames, ctx, this_val, argc, argv);
}
static JSValue node_path_class_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::slice, ctx, this_val, argc, argv);
}
static JSValue node_path_class_get_as_property_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::get_as_property_path, ctx, this_val, argc, argv);
}
static JSValue node_path_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&NodePath::is_empty, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry node_path_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_absolute", 0, &node_path_class_is_absolute),
	JS_CFUNC_DEF("get_name_count", 0, &node_path_class_get_name_count),
	JS_CFUNC_DEF("get_name", 1, &node_path_class_get_name),
	JS_CFUNC_DEF("get_subname_count", 0, &node_path_class_get_subname_count),
	JS_CFUNC_DEF("hash", 0, &node_path_class_hash),
	JS_CFUNC_DEF("get_subname", 1, &node_path_class_get_subname),
	JS_CFUNC_DEF("get_concatenated_names", 0, &node_path_class_get_concatenated_names),
	JS_CFUNC_DEF("get_concatenated_subnames", 0, &node_path_class_get_concatenated_subnames),
	JS_CFUNC_DEF("slice", 2, &node_path_class_slice),
	JS_CFUNC_DEF("get_as_property_path", 0, &node_path_class_get_as_property_path),
	JS_CFUNC_DEF("is_empty", 0, &node_path_class_is_empty),
};


static int js_node_path_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["NodePath"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "NodePath";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &node_path_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, node_path_class_proto_funcs, _countof(node_path_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, node_path_class_constructor, "NodePath", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "NodePath", ctor);

	return 0;
}

void js_init_node_path_module(JSContext *ctx) {
	js_node_path_class_init(ctx);
}

void register_node_path() {
	js_init_node_path_module(js_context());
}

// ------------------NodePathProxy------------------
static void node_path_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["NodePathProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<NodePath> *>(proxy));
	}
}

static JSClassDef node_path_proxy_def = {
	"NodePathProxy",
	.finalizer = node_path_proxy_finalizer
};


static JSValue node_path_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["NodePathProxy"];
	JSValue proto = JS_GetPropertyStr(js_context(), new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(js_context(), proto, class_id);
	if (is_exception(js_context(), obj)) {
		return obj;
	}

	ObjectProxy<NodePath> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<NodePath> *>(JS_GetAnyOpaque(*argv, &opaque_id));
	} else {
		return JS_EXCEPTION;
	}

	if (!proxy) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	return obj;
}

static JSValue node_path_proxy_is_absolute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::is_absolute, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_name_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_name_count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_name, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_subname_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_subname_count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::hash, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_subname(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_subname, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_concatenated_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_concatenated_names, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_concatenated_subnames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_concatenated_subnames, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::slice, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_get_as_property_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::get_as_property_path, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue node_path_proxy_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["NodePathProxy"]);
    ObjectProxy<NodePath> *proxy = reinterpret_cast<ObjectProxy<NodePath> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&NodePath::is_empty, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}


static const JSCFunctionListEntry node_path_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("is_absolute", 0, &node_path_proxy_is_absolute),
	JS_CFUNC_DEF("get_name_count", 0, &node_path_proxy_get_name_count),
	JS_CFUNC_DEF("get_name", 1, &node_path_proxy_get_name),
	JS_CFUNC_DEF("get_subname_count", 0, &node_path_proxy_get_subname_count),
	JS_CFUNC_DEF("hash", 0, &node_path_proxy_hash),
	JS_CFUNC_DEF("get_subname", 1, &node_path_proxy_get_subname),
	JS_CFUNC_DEF("get_concatenated_names", 0, &node_path_proxy_get_concatenated_names),
	JS_CFUNC_DEF("get_concatenated_subnames", 0, &node_path_proxy_get_concatenated_subnames),
	JS_CFUNC_DEF("slice", 2, &node_path_proxy_slice),
	JS_CFUNC_DEF("get_as_property_path", 0, &node_path_proxy_get_as_property_path),
	JS_CFUNC_DEF("is_empty", 0, &node_path_proxy_is_empty),
};


static int js_node_path_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["NodePathProxy"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "NodePathProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &node_path_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, node_path_proxy_proto_funcs, _countof(node_path_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, node_path_proxy_constructor, "NodePathProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "NodePathProxy", ctor);

	return 0;
}

void js_init_node_path_proxy_module(JSContext *ctx) {
	js_node_path_proxy_init(ctx);
}

void register_proxy_node_path() {
	js_init_node_path_proxy_module(js_context());
}