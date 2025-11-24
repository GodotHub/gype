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
	JSClassID class_id = classes["NodePath"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef node_path_class_def = {
	"NodePath",
	node_path_class_finalizer
};

static JSValue node_path_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["NodePath"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	NodePath instance;
	if (argc == 0) {
		instance = NodePath();
	}
	if (argc == 1&&JS_IsString(argv[0])) {
		NodePath v0 = VariantAdapter(argv[0]).get();
		instance = NodePath(v0);
	}
	if (argc == 1&&JS_IsString(argv[0])) {
		String v0 = VariantAdapter(argv[0]).get();
		instance = NodePath(v0);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
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
	classes["NodePath"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "NodePath";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &node_path_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, node_path_class_proto_funcs, _countof(node_path_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, node_path_class_constructor, "NodePath", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "NodePath", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_node_path_module(JSContext *ctx) {
	js_node_path_class_init(ctx);
}

void register_node_path() {
	js_init_node_path_module(js_context());
}

