#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>



using namespace godot;

static void rid_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RID"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef rid_class_def = {
	"RID",
	rid_class_finalizer
};

static JSValue rid_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["RID"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	RID instance;
	if (argc == 0) {
		instance = RID();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::RID)) {
		RID v0 = VariantAdapter(argv[0]).get();
		instance = RID(v0);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue rid_class_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RID::is_valid, ctx, this_val, argc, argv);
}
static JSValue rid_class_get_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&RID::get_id, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry rid_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_valid", 0, &rid_class_is_valid),
	JS_CFUNC_DEF("get_id", 0, &rid_class_get_id),
};


static int js_rid_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["RID"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "RID";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &rid_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, rid_class_proto_funcs, _countof(rid_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rid_class_constructor, "RID", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "RID", ctor);

	return 0;
}

static void js_init_rid_module(JSContext *ctx) {
	js_rid_class_init(ctx);
}

void register_rid() {
	js_init_rid_module(js_context());
}

// ------------------RIDProxy------------------
static void rid_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["RIDProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<RID> *>(proxy));
	}
}

static JSClassDef rid_proxy_def = {
	"RIDProxy",
	rid_proxy_finalizer
};


static JSValue rid_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["RIDProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<RID> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<RID> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue rid_proxy_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["RIDProxy"]);
    ObjectProxy<RID> *proxy = static_cast<ObjectProxy<RID> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&RID::is_valid, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rid_proxy_get_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["RIDProxy"]);
    ObjectProxy<RID> *proxy = static_cast<ObjectProxy<RID> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&RID::get_id, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}


static const JSCFunctionListEntry rid_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("is_valid", 0, &rid_proxy_is_valid),
	JS_CFUNC_DEF("get_id", 0, &rid_proxy_get_id),
};


static int js_rid_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["RIDProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "RIDProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &rid_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, rid_proxy_proto_funcs, _countof(rid_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, rid_proxy_constructor, "RIDProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "RIDProxy", ctor);

	return 0;
}

void js_init_rid_proxy_module(JSContext *ctx) {
	js_rid_proxy_init(ctx);
}

void register_proxy_rid() {
	js_init_rid_proxy_module(js_context());
}