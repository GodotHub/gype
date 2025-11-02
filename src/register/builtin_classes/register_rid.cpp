#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>


using namespace godot;

static void rid_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes[typeid(RID)];
	GDVariantAdapter<RID> *opaque_ptr = static_cast<GDVariantAdapter<RID> *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr && opaque_ptr->can_memfree) {
		memfree(const_cast<RID *>(opaque_ptr->m_active_variant));
	}
}

static JSClassDef rid_class_def = {
	"RID",
	.finalizer = rid_class_finalizer
};

static JSValue rid_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes[typeid(RID)];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}
	
	RID *instance = nullptr;
	GDVariantAdapter<RID> *adapter = reinterpret_cast<GDVariantAdapter<RID> *>(memalloc(sizeof(GDVariantAdapter<RID>)));
	if (argc == 0) {
		instance = reinterpret_cast<RID *>(memalloc(sizeof(RID)));
		instance = new (instance) RID();
	}
	if (argc == 1&&(JSValueAdapter<RID>::can_cast(argv[0]))) {
		RID v0 = *JSValueAdapter<RID>(argv[0]).get();
		instance = reinterpret_cast<RID *>(memalloc(sizeof(RID)));
		instance = new (instance) RID(v0);
	}
	adapter = new (adapter) GDVariantAdapter<RID>(*instance, true);

	if (!instance || !adapter) {
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
	JSClassID class_id = JS_NewClassID(&classes[typeid(RID)]);

	JS_NewClass(JS_GetRuntime(ctx), class_id, &rid_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, rid_class_proto_funcs, _countof(rid_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rid_class_constructor, "RID", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "RID", ctor);

	return 0;
}

void js_init_rid_module(JSContext *ctx) {
	js_rid_class_init(ctx);
}

void register_rid() {
	js_init_rid_module(js_context());
}