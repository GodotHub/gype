#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/back_buffer_copy.hpp>
using namespace godot;

static void back_buffer_copy_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BackBufferCopy"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef back_buffer_copy_class_def = {
    "BackBufferCopy",
    back_buffer_copy_class_finalizer
};

static JSValue back_buffer_copy_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BackBufferCopy"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BackBufferCopy *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BackBufferCopy *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BackBufferCopy);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue back_buffer_copy_class_set_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BackBufferCopy::set_rect, ctx, this_val, argc, argv);
};
static JSValue back_buffer_copy_class_get_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		BackBufferCopy *obj = static_cast<BackBufferCopy *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_rect();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		BackBufferCopy *js_proxy = static_cast<BackBufferCopy *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_rect(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue back_buffer_copy_class_set_copy_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BackBufferCopy::set_copy_mode, ctx, this_val, argc, argv);
};
static JSValue back_buffer_copy_class_get_copy_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BackBufferCopy::get_copy_mode, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry back_buffer_copy_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_rect", 1, &back_buffer_copy_class_set_rect),
	JS_CFUNC_DEF("get_rect", 0, &back_buffer_copy_class_get_rect),
	JS_CFUNC_DEF("set_copy_mode", 1, &back_buffer_copy_class_set_copy_mode),
	JS_CFUNC_DEF("get_copy_mode", 0, &back_buffer_copy_class_get_copy_mode),
};




static void define_back_buffer_copy_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "copy_mode"),
        JS_NewCFunction(ctx, back_buffer_copy_class_get_copy_mode, "get_copy_mode", 0),
        JS_NewCFunction(ctx, back_buffer_copy_class_set_copy_mode, "set_copy_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rect"),
        JS_NewCFunction(ctx, back_buffer_copy_class_get_rect, "get_rect", 0),
        JS_NewCFunction(ctx, back_buffer_copy_class_set_rect, "set_rect", 1),
        JS_PROP_GETSET
    );
}

static void define_back_buffer_copy_enum(JSContext *ctx, JSValue ctor) {
	JSValue CopyMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CopyMode_obj, "COPY_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CopyMode_obj, "COPY_MODE_RECT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CopyMode_obj, "COPY_MODE_VIEWPORT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "CopyMode", CopyMode_obj);
}

static int js_back_buffer_copy_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BackBufferCopy"] = class_id;
	classes_by_id[class_id] = "BackBufferCopy";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &back_buffer_copy_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_back_buffer_copy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, back_buffer_copy_class_proto_funcs, _countof(back_buffer_copy_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, back_buffer_copy_class_constructor, "BackBufferCopy", 0, JS_CFUNC_constructor, 0);
	define_back_buffer_copy_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BackBufferCopy", ctor);

	return 0;
}

JSModuleDef *_js_init_back_buffer_copy_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_back_buffer_copy_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BackBufferCopy");
	return m;
}

JSModuleDef *js_init_back_buffer_copy_module(JSContext *ctx) {
	return _js_init_back_buffer_copy_module(ctx, "@godot/classes/back_buffer_copy");
}

void __register_back_buffer_copy() {
	js_init_back_buffer_copy_module(js_context());
}

void register_back_buffer_copy() {
	__register_back_buffer_copy();
}