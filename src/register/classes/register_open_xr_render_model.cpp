#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_render_model.hpp>
using namespace godot;

static void open_xr_render_model_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRRenderModel"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_render_model_class_def = {
    "OpenXRRenderModel",
    open_xr_render_model_class_finalizer
};

static JSValue open_xr_render_model_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRRenderModel"];
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
        instance = memnew(OpenXRRenderModel);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_render_model_class_get_top_level_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRRenderModel::get_top_level_path, ctx, this_val, argc, argv);
};
static JSValue open_xr_render_model_class_get_render_model(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		OpenXRRenderModel *obj = static_cast<OpenXRRenderModel *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_render_model();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		OpenXRRenderModel *js_proxy = static_cast<OpenXRRenderModel *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_render_model(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue open_xr_render_model_class_set_render_model(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRRenderModel::set_render_model, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_render_model_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_top_level_path", 0, &open_xr_render_model_class_get_top_level_path),
	JS_CFUNC_DEF("get_render_model", 0, &open_xr_render_model_class_get_render_model),
	JS_CFUNC_DEF("set_render_model", 1, &open_xr_render_model_class_set_render_model),
};


static JSValue open_xr_render_model_class_get_render_model_top_level_path_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "render_model_top_level_path_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_open_xr_render_model_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_model"),
        JS_NewCFunction(ctx, open_xr_render_model_class_get_render_model, "get_render_model", 0),
        JS_NewCFunction(ctx, open_xr_render_model_class_set_render_model, "set_render_model", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "render_model_top_level_path_changed"),
		JS_NewCFunction(ctx, open_xr_render_model_class_get_render_model_top_level_path_changed_signal, "get_render_model_top_level_path_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_open_xr_render_model_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_render_model_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRRenderModel"] = class_id;
	classes_by_id[class_id] = "OpenXRRenderModel";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_render_model_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_render_model_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_render_model_class_proto_funcs, _countof(open_xr_render_model_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_render_model_class_constructor, "OpenXRRenderModel", 0, JS_CFUNC_constructor, 0);
	define_open_xr_render_model_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRRenderModel", ctor);
	ctor_list["OpenXRRenderModel"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_render_model_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_render_model_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRRenderModel");
	return m;
}

JSModuleDef *js_init_open_xr_render_model_module(JSContext *ctx) {
	return _js_init_open_xr_render_model_module(ctx, "@godot/classes/open_xr_render_model");
}

void __register_open_xr_render_model() {
	js_init_open_xr_render_model_module(js_context());
}

void register_open_xr_render_model() {
	__register_open_xr_render_model();
}