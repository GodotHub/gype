#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/texture2drd.hpp>
using namespace godot;

static void texture2drd_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Texture2DRD"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef texture2drd_class_def = {
    "Texture2DRD",
    texture2drd_class_finalizer
};

static JSValue texture2drd_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Texture2DRD"];
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
        instance = memnew(Texture2DRD);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue texture2drd_class_set_texture_rd_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Texture2DRD::set_texture_rd_rid, ctx, this_val, argc, argv);
};
static JSValue texture2drd_class_get_texture_rd_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		Texture2DRD *obj = static_cast<Texture2DRD *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_texture_rd_rid();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		Texture2DRD *js_proxy = static_cast<Texture2DRD *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_texture_rd_rid(value);
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



static const JSCFunctionListEntry texture2drd_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture_rd_rid", 1, &texture2drd_class_set_texture_rd_rid),
	JS_CFUNC_DEF("get_texture_rd_rid", 0, &texture2drd_class_get_texture_rd_rid),
};




static void define_texture2drd_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_rd_rid"),
        JS_NewCFunction(ctx, texture2drd_class_get_texture_rd_rid, "get_texture_rd_rid", 0),
        JS_NewCFunction(ctx, texture2drd_class_set_texture_rd_rid, "set_texture_rd_rid", 1),
        JS_PROP_GETSET
    );
}

static void define_texture2drd_enum(JSContext *ctx, JSValue ctor) {
}

static int js_texture2drd_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Texture2DRD"] = class_id;
	classes_by_id[class_id] = "Texture2DRD";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &texture2drd_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_texture2drd_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, texture2drd_class_proto_funcs, _countof(texture2drd_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, texture2drd_class_constructor, "Texture2DRD", 0, JS_CFUNC_constructor, 0);
	define_texture2drd_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Texture2DRD", ctor);
	ctor_list["Texture2DRD"] = ctor;

	return 0;
}

JSModuleDef *_js_init_texture2drd_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_texture2drd_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Texture2DRD");
	return m;
}

JSModuleDef *js_init_texture2drd_module(JSContext *ctx) {
	return _js_init_texture2drd_module(ctx, "@godot/classes/texture2drd");
}

void __register_texture2drd() {
	js_init_texture2drd_module(js_context());
}

void register_texture2drd() {
	__register_texture2drd();
}