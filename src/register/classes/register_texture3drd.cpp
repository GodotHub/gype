#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/texture3drd.hpp>
using namespace godot;

static void texture3drd_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Texture3DRD"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef texture3drd_class_def = {
    "Texture3DRD",
    texture3drd_class_finalizer
};

static JSValue texture3drd_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Texture3DRD"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Texture3DRD *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Texture3DRD *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Texture3DRD);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue texture3drd_class_set_texture_rd_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Texture3DRD::set_texture_rd_rid, ctx, this_val, argc, argv);
};
static JSValue texture3drd_class_get_texture_rd_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		Texture3DRD *obj = static_cast<Texture3DRD *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_texture_rd_rid();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		Texture3DRD *js_proxy = static_cast<Texture3DRD *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_texture_rd_rid(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry texture3drd_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture_rd_rid", 1, &texture3drd_class_set_texture_rd_rid),
	JS_CFUNC_DEF("get_texture_rd_rid", 0, &texture3drd_class_get_texture_rd_rid),
};




static void define_texture3drd_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_rd_rid"),
        JS_NewCFunction(ctx, texture3drd_class_get_texture_rd_rid, "get_texture_rd_rid", 0),
        JS_NewCFunction(ctx, texture3drd_class_set_texture_rd_rid, "set_texture_rd_rid", 1),
        JS_PROP_GETSET
    );
}

static void define_texture3drd_enum(JSContext *ctx, JSValue ctor) {
}

static int js_texture3drd_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Texture3DRD"] = class_id;
	classes_by_id[class_id] = "Texture3DRD";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &texture3drd_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_texture3drd_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, texture3drd_class_proto_funcs, _countof(texture3drd_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, texture3drd_class_constructor, "Texture3DRD", 0, JS_CFUNC_constructor, 0);
	define_texture3drd_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Texture3DRD", ctor);

	return 0;
}

JSModuleDef *_js_init_texture3drd_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_texture3drd_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Texture3DRD");
	return m;
}

JSModuleDef *js_init_texture3drd_module(JSContext *ctx) {
	return _js_init_texture3drd_module(ctx, "@godot/classes/texture3drd");
}

void __register_texture3drd() {
	js_init_texture3drd_module(js_context());
}

void register_texture3drd() {
	__register_texture3drd();
}