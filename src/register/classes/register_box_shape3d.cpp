#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/box_shape3d.hpp>
using namespace godot;

static void box_shape3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BoxShape3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef box_shape3d_class_def = {
    "BoxShape3D",
    box_shape3d_class_finalizer
};

static JSValue box_shape3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BoxShape3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BoxShape3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BoxShape3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BoxShape3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue box_shape3d_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxShape3D::set_size, ctx, this_val, argc, argv);
};
static JSValue box_shape3d_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		BoxShape3D *obj = static_cast<BoxShape3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		BoxShape3D *js_proxy = static_cast<BoxShape3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry box_shape3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &box_shape3d_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &box_shape3d_class_get_size),
};




static void define_box_shape3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, box_shape3d_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, box_shape3d_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
}

static void define_box_shape3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_box_shape3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BoxShape3D"] = class_id;
	classes_by_id[class_id] = "BoxShape3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &box_shape3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Shape3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_box_shape3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, box_shape3d_class_proto_funcs, _countof(box_shape3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, box_shape3d_class_constructor, "BoxShape3D", 0, JS_CFUNC_constructor, 0);
	define_box_shape3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BoxShape3D", ctor);

	return 0;
}

JSModuleDef *_js_init_box_shape3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/shape3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_box_shape3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BoxShape3D");
	return m;
}

JSModuleDef *js_init_box_shape3d_module(JSContext *ctx) {
	return _js_init_box_shape3d_module(ctx, "@godot/classes/box_shape3d");
}

void __register_box_shape3d() {
	js_init_box_shape3d_module(js_context());
}

void register_box_shape3d() {
	__register_box_shape3d();
}