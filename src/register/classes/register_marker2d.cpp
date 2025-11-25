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
#include <godot_cpp/classes/marker2d.hpp>
using namespace godot;

static void marker2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Marker2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef marker2d_class_def = {
    "Marker2D",
    marker2d_class_finalizer
};

static JSValue marker2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Marker2D"];
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
        instance = memnew(Marker2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue marker2d_class_set_gizmo_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Marker2D::set_gizmo_extents, ctx, this_val, argc, argv);
};
static JSValue marker2d_class_get_gizmo_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Marker2D::get_gizmo_extents, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry marker2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_gizmo_extents", 1, &marker2d_class_set_gizmo_extents),
	JS_CFUNC_DEF("get_gizmo_extents", 0, &marker2d_class_get_gizmo_extents),
};




static void define_marker2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gizmo_extents"),
        JS_NewCFunction(ctx, marker2d_class_get_gizmo_extents, "get_gizmo_extents", 0),
        JS_NewCFunction(ctx, marker2d_class_set_gizmo_extents, "set_gizmo_extents", 1),
        JS_PROP_GETSET
    );
}

static void define_marker2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_marker2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Marker2D"] = class_id;
	classes_by_id[class_id] = "Marker2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &marker2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_marker2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, marker2d_class_proto_funcs, _countof(marker2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, marker2d_class_constructor, "Marker2D", 0, JS_CFUNC_constructor, 0);
	define_marker2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Marker2D", ctor);
	ctor_list["Marker2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_marker2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_marker2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Marker2D");
	return m;
}

JSModuleDef *js_init_marker2d_module(JSContext *ctx) {
	return _js_init_marker2d_module(ctx, "@godot/classes/marker2d");
}

void __register_marker2d() {
	js_init_marker2d_module(js_context());
}

void register_marker2d() {
	__register_marker2d();
}