#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/joint2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/groove_joint2d.hpp>
using namespace godot;

static void groove_joint2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GrooveJoint2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef groove_joint2d_class_def = {
    "GrooveJoint2D",
    groove_joint2d_class_finalizer
};

static JSValue groove_joint2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GrooveJoint2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GrooveJoint2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GrooveJoint2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GrooveJoint2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue groove_joint2d_class_set_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GrooveJoint2D::set_length, ctx, this_val, argc, argv);
};
static JSValue groove_joint2d_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GrooveJoint2D::get_length, ctx, this_val, argc, argv);
}
static JSValue groove_joint2d_class_set_initial_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GrooveJoint2D::set_initial_offset, ctx, this_val, argc, argv);
};
static JSValue groove_joint2d_class_get_initial_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GrooveJoint2D::get_initial_offset, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry groove_joint2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_length", 1, &groove_joint2d_class_set_length),
	JS_CFUNC_DEF("get_length", 0, &groove_joint2d_class_get_length),
	JS_CFUNC_DEF("set_initial_offset", 1, &groove_joint2d_class_set_initial_offset),
	JS_CFUNC_DEF("get_initial_offset", 0, &groove_joint2d_class_get_initial_offset),
};




static void define_groove_joint2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "length"),
        JS_NewCFunction(ctx, groove_joint2d_class_get_length, "get_length", 0),
        JS_NewCFunction(ctx, groove_joint2d_class_set_length, "set_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "initial_offset"),
        JS_NewCFunction(ctx, groove_joint2d_class_get_initial_offset, "get_initial_offset", 0),
        JS_NewCFunction(ctx, groove_joint2d_class_set_initial_offset, "set_initial_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_groove_joint2d_enum(JSContext *ctx, JSValue proto) {
}

static int js_groove_joint2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GrooveJoint2D"] = class_id;
	classes_by_id[class_id] = "GrooveJoint2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &groove_joint2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Joint2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_groove_joint2d_property(ctx, proto);
	define_groove_joint2d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, groove_joint2d_class_proto_funcs, _countof(groove_joint2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, groove_joint2d_class_constructor, "GrooveJoint2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GrooveJoint2D", ctor);

	return 0;
}

JSModuleDef *_js_init_groove_joint2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/joint2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_groove_joint2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GrooveJoint2D");
	return m;
}

JSModuleDef *js_init_groove_joint2d_module(JSContext *ctx) {
	return _js_init_groove_joint2d_module(ctx, "@godot/classes/groove_joint2d");
}

void __register_groove_joint2d() {
	js_init_groove_joint2d_module(js_context());
}

void register_groove_joint2d() {
	__register_groove_joint2d();
}