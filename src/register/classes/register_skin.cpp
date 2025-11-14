#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skin.hpp>
using namespace godot;

static void skin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Skin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef skin_class_def = {
    "Skin",
    skin_class_finalizer
};

static JSValue skin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Skin"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Skin *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Skin *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Skin);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skin_class_set_bind_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::set_bind_count, ctx, this_val, argc, argv);
};
static JSValue skin_class_get_bind_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skin::get_bind_count, ctx, this_val, argc, argv);
};
static JSValue skin_class_add_bind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::add_bind, ctx, this_val, argc, argv);
};
static JSValue skin_class_add_named_bind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::add_named_bind, ctx, this_val, argc, argv);
};
static JSValue skin_class_set_bind_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::set_bind_pose, ctx, this_val, argc, argv);
};
static JSValue skin_class_get_bind_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skin::get_bind_pose, ctx, this_val, argc, argv);
};
static JSValue skin_class_set_bind_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::set_bind_name, ctx, this_val, argc, argv);
};
static JSValue skin_class_get_bind_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skin::get_bind_name, ctx, this_val, argc, argv);
};
static JSValue skin_class_set_bind_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::set_bind_bone, ctx, this_val, argc, argv);
};
static JSValue skin_class_get_bind_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skin::get_bind_bone, ctx, this_val, argc, argv);
};
static JSValue skin_class_clear_binds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skin::clear_binds, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry skin_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_bind_count", 1, &skin_class_set_bind_count),
	JS_CFUNC_DEF("get_bind_count", 0, &skin_class_get_bind_count),
	JS_CFUNC_DEF("add_bind", 2, &skin_class_add_bind),
	JS_CFUNC_DEF("add_named_bind", 2, &skin_class_add_named_bind),
	JS_CFUNC_DEF("set_bind_pose", 2, &skin_class_set_bind_pose),
	JS_CFUNC_DEF("get_bind_pose", 1, &skin_class_get_bind_pose),
	JS_CFUNC_DEF("set_bind_name", 2, &skin_class_set_bind_name),
	JS_CFUNC_DEF("get_bind_name", 1, &skin_class_get_bind_name),
	JS_CFUNC_DEF("set_bind_bone", 2, &skin_class_set_bind_bone),
	JS_CFUNC_DEF("get_bind_bone", 1, &skin_class_get_bind_bone),
	JS_CFUNC_DEF("clear_binds", 0, &skin_class_clear_binds),
};




static void define_skin_property(JSContext *ctx, JSValue proto) {
}

static void define_skin_enum(JSContext *ctx, JSValue proto) {
}

static int js_skin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Skin"] = class_id;
	classes_by_id[class_id] = "Skin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skin_property(ctx, proto);
	define_skin_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skin_class_proto_funcs, _countof(skin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skin_class_constructor, "Skin", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Skin", ctor);

	return 0;
}

JSModuleDef *_js_init_skin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Skin");
	return m;
}

JSModuleDef *js_init_skin_module(JSContext *ctx) {
	return _js_init_skin_module(ctx, "@godot/classes/skin");
}

void __register_skin() {
	js_init_skin_module(js_context());
}

void register_skin() {
	__register_skin();
}