#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/box_container.hpp>
using namespace godot;

static void box_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BoxContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef box_container_class_def = {
    "BoxContainer",
    box_container_class_finalizer
};

static JSValue box_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BoxContainer"];
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
        instance = memnew(BoxContainer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue box_container_class_add_spacer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&BoxContainer::add_spacer, ctx, this_val, argc, argv);
};
static JSValue box_container_class_set_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxContainer::set_alignment, ctx, this_val, argc, argv);
};
static JSValue box_container_class_get_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoxContainer::get_alignment, ctx, this_val, argc, argv);
}
static JSValue box_container_class_set_vertical(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoxContainer::set_vertical, ctx, this_val, argc, argv);
};
static JSValue box_container_class_is_vertical(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoxContainer::is_vertical, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry box_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_spacer", 1, &box_container_class_add_spacer),
	JS_CFUNC_DEF("set_alignment", 1, &box_container_class_set_alignment),
	JS_CFUNC_DEF("get_alignment", 0, &box_container_class_get_alignment),
	JS_CFUNC_DEF("set_vertical", 1, &box_container_class_set_vertical),
	JS_CFUNC_DEF("is_vertical", 0, &box_container_class_is_vertical),
};




static void define_box_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alignment"),
        JS_NewCFunction(ctx, box_container_class_get_alignment, "get_alignment", 0),
        JS_NewCFunction(ctx, box_container_class_set_alignment, "set_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertical"),
        JS_NewCFunction(ctx, box_container_class_is_vertical, "is_vertical", 0),
        JS_NewCFunction(ctx, box_container_class_set_vertical, "set_vertical", 1),
        JS_PROP_GETSET
    );
}

static void define_box_container_enum(JSContext *ctx, JSValue ctor) {
	JSValue AlignmentMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AlignmentMode_obj, "ALIGNMENT_BEGIN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AlignmentMode_obj, "ALIGNMENT_CENTER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AlignmentMode_obj, "ALIGNMENT_END", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AlignmentMode", AlignmentMode_obj);
}

static int js_box_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BoxContainer"] = class_id;
	classes_by_id[class_id] = "BoxContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &box_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_box_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, box_container_class_proto_funcs, _countof(box_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, box_container_class_constructor, "BoxContainer", 0, JS_CFUNC_constructor, 0);
	define_box_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BoxContainer", ctor);
	ctor_list["BoxContainer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_box_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_box_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BoxContainer");
	return m;
}

JSModuleDef *js_init_box_container_module(JSContext *ctx) {
	return _js_init_box_container_module(ctx, "@godot/classes/box_container");
}

void __register_box_container() {
	js_init_box_container_module(js_context());
}

void register_box_container() {
	__register_box_container();
}