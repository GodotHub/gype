#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/rd_attachment_format.hpp>
using namespace godot;

static void rd_attachment_format_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDAttachmentFormat"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_attachment_format_class_def = {
    "RDAttachmentFormat",
    rd_attachment_format_class_finalizer
};

static JSValue rd_attachment_format_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDAttachmentFormat"];
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
        instance = memnew(RDAttachmentFormat);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_attachment_format_class_set_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDAttachmentFormat::set_format, ctx, this_val, argc, argv);
};
static JSValue rd_attachment_format_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDAttachmentFormat::get_format, ctx, this_val, argc, argv);
}
static JSValue rd_attachment_format_class_set_samples(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDAttachmentFormat::set_samples, ctx, this_val, argc, argv);
};
static JSValue rd_attachment_format_class_get_samples(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDAttachmentFormat::get_samples, ctx, this_val, argc, argv);
}
static JSValue rd_attachment_format_class_set_usage_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDAttachmentFormat::set_usage_flags, ctx, this_val, argc, argv);
};
static JSValue rd_attachment_format_class_get_usage_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDAttachmentFormat::get_usage_flags, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_attachment_format_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_format", 1, &rd_attachment_format_class_set_format),
	JS_CFUNC_DEF("get_format", 0, &rd_attachment_format_class_get_format),
	JS_CFUNC_DEF("set_samples", 1, &rd_attachment_format_class_set_samples),
	JS_CFUNC_DEF("get_samples", 0, &rd_attachment_format_class_get_samples),
	JS_CFUNC_DEF("set_usage_flags", 1, &rd_attachment_format_class_set_usage_flags),
	JS_CFUNC_DEF("get_usage_flags", 0, &rd_attachment_format_class_get_usage_flags),
};




static void define_rd_attachment_format_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "format"),
        JS_NewCFunction(ctx, rd_attachment_format_class_get_format, "get_format", 0),
        JS_NewCFunction(ctx, rd_attachment_format_class_set_format, "set_format", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "samples"),
        JS_NewCFunction(ctx, rd_attachment_format_class_get_samples, "get_samples", 0),
        JS_NewCFunction(ctx, rd_attachment_format_class_set_samples, "set_samples", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "usage_flags"),
        JS_NewCFunction(ctx, rd_attachment_format_class_get_usage_flags, "get_usage_flags", 0),
        JS_NewCFunction(ctx, rd_attachment_format_class_set_usage_flags, "set_usage_flags", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_attachment_format_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_attachment_format_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDAttachmentFormat"] = class_id;
	classes_by_id[class_id] = "RDAttachmentFormat";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_attachment_format_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_attachment_format_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_attachment_format_class_proto_funcs, _countof(rd_attachment_format_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_attachment_format_class_constructor, "RDAttachmentFormat", 0, JS_CFUNC_constructor, 0);
	define_rd_attachment_format_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDAttachmentFormat", ctor);
	ctor_list["RDAttachmentFormat"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_attachment_format_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_attachment_format_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDAttachmentFormat");
	return m;
}

JSModuleDef *js_init_rd_attachment_format_module(JSContext *ctx) {
	return _js_init_rd_attachment_format_module(ctx, "@godot/classes/rd_attachment_format");
}

void __register_rd_attachment_format() {
	js_init_rd_attachment_format_module(js_context());
}

void register_rd_attachment_format() {
	__register_rd_attachment_format();
}