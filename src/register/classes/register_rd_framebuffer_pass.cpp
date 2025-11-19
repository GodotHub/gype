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
#include <godot_cpp/classes/rd_framebuffer_pass.hpp>
using namespace godot;

static void rd_framebuffer_pass_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDFramebufferPass"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef rd_framebuffer_pass_class_def = {
    "RDFramebufferPass",
    rd_framebuffer_pass_class_finalizer
};

static JSValue rd_framebuffer_pass_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDFramebufferPass"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RDFramebufferPass *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RDFramebufferPass *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RDFramebufferPass);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_framebuffer_pass_class_set_color_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDFramebufferPass::set_color_attachments, ctx, this_val, argc, argv);
};
static JSValue rd_framebuffer_pass_class_get_color_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		RDFramebufferPass *obj = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color_attachments();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		RDFramebufferPass *js_proxy = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color_attachments(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue rd_framebuffer_pass_class_set_input_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDFramebufferPass::set_input_attachments, ctx, this_val, argc, argv);
};
static JSValue rd_framebuffer_pass_class_get_input_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		RDFramebufferPass *obj = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_input_attachments();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		RDFramebufferPass *js_proxy = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_input_attachments(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue rd_framebuffer_pass_class_set_resolve_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDFramebufferPass::set_resolve_attachments, ctx, this_val, argc, argv);
};
static JSValue rd_framebuffer_pass_class_get_resolve_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		RDFramebufferPass *obj = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_resolve_attachments();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		RDFramebufferPass *js_proxy = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_resolve_attachments(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue rd_framebuffer_pass_class_set_preserve_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDFramebufferPass::set_preserve_attachments, ctx, this_val, argc, argv);
};
static JSValue rd_framebuffer_pass_class_get_preserve_attachments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		RDFramebufferPass *obj = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_preserve_attachments();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		RDFramebufferPass *js_proxy = static_cast<RDFramebufferPass *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_preserve_attachments(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue rd_framebuffer_pass_class_set_depth_attachment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDFramebufferPass::set_depth_attachment, ctx, this_val, argc, argv);
};
static JSValue rd_framebuffer_pass_class_get_depth_attachment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDFramebufferPass::get_depth_attachment, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_framebuffer_pass_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_color_attachments", 1, &rd_framebuffer_pass_class_set_color_attachments),
	JS_CFUNC_DEF("get_color_attachments", 0, &rd_framebuffer_pass_class_get_color_attachments),
	JS_CFUNC_DEF("set_input_attachments", 1, &rd_framebuffer_pass_class_set_input_attachments),
	JS_CFUNC_DEF("get_input_attachments", 0, &rd_framebuffer_pass_class_get_input_attachments),
	JS_CFUNC_DEF("set_resolve_attachments", 1, &rd_framebuffer_pass_class_set_resolve_attachments),
	JS_CFUNC_DEF("get_resolve_attachments", 0, &rd_framebuffer_pass_class_get_resolve_attachments),
	JS_CFUNC_DEF("set_preserve_attachments", 1, &rd_framebuffer_pass_class_set_preserve_attachments),
	JS_CFUNC_DEF("get_preserve_attachments", 0, &rd_framebuffer_pass_class_get_preserve_attachments),
	JS_CFUNC_DEF("set_depth_attachment", 1, &rd_framebuffer_pass_class_set_depth_attachment),
	JS_CFUNC_DEF("get_depth_attachment", 0, &rd_framebuffer_pass_class_get_depth_attachment),
};




static void define_rd_framebuffer_pass_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_attachments"),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_get_color_attachments, "get_color_attachments", 0),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_set_color_attachments, "set_color_attachments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_attachments"),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_get_input_attachments, "get_input_attachments", 0),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_set_input_attachments, "set_input_attachments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resolve_attachments"),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_get_resolve_attachments, "get_resolve_attachments", 0),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_set_resolve_attachments, "set_resolve_attachments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preserve_attachments"),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_get_preserve_attachments, "get_preserve_attachments", 0),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_set_preserve_attachments, "set_preserve_attachments", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth_attachment"),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_get_depth_attachment, "get_depth_attachment", 0),
        JS_NewCFunction(ctx, rd_framebuffer_pass_class_set_depth_attachment, "set_depth_attachment", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_framebuffer_pass_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_framebuffer_pass_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDFramebufferPass"] = class_id;
	classes_by_id[class_id] = "RDFramebufferPass";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_framebuffer_pass_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_framebuffer_pass_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_framebuffer_pass_class_proto_funcs, _countof(rd_framebuffer_pass_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_framebuffer_pass_class_constructor, "RDFramebufferPass", 0, JS_CFUNC_constructor, 0);
	define_rd_framebuffer_pass_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDFramebufferPass", ctor);

	return 0;
}

JSModuleDef *_js_init_rd_framebuffer_pass_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_framebuffer_pass_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDFramebufferPass");
	return m;
}

JSModuleDef *js_init_rd_framebuffer_pass_module(JSContext *ctx) {
	return _js_init_rd_framebuffer_pass_module(ctx, "@godot/classes/rd_framebuffer_pass");
}

void __register_rd_framebuffer_pass() {
	js_init_rd_framebuffer_pass_module(js_context());
}

void register_rd_framebuffer_pass() {
	__register_rd_framebuffer_pass();
}