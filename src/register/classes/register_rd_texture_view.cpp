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
#include <godot_cpp/classes/rd_texture_view.hpp>
using namespace godot;

static void rd_texture_view_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDTextureView"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_texture_view_class_def = {
    "RDTextureView",
    rd_texture_view_class_finalizer
};

static JSValue rd_texture_view_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDTextureView"];
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
        instance = memnew(RDTextureView);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_texture_view_class_set_format_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDTextureView::set_format_override, ctx, this_val, argc, argv);
};
static JSValue rd_texture_view_class_get_format_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDTextureView::get_format_override, ctx, this_val, argc, argv);
}
static JSValue rd_texture_view_class_set_swizzle_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDTextureView::set_swizzle_r, ctx, this_val, argc, argv);
};
static JSValue rd_texture_view_class_get_swizzle_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDTextureView::get_swizzle_r, ctx, this_val, argc, argv);
}
static JSValue rd_texture_view_class_set_swizzle_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDTextureView::set_swizzle_g, ctx, this_val, argc, argv);
};
static JSValue rd_texture_view_class_get_swizzle_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDTextureView::get_swizzle_g, ctx, this_val, argc, argv);
}
static JSValue rd_texture_view_class_set_swizzle_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDTextureView::set_swizzle_b, ctx, this_val, argc, argv);
};
static JSValue rd_texture_view_class_get_swizzle_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDTextureView::get_swizzle_b, ctx, this_val, argc, argv);
}
static JSValue rd_texture_view_class_set_swizzle_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDTextureView::set_swizzle_a, ctx, this_val, argc, argv);
};
static JSValue rd_texture_view_class_get_swizzle_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDTextureView::get_swizzle_a, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_texture_view_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_format_override", 1, &rd_texture_view_class_set_format_override),
	JS_CFUNC_DEF("get_format_override", 0, &rd_texture_view_class_get_format_override),
	JS_CFUNC_DEF("set_swizzle_r", 1, &rd_texture_view_class_set_swizzle_r),
	JS_CFUNC_DEF("get_swizzle_r", 0, &rd_texture_view_class_get_swizzle_r),
	JS_CFUNC_DEF("set_swizzle_g", 1, &rd_texture_view_class_set_swizzle_g),
	JS_CFUNC_DEF("get_swizzle_g", 0, &rd_texture_view_class_get_swizzle_g),
	JS_CFUNC_DEF("set_swizzle_b", 1, &rd_texture_view_class_set_swizzle_b),
	JS_CFUNC_DEF("get_swizzle_b", 0, &rd_texture_view_class_get_swizzle_b),
	JS_CFUNC_DEF("set_swizzle_a", 1, &rd_texture_view_class_set_swizzle_a),
	JS_CFUNC_DEF("get_swizzle_a", 0, &rd_texture_view_class_get_swizzle_a),
};




static void define_rd_texture_view_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "format_override"),
        JS_NewCFunction(ctx, rd_texture_view_class_get_format_override, "get_format_override", 0),
        JS_NewCFunction(ctx, rd_texture_view_class_set_format_override, "set_format_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swizzle_r"),
        JS_NewCFunction(ctx, rd_texture_view_class_get_swizzle_r, "get_swizzle_r", 0),
        JS_NewCFunction(ctx, rd_texture_view_class_set_swizzle_r, "set_swizzle_r", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swizzle_g"),
        JS_NewCFunction(ctx, rd_texture_view_class_get_swizzle_g, "get_swizzle_g", 0),
        JS_NewCFunction(ctx, rd_texture_view_class_set_swizzle_g, "set_swizzle_g", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swizzle_b"),
        JS_NewCFunction(ctx, rd_texture_view_class_get_swizzle_b, "get_swizzle_b", 0),
        JS_NewCFunction(ctx, rd_texture_view_class_set_swizzle_b, "set_swizzle_b", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swizzle_a"),
        JS_NewCFunction(ctx, rd_texture_view_class_get_swizzle_a, "get_swizzle_a", 0),
        JS_NewCFunction(ctx, rd_texture_view_class_set_swizzle_a, "set_swizzle_a", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_texture_view_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_texture_view_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDTextureView"] = class_id;
	classes_by_id[class_id] = "RDTextureView";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_texture_view_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_texture_view_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_texture_view_class_proto_funcs, _countof(rd_texture_view_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_texture_view_class_constructor, "RDTextureView", 0, JS_CFUNC_constructor, 0);
	define_rd_texture_view_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDTextureView", ctor);
	ctor_list["RDTextureView"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_texture_view_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_texture_view_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDTextureView");
	return m;
}

JSModuleDef *js_init_rd_texture_view_module(JSContext *ctx) {
	return _js_init_rd_texture_view_module(ctx, "@godot/classes/rd_texture_view");
}

void __register_rd_texture_view() {
	js_init_rd_texture_view_module(js_context());
}

void register_rd_texture_view() {
	__register_rd_texture_view();
}