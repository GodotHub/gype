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
#include <godot_cpp/classes/rd_vertex_attribute.hpp>
using namespace godot;

static void rd_vertex_attribute_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDVertexAttribute"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_vertex_attribute_class_def = {
    "RDVertexAttribute",
    rd_vertex_attribute_class_finalizer
};

static JSValue rd_vertex_attribute_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDVertexAttribute"];
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
        instance = memnew(RDVertexAttribute);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_vertex_attribute_class_set_location(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDVertexAttribute::set_location, ctx, this_val, argc, argv);
};
static JSValue rd_vertex_attribute_class_get_location(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDVertexAttribute::get_location, ctx, this_val, argc, argv);
}
static JSValue rd_vertex_attribute_class_set_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDVertexAttribute::set_offset, ctx, this_val, argc, argv);
};
static JSValue rd_vertex_attribute_class_get_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDVertexAttribute::get_offset, ctx, this_val, argc, argv);
}
static JSValue rd_vertex_attribute_class_set_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDVertexAttribute::set_format, ctx, this_val, argc, argv);
};
static JSValue rd_vertex_attribute_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDVertexAttribute::get_format, ctx, this_val, argc, argv);
}
static JSValue rd_vertex_attribute_class_set_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDVertexAttribute::set_stride, ctx, this_val, argc, argv);
};
static JSValue rd_vertex_attribute_class_get_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDVertexAttribute::get_stride, ctx, this_val, argc, argv);
}
static JSValue rd_vertex_attribute_class_set_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDVertexAttribute::set_frequency, ctx, this_val, argc, argv);
};
static JSValue rd_vertex_attribute_class_get_frequency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDVertexAttribute::get_frequency, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry rd_vertex_attribute_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_location", 1, &rd_vertex_attribute_class_set_location),
	JS_CFUNC_DEF("get_location", 0, &rd_vertex_attribute_class_get_location),
	JS_CFUNC_DEF("set_offset", 1, &rd_vertex_attribute_class_set_offset),
	JS_CFUNC_DEF("get_offset", 0, &rd_vertex_attribute_class_get_offset),
	JS_CFUNC_DEF("set_format", 1, &rd_vertex_attribute_class_set_format),
	JS_CFUNC_DEF("get_format", 0, &rd_vertex_attribute_class_get_format),
	JS_CFUNC_DEF("set_stride", 1, &rd_vertex_attribute_class_set_stride),
	JS_CFUNC_DEF("get_stride", 0, &rd_vertex_attribute_class_get_stride),
	JS_CFUNC_DEF("set_frequency", 1, &rd_vertex_attribute_class_set_frequency),
	JS_CFUNC_DEF("get_frequency", 0, &rd_vertex_attribute_class_get_frequency),
};




static void define_rd_vertex_attribute_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "location"),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_get_location, "get_location", 0),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_set_location, "set_location", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset"),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_get_offset, "get_offset", 0),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_set_offset, "set_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "format"),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_get_format, "get_format", 0),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_set_format, "set_format", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stride"),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_get_stride, "get_stride", 0),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_set_stride, "set_stride", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "frequency"),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_get_frequency, "get_frequency", 0),
        JS_NewCFunction(ctx, rd_vertex_attribute_class_set_frequency, "set_frequency", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_vertex_attribute_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_vertex_attribute_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDVertexAttribute"] = class_id;
	classes_by_id[class_id] = "RDVertexAttribute";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_vertex_attribute_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_vertex_attribute_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_vertex_attribute_class_proto_funcs, _countof(rd_vertex_attribute_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_vertex_attribute_class_constructor, "RDVertexAttribute", 0, JS_CFUNC_constructor, 0);
	define_rd_vertex_attribute_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDVertexAttribute", ctor);
	ctor_list["RDVertexAttribute"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_vertex_attribute_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_vertex_attribute_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDVertexAttribute");
	return m;
}

JSModuleDef *js_init_rd_vertex_attribute_module(JSContext *ctx) {
	return _js_init_rd_vertex_attribute_module(ctx, "@godot/classes/rd_vertex_attribute");
}

void __register_rd_vertex_attribute() {
	js_init_rd_vertex_attribute_module(js_context());
}

void register_rd_vertex_attribute() {
	__register_rd_vertex_attribute();
}