#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gltf_state.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_buffer_view.hpp>
using namespace godot;

static void gltf_buffer_view_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFBufferView"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_buffer_view_class_def = {
    "GLTFBufferView",
    gltf_buffer_view_class_finalizer
};

static JSValue gltf_buffer_view_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFBufferView"];
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
        instance = memnew(GLTFBufferView);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_buffer_view_class_load_buffer_view_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::load_buffer_view_data, ctx, this_val, argc, argv);
};
static JSValue gltf_buffer_view_class_get_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::get_buffer, ctx, this_val, argc, argv);
}
static JSValue gltf_buffer_view_class_set_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFBufferView::set_buffer, ctx, this_val, argc, argv);
};
static JSValue gltf_buffer_view_class_get_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::get_byte_offset, ctx, this_val, argc, argv);
}
static JSValue gltf_buffer_view_class_set_byte_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFBufferView::set_byte_offset, ctx, this_val, argc, argv);
};
static JSValue gltf_buffer_view_class_get_byte_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::get_byte_length, ctx, this_val, argc, argv);
}
static JSValue gltf_buffer_view_class_set_byte_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFBufferView::set_byte_length, ctx, this_val, argc, argv);
};
static JSValue gltf_buffer_view_class_get_byte_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::get_byte_stride, ctx, this_val, argc, argv);
}
static JSValue gltf_buffer_view_class_set_byte_stride(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFBufferView::set_byte_stride, ctx, this_val, argc, argv);
};
static JSValue gltf_buffer_view_class_get_indices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::get_indices, ctx, this_val, argc, argv);
}
static JSValue gltf_buffer_view_class_set_indices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFBufferView::set_indices, ctx, this_val, argc, argv);
};
static JSValue gltf_buffer_view_class_get_vertex_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFBufferView::get_vertex_attributes, ctx, this_val, argc, argv);
}
static JSValue gltf_buffer_view_class_set_vertex_attributes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFBufferView::set_vertex_attributes, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry gltf_buffer_view_class_proto_funcs[] = {
	JS_CFUNC_DEF("load_buffer_view_data", 1, &gltf_buffer_view_class_load_buffer_view_data),
	JS_CFUNC_DEF("get_buffer", 0, &gltf_buffer_view_class_get_buffer),
	JS_CFUNC_DEF("set_buffer", 1, &gltf_buffer_view_class_set_buffer),
	JS_CFUNC_DEF("get_byte_offset", 0, &gltf_buffer_view_class_get_byte_offset),
	JS_CFUNC_DEF("set_byte_offset", 1, &gltf_buffer_view_class_set_byte_offset),
	JS_CFUNC_DEF("get_byte_length", 0, &gltf_buffer_view_class_get_byte_length),
	JS_CFUNC_DEF("set_byte_length", 1, &gltf_buffer_view_class_set_byte_length),
	JS_CFUNC_DEF("get_byte_stride", 0, &gltf_buffer_view_class_get_byte_stride),
	JS_CFUNC_DEF("set_byte_stride", 1, &gltf_buffer_view_class_set_byte_stride),
	JS_CFUNC_DEF("get_indices", 0, &gltf_buffer_view_class_get_indices),
	JS_CFUNC_DEF("set_indices", 1, &gltf_buffer_view_class_set_indices),
	JS_CFUNC_DEF("get_vertex_attributes", 0, &gltf_buffer_view_class_get_vertex_attributes),
	JS_CFUNC_DEF("set_vertex_attributes", 1, &gltf_buffer_view_class_set_vertex_attributes),
};




static void define_gltf_buffer_view_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer"),
        JS_NewCFunction(ctx, gltf_buffer_view_class_get_buffer, "get_buffer", 0),
        JS_NewCFunction(ctx, gltf_buffer_view_class_set_buffer, "set_buffer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "byte_offset"),
        JS_NewCFunction(ctx, gltf_buffer_view_class_get_byte_offset, "get_byte_offset", 0),
        JS_NewCFunction(ctx, gltf_buffer_view_class_set_byte_offset, "set_byte_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "byte_length"),
        JS_NewCFunction(ctx, gltf_buffer_view_class_get_byte_length, "get_byte_length", 0),
        JS_NewCFunction(ctx, gltf_buffer_view_class_set_byte_length, "set_byte_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "byte_stride"),
        JS_NewCFunction(ctx, gltf_buffer_view_class_get_byte_stride, "get_byte_stride", 0),
        JS_NewCFunction(ctx, gltf_buffer_view_class_set_byte_stride, "set_byte_stride", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "indices"),
        JS_NewCFunction(ctx, gltf_buffer_view_class_get_indices, "get_indices", 0),
        JS_NewCFunction(ctx, gltf_buffer_view_class_set_indices, "set_indices", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vertex_attributes"),
        JS_NewCFunction(ctx, gltf_buffer_view_class_get_vertex_attributes, "get_vertex_attributes", 0),
        JS_NewCFunction(ctx, gltf_buffer_view_class_set_vertex_attributes, "set_vertex_attributes", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_buffer_view_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_buffer_view_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFBufferView"] = class_id;
	classes_by_id[class_id] = "GLTFBufferView";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_buffer_view_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_buffer_view_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_buffer_view_class_proto_funcs, _countof(gltf_buffer_view_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_buffer_view_class_constructor, "GLTFBufferView", 0, JS_CFUNC_constructor, 0);
	define_gltf_buffer_view_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFBufferView", ctor);
	ctor_list["GLTFBufferView"] = ctor;

	return 0;
}

JSModuleDef *_js_init_gltf_buffer_view_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_buffer_view_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFBufferView");
	return m;
}

JSModuleDef *js_init_gltf_buffer_view_module(JSContext *ctx) {
	return _js_init_gltf_buffer_view_module(ctx, "@godot/classes/gltf_buffer_view");
}

void __register_gltf_buffer_view() {
	js_init_gltf_buffer_view_module(js_context());
}

void register_gltf_buffer_view() {
	__register_gltf_buffer_view();
}