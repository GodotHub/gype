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
#include <godot_cpp/classes/rd_shader_source.hpp>
using namespace godot;

static void rd_shader_source_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDShaderSource"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_shader_source_class_def = {
    "RDShaderSource",
    rd_shader_source_class_finalizer
};

static JSValue rd_shader_source_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDShaderSource"];
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
        instance = memnew(RDShaderSource);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_shader_source_class_set_stage_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDShaderSource::set_stage_source, ctx, this_val, argc, argv);
};
static JSValue rd_shader_source_class_get_stage_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDShaderSource::get_stage_source, ctx, this_val, argc, argv);
}
static JSValue rd_shader_source_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDShaderSource::set_language, ctx, this_val, argc, argv);
};
static JSValue rd_shader_source_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDShaderSource::get_language, ctx, this_val, argc, argv);
}

static JSValue rd_shader_source_class_get_source_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSource::get_stage_source, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_source_class_set_source_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSource::set_stage_source, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_source_class_get_source_fragment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSource::get_stage_source, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_source_class_set_source_fragment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSource::set_stage_source, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_source_class_get_source_tesselation_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSource::get_stage_source, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_source_class_set_source_tesselation_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSource::set_stage_source, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_source_class_get_source_tesselation_evaluation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSource::get_stage_source, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_source_class_set_source_tesselation_evaluation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSource::set_stage_source, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_source_class_get_source_compute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSource::get_stage_source, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_source_class_set_source_compute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSource::set_stage_source, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry rd_shader_source_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stage_source", 2, &rd_shader_source_class_set_stage_source),
	JS_CFUNC_DEF("get_stage_source", 1, &rd_shader_source_class_get_stage_source),
	JS_CFUNC_DEF("set_language", 1, &rd_shader_source_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &rd_shader_source_class_get_language),
    JS_CFUNC_MAGIC_DEF("get_source_fragment", 0, &rd_shader_source_class_get_source_fragment, 1),
    JS_CFUNC_MAGIC_DEF("set_source_fragment", 1, &rd_shader_source_class_set_source_fragment, 1),
    JS_CFUNC_MAGIC_DEF("get_source_tesselation_control", 0, &rd_shader_source_class_get_source_tesselation_control, 2),
    JS_CFUNC_MAGIC_DEF("set_source_tesselation_control", 1, &rd_shader_source_class_set_source_tesselation_control, 2),
    JS_CFUNC_MAGIC_DEF("get_source_tesselation_evaluation", 0, &rd_shader_source_class_get_source_tesselation_evaluation, 3),
    JS_CFUNC_MAGIC_DEF("set_source_tesselation_evaluation", 1, &rd_shader_source_class_set_source_tesselation_evaluation, 3),
    JS_CFUNC_MAGIC_DEF("get_source_compute", 0, &rd_shader_source_class_get_source_compute, 4),
    JS_CFUNC_MAGIC_DEF("set_source_compute", 1, &rd_shader_source_class_set_source_compute, 4),
};




static void define_rd_shader_source_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "source_vertex"),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_get_source_vertex, "get_source_vertex", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_set_source_vertex, "set_source_vertex", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "source_fragment"),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_get_source_fragment, "get_source_fragment", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_set_source_fragment, "set_source_fragment", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "source_tesselation_control"),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_get_source_tesselation_control, "get_source_tesselation_control", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_set_source_tesselation_control, "set_source_tesselation_control", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "source_tesselation_evaluation"),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_get_source_tesselation_evaluation, "get_source_tesselation_evaluation", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_set_source_tesselation_evaluation, "set_source_tesselation_evaluation", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "source_compute"),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_get_source_compute, "get_source_compute", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, rd_shader_source_class_set_source_compute, "set_source_compute", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, rd_shader_source_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, rd_shader_source_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
}

static void define_rd_shader_source_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_shader_source_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDShaderSource"] = class_id;
	classes_by_id[class_id] = "RDShaderSource";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_shader_source_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_shader_source_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_shader_source_class_proto_funcs, _countof(rd_shader_source_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_shader_source_class_constructor, "RDShaderSource", 0, JS_CFUNC_constructor, 0);
	define_rd_shader_source_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDShaderSource", ctor);
	ctor_list["RDShaderSource"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_shader_source_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_shader_source_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDShaderSource");
	return m;
}

JSModuleDef *js_init_rd_shader_source_module(JSContext *ctx) {
	return _js_init_rd_shader_source_module(ctx, "@godot/classes/rd_shader_source");
}

void __register_rd_shader_source() {
	js_init_rd_shader_source_module(js_context());
}

void register_rd_shader_source() {
	__register_rd_shader_source();
}