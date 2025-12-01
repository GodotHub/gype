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
#include <godot_cpp/classes/rd_shader_spirv.hpp>
using namespace godot;

static void rd_shader_spirv_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RDShaderSPIRV"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef rd_shader_spirv_class_def = {
    "RDShaderSPIRV",
    rd_shader_spirv_class_finalizer
};

static JSValue rd_shader_spirv_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RDShaderSPIRV"];
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
        instance = memnew(RDShaderSPIRV);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rd_shader_spirv_class_set_stage_bytecode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_bytecode, ctx, this_val, argc, argv);
};
static JSValue rd_shader_spirv_class_get_stage_bytecode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_bytecode, ctx, this_val, argc, argv);
}
static JSValue rd_shader_spirv_class_set_stage_compile_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_compile_error, ctx, this_val, argc, argv);
};
static JSValue rd_shader_spirv_class_get_stage_compile_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_compile_error, ctx, this_val, argc, argv);
}

static JSValue rd_shader_spirv_class_get_bytecode_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_bytecode, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_bytecode_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_bytecode, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_bytecode_fragment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_bytecode, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_bytecode_fragment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_bytecode, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_bytecode_tesselation_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_bytecode, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_bytecode_tesselation_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_bytecode, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_bytecode_tesselation_evaluation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_bytecode, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_bytecode_tesselation_evaluation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_bytecode, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_bytecode_compute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_bytecode, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_bytecode_compute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_bytecode, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_compile_error_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_compile_error, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_compile_error_vertex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_compile_error, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_compile_error_fragment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_compile_error, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_compile_error_fragment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_compile_error, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_compile_error_tesselation_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_compile_error, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_compile_error_tesselation_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_compile_error, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_compile_error_tesselation_evaluation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_compile_error, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_compile_error_tesselation_evaluation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_compile_error, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue rd_shader_spirv_class_get_compile_error_compute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&RDShaderSPIRV::get_stage_compile_error, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue rd_shader_spirv_class_set_compile_error_compute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&RDShaderSPIRV::set_stage_compile_error, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry rd_shader_spirv_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stage_bytecode", 2, &rd_shader_spirv_class_set_stage_bytecode),
	JS_CFUNC_DEF("get_stage_bytecode", 1, &rd_shader_spirv_class_get_stage_bytecode),
	JS_CFUNC_DEF("set_stage_compile_error", 2, &rd_shader_spirv_class_set_stage_compile_error),
	JS_CFUNC_DEF("get_stage_compile_error", 1, &rd_shader_spirv_class_get_stage_compile_error),
    JS_CFUNC_MAGIC_DEF("get_bytecode_fragment", 0, &rd_shader_spirv_class_get_bytecode_fragment, 1),
    JS_CFUNC_MAGIC_DEF("set_bytecode_fragment", 1, &rd_shader_spirv_class_set_bytecode_fragment, 1),
    JS_CFUNC_MAGIC_DEF("get_bytecode_tesselation_control", 0, &rd_shader_spirv_class_get_bytecode_tesselation_control, 2),
    JS_CFUNC_MAGIC_DEF("set_bytecode_tesselation_control", 1, &rd_shader_spirv_class_set_bytecode_tesselation_control, 2),
    JS_CFUNC_MAGIC_DEF("get_bytecode_tesselation_evaluation", 0, &rd_shader_spirv_class_get_bytecode_tesselation_evaluation, 3),
    JS_CFUNC_MAGIC_DEF("set_bytecode_tesselation_evaluation", 1, &rd_shader_spirv_class_set_bytecode_tesselation_evaluation, 3),
    JS_CFUNC_MAGIC_DEF("get_bytecode_compute", 0, &rd_shader_spirv_class_get_bytecode_compute, 4),
    JS_CFUNC_MAGIC_DEF("set_bytecode_compute", 1, &rd_shader_spirv_class_set_bytecode_compute, 4),
    JS_CFUNC_MAGIC_DEF("get_compile_error_fragment", 0, &rd_shader_spirv_class_get_compile_error_fragment, 1),
    JS_CFUNC_MAGIC_DEF("set_compile_error_fragment", 1, &rd_shader_spirv_class_set_compile_error_fragment, 1),
    JS_CFUNC_MAGIC_DEF("get_compile_error_tesselation_control", 0, &rd_shader_spirv_class_get_compile_error_tesselation_control, 2),
    JS_CFUNC_MAGIC_DEF("set_compile_error_tesselation_control", 1, &rd_shader_spirv_class_set_compile_error_tesselation_control, 2),
    JS_CFUNC_MAGIC_DEF("get_compile_error_tesselation_evaluation", 0, &rd_shader_spirv_class_get_compile_error_tesselation_evaluation, 3),
    JS_CFUNC_MAGIC_DEF("set_compile_error_tesselation_evaluation", 1, &rd_shader_spirv_class_set_compile_error_tesselation_evaluation, 3),
    JS_CFUNC_MAGIC_DEF("get_compile_error_compute", 0, &rd_shader_spirv_class_get_compile_error_compute, 4),
    JS_CFUNC_MAGIC_DEF("set_compile_error_compute", 1, &rd_shader_spirv_class_set_compile_error_compute, 4),
};




static void define_rd_shader_spirv_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bytecode_vertex"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_bytecode_vertex, "get_bytecode_vertex", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_bytecode_vertex, "set_bytecode_vertex", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bytecode_fragment"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_bytecode_fragment, "get_bytecode_fragment", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_bytecode_fragment, "set_bytecode_fragment", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bytecode_tesselation_control"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_bytecode_tesselation_control, "get_bytecode_tesselation_control", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_bytecode_tesselation_control, "set_bytecode_tesselation_control", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bytecode_tesselation_evaluation"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_bytecode_tesselation_evaluation, "get_bytecode_tesselation_evaluation", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_bytecode_tesselation_evaluation, "set_bytecode_tesselation_evaluation", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bytecode_compute"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_bytecode_compute, "get_bytecode_compute", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_bytecode_compute, "set_bytecode_compute", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "compile_error_vertex"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_compile_error_vertex, "get_compile_error_vertex", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_compile_error_vertex, "set_compile_error_vertex", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "compile_error_fragment"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_compile_error_fragment, "get_compile_error_fragment", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_compile_error_fragment, "set_compile_error_fragment", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "compile_error_tesselation_control"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_compile_error_tesselation_control, "get_compile_error_tesselation_control", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_compile_error_tesselation_control, "set_compile_error_tesselation_control", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "compile_error_tesselation_evaluation"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_compile_error_tesselation_evaluation, "get_compile_error_tesselation_evaluation", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_compile_error_tesselation_evaluation, "set_compile_error_tesselation_evaluation", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "compile_error_compute"),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_get_compile_error_compute, "get_compile_error_compute", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, rd_shader_spirv_class_set_compile_error_compute, "set_compile_error_compute", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
}

static void define_rd_shader_spirv_enum(JSContext *ctx, JSValue ctor) {
}

static int js_rd_shader_spirv_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RDShaderSPIRV"] = class_id;
	classes_by_id[class_id] = "RDShaderSPIRV";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rd_shader_spirv_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rd_shader_spirv_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rd_shader_spirv_class_proto_funcs, _countof(rd_shader_spirv_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rd_shader_spirv_class_constructor, "RDShaderSPIRV", 0, JS_CFUNC_constructor, 0);
	define_rd_shader_spirv_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RDShaderSPIRV", ctor);
	ctor_list["RDShaderSPIRV"] = ctor;

	return 0;
}

JSModuleDef *_js_init_rd_shader_spirv_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rd_shader_spirv_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RDShaderSPIRV");
	return m;
}

JSModuleDef *js_init_rd_shader_spirv_module(JSContext *ctx) {
	return _js_init_rd_shader_spirv_module(ctx, "@godot/classes/rd_shader_spirv");
}

void __register_rd_shader_spirv() {
	js_init_rd_shader_spirv_module(js_context());
}

void register_rd_shader_spirv() {
	__register_rd_shader_spirv();
}