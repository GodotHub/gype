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
#include <godot_cpp/classes/zip_reader.hpp>
using namespace godot;

static void zip_reader_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ZIPReader"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef zip_reader_class_def = {
    "ZIPReader",
    zip_reader_class_finalizer
};

static JSValue zip_reader_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ZIPReader"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ZIPReader *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ZIPReader *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ZIPReader);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue zip_reader_class_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPReader::open, ctx, this_val, argc, argv);
};
static JSValue zip_reader_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPReader::close, ctx, this_val, argc, argv);
};
static JSValue zip_reader_class_get_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPReader::get_files, ctx, this_val, argc, argv);
};
static JSValue zip_reader_class_read_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPReader::read_file, ctx, this_val, argc, argv);
};
static JSValue zip_reader_class_file_exists(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPReader::file_exists, ctx, this_val, argc, argv);
};
static JSValue zip_reader_class_get_compression_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPReader::get_compression_level, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry zip_reader_class_proto_funcs[] = {
	JS_CFUNC_DEF("open", 1, &zip_reader_class_open),
	JS_CFUNC_DEF("close", 0, &zip_reader_class_close),
	JS_CFUNC_DEF("get_files", 0, &zip_reader_class_get_files),
	JS_CFUNC_DEF("read_file", 2, &zip_reader_class_read_file),
	JS_CFUNC_DEF("file_exists", 2, &zip_reader_class_file_exists),
	JS_CFUNC_DEF("get_compression_level", 2, &zip_reader_class_get_compression_level),
};




static void define_zip_reader_property(JSContext *ctx, JSValue proto) {
}

static void define_zip_reader_enum(JSContext *ctx, JSValue ctor) {
}

static int js_zip_reader_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ZIPReader"] = class_id;
	classes_by_id[class_id] = "ZIPReader";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &zip_reader_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_zip_reader_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, zip_reader_class_proto_funcs, _countof(zip_reader_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, zip_reader_class_constructor, "ZIPReader", 0, JS_CFUNC_constructor, 0);
	define_zip_reader_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ZIPReader", ctor);

	return 0;
}

JSModuleDef *_js_init_zip_reader_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_zip_reader_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ZIPReader");
	return m;
}

JSModuleDef *js_init_zip_reader_module(JSContext *ctx) {
	return _js_init_zip_reader_module(ctx, "@godot/classes/zip_reader");
}

void __register_zip_reader() {
	js_init_zip_reader_module(js_context());
}

void register_zip_reader() {
	__register_zip_reader();
}