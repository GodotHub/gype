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
#include <godot_cpp/classes/zip_packer.hpp>
using namespace godot;

static void zip_packer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ZIPPacker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef zip_packer_class_def = {
    "ZIPPacker",
    zip_packer_class_finalizer
};

static JSValue zip_packer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ZIPPacker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ZIPPacker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ZIPPacker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ZIPPacker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue zip_packer_class_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPPacker::open, ctx, this_val, argc, argv);
};
static JSValue zip_packer_class_set_compression_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ZIPPacker::set_compression_level, ctx, this_val, argc, argv);
};
static JSValue zip_packer_class_get_compression_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ZIPPacker::get_compression_level, ctx, this_val, argc, argv);
}
static JSValue zip_packer_class_start_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPPacker::start_file, ctx, this_val, argc, argv);
};
static JSValue zip_packer_class_write_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPPacker::write_file, ctx, this_val, argc, argv);
};
static JSValue zip_packer_class_close_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPPacker::close_file, ctx, this_val, argc, argv);
};
static JSValue zip_packer_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ZIPPacker::close, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry zip_packer_class_proto_funcs[] = {
	JS_CFUNC_DEF("open", 2, &zip_packer_class_open),
	JS_CFUNC_DEF("set_compression_level", 1, &zip_packer_class_set_compression_level),
	JS_CFUNC_DEF("get_compression_level", 0, &zip_packer_class_get_compression_level),
	JS_CFUNC_DEF("start_file", 1, &zip_packer_class_start_file),
	JS_CFUNC_DEF("write_file", 1, &zip_packer_class_write_file),
	JS_CFUNC_DEF("close_file", 0, &zip_packer_class_close_file),
	JS_CFUNC_DEF("close", 0, &zip_packer_class_close),
};




static void define_zip_packer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "compression_level"),
        JS_NewCFunction(ctx, zip_packer_class_get_compression_level, "get_compression_level", 0),
        JS_NewCFunction(ctx, zip_packer_class_set_compression_level, "set_compression_level", 1),
        JS_PROP_GETSET
    );
}

static void define_zip_packer_enum(JSContext *ctx, JSValue ctor) {
	JSValue ZipAppend_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ZipAppend_obj, "APPEND_CREATE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ZipAppend_obj, "APPEND_CREATEAFTER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ZipAppend_obj, "APPEND_ADDINZIP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ZipAppend", ZipAppend_obj);
	JSValue CompressionLevel_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompressionLevel_obj, "COMPRESSION_DEFAULT", JS_NewInt64(ctx, -1));
	JS_SetPropertyStr(ctx, CompressionLevel_obj, "COMPRESSION_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompressionLevel_obj, "COMPRESSION_FAST", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompressionLevel_obj, "COMPRESSION_BEST", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, ctor, "CompressionLevel", CompressionLevel_obj);
}

static int js_zip_packer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ZIPPacker"] = class_id;
	classes_by_id[class_id] = "ZIPPacker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &zip_packer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_zip_packer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, zip_packer_class_proto_funcs, _countof(zip_packer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, zip_packer_class_constructor, "ZIPPacker", 0, JS_CFUNC_constructor, 0);
	define_zip_packer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ZIPPacker", ctor);

	return 0;
}

JSModuleDef *_js_init_zip_packer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_zip_packer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ZIPPacker");
	return m;
}

JSModuleDef *js_init_zip_packer_module(JSContext *ctx) {
	return _js_init_zip_packer_module(ctx, "@godot/classes/zip_packer");
}

void __register_zip_packer() {
	js_init_zip_packer_module(js_context());
}

void register_zip_packer() {
	__register_zip_packer();
}