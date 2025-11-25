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
#include <godot_cpp/classes/pck_packer.hpp>
using namespace godot;

static void pck_packer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PCKPacker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef pck_packer_class_def = {
    "PCKPacker",
    pck_packer_class_finalizer
};

static JSValue pck_packer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PCKPacker"];
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
        instance = memnew(PCKPacker);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue pck_packer_class_pck_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PCKPacker::pck_start, ctx, this_val, argc, argv);
};
static JSValue pck_packer_class_add_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PCKPacker::add_file, ctx, this_val, argc, argv);
};
static JSValue pck_packer_class_add_file_removal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PCKPacker::add_file_removal, ctx, this_val, argc, argv);
};
static JSValue pck_packer_class_flush(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PCKPacker::flush, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry pck_packer_class_proto_funcs[] = {
	JS_CFUNC_DEF("pck_start", 4, &pck_packer_class_pck_start),
	JS_CFUNC_DEF("add_file", 3, &pck_packer_class_add_file),
	JS_CFUNC_DEF("add_file_removal", 1, &pck_packer_class_add_file_removal),
	JS_CFUNC_DEF("flush", 1, &pck_packer_class_flush),
};




static void define_pck_packer_property(JSContext *ctx, JSValue proto) {
}

static void define_pck_packer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_pck_packer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PCKPacker"] = class_id;
	classes_by_id[class_id] = "PCKPacker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &pck_packer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_pck_packer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, pck_packer_class_proto_funcs, _countof(pck_packer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, pck_packer_class_constructor, "PCKPacker", 0, JS_CFUNC_constructor, 0);
	define_pck_packer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PCKPacker", ctor);
	ctor_list["PCKPacker"] = ctor;

	return 0;
}

JSModuleDef *_js_init_pck_packer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_pck_packer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PCKPacker");
	return m;
}

JSModuleDef *js_init_pck_packer_module(JSContext *ctx) {
	return _js_init_pck_packer_module(ctx, "@godot/classes/pck_packer");
}

void __register_pck_packer() {
	js_init_pck_packer_module(js_context());
}

void register_pck_packer() {
	__register_pck_packer();
}