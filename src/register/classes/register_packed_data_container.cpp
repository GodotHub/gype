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
#include <godot_cpp/classes/packed_data_container.hpp>
using namespace godot;

static void packed_data_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PackedDataContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef packed_data_container_class_def = {
    "PackedDataContainer",
    packed_data_container_class_finalizer
};

static JSValue packed_data_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PackedDataContainer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PackedDataContainer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PackedDataContainer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PackedDataContainer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue packed_data_container_class_pack(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PackedDataContainer::pack, ctx, this_val, argc, argv);
};
static JSValue packed_data_container_class_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PackedDataContainer::size, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry packed_data_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("pack", 1, &packed_data_container_class_pack),
	JS_CFUNC_DEF("size", 0, &packed_data_container_class_size),
};




static void define_packed_data_container_property(JSContext *ctx, JSValue proto) {
}

static void define_packed_data_container_enum(JSContext *ctx, JSValue ctor) {
}

static int js_packed_data_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PackedDataContainer"] = class_id;
	classes_by_id[class_id] = "PackedDataContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &packed_data_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_packed_data_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, packed_data_container_class_proto_funcs, _countof(packed_data_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, packed_data_container_class_constructor, "PackedDataContainer", 0, JS_CFUNC_constructor, 0);
	define_packed_data_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PackedDataContainer", ctor);

	return 0;
}

JSModuleDef *_js_init_packed_data_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_packed_data_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PackedDataContainer");
	return m;
}

JSModuleDef *js_init_packed_data_container_module(JSContext *ctx) {
	return _js_init_packed_data_container_module(ctx, "@godot/classes/packed_data_container");
}

void __register_packed_data_container() {
	js_init_packed_data_container_module(js_context());
}

void register_packed_data_container() {
	__register_packed_data_container();
}