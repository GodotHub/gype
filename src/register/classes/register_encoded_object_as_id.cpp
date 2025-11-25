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
#include <godot_cpp/classes/encoded_object_as_id.hpp>
using namespace godot;

static void encoded_object_as_id_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EncodedObjectAsID"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef encoded_object_as_id_class_def = {
    "EncodedObjectAsID",
    encoded_object_as_id_class_finalizer
};

static JSValue encoded_object_as_id_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EncodedObjectAsID"];
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
        instance = memnew(EncodedObjectAsID);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue encoded_object_as_id_class_set_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EncodedObjectAsID::set_object_id, ctx, this_val, argc, argv);
};
static JSValue encoded_object_as_id_class_get_object_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EncodedObjectAsID::get_object_id, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry encoded_object_as_id_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_object_id", 1, &encoded_object_as_id_class_set_object_id),
	JS_CFUNC_DEF("get_object_id", 0, &encoded_object_as_id_class_get_object_id),
};




static void define_encoded_object_as_id_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "object_id"),
        JS_NewCFunction(ctx, encoded_object_as_id_class_get_object_id, "get_object_id", 0),
        JS_NewCFunction(ctx, encoded_object_as_id_class_set_object_id, "set_object_id", 1),
        JS_PROP_GETSET
    );
}

static void define_encoded_object_as_id_enum(JSContext *ctx, JSValue ctor) {
}

static int js_encoded_object_as_id_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EncodedObjectAsID"] = class_id;
	classes_by_id[class_id] = "EncodedObjectAsID";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &encoded_object_as_id_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_encoded_object_as_id_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, encoded_object_as_id_class_proto_funcs, _countof(encoded_object_as_id_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, encoded_object_as_id_class_constructor, "EncodedObjectAsID", 0, JS_CFUNC_constructor, 0);
	define_encoded_object_as_id_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EncodedObjectAsID", ctor);
	ctor_list["EncodedObjectAsID"] = ctor;

	return 0;
}

JSModuleDef *_js_init_encoded_object_as_id_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_encoded_object_as_id_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EncodedObjectAsID");
	return m;
}

JSModuleDef *js_init_encoded_object_as_id_module(JSContext *ctx) {
	return _js_init_encoded_object_as_id_module(ctx, "@godot/classes/encoded_object_as_id");
}

void __register_encoded_object_as_id() {
	js_init_encoded_object_as_id_module(js_context());
}

void register_encoded_object_as_id() {
	__register_encoded_object_as_id();
}