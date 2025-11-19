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
#include <godot_cpp/classes/ogg_packet_sequence.hpp>
using namespace godot;

static void ogg_packet_sequence_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OggPacketSequence"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef ogg_packet_sequence_class_def = {
    "OggPacketSequence",
    ogg_packet_sequence_class_finalizer
};

static JSValue ogg_packet_sequence_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OggPacketSequence"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OggPacketSequence *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OggPacketSequence *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OggPacketSequence);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue ogg_packet_sequence_class_set_packet_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OggPacketSequence::set_packet_data, ctx, this_val, argc, argv);
};
static JSValue ogg_packet_sequence_class_get_packet_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OggPacketSequence::get_packet_data, ctx, this_val, argc, argv);
}
static JSValue ogg_packet_sequence_class_set_packet_granule_positions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OggPacketSequence::set_packet_granule_positions, ctx, this_val, argc, argv);
};
static JSValue ogg_packet_sequence_class_get_packet_granule_positions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt64Array> *proxy = memnew(ObjectProxy<PackedInt64Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt64Array {
		OggPacketSequence *obj = static_cast<OggPacketSequence *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_packet_granule_positions();
	};
	proxy->setter = [this_val](const PackedInt64Array &value) -> void {
		OggPacketSequence *js_proxy = static_cast<OggPacketSequence *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_packet_granule_positions(PackedInt64Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt64ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt64ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue ogg_packet_sequence_class_set_sampling_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OggPacketSequence::set_sampling_rate, ctx, this_val, argc, argv);
};
static JSValue ogg_packet_sequence_class_get_sampling_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OggPacketSequence::get_sampling_rate, ctx, this_val, argc, argv);
}
static JSValue ogg_packet_sequence_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OggPacketSequence::get_length, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry ogg_packet_sequence_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_packet_data", 1, &ogg_packet_sequence_class_set_packet_data),
	JS_CFUNC_DEF("get_packet_data", 0, &ogg_packet_sequence_class_get_packet_data),
	JS_CFUNC_DEF("set_packet_granule_positions", 1, &ogg_packet_sequence_class_set_packet_granule_positions),
	JS_CFUNC_DEF("get_packet_granule_positions", 0, &ogg_packet_sequence_class_get_packet_granule_positions),
	JS_CFUNC_DEF("set_sampling_rate", 1, &ogg_packet_sequence_class_set_sampling_rate),
	JS_CFUNC_DEF("get_sampling_rate", 0, &ogg_packet_sequence_class_get_sampling_rate),
	JS_CFUNC_DEF("get_length", 0, &ogg_packet_sequence_class_get_length),
};




static void define_ogg_packet_sequence_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "packet_data"),
        JS_NewCFunction(ctx, ogg_packet_sequence_class_get_packet_data, "get_packet_data", 0),
        JS_NewCFunction(ctx, ogg_packet_sequence_class_set_packet_data, "set_packet_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "granule_positions"),
        JS_NewCFunction(ctx, ogg_packet_sequence_class_get_packet_granule_positions, "get_packet_granule_positions", 0),
        JS_NewCFunction(ctx, ogg_packet_sequence_class_set_packet_granule_positions, "set_packet_granule_positions", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sampling_rate"),
        JS_NewCFunction(ctx, ogg_packet_sequence_class_get_sampling_rate, "get_sampling_rate", 0),
        JS_NewCFunction(ctx, ogg_packet_sequence_class_set_sampling_rate, "set_sampling_rate", 1),
        JS_PROP_GETSET
    );
}

static void define_ogg_packet_sequence_enum(JSContext *ctx, JSValue ctor) {
}

static int js_ogg_packet_sequence_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OggPacketSequence"] = class_id;
	classes_by_id[class_id] = "OggPacketSequence";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &ogg_packet_sequence_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_ogg_packet_sequence_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, ogg_packet_sequence_class_proto_funcs, _countof(ogg_packet_sequence_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, ogg_packet_sequence_class_constructor, "OggPacketSequence", 0, JS_CFUNC_constructor, 0);
	define_ogg_packet_sequence_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OggPacketSequence", ctor);

	return 0;
}

JSModuleDef *_js_init_ogg_packet_sequence_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_ogg_packet_sequence_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OggPacketSequence");
	return m;
}

JSModuleDef *js_init_ogg_packet_sequence_module(JSContext *ctx) {
	return _js_init_ogg_packet_sequence_module(ctx, "@godot/classes/ogg_packet_sequence");
}

void __register_ogg_packet_sequence() {
	js_init_ogg_packet_sequence_module(js_context());
}

void register_ogg_packet_sequence() {
	__register_ogg_packet_sequence();
}