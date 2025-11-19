#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_interface.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/mobile_vr_interface.hpp>
using namespace godot;

static void mobile_vr_interface_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MobileVRInterface"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef mobile_vr_interface_class_def = {
    "MobileVRInterface",
    mobile_vr_interface_class_finalizer
};

static JSValue mobile_vr_interface_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MobileVRInterface"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MobileVRInterface *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MobileVRInterface *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MobileVRInterface);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue mobile_vr_interface_class_set_eye_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_eye_height, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_eye_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_eye_height, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_iod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_iod, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_iod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_iod, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_display_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_display_width, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_display_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_display_width, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_display_to_lens(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_display_to_lens, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_display_to_lens(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_display_to_lens, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_offset_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_offset_rect, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_offset_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		MobileVRInterface *obj = static_cast<MobileVRInterface *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_offset_rect();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		MobileVRInterface *js_proxy = static_cast<MobileVRInterface *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_offset_rect(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue mobile_vr_interface_class_set_oversample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_oversample, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_oversample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_oversample, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_k1(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_k1, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_k1(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_k1, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_k2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_k2, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_k2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_k2, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_get_vrs_min_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_vrs_min_radius, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_vrs_min_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_vrs_min_radius, ctx, this_val, argc, argv);
};
static JSValue mobile_vr_interface_class_get_vrs_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MobileVRInterface::get_vrs_strength, ctx, this_val, argc, argv);
}
static JSValue mobile_vr_interface_class_set_vrs_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MobileVRInterface::set_vrs_strength, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry mobile_vr_interface_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_eye_height", 1, &mobile_vr_interface_class_set_eye_height),
	JS_CFUNC_DEF("get_eye_height", 0, &mobile_vr_interface_class_get_eye_height),
	JS_CFUNC_DEF("set_iod", 1, &mobile_vr_interface_class_set_iod),
	JS_CFUNC_DEF("get_iod", 0, &mobile_vr_interface_class_get_iod),
	JS_CFUNC_DEF("set_display_width", 1, &mobile_vr_interface_class_set_display_width),
	JS_CFUNC_DEF("get_display_width", 0, &mobile_vr_interface_class_get_display_width),
	JS_CFUNC_DEF("set_display_to_lens", 1, &mobile_vr_interface_class_set_display_to_lens),
	JS_CFUNC_DEF("get_display_to_lens", 0, &mobile_vr_interface_class_get_display_to_lens),
	JS_CFUNC_DEF("set_offset_rect", 1, &mobile_vr_interface_class_set_offset_rect),
	JS_CFUNC_DEF("get_offset_rect", 0, &mobile_vr_interface_class_get_offset_rect),
	JS_CFUNC_DEF("set_oversample", 1, &mobile_vr_interface_class_set_oversample),
	JS_CFUNC_DEF("get_oversample", 0, &mobile_vr_interface_class_get_oversample),
	JS_CFUNC_DEF("set_k1", 1, &mobile_vr_interface_class_set_k1),
	JS_CFUNC_DEF("get_k1", 0, &mobile_vr_interface_class_get_k1),
	JS_CFUNC_DEF("set_k2", 1, &mobile_vr_interface_class_set_k2),
	JS_CFUNC_DEF("get_k2", 0, &mobile_vr_interface_class_get_k2),
	JS_CFUNC_DEF("get_vrs_min_radius", 0, &mobile_vr_interface_class_get_vrs_min_radius),
	JS_CFUNC_DEF("set_vrs_min_radius", 1, &mobile_vr_interface_class_set_vrs_min_radius),
	JS_CFUNC_DEF("get_vrs_strength", 0, &mobile_vr_interface_class_get_vrs_strength),
	JS_CFUNC_DEF("set_vrs_strength", 1, &mobile_vr_interface_class_set_vrs_strength),
};




static void define_mobile_vr_interface_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "eye_height"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_eye_height, "get_eye_height", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_eye_height, "set_eye_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "iod"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_iod, "get_iod", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_iod, "set_iod", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "display_width"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_display_width, "get_display_width", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_display_width, "set_display_width", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "display_to_lens"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_display_to_lens, "get_display_to_lens", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_display_to_lens, "set_display_to_lens", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "offset_rect"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_offset_rect, "get_offset_rect", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_offset_rect, "set_offset_rect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "oversample"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_oversample, "get_oversample", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_oversample, "set_oversample", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "k1"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_k1, "get_k1", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_k1, "set_k1", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "k2"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_k2, "get_k2", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_k2, "set_k2", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_min_radius"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_vrs_min_radius, "get_vrs_min_radius", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_vrs_min_radius, "set_vrs_min_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_strength"),
        JS_NewCFunction(ctx, mobile_vr_interface_class_get_vrs_strength, "get_vrs_strength", 0),
        JS_NewCFunction(ctx, mobile_vr_interface_class_set_vrs_strength, "set_vrs_strength", 1),
        JS_PROP_GETSET
    );
}

static void define_mobile_vr_interface_enum(JSContext *ctx, JSValue ctor) {
}

static int js_mobile_vr_interface_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MobileVRInterface"] = class_id;
	classes_by_id[class_id] = "MobileVRInterface";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &mobile_vr_interface_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRInterface"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_mobile_vr_interface_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, mobile_vr_interface_class_proto_funcs, _countof(mobile_vr_interface_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, mobile_vr_interface_class_constructor, "MobileVRInterface", 0, JS_CFUNC_constructor, 0);
	define_mobile_vr_interface_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MobileVRInterface", ctor);

	return 0;
}

JSModuleDef *_js_init_mobile_vr_interface_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_interface';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_mobile_vr_interface_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MobileVRInterface");
	return m;
}

JSModuleDef *js_init_mobile_vr_interface_module(JSContext *ctx) {
	return _js_init_mobile_vr_interface_module(ctx, "@godot/classes/mobile_vr_interface");
}

void __register_mobile_vr_interface() {
	js_init_mobile_vr_interface_module(js_context());
}

void register_mobile_vr_interface() {
	__register_mobile_vr_interface();
}