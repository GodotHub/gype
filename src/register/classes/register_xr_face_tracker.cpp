#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_tracker.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_face_tracker.hpp>
using namespace godot;

static void xr_face_tracker_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRFaceTracker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_face_tracker_class_def = {
    "XRFaceTracker",
    xr_face_tracker_class_finalizer
};

static JSValue xr_face_tracker_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRFaceTracker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XRFaceTracker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XRFaceTracker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XRFaceTracker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_face_tracker_class_get_blend_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRFaceTracker::get_blend_shape, ctx, this_val, argc, argv);
};
static JSValue xr_face_tracker_class_set_blend_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRFaceTracker::set_blend_shape, ctx, this_val, argc, argv);
};
static JSValue xr_face_tracker_class_get_blend_shapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedFloat32Array> *proxy = memnew(ObjectProxy<PackedFloat32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedFloat32Array {
		XRFaceTracker *obj = static_cast<XRFaceTracker *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_blend_shapes();
	};
	proxy->setter = [this_val](const PackedFloat32Array &value) -> void {
		XRFaceTracker *js_proxy = static_cast<XRFaceTracker *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_blend_shapes(PackedFloat32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedFloat32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedFloat32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue xr_face_tracker_class_set_blend_shapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRFaceTracker::set_blend_shapes, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xr_face_tracker_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_blend_shape", 1, &xr_face_tracker_class_get_blend_shape),
	JS_CFUNC_DEF("set_blend_shape", 2, &xr_face_tracker_class_set_blend_shape),
	JS_CFUNC_DEF("get_blend_shapes", 0, &xr_face_tracker_class_get_blend_shapes),
	JS_CFUNC_DEF("set_blend_shapes", 1, &xr_face_tracker_class_set_blend_shapes),
};




static void define_xr_face_tracker_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_shapes"),
        JS_NewCFunction(ctx, xr_face_tracker_class_get_blend_shapes, "get_blend_shapes", 0),
        JS_NewCFunction(ctx, xr_face_tracker_class_set_blend_shapes, "set_blend_shapes", 1),
        JS_PROP_GETSET
    );
}

static void define_xr_face_tracker_enum(JSContext *ctx, JSValue ctor) {
	JSValue BlendShapeEntry_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_OUT_RIGHT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_IN_RIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_UP_RIGHT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_DOWN_RIGHT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_OUT_LEFT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_IN_LEFT", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_UP_LEFT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_LOOK_DOWN_LEFT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_CLOSED_RIGHT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_CLOSED_LEFT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_SQUINT_RIGHT", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_SQUINT_LEFT", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_WIDE_RIGHT", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_WIDE_LEFT", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_DILATION_RIGHT", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_DILATION_LEFT", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_CONSTRICT_RIGHT", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_CONSTRICT_LEFT", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_PINCH_RIGHT", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_PINCH_LEFT", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_LOWERER_RIGHT", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_LOWERER_LEFT", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_INNER_UP_RIGHT", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_INNER_UP_LEFT", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_OUTER_UP_RIGHT", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_OUTER_UP_LEFT", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NOSE_SNEER_RIGHT", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NOSE_SNEER_LEFT", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NASAL_DILATION_RIGHT", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NASAL_DILATION_LEFT", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NASAL_CONSTRICT_RIGHT", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NASAL_CONSTRICT_LEFT", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_SQUINT_RIGHT", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_SQUINT_LEFT", JS_NewInt64(ctx, 33));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_PUFF_RIGHT", JS_NewInt64(ctx, 34));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_PUFF_LEFT", JS_NewInt64(ctx, 35));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_SUCK_RIGHT", JS_NewInt64(ctx, 36));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_SUCK_LEFT", JS_NewInt64(ctx, 37));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_OPEN", JS_NewInt64(ctx, 38));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_CLOSED", JS_NewInt64(ctx, 39));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_RIGHT", JS_NewInt64(ctx, 40));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_LEFT", JS_NewInt64(ctx, 41));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_FORWARD", JS_NewInt64(ctx, 42));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_BACKWARD", JS_NewInt64(ctx, 43));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_CLENCH", JS_NewInt64(ctx, 44));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_JAW_MANDIBLE_RAISE", JS_NewInt64(ctx, 45));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_UPPER_RIGHT", JS_NewInt64(ctx, 46));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_UPPER_LEFT", JS_NewInt64(ctx, 47));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_LOWER_RIGHT", JS_NewInt64(ctx, 48));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_LOWER_LEFT", JS_NewInt64(ctx, 49));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_CORNER_RIGHT", JS_NewInt64(ctx, 50));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_CORNER_LEFT", JS_NewInt64(ctx, 51));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL_UPPER_RIGHT", JS_NewInt64(ctx, 52));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL_UPPER_LEFT", JS_NewInt64(ctx, 53));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL_LOWER_RIGHT", JS_NewInt64(ctx, 54));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL_LOWER_LEFT", JS_NewInt64(ctx, 55));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER_UPPER_RIGHT", JS_NewInt64(ctx, 56));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER_UPPER_LEFT", JS_NewInt64(ctx, 57));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER_LOWER_RIGHT", JS_NewInt64(ctx, 58));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER_LOWER_LEFT", JS_NewInt64(ctx, 59));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_UP_RIGHT", JS_NewInt64(ctx, 60));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_UP_LEFT", JS_NewInt64(ctx, 61));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_LOWER_DOWN_RIGHT", JS_NewInt64(ctx, 62));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_LOWER_DOWN_LEFT", JS_NewInt64(ctx, 63));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_DEEPEN_RIGHT", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_DEEPEN_LEFT", JS_NewInt64(ctx, 65));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_RIGHT", JS_NewInt64(ctx, 66));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_LEFT", JS_NewInt64(ctx, 67));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_LOWER_RIGHT", JS_NewInt64(ctx, 68));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_LOWER_LEFT", JS_NewInt64(ctx, 69));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_CORNER_PULL_RIGHT", JS_NewInt64(ctx, 70));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_CORNER_PULL_LEFT", JS_NewInt64(ctx, 71));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_CORNER_SLANT_RIGHT", JS_NewInt64(ctx, 72));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_CORNER_SLANT_LEFT", JS_NewInt64(ctx, 73));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_FROWN_RIGHT", JS_NewInt64(ctx, 74));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_FROWN_LEFT", JS_NewInt64(ctx, 75));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_STRETCH_RIGHT", JS_NewInt64(ctx, 76));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_STRETCH_LEFT", JS_NewInt64(ctx, 77));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_DIMPLE_RIGHT", JS_NewInt64(ctx, 78));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_DIMPLE_LEFT", JS_NewInt64(ctx, 79));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_RAISER_UPPER", JS_NewInt64(ctx, 80));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_RAISER_LOWER", JS_NewInt64(ctx, 81));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_PRESS_RIGHT", JS_NewInt64(ctx, 82));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_PRESS_LEFT", JS_NewInt64(ctx, 83));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_TIGHTENER_RIGHT", JS_NewInt64(ctx, 84));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_TIGHTENER_LEFT", JS_NewInt64(ctx, 85));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_OUT", JS_NewInt64(ctx, 86));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_UP", JS_NewInt64(ctx, 87));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_DOWN", JS_NewInt64(ctx, 88));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_RIGHT", JS_NewInt64(ctx, 89));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_LEFT", JS_NewInt64(ctx, 90));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_ROLL", JS_NewInt64(ctx, 91));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_BLEND_DOWN", JS_NewInt64(ctx, 92));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_CURL_UP", JS_NewInt64(ctx, 93));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_SQUISH", JS_NewInt64(ctx, 94));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_FLAT", JS_NewInt64(ctx, 95));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_TWIST_RIGHT", JS_NewInt64(ctx, 96));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_TONGUE_TWIST_LEFT", JS_NewInt64(ctx, 97));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_SOFT_PALATE_CLOSE", JS_NewInt64(ctx, 98));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_THROAT_SWALLOW", JS_NewInt64(ctx, 99));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NECK_FLEX_RIGHT", JS_NewInt64(ctx, 100));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NECK_FLEX_LEFT", JS_NewInt64(ctx, 101));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_CLOSED", JS_NewInt64(ctx, 102));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_WIDE", JS_NewInt64(ctx, 103));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_SQUINT", JS_NewInt64(ctx, 104));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_DILATION", JS_NewInt64(ctx, 105));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_EYE_CONSTRICT", JS_NewInt64(ctx, 106));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_DOWN_RIGHT", JS_NewInt64(ctx, 107));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_DOWN_LEFT", JS_NewInt64(ctx, 108));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_DOWN", JS_NewInt64(ctx, 109));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_UP_RIGHT", JS_NewInt64(ctx, 110));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_UP_LEFT", JS_NewInt64(ctx, 111));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_BROW_UP", JS_NewInt64(ctx, 112));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NOSE_SNEER", JS_NewInt64(ctx, 113));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NASAL_DILATION", JS_NewInt64(ctx, 114));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_NASAL_CONSTRICT", JS_NewInt64(ctx, 115));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_PUFF", JS_NewInt64(ctx, 116));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_SUCK", JS_NewInt64(ctx, 117));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_CHEEK_SQUINT", JS_NewInt64(ctx, 118));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_UPPER", JS_NewInt64(ctx, 119));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK_LOWER", JS_NewInt64(ctx, 120));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_SUCK", JS_NewInt64(ctx, 121));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL_UPPER", JS_NewInt64(ctx, 122));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL_LOWER", JS_NewInt64(ctx, 123));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_FUNNEL", JS_NewInt64(ctx, 124));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER_UPPER", JS_NewInt64(ctx, 125));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER_LOWER", JS_NewInt64(ctx, 126));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_LIP_PUCKER", JS_NewInt64(ctx, 127));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_UPPER_UP", JS_NewInt64(ctx, 128));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_LOWER_DOWN", JS_NewInt64(ctx, 129));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_OPEN", JS_NewInt64(ctx, 130));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_RIGHT", JS_NewInt64(ctx, 131));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_LEFT", JS_NewInt64(ctx, 132));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_SMILE_RIGHT", JS_NewInt64(ctx, 133));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_SMILE_LEFT", JS_NewInt64(ctx, 134));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_SMILE", JS_NewInt64(ctx, 135));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_SAD_RIGHT", JS_NewInt64(ctx, 136));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_SAD_LEFT", JS_NewInt64(ctx, 137));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_SAD", JS_NewInt64(ctx, 138));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_STRETCH", JS_NewInt64(ctx, 139));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_DIMPLE", JS_NewInt64(ctx, 140));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_TIGHTENER", JS_NewInt64(ctx, 141));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MOUTH_PRESS", JS_NewInt64(ctx, 142));
	JS_SetPropertyStr(ctx, BlendShapeEntry_obj, "FT_MAX", JS_NewInt64(ctx, 143));
	JS_SetPropertyStr(ctx, ctor, "BlendShapeEntry", BlendShapeEntry_obj);
}

static int js_xr_face_tracker_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRFaceTracker"] = class_id;
	classes_by_id[class_id] = "XRFaceTracker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_face_tracker_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRTracker"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_face_tracker_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_face_tracker_class_proto_funcs, _countof(xr_face_tracker_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_face_tracker_class_constructor, "XRFaceTracker", 0, JS_CFUNC_constructor, 0);
	define_xr_face_tracker_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRFaceTracker", ctor);

	return 0;
}

JSModuleDef *_js_init_xr_face_tracker_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_tracker';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_face_tracker_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRFaceTracker");
	return m;
}

JSModuleDef *js_init_xr_face_tracker_module(JSContext *ctx) {
	return _js_init_xr_face_tracker_module(ctx, "@godot/classes/xr_face_tracker");
}

void __register_xr_face_tracker() {
	js_init_xr_face_tracker_module(js_context());
}

void register_xr_face_tracker() {
	__register_xr_face_tracker();
}