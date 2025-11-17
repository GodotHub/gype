#include "register/builtin_classes/register_builtin_classes.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/variant.hpp>
#include "utils/quickjs_helper.hpp"
#include "utils/func_utils.hpp"

using namespace godot;

static void variant_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Variant"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef variant_class_def = {
	"Variant",
	variant_class_finalizer
};

static JSValue variant_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Variant"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}

	Variant instance;
	if (argc == 0) {
		instance = Variant();
	}
	else if (argc == 1) {
		VariantAdapter v0 = VariantAdapter(argv[0]);
		instance = Variant(v0);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}

static void define_variant_enum(JSContext *ctx, JSValue ctor) {
	JSValue type_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, type_obj, "NIL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, type_obj, "BOOL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, type_obj, "INT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, type_obj, "FLOAT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, type_obj, "STRING", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, type_obj, "VECTOR2", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, type_obj, "VECTOR2I", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, type_obj, "RECT2", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, type_obj, "RECT2I", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, type_obj, "VECTOR3", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, type_obj, "VECTOR3I", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, type_obj, "TRANSFORM2D", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, type_obj, "VECTOR4", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, type_obj, "VECTOR4I", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, type_obj, "PLANE", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, type_obj, "QUATERNION", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, type_obj, "AABB", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, type_obj, "BASIS", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, type_obj, "TRANSFORM3D", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, type_obj, "PROJECTION", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, type_obj, "COLOR", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, type_obj, "STRING_NAME", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, type_obj, "NODE_PATH", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, type_obj, "RID", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, type_obj, "OBJECT", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, type_obj, "CALLABLE", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, type_obj, "SIGNAL", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, type_obj, "DICTIONARY", JS_NewInt64(ctx, 27));
	JS_SetPropertyStr(ctx, type_obj, "ARRAY", JS_NewInt64(ctx, 28));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_BYTE_ARRAY", JS_NewInt64(ctx, 29));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_INT32_ARRAY", JS_NewInt64(ctx, 30));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_INT64_ARRAY", JS_NewInt64(ctx, 31));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_FLOAT32_ARRAY", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_FLOAT64_ARRAY", JS_NewInt64(ctx, 33));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_STRING_ARRAY", JS_NewInt64(ctx, 34));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_VECTOR2_ARRAY", JS_NewInt64(ctx, 35));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_VECTOR3_ARRAY", JS_NewInt64(ctx, 36));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_COLOR_ARRAY", JS_NewInt64(ctx, 37));
	JS_SetPropertyStr(ctx, type_obj, "PACKED_VECTOR4_ARRAY", JS_NewInt64(ctx, 38));
	JS_SetPropertyStr(ctx, type_obj, "VARIANT_MAX", JS_NewInt64(ctx, 39));
	JS_SetPropertyStr(ctx, ctor, "Type", type_obj);
}

static int js_variant_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Variant"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Variant";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &variant_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JSValue ctor = JS_NewCFunction2(ctx, variant_class_constructor, "Variant", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	define_variant_enum(ctx, ctor);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Variant", ctor);

	return 0;
}

static void js_init_variant_module(JSContext *ctx) {
	js_variant_class_init(ctx);
}

void register_variant() {
	js_init_variant_module(js_context());
}