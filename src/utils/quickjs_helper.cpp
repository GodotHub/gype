#include "utils/quickjs_helper.hpp"
#include "quickjs/env.h"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <unordered_map>

HashSet<int> class_id_list;
// <class_name, JSClassID>
HashMap<StringName, JSClassID> classes;

using namespace godot;

enum {
	/* classid tag        */ /* union usage   | properties */
	JS_CLASS_OBJECT = 1, /* must be first */
	JS_CLASS_ARRAY, /* u.array       | length */
	JS_CLASS_ERROR,
	JS_CLASS_NUMBER, /* u.object_data */
	JS_CLASS_STRING, /* u.object_data */
	JS_CLASS_BOOLEAN, /* u.object_data */
	JS_CLASS_SYMBOL, /* u.object_data */
	JS_CLASS_ARGUMENTS, /* u.array       | length */
	JS_CLASS_MAPPED_ARGUMENTS, /*               | length */
	JS_CLASS_DATE, /* u.object_data */
	JS_CLASS_MODULE_NS,
	JS_CLASS_C_FUNCTION, /* u.cfunc */
	JS_CLASS_BYTECODE_FUNCTION, /* u.func */
	JS_CLASS_BOUND_FUNCTION, /* u.bound_function */
	JS_CLASS_C_FUNCTION_DATA, /* u.c_function_data_record */
	JS_CLASS_GENERATOR_FUNCTION, /* u.func */
	JS_CLASS_FOR_IN_ITERATOR, /* u.for_in_iterator */
	JS_CLASS_REGEXP, /* u.regexp */
	JS_CLASS_ARRAY_BUFFER, /* u.array_buffer */
	JS_CLASS_SHARED_ARRAY_BUFFER, /* u.array_buffer */
	JS_CLASS_UINT8C_ARRAY, /* u.array (typed_array) */
	JS_CLASS_INT8_ARRAY, /* u.array (typed_array) */
	JS_CLASS_UINT8_ARRAY, /* u.array (typed_array) */
	JS_CLASS_INT16_ARRAY, /* u.array (typed_array) */
	JS_CLASS_UINT16_ARRAY, /* u.array (typed_array) */
	JS_CLASS_INT32_ARRAY, /* u.array (typed_array) */
	JS_CLASS_UINT32_ARRAY, /* u.array (typed_array) */
	JS_CLASS_BIG_INT64_ARRAY, /* u.array (typed_array) */
	JS_CLASS_BIG_UINT64_ARRAY, /* u.array (typed_array) */
	JS_CLASS_FLOAT32_ARRAY, /* u.array (typed_array) */
	JS_CLASS_FLOAT64_ARRAY, /* u.array (typed_array) */
	JS_CLASS_DATAVIEW, /* u.typed_array */
	JS_CLASS_BIG_INT, /* u.object_data */
#ifdef CONFIG_BIGNUM
	JS_CLASS_BIG_FLOAT, /* u.object_data */
	JS_CLASS_FLOAT_ENV, /* u.float_env */
	JS_CLASS_BIG_DECIMAL, /* u.object_data */
	JS_CLASS_OPERATOR_SET, /* u.operator_set */
#endif
	JS_CLASS_MAP, /* u.map_state */
	JS_CLASS_SET, /* u.map_state */
	JS_CLASS_WEAKMAP, /* u.map_state */
	JS_CLASS_WEAKSET, /* u.map_state */
	JS_CLASS_MAP_ITERATOR, /* u.map_iterator_data */
	JS_CLASS_SET_ITERATOR, /* u.map_iterator_data */
	JS_CLASS_ARRAY_ITERATOR, /* u.array_iterator_data */
	JS_CLASS_STRING_ITERATOR, /* u.array_iterator_data */
	JS_CLASS_REGEXP_STRING_ITERATOR, /* u.regexp_string_iterator_data */
	JS_CLASS_GENERATOR, /* u.generator_data */
	JS_CLASS_PROXY, /* u.proxy_data */
	JS_CLASS_PROMISE, /* u.promise_data */
	JS_CLASS_PROMISE_RESOLVE_FUNCTION, /* u.promise_function_data */
	JS_CLASS_PROMISE_REJECT_FUNCTION, /* u.promise_function_data */
	JS_CLASS_ASYNC_FUNCTION, /* u.func */
	JS_CLASS_ASYNC_FUNCTION_RESOLVE, /* u.async_function_data */
	JS_CLASS_ASYNC_FUNCTION_REJECT, /* u.async_function_data */
	JS_CLASS_ASYNC_FROM_SYNC_ITERATOR, /* u.async_from_sync_iterator_data */
	JS_CLASS_ASYNC_GENERATOR_FUNCTION, /* u.func */
	JS_CLASS_ASYNC_GENERATOR, /* u.async_generator_data */

	JS_CLASS_INIT_COUNT, /* last entry for predefined classes */
};

#define CREATE_OBJECT_FUNC(type)                           \
	static JSValue create_##type##_obj(Variant val) {      \
		type *obj = memnew(type());                        \
		memnew_placement(obj, type(val));                  \
		JSClassID class_id = classes[#type];               \
		JSValue js_obj = JS_NewObjectClass(ctx, class_id); \
		JS_SetOpaque(js_obj, obj);                         \
		return js_obj;                                     \
	}
Variant JSArray_to_PackedArray(JSValue val);
Variant any_to_variant(JSValue val);
Variant obj_to_variant(JSValue val);
JSValue packed_to_jsvalue(const Variant val);
CREATE_OBJECT_FUNC(Vector2);
CREATE_OBJECT_FUNC(Vector2i);
CREATE_OBJECT_FUNC(Vector3);
CREATE_OBJECT_FUNC(Vector3i);
CREATE_OBJECT_FUNC(Vector4);
CREATE_OBJECT_FUNC(Vector4i);
CREATE_OBJECT_FUNC(AABB);
CREATE_OBJECT_FUNC(Rect2);
CREATE_OBJECT_FUNC(Rect2i);
CREATE_OBJECT_FUNC(Transform2D);
CREATE_OBJECT_FUNC(Transform3D);
CREATE_OBJECT_FUNC(Plane);
CREATE_OBJECT_FUNC(Quaternion);
CREATE_OBJECT_FUNC(Basis);
CREATE_OBJECT_FUNC(Projection);
CREATE_OBJECT_FUNC(Color);
CREATE_OBJECT_FUNC(NodePath);
CREATE_OBJECT_FUNC(RID);
CREATE_OBJECT_FUNC(Callable);
CREATE_OBJECT_FUNC(Signal);
CREATE_OBJECT_FUNC(Dictionary);
CREATE_OBJECT_FUNC(PackedByteArray);
CREATE_OBJECT_FUNC(PackedColorArray);
CREATE_OBJECT_FUNC(PackedFloat32Array);
CREATE_OBJECT_FUNC(PackedFloat64Array);
CREATE_OBJECT_FUNC(PackedInt32Array);
CREATE_OBJECT_FUNC(PackedInt64Array);
CREATE_OBJECT_FUNC(PackedStringArray);
CREATE_OBJECT_FUNC(PackedVector2Array);
CREATE_OBJECT_FUNC(PackedVector3Array);
CREATE_OBJECT_FUNC(PackedVector4Array);

bool is_int(JSContext *ctx, JSValue value) {
	return JS_VALUE_GET_TAG(value) == JS_TAG_INT;
}

bool is_float(JSContext *ctx, JSValue value) {
	return JS_VALUE_GET_TAG(value) == JS_TAG_FLOAT64;
}

int64_t to_int64(JSContext *ctx, JSValue val) {
	int64_t i;
	ERR_FAIL_COND_V(JS_ToInt64(ctx, &i, val), 0);
	return i;
}

void print_exception(JSContext *ctx) {
	JSValue exp = JS_GetException(ctx);
	JSValue message = JS_GetPropertyStr(ctx, exp, "message");
	JSValue stack = JS_GetPropertyStr(ctx, exp, "stack");
	const char *mssage_str = JS_ToCString(ctx, message);
	const char *stack_str = JS_ToCString(ctx, stack);
	UtilityFunctions::print(mssage_str);
	UtilityFunctions::print(stack_str);
	JS_FreeValue(ctx, exp);
	JS_FreeValue(ctx, message);
	JS_FreeValue(ctx, stack);
	JS_FreeCString(ctx, mssage_str);
	JS_FreeCString(ctx, stack_str);
}

bool is_exception(JSContext *ctx, JSValue exp) {
	if (JS_IsException(exp)) {
		print_exception(ctx);
		return true;
	} else {
		return false;
	}
}

Variant any_to_variant(JSValue val) {
	int tag = JS_VALUE_GET_TAG(val);
	switch (tag) {
		case JS_TAG_INT: {
			int64_t i;
			ERR_FAIL_COND_V(JS_ToInt64(ctx, &i, val), 0);
			return i;
		}
		case JS_TAG_FLOAT64: {
			double i;
			ERR_FAIL_COND_V(JS_ToFloat64(ctx, &i, val), 0);
			return i;
		}
		case JS_TAG_BOOL:
			return JS_ToBool(ctx, val);
		case JS_TAG_STRING:
			return JS_ToCString(ctx, val);
		case JS_TAG_OBJECT:
			return obj_to_variant(val);
		case JS_TAG_UNDEFINED:
		case JS_TAG_NULL:
		case JS_TAG_UNINITIALIZED:
			return Variant();
		default:
			ERR_FAIL_V(Variant());
	}
}

#define CASE_TO_VARIANT(type, val)                                               \
	{                                                                            \
		int class_id = JS_GetClassID(val);                                       \
		if (class_id == classes[#type]) {                                        \
			return type(*reinterpret_cast<type *>(JS_GetOpaque(val, class_id))); \
		}                                                                        \
	}

Variant obj_to_variant(JSValue val) {
	CASE_TO_VARIANT(Vector2, val);
	CASE_TO_VARIANT(Vector2i, val);
	CASE_TO_VARIANT(Vector3, val);
	CASE_TO_VARIANT(Vector3i, val);
	CASE_TO_VARIANT(Vector4, val);
	CASE_TO_VARIANT(Vector4i, val);
	CASE_TO_VARIANT(AABB, val);
	CASE_TO_VARIANT(Callable, val);
	CASE_TO_VARIANT(Basis, val);
	CASE_TO_VARIANT(Dictionary, val);
	CASE_TO_VARIANT(Color, val);
	CASE_TO_VARIANT(NodePath, val);
	CASE_TO_VARIANT(Plane, val);
	CASE_TO_VARIANT(Projection, val);
	CASE_TO_VARIANT(Quaternion, val);
	CASE_TO_VARIANT(Rect2, val);
	CASE_TO_VARIANT(Rect2i, val);
	CASE_TO_VARIANT(RID, val);
	CASE_TO_VARIANT(Signal, val);
	CASE_TO_VARIANT(Transform2D, val);
	CASE_TO_VARIANT(Transform3D, val);
	CASE_TO_VARIANT(String, val);
	CASE_TO_VARIANT(StringName, val);
	// not match Variant case
	int class_id = JS_GetClassID(val);
	switch (class_id) {
		case JS_CLASS_ARRAY: {
			Array gd_arr;
			JSValue js_len = JS_GetPropertyStr(ctx, val, "length");
			int64_t len = to_int64(ctx, js_len);
			for (int64_t i = 0; i < len; i++) {
				JSValue el = JS_GetPropertyUint32(ctx, val, i);
				gd_arr.append(any_to_variant(el));
			}
			JS_FreeValue(ctx, js_len);
			return gd_arr;
		}
		default: {
			// TODO Ref<>会有提前释放的BUG
			return Variant(reinterpret_cast<Object *>(JS_GetOpaque(val, class_id)));
		}
	}
}

JSValue any_to_jsvalue(const Variant &val) {
	Variant::Type type = val.get_type();
	switch (type) {
		case Variant::Type::NIL:
			return JS_UNDEFINED;
		case Variant::Type::INT:
			return JS_NewInt64(ctx, val);
		case Variant::Type::FLOAT:
			return JS_NewFloat64(ctx, val);
		case Variant::Type::BOOL:
			return JS_NewBool(ctx, val);
		case Variant::Type::STRING:
			return JS_NewString(ctx, to_chars(String(val)));
		case Variant::Type::STRING_NAME:
			return JS_NewString(ctx, to_chars(StringName(val)));
		case Variant::Type::VECTOR2:
			return create_Vector2_obj(val);
		case Variant::Type::VECTOR2I:
			return create_Vector2i_obj(val);
		case Variant::Type::VECTOR3:
			return create_Vector3_obj(val);
		case Variant::Type::VECTOR3I:
			return create_Vector3i_obj(val);
		case Variant::Type::VECTOR4:
			return create_Vector4_obj(val);
		case Variant::Type::VECTOR4I:
			return create_Vector4i_obj(val);
		case Variant::Type::AABB:
			return create_AABB_obj(val);
		case Variant::Type::BASIS:
			return create_Basis_obj(val);
		case Variant::Type::CALLABLE:
			return create_Callable_obj(val);
		case Variant::Type::COLOR:
			return create_Color_obj(val);
		case Variant::Type::DICTIONARY:
			return create_Dictionary_obj(val);
		case Variant::Type::NODE_PATH:
			return create_NodePath_obj(val);
		case Variant::Type::PLANE:
			return create_Plane_obj(val);
		case Variant::Type::PROJECTION:
			return create_Projection_obj(val);
		case Variant::Type::QUATERNION:
			return create_Quaternion_obj(val);
		case Variant::Type::RECT2:
			return create_Rect2_obj(val);
		case Variant::Type::RECT2I:
			return create_Rect2i_obj(val);
		case Variant::Type::RID:
			return create_RID_obj(val);
		case Variant::Type::SIGNAL:
			return create_Signal_obj(val);
		case Variant::Type::TRANSFORM2D:
			return create_Transform2D_obj(val);
		case Variant::Type::TRANSFORM3D:
			return create_Transform3D_obj(val);
		case Variant::PACKED_BYTE_ARRAY:
			return create_PackedByteArray_obj(val);
		case Variant::PACKED_COLOR_ARRAY:
			return create_PackedColorArray_obj(val);
		case Variant::PACKED_FLOAT32_ARRAY:
			return create_PackedFloat32Array_obj(val);
		case Variant::PACKED_FLOAT64_ARRAY:
			return create_PackedFloat64Array_obj(val);
		case Variant::PACKED_INT32_ARRAY:
			return create_PackedInt32Array_obj(val);
		case Variant::PACKED_INT64_ARRAY:
			return create_PackedInt64Array_obj(val);
		case Variant::PACKED_STRING_ARRAY:
			return create_PackedStringArray_obj(val);
		case Variant::PACKED_VECTOR2_ARRAY:
			return create_PackedVector2Array_obj(val);
		case Variant::PACKED_VECTOR3_ARRAY:
			return create_PackedVector3Array_obj(val);
		case Variant::PACKED_VECTOR4_ARRAY:
			return create_PackedVector4Array_obj(val);
		case Variant::Type::VARIANT_MAX:
			return VariantAdapter(val);
		case Variant::Type::ARRAY: {
			Array arr = val;
			JSValue js_arr = JS_NewArray(ctx);
			for (int i = 0; i < arr.size(); i++) {
				JS_SetPropertyUint32(ctx, js_arr, i, any_to_jsvalue(arr[i]));
			}
			return js_arr;
		}
		case Variant::Type::OBJECT: {
			Object *obj = val;
			if (obj) {
				const char *class_name = to_chars(obj->get_class());
				char code[1024];
				sprintf(code, "import { %s } from \"@godot/classes/%s\";", class_name, camelToSnake(class_name).c_str());
				JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
				JSClassID class_id = classes[class_name];
				JSValue js_obj = JS_NewObjectClass(ctx, class_id);
				JS_SetOpaque(js_obj, obj);
				return js_obj;
			}
			return JS_UNDEFINED;
		}
		default: {
			return JS_UNDEFINED;
		}
	}
}
