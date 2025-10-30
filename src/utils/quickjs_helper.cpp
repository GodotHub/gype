#include "utils/quickjs_helper.hpp"
#include "utils/env.hpp"
#include "utils/str_helper.hpp"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

HashMap<StringName, JSClassID> classes;

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
	JS_CLASS_FLOAT16_ARRAY, /* u.array (typed_array) */
	JS_CLASS_FLOAT32_ARRAY, /* u.array (typed_array) */
	JS_CLASS_FLOAT64_ARRAY, /* u.array (typed_array) */
	JS_CLASS_DATAVIEW, /* u.typed_array */
	JS_CLASS_BIG_INT, /* u.object_data */
	JS_CLASS_MAP, /* u.map_state */
	JS_CLASS_SET, /* u.map_state */
	JS_CLASS_WEAKMAP, /* u.map_state */
	JS_CLASS_WEAKSET, /* u.map_state */
	JS_CLASS_ITERATOR, /* u.map_iterator_data */
	JS_CLASS_ITERATOR_HELPER, /* u.iterator_helper_data */
	JS_CLASS_ITERATOR_WRAP, /* u.iterator_wrap_data */
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
	JS_CLASS_WEAK_REF,
	JS_CLASS_FINALIZATION_REGISTRY,

	JS_CLASS_INIT_COUNT, /* last entry for predefined classes */
};

void print_exception(JSContext *ctx) {
    JSValue exception_val, val;
    const char *stack;

    // 1. 从 context 中获取异常对象
    exception_val = JS_GetException(ctx);

    // 2. 尝试获取 'stack' 属性，它包含最详细的信息
    val = JS_GetPropertyStr(ctx, exception_val, "stack");
    if (!JS_IsUndefined(val)) {
        stack = JS_ToCString(ctx, val);
        if (stack) {
            UtilityFunctions::print("Caught Exception: ", stack);
            JS_FreeCString(ctx, stack);
        }
    }
    JS_FreeValue(ctx, val); // 释放 'stack' 属性的 JSValue

    // 3. 如果没有 'stack'，就直接打印异常本身
    //    JS_ToCString 会自动调用 error.toString()
    if (JS_IsError(ctx, exception_val)) {
        const char *err_str = JS_ToCString(ctx, exception_val);
        if (err_str) {
            // 如果上面已经打印了 stack，这里就不用重复打印了
            // 但作为备用方案，这很有用
            // printf("Error: %s\n", err_str);
			UtilityFunctions::print(err_str);
            JS_FreeCString(ctx, err_str);
        }
    }

    // 4. 释放异常对象本身
    JS_FreeValue(ctx, exception_val);
}

bool is_exception(JSContext *ctx, JSValue exp) {
	if (JS_IsException(exp)) {
		print_exception(ctx);
		return true;
	} else {
		return false;
	}
}

static inline int64_t to_int64(JSContext *ctx, JSValue val) {
	int64_t i;
	ERR_FAIL_COND_V(JS_ToInt64(ctx, &i, val), 0);
	return i;
}

void *create_heap_copy_from_variant(const Variant &p_variant) {
	switch (p_variant.get_type()) {
		case Variant::VECTOR2:
			return memnew(Vector2(p_variant));
		case Variant::VECTOR2I:
			return memnew(Vector2i(p_variant));
		case Variant::VECTOR3:
			return memnew(Vector3(p_variant));
		case Variant::VECTOR3I:
			return memnew(Vector3i(p_variant));
		case Variant::VECTOR4:
			return memnew(Vector4(p_variant));
		case Variant::VECTOR4I:
			return memnew(Vector4i(p_variant));
		case Variant::AABB:
			return memnew(AABB(p_variant));
		case Variant::BASIS:
			return memnew(Basis(p_variant));
		case Variant::CALLABLE:
			return memnew(Callable(p_variant));
		case Variant::COLOR:
			return memnew(Color(p_variant));
		case Variant::DICTIONARY:
			return memnew(Dictionary(p_variant));
		case Variant::NODE_PATH:
			return memnew(NodePath(p_variant));
		case Variant::PLANE:
			return memnew(Plane(p_variant));
		case Variant::PROJECTION:
			return memnew(Projection(p_variant));
		case Variant::QUATERNION:
			return memnew(Quaternion(p_variant));
		case Variant::RECT2:
			return memnew(Rect2(p_variant));
		case Variant::RECT2I:
			return memnew(Rect2i(p_variant));
		case Variant::RID:
			return memnew(RID(p_variant));
		case Variant::SIGNAL:
			return memnew(Signal(p_variant));
		case Variant::TRANSFORM2D:
			return memnew(Transform2D(p_variant));
		case Variant::TRANSFORM3D:
			return memnew(Transform3D(p_variant));
		case Variant::PACKED_BYTE_ARRAY:
			return memnew(PackedByteArray(p_variant));
		case Variant::PACKED_COLOR_ARRAY:
			return memnew(PackedColorArray(p_variant));
		case Variant::PACKED_FLOAT32_ARRAY:
			return memnew(PackedFloat32Array(p_variant));
		case Variant::PACKED_FLOAT64_ARRAY:
			return memnew(PackedFloat64Array(p_variant));
		case Variant::PACKED_INT32_ARRAY:
			return memnew(PackedInt32Array(p_variant));
		case Variant::PACKED_INT64_ARRAY:
			return memnew(PackedInt64Array(p_variant));
		case Variant::PACKED_STRING_ARRAY:
			return memnew(PackedStringArray(p_variant));
		case Variant::PACKED_VECTOR2_ARRAY:
			return memnew(PackedVector2Array(p_variant));
		case Variant::PACKED_VECTOR3_ARRAY:
			return memnew(PackedVector3Array(p_variant));
		case Variant::PACKED_VECTOR4_ARRAY:
			return memnew(PackedVector4Array(p_variant));
		default:
			// 对于不支持的类型，返回 nullptr
			return nullptr;
	}
}

JSValue variant_to_jsvalue(const Variant &val) {
	Variant::Type type = val.get_type();
	String type_name = Variant::get_type_name(type);
	switch (type) {
		case Variant::Type::NIL:
			return JS_UNDEFINED;
		case Variant::Type::INT:
			return JS_NewInt64(js_context(), val);
		case Variant::Type::FLOAT:
			return JS_NewFloat64(js_context(), val);
		case Variant::Type::BOOL:
			return JS_NewBool(js_context(), val);
		case Variant::Type::STRING:
			return JS_NewString(js_context(), to_chars(String(val)));
		case Variant::Type::STRING_NAME:
			return JS_NewString(js_context(), to_chars(StringName(val)));
		case Variant::Type::VECTOR2:
		case Variant::Type::VECTOR2I:
		case Variant::Type::VECTOR3:
		case Variant::Type::VECTOR3I:
		case Variant::Type::VECTOR4:
		case Variant::Type::VECTOR4I:
		case Variant::Type::AABB:
		case Variant::Type::BASIS:
		case Variant::Type::CALLABLE:
		case Variant::Type::COLOR:
		case Variant::Type::DICTIONARY:
		case Variant::Type::NODE_PATH:
		case Variant::Type::PLANE:
		case Variant::Type::PROJECTION:
		case Variant::Type::QUATERNION:
		case Variant::Type::RECT2:
		case Variant::Type::RECT2I:
		case Variant::Type::RID:
		case Variant::Type::SIGNAL:
		case Variant::Type::TRANSFORM2D:
		case Variant::Type::TRANSFORM3D:
		case Variant::Type::PACKED_BYTE_ARRAY:
		case Variant::Type::PACKED_COLOR_ARRAY:
		case Variant::Type::PACKED_FLOAT32_ARRAY:
		case Variant::Type::PACKED_FLOAT64_ARRAY:
		case Variant::Type::PACKED_INT32_ARRAY:
		case Variant::Type::PACKED_INT64_ARRAY:
		case Variant::Type::PACKED_STRING_ARRAY:
		case Variant::Type::PACKED_VECTOR2_ARRAY:
		case Variant::Type::PACKED_VECTOR3_ARRAY:
		case Variant::Type::PACKED_VECTOR4_ARRAY: {
			void *gd_obj_copy = const_cast<Variant *>(&val);
			if (!gd_obj_copy) {
				return JS_UNDEFINED;
			}
			String type_name = Variant::get_type_name(type);
			JSClassID class_id = classes[type_name];
			JSValue js_obj = JS_NewObjectClass(js_context(), class_id);
			JS_SetOpaque(js_obj, gd_obj_copy);
			return js_obj;
		}
		case Variant::Type::ARRAY: {
			Array arr = val;
			JSValue js_arr = JS_NewArray(js_context());
			for (int i = 0; i < arr.size(); i++) {
				JS_SetPropertyUint32(js_context(), js_arr, i, variant_to_jsvalue(arr[i]));
			}
			return js_arr;
		}
		case Variant::Type::OBJECT: {
			Object *obj = val;
			if (obj) {
				const char *class_name = to_chars(obj->get_class());
				char code[1024];
				sprintf(code, "import { %s } from \"@godot/classes/%s\";", class_name, camelToSnake(class_name).c_str());
				JS_Eval(js_context(), code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
				JSClassID class_id = classes[class_name];
				JSValue js_obj = JS_NewObjectClass(js_context(), class_id);
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

static inline Variant js_obj_to_variant(JSValue val) {
#define CASE_TO_VARIANT_CASE(type)                                     \
	else if (class_id == classes[#type]) {                             \
		return *reinterpret_cast<type *>(JS_GetOpaque(val, class_id)); \
	}

	JSClassID class_id = JS_GetClassID(val);
	if (JS_IsArray(js_context(), val)) {
		Array gd_arr;
		JSValue js_len = JS_GetPropertyStr(js_context(), val, "length");
		int64_t len = to_int64(js_context(), js_len);
		for (int64_t i = 0; i < len; i++) {
			JSValue el = JS_GetPropertyUint32(js_context(), val, i);
			gd_arr.append(js_obj_to_variant(el));
		}
		JS_FreeValue(js_context(), js_len);
		return gd_arr;
	}
	CASE_TO_VARIANT_CASE(Vector2)
	CASE_TO_VARIANT_CASE(Vector2i)
	CASE_TO_VARIANT_CASE(Vector3)
	CASE_TO_VARIANT_CASE(Vector3i)
	CASE_TO_VARIANT_CASE(Vector4)
	CASE_TO_VARIANT_CASE(Vector4i)
	CASE_TO_VARIANT_CASE(AABB)
	CASE_TO_VARIANT_CASE(Callable)
	CASE_TO_VARIANT_CASE(Basis)
	CASE_TO_VARIANT_CASE(Dictionary)
	CASE_TO_VARIANT_CASE(Color)
	CASE_TO_VARIANT_CASE(NodePath)
	CASE_TO_VARIANT_CASE(Plane)
	CASE_TO_VARIANT_CASE(Projection)
	CASE_TO_VARIANT_CASE(Quaternion)
	CASE_TO_VARIANT_CASE(Rect2)
	CASE_TO_VARIANT_CASE(Rect2i)
	CASE_TO_VARIANT_CASE(RID)
	CASE_TO_VARIANT_CASE(Signal)
	CASE_TO_VARIANT_CASE(Transform2D)
	CASE_TO_VARIANT_CASE(Transform3D)
	CASE_TO_VARIANT_CASE(String)
	CASE_TO_VARIANT_CASE(StringName)
	else {
		return Variant(reinterpret_cast<Object *>(JS_GetOpaque(val, class_id)));
	}
}

Variant jsvalue_to_variant(JSValue val) {
	int tag = JS_VALUE_GET_TAG(val);
	switch (tag) {
		case JS_TAG_INT: {
			int64_t i;
			ERR_FAIL_COND_V(JS_ToInt64(js_context(), &i, val), 0);
			return i;
		}
		case JS_TAG_FLOAT64: {
			double i;
			ERR_FAIL_COND_V(JS_ToFloat64(js_context(), &i, val), 0);
			return i;
		}
		case JS_TAG_BOOL:
			return JS_ToBool(js_context(), val);
		case JS_TAG_STRING:
			return JS_ToCString(js_context(), val);
		case JS_TAG_OBJECT:
			return js_obj_to_variant(val);
		case JS_TAG_UNDEFINED:
		case JS_TAG_NULL:
		case JS_TAG_UNINITIALIZED:
			return Variant();
		default:
			ERR_FAIL_V(Variant());
	}
}
