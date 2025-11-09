#ifndef __VARIANT_HELPER_H__
#define __VARIANT_HELPER_H__

#include "utils/env.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/core/type_info.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <type_traits>

namespace godot {
class Variant;
class Object;
} //namespace godot

extern godot::HashMap<godot::StringName, JSClassID> classes;
extern godot::HashMap<JSClassID, godot::StringName> classes_by_id;

extern godot::Variant jsvalue_to_variant(JSValue val);
extern JSValue variant_to_jsvalue(const godot::Variant &val);

// template <typename IN, typename OUT, typename = void>
// class VariantAdapter;

// template <typename IN>
// using GDVariantAdapter = VariantAdapter<IN, JSValue>;
// template <typename IN>
// using GDObjectAdapter = VariantAdapter<IN *, JSValue>;
// template <typename OUT>
// using JSValueAdapter = VariantAdapter<JSValue, OUT>;
// template <typename OUT>
// using JSObjectAdapter = VariantAdapter<JSValue, OUT *>;

// template <typename T, typename = std::enable_if_t<std::is_base_of_v<godot::Object, T>>>
// JSValue variant_to_jsvalue(const T *val) {
// 	const godot::Object *obj = val;
// 	const char *class_name = to_chars(obj->get_class());
// 	char code[1024];
// 	sprintf(code, "import { %s } from \"@godot/classes/%s\";", class_name, camelToSnake(class_name).c_str());
// 	JS_Eval(js_context(), code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
// 	JSClassID class_id = classes[typeid(*obj)];
// 	JSValue js_obj = JS_NewObjectClass(js_context(), class_id);
// 	void *raw_mem = memalloc(sizeof(GDObjectAdapter<T>));
// 	GDObjectAdapter<T> *adapter = new (raw_mem) GDObjectAdapter<T>(val, false);
// 	JS_SetOpaque(js_obj, adapter);
// 	return js_obj;
// }

// template <typename T, typename = std::enable_if_t<!std::is_pointer_v<T>>>
// JSValue variant_to_jsvalue(const T &val) {
// 	JSClassID class_id = classes[typeid(T)];
// 	if constexpr (std::is_same_v<T, godot::Array>) {
// 		godot::Array arr = val;
// 		JSValue js_arr = JS_NewArray(js_context());
// 		for (int i = 0; i < arr.size(); i++) {
// 			JS_SetPropertyUint32(js_context(), js_arr, i, variant_to_jsvalue<godot::Variant>(arr[i]));
// 		}
// 		return js_arr;
// 	} else if constexpr (std::is_fundamental_v<T>) {
// 		if constexpr (std::is_integral_v<T>) {
// 			return JS_NewInt64(js_context(), val);
// 		} else if constexpr (std::is_floating_point_v<T>) {
// 			return JS_NewFloat64(js_context(), val);
// 		} else if constexpr (std::is_same_v<T, char *>) {
// 			return JS_NewString(js_context(), val);
// 		} else if constexpr (std::is_same_v<T, bool>) {
// 			return JS_NewBool(js_context(), val);
// 		} else {
// 			return JS_UNDEFINED;
// 		}
// 	} else {
// 		JSValue js_obj = JS_NewObjectClass(js_context(), class_id);
// 		void *raw_mem = memalloc(sizeof(GDVariantAdapter<T>));
// 		GDVariantAdapter<T> *adapter = new (raw_mem) GDVariantAdapter<T>(val);
// 		JS_SetOpaque(js_obj, adapter);
// 		return js_obj;
// 	}
// }

// class IAdapter {
// public:
// 	virtual ~IAdapter() = default;

// 	virtual godot::Variant get() const = 0;

// 	virtual std::type_index get_type() const = 0;
// };

// template <typename IN>
// class VariantAdapter<IN, JSValue,
// 		std::enable_if_t<!std::is_pointer_v<IN> &&
// 				!std::is_base_of_v<godot::Object, IN> &&
// 				!std::is_same_v<IN, JSValue> &&
// 				std::is_constructible_v<godot::Variant, IN>>> : public IAdapter {
// public:
// 	using CleanIN = std::decay_t<IN>;

// 	const CleanIN m_internal_storage;
// 	const CleanIN *m_active_variant;
// 	const bool can_memfree = false;

// public:
// 	VariantAdapter() :
// 			m_internal_storage(IN()),
// 			m_active_variant(&m_internal_storage),
// 			can_memfree(false) {}
// 	VariantAdapter(const IN &p_other, bool can_memfree = false) :
// 			m_internal_storage(p_other),
// 			m_active_variant(&m_internal_storage),
// 			can_memfree(can_memfree) {}

// 	static bool can_cast(JSValue val) {
// 		return classes[typeid(IN)] == JS_GetClassID(val);
// 	}

// 	operator JSValue() { return variant_to_jsvalue<IN>(*m_active_variant); }
// 	operator CleanIN() { return *m_active_variant; }

// 	CleanIN *get() {
// 		return const_cast<IN *>(m_active_variant);
// 	}
// };

// template <typename IN>
// class VariantAdapter<IN *, JSValue, std::enable_if_t<std::is_same_v<godot::Object, IN> || std::is_base_of_v<godot::Object, IN>>> : public IAdapter {
// public:
// 	const IN *m_active_variant;
// 	const bool can_memfree = false;

// 	VariantAdapter() :
// 			m_active_variant(nullptr),
// 			can_memfree(false) {}
// 	VariantAdapter(const IN *p_other, bool can_memfree = false) :
// 			m_active_variant(p_other),
// 			can_memfree(can_memfree) {}

// 	static bool can_cast(JSValue val) {
// 		return classes[typeid(IN)] == JS_GetClassID(val);
// 	}

// 	IN *get() {
// 		return const_cast<IN *>(m_active_variant);
// 	}

// 	operator JSValue() { return variant_to_jsvalue(m_active_variant); }
// 	operator IN *() { return m_active_variant; }
// };

// template <typename OUT>
// class VariantAdapter<JSValue, OUT, std::enable_if_t<!(std::is_pointer_v<OUT> || std::is_same_v<godot::Object, OUT> || std::is_base_of_v<godot::Object, OUT>)>> : public IAdapter {
// public:
// 	const JSValue m_active_variant;
// 	const OUT out_variant;
// 	const bool can_memfree = false;

// 	VariantAdapter() :
// 			m_active_variant(JS_UNDEFINED) {}
// 	VariantAdapter(const JSValue &p_other) :
// 			m_active_variant(p_other),
// 			out_variant(jsvalue_to_variant(p_other)) {}

// 	static bool can_cast(JSValue val) {
// 		if (JS_IsNumber(val) || JS_IsBool(val)) {
// 			return std::is_fundamental_v<OUT>;
// 		} else if (JS_IsObject(val)) {
// 			return classes[typeid(OUT)] == JS_GetClassID(val);
// 		} else {
// 			return false;
// 		}
// 	}

// 	OUT *get() {
// 		return const_cast<OUT *>(&out_variant);
// 	}

// 	operator JSValue() { return m_active_variant; }
// 	operator OUT *() { return get(); }
// };

// template <typename OUT>
// class VariantAdapter<JSValue, OUT *, std::enable_if_t<std::is_same_v<godot::Object, OUT> || std::is_base_of_v<godot::Object, OUT>>> : public IAdapter {
// public:
// 	const JSValue m_active_variant;
// 	const OUT *out_ptr;
// 	const bool can_memfree = false;

// 	VariantAdapter() :
// 			m_active_variant(JS_UNDEFINED) {}
// 	VariantAdapter(const JSValue &p_other) :
// 			m_active_variant(p_other),
// 			out_ptr(static_cast<OUT *>((jsvalue_to_variant(p_other).operator godot::Object *()))) {}

// 	static bool can_cast(JSValue val) {
// 		if (JS_IsNumber(val) || JS_IsBool(val)) {
// 			return std::is_fundamental_v<OUT>;
// 		} else if (JS_IsObject(val)) {
// 			return classes[typeid(OUT)] == JS_GetClassID(val);
// 		} else {
// 			return false;
// 		}
// 	}

// 	OUT *get() {
// 		return const_cast<OUT *>(out_ptr);
// 	}
// 	operator JSValue() { return m_active_variant; }
// 	operator OUT *() { return get(); }
// };

class IAdapter {
public:
	bool const can_memfree = false;

public:
	IAdapter() :
			can_memfree(false) {}
	IAdapter(bool can_memfree) :
			can_memfree(can_memfree) {}
	virtual godot::Variant::Type get_type() const = 0;
};

class VariantAdapter : public IAdapter {
public:
	const godot::Variant variant;
	void *typedVariant = nullptr;

public:
	VariantAdapter() :
			IAdapter() {}
	VariantAdapter(const godot::Variant &p_other, bool can_memfree = false) :
			IAdapter(can_memfree), variant(p_other) {}

	VariantAdapter(const JSValue jsvalue, bool can_memfree = false) :
			IAdapter(can_memfree),
			variant(jsvalue_to_variant(jsvalue)) {}

	godot::Variant get() const {
		return variant;
	}

	template <typename T>
	godot::Variant get() const {
		return variant;
	}

	godot::Variant::Type get_type() const override {
		return variant.get_type();
	}

	static bool can_cast(godot::Variant val, godot::Variant::Type type) {
		return val.get_type() == type;
	}

	static bool can_cast(JSValue val, godot::Variant::Type type) {
		return VariantAdapter(val).get().get_type() == type;
	}

	operator godot::Variant() { return variant; }

	operator JSValue() { return variant_to_jsvalue(variant); }
};

class ObjectAdapter : public IAdapter {
	const godot::Object *obj;

private:
	godot::Object *jsvalue_to_object(JSValue jsvalue) {
		return (godot::Object *)JS_GetOpaque(jsvalue, JS_GetClassID(jsvalue));
	}

public:
	ObjectAdapter() :
			IAdapter() {}
	ObjectAdapter(const godot::Object *p_other, bool can_memfree = false) :
			IAdapter(can_memfree), obj(p_other) {}

	ObjectAdapter(const JSValue jsvalue, bool can_memfree = false) :
			IAdapter(can_memfree),
			obj(jsvalue_to_variant(jsvalue)) {}

	godot::Object *get() const {
		return const_cast<godot::Object *>(static_cast<const godot::Object *>(obj));
	}
	virtual godot::Variant::Type get_type() const {
		return godot::Variant::Type::OBJECT;
	}
	operator godot::Object *() { return const_cast<godot::Object *>(obj); }

	operator JSValue() { return variant_to_jsvalue(obj); }
};

#endif // __VARIANT_HELPER_H__