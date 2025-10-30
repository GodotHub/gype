#ifndef __VARIANT_HELPER_H__
#define __VARIANT_HELPER_H__

#include "utils/env.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/variant.hpp>

class VariantAdapter {
	godot::Variant m_internal_storage;
	const godot::Variant *m_active_variant;

public:
	VariantAdapter() :
			m_active_variant(&m_internal_storage) {}

	VariantAdapter(const godot::Variant &p_other) :
			m_active_variant(&p_other) {}

	VariantAdapter(const JSValue &p_jsvalue) :
			m_internal_storage(jsvalue_to_variant(p_jsvalue)),
			m_active_variant(&m_internal_storage) {
	}

	template <typename T>
	T get() const {
		if constexpr (std::is_same_v<T, char32_t>) {
			return static_cast<godot::String>(*m_active_variant).ptrw();
		} else {
			return static_cast<T>(*m_active_variant);
		}
	}

	operator godot::Variant() const {
		return *m_active_variant;
	}

	operator JSValue() const {
		return variant_to_jsvalue(*m_active_variant);
	}

	godot::Variant::Type get_type() const {
		return m_active_variant->get_type();
	}
};

#endif // __VARIANT_HELPER_H__