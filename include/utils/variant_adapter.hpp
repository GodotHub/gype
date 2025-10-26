#ifndef __VARIANT_ADAPTER_H__
#define __VARIANT_ADAPTER_H__

#include "utils/env.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/variant.hpp>
#include <quickjs.h>

using namespace godot;

Variant jsvalue_to_variant(JSContext *ctx, const JSValue &p_jsvalue);
JSValue variant_to_jsvalue(JSContext *ctx, const Variant &p_variant);

class VariantAdapter {
	Variant variant;

public:
	// 默认构造
	VariantAdapter() :
			variant() {}

	VariantAdapter(const Variant &p_other) :
			variant(p_other) {}

	VariantAdapter(const JSValue &p_jsvalue) {
		variant = jsvalue_to_variant(js_context(), p_jsvalue);
	}

	template <typename T>
	T get() const {
		return (T)variant;
	}

	operator Variant() const {
		return variant;
	}

    operator JSValue() const {
		return variant_to_jsvalue(js_context(), variant);
    }

	Variant::Type get_type() const {
		return variant.get_type();
	}
};

#endif // __VARIANT_ADAPTER_H__