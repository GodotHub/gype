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
	godot::Variant variant;

public:
	VariantAdapter(const godot::Variant &p_other, bool can_memfree = false) :
			IAdapter(can_memfree),
			variant(p_other) {} 
 
	VariantAdapter(const JSValue jsvalue, bool can_memfree = false) :
			IAdapter(can_memfree),
			variant(jsvalue_to_variant(jsvalue)) {}

	const godot::Variant get() const {
		return variant;
	}

	void set(const godot::Variant &variant) {
		this->variant = variant;
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
#endif