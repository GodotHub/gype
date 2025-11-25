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

class VariantAdapter {
public:
	godot::Variant variant;
	bool can_unref = true;

public:
	VariantAdapter(const godot::Variant &p_other, bool can_unref = true) :
			variant(p_other),
			can_unref(can_unref){} 
 
	VariantAdapter(const JSValue jsvalue, bool can_unref = true) :
			variant(jsvalue_to_variant(jsvalue)),
			can_unref(can_unref) {}

	const godot::Variant get() const {
		return variant;
	}

	void set(const godot::Variant &variant) {
		this->variant = variant;
	}

	godot::Variant::Type get_type() const {
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