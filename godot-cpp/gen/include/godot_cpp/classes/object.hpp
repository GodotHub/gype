/**************************************************************************/
/*  object.hpp                                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

// THIS FILE IS GENERATED. EDITS WILL BE LOST.

#ifndef GODOT_CPP_OBJECT_HPP
#define GODOT_CPP_OBJECT_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>


#include <godot_cpp/templates/vararg.hpp>
namespace godot {

class Callable;
class NodePath;

class Object : public Wrapped {
	GDEXTENSION_CLASS(Object, Wrapped)

public:
	enum ConnectFlags {
		CONNECT_DEFERRED = 1,
		CONNECT_PERSIST = 2,
		CONNECT_ONE_SHOT = 4,
		CONNECT_REFERENCE_COUNTED = 8,
	};

	static const int NOTIFICATION_POSTINITIALIZE = 0;
	static const int NOTIFICATION_PREDELETE = 1;
	static const int NOTIFICATION_EXTENSION_RELOADED = 2;

	String get_class() const;
	bool is_class(const String &_class) const;
	void set(const StringName &property, const Variant &value);
	Variant get(const StringName &property) const;
	void set_indexed(const NodePath &property_path, const Variant &value);
	Variant get_indexed(const NodePath &property_path) const;
	TypedArray<Dictionary> get_property_list() const;
	TypedArray<Dictionary> get_method_list() const;
	bool property_can_revert(const StringName &property) const;
	Variant property_get_revert(const StringName &property) const;
	void notification(int32_t what, bool reversed = false);
	String to_string();
	uint64_t get_instance_id() const;
	void set_script(const Variant &script);
	Variant get_script() const;
	void set_meta(const StringName &name, const Variant &value);
	void remove_meta(const StringName &name);
	Variant get_meta(const StringName &name, const Variant &_default = nullptr) const;
	bool has_meta(const StringName &name) const;
	TypedArray<StringName> get_meta_list() const;
	void add_user_signal(const String &signal, const Array &arguments = Array());
	bool has_user_signal(const StringName &signal) const;

private:
private:
	Error emit_signal_internal(const Variant **args, GDExtensionInt arg_count);

public:
	Error emit_signal(const StringName &signal, rest<Variant> args) {
		std::vector<Variant> variant_args;
		variant_args.push_back(Variant(signal));
		variant_args.insert(variant_args.end(), args.begin(), args.end());
		std::vector<const Variant *> call_args;
		for (size_t i = 0; i < variant_args.size(); i++) {
			call_args.push_back(&variant_args[i]);
		}
		return emit_signal_internal(call_args.data(), variant_args.size());
	}

private:
private:
	Variant call_internal(const Variant **args, GDExtensionInt arg_count);

public:
	Variant call(const StringName &method, rest<Variant> args) {
		std::vector<Variant> variant_args;
		variant_args.push_back(Variant(method));
		variant_args.insert(variant_args.end(), args.begin(), args.end());
		std::vector<const Variant *> call_args;
		for (size_t i = 0; i < variant_args.size(); i++) {
			call_args.push_back(&variant_args[i]);
		}
		return call_internal(call_args.data(), variant_args.size());
	}

private:
private:
	Variant call_deferred_internal(const Variant **args, GDExtensionInt arg_count);

public:
	Variant call_deferred(const StringName &method, rest<Variant> args) {
		std::vector<Variant> variant_args;
		variant_args.push_back(Variant(method));
		variant_args.insert(variant_args.end(), args.begin(), args.end());
		std::vector<const Variant *> call_args;
		for (size_t i = 0; i < variant_args.size(); i++) {
			call_args.push_back(&variant_args[i]);
		}
		return call_deferred_internal(call_args.data(), variant_args.size());
	}
	void set_deferred(const StringName &property, const Variant &value);
	Variant callv(const StringName &method, const Array &arg_array);
	bool has_method(const StringName &method) const;
	bool has_signal(const StringName &signal) const;
	TypedArray<Dictionary> get_signal_list() const;
	TypedArray<Dictionary> get_signal_connection_list(const StringName &signal) const;
	TypedArray<Dictionary> get_incoming_connections() const;
	Error connect(const StringName &signal, const Callable &callable, uint32_t flags = 0);
	void disconnect(const StringName &signal, const Callable &callable);
	bool is_connected(const StringName &signal, const Callable &callable) const;
	void set_block_signals(bool enable);
	bool is_blocking_signals() const;
	void notify_property_list_changed();
	void set_message_translation(bool enable);
	bool can_translate_messages() const;
	String tr(const StringName &message, const StringName &context = String()) const;
	String tr_n(const StringName &message, const StringName &plural_message, int32_t n, const StringName &context = String()) const;
	bool is_queued_for_deletion() const;
	void cancel_free();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
	}

public:
	template <typename T>
	static T *cast_to(Object *p_object);
	template <typename T>
	static const T *cast_to(const Object *p_object);
	virtual ~Object() = default;
};

} // namespace godot

#endif // ! GODOT_CPP_OBJECT_HPP