/**************************************************************************/
/*  visual_shader_node_parameter.hpp                                      */
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

#ifndef GODOT_CPP_VISUAL_SHADER_NODE_PARAMETER_HPP
#define GODOT_CPP_VISUAL_SHADER_NODE_PARAMETER_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/visual_shader_node.hpp>
#include <godot_cpp/variant/string.hpp>


#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

#include <godot_cpp/templates/vararg.hpp>
namespace godot {

class VisualShaderNodeParameter : public VisualShaderNode {
	GDEXTENSION_CLASS(VisualShaderNodeParameter, VisualShaderNode)

public:
	enum Qualifier {
		QUAL_NONE = 0,
		QUAL_GLOBAL = 1,
		QUAL_INSTANCE = 2,
		QUAL_MAX = 3,
	};

	void set_parameter_name(const String &name);
	String get_parameter_name() const;
	void set_qualifier(VisualShaderNodeParameter::Qualifier qualifier);
	VisualShaderNodeParameter::Qualifier get_qualifier() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		VisualShaderNode::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(VisualShaderNodeParameter::Qualifier);

#endif // ! GODOT_CPP_VISUAL_SHADER_NODE_PARAMETER_HPP