/**************************************************************************/
/*  visible_on_screen_enabler3d.hpp                                       */
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

#ifndef GODOT_CPP_VISIBLE_ON_SCREEN_ENABLER3D_HPP
#define GODOT_CPP_VISIBLE_ON_SCREEN_ENABLER3D_HPP

#include <godot_cpp/classes/visible_on_screen_notifier3d.hpp>
#include <godot_cpp/variant/node_path.hpp>


#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

#include <godot_cpp/templates/vararg.hpp>
namespace godot {

class VisibleOnScreenEnabler3D : public VisibleOnScreenNotifier3D {
	GDEXTENSION_CLASS(VisibleOnScreenEnabler3D, VisibleOnScreenNotifier3D)

public:
	enum EnableMode {
		ENABLE_MODE_INHERIT = 0,
		ENABLE_MODE_ALWAYS = 1,
		ENABLE_MODE_WHEN_PAUSED = 2,
	};

	void set_enable_mode(VisibleOnScreenEnabler3D::EnableMode mode);
	VisibleOnScreenEnabler3D::EnableMode get_enable_mode();
	void set_enable_node_path(const NodePath &path);
	NodePath get_enable_node_path();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		VisibleOnScreenNotifier3D::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(VisibleOnScreenEnabler3D::EnableMode);

#endif // ! GODOT_CPP_VISIBLE_ON_SCREEN_ENABLER3D_HPP