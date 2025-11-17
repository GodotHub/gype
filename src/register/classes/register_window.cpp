#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/theme.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/window.hpp>
using namespace godot;

static void window_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Window"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef window_class_def = {
    "Window",
    window_class_finalizer
};

static JSValue window_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Window"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Window *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Window *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Window);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue window_class_set_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_title, ctx, this_val, argc, argv);
};
static JSValue window_class_get_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_title();
	};
	proxy->setter = [this_val](const String &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_title(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_initial_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_initial_position, ctx, this_val, argc, argv);
};
static JSValue window_class_get_initial_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_initial_position, ctx, this_val, argc, argv);
}
static JSValue window_class_set_current_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_current_screen, ctx, this_val, argc, argv);
};
static JSValue window_class_get_current_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_current_screen, ctx, this_val, argc, argv);
}
static JSValue window_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_position, ctx, this_val, argc, argv);
};
static JSValue window_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_position();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_position(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_move_to_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::move_to_center, ctx, this_val, argc, argv);
};
static JSValue window_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_reset_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::reset_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_position_with_decorations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_position_with_decorations, ctx, this_val, argc, argv);
};
static JSValue window_class_get_size_with_decorations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_size_with_decorations, ctx, this_val, argc, argv);
};
static JSValue window_class_set_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_max_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_max_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_max_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_min_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_min_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_min_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_mode, ctx, this_val, argc, argv);
};
static JSValue window_class_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_mode, ctx, this_val, argc, argv);
}
static JSValue window_class_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_flag, ctx, this_val, argc, argv);
};
static JSValue window_class_get_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_flag, ctx, this_val, argc, argv);
}
static JSValue window_class_is_maximize_allowed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_maximize_allowed, ctx, this_val, argc, argv);
};
static JSValue window_class_request_attention(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::request_attention, ctx, this_val, argc, argv);
};
static JSValue window_class_move_to_foreground(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::move_to_foreground, ctx, this_val, argc, argv);
};
static JSValue window_class_set_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_visible, ctx, this_val, argc, argv);
};
static JSValue window_class_is_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_visible, ctx, this_val, argc, argv);
}
static JSValue window_class_hide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::hide, ctx, this_val, argc, argv);
};
static JSValue window_class_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::show, ctx, this_val, argc, argv);
};
static JSValue window_class_set_transient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_transient, ctx, this_val, argc, argv);
};
static JSValue window_class_is_transient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_transient, ctx, this_val, argc, argv);
}
static JSValue window_class_set_transient_to_focused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_transient_to_focused, ctx, this_val, argc, argv);
};
static JSValue window_class_is_transient_to_focused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_transient_to_focused, ctx, this_val, argc, argv);
}
static JSValue window_class_set_exclusive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_exclusive, ctx, this_val, argc, argv);
};
static JSValue window_class_is_exclusive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_exclusive, ctx, this_val, argc, argv);
}
static JSValue window_class_set_unparent_when_invisible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_unparent_when_invisible, ctx, this_val, argc, argv);
};
static JSValue window_class_can_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::can_draw, ctx, this_val, argc, argv);
};
static JSValue window_class_has_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_focus, ctx, this_val, argc, argv);
};
static JSValue window_class_grab_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::grab_focus, ctx, this_val, argc, argv);
};
static JSValue window_class_start_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::start_drag, ctx, this_val, argc, argv);
};
static JSValue window_class_start_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::start_resize, ctx, this_val, argc, argv);
};
static JSValue window_class_set_ime_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_ime_active, ctx, this_val, argc, argv);
};
static JSValue window_class_set_ime_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_ime_position, ctx, this_val, argc, argv);
};
static JSValue window_class_is_embedded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_embedded, ctx, this_val, argc, argv);
};
static JSValue window_class_get_contents_minimum_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_contents_minimum_size, ctx, this_val, argc, argv);
};
static JSValue window_class_set_force_native(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_force_native, ctx, this_val, argc, argv);
};
static JSValue window_class_get_force_native(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_force_native, ctx, this_val, argc, argv);
}
static JSValue window_class_set_content_scale_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_content_scale_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_content_scale_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_content_scale_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_content_scale_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_content_scale_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_content_scale_mode, ctx, this_val, argc, argv);
};
static JSValue window_class_get_content_scale_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_content_scale_mode, ctx, this_val, argc, argv);
}
static JSValue window_class_set_content_scale_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_content_scale_aspect, ctx, this_val, argc, argv);
};
static JSValue window_class_get_content_scale_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_content_scale_aspect, ctx, this_val, argc, argv);
}
static JSValue window_class_set_content_scale_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_content_scale_stretch, ctx, this_val, argc, argv);
};
static JSValue window_class_get_content_scale_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_content_scale_stretch, ctx, this_val, argc, argv);
}
static JSValue window_class_set_keep_title_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_keep_title_visible, ctx, this_val, argc, argv);
};
static JSValue window_class_get_keep_title_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_keep_title_visible, ctx, this_val, argc, argv);
}
static JSValue window_class_set_content_scale_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_content_scale_factor, ctx, this_val, argc, argv);
};
static JSValue window_class_get_content_scale_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_content_scale_factor, ctx, this_val, argc, argv);
}
static JSValue window_class_set_mouse_passthrough_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_mouse_passthrough_polygon, ctx, this_val, argc, argv);
};
static JSValue window_class_get_mouse_passthrough_polygon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_mouse_passthrough_polygon();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_mouse_passthrough_polygon(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_wrap_controls(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_wrap_controls, ctx, this_val, argc, argv);
};
static JSValue window_class_is_wrapping_controls(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_wrapping_controls, ctx, this_val, argc, argv);
}
static JSValue window_class_child_controls_changed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::child_controls_changed, ctx, this_val, argc, argv);
};
static JSValue window_class_set_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_theme, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme, ctx, this_val, argc, argv);
}
static JSValue window_class_set_theme_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_theme_type_variation, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<StringName> *proxy = memnew(ObjectProxy<StringName>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> StringName {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_theme_type_variation();
	};
	proxy->setter = [this_val](const StringName &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_theme_type_variation(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringNameProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringNameProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_begin_bulk_theme_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::begin_bulk_theme_override, ctx, this_val, argc, argv);
};
static JSValue window_class_end_bulk_theme_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::end_bulk_theme_override, ctx, this_val, argc, argv);
};
static JSValue window_class_add_theme_icon_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::add_theme_icon_override, ctx, this_val, argc, argv);
};
static JSValue window_class_add_theme_stylebox_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::add_theme_stylebox_override, ctx, this_val, argc, argv);
};
static JSValue window_class_add_theme_font_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::add_theme_font_override, ctx, this_val, argc, argv);
};
static JSValue window_class_add_theme_font_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::add_theme_font_size_override, ctx, this_val, argc, argv);
};
static JSValue window_class_add_theme_color_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::add_theme_color_override, ctx, this_val, argc, argv);
};
static JSValue window_class_add_theme_constant_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::add_theme_constant_override, ctx, this_val, argc, argv);
};
static JSValue window_class_remove_theme_icon_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::remove_theme_icon_override, ctx, this_val, argc, argv);
};
static JSValue window_class_remove_theme_stylebox_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::remove_theme_stylebox_override, ctx, this_val, argc, argv);
};
static JSValue window_class_remove_theme_font_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::remove_theme_font_override, ctx, this_val, argc, argv);
};
static JSValue window_class_remove_theme_font_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::remove_theme_font_size_override, ctx, this_val, argc, argv);
};
static JSValue window_class_remove_theme_color_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::remove_theme_color_override, ctx, this_val, argc, argv);
};
static JSValue window_class_remove_theme_constant_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::remove_theme_constant_override, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_icon, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_stylebox, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_font, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_font_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_color, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_constant, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_icon_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_icon_override, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_stylebox_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_stylebox_override, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_font_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_font_override, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_font_size_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_font_size_override, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_color_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_color_override, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_constant_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_constant_override, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_icon, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_stylebox, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_font, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_font_size, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_color, ctx, this_val, argc, argv);
};
static JSValue window_class_has_theme_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::has_theme_constant, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_default_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_default_base_scale, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_default_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_default_font, ctx, this_val, argc, argv);
};
static JSValue window_class_get_theme_default_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_theme_default_font_size, ctx, this_val, argc, argv);
};
static JSValue window_class_get_window_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_window_id, ctx, this_val, argc, argv);
};
static JSValue window_class_set_accessibility_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_accessibility_name, ctx, this_val, argc, argv);
};
static JSValue window_class_get_accessibility_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_accessibility_name();
	};
	proxy->setter = [this_val](const String &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_accessibility_name(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_accessibility_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_accessibility_description, ctx, this_val, argc, argv);
};
static JSValue window_class_get_accessibility_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		Window *obj = static_cast<Window *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_accessibility_description();
	};
	proxy->setter = [this_val](const String &value) -> void {
		Window *js_proxy = static_cast<Window *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_accessibility_description(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue window_class_set_layout_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_layout_direction, ctx, this_val, argc, argv);
};
static JSValue window_class_get_layout_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::get_layout_direction, ctx, this_val, argc, argv);
};
static JSValue window_class_is_layout_rtl(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_layout_rtl, ctx, this_val, argc, argv);
};
static JSValue window_class_set_auto_translate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_auto_translate, ctx, this_val, argc, argv);
};
static JSValue window_class_is_auto_translating(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_auto_translating, ctx, this_val, argc, argv);
}
static JSValue window_class_set_use_font_oversampling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::set_use_font_oversampling, ctx, this_val, argc, argv);
};
static JSValue window_class_is_using_font_oversampling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Window::is_using_font_oversampling, ctx, this_val, argc, argv);
};
static JSValue window_class_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_on_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_on_parent, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_centered, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_centered_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_centered_ratio, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_centered_clamped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_centered_clamped, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_exclusive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_exclusive, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_exclusive_on_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_exclusive_on_parent, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_exclusive_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_exclusive_centered, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_exclusive_centered_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_exclusive_centered_ratio, ctx, this_val, argc, argv);
};
static JSValue window_class_popup_exclusive_centered_clamped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Window::popup_exclusive_centered_clamped, ctx, this_val, argc, argv);
};
static JSValue window_class_get_focused_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Window::get_focused_window, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry window_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_title", 1, &window_class_set_title),
	JS_CFUNC_DEF("get_title", 0, &window_class_get_title),
	JS_CFUNC_DEF("set_initial_position", 1, &window_class_set_initial_position),
	JS_CFUNC_DEF("get_initial_position", 0, &window_class_get_initial_position),
	JS_CFUNC_DEF("set_current_screen", 1, &window_class_set_current_screen),
	JS_CFUNC_DEF("get_current_screen", 0, &window_class_get_current_screen),
	JS_CFUNC_DEF("set_position", 1, &window_class_set_position),
	JS_CFUNC_DEF("get_position", 0, &window_class_get_position),
	JS_CFUNC_DEF("move_to_center", 0, &window_class_move_to_center),
	JS_CFUNC_DEF("set_size", 1, &window_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &window_class_get_size),
	JS_CFUNC_DEF("reset_size", 0, &window_class_reset_size),
	JS_CFUNC_DEF("get_position_with_decorations", 0, &window_class_get_position_with_decorations),
	JS_CFUNC_DEF("get_size_with_decorations", 0, &window_class_get_size_with_decorations),
	JS_CFUNC_DEF("set_max_size", 1, &window_class_set_max_size),
	JS_CFUNC_DEF("get_max_size", 0, &window_class_get_max_size),
	JS_CFUNC_DEF("set_min_size", 1, &window_class_set_min_size),
	JS_CFUNC_DEF("get_min_size", 0, &window_class_get_min_size),
	JS_CFUNC_DEF("set_mode", 1, &window_class_set_mode),
	JS_CFUNC_DEF("get_mode", 0, &window_class_get_mode),
	JS_CFUNC_DEF("set_flag", 2, &window_class_set_flag),
	JS_CFUNC_DEF("get_flag", 1, &window_class_get_flag),
	JS_CFUNC_DEF("is_maximize_allowed", 0, &window_class_is_maximize_allowed),
	JS_CFUNC_DEF("request_attention", 0, &window_class_request_attention),
	JS_CFUNC_DEF("move_to_foreground", 0, &window_class_move_to_foreground),
	JS_CFUNC_DEF("set_visible", 1, &window_class_set_visible),
	JS_CFUNC_DEF("is_visible", 0, &window_class_is_visible),
	JS_CFUNC_DEF("hide", 0, &window_class_hide),
	JS_CFUNC_DEF("show", 0, &window_class_show),
	JS_CFUNC_DEF("set_transient", 1, &window_class_set_transient),
	JS_CFUNC_DEF("is_transient", 0, &window_class_is_transient),
	JS_CFUNC_DEF("set_transient_to_focused", 1, &window_class_set_transient_to_focused),
	JS_CFUNC_DEF("is_transient_to_focused", 0, &window_class_is_transient_to_focused),
	JS_CFUNC_DEF("set_exclusive", 1, &window_class_set_exclusive),
	JS_CFUNC_DEF("is_exclusive", 0, &window_class_is_exclusive),
	JS_CFUNC_DEF("set_unparent_when_invisible", 1, &window_class_set_unparent_when_invisible),
	JS_CFUNC_DEF("can_draw", 0, &window_class_can_draw),
	JS_CFUNC_DEF("has_focus", 0, &window_class_has_focus),
	JS_CFUNC_DEF("grab_focus", 0, &window_class_grab_focus),
	JS_CFUNC_DEF("start_drag", 0, &window_class_start_drag),
	JS_CFUNC_DEF("start_resize", 1, &window_class_start_resize),
	JS_CFUNC_DEF("set_ime_active", 1, &window_class_set_ime_active),
	JS_CFUNC_DEF("set_ime_position", 1, &window_class_set_ime_position),
	JS_CFUNC_DEF("is_embedded", 0, &window_class_is_embedded),
	JS_CFUNC_DEF("get_contents_minimum_size", 0, &window_class_get_contents_minimum_size),
	JS_CFUNC_DEF("set_force_native", 1, &window_class_set_force_native),
	JS_CFUNC_DEF("get_force_native", 0, &window_class_get_force_native),
	JS_CFUNC_DEF("set_content_scale_size", 1, &window_class_set_content_scale_size),
	JS_CFUNC_DEF("get_content_scale_size", 0, &window_class_get_content_scale_size),
	JS_CFUNC_DEF("set_content_scale_mode", 1, &window_class_set_content_scale_mode),
	JS_CFUNC_DEF("get_content_scale_mode", 0, &window_class_get_content_scale_mode),
	JS_CFUNC_DEF("set_content_scale_aspect", 1, &window_class_set_content_scale_aspect),
	JS_CFUNC_DEF("get_content_scale_aspect", 0, &window_class_get_content_scale_aspect),
	JS_CFUNC_DEF("set_content_scale_stretch", 1, &window_class_set_content_scale_stretch),
	JS_CFUNC_DEF("get_content_scale_stretch", 0, &window_class_get_content_scale_stretch),
	JS_CFUNC_DEF("set_keep_title_visible", 1, &window_class_set_keep_title_visible),
	JS_CFUNC_DEF("get_keep_title_visible", 0, &window_class_get_keep_title_visible),
	JS_CFUNC_DEF("set_content_scale_factor", 1, &window_class_set_content_scale_factor),
	JS_CFUNC_DEF("get_content_scale_factor", 0, &window_class_get_content_scale_factor),
	JS_CFUNC_DEF("set_mouse_passthrough_polygon", 1, &window_class_set_mouse_passthrough_polygon),
	JS_CFUNC_DEF("get_mouse_passthrough_polygon", 0, &window_class_get_mouse_passthrough_polygon),
	JS_CFUNC_DEF("set_wrap_controls", 1, &window_class_set_wrap_controls),
	JS_CFUNC_DEF("is_wrapping_controls", 0, &window_class_is_wrapping_controls),
	JS_CFUNC_DEF("child_controls_changed", 0, &window_class_child_controls_changed),
	JS_CFUNC_DEF("set_theme", 1, &window_class_set_theme),
	JS_CFUNC_DEF("get_theme", 0, &window_class_get_theme),
	JS_CFUNC_DEF("set_theme_type_variation", 1, &window_class_set_theme_type_variation),
	JS_CFUNC_DEF("get_theme_type_variation", 0, &window_class_get_theme_type_variation),
	JS_CFUNC_DEF("begin_bulk_theme_override", 0, &window_class_begin_bulk_theme_override),
	JS_CFUNC_DEF("end_bulk_theme_override", 0, &window_class_end_bulk_theme_override),
	JS_CFUNC_DEF("add_theme_icon_override", 2, &window_class_add_theme_icon_override),
	JS_CFUNC_DEF("add_theme_stylebox_override", 2, &window_class_add_theme_stylebox_override),
	JS_CFUNC_DEF("add_theme_font_override", 2, &window_class_add_theme_font_override),
	JS_CFUNC_DEF("add_theme_font_size_override", 2, &window_class_add_theme_font_size_override),
	JS_CFUNC_DEF("add_theme_color_override", 2, &window_class_add_theme_color_override),
	JS_CFUNC_DEF("add_theme_constant_override", 2, &window_class_add_theme_constant_override),
	JS_CFUNC_DEF("remove_theme_icon_override", 1, &window_class_remove_theme_icon_override),
	JS_CFUNC_DEF("remove_theme_stylebox_override", 1, &window_class_remove_theme_stylebox_override),
	JS_CFUNC_DEF("remove_theme_font_override", 1, &window_class_remove_theme_font_override),
	JS_CFUNC_DEF("remove_theme_font_size_override", 1, &window_class_remove_theme_font_size_override),
	JS_CFUNC_DEF("remove_theme_color_override", 1, &window_class_remove_theme_color_override),
	JS_CFUNC_DEF("remove_theme_constant_override", 1, &window_class_remove_theme_constant_override),
	JS_CFUNC_DEF("get_theme_icon", 2, &window_class_get_theme_icon),
	JS_CFUNC_DEF("get_theme_stylebox", 2, &window_class_get_theme_stylebox),
	JS_CFUNC_DEF("get_theme_font", 2, &window_class_get_theme_font),
	JS_CFUNC_DEF("get_theme_font_size", 2, &window_class_get_theme_font_size),
	JS_CFUNC_DEF("get_theme_color", 2, &window_class_get_theme_color),
	JS_CFUNC_DEF("get_theme_constant", 2, &window_class_get_theme_constant),
	JS_CFUNC_DEF("has_theme_icon_override", 1, &window_class_has_theme_icon_override),
	JS_CFUNC_DEF("has_theme_stylebox_override", 1, &window_class_has_theme_stylebox_override),
	JS_CFUNC_DEF("has_theme_font_override", 1, &window_class_has_theme_font_override),
	JS_CFUNC_DEF("has_theme_font_size_override", 1, &window_class_has_theme_font_size_override),
	JS_CFUNC_DEF("has_theme_color_override", 1, &window_class_has_theme_color_override),
	JS_CFUNC_DEF("has_theme_constant_override", 1, &window_class_has_theme_constant_override),
	JS_CFUNC_DEF("has_theme_icon", 2, &window_class_has_theme_icon),
	JS_CFUNC_DEF("has_theme_stylebox", 2, &window_class_has_theme_stylebox),
	JS_CFUNC_DEF("has_theme_font", 2, &window_class_has_theme_font),
	JS_CFUNC_DEF("has_theme_font_size", 2, &window_class_has_theme_font_size),
	JS_CFUNC_DEF("has_theme_color", 2, &window_class_has_theme_color),
	JS_CFUNC_DEF("has_theme_constant", 2, &window_class_has_theme_constant),
	JS_CFUNC_DEF("get_theme_default_base_scale", 0, &window_class_get_theme_default_base_scale),
	JS_CFUNC_DEF("get_theme_default_font", 0, &window_class_get_theme_default_font),
	JS_CFUNC_DEF("get_theme_default_font_size", 0, &window_class_get_theme_default_font_size),
	JS_CFUNC_DEF("get_window_id", 0, &window_class_get_window_id),
	JS_CFUNC_DEF("set_accessibility_name", 1, &window_class_set_accessibility_name),
	JS_CFUNC_DEF("get_accessibility_name", 0, &window_class_get_accessibility_name),
	JS_CFUNC_DEF("set_accessibility_description", 1, &window_class_set_accessibility_description),
	JS_CFUNC_DEF("get_accessibility_description", 0, &window_class_get_accessibility_description),
	JS_CFUNC_DEF("set_layout_direction", 1, &window_class_set_layout_direction),
	JS_CFUNC_DEF("get_layout_direction", 0, &window_class_get_layout_direction),
	JS_CFUNC_DEF("is_layout_rtl", 0, &window_class_is_layout_rtl),
	JS_CFUNC_DEF("set_auto_translate", 1, &window_class_set_auto_translate),
	JS_CFUNC_DEF("is_auto_translating", 0, &window_class_is_auto_translating),
	JS_CFUNC_DEF("set_use_font_oversampling", 1, &window_class_set_use_font_oversampling),
	JS_CFUNC_DEF("is_using_font_oversampling", 0, &window_class_is_using_font_oversampling),
	JS_CFUNC_DEF("popup", 1, &window_class_popup),
	JS_CFUNC_DEF("popup_on_parent", 1, &window_class_popup_on_parent),
	JS_CFUNC_DEF("popup_centered", 1, &window_class_popup_centered),
	JS_CFUNC_DEF("popup_centered_ratio", 1, &window_class_popup_centered_ratio),
	JS_CFUNC_DEF("popup_centered_clamped", 2, &window_class_popup_centered_clamped),
	JS_CFUNC_DEF("popup_exclusive", 2, &window_class_popup_exclusive),
	JS_CFUNC_DEF("popup_exclusive_on_parent", 2, &window_class_popup_exclusive_on_parent),
	JS_CFUNC_DEF("popup_exclusive_centered", 2, &window_class_popup_exclusive_centered),
	JS_CFUNC_DEF("popup_exclusive_centered_ratio", 2, &window_class_popup_exclusive_centered_ratio),
	JS_CFUNC_DEF("popup_exclusive_centered_clamped", 3, &window_class_popup_exclusive_centered_clamped),
};

static const JSCFunctionListEntry window_class_static_funcs[] = {
	JS_CFUNC_DEF("get_focused_window", 0, &window_class_get_focused_window),
};

static JSValue window_class_get_window_input_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "window_input_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "window_input"));
		JS_DefinePropertyValueStr(ctx, this_val, "window_input_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_files_dropped_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "files_dropped_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "files_dropped"));
		JS_DefinePropertyValueStr(ctx, this_val, "files_dropped_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_mouse_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "mouse_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "mouse_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "mouse_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_mouse_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "mouse_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "mouse_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "mouse_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_focus_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "focus_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "focus_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "focus_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_focus_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "focus_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "focus_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "focus_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_close_requested_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "close_requested_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "close_requested"));
		JS_DefinePropertyValueStr(ctx, this_val, "close_requested_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_go_back_requested_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "go_back_requested_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "go_back_requested"));
		JS_DefinePropertyValueStr(ctx, this_val, "go_back_requested_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_visibility_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "visibility_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "visibility_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "visibility_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_about_to_popup_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "about_to_popup_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "about_to_popup"));
		JS_DefinePropertyValueStr(ctx, this_val, "about_to_popup_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_theme_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "theme_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "theme_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "theme_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_dpi_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "dpi_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "dpi_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "dpi_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_titlebar_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "titlebar_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "titlebar_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "titlebar_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue window_class_get_title_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Window *opaque = static_cast<Window *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "title_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "title_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "title_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_window_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mode"),
        JS_NewCFunction(ctx, window_class_get_mode, "get_mode", 0),
        JS_NewCFunction(ctx, window_class_set_mode, "set_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title"),
        JS_NewCFunction(ctx, window_class_get_title, "get_title", 0),
        JS_NewCFunction(ctx, window_class_set_title, "set_title", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "initial_position"),
        JS_NewCFunction(ctx, window_class_get_initial_position, "get_initial_position", 0),
        JS_NewCFunction(ctx, window_class_set_initial_position, "set_initial_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "position"),
        JS_NewCFunction(ctx, window_class_get_position, "get_position", 0),
        JS_NewCFunction(ctx, window_class_set_position, "set_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, window_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, window_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_screen"),
        JS_NewCFunction(ctx, window_class_get_current_screen, "get_current_screen", 0),
        JS_NewCFunction(ctx, window_class_set_current_screen, "set_current_screen", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_passthrough_polygon"),
        JS_NewCFunction(ctx, window_class_get_mouse_passthrough_polygon, "get_mouse_passthrough_polygon", 0),
        JS_NewCFunction(ctx, window_class_set_mouse_passthrough_polygon, "set_mouse_passthrough_polygon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visible"),
        JS_NewCFunction(ctx, window_class_is_visible, "is_visible", 0),
        JS_NewCFunction(ctx, window_class_set_visible, "set_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wrap_controls"),
        JS_NewCFunction(ctx, window_class_is_wrapping_controls, "is_wrapping_controls", 0),
        JS_NewCFunction(ctx, window_class_set_wrap_controls, "set_wrap_controls", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transient"),
        JS_NewCFunction(ctx, window_class_is_transient, "is_transient", 0),
        JS_NewCFunction(ctx, window_class_set_transient, "set_transient", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transient_to_focused"),
        JS_NewCFunction(ctx, window_class_is_transient_to_focused, "is_transient_to_focused", 0),
        JS_NewCFunction(ctx, window_class_set_transient_to_focused, "set_transient_to_focused", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclusive"),
        JS_NewCFunction(ctx, window_class_is_exclusive, "is_exclusive", 0),
        JS_NewCFunction(ctx, window_class_set_exclusive, "set_exclusive", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unresizable"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "borderless"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "always_on_top"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transparent"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unfocusable"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "popup_window"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "extend_to_title"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mouse_passthrough"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sharp_corners"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "exclude_from_capture"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "popup_wm_hint"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minimize_disabled"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "maximize_disabled"),
        JS_NewCFunction(ctx, window_class_get_flag, "get_flag", 0),
        JS_NewCFunction(ctx, window_class_set_flag, "set_flag", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "force_native"),
        JS_NewCFunction(ctx, window_class_get_force_native, "get_force_native", 0),
        JS_NewCFunction(ctx, window_class_set_force_native, "set_force_native", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "min_size"),
        JS_NewCFunction(ctx, window_class_get_min_size, "get_min_size", 0),
        JS_NewCFunction(ctx, window_class_set_min_size, "set_min_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_size"),
        JS_NewCFunction(ctx, window_class_get_max_size, "get_max_size", 0),
        JS_NewCFunction(ctx, window_class_set_max_size, "set_max_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_title_visible"),
        JS_NewCFunction(ctx, window_class_get_keep_title_visible, "get_keep_title_visible", 0),
        JS_NewCFunction(ctx, window_class_set_keep_title_visible, "set_keep_title_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_scale_size"),
        JS_NewCFunction(ctx, window_class_get_content_scale_size, "get_content_scale_size", 0),
        JS_NewCFunction(ctx, window_class_set_content_scale_size, "set_content_scale_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_scale_mode"),
        JS_NewCFunction(ctx, window_class_get_content_scale_mode, "get_content_scale_mode", 0),
        JS_NewCFunction(ctx, window_class_set_content_scale_mode, "set_content_scale_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_scale_aspect"),
        JS_NewCFunction(ctx, window_class_get_content_scale_aspect, "get_content_scale_aspect", 0),
        JS_NewCFunction(ctx, window_class_set_content_scale_aspect, "set_content_scale_aspect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_scale_stretch"),
        JS_NewCFunction(ctx, window_class_get_content_scale_stretch, "get_content_scale_stretch", 0),
        JS_NewCFunction(ctx, window_class_set_content_scale_stretch, "set_content_scale_stretch", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "content_scale_factor"),
        JS_NewCFunction(ctx, window_class_get_content_scale_factor, "get_content_scale_factor", 0),
        JS_NewCFunction(ctx, window_class_set_content_scale_factor, "set_content_scale_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_translate"),
        JS_NewCFunction(ctx, window_class_is_auto_translating, "is_auto_translating", 0),
        JS_NewCFunction(ctx, window_class_set_auto_translate, "set_auto_translate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_name"),
        JS_NewCFunction(ctx, window_class_get_accessibility_name, "get_accessibility_name", 0),
        JS_NewCFunction(ctx, window_class_set_accessibility_name, "set_accessibility_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessibility_description"),
        JS_NewCFunction(ctx, window_class_get_accessibility_description, "get_accessibility_description", 0),
        JS_NewCFunction(ctx, window_class_set_accessibility_description, "set_accessibility_description", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "theme"),
        JS_NewCFunction(ctx, window_class_get_theme, "get_theme", 0),
        JS_NewCFunction(ctx, window_class_set_theme, "set_theme", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "theme_type_variation"),
        JS_NewCFunction(ctx, window_class_get_theme_type_variation, "get_theme_type_variation", 0),
        JS_NewCFunction(ctx, window_class_set_theme_type_variation, "set_theme_type_variation", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "window_input"),
		JS_NewCFunction(ctx, window_class_get_window_input_signal, "get_window_input_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "files_dropped"),
		JS_NewCFunction(ctx, window_class_get_files_dropped_signal, "get_files_dropped_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "mouse_entered"),
		JS_NewCFunction(ctx, window_class_get_mouse_entered_signal, "get_mouse_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "mouse_exited"),
		JS_NewCFunction(ctx, window_class_get_mouse_exited_signal, "get_mouse_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "focus_entered"),
		JS_NewCFunction(ctx, window_class_get_focus_entered_signal, "get_focus_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "focus_exited"),
		JS_NewCFunction(ctx, window_class_get_focus_exited_signal, "get_focus_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "close_requested"),
		JS_NewCFunction(ctx, window_class_get_close_requested_signal, "get_close_requested_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "go_back_requested"),
		JS_NewCFunction(ctx, window_class_get_go_back_requested_signal, "get_go_back_requested_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "visibility_changed"),
		JS_NewCFunction(ctx, window_class_get_visibility_changed_signal, "get_visibility_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "about_to_popup"),
		JS_NewCFunction(ctx, window_class_get_about_to_popup_signal, "get_about_to_popup_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "theme_changed"),
		JS_NewCFunction(ctx, window_class_get_theme_changed_signal, "get_theme_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "dpi_changed"),
		JS_NewCFunction(ctx, window_class_get_dpi_changed_signal, "get_dpi_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "titlebar_changed"),
		JS_NewCFunction(ctx, window_class_get_titlebar_changed_signal, "get_titlebar_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "title_changed"),
		JS_NewCFunction(ctx, window_class_get_title_changed_signal, "get_title_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_window_enum(JSContext *ctx, JSValue ctor) {
	JSValue Mode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_WINDOWED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_MINIMIZED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_MAXIMIZED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_FULLSCREEN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_EXCLUSIVE_FULLSCREEN", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "Mode", Mode_obj);
	JSValue Flags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_RESIZE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_BORDERLESS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_ALWAYS_ON_TOP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_TRANSPARENT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_NO_FOCUS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_POPUP", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_EXTEND_TO_TITLE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_MOUSE_PASSTHROUGH", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_SHARP_CORNERS", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_EXCLUDE_FROM_CAPTURE", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_POPUP_WM_HINT", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_MINIMIZE_DISABLED", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_MAXIMIZE_DISABLED", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_MAX", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ctor, "Flags", Flags_obj);
	JSValue ContentScaleMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ContentScaleMode_obj, "CONTENT_SCALE_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ContentScaleMode_obj, "CONTENT_SCALE_MODE_CANVAS_ITEMS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ContentScaleMode_obj, "CONTENT_SCALE_MODE_VIEWPORT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ContentScaleMode", ContentScaleMode_obj);
	JSValue ContentScaleAspect_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ContentScaleAspect_obj, "CONTENT_SCALE_ASPECT_IGNORE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ContentScaleAspect_obj, "CONTENT_SCALE_ASPECT_KEEP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ContentScaleAspect_obj, "CONTENT_SCALE_ASPECT_KEEP_WIDTH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ContentScaleAspect_obj, "CONTENT_SCALE_ASPECT_KEEP_HEIGHT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ContentScaleAspect_obj, "CONTENT_SCALE_ASPECT_EXPAND", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "ContentScaleAspect", ContentScaleAspect_obj);
	JSValue ContentScaleStretch_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ContentScaleStretch_obj, "CONTENT_SCALE_STRETCH_FRACTIONAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ContentScaleStretch_obj, "CONTENT_SCALE_STRETCH_INTEGER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "ContentScaleStretch", ContentScaleStretch_obj);
	JSValue LayoutDirection_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_INHERITED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_APPLICATION_LOCALE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_LTR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_RTL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_SYSTEM_LOCALE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, LayoutDirection_obj, "LAYOUT_DIRECTION_LOCALE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "LayoutDirection", LayoutDirection_obj);
	JSValue WindowInitialPosition_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, WindowInitialPosition_obj, "WINDOW_INITIAL_POSITION_ABSOLUTE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, WindowInitialPosition_obj, "WINDOW_INITIAL_POSITION_CENTER_PRIMARY_SCREEN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, WindowInitialPosition_obj, "WINDOW_INITIAL_POSITION_CENTER_MAIN_WINDOW_SCREEN", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, WindowInitialPosition_obj, "WINDOW_INITIAL_POSITION_CENTER_OTHER_SCREEN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, WindowInitialPosition_obj, "WINDOW_INITIAL_POSITION_CENTER_SCREEN_WITH_MOUSE_FOCUS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, WindowInitialPosition_obj, "WINDOW_INITIAL_POSITION_CENTER_SCREEN_WITH_KEYBOARD_FOCUS", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "WindowInitialPosition", WindowInitialPosition_obj);
}

static int js_window_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Window"] = class_id;
	classes_by_id[class_id] = "Window";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &window_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Viewport"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_window_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, window_class_proto_funcs, _countof(window_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, window_class_constructor, "Window", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, window_class_static_funcs, _countof(window_class_static_funcs));
	define_window_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Window", ctor);

	return 0;
}

JSModuleDef *_js_init_window_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/viewport';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_window_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Window");
	return m;
}

JSModuleDef *js_init_window_module(JSContext *ctx) {
	return _js_init_window_module(ctx, "@godot/classes/window");
}

void __register_window() {
	js_init_window_module(js_context());
}

void register_window() {
	__register_window();
}