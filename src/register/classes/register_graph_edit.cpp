#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/graph_frame.hpp>
#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/graph_edit.hpp>
using namespace godot;

static void graph_edit_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GraphEdit"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef graph_edit_class_def = {
    "GraphEdit",
    graph_edit_class_finalizer
};

static JSValue graph_edit_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GraphEdit"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GraphEdit *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GraphEdit *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GraphEdit);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue graph_edit_class_connect_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphEdit::connect_node, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_node_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphEdit::is_node_connected, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_disconnect_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::disconnect_node, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_set_connection_activity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_connection_activity, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_set_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_connections, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_connection_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_connection_list, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_get_connection_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphEdit::get_connection_count, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_closest_connection_at_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_closest_connection_at_point, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_connection_list_from_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_connection_list_from_node, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_connections_intersecting_with_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_connections_intersecting_with_rect, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_clear_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::clear_connections, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_force_connection_drag_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::force_connection_drag_end, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		GraphEdit *obj = static_cast<GraphEdit *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_scroll_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		GraphEdit *js_proxy = static_cast<GraphEdit *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_scroll_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue graph_edit_class_set_scroll_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_scroll_offset, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_add_valid_right_disconnect_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::add_valid_right_disconnect_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_remove_valid_right_disconnect_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::remove_valid_right_disconnect_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_add_valid_left_disconnect_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::add_valid_left_disconnect_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_remove_valid_left_disconnect_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::remove_valid_left_disconnect_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_add_valid_connection_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::add_valid_connection_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_remove_valid_connection_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::remove_valid_connection_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_valid_connection_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_valid_connection_type, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_connection_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_connection_line, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_attach_graph_element_to_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::attach_graph_element_to_frame, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_detach_graph_element_from_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::detach_graph_element_from_frame, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_element_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphEdit::get_element_frame, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_attached_nodes_of_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphEdit::get_attached_nodes_of_frame, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_set_panning_scheme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_panning_scheme, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_panning_scheme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_panning_scheme, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_zoom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_zoom, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_zoom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_zoom, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_zoom_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_zoom_min, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_zoom_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_zoom_min, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_zoom_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_zoom_max, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_zoom_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_zoom_max, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_zoom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_zoom_step, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_zoom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_zoom_step, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_grid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_grid, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_grid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_grid, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_grid_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_grid_pattern, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_grid_pattern(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_grid_pattern, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_snapping_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_snapping_enabled, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_snapping_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_snapping_enabled, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_snapping_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_snapping_distance, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_snapping_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_snapping_distance, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_connection_lines_curvature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_connection_lines_curvature, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_connection_lines_curvature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_connection_lines_curvature, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_connection_lines_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_connection_lines_thickness, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_connection_lines_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_connection_lines_thickness, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_connection_lines_antialiased(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_connection_lines_antialiased, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_connection_lines_antialiased(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_connection_lines_antialiased, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_minimap_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_minimap_size, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_minimap_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		GraphEdit *obj = static_cast<GraphEdit *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_minimap_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		GraphEdit *js_proxy = static_cast<GraphEdit *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_minimap_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue graph_edit_class_set_minimap_opacity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_minimap_opacity, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_minimap_opacity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_minimap_opacity, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_minimap_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_minimap_enabled, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_minimap_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_minimap_enabled, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_menu, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_menu, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_zoom_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_zoom_label, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_zoom_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_zoom_label, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_grid_buttons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_grid_buttons, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_grid_buttons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_grid_buttons, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_zoom_buttons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_zoom_buttons, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_zoom_buttons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_zoom_buttons, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_minimap_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_minimap_button, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_minimap_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_minimap_button, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_show_arrange_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_show_arrange_button, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_showing_arrange_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_showing_arrange_button, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_right_disconnects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_right_disconnects, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_is_right_disconnects_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::is_right_disconnects_enabled, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_set_type_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_type_names, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_get_type_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GraphEdit::get_type_names, ctx, this_val, argc, argv);
}
static JSValue graph_edit_class_get_menu_hbox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GraphEdit::get_menu_hbox, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_arrange_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::arrange_nodes, ctx, this_val, argc, argv);
};
static JSValue graph_edit_class_set_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GraphEdit::set_selected, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry graph_edit_class_proto_funcs[] = {
	JS_CFUNC_DEF("connect_node", 5, &graph_edit_class_connect_node),
	JS_CFUNC_DEF("is_node_connected", 4, &graph_edit_class_is_node_connected),
	JS_CFUNC_DEF("disconnect_node", 4, &graph_edit_class_disconnect_node),
	JS_CFUNC_DEF("set_connection_activity", 5, &graph_edit_class_set_connection_activity),
	JS_CFUNC_DEF("set_connections", 1, &graph_edit_class_set_connections),
	JS_CFUNC_DEF("get_connection_list", 0, &graph_edit_class_get_connection_list),
	JS_CFUNC_DEF("get_connection_count", 2, &graph_edit_class_get_connection_count),
	JS_CFUNC_DEF("get_closest_connection_at_point", 2, &graph_edit_class_get_closest_connection_at_point),
	JS_CFUNC_DEF("get_connection_list_from_node", 1, &graph_edit_class_get_connection_list_from_node),
	JS_CFUNC_DEF("get_connections_intersecting_with_rect", 1, &graph_edit_class_get_connections_intersecting_with_rect),
	JS_CFUNC_DEF("clear_connections", 0, &graph_edit_class_clear_connections),
	JS_CFUNC_DEF("force_connection_drag_end", 0, &graph_edit_class_force_connection_drag_end),
	JS_CFUNC_DEF("get_scroll_offset", 0, &graph_edit_class_get_scroll_offset),
	JS_CFUNC_DEF("set_scroll_offset", 1, &graph_edit_class_set_scroll_offset),
	JS_CFUNC_DEF("add_valid_right_disconnect_type", 1, &graph_edit_class_add_valid_right_disconnect_type),
	JS_CFUNC_DEF("remove_valid_right_disconnect_type", 1, &graph_edit_class_remove_valid_right_disconnect_type),
	JS_CFUNC_DEF("add_valid_left_disconnect_type", 1, &graph_edit_class_add_valid_left_disconnect_type),
	JS_CFUNC_DEF("remove_valid_left_disconnect_type", 1, &graph_edit_class_remove_valid_left_disconnect_type),
	JS_CFUNC_DEF("add_valid_connection_type", 2, &graph_edit_class_add_valid_connection_type),
	JS_CFUNC_DEF("remove_valid_connection_type", 2, &graph_edit_class_remove_valid_connection_type),
	JS_CFUNC_DEF("is_valid_connection_type", 2, &graph_edit_class_is_valid_connection_type),
	JS_CFUNC_DEF("get_connection_line", 2, &graph_edit_class_get_connection_line),
	JS_CFUNC_DEF("attach_graph_element_to_frame", 2, &graph_edit_class_attach_graph_element_to_frame),
	JS_CFUNC_DEF("detach_graph_element_from_frame", 1, &graph_edit_class_detach_graph_element_from_frame),
	JS_CFUNC_DEF("get_element_frame", 1, &graph_edit_class_get_element_frame),
	JS_CFUNC_DEF("get_attached_nodes_of_frame", 1, &graph_edit_class_get_attached_nodes_of_frame),
	JS_CFUNC_DEF("set_panning_scheme", 1, &graph_edit_class_set_panning_scheme),
	JS_CFUNC_DEF("get_panning_scheme", 0, &graph_edit_class_get_panning_scheme),
	JS_CFUNC_DEF("set_zoom", 1, &graph_edit_class_set_zoom),
	JS_CFUNC_DEF("get_zoom", 0, &graph_edit_class_get_zoom),
	JS_CFUNC_DEF("set_zoom_min", 1, &graph_edit_class_set_zoom_min),
	JS_CFUNC_DEF("get_zoom_min", 0, &graph_edit_class_get_zoom_min),
	JS_CFUNC_DEF("set_zoom_max", 1, &graph_edit_class_set_zoom_max),
	JS_CFUNC_DEF("get_zoom_max", 0, &graph_edit_class_get_zoom_max),
	JS_CFUNC_DEF("set_zoom_step", 1, &graph_edit_class_set_zoom_step),
	JS_CFUNC_DEF("get_zoom_step", 0, &graph_edit_class_get_zoom_step),
	JS_CFUNC_DEF("set_show_grid", 1, &graph_edit_class_set_show_grid),
	JS_CFUNC_DEF("is_showing_grid", 0, &graph_edit_class_is_showing_grid),
	JS_CFUNC_DEF("set_grid_pattern", 1, &graph_edit_class_set_grid_pattern),
	JS_CFUNC_DEF("get_grid_pattern", 0, &graph_edit_class_get_grid_pattern),
	JS_CFUNC_DEF("set_snapping_enabled", 1, &graph_edit_class_set_snapping_enabled),
	JS_CFUNC_DEF("is_snapping_enabled", 0, &graph_edit_class_is_snapping_enabled),
	JS_CFUNC_DEF("set_snapping_distance", 1, &graph_edit_class_set_snapping_distance),
	JS_CFUNC_DEF("get_snapping_distance", 0, &graph_edit_class_get_snapping_distance),
	JS_CFUNC_DEF("set_connection_lines_curvature", 1, &graph_edit_class_set_connection_lines_curvature),
	JS_CFUNC_DEF("get_connection_lines_curvature", 0, &graph_edit_class_get_connection_lines_curvature),
	JS_CFUNC_DEF("set_connection_lines_thickness", 1, &graph_edit_class_set_connection_lines_thickness),
	JS_CFUNC_DEF("get_connection_lines_thickness", 0, &graph_edit_class_get_connection_lines_thickness),
	JS_CFUNC_DEF("set_connection_lines_antialiased", 1, &graph_edit_class_set_connection_lines_antialiased),
	JS_CFUNC_DEF("is_connection_lines_antialiased", 0, &graph_edit_class_is_connection_lines_antialiased),
	JS_CFUNC_DEF("set_minimap_size", 1, &graph_edit_class_set_minimap_size),
	JS_CFUNC_DEF("get_minimap_size", 0, &graph_edit_class_get_minimap_size),
	JS_CFUNC_DEF("set_minimap_opacity", 1, &graph_edit_class_set_minimap_opacity),
	JS_CFUNC_DEF("get_minimap_opacity", 0, &graph_edit_class_get_minimap_opacity),
	JS_CFUNC_DEF("set_minimap_enabled", 1, &graph_edit_class_set_minimap_enabled),
	JS_CFUNC_DEF("is_minimap_enabled", 0, &graph_edit_class_is_minimap_enabled),
	JS_CFUNC_DEF("set_show_menu", 1, &graph_edit_class_set_show_menu),
	JS_CFUNC_DEF("is_showing_menu", 0, &graph_edit_class_is_showing_menu),
	JS_CFUNC_DEF("set_show_zoom_label", 1, &graph_edit_class_set_show_zoom_label),
	JS_CFUNC_DEF("is_showing_zoom_label", 0, &graph_edit_class_is_showing_zoom_label),
	JS_CFUNC_DEF("set_show_grid_buttons", 1, &graph_edit_class_set_show_grid_buttons),
	JS_CFUNC_DEF("is_showing_grid_buttons", 0, &graph_edit_class_is_showing_grid_buttons),
	JS_CFUNC_DEF("set_show_zoom_buttons", 1, &graph_edit_class_set_show_zoom_buttons),
	JS_CFUNC_DEF("is_showing_zoom_buttons", 0, &graph_edit_class_is_showing_zoom_buttons),
	JS_CFUNC_DEF("set_show_minimap_button", 1, &graph_edit_class_set_show_minimap_button),
	JS_CFUNC_DEF("is_showing_minimap_button", 0, &graph_edit_class_is_showing_minimap_button),
	JS_CFUNC_DEF("set_show_arrange_button", 1, &graph_edit_class_set_show_arrange_button),
	JS_CFUNC_DEF("is_showing_arrange_button", 0, &graph_edit_class_is_showing_arrange_button),
	JS_CFUNC_DEF("set_right_disconnects", 1, &graph_edit_class_set_right_disconnects),
	JS_CFUNC_DEF("is_right_disconnects_enabled", 0, &graph_edit_class_is_right_disconnects_enabled),
	JS_CFUNC_DEF("set_type_names", 1, &graph_edit_class_set_type_names),
	JS_CFUNC_DEF("get_type_names", 0, &graph_edit_class_get_type_names),
	JS_CFUNC_DEF("get_menu_hbox", 0, &graph_edit_class_get_menu_hbox),
	JS_CFUNC_DEF("arrange_nodes", 0, &graph_edit_class_arrange_nodes),
	JS_CFUNC_DEF("set_selected", 1, &graph_edit_class_set_selected),
};


static JSValue graph_edit_class_get_connection_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connection_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connection_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "connection_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_disconnection_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "disconnection_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "disconnection_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "disconnection_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_connection_to_empty_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connection_to_empty_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connection_to_empty"));
		JS_DefinePropertyValueStr(ctx, this_val, "connection_to_empty_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_connection_from_empty_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connection_from_empty_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connection_from_empty"));
		JS_DefinePropertyValueStr(ctx, this_val, "connection_from_empty_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_connection_drag_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connection_drag_started_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connection_drag_started"));
		JS_DefinePropertyValueStr(ctx, this_val, "connection_drag_started_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_connection_drag_ended_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connection_drag_ended_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connection_drag_ended"));
		JS_DefinePropertyValueStr(ctx, this_val, "connection_drag_ended_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_copy_nodes_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "copy_nodes_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "copy_nodes_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "copy_nodes_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_cut_nodes_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "cut_nodes_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "cut_nodes_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "cut_nodes_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_paste_nodes_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "paste_nodes_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "paste_nodes_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "paste_nodes_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_duplicate_nodes_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "duplicate_nodes_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "duplicate_nodes_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "duplicate_nodes_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_delete_nodes_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "delete_nodes_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "delete_nodes_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "delete_nodes_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_node_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_node_deselected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_deselected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_deselected"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_deselected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_frame_rect_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "frame_rect_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "frame_rect_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "frame_rect_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_popup_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "popup_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "popup_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "popup_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_begin_node_move_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "begin_node_move_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "begin_node_move"));
		JS_DefinePropertyValueStr(ctx, this_val, "begin_node_move_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_end_node_move_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "end_node_move_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "end_node_move"));
		JS_DefinePropertyValueStr(ctx, this_val, "end_node_move_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_graph_elements_linked_to_frame_request_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "graph_elements_linked_to_frame_request_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "graph_elements_linked_to_frame_request"));
		JS_DefinePropertyValueStr(ctx, this_val, "graph_elements_linked_to_frame_request_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue graph_edit_class_get_scroll_offset_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GraphEdit *opaque = static_cast<GraphEdit *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scroll_offset_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scroll_offset_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "scroll_offset_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_graph_edit_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scroll_offset"),
        JS_NewCFunction(ctx, graph_edit_class_get_scroll_offset, "get_scroll_offset", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_scroll_offset, "set_scroll_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_grid"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_grid, "is_showing_grid", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_grid, "set_show_grid", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "grid_pattern"),
        JS_NewCFunction(ctx, graph_edit_class_get_grid_pattern, "get_grid_pattern", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_grid_pattern, "set_grid_pattern", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "snapping_enabled"),
        JS_NewCFunction(ctx, graph_edit_class_is_snapping_enabled, "is_snapping_enabled", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_snapping_enabled, "set_snapping_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "snapping_distance"),
        JS_NewCFunction(ctx, graph_edit_class_get_snapping_distance, "get_snapping_distance", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_snapping_distance, "set_snapping_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "panning_scheme"),
        JS_NewCFunction(ctx, graph_edit_class_get_panning_scheme, "get_panning_scheme", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_panning_scheme, "set_panning_scheme", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "right_disconnects"),
        JS_NewCFunction(ctx, graph_edit_class_is_right_disconnects_enabled, "is_right_disconnects_enabled", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_right_disconnects, "set_right_disconnects", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "type_names"),
        JS_NewCFunction(ctx, graph_edit_class_get_type_names, "get_type_names", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_type_names, "set_type_names", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "connection_lines_curvature"),
        JS_NewCFunction(ctx, graph_edit_class_get_connection_lines_curvature, "get_connection_lines_curvature", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_connection_lines_curvature, "set_connection_lines_curvature", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "connection_lines_thickness"),
        JS_NewCFunction(ctx, graph_edit_class_get_connection_lines_thickness, "get_connection_lines_thickness", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_connection_lines_thickness, "set_connection_lines_thickness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "connection_lines_antialiased"),
        JS_NewCFunction(ctx, graph_edit_class_is_connection_lines_antialiased, "is_connection_lines_antialiased", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_connection_lines_antialiased, "set_connection_lines_antialiased", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "connections"),
        JS_NewCFunction(ctx, graph_edit_class_get_connection_list, "get_connection_list", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_connections, "set_connections", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "zoom"),
        JS_NewCFunction(ctx, graph_edit_class_get_zoom, "get_zoom", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_zoom, "set_zoom", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "zoom_min"),
        JS_NewCFunction(ctx, graph_edit_class_get_zoom_min, "get_zoom_min", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_zoom_min, "set_zoom_min", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "zoom_max"),
        JS_NewCFunction(ctx, graph_edit_class_get_zoom_max, "get_zoom_max", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_zoom_max, "set_zoom_max", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "zoom_step"),
        JS_NewCFunction(ctx, graph_edit_class_get_zoom_step, "get_zoom_step", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_zoom_step, "set_zoom_step", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minimap_enabled"),
        JS_NewCFunction(ctx, graph_edit_class_is_minimap_enabled, "is_minimap_enabled", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_minimap_enabled, "set_minimap_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minimap_size"),
        JS_NewCFunction(ctx, graph_edit_class_get_minimap_size, "get_minimap_size", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_minimap_size, "set_minimap_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minimap_opacity"),
        JS_NewCFunction(ctx, graph_edit_class_get_minimap_opacity, "get_minimap_opacity", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_minimap_opacity, "set_minimap_opacity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_menu"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_menu, "is_showing_menu", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_menu, "set_show_menu", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_zoom_label"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_zoom_label, "is_showing_zoom_label", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_zoom_label, "set_show_zoom_label", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_zoom_buttons"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_zoom_buttons, "is_showing_zoom_buttons", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_zoom_buttons, "set_show_zoom_buttons", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_grid_buttons"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_grid_buttons, "is_showing_grid_buttons", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_grid_buttons, "set_show_grid_buttons", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_minimap_button"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_minimap_button, "is_showing_minimap_button", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_minimap_button, "set_show_minimap_button", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_arrange_button"),
        JS_NewCFunction(ctx, graph_edit_class_is_showing_arrange_button, "is_showing_arrange_button", 0),
        JS_NewCFunction(ctx, graph_edit_class_set_show_arrange_button, "set_show_arrange_button", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connection_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_connection_request_signal, "get_connection_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "disconnection_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_disconnection_request_signal, "get_disconnection_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connection_to_empty"),
		JS_NewCFunction(ctx, graph_edit_class_get_connection_to_empty_signal, "get_connection_to_empty_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connection_from_empty"),
		JS_NewCFunction(ctx, graph_edit_class_get_connection_from_empty_signal, "get_connection_from_empty_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connection_drag_started"),
		JS_NewCFunction(ctx, graph_edit_class_get_connection_drag_started_signal, "get_connection_drag_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connection_drag_ended"),
		JS_NewCFunction(ctx, graph_edit_class_get_connection_drag_ended_signal, "get_connection_drag_ended_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "copy_nodes_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_copy_nodes_request_signal, "get_copy_nodes_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "cut_nodes_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_cut_nodes_request_signal, "get_cut_nodes_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "paste_nodes_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_paste_nodes_request_signal, "get_paste_nodes_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "duplicate_nodes_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_duplicate_nodes_request_signal, "get_duplicate_nodes_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "delete_nodes_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_delete_nodes_request_signal, "get_delete_nodes_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_selected"),
		JS_NewCFunction(ctx, graph_edit_class_get_node_selected_signal, "get_node_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_deselected"),
		JS_NewCFunction(ctx, graph_edit_class_get_node_deselected_signal, "get_node_deselected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "frame_rect_changed"),
		JS_NewCFunction(ctx, graph_edit_class_get_frame_rect_changed_signal, "get_frame_rect_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "popup_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_popup_request_signal, "get_popup_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "begin_node_move"),
		JS_NewCFunction(ctx, graph_edit_class_get_begin_node_move_signal, "get_begin_node_move_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "end_node_move"),
		JS_NewCFunction(ctx, graph_edit_class_get_end_node_move_signal, "get_end_node_move_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "graph_elements_linked_to_frame_request"),
		JS_NewCFunction(ctx, graph_edit_class_get_graph_elements_linked_to_frame_request_signal, "get_graph_elements_linked_to_frame_request_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scroll_offset_changed"),
		JS_NewCFunction(ctx, graph_edit_class_get_scroll_offset_changed_signal, "get_scroll_offset_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_graph_edit_enum(JSContext *ctx, JSValue ctor) {
	JSValue PanningScheme_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PanningScheme_obj, "SCROLL_ZOOMS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PanningScheme_obj, "SCROLL_PANS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "PanningScheme", PanningScheme_obj);
	JSValue GridPattern_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GridPattern_obj, "GRID_PATTERN_LINES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GridPattern_obj, "GRID_PATTERN_DOTS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "GridPattern", GridPattern_obj);
}

static int js_graph_edit_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GraphEdit"] = class_id;
	classes_by_id[class_id] = "GraphEdit";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &graph_edit_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_graph_edit_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, graph_edit_class_proto_funcs, _countof(graph_edit_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, graph_edit_class_constructor, "GraphEdit", 0, JS_CFUNC_constructor, 0);
	define_graph_edit_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GraphEdit", ctor);

	return 0;
}

JSModuleDef *_js_init_graph_edit_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_graph_edit_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GraphEdit");
	return m;
}

JSModuleDef *js_init_graph_edit_module(JSContext *ctx) {
	return _js_init_graph_edit_module(ctx, "@godot/classes/graph_edit");
}

void __register_graph_edit() {
	js_init_graph_edit_module(js_context());
}

void register_graph_edit() {
	__register_graph_edit();
}