#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include "register/classes/class_node_vararg.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/multiplayer_api.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/node.hpp>
using namespace godot;

static void node_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Node"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef node_class_def = {
    "Node",
    node_class_finalizer
};

static JSValue node_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Node"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(Node);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue node_class_add_sibling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::add_sibling, ctx, this_val, argc, argv);
};
static JSValue node_class_set_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_name, ctx, this_val, argc, argv);
};
static JSValue node_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_name, ctx, this_val, argc, argv);
}
static JSValue node_class_add_child(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::add_child, ctx, this_val, argc, argv);
};
static JSValue node_class_remove_child(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::remove_child, ctx, this_val, argc, argv);
};
static JSValue node_class_reparent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::reparent, ctx, this_val, argc, argv);
};
static JSValue node_class_get_child_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_child_count, ctx, this_val, argc, argv);
};
static JSValue node_class_get_children(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_children, ctx, this_val, argc, argv);
};
static JSValue node_class_get_child(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_child, ctx, this_val, argc, argv);
};
static JSValue node_class_has_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::has_node, ctx, this_val, argc, argv);
};
static JSValue node_class_get_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_node_internal, ctx, this_val, argc, argv);
};
static JSValue node_class_get_node_or_null(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_node_or_null, ctx, this_val, argc, argv);
};
static JSValue node_class_get_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_parent, ctx, this_val, argc, argv);
};
static JSValue node_class_find_child(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::find_child, ctx, this_val, argc, argv);
};
static JSValue node_class_find_children(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::find_children, ctx, this_val, argc, argv);
};
static JSValue node_class_find_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::find_parent, ctx, this_val, argc, argv);
};
static JSValue node_class_has_node_and_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::has_node_and_resource, ctx, this_val, argc, argv);
};
static JSValue node_class_get_node_and_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Node::get_node_and_resource, ctx, this_val, argc, argv);
};
static JSValue node_class_is_inside_tree(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_inside_tree, ctx, this_val, argc, argv);
};
static JSValue node_class_is_part_of_edited_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_part_of_edited_scene, ctx, this_val, argc, argv);
};
static JSValue node_class_is_ancestor_of(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_ancestor_of, ctx, this_val, argc, argv);
};
static JSValue node_class_is_greater_than(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_greater_than, ctx, this_val, argc, argv);
};
static JSValue node_class_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_path, ctx, this_val, argc, argv);
};
static JSValue node_class_get_path_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_path_to, ctx, this_val, argc, argv);
};
static JSValue node_class_add_to_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::add_to_group, ctx, this_val, argc, argv);
};
static JSValue node_class_remove_from_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::remove_from_group, ctx, this_val, argc, argv);
};
static JSValue node_class_is_in_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_in_group, ctx, this_val, argc, argv);
};
static JSValue node_class_move_child(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::move_child, ctx, this_val, argc, argv);
};
static JSValue node_class_get_groups(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_groups, ctx, this_val, argc, argv);
};
static JSValue node_class_set_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_owner, ctx, this_val, argc, argv);
};
static JSValue node_class_get_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_owner, ctx, this_val, argc, argv);
}
static JSValue node_class_get_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_index, ctx, this_val, argc, argv);
};
static JSValue node_class_print_tree(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::print_tree, ctx, this_val, argc, argv);
};
static JSValue node_class_print_tree_pretty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::print_tree_pretty, ctx, this_val, argc, argv);
};
static JSValue node_class_get_tree_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Node::get_tree_string, ctx, this_val, argc, argv);
};
static JSValue node_class_get_tree_string_pretty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Node::get_tree_string_pretty, ctx, this_val, argc, argv);
};
static JSValue node_class_set_scene_file_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_scene_file_path, ctx, this_val, argc, argv);
};
static JSValue node_class_get_scene_file_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_scene_file_path, ctx, this_val, argc, argv);
}
static JSValue node_class_propagate_notification(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::propagate_notification, ctx, this_val, argc, argv);
};
static JSValue node_class_propagate_call(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::propagate_call, ctx, this_val, argc, argv);
};
static JSValue node_class_set_physics_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_physics_process, ctx, this_val, argc, argv);
};
static JSValue node_class_get_physics_process_delta_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_physics_process_delta_time, ctx, this_val, argc, argv);
};
static JSValue node_class_is_physics_processing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_physics_processing, ctx, this_val, argc, argv);
};
static JSValue node_class_get_process_delta_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_process_delta_time, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_priority, ctx, this_val, argc, argv);
};
static JSValue node_class_get_process_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_process_priority, ctx, this_val, argc, argv);
}
static JSValue node_class_set_physics_process_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_physics_process_priority, ctx, this_val, argc, argv);
};
static JSValue node_class_get_physics_process_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_physics_process_priority, ctx, this_val, argc, argv);
}
static JSValue node_class_is_processing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_processing, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_input, ctx, this_val, argc, argv);
};
static JSValue node_class_is_processing_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_processing_input, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_shortcut_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_shortcut_input, ctx, this_val, argc, argv);
};
static JSValue node_class_is_processing_shortcut_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_processing_shortcut_input, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_unhandled_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_unhandled_input, ctx, this_val, argc, argv);
};
static JSValue node_class_is_processing_unhandled_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_processing_unhandled_input, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_unhandled_key_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_unhandled_key_input, ctx, this_val, argc, argv);
};
static JSValue node_class_is_processing_unhandled_key_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_processing_unhandled_key_input, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_mode, ctx, this_val, argc, argv);
};
static JSValue node_class_get_process_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_process_mode, ctx, this_val, argc, argv);
}
static JSValue node_class_can_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::can_process, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_thread_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_thread_group, ctx, this_val, argc, argv);
};
static JSValue node_class_get_process_thread_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_process_thread_group, ctx, this_val, argc, argv);
}
static JSValue node_class_set_process_thread_messages(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_thread_messages, ctx, this_val, argc, argv);
};
static JSValue node_class_get_process_thread_messages(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_process_thread_messages, ctx, this_val, argc, argv);
}
static JSValue node_class_set_process_thread_group_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_thread_group_order, ctx, this_val, argc, argv);
};
static JSValue node_class_get_process_thread_group_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_process_thread_group_order, ctx, this_val, argc, argv);
}
static JSValue node_class_queue_accessibility_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::queue_accessibility_update, ctx, this_val, argc, argv);
};
static JSValue node_class_get_accessibility_element(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_accessibility_element, ctx, this_val, argc, argv);
};
static JSValue node_class_set_display_folded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_display_folded, ctx, this_val, argc, argv);
};
static JSValue node_class_is_displayed_folded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_displayed_folded, ctx, this_val, argc, argv);
};
static JSValue node_class_set_process_internal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_process_internal, ctx, this_val, argc, argv);
};
static JSValue node_class_is_processing_internal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_processing_internal, ctx, this_val, argc, argv);
};
static JSValue node_class_set_physics_process_internal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_physics_process_internal, ctx, this_val, argc, argv);
};
static JSValue node_class_is_physics_processing_internal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_physics_processing_internal, ctx, this_val, argc, argv);
};
static JSValue node_class_set_physics_interpolation_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_physics_interpolation_mode, ctx, this_val, argc, argv);
};
static JSValue node_class_get_physics_interpolation_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_physics_interpolation_mode, ctx, this_val, argc, argv);
}
static JSValue node_class_is_physics_interpolated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_physics_interpolated, ctx, this_val, argc, argv);
};
static JSValue node_class_is_physics_interpolated_and_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_physics_interpolated_and_enabled, ctx, this_val, argc, argv);
};
static JSValue node_class_reset_physics_interpolation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::reset_physics_interpolation, ctx, this_val, argc, argv);
};
static JSValue node_class_set_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_auto_translate_mode, ctx, this_val, argc, argv);
};
static JSValue node_class_get_auto_translate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_auto_translate_mode, ctx, this_val, argc, argv);
}
static JSValue node_class_can_auto_translate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::can_auto_translate, ctx, this_val, argc, argv);
};
static JSValue node_class_set_translation_domain_inherited(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_translation_domain_inherited, ctx, this_val, argc, argv);
};
static JSValue node_class_get_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_window, ctx, this_val, argc, argv);
};
static JSValue node_class_get_last_exclusive_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_last_exclusive_window, ctx, this_val, argc, argv);
};
static JSValue node_class_get_tree(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_tree, ctx, this_val, argc, argv);
};
static JSValue node_class_create_tween(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Node::create_tween, ctx, this_val, argc, argv);
};
static JSValue node_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::duplicate, ctx, this_val, argc, argv);
};
static JSValue node_class_replace_by(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::replace_by, ctx, this_val, argc, argv);
};
static JSValue node_class_set_scene_instance_load_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_scene_instance_load_placeholder, ctx, this_val, argc, argv);
};
static JSValue node_class_get_scene_instance_load_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_scene_instance_load_placeholder, ctx, this_val, argc, argv);
};
static JSValue node_class_set_editable_instance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_editable_instance, ctx, this_val, argc, argv);
};
static JSValue node_class_is_editable_instance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_editable_instance, ctx, this_val, argc, argv);
};
static JSValue node_class_get_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_viewport, ctx, this_val, argc, argv);
};
static JSValue node_class_queue_free(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::queue_free, ctx, this_val, argc, argv);
};
static JSValue node_class_request_ready(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::request_ready, ctx, this_val, argc, argv);
};
static JSValue node_class_is_node_ready(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_node_ready, ctx, this_val, argc, argv);
};
static JSValue node_class_set_multiplayer_authority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_multiplayer_authority, ctx, this_val, argc, argv);
};
static JSValue node_class_get_multiplayer_authority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_multiplayer_authority, ctx, this_val, argc, argv);
};
static JSValue node_class_is_multiplayer_authority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_multiplayer_authority, ctx, this_val, argc, argv);
};
static JSValue node_class_get_multiplayer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_multiplayer, ctx, this_val, argc, argv);
}
static JSValue node_class_rpc_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::rpc_config, ctx, this_val, argc, argv);
};
static JSValue node_class_get_node_rpc_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_node_rpc_config, ctx, this_val, argc, argv);
};
static JSValue node_class_set_editor_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_editor_description, ctx, this_val, argc, argv);
};
static JSValue node_class_get_editor_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::get_editor_description, ctx, this_val, argc, argv);
}
static JSValue node_class_set_unique_name_in_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_unique_name_in_owner, ctx, this_val, argc, argv);
};
static JSValue node_class_is_unique_name_in_owner(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::is_unique_name_in_owner, ctx, this_val, argc, argv);
}
static JSValue node_class_atr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::atr, ctx, this_val, argc, argv);
};
static JSValue node_class_atr_n(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Node::atr_n, ctx, this_val, argc, argv);
};
static JSValue node_class_update_configuration_warnings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::update_configuration_warnings, ctx, this_val, argc, argv);
};
static JSValue node_class_set_deferred_thread_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_deferred_thread_group, ctx, this_val, argc, argv);
};
static JSValue node_class_notify_deferred_thread_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::notify_deferred_thread_group, ctx, this_val, argc, argv);
};
static JSValue node_class_set_thread_safe(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::set_thread_safe, ctx, this_val, argc, argv);
};
static JSValue node_class_notify_thread_safe(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Node::notify_thread_safe, ctx, this_val, argc, argv);
};


static JSValue node_class_print_orphan_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&Node::print_orphan_nodes, ctx, this_val, argc, argv);
};
static JSValue node_class_get_orphan_node_ids(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Node::get_orphan_node_ids, ctx, this_val, argc, argv);
};
static JSValue node_class_rpc(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_rpc, ctx, this_val, argc, argv);
}
static JSValue node_class_rpc_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_rpc_id, ctx, this_val, argc, argv);
}
static JSValue node_class_call_deferred_thread_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_call_deferred_thread_group, ctx, this_val, argc, argv);
}
static JSValue node_class_call_thread_safe(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_free_owner_vararg_method_ret(&js_call_thread_safe, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry node_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_sibling", 2, &node_class_add_sibling),
	JS_CFUNC_DEF("set_name", 1, &node_class_set_name),
	JS_CFUNC_DEF("get_name", 0, &node_class_get_name),
	JS_CFUNC_DEF("add_child", 3, &node_class_add_child),
	JS_CFUNC_DEF("remove_child", 1, &node_class_remove_child),
	JS_CFUNC_DEF("reparent", 2, &node_class_reparent),
	JS_CFUNC_DEF("get_child_count", 1, &node_class_get_child_count),
	JS_CFUNC_DEF("get_children", 1, &node_class_get_children),
	JS_CFUNC_DEF("get_child", 2, &node_class_get_child),
	JS_CFUNC_DEF("has_node", 1, &node_class_has_node),
	JS_CFUNC_DEF("get_node", 1, &node_class_get_node),
	JS_CFUNC_DEF("get_node_or_null", 1, &node_class_get_node_or_null),
	JS_CFUNC_DEF("get_parent", 0, &node_class_get_parent),
	JS_CFUNC_DEF("find_child", 3, &node_class_find_child),
	JS_CFUNC_DEF("find_children", 4, &node_class_find_children),
	JS_CFUNC_DEF("find_parent", 1, &node_class_find_parent),
	JS_CFUNC_DEF("has_node_and_resource", 1, &node_class_has_node_and_resource),
	JS_CFUNC_DEF("get_node_and_resource", 1, &node_class_get_node_and_resource),
	JS_CFUNC_DEF("is_inside_tree", 0, &node_class_is_inside_tree),
	JS_CFUNC_DEF("is_part_of_edited_scene", 0, &node_class_is_part_of_edited_scene),
	JS_CFUNC_DEF("is_ancestor_of", 1, &node_class_is_ancestor_of),
	JS_CFUNC_DEF("is_greater_than", 1, &node_class_is_greater_than),
	JS_CFUNC_DEF("get_path", 0, &node_class_get_path),
	JS_CFUNC_DEF("get_path_to", 2, &node_class_get_path_to),
	JS_CFUNC_DEF("add_to_group", 2, &node_class_add_to_group),
	JS_CFUNC_DEF("remove_from_group", 1, &node_class_remove_from_group),
	JS_CFUNC_DEF("is_in_group", 1, &node_class_is_in_group),
	JS_CFUNC_DEF("move_child", 2, &node_class_move_child),
	JS_CFUNC_DEF("get_groups", 0, &node_class_get_groups),
	JS_CFUNC_DEF("set_owner", 1, &node_class_set_owner),
	JS_CFUNC_DEF("get_owner", 0, &node_class_get_owner),
	JS_CFUNC_DEF("get_index", 1, &node_class_get_index),
	JS_CFUNC_DEF("print_tree", 0, &node_class_print_tree),
	JS_CFUNC_DEF("print_tree_pretty", 0, &node_class_print_tree_pretty),
	JS_CFUNC_DEF("get_tree_string", 0, &node_class_get_tree_string),
	JS_CFUNC_DEF("get_tree_string_pretty", 0, &node_class_get_tree_string_pretty),
	JS_CFUNC_DEF("set_scene_file_path", 1, &node_class_set_scene_file_path),
	JS_CFUNC_DEF("get_scene_file_path", 0, &node_class_get_scene_file_path),
	JS_CFUNC_DEF("propagate_notification", 1, &node_class_propagate_notification),
	JS_CFUNC_DEF("propagate_call", 3, &node_class_propagate_call),
	JS_CFUNC_DEF("set_physics_process", 1, &node_class_set_physics_process),
	JS_CFUNC_DEF("get_physics_process_delta_time", 0, &node_class_get_physics_process_delta_time),
	JS_CFUNC_DEF("is_physics_processing", 0, &node_class_is_physics_processing),
	JS_CFUNC_DEF("get_process_delta_time", 0, &node_class_get_process_delta_time),
	JS_CFUNC_DEF("set_process", 1, &node_class_set_process),
	JS_CFUNC_DEF("set_process_priority", 1, &node_class_set_process_priority),
	JS_CFUNC_DEF("get_process_priority", 0, &node_class_get_process_priority),
	JS_CFUNC_DEF("set_physics_process_priority", 1, &node_class_set_physics_process_priority),
	JS_CFUNC_DEF("get_physics_process_priority", 0, &node_class_get_physics_process_priority),
	JS_CFUNC_DEF("is_processing", 0, &node_class_is_processing),
	JS_CFUNC_DEF("set_process_input", 1, &node_class_set_process_input),
	JS_CFUNC_DEF("is_processing_input", 0, &node_class_is_processing_input),
	JS_CFUNC_DEF("set_process_shortcut_input", 1, &node_class_set_process_shortcut_input),
	JS_CFUNC_DEF("is_processing_shortcut_input", 0, &node_class_is_processing_shortcut_input),
	JS_CFUNC_DEF("set_process_unhandled_input", 1, &node_class_set_process_unhandled_input),
	JS_CFUNC_DEF("is_processing_unhandled_input", 0, &node_class_is_processing_unhandled_input),
	JS_CFUNC_DEF("set_process_unhandled_key_input", 1, &node_class_set_process_unhandled_key_input),
	JS_CFUNC_DEF("is_processing_unhandled_key_input", 0, &node_class_is_processing_unhandled_key_input),
	JS_CFUNC_DEF("set_process_mode", 1, &node_class_set_process_mode),
	JS_CFUNC_DEF("get_process_mode", 0, &node_class_get_process_mode),
	JS_CFUNC_DEF("can_process", 0, &node_class_can_process),
	JS_CFUNC_DEF("set_process_thread_group", 1, &node_class_set_process_thread_group),
	JS_CFUNC_DEF("get_process_thread_group", 0, &node_class_get_process_thread_group),
	JS_CFUNC_DEF("set_process_thread_messages", 1, &node_class_set_process_thread_messages),
	JS_CFUNC_DEF("get_process_thread_messages", 0, &node_class_get_process_thread_messages),
	JS_CFUNC_DEF("set_process_thread_group_order", 1, &node_class_set_process_thread_group_order),
	JS_CFUNC_DEF("get_process_thread_group_order", 0, &node_class_get_process_thread_group_order),
	JS_CFUNC_DEF("queue_accessibility_update", 0, &node_class_queue_accessibility_update),
	JS_CFUNC_DEF("get_accessibility_element", 0, &node_class_get_accessibility_element),
	JS_CFUNC_DEF("set_display_folded", 1, &node_class_set_display_folded),
	JS_CFUNC_DEF("is_displayed_folded", 0, &node_class_is_displayed_folded),
	JS_CFUNC_DEF("set_process_internal", 1, &node_class_set_process_internal),
	JS_CFUNC_DEF("is_processing_internal", 0, &node_class_is_processing_internal),
	JS_CFUNC_DEF("set_physics_process_internal", 1, &node_class_set_physics_process_internal),
	JS_CFUNC_DEF("is_physics_processing_internal", 0, &node_class_is_physics_processing_internal),
	JS_CFUNC_DEF("set_physics_interpolation_mode", 1, &node_class_set_physics_interpolation_mode),
	JS_CFUNC_DEF("get_physics_interpolation_mode", 0, &node_class_get_physics_interpolation_mode),
	JS_CFUNC_DEF("is_physics_interpolated", 0, &node_class_is_physics_interpolated),
	JS_CFUNC_DEF("is_physics_interpolated_and_enabled", 0, &node_class_is_physics_interpolated_and_enabled),
	JS_CFUNC_DEF("reset_physics_interpolation", 0, &node_class_reset_physics_interpolation),
	JS_CFUNC_DEF("set_auto_translate_mode", 1, &node_class_set_auto_translate_mode),
	JS_CFUNC_DEF("get_auto_translate_mode", 0, &node_class_get_auto_translate_mode),
	JS_CFUNC_DEF("can_auto_translate", 0, &node_class_can_auto_translate),
	JS_CFUNC_DEF("set_translation_domain_inherited", 0, &node_class_set_translation_domain_inherited),
	JS_CFUNC_DEF("get_window", 0, &node_class_get_window),
	JS_CFUNC_DEF("get_last_exclusive_window", 0, &node_class_get_last_exclusive_window),
	JS_CFUNC_DEF("get_tree", 0, &node_class_get_tree),
	JS_CFUNC_DEF("create_tween", 0, &node_class_create_tween),
	JS_CFUNC_DEF("duplicate", 1, &node_class_duplicate),
	JS_CFUNC_DEF("replace_by", 2, &node_class_replace_by),
	JS_CFUNC_DEF("set_scene_instance_load_placeholder", 1, &node_class_set_scene_instance_load_placeholder),
	JS_CFUNC_DEF("get_scene_instance_load_placeholder", 0, &node_class_get_scene_instance_load_placeholder),
	JS_CFUNC_DEF("set_editable_instance", 2, &node_class_set_editable_instance),
	JS_CFUNC_DEF("is_editable_instance", 1, &node_class_is_editable_instance),
	JS_CFUNC_DEF("get_viewport", 0, &node_class_get_viewport),
	JS_CFUNC_DEF("queue_free", 0, &node_class_queue_free),
	JS_CFUNC_DEF("request_ready", 0, &node_class_request_ready),
	JS_CFUNC_DEF("is_node_ready", 0, &node_class_is_node_ready),
	JS_CFUNC_DEF("set_multiplayer_authority", 2, &node_class_set_multiplayer_authority),
	JS_CFUNC_DEF("get_multiplayer_authority", 0, &node_class_get_multiplayer_authority),
	JS_CFUNC_DEF("is_multiplayer_authority", 0, &node_class_is_multiplayer_authority),
	JS_CFUNC_DEF("get_multiplayer", 0, &node_class_get_multiplayer),
	JS_CFUNC_DEF("rpc_config", 2, &node_class_rpc_config),
	JS_CFUNC_DEF("get_node_rpc_config", 0, &node_class_get_node_rpc_config),
	JS_CFUNC_DEF("set_editor_description", 1, &node_class_set_editor_description),
	JS_CFUNC_DEF("get_editor_description", 0, &node_class_get_editor_description),
	JS_CFUNC_DEF("set_unique_name_in_owner", 1, &node_class_set_unique_name_in_owner),
	JS_CFUNC_DEF("is_unique_name_in_owner", 0, &node_class_is_unique_name_in_owner),
	JS_CFUNC_DEF("atr", 2, &node_class_atr),
	JS_CFUNC_DEF("atr_n", 4, &node_class_atr_n),
	JS_CFUNC_DEF("update_configuration_warnings", 0, &node_class_update_configuration_warnings),
	JS_CFUNC_DEF("set_deferred_thread_group", 2, &node_class_set_deferred_thread_group),
	JS_CFUNC_DEF("notify_deferred_thread_group", 1, &node_class_notify_deferred_thread_group),
	JS_CFUNC_DEF("set_thread_safe", 2, &node_class_set_thread_safe),
	JS_CFUNC_DEF("notify_thread_safe", 1, &node_class_notify_thread_safe),
	JS_CFUNC_DEF("rpc", 1, &node_class_rpc),
	JS_CFUNC_DEF("rpc_id", 2, &node_class_rpc_id),
	JS_CFUNC_DEF("call_deferred_thread_group", 1, &node_class_call_deferred_thread_group),
	JS_CFUNC_DEF("call_thread_safe", 1, &node_class_call_thread_safe),
};

static const JSCFunctionListEntry node_class_static_funcs[] = {
	JS_CFUNC_DEF("print_orphan_nodes", 0, &node_class_print_orphan_nodes),
	JS_CFUNC_DEF("get_orphan_node_ids", 0, &node_class_get_orphan_node_ids),
};

static JSValue node_class_get_ready_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "ready");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_renamed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "renamed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_tree_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "tree_entered");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_tree_exiting_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "tree_exiting");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_tree_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "tree_exited");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_child_entered_tree_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "child_entered_tree");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_child_exiting_tree_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "child_exiting_tree");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_child_order_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "child_order_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_replacing_by_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "replacing_by");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_editor_description_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "editor_description_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue node_class_get_editor_state_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "editor_state_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_node_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "name"),
        JS_NewCFunction(ctx, node_class_get_name, "get_name", 0),
        JS_NewCFunction(ctx, node_class_set_name, "set_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unique_name_in_owner"),
        JS_NewCFunction(ctx, node_class_is_unique_name_in_owner, "is_unique_name_in_owner", 0),
        JS_NewCFunction(ctx, node_class_set_unique_name_in_owner, "set_unique_name_in_owner", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scene_file_path"),
        JS_NewCFunction(ctx, node_class_get_scene_file_path, "get_scene_file_path", 0),
        JS_NewCFunction(ctx, node_class_set_scene_file_path, "set_scene_file_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "owner"),
        JS_NewCFunction(ctx, node_class_get_owner, "get_owner", 0),
        JS_NewCFunction(ctx, node_class_set_owner, "set_owner", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "multiplayer"),
        JS_NewCFunction(ctx, node_class_get_multiplayer, "get_multiplayer", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_mode"),
        JS_NewCFunction(ctx, node_class_get_process_mode, "get_process_mode", 0),
        JS_NewCFunction(ctx, node_class_set_process_mode, "set_process_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_priority"),
        JS_NewCFunction(ctx, node_class_get_process_priority, "get_process_priority", 0),
        JS_NewCFunction(ctx, node_class_set_process_priority, "set_process_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_physics_priority"),
        JS_NewCFunction(ctx, node_class_get_physics_process_priority, "get_physics_process_priority", 0),
        JS_NewCFunction(ctx, node_class_set_physics_process_priority, "set_physics_process_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_thread_group"),
        JS_NewCFunction(ctx, node_class_get_process_thread_group, "get_process_thread_group", 0),
        JS_NewCFunction(ctx, node_class_set_process_thread_group, "set_process_thread_group", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_thread_group_order"),
        JS_NewCFunction(ctx, node_class_get_process_thread_group_order, "get_process_thread_group_order", 0),
        JS_NewCFunction(ctx, node_class_set_process_thread_group_order, "set_process_thread_group_order", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_thread_messages"),
        JS_NewCFunction(ctx, node_class_get_process_thread_messages, "get_process_thread_messages", 0),
        JS_NewCFunction(ctx, node_class_set_process_thread_messages, "set_process_thread_messages", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "physics_interpolation_mode"),
        JS_NewCFunction(ctx, node_class_get_physics_interpolation_mode, "get_physics_interpolation_mode", 0),
        JS_NewCFunction(ctx, node_class_set_physics_interpolation_mode, "set_physics_interpolation_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_translate_mode"),
        JS_NewCFunction(ctx, node_class_get_auto_translate_mode, "get_auto_translate_mode", 0),
        JS_NewCFunction(ctx, node_class_set_auto_translate_mode, "set_auto_translate_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editor_description"),
        JS_NewCFunction(ctx, node_class_get_editor_description, "get_editor_description", 0),
        JS_NewCFunction(ctx, node_class_set_editor_description, "set_editor_description", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "ready"),
		JS_NewCFunction(ctx, node_class_get_ready_signal, "get_ready_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "renamed"),
		JS_NewCFunction(ctx, node_class_get_renamed_signal, "get_renamed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tree_entered"),
		JS_NewCFunction(ctx, node_class_get_tree_entered_signal, "get_tree_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tree_exiting"),
		JS_NewCFunction(ctx, node_class_get_tree_exiting_signal, "get_tree_exiting_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tree_exited"),
		JS_NewCFunction(ctx, node_class_get_tree_exited_signal, "get_tree_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "child_entered_tree"),
		JS_NewCFunction(ctx, node_class_get_child_entered_tree_signal, "get_child_entered_tree_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "child_exiting_tree"),
		JS_NewCFunction(ctx, node_class_get_child_exiting_tree_signal, "get_child_exiting_tree_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "child_order_changed"),
		JS_NewCFunction(ctx, node_class_get_child_order_changed_signal, "get_child_order_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "replacing_by"),
		JS_NewCFunction(ctx, node_class_get_replacing_by_signal, "get_replacing_by_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "editor_description_changed"),
		JS_NewCFunction(ctx, node_class_get_editor_description_changed_signal, "get_editor_description_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "editor_state_changed"),
		JS_NewCFunction(ctx, node_class_get_editor_state_changed_signal, "get_editor_state_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_node_enum(JSContext *ctx, JSValue ctor) {
	JSValue ProcessMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_INHERIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_PAUSABLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_WHEN_PAUSED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_ALWAYS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_DISABLED", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "ProcessMode", ProcessMode_obj);
	JSValue ProcessThreadGroup_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ProcessThreadGroup_obj, "PROCESS_THREAD_GROUP_INHERIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ProcessThreadGroup_obj, "PROCESS_THREAD_GROUP_MAIN_THREAD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ProcessThreadGroup_obj, "PROCESS_THREAD_GROUP_SUB_THREAD", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ProcessThreadGroup", ProcessThreadGroup_obj);
	JSValue ProcessThreadMessages_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ProcessThreadMessages_obj, "FLAG_PROCESS_THREAD_MESSAGES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ProcessThreadMessages_obj, "FLAG_PROCESS_THREAD_MESSAGES_PHYSICS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ProcessThreadMessages_obj, "FLAG_PROCESS_THREAD_MESSAGES_ALL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ProcessThreadMessages", ProcessThreadMessages_obj);
	JSValue PhysicsInterpolationMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PhysicsInterpolationMode_obj, "PHYSICS_INTERPOLATION_MODE_INHERIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PhysicsInterpolationMode_obj, "PHYSICS_INTERPOLATION_MODE_ON", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PhysicsInterpolationMode_obj, "PHYSICS_INTERPOLATION_MODE_OFF", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PhysicsInterpolationMode", PhysicsInterpolationMode_obj);
	JSValue DuplicateFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DuplicateFlags_obj, "DUPLICATE_SIGNALS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DuplicateFlags_obj, "DUPLICATE_GROUPS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DuplicateFlags_obj, "DUPLICATE_SCRIPTS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DuplicateFlags_obj, "DUPLICATE_USE_INSTANTIATION", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "DuplicateFlags", DuplicateFlags_obj);
	JSValue InternalMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, InternalMode_obj, "INTERNAL_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InternalMode_obj, "INTERNAL_MODE_FRONT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InternalMode_obj, "INTERNAL_MODE_BACK", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "InternalMode", InternalMode_obj);
	JSValue AutoTranslateMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AutoTranslateMode_obj, "AUTO_TRANSLATE_MODE_INHERIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AutoTranslateMode_obj, "AUTO_TRANSLATE_MODE_ALWAYS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AutoTranslateMode_obj, "AUTO_TRANSLATE_MODE_DISABLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AutoTranslateMode", AutoTranslateMode_obj);
}

static int js_node_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Node"] = class_id;
	classes_by_id[class_id] = "Node";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &node_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_node_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, node_class_proto_funcs, _countof(node_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, node_class_constructor, "Node", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, node_class_static_funcs, _countof(node_class_static_funcs));
	define_node_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Node", ctor);
	ctor_list["Node"] = ctor;

	return 0;
}

JSModuleDef *_js_init_node_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_node_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Node");
	return m;
}

JSModuleDef *js_init_node_module(JSContext *ctx) {
	return _js_init_node_module(ctx, "@godot/classes/node");
}

void __register_node() {
	js_init_node_module(js_context());
}

void register_node() {
	__register_node();
}