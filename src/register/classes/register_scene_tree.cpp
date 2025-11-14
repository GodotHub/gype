#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include "register/classes/class_scene_tree_vararg.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/main_loop.hpp>
#include <godot_cpp/classes/multiplayer_api.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/scene_tree_timer.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
using namespace godot;

static void scene_tree_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SceneTree"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef scene_tree_class_def = {
    "SceneTree",
    scene_tree_class_finalizer
};

static JSValue scene_tree_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SceneTree"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SceneTree *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SceneTree *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SceneTree);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue scene_tree_class_get_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_root, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_has_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::has_group, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_accessibility_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_accessibility_enabled, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_accessibility_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_accessibility_supported, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_auto_accept_quit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_auto_accept_quit, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_set_auto_accept_quit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_auto_accept_quit, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_quit_on_go_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_quit_on_go_back, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_set_quit_on_go_back(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_quit_on_go_back, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_debug_collisions_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_debug_collisions_hint, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_debugging_collisions_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_debugging_collisions_hint, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_set_debug_paths_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_debug_paths_hint, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_debugging_paths_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_debugging_paths_hint, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_set_debug_navigation_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_debug_navigation_hint, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_debugging_navigation_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_debugging_navigation_hint, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_set_edited_scene_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_edited_scene_root, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_edited_scene_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_edited_scene_root, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_set_pause(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_pause, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_paused, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_create_timer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::create_timer, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_create_tween(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::create_tween, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_processed_tweens(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::get_processed_tweens, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_node_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_node_count, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_frame, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_quit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::quit, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_physics_interpolation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_physics_interpolation_enabled, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_physics_interpolation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_physics_interpolation_enabled, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_queue_delete(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::queue_delete, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_notify_group_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::notify_group_flags, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_group_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_group_flags, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_notify_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::notify_group, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_group, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_nodes_in_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::get_nodes_in_group, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_first_node_in_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::get_first_node_in_group, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_node_count_in_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_node_count_in_group, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_current_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_current_scene, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_current_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_current_scene, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_change_scene_to_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::change_scene_to_file, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_change_scene_to_packed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::change_scene_to_packed, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_reload_current_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneTree::reload_current_scene, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_unload_current_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::unload_current_scene, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_multiplayer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_multiplayer, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_get_multiplayer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::get_multiplayer, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_set_multiplayer_poll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneTree::set_multiplayer_poll_enabled, ctx, this_val, argc, argv);
};
static JSValue scene_tree_class_is_multiplayer_poll_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneTree::is_multiplayer_poll_enabled, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_call_group_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_free_owner_vararg_method_no_ret(&js_call_group_flags, ctx, this_val, argc, argv);
}
static JSValue scene_tree_class_call_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_free_owner_vararg_method_no_ret(&js_call_group, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry scene_tree_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_root", 0, &scene_tree_class_get_root),
	JS_CFUNC_DEF("has_group", 1, &scene_tree_class_has_group),
	JS_CFUNC_DEF("is_accessibility_enabled", 0, &scene_tree_class_is_accessibility_enabled),
	JS_CFUNC_DEF("is_accessibility_supported", 0, &scene_tree_class_is_accessibility_supported),
	JS_CFUNC_DEF("is_auto_accept_quit", 0, &scene_tree_class_is_auto_accept_quit),
	JS_CFUNC_DEF("set_auto_accept_quit", 1, &scene_tree_class_set_auto_accept_quit),
	JS_CFUNC_DEF("is_quit_on_go_back", 0, &scene_tree_class_is_quit_on_go_back),
	JS_CFUNC_DEF("set_quit_on_go_back", 1, &scene_tree_class_set_quit_on_go_back),
	JS_CFUNC_DEF("set_debug_collisions_hint", 1, &scene_tree_class_set_debug_collisions_hint),
	JS_CFUNC_DEF("is_debugging_collisions_hint", 0, &scene_tree_class_is_debugging_collisions_hint),
	JS_CFUNC_DEF("set_debug_paths_hint", 1, &scene_tree_class_set_debug_paths_hint),
	JS_CFUNC_DEF("is_debugging_paths_hint", 0, &scene_tree_class_is_debugging_paths_hint),
	JS_CFUNC_DEF("set_debug_navigation_hint", 1, &scene_tree_class_set_debug_navigation_hint),
	JS_CFUNC_DEF("is_debugging_navigation_hint", 0, &scene_tree_class_is_debugging_navigation_hint),
	JS_CFUNC_DEF("set_edited_scene_root", 1, &scene_tree_class_set_edited_scene_root),
	JS_CFUNC_DEF("get_edited_scene_root", 0, &scene_tree_class_get_edited_scene_root),
	JS_CFUNC_DEF("set_pause", 1, &scene_tree_class_set_pause),
	JS_CFUNC_DEF("is_paused", 0, &scene_tree_class_is_paused),
	JS_CFUNC_DEF("create_timer", 4, &scene_tree_class_create_timer),
	JS_CFUNC_DEF("create_tween", 0, &scene_tree_class_create_tween),
	JS_CFUNC_DEF("get_processed_tweens", 0, &scene_tree_class_get_processed_tweens),
	JS_CFUNC_DEF("get_node_count", 0, &scene_tree_class_get_node_count),
	JS_CFUNC_DEF("get_frame", 0, &scene_tree_class_get_frame),
	JS_CFUNC_DEF("quit", 1, &scene_tree_class_quit),
	JS_CFUNC_DEF("set_physics_interpolation_enabled", 1, &scene_tree_class_set_physics_interpolation_enabled),
	JS_CFUNC_DEF("is_physics_interpolation_enabled", 0, &scene_tree_class_is_physics_interpolation_enabled),
	JS_CFUNC_DEF("queue_delete", 1, &scene_tree_class_queue_delete),
	JS_CFUNC_DEF("notify_group_flags", 3, &scene_tree_class_notify_group_flags),
	JS_CFUNC_DEF("set_group_flags", 4, &scene_tree_class_set_group_flags),
	JS_CFUNC_DEF("notify_group", 2, &scene_tree_class_notify_group),
	JS_CFUNC_DEF("set_group", 3, &scene_tree_class_set_group),
	JS_CFUNC_DEF("get_nodes_in_group", 1, &scene_tree_class_get_nodes_in_group),
	JS_CFUNC_DEF("get_first_node_in_group", 1, &scene_tree_class_get_first_node_in_group),
	JS_CFUNC_DEF("get_node_count_in_group", 1, &scene_tree_class_get_node_count_in_group),
	JS_CFUNC_DEF("set_current_scene", 1, &scene_tree_class_set_current_scene),
	JS_CFUNC_DEF("get_current_scene", 0, &scene_tree_class_get_current_scene),
	JS_CFUNC_DEF("change_scene_to_file", 1, &scene_tree_class_change_scene_to_file),
	JS_CFUNC_DEF("change_scene_to_packed", 1, &scene_tree_class_change_scene_to_packed),
	JS_CFUNC_DEF("reload_current_scene", 0, &scene_tree_class_reload_current_scene),
	JS_CFUNC_DEF("unload_current_scene", 0, &scene_tree_class_unload_current_scene),
	JS_CFUNC_DEF("set_multiplayer", 2, &scene_tree_class_set_multiplayer),
	JS_CFUNC_DEF("get_multiplayer", 1, &scene_tree_class_get_multiplayer),
	JS_CFUNC_DEF("set_multiplayer_poll_enabled", 1, &scene_tree_class_set_multiplayer_poll_enabled),
	JS_CFUNC_DEF("is_multiplayer_poll_enabled", 0, &scene_tree_class_is_multiplayer_poll_enabled),
	JS_CFUNC_DEF("call_group_flags", 3, &scene_tree_class_call_group_flags),
	JS_CFUNC_DEF("call_group", 2, &scene_tree_class_call_group),
};


static JSValue scene_tree_class_get_tree_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tree_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tree_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "tree_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_scene_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scene_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scene_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "scene_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_tree_process_mode_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tree_process_mode_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tree_process_mode_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "tree_process_mode_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_node_added_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_added_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_added"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_added_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_node_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_removed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_removed"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_removed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_node_renamed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_renamed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_renamed"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_renamed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_node_configuration_warning_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "node_configuration_warning_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "node_configuration_warning_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "node_configuration_warning_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_process_frame_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "process_frame_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "process_frame"));
		JS_DefinePropertyValueStr(ctx, this_val, "process_frame_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_tree_class_get_physics_frame_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneTree *opaque = static_cast<SceneTree *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "physics_frame_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "physics_frame"));
		JS_DefinePropertyValueStr(ctx, this_val, "physics_frame_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_scene_tree_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auto_accept_quit"),
        JS_NewCFunction(ctx, scene_tree_class_is_auto_accept_quit, "is_auto_accept_quit", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_auto_accept_quit, "set_auto_accept_quit", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "quit_on_go_back"),
        JS_NewCFunction(ctx, scene_tree_class_is_quit_on_go_back, "is_quit_on_go_back", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_quit_on_go_back, "set_quit_on_go_back", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_collisions_hint"),
        JS_NewCFunction(ctx, scene_tree_class_is_debugging_collisions_hint, "is_debugging_collisions_hint", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_debug_collisions_hint, "set_debug_collisions_hint", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_paths_hint"),
        JS_NewCFunction(ctx, scene_tree_class_is_debugging_paths_hint, "is_debugging_paths_hint", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_debug_paths_hint, "set_debug_paths_hint", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "debug_navigation_hint"),
        JS_NewCFunction(ctx, scene_tree_class_is_debugging_navigation_hint, "is_debugging_navigation_hint", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_debug_navigation_hint, "set_debug_navigation_hint", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "paused"),
        JS_NewCFunction(ctx, scene_tree_class_is_paused, "is_paused", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_pause, "set_pause", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edited_scene_root"),
        JS_NewCFunction(ctx, scene_tree_class_get_edited_scene_root, "get_edited_scene_root", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_edited_scene_root, "set_edited_scene_root", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_scene"),
        JS_NewCFunction(ctx, scene_tree_class_get_current_scene, "get_current_scene", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_current_scene, "set_current_scene", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root"),
        JS_NewCFunction(ctx, scene_tree_class_get_root, "get_root", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "multiplayer_poll"),
        JS_NewCFunction(ctx, scene_tree_class_is_multiplayer_poll_enabled, "is_multiplayer_poll_enabled", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_multiplayer_poll_enabled, "set_multiplayer_poll_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "physics_interpolation"),
        JS_NewCFunction(ctx, scene_tree_class_is_physics_interpolation_enabled, "is_physics_interpolation_enabled", 0),
        JS_NewCFunction(ctx, scene_tree_class_set_physics_interpolation_enabled, "set_physics_interpolation_enabled", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tree_changed"),
		JS_NewCFunction(ctx, scene_tree_class_get_tree_changed_signal, "get_tree_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scene_changed"),
		JS_NewCFunction(ctx, scene_tree_class_get_scene_changed_signal, "get_scene_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tree_process_mode_changed"),
		JS_NewCFunction(ctx, scene_tree_class_get_tree_process_mode_changed_signal, "get_tree_process_mode_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_added"),
		JS_NewCFunction(ctx, scene_tree_class_get_node_added_signal, "get_node_added_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_removed"),
		JS_NewCFunction(ctx, scene_tree_class_get_node_removed_signal, "get_node_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_renamed"),
		JS_NewCFunction(ctx, scene_tree_class_get_node_renamed_signal, "get_node_renamed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "node_configuration_warning_changed"),
		JS_NewCFunction(ctx, scene_tree_class_get_node_configuration_warning_changed_signal, "get_node_configuration_warning_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "process_frame"),
		JS_NewCFunction(ctx, scene_tree_class_get_process_frame_signal, "get_process_frame_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "physics_frame"),
		JS_NewCFunction(ctx, scene_tree_class_get_physics_frame_signal, "get_physics_frame_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_scene_tree_enum(JSContext *ctx, JSValue proto) {
	JSValue GroupCallFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GroupCallFlags_obj, "GROUP_CALL_DEFAULT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GroupCallFlags_obj, "GROUP_CALL_REVERSE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GroupCallFlags_obj, "GROUP_CALL_DEFERRED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, GroupCallFlags_obj, "GROUP_CALL_UNIQUE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "GroupCallFlags", GroupCallFlags_obj);
}

static int js_scene_tree_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SceneTree"] = class_id;
	classes_by_id[class_id] = "SceneTree";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &scene_tree_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["MainLoop"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_scene_tree_property(ctx, proto);
	define_scene_tree_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, scene_tree_class_proto_funcs, _countof(scene_tree_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, scene_tree_class_constructor, "SceneTree", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SceneTree", ctor);

	return 0;
}

JSModuleDef *_js_init_scene_tree_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/main_loop';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_scene_tree_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SceneTree");
	return m;
}

JSModuleDef *js_init_scene_tree_module(JSContext *ctx) {
	return _js_init_scene_tree_module(ctx, "@godot/classes/scene_tree");
}

void __register_scene_tree() {
	js_init_scene_tree_module(js_context());
}

void register_scene_tree() {
	__register_scene_tree();
}