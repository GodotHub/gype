#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/gltf_accessor.hpp>
#include <godot_cpp/classes/gltf_animation.hpp>
#include <godot_cpp/classes/gltf_buffer_view.hpp>
#include <godot_cpp/classes/gltf_camera.hpp>
#include <godot_cpp/classes/gltf_light.hpp>
#include <godot_cpp/classes/gltf_mesh.hpp>
#include <godot_cpp/classes/gltf_node.hpp>
#include <godot_cpp/classes/gltf_skeleton.hpp>
#include <godot_cpp/classes/gltf_skin.hpp>
#include <godot_cpp/classes/gltf_texture.hpp>
#include <godot_cpp/classes/gltf_texture_sampler.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gltf_state.hpp>
using namespace godot;

static void gltf_state_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GLTFState"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef gltf_state_class_def = {
    "GLTFState",
    gltf_state_class_finalizer
};

static JSValue gltf_state_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GLTFState"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GLTFState *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GLTFState *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GLTFState);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gltf_state_class_add_used_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::add_used_extension, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_append_data_to_buffers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::append_data_to_buffers, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_append_gltf_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::append_gltf_node, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_json(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		GLTFState *obj = static_cast<GLTFState *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_json();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		GLTFState *js_proxy = static_cast<GLTFState *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_json(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_state_class_set_json(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_json, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_major_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_major_version, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_major_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_major_version, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_minor_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_minor_version, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_minor_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_minor_version, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_copyright(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFState::get_copyright, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_copyright(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_copyright, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_glb_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedByteArray> *proxy = memnew(ObjectProxy<PackedByteArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedByteArray {
		GLTFState *obj = static_cast<GLTFState *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_glb_data();
	};
	proxy->setter = [this_val](const PackedByteArray &value) -> void {
		GLTFState *js_proxy = static_cast<GLTFState *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_glb_data(PackedByteArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedByteArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedByteArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_state_class_set_glb_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_glb_data, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_use_named_skin_binds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_use_named_skin_binds, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_use_named_skin_binds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_use_named_skin_binds, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_nodes, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_nodes, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_buffers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_buffers, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_buffers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_buffers, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_buffer_views(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_buffer_views, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_buffer_views(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_buffer_views, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_accessors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_accessors, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_accessors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_accessors, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_meshes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_meshes, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_meshes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_meshes, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_animation_players_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_animation_players_count, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_animation_player(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_animation_player, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_materials(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_materials, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_materials(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_materials, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_scene_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_scene_name, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_scene_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_scene_name, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_base_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_base_path, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_base_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_base_path, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFState::get_filename, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_filename, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_root_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedInt32Array> *proxy = memnew(ObjectProxy<PackedInt32Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedInt32Array {
		GLTFState *obj = static_cast<GLTFState *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_root_nodes();
	};
	proxy->setter = [this_val](const PackedInt32Array &value) -> void {
		GLTFState *js_proxy = static_cast<GLTFState *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_root_nodes(PackedInt32Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedInt32ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedInt32ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue gltf_state_class_set_root_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_root_nodes, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_textures, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_textures, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_texture_samplers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_texture_samplers, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_texture_samplers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_texture_samplers, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_images(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_images, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_images(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_images, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_skins(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_skins, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_skins(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_skins, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_cameras(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_cameras, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_cameras(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_cameras, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_lights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_lights, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_lights(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_lights, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_unique_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_unique_names, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_unique_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_unique_names, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_unique_animation_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_unique_animation_names, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_unique_animation_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_unique_animation_names, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_skeletons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_skeletons, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_skeletons(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_skeletons, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_create_animations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_create_animations, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_create_animations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_create_animations, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_import_as_skeleton_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_import_as_skeleton_bones, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_import_as_skeleton_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_import_as_skeleton_bones, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_animations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_animations, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_animations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_animations, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_scene_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_scene_node, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_node_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_node_index, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_set_additional_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_additional_data, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_handle_binary_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GLTFState::get_handle_binary_image, ctx, this_val, argc, argv);
}
static JSValue gltf_state_class_set_handle_binary_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_handle_binary_image, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_set_bake_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GLTFState::set_bake_fps, ctx, this_val, argc, argv);
};
static JSValue gltf_state_class_get_bake_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GLTFState::get_bake_fps, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry gltf_state_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_used_extension", 2, &gltf_state_class_add_used_extension),
	JS_CFUNC_DEF("append_data_to_buffers", 2, &gltf_state_class_append_data_to_buffers),
	JS_CFUNC_DEF("append_gltf_node", 3, &gltf_state_class_append_gltf_node),
	JS_CFUNC_DEF("get_json", 0, &gltf_state_class_get_json),
	JS_CFUNC_DEF("set_json", 1, &gltf_state_class_set_json),
	JS_CFUNC_DEF("get_major_version", 0, &gltf_state_class_get_major_version),
	JS_CFUNC_DEF("set_major_version", 1, &gltf_state_class_set_major_version),
	JS_CFUNC_DEF("get_minor_version", 0, &gltf_state_class_get_minor_version),
	JS_CFUNC_DEF("set_minor_version", 1, &gltf_state_class_set_minor_version),
	JS_CFUNC_DEF("get_copyright", 0, &gltf_state_class_get_copyright),
	JS_CFUNC_DEF("set_copyright", 1, &gltf_state_class_set_copyright),
	JS_CFUNC_DEF("get_glb_data", 0, &gltf_state_class_get_glb_data),
	JS_CFUNC_DEF("set_glb_data", 1, &gltf_state_class_set_glb_data),
	JS_CFUNC_DEF("get_use_named_skin_binds", 0, &gltf_state_class_get_use_named_skin_binds),
	JS_CFUNC_DEF("set_use_named_skin_binds", 1, &gltf_state_class_set_use_named_skin_binds),
	JS_CFUNC_DEF("get_nodes", 0, &gltf_state_class_get_nodes),
	JS_CFUNC_DEF("set_nodes", 1, &gltf_state_class_set_nodes),
	JS_CFUNC_DEF("get_buffers", 0, &gltf_state_class_get_buffers),
	JS_CFUNC_DEF("set_buffers", 1, &gltf_state_class_set_buffers),
	JS_CFUNC_DEF("get_buffer_views", 0, &gltf_state_class_get_buffer_views),
	JS_CFUNC_DEF("set_buffer_views", 1, &gltf_state_class_set_buffer_views),
	JS_CFUNC_DEF("get_accessors", 0, &gltf_state_class_get_accessors),
	JS_CFUNC_DEF("set_accessors", 1, &gltf_state_class_set_accessors),
	JS_CFUNC_DEF("get_meshes", 0, &gltf_state_class_get_meshes),
	JS_CFUNC_DEF("set_meshes", 1, &gltf_state_class_set_meshes),
	JS_CFUNC_DEF("get_animation_players_count", 1, &gltf_state_class_get_animation_players_count),
	JS_CFUNC_DEF("get_animation_player", 1, &gltf_state_class_get_animation_player),
	JS_CFUNC_DEF("get_materials", 0, &gltf_state_class_get_materials),
	JS_CFUNC_DEF("set_materials", 1, &gltf_state_class_set_materials),
	JS_CFUNC_DEF("get_scene_name", 0, &gltf_state_class_get_scene_name),
	JS_CFUNC_DEF("set_scene_name", 1, &gltf_state_class_set_scene_name),
	JS_CFUNC_DEF("get_base_path", 0, &gltf_state_class_get_base_path),
	JS_CFUNC_DEF("set_base_path", 1, &gltf_state_class_set_base_path),
	JS_CFUNC_DEF("get_filename", 0, &gltf_state_class_get_filename),
	JS_CFUNC_DEF("set_filename", 1, &gltf_state_class_set_filename),
	JS_CFUNC_DEF("get_root_nodes", 0, &gltf_state_class_get_root_nodes),
	JS_CFUNC_DEF("set_root_nodes", 1, &gltf_state_class_set_root_nodes),
	JS_CFUNC_DEF("get_textures", 0, &gltf_state_class_get_textures),
	JS_CFUNC_DEF("set_textures", 1, &gltf_state_class_set_textures),
	JS_CFUNC_DEF("get_texture_samplers", 0, &gltf_state_class_get_texture_samplers),
	JS_CFUNC_DEF("set_texture_samplers", 1, &gltf_state_class_set_texture_samplers),
	JS_CFUNC_DEF("get_images", 0, &gltf_state_class_get_images),
	JS_CFUNC_DEF("set_images", 1, &gltf_state_class_set_images),
	JS_CFUNC_DEF("get_skins", 0, &gltf_state_class_get_skins),
	JS_CFUNC_DEF("set_skins", 1, &gltf_state_class_set_skins),
	JS_CFUNC_DEF("get_cameras", 0, &gltf_state_class_get_cameras),
	JS_CFUNC_DEF("set_cameras", 1, &gltf_state_class_set_cameras),
	JS_CFUNC_DEF("get_lights", 0, &gltf_state_class_get_lights),
	JS_CFUNC_DEF("set_lights", 1, &gltf_state_class_set_lights),
	JS_CFUNC_DEF("get_unique_names", 0, &gltf_state_class_get_unique_names),
	JS_CFUNC_DEF("set_unique_names", 1, &gltf_state_class_set_unique_names),
	JS_CFUNC_DEF("get_unique_animation_names", 0, &gltf_state_class_get_unique_animation_names),
	JS_CFUNC_DEF("set_unique_animation_names", 1, &gltf_state_class_set_unique_animation_names),
	JS_CFUNC_DEF("get_skeletons", 0, &gltf_state_class_get_skeletons),
	JS_CFUNC_DEF("set_skeletons", 1, &gltf_state_class_set_skeletons),
	JS_CFUNC_DEF("get_create_animations", 0, &gltf_state_class_get_create_animations),
	JS_CFUNC_DEF("set_create_animations", 1, &gltf_state_class_set_create_animations),
	JS_CFUNC_DEF("get_import_as_skeleton_bones", 0, &gltf_state_class_get_import_as_skeleton_bones),
	JS_CFUNC_DEF("set_import_as_skeleton_bones", 1, &gltf_state_class_set_import_as_skeleton_bones),
	JS_CFUNC_DEF("get_animations", 0, &gltf_state_class_get_animations),
	JS_CFUNC_DEF("set_animations", 1, &gltf_state_class_set_animations),
	JS_CFUNC_DEF("get_scene_node", 1, &gltf_state_class_get_scene_node),
	JS_CFUNC_DEF("get_node_index", 1, &gltf_state_class_get_node_index),
	JS_CFUNC_DEF("get_additional_data", 1, &gltf_state_class_get_additional_data),
	JS_CFUNC_DEF("set_additional_data", 2, &gltf_state_class_set_additional_data),
	JS_CFUNC_DEF("get_handle_binary_image", 0, &gltf_state_class_get_handle_binary_image),
	JS_CFUNC_DEF("set_handle_binary_image", 1, &gltf_state_class_set_handle_binary_image),
	JS_CFUNC_DEF("set_bake_fps", 1, &gltf_state_class_set_bake_fps),
	JS_CFUNC_DEF("get_bake_fps", 0, &gltf_state_class_get_bake_fps),
};




static void define_gltf_state_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "json"),
        JS_NewCFunction(ctx, gltf_state_class_get_json, "get_json", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_json, "set_json", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "major_version"),
        JS_NewCFunction(ctx, gltf_state_class_get_major_version, "get_major_version", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_major_version, "set_major_version", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "minor_version"),
        JS_NewCFunction(ctx, gltf_state_class_get_minor_version, "get_minor_version", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_minor_version, "set_minor_version", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "copyright"),
        JS_NewCFunction(ctx, gltf_state_class_get_copyright, "get_copyright", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_copyright, "set_copyright", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glb_data"),
        JS_NewCFunction(ctx, gltf_state_class_get_glb_data, "get_glb_data", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_glb_data, "set_glb_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_named_skin_binds"),
        JS_NewCFunction(ctx, gltf_state_class_get_use_named_skin_binds, "get_use_named_skin_binds", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_use_named_skin_binds, "set_use_named_skin_binds", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "nodes"),
        JS_NewCFunction(ctx, gltf_state_class_get_nodes, "get_nodes", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_nodes, "set_nodes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffers"),
        JS_NewCFunction(ctx, gltf_state_class_get_buffers, "get_buffers", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_buffers, "set_buffers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer_views"),
        JS_NewCFunction(ctx, gltf_state_class_get_buffer_views, "get_buffer_views", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_buffer_views, "set_buffer_views", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "accessors"),
        JS_NewCFunction(ctx, gltf_state_class_get_accessors, "get_accessors", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_accessors, "set_accessors", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "meshes"),
        JS_NewCFunction(ctx, gltf_state_class_get_meshes, "get_meshes", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_meshes, "set_meshes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "materials"),
        JS_NewCFunction(ctx, gltf_state_class_get_materials, "get_materials", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_materials, "set_materials", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scene_name"),
        JS_NewCFunction(ctx, gltf_state_class_get_scene_name, "get_scene_name", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_scene_name, "set_scene_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "base_path"),
        JS_NewCFunction(ctx, gltf_state_class_get_base_path, "get_base_path", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_base_path, "set_base_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filename"),
        JS_NewCFunction(ctx, gltf_state_class_get_filename, "get_filename", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_filename, "set_filename", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root_nodes"),
        JS_NewCFunction(ctx, gltf_state_class_get_root_nodes, "get_root_nodes", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_root_nodes, "set_root_nodes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "textures"),
        JS_NewCFunction(ctx, gltf_state_class_get_textures, "get_textures", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_textures, "set_textures", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_samplers"),
        JS_NewCFunction(ctx, gltf_state_class_get_texture_samplers, "get_texture_samplers", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_texture_samplers, "set_texture_samplers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "images"),
        JS_NewCFunction(ctx, gltf_state_class_get_images, "get_images", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_images, "set_images", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skins"),
        JS_NewCFunction(ctx, gltf_state_class_get_skins, "get_skins", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_skins, "set_skins", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cameras"),
        JS_NewCFunction(ctx, gltf_state_class_get_cameras, "get_cameras", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_cameras, "set_cameras", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lights"),
        JS_NewCFunction(ctx, gltf_state_class_get_lights, "get_lights", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_lights, "set_lights", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unique_names"),
        JS_NewCFunction(ctx, gltf_state_class_get_unique_names, "get_unique_names", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_unique_names, "set_unique_names", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unique_animation_names"),
        JS_NewCFunction(ctx, gltf_state_class_get_unique_animation_names, "get_unique_animation_names", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_unique_animation_names, "set_unique_animation_names", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skeletons"),
        JS_NewCFunction(ctx, gltf_state_class_get_skeletons, "get_skeletons", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_skeletons, "set_skeletons", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "create_animations"),
        JS_NewCFunction(ctx, gltf_state_class_get_create_animations, "get_create_animations", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_create_animations, "set_create_animations", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "import_as_skeleton_bones"),
        JS_NewCFunction(ctx, gltf_state_class_get_import_as_skeleton_bones, "get_import_as_skeleton_bones", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_import_as_skeleton_bones, "set_import_as_skeleton_bones", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "animations"),
        JS_NewCFunction(ctx, gltf_state_class_get_animations, "get_animations", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_animations, "set_animations", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "handle_binary_image"),
        JS_NewCFunction(ctx, gltf_state_class_get_handle_binary_image, "get_handle_binary_image", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_handle_binary_image, "set_handle_binary_image", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bake_fps"),
        JS_NewCFunction(ctx, gltf_state_class_get_bake_fps, "get_bake_fps", 0),
        JS_NewCFunction(ctx, gltf_state_class_set_bake_fps, "set_bake_fps", 1),
        JS_PROP_GETSET
    );
}

static void define_gltf_state_enum(JSContext *ctx, JSValue ctor) {
}

static int js_gltf_state_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GLTFState"] = class_id;
	classes_by_id[class_id] = "GLTFState";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gltf_state_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gltf_state_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gltf_state_class_proto_funcs, _countof(gltf_state_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gltf_state_class_constructor, "GLTFState", 0, JS_CFUNC_constructor, 0);
	define_gltf_state_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GLTFState", ctor);

	return 0;
}

JSModuleDef *_js_init_gltf_state_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gltf_state_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GLTFState");
	return m;
}

JSModuleDef *js_init_gltf_state_module(JSContext *ctx) {
	return _js_init_gltf_state_module(ctx, "@godot/classes/gltf_state");
}

void __register_gltf_state() {
	js_init_gltf_state_module(js_context());
}

void register_gltf_state() {
	__register_gltf_state();
}