import * as internal from '__internal__';
import { NodePath } from 'src/js_godot/variant/node_path'
import { Variant } from 'src/js_godot/variant/variant'
import { StringName } from 'src/js_godot/variant/string_name'
import { Vector3 } from 'src/js_godot/variant/vector3'
import { Node } from 'src/js_godot/classesnode'
import { PackedStringArray } from 'src/js_godot/variant/packed_string_array'
import { Quaternion } from 'src/js_godot/variant/quaternion'
class _MethodBindings {
    method__post_process_key_value;
    method_add_animation_library;
    method_remove_animation_library;
    method_rename_animation_library;
    method_has_animation_library;
    method_get_animation_library;
    method_get_animation_library_list;
    method_has_animation;
    method_get_animation;
    method_get_animation_list;
    method_set_active;
    method_is_active;
    method_set_deterministic;
    method_is_deterministic;
    method_set_root_node;
    method_get_root_node;
    method_set_callback_mode_process;
    method_get_callback_mode_process;
    method_set_callback_mode_method;
    method_get_callback_mode_method;
    method_set_callback_mode_discrete;
    method_get_callback_mode_discrete;
    method_set_audio_max_polyphony;
    method_get_audio_max_polyphony;
    method_set_root_motion_track;
    method_get_root_motion_track;
    method_get_root_motion_position;
    method_get_root_motion_rotation;
    method_get_root_motion_scale;
    method_get_root_motion_position_accumulator;
    method_get_root_motion_rotation_accumulator;
    method_get_root_motion_scale_accumulator;
    method_clear_caches;
    method_advance;
    method_capture;
    method_set_reset_on_save_enabled;
    method_is_reset_on_save_enabled;
    method_find_animation;
    method_find_animation_library;
}


export class AnimationMixer extends Node{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("AnimationMixer");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("_post_process_key_value");
      this._bindings.method__post_process_key_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("add_animation_library");
      this._bindings.method_add_animation_library = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        618909818
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("remove_animation_library");
      this._bindings.method_remove_animation_library = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3304788590
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("rename_animation_library");
      this._bindings.method_rename_animation_library = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3740211285
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("has_animation_library");
      this._bindings.method_has_animation_library = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2619796661
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_animation_library");
      this._bindings.method_get_animation_library = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        147342321
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_animation_library_list");
      this._bindings.method_get_animation_library_list = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3995934104
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("has_animation");
      this._bindings.method_has_animation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2619796661
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_animation");
      this._bindings.method_get_animation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2933122410
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_animation_list");
      this._bindings.method_get_animation_list = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1139954409
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_active");
      this._bindings.method_set_active = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("is_active");
      this._bindings.method_is_active = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_deterministic");
      this._bindings.method_set_deterministic = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("is_deterministic");
      this._bindings.method_is_deterministic = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_root_node");
      this._bindings.method_set_root_node = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1348162250
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_node");
      this._bindings.method_get_root_node = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4075236667
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_callback_mode_process");
      this._bindings.method_set_callback_mode_process = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2153733086
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_callback_mode_process");
      this._bindings.method_get_callback_mode_process = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1394468472
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_callback_mode_method");
      this._bindings.method_set_callback_mode_method = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        742218271
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_callback_mode_method");
      this._bindings.method_get_callback_mode_method = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        489449656
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_callback_mode_discrete");
      this._bindings.method_set_callback_mode_discrete = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1998944670
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_callback_mode_discrete");
      this._bindings.method_get_callback_mode_discrete = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3493168860
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_audio_max_polyphony");
      this._bindings.method_set_audio_max_polyphony = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_audio_max_polyphony");
      this._bindings.method_get_audio_max_polyphony = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_root_motion_track");
      this._bindings.method_set_root_motion_track = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1348162250
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_track");
      this._bindings.method_get_root_motion_track = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4075236667
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_position");
      this._bindings.method_get_root_motion_position = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_rotation");
      this._bindings.method_get_root_motion_rotation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1222331677
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_scale");
      this._bindings.method_get_root_motion_scale = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_position_accumulator");
      this._bindings.method_get_root_motion_position_accumulator = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_rotation_accumulator");
      this._bindings.method_get_root_motion_rotation_accumulator = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1222331677
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("get_root_motion_scale_accumulator");
      this._bindings.method_get_root_motion_scale_accumulator = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("clear_caches");
      this._bindings.method_clear_caches = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3218959716
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("advance");
      this._bindings.method_advance = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("capture");
      this._bindings.method_capture = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1333632127
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("set_reset_on_save_enabled");
      this._bindings.method_set_reset_on_save_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("is_reset_on_save_enabled");
      this._bindings.method_is_reset_on_save_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("find_animation");
      this._bindings.method_find_animation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1559484580
      );
    }
    {
      let classname = new StringName("AnimationMixer");
      let methodname = new StringName("find_animation_library");
      this._bindings.method_find_animation_library = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1559484580
      );
    }
  }
  _post_process_key_value(_animation, _track, _value, _object_id, _object_sub_idx) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__post_process_key_value,
      this._owner,
			Variant.Type.VARIANT
    ,
      _animation, _track, _value, _object_id, _object_sub_idx
    );
  }
  add_animation_library(_name, _library) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_add_animation_library,
      this._owner,
			Variant.INT,
      _name, _library
    );
  }
  remove_animation_library(_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_remove_animation_library,
      this._owner,
      _name
    );
  }
  rename_animation_library(_name, _newname) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_rename_animation_library,
      this._owner,
      _name, _newname
    );
  }
  has_animation_library(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_has_animation_library,
      this._owner,
			Variant.Type.BOOL,
      _name
    );
  }
  get_animation_library(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_animation_library,
      this._owner,
			Variant.INT,
      _name
    );
  }
  get_animation_library_list() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_animation_library_list,
      this._owner,
			Variant.INT,
      
    );
  }
  has_animation(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_has_animation,
      this._owner,
			Variant.Type.BOOL,
      _name
    );
  }
  get_animation(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_animation,
      this._owner,
			Variant.INT,
      _name
    );
  }
  get_animation_list() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_animation_list,
      this._owner,
			Variant.Type.PACKED_STRING_ARRAY
    ,
      
    );
  }
  set_active(_active) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_active,
      this._owner,
      _active
    );
  }
  is_active() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_active,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_deterministic(_deterministic) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_deterministic,
      this._owner,
      _deterministic
    );
  }
  is_deterministic() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_deterministic,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_root_node(_path) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_root_node,
      this._owner,
      _path
    );
  }
  get_root_node() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_node,
      this._owner,
			Variant.Type.NODE_PATH
    ,
      
    );
  }
  set_callback_mode_process(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_callback_mode_process,
      this._owner,
      _mode
    );
  }
  get_callback_mode_process() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_callback_mode_process,
      this._owner,
			Variant.INT,
      
    );
  }
  set_callback_mode_method(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_callback_mode_method,
      this._owner,
      _mode
    );
  }
  get_callback_mode_method() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_callback_mode_method,
      this._owner,
			Variant.INT,
      
    );
  }
  set_callback_mode_discrete(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_callback_mode_discrete,
      this._owner,
      _mode
    );
  }
  get_callback_mode_discrete() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_callback_mode_discrete,
      this._owner,
			Variant.INT,
      
    );
  }
  set_audio_max_polyphony(_max_polyphony) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_audio_max_polyphony,
      this._owner,
      _max_polyphony
    );
  }
  get_audio_max_polyphony() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_audio_max_polyphony,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_root_motion_track(_path) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_root_motion_track,
      this._owner,
      _path
    );
  }
  get_root_motion_track() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_track,
      this._owner,
			Variant.Type.NODE_PATH
    ,
      
    );
  }
  get_root_motion_position() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_position,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  get_root_motion_rotation() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_rotation,
      this._owner,
			Variant.Type.QUATERNION
    ,
      
    );
  }
  get_root_motion_scale() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_scale,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  get_root_motion_position_accumulator() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_position_accumulator,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  get_root_motion_rotation_accumulator() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_rotation_accumulator,
      this._owner,
			Variant.Type.QUATERNION
    ,
      
    );
  }
  get_root_motion_scale_accumulator() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_root_motion_scale_accumulator,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  clear_caches() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_clear_caches,
      this._owner,
      
    );
  }
  advance(_delta) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_advance,
      this._owner,
      _delta
    );
  }
  capture(_name, _duration, _trans_type, _ease_type) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_capture,
      this._owner,
      _name, _duration, _trans_type, _ease_type
    );
  }
  set_reset_on_save_enabled(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_reset_on_save_enabled,
      this._owner,
      _enabled
    );
  }
  is_reset_on_save_enabled() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_reset_on_save_enabled,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  find_animation(_animation) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_find_animation,
      this._owner,
			Variant.Type.STRING_NAME
    ,
      _animation
    );
  }
  find_animation_library(_animation) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_find_animation_library,
      this._owner,
			Variant.Type.STRING_NAME
    ,
      _animation
    );
  }
  static AnimationCallbackModeProcess = {
    ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS: 0,
    ANIMATION_CALLBACK_MODE_PROCESS_IDLE: 1,
    ANIMATION_CALLBACK_MODE_PROCESS_MANUAL: 2,
  }
  static AnimationCallbackModeMethod = {
    ANIMATION_CALLBACK_MODE_METHOD_DEFERRED: 0,
    ANIMATION_CALLBACK_MODE_METHOD_IMMEDIATE: 1,
  }
  static AnimationCallbackModeDiscrete = {
    ANIMATION_CALLBACK_MODE_DISCRETE_DOMINANT: 0,
    ANIMATION_CALLBACK_MODE_DISCRETE_RECESSIVE: 1,
    ANIMATION_CALLBACK_MODE_DISCRETE_FORCE_CONTINUOUS: 2,
  }
}