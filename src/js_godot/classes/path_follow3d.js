import * as internal from '__internal__';
import { Node3D } from 'src/js_godot/classesnode3d'
import { Transform3D } from 'src/js_godot/variant/transform3d'
class _MethodBindings {
    method_set_progress;
    method_get_progress;
    method_set_h_offset;
    method_get_h_offset;
    method_set_v_offset;
    method_get_v_offset;
    method_set_progress_ratio;
    method_get_progress_ratio;
    method_set_rotation_mode;
    method_get_rotation_mode;
    method_set_cubic_interpolation;
    method_get_cubic_interpolation;
    method_set_use_model_front;
    method_is_using_model_front;
    method_set_loop;
    method_has_loop;
    method_set_tilt_enabled;
    method_is_tilt_enabled;
    method_correct_posture;
}


export class PathFollow3D extends Node3D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("PathFollow3D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_progress");
      this._bindings.method_set_progress = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("get_progress");
      this._bindings.method_get_progress = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_h_offset");
      this._bindings.method_set_h_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("get_h_offset");
      this._bindings.method_get_h_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_v_offset");
      this._bindings.method_set_v_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("get_v_offset");
      this._bindings.method_get_v_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_progress_ratio");
      this._bindings.method_set_progress_ratio = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("get_progress_ratio");
      this._bindings.method_get_progress_ratio = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_rotation_mode");
      this._bindings.method_set_rotation_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1640311967
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("get_rotation_mode");
      this._bindings.method_get_rotation_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3814010545
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_cubic_interpolation");
      this._bindings.method_set_cubic_interpolation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("get_cubic_interpolation");
      this._bindings.method_get_cubic_interpolation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_use_model_front");
      this._bindings.method_set_use_model_front = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("is_using_model_front");
      this._bindings.method_is_using_model_front = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_loop");
      this._bindings.method_set_loop = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("has_loop");
      this._bindings.method_has_loop = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("set_tilt_enabled");
      this._bindings.method_set_tilt_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("is_tilt_enabled");
      this._bindings.method_is_tilt_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("PathFollow3D");
      let methodname = new StringName("correct_posture");
      this._bindings.method_correct_posture = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2686588690
      );
    }
  }
  set_progress(_progress) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_progress,
      this._owner,
      _progress
    );
  }
  get_progress() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_progress,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_h_offset(_h_offset) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_h_offset,
      this._owner,
      _h_offset
    );
  }
  get_h_offset() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_h_offset,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_v_offset(_v_offset) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_v_offset,
      this._owner,
      _v_offset
    );
  }
  get_v_offset() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_v_offset,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_progress_ratio(_ratio) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_progress_ratio,
      this._owner,
      _ratio
    );
  }
  get_progress_ratio() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_progress_ratio,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_rotation_mode(_rotation_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_rotation_mode,
      this._owner,
      _rotation_mode
    );
  }
  get_rotation_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_rotation_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  set_cubic_interpolation(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_cubic_interpolation,
      this._owner,
      _enabled
    );
  }
  get_cubic_interpolation() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_cubic_interpolation,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_use_model_front(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_use_model_front,
      this._owner,
      _enabled
    );
  }
  is_using_model_front() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_using_model_front,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_loop(_loop) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_loop,
      this._owner,
      _loop
    );
  }
  has_loop() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_has_loop,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_tilt_enabled(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_tilt_enabled,
      this._owner,
      _enabled
    );
  }
  is_tilt_enabled() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_tilt_enabled,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  correct_posture(_transform, _rotation_mode) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_correct_posture,
      this._owner,
			Variant.Type.TRANSFORM3D
    ,
      _transform, _rotation_mode
    );
  }
  static RotationMode = {
    ROTATION_NONE: 0,
    ROTATION_Y: 1,
    ROTATION_XY: 2,
    ROTATION_XYZ: 3,
    ROTATION_ORIENTED: 4,
  }
}