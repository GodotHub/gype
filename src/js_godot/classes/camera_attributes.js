import * as internal from '__internal__';
import { Resource } from 'src/js_godot/classesresource'
class _MethodBindings {
    method_set_exposure_multiplier;
    method_get_exposure_multiplier;
    method_set_exposure_sensitivity;
    method_get_exposure_sensitivity;
    method_set_auto_exposure_enabled;
    method_is_auto_exposure_enabled;
    method_set_auto_exposure_speed;
    method_get_auto_exposure_speed;
    method_set_auto_exposure_scale;
    method_get_auto_exposure_scale;
}


export class CameraAttributes extends Resource{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("CameraAttributes");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("set_exposure_multiplier");
      this._bindings.method_set_exposure_multiplier = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("get_exposure_multiplier");
      this._bindings.method_get_exposure_multiplier = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("set_exposure_sensitivity");
      this._bindings.method_set_exposure_sensitivity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("get_exposure_sensitivity");
      this._bindings.method_get_exposure_sensitivity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("set_auto_exposure_enabled");
      this._bindings.method_set_auto_exposure_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("is_auto_exposure_enabled");
      this._bindings.method_is_auto_exposure_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("set_auto_exposure_speed");
      this._bindings.method_set_auto_exposure_speed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("get_auto_exposure_speed");
      this._bindings.method_get_auto_exposure_speed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("set_auto_exposure_scale");
      this._bindings.method_set_auto_exposure_scale = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributes");
      let methodname = new StringName("get_auto_exposure_scale");
      this._bindings.method_get_auto_exposure_scale = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
  }
  set_exposure_multiplier(_multiplier) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_exposure_multiplier,
      this._owner,
      _multiplier
    );
  }
  get_exposure_multiplier() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_exposure_multiplier,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_exposure_sensitivity(_sensitivity) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_exposure_sensitivity,
      this._owner,
      _sensitivity
    );
  }
  get_exposure_sensitivity() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_exposure_sensitivity,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_auto_exposure_enabled(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_auto_exposure_enabled,
      this._owner,
      _enabled
    );
  }
  is_auto_exposure_enabled() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_auto_exposure_enabled,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_auto_exposure_speed(_exposure_speed) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_auto_exposure_speed,
      this._owner,
      _exposure_speed
    );
  }
  get_auto_exposure_speed() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_auto_exposure_speed,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_auto_exposure_scale(_exposure_grey) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_auto_exposure_scale,
      this._owner,
      _exposure_grey
    );
  }
  get_auto_exposure_scale() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_auto_exposure_scale,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
}