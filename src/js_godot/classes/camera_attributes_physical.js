import * as internal from '__internal__';
import { CameraAttributes } from 'src/js_godot/classescamera_attributes'
class _MethodBindings {
    method_set_aperture;
    method_get_aperture;
    method_set_shutter_speed;
    method_get_shutter_speed;
    method_set_focal_length;
    method_get_focal_length;
    method_set_focus_distance;
    method_get_focus_distance;
    method_set_near;
    method_get_near;
    method_set_far;
    method_get_far;
    method_get_fov;
    method_set_auto_exposure_max_exposure_value;
    method_get_auto_exposure_max_exposure_value;
    method_set_auto_exposure_min_exposure_value;
    method_get_auto_exposure_min_exposure_value;
}


export class CameraAttributesPhysical extends CameraAttributes{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("CameraAttributesPhysical");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_aperture");
      this._bindings.method_set_aperture = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_aperture");
      this._bindings.method_get_aperture = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_shutter_speed");
      this._bindings.method_set_shutter_speed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_shutter_speed");
      this._bindings.method_get_shutter_speed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_focal_length");
      this._bindings.method_set_focal_length = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_focal_length");
      this._bindings.method_get_focal_length = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_focus_distance");
      this._bindings.method_set_focus_distance = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_focus_distance");
      this._bindings.method_get_focus_distance = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_near");
      this._bindings.method_set_near = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_near");
      this._bindings.method_get_near = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_far");
      this._bindings.method_set_far = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_far");
      this._bindings.method_get_far = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_fov");
      this._bindings.method_get_fov = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_auto_exposure_max_exposure_value");
      this._bindings.method_set_auto_exposure_max_exposure_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_auto_exposure_max_exposure_value");
      this._bindings.method_get_auto_exposure_max_exposure_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("set_auto_exposure_min_exposure_value");
      this._bindings.method_set_auto_exposure_min_exposure_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CameraAttributesPhysical");
      let methodname = new StringName("get_auto_exposure_min_exposure_value");
      this._bindings.method_get_auto_exposure_min_exposure_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
  }
  set_aperture(_aperture) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_aperture,
      this._owner,
      _aperture
    );
  }
  get_aperture() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_aperture,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_shutter_speed(_shutter_speed) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_shutter_speed,
      this._owner,
      _shutter_speed
    );
  }
  get_shutter_speed() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_shutter_speed,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_focal_length(_focal_length) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_focal_length,
      this._owner,
      _focal_length
    );
  }
  get_focal_length() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_focal_length,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_focus_distance(_focus_distance) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_focus_distance,
      this._owner,
      _focus_distance
    );
  }
  get_focus_distance() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_focus_distance,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_near(_near) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_near,
      this._owner,
      _near
    );
  }
  get_near() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_near,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_far(_far) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_far,
      this._owner,
      _far
    );
  }
  get_far() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_far,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_fov() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_fov,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_auto_exposure_max_exposure_value(_exposure_value_max) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_auto_exposure_max_exposure_value,
      this._owner,
      _exposure_value_max
    );
  }
  get_auto_exposure_max_exposure_value() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_auto_exposure_max_exposure_value,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_auto_exposure_min_exposure_value(_exposure_value_min) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_auto_exposure_min_exposure_value,
      this._owner,
      _exposure_value_min
    );
  }
  get_auto_exposure_min_exposure_value() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_auto_exposure_min_exposure_value,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
}