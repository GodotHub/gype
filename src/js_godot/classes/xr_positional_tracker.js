import * as internal from '__internal__';
import { GDString } from 'src/js_godot/variant/gd_string'
import { Variant } from 'src/js_godot/variant/variant'
import { Vector3 } from 'src/js_godot/variant/vector3'
import { StringName } from 'src/js_godot/variant/string_name'
import { Transform3D } from 'src/js_godot/variant/transform3d'
import { XRTracker } from 'src/js_godot/classesxr_tracker'
class _MethodBindings {
    method_get_tracker_profile;
    method_set_tracker_profile;
    method_get_tracker_hand;
    method_set_tracker_hand;
    method_has_pose;
    method_get_pose;
    method_invalidate_pose;
    method_set_pose;
    method_get_input;
    method_set_input;
}


export class XRPositionalTracker extends XRTracker{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("XRPositionalTracker");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("get_tracker_profile");
      this._bindings.method_get_tracker_profile = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        201670096
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("set_tracker_profile");
      this._bindings.method_set_tracker_profile = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        83702148
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("get_tracker_hand");
      this._bindings.method_get_tracker_hand = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4181770860
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("set_tracker_hand");
      this._bindings.method_set_tracker_hand = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3904108980
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("has_pose");
      this._bindings.method_has_pose = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2619796661
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("get_pose");
      this._bindings.method_get_pose = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4099720006
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("invalidate_pose");
      this._bindings.method_invalidate_pose = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3304788590
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("set_pose");
      this._bindings.method_set_pose = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3451230163
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("get_input");
      this._bindings.method_get_input = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2760726917
      );
    }
    {
      let classname = new StringName("XRPositionalTracker");
      let methodname = new StringName("set_input");
      this._bindings.method_set_input = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3776071444
      );
    }
  }
  get_tracker_profile() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_tracker_profile,
      this._owner,
			Variant.Type.STRING
    ,
      
    );
  }
  set_tracker_profile(_profile) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_tracker_profile,
      this._owner,
      _profile
    );
  }
  get_tracker_hand() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_tracker_hand,
      this._owner,
			Variant.INT,
      
    );
  }
  set_tracker_hand(_hand) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_tracker_hand,
      this._owner,
      _hand
    );
  }
  has_pose(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_has_pose,
      this._owner,
			Variant.Type.BOOL,
      _name
    );
  }
  get_pose(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_pose,
      this._owner,
			Variant.INT,
      _name
    );
  }
  invalidate_pose(_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_invalidate_pose,
      this._owner,
      _name
    );
  }
  set_pose(_name, _transform, _linear_velocity, _angular_velocity, _tracking_confidence) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_pose,
      this._owner,
      _name, _transform, _linear_velocity, _angular_velocity, _tracking_confidence
    );
  }
  get_input(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_input,
      this._owner,
			Variant.Type.VARIANT
    ,
      _name
    );
  }
  set_input(_name, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_input,
      this._owner,
      _name, _value
    );
  }
  static TrackerHand = {
    TRACKER_HAND_UNKNOWN: 0,
    TRACKER_HAND_LEFT: 1,
    TRACKER_HAND_RIGHT: 2,
    TRACKER_HAND_MAX: 3,
  }
}