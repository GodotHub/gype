import * as internal from '__internal__';
import { Joint3D } from 'src/js_godot/classesjoint3d'
class _MethodBindings {
    method_set_param;
    method_get_param;
}


export class SliderJoint3D extends Joint3D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("SliderJoint3D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("SliderJoint3D");
      let methodname = new StringName("set_param");
      this._bindings.method_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        918243683
      );
    }
    {
      let classname = new StringName("SliderJoint3D");
      let methodname = new StringName("get_param");
      this._bindings.method_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        959925627
      );
    }
  }
  set_param(_param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_param,
      this._owner,
      _param, _value
    );
  }
  get_param(_param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _param
    );
  }
  static Param = {
    PARAM_LINEAR_LIMIT_UPPER: 0,
    PARAM_LINEAR_LIMIT_LOWER: 1,
    PARAM_LINEAR_LIMIT_SOFTNESS: 2,
    PARAM_LINEAR_LIMIT_RESTITUTION: 3,
    PARAM_LINEAR_LIMIT_DAMPING: 4,
    PARAM_LINEAR_MOTION_SOFTNESS: 5,
    PARAM_LINEAR_MOTION_RESTITUTION: 6,
    PARAM_LINEAR_MOTION_DAMPING: 7,
    PARAM_LINEAR_ORTHOGONAL_SOFTNESS: 8,
    PARAM_LINEAR_ORTHOGONAL_RESTITUTION: 9,
    PARAM_LINEAR_ORTHOGONAL_DAMPING: 10,
    PARAM_ANGULAR_LIMIT_UPPER: 11,
    PARAM_ANGULAR_LIMIT_LOWER: 12,
    PARAM_ANGULAR_LIMIT_SOFTNESS: 13,
    PARAM_ANGULAR_LIMIT_RESTITUTION: 14,
    PARAM_ANGULAR_LIMIT_DAMPING: 15,
    PARAM_ANGULAR_MOTION_SOFTNESS: 16,
    PARAM_ANGULAR_MOTION_RESTITUTION: 17,
    PARAM_ANGULAR_MOTION_DAMPING: 18,
    PARAM_ANGULAR_ORTHOGONAL_SOFTNESS: 19,
    PARAM_ANGULAR_ORTHOGONAL_RESTITUTION: 20,
    PARAM_ANGULAR_ORTHOGONAL_DAMPING: 21,
    PARAM_MAX: 22,
  }
}