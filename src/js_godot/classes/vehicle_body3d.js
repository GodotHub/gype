import * as internal from '__internal__';
import { RigidBody3D } from 'src/js_godot/classesrigid_body3d'
class _MethodBindings {
    method_set_engine_force;
    method_get_engine_force;
    method_set_brake;
    method_get_brake;
    method_set_steering;
    method_get_steering;
}


export class VehicleBody3D extends RigidBody3D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("VehicleBody3D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("VehicleBody3D");
      let methodname = new StringName("set_engine_force");
      this._bindings.method_set_engine_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("VehicleBody3D");
      let methodname = new StringName("get_engine_force");
      this._bindings.method_get_engine_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("VehicleBody3D");
      let methodname = new StringName("set_brake");
      this._bindings.method_set_brake = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("VehicleBody3D");
      let methodname = new StringName("get_brake");
      this._bindings.method_get_brake = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("VehicleBody3D");
      let methodname = new StringName("set_steering");
      this._bindings.method_set_steering = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("VehicleBody3D");
      let methodname = new StringName("get_steering");
      this._bindings.method_get_steering = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
  }
  set_engine_force(_engine_force) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_engine_force,
      this._owner,
      _engine_force
    );
  }
  get_engine_force() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_engine_force,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_brake(_brake) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_brake,
      this._owner,
      _brake
    );
  }
  get_brake() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_brake,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_steering(_steering) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_steering,
      this._owner,
      _steering
    );
  }
  get_steering() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_steering,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
}