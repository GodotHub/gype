import * as internal from '__internal__';
import { Vector3 } from 'src/js_godot/variant/vector3'
import { CollisionObject3D } from 'src/js_godot/classescollision_object3d'
import { Transform3D } from 'src/js_godot/variant/transform3d'
class _MethodBindings {
    method_move_and_collide;
    method_test_move;
    method_get_gravity;
    method_set_axis_lock;
    method_get_axis_lock;
    method_get_collision_exceptions;
    method_add_collision_exception_with;
    method_remove_collision_exception_with;
}


export class PhysicsBody3D extends CollisionObject3D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("PhysicsBody3D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("move_and_collide");
      this._bindings.method_move_and_collide = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3208792678
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("test_move");
      this._bindings.method_test_move = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2481691619
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("get_gravity");
      this._bindings.method_get_gravity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("set_axis_lock");
      this._bindings.method_set_axis_lock = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1787895195
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("get_axis_lock");
      this._bindings.method_get_axis_lock = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2264617709
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("get_collision_exceptions");
      this._bindings.method_get_collision_exceptions = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2915620761
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("add_collision_exception_with");
      this._bindings.method_add_collision_exception_with = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1078189570
      );
    }
    {
      let classname = new StringName("PhysicsBody3D");
      let methodname = new StringName("remove_collision_exception_with");
      this._bindings.method_remove_collision_exception_with = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1078189570
      );
    }
  }
  move_and_collide(_motion, _test_only, _safe_margin, _recovery_as_collision, _max_collisions) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_move_and_collide,
      this._owner,
			Variant.INT,
      _motion, _test_only, _safe_margin, _recovery_as_collision, _max_collisions
    );
  }
  test_move(_from, _motion, _collision, _safe_margin, _recovery_as_collision, _max_collisions) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_test_move,
      this._owner,
			Variant.Type.BOOL,
      _from, _motion, _collision, _safe_margin, _recovery_as_collision, _max_collisions
    );
  }
  get_gravity() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_gravity,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  set_axis_lock(_axis, _lock) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_axis_lock,
      this._owner,
      _axis, _lock
    );
  }
  get_axis_lock(_axis) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_axis_lock,
      this._owner,
			Variant.Type.BOOL,
      _axis
    );
  }
  get_collision_exceptions() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collision_exceptions,
      this._owner,
			Variant.INT,
      
    );
  }
  add_collision_exception_with(_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_add_collision_exception_with,
      this._owner,
      _body
    );
  }
  remove_collision_exception_with(_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_remove_collision_exception_with,
      this._owner,
      _body
    );
  }
}