import * as internal from '__internal__';
import { Vector3 } from 'src/js_godot/variant/vector3'
import { RefCounted } from 'src/js_godot/classesref_counted'
import { RID } from 'src/js_godot/variant/rid'
class _MethodBindings {
    method_get_travel;
    method_get_remainder;
    method_get_depth;
    method_get_collision_count;
    method_get_position;
    method_get_normal;
    method_get_angle;
    method_get_local_shape;
    method_get_collider;
    method_get_collider_id;
    method_get_collider_rid;
    method_get_collider_shape;
    method_get_collider_shape_index;
    method_get_collider_velocity;
}


export class KinematicCollision3D extends RefCounted{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("KinematicCollision3D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_travel");
      this._bindings.method_get_travel = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_remainder");
      this._bindings.method_get_remainder = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3360562783
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_depth");
      this._bindings.method_get_depth = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collision_count");
      this._bindings.method_get_collision_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_position");
      this._bindings.method_get_position = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1914908202
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_normal");
      this._bindings.method_get_normal = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1914908202
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_angle");
      this._bindings.method_get_angle = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1242741860
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_local_shape");
      this._bindings.method_get_local_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2639523548
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collider");
      this._bindings.method_get_collider = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2639523548
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collider_id");
      this._bindings.method_get_collider_id = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1591665591
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collider_rid");
      this._bindings.method_get_collider_rid = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1231817359
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collider_shape");
      this._bindings.method_get_collider_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2639523548
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collider_shape_index");
      this._bindings.method_get_collider_shape_index = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1591665591
      );
    }
    {
      let classname = new StringName("KinematicCollision3D");
      let methodname = new StringName("get_collider_velocity");
      this._bindings.method_get_collider_velocity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1914908202
      );
    }
  }
  get_travel() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_travel,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  get_remainder() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_remainder,
      this._owner,
			Variant.Type.VECTOR3
    ,
      
    );
  }
  get_depth() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_depth,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_collision_count() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collision_count,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  get_position(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_position,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _collision_index
    );
  }
  get_normal(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_normal,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _collision_index
    );
  }
  get_angle(_collision_index, _up_direction) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_angle,
      this._owner,
			Variant.Type.FLOAT,
      _collision_index, _up_direction
    );
  }
  get_local_shape(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_local_shape,
      this._owner,
			Variant.INT,
      _collision_index
    );
  }
  get_collider(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collider,
      this._owner,
			Variant.INT,
      _collision_index
    );
  }
  get_collider_id(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collider_id,
      this._owner,
			Variant.Type.INT,
      _collision_index
    );
  }
  get_collider_rid(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collider_rid,
      this._owner,
			Variant.Type.RID
    ,
      _collision_index
    );
  }
  get_collider_shape(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collider_shape,
      this._owner,
			Variant.INT,
      _collision_index
    );
  }
  get_collider_shape_index(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collider_shape_index,
      this._owner,
			Variant.Type.INT,
      _collision_index
    );
  }
  get_collider_velocity(_collision_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_collider_velocity,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _collision_index
    );
  }
}