import * as internal from '__internal__';
import { Node2D } from 'src/js_godot/classesnode2d'
import { PackedVector2Array } from 'src/js_godot/variant/packed_vector2_array'
class _MethodBindings {
    method_set_polygon;
    method_get_polygon;
    method_set_build_mode;
    method_get_build_mode;
    method_set_disabled;
    method_is_disabled;
    method_set_one_way_collision;
    method_is_one_way_collision_enabled;
    method_set_one_way_collision_margin;
    method_get_one_way_collision_margin;
}


export class CollisionPolygon2D extends Node2D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("CollisionPolygon2D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("set_polygon");
      this._bindings.method_set_polygon = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1509147220
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("get_polygon");
      this._bindings.method_get_polygon = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2961356807
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("set_build_mode");
      this._bindings.method_set_build_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2780803135
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("get_build_mode");
      this._bindings.method_get_build_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3044948800
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("set_disabled");
      this._bindings.method_set_disabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("is_disabled");
      this._bindings.method_is_disabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("set_one_way_collision");
      this._bindings.method_set_one_way_collision = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("is_one_way_collision_enabled");
      this._bindings.method_is_one_way_collision_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("set_one_way_collision_margin");
      this._bindings.method_set_one_way_collision_margin = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("CollisionPolygon2D");
      let methodname = new StringName("get_one_way_collision_margin");
      this._bindings.method_get_one_way_collision_margin = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
  }
  set_polygon(_polygon) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_polygon,
      this._owner,
      _polygon
    );
  }
  get_polygon() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_polygon,
      this._owner,
			Variant.Type.PACKED_VECTOR2_ARRAY
    ,
      
    );
  }
  set_build_mode(_build_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_build_mode,
      this._owner,
      _build_mode
    );
  }
  get_build_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_build_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  set_disabled(_disabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_disabled,
      this._owner,
      _disabled
    );
  }
  is_disabled() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_disabled,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_one_way_collision(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_one_way_collision,
      this._owner,
      _enabled
    );
  }
  is_one_way_collision_enabled() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_one_way_collision_enabled,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_one_way_collision_margin(_margin) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_one_way_collision_margin,
      this._owner,
      _margin
    );
  }
  get_one_way_collision_margin() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_one_way_collision_margin,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  static BuildMode = {
    BUILD_SOLIDS: 0,
    BUILD_SEGMENTS: 1,
  }
}