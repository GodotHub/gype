import * as internal from '__internal__';
import { Node2D } from 'src/js_godot/classesnode2d'
class _MethodBindings {
    method_set_occluder_polygon;
    method_get_occluder_polygon;
    method_set_occluder_light_mask;
    method_get_occluder_light_mask;
    method_set_as_sdf_collision;
    method_is_set_as_sdf_collision;
}


export class LightOccluder2D extends Node2D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("LightOccluder2D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("LightOccluder2D");
      let methodname = new StringName("set_occluder_polygon");
      this._bindings.method_set_occluder_polygon = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3258315893
      );
    }
    {
      let classname = new StringName("LightOccluder2D");
      let methodname = new StringName("get_occluder_polygon");
      this._bindings.method_get_occluder_polygon = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3962317075
      );
    }
    {
      let classname = new StringName("LightOccluder2D");
      let methodname = new StringName("set_occluder_light_mask");
      this._bindings.method_set_occluder_light_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("LightOccluder2D");
      let methodname = new StringName("get_occluder_light_mask");
      this._bindings.method_get_occluder_light_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("LightOccluder2D");
      let methodname = new StringName("set_as_sdf_collision");
      this._bindings.method_set_as_sdf_collision = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("LightOccluder2D");
      let methodname = new StringName("is_set_as_sdf_collision");
      this._bindings.method_is_set_as_sdf_collision = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
  }
  set_occluder_polygon(_polygon) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_occluder_polygon,
      this._owner,
      _polygon
    );
  }
  get_occluder_polygon() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_occluder_polygon,
      this._owner,
			Variant.INT,
      
    );
  }
  set_occluder_light_mask(_mask) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_occluder_light_mask,
      this._owner,
      _mask
    );
  }
  get_occluder_light_mask() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_occluder_light_mask,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_as_sdf_collision(_enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_as_sdf_collision,
      this._owner,
      _enable
    );
  }
  is_set_as_sdf_collision() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_set_as_sdf_collision,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
}