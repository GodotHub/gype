import * as internal from '__internal__';
import { Joint2D } from 'src/js_godot/classesjoint2d'
class _MethodBindings {
    method_set_length;
    method_get_length;
    method_set_initial_offset;
    method_get_initial_offset;
}


export class GrooveJoint2D extends Joint2D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("GrooveJoint2D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("GrooveJoint2D");
      let methodname = new StringName("set_length");
      this._bindings.method_set_length = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("GrooveJoint2D");
      let methodname = new StringName("get_length");
      this._bindings.method_get_length = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("GrooveJoint2D");
      let methodname = new StringName("set_initial_offset");
      this._bindings.method_set_initial_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("GrooveJoint2D");
      let methodname = new StringName("get_initial_offset");
      this._bindings.method_get_initial_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
  }
  set_length(_length) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_length,
      this._owner,
      _length
    );
  }
  get_length() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_length,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_initial_offset(_offset) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_initial_offset,
      this._owner,
      _offset
    );
  }
  get_initial_offset() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_initial_offset,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
}