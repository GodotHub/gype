import * as internal from '__internal__';
import { InputEvent } from 'src/js_godot/classesinput_event'
class _MethodBindings {
    method_set_button_index;
    method_get_button_index;
    method_set_pressure;
    method_get_pressure;
    method_set_pressed;
}


export class InputEventJoypadButton extends InputEvent{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("InputEventJoypadButton");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("InputEventJoypadButton");
      let methodname = new StringName("set_button_index");
      this._bindings.method_set_button_index = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1466368136
      );
    }
    {
      let classname = new StringName("InputEventJoypadButton");
      let methodname = new StringName("get_button_index");
      this._bindings.method_get_button_index = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        595588182
      );
    }
    {
      let classname = new StringName("InputEventJoypadButton");
      let methodname = new StringName("set_pressure");
      this._bindings.method_set_pressure = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("InputEventJoypadButton");
      let methodname = new StringName("get_pressure");
      this._bindings.method_get_pressure = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("InputEventJoypadButton");
      let methodname = new StringName("set_pressed");
      this._bindings.method_set_pressed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
  }
  set_button_index(_button_index) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_button_index,
      this._owner,
      _button_index
    );
  }
  get_button_index() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_button_index,
      this._owner,
			Variant.INT,
      
    );
  }
  set_pressure(_pressure) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_pressure,
      this._owner,
      _pressure
    );
  }
  get_pressure() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_pressure,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_pressed(_pressed) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_pressed,
      this._owner,
      _pressed
    );
  }
}