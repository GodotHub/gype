import * as internal from '__internal__';
import { Button } from 'src/js_godot/classesbutton'
class _MethodBindings {
    method_get_popup;
    method_show_popup;
    method_set_switch_on_hover;
    method_is_switch_on_hover;
    method_set_disable_shortcuts;
    method_set_item_count;
    method_get_item_count;
}


export class MenuButton extends Button{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("MenuButton");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("get_popup");
      this._bindings.method_get_popup = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        229722558
      );
    }
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("show_popup");
      this._bindings.method_show_popup = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3218959716
      );
    }
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("set_switch_on_hover");
      this._bindings.method_set_switch_on_hover = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("is_switch_on_hover");
      this._bindings.method_is_switch_on_hover = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2240911060
      );
    }
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("set_disable_shortcuts");
      this._bindings.method_set_disable_shortcuts = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("set_item_count");
      this._bindings.method_set_item_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("MenuButton");
      let methodname = new StringName("get_item_count");
      this._bindings.method_get_item_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
  }
  get_popup() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_popup,
      this._owner,
			Variant.INT,
      
    );
  }
  show_popup() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_show_popup,
      this._owner,
      
    );
  }
  set_switch_on_hover(_enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_switch_on_hover,
      this._owner,
      _enable
    );
  }
  is_switch_on_hover() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_switch_on_hover,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_disable_shortcuts(_disabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_disable_shortcuts,
      this._owner,
      _disabled
    );
  }
  set_item_count(_count) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_item_count,
      this._owner,
      _count
    );
  }
  get_item_count() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_item_count,
      this._owner,
			Variant.Type.INT,
      
    );
  }
}