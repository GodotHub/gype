import * as internal from '__internal__';
import { Node2D } from 'src/js_godot/classesnode2d'
import { GDString } from 'src/js_godot/variant/gd_string'
class _MethodBindings {
    method_set_texture_normal;
    method_get_texture_normal;
    method_set_texture_pressed;
    method_get_texture_pressed;
    method_set_bitmask;
    method_get_bitmask;
    method_set_shape;
    method_get_shape;
    method_set_shape_centered;
    method_is_shape_centered;
    method_set_shape_visible;
    method_is_shape_visible;
    method_set_action;
    method_get_action;
    method_set_visibility_mode;
    method_get_visibility_mode;
    method_set_passby_press;
    method_is_passby_press_enabled;
    method_is_pressed;
}


export class TouchScreenButton extends Node2D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("TouchScreenButton");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_texture_normal");
      this._bindings.method_set_texture_normal = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4051416890
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("get_texture_normal");
      this._bindings.method_get_texture_normal = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3635182373
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_texture_pressed");
      this._bindings.method_set_texture_pressed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4051416890
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("get_texture_pressed");
      this._bindings.method_get_texture_pressed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3635182373
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_bitmask");
      this._bindings.method_set_bitmask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        698588216
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("get_bitmask");
      this._bindings.method_get_bitmask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2459671998
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_shape");
      this._bindings.method_set_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        771364740
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("get_shape");
      this._bindings.method_get_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        522005891
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_shape_centered");
      this._bindings.method_set_shape_centered = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("is_shape_centered");
      this._bindings.method_is_shape_centered = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_shape_visible");
      this._bindings.method_set_shape_visible = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("is_shape_visible");
      this._bindings.method_is_shape_visible = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_action");
      this._bindings.method_set_action = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        83702148
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("get_action");
      this._bindings.method_get_action = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        201670096
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_visibility_mode");
      this._bindings.method_set_visibility_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3031128463
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("get_visibility_mode");
      this._bindings.method_get_visibility_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2558996468
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("set_passby_press");
      this._bindings.method_set_passby_press = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("is_passby_press_enabled");
      this._bindings.method_is_passby_press_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("TouchScreenButton");
      let methodname = new StringName("is_pressed");
      this._bindings.method_is_pressed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
  }
  set_texture_normal(_texture) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_texture_normal,
      this._owner,
      _texture
    );
  }
  get_texture_normal() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_texture_normal,
      this._owner,
			Variant.INT,
      
    );
  }
  set_texture_pressed(_texture) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_texture_pressed,
      this._owner,
      _texture
    );
  }
  get_texture_pressed() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_texture_pressed,
      this._owner,
			Variant.INT,
      
    );
  }
  set_bitmask(_bitmask) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_bitmask,
      this._owner,
      _bitmask
    );
  }
  get_bitmask() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_bitmask,
      this._owner,
			Variant.INT,
      
    );
  }
  set_shape(_shape) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_shape,
      this._owner,
      _shape
    );
  }
  get_shape() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_shape,
      this._owner,
			Variant.INT,
      
    );
  }
  set_shape_centered(_bool) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_shape_centered,
      this._owner,
      _bool
    );
  }
  is_shape_centered() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_shape_centered,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_shape_visible(_bool) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_shape_visible,
      this._owner,
      _bool
    );
  }
  is_shape_visible() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_shape_visible,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_action(_action) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_action,
      this._owner,
      _action
    );
  }
  get_action() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_action,
      this._owner,
			Variant.Type.STRING
    ,
      
    );
  }
  set_visibility_mode(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_visibility_mode,
      this._owner,
      _mode
    );
  }
  get_visibility_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_visibility_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  set_passby_press(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_passby_press,
      this._owner,
      _enabled
    );
  }
  is_passby_press_enabled() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_passby_press_enabled,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  is_pressed() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_pressed,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  static VisibilityMode = {
    VISIBILITY_ALWAYS: 0,
    VISIBILITY_TOUCHSCREEN_ONLY: 1,
  }
}