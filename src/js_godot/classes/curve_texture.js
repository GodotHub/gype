import * as internal from '__internal__';
import { Texture2D } from 'src/js_godot/classestexture2d'
class _MethodBindings {
    method_set_width;
    method_set_curve;
    method_get_curve;
    method_set_texture_mode;
    method_get_texture_mode;
}


export class CurveTexture extends Texture2D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("CurveTexture");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("CurveTexture");
      let methodname = new StringName("set_width");
      this._bindings.method_set_width = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("CurveTexture");
      let methodname = new StringName("set_curve");
      this._bindings.method_set_curve = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        270443179
      );
    }
    {
      let classname = new StringName("CurveTexture");
      let methodname = new StringName("get_curve");
      this._bindings.method_get_curve = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2460114913
      );
    }
    {
      let classname = new StringName("CurveTexture");
      let methodname = new StringName("set_texture_mode");
      this._bindings.method_set_texture_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1321955367
      );
    }
    {
      let classname = new StringName("CurveTexture");
      let methodname = new StringName("get_texture_mode");
      this._bindings.method_get_texture_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        715756376
      );
    }
  }
  set_width(_width) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_width,
      this._owner,
      _width
    );
  }
  set_curve(_curve) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_curve,
      this._owner,
      _curve
    );
  }
  get_curve() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_curve,
      this._owner,
			Variant.INT,
      
    );
  }
  set_texture_mode(_texture_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_texture_mode,
      this._owner,
      _texture_mode
    );
  }
  get_texture_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_texture_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  static TextureMode = {
    TEXTURE_MODE_RGB: 0,
    TEXTURE_MODE_RED: 1,
  }
}