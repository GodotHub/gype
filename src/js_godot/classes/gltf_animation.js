import * as internal from '__internal__';
import { Resource } from 'src/js_godot/classesresource'
import { Variant } from 'src/js_godot/variant/variant'
import { StringName } from 'src/js_godot/variant/string_name'
import { GDString } from 'src/js_godot/variant/gd_string'
class _MethodBindings {
    method_get_original_name;
    method_set_original_name;
    method_get_loop;
    method_set_loop;
    method_get_additional_data;
    method_set_additional_data;
}


export class GLTFAnimation extends Resource{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("GLTFAnimation");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("GLTFAnimation");
      let methodname = new StringName("get_original_name");
      this._bindings.method_get_original_name = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2841200299
      );
    }
    {
      let classname = new StringName("GLTFAnimation");
      let methodname = new StringName("set_original_name");
      this._bindings.method_set_original_name = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        83702148
      );
    }
    {
      let classname = new StringName("GLTFAnimation");
      let methodname = new StringName("get_loop");
      this._bindings.method_get_loop = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("GLTFAnimation");
      let methodname = new StringName("set_loop");
      this._bindings.method_set_loop = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("GLTFAnimation");
      let methodname = new StringName("get_additional_data");
      this._bindings.method_get_additional_data = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2138907829
      );
    }
    {
      let classname = new StringName("GLTFAnimation");
      let methodname = new StringName("set_additional_data");
      this._bindings.method_set_additional_data = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3776071444
      );
    }
  }
  get_original_name() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_original_name,
      this._owner,
			Variant.Type.STRING
    ,
      
    );
  }
  set_original_name(_original_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_original_name,
      this._owner,
      _original_name
    );
  }
  get_loop() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_loop,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_loop(_loop) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_loop,
      this._owner,
      _loop
    );
  }
  get_additional_data(_extension_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_additional_data,
      this._owner,
			Variant.Type.VARIANT
    ,
      _extension_name
    );
  }
  set_additional_data(_extension_name, _additional_data) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_additional_data,
      this._owner,
      _extension_name, _additional_data
    );
  }
}