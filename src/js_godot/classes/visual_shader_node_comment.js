import * as internal from '__internal__';
import { VisualShaderNodeFrame } from 'src/js_godot/classesvisual_shader_node_frame'
import { GDString } from 'src/js_godot/variant/gd_string'
class _MethodBindings {
    method_set_description;
    method_get_description;
}


export class VisualShaderNodeComment extends VisualShaderNodeFrame{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("VisualShaderNodeComment");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("VisualShaderNodeComment");
      let methodname = new StringName("set_description");
      this._bindings.method_set_description = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        83702148
      );
    }
    {
      let classname = new StringName("VisualShaderNodeComment");
      let methodname = new StringName("get_description");
      this._bindings.method_get_description = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        201670096
      );
    }
  }
  set_description(_description) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_description,
      this._owner,
      _description
    );
  }
  get_description() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_description,
      this._owner,
			Variant.Type.STRING
    ,
      
    );
  }
}