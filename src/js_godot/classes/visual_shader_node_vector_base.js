import * as internal from '__internal__';
import { VisualShaderNode } from 'src/js_godot/classesvisual_shader_node'
class _MethodBindings {
    method_set_op_type;
    method_get_op_type;
}


export class VisualShaderNodeVectorBase extends VisualShaderNode{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("VisualShaderNodeVectorBase");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("VisualShaderNodeVectorBase");
      let methodname = new StringName("set_op_type");
      this._bindings.method_set_op_type = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1692596998
      );
    }
    {
      let classname = new StringName("VisualShaderNodeVectorBase");
      let methodname = new StringName("get_op_type");
      this._bindings.method_get_op_type = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2568738462
      );
    }
  }
  set_op_type(_type) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_op_type,
      this._owner,
      _type
    );
  }
  get_op_type() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_op_type,
      this._owner,
			Variant.INT,
      
    );
  }
  static OpType = {
    OP_TYPE_VECTOR_2D: 0,
    OP_TYPE_VECTOR_3D: 1,
    OP_TYPE_VECTOR_4D: 2,
    OP_TYPE_MAX: 3,
  }
}