import * as internal from '__internal__';
import { Color } from 'src/js_godot/variant/color'
import { RefCounted } from 'src/js_godot/classesref_counted'
class _MethodBindings {
    method_set_enable_logic_op;
    method_get_enable_logic_op;
    method_set_logic_op;
    method_get_logic_op;
    method_set_blend_constant;
    method_get_blend_constant;
    method_set_attachments;
    method_get_attachments;
}


export class RDPipelineColorBlendState extends RefCounted{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("RDPipelineColorBlendState");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("set_enable_logic_op");
      this._bindings.method_set_enable_logic_op = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("get_enable_logic_op");
      this._bindings.method_get_enable_logic_op = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("set_logic_op");
      this._bindings.method_set_logic_op = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3610841058
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("get_logic_op");
      this._bindings.method_get_logic_op = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        988254690
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("set_blend_constant");
      this._bindings.method_set_blend_constant = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2920490490
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("get_blend_constant");
      this._bindings.method_get_blend_constant = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3444240500
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("set_attachments");
      this._bindings.method_set_attachments = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        381264803
      );
    }
    {
      let classname = new StringName("RDPipelineColorBlendState");
      let methodname = new StringName("get_attachments");
      this._bindings.method_get_attachments = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3995934104
      );
    }
  }
  set_enable_logic_op(_p_member) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_enable_logic_op,
      this._owner,
      _p_member
    );
  }
  get_enable_logic_op() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_enable_logic_op,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_logic_op(_p_member) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_logic_op,
      this._owner,
      _p_member
    );
  }
  get_logic_op() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_logic_op,
      this._owner,
			Variant.INT,
      
    );
  }
  set_blend_constant(_p_member) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_blend_constant,
      this._owner,
      _p_member
    );
  }
  get_blend_constant() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_blend_constant,
      this._owner,
			Variant.Type.COLOR
    ,
      
    );
  }
  set_attachments(_attachments) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_attachments,
      this._owner,
      _attachments
    );
  }
  get_attachments() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_attachments,
      this._owner,
			Variant.INT,
      
    );
  }
}