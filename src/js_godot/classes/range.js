import * as internal from '__internal__';
import { Control } from 'src/js_godot/classescontrol'
class _MethodBindings {
    method__value_changed;
    method_get_value;
    method_get_min;
    method_get_max;
    method_get_step;
    method_get_page;
    method_get_as_ratio;
    method_set_value;
    method_set_value_no_signal;
    method_set_min;
    method_set_max;
    method_set_step;
    method_set_page;
    method_set_as_ratio;
    method_set_use_rounded_values;
    method_is_using_rounded_values;
    method_set_exp_ratio;
    method_is_ratio_exp;
    method_set_allow_greater;
    method_is_greater_allowed;
    method_set_allow_lesser;
    method_is_lesser_allowed;
    method_share;
    method_unshare;
}


export class Range extends Control{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("Range");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("Range");
      let methodname = new StringName("_value_changed");
      this._bindings.method__value_changed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("get_value");
      this._bindings.method_get_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("get_min");
      this._bindings.method_get_min = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("get_max");
      this._bindings.method_get_max = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("get_step");
      this._bindings.method_get_step = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("get_page");
      this._bindings.method_get_page = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("get_as_ratio");
      this._bindings.method_get_as_ratio = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_value");
      this._bindings.method_set_value = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_value_no_signal");
      this._bindings.method_set_value_no_signal = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_min");
      this._bindings.method_set_min = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_max");
      this._bindings.method_set_max = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_step");
      this._bindings.method_set_step = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_page");
      this._bindings.method_set_page = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_as_ratio");
      this._bindings.method_set_as_ratio = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_use_rounded_values");
      this._bindings.method_set_use_rounded_values = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("is_using_rounded_values");
      this._bindings.method_is_using_rounded_values = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_exp_ratio");
      this._bindings.method_set_exp_ratio = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("is_ratio_exp");
      this._bindings.method_is_ratio_exp = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_allow_greater");
      this._bindings.method_set_allow_greater = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("is_greater_allowed");
      this._bindings.method_is_greater_allowed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("set_allow_lesser");
      this._bindings.method_set_allow_lesser = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("is_lesser_allowed");
      this._bindings.method_is_lesser_allowed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("share");
      this._bindings.method_share = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1078189570
      );
    }
    {
      let classname = new StringName("Range");
      let methodname = new StringName("unshare");
      this._bindings.method_unshare = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3218959716
      );
    }
  }
  _value_changed(_new_value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__value_changed,
      this._owner,
      _new_value
    );
  }
  get_value() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_value,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_min() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_min,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_max() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_max,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_step() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_step,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_page() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_page,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  get_as_ratio() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_as_ratio,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_value(_value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_value,
      this._owner,
      _value
    );
  }
  set_value_no_signal(_value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_value_no_signal,
      this._owner,
      _value
    );
  }
  set_min(_minimum) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_min,
      this._owner,
      _minimum
    );
  }
  set_max(_maximum) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_max,
      this._owner,
      _maximum
    );
  }
  set_step(_step) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_step,
      this._owner,
      _step
    );
  }
  set_page(_pagesize) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_page,
      this._owner,
      _pagesize
    );
  }
  set_as_ratio(_value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_as_ratio,
      this._owner,
      _value
    );
  }
  set_use_rounded_values(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_use_rounded_values,
      this._owner,
      _enabled
    );
  }
  is_using_rounded_values() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_using_rounded_values,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_exp_ratio(_enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_exp_ratio,
      this._owner,
      _enabled
    );
  }
  is_ratio_exp() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_ratio_exp,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_allow_greater(_allow) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_allow_greater,
      this._owner,
      _allow
    );
  }
  is_greater_allowed() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_greater_allowed,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_allow_lesser(_allow) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_allow_lesser,
      this._owner,
      _allow
    );
  }
  is_lesser_allowed() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_lesser_allowed,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  share(_with) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_share,
      this._owner,
      _with
    );
  }
  unshare() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_unshare,
      this._owner,
      
    );
  }
}