import * as internal from '__internal__';
import { Variant } from 'src/js_godot/variant/variant'
import { StringName } from 'src/js_godot/variant/string_name'
import { GDString } from 'src/js_godot/variant/gd_string'
import { Container } from 'src/js_godot/classescontainer'
class _MethodBindings {
    method__update_property;
    method__set_read_only;
    method_set_label;
    method_get_label;
    method_set_read_only;
    method_is_read_only;
    method_set_checkable;
    method_is_checkable;
    method_set_checked;
    method_is_checked;
    method_set_draw_warning;
    method_is_draw_warning;
    method_set_keying;
    method_is_keying;
    method_set_deletable;
    method_is_deletable;
    method_get_edited_property;
    method_get_edited_object;
    method_update_property;
    method_add_focusable;
    method_set_bottom_editor;
    method_emit_changed;
}


export class EditorProperty extends Container{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("EditorProperty");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("_update_property");
      this._bindings.method__update_property = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("_set_read_only");
      this._bindings.method__set_read_only = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_label");
      this._bindings.method_set_label = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        83702148
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("get_label");
      this._bindings.method_get_label = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        201670096
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_read_only");
      this._bindings.method_set_read_only = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("is_read_only");
      this._bindings.method_is_read_only = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_checkable");
      this._bindings.method_set_checkable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("is_checkable");
      this._bindings.method_is_checkable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_checked");
      this._bindings.method_set_checked = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("is_checked");
      this._bindings.method_is_checked = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_draw_warning");
      this._bindings.method_set_draw_warning = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("is_draw_warning");
      this._bindings.method_is_draw_warning = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_keying");
      this._bindings.method_set_keying = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("is_keying");
      this._bindings.method_is_keying = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_deletable");
      this._bindings.method_set_deletable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("is_deletable");
      this._bindings.method_is_deletable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("get_edited_property");
      this._bindings.method_get_edited_property = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2002593661
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("get_edited_object");
      this._bindings.method_get_edited_object = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2050059866
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("update_property");
      this._bindings.method_update_property = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3218959716
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("add_focusable");
      this._bindings.method_add_focusable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1496901182
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("set_bottom_editor");
      this._bindings.method_set_bottom_editor = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1496901182
      );
    }
    {
      let classname = new StringName("EditorProperty");
      let methodname = new StringName("emit_changed");
      this._bindings.method_emit_changed = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3069422438
      );
    }
  }
  _update_property() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__update_property,
      this._owner,
      
    );
  }
  _set_read_only(_read_only) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__set_read_only,
      this._owner,
      _read_only
    );
  }
  set_label(_text) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_label,
      this._owner,
      _text
    );
  }
  get_label() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_label,
      this._owner,
			Variant.Type.STRING
    ,
      
    );
  }
  set_read_only(_read_only) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_read_only,
      this._owner,
      _read_only
    );
  }
  is_read_only() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_read_only,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_checkable(_checkable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_checkable,
      this._owner,
      _checkable
    );
  }
  is_checkable() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_checkable,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_checked(_checked) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_checked,
      this._owner,
      _checked
    );
  }
  is_checked() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_checked,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_draw_warning(_draw_warning) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_draw_warning,
      this._owner,
      _draw_warning
    );
  }
  is_draw_warning() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_draw_warning,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_keying(_keying) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_keying,
      this._owner,
      _keying
    );
  }
  is_keying() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_keying,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_deletable(_deletable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_deletable,
      this._owner,
      _deletable
    );
  }
  is_deletable() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_deletable,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  get_edited_property() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_edited_property,
      this._owner,
			Variant.Type.STRING_NAME
    ,
      
    );
  }
  get_edited_object() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_edited_object,
      this._owner,
			Variant.INT,
      
    );
  }
  update_property() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_update_property,
      this._owner,
      
    );
  }
  add_focusable(_control) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_add_focusable,
      this._owner,
      _control
    );
  }
  set_bottom_editor(_editor) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_bottom_editor,
      this._owner,
      _editor
    );
  }
  emit_changed(_property, _value, _field, _changing) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_emit_changed,
      this._owner,
      _property, _value, _field, _changing
    );
  }
}