import * as internal from '__internal__';
import { StringName } from 'src/js_godot/variant/string_name'
import { PackedStringArray } from 'src/js_godot/variant/packed_string_array'
import { Node } from 'src/js_godot/classesnode'
class _MethodBindings {
    method_add_resource;
    method_remove_resource;
    method_rename_resource;
    method_has_resource;
    method_get_resource;
    method_get_resource_list;
}


export class ResourcePreloader extends Node{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("ResourcePreloader");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("ResourcePreloader");
      let methodname = new StringName("add_resource");
      this._bindings.method_add_resource = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1168801743
      );
    }
    {
      let classname = new StringName("ResourcePreloader");
      let methodname = new StringName("remove_resource");
      this._bindings.method_remove_resource = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3304788590
      );
    }
    {
      let classname = new StringName("ResourcePreloader");
      let methodname = new StringName("rename_resource");
      this._bindings.method_rename_resource = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3740211285
      );
    }
    {
      let classname = new StringName("ResourcePreloader");
      let methodname = new StringName("has_resource");
      this._bindings.method_has_resource = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2619796661
      );
    }
    {
      let classname = new StringName("ResourcePreloader");
      let methodname = new StringName("get_resource");
      this._bindings.method_get_resource = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3742749261
      );
    }
    {
      let classname = new StringName("ResourcePreloader");
      let methodname = new StringName("get_resource_list");
      this._bindings.method_get_resource_list = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1139954409
      );
    }
  }
  add_resource(_name, _resource) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_add_resource,
      this._owner,
      _name, _resource
    );
  }
  remove_resource(_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_remove_resource,
      this._owner,
      _name
    );
  }
  rename_resource(_name, _newname) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_rename_resource,
      this._owner,
      _name, _newname
    );
  }
  has_resource(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_has_resource,
      this._owner,
			Variant.Type.BOOL,
      _name
    );
  }
  get_resource(_name) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_resource,
      this._owner,
			Variant.INT,
      _name
    );
  }
  get_resource_list() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_resource_list,
      this._owner,
			Variant.Type.PACKED_STRING_ARRAY
    ,
      
    );
  }
}