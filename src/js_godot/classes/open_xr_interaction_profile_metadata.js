import * as internal from '__internal__';
import { GodotObject } from 'src/js_godot/classesgodot_object'
import { GDString } from 'src/js_godot/variant/gd_string'
class _MethodBindings {
    method_register_profile_rename;
    method_register_top_level_path;
    method_register_interaction_profile;
    method_register_io_path;
}


export class OpenXRInteractionProfileMetadata extends GodotObject{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("OpenXRInteractionProfileMetadata");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("OpenXRInteractionProfileMetadata");
      let methodname = new StringName("register_profile_rename");
      this._bindings.method_register_profile_rename = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3186203200
      );
    }
    {
      let classname = new StringName("OpenXRInteractionProfileMetadata");
      let methodname = new StringName("register_top_level_path");
      this._bindings.method_register_top_level_path = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        254767734
      );
    }
    {
      let classname = new StringName("OpenXRInteractionProfileMetadata");
      let methodname = new StringName("register_interaction_profile");
      this._bindings.method_register_interaction_profile = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        254767734
      );
    }
    {
      let classname = new StringName("OpenXRInteractionProfileMetadata");
      let methodname = new StringName("register_io_path");
      this._bindings.method_register_io_path = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3443511926
      );
    }
  }
  register_profile_rename(_old_name, _new_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_register_profile_rename,
      this._owner,
      _old_name, _new_name
    );
  }
  register_top_level_path(_display_name, _openxr_path, _openxr_extension_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_register_top_level_path,
      this._owner,
      _display_name, _openxr_path, _openxr_extension_name
    );
  }
  register_interaction_profile(_display_name, _openxr_path, _openxr_extension_name) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_register_interaction_profile,
      this._owner,
      _display_name, _openxr_path, _openxr_extension_name
    );
  }
  register_io_path(_interaction_profile, _display_name, _toplevel_path, _openxr_path, _openxr_extension_name, _action_type) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_register_io_path,
      this._owner,
      _interaction_profile, _display_name, _toplevel_path, _openxr_path, _openxr_extension_name, _action_type
    );
  }
}