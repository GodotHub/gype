import * as internal from '__internal__';
import { RefCounted } from 'src/js_godot/classesref_counted'
class _MethodBindings {
    method_setup;
    method_take_connection;
}


export class DTLSServer extends RefCounted{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("DTLSServer");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("DTLSServer");
      let methodname = new StringName("setup");
      this._bindings.method_setup = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1262296096
      );
    }
    {
      let classname = new StringName("DTLSServer");
      let methodname = new StringName("take_connection");
      this._bindings.method_take_connection = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3946580474
      );
    }
  }
  setup(_server_options) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_setup,
      this._owner,
			Variant.INT,
      _server_options
    );
  }
  take_connection(_udp_peer) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_take_connection,
      this._owner,
			Variant.INT,
      _udp_peer
    );
  }
}