import * as internal from '__internal__';
import { PackedByteArray } from 'src/js_godot/variant/packed_byte_array'
import { StreamPeer } from 'src/js_godot/classesstream_peer'
class _MethodBindings {
    method_seek;
    method_get_size;
    method_get_position;
    method_resize;
    method_set_data_array;
    method_get_data_array;
    method_clear;
    method_duplicate;
}


export class StreamPeerBuffer extends StreamPeer{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("StreamPeerBuffer");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("seek");
      this._bindings.method_seek = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("get_size");
      this._bindings.method_get_size = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("get_position");
      this._bindings.method_get_position = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("resize");
      this._bindings.method_resize = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("set_data_array");
      this._bindings.method_set_data_array = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2971499966
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("get_data_array");
      this._bindings.method_get_data_array = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2362200018
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("clear");
      this._bindings.method_clear = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3218959716
      );
    }
    {
      let classname = new StringName("StreamPeerBuffer");
      let methodname = new StringName("duplicate");
      this._bindings.method_duplicate = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2474064677
      );
    }
  }
  seek(_position) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_seek,
      this._owner,
      _position
    );
  }
  get_size() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_size,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  get_position() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_position,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  resize(_size) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_resize,
      this._owner,
      _size
    );
  }
  set_data_array(_data) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_data_array,
      this._owner,
      _data
    );
  }
  get_data_array() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_data_array,
      this._owner,
			Variant.Type.PACKED_BYTE_ARRAY
    ,
      
    );
  }
  clear() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_clear,
      this._owner,
      
    );
  }
  duplicate() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_duplicate,
      this._owner,
			Variant.INT,
      
    );
  }
}