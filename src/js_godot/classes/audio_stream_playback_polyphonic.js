import * as internal from '__internal__';
import { AudioStreamPlayback } from 'src/js_godot/classesaudio_stream_playback'
import { StringName } from 'src/js_godot/variant/string_name'
class _MethodBindings {
    method_play_stream;
    method_set_stream_volume;
    method_set_stream_pitch_scale;
    method_is_stream_playing;
    method_stop_stream;
}


export class AudioStreamPlaybackPolyphonic extends AudioStreamPlayback{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("AudioStreamPlaybackPolyphonic");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("AudioStreamPlaybackPolyphonic");
      let methodname = new StringName("play_stream");
      this._bindings.method_play_stream = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1846744803
      );
    }
    {
      let classname = new StringName("AudioStreamPlaybackPolyphonic");
      let methodname = new StringName("set_stream_volume");
      this._bindings.method_set_stream_volume = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1602489585
      );
    }
    {
      let classname = new StringName("AudioStreamPlaybackPolyphonic");
      let methodname = new StringName("set_stream_pitch_scale");
      this._bindings.method_set_stream_pitch_scale = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1602489585
      );
    }
    {
      let classname = new StringName("AudioStreamPlaybackPolyphonic");
      let methodname = new StringName("is_stream_playing");
      this._bindings.method_is_stream_playing = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1116898809
      );
    }
    {
      let classname = new StringName("AudioStreamPlaybackPolyphonic");
      let methodname = new StringName("stop_stream");
      this._bindings.method_stop_stream = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
  }
  play_stream(_stream, _from_offset, _volume_db, _pitch_scale, _playback_type, _bus) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_play_stream,
      this._owner,
			Variant.Type.INT,
      _stream, _from_offset, _volume_db, _pitch_scale, _playback_type, _bus
    );
  }
  set_stream_volume(_stream, _volume_db) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_stream_volume,
      this._owner,
      _stream, _volume_db
    );
  }
  set_stream_pitch_scale(_stream, _pitch_scale) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_stream_pitch_scale,
      this._owner,
      _stream, _pitch_scale
    );
  }
  is_stream_playing(_stream) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_stream_playing,
      this._owner,
			Variant.Type.BOOL,
      _stream
    );
  }
  stop_stream(_stream) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_stop_stream,
      this._owner,
      _stream
    );
  }
}