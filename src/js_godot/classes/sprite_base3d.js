import * as internal from '__internal__';
import { Rect2 } from 'src/js_godot/variant/rect2'
import { Color } from 'src/js_godot/variant/color'
import { GeometryInstance3D } from 'src/js_godot/classesgeometry_instance3d'
import { Vector2 } from 'src/js_godot/variant/vector2'
class _MethodBindings {
    method_set_centered;
    method_is_centered;
    method_set_offset;
    method_get_offset;
    method_set_flip_h;
    method_is_flipped_h;
    method_set_flip_v;
    method_is_flipped_v;
    method_set_modulate;
    method_get_modulate;
    method_set_render_priority;
    method_get_render_priority;
    method_set_pixel_size;
    method_get_pixel_size;
    method_set_axis;
    method_get_axis;
    method_set_draw_flag;
    method_get_draw_flag;
    method_set_alpha_cut_mode;
    method_get_alpha_cut_mode;
    method_set_alpha_scissor_threshold;
    method_get_alpha_scissor_threshold;
    method_set_alpha_hash_scale;
    method_get_alpha_hash_scale;
    method_set_alpha_antialiasing;
    method_get_alpha_antialiasing;
    method_set_alpha_antialiasing_edge;
    method_get_alpha_antialiasing_edge;
    method_set_billboard_mode;
    method_get_billboard_mode;
    method_set_texture_filter;
    method_get_texture_filter;
    method_get_item_rect;
    method_generate_triangle_mesh;
}


export class SpriteBase3D extends GeometryInstance3D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("SpriteBase3D");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_centered");
      this._bindings.method_set_centered = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("is_centered");
      this._bindings.method_is_centered = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_offset");
      this._bindings.method_set_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        743155724
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_offset");
      this._bindings.method_get_offset = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3341600327
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_flip_h");
      this._bindings.method_set_flip_h = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("is_flipped_h");
      this._bindings.method_is_flipped_h = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_flip_v");
      this._bindings.method_set_flip_v = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("is_flipped_v");
      this._bindings.method_is_flipped_v = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_modulate");
      this._bindings.method_set_modulate = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2920490490
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_modulate");
      this._bindings.method_get_modulate = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3444240500
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_render_priority");
      this._bindings.method_set_render_priority = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_render_priority");
      this._bindings.method_get_render_priority = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_pixel_size");
      this._bindings.method_set_pixel_size = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_pixel_size");
      this._bindings.method_get_pixel_size = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_axis");
      this._bindings.method_set_axis = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1144690656
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_axis");
      this._bindings.method_get_axis = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3050976882
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_draw_flag");
      this._bindings.method_set_draw_flag = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1135633219
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_draw_flag");
      this._bindings.method_get_draw_flag = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1733036628
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_alpha_cut_mode");
      this._bindings.method_set_alpha_cut_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        227561226
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_alpha_cut_mode");
      this._bindings.method_get_alpha_cut_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        336003791
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_alpha_scissor_threshold");
      this._bindings.method_set_alpha_scissor_threshold = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_alpha_scissor_threshold");
      this._bindings.method_get_alpha_scissor_threshold = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_alpha_hash_scale");
      this._bindings.method_set_alpha_hash_scale = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_alpha_hash_scale");
      this._bindings.method_get_alpha_hash_scale = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_alpha_antialiasing");
      this._bindings.method_set_alpha_antialiasing = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3212649852
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_alpha_antialiasing");
      this._bindings.method_get_alpha_antialiasing = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2889939400
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_alpha_antialiasing_edge");
      this._bindings.method_set_alpha_antialiasing_edge = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_alpha_antialiasing_edge");
      this._bindings.method_get_alpha_antialiasing_edge = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_billboard_mode");
      this._bindings.method_set_billboard_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4202036497
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_billboard_mode");
      this._bindings.method_get_billboard_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1283840139
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("set_texture_filter");
      this._bindings.method_set_texture_filter = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        22904437
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_texture_filter");
      this._bindings.method_get_texture_filter = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3289213076
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("get_item_rect");
      this._bindings.method_get_item_rect = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1639390495
      );
    }
    {
      let classname = new StringName("SpriteBase3D");
      let methodname = new StringName("generate_triangle_mesh");
      this._bindings.method_generate_triangle_mesh = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3476533166
      );
    }
  }
  set_centered(_centered) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_centered,
      this._owner,
      _centered
    );
  }
  is_centered() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_centered,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_offset(_offset) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_offset,
      this._owner,
      _offset
    );
  }
  get_offset() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_offset,
      this._owner,
			Variant.Type.VECTOR2
    ,
      
    );
  }
  set_flip_h(_flip_h) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_flip_h,
      this._owner,
      _flip_h
    );
  }
  is_flipped_h() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_flipped_h,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_flip_v(_flip_v) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_flip_v,
      this._owner,
      _flip_v
    );
  }
  is_flipped_v() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_is_flipped_v,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_modulate(_modulate) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_modulate,
      this._owner,
      _modulate
    );
  }
  get_modulate() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_modulate,
      this._owner,
			Variant.Type.COLOR
    ,
      
    );
  }
  set_render_priority(_priority) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_render_priority,
      this._owner,
      _priority
    );
  }
  get_render_priority() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_render_priority,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_pixel_size(_pixel_size) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_pixel_size,
      this._owner,
      _pixel_size
    );
  }
  get_pixel_size() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_pixel_size,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_axis(_axis) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_axis,
      this._owner,
      _axis
    );
  }
  get_axis() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_axis,
      this._owner,
			Variant.INT,
      
    );
  }
  set_draw_flag(_flag, _enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_draw_flag,
      this._owner,
      _flag, _enabled
    );
  }
  get_draw_flag(_flag) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_draw_flag,
      this._owner,
			Variant.Type.BOOL,
      _flag
    );
  }
  set_alpha_cut_mode(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_alpha_cut_mode,
      this._owner,
      _mode
    );
  }
  get_alpha_cut_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_alpha_cut_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  set_alpha_scissor_threshold(_threshold) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_alpha_scissor_threshold,
      this._owner,
      _threshold
    );
  }
  get_alpha_scissor_threshold() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_alpha_scissor_threshold,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_alpha_hash_scale(_threshold) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_alpha_hash_scale,
      this._owner,
      _threshold
    );
  }
  get_alpha_hash_scale() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_alpha_hash_scale,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_alpha_antialiasing(_alpha_aa) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_alpha_antialiasing,
      this._owner,
      _alpha_aa
    );
  }
  get_alpha_antialiasing() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_alpha_antialiasing,
      this._owner,
			Variant.INT,
      
    );
  }
  set_alpha_antialiasing_edge(_edge) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_alpha_antialiasing_edge,
      this._owner,
      _edge
    );
  }
  get_alpha_antialiasing_edge() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_alpha_antialiasing_edge,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_billboard_mode(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_billboard_mode,
      this._owner,
      _mode
    );
  }
  get_billboard_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_billboard_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  set_texture_filter(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_texture_filter,
      this._owner,
      _mode
    );
  }
  get_texture_filter() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_texture_filter,
      this._owner,
			Variant.INT,
      
    );
  }
  get_item_rect() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_item_rect,
      this._owner,
			Variant.Type.RECT2
    ,
      
    );
  }
  generate_triangle_mesh() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_generate_triangle_mesh,
      this._owner,
			Variant.INT,
      
    );
  }
  static DrawFlags = {
    FLAG_TRANSPARENT: 0,
    FLAG_SHADED: 1,
    FLAG_DOUBLE_SIDED: 2,
    FLAG_DISABLE_DEPTH_TEST: 3,
    FLAG_FIXED_SIZE: 4,
    FLAG_MAX: 5,
  }
  static AlphaCutMode = {
    ALPHA_CUT_DISABLED: 0,
    ALPHA_CUT_DISCARD: 1,
    ALPHA_CUT_OPAQUE_PREPASS: 2,
    ALPHA_CUT_HASH: 3,
  }
}