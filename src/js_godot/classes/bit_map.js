import * as internal from '__internal__';
import { Resource } from 'src/js_godot/classesresource'
import { Vector2i } from 'src/js_godot/variant/vector2i'
import { Rect2i } from 'src/js_godot/variant/rect2i'
class _MethodBindings {
    method_create;
    method_create_from_image_alpha;
    method_set_bitv;
    method_set_bit;
    method_get_bitv;
    method_get_bit;
    method_set_bit_rect;
    method_get_true_bit_count;
    method_get_size;
    method_resize;
    method_grow_mask;
    method_convert_to_image;
    method_opaque_to_polygons;
}


export class BitMap extends Resource{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("BitMap");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("create");
      this._bindings.method_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1130785943
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("create_from_image_alpha");
      this._bindings.method_create_from_image_alpha = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        106271684
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("set_bitv");
      this._bindings.method_set_bitv = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4153096796
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("set_bit");
      this._bindings.method_set_bit = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1383440665
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("get_bitv");
      this._bindings.method_get_bitv = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3900751641
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("get_bit");
      this._bindings.method_get_bit = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2522259332
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("set_bit_rect");
      this._bindings.method_set_bit_rect = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        472162941
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("get_true_bit_count");
      this._bindings.method_get_true_bit_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("get_size");
      this._bindings.method_get_size = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3690982128
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("resize");
      this._bindings.method_resize = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1130785943
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("grow_mask");
      this._bindings.method_grow_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3317281434
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("convert_to_image");
      this._bindings.method_convert_to_image = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4190603485
      );
    }
    {
      let classname = new StringName("BitMap");
      let methodname = new StringName("opaque_to_polygons");
      this._bindings.method_opaque_to_polygons = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        48478126
      );
    }
  }
  create(_size) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_create,
      this._owner,
      _size
    );
  }
  create_from_image_alpha(_image, _threshold) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_create_from_image_alpha,
      this._owner,
      _image, _threshold
    );
  }
  set_bitv(_position, _bit) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_bitv,
      this._owner,
      _position, _bit
    );
  }
  set_bit(_x, _y, _bit) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_bit,
      this._owner,
      _x, _y, _bit
    );
  }
  get_bitv(_position) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_bitv,
      this._owner,
			Variant.Type.BOOL,
      _position
    );
  }
  get_bit(_x, _y) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_bit,
      this._owner,
			Variant.Type.BOOL,
      _x, _y
    );
  }
  set_bit_rect(_rect, _bit) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_bit_rect,
      this._owner,
      _rect, _bit
    );
  }
  get_true_bit_count() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_true_bit_count,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  get_size() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_size,
      this._owner,
			Variant.Type.VECTOR2I
    ,
      
    );
  }
  resize(_new_size) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_resize,
      this._owner,
      _new_size
    );
  }
  grow_mask(_pixels, _rect) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_grow_mask,
      this._owner,
      _pixels, _rect
    );
  }
  convert_to_image() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_convert_to_image,
      this._owner,
			Variant.INT,
      
    );
  }
  opaque_to_polygons(_rect, _epsilon) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_opaque_to_polygons,
      this._owner,
			Variant.INT,
      _rect, _epsilon
    );
  }
}