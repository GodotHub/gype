import * as internal from '__internal__';
import { RefCounted } from 'src/js_godot/classesref_counted'
class _MethodBindings {
    method_set_max_concavity;
    method_get_max_concavity;
    method_set_symmetry_planes_clipping_bias;
    method_get_symmetry_planes_clipping_bias;
    method_set_revolution_axes_clipping_bias;
    method_get_revolution_axes_clipping_bias;
    method_set_min_volume_per_convex_hull;
    method_get_min_volume_per_convex_hull;
    method_set_resolution;
    method_get_resolution;
    method_set_max_num_vertices_per_convex_hull;
    method_get_max_num_vertices_per_convex_hull;
    method_set_plane_downsampling;
    method_get_plane_downsampling;
    method_set_convex_hull_downsampling;
    method_get_convex_hull_downsampling;
    method_set_normalize_mesh;
    method_get_normalize_mesh;
    method_set_mode;
    method_get_mode;
    method_set_convex_hull_approximation;
    method_get_convex_hull_approximation;
    method_set_max_convex_hulls;
    method_get_max_convex_hulls;
    method_set_project_hull_vertices;
    method_get_project_hull_vertices;
}


export class MeshConvexDecompositionSettings extends RefCounted{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("MeshConvexDecompositionSettings");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_max_concavity");
      this._bindings.method_set_max_concavity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_max_concavity");
      this._bindings.method_get_max_concavity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_symmetry_planes_clipping_bias");
      this._bindings.method_set_symmetry_planes_clipping_bias = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_symmetry_planes_clipping_bias");
      this._bindings.method_get_symmetry_planes_clipping_bias = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_revolution_axes_clipping_bias");
      this._bindings.method_set_revolution_axes_clipping_bias = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_revolution_axes_clipping_bias");
      this._bindings.method_get_revolution_axes_clipping_bias = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_min_volume_per_convex_hull");
      this._bindings.method_set_min_volume_per_convex_hull = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        373806689
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_min_volume_per_convex_hull");
      this._bindings.method_get_min_volume_per_convex_hull = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1740695150
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_resolution");
      this._bindings.method_set_resolution = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_resolution");
      this._bindings.method_get_resolution = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_max_num_vertices_per_convex_hull");
      this._bindings.method_set_max_num_vertices_per_convex_hull = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_max_num_vertices_per_convex_hull");
      this._bindings.method_get_max_num_vertices_per_convex_hull = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_plane_downsampling");
      this._bindings.method_set_plane_downsampling = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_plane_downsampling");
      this._bindings.method_get_plane_downsampling = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_convex_hull_downsampling");
      this._bindings.method_set_convex_hull_downsampling = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_convex_hull_downsampling");
      this._bindings.method_get_convex_hull_downsampling = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_normalize_mesh");
      this._bindings.method_set_normalize_mesh = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_normalize_mesh");
      this._bindings.method_get_normalize_mesh = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_mode");
      this._bindings.method_set_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1668072869
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_mode");
      this._bindings.method_get_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        23479454
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_convex_hull_approximation");
      this._bindings.method_set_convex_hull_approximation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_convex_hull_approximation");
      this._bindings.method_get_convex_hull_approximation = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_max_convex_hulls");
      this._bindings.method_set_max_convex_hulls = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1286410249
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_max_convex_hulls");
      this._bindings.method_get_max_convex_hulls = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        3905245786
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("set_project_hull_vertices");
      this._bindings.method_set_project_hull_vertices = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        2586408642
      );
    }
    {
      let classname = new StringName("MeshConvexDecompositionSettings");
      let methodname = new StringName("get_project_hull_vertices");
      this._bindings.method_get_project_hull_vertices = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        36873697
      );
    }
  }
  set_max_concavity(_max_concavity) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_max_concavity,
      this._owner,
      _max_concavity
    );
  }
  get_max_concavity() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_max_concavity,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_symmetry_planes_clipping_bias(_symmetry_planes_clipping_bias) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_symmetry_planes_clipping_bias,
      this._owner,
      _symmetry_planes_clipping_bias
    );
  }
  get_symmetry_planes_clipping_bias() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_symmetry_planes_clipping_bias,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_revolution_axes_clipping_bias(_revolution_axes_clipping_bias) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_revolution_axes_clipping_bias,
      this._owner,
      _revolution_axes_clipping_bias
    );
  }
  get_revolution_axes_clipping_bias() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_revolution_axes_clipping_bias,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_min_volume_per_convex_hull(_min_volume_per_convex_hull) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_min_volume_per_convex_hull,
      this._owner,
      _min_volume_per_convex_hull
    );
  }
  get_min_volume_per_convex_hull() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_min_volume_per_convex_hull,
      this._owner,
			Variant.Type.FLOAT,
      
    );
  }
  set_resolution(_min_volume_per_convex_hull) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_resolution,
      this._owner,
      _min_volume_per_convex_hull
    );
  }
  get_resolution() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_resolution,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_max_num_vertices_per_convex_hull(_max_num_vertices_per_convex_hull) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_max_num_vertices_per_convex_hull,
      this._owner,
      _max_num_vertices_per_convex_hull
    );
  }
  get_max_num_vertices_per_convex_hull() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_max_num_vertices_per_convex_hull,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_plane_downsampling(_plane_downsampling) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_plane_downsampling,
      this._owner,
      _plane_downsampling
    );
  }
  get_plane_downsampling() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_plane_downsampling,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_convex_hull_downsampling(_convex_hull_downsampling) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_convex_hull_downsampling,
      this._owner,
      _convex_hull_downsampling
    );
  }
  get_convex_hull_downsampling() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_convex_hull_downsampling,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_normalize_mesh(_normalize_mesh) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_normalize_mesh,
      this._owner,
      _normalize_mesh
    );
  }
  get_normalize_mesh() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_normalize_mesh,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_mode(_mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_mode,
      this._owner,
      _mode
    );
  }
  get_mode() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_mode,
      this._owner,
			Variant.INT,
      
    );
  }
  set_convex_hull_approximation(_convex_hull_approximation) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_convex_hull_approximation,
      this._owner,
      _convex_hull_approximation
    );
  }
  get_convex_hull_approximation() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_convex_hull_approximation,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  set_max_convex_hulls(_max_convex_hulls) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_max_convex_hulls,
      this._owner,
      _max_convex_hulls
    );
  }
  get_max_convex_hulls() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_max_convex_hulls,
      this._owner,
			Variant.Type.INT,
      
    );
  }
  set_project_hull_vertices(_project_hull_vertices) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method_set_project_hull_vertices,
      this._owner,
      _project_hull_vertices
    );
  }
  get_project_hull_vertices() {
    return _call_native_mb_ret(
      ClassDB._bindings.method_get_project_hull_vertices,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  static Mode = {
    CONVEX_DECOMPOSITION_MODE_VOXEL: 0,
    CONVEX_DECOMPOSITION_MODE_TETRAHEDRON: 1,
  }
}