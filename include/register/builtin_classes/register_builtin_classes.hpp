#ifndef __REGISTER_BUILTIN_CLASSES_H__
#define __REGISTER_BUILTIN_CLASSES_H__

// Forward declarations for individual class registration functions
// void register_variant();
void register_string();
void register_proxy_string();
void register_vector2();
void register_proxy_vector2();
void register_vector2i();
void register_proxy_vector2i();
void register_rect2();
void register_proxy_rect2();
void register_rect2i();
void register_proxy_rect2i();
void register_vector3();
void register_proxy_vector3();
void register_vector3i();
void register_proxy_vector3i();
void register_transform2d();
void register_proxy_transform2d();
void register_vector4();
void register_proxy_vector4();
void register_vector4i();
void register_proxy_vector4i();
void register_plane();
void register_proxy_plane();
void register_quaternion();
void register_proxy_quaternion();
void register_aabb();
void register_proxy_aabb();
void register_basis();
void register_proxy_basis();
void register_transform3d();
void register_proxy_transform3d();
void register_projection();
void register_proxy_projection();
void register_color();
void register_proxy_color();
void register_string_name();
void register_proxy_string_name();
void register_node_path();
void register_proxy_node_path();
void register_rid();
void register_proxy_rid();
void register_callable();
void register_proxy_callable();
void register_signal();
void register_proxy_signal();
void register_dictionary();
void register_proxy_dictionary();
void register_array();
void register_proxy_array();
void register_packed_byte_array();
void register_proxy_packed_byte_array();
void register_packed_int32_array();
void register_proxy_packed_int32_array();
void register_packed_int64_array();
void register_proxy_packed_int64_array();
void register_packed_float32_array();
void register_proxy_packed_float32_array();
void register_packed_float64_array();
void register_proxy_packed_float64_array();
void register_packed_string_array();
void register_proxy_packed_string_array();
void register_packed_vector2_array();
void register_proxy_packed_vector2_array();
void register_packed_vector3_array();
void register_proxy_packed_vector3_array();
void register_packed_color_array();
void register_proxy_packed_color_array();
void register_packed_vector4_array();
void register_proxy_packed_vector4_array();

// Main function to orchestrate the registration of all built-in classes
void register_builtin_classes();

#endif // __REGISTER_BUILTIN_CLASSES_H__