#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/navigation_agent3d.hpp>

using namespace godot;

void register_classes_NavigationAgent3D() {
    qjs::Context::Module &_module = _Node;
    _module.class_<NavigationAgent3D>("NavigationAgent3D")
           .constructor<>()
           .property<NavigationAgent3D::get_target_position, NavigationAgent3D::set_target_position>("target_position")
           .property<NavigationAgent3D::get_path_desired_distance, NavigationAgent3D::set_path_desired_distance>("path_desired_distance")
           .property<NavigationAgent3D::get_target_desired_distance, NavigationAgent3D::set_target_desired_distance>("target_desired_distance")
           .property<NavigationAgent3D::get_path_height_offset, NavigationAgent3D::set_path_height_offset>("path_height_offset")
           .property<NavigationAgent3D::get_path_max_distance, NavigationAgent3D::set_path_max_distance>("path_max_distance")
           .property<NavigationAgent3D::get_navigation_layers, NavigationAgent3D::set_navigation_layers>("navigation_layers")
           .property<NavigationAgent3D::get_pathfinding_algorithm, NavigationAgent3D::set_pathfinding_algorithm>("pathfinding_algorithm")
           .property<NavigationAgent3D::get_path_postprocessing, NavigationAgent3D::set_path_postprocessing>("path_postprocessing")
           .property<NavigationAgent3D::get_path_metadata_flags, NavigationAgent3D::set_path_metadata_flags>("path_metadata_flags")
           .property<NavigationAgent3D::get_avoidance_enabled, NavigationAgent3D::set_avoidance_enabled>("avoidance_enabled")
           .property<NavigationAgent3D::get_velocity, NavigationAgent3D::set_velocity>("velocity")
           .property<NavigationAgent3D::get_height, NavigationAgent3D::set_height>("height")
           .property<NavigationAgent3D::get_radius, NavigationAgent3D::set_radius>("radius")
           .property<NavigationAgent3D::get_neighbor_distance, NavigationAgent3D::set_neighbor_distance>("neighbor_distance")
           .property<NavigationAgent3D::get_max_neighbors, NavigationAgent3D::set_max_neighbors>("max_neighbors")
           .property<NavigationAgent3D::get_time_horizon_agents, NavigationAgent3D::set_time_horizon_agents>("time_horizon_agents")
           .property<NavigationAgent3D::get_time_horizon_obstacles, NavigationAgent3D::set_time_horizon_obstacles>("time_horizon_obstacles")
           .property<NavigationAgent3D::get_max_speed, NavigationAgent3D::set_max_speed>("max_speed")
           .property<NavigationAgent3D::get_use_3d_avoidance, NavigationAgent3D::set_use_3d_avoidance>("use_3d_avoidance")
           .property<NavigationAgent3D::get_keep_y_velocity, NavigationAgent3D::set_keep_y_velocity>("keep_y_velocity")
           .property<NavigationAgent3D::get_avoidance_layers, NavigationAgent3D::set_avoidance_layers>("avoidance_layers")
           .property<NavigationAgent3D::get_avoidance_mask, NavigationAgent3D::set_avoidance_mask>("avoidance_mask")
           .property<NavigationAgent3D::get_avoidance_priority, NavigationAgent3D::set_avoidance_priority>("avoidance_priority")
           .property<NavigationAgent3D::get_debug_enabled, NavigationAgent3D::set_debug_enabled>("debug_enabled")
           .property<NavigationAgent3D::get_debug_use_custom, NavigationAgent3D::set_debug_use_custom>("debug_use_custom")
           .property<NavigationAgent3D::get_debug_path_custom_color, NavigationAgent3D::set_debug_path_custom_color>("debug_path_custom_color")
           .property<NavigationAgent3D::get_debug_path_custom_point_size, NavigationAgent3D::set_debug_path_custom_point_size>("debug_path_custom_point_size")
		    .fun<static_cast<RID(NavigationAgent3D::*)()const>(&NavigationAgent3D::get_rid)>("get_rid")
		    .fun<static_cast<void(NavigationAgent3D::*)(int32_t,bool)>(&NavigationAgent3D::set_navigation_layer_value)>("set_navigation_layer_value")
		    .fun<static_cast<bool(NavigationAgent3D::*)(int32_t)const>(&NavigationAgent3D::get_navigation_layer_value)>("get_navigation_layer_value")
		    .fun<static_cast<void(NavigationAgent3D::*)(const RID &)>(&NavigationAgent3D::set_navigation_map)>("set_navigation_map")
		    .fun<static_cast<RID(NavigationAgent3D::*)()const>(&NavigationAgent3D::get_navigation_map)>("get_navigation_map")
		    .fun<static_cast<Vector3(NavigationAgent3D::*)()>(&NavigationAgent3D::get_next_path_position)>("get_next_path_position")
		    .fun<static_cast<void(NavigationAgent3D::*)(const Vector3 &)>(&NavigationAgent3D::set_velocity_forced)>("set_velocity_forced")
		    .fun<static_cast<double(NavigationAgent3D::*)()const>(&NavigationAgent3D::distance_to_target)>("distance_to_target")
		    .fun<static_cast<Ref<NavigationPathQueryResult3D>(NavigationAgent3D::*)()const>(&NavigationAgent3D::get_current_navigation_result)>("get_current_navigation_result")
		    .fun<static_cast<PackedVector3Array(NavigationAgent3D::*)()const>(&NavigationAgent3D::get_current_navigation_path)>("get_current_navigation_path")
		    .fun<static_cast<int32_t(NavigationAgent3D::*)()const>(&NavigationAgent3D::get_current_navigation_path_index)>("get_current_navigation_path_index")
		    .fun<static_cast<bool(NavigationAgent3D::*)()const>(&NavigationAgent3D::is_target_reached)>("is_target_reached")
		    .fun<static_cast<bool(NavigationAgent3D::*)()>(&NavigationAgent3D::is_target_reachable)>("is_target_reachable")
		    .fun<static_cast<bool(NavigationAgent3D::*)()>(&NavigationAgent3D::is_navigation_finished)>("is_navigation_finished")
		    .fun<static_cast<Vector3(NavigationAgent3D::*)()>(&NavigationAgent3D::get_final_position)>("get_final_position")
		    .fun<static_cast<void(NavigationAgent3D::*)(int32_t,bool)>(&NavigationAgent3D::set_avoidance_layer_value)>("set_avoidance_layer_value")
		    .fun<static_cast<bool(NavigationAgent3D::*)(int32_t)const>(&NavigationAgent3D::get_avoidance_layer_value)>("get_avoidance_layer_value")
		    .fun<static_cast<void(NavigationAgent3D::*)(int32_t,bool)>(&NavigationAgent3D::set_avoidance_mask_value)>("set_avoidance_mask_value")
		    .fun<static_cast<bool(NavigationAgent3D::*)(int32_t)const>(&NavigationAgent3D::get_avoidance_mask_value)>("get_avoidance_mask_value")
;}