#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/skeleton_modification2dccdik.hpp>

using namespace godot;

void register_classes_SkeletonModification2DCCDIK() {
    qjs::Context::Module &_module = _General;
    _module.class_<SkeletonModification2DCCDIK>("SkeletonModification2DCCDIK")
           .constructor<>()
           .property<SkeletonModification2DCCDIK::get_target_node, SkeletonModification2DCCDIK::set_target_node>("target_nodepath")
           .property<SkeletonModification2DCCDIK::get_tip_node, SkeletonModification2DCCDIK::set_tip_node>("tip_nodepath")
           .property<SkeletonModification2DCCDIK::get_ccdik_data_chain_length, SkeletonModification2DCCDIK::set_ccdik_data_chain_length>("ccdik_data_chain_length")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,const NodePath &)>(&SkeletonModification2DCCDIK::set_ccdik_joint_bone2d_node)>("set_ccdik_joint_bone2d_node")
		    .fun<static_cast<NodePath(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_bone2d_node)>("get_ccdik_joint_bone2d_node")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,int32_t)>(&SkeletonModification2DCCDIK::set_ccdik_joint_bone_index)>("set_ccdik_joint_bone_index")
		    .fun<static_cast<int32_t(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_bone_index)>("get_ccdik_joint_bone_index")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,bool)>(&SkeletonModification2DCCDIK::set_ccdik_joint_rotate_from_joint)>("set_ccdik_joint_rotate_from_joint")
		    .fun<static_cast<bool(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_rotate_from_joint)>("get_ccdik_joint_rotate_from_joint")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,bool)>(&SkeletonModification2DCCDIK::set_ccdik_joint_enable_constraint)>("set_ccdik_joint_enable_constraint")
		    .fun<static_cast<bool(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_enable_constraint)>("get_ccdik_joint_enable_constraint")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,double)>(&SkeletonModification2DCCDIK::set_ccdik_joint_constraint_angle_min)>("set_ccdik_joint_constraint_angle_min")
		    .fun<static_cast<double(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_constraint_angle_min)>("get_ccdik_joint_constraint_angle_min")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,double)>(&SkeletonModification2DCCDIK::set_ccdik_joint_constraint_angle_max)>("set_ccdik_joint_constraint_angle_max")
		    .fun<static_cast<double(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_constraint_angle_max)>("get_ccdik_joint_constraint_angle_max")
		    .fun<static_cast<void(SkeletonModification2DCCDIK::*)(int32_t,bool)>(&SkeletonModification2DCCDIK::set_ccdik_joint_constraint_angle_invert)>("set_ccdik_joint_constraint_angle_invert")
		    .fun<static_cast<bool(SkeletonModification2DCCDIK::*)(int32_t)const>(&SkeletonModification2DCCDIK::get_ccdik_joint_constraint_angle_invert)>("get_ccdik_joint_constraint_angle_invert")
;}