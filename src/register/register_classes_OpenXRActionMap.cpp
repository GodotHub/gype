#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/open_xr_action_map.hpp>

using namespace godot;

void register_classes_OpenXRActionMap() {
    qjs::Context::Module &_module = _General;
    _module.class_<OpenXRActionMap>("OpenXRActionMap")
           .constructor<>()
           .property<OpenXRActionMap::get_action_sets, OpenXRActionMap::set_action_sets>("action_sets")
           .property<OpenXRActionMap::get_interaction_profiles, OpenXRActionMap::set_interaction_profiles>("interaction_profiles")
		    .fun<static_cast<int32_t(OpenXRActionMap::*)()const>(&OpenXRActionMap::get_action_set_count)>("get_action_set_count")
		    .fun<static_cast<Ref<OpenXRActionSet>(OpenXRActionMap::*)(const String &)const>(&OpenXRActionMap::find_action_set)>("find_action_set")
		    .fun<static_cast<Ref<OpenXRActionSet>(OpenXRActionMap::*)(int32_t)const>(&OpenXRActionMap::get_action_set)>("get_action_set")
		    .fun<static_cast<void(OpenXRActionMap::*)(const Ref<OpenXRActionSet> &)>(&OpenXRActionMap::add_action_set)>("add_action_set")
		    .fun<static_cast<void(OpenXRActionMap::*)(const Ref<OpenXRActionSet> &)>(&OpenXRActionMap::remove_action_set)>("remove_action_set")
		    .fun<static_cast<int32_t(OpenXRActionMap::*)()const>(&OpenXRActionMap::get_interaction_profile_count)>("get_interaction_profile_count")
		    .fun<static_cast<Ref<OpenXRInteractionProfile>(OpenXRActionMap::*)(const String &)const>(&OpenXRActionMap::find_interaction_profile)>("find_interaction_profile")
		    .fun<static_cast<Ref<OpenXRInteractionProfile>(OpenXRActionMap::*)(int32_t)const>(&OpenXRActionMap::get_interaction_profile)>("get_interaction_profile")
		    .fun<static_cast<void(OpenXRActionMap::*)(const Ref<OpenXRInteractionProfile> &)>(&OpenXRActionMap::add_interaction_profile)>("add_interaction_profile")
		    .fun<static_cast<void(OpenXRActionMap::*)(const Ref<OpenXRInteractionProfile> &)>(&OpenXRActionMap::remove_interaction_profile)>("remove_interaction_profile")
		    .fun<static_cast<void(OpenXRActionMap::*)()>(&OpenXRActionMap::create_default_action_sets)>("create_default_action_sets")
;}