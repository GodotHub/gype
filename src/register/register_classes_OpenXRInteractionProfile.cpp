#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/open_xr_interaction_profile.hpp>

using namespace godot;

void register_classes_OpenXRInteractionProfile() {
    qjs::Context::Module &_module = _General;
    _module.class_<OpenXRInteractionProfile>("OpenXRInteractionProfile")
           .constructor<>()
           .property<OpenXRInteractionProfile::get_interaction_profile_path, OpenXRInteractionProfile::set_interaction_profile_path>("interaction_profile_path")
           .property<OpenXRInteractionProfile::get_bindings, OpenXRInteractionProfile::set_bindings>("bindings")
		    .fun<static_cast<int32_t(OpenXRInteractionProfile::*)()const>(&OpenXRInteractionProfile::get_binding_count)>("get_binding_count")
		    .fun<static_cast<Ref<OpenXRIPBinding>(OpenXRInteractionProfile::*)(int32_t)const>(&OpenXRInteractionProfile::get_binding)>("get_binding")
;}