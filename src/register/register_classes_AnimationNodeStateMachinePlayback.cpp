#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/animation_node_state_machine_playback.hpp>

using namespace godot;

void register_classes_AnimationNodeStateMachinePlayback() {
    qjs::Context::Module &_module = _General;
    _module.class_<AnimationNodeStateMachinePlayback>("AnimationNodeStateMachinePlayback")
           .constructor<>()
		    .fun<static_cast<void(AnimationNodeStateMachinePlayback::*)(const StringName &,bool)>(&AnimationNodeStateMachinePlayback::travel)>("travel")
		    .fun<static_cast<void(AnimationNodeStateMachinePlayback::*)(const StringName &,bool)>(&AnimationNodeStateMachinePlayback::start)>("start")
		    .fun<static_cast<void(AnimationNodeStateMachinePlayback::*)()>(&AnimationNodeStateMachinePlayback::next)>("next")
		    .fun<static_cast<void(AnimationNodeStateMachinePlayback::*)()>(&AnimationNodeStateMachinePlayback::stop)>("stop")
		    .fun<static_cast<bool(AnimationNodeStateMachinePlayback::*)()const>(&AnimationNodeStateMachinePlayback::is_playing)>("is_playing")
		    .fun<static_cast<StringName(AnimationNodeStateMachinePlayback::*)()const>(&AnimationNodeStateMachinePlayback::get_current_node)>("get_current_node")
		    .fun<static_cast<double(AnimationNodeStateMachinePlayback::*)()const>(&AnimationNodeStateMachinePlayback::get_current_play_position)>("get_current_play_position")
		    .fun<static_cast<double(AnimationNodeStateMachinePlayback::*)()const>(&AnimationNodeStateMachinePlayback::get_current_length)>("get_current_length")
		    .fun<static_cast<StringName(AnimationNodeStateMachinePlayback::*)()const>(&AnimationNodeStateMachinePlayback::get_fading_from_node)>("get_fading_from_node")
		    .fun<static_cast<TypedArray<StringName>(AnimationNodeStateMachinePlayback::*)()const>(&AnimationNodeStateMachinePlayback::get_travel_path)>("get_travel_path")
;}