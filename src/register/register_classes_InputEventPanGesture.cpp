#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/input_event_pan_gesture.hpp>

using namespace godot;

void register_classes_InputEventPanGesture() {
    qjs::Context::Module &_module = _General;
    _module.class_<InputEventPanGesture>("InputEventPanGesture")
           .constructor<>()
           .property<InputEventPanGesture::get_delta, InputEventPanGesture::set_delta>("delta")
;}