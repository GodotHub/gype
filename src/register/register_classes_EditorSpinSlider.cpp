#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/editor_spin_slider.hpp>

using namespace godot;

void register_classes_EditorSpinSlider() {
    qjs::Context::Module &_module = _Control;
    _module.class_<EditorSpinSlider>("EditorSpinSlider")
           .constructor<>()
           .property<EditorSpinSlider::get_label, EditorSpinSlider::set_label>("label")
           .property<EditorSpinSlider::get_suffix, EditorSpinSlider::set_suffix>("suffix")
           .property<EditorSpinSlider::is_read_only, EditorSpinSlider::set_read_only>("read_only")
           .property<EditorSpinSlider::is_flat, EditorSpinSlider::set_flat>("flat")
           .property<EditorSpinSlider::is_hiding_slider, EditorSpinSlider::set_hide_slider>("hide_slider")
;}