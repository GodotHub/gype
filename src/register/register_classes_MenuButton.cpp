#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/menu_button.hpp>

using namespace godot;

void register_classes_MenuButton() {
    qjs::Context::Module &_module = _Control;
    _module.class_<MenuButton>("MenuButton")
           .constructor<>()
           .property<MenuButton::is_switch_on_hover, MenuButton::set_switch_on_hover>("switch_on_hover")
           .property<MenuButton::get_item_count, MenuButton::set_item_count>("item_count")
		    .fun<static_cast<PopupMenu *(MenuButton::*)()const>(&MenuButton::get_popup)>("get_popup")
		    .fun<static_cast<void(MenuButton::*)()>(&MenuButton::show_popup)>("show_popup")
		    .fun<static_cast<void(MenuButton::*)(bool)>(&MenuButton::set_disable_shortcuts)>("set_disable_shortcuts")
;}