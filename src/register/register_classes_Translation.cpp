#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/translation.hpp>

using namespace godot;

void register_classes_Translation() {
    qjs::Context::Module &_module = _General;
    _module.class_<Translation>("Translation")
           .constructor<>()
           .property<Translation::_get_messages, Translation::_set_messages>("messages")
           .property<Translation::get_locale, Translation::set_locale>("locale")
		    .fun<static_cast<StringName(Translation::*)(const StringName &,const StringName &,int32_t,const StringName &)const>(&Translation::_get_plural_message)>("_get_plural_message")
		    .fun<static_cast<StringName(Translation::*)(const StringName &,const StringName &)const>(&Translation::_get_message)>("_get_message")
		    .fun<static_cast<void(Translation::*)(const StringName &,const StringName &,const StringName &)>(&Translation::add_message)>("add_message")
		    .fun<static_cast<void(Translation::*)(const StringName &,const PackedStringArray &,const StringName &)>(&Translation::add_plural_message)>("add_plural_message")
		    .fun<static_cast<StringName(Translation::*)(const StringName &,const StringName &)const>(&Translation::get_message)>("get_message")
		    .fun<static_cast<StringName(Translation::*)(const StringName &,const StringName &,int32_t,const StringName &)const>(&Translation::get_plural_message)>("get_plural_message")
		    .fun<static_cast<void(Translation::*)(const StringName &,const StringName &)>(&Translation::erase_message)>("erase_message")
		    .fun<static_cast<PackedStringArray(Translation::*)()const>(&Translation::get_message_list)>("get_message_list")
		    .fun<static_cast<PackedStringArray(Translation::*)()const>(&Translation::get_translated_message_list)>("get_translated_message_list")
		    .fun<static_cast<int32_t(Translation::*)()const>(&Translation::get_message_count)>("get_message_count")
;}