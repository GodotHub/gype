#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/encoded_object_as_id.hpp>

using namespace godot;

void register_classes_EncodedObjectAsID() {
    qjs::Context::Module &_module = _General;
    _module.class_<EncodedObjectAsID>("EncodedObjectAsID")
           .constructor<>()
           .property<EncodedObjectAsID::get_object_id, EncodedObjectAsID::set_object_id>("object_id")
;}