#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/script_create_dialog.hpp>

using namespace godot;

void register_classes_ScriptCreateDialog() {
    qjs::Context::Module &_module = _Node;
    _module.class_<ScriptCreateDialog>("ScriptCreateDialog")
           .constructor<>()
		    .fun<static_cast<void(ScriptCreateDialog::*)(const String &,const String &,bool,bool)>(&ScriptCreateDialog::config)>("config")
;}