#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/editor_import_plugin.hpp>

using namespace godot;

void register_classes_EditorImportPlugin() {
    qjs::Context::Module &_module = _General;
    _module.class_<EditorImportPlugin>("EditorImportPlugin")
           .constructor<>()
		    .fun<static_cast<String(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_importer_name)>("_get_importer_name")
		    .fun<static_cast<String(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_visible_name)>("_get_visible_name")
		    .fun<static_cast<int32_t(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_preset_count)>("_get_preset_count")
		    .fun<static_cast<String(EditorImportPlugin::*)(int32_t)const>(&EditorImportPlugin::_get_preset_name)>("_get_preset_name")
		    .fun<static_cast<PackedStringArray(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_recognized_extensions)>("_get_recognized_extensions")
		    .fun<static_cast<TypedArray<Dictionary>(EditorImportPlugin::*)(const String &,int32_t)const>(&EditorImportPlugin::_get_import_options)>("_get_import_options")
		    .fun<static_cast<String(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_save_extension)>("_get_save_extension")
		    .fun<static_cast<String(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_resource_type)>("_get_resource_type")
		    .fun<static_cast<double(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_priority)>("_get_priority")
		    .fun<static_cast<int32_t(EditorImportPlugin::*)()const>(&EditorImportPlugin::_get_import_order)>("_get_import_order")
		    .fun<static_cast<bool(EditorImportPlugin::*)(const String &,const StringName &,const Dictionary &)const>(&EditorImportPlugin::_get_option_visibility)>("_get_option_visibility")
		    .fun<static_cast<Error(EditorImportPlugin::*)(const String &,const String &,const Dictionary &,const TypedArray<String> &,const TypedArray<String> &)const>(&EditorImportPlugin::_import)>("_import")
		    .fun<static_cast<Error(EditorImportPlugin::*)(const String &,const Dictionary &,const String &,const Variant &)>(&EditorImportPlugin::append_import_external_resource)>("append_import_external_resource")
;}