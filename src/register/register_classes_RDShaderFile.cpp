#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/rd_shader_file.hpp>

using namespace godot;

void register_classes_RDShaderFile() {
    qjs::Context::Module &_module = _General;
    _module.class_<RDShaderFile>("RDShaderFile")
           .constructor<>()
           .property<RDShaderFile::get_base_error, RDShaderFile::set_base_error>("base_error")
		    .fun<static_cast<void(RDShaderFile::*)(const Ref<RDShaderSPIRV> &,const StringName &)>(&RDShaderFile::set_bytecode)>("set_bytecode")
		    .fun<static_cast<Ref<RDShaderSPIRV>(RDShaderFile::*)(const StringName &)const>(&RDShaderFile::get_spirv)>("get_spirv")
		    .fun<static_cast<TypedArray<StringName>(RDShaderFile::*)()const>(&RDShaderFile::get_version_list)>("get_version_list")
;}