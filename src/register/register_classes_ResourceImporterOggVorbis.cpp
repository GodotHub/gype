#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/resource_importer_ogg_vorbis.hpp>

using namespace godot;

void register_classes_ResourceImporterOggVorbis() {
    qjs::Context::Module &_module = _General;
    _module.class_<ResourceImporterOggVorbis>("ResourceImporterOggVorbis")
           .constructor<>()
            .static_fun<ResourceImporterOggVorbis::load_from_buffer>("load_from_buffer")
            .static_fun<ResourceImporterOggVorbis::load_from_file>("load_from_file")
;}