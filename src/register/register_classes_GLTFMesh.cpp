#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/gltf_mesh.hpp>

using namespace godot;

void register_classes_GLTFMesh() {
    qjs::Context::Module &_module = _General;
    _module.class_<GLTFMesh>("GLTFMesh")
           .constructor<>()
           .property<GLTFMesh::get_mesh, GLTFMesh::set_mesh>("mesh")
           .property<GLTFMesh::get_blend_weights, GLTFMesh::set_blend_weights>("blend_weights")
           .property<GLTFMesh::get_instance_materials, GLTFMesh::set_instance_materials>("instance_materials")
;}