#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/cylinder_mesh.hpp>

using namespace godot;

void register_classes_CylinderMesh() {
    qjs::Context::Module &_module = _General;
    _module.class_<CylinderMesh>("CylinderMesh")
           .constructor<>()
           .property<CylinderMesh::get_top_radius, CylinderMesh::set_top_radius>("top_radius")
           .property<CylinderMesh::get_bottom_radius, CylinderMesh::set_bottom_radius>("bottom_radius")
           .property<CylinderMesh::get_height, CylinderMesh::set_height>("height")
           .property<CylinderMesh::get_radial_segments, CylinderMesh::set_radial_segments>("radial_segments")
           .property<CylinderMesh::get_rings, CylinderMesh::set_rings>("rings")
           .property<CylinderMesh::is_cap_top, CylinderMesh::set_cap_top>("cap_top")
           .property<CylinderMesh::is_cap_bottom, CylinderMesh::set_cap_bottom>("cap_bottom")
;}