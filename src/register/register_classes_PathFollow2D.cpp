#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/path_follow2d.hpp>

using namespace godot;

void register_classes_PathFollow2D() {
    qjs::Context::Module &_module = _Node2D;
    _module.class_<PathFollow2D>("PathFollow2D")
           .constructor<>()
           .property<PathFollow2D::get_progress, PathFollow2D::set_progress>("progress")
           .property<PathFollow2D::get_progress_ratio, PathFollow2D::set_progress_ratio>("progress_ratio")
           .property<PathFollow2D::get_h_offset, PathFollow2D::set_h_offset>("h_offset")
           .property<PathFollow2D::get_v_offset, PathFollow2D::set_v_offset>("v_offset")
           .property<PathFollow2D::is_rotating, PathFollow2D::set_rotates>("rotates")
           .property<PathFollow2D::get_cubic_interpolation, PathFollow2D::set_cubic_interpolation>("cubic_interp")
           .property<PathFollow2D::has_loop, PathFollow2D::set_loop>("loop")
;}