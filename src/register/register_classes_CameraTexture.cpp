#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/camera_texture.hpp>

using namespace godot;

void register_classes_CameraTexture() {
    qjs::Context::Module &_module = _General;
    _module.class_<CameraTexture>("CameraTexture")
           .constructor<>()
           .property<CameraTexture::get_camera_feed_id, CameraTexture::set_camera_feed_id>("camera_feed_id")
           .property<CameraTexture::get_which_feed, CameraTexture::set_which_feed>("which_feed")
           .property<CameraTexture::get_camera_active, CameraTexture::set_camera_active>("camera_is_active")
;}