#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/semaphore.hpp>

using namespace godot;

void register_classes_Semaphore() {
    qjs::Context::Module &_module = _General;
    _module.class_<Semaphore>("Semaphore")
           .constructor<>()
		    .fun<static_cast<void(Semaphore::*)()>(&Semaphore::wait)>("wait")
		    .fun<static_cast<bool(Semaphore::*)()>(&Semaphore::try_wait)>("try_wait")
		    .fun<static_cast<void(Semaphore::*)()>(&Semaphore::post)>("post")
;}