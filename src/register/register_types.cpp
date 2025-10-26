#include "register/register_types.h"
#include "utils/env.hpp"
#include <godot_cpp/variant/utility_functions.hpp>
#include "register/utility_functions/register_utility_functions.hpp"

using namespace godot;

void init_quickjs() {
}

void init_ts_support() {
}

void initialize_gype_types(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SERVERS) {
		return;
	}
	UtilityFunctions::print("Quickjs start initialization");
	init_quickjs();
	init_ts_support();
	UtilityFunctions::print("Quickjs initialization is over");
}

void uninitialize_gype_types(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SERVERS) {
		return;
	}
}

extern "C" {

GDExtensionBool GDE_EXPORT gype_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject initObj(p_get_proc_address, p_library, r_initialization);

	initObj.register_initializer(initialize_gype_types);
	initObj.register_terminator(uninitialize_gype_types);
	initObj.set_minimum_library_initialization_level(godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SERVERS);

	return initObj.init();
}
}