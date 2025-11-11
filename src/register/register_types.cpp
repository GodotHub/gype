#include "register/register_types.h"
#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/classes/register_classes.hpp"
#include "register/utility_functions/register_utility_functions.hpp"
#include "support/module_loader.hpp"
#include "support/typescript.hpp"
#include "support/typescript_language.hpp"
#include "support/typescript_loader.hpp"
#include "support/typescript_saver.hpp"
#include "utils/env.hpp"
#include "utils/event_loop.hpp"
#include <quickjs-libc.h>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/resource_saver.hpp>
#include <utils/quickjs_helper.hpp>


using namespace godot;

void init_quickjs() {
	js_std_init_handlers(js_runtime());
	JS_SetModuleLoaderFunc(js_runtime(), NULL, module_loader, NULL);
	register_builtin_classes();
	register_classes();
	register_utility_functions();
}

void init_ts_support() {
	GDREGISTER_CLASS(TypeScriptLoader);
	GDREGISTER_CLASS(TypeScriptSaver);
	GDREGISTER_CLASS(TypeScriptLanguage);
	GDREGISTER_CLASS(TypeScript);
	Engine::get_singleton()->register_script_language(TypeScriptLanguage::get_singleton());
	ResourceSaver::get_singleton()->add_resource_format_saver(TypeScriptSaver::get_singleton());
	ResourceLoader::get_singleton()->add_resource_format_loader(TypeScriptLoader::get_singleton());
}

void initialize_gype_types(ModuleInitializationLevel p_level) {
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
		init_quickjs();
	}
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
		init_ts_support();
		GDREGISTER_CLASS(EventLoop);
	}
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_EDITOR) {
		GDREGISTER_CLASS(GypePlugin);
		EditorPlugins::add_by_type<GypePlugin>();
	}
}

void uninitialize_gype_types(godot::ModuleInitializationLevel p_level) {
	if (p_level == godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
		Engine::get_singleton()->unregister_script_language(TypeScriptLanguage::get_singleton());
		ResourceSaver::get_singleton()->remove_resource_format_saver(TypeScriptSaver::get_singleton());
		ResourceLoader::get_singleton()->remove_resource_format_loader(TypeScriptLoader::get_singleton());
		memdelete(TypeScriptLanguage::get_singleton());
		memdelete(TypeScriptSaver::get_singleton());
		memdelete(TypeScriptLoader::get_singleton());
	}
}

extern "C" {
GDExtensionBool GDE_EXPORT gype_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject initObj(p_get_proc_address, p_library, r_initialization);

	initObj.register_initializer(initialize_gype_types);
	initObj.register_terminator(uninitialize_gype_types);
	initObj.set_minimum_library_initialization_level(ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_EDITOR);

	return initObj.init();
}
}