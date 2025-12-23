#include "support/module_loader.hpp"

#include "godot_cpp/classes/dir_access.hpp"
#include "godot_cpp/classes/file_access.hpp"
#include "support/typescript.hpp"

#include <quickjs-libc.h>
#include <quickjs.h>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/string.hpp>
#include <string>
#include <utils/str_helper.hpp>

using namespace godot;

char *module_normalize(JSContext *ctx,
		const char *module_base_name,
		const char *module_name, void *opaque) {
	String gd_module_name = module_name;
	if (gd_module_name.begins_with("@res") && !gd_module_name.contains("?v=")) {
		gd_module_name = gd_module_name + "?v=" + std::to_string(UtilityFunctions::randi()).c_str();
		module_name = to_chars(gd_module_name);
	}
	return strdup(module_name);
}

JSModuleDef *script_loader(JSContext *ctx, const char *module_name) {
	String gd_module_name = module_name;
	if (gd_module_name.contains("?v=")) {
		module_name = to_chars(gd_module_name.split("?")[0]);
	}

	char filepath[1024];
	sprintf(filepath, "%s.js", module_name);

	String path(filepath);
	char p[128];
	if (path.begins_with("@res")) {
		path = path.replace("@res", TypeScript::dist_path);
	} else if (path.begins_with("@godot/core")) {
		sprintf(p, "%saddons/gype/godot", TypeScript::dist_path);
		path = path.replace("@godot", p);
	}

	Ref<TypeScript> script = ResourceLoader::get_singleton()->load(path);
	script->reload();
	if (script.is_null()) {
		return NULL;
	}
	
	String code = script->_get_source_code();
	std::string code_str = code.utf8().get_data();
	const char *buf = code_str.c_str();
	size_t buf_len = strlen(buf);

	JSValue func_val = JS_Eval(ctx, (char *)buf, buf_len, module_name, JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);
	if (JS_IsException(func_val)) {
		JS_FreeValue(ctx, func_val);
		return NULL;
	}

	// 获取模块定义
	JSModuleDef *m = (JSModuleDef *)JS_VALUE_GET_PTR(func_val);
	JS_FreeValue(ctx, func_val);
	return m;
}

JSModuleDef *module_loader(JSContext *ctx, const char *module_name, void *opaque) {
	if (StringName(module_name).begins_with("@godot/classes")) {
		return NULL;
	} else {
		return script_loader(ctx, module_name);
	}
}