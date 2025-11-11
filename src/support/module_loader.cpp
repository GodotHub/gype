#include "support/module_loader.hpp"
#include "support/typescript.hpp"

#include <quickjs-libc.h>
#include <quickjs.h>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/string.hpp>
#include <string>

using namespace godot;

static JSModuleDef *script_loader(JSContext *ctx, const char *module_name) {
	char filepath[1024];
	sprintf(filepath, "%s.js", module_name);

	String path(filepath);
	if (path.begins_with("@res")) {
		path = path.replace("@res", "res://");
	} else if (path.begins_with("@godot/core")) {
		char p[128];
		sprintf(p, "%saddons/gype/godot", TypeScript::dist_path);
		path = path.replace("@godot", p);
	}

	Ref<TypeScript> script = ResourceLoader::get_singleton()->load(path);
	if (script.is_null()) {
		return NULL;
	}

	String code = script->_get_source_code();
	std::string code_str = code.utf8().get_data();
	const char *buf = code_str.c_str();
	size_t buf_len = strlen(buf);

	// 编译模块
	JSValue func_val;
	func_val = JS_Eval(ctx, (char *)buf, buf_len, module_name, JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);
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
	if (StringName(module_name).begins_with("qjs:")) {
		static JSModuleDef *os_module = js_init_module_os(ctx, "qjs:os");
		return os_module;
	} else if (StringName(module_name).begins_with("@godot/classes")) {
		return NULL;
	} else {
		return script_loader(ctx, module_name);
	}
}