#include "utils/str_helper.hpp"
#include <stddef.h>
#include <cctype>
#include <cstring>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <iostream>
#include <regex>
#include <godot_cpp/classes/reg_ex.hpp>
#include <godot_cpp/classes/reg_ex_match.hpp>

using namespace godot;

std::string underscoreToCamelCase(std::string input) {
	std::string output;
	bool capitalizeNext = false;

	for (char ch : input) {
		if (ch == '_') {
			// 下一个字符应该大写
			capitalizeNext = true;
		} else {
			if (capitalizeNext) {
				output += std::toupper(ch); // 将字符转换为大写
				capitalizeNext = false;
			} else {
				output += ch;
			}
		}
	}
	return output;
}

std::string camelToSnake(std::string input) {
	std::string result = input;

	// 处理连续的大写字母，例如 "HTTPRequestID" -> "HTTP_Request_ID"
	result = std::regex_replace(result, std::regex("(.)([A-Z][a-z]+)"), "$1_$2");

	// 处理驼峰命名，例如 "camelCase" -> "camel_Case"
	result = std::regex_replace(result, std::regex("([a-z0-9])([A-Z])"), "$1_$2");

	std::regex reg_2d("2_D");
	std::regex reg_3d("3_D");

	result = std::regex_replace(result, reg_2d, "2D");
	result = std::regex_replace(result, reg_3d, "3D");

	// 转换为全小写
	for (auto &c : result) {
		c = std::tolower(c);
	}

	return result;
}

const char *to_chars(const godot::String &input) {
	std::string str = std::string(input.utf8().get_data());
	char *chars = new char[str.size() * 4];
	strcpy(chars, str.c_str());
	return chars;
}

const char *to_chars(const godot::StringName &input) {
	std::string str = std::string(godot::String(input).utf8().get_data());
	char *chars = new char[str.size() * 4];
	strcpy(chars, str.c_str());
	return chars;
}

String add_cache_buster_to_code_gd(const String& code, const String& version) {
	if (version.is_empty()) {
		return code;
	}

	// 在路径后追加的查询字符串
	// 注意：在JS模块中，需要添加 .js 后缀才能让浏览器识别，并追加版本号
	String buster = "?v=" + version;

	// 正则表达式保持 v3 的版本，它本身是正确的
	String pattern = "(import[\\s\\S]*?from\\s*|export[^;]*?from\\s*|import\\s*\\()(['\"])([^'\"]+)(['\"])";
    
	Ref<RegEx> regex = RegEx::create_from_string(pattern);
	if (!regex.is_valid()) {
		return code;
	}

	String new_code = code;
	Array matches = regex->search_all(code);

	for (int i = matches.size() - 1; i >= 0; --i) {
		Ref<RegExMatch> match = matches[i];
		if (match.is_null()) {
			continue;
		}

		String path = match->get_string(3);

		// 【关键修正】
		// 重新定义判断逻辑：如果是一个项目内的路径，就应该处理它。
		// 项目内路径通常以 '.', '/', 'res://', 或别名 '@res/' 开头。
		bool is_project_path = path.begins_with(".") || path.begins_with("/") || path.begins_with("res://") || path.begins_with("@res/");

		// 如果它不是项目内路径，或者是外部URL，或者已经有版本号，则跳过
		if (!is_project_path || path.begins_with("http") || path.contains("?v=")) {
			continue;
		}

		// 完整地重新构建匹配
		String statement_part = match->get_string(1);
		String opening_quote = match->get_string(2);
		String closing_quote = match->get_string(4);
        
		// 构建新的、带版本号的路径。
		// 因为原始路径没有 .js，我们需要在这里加上它，然后再加上版本号。
		String new_path_with_buster = path + buster;
        
		String replacement = statement_part + opening_quote + new_path_with_buster + closing_quote;

		int start = match->get_start(0);
		int end = match->get_end(0);

		new_code = new_code.substr(0, start) + replacement + new_code.substr(end);
	}

	return new_code;
}
