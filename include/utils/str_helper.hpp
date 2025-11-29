#ifndef __STR_HELPER_H__
#define __STR_HELPER_H__

#include <string>
#include <godot_cpp/variant/string.hpp>

namespace godot {

class String;
class StringName;
} //namespace godot

std::string underscoreToCamelCase(std::string input);
std::string camelToSnake(std::string input);
const char *to_chars(const godot::String &input);
const char *to_chars(const godot::StringName &input);
godot::String add_cache_buster_to_code_gd(const godot::String& code, const godot::String& version);

#endif // __STR_HELPER_H__