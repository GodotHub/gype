#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/string_name.hpp>

using namespace godot;

static void string_name_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StringName"];
	StringName *opaque_ptr = static_cast<StringName *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef string_name_class_def = {
	"StringName",
	.finalizer = string_name_class_finalizer
};

static JSValue string_name_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["StringName"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	StringName *instance = nullptr;	if (argc == 0) {
		instance = memnew(StringName());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::STRING_NAME) {
		StringName v0 = VariantAdapter(argv[0]).get<StringName>();
		instance = memnew(StringName(v0));
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::STRING) {
		String v0 = VariantAdapter(argv[0]).get<String>();
		instance = memnew(StringName(v0));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
	return obj;
}
static JSValue string_name_class_casecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::casecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_name_class_nocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::nocasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_name_class_naturalcasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::naturalcasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_name_class_naturalnocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::naturalnocasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_name_class_filecasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::filecasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_name_class_filenocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::filenocasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_name_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::length, ctx, this_val, argc, argv);
}
static JSValue string_name_class_substr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::substr, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_slice, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_slicec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_slicec, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_slice_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_slice_count, ctx, this_val, argc, argv);
}
static JSValue string_name_class_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::find, ctx, this_val, argc, argv);
}
static JSValue string_name_class_findn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::findn, ctx, this_val, argc, argv);
}
static JSValue string_name_class_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::count, ctx, this_val, argc, argv);
}
static JSValue string_name_class_countn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::countn, ctx, this_val, argc, argv);
}
static JSValue string_name_class_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::rfind, ctx, this_val, argc, argv);
}
static JSValue string_name_class_rfindn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::rfindn, ctx, this_val, argc, argv);
}
static JSValue string_name_class_match(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::match, ctx, this_val, argc, argv);
}
static JSValue string_name_class_matchn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::matchn, ctx, this_val, argc, argv);
}
static JSValue string_name_class_begins_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::begins_with, ctx, this_val, argc, argv);
}
static JSValue string_name_class_ends_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::ends_with, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_subsequence_of(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_subsequence_of, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_subsequence_ofn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_subsequence_ofn, ctx, this_val, argc, argv);
}
static JSValue string_name_class_bigrams(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::bigrams, ctx, this_val, argc, argv);
}
static JSValue string_name_class_similarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::similarity, ctx, this_val, argc, argv);
}
static JSValue string_name_class_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::format, ctx, this_val, argc, argv);
}
static JSValue string_name_class_replace(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::replace, ctx, this_val, argc, argv);
}
static JSValue string_name_class_replacen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::replacen, ctx, this_val, argc, argv);
}
static JSValue string_name_class_replace_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::replace_char, ctx, this_val, argc, argv);
}
static JSValue string_name_class_replace_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::replace_chars, ctx, this_val, argc, argv);
}
static JSValue string_name_class_remove_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::remove_char, ctx, this_val, argc, argv);
}
static JSValue string_name_class_remove_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::remove_chars, ctx, this_val, argc, argv);
}
static JSValue string_name_class_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::repeat, ctx, this_val, argc, argv);
}
static JSValue string_name_class_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::reverse, ctx, this_val, argc, argv);
}
static JSValue string_name_class_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::insert, ctx, this_val, argc, argv);
}
static JSValue string_name_class_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::erase, ctx, this_val, argc, argv);
}
static JSValue string_name_class_capitalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::capitalize, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_camel_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_camel_case, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_pascal_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_pascal_case, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_snake_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_snake_case, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_kebab_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_kebab_case, ctx, this_val, argc, argv);
}
static JSValue string_name_class_split(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::split, ctx, this_val, argc, argv);
}
static JSValue string_name_class_rsplit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::rsplit, ctx, this_val, argc, argv);
}
static JSValue string_name_class_split_floats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::split_floats, ctx, this_val, argc, argv);
}
static JSValue string_name_class_join(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::join, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_upper(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_upper, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_lower(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_lower, ctx, this_val, argc, argv);
}
static JSValue string_name_class_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::left, ctx, this_val, argc, argv);
}
static JSValue string_name_class_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::right, ctx, this_val, argc, argv);
}
static JSValue string_name_class_strip_edges(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::strip_edges, ctx, this_val, argc, argv);
}
static JSValue string_name_class_strip_escapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::strip_escapes, ctx, this_val, argc, argv);
}
static JSValue string_name_class_lstrip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::lstrip, ctx, this_val, argc, argv);
}
static JSValue string_name_class_rstrip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::rstrip, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_extension, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_basename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_basename, ctx, this_val, argc, argv);
}
static JSValue string_name_class_path_join(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::path_join, ctx, this_val, argc, argv);
}
static JSValue string_name_class_unicode_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::unicode_at, ctx, this_val, argc, argv);
}
static JSValue string_name_class_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::indent, ctx, this_val, argc, argv);
}
static JSValue string_name_class_dedent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::dedent, ctx, this_val, argc, argv);
}
static JSValue string_name_class_md5_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::md5_text, ctx, this_val, argc, argv);
}
static JSValue string_name_class_sha1_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::sha1_text, ctx, this_val, argc, argv);
}
static JSValue string_name_class_sha256_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::sha256_text, ctx, this_val, argc, argv);
}
static JSValue string_name_class_md5_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::md5_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_sha1_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::sha1_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_sha256_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::sha256_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_empty, ctx, this_val, argc, argv);
}
static JSValue string_name_class_contains(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::contains, ctx, this_val, argc, argv);
}
static JSValue string_name_class_containsn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::containsn, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_absolute_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_absolute_path, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_relative_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_relative_path, ctx, this_val, argc, argv);
}
static JSValue string_name_class_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::simplify_path, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_base_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_base_dir, ctx, this_val, argc, argv);
}
static JSValue string_name_class_get_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::get_file, ctx, this_val, argc, argv);
}
static JSValue string_name_class_xml_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::xml_escape, ctx, this_val, argc, argv);
}
static JSValue string_name_class_xml_unescape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::xml_unescape, ctx, this_val, argc, argv);
}
static JSValue string_name_class_uri_encode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::uri_encode, ctx, this_val, argc, argv);
}
static JSValue string_name_class_uri_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::uri_decode, ctx, this_val, argc, argv);
}
static JSValue string_name_class_uri_file_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::uri_file_decode, ctx, this_val, argc, argv);
}
static JSValue string_name_class_c_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::c_escape, ctx, this_val, argc, argv);
}
static JSValue string_name_class_c_unescape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::c_unescape, ctx, this_val, argc, argv);
}
static JSValue string_name_class_json_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::json_escape, ctx, this_val, argc, argv);
}
static JSValue string_name_class_validate_node_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::validate_node_name, ctx, this_val, argc, argv);
}
static JSValue string_name_class_validate_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::validate_filename, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_ascii_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_ascii_identifier, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_unicode_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_unicode_identifier, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_identifier, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_int, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_float, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_hex_number(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_hex_number, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_html_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_html_color, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_ip_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_ip_address, ctx, this_val, argc, argv);
}
static JSValue string_name_class_is_valid_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::is_valid_filename, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_int, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_float, ctx, this_val, argc, argv);
}
static JSValue string_name_class_hex_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::hex_to_int, ctx, this_val, argc, argv);
}
static JSValue string_name_class_bin_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::bin_to_int, ctx, this_val, argc, argv);
}
static JSValue string_name_class_lpad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::lpad, ctx, this_val, argc, argv);
}
static JSValue string_name_class_rpad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::rpad, ctx, this_val, argc, argv);
}
static JSValue string_name_class_pad_decimals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::pad_decimals, ctx, this_val, argc, argv);
}
static JSValue string_name_class_pad_zeros(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::pad_zeros, ctx, this_val, argc, argv);
}
static JSValue string_name_class_trim_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::trim_prefix, ctx, this_val, argc, argv);
}
static JSValue string_name_class_trim_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::trim_suffix, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_ascii_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_ascii_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_utf8_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_utf8_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_utf16_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_utf16_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_utf32_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_utf32_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_wchar_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_wchar_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_to_multibyte_char_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::to_multibyte_char_buffer, ctx, this_val, argc, argv);
}
static JSValue string_name_class_hex_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::hex_decode, ctx, this_val, argc, argv);
}
static JSValue string_name_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&StringName::hash, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry string_name_class_proto_funcs[] = {
	JS_CFUNC_DEF("casecmp_to", 1, &string_name_class_casecmp_to),
	JS_CFUNC_DEF("nocasecmp_to", 1, &string_name_class_nocasecmp_to),
	JS_CFUNC_DEF("naturalcasecmp_to", 1, &string_name_class_naturalcasecmp_to),
	JS_CFUNC_DEF("naturalnocasecmp_to", 1, &string_name_class_naturalnocasecmp_to),
	JS_CFUNC_DEF("filecasecmp_to", 1, &string_name_class_filecasecmp_to),
	JS_CFUNC_DEF("filenocasecmp_to", 1, &string_name_class_filenocasecmp_to),
	JS_CFUNC_DEF("length", 0, &string_name_class_length),
	JS_CFUNC_DEF("substr", 2, &string_name_class_substr),
	JS_CFUNC_DEF("get_slice", 2, &string_name_class_get_slice),
	JS_CFUNC_DEF("get_slicec", 2, &string_name_class_get_slicec),
	JS_CFUNC_DEF("get_slice_count", 1, &string_name_class_get_slice_count),
	JS_CFUNC_DEF("find", 2, &string_name_class_find),
	JS_CFUNC_DEF("findn", 2, &string_name_class_findn),
	JS_CFUNC_DEF("count", 3, &string_name_class_count),
	JS_CFUNC_DEF("countn", 3, &string_name_class_countn),
	JS_CFUNC_DEF("rfind", 2, &string_name_class_rfind),
	JS_CFUNC_DEF("rfindn", 2, &string_name_class_rfindn),
	JS_CFUNC_DEF("match", 1, &string_name_class_match),
	JS_CFUNC_DEF("matchn", 1, &string_name_class_matchn),
	JS_CFUNC_DEF("begins_with", 1, &string_name_class_begins_with),
	JS_CFUNC_DEF("ends_with", 1, &string_name_class_ends_with),
	JS_CFUNC_DEF("is_subsequence_of", 1, &string_name_class_is_subsequence_of),
	JS_CFUNC_DEF("is_subsequence_ofn", 1, &string_name_class_is_subsequence_ofn),
	JS_CFUNC_DEF("bigrams", 0, &string_name_class_bigrams),
	JS_CFUNC_DEF("similarity", 1, &string_name_class_similarity),
	JS_CFUNC_DEF("format", 2, &string_name_class_format),
	JS_CFUNC_DEF("replace", 2, &string_name_class_replace),
	JS_CFUNC_DEF("replacen", 2, &string_name_class_replacen),
	JS_CFUNC_DEF("replace_char", 2, &string_name_class_replace_char),
	JS_CFUNC_DEF("replace_chars", 2, &string_name_class_replace_chars),
	JS_CFUNC_DEF("remove_char", 1, &string_name_class_remove_char),
	JS_CFUNC_DEF("remove_chars", 1, &string_name_class_remove_chars),
	JS_CFUNC_DEF("repeat", 1, &string_name_class_repeat),
	JS_CFUNC_DEF("reverse", 0, &string_name_class_reverse),
	JS_CFUNC_DEF("insert", 2, &string_name_class_insert),
	JS_CFUNC_DEF("erase", 2, &string_name_class_erase),
	JS_CFUNC_DEF("capitalize", 0, &string_name_class_capitalize),
	JS_CFUNC_DEF("to_camel_case", 0, &string_name_class_to_camel_case),
	JS_CFUNC_DEF("to_pascal_case", 0, &string_name_class_to_pascal_case),
	JS_CFUNC_DEF("to_snake_case", 0, &string_name_class_to_snake_case),
	JS_CFUNC_DEF("to_kebab_case", 0, &string_name_class_to_kebab_case),
	JS_CFUNC_DEF("split", 3, &string_name_class_split),
	JS_CFUNC_DEF("rsplit", 3, &string_name_class_rsplit),
	JS_CFUNC_DEF("split_floats", 2, &string_name_class_split_floats),
	JS_CFUNC_DEF("join", 1, &string_name_class_join),
	JS_CFUNC_DEF("to_upper", 0, &string_name_class_to_upper),
	JS_CFUNC_DEF("to_lower", 0, &string_name_class_to_lower),
	JS_CFUNC_DEF("left", 1, &string_name_class_left),
	JS_CFUNC_DEF("right", 1, &string_name_class_right),
	JS_CFUNC_DEF("strip_edges", 2, &string_name_class_strip_edges),
	JS_CFUNC_DEF("strip_escapes", 0, &string_name_class_strip_escapes),
	JS_CFUNC_DEF("lstrip", 1, &string_name_class_lstrip),
	JS_CFUNC_DEF("rstrip", 1, &string_name_class_rstrip),
	JS_CFUNC_DEF("get_extension", 0, &string_name_class_get_extension),
	JS_CFUNC_DEF("get_basename", 0, &string_name_class_get_basename),
	JS_CFUNC_DEF("path_join", 1, &string_name_class_path_join),
	JS_CFUNC_DEF("unicode_at", 1, &string_name_class_unicode_at),
	JS_CFUNC_DEF("indent", 1, &string_name_class_indent),
	JS_CFUNC_DEF("dedent", 0, &string_name_class_dedent),
	JS_CFUNC_DEF("md5_text", 0, &string_name_class_md5_text),
	JS_CFUNC_DEF("sha1_text", 0, &string_name_class_sha1_text),
	JS_CFUNC_DEF("sha256_text", 0, &string_name_class_sha256_text),
	JS_CFUNC_DEF("md5_buffer", 0, &string_name_class_md5_buffer),
	JS_CFUNC_DEF("sha1_buffer", 0, &string_name_class_sha1_buffer),
	JS_CFUNC_DEF("sha256_buffer", 0, &string_name_class_sha256_buffer),
	JS_CFUNC_DEF("is_empty", 0, &string_name_class_is_empty),
	JS_CFUNC_DEF("contains", 1, &string_name_class_contains),
	JS_CFUNC_DEF("containsn", 1, &string_name_class_containsn),
	JS_CFUNC_DEF("is_absolute_path", 0, &string_name_class_is_absolute_path),
	JS_CFUNC_DEF("is_relative_path", 0, &string_name_class_is_relative_path),
	JS_CFUNC_DEF("simplify_path", 0, &string_name_class_simplify_path),
	JS_CFUNC_DEF("get_base_dir", 0, &string_name_class_get_base_dir),
	JS_CFUNC_DEF("get_file", 0, &string_name_class_get_file),
	JS_CFUNC_DEF("xml_escape", 1, &string_name_class_xml_escape),
	JS_CFUNC_DEF("xml_unescape", 0, &string_name_class_xml_unescape),
	JS_CFUNC_DEF("uri_encode", 0, &string_name_class_uri_encode),
	JS_CFUNC_DEF("uri_decode", 0, &string_name_class_uri_decode),
	JS_CFUNC_DEF("uri_file_decode", 0, &string_name_class_uri_file_decode),
	JS_CFUNC_DEF("c_escape", 0, &string_name_class_c_escape),
	JS_CFUNC_DEF("c_unescape", 0, &string_name_class_c_unescape),
	JS_CFUNC_DEF("json_escape", 0, &string_name_class_json_escape),
	JS_CFUNC_DEF("validate_node_name", 0, &string_name_class_validate_node_name),
	JS_CFUNC_DEF("validate_filename", 0, &string_name_class_validate_filename),
	JS_CFUNC_DEF("is_valid_ascii_identifier", 0, &string_name_class_is_valid_ascii_identifier),
	JS_CFUNC_DEF("is_valid_unicode_identifier", 0, &string_name_class_is_valid_unicode_identifier),
	JS_CFUNC_DEF("is_valid_identifier", 0, &string_name_class_is_valid_identifier),
	JS_CFUNC_DEF("is_valid_int", 0, &string_name_class_is_valid_int),
	JS_CFUNC_DEF("is_valid_float", 0, &string_name_class_is_valid_float),
	JS_CFUNC_DEF("is_valid_hex_number", 1, &string_name_class_is_valid_hex_number),
	JS_CFUNC_DEF("is_valid_html_color", 0, &string_name_class_is_valid_html_color),
	JS_CFUNC_DEF("is_valid_ip_address", 0, &string_name_class_is_valid_ip_address),
	JS_CFUNC_DEF("is_valid_filename", 0, &string_name_class_is_valid_filename),
	JS_CFUNC_DEF("to_int", 0, &string_name_class_to_int),
	JS_CFUNC_DEF("to_float", 0, &string_name_class_to_float),
	JS_CFUNC_DEF("hex_to_int", 0, &string_name_class_hex_to_int),
	JS_CFUNC_DEF("bin_to_int", 0, &string_name_class_bin_to_int),
	JS_CFUNC_DEF("lpad", 2, &string_name_class_lpad),
	JS_CFUNC_DEF("rpad", 2, &string_name_class_rpad),
	JS_CFUNC_DEF("pad_decimals", 1, &string_name_class_pad_decimals),
	JS_CFUNC_DEF("pad_zeros", 1, &string_name_class_pad_zeros),
	JS_CFUNC_DEF("trim_prefix", 1, &string_name_class_trim_prefix),
	JS_CFUNC_DEF("trim_suffix", 1, &string_name_class_trim_suffix),
	JS_CFUNC_DEF("to_ascii_buffer", 0, &string_name_class_to_ascii_buffer),
	JS_CFUNC_DEF("to_utf8_buffer", 0, &string_name_class_to_utf8_buffer),
	JS_CFUNC_DEF("to_utf16_buffer", 0, &string_name_class_to_utf16_buffer),
	JS_CFUNC_DEF("to_utf32_buffer", 0, &string_name_class_to_utf32_buffer),
	JS_CFUNC_DEF("to_wchar_buffer", 0, &string_name_class_to_wchar_buffer),
	JS_CFUNC_DEF("to_multibyte_char_buffer", 1, &string_name_class_to_multibyte_char_buffer),
	JS_CFUNC_DEF("hex_decode", 0, &string_name_class_hex_decode),
	JS_CFUNC_DEF("hash", 0, &string_name_class_hash),
};


static int js_string_name_class_init(JSContext *ctx) {
	classes["StringName"] = 0;
	classes["StringName"] = JS_NewClassID(&classes["StringName"]);
	JSClassID class_id = classes["StringName"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &string_name_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, string_name_class_proto_funcs, _countof(string_name_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, string_name_class_constructor, "StringName", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "StringName", ctor);

	return 0;
}

void js_init_string_name_module(JSContext *ctx) {
	js_string_name_class_init(ctx);
}

void register_string_name() {
	js_init_string_name_module(js_context());
}