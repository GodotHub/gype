#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/packed_float64_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>


using namespace godot;

static void string_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["String"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef string_class_def = {
	"String",
	.finalizer = string_class_finalizer
};

static JSValue string_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["String"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	String instance;
	if (argc == 0) {
		instance = String();
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::STRING))) {
		String v0 = VariantAdapter(argv[0]).get();
		instance = String(v0);
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::STRING_NAME))) {
		StringName v0 = VariantAdapter(argv[0]).get();
		instance = String(v0);
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::NODE_PATH))) {
		NodePath v0 = VariantAdapter(argv[0]).get();
		instance = String(v0);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue string_class_casecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::casecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_class_nocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::nocasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_class_naturalcasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::naturalcasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_class_naturalnocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::naturalnocasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_class_filecasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::filecasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_class_filenocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::filenocasecmp_to, ctx, this_val, argc, argv);
}
static JSValue string_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::length, ctx, this_val, argc, argv);
}
static JSValue string_class_substr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::substr, ctx, this_val, argc, argv);
}
static JSValue string_class_get_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_slice, ctx, this_val, argc, argv);
}
static JSValue string_class_get_slicec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_slicec, ctx, this_val, argc, argv);
}
static JSValue string_class_get_slice_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_slice_count, ctx, this_val, argc, argv);
}
static JSValue string_class_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::find, ctx, this_val, argc, argv);
}
static JSValue string_class_findn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::findn, ctx, this_val, argc, argv);
}
static JSValue string_class_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::count, ctx, this_val, argc, argv);
}
static JSValue string_class_countn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::countn, ctx, this_val, argc, argv);
}
static JSValue string_class_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::rfind, ctx, this_val, argc, argv);
}
static JSValue string_class_rfindn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::rfindn, ctx, this_val, argc, argv);
}
static JSValue string_class_match(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::match, ctx, this_val, argc, argv);
}
static JSValue string_class_matchn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::matchn, ctx, this_val, argc, argv);
}
static JSValue string_class_begins_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::begins_with, ctx, this_val, argc, argv);
}
static JSValue string_class_ends_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::ends_with, ctx, this_val, argc, argv);
}
static JSValue string_class_is_subsequence_of(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_subsequence_of, ctx, this_val, argc, argv);
}
static JSValue string_class_is_subsequence_ofn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_subsequence_ofn, ctx, this_val, argc, argv);
}
static JSValue string_class_bigrams(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::bigrams, ctx, this_val, argc, argv);
}
static JSValue string_class_similarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::similarity, ctx, this_val, argc, argv);
}
static JSValue string_class_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::format, ctx, this_val, argc, argv);
}
static JSValue string_class_replace(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::replace, ctx, this_val, argc, argv);
}
static JSValue string_class_replacen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::replacen, ctx, this_val, argc, argv);
}
static JSValue string_class_replace_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::replace_char, ctx, this_val, argc, argv);
}
static JSValue string_class_replace_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::replace_chars, ctx, this_val, argc, argv);
}
static JSValue string_class_remove_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::remove_char, ctx, this_val, argc, argv);
}
static JSValue string_class_remove_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::remove_chars, ctx, this_val, argc, argv);
}
static JSValue string_class_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::repeat, ctx, this_val, argc, argv);
}
static JSValue string_class_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::reverse, ctx, this_val, argc, argv);
}
static JSValue string_class_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::insert, ctx, this_val, argc, argv);
}
static JSValue string_class_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::erase, ctx, this_val, argc, argv);
}
static JSValue string_class_capitalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::capitalize, ctx, this_val, argc, argv);
}
static JSValue string_class_to_camel_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_camel_case, ctx, this_val, argc, argv);
}
static JSValue string_class_to_pascal_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_pascal_case, ctx, this_val, argc, argv);
}
static JSValue string_class_to_snake_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_snake_case, ctx, this_val, argc, argv);
}
static JSValue string_class_to_kebab_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_kebab_case, ctx, this_val, argc, argv);
}
static JSValue string_class_split(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::split, ctx, this_val, argc, argv);
}
static JSValue string_class_rsplit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::rsplit, ctx, this_val, argc, argv);
}
static JSValue string_class_split_floats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::split_floats, ctx, this_val, argc, argv);
}
static JSValue string_class_join(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::join, ctx, this_val, argc, argv);
}
static JSValue string_class_to_upper(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_upper, ctx, this_val, argc, argv);
}
static JSValue string_class_to_lower(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_lower, ctx, this_val, argc, argv);
}
static JSValue string_class_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::left, ctx, this_val, argc, argv);
}
static JSValue string_class_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::right, ctx, this_val, argc, argv);
}
static JSValue string_class_strip_edges(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::strip_edges, ctx, this_val, argc, argv);
}
static JSValue string_class_strip_escapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::strip_escapes, ctx, this_val, argc, argv);
}
static JSValue string_class_lstrip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::lstrip, ctx, this_val, argc, argv);
}
static JSValue string_class_rstrip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::rstrip, ctx, this_val, argc, argv);
}
static JSValue string_class_get_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_extension, ctx, this_val, argc, argv);
}
static JSValue string_class_get_basename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_basename, ctx, this_val, argc, argv);
}
static JSValue string_class_path_join(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::path_join, ctx, this_val, argc, argv);
}
static JSValue string_class_unicode_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::unicode_at, ctx, this_val, argc, argv);
}
static JSValue string_class_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::indent, ctx, this_val, argc, argv);
}
static JSValue string_class_dedent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::dedent, ctx, this_val, argc, argv);
}
static JSValue string_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::hash, ctx, this_val, argc, argv);
}
static JSValue string_class_md5_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::md5_text, ctx, this_val, argc, argv);
}
static JSValue string_class_sha1_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::sha1_text, ctx, this_val, argc, argv);
}
static JSValue string_class_sha256_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::sha256_text, ctx, this_val, argc, argv);
}
static JSValue string_class_md5_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::md5_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_sha1_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::sha1_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_sha256_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::sha256_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_empty, ctx, this_val, argc, argv);
}
static JSValue string_class_contains(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::contains, ctx, this_val, argc, argv);
}
static JSValue string_class_containsn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::containsn, ctx, this_val, argc, argv);
}
static JSValue string_class_is_absolute_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_absolute_path, ctx, this_val, argc, argv);
}
static JSValue string_class_is_relative_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_relative_path, ctx, this_val, argc, argv);
}
static JSValue string_class_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::simplify_path, ctx, this_val, argc, argv);
}
static JSValue string_class_get_base_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_base_dir, ctx, this_val, argc, argv);
}
static JSValue string_class_get_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::get_file, ctx, this_val, argc, argv);
}
static JSValue string_class_xml_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::xml_escape, ctx, this_val, argc, argv);
}
static JSValue string_class_xml_unescape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::xml_unescape, ctx, this_val, argc, argv);
}
static JSValue string_class_uri_encode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::uri_encode, ctx, this_val, argc, argv);
}
static JSValue string_class_uri_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::uri_decode, ctx, this_val, argc, argv);
}
static JSValue string_class_uri_file_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::uri_file_decode, ctx, this_val, argc, argv);
}
static JSValue string_class_c_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::c_escape, ctx, this_val, argc, argv);
}
static JSValue string_class_c_unescape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::c_unescape, ctx, this_val, argc, argv);
}
static JSValue string_class_json_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::json_escape, ctx, this_val, argc, argv);
}
static JSValue string_class_validate_node_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::validate_node_name, ctx, this_val, argc, argv);
}
static JSValue string_class_validate_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::validate_filename, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_ascii_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_ascii_identifier, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_unicode_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_unicode_identifier, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_identifier, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_int, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_float, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_hex_number(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_hex_number, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_html_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_html_color, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_ip_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_ip_address, ctx, this_val, argc, argv);
}
static JSValue string_class_is_valid_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::is_valid_filename, ctx, this_val, argc, argv);
}
static JSValue string_class_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_int, ctx, this_val, argc, argv);
}
static JSValue string_class_to_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_float, ctx, this_val, argc, argv);
}
static JSValue string_class_hex_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::hex_to_int, ctx, this_val, argc, argv);
}
static JSValue string_class_bin_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::bin_to_int, ctx, this_val, argc, argv);
}
static JSValue string_class_lpad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::lpad, ctx, this_val, argc, argv);
}
static JSValue string_class_rpad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::rpad, ctx, this_val, argc, argv);
}
static JSValue string_class_pad_decimals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::pad_decimals, ctx, this_val, argc, argv);
}
static JSValue string_class_pad_zeros(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::pad_zeros, ctx, this_val, argc, argv);
}
static JSValue string_class_trim_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::trim_prefix, ctx, this_val, argc, argv);
}
static JSValue string_class_trim_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::trim_suffix, ctx, this_val, argc, argv);
}
static JSValue string_class_to_ascii_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_ascii_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_to_utf8_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_utf8_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_to_utf16_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_utf16_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_to_utf32_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_utf32_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_to_wchar_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_wchar_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_to_multibyte_char_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::to_multibyte_char_buffer, ctx, this_val, argc, argv);
}
static JSValue string_class_hex_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&String::hex_decode, ctx, this_val, argc, argv);
}
static JSValue string_class_num_scientific(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num_scientific, ctx, this_val, argc, argv);
}
static JSValue string_class_num(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num, ctx, this_val, argc, argv);
}
static JSValue string_class_num_int64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num_int64, ctx, this_val, argc, argv);
}
static JSValue string_class_num_uint64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num_uint64, ctx, this_val, argc, argv);
}
static JSValue string_class_chr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::chr, ctx, this_val, argc, argv);
}
static JSValue string_class_humanize_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::humanize_size, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry string_class_proto_funcs[] = {
	JS_CFUNC_DEF("casecmp_to", 1, &string_class_casecmp_to),
	JS_CFUNC_DEF("nocasecmp_to", 1, &string_class_nocasecmp_to),
	JS_CFUNC_DEF("naturalcasecmp_to", 1, &string_class_naturalcasecmp_to),
	JS_CFUNC_DEF("naturalnocasecmp_to", 1, &string_class_naturalnocasecmp_to),
	JS_CFUNC_DEF("filecasecmp_to", 1, &string_class_filecasecmp_to),
	JS_CFUNC_DEF("filenocasecmp_to", 1, &string_class_filenocasecmp_to),
	JS_CFUNC_DEF("length", 0, &string_class_length),
	JS_CFUNC_DEF("substr", 2, &string_class_substr),
	JS_CFUNC_DEF("get_slice", 2, &string_class_get_slice),
	JS_CFUNC_DEF("get_slicec", 2, &string_class_get_slicec),
	JS_CFUNC_DEF("get_slice_count", 1, &string_class_get_slice_count),
	JS_CFUNC_DEF("find", 2, &string_class_find),
	JS_CFUNC_DEF("findn", 2, &string_class_findn),
	JS_CFUNC_DEF("count", 3, &string_class_count),
	JS_CFUNC_DEF("countn", 3, &string_class_countn),
	JS_CFUNC_DEF("rfind", 2, &string_class_rfind),
	JS_CFUNC_DEF("rfindn", 2, &string_class_rfindn),
	JS_CFUNC_DEF("match", 1, &string_class_match),
	JS_CFUNC_DEF("matchn", 1, &string_class_matchn),
	JS_CFUNC_DEF("begins_with", 1, &string_class_begins_with),
	JS_CFUNC_DEF("ends_with", 1, &string_class_ends_with),
	JS_CFUNC_DEF("is_subsequence_of", 1, &string_class_is_subsequence_of),
	JS_CFUNC_DEF("is_subsequence_ofn", 1, &string_class_is_subsequence_ofn),
	JS_CFUNC_DEF("bigrams", 0, &string_class_bigrams),
	JS_CFUNC_DEF("similarity", 1, &string_class_similarity),
	JS_CFUNC_DEF("format", 2, &string_class_format),
	JS_CFUNC_DEF("replace", 2, &string_class_replace),
	JS_CFUNC_DEF("replacen", 2, &string_class_replacen),
	JS_CFUNC_DEF("replace_char", 2, &string_class_replace_char),
	JS_CFUNC_DEF("replace_chars", 2, &string_class_replace_chars),
	JS_CFUNC_DEF("remove_char", 1, &string_class_remove_char),
	JS_CFUNC_DEF("remove_chars", 1, &string_class_remove_chars),
	JS_CFUNC_DEF("repeat", 1, &string_class_repeat),
	JS_CFUNC_DEF("reverse", 0, &string_class_reverse),
	JS_CFUNC_DEF("insert", 2, &string_class_insert),
	JS_CFUNC_DEF("erase", 2, &string_class_erase),
	JS_CFUNC_DEF("capitalize", 0, &string_class_capitalize),
	JS_CFUNC_DEF("to_camel_case", 0, &string_class_to_camel_case),
	JS_CFUNC_DEF("to_pascal_case", 0, &string_class_to_pascal_case),
	JS_CFUNC_DEF("to_snake_case", 0, &string_class_to_snake_case),
	JS_CFUNC_DEF("to_kebab_case", 0, &string_class_to_kebab_case),
	JS_CFUNC_DEF("split", 3, &string_class_split),
	JS_CFUNC_DEF("rsplit", 3, &string_class_rsplit),
	JS_CFUNC_DEF("split_floats", 2, &string_class_split_floats),
	JS_CFUNC_DEF("join", 1, &string_class_join),
	JS_CFUNC_DEF("to_upper", 0, &string_class_to_upper),
	JS_CFUNC_DEF("to_lower", 0, &string_class_to_lower),
	JS_CFUNC_DEF("left", 1, &string_class_left),
	JS_CFUNC_DEF("right", 1, &string_class_right),
	JS_CFUNC_DEF("strip_edges", 2, &string_class_strip_edges),
	JS_CFUNC_DEF("strip_escapes", 0, &string_class_strip_escapes),
	JS_CFUNC_DEF("lstrip", 1, &string_class_lstrip),
	JS_CFUNC_DEF("rstrip", 1, &string_class_rstrip),
	JS_CFUNC_DEF("get_extension", 0, &string_class_get_extension),
	JS_CFUNC_DEF("get_basename", 0, &string_class_get_basename),
	JS_CFUNC_DEF("path_join", 1, &string_class_path_join),
	JS_CFUNC_DEF("unicode_at", 1, &string_class_unicode_at),
	JS_CFUNC_DEF("indent", 1, &string_class_indent),
	JS_CFUNC_DEF("dedent", 0, &string_class_dedent),
	JS_CFUNC_DEF("hash", 0, &string_class_hash),
	JS_CFUNC_DEF("md5_text", 0, &string_class_md5_text),
	JS_CFUNC_DEF("sha1_text", 0, &string_class_sha1_text),
	JS_CFUNC_DEF("sha256_text", 0, &string_class_sha256_text),
	JS_CFUNC_DEF("md5_buffer", 0, &string_class_md5_buffer),
	JS_CFUNC_DEF("sha1_buffer", 0, &string_class_sha1_buffer),
	JS_CFUNC_DEF("sha256_buffer", 0, &string_class_sha256_buffer),
	JS_CFUNC_DEF("is_empty", 0, &string_class_is_empty),
	JS_CFUNC_DEF("contains", 1, &string_class_contains),
	JS_CFUNC_DEF("containsn", 1, &string_class_containsn),
	JS_CFUNC_DEF("is_absolute_path", 0, &string_class_is_absolute_path),
	JS_CFUNC_DEF("is_relative_path", 0, &string_class_is_relative_path),
	JS_CFUNC_DEF("simplify_path", 0, &string_class_simplify_path),
	JS_CFUNC_DEF("get_base_dir", 0, &string_class_get_base_dir),
	JS_CFUNC_DEF("get_file", 0, &string_class_get_file),
	JS_CFUNC_DEF("xml_escape", 1, &string_class_xml_escape),
	JS_CFUNC_DEF("xml_unescape", 0, &string_class_xml_unescape),
	JS_CFUNC_DEF("uri_encode", 0, &string_class_uri_encode),
	JS_CFUNC_DEF("uri_decode", 0, &string_class_uri_decode),
	JS_CFUNC_DEF("uri_file_decode", 0, &string_class_uri_file_decode),
	JS_CFUNC_DEF("c_escape", 0, &string_class_c_escape),
	JS_CFUNC_DEF("c_unescape", 0, &string_class_c_unescape),
	JS_CFUNC_DEF("json_escape", 0, &string_class_json_escape),
	JS_CFUNC_DEF("validate_node_name", 0, &string_class_validate_node_name),
	JS_CFUNC_DEF("validate_filename", 0, &string_class_validate_filename),
	JS_CFUNC_DEF("is_valid_ascii_identifier", 0, &string_class_is_valid_ascii_identifier),
	JS_CFUNC_DEF("is_valid_unicode_identifier", 0, &string_class_is_valid_unicode_identifier),
	JS_CFUNC_DEF("is_valid_identifier", 0, &string_class_is_valid_identifier),
	JS_CFUNC_DEF("is_valid_int", 0, &string_class_is_valid_int),
	JS_CFUNC_DEF("is_valid_float", 0, &string_class_is_valid_float),
	JS_CFUNC_DEF("is_valid_hex_number", 1, &string_class_is_valid_hex_number),
	JS_CFUNC_DEF("is_valid_html_color", 0, &string_class_is_valid_html_color),
	JS_CFUNC_DEF("is_valid_ip_address", 0, &string_class_is_valid_ip_address),
	JS_CFUNC_DEF("is_valid_filename", 0, &string_class_is_valid_filename),
	JS_CFUNC_DEF("to_int", 0, &string_class_to_int),
	JS_CFUNC_DEF("to_float", 0, &string_class_to_float),
	JS_CFUNC_DEF("hex_to_int", 0, &string_class_hex_to_int),
	JS_CFUNC_DEF("bin_to_int", 0, &string_class_bin_to_int),
	JS_CFUNC_DEF("lpad", 2, &string_class_lpad),
	JS_CFUNC_DEF("rpad", 2, &string_class_rpad),
	JS_CFUNC_DEF("pad_decimals", 1, &string_class_pad_decimals),
	JS_CFUNC_DEF("pad_zeros", 1, &string_class_pad_zeros),
	JS_CFUNC_DEF("trim_prefix", 1, &string_class_trim_prefix),
	JS_CFUNC_DEF("trim_suffix", 1, &string_class_trim_suffix),
	JS_CFUNC_DEF("to_ascii_buffer", 0, &string_class_to_ascii_buffer),
	JS_CFUNC_DEF("to_utf8_buffer", 0, &string_class_to_utf8_buffer),
	JS_CFUNC_DEF("to_utf16_buffer", 0, &string_class_to_utf16_buffer),
	JS_CFUNC_DEF("to_utf32_buffer", 0, &string_class_to_utf32_buffer),
	JS_CFUNC_DEF("to_wchar_buffer", 0, &string_class_to_wchar_buffer),
	JS_CFUNC_DEF("to_multibyte_char_buffer", 1, &string_class_to_multibyte_char_buffer),
	JS_CFUNC_DEF("hex_decode", 0, &string_class_hex_decode),
	JS_CFUNC_DEF("num_scientific", 1, &string_class_num_scientific),
	JS_CFUNC_DEF("num", 2, &string_class_num),
	JS_CFUNC_DEF("num_int64", 3, &string_class_num_int64),
	JS_CFUNC_DEF("num_uint64", 3, &string_class_num_uint64),
	JS_CFUNC_DEF("chr", 1, &string_class_chr),
	JS_CFUNC_DEF("humanize_size", 1, &string_class_humanize_size),
};


static int js_string_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["String"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "String";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &string_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	JS_SetPropertyFunctionList(ctx, proto, string_class_proto_funcs, _countof(string_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, string_class_constructor, "GDString", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "GDString", ctor);

	return 0;
}

void js_init_string_module(JSContext *ctx) {
	js_string_class_init(ctx);
}

void register_string() {
	js_init_string_module(js_context());
}

// ------------------StringProxy------------------
static void string_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["StringProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<String> *>(proxy));
	}
}

static JSClassDef string_proxy_def = {
	"StringProxy",
	.finalizer = string_proxy_finalizer
};


static JSValue string_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["StringProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<String> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<String> *>(JS_GetAnyOpaque(*argv, &opaque_id));
	} else {
		return JS_EXCEPTION;
	}

	if (!proxy) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	return obj;
}

static JSValue string_proxy_casecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::casecmp_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_nocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::nocasecmp_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_naturalcasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::naturalcasecmp_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_naturalnocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::naturalnocasecmp_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_filecasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::filecasecmp_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_filenocasecmp_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::filenocasecmp_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::length, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_substr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::substr, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_slice(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_slice, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_slicec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_slicec, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_slice_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_slice_count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_find(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::find, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_findn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::findn, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::count, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_countn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::countn, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_rfind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::rfind, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_rfindn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::rfindn, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_match(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::match, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_matchn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::matchn, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_begins_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::begins_with, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_ends_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::ends_with, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_subsequence_of(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_subsequence_of, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_subsequence_ofn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_subsequence_ofn, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_bigrams(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::bigrams, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_similarity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::similarity, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::format, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_replace(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::replace, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_replacen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::replacen, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_replace_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::replace_char, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_replace_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::replace_chars, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_remove_char(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::remove_char, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_remove_chars(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::remove_chars, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::repeat, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_reverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::reverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_insert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::insert, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_erase(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::erase, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_capitalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::capitalize, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_camel_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_camel_case, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_pascal_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_pascal_case, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_snake_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_snake_case, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_kebab_case(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_kebab_case, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_split(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::split, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_rsplit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::rsplit, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_split_floats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::split_floats, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_join(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::join, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_upper(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_upper, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_lower(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_lower, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::left, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::right, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_strip_edges(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::strip_edges, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_strip_escapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::strip_escapes, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_lstrip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::lstrip, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_rstrip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::rstrip, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_extension, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_basename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_basename, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_path_join(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::path_join, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_unicode_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::unicode_at, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_indent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::indent, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_dedent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::dedent, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::hash, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_md5_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::md5_text, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_sha1_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::sha1_text, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_sha256_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::sha256_text, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_md5_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::md5_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_sha1_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::sha1_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_sha256_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::sha256_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_empty, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_contains(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::contains, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_containsn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::containsn, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_absolute_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_absolute_path, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_relative_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_relative_path, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_simplify_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::simplify_path, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_base_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_base_dir, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_get_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::get_file, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_xml_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::xml_escape, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_xml_unescape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::xml_unescape, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_uri_encode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::uri_encode, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_uri_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::uri_decode, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_uri_file_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::uri_file_decode, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_c_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::c_escape, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_c_unescape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::c_unescape, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_json_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::json_escape, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_validate_node_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::validate_node_name, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_validate_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::validate_filename, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_ascii_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_ascii_identifier, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_unicode_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_unicode_identifier, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_identifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_identifier, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_int, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_float, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_hex_number(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_hex_number, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_html_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_html_color, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_ip_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_ip_address, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_is_valid_filename(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::is_valid_filename, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_int, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_float, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_hex_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::hex_to_int, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_bin_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::bin_to_int, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_lpad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::lpad, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_rpad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::rpad, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_pad_decimals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::pad_decimals, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_pad_zeros(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::pad_zeros, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_trim_prefix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::trim_prefix, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_trim_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::trim_suffix, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_ascii_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_ascii_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_utf8_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_utf8_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_utf16_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_utf16_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_utf32_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_utf32_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_wchar_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_wchar_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_to_multibyte_char_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::to_multibyte_char_buffer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_hex_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["StringProxy"]);
    ObjectProxy<String> *proxy = reinterpret_cast<ObjectProxy<String> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&String::hex_decode, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue string_proxy_num_scientific(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num_scientific, ctx, this_val, argc, argv);
}
static JSValue string_proxy_num(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num, ctx, this_val, argc, argv);
}
static JSValue string_proxy_num_int64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num_int64, ctx, this_val, argc, argv);
}
static JSValue string_proxy_num_uint64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::num_uint64, ctx, this_val, argc, argv);
}
static JSValue string_proxy_chr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::chr, ctx, this_val, argc, argv);
}
static JSValue string_proxy_humanize_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&String::humanize_size, ctx, this_val, argc, argv);
}


static const JSCFunctionListEntry string_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("casecmp_to", 1, &string_proxy_casecmp_to),
	JS_CFUNC_DEF("nocasecmp_to", 1, &string_proxy_nocasecmp_to),
	JS_CFUNC_DEF("naturalcasecmp_to", 1, &string_proxy_naturalcasecmp_to),
	JS_CFUNC_DEF("naturalnocasecmp_to", 1, &string_proxy_naturalnocasecmp_to),
	JS_CFUNC_DEF("filecasecmp_to", 1, &string_proxy_filecasecmp_to),
	JS_CFUNC_DEF("filenocasecmp_to", 1, &string_proxy_filenocasecmp_to),
	JS_CFUNC_DEF("length", 0, &string_proxy_length),
	JS_CFUNC_DEF("substr", 2, &string_proxy_substr),
	JS_CFUNC_DEF("get_slice", 2, &string_proxy_get_slice),
	JS_CFUNC_DEF("get_slicec", 2, &string_proxy_get_slicec),
	JS_CFUNC_DEF("get_slice_count", 1, &string_proxy_get_slice_count),
	JS_CFUNC_DEF("find", 2, &string_proxy_find),
	JS_CFUNC_DEF("findn", 2, &string_proxy_findn),
	JS_CFUNC_DEF("count", 3, &string_proxy_count),
	JS_CFUNC_DEF("countn", 3, &string_proxy_countn),
	JS_CFUNC_DEF("rfind", 2, &string_proxy_rfind),
	JS_CFUNC_DEF("rfindn", 2, &string_proxy_rfindn),
	JS_CFUNC_DEF("match", 1, &string_proxy_match),
	JS_CFUNC_DEF("matchn", 1, &string_proxy_matchn),
	JS_CFUNC_DEF("begins_with", 1, &string_proxy_begins_with),
	JS_CFUNC_DEF("ends_with", 1, &string_proxy_ends_with),
	JS_CFUNC_DEF("is_subsequence_of", 1, &string_proxy_is_subsequence_of),
	JS_CFUNC_DEF("is_subsequence_ofn", 1, &string_proxy_is_subsequence_ofn),
	JS_CFUNC_DEF("bigrams", 0, &string_proxy_bigrams),
	JS_CFUNC_DEF("similarity", 1, &string_proxy_similarity),
	JS_CFUNC_DEF("format", 2, &string_proxy_format),
	JS_CFUNC_DEF("replace", 2, &string_proxy_replace),
	JS_CFUNC_DEF("replacen", 2, &string_proxy_replacen),
	JS_CFUNC_DEF("replace_char", 2, &string_proxy_replace_char),
	JS_CFUNC_DEF("replace_chars", 2, &string_proxy_replace_chars),
	JS_CFUNC_DEF("remove_char", 1, &string_proxy_remove_char),
	JS_CFUNC_DEF("remove_chars", 1, &string_proxy_remove_chars),
	JS_CFUNC_DEF("repeat", 1, &string_proxy_repeat),
	JS_CFUNC_DEF("reverse", 0, &string_proxy_reverse),
	JS_CFUNC_DEF("insert", 2, &string_proxy_insert),
	JS_CFUNC_DEF("erase", 2, &string_proxy_erase),
	JS_CFUNC_DEF("capitalize", 0, &string_proxy_capitalize),
	JS_CFUNC_DEF("to_camel_case", 0, &string_proxy_to_camel_case),
	JS_CFUNC_DEF("to_pascal_case", 0, &string_proxy_to_pascal_case),
	JS_CFUNC_DEF("to_snake_case", 0, &string_proxy_to_snake_case),
	JS_CFUNC_DEF("to_kebab_case", 0, &string_proxy_to_kebab_case),
	JS_CFUNC_DEF("split", 3, &string_proxy_split),
	JS_CFUNC_DEF("rsplit", 3, &string_proxy_rsplit),
	JS_CFUNC_DEF("split_floats", 2, &string_proxy_split_floats),
	JS_CFUNC_DEF("join", 1, &string_proxy_join),
	JS_CFUNC_DEF("to_upper", 0, &string_proxy_to_upper),
	JS_CFUNC_DEF("to_lower", 0, &string_proxy_to_lower),
	JS_CFUNC_DEF("left", 1, &string_proxy_left),
	JS_CFUNC_DEF("right", 1, &string_proxy_right),
	JS_CFUNC_DEF("strip_edges", 2, &string_proxy_strip_edges),
	JS_CFUNC_DEF("strip_escapes", 0, &string_proxy_strip_escapes),
	JS_CFUNC_DEF("lstrip", 1, &string_proxy_lstrip),
	JS_CFUNC_DEF("rstrip", 1, &string_proxy_rstrip),
	JS_CFUNC_DEF("get_extension", 0, &string_proxy_get_extension),
	JS_CFUNC_DEF("get_basename", 0, &string_proxy_get_basename),
	JS_CFUNC_DEF("path_join", 1, &string_proxy_path_join),
	JS_CFUNC_DEF("unicode_at", 1, &string_proxy_unicode_at),
	JS_CFUNC_DEF("indent", 1, &string_proxy_indent),
	JS_CFUNC_DEF("dedent", 0, &string_proxy_dedent),
	JS_CFUNC_DEF("hash", 0, &string_proxy_hash),
	JS_CFUNC_DEF("md5_text", 0, &string_proxy_md5_text),
	JS_CFUNC_DEF("sha1_text", 0, &string_proxy_sha1_text),
	JS_CFUNC_DEF("sha256_text", 0, &string_proxy_sha256_text),
	JS_CFUNC_DEF("md5_buffer", 0, &string_proxy_md5_buffer),
	JS_CFUNC_DEF("sha1_buffer", 0, &string_proxy_sha1_buffer),
	JS_CFUNC_DEF("sha256_buffer", 0, &string_proxy_sha256_buffer),
	JS_CFUNC_DEF("is_empty", 0, &string_proxy_is_empty),
	JS_CFUNC_DEF("contains", 1, &string_proxy_contains),
	JS_CFUNC_DEF("containsn", 1, &string_proxy_containsn),
	JS_CFUNC_DEF("is_absolute_path", 0, &string_proxy_is_absolute_path),
	JS_CFUNC_DEF("is_relative_path", 0, &string_proxy_is_relative_path),
	JS_CFUNC_DEF("simplify_path", 0, &string_proxy_simplify_path),
	JS_CFUNC_DEF("get_base_dir", 0, &string_proxy_get_base_dir),
	JS_CFUNC_DEF("get_file", 0, &string_proxy_get_file),
	JS_CFUNC_DEF("xml_escape", 1, &string_proxy_xml_escape),
	JS_CFUNC_DEF("xml_unescape", 0, &string_proxy_xml_unescape),
	JS_CFUNC_DEF("uri_encode", 0, &string_proxy_uri_encode),
	JS_CFUNC_DEF("uri_decode", 0, &string_proxy_uri_decode),
	JS_CFUNC_DEF("uri_file_decode", 0, &string_proxy_uri_file_decode),
	JS_CFUNC_DEF("c_escape", 0, &string_proxy_c_escape),
	JS_CFUNC_DEF("c_unescape", 0, &string_proxy_c_unescape),
	JS_CFUNC_DEF("json_escape", 0, &string_proxy_json_escape),
	JS_CFUNC_DEF("validate_node_name", 0, &string_proxy_validate_node_name),
	JS_CFUNC_DEF("validate_filename", 0, &string_proxy_validate_filename),
	JS_CFUNC_DEF("is_valid_ascii_identifier", 0, &string_proxy_is_valid_ascii_identifier),
	JS_CFUNC_DEF("is_valid_unicode_identifier", 0, &string_proxy_is_valid_unicode_identifier),
	JS_CFUNC_DEF("is_valid_identifier", 0, &string_proxy_is_valid_identifier),
	JS_CFUNC_DEF("is_valid_int", 0, &string_proxy_is_valid_int),
	JS_CFUNC_DEF("is_valid_float", 0, &string_proxy_is_valid_float),
	JS_CFUNC_DEF("is_valid_hex_number", 1, &string_proxy_is_valid_hex_number),
	JS_CFUNC_DEF("is_valid_html_color", 0, &string_proxy_is_valid_html_color),
	JS_CFUNC_DEF("is_valid_ip_address", 0, &string_proxy_is_valid_ip_address),
	JS_CFUNC_DEF("is_valid_filename", 0, &string_proxy_is_valid_filename),
	JS_CFUNC_DEF("to_int", 0, &string_proxy_to_int),
	JS_CFUNC_DEF("to_float", 0, &string_proxy_to_float),
	JS_CFUNC_DEF("hex_to_int", 0, &string_proxy_hex_to_int),
	JS_CFUNC_DEF("bin_to_int", 0, &string_proxy_bin_to_int),
	JS_CFUNC_DEF("lpad", 2, &string_proxy_lpad),
	JS_CFUNC_DEF("rpad", 2, &string_proxy_rpad),
	JS_CFUNC_DEF("pad_decimals", 1, &string_proxy_pad_decimals),
	JS_CFUNC_DEF("pad_zeros", 1, &string_proxy_pad_zeros),
	JS_CFUNC_DEF("trim_prefix", 1, &string_proxy_trim_prefix),
	JS_CFUNC_DEF("trim_suffix", 1, &string_proxy_trim_suffix),
	JS_CFUNC_DEF("to_ascii_buffer", 0, &string_proxy_to_ascii_buffer),
	JS_CFUNC_DEF("to_utf8_buffer", 0, &string_proxy_to_utf8_buffer),
	JS_CFUNC_DEF("to_utf16_buffer", 0, &string_proxy_to_utf16_buffer),
	JS_CFUNC_DEF("to_utf32_buffer", 0, &string_proxy_to_utf32_buffer),
	JS_CFUNC_DEF("to_wchar_buffer", 0, &string_proxy_to_wchar_buffer),
	JS_CFUNC_DEF("to_multibyte_char_buffer", 1, &string_proxy_to_multibyte_char_buffer),
	JS_CFUNC_DEF("hex_decode", 0, &string_proxy_hex_decode),
	JS_CFUNC_DEF("num_scientific", 1, &string_proxy_num_scientific),
	JS_CFUNC_DEF("num", 2, &string_proxy_num),
	JS_CFUNC_DEF("num_int64", 3, &string_proxy_num_int64),
	JS_CFUNC_DEF("num_uint64", 3, &string_proxy_num_uint64),
	JS_CFUNC_DEF("chr", 1, &string_proxy_chr),
	JS_CFUNC_DEF("humanize_size", 1, &string_proxy_humanize_size),
};


static int js_string_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["StringProxy"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "StringProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &string_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, string_proxy_proto_funcs, _countof(string_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, string_proxy_constructor, "StringProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "StringProxy", ctor);

	return 0;
}

void js_init_string_proxy_module(JSContext *ctx) {
	js_string_proxy_init(ctx);
}

void register_proxy_string() {
	js_init_string_proxy_module(js_context());
}