#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/file_access.hpp>
using namespace godot;

static void file_access_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FileAccess"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef file_access_class_def = {
    "FileAccess",
    file_access_class_finalizer
};

static JSValue file_access_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FileAccess"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FileAccess *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FileAccess *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FileAccess);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue file_access_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::resize, ctx, this_val, argc, argv);
};
static JSValue file_access_class_flush(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileAccess::flush, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_path, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_path_absolute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_path_absolute, ctx, this_val, argc, argv);
};
static JSValue file_access_class_is_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::is_open, ctx, this_val, argc, argv);
};
static JSValue file_access_class_seek(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileAccess::seek, ctx, this_val, argc, argv);
};
static JSValue file_access_class_seek_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileAccess::seek_end, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_position, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_length, ctx, this_val, argc, argv);
};
static JSValue file_access_class_eof_reached(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::eof_reached, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_8, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_16(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_16, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_32, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_64, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_half(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_half, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_float, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_double(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_double, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_real(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_real, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(static_cast<PackedByteArray(FileAccess::*)(int64_t) const>(&FileAccess::get_buffer), ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_line, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_csv_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_csv_line, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_as_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_as_text, ctx, this_val, argc, argv);
};
static JSValue file_access_class_is_big_endian(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::is_big_endian, ctx, this_val, argc, argv);
}
static JSValue file_access_class_set_big_endian(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileAccess::set_big_endian, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_error, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_var(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileAccess::get_var, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_8, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_16(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_16, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_32, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_64, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_half(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_half, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_float, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_double(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_double, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_real(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_real, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(static_cast<bool(FileAccess::*)(const PackedByteArray &)>(&FileAccess::store_buffer), ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_line, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_csv_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_csv_line, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_string, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_var(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_var, ctx, this_val, argc, argv);
};
static JSValue file_access_class_store_pascal_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::store_pascal_string, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_pascal_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileAccess::get_pascal_string, ctx, this_val, argc, argv);
};
static JSValue file_access_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileAccess::close, ctx, this_val, argc, argv);
};
static JSValue file_access_class_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::open, ctx, this_val, argc, argv);
};
static JSValue file_access_class_open_encrypted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::open_encrypted, ctx, this_val, argc, argv);
};
static JSValue file_access_class_open_encrypted_with_pass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::open_encrypted_with_pass, ctx, this_val, argc, argv);
};
static JSValue file_access_class_open_compressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::open_compressed, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_open_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_open_error, ctx, this_val, argc, argv);
};
static JSValue file_access_class_create_temp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::create_temp, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_file_as_bytes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_file_as_bytes, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_file_as_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_file_as_string, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_md5(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_md5, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_sha256(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_sha256, ctx, this_val, argc, argv);
};
static JSValue file_access_class_file_exists(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::file_exists, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_modified_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_modified_time, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_access_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_access_time, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_size, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_unix_permissions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_unix_permissions, ctx, this_val, argc, argv);
};
static JSValue file_access_class_set_unix_permissions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::set_unix_permissions, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_hidden_attribute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_hidden_attribute, ctx, this_val, argc, argv);
};
static JSValue file_access_class_set_hidden_attribute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::set_hidden_attribute, ctx, this_val, argc, argv);
};
static JSValue file_access_class_set_read_only_attribute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::set_read_only_attribute, ctx, this_val, argc, argv);
};
static JSValue file_access_class_get_read_only_attribute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FileAccess::get_read_only_attribute, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry file_access_class_proto_funcs[] = {
	JS_CFUNC_DEF("resize", 1, &file_access_class_resize),
	JS_CFUNC_DEF("flush", 0, &file_access_class_flush),
	JS_CFUNC_DEF("get_path", 0, &file_access_class_get_path),
	JS_CFUNC_DEF("get_path_absolute", 0, &file_access_class_get_path_absolute),
	JS_CFUNC_DEF("is_open", 0, &file_access_class_is_open),
	JS_CFUNC_DEF("seek", 1, &file_access_class_seek),
	JS_CFUNC_DEF("seek_end", 1, &file_access_class_seek_end),
	JS_CFUNC_DEF("get_position", 0, &file_access_class_get_position),
	JS_CFUNC_DEF("get_length", 0, &file_access_class_get_length),
	JS_CFUNC_DEF("eof_reached", 0, &file_access_class_eof_reached),
	JS_CFUNC_DEF("get_8", 0, &file_access_class_get_8),
	JS_CFUNC_DEF("get_16", 0, &file_access_class_get_16),
	JS_CFUNC_DEF("get_32", 0, &file_access_class_get_32),
	JS_CFUNC_DEF("get_64", 0, &file_access_class_get_64),
	JS_CFUNC_DEF("get_half", 0, &file_access_class_get_half),
	JS_CFUNC_DEF("get_float", 0, &file_access_class_get_float),
	JS_CFUNC_DEF("get_double", 0, &file_access_class_get_double),
	JS_CFUNC_DEF("get_real", 0, &file_access_class_get_real),
	JS_CFUNC_DEF("get_buffer", 1, &file_access_class_get_buffer),
	JS_CFUNC_DEF("get_line", 0, &file_access_class_get_line),
	JS_CFUNC_DEF("get_csv_line", 1, &file_access_class_get_csv_line),
	JS_CFUNC_DEF("get_as_text", 1, &file_access_class_get_as_text),
	JS_CFUNC_DEF("is_big_endian", 0, &file_access_class_is_big_endian),
	JS_CFUNC_DEF("set_big_endian", 1, &file_access_class_set_big_endian),
	JS_CFUNC_DEF("get_error", 0, &file_access_class_get_error),
	JS_CFUNC_DEF("get_var", 1, &file_access_class_get_var),
	JS_CFUNC_DEF("store_8", 1, &file_access_class_store_8),
	JS_CFUNC_DEF("store_16", 1, &file_access_class_store_16),
	JS_CFUNC_DEF("store_32", 1, &file_access_class_store_32),
	JS_CFUNC_DEF("store_64", 1, &file_access_class_store_64),
	JS_CFUNC_DEF("store_half", 1, &file_access_class_store_half),
	JS_CFUNC_DEF("store_float", 1, &file_access_class_store_float),
	JS_CFUNC_DEF("store_double", 1, &file_access_class_store_double),
	JS_CFUNC_DEF("store_real", 1, &file_access_class_store_real),
	JS_CFUNC_DEF("store_buffer", 1, &file_access_class_store_buffer),
	JS_CFUNC_DEF("store_line", 1, &file_access_class_store_line),
	JS_CFUNC_DEF("store_csv_line", 2, &file_access_class_store_csv_line),
	JS_CFUNC_DEF("store_string", 1, &file_access_class_store_string),
	JS_CFUNC_DEF("store_var", 2, &file_access_class_store_var),
	JS_CFUNC_DEF("store_pascal_string", 1, &file_access_class_store_pascal_string),
	JS_CFUNC_DEF("get_pascal_string", 0, &file_access_class_get_pascal_string),
	JS_CFUNC_DEF("close", 0, &file_access_class_close),
};

static const JSCFunctionListEntry file_access_class_static_funcs[] = {
	JS_CFUNC_DEF("open", 2, &file_access_class_open),
	JS_CFUNC_DEF("open_encrypted", 4, &file_access_class_open_encrypted),
	JS_CFUNC_DEF("open_encrypted_with_pass", 3, &file_access_class_open_encrypted_with_pass),
	JS_CFUNC_DEF("open_compressed", 3, &file_access_class_open_compressed),
	JS_CFUNC_DEF("get_open_error", 0, &file_access_class_get_open_error),
	JS_CFUNC_DEF("create_temp", 4, &file_access_class_create_temp),
	JS_CFUNC_DEF("get_file_as_bytes", 1, &file_access_class_get_file_as_bytes),
	JS_CFUNC_DEF("get_file_as_string", 1, &file_access_class_get_file_as_string),
	JS_CFUNC_DEF("get_md5", 1, &file_access_class_get_md5),
	JS_CFUNC_DEF("get_sha256", 1, &file_access_class_get_sha256),
	JS_CFUNC_DEF("file_exists", 1, &file_access_class_file_exists),
	JS_CFUNC_DEF("get_modified_time", 1, &file_access_class_get_modified_time),
	JS_CFUNC_DEF("get_access_time", 1, &file_access_class_get_access_time),
	JS_CFUNC_DEF("get_size", 1, &file_access_class_get_size),
	JS_CFUNC_DEF("get_unix_permissions", 1, &file_access_class_get_unix_permissions),
	JS_CFUNC_DEF("set_unix_permissions", 2, &file_access_class_set_unix_permissions),
	JS_CFUNC_DEF("get_hidden_attribute", 1, &file_access_class_get_hidden_attribute),
	JS_CFUNC_DEF("set_hidden_attribute", 2, &file_access_class_set_hidden_attribute),
	JS_CFUNC_DEF("set_read_only_attribute", 2, &file_access_class_set_read_only_attribute),
	JS_CFUNC_DEF("get_read_only_attribute", 1, &file_access_class_get_read_only_attribute),
};



static void define_file_access_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "big_endian"),
        JS_NewCFunction(ctx, file_access_class_is_big_endian, "is_big_endian", 0),
        JS_NewCFunction(ctx, file_access_class_set_big_endian, "set_big_endian", 1),
        JS_PROP_GETSET
    );
}

static void define_file_access_enum(JSContext *ctx, JSValue proto) {
	JSValue ModeFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ModeFlags_obj, "READ", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ModeFlags_obj, "WRITE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ModeFlags_obj, "READ_WRITE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ModeFlags_obj, "WRITE_READ", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, proto, "ModeFlags", ModeFlags_obj);
	JSValue CompressionMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_FASTLZ", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_DEFLATE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_ZSTD", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_GZIP", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESSION_BROTLI", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "CompressionMode", CompressionMode_obj);
	JSValue UnixPermissionFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_READ_OWNER", JS_NewInt64(ctx, 256));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_WRITE_OWNER", JS_NewInt64(ctx, 128));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_EXECUTE_OWNER", JS_NewInt64(ctx, 64));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_READ_GROUP", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_WRITE_GROUP", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_EXECUTE_GROUP", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_READ_OTHER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_WRITE_OTHER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_EXECUTE_OTHER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_SET_USER_ID", JS_NewInt64(ctx, 2048));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_SET_GROUP_ID", JS_NewInt64(ctx, 1024));
	JS_SetPropertyStr(ctx, UnixPermissionFlags_obj, "UNIX_RESTRICTED_DELETE", JS_NewInt64(ctx, 512));
	JS_SetPropertyStr(ctx, proto, "UnixPermissionFlags", UnixPermissionFlags_obj);
}

static int js_file_access_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FileAccess"] = class_id;
	classes_by_id[class_id] = "FileAccess";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &file_access_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_file_access_property(ctx, proto);
	define_file_access_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, file_access_class_proto_funcs, _countof(file_access_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, file_access_class_constructor, "FileAccess", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, file_access_class_static_funcs, _countof(file_access_class_static_funcs));
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FileAccess", ctor);

	return 0;
}

JSModuleDef *_js_init_file_access_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_file_access_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FileAccess");
	return m;
}

JSModuleDef *js_init_file_access_module(JSContext *ctx) {
	return _js_init_file_access_module(ctx, "@godot/classes/file_access");
}

void __register_file_access() {
	js_init_file_access_module(js_context());
}

void register_file_access() {
	__register_file_access();
}