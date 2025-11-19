#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/confirmation_dialog.hpp>
#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/file_dialog.hpp>
using namespace godot;

static void file_dialog_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FileDialog"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef file_dialog_class_def = {
    "FileDialog",
    file_dialog_class_finalizer
};

static JSValue file_dialog_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FileDialog"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FileDialog *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FileDialog *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FileDialog);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue file_dialog_class_clear_filters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::clear_filters, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_add_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::add_filter, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_filters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_filters, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_filters(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		FileDialog *obj = static_cast<FileDialog *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_filters();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		FileDialog *js_proxy = static_cast<FileDialog *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_filters(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue file_dialog_class_clear_filename_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::clear_filename_filter, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_filename_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_filename_filter, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_filename_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_filename_filter, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_get_option_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_option_name, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_option_values(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_option_values, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_option_default(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_option_default, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_option_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_option_name, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_option_values(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_option_values, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_option_default(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_option_default, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_option_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_option_count, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_option_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_option_count, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_add_option(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::add_option, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_selected_options(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_selected_options, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_current_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_current_dir, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_get_current_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_current_file, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_get_current_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_current_path, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_current_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_current_dir, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_current_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_current_file, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_current_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_current_path, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_mode_overrides_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_mode_overrides_title, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_is_mode_overriding_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::is_mode_overriding_title, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_file_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_file_mode, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_file_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_file_mode, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_display_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_display_mode, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_display_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_display_mode, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_get_vbox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileDialog::get_vbox, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_line_edit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FileDialog::get_line_edit, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_set_access(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_access, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_access(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_access, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_root_subfolder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_root_subfolder, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_root_subfolder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_root_subfolder, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_show_hidden_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_show_hidden_files, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_is_showing_hidden_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::is_showing_hidden_files, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_use_native_dialog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_use_native_dialog, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_get_use_native_dialog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::get_use_native_dialog, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_set_customization_flag_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_is_customization_flag_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, argv);
}
static JSValue file_dialog_class_deselect_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::deselect_all, ctx, this_val, argc, argv);
};
static JSValue file_dialog_class_invalidate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FileDialog::invalidate, ctx, this_val, argc, argv);
};

static JSValue file_dialog_class_get_hidden_files_toggle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_hidden_files_toggle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue file_dialog_class_get_file_filter_toggle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_file_filter_toggle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue file_dialog_class_get_file_sort_options_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_file_sort_options_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue file_dialog_class_get_folder_creation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_folder_creation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue file_dialog_class_get_favorites_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_favorites_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue file_dialog_class_get_recent_list_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_recent_list_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue file_dialog_class_get_layout_toggle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&FileDialog::is_customization_flag_enabled, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue file_dialog_class_set_layout_toggle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&FileDialog::set_customization_flag_enabled, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry file_dialog_class_proto_funcs[] = {
	JS_CFUNC_DEF("clear_filters", 0, &file_dialog_class_clear_filters),
	JS_CFUNC_DEF("add_filter", 2, &file_dialog_class_add_filter),
	JS_CFUNC_DEF("set_filters", 1, &file_dialog_class_set_filters),
	JS_CFUNC_DEF("get_filters", 0, &file_dialog_class_get_filters),
	JS_CFUNC_DEF("clear_filename_filter", 0, &file_dialog_class_clear_filename_filter),
	JS_CFUNC_DEF("set_filename_filter", 1, &file_dialog_class_set_filename_filter),
	JS_CFUNC_DEF("get_filename_filter", 0, &file_dialog_class_get_filename_filter),
	JS_CFUNC_DEF("get_option_name", 1, &file_dialog_class_get_option_name),
	JS_CFUNC_DEF("get_option_values", 1, &file_dialog_class_get_option_values),
	JS_CFUNC_DEF("get_option_default", 1, &file_dialog_class_get_option_default),
	JS_CFUNC_DEF("set_option_name", 2, &file_dialog_class_set_option_name),
	JS_CFUNC_DEF("set_option_values", 2, &file_dialog_class_set_option_values),
	JS_CFUNC_DEF("set_option_default", 2, &file_dialog_class_set_option_default),
	JS_CFUNC_DEF("set_option_count", 1, &file_dialog_class_set_option_count),
	JS_CFUNC_DEF("get_option_count", 0, &file_dialog_class_get_option_count),
	JS_CFUNC_DEF("add_option", 3, &file_dialog_class_add_option),
	JS_CFUNC_DEF("get_selected_options", 0, &file_dialog_class_get_selected_options),
	JS_CFUNC_DEF("get_current_dir", 0, &file_dialog_class_get_current_dir),
	JS_CFUNC_DEF("get_current_file", 0, &file_dialog_class_get_current_file),
	JS_CFUNC_DEF("get_current_path", 0, &file_dialog_class_get_current_path),
	JS_CFUNC_DEF("set_current_dir", 1, &file_dialog_class_set_current_dir),
	JS_CFUNC_DEF("set_current_file", 1, &file_dialog_class_set_current_file),
	JS_CFUNC_DEF("set_current_path", 1, &file_dialog_class_set_current_path),
	JS_CFUNC_DEF("set_mode_overrides_title", 1, &file_dialog_class_set_mode_overrides_title),
	JS_CFUNC_DEF("is_mode_overriding_title", 0, &file_dialog_class_is_mode_overriding_title),
	JS_CFUNC_DEF("set_file_mode", 1, &file_dialog_class_set_file_mode),
	JS_CFUNC_DEF("get_file_mode", 0, &file_dialog_class_get_file_mode),
	JS_CFUNC_DEF("set_display_mode", 1, &file_dialog_class_set_display_mode),
	JS_CFUNC_DEF("get_display_mode", 0, &file_dialog_class_get_display_mode),
	JS_CFUNC_DEF("get_vbox", 0, &file_dialog_class_get_vbox),
	JS_CFUNC_DEF("get_line_edit", 0, &file_dialog_class_get_line_edit),
	JS_CFUNC_DEF("set_access", 1, &file_dialog_class_set_access),
	JS_CFUNC_DEF("get_access", 0, &file_dialog_class_get_access),
	JS_CFUNC_DEF("set_root_subfolder", 1, &file_dialog_class_set_root_subfolder),
	JS_CFUNC_DEF("get_root_subfolder", 0, &file_dialog_class_get_root_subfolder),
	JS_CFUNC_DEF("set_show_hidden_files", 1, &file_dialog_class_set_show_hidden_files),
	JS_CFUNC_DEF("is_showing_hidden_files", 0, &file_dialog_class_is_showing_hidden_files),
	JS_CFUNC_DEF("set_use_native_dialog", 1, &file_dialog_class_set_use_native_dialog),
	JS_CFUNC_DEF("get_use_native_dialog", 0, &file_dialog_class_get_use_native_dialog),
	JS_CFUNC_DEF("set_customization_flag_enabled", 2, &file_dialog_class_set_customization_flag_enabled),
	JS_CFUNC_DEF("is_customization_flag_enabled", 1, &file_dialog_class_is_customization_flag_enabled),
	JS_CFUNC_DEF("deselect_all", 0, &file_dialog_class_deselect_all),
	JS_CFUNC_DEF("invalidate", 0, &file_dialog_class_invalidate),
    JS_CFUNC_MAGIC_DEF("get_file_filter_toggle_enabled", 0, &file_dialog_class_get_file_filter_toggle_enabled, 2),
    JS_CFUNC_MAGIC_DEF("set_file_filter_toggle_enabled", 1, &file_dialog_class_set_file_filter_toggle_enabled, 2),
    JS_CFUNC_MAGIC_DEF("get_file_sort_options_enabled", 0, &file_dialog_class_get_file_sort_options_enabled, 3),
    JS_CFUNC_MAGIC_DEF("set_file_sort_options_enabled", 1, &file_dialog_class_set_file_sort_options_enabled, 3),
    JS_CFUNC_MAGIC_DEF("get_folder_creation_enabled", 0, &file_dialog_class_get_folder_creation_enabled, 1),
    JS_CFUNC_MAGIC_DEF("set_folder_creation_enabled", 1, &file_dialog_class_set_folder_creation_enabled, 1),
    JS_CFUNC_MAGIC_DEF("get_favorites_enabled", 0, &file_dialog_class_get_favorites_enabled, 4),
    JS_CFUNC_MAGIC_DEF("set_favorites_enabled", 1, &file_dialog_class_set_favorites_enabled, 4),
    JS_CFUNC_MAGIC_DEF("get_recent_list_enabled", 0, &file_dialog_class_get_recent_list_enabled, 5),
    JS_CFUNC_MAGIC_DEF("set_recent_list_enabled", 1, &file_dialog_class_set_recent_list_enabled, 5),
    JS_CFUNC_MAGIC_DEF("get_layout_toggle_enabled", 0, &file_dialog_class_get_layout_toggle_enabled, 6),
    JS_CFUNC_MAGIC_DEF("set_layout_toggle_enabled", 1, &file_dialog_class_set_layout_toggle_enabled, 6),
};


static JSValue file_dialog_class_get_file_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	FileDialog *opaque = static_cast<FileDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "file_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "file_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "file_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue file_dialog_class_get_files_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	FileDialog *opaque = static_cast<FileDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "files_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "files_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "files_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue file_dialog_class_get_dir_selected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	FileDialog *opaque = static_cast<FileDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "dir_selected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "dir_selected"));
		JS_DefinePropertyValueStr(ctx, this_val, "dir_selected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue file_dialog_class_get_filename_filter_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	FileDialog *opaque = static_cast<FileDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "filename_filter_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "filename_filter_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "filename_filter_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_file_dialog_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mode_overrides_title"),
        JS_NewCFunction(ctx, file_dialog_class_is_mode_overriding_title, "is_mode_overriding_title", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_mode_overrides_title, "set_mode_overrides_title", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "file_mode"),
        JS_NewCFunction(ctx, file_dialog_class_get_file_mode, "get_file_mode", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_file_mode, "set_file_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "display_mode"),
        JS_NewCFunction(ctx, file_dialog_class_get_display_mode, "get_display_mode", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_display_mode, "set_display_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "access"),
        JS_NewCFunction(ctx, file_dialog_class_get_access, "get_access", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_access, "set_access", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root_subfolder"),
        JS_NewCFunction(ctx, file_dialog_class_get_root_subfolder, "get_root_subfolder", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_root_subfolder, "set_root_subfolder", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filters"),
        JS_NewCFunction(ctx, file_dialog_class_get_filters, "get_filters", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_filters, "set_filters", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filename_filter"),
        JS_NewCFunction(ctx, file_dialog_class_get_filename_filter, "get_filename_filter", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_filename_filter, "set_filename_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_hidden_files"),
        JS_NewCFunction(ctx, file_dialog_class_is_showing_hidden_files, "is_showing_hidden_files", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_show_hidden_files, "set_show_hidden_files", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_native_dialog"),
        JS_NewCFunction(ctx, file_dialog_class_get_use_native_dialog, "get_use_native_dialog", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_use_native_dialog, "set_use_native_dialog", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "option_count"),
        JS_NewCFunction(ctx, file_dialog_class_get_option_count, "get_option_count", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_option_count, "set_option_count", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "hidden_files_toggle_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_hidden_files_toggle_enabled, "get_hidden_files_toggle_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_hidden_files_toggle_enabled, "set_hidden_files_toggle_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "file_filter_toggle_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_file_filter_toggle_enabled, "get_file_filter_toggle_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_file_filter_toggle_enabled, "set_file_filter_toggle_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "file_sort_options_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_file_sort_options_enabled, "get_file_sort_options_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_file_sort_options_enabled, "set_file_sort_options_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "folder_creation_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_folder_creation_enabled, "get_folder_creation_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_folder_creation_enabled, "set_folder_creation_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "favorites_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_favorites_enabled, "get_favorites_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_favorites_enabled, "set_favorites_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "recent_list_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_recent_list_enabled, "get_recent_list_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_recent_list_enabled, "set_recent_list_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "layout_toggle_enabled"),
		JS_NewCFunctionMagic(ctx, file_dialog_class_get_layout_toggle_enabled, "get_layout_toggle_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, file_dialog_class_set_layout_toggle_enabled, "set_layout_toggle_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_dir"),
        JS_NewCFunction(ctx, file_dialog_class_get_current_dir, "get_current_dir", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_current_dir, "set_current_dir", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_file"),
        JS_NewCFunction(ctx, file_dialog_class_get_current_file, "get_current_file", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_current_file, "set_current_file", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_path"),
        JS_NewCFunction(ctx, file_dialog_class_get_current_path, "get_current_path", 0),
        JS_NewCFunction(ctx, file_dialog_class_set_current_path, "set_current_path", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "file_selected"),
		JS_NewCFunction(ctx, file_dialog_class_get_file_selected_signal, "get_file_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "files_selected"),
		JS_NewCFunction(ctx, file_dialog_class_get_files_selected_signal, "get_files_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "dir_selected"),
		JS_NewCFunction(ctx, file_dialog_class_get_dir_selected_signal, "get_dir_selected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "filename_filter_changed"),
		JS_NewCFunction(ctx, file_dialog_class_get_filename_filter_changed_signal, "get_filename_filter_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_file_dialog_enum(JSContext *ctx, JSValue ctor) {
	JSValue FileMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FileMode_obj, "FILE_MODE_OPEN_FILE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FileMode_obj, "FILE_MODE_OPEN_FILES", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FileMode_obj, "FILE_MODE_OPEN_DIR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FileMode_obj, "FILE_MODE_OPEN_ANY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, FileMode_obj, "FILE_MODE_SAVE_FILE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "FileMode", FileMode_obj);
	JSValue Access_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Access_obj, "ACCESS_RESOURCES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Access_obj, "ACCESS_USERDATA", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Access_obj, "ACCESS_FILESYSTEM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Access", Access_obj);
	JSValue DisplayMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DisplayMode_obj, "DISPLAY_THUMBNAILS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DisplayMode_obj, "DISPLAY_LIST", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "DisplayMode", DisplayMode_obj);
	JSValue Customization_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_HIDDEN_FILES", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_CREATE_FOLDER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_FILE_FILTER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_FILE_SORT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_FAVORITES", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_RECENT", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Customization_obj, "CUSTOMIZATION_LAYOUT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "Customization", Customization_obj);
}

static int js_file_dialog_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FileDialog"] = class_id;
	classes_by_id[class_id] = "FileDialog";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &file_dialog_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ConfirmationDialog"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_file_dialog_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, file_dialog_class_proto_funcs, _countof(file_dialog_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, file_dialog_class_constructor, "FileDialog", 0, JS_CFUNC_constructor, 0);
	define_file_dialog_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FileDialog", ctor);

	return 0;
}

JSModuleDef *_js_init_file_dialog_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/confirmation_dialog';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_file_dialog_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FileDialog");
	return m;
}

JSModuleDef *js_init_file_dialog_module(JSContext *ctx) {
	return _js_init_file_dialog_module(ctx, "@godot/classes/file_dialog");
}

void __register_file_dialog() {
	js_init_file_dialog_module(js_context());
}

void register_file_dialog() {
	__register_file_dialog();
}