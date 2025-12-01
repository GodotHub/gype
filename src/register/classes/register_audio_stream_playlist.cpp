#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_playlist.hpp>
using namespace godot;

static void audio_stream_playlist_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamPlaylist"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_playlist_class_def = {
    "AudioStreamPlaylist",
    audio_stream_playlist_class_finalizer
};

static JSValue audio_stream_playlist_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamPlaylist"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(AudioStreamPlaylist);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_playlist_class_set_stream_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaylist::set_stream_count, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playlist_class_get_stream_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaylist::get_stream_count, ctx, this_val, argc, argv);
}
static JSValue audio_stream_playlist_class_get_bpm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaylist::get_bpm, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playlist_class_set_list_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playlist_class_get_list_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, argv);
}
static JSValue audio_stream_playlist_class_set_shuffle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaylist::set_shuffle, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playlist_class_get_shuffle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaylist::get_shuffle, ctx, this_val, argc, argv);
}
static JSValue audio_stream_playlist_class_set_fade_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaylist::set_fade_time, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playlist_class_get_fade_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaylist::get_fade_time, ctx, this_val, argc, argv);
}
static JSValue audio_stream_playlist_class_set_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaylist::set_loop, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playlist_class_has_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaylist::has_loop, ctx, this_val, argc, argv);
}

static JSValue audio_stream_playlist_class_get_stream_0(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_0(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_1(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_1(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_3(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_3(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_4(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_4(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_5(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_5(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_6(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_6(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_7(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_7(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_9(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_9(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_10(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_10(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_11(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_11(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_12(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_12(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_13(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_13(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_14(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_14(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_15(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_15(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_16(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_16(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_17(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_17(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_18(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_18(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_19(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_19(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_20(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_20(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_21(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_21(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_22(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_22(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_23(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_23(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_24(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_24(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_25(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_25(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_26(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_26(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_27(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_27(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_28(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_28(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_29(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_29(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_30(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_30(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_31(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_31(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_33(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_33(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_34(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_34(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_35(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_35(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_36(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_36(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_37(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_37(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_38(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_38(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_39(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_39(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_40(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_40(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_41(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_41(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_42(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_42(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_43(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_43(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_44(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_44(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_45(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_45(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_46(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_46(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_47(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_47(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_48(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_48(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_49(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_49(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_50(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_50(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_51(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_51(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_52(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_52(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_53(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_53(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_54(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_54(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_55(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_55(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_56(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_56(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_57(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_57(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_58(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_58(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_59(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_59(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_60(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_60(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_61(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_61(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_62(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_62(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue audio_stream_playlist_class_get_stream_63(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&AudioStreamPlaylist::get_list_stream, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue audio_stream_playlist_class_set_stream_63(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&AudioStreamPlaylist::set_list_stream, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry audio_stream_playlist_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stream_count", 1, &audio_stream_playlist_class_set_stream_count),
	JS_CFUNC_DEF("get_stream_count", 0, &audio_stream_playlist_class_get_stream_count),
	JS_CFUNC_DEF("get_bpm", 0, &audio_stream_playlist_class_get_bpm),
	JS_CFUNC_DEF("set_list_stream", 2, &audio_stream_playlist_class_set_list_stream),
	JS_CFUNC_DEF("get_list_stream", 1, &audio_stream_playlist_class_get_list_stream),
	JS_CFUNC_DEF("set_shuffle", 1, &audio_stream_playlist_class_set_shuffle),
	JS_CFUNC_DEF("get_shuffle", 0, &audio_stream_playlist_class_get_shuffle),
	JS_CFUNC_DEF("set_fade_time", 1, &audio_stream_playlist_class_set_fade_time),
	JS_CFUNC_DEF("get_fade_time", 0, &audio_stream_playlist_class_get_fade_time),
	JS_CFUNC_DEF("set_loop", 1, &audio_stream_playlist_class_set_loop),
	JS_CFUNC_DEF("has_loop", 0, &audio_stream_playlist_class_has_loop),
    JS_CFUNC_MAGIC_DEF("get_stream_1", 0, &audio_stream_playlist_class_get_stream_1, 1),
    JS_CFUNC_MAGIC_DEF("set_stream_1", 1, &audio_stream_playlist_class_set_stream_1, 1),
    JS_CFUNC_MAGIC_DEF("get_stream_2", 0, &audio_stream_playlist_class_get_stream_2, 2),
    JS_CFUNC_MAGIC_DEF("set_stream_2", 1, &audio_stream_playlist_class_set_stream_2, 2),
    JS_CFUNC_MAGIC_DEF("get_stream_3", 0, &audio_stream_playlist_class_get_stream_3, 3),
    JS_CFUNC_MAGIC_DEF("set_stream_3", 1, &audio_stream_playlist_class_set_stream_3, 3),
    JS_CFUNC_MAGIC_DEF("get_stream_4", 0, &audio_stream_playlist_class_get_stream_4, 4),
    JS_CFUNC_MAGIC_DEF("set_stream_4", 1, &audio_stream_playlist_class_set_stream_4, 4),
    JS_CFUNC_MAGIC_DEF("get_stream_5", 0, &audio_stream_playlist_class_get_stream_5, 5),
    JS_CFUNC_MAGIC_DEF("set_stream_5", 1, &audio_stream_playlist_class_set_stream_5, 5),
    JS_CFUNC_MAGIC_DEF("get_stream_6", 0, &audio_stream_playlist_class_get_stream_6, 6),
    JS_CFUNC_MAGIC_DEF("set_stream_6", 1, &audio_stream_playlist_class_set_stream_6, 6),
    JS_CFUNC_MAGIC_DEF("get_stream_7", 0, &audio_stream_playlist_class_get_stream_7, 7),
    JS_CFUNC_MAGIC_DEF("set_stream_7", 1, &audio_stream_playlist_class_set_stream_7, 7),
    JS_CFUNC_MAGIC_DEF("get_stream_8", 0, &audio_stream_playlist_class_get_stream_8, 8),
    JS_CFUNC_MAGIC_DEF("set_stream_8", 1, &audio_stream_playlist_class_set_stream_8, 8),
    JS_CFUNC_MAGIC_DEF("get_stream_9", 0, &audio_stream_playlist_class_get_stream_9, 9),
    JS_CFUNC_MAGIC_DEF("set_stream_9", 1, &audio_stream_playlist_class_set_stream_9, 9),
    JS_CFUNC_MAGIC_DEF("get_stream_10", 0, &audio_stream_playlist_class_get_stream_10, 10),
    JS_CFUNC_MAGIC_DEF("set_stream_10", 1, &audio_stream_playlist_class_set_stream_10, 10),
    JS_CFUNC_MAGIC_DEF("get_stream_11", 0, &audio_stream_playlist_class_get_stream_11, 11),
    JS_CFUNC_MAGIC_DEF("set_stream_11", 1, &audio_stream_playlist_class_set_stream_11, 11),
    JS_CFUNC_MAGIC_DEF("get_stream_12", 0, &audio_stream_playlist_class_get_stream_12, 12),
    JS_CFUNC_MAGIC_DEF("set_stream_12", 1, &audio_stream_playlist_class_set_stream_12, 12),
    JS_CFUNC_MAGIC_DEF("get_stream_13", 0, &audio_stream_playlist_class_get_stream_13, 13),
    JS_CFUNC_MAGIC_DEF("set_stream_13", 1, &audio_stream_playlist_class_set_stream_13, 13),
    JS_CFUNC_MAGIC_DEF("get_stream_14", 0, &audio_stream_playlist_class_get_stream_14, 14),
    JS_CFUNC_MAGIC_DEF("set_stream_14", 1, &audio_stream_playlist_class_set_stream_14, 14),
    JS_CFUNC_MAGIC_DEF("get_stream_15", 0, &audio_stream_playlist_class_get_stream_15, 15),
    JS_CFUNC_MAGIC_DEF("set_stream_15", 1, &audio_stream_playlist_class_set_stream_15, 15),
    JS_CFUNC_MAGIC_DEF("get_stream_16", 0, &audio_stream_playlist_class_get_stream_16, 16),
    JS_CFUNC_MAGIC_DEF("set_stream_16", 1, &audio_stream_playlist_class_set_stream_16, 16),
    JS_CFUNC_MAGIC_DEF("get_stream_17", 0, &audio_stream_playlist_class_get_stream_17, 17),
    JS_CFUNC_MAGIC_DEF("set_stream_17", 1, &audio_stream_playlist_class_set_stream_17, 17),
    JS_CFUNC_MAGIC_DEF("get_stream_18", 0, &audio_stream_playlist_class_get_stream_18, 18),
    JS_CFUNC_MAGIC_DEF("set_stream_18", 1, &audio_stream_playlist_class_set_stream_18, 18),
    JS_CFUNC_MAGIC_DEF("get_stream_19", 0, &audio_stream_playlist_class_get_stream_19, 19),
    JS_CFUNC_MAGIC_DEF("set_stream_19", 1, &audio_stream_playlist_class_set_stream_19, 19),
    JS_CFUNC_MAGIC_DEF("get_stream_20", 0, &audio_stream_playlist_class_get_stream_20, 20),
    JS_CFUNC_MAGIC_DEF("set_stream_20", 1, &audio_stream_playlist_class_set_stream_20, 20),
    JS_CFUNC_MAGIC_DEF("get_stream_21", 0, &audio_stream_playlist_class_get_stream_21, 21),
    JS_CFUNC_MAGIC_DEF("set_stream_21", 1, &audio_stream_playlist_class_set_stream_21, 21),
    JS_CFUNC_MAGIC_DEF("get_stream_22", 0, &audio_stream_playlist_class_get_stream_22, 22),
    JS_CFUNC_MAGIC_DEF("set_stream_22", 1, &audio_stream_playlist_class_set_stream_22, 22),
    JS_CFUNC_MAGIC_DEF("get_stream_23", 0, &audio_stream_playlist_class_get_stream_23, 23),
    JS_CFUNC_MAGIC_DEF("set_stream_23", 1, &audio_stream_playlist_class_set_stream_23, 23),
    JS_CFUNC_MAGIC_DEF("get_stream_24", 0, &audio_stream_playlist_class_get_stream_24, 24),
    JS_CFUNC_MAGIC_DEF("set_stream_24", 1, &audio_stream_playlist_class_set_stream_24, 24),
    JS_CFUNC_MAGIC_DEF("get_stream_25", 0, &audio_stream_playlist_class_get_stream_25, 25),
    JS_CFUNC_MAGIC_DEF("set_stream_25", 1, &audio_stream_playlist_class_set_stream_25, 25),
    JS_CFUNC_MAGIC_DEF("get_stream_26", 0, &audio_stream_playlist_class_get_stream_26, 26),
    JS_CFUNC_MAGIC_DEF("set_stream_26", 1, &audio_stream_playlist_class_set_stream_26, 26),
    JS_CFUNC_MAGIC_DEF("get_stream_27", 0, &audio_stream_playlist_class_get_stream_27, 27),
    JS_CFUNC_MAGIC_DEF("set_stream_27", 1, &audio_stream_playlist_class_set_stream_27, 27),
    JS_CFUNC_MAGIC_DEF("get_stream_28", 0, &audio_stream_playlist_class_get_stream_28, 28),
    JS_CFUNC_MAGIC_DEF("set_stream_28", 1, &audio_stream_playlist_class_set_stream_28, 28),
    JS_CFUNC_MAGIC_DEF("get_stream_29", 0, &audio_stream_playlist_class_get_stream_29, 29),
    JS_CFUNC_MAGIC_DEF("set_stream_29", 1, &audio_stream_playlist_class_set_stream_29, 29),
    JS_CFUNC_MAGIC_DEF("get_stream_30", 0, &audio_stream_playlist_class_get_stream_30, 30),
    JS_CFUNC_MAGIC_DEF("set_stream_30", 1, &audio_stream_playlist_class_set_stream_30, 30),
    JS_CFUNC_MAGIC_DEF("get_stream_31", 0, &audio_stream_playlist_class_get_stream_31, 31),
    JS_CFUNC_MAGIC_DEF("set_stream_31", 1, &audio_stream_playlist_class_set_stream_31, 31),
    JS_CFUNC_MAGIC_DEF("get_stream_32", 0, &audio_stream_playlist_class_get_stream_32, 32),
    JS_CFUNC_MAGIC_DEF("set_stream_32", 1, &audio_stream_playlist_class_set_stream_32, 32),
    JS_CFUNC_MAGIC_DEF("get_stream_33", 0, &audio_stream_playlist_class_get_stream_33, 33),
    JS_CFUNC_MAGIC_DEF("set_stream_33", 1, &audio_stream_playlist_class_set_stream_33, 33),
    JS_CFUNC_MAGIC_DEF("get_stream_34", 0, &audio_stream_playlist_class_get_stream_34, 34),
    JS_CFUNC_MAGIC_DEF("set_stream_34", 1, &audio_stream_playlist_class_set_stream_34, 34),
    JS_CFUNC_MAGIC_DEF("get_stream_35", 0, &audio_stream_playlist_class_get_stream_35, 35),
    JS_CFUNC_MAGIC_DEF("set_stream_35", 1, &audio_stream_playlist_class_set_stream_35, 35),
    JS_CFUNC_MAGIC_DEF("get_stream_36", 0, &audio_stream_playlist_class_get_stream_36, 36),
    JS_CFUNC_MAGIC_DEF("set_stream_36", 1, &audio_stream_playlist_class_set_stream_36, 36),
    JS_CFUNC_MAGIC_DEF("get_stream_37", 0, &audio_stream_playlist_class_get_stream_37, 37),
    JS_CFUNC_MAGIC_DEF("set_stream_37", 1, &audio_stream_playlist_class_set_stream_37, 37),
    JS_CFUNC_MAGIC_DEF("get_stream_38", 0, &audio_stream_playlist_class_get_stream_38, 38),
    JS_CFUNC_MAGIC_DEF("set_stream_38", 1, &audio_stream_playlist_class_set_stream_38, 38),
    JS_CFUNC_MAGIC_DEF("get_stream_39", 0, &audio_stream_playlist_class_get_stream_39, 39),
    JS_CFUNC_MAGIC_DEF("set_stream_39", 1, &audio_stream_playlist_class_set_stream_39, 39),
    JS_CFUNC_MAGIC_DEF("get_stream_40", 0, &audio_stream_playlist_class_get_stream_40, 40),
    JS_CFUNC_MAGIC_DEF("set_stream_40", 1, &audio_stream_playlist_class_set_stream_40, 40),
    JS_CFUNC_MAGIC_DEF("get_stream_41", 0, &audio_stream_playlist_class_get_stream_41, 41),
    JS_CFUNC_MAGIC_DEF("set_stream_41", 1, &audio_stream_playlist_class_set_stream_41, 41),
    JS_CFUNC_MAGIC_DEF("get_stream_42", 0, &audio_stream_playlist_class_get_stream_42, 42),
    JS_CFUNC_MAGIC_DEF("set_stream_42", 1, &audio_stream_playlist_class_set_stream_42, 42),
    JS_CFUNC_MAGIC_DEF("get_stream_43", 0, &audio_stream_playlist_class_get_stream_43, 43),
    JS_CFUNC_MAGIC_DEF("set_stream_43", 1, &audio_stream_playlist_class_set_stream_43, 43),
    JS_CFUNC_MAGIC_DEF("get_stream_44", 0, &audio_stream_playlist_class_get_stream_44, 44),
    JS_CFUNC_MAGIC_DEF("set_stream_44", 1, &audio_stream_playlist_class_set_stream_44, 44),
    JS_CFUNC_MAGIC_DEF("get_stream_45", 0, &audio_stream_playlist_class_get_stream_45, 45),
    JS_CFUNC_MAGIC_DEF("set_stream_45", 1, &audio_stream_playlist_class_set_stream_45, 45),
    JS_CFUNC_MAGIC_DEF("get_stream_46", 0, &audio_stream_playlist_class_get_stream_46, 46),
    JS_CFUNC_MAGIC_DEF("set_stream_46", 1, &audio_stream_playlist_class_set_stream_46, 46),
    JS_CFUNC_MAGIC_DEF("get_stream_47", 0, &audio_stream_playlist_class_get_stream_47, 47),
    JS_CFUNC_MAGIC_DEF("set_stream_47", 1, &audio_stream_playlist_class_set_stream_47, 47),
    JS_CFUNC_MAGIC_DEF("get_stream_48", 0, &audio_stream_playlist_class_get_stream_48, 48),
    JS_CFUNC_MAGIC_DEF("set_stream_48", 1, &audio_stream_playlist_class_set_stream_48, 48),
    JS_CFUNC_MAGIC_DEF("get_stream_49", 0, &audio_stream_playlist_class_get_stream_49, 49),
    JS_CFUNC_MAGIC_DEF("set_stream_49", 1, &audio_stream_playlist_class_set_stream_49, 49),
    JS_CFUNC_MAGIC_DEF("get_stream_50", 0, &audio_stream_playlist_class_get_stream_50, 50),
    JS_CFUNC_MAGIC_DEF("set_stream_50", 1, &audio_stream_playlist_class_set_stream_50, 50),
    JS_CFUNC_MAGIC_DEF("get_stream_51", 0, &audio_stream_playlist_class_get_stream_51, 51),
    JS_CFUNC_MAGIC_DEF("set_stream_51", 1, &audio_stream_playlist_class_set_stream_51, 51),
    JS_CFUNC_MAGIC_DEF("get_stream_52", 0, &audio_stream_playlist_class_get_stream_52, 52),
    JS_CFUNC_MAGIC_DEF("set_stream_52", 1, &audio_stream_playlist_class_set_stream_52, 52),
    JS_CFUNC_MAGIC_DEF("get_stream_53", 0, &audio_stream_playlist_class_get_stream_53, 53),
    JS_CFUNC_MAGIC_DEF("set_stream_53", 1, &audio_stream_playlist_class_set_stream_53, 53),
    JS_CFUNC_MAGIC_DEF("get_stream_54", 0, &audio_stream_playlist_class_get_stream_54, 54),
    JS_CFUNC_MAGIC_DEF("set_stream_54", 1, &audio_stream_playlist_class_set_stream_54, 54),
    JS_CFUNC_MAGIC_DEF("get_stream_55", 0, &audio_stream_playlist_class_get_stream_55, 55),
    JS_CFUNC_MAGIC_DEF("set_stream_55", 1, &audio_stream_playlist_class_set_stream_55, 55),
    JS_CFUNC_MAGIC_DEF("get_stream_56", 0, &audio_stream_playlist_class_get_stream_56, 56),
    JS_CFUNC_MAGIC_DEF("set_stream_56", 1, &audio_stream_playlist_class_set_stream_56, 56),
    JS_CFUNC_MAGIC_DEF("get_stream_57", 0, &audio_stream_playlist_class_get_stream_57, 57),
    JS_CFUNC_MAGIC_DEF("set_stream_57", 1, &audio_stream_playlist_class_set_stream_57, 57),
    JS_CFUNC_MAGIC_DEF("get_stream_58", 0, &audio_stream_playlist_class_get_stream_58, 58),
    JS_CFUNC_MAGIC_DEF("set_stream_58", 1, &audio_stream_playlist_class_set_stream_58, 58),
    JS_CFUNC_MAGIC_DEF("get_stream_59", 0, &audio_stream_playlist_class_get_stream_59, 59),
    JS_CFUNC_MAGIC_DEF("set_stream_59", 1, &audio_stream_playlist_class_set_stream_59, 59),
    JS_CFUNC_MAGIC_DEF("get_stream_60", 0, &audio_stream_playlist_class_get_stream_60, 60),
    JS_CFUNC_MAGIC_DEF("set_stream_60", 1, &audio_stream_playlist_class_set_stream_60, 60),
    JS_CFUNC_MAGIC_DEF("get_stream_61", 0, &audio_stream_playlist_class_get_stream_61, 61),
    JS_CFUNC_MAGIC_DEF("set_stream_61", 1, &audio_stream_playlist_class_set_stream_61, 61),
    JS_CFUNC_MAGIC_DEF("get_stream_62", 0, &audio_stream_playlist_class_get_stream_62, 62),
    JS_CFUNC_MAGIC_DEF("set_stream_62", 1, &audio_stream_playlist_class_set_stream_62, 62),
    JS_CFUNC_MAGIC_DEF("get_stream_63", 0, &audio_stream_playlist_class_get_stream_63, 63),
    JS_CFUNC_MAGIC_DEF("set_stream_63", 1, &audio_stream_playlist_class_set_stream_63, 63),
};




static void define_audio_stream_playlist_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shuffle"),
        JS_NewCFunction(ctx, audio_stream_playlist_class_get_shuffle, "get_shuffle", 0),
        JS_NewCFunction(ctx, audio_stream_playlist_class_set_shuffle, "set_shuffle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop"),
        JS_NewCFunction(ctx, audio_stream_playlist_class_has_loop, "has_loop", 0),
        JS_NewCFunction(ctx, audio_stream_playlist_class_set_loop, "set_loop", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fade_time"),
        JS_NewCFunction(ctx, audio_stream_playlist_class_get_fade_time, "get_fade_time", 0),
        JS_NewCFunction(ctx, audio_stream_playlist_class_set_fade_time, "set_fade_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stream_count"),
        JS_NewCFunction(ctx, audio_stream_playlist_class_get_stream_count, "get_stream_count", 0),
        JS_NewCFunction(ctx, audio_stream_playlist_class_set_stream_count, "set_stream_count", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_0"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_0, "get_stream_0", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_0, "set_stream_0", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_1"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_1, "get_stream_1", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_1, "set_stream_1", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_2"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_2, "get_stream_2", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_2, "set_stream_2", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_3"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_3, "get_stream_3", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_3, "set_stream_3", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_4"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_4, "get_stream_4", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_4, "set_stream_4", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_5"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_5, "get_stream_5", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_5, "set_stream_5", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_6"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_6, "get_stream_6", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_6, "set_stream_6", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_7"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_7, "get_stream_7", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_7, "set_stream_7", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_8"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_8, "get_stream_8", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_8, "set_stream_8", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_9"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_9, "get_stream_9", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_9, "set_stream_9", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_10"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_10, "get_stream_10", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_10, "set_stream_10", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_11"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_11, "get_stream_11", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_11, "set_stream_11", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_12"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_12, "get_stream_12", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_12, "set_stream_12", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_13"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_13, "get_stream_13", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 13),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_13, "set_stream_13", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 13),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_14"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_14, "get_stream_14", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 14),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_14, "set_stream_14", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 14),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_15"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_15, "get_stream_15", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 15),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_15, "set_stream_15", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 15),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_16"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_16, "get_stream_16", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 16),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_16, "set_stream_16", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 16),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_17"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_17, "get_stream_17", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 17),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_17, "set_stream_17", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 17),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_18"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_18, "get_stream_18", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 18),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_18, "set_stream_18", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 18),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_19"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_19, "get_stream_19", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 19),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_19, "set_stream_19", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 19),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_20"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_20, "get_stream_20", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 20),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_20, "set_stream_20", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 20),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_21"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_21, "get_stream_21", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 21),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_21, "set_stream_21", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 21),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_22"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_22, "get_stream_22", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 22),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_22, "set_stream_22", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 22),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_23"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_23, "get_stream_23", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 23),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_23, "set_stream_23", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 23),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_24"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_24, "get_stream_24", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 24),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_24, "set_stream_24", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 24),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_25"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_25, "get_stream_25", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 25),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_25, "set_stream_25", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 25),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_26"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_26, "get_stream_26", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 26),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_26, "set_stream_26", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 26),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_27"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_27, "get_stream_27", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 27),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_27, "set_stream_27", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 27),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_28"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_28, "get_stream_28", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 28),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_28, "set_stream_28", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 28),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_29"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_29, "get_stream_29", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 29),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_29, "set_stream_29", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 29),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_30"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_30, "get_stream_30", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 30),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_30, "set_stream_30", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 30),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_31"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_31, "get_stream_31", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 31),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_31, "set_stream_31", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 31),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_32"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_32, "get_stream_32", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 32),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_32, "set_stream_32", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 32),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_33"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_33, "get_stream_33", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 33),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_33, "set_stream_33", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 33),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_34"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_34, "get_stream_34", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 34),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_34, "set_stream_34", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 34),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_35"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_35, "get_stream_35", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 35),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_35, "set_stream_35", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 35),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_36"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_36, "get_stream_36", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 36),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_36, "set_stream_36", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 36),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_37"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_37, "get_stream_37", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 37),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_37, "set_stream_37", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 37),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_38"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_38, "get_stream_38", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 38),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_38, "set_stream_38", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 38),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_39"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_39, "get_stream_39", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 39),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_39, "set_stream_39", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 39),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_40"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_40, "get_stream_40", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 40),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_40, "set_stream_40", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 40),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_41"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_41, "get_stream_41", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 41),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_41, "set_stream_41", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 41),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_42"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_42, "get_stream_42", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 42),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_42, "set_stream_42", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 42),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_43"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_43, "get_stream_43", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 43),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_43, "set_stream_43", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 43),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_44"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_44, "get_stream_44", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 44),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_44, "set_stream_44", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 44),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_45"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_45, "get_stream_45", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 45),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_45, "set_stream_45", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 45),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_46"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_46, "get_stream_46", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 46),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_46, "set_stream_46", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 46),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_47"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_47, "get_stream_47", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 47),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_47, "set_stream_47", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 47),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_48"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_48, "get_stream_48", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 48),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_48, "set_stream_48", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 48),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_49"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_49, "get_stream_49", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 49),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_49, "set_stream_49", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 49),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_50"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_50, "get_stream_50", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 50),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_50, "set_stream_50", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 50),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_51"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_51, "get_stream_51", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 51),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_51, "set_stream_51", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 51),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_52"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_52, "get_stream_52", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 52),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_52, "set_stream_52", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 52),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_53"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_53, "get_stream_53", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 53),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_53, "set_stream_53", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 53),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_54"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_54, "get_stream_54", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 54),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_54, "set_stream_54", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 54),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_55"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_55, "get_stream_55", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 55),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_55, "set_stream_55", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 55),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_56"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_56, "get_stream_56", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 56),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_56, "set_stream_56", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 56),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_57"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_57, "get_stream_57", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 57),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_57, "set_stream_57", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 57),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_58"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_58, "get_stream_58", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 58),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_58, "set_stream_58", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 58),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_59"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_59, "get_stream_59", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 59),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_59, "set_stream_59", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 59),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_60"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_60, "get_stream_60", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 60),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_60, "set_stream_60", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 60),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_61"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_61, "get_stream_61", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 61),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_61, "set_stream_61", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 61),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_62"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_62, "get_stream_62", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 62),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_62, "set_stream_62", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 62),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stream_63"),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_get_stream_63, "get_stream_63", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 63),
		JS_NewCFunctionMagic(ctx, audio_stream_playlist_class_set_stream_63, "set_stream_63", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 63),
		JS_PROP_GETSET
	);
}

static void define_audio_stream_playlist_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_stream_playlist_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamPlaylist"] = class_id;
	classes_by_id[class_id] = "AudioStreamPlaylist";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_playlist_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStream"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_playlist_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_playlist_class_proto_funcs, _countof(audio_stream_playlist_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_playlist_class_constructor, "AudioStreamPlaylist", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_playlist_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamPlaylist", ctor);
	ctor_list["AudioStreamPlaylist"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_stream_playlist_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_playlist_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamPlaylist");
	return m;
}

JSModuleDef *js_init_audio_stream_playlist_module(JSContext *ctx) {
	return _js_init_audio_stream_playlist_module(ctx, "@godot/classes/audio_stream_playlist");
}

void __register_audio_stream_playlist() {
	js_init_audio_stream_playlist_module(js_context());
}

void register_audio_stream_playlist() {
	__register_audio_stream_playlist();
}