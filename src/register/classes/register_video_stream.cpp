#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/video_stream_playback.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/video_stream.hpp>
using namespace godot;

static void video_stream_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VideoStream"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef video_stream_class_def = {
    "VideoStream",
    video_stream_class_finalizer
};

static JSValue video_stream_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VideoStream"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    VideoStream *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<VideoStream *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(VideoStream);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue video_stream_class_set_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStream::set_file, ctx, this_val, argc, argv);
};
static JSValue video_stream_class_get_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&VideoStream::get_file, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry video_stream_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_file", 1, &video_stream_class_set_file),
	JS_CFUNC_DEF("get_file", 0, &video_stream_class_get_file),
};




static void define_video_stream_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "file"),
        JS_NewCFunction(ctx, video_stream_class_get_file, "get_file", 0),
        JS_NewCFunction(ctx, video_stream_class_set_file, "set_file", 1),
        JS_PROP_GETSET
    );
}

static void define_video_stream_enum(JSContext *ctx, JSValue ctor) {
}

static int js_video_stream_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VideoStream"] = class_id;
	classes_by_id[class_id] = "VideoStream";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &video_stream_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_video_stream_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, video_stream_class_proto_funcs, _countof(video_stream_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, video_stream_class_constructor, "VideoStream", 0, JS_CFUNC_constructor, 0);
	define_video_stream_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VideoStream", ctor);

	return 0;
}

JSModuleDef *_js_init_video_stream_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_video_stream_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VideoStream");
	return m;
}

JSModuleDef *js_init_video_stream_module(JSContext *ctx) {
	return _js_init_video_stream_module(ctx, "@godot/classes/video_stream");
}

void __register_video_stream() {
	js_init_video_stream_module(js_context());
}

void register_video_stream() {
	__register_video_stream();
}