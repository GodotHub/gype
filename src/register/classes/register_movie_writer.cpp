#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/movie_writer.hpp>
using namespace godot;

static void movie_writer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MovieWriter"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef movie_writer_class_def = {
    "MovieWriter",
    movie_writer_class_finalizer
};

static JSValue movie_writer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MovieWriter"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MovieWriter *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MovieWriter *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MovieWriter);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue movie_writer_class_add_writer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&MovieWriter::add_writer, ctx, this_val, argc, argv);
};


static const JSCFunctionListEntry movie_writer_class_static_funcs[] = {
	JS_CFUNC_DEF("add_writer", 1, &movie_writer_class_add_writer),
};



static void define_movie_writer_property(JSContext *ctx, JSValue proto) {
}

static void define_movie_writer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_movie_writer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MovieWriter"] = class_id;
	classes_by_id[class_id] = "MovieWriter";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &movie_writer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_movie_writer_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, movie_writer_class_constructor, "MovieWriter", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, movie_writer_class_static_funcs, _countof(movie_writer_class_static_funcs));
	define_movie_writer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MovieWriter", ctor);

	return 0;
}

JSModuleDef *_js_init_movie_writer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_movie_writer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MovieWriter");
	return m;
}

JSModuleDef *js_init_movie_writer_module(JSContext *ctx) {
	return _js_init_movie_writer_module(ctx, "@godot/classes/movie_writer");
}

void __register_movie_writer() {
	js_init_movie_writer_module(js_context());
}

void register_movie_writer() {
	__register_movie_writer();
}