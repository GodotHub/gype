#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream_ogg_vorbis.hpp>
#include <godot_cpp/classes/resource_importer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/resource_importer_ogg_vorbis.hpp>
using namespace godot;

static void resource_importer_ogg_vorbis_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ResourceImporterOggVorbis"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef resource_importer_ogg_vorbis_class_def = {
    "ResourceImporterOggVorbis",
    resource_importer_ogg_vorbis_class_finalizer
};

static JSValue resource_importer_ogg_vorbis_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ResourceImporterOggVorbis"];
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
        instance = memnew(ResourceImporterOggVorbis);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}



static JSValue resource_importer_ogg_vorbis_class_load_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&ResourceImporterOggVorbis::load_from_buffer, ctx, this_val, argc, argv);
};
static JSValue resource_importer_ogg_vorbis_class_load_from_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&ResourceImporterOggVorbis::load_from_file, ctx, this_val, argc, argv);
};


static const JSCFunctionListEntry resource_importer_ogg_vorbis_class_static_funcs[] = {
	JS_CFUNC_DEF("load_from_buffer", 1, &resource_importer_ogg_vorbis_class_load_from_buffer),
	JS_CFUNC_DEF("load_from_file", 1, &resource_importer_ogg_vorbis_class_load_from_file),
};



static void define_resource_importer_ogg_vorbis_property(JSContext *ctx, JSValue proto) {
}

static void define_resource_importer_ogg_vorbis_enum(JSContext *ctx, JSValue ctor) {
}

static int js_resource_importer_ogg_vorbis_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ResourceImporterOggVorbis"] = class_id;
	classes_by_id[class_id] = "ResourceImporterOggVorbis";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &resource_importer_ogg_vorbis_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ResourceImporter"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_resource_importer_ogg_vorbis_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, resource_importer_ogg_vorbis_class_constructor, "ResourceImporterOggVorbis", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, resource_importer_ogg_vorbis_class_static_funcs, _countof(resource_importer_ogg_vorbis_class_static_funcs));
	define_resource_importer_ogg_vorbis_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ResourceImporterOggVorbis", ctor);
	ctor_list["ResourceImporterOggVorbis"] = ctor;

	return 0;
}

JSModuleDef *_js_init_resource_importer_ogg_vorbis_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource_importer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_resource_importer_ogg_vorbis_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ResourceImporterOggVorbis");
	return m;
}

JSModuleDef *js_init_resource_importer_ogg_vorbis_module(JSContext *ctx) {
	return _js_init_resource_importer_ogg_vorbis_module(ctx, "@godot/classes/resource_importer_ogg_vorbis");
}

void __register_resource_importer_ogg_vorbis() {
	js_init_resource_importer_ogg_vorbis_module(js_context());
}

void register_resource_importer_ogg_vorbis() {
	__register_resource_importer_ogg_vorbis();
}