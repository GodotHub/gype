#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/shortcut.hpp>
using namespace godot;

static void shortcut_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Shortcut"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef shortcut_class_def = {
    "Shortcut",
    shortcut_class_finalizer
};

static JSValue shortcut_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Shortcut"];
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
        instance = memnew(Shortcut);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue shortcut_class_set_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Shortcut::set_events, ctx, this_val, argc, argv);
};
static JSValue shortcut_class_get_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shortcut::get_events, ctx, this_val, argc, argv);
}
static JSValue shortcut_class_has_valid_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shortcut::has_valid_event, ctx, this_val, argc, argv);
};
static JSValue shortcut_class_matches_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shortcut::matches_event, ctx, this_val, argc, argv);
};
static JSValue shortcut_class_get_as_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Shortcut::get_as_text, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry shortcut_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_events", 1, &shortcut_class_set_events),
	JS_CFUNC_DEF("get_events", 0, &shortcut_class_get_events),
	JS_CFUNC_DEF("has_valid_event", 0, &shortcut_class_has_valid_event),
	JS_CFUNC_DEF("matches_event", 1, &shortcut_class_matches_event),
	JS_CFUNC_DEF("get_as_text", 0, &shortcut_class_get_as_text),
};




static void define_shortcut_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "events"),
        JS_NewCFunction(ctx, shortcut_class_get_events, "get_events", 0),
        JS_NewCFunction(ctx, shortcut_class_set_events, "set_events", 1),
        JS_PROP_GETSET
    );
}

static void define_shortcut_enum(JSContext *ctx, JSValue ctor) {
}

static int js_shortcut_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Shortcut"] = class_id;
	classes_by_id[class_id] = "Shortcut";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &shortcut_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_shortcut_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, shortcut_class_proto_funcs, _countof(shortcut_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, shortcut_class_constructor, "Shortcut", 0, JS_CFUNC_constructor, 0);
	define_shortcut_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Shortcut", ctor);
	ctor_list["Shortcut"] = ctor;

	return 0;
}

JSModuleDef *_js_init_shortcut_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_shortcut_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Shortcut");
	return m;
}

JSModuleDef *js_init_shortcut_module(JSContext *ctx) {
	return _js_init_shortcut_module(ctx, "@godot/classes/shortcut");
}

void __register_shortcut() {
	js_init_shortcut_module(js_context());
}

void register_shortcut() {
	__register_shortcut();
}