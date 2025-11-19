#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/canvas_modulate.hpp>
using namespace godot;

static void canvas_modulate_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CanvasModulate"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef canvas_modulate_class_def = {
    "CanvasModulate",
    canvas_modulate_class_finalizer
};

static JSValue canvas_modulate_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CanvasModulate"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CanvasModulate *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CanvasModulate *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CanvasModulate);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue canvas_modulate_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CanvasModulate::set_color, ctx, this_val, argc, argv);
};
static JSValue canvas_modulate_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CanvasModulate *obj = static_cast<CanvasModulate *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CanvasModulate *js_proxy = static_cast<CanvasModulate *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}



static const JSCFunctionListEntry canvas_modulate_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_color", 1, &canvas_modulate_class_set_color),
	JS_CFUNC_DEF("get_color", 0, &canvas_modulate_class_get_color),
};




static void define_canvas_modulate_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, canvas_modulate_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, canvas_modulate_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
}

static void define_canvas_modulate_enum(JSContext *ctx, JSValue ctor) {
}

static int js_canvas_modulate_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CanvasModulate"] = class_id;
	classes_by_id[class_id] = "CanvasModulate";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &canvas_modulate_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_canvas_modulate_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, canvas_modulate_class_proto_funcs, _countof(canvas_modulate_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, canvas_modulate_class_constructor, "CanvasModulate", 0, JS_CFUNC_constructor, 0);
	define_canvas_modulate_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CanvasModulate", ctor);

	return 0;
}

JSModuleDef *_js_init_canvas_modulate_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_canvas_modulate_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CanvasModulate");
	return m;
}

JSModuleDef *js_init_canvas_modulate_module(JSContext *ctx) {
	return _js_init_canvas_modulate_module(ctx, "@godot/classes/canvas_modulate");
}

void __register_canvas_modulate() {
	js_init_canvas_modulate_module(js_context());
}

void register_canvas_modulate() {
	__register_canvas_modulate();
}