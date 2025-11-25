#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/root_motion_view.hpp>
using namespace godot;

static void root_motion_view_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RootMotionView"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef root_motion_view_class_def = {
    "RootMotionView",
    root_motion_view_class_finalizer
};

static JSValue root_motion_view_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RootMotionView"];
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
        instance = memnew(RootMotionView);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue root_motion_view_class_set_animation_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RootMotionView::set_animation_path, ctx, this_val, argc, argv);
};
static JSValue root_motion_view_class_get_animation_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RootMotionView::get_animation_path, ctx, this_val, argc, argv);
}
static JSValue root_motion_view_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RootMotionView::set_color, ctx, this_val, argc, argv);
};
static JSValue root_motion_view_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		RootMotionView *obj = static_cast<RootMotionView *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		RootMotionView *js_proxy = static_cast<RootMotionView *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue root_motion_view_class_set_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RootMotionView::set_cell_size, ctx, this_val, argc, argv);
};
static JSValue root_motion_view_class_get_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RootMotionView::get_cell_size, ctx, this_val, argc, argv);
}
static JSValue root_motion_view_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RootMotionView::set_radius, ctx, this_val, argc, argv);
};
static JSValue root_motion_view_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RootMotionView::get_radius, ctx, this_val, argc, argv);
}
static JSValue root_motion_view_class_set_zero_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RootMotionView::set_zero_y, ctx, this_val, argc, argv);
};
static JSValue root_motion_view_class_get_zero_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RootMotionView::get_zero_y, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry root_motion_view_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_animation_path", 1, &root_motion_view_class_set_animation_path),
	JS_CFUNC_DEF("get_animation_path", 0, &root_motion_view_class_get_animation_path),
	JS_CFUNC_DEF("set_color", 1, &root_motion_view_class_set_color),
	JS_CFUNC_DEF("get_color", 0, &root_motion_view_class_get_color),
	JS_CFUNC_DEF("set_cell_size", 1, &root_motion_view_class_set_cell_size),
	JS_CFUNC_DEF("get_cell_size", 0, &root_motion_view_class_get_cell_size),
	JS_CFUNC_DEF("set_radius", 1, &root_motion_view_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &root_motion_view_class_get_radius),
	JS_CFUNC_DEF("set_zero_y", 1, &root_motion_view_class_set_zero_y),
	JS_CFUNC_DEF("get_zero_y", 0, &root_motion_view_class_get_zero_y),
};




static void define_root_motion_view_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "animation_path"),
        JS_NewCFunction(ctx, root_motion_view_class_get_animation_path, "get_animation_path", 0),
        JS_NewCFunction(ctx, root_motion_view_class_set_animation_path, "set_animation_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, root_motion_view_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, root_motion_view_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cell_size"),
        JS_NewCFunction(ctx, root_motion_view_class_get_cell_size, "get_cell_size", 0),
        JS_NewCFunction(ctx, root_motion_view_class_set_cell_size, "set_cell_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, root_motion_view_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, root_motion_view_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "zero_y"),
        JS_NewCFunction(ctx, root_motion_view_class_get_zero_y, "get_zero_y", 0),
        JS_NewCFunction(ctx, root_motion_view_class_set_zero_y, "set_zero_y", 1),
        JS_PROP_GETSET
    );
}

static void define_root_motion_view_enum(JSContext *ctx, JSValue ctor) {
}

static int js_root_motion_view_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RootMotionView"] = class_id;
	classes_by_id[class_id] = "RootMotionView";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &root_motion_view_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_root_motion_view_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, root_motion_view_class_proto_funcs, _countof(root_motion_view_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, root_motion_view_class_constructor, "RootMotionView", 0, JS_CFUNC_constructor, 0);
	define_root_motion_view_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RootMotionView", ctor);
	ctor_list["RootMotionView"] = ctor;

	return 0;
}

JSModuleDef *_js_init_root_motion_view_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_root_motion_view_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RootMotionView");
	return m;
}

JSModuleDef *js_init_root_motion_view_module(JSContext *ctx) {
	return _js_init_root_motion_view_module(ctx, "@godot/classes/root_motion_view");
}

void __register_root_motion_view() {
	js_init_root_motion_view_module(js_context());
}

void register_root_motion_view() {
	__register_root_motion_view();
}