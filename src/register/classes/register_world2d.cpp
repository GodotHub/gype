#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/physics_direct_space_state2d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/world2d.hpp>
using namespace godot;

static void world2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["World2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef world2d_class_def = {
    "World2D",
    world2d_class_finalizer
};

static JSValue world2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["World2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    World2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<World2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(World2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue world2d_class_get_canvas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		World2D *obj = static_cast<World2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_canvas();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue world2d_class_get_navigation_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		World2D *obj = static_cast<World2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_navigation_map();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue world2d_class_get_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		World2D *obj = static_cast<World2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_space();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue world2d_class_get_direct_space_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&World2D::get_direct_space_state, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry world2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_canvas", 0, &world2d_class_get_canvas),
	JS_CFUNC_DEF("get_navigation_map", 0, &world2d_class_get_navigation_map),
	JS_CFUNC_DEF("get_space", 0, &world2d_class_get_space),
	JS_CFUNC_DEF("get_direct_space_state", 0, &world2d_class_get_direct_space_state),
};




static void define_world2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "canvas"),
        JS_NewCFunction(ctx, world2d_class_get_canvas, "get_canvas", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "navigation_map"),
        JS_NewCFunction(ctx, world2d_class_get_navigation_map, "get_navigation_map", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "space"),
        JS_NewCFunction(ctx, world2d_class_get_space, "get_space", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "direct_space_state"),
        JS_NewCFunction(ctx, world2d_class_get_direct_space_state, "get_direct_space_state", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
}

static void define_world2d_enum(JSContext *ctx, JSValue proto) {
}

static int js_world2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["World2D"] = class_id;
	classes_by_id[class_id] = "World2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &world2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_world2d_property(ctx, proto);
	define_world2d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, world2d_class_proto_funcs, _countof(world2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, world2d_class_constructor, "World2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "World2D", ctor);

	return 0;
}

JSModuleDef *_js_init_world2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_world2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "World2D");
	return m;
}

JSModuleDef *js_init_world2d_module(JSContext *ctx) {
	return _js_init_world2d_module(ctx, "@godot/classes/world2d");
}

void __register_world2d() {
	js_init_world2d_module(js_context());
}

void register_world2d() {
	__register_world2d();
}