#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gltf_state.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/fbx_state.hpp>
using namespace godot;

static void fbx_state_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FBXState"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef fbx_state_class_def = {
    "FBXState",
    fbx_state_class_finalizer
};

static JSValue fbx_state_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FBXState"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FBXState *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FBXState *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FBXState);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue fbx_state_class_get_allow_geometry_helper_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&FBXState::get_allow_geometry_helper_nodes, ctx, this_val, argc, argv);
}
static JSValue fbx_state_class_set_allow_geometry_helper_nodes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FBXState::set_allow_geometry_helper_nodes, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry fbx_state_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_allow_geometry_helper_nodes", 0, &fbx_state_class_get_allow_geometry_helper_nodes),
	JS_CFUNC_DEF("set_allow_geometry_helper_nodes", 1, &fbx_state_class_set_allow_geometry_helper_nodes),
};




static void define_fbx_state_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_geometry_helper_nodes"),
        JS_NewCFunction(ctx, fbx_state_class_get_allow_geometry_helper_nodes, "get_allow_geometry_helper_nodes", 0),
        JS_NewCFunction(ctx, fbx_state_class_set_allow_geometry_helper_nodes, "set_allow_geometry_helper_nodes", 1),
        JS_PROP_GETSET
    );
}

static void define_fbx_state_enum(JSContext *ctx, JSValue proto) {
}

static int js_fbx_state_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FBXState"] = class_id;
	classes_by_id[class_id] = "FBXState";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &fbx_state_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GLTFState"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_fbx_state_property(ctx, proto);
	define_fbx_state_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, fbx_state_class_proto_funcs, _countof(fbx_state_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, fbx_state_class_constructor, "FBXState", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FBXState", ctor);

	return 0;
}

JSModuleDef *_js_init_fbx_state_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/gltf_state';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_fbx_state_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FBXState");
	return m;
}

JSModuleDef *js_init_fbx_state_module(JSContext *ctx) {
	return _js_init_fbx_state_module(ctx, "@godot/classes/fbx_state");
}

void __register_fbx_state() {
	js_init_fbx_state_module(js_context());
}

void register_fbx_state() {
	__register_fbx_state();
}