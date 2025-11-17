#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/importer_mesh.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/importer_mesh_instance3d.hpp>
using namespace godot;

static void importer_mesh_instance3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ImporterMeshInstance3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef importer_mesh_instance3d_class_def = {
    "ImporterMeshInstance3D",
    importer_mesh_instance3d_class_finalizer
};

static JSValue importer_mesh_instance3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ImporterMeshInstance3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ImporterMeshInstance3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ImporterMeshInstance3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ImporterMeshInstance3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue importer_mesh_instance3d_class_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_mesh, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_mesh, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_skin, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_skin, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_skeleton_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_skeleton_path, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_skeleton_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		ImporterMeshInstance3D *obj = static_cast<ImporterMeshInstance3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_skeleton_path();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		ImporterMeshInstance3D *js_proxy = static_cast<ImporterMeshInstance3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_skeleton_path(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue importer_mesh_instance3d_class_set_layer_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_layer_mask, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_layer_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_layer_mask, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_cast_shadows_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_cast_shadows_setting, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_cast_shadows_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_cast_shadows_setting, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_visibility_range_end_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_visibility_range_end_margin, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_visibility_range_end_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_visibility_range_end_margin, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_visibility_range_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_visibility_range_end, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_visibility_range_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_visibility_range_end, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_visibility_range_begin_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_visibility_range_begin_margin, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_visibility_range_begin_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_visibility_range_begin_margin, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_visibility_range_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_visibility_range_begin, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_visibility_range_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_visibility_range_begin, ctx, this_val, argc, argv);
}
static JSValue importer_mesh_instance3d_class_set_visibility_range_fade_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ImporterMeshInstance3D::set_visibility_range_fade_mode, ctx, this_val, argc, argv);
};
static JSValue importer_mesh_instance3d_class_get_visibility_range_fade_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ImporterMeshInstance3D::get_visibility_range_fade_mode, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry importer_mesh_instance3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mesh", 1, &importer_mesh_instance3d_class_set_mesh),
	JS_CFUNC_DEF("get_mesh", 0, &importer_mesh_instance3d_class_get_mesh),
	JS_CFUNC_DEF("set_skin", 1, &importer_mesh_instance3d_class_set_skin),
	JS_CFUNC_DEF("get_skin", 0, &importer_mesh_instance3d_class_get_skin),
	JS_CFUNC_DEF("set_skeleton_path", 1, &importer_mesh_instance3d_class_set_skeleton_path),
	JS_CFUNC_DEF("get_skeleton_path", 0, &importer_mesh_instance3d_class_get_skeleton_path),
	JS_CFUNC_DEF("set_layer_mask", 1, &importer_mesh_instance3d_class_set_layer_mask),
	JS_CFUNC_DEF("get_layer_mask", 0, &importer_mesh_instance3d_class_get_layer_mask),
	JS_CFUNC_DEF("set_cast_shadows_setting", 1, &importer_mesh_instance3d_class_set_cast_shadows_setting),
	JS_CFUNC_DEF("get_cast_shadows_setting", 0, &importer_mesh_instance3d_class_get_cast_shadows_setting),
	JS_CFUNC_DEF("set_visibility_range_end_margin", 1, &importer_mesh_instance3d_class_set_visibility_range_end_margin),
	JS_CFUNC_DEF("get_visibility_range_end_margin", 0, &importer_mesh_instance3d_class_get_visibility_range_end_margin),
	JS_CFUNC_DEF("set_visibility_range_end", 1, &importer_mesh_instance3d_class_set_visibility_range_end),
	JS_CFUNC_DEF("get_visibility_range_end", 0, &importer_mesh_instance3d_class_get_visibility_range_end),
	JS_CFUNC_DEF("set_visibility_range_begin_margin", 1, &importer_mesh_instance3d_class_set_visibility_range_begin_margin),
	JS_CFUNC_DEF("get_visibility_range_begin_margin", 0, &importer_mesh_instance3d_class_get_visibility_range_begin_margin),
	JS_CFUNC_DEF("set_visibility_range_begin", 1, &importer_mesh_instance3d_class_set_visibility_range_begin),
	JS_CFUNC_DEF("get_visibility_range_begin", 0, &importer_mesh_instance3d_class_get_visibility_range_begin),
	JS_CFUNC_DEF("set_visibility_range_fade_mode", 1, &importer_mesh_instance3d_class_set_visibility_range_fade_mode),
	JS_CFUNC_DEF("get_visibility_range_fade_mode", 0, &importer_mesh_instance3d_class_get_visibility_range_fade_mode),
};




static void define_importer_mesh_instance3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_mesh, "get_mesh", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_mesh, "set_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skin"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_skin, "get_skin", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_skin, "set_skin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skeleton_path"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_skeleton_path, "get_skeleton_path", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_skeleton_path, "set_skeleton_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "layer_mask"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_layer_mask, "get_layer_mask", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_layer_mask, "set_layer_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cast_shadow"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_cast_shadows_setting, "get_cast_shadows_setting", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_cast_shadows_setting, "set_cast_shadows_setting", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_begin"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_visibility_range_begin, "get_visibility_range_begin", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_visibility_range_begin, "set_visibility_range_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_begin_margin"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_visibility_range_begin_margin, "get_visibility_range_begin_margin", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_visibility_range_begin_margin, "set_visibility_range_begin_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_end"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_visibility_range_end, "get_visibility_range_end", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_visibility_range_end, "set_visibility_range_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_end_margin"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_visibility_range_end_margin, "get_visibility_range_end_margin", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_visibility_range_end_margin, "set_visibility_range_end_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_fade_mode"),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_get_visibility_range_fade_mode, "get_visibility_range_fade_mode", 0),
        JS_NewCFunction(ctx, importer_mesh_instance3d_class_set_visibility_range_fade_mode, "set_visibility_range_fade_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_importer_mesh_instance3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_importer_mesh_instance3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ImporterMeshInstance3D"] = class_id;
	classes_by_id[class_id] = "ImporterMeshInstance3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &importer_mesh_instance3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_importer_mesh_instance3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, importer_mesh_instance3d_class_proto_funcs, _countof(importer_mesh_instance3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, importer_mesh_instance3d_class_constructor, "ImporterMeshInstance3D", 0, JS_CFUNC_constructor, 0);
	define_importer_mesh_instance3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ImporterMeshInstance3D", ctor);

	return 0;
}

JSModuleDef *_js_init_importer_mesh_instance3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_importer_mesh_instance3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ImporterMeshInstance3D");
	return m;
}

JSModuleDef *js_init_importer_mesh_instance3d_module(JSContext *ctx) {
	return _js_init_importer_mesh_instance3d_module(ctx, "@godot/classes/importer_mesh_instance3d");
}

void __register_importer_mesh_instance3d() {
	js_init_importer_mesh_instance3d_module(js_context());
}

void register_importer_mesh_instance3d() {
	__register_importer_mesh_instance3d();
}