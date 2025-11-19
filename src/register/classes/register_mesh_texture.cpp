#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/mesh_texture.hpp>
using namespace godot;

static void mesh_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MeshTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef mesh_texture_class_def = {
    "MeshTexture",
    mesh_texture_class_finalizer
};

static JSValue mesh_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MeshTexture"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MeshTexture *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MeshTexture *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MeshTexture);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue mesh_texture_class_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshTexture::set_mesh, ctx, this_val, argc, argv);
};
static JSValue mesh_texture_class_get_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshTexture::get_mesh, ctx, this_val, argc, argv);
}
static JSValue mesh_texture_class_set_image_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshTexture::set_image_size, ctx, this_val, argc, argv);
};
static JSValue mesh_texture_class_get_image_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		MeshTexture *obj = static_cast<MeshTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_image_size();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		MeshTexture *js_proxy = static_cast<MeshTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_image_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue mesh_texture_class_set_base_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MeshTexture::set_base_texture, ctx, this_val, argc, argv);
};
static JSValue mesh_texture_class_get_base_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MeshTexture::get_base_texture, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry mesh_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mesh", 1, &mesh_texture_class_set_mesh),
	JS_CFUNC_DEF("get_mesh", 0, &mesh_texture_class_get_mesh),
	JS_CFUNC_DEF("set_image_size", 1, &mesh_texture_class_set_image_size),
	JS_CFUNC_DEF("get_image_size", 0, &mesh_texture_class_get_image_size),
	JS_CFUNC_DEF("set_base_texture", 1, &mesh_texture_class_set_base_texture),
	JS_CFUNC_DEF("get_base_texture", 0, &mesh_texture_class_get_base_texture),
};




static void define_mesh_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mesh"),
        JS_NewCFunction(ctx, mesh_texture_class_get_mesh, "get_mesh", 0),
        JS_NewCFunction(ctx, mesh_texture_class_set_mesh, "set_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "base_texture"),
        JS_NewCFunction(ctx, mesh_texture_class_get_base_texture, "get_base_texture", 0),
        JS_NewCFunction(ctx, mesh_texture_class_set_base_texture, "set_base_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "image_size"),
        JS_NewCFunction(ctx, mesh_texture_class_get_image_size, "get_image_size", 0),
        JS_NewCFunction(ctx, mesh_texture_class_set_image_size, "set_image_size", 1),
        JS_PROP_GETSET
    );
}

static void define_mesh_texture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_mesh_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MeshTexture"] = class_id;
	classes_by_id[class_id] = "MeshTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &mesh_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Texture2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_mesh_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, mesh_texture_class_proto_funcs, _countof(mesh_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, mesh_texture_class_constructor, "MeshTexture", 0, JS_CFUNC_constructor, 0);
	define_mesh_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MeshTexture", ctor);

	return 0;
}

JSModuleDef *_js_init_mesh_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/texture2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_mesh_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MeshTexture");
	return m;
}

JSModuleDef *js_init_mesh_texture_module(JSContext *ctx) {
	return _js_init_mesh_texture_module(ctx, "@godot/classes/mesh_texture");
}

void __register_mesh_texture() {
	js_init_mesh_texture_module(js_context());
}

void register_mesh_texture() {
	__register_mesh_texture();
}