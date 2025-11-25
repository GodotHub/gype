#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_script.hpp>
using namespace godot;

static void editor_script_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorScript"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_script_class_def = {
    "EditorScript",
    editor_script_class_finalizer
};

static JSValue editor_script_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorScript"];
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
        instance = memnew(EditorScript);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_script_class_add_root_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorScript::add_root_node, ctx, this_val, argc, argv);
};
static JSValue editor_script_class_get_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorScript::get_scene, ctx, this_val, argc, argv);
};
static JSValue editor_script_class_get_editor_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorScript::get_editor_interface, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_script_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_root_node", 1, &editor_script_class_add_root_node),
	JS_CFUNC_DEF("get_scene", 0, &editor_script_class_get_scene),
	JS_CFUNC_DEF("get_editor_interface", 0, &editor_script_class_get_editor_interface),
};




static void define_editor_script_property(JSContext *ctx, JSValue proto) {
}

static void define_editor_script_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_script_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorScript"] = class_id;
	classes_by_id[class_id] = "EditorScript";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_script_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_script_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_script_class_proto_funcs, _countof(editor_script_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_script_class_constructor, "EditorScript", 0, JS_CFUNC_constructor, 0);
	define_editor_script_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorScript", ctor);
	ctor_list["EditorScript"] = ctor;

	return 0;
}

JSModuleDef *_js_init_editor_script_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_script_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorScript");
	return m;
}

JSModuleDef *js_init_editor_script_module(JSContext *ctx) {
	return _js_init_editor_script_module(ctx, "@godot/classes/editor_script");
}

void __register_editor_script() {
	js_init_editor_script_module(js_context());
}

void register_editor_script() {
	__register_editor_script();
}