#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/container.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/foldable_group.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/foldable_container.hpp>
using namespace godot;

static void foldable_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FoldableContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef foldable_container_class_def = {
    "FoldableContainer",
    foldable_container_class_finalizer
};

static JSValue foldable_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FoldableContainer"];
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
        instance = memnew(FoldableContainer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue foldable_container_class_fold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::fold, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::expand, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_set_folded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_folded, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_is_folded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::is_folded, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_foldable_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_foldable_group, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_foldable_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_foldable_group, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_title, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_title, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_title_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_title_alignment, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_title_alignment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_title_alignment, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_language, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_language, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_title_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_title_text_direction, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_title_text_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_title_text_direction, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_title_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_title_text_overrun_behavior, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_title_text_overrun_behavior(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_title_text_overrun_behavior, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_set_title_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::set_title_position, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_get_title_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FoldableContainer::get_title_position, ctx, this_val, argc, argv);
}
static JSValue foldable_container_class_add_title_bar_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::add_title_bar_control, ctx, this_val, argc, argv);
};
static JSValue foldable_container_class_remove_title_bar_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FoldableContainer::remove_title_bar_control, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry foldable_container_class_proto_funcs[] = {
	JS_CFUNC_DEF("fold", 0, &foldable_container_class_fold),
	JS_CFUNC_DEF("expand", 0, &foldable_container_class_expand),
	JS_CFUNC_DEF("set_folded", 1, &foldable_container_class_set_folded),
	JS_CFUNC_DEF("is_folded", 0, &foldable_container_class_is_folded),
	JS_CFUNC_DEF("set_foldable_group", 1, &foldable_container_class_set_foldable_group),
	JS_CFUNC_DEF("get_foldable_group", 0, &foldable_container_class_get_foldable_group),
	JS_CFUNC_DEF("set_title", 1, &foldable_container_class_set_title),
	JS_CFUNC_DEF("get_title", 0, &foldable_container_class_get_title),
	JS_CFUNC_DEF("set_title_alignment", 1, &foldable_container_class_set_title_alignment),
	JS_CFUNC_DEF("get_title_alignment", 0, &foldable_container_class_get_title_alignment),
	JS_CFUNC_DEF("set_language", 1, &foldable_container_class_set_language),
	JS_CFUNC_DEF("get_language", 0, &foldable_container_class_get_language),
	JS_CFUNC_DEF("set_title_text_direction", 1, &foldable_container_class_set_title_text_direction),
	JS_CFUNC_DEF("get_title_text_direction", 0, &foldable_container_class_get_title_text_direction),
	JS_CFUNC_DEF("set_title_text_overrun_behavior", 1, &foldable_container_class_set_title_text_overrun_behavior),
	JS_CFUNC_DEF("get_title_text_overrun_behavior", 0, &foldable_container_class_get_title_text_overrun_behavior),
	JS_CFUNC_DEF("set_title_position", 1, &foldable_container_class_set_title_position),
	JS_CFUNC_DEF("get_title_position", 0, &foldable_container_class_get_title_position),
	JS_CFUNC_DEF("add_title_bar_control", 1, &foldable_container_class_add_title_bar_control),
	JS_CFUNC_DEF("remove_title_bar_control", 1, &foldable_container_class_remove_title_bar_control),
};


static JSValue foldable_container_class_get_folding_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "folding_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_foldable_container_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "folded"),
        JS_NewCFunction(ctx, foldable_container_class_is_folded, "is_folded", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_folded, "set_folded", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title"),
        JS_NewCFunction(ctx, foldable_container_class_get_title, "get_title", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_title, "set_title", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title_alignment"),
        JS_NewCFunction(ctx, foldable_container_class_get_title_alignment, "get_title_alignment", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_title_alignment, "set_title_alignment", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title_position"),
        JS_NewCFunction(ctx, foldable_container_class_get_title_position, "get_title_position", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_title_position, "set_title_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title_text_overrun_behavior"),
        JS_NewCFunction(ctx, foldable_container_class_get_title_text_overrun_behavior, "get_title_text_overrun_behavior", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_title_text_overrun_behavior, "set_title_text_overrun_behavior", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "foldable_group"),
        JS_NewCFunction(ctx, foldable_container_class_get_foldable_group, "get_foldable_group", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_foldable_group, "set_foldable_group", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "title_text_direction"),
        JS_NewCFunction(ctx, foldable_container_class_get_title_text_direction, "get_title_text_direction", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_title_text_direction, "set_title_text_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "language"),
        JS_NewCFunction(ctx, foldable_container_class_get_language, "get_language", 0),
        JS_NewCFunction(ctx, foldable_container_class_set_language, "set_language", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "folding_changed"),
		JS_NewCFunction(ctx, foldable_container_class_get_folding_changed_signal, "get_folding_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_foldable_container_enum(JSContext *ctx, JSValue ctor) {
	JSValue TitlePosition_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TitlePosition_obj, "POSITION_TOP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TitlePosition_obj, "POSITION_BOTTOM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "TitlePosition", TitlePosition_obj);
}

static int js_foldable_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FoldableContainer"] = class_id;
	classes_by_id[class_id] = "FoldableContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &foldable_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Container"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_foldable_container_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, foldable_container_class_proto_funcs, _countof(foldable_container_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, foldable_container_class_constructor, "FoldableContainer", 0, JS_CFUNC_constructor, 0);
	define_foldable_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FoldableContainer", ctor);
	ctor_list["FoldableContainer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_foldable_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_foldable_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FoldableContainer");
	return m;
}

JSModuleDef *js_init_foldable_container_module(JSContext *ctx) {
	return _js_init_foldable_container_module(ctx, "@godot/classes/foldable_container");
}

void __register_foldable_container() {
	js_init_foldable_container_module(js_context());
}

void register_foldable_container() {
	__register_foldable_container();
}