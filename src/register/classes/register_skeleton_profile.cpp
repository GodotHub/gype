#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skeleton_profile.hpp>
using namespace godot;

static void skeleton_profile_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonProfile"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_profile_class_def = {
    "SkeletonProfile",
    skeleton_profile_class_finalizer
};

static JSValue skeleton_profile_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonProfile"];
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
        instance = memnew(SkeletonProfile);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_profile_class_set_root_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_root_bone, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_root_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonProfile::get_root_bone, ctx, this_val, argc, argv);
}
static JSValue skeleton_profile_class_set_scale_base_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_scale_base_bone, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_scale_base_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonProfile::get_scale_base_bone, ctx, this_val, argc, argv);
}
static JSValue skeleton_profile_class_set_group_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_group_size, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_group_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonProfile::get_group_size, ctx, this_val, argc, argv);
}
static JSValue skeleton_profile_class_get_group_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_group_name, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_group_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_group_name, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_texture, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_texture, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_bone_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_bone_size, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_bone_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonProfile::get_bone_size, ctx, this_val, argc, argv);
}
static JSValue skeleton_profile_class_find_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::find_bone, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_bone_name, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_bone_name, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_bone_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_bone_parent, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_bone_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_bone_parent, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_tail_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_tail_direction, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_tail_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_tail_direction, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_bone_tail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_bone_tail, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_bone_tail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_bone_tail, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_reference_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_reference_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_reference_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_reference_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_handle_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_handle_offset, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_handle_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_handle_offset, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_get_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::get_group, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_group, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_is_required(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonProfile::is_required, ctx, this_val, argc, argv);
};
static JSValue skeleton_profile_class_set_required(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonProfile::set_required, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry skeleton_profile_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_root_bone", 1, &skeleton_profile_class_set_root_bone),
	JS_CFUNC_DEF("get_root_bone", 0, &skeleton_profile_class_get_root_bone),
	JS_CFUNC_DEF("set_scale_base_bone", 1, &skeleton_profile_class_set_scale_base_bone),
	JS_CFUNC_DEF("get_scale_base_bone", 0, &skeleton_profile_class_get_scale_base_bone),
	JS_CFUNC_DEF("set_group_size", 1, &skeleton_profile_class_set_group_size),
	JS_CFUNC_DEF("get_group_size", 0, &skeleton_profile_class_get_group_size),
	JS_CFUNC_DEF("get_group_name", 1, &skeleton_profile_class_get_group_name),
	JS_CFUNC_DEF("set_group_name", 2, &skeleton_profile_class_set_group_name),
	JS_CFUNC_DEF("get_texture", 1, &skeleton_profile_class_get_texture),
	JS_CFUNC_DEF("set_texture", 2, &skeleton_profile_class_set_texture),
	JS_CFUNC_DEF("set_bone_size", 1, &skeleton_profile_class_set_bone_size),
	JS_CFUNC_DEF("get_bone_size", 0, &skeleton_profile_class_get_bone_size),
	JS_CFUNC_DEF("find_bone", 1, &skeleton_profile_class_find_bone),
	JS_CFUNC_DEF("get_bone_name", 1, &skeleton_profile_class_get_bone_name),
	JS_CFUNC_DEF("set_bone_name", 2, &skeleton_profile_class_set_bone_name),
	JS_CFUNC_DEF("get_bone_parent", 1, &skeleton_profile_class_get_bone_parent),
	JS_CFUNC_DEF("set_bone_parent", 2, &skeleton_profile_class_set_bone_parent),
	JS_CFUNC_DEF("get_tail_direction", 1, &skeleton_profile_class_get_tail_direction),
	JS_CFUNC_DEF("set_tail_direction", 2, &skeleton_profile_class_set_tail_direction),
	JS_CFUNC_DEF("get_bone_tail", 1, &skeleton_profile_class_get_bone_tail),
	JS_CFUNC_DEF("set_bone_tail", 2, &skeleton_profile_class_set_bone_tail),
	JS_CFUNC_DEF("get_reference_pose", 1, &skeleton_profile_class_get_reference_pose),
	JS_CFUNC_DEF("set_reference_pose", 2, &skeleton_profile_class_set_reference_pose),
	JS_CFUNC_DEF("get_handle_offset", 1, &skeleton_profile_class_get_handle_offset),
	JS_CFUNC_DEF("set_handle_offset", 2, &skeleton_profile_class_set_handle_offset),
	JS_CFUNC_DEF("get_group", 1, &skeleton_profile_class_get_group),
	JS_CFUNC_DEF("set_group", 2, &skeleton_profile_class_set_group),
	JS_CFUNC_DEF("is_required", 1, &skeleton_profile_class_is_required),
	JS_CFUNC_DEF("set_required", 2, &skeleton_profile_class_set_required),
};


static JSValue skeleton_profile_class_get_profile_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "profile_updated");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_skeleton_profile_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root_bone"),
        JS_NewCFunction(ctx, skeleton_profile_class_get_root_bone, "get_root_bone", 0),
        JS_NewCFunction(ctx, skeleton_profile_class_set_root_bone, "set_root_bone", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale_base_bone"),
        JS_NewCFunction(ctx, skeleton_profile_class_get_scale_base_bone, "get_scale_base_bone", 0),
        JS_NewCFunction(ctx, skeleton_profile_class_set_scale_base_bone, "set_scale_base_bone", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "group_size"),
        JS_NewCFunction(ctx, skeleton_profile_class_get_group_size, "get_group_size", 0),
        JS_NewCFunction(ctx, skeleton_profile_class_set_group_size, "set_group_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_size"),
        JS_NewCFunction(ctx, skeleton_profile_class_get_bone_size, "get_bone_size", 0),
        JS_NewCFunction(ctx, skeleton_profile_class_set_bone_size, "set_bone_size", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "profile_updated"),
		JS_NewCFunction(ctx, skeleton_profile_class_get_profile_updated_signal, "get_profile_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_skeleton_profile_enum(JSContext *ctx, JSValue ctor) {
	JSValue TailDirection_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TailDirection_obj, "TAIL_DIRECTION_AVERAGE_CHILDREN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TailDirection_obj, "TAIL_DIRECTION_SPECIFIC_CHILD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TailDirection_obj, "TAIL_DIRECTION_END", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TailDirection", TailDirection_obj);
}

static int js_skeleton_profile_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonProfile"] = class_id;
	classes_by_id[class_id] = "SkeletonProfile";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_profile_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_profile_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_profile_class_proto_funcs, _countof(skeleton_profile_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_profile_class_constructor, "SkeletonProfile", 0, JS_CFUNC_constructor, 0);
	define_skeleton_profile_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonProfile", ctor);
	ctor_list["SkeletonProfile"] = ctor;

	return 0;
}

JSModuleDef *_js_init_skeleton_profile_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_profile_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonProfile");
	return m;
}

JSModuleDef *js_init_skeleton_profile_module(JSContext *ctx) {
	return _js_init_skeleton_profile_module(ctx, "@godot/classes/skeleton_profile");
}

void __register_skeleton_profile() {
	js_init_skeleton_profile_module(js_context());
}

void register_skeleton_profile() {
	__register_skeleton_profile();
}