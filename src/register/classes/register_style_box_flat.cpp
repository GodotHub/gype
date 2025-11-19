#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/style_box_flat.hpp>
using namespace godot;

static void style_box_flat_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StyleBoxFlat"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef style_box_flat_class_def = {
    "StyleBoxFlat",
    style_box_flat_class_finalizer
};

static JSValue style_box_flat_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StyleBoxFlat"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    StyleBoxFlat *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<StyleBoxFlat *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(StyleBoxFlat);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue style_box_flat_class_set_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_bg_color, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		StyleBoxFlat *obj = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_bg_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		StyleBoxFlat *js_proxy = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_bg_color(value);
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
static JSValue style_box_flat_class_set_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_border_color, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		StyleBoxFlat *obj = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_border_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		StyleBoxFlat *js_proxy = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_border_color(value);
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
static JSValue style_box_flat_class_set_border_width_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_border_width_all, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_border_width_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_border_width_min, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_set_border_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_border_width, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_border_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_border_width, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_border_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_border_blend, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_border_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_border_blend, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_corner_radius_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_corner_radius_all, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_set_corner_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_corner_radius, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_corner_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_corner_radius, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_expand_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_expand_margin, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_set_expand_margin_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_expand_margin_all, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_expand_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_expand_margin, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_draw_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_draw_center, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_is_draw_center_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::is_draw_center_enabled, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_skew(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_skew, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_skew(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		StyleBoxFlat *obj = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_skew();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		StyleBoxFlat *js_proxy = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_skew(value);
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
static JSValue style_box_flat_class_set_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_shadow_color, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		StyleBoxFlat *obj = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shadow_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		StyleBoxFlat *js_proxy = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shadow_color(value);
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
static JSValue style_box_flat_class_set_shadow_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_shadow_size, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_shadow_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_shadow_size, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_shadow_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_shadow_offset, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_shadow_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		StyleBoxFlat *obj = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shadow_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		StyleBoxFlat *js_proxy = static_cast<StyleBoxFlat *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shadow_offset(value);
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
static JSValue style_box_flat_class_set_anti_aliased(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_anti_aliased, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_is_anti_aliased(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::is_anti_aliased, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_aa_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_aa_size, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_aa_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_aa_size, ctx, this_val, argc, argv);
}
static JSValue style_box_flat_class_set_corner_detail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxFlat::set_corner_detail, ctx, this_val, argc, argv);
};
static JSValue style_box_flat_class_get_corner_detail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxFlat::get_corner_detail, ctx, this_val, argc, argv);
}

static JSValue style_box_flat_class_get_border_width_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_border_width, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_border_width_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_border_width, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_border_width_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_border_width, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_border_width_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_border_width, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_border_width_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_border_width, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_border_width_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_border_width, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_border_width_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_border_width, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_border_width_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_border_width, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_corner_radius_top_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_corner_radius, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_corner_radius_top_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_corner_radius, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_corner_radius_top_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_corner_radius, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_corner_radius_top_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_corner_radius, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_corner_radius_bottom_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_corner_radius, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_corner_radius_bottom_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_corner_radius, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_corner_radius_bottom_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_corner_radius, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_corner_radius_bottom_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_corner_radius, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_expand_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_expand_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_expand_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_expand_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_expand_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_expand_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_flat_class_get_expand_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxFlat::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_flat_class_set_expand_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxFlat::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry style_box_flat_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_bg_color", 1, &style_box_flat_class_set_bg_color),
	JS_CFUNC_DEF("get_bg_color", 0, &style_box_flat_class_get_bg_color),
	JS_CFUNC_DEF("set_border_color", 1, &style_box_flat_class_set_border_color),
	JS_CFUNC_DEF("get_border_color", 0, &style_box_flat_class_get_border_color),
	JS_CFUNC_DEF("set_border_width_all", 1, &style_box_flat_class_set_border_width_all),
	JS_CFUNC_DEF("get_border_width_min", 0, &style_box_flat_class_get_border_width_min),
	JS_CFUNC_DEF("set_border_width", 2, &style_box_flat_class_set_border_width),
	JS_CFUNC_DEF("get_border_width", 1, &style_box_flat_class_get_border_width),
	JS_CFUNC_DEF("set_border_blend", 1, &style_box_flat_class_set_border_blend),
	JS_CFUNC_DEF("get_border_blend", 0, &style_box_flat_class_get_border_blend),
	JS_CFUNC_DEF("set_corner_radius_all", 1, &style_box_flat_class_set_corner_radius_all),
	JS_CFUNC_DEF("set_corner_radius", 2, &style_box_flat_class_set_corner_radius),
	JS_CFUNC_DEF("get_corner_radius", 1, &style_box_flat_class_get_corner_radius),
	JS_CFUNC_DEF("set_expand_margin", 2, &style_box_flat_class_set_expand_margin),
	JS_CFUNC_DEF("set_expand_margin_all", 1, &style_box_flat_class_set_expand_margin_all),
	JS_CFUNC_DEF("get_expand_margin", 1, &style_box_flat_class_get_expand_margin),
	JS_CFUNC_DEF("set_draw_center", 1, &style_box_flat_class_set_draw_center),
	JS_CFUNC_DEF("is_draw_center_enabled", 0, &style_box_flat_class_is_draw_center_enabled),
	JS_CFUNC_DEF("set_skew", 1, &style_box_flat_class_set_skew),
	JS_CFUNC_DEF("get_skew", 0, &style_box_flat_class_get_skew),
	JS_CFUNC_DEF("set_shadow_color", 1, &style_box_flat_class_set_shadow_color),
	JS_CFUNC_DEF("get_shadow_color", 0, &style_box_flat_class_get_shadow_color),
	JS_CFUNC_DEF("set_shadow_size", 1, &style_box_flat_class_set_shadow_size),
	JS_CFUNC_DEF("get_shadow_size", 0, &style_box_flat_class_get_shadow_size),
	JS_CFUNC_DEF("set_shadow_offset", 1, &style_box_flat_class_set_shadow_offset),
	JS_CFUNC_DEF("get_shadow_offset", 0, &style_box_flat_class_get_shadow_offset),
	JS_CFUNC_DEF("set_anti_aliased", 1, &style_box_flat_class_set_anti_aliased),
	JS_CFUNC_DEF("is_anti_aliased", 0, &style_box_flat_class_is_anti_aliased),
	JS_CFUNC_DEF("set_aa_size", 1, &style_box_flat_class_set_aa_size),
	JS_CFUNC_DEF("get_aa_size", 0, &style_box_flat_class_get_aa_size),
	JS_CFUNC_DEF("set_corner_detail", 1, &style_box_flat_class_set_corner_detail),
	JS_CFUNC_DEF("get_corner_detail", 0, &style_box_flat_class_get_corner_detail),
    JS_CFUNC_MAGIC_DEF("get_border_width_top", 0, &style_box_flat_class_get_border_width_top, 1),
    JS_CFUNC_MAGIC_DEF("set_border_width_top", 1, &style_box_flat_class_set_border_width_top, 1),
    JS_CFUNC_MAGIC_DEF("get_border_width_right", 0, &style_box_flat_class_get_border_width_right, 2),
    JS_CFUNC_MAGIC_DEF("set_border_width_right", 1, &style_box_flat_class_set_border_width_right, 2),
    JS_CFUNC_MAGIC_DEF("get_border_width_bottom", 0, &style_box_flat_class_get_border_width_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_border_width_bottom", 1, &style_box_flat_class_set_border_width_bottom, 3),
    JS_CFUNC_MAGIC_DEF("get_corner_radius_top_right", 0, &style_box_flat_class_get_corner_radius_top_right, 1),
    JS_CFUNC_MAGIC_DEF("set_corner_radius_top_right", 1, &style_box_flat_class_set_corner_radius_top_right, 1),
    JS_CFUNC_MAGIC_DEF("get_corner_radius_bottom_right", 0, &style_box_flat_class_get_corner_radius_bottom_right, 2),
    JS_CFUNC_MAGIC_DEF("set_corner_radius_bottom_right", 1, &style_box_flat_class_set_corner_radius_bottom_right, 2),
    JS_CFUNC_MAGIC_DEF("get_corner_radius_bottom_left", 0, &style_box_flat_class_get_corner_radius_bottom_left, 3),
    JS_CFUNC_MAGIC_DEF("set_corner_radius_bottom_left", 1, &style_box_flat_class_set_corner_radius_bottom_left, 3),
    JS_CFUNC_MAGIC_DEF("get_expand_margin_top", 0, &style_box_flat_class_get_expand_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("set_expand_margin_top", 1, &style_box_flat_class_set_expand_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("get_expand_margin_right", 0, &style_box_flat_class_get_expand_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("set_expand_margin_right", 1, &style_box_flat_class_set_expand_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("get_expand_margin_bottom", 0, &style_box_flat_class_get_expand_margin_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_expand_margin_bottom", 1, &style_box_flat_class_set_expand_margin_bottom, 3),
};




static void define_style_box_flat_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bg_color"),
        JS_NewCFunction(ctx, style_box_flat_class_get_bg_color, "get_bg_color", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_bg_color, "set_bg_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_center"),
        JS_NewCFunction(ctx, style_box_flat_class_is_draw_center_enabled, "is_draw_center_enabled", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_draw_center, "set_draw_center", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skew"),
        JS_NewCFunction(ctx, style_box_flat_class_get_skew, "get_skew", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_skew, "set_skew", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "border_width_left"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_border_width_left, "get_border_width_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_border_width_left, "set_border_width_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "border_width_top"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_border_width_top, "get_border_width_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_border_width_top, "set_border_width_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "border_width_right"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_border_width_right, "get_border_width_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_border_width_right, "set_border_width_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "border_width_bottom"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_border_width_bottom, "get_border_width_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_border_width_bottom, "set_border_width_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_color"),
        JS_NewCFunction(ctx, style_box_flat_class_get_border_color, "get_border_color", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_border_color, "set_border_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "border_blend"),
        JS_NewCFunction(ctx, style_box_flat_class_get_border_blend, "get_border_blend", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_border_blend, "set_border_blend", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "corner_radius_top_left"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_corner_radius_top_left, "get_corner_radius_top_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_corner_radius_top_left, "set_corner_radius_top_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "corner_radius_top_right"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_corner_radius_top_right, "get_corner_radius_top_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_corner_radius_top_right, "set_corner_radius_top_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "corner_radius_bottom_right"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_corner_radius_bottom_right, "get_corner_radius_bottom_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_corner_radius_bottom_right, "set_corner_radius_bottom_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "corner_radius_bottom_left"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_corner_radius_bottom_left, "get_corner_radius_bottom_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_corner_radius_bottom_left, "set_corner_radius_bottom_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "corner_detail"),
        JS_NewCFunction(ctx, style_box_flat_class_get_corner_detail, "get_corner_detail", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_corner_detail, "set_corner_detail", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_left"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_expand_margin_left, "get_expand_margin_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_expand_margin_left, "set_expand_margin_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_top"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_expand_margin_top, "get_expand_margin_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_expand_margin_top, "set_expand_margin_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_right"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_expand_margin_right, "get_expand_margin_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_expand_margin_right, "set_expand_margin_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_bottom"),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_get_expand_margin_bottom, "get_expand_margin_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, style_box_flat_class_set_expand_margin_bottom, "set_expand_margin_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_color"),
        JS_NewCFunction(ctx, style_box_flat_class_get_shadow_color, "get_shadow_color", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_shadow_color, "set_shadow_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_size"),
        JS_NewCFunction(ctx, style_box_flat_class_get_shadow_size, "get_shadow_size", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_shadow_size, "set_shadow_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_offset"),
        JS_NewCFunction(ctx, style_box_flat_class_get_shadow_offset, "get_shadow_offset", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_shadow_offset, "set_shadow_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "anti_aliasing"),
        JS_NewCFunction(ctx, style_box_flat_class_is_anti_aliased, "is_anti_aliased", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_anti_aliased, "set_anti_aliased", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "anti_aliasing_size"),
        JS_NewCFunction(ctx, style_box_flat_class_get_aa_size, "get_aa_size", 0),
        JS_NewCFunction(ctx, style_box_flat_class_set_aa_size, "set_aa_size", 1),
        JS_PROP_GETSET
    );
}

static void define_style_box_flat_enum(JSContext *ctx, JSValue ctor) {
}

static int js_style_box_flat_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StyleBoxFlat"] = class_id;
	classes_by_id[class_id] = "StyleBoxFlat";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &style_box_flat_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["StyleBox"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_style_box_flat_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, style_box_flat_class_proto_funcs, _countof(style_box_flat_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, style_box_flat_class_constructor, "StyleBoxFlat", 0, JS_CFUNC_constructor, 0);
	define_style_box_flat_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StyleBoxFlat", ctor);

	return 0;
}

JSModuleDef *_js_init_style_box_flat_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/style_box';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_style_box_flat_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StyleBoxFlat");
	return m;
}

JSModuleDef *js_init_style_box_flat_module(JSContext *ctx) {
	return _js_init_style_box_flat_module(ctx, "@godot/classes/style_box_flat");
}

void __register_style_box_flat() {
	js_init_style_box_flat_module(js_context());
}

void register_style_box_flat() {
	__register_style_box_flat();
}