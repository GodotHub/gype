#include <quickjs.h>
#include "utils/str_helper.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "register/utility_functions/utility_functions_vararg_method.hpp"
#include "register/utility_functions/register_utility_functions.hpp"
#include "utils/quickjs_helper.hpp"
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

JSValue utility_functions_instance;

static void utility_functions_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["UtilityFunctions"];
	UtilityFunctions *utility_functions = static_cast<UtilityFunctions *>(JS_GetOpaque(val, class_id));
	if (utility_functions)
		memdelete(utility_functions);
}

static JSClassDef utility_functions_class_def = {
	"UtilityFunctions",
	.finalizer = utility_functions_class_finalizer
};

static JSValue utility_functions_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["UtilityFunctions"];
	UtilityFunctions *utility_functions_class;
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;
	utility_functions_class = memnew(UtilityFunctions);
	if (!utility_functions_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, utility_functions_class);
	return obj;
}
static JSValue utility_functions_class_sin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::sin, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_cos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::cos, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_tan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::tan, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_sinh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::sinh, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_cosh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::cosh, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_tanh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::tanh, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_asin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::asin, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_acos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::acos, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_atan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::atan, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_atan2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::atan2, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_asinh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::asinh, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_acosh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::acosh, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_atanh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::atanh, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_sqrt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::sqrt, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_fmod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::fmod, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_fposmod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::fposmod, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_posmod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::posmod, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_floor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::floor, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_floorf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::floorf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_floori(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::floori, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_ceil(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::ceil, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_ceilf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::ceilf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_ceili(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::ceili, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_round(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::round, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_roundf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::roundf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_roundi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::roundi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::abs, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_absf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::absf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_absi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::absi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::sign, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_signf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::signf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_signi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::signi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::snapped, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_snappedf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::snappedf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::snappedi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_pow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::pow, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::log, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_exp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::exp, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_nan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_nan, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_inf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_inf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_equal_approx, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_zero_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_zero_approx, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_finite, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_ease(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::ease, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_step_decimals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::step_decimals, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::lerp, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_lerpf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::lerpf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::cubic_interpolate, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_cubic_interpolate_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::cubic_interpolate_angle, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::cubic_interpolate_in_time, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_cubic_interpolate_angle_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::cubic_interpolate_angle_in_time, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_bezier_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::bezier_interpolate, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_bezier_derivative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::bezier_derivative, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_angle_difference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::angle_difference, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_lerp_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::lerp_angle, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_inverse_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::inverse_lerp, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_remap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::remap, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_smoothstep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::smoothstep, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_move_toward(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::move_toward, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_rotate_toward(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::rotate_toward, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_deg_to_rad(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::deg_to_rad, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_rad_to_deg(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::rad_to_deg, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_linear_to_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::linear_to_db, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_db_to_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::db_to_linear, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::wrap, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_wrapi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::wrapi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_wrapf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::wrapf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::maxi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_maxf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::maxf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::mini, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_minf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::minf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::clamp, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::clampi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_clampf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::clampf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_nearest_po2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::nearest_po2, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_pingpong(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::pingpong, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_randomize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_static_method_no_ret(&UtilityFunctions::randomize, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue utility_functions_class_randi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::randi, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_randf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::randf, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_randi_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::randi_range, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_randf_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::randf_range, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_randfn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::randfn, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_static_method_no_ret(&UtilityFunctions::seed, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue utility_functions_class_rand_from_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::rand_from_seed, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_weakref(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::weakref, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_typeof(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::type_of, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_type_convert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::type_convert, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_error_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::error_string, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_type_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::type_string, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_var_to_str(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::var_to_str, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_str_to_var(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::str_to_var, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_var_to_bytes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::var_to_bytes, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_bytes_to_var(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::bytes_to_var, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_var_to_bytes_with_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::var_to_bytes_with_objects, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_bytes_to_var_with_objects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::bytes_to_var_with_objects, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_hash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::hash, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_instance_from_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::instance_from_id, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_instance_id_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_instance_id_valid, ctx, this_val, argc, argv);
};
// static JSValue utility_functions_class_is_instance_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	return call_builtin_static_method_ret(&UtilityFunctions::is_instance_valid, ctx, this_val, argc, argv);
// };
static JSValue utility_functions_class_rid_allocate_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::rid_allocate_id, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_rid_from_int64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::rid_from_int64, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_is_same(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UtilityFunctions::is_same, ctx, this_val, argc, argv);
};
static JSValue utility_functions_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_vararg_method_ret(&js_max, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_vararg_method_ret(&js_min, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_str(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_vararg_method_ret(&js_str, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_print(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_print, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_print_rich(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_print_rich, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_printerr(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_printerr, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_printt(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_printt, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_prints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_prints, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_printraw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_printraw, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_print_verbose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_print_verbose, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_push_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_push_error, ctx, this_val, argc, argv);
}
static JSValue utility_functions_class_push_warning(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_vararg_method_no_ret(&js_push_warning, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry utility_functions_class_funcs[] = {
	JS_CFUNC_DEF("sin", 1, &utility_functions_class_sin),
	JS_CFUNC_DEF("cos", 1, &utility_functions_class_cos),
	JS_CFUNC_DEF("tan", 1, &utility_functions_class_tan),
	JS_CFUNC_DEF("sinh", 1, &utility_functions_class_sinh),
	JS_CFUNC_DEF("cosh", 1, &utility_functions_class_cosh),
	JS_CFUNC_DEF("tanh", 1, &utility_functions_class_tanh),
	JS_CFUNC_DEF("asin", 1, &utility_functions_class_asin),
	JS_CFUNC_DEF("acos", 1, &utility_functions_class_acos),
	JS_CFUNC_DEF("atan", 1, &utility_functions_class_atan),
	JS_CFUNC_DEF("atan2", 2, &utility_functions_class_atan2),
	JS_CFUNC_DEF("asinh", 1, &utility_functions_class_asinh),
	JS_CFUNC_DEF("acosh", 1, &utility_functions_class_acosh),
	JS_CFUNC_DEF("atanh", 1, &utility_functions_class_atanh),
	JS_CFUNC_DEF("sqrt", 1, &utility_functions_class_sqrt),
	JS_CFUNC_DEF("fmod", 2, &utility_functions_class_fmod),
	JS_CFUNC_DEF("fposmod", 2, &utility_functions_class_fposmod),
	JS_CFUNC_DEF("posmod", 2, &utility_functions_class_posmod),
	JS_CFUNC_DEF("floor", 1, &utility_functions_class_floor),
	JS_CFUNC_DEF("floorf", 1, &utility_functions_class_floorf),
	JS_CFUNC_DEF("floori", 1, &utility_functions_class_floori),
	JS_CFUNC_DEF("ceil", 1, &utility_functions_class_ceil),
	JS_CFUNC_DEF("ceilf", 1, &utility_functions_class_ceilf),
	JS_CFUNC_DEF("ceili", 1, &utility_functions_class_ceili),
	JS_CFUNC_DEF("round", 1, &utility_functions_class_round),
	JS_CFUNC_DEF("roundf", 1, &utility_functions_class_roundf),
	JS_CFUNC_DEF("roundi", 1, &utility_functions_class_roundi),
	JS_CFUNC_DEF("abs", 1, &utility_functions_class_abs),
	JS_CFUNC_DEF("absf", 1, &utility_functions_class_absf),
	JS_CFUNC_DEF("absi", 1, &utility_functions_class_absi),
	JS_CFUNC_DEF("sign", 1, &utility_functions_class_sign),
	JS_CFUNC_DEF("signf", 1, &utility_functions_class_signf),
	JS_CFUNC_DEF("signi", 1, &utility_functions_class_signi),
	JS_CFUNC_DEF("snapped", 2, &utility_functions_class_snapped),
	JS_CFUNC_DEF("snappedf", 2, &utility_functions_class_snappedf),
	JS_CFUNC_DEF("snappedi", 2, &utility_functions_class_snappedi),
	JS_CFUNC_DEF("pow", 2, &utility_functions_class_pow),
	JS_CFUNC_DEF("log", 1, &utility_functions_class_log),
	JS_CFUNC_DEF("exp", 1, &utility_functions_class_exp),
	JS_CFUNC_DEF("is_nan", 1, &utility_functions_class_is_nan),
	JS_CFUNC_DEF("is_inf", 1, &utility_functions_class_is_inf),
	JS_CFUNC_DEF("is_equal_approx", 2, &utility_functions_class_is_equal_approx),
	JS_CFUNC_DEF("is_zero_approx", 1, &utility_functions_class_is_zero_approx),
	JS_CFUNC_DEF("is_finite", 1, &utility_functions_class_is_finite),
	JS_CFUNC_DEF("ease", 2, &utility_functions_class_ease),
	JS_CFUNC_DEF("step_decimals", 1, &utility_functions_class_step_decimals),
	JS_CFUNC_DEF("lerp", 3, &utility_functions_class_lerp),
	JS_CFUNC_DEF("lerpf", 3, &utility_functions_class_lerpf),
	JS_CFUNC_DEF("cubic_interpolate", 5, &utility_functions_class_cubic_interpolate),
	JS_CFUNC_DEF("cubic_interpolate_angle", 5, &utility_functions_class_cubic_interpolate_angle),
	JS_CFUNC_DEF("cubic_interpolate_in_time", 8, &utility_functions_class_cubic_interpolate_in_time),
	JS_CFUNC_DEF("cubic_interpolate_angle_in_time", 8, &utility_functions_class_cubic_interpolate_angle_in_time),
	JS_CFUNC_DEF("bezier_interpolate", 5, &utility_functions_class_bezier_interpolate),
	JS_CFUNC_DEF("bezier_derivative", 5, &utility_functions_class_bezier_derivative),
	JS_CFUNC_DEF("angle_difference", 2, &utility_functions_class_angle_difference),
	JS_CFUNC_DEF("lerp_angle", 3, &utility_functions_class_lerp_angle),
	JS_CFUNC_DEF("inverse_lerp", 3, &utility_functions_class_inverse_lerp),
	JS_CFUNC_DEF("remap", 5, &utility_functions_class_remap),
	JS_CFUNC_DEF("smoothstep", 3, &utility_functions_class_smoothstep),
	JS_CFUNC_DEF("move_toward", 3, &utility_functions_class_move_toward),
	JS_CFUNC_DEF("rotate_toward", 3, &utility_functions_class_rotate_toward),
	JS_CFUNC_DEF("deg_to_rad", 1, &utility_functions_class_deg_to_rad),
	JS_CFUNC_DEF("rad_to_deg", 1, &utility_functions_class_rad_to_deg),
	JS_CFUNC_DEF("linear_to_db", 1, &utility_functions_class_linear_to_db),
	JS_CFUNC_DEF("db_to_linear", 1, &utility_functions_class_db_to_linear),
	JS_CFUNC_DEF("wrap", 3, &utility_functions_class_wrap),
	JS_CFUNC_DEF("wrapi", 3, &utility_functions_class_wrapi),
	JS_CFUNC_DEF("wrapf", 3, &utility_functions_class_wrapf),
	JS_CFUNC_DEF("maxi", 2, &utility_functions_class_maxi),
	JS_CFUNC_DEF("maxf", 2, &utility_functions_class_maxf),
	JS_CFUNC_DEF("mini", 2, &utility_functions_class_mini),
	JS_CFUNC_DEF("minf", 2, &utility_functions_class_minf),
	JS_CFUNC_DEF("clamp", 3, &utility_functions_class_clamp),
	JS_CFUNC_DEF("clampi", 3, &utility_functions_class_clampi),
	JS_CFUNC_DEF("clampf", 3, &utility_functions_class_clampf),
	JS_CFUNC_DEF("nearest_po2", 1, &utility_functions_class_nearest_po2),
	JS_CFUNC_DEF("pingpong", 2, &utility_functions_class_pingpong),
	JS_CFUNC_DEF("randomize", 0, &utility_functions_class_randomize),
	JS_CFUNC_DEF("randi", 0, &utility_functions_class_randi),
	JS_CFUNC_DEF("randf", 0, &utility_functions_class_randf),
	JS_CFUNC_DEF("randi_range", 2, &utility_functions_class_randi_range),
	JS_CFUNC_DEF("randf_range", 2, &utility_functions_class_randf_range),
	JS_CFUNC_DEF("randfn", 2, &utility_functions_class_randfn),
	JS_CFUNC_DEF("seed", 1, &utility_functions_class_seed),
	JS_CFUNC_DEF("rand_from_seed", 1, &utility_functions_class_rand_from_seed),
	JS_CFUNC_DEF("weakref", 1, &utility_functions_class_weakref),
	JS_CFUNC_DEF("typeof", 1, &utility_functions_class_typeof),
	JS_CFUNC_DEF("type_convert", 2, &utility_functions_class_type_convert),
	JS_CFUNC_DEF("error_string", 1, &utility_functions_class_error_string),
	JS_CFUNC_DEF("type_string", 1, &utility_functions_class_type_string),
	JS_CFUNC_DEF("var_to_str", 1, &utility_functions_class_var_to_str),
	JS_CFUNC_DEF("str_to_var", 1, &utility_functions_class_str_to_var),
	JS_CFUNC_DEF("var_to_bytes", 1, &utility_functions_class_var_to_bytes),
	JS_CFUNC_DEF("bytes_to_var", 1, &utility_functions_class_bytes_to_var),
	JS_CFUNC_DEF("var_to_bytes_with_objects", 1, &utility_functions_class_var_to_bytes_with_objects),
	JS_CFUNC_DEF("bytes_to_var_with_objects", 1, &utility_functions_class_bytes_to_var_with_objects),
	JS_CFUNC_DEF("hash", 1, &utility_functions_class_hash),
	JS_CFUNC_DEF("instance_from_id", 1, &utility_functions_class_instance_from_id),
	JS_CFUNC_DEF("is_instance_id_valid", 1, &utility_functions_class_is_instance_id_valid),
	// JS_CFUNC_DEF("is_instance_valid", 1, &utility_functions_class_is_instance_valid),
	JS_CFUNC_DEF("rid_allocate_id", 0, &utility_functions_class_rid_allocate_id),
	JS_CFUNC_DEF("rid_from_int64", 1, &utility_functions_class_rid_from_int64),
	JS_CFUNC_DEF("is_same", 2, &utility_functions_class_is_same),
	JS_CFUNC_DEF("max", 2, &utility_functions_class_max),
	JS_CFUNC_DEF("min", 2, &utility_functions_class_min),
	JS_CFUNC_DEF("str", 1, &utility_functions_class_str),
	JS_CFUNC_DEF("print", 1, &utility_functions_class_print),
	JS_CFUNC_DEF("print_rich", 1, &utility_functions_class_print_rich),
	JS_CFUNC_DEF("printerr", 1, &utility_functions_class_printerr),
	JS_CFUNC_DEF("printt", 1, &utility_functions_class_printt),
	JS_CFUNC_DEF("prints", 1, &utility_functions_class_prints),
	JS_CFUNC_DEF("printraw", 1, &utility_functions_class_printraw),
	JS_CFUNC_DEF("print_verbose", 1, &utility_functions_class_print_verbose),
	JS_CFUNC_DEF("push_error", 1, &utility_functions_class_push_error),
	JS_CFUNC_DEF("push_warning", 1, &utility_functions_class_push_warning),
};

static int js_utility_functions_class_init(JSContext *ctx) {
	classes["UtilityFunctions"] = JS_NewClassID(&classes["UtilityFunctions"]);
	JSClassID class_id = classes["UtilityFunctions"];
	JS_NewClass(JS_GetRuntime(ctx), class_id, &utility_functions_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	JS_SetPropertyFunctionList(ctx, proto, utility_functions_class_funcs, _countof(utility_functions_class_funcs));

	JSValue global = JS_GetGlobalObject(ctx);
	utility_functions_instance = utility_functions_class_constructor(ctx, global, 0, NULL);
	JS_SetPropertyStr(ctx, global, "GD", utility_functions_instance);

	return 0;
}

void register_utility_functions() {
	js_utility_functions_class_init(js_context());
}