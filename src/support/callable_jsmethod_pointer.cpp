#include "support/callable_jsmethod_pointer.hpp"

namespace godot {
static void custom_callable_mp_call(void *p_userdata, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	CallableCustomMethodPointerBase *callable_method_pointer = (CallableCustomMethodPointerBase *)p_userdata;
	callable_method_pointer->call((const Variant **)p_args, p_argument_count, *(Variant *)r_return, *r_error);
}

static GDExtensionBool custom_callable_mp_is_valid(void *p_userdata) {
	CallableCustomMethodPointerBase *callable_method_pointer = (CallableCustomMethodPointerBase *)p_userdata;
	ObjectID object = callable_method_pointer->get_object();
	return object == ObjectID() || ObjectDB::get_instance(object);
}

static void custom_callable_mp_free(void *p_userdata) {
	CallableJSMethodPointer *callable_method_pointer = (CallableJSMethodPointer *)p_userdata;
	JS_FreeValue(js_context(), callable_method_pointer->function);
	memdelete(callable_method_pointer);
}

static uint32_t custom_callable_mp_hash(void *p_userdata) {
	CallableCustomMethodPointerBase *callable_method_pointer = (CallableCustomMethodPointerBase *)p_userdata;
	return callable_method_pointer->get_hash();
}

static GDExtensionBool custom_callable_mp_equal_func(void *p_a, void *p_b) {
	CallableCustomMethodPointerBase *a = (CallableCustomMethodPointerBase *)p_a;
	CallableCustomMethodPointerBase *b = (CallableCustomMethodPointerBase *)p_b;

	if (a->get_comp_size() != b->get_comp_size()) {
		return false;
	}

	return memcmp(a->get_comp_ptr(), b->get_comp_ptr(), a->get_comp_size() * 4) == 0;
}

static GDExtensionBool custom_callable_mp_less_than_func(void *p_a, void *p_b) {
	CallableCustomMethodPointerBase *a = (CallableCustomMethodPointerBase *)p_a;
	CallableCustomMethodPointerBase *b = (CallableCustomMethodPointerBase *)p_b;

	if (a->get_comp_size() != b->get_comp_size()) {
		return a->get_comp_size() < b->get_comp_size();
	}

	return memcmp(a->get_comp_ptr(), b->get_comp_ptr(), a->get_comp_size() * 4) < 0;
}

static GDExtensionInt custom_callable_mp_get_argument_count_func(void *p_userdata, GDExtensionBool *r_is_valid) {
	CallableCustomMethodPointerBase *callable_method_pointer = (CallableCustomMethodPointerBase *)p_userdata;
	bool valid = false;
	int ret = callable_method_pointer->get_argument_count(valid);
	*r_is_valid = valid;
	return ret;
}

Callable create_custom_javascript_callable(JSValue instance, JSValue function) {
	CallableJSMethodPointer *ccmp = memnew(CallableJSMethodPointer(instance, function));
	JS_DupValue(js_context(), function);
	return ::internal::create_callable_from_ccmp(ccmp);
}

Callable create_custom_javascript_callable(JSValue function) {
	CallableJSMethodPointer *ccmp = memnew(CallableJSMethodPointer(JS_UNDEFINED, function));
	return ::internal::create_callable_from_ccmp(ccmp);
}

int CallableJSMethodPointer::get_argument_count(bool &r_is_valid) const {
	JSValue js_count = JS_GetPropertyStr(js_context(), instance, "length");
	int32_t count;
	r_is_valid = !JS_ToInt32(js_context(), &count, js_count);
	return count;
}

void CallableJSMethodPointer::call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const {
	std::vector<JSValue> args;
	for (int i = 0; i < p_argcount; i++) {
		args.push_back(VariantAdapter((*p_arguments)[i]));
	}
	JSValue ret = JS_Call(js_context(), function, instance, p_argcount, args.data());
	if (is_exception(js_context(), ret)) {
		r_call_error.error = GDExtensionCallErrorType::GDEXTENSION_CALL_ERROR_INVALID_METHOD;
	}
	r_return_value = VariantAdapter(ret).get();
	r_call_error.error = GDExtensionCallErrorType::GDEXTENSION_CALL_OK;
}

CallableJSMethodPointer::CallableJSMethodPointer(JSValue instance, JSValue function) {
	this->instance = instance;
	this->function = function;
	JS_DupValue(js_context(), function);
}

namespace internal {
Callable create_callable_from_ccmp(CallableCustomMethodPointerBase *p_callable_method_pointer) {
	GDExtensionCallableCustomInfo2 info = {};
	info.callable_userdata = p_callable_method_pointer;
	info.token = internal::token;
	info.object_id = p_callable_method_pointer->get_object();
	info.call_func = &custom_callable_mp_call;
	info.is_valid_func = &custom_callable_mp_is_valid;
	info.free_func = &custom_callable_mp_free;
	info.hash_func = &custom_callable_mp_hash;
	info.equal_func = &custom_callable_mp_equal_func;
	info.less_than_func = &custom_callable_mp_less_than_func;
	info.get_argument_count_func = &custom_callable_mp_get_argument_count_func;

	Callable callable;
	::godot::internal::gdextension_interface_callable_custom_create2(callable._native_ptr(), &info);
	return callable;
}
} // namespace internal
} //namespace godot