#ifndef __CALLABLE_JSMETHOD_POINTER_H__
#define __CALLABLE_JSMETHOD_POINTER_H__

#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/templates/hashfuncs.hpp>
#include <godot_cpp/variant/callable_method_pointer.hpp>
#include <vector>

namespace godot {
namespace internal {
Callable create_callable_from_ccmp(CallableCustomMethodPointerBase *p_callable_method_pointer);
} //namespace internal

class CallableJSMethodPointer : public CallableCustomMethodPointerBase {

public:
	JSValue instance;
	JSValue function;
	
	virtual ObjectID get_object() const override {
		if (JS_IsUndefined(instance) || !JS_IsObject(instance)) {
			return ObjectID();
		}
		
		JSClassID class_id = JS_GetClassID(instance);
		if (!classes_by_id.has(class_id)) {
			return ObjectID();
		}

		VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(instance, class_id));
		if (!adapter) {
			return ObjectID();
		}

		Object *obj = adapter->get();
		if (!obj) {
			return ObjectID();
		}

		return ObjectID(obj->get_instance_id());
	}

	virtual int get_argument_count(bool &r_is_valid) const override;
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override;

	CallableJSMethodPointer(JSValue instance, JSValue function);
};

Callable create_custom_javascript_callable(JSValue instance, JSValue function);
Callable create_custom_javascript_callable(JSValue function);
} //namespace godot

#endif // __CALLABLE_JSMETHOD_POINTER_H__