#include "register/register_builtin_classes.h"
#include "register/utils.h"

using namespace godot;

void register_builtin_classes_Callable() {
	_Variant.class_<Callable>("Callable")
            .constructor<>()
            .constructor<const Callable &>("Callable_1")
            .constructor<Object *,const StringName &>("Callable_2")

			.fun<static_cast<Variant(Callable::*)(const Array &)const>(&Callable::callv)>("callv")
			.fun<static_cast<bool(Callable::*)()const>(&Callable::is_null)>("is_null")
			.fun<static_cast<bool(Callable::*)()const>(&Callable::is_custom)>("is_custom")
			.fun<static_cast<bool(Callable::*)()const>(&Callable::is_standard)>("is_standard")
			.fun<static_cast<bool(Callable::*)()const>(&Callable::is_valid)>("is_valid")
			.fun<static_cast<Object *(Callable::*)()const>(&Callable::get_object)>("get_object")
			.fun<static_cast<int64_t(Callable::*)()const>(&Callable::get_object_id)>("get_object_id")
			.fun<static_cast<StringName(Callable::*)()const>(&Callable::get_method)>("get_method")
			.fun<static_cast<int64_t(Callable::*)()const>(&Callable::get_bound_arguments_count)>("get_bound_arguments_count")
			.fun<static_cast<Array(Callable::*)()const>(&Callable::get_bound_arguments)>("get_bound_arguments")
			.fun<static_cast<int64_t(Callable::*)()const>(&Callable::hash)>("hash")
			.fun<static_cast<Callable(Callable::*)(const Array &)>(&Callable::bindv)>("bindv")
			.fun<static_cast<Callable(Callable::*)(int64_t)const>(&Callable::unbind)>("unbind")
			.fun<static_cast<Variant(Callable::*)(rest<Variant> args)const>(&Callable::call)>("call")
			.fun<static_cast<void(Callable::*)(rest<Variant> args)const>(&Callable::call_deferred)>("call_deferred")
			.fun<static_cast<void(Callable::*)(rest<Variant> args)const>(&Callable::rpc)>("rpc")
			.fun<static_cast<void(Callable::*)(int64_t,rest<Variant> args)const>(&Callable::rpc_id)>("rpc_id")
			.fun<static_cast<Callable(Callable::*)(rest<Variant> args)const>(&Callable::bind)>("bind");
}