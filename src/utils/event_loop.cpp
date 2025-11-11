#include "utils/event_loop.hpp"
#include "utils/env.hpp"
#include <quickjs.h>

using namespace godot;

void EventLoop::_bind_methods() {
}

void EventLoop::_process(double delta) {
	JSContext *ctx = js_context();
	if (JS_IsJobPending(js_runtime()) && JS_ExecutePendingJob(js_runtime(), &ctx) < 0) {
		godot::UtilityFunctions::print("Error executing pending job.");
	}
}

void GypePlugin::_enter_tree() {
	event_loop = memnew(EventLoop());
	add_child(event_loop);
}

void GypePlugin::_bind_methods() {
}