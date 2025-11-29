#include "utils/env.hpp"
#include <quickjs.h>

JSContext *js_context() {
	static JSContext *ctx = JS_NewContext(js_runtime());
	return ctx;
}

JSRuntime *js_runtime() {
	static JSRuntime *rt = JS_NewRuntime();
	return rt;
}