#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xml_parser.hpp>
using namespace godot;

static void xml_parser_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XMLParser"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef xml_parser_class_def = {
    "XMLParser",
    xml_parser_class_finalizer
};

static JSValue xml_parser_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XMLParser"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XMLParser *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XMLParser *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XMLParser);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xml_parser_class_read(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XMLParser::read, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_node_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XMLParser::get_node_type, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_node_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_node_name, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_node_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_node_data, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_node_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_node_offset, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_attribute_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_attribute_count, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_attribute_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_attribute_name, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_attribute_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_attribute_value, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_has_attribute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::has_attribute, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_named_attribute_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_named_attribute_value, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_named_attribute_value_safe(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_named_attribute_value_safe, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_is_empty(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::is_empty, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_get_current_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XMLParser::get_current_line, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_skip_section(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XMLParser::skip_section, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_seek(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XMLParser::seek, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XMLParser::open, ctx, this_val, argc, argv);
};
static JSValue xml_parser_class_open_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XMLParser::open_buffer, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xml_parser_class_proto_funcs[] = {
	JS_CFUNC_DEF("read", 0, &xml_parser_class_read),
	JS_CFUNC_DEF("get_node_type", 0, &xml_parser_class_get_node_type),
	JS_CFUNC_DEF("get_node_name", 0, &xml_parser_class_get_node_name),
	JS_CFUNC_DEF("get_node_data", 0, &xml_parser_class_get_node_data),
	JS_CFUNC_DEF("get_node_offset", 0, &xml_parser_class_get_node_offset),
	JS_CFUNC_DEF("get_attribute_count", 0, &xml_parser_class_get_attribute_count),
	JS_CFUNC_DEF("get_attribute_name", 1, &xml_parser_class_get_attribute_name),
	JS_CFUNC_DEF("get_attribute_value", 1, &xml_parser_class_get_attribute_value),
	JS_CFUNC_DEF("has_attribute", 1, &xml_parser_class_has_attribute),
	JS_CFUNC_DEF("get_named_attribute_value", 1, &xml_parser_class_get_named_attribute_value),
	JS_CFUNC_DEF("get_named_attribute_value_safe", 1, &xml_parser_class_get_named_attribute_value_safe),
	JS_CFUNC_DEF("is_empty", 0, &xml_parser_class_is_empty),
	JS_CFUNC_DEF("get_current_line", 0, &xml_parser_class_get_current_line),
	JS_CFUNC_DEF("skip_section", 0, &xml_parser_class_skip_section),
	JS_CFUNC_DEF("seek", 1, &xml_parser_class_seek),
	JS_CFUNC_DEF("open", 1, &xml_parser_class_open),
	JS_CFUNC_DEF("open_buffer", 1, &xml_parser_class_open_buffer),
};




static void define_xml_parser_property(JSContext *ctx, JSValue proto) {
}

static void define_xml_parser_enum(JSContext *ctx, JSValue ctor) {
	JSValue NodeType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_ELEMENT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_ELEMENT_END", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_TEXT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_COMMENT", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_CDATA", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, NodeType_obj, "NODE_UNKNOWN", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "NodeType", NodeType_obj);
}

static int js_xml_parser_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XMLParser"] = class_id;
	classes_by_id[class_id] = "XMLParser";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xml_parser_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xml_parser_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xml_parser_class_proto_funcs, _countof(xml_parser_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xml_parser_class_constructor, "XMLParser", 0, JS_CFUNC_constructor, 0);
	define_xml_parser_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XMLParser", ctor);

	return 0;
}

JSModuleDef *_js_init_xml_parser_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xml_parser_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XMLParser");
	return m;
}

JSModuleDef *js_init_xml_parser_module(JSContext *ctx) {
	return _js_init_xml_parser_module(ctx, "@godot/classes/xml_parser");
}

void __register_xml_parser() {
	js_init_xml_parser_module(js_context());
}

void register_xml_parser() {
	__register_xml_parser();
}