#ifndef __EVENT_LOOP_H__
#define __EVENT_LOOP_H__

#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/node.hpp>

class EventLoop : public godot::Node {
	GDCLASS(EventLoop, Node);

protected:
	static void _bind_methods();

public:
	void _process(double delta) override;
};

class GypePlugin : public godot::EditorPlugin {
	GDCLASS(GypePlugin, EditorPlugin);

	EventLoop *event_loop = nullptr;
protected:
	static void _bind_methods();

public:
	void _enter_tree() override;
};

#endif // __EVENT_LOOP_H__