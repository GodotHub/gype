@tool
extends EditorPlugin

var compile_button: Button = null

func _enable_plugin() -> void:
	compile_button = Button.new()
	compile_button.text = "compile"
	compile_button.pressed.connect(compile)
	add_control_to_container(CONTAINER_TOOLBAR, compile_button)
	add_autoload_singleton("EventLoopSingleton", "res://addons/gype/event_loop.gd")
	pass


func _disable_plugin() -> void:
	compile_button.pressed.disconnect(compile)
	remove_control_from_container(CONTAINER_TOOLBAR, compile_button)
	remove_autoload_singleton("EventLoopSingleton")
	compile_button.queue_free()
	pass


func _enter_tree() -> void:
	compile_button = Button.new()
	compile_button.text = "compile"
	compile_button.pressed.connect(compile)
	add_control_to_container(CONTAINER_TOOLBAR, compile_button)
	add_autoload_singleton("EventLoopSingleton", "res://addons/gype/event_loop.gd")
	pass


func _exit_tree() -> void:
	compile_button.pressed.disconnect(compile)
	remove_control_from_container(CONTAINER_TOOLBAR, compile_button)
	remove_autoload_singleton("EventLoopSingleton")
	compile_button.queue_free()
	pass

func compile():
	TypeScriptLanguage.compile_scripts()
