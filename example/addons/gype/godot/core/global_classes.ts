import { Node } from "@godot/classes/node";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class GlobalClasses extends Node {
	public _ready(): void {
		let global = globalThis as any;
		global.Input = new _Input();
		global.Performance = new _Performance();
		global.TextServerManager = new _TextServerManager();
		global.PhysicsServer2DManager = new _PhysicsServer2DManager();
		global.PhysicsServer3DManager = new _PhysicsServer3DManager();
		global.NavigationMeshGenerator = new _NavigationMeshGenerator();
		global.ProjectSettings = new _ProjectSettings();
		global.IP = new _IP();
		global.Geometry2D = new _Geometry2D();
		global.Geometry3D = new _Geometry3D();
		global.ResourceLoader = new _ResourceLoader();
		global.ResourceSaver = new _ResourceSaver();
		global.OS = new _OS();
		global.Engine = new _Engine();
		global.ClassDB = new _ClassDB();
		global.Marshalls = new _Marshalls();
		global.TranslationServer = new _TranslationServer();
		global.InputMap = new _InputMap();
		global.EngineDebugger = new _EngineDebugger();
		global.Time = new _Time();
		global.ResourceUID = new _ResourceUID();
		global.WorkerThreadPool = new _WorkerThreadPool();
		global.ThemeDB = new _ThemeDB();
		// global.EditorInterface = new _EditorInterface();
		global.JavaClassWrapper = new _JavaClassWrapper();
		global.JavaScriptBridge = new _JavaScriptBridge();
		global.AudioServer = new _AudioServer();
		global.CameraServer = new _CameraServer();
		global.DisplayServer = new _DisplayServer();
		global.NativeMenu = new _NativeMenu();
		global.NavigationServer2D = new _NavigationServer2D();
		global.NavigationServer3D = new _NavigationServer3D();
		global.RenderingServer = new _RenderingServer();
		global.PhysicsServer2D = new _PhysicsServer2D();
		global.PhysicsServer3D = new _PhysicsServer3D();
		global.XRServer = new _XRServer();
		
	}

	public _process(delta: number): void {

	}
}
	
