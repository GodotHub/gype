import {Button} from "@godot/classes/button";
import {GodotClass, GodotExport, GodotSignal, GodotTool, to_promise} from "@godot/core/class_defined";

@GodotClass
export class Test extends Button {

  //@GodotSignal
  //private test_signal!: Signal;

  @GodotExport(Variant.Type.INT)
  private test_export: number = 10;

  private test_export2: number = 50;

  public async _enter_tree(): Promise<void> {
	//await to_promise(this.test_signal);
	//GD.print("test_signal");
  }

  public _ready(): void {
	GD.print('test_export: ', this.test_export);
	GD.print('test_export2: ', this.test_export2);
	//this.test_signal.emit();
  }

  public _process(delta: number): void {
  }
}
