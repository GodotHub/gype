import * as internal from '__internal__';
import { TextServerExtension } from 'src/js_godot/classestext_server_extension'
class _MethodBindings {
}


export class TextServerDummy extends TextServerExtension{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("TextServerDummy");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
  }
}