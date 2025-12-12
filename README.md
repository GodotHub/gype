Quick Start
```typescript
import { Node2D } from "@godot/classes/node2d";

export default class HelloWorld extends Node2D {
  public _ready(): void {
    GD.print("Hello World!");
  }
}

```