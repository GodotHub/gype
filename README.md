Quick Start
```typescript
import { Node2D } from "@godot/classes/node2d";

export default class HelloWorld extends Node2D {
  public _ready(): void {
    GD.print("Hello World!");
  }
}

```

可以查看`example`目录下的例子。  
> 源代码仓库内不包含编译好的二进制文件，因此addons目录需要自行导入插件。  

注意：  
1. Godot的`variant`类型均在全局作用域，无需`import`即可使用  
2. Godot的`object`类均在`godot/classes/xxxx`，如`godot/classes/node`  
3. Godot的工具函数均在`GD`单例内，例如`GD.print()`

#### 配置编译器
该项目使用msvc编译,使用cmake生成build之后使用编辑器打开.sln文件即可
