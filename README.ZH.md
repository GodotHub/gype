## GypeScript  
  
Godot引擎，但是带有JavaScript/TypeScript支持  
  
[English](https://github.com/GodotHub/Gype) &nbsp;&nbsp;&nbsp;&nbsp;[中文](https://github.com/GodotHub/Gype/blob/master/README.ZH.md)  

## 快速开始

在Godot项目中导入[插件](https://github.com/GodotHub/Gype/releases/download/1.0.0/addons.zip)，像GDS一样使用：  
```ts
import { Button } from "@godot/classes/button";
import { GodotClass } from "@godot/core/class_defined";
import { Label } from "@godot/classes/label";

@GodotClass
export class ClickGype extends Button {
	#label?: Label;
	#count = 0;

	public _ready(): void {
		this.#label = this.get_node("../Label");
		this.pressed.connect(new Callable(this, this.add_count));
	}

	public add_count() {
		this.#label!.text = (this.#count++).toString();
	}

	public _process(delta: number): void {

	}
}
```  

可以查看`example`目录下的例子。  
> 源代码仓库内不包含编译好的二进制文件，因此addons目录需要自行导入插件。  

注意：  
1. Godot的`variant`类型均在全局作用域，无需`import`即可使用  
2. Godot的`object`类均在`godot/classes/xxxx`，如`godot/classes/node`  
3. Godot的工具函数均在`GD`单例内，例如`GD.print()`  

## 项目规划

1. ✅ 运行JS/TS脚本  
2. ✅ 添加Godot API的JS/TS绑定  
3. 🟦 通过JS/TS绑定实现新版GMUI  
4. 🟨 为JS/TS脚本添加编辑器支持  
5. 🟦🟨✅...  

## 编译项目

#### 配置编译器

在Linux上，直接使用GCC即可  
  
在Windows，下载[mingw64 (posix version)](https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev1/x86_64-13.2.0-release-posix-seh-msvcrt-rt_v11-rev1.7z)然后设置PATH环境变量  

#### 构建二进制文件

Windows: 在仓库根目录里执行`./build.ps1`  
