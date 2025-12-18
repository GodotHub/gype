Godot-TypeScript 快速入门指南
欢迎来到 Godot-TypeScript 集成项目！本指南将帮助您快速搭建开发环境，并编写您的第一个脚本。让我们一起体验在 Godot 中使用 TypeScript 的强大与便捷。

# 🚀 快速开始
### 1. 前置准备
在开始之前，请确保您的系统已安装以下工具：

Godot Engine: 项目所依赖的引擎版本。
Node.js & npm: 用于管理 TypeScript 项目依赖。
C++ 编译器:
Windows: MSVC (Visual Studio Build Tools)。
macOS: Clang (Xcode Command Line Tools)。
Linux: GCC。
CMake: 用于生成跨平台的编译项目。
### 2. 环境搭建
步骤一：获取源代码
首先，克隆本仓库到您的本地机器。

git clone [(https://github.com/GodotHub/gype.git)](https://github.com/GodotHub/gype.git)
步骤二：编译核心插件
重要提示：源代码仓库内不包含编译好的二进制文件。您需要自行编译，并将生成的文件放入 Godot 项目的 addons 目录。

生成构建文件:
使用 CMake 在项目根目录下创建一个 build 目录并生成构建文件。

cmake -B build
执行编译:

Windows (MSVC):
使用 Visual Studio 打开 build 目录下生成的 .sln 解决方案文件，然后执行“生成解决方案”(Build Solution)。
macOS/Linux (Make):
进入 build 目录并使用 make 命令进行编译。
cd build
make
安装插件:
编译成功后，将生成的插件目录（通常包含 bin 和 plugin.cfg 等文件）完整复制到您的 Godot 项目的 addons/ 目录下。

### 3. 您的第一个 TypeScript 脚本
现在，让我们来编写一个经典的 "Hello World" 脚本。在 Godot 编辑器中创建一个新的 Node2D 节点，并为其附加一个新的 TypeScript 脚本。

HelloWorld.ts
```typescript
import { Node2D } from "@godot/classes/node2d";

/**
 * 一个简单的示例类，继承自 Godot 的 Node2D。
 * 当节点准备就绪时，它会在控制台打印 "Hello World!"。
 */
export default class HelloWorld extends Node2D {
  /**
   * Godot 的生命周期函数，当节点及其所有子节点都进入场景树时调用。
   * 相当于 GDScript 中的 `_ready()`。
   */
  public _ready(): void {
    // 使用全局的 GD 单例来调用 Godot 的内置函数
    GD.print("Hello from TypeScript!");
  }
}
```
运行场景，您将在 Godot 的输出面板中看到 Hello from TypeScript!。恭喜，您已成功运行了第一个脚本！

### 4. 核心概念：TypeScript 与 Godot 的交互
为了让您更顺畅地开发，请务必理解以下几个关键设计：

#### 1. 全局作用域的 Variant 类型
Godot 的核心数据类型（如 Vector2, Color, StringName 等 Variant 类型）已经被注入到 TypeScript 的全局作用域中。这意味着您无需 import 即可直接使用它们，就像在 GDScript 中一样。
```typescript
// 无需 import Vector2
const playerPosition = new Vector2(100, 150);
this.position = playerPosition;
```
#### 2. 按需导入的 Object 类
所有继承自 Object 的 Godot 类（如 Node, Sprite2D, CharacterBody3D 等）都存放于 @godot/classes/ 路径下，需要手动 import。这种设计可以保持代码清晰，并有利于 Tree Shaking（摇树优化）。

```typescript
// 正确导入
import { Sprite2D } from "@godot/classes/sprite2d";
import { CharacterBody2D } from "@godot/classes/character_body_2d";
```
#### 3. 全局 GD 单例
Godot 的所有全局函数（如 print, load, randi 等）都被统一封装在 GD 这个全局单例对象中。这提供了清晰的命名空间，避免了全局污染。

```typescript
// 加载资源
const myScene = GD.load<PackedScene>("res://my_scene.tscn");

// 生成随机数
const roll = GD.randi_range(1, 6);

// 打印调试信息
GD.print(`You rolled a ${roll}`);
```
### 5. 接下来做什么？
探索示例: 查看项目中的 example 目录，那里包含了更多功能和用法的实际案例，是学习的最佳资源。
查阅类型定义: 利用 VSCode 等编辑器的智能提示（IntelliSense）功能，可以轻松探索所有可用的类和函数。
现在，您已经准备好在 Godot 中尽情享受 TypeScript 带来的类型安全和现代化开发体验了。祝您编码愉快！

