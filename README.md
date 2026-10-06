## 1) About
A C++ game engine built from scratch, currently using OpenGL for rendering with Vulkan planned as a second graphics API in the future.

This project is attempting to building a modular engine primarily for game development use.

## 2) Prerequisites
* CMake ≥ 3.10
* A C++17-capable compiler:
  * Windows: MSVC (Visual Studio), or clang/MinGW
  * macOS: Apple Clang (Xcode command line tools)
  * Linux: GCC or Clang
* Platform SDK / development tools:
  * Windows: install “Desktop development with C++” (for MSVC)
  * macOS: xcode-select --install
  * Linux: install build-essential (Debian/Ubuntu) or equivalents

## 3) Project Structure
This project was built with abstraction and proper architecture as a key focus.

```text
src/
├── graphics/
│   ├── GraphicsAPI
│   ├── ShaderProgram
│   └── VertexLayout
│
├── input/
│   └── InputManager
│
├── render/
│   ├── Material
│   ├── Mesh
│   └── RenderQueue
│
├── scene/
│   ├── GameObject
│   └── Scene
│
├── Application
└── Engine
```

<img width="1274" height="2268" alt="image" src="https://github.com/user-attachments/assets/3af83b5e-a8a7-4a74-84c9-e74d6b612328" />

### Graphics Layer
* **GraphicsAPI:** Acts as the engine's interface to the graphics backend. (Soon to include Vulkan)
* **ShaderProgram:** Encapsulates shader compilation, binding, and uniform management.
* **VertexLayout:** Defines vertex attribute layouts independently from mesh data.

### Engine Core
**Engine**
* Owns the graphics, rendering, and input systems.
* Manages the application lifecycle.
* Executes the main loop.

**Application**
* Defines the game-specific implementation.
* Provides initialization, update, and shutdown behavior.
