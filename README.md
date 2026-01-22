Lumina Game Engine

Lumina is a lightweight, modular 3D game engine written in C++20/23, designed with flexibility and future expansion in mind.
Currently, it supports OpenGL rendering and GLFW for window/context management. The engine is being developed from scratch with a focus on a clean architecture and modular RHI (Rendering Hardware Interface) design, allowing for future support for Vulkan and DirectX.


---

Features (WIP)

Modular Layer system for game logic and rendering

OpenGL Renderer with basic shader and buffer management

GLFW-based window creation and input handling

Event system for flexible input and window events

Abstracted RHI design for multi-backend support

Scene and camera abstractions (planned)



---

Getting Started

Requirements

C++20/23 compiler (g++, clang++)

GLFW

GLM

GLAD


> All dependencies should be installed globally.



Build

Clone the repository:

git clone https://github.com/<your-username>/Lumina.git  
cd Lumina  
Build using the provided Makefile:  
Copy code  
Bash  
make  
Run the engine:  
Copy code  
Bash  
./engine  
Folder Structure (Work In Progress)  
Copy code  
  
src/  
 ├─ Core/           # Application, Layer, LayerStack, Event system  
 ├─ Layers/         # Example game layers  
 ├─ Platform/       # Platform-specific window code (GLFW)  
 ├─ RHI/            # Rendering Hardware Interface abstraction  
 │    └─ OpenGL/    # OpenGL-specific implementations  
 └─ main.cpp        # Entry point  
Contributing  
This engine is in the very early stages. Contributions and suggestions are welcome, especially regarding:  
Renderer design (OpenGL, Vulkan, DX)  
Scene abstraction  
Event and Layer system improvements  
License  
MIT License. See LICENSE for more details.  
Copy code  
  
I kept it **lightweight but clear**, with room to grow.    
  
  
  
  
Structure is off
