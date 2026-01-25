# Lumina Renderer 1.0

A minimal, real-time 3D renderer built in modern C++ with a clean, backend-agnostic architecture.

The project focuses on correctness, clarity, and solid software design rather than advanced rendering features. This renderer is intended as a learning project and a portfolio piece, not a full game engine.

## Project Goals

The primary goal of this project is to design and implement a small but well-architected rendering system that:

- Renders a 3D scene (meshes + camera) in real time
- Maintains a stable 60 FPS on simple scenes
- Cleanly separates engine systems from the rendering backend
- Uses modern C++ (C++23) idioms and language features
- Is small enough to be completed within 1–3 months

## Functional Requirements

### Scene Rendering
Render a scene consisting of:
- Meshes
- A camera

### Display
- Display output in a window and update every frame

### Lighting
Support basic lighting:
- Blinn-Phong or simple PBR

### Performance
- Stable real-time performance (~16ms per frame)

### Collision Detection
Very simple collision detection:
- Spheres
- Axis-Aligned Bounding Boxes (AABBs)

### Final Demonstration
A small playable demo:
- A simple game where the player rolls/controls a ball through an obstacle course
- Used to validate that the renderer is practical and usable, not just a tech demo

## Non-Functional Requirements

### Scalability
- The renderer can be used without knowing which graphics backend is active
- Features can be added incrementally using layers
- Simple scenes can grow in complexity without major performance degradation

### Usability
- Backend-agnostic public API
- Clean separation between engine code and rendering implementation
- Ability to add custom application layers without modifying the renderer core

## Architecture Overview

The engine follows an event-driven, layered architecture, inspired by engines such as Hazel (Cherno).

### High-Level Structure

**Core**
- Application lifecycle
- Layer stack
- Event system

**Renderer API**
- Backend-agnostic interfaces (buffers, shaders, textures, etc.)

**Rendering Backend**
- Concrete implementation (initially OpenGL)

**Layers**
- Game logic
- Rendering logic
- Input handling

**Scene**
- Camera
- Meshes
- Basic collision primitives

### Key Architectural Rule

**No graphics-API-specific headers or types (OpenGL, Vulkan, etc.) are allowed outside the rendering backend.**

### Rendering Backend

- **Initial backend:** OpenGL
- The architecture is designed to allow additional backends (e.g. Vulkan) in the future
- Only one backend is implemented for this project

## Non-Goals

To keep scope under control, the following are explicitly out of scope:

- No ECS
- No editor
- No multithreaded renderer
- No deferred rendering
- No advanced physics engine
- No complex asset pipeline
- No scripting system

## Constraints

- **Time budget:** 1–3 months
- **Language standard:** C++23
- **Target platform:** Desktop (Linux / Windows)
- **Performance target:** 60 FPS on simple scenes

## Development Philosophy

### No AI-Generated Code
- All code is written manually
- Bugs and issues are researched via documentation and search engines

### Emphasis on:
- Clear abstractions
- Readable code
- Correctness over cleverness

### Prefer modern C++ features over legacy patterns:
- RAII
- Strong typing
- Standard library containers and utilities

## Why This Project Exists

The term "3D game engine" is extremely broad.

This project deliberately narrows the scope to focus on:
- Rendering fundamentals
- Engine architecture
- Graphics programming concepts
- Building something complete and explainable

The result is a renderer that is small, understandable, and suitable for a portfolio.
