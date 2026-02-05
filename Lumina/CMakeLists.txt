project(Lumina LANGUAGES CXX)

# Gather source files
file(GLOB_RECURSE LUMINA_SRC
    src/Lumina/*.cpp
)

add_library(Lumina SHARED ${LUMINA_SRC})

target_include_directories(Lumina
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glm/glm
        ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
)

find_package(Vulkan REQUIRED)

# In GLFW build
set(GLFW_BUILD_WIN32 ON CACHE BOOL "" FORCE)
set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_COCOA OFF CACHE BOOL "" FORCE)
set(GLFW_USE_JOYSTICK OFF CACHE BOOL "" FORCE)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(external/glad)
add_subdirectory(external/glm)
add_subdirectory(external/spdlog)
add_subdirectory(external/glfw)
add_subdirectory(external/imgui)

target_link_libraries(Lumina
    PRIVATE
        glad
        spdlog
        Vulkan::Vulkan
        glfw
        imgui
        imgui_vulkan
    PUBLIC
        glm
        X11
)

# Platform-specific stuff (Linux)
if (UNIX AND NOT APPLE)
    target_link_libraries(Lumina PUBLIC dl pthread)
endif()

# Export symbol visibility (important for shared libs)
target_compile_definitions(Lumina PRIVATE LUMINA_BUILD_DLL)
