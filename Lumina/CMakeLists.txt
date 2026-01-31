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
)

#So glfw can be built in termux
set(GLFW_BUILD_X11 OFF)
set(GLFW_BUILD_WAYLAND ON)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

# set(GLFW_USE_WAYLAND ON)
set(GLFW_X11_XRANDR OFF CACHE BOOL "" FORCE)
set(GLFW_LIBRARY_TYPE STATIC)
# set(GLFW_USE_XRANDR OFF)

# glad
add_subdirectory(external/glad)
add_subdirectory(external/glm)
add_subdirectory(external/spdlog)
add_subdirectory(external/glfw)

target_link_libraries(Lumina
    PUBLIC
        glad
        glm
        spdlog
        glfw
)

# Platform-specific stuff (Linux)
if (UNIX AND NOT APPLE)
    target_link_libraries(Lumina PUBLIC dl pthread)
endif()

# Export symbol visibility (important for shared libs)
target_compile_definitions(Lumina PRIVATE LUMINA_BUILD_DLL)
