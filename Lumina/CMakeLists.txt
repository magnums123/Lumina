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
find_package(glfw3 REQUIRED)

add_subdirectory(external/glad)
add_subdirectory(external/glm)
add_subdirectory(external/spdlog)
add_subdirectory(external/imgui)

target_link_libraries(Lumina
    PRIVATE
        glad
        spdlog
        Vulkan::Vulkan
        glfw
        imgui
    PUBLIC
        glm
)

# Platform-specific stuff (Linux)
if (UNIX AND NOT APPLE)
    target_link_libraries(Lumina PUBLIC dl pthread)
endif()

# Export symbol visibility (important for shared libs)
target_compile_definitions(Lumina PRIVATE LUMINA_BUILD_DLL)
