project(Sandbox LANGUAGES CXX)

add_executable(Sandbox
    src/Sandbox.cpp
)

target_include_directories(Sandbox
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Lumina/src
)

target_link_libraries(Sandbox
    PRIVATE
        Lumina
)
