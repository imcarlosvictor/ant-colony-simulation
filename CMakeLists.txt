cmake_minimum_required(VERSION 3.16)
project(ant-colony-sim)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/SDL/vendored/SDL EXCLUDE_FROM_ALL)

# ImGui has no CMakeLists.txt of its own — build its sources as a static lib
set(IMGUI_DIR lib/imgui)
add_library(imgui STATIC
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp
)
target_include_directories(imgui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)
target_link_libraries(imgui PUBLIC SDL3::SDL3)

add_executable(ant-colony-sim
    src/main.cpp
    src/window.cpp
    src/ant.cpp
    src/colony.cpp
    src/map.cpp
    src/tile.cpp
		src/gui.cpp
)
target_link_libraries(ant-colony-sim PRIVATE SDL3::SDL3 imgui)
