cmake_minimum_required(VERSION 3.16)
project(ant-colony-sim)

# set the output directory for build objects
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# generate compile_commands.json for your editor/LSP (fixes the ALE squiggle too)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(SDL/vendored/SDL EXCLUDE_FROM_ALL)

add_executable(ant-colony-sim 
	src/main.cpp
	src/window.cpp
	src/ant.cpp
	src/colony.cpp
	src/map.cpp
	src/tile.cpp
)

target_link_libraries(ant-colony-sim PRIVATE SDL3::SDL3)
