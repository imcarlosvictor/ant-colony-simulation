cmake_minimum_required(VERSION 3.16)
project(ant-colony-sim)

# set the output directory for build objects
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(sdl/vendored/SDL EXCLUDE_FROM_ALL)

add_executable(ant-colony-sim main.cpp)
target_link_libraries(ant-colony-sim PRIVATE SDL3::SDL3)
