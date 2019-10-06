cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glew 2.1.0 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

add_executable(game main.cpp)

target_link_libraries(game ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})