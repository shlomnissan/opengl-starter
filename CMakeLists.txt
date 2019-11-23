cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(GLEW_LIBRARIES /usr/local/Cellar/glew/2.1.0/lib/libGLEW.a)
set(SOIL_LIBRARIES "${PROJECT_SOURCE_DIR}/vendor/SOIL/libSOIL.a")

find_package(PkgConfig REQUIRED)
find_package(glfw REQUIRED)
find_package(glew REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLFW_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR})

add_executable(game main.cpp game.cpp game.hpp resource_manager.cpp resource_manager.hpp shader.cpp shader.hpp texture2d.cpp texture2d.hpp)

target_link_libraries(game ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SOIL_LIBRARIES})