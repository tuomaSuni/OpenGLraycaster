cmake_minimum_required(VERSION 3.10)
project(OpenGLraycaster)

set(CMAKE_CXX_STANDARD 17)

# Specify the include directory for GLFW
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link directories where GLFW and OpenGL library files are located
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add executable
add_executable(OpenGLraycaster src/main.cpp)

# Link the GLFW and OpenGL libraries
target_link_libraries(OpenGLraycaster glfw3 opengl32)