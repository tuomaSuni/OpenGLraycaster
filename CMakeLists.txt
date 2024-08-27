cmake_minimum_required(VERSION 3.10)
project(OpenGLraycaster)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all source files from the src directory
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(OpenGLraycaster ${SOURCES})

# Specify include directories for the target
target_include_directories(OpenGLraycaster PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Specify library directories and link libraries
target_link_libraries(OpenGLraycaster PRIVATE ${CMAKE_SOURCE_DIR}/lib/libglfw3.a ${CMAKE_SOURCE_DIR}/lib/glew32.lib opengl32)
