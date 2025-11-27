cmake_minimum_required (VERSION 3.10)

# To prevent warnings
project (ProjectName)

# Libraries
add_subdirectory(Dependencies/glad)
add_subdirectory(Dependencies/GLFW)

include_directories(Dependencies/glm)

add_subdirectory ("Tetris")
