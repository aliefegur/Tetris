cmake_minimum_required (VERSION 3.10)

# To prevent warnings
project (ProjectName)

# Libraries
add_subdirectory(Dependencies/glad)
add_subdirectory(Dependencies/GLFW)
add_subdirectory(Dependencies/glm)

add_subdirectory ("Tetris")
