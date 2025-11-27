project(glad)

include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/include)
add_library(${PROJECT_NAME} STATIC src/glad.c)
