project ("Tetris")
file(GLOB SOURCE_FILES	./src/**.cpp
						./src/**.h)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE	glfw 
												glad
												opengl32)
