project ("Tetris")
file(GLOB SOURCE_FILES	./src/**.cpp
						./src/**/**.cpp
						./src/**/**.h)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE	glfw 
												glad
												opengl32
												glm::glm)

# Copy resources to output directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>)
