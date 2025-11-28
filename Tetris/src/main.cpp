#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "Core/Shader.h"
#include "Core/ShaderProgram.h"
#include "Core/Vertex.h"
#include "Core/Buffer.h"
#include "Core/VertexArray.h"

int main(int argc, char** argv)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Tetris", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Load OpenGL pointers with GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	// Model data
	std::vector<Vertex> vertices = {
		{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
		{{ 0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
		{{ 0.0f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}
	};
	std::vector<unsigned short> indices = { 0, 1, 2 };

	// Buffers
	Buffer	vertexBuffer(Buffer::Type::Vertex),
			elementBuffer(Buffer::Type::Index);
	vertexBuffer.LoadData(vertices.data(), vertices.size() * sizeof(Vertex), Buffer::Usage::Static);
	elementBuffer.LoadData(indices.data(), indices.size() * sizeof(unsigned short), Buffer::Usage::Static);
	
	// Vertex Array
	VertexArray vertexArray;
	vertexArray.SetAttribute(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, Position));
	vertexArray.SetAttribute(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, Color));

	// Shader pipeline
	Shader	vertexShader(Shader::Type::VERTEX, "shaders/ObjectVS.glsl"), 
			fragmentShader(Shader::Type::FRAGMENT, "shaders/ObjectFS.glsl");
	ShaderProgram shaderProgram;
	shaderProgram.AttachShader(vertexShader);
	shaderProgram.AttachShader(fragmentShader);
	shaderProgram.LinkProgram();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// Bind shader and buffers
		shaderProgram.Use();
		vertexArray.Bind();
		elementBuffer.Bind();

		// Draw call
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_SHORT, 0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
