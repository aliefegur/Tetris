#include "Shader.h"
#include "../File.h"
#include <iostream>

Shader::Shader(Type type, const std::string& sourceFile)
{
	m_ID = glCreateShader(static_cast<GLenum>(type));
	std::string sourceCodeStr = File::ReadFile(sourceFile);
	const char* sourceCode = sourceCodeStr.c_str();
	glShaderSource(m_ID, 1, &sourceCode, NULL);
	glCompileShader(m_ID);

	// Check for compilation errors
	int isCompiled;
	glGetShaderiv(m_ID, GL_COMPILE_STATUS, &isCompiled);
	if (!isCompiled)
	{
		char log[1024];
		glGetShaderInfoLog(m_ID, 1024, nullptr, log);
		std::cerr	<< "Failed to compile shader!" << std::endl 
					<< "ShaderID: " << m_ID << std::endl
					<< "Shader Source: " << sourceFile << std::endl
					<< "Shader Type: " << std::hex << static_cast<GLenum>(type) << std::endl
					<< "Error Log: " << std::endl << log << std::endl;
		throw log;
	}
}

Shader::~Shader()
{
	glDeleteShader(m_ID);
}
