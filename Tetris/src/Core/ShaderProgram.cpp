#include "ShaderProgram.h"
#include <glad/glad.h>
#include <iostream>

ShaderProgram::ShaderProgram()
{
	m_ID = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_ID);
}

void ShaderProgram::AttachShader(uint32_t shaderID) const
{
	glAttachShader(m_ID, shaderID);
}

void ShaderProgram::LinkProgram() const
{
	glLinkProgram(m_ID);

	int isLinked;
	glGetProgramiv(m_ID, GL_LINK_STATUS, &isLinked);
	if (!isLinked)
	{
		char log[1024];
		glGetProgramInfoLog(m_ID, 1024, nullptr, log);
		std::cerr << "Failed to link shader program!" << std::endl
			<< "ShaderProgramID: " << m_ID << std::endl
			<< "Error Log: " << std::endl << log << std::endl;
		throw log;
	}
}

void ShaderProgram::Use()
{
	glUseProgram(m_ID);
}
