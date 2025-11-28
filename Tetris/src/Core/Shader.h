#pragma once

#include <glad/glad.h>
#include <string>
#include <cstdint>

class Shader
{
public:
	enum class Type
	{
		VERTEX = GL_VERTEX_SHADER,
		FRAGMENT = GL_FRAGMENT_SHADER,
	};

	Shader(Type type, const std::string& sourceFile);
	~Shader();

	operator unsigned int() const { return m_ID; }

private:
	uint32_t m_ID;
};
