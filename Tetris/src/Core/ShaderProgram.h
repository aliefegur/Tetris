#pragma once

#include <cstdint>

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	void AttachShader(uint32_t shaderID) const;
	void LinkProgram() const;
	void Use();

	operator unsigned int() const { return m_ID; }
private:
	uint32_t m_ID;
};
