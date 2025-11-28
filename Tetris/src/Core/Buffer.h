#pragma once

#include <glad/glad.h>
#include <cstdint>

class Buffer
{
public:
	enum class Type
	{
		Vertex = GL_ARRAY_BUFFER,
		Index = GL_ELEMENT_ARRAY_BUFFER
	};
	enum class Usage
	{
		Static = GL_STATIC_DRAW,
		Dynamic = GL_DYNAMIC_DRAW,
		Stream = GL_STREAM_DRAW
	};

	Buffer(Type type);
	~Buffer();

	void LoadData(const void* data, size_t size, Usage usage) const;

	void Bind() const;
	void Bind(Type type) const;

private:
	Type m_Type;
	uint32_t m_ID;
};
