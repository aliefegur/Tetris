#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray()
{
	glCreateVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_ID);
}

void VertexArray::SetAttribute(unsigned int index, int size, unsigned int type, bool normalized, size_t stride, const void* pointer) const
{
	Bind();
	glVertexAttribPointer(index, size, type, normalized ? GL_TRUE : GL_FALSE, static_cast<GLsizei>(stride), pointer);
	glEnableVertexAttribArray(index);
}
