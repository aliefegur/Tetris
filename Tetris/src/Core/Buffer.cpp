#include "Buffer.h"

Buffer::Buffer(Type type)
	:
	m_Type(type)
{
	glCreateBuffers(1, &m_ID);
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &m_ID);
}

void Buffer::LoadData(const void* data, size_t size, Usage usage) const
{
	Bind();
	glBufferData(static_cast<GLenum>(m_Type), size, data, static_cast<GLenum>(usage));
}

void Buffer::Bind() const
{
	glBindBuffer(static_cast<GLenum>(m_Type), m_ID);
}

void Buffer::Bind(Type type) const
{
	glBindBuffer(static_cast<GLenum>(type), m_ID);
}
