#pragma once

#include <cstdint>

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void Bind() const;

	void SetAttribute(unsigned int index, int size, unsigned int type, bool normalized, size_t stride, const void* pointer) const;

private:
	uint32_t m_ID;
};
