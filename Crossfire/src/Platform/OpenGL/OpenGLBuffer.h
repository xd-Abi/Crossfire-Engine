#pragma once

#include "Crossfire/Rendering/Buffer.h"

namespace Crossfire
{

	class OpenGLVertexBuffer : public VertexBuffer
	{

		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		void Bind() override;
		void Unbind() override;

	private:
		uint32_t m_ID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{

	public:
		
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();

		void Bind() override;
		void Unbind() override;

		uint32_t GetCount() const override { return m_Count; }

	private:

		uint32_t m_ID;
		uint32_t m_Count;
	};
}
