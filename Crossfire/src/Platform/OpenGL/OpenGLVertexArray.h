#pragma once

#include "Crossfire/Rendering/VertexArray.h"

namespace Crossfire
{

	class OpenGLVertexArray : public VertexArray
	{

	public:

		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const Ref<VertexBuffer> vertexBuffer) override;
		void SetIndexBuffer(const Ref<IndexBuffer> indexBuffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
	private:
		uint32_t m_ID;
		Vec<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};
}
