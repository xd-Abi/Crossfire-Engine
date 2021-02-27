#pragma once

namespace Crossfire
{

	class VertexBuffer
	{

	public:

		virtual ~VertexBuffer() = default;
		
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static Ref<VertexBuffer> Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{

	public:

		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t GetCount() const = 0;

		static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};
}

