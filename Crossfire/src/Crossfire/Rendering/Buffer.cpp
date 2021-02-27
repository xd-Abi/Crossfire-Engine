#include "cfpch.h"
#include "Buffer.h"

#include "Crossfire/Rendering/RenderAPI.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Crossfire
{

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (RenderAPI::GetAPI())
		{
		case RenderAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (RenderAPI::GetAPI())
		{
		case RenderAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		return nullptr;
	}
}