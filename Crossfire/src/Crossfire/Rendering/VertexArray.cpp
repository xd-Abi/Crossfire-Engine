#include "cfpch.h"
#include "VertexArray.h"

#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Crossfire
{

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RenderAPI::GetAPI())
		{
		case RenderAPI::API::OpenGL: CreateRef<OpenGLVertexArray>();
		}

		return nullptr;
	}
}