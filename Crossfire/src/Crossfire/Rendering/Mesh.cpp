#include "cfpch.h"
#include "Mesh.h"
#include "RenderAPI.h"

#include "Platform/OpenGL/OpenGLMesh.h"

namespace Crossfire
{

	Ref<Mesh> Mesh::Create()
	{
		switch (RenderAPI::GetAPI())
		{
		case RenderAPI::API::OpenGL: return CreateRef<OpenGLMesh>();
		}

		return nullptr;
	}
}