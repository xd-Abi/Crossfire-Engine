#include "cfpch.h"
#include "RenderAPI.h"

#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace Crossfire
{

	RenderAPI::API RenderAPI::s_API;

	Scope<RenderAPI> RenderAPI::Create(RenderAPI::API API)
	{
		switch (API)
		{
		case RenderAPI::API::OpenGL:
			return CreateScope<OpenGLRenderAPI>();
		}

		CF_CORE_ERROR("RenderAPI: Unkown API");
		return nullptr;
	}
}