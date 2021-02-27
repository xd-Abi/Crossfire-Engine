#include "cfpch.h"
#include "Renderer.h"
#include "Crossfire/Core/Application.h"
#include "Crossfire/Core/Window.h"

namespace Crossfire
{

	Scope<RenderAPI> Renderer::s_RenderAPI;
	void Renderer::Init()
	{

	#ifdef CF_API_OPENGL
		s_RenderAPI = RenderAPI::Create(RenderAPI::API::OpenGL);
	#endif
	}

	void Renderer::OnRender()
	{
		s_RenderAPI->Clear();

		// RENDER 

	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		s_RenderAPI->SetViewport(width, height);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
		s_RenderAPI->SetClearColor(r, g, b, a);
	}
}