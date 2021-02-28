#include "Core/cfpch.h"
#include "Renderer.h"
#include "Core/Application.h"
#include "Core/Window.h"

#include "Mesh.h"

namespace Crossfire
{

	Scope<RenderAPI> Renderer::s_RenderAPI;
	
	//TESTING
	Ref<Mesh> mesh;


	void Renderer::Init()
	{

	#ifdef CF_API_OPENGL
		s_RenderAPI = RenderAPI::Create(RenderAPI::API::OpenGL);
	#endif

		mesh = Mesh::Create();

		Vec<float> vertices = {
			-0.5f, 0.5f,
			-0.5f, -0.5f,
			0.5f, -0.5f,
			0.5f, 0.5f
		};

		Vec<uint32_t> indices = {
					3, 2, 1, 1, 0, 3
		};

		mesh->SetVertices(vertices, 2);
		mesh->SetIndices(indices);
	}

	void Renderer::OnRender()
	{
		s_RenderAPI->Clear();

		// RENDER 
		mesh->Draw();
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