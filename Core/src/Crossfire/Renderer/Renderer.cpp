#include "cfpch.h"
#include "Renderer.h"
#include "Crossfire/Core/Application.h"
#include "Crossfire/Core/Window.h"

#include "Mesh.h"
#include "Shader.h"

namespace Crossfire
{

	Scope<RenderAPI> Renderer::s_RenderAPI;
	
	//TESTING
	Ref<Mesh> mesh;
	Ref<Shader> shader;


	void Renderer::Init()
	{

#ifdef CF_API_OPENGL
		s_RenderAPI = RenderAPI::Create(RenderAPI::API::OpenGL);
#endif

		s_RenderAPI->Init();

		mesh = Mesh::Create();

		Vec<float> vertices = {
			-0.25f, 0.5f,
			-0.25f, -0.25f,
			0.25f, -0.25f,
			0.25f, 0.5f
		};

		Vec<uint32_t> indices = {
					3, 2, 1, 1, 0, 3
		};

		mesh->SetVertices(vertices, 2);
		mesh->SetIndices(indices);

		std::string version = "#version 330";
		std::string VertexShader = 
			version + "\n" + 
			"layout (location = 0) in vec3 position;\n" + 
			"void main(){\n" + 
			"gl_Position = vec4(position,1);\n" 
			+ "}\n";
		
		std::string FragmentShader = 
			version + "\n" + 
			"out vec4 color;\n" + 
			"void main(){\n" + 
			"color = vec4(1,1.0,1.0,0.1);\n"
			+ "}\n";

		shader = Shader::Create(VertexShader, FragmentShader);
	}

	void Renderer::OnRender()
	{
		CF_INFO("I'm Rendering!");

		s_RenderAPI->Clear();

		// RENDER 
		shader->Bind();
		mesh->Draw();
		shader->Unbind();
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