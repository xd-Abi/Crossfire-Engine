#include "Crossfire.h"
#include "TestLayer.h"

namespace Crossfire
{

	Ref<Mesh> mesh;
	Ref<Shader> shader;

	TestLayer::TestLayer()
		: Layer("TestLayer")
	{
	}

	void TestLayer::OnAttach()
	{
		Renderer::SetClearColor(0, 0, 0, 1);
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
			"layout (location = 0) in vec2 u_dimensions;\n" +
			"void main(){\n" +
			"gl_Position = vec4(u_dimensions, 0,1);\n"
			 "}\n";

		std::string FragmentShader =
			version + "\n" +
			"out vec4 color;\n" +
			"void main(){\n" +
			"color = vec4(1,1.0,1.0,0.1);\n"
			+ "}\n";

		shader = Shader::Create(VertexShader, FragmentShader);
	}

	void TestLayer::OnDetach()
	{
		CF_INFO("DETACH");
	}

	void TestLayer::OnUpdate(Timestep ts)
	{
		CF_CORE_INFO("TEST {0}", ts);
	}

	void TestLayer::OnRender()
	{
		shader->Bind();
		mesh->Draw();
		shader->Unbind();
	}
	
}