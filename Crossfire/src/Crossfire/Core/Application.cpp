#include "cfpch.h"
#include "Application.h"
#include "GLFW/glfw3.h"

namespace Crossfire
{

	Application* Application::s_Instance;

	Application::Application()
	{
		s_Instance = this;
		m_Window = Window::Create(WindowProps("Crossfire | 0.0.1 Aplha"));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		while (m_Running)
		{
			OnUpdate();
			OnRender();
		}
	}

	void Application::OnUpdate()
	{
		m_Window->OnUpdate();
	}

	void Application::OnRender()
	{

	}
}