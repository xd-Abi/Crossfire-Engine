#include "cfpch.h"
#include "Application.h"

namespace Crossfire
{

	Application::Application()
	{

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

	}

	void Application::OnRender()
	{

	}
}