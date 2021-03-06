	#include "cfpch.h"
#include "Application.h"

#include "Crossfire/Renderer/Renderer.h"

namespace Crossfire
{

	Application* Application::s_Instance;

	Application::Application()
	{
		s_Instance = this;
		
		m_Window = Window::Create(WindowProps("Crossfire | 0.0.1 Aplha"));
		m_Window->SetEventCallback(CF_BIND_EVENT_FN(Application::OnEvent));
	
		Renderer::Init();
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(CF_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(CF_BIND_EVENT_FN(Application::OnWindowResize));

		CF_CORE_INFO(e.ToString());
	}

	void Application::Run()
	{

		while (m_Running)
		{
			OnUpdate();
			OnRender();
		}
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return true;
	}

	void Application::OnUpdate()
	{
		m_Window->OnUpdate();
	}

	void Application::OnRender()
	{
		Renderer::OnRender();
		m_Window->OnDraw();
	}
}