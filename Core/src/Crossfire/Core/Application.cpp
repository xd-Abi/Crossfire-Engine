#include "cfpch.h"
#include "Application.h"

#include "Crossfire/Renderer/Renderer.h"
#include "Timestep.h"

#include "GLFW/glfw3.h"

namespace Crossfire
{

	Application* Application::s_Instance;

	Application::Application()
	{
		s_Instance = this;
		
		Log::Initialize();

		m_Window = Window::Create(WindowProps("Crossfire | 0.0.1 Aplha"));
		m_Window->SetEventCallback(CF_BIND_EVENT_FN(Application::OnEvent));
	
		Renderer::Init();
	}

	Application::~Application()
	{
		for (Layer* layer : m_LayerStack)
			layer->OnDetach();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(CF_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(CF_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}

		CF_CORE_INFO(e.ToString());
	}

	void Application::Run()
	{

		while (m_Running)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			OnUpdate(timestep);
			OnRender();
		}
	}

	void Application::OnUpdate(Timestep ts)
	{
		if (!m_Minimized)
		{
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(ts);
		}

		m_Window->OnUpdate();
	}

	void Application::OnRender()
	{
		if (!m_Minimized)
		{ 
			Renderer::OnRender();

			for (Layer* layer : m_LayerStack)
				layer->OnRender();
		}

		m_Window->OnDraw();
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;

		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return true;
	}

}