#pragma once

#include "Base.h"
#include "Window.h"
#include "Crossfire/Events/Event.h"
#include "Crossfire/Events/ApplicationEvent.h"
#include "Crossfire/Layer/LayerStack.h"
#include "Timestep.h"

namespace Crossfire
{

	class Application
	{

	public:

		Application(WindowProps& props = WindowProps());
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }

	private:
			
		// EventsCallbacks
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		void OnUpdate(Timestep ts);
		void OnRender();

	private:

		Scope<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;

		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in Client

	Application* CreateApplication();
}

