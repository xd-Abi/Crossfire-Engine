#pragma once

#include "Base.h"
#include "Window.h"
#include "Crossfire/Events/Event.h"
#include "Crossfire/Events/ApplicationEvent.h"
#include "Timestep.h"

namespace Crossfire
{

	class Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		
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

	private:
		static Application* s_Instance;
	};

	// To be defined in Client

	Application* CreateApplication();
}

