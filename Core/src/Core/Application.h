#pragma once

#include "Base.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

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

		void OnUpdate();
		void OnRender();

	private:

		Scope<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
	};
}

