#pragma once

#include "Base.h"
#include "Window.h"
#include "Crossfire/Events/Event.h"
#include "Crossfire/Events/ApplicationEvent.h"

namespace Crossfire
{

	class Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		
		static Application& Get() { return *s_Instance; }

	private:
			
		// EventsCallbacks
		bool OnWindowClose(WindowCloseEvent& e);

		void OnUpdate();
		void OnRender();

	private:

		Scope<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
	};
}

