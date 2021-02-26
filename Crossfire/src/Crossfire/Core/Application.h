#pragma once

#include "Base.h"
#include "Window.h"

namespace Crossfire
{

	class Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
		
		static Application& Get() { return *s_Instance; }

	private:
		
		void OnUpdate();
		void OnRender();

	private:

		Scope<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
	};
}

