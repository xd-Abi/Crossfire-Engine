#pragma once

#include "Base.h"

namespace Crossfire
{

	class CF_API Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();

	private:
		
		void OnUpdate();
		void OnRender();

	private:

		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

