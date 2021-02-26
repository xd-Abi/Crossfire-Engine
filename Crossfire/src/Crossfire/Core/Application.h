#pragma once

#include "Base.h"

namespace Crossfire
{

	class Application
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
}

