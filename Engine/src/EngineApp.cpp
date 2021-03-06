#include <Crossfire.h>
#include <Crossfire/Core/EntryPoint.h>
#include "TestLayer.h"

namespace Crossfire
{
	class EngineApp : public Crossfire::Application
	{

	public:
		EngineApp()
		{
			PushLayer(new TestLayer());
		}

		~EngineApp()
		{

		}
	};

	Crossfire::Application* Crossfire::CreateApplication()
	{
		return new EngineApp();
	}
}