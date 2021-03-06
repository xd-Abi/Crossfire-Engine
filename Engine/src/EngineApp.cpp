#include <Crossfire.h>
#include <Crossfire/Core/EntryPoint.h>
#include <Crossfire/Renderer/Renderer.h>

namespace Crossfire
{
	class EngineApp : public Crossfire::Application
	{

	public:
		EngineApp()
		{
			Renderer::SetClearColor(0, 0, 0, 1);
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