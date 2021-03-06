#include <Crossfire.h>
#include <Crossfire/Core/EntryPoint.h>


namespace Crossfire
{
	class EngineApp : public Crossfire::Application
	{

	public:
		EngineApp()
		{

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